/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*	(c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*	1997-2004, All Rights Reserved					*/
/*									*/
/* MODULE NAME : tp0_sock.c						*/
/* PRODUCT(S)  : Lean-T Stack						*/
/*									*/
/* MODULE DESCRIPTION :							*/
/*	TP0 functions for dealing with "sockets" interface.		*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev     Comments					*/
/* --------  ---  ------   -------------------------------------------  */
/* 01/14/04  EJV    27     np_data_req: added eot param.		*/
/*			   Added np_get_tx_queue_cnt func.		*/
/* 10/23/03  JRB    26     Move clnp_debug_sel to slog.c, slogl.c.	*/
/* 07/30/03  EJV    25     Added encrypt_ctrl to np_connect_req.	*/
/* 06/19/03  JRB    24     Del unused "*_logstr".			*/
/* 07/16/02  JRB    23     Del unused local vars.			*/
/* 06/20/02  JRB    22     Pass ip addr as ulong to np_connect_req.	*/
/* 05/06/02  JRB    21     np_connect_req: pass ip_addr to Read task or	*/
/*			   thread and call "blocking" connect from there.*/
/* 02/25/02  MDE    20     Now get max PDU size from mvl_cfg_info	*/
/* 06/18/01  JRB    19     Set RCVTIMEO socket option to "infinite".	*/
/* 03/15/01  JRB    18     Use new SMEM allocation functions.		*/
/* 08/07/00  MDE    17     Changed 'connect' return error check	again	*/
/* 08/01/00  MDE    16     Changed 'connect' return error check		*/
/* 07/25/00  JRB    15     Close socket ONLY from sock_info_free.	*/
/* 05/18/00  JRB    14     Only post "listen" if called conns supported.*/
/*			   Fix np_connect_req to closesocket on error.	*/
/*			   Do NOT kill read tasks: they will exit.	*/
/*			   Use new ioctlsocket macro. Lint cleanup.	*/
/* 09/13/99  MDE    13     Added SD_CONST modifiers			*/
/* 01/26/99  JRB    12     Init clnp_debug_sel in np_init.		*/
/* 10/22/98  JRB    11     Chg LOG_ALWAYS macros to LOG_REQ.		*/
/* 10/08/98  MDE    10     Minor logging cleanup			*/
/* 08/13/98  JRB    09     Lint cleanup.				*/
/* 03/11/98  JRB    08     setsockopt NODELAY always.			*/
/*			   setsockopt KEEPALIVE if tp0_cfg.keepalive.	*/
/* 02/16/98  JRB    07     Fix gethostbyname #if. Cast setsockopt arg.	*/
/* 12/08/97  JRB    06     Added __OS2__ support.			*/
/* 12/08/97  JRB    05     Skip FD_SETSIZE check. Can't happen.		*/
/* 11/24/97  JRB    04     Set socket option REUSEADDR.			*/
/*			   Call shutdown before closing socket.		*/
/* 11/24/97  JRB    03     Added VXWORKS support.			*/
/* 09/23/97  JRB    02     np_init call sockets_end on error.		*/
/* 08/01/97  JRB    01     Created (compatible with MMS-EASE 7.0).	*/
/************************************************************************/
#include "glbtypes.h"
#include "sysincs.h"
#include "mem_chk.h"
#include "tp4api.h"		/* User definitions for tp4	*/
#include "tp4.h"		/* Internal definitions for tp4	*/
#include "tp4_log.h" 
#include "clnp_log.h"
#include "acse2.h"
#include "copp.h"


#ifdef MMS_LITE
#include "mvl_acse.h"		/* Need "mvl_num_called".	*/
#endif

#ifdef DEBUG_SISCO
SD_CONST static ST_CHAR *SD_CONST thisFileName = __FILE__;
#endif

/************************************************************************/
/* Global variables.							*/
/************************************************************************/
#if !defined (TP4_ENABLED)
#ifdef DEBUG_SISCO
SD_CONST ST_CHAR *SD_CONST _clnp_err_logstr = "CLNP_LOG_ERR";
SD_CONST ST_CHAR *SD_CONST _clnp_nerr_logstr = "CLNP_LOG_NERR";
SD_CONST ST_CHAR *SD_CONST _clnp_req_logstr = "CLNP_LOG_REQ";
SD_CONST ST_CHAR *SD_CONST _clnp_ind_logstr = "CLNP_LOG_IND";
#endif
#endif	/* !TP4_ENABLED	*/

/************************************************************************/
/*			handle_accepted_conn				*/
/************************************************************************/
ST_VOID handle_accepted_conn (SOCK_INFO *sock_info)
{
	/* User only cares about T-CONNECT.ind.  Just log this.		*/
	CLNP_LOG_IND1 ("N-CONNECT.ind:  sock_info = 0x%X", sock_info);
	sock_info->state = SOCK_STATE_CONNECTED;
}

/************************************************************************/
/*			handle_data					*/
/* Parameters:								*/
/* 	sock_info	ptr to socket tracking struct			*/
/*	tpkt_ptr	ptr to RFC1006 TPKT.				*/
/*	tpkt_len	len of RFC1006 TPKT.				*/
/************************************************************************/
ST_VOID handle_data (SOCK_INFO *sock_info, ST_UCHAR *tpkt_ptr, ST_UINT16 tpkt_len)
{
	CLNP_LOG_IND3 ("N-DATA.ind:  sock_info = 0x%X, user_conn = %d tpkt_len = %d",
		sock_info, sock_info->user_conn_id, tpkt_len);
	CLNP_LOGH_IND (tpkt_len, tpkt_ptr);
	np_data_ind (sock_info, tpkt_ptr, tpkt_len);
}
/************************************************************************/
/*			handle_disconnect				*/
/************************************************************************/
ST_VOID handle_disconnect (SOCK_INFO *sock_info)
{
	CLNP_LOG_IND2 ("N-DISCONNECT.ind:  sock_info = 0x%X, user_conn = %d",
		sock_info, sock_info->user_conn_id);
	np_disconnect_ind (sock_info);
	sock_info_free (sock_info);
}
/************************************************************************/
/*			np_connect_req					*/
/* RETURNS:								*/
/*	SOCK_INFO *	ptr to socket info for new socket,  OR		*/
/*			NULL if connect fails immediately.		*/
/************************************************************************/
SOCK_INFO *np_connect_req (ST_LONG user_conn_id, ST_ULONG ipAddr,
						   S_SEC_ENCRYPT_CTRL *encrypt_ctrl)
{
	SOCK_INFO *sock_info;		/* new tracking struct for this conn.*/
	ST_INT status = SD_SUCCESS;	/* Change status if "anything" fails.	*/
	ACSE_CONN *acse_conn;

	acse_conn = (ACSE_CONN *)(((TP0_CONN *)user_conn_id)->user_conn_id);
	sock_info = &sock_info_table[acse_conn->idx];
	sock_info->state = SOCK_STATE_CONNECTING;   
	sock_info->user_conn_id = user_conn_id;
	//  acse_conn->copp_state = COPP_STATE_IDLE;

	/* Spawn Read Task/Thread. It will first do a blocking "connect" call.*/
	/* sock_info->state = SOCK_STATE_CONNECTING.				*/
	if(!sock_info->bSpawn){
		if (spawn_read (sock_info) != SD_SUCCESS)
		{
			CLNP_LOG_ERR0 ("N-CONNECT.req ERROR: spawning Read");
			status = SD_FAILURE;
		}
		sock_info->bSpawn = SD_TRUE;
	}else{
		/*sock_info->net_error = SD_TRUE;*/
	}

	return (sock_info);
}

/************************************************************************/
/*			np_get_tx_queue_cnt				*/
/* Returns number of queued SPDUs. 					*/
/************************************************************************/
ST_UINT np_get_tx_queue_cnt (SOCK_INFO *sock_info)
{
	return (0);	/* not queueing */
}

/************************************************************************/
/*			np_disconnect_req				*/
/* This function is called by the user to break connection		*/
/************************************************************************/

ST_RET np_disconnect_req (SOCK_INFO *sock_info)
{
	ST_INT nRet = 0;
	CLNP_LOG_REQ2 ("N-DISCONNECT.req:  sock_info = 0x%X, user_conn = %d",
		sock_info, sock_info->user_conn_id);

	sock_info->state = SOCK_STATE_DISCONNECTING;
	nRet = shutdown (sock_info->hSock, 2);
	closesocket(sock_info->hSock);
	sock_info->hSock = NULL;

	if (nRet)
	{
		CLNP_LOG_ERR1 ("Error %d shutting down socket", WSAGetLastError());
		return (SD_FAILURE);
	}

	/* NOTE: do not free "sock_info" until signal from ThreadSockRead	*/
	/*       that disconnect is done.					*/
	return (SD_SUCCESS);
}
/************************************************************************/
/*			sock_info_alloc					*/
/* Allocate a SOCK_INFO struct and fill it in.				*/
/************************************************************************/
SOCK_INFO *sock_info_alloc (SOCKET hSock, ST_INT state, ST_LONG user_conn_id)
{
	SOCK_INFO *sock_info;

	/* Allocate SOCK_INFO struct.						*/
	sock_info = (SOCK_INFO *) M_MALLOC (MSMEM_SOCK_INFO, sizeof (SOCK_INFO));
	/* Fill in SOCK_INFO struct.						*/
	sock_info->hSock = hSock;
	sock_info->state = state;
	sock_info->user_conn_id = user_conn_id;
	return (sock_info);
}
/************************************************************************/
/*			sock_info_free					*/
/* Free a SOCK_INFO struct.						*/
/************************************************************************/
ST_VOID sock_info_free (SOCK_INFO *sock_info)
{
	return;	
	/* Close socket here and ONLY here.					*/
	if (closesocket (sock_info->hSock) < 0)
	{
		CLNP_LOG_ERR1 ("Error %d closing socket", WSAGetLastError());
	}
	/*  M_FREE (MSMEM_SOCK_INFO, sock_info);*/
}
