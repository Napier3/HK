/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*	(c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*	1997-2001, All Rights Reserved					*/
/*									*/
/* MODULE NAME : tp0_read.c						*/
/* PRODUCT(S)  : Lean-T Stack						*/
/*									*/
/* MODULE DESCRIPTION :							*/
/*	TP0 functions for socket "Read" Task/Thread.  This Task/Thread	*/
/*	is spawned by the "main" Task/Thread for each connected		*/
/*	socket. This module contains different versions of code for	*/
/*	different platforms or operating systems.  It also contains	*/
/*	common code in static functions which are used by all platforms.*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev     Comments					*/
/* --------  ---  ------   -------------------------------------------  */
/* 03/11/04  GLB    19     Cleaned up "thisFileName"                    */
/* 04/14/03  JRB    18     Chg main return from void to "int".		*/
/* 07/16/02  JRB    17     VXWORKS & default sys: Close pipe before exit*/
/* 05/16/02  JRB    16     Call blocking connect from Read task/thread.	*/
/*			   Store "errno" in connect_result so main	*/
/*			   task/thread can examine or log it.		*/
/*			   WIN32: Log if WriteFile fails.		*/
/*			   UNIX: chg M_MALLOC back to malloc to avoid	*/
/*			   needing mem lib in Read task (one per conn).	*/
/* 03/07/02  JRB    15     Use memset to start with clean pipe_msg.	*/
/* 03/14/01  JRB    14     Use new SMEM allocation functions.		*/
/* 11/13/00  JRB    13     Chg arg to read thread to (SOCK_INFO *).	*/
/* 08/15/00  EJV    12     WIN32: Del pipe_msg_crit_sec, pipe_msg_count.*/
/*			     Caused deadlock when pipe filled up on NT.	*/
/* 05/18/00  JRB    11     Lint cleanup for VXWORKS.			*/
/*			   VXWORKS & UNIX exit instead of being killed.	*/
/*			   VXWORKS & UNIX ignore SIGINT.		*/
/*			   Use new ioctlsocket macro.			*/
/* 09/30/99  JRB    10     Don't use "chk_*" functions for thread_info	*/
/*			   (was causing linked list tearing).		*/
/* 08/05/99  JRB    09     Use hTcpEvent, gs_*_event_sem for WIN32, OS2.*/
/* 01/27/99  JRB    08     Change default code to use "unnamed" pipes,	*/
/*			   works without file system.			*/
/* 08/13/98  JRB    07     Lint cleanup.				*/
/* 02/20/98  JRB    06     VXWORKS bug fix: chg chk_malloc to malloc	*/
/*			   for tpkt_ptr (freed in "main" task).		*/
/* 12/10/97  JRB    05     Don't chk for (tpkt_len < 0). It's unsigned.	*/
/* 12/08/97  JRB    04     Added __OS2__ support.			*/
/* 12/08/97  JRB    03     Skip FD_SETSIZE check. Can't happen.		*/
/* 11/14/97  JRB    02     Added VXWORKS support.			*/
/* 08/01/97  JRB    01     Created (compatible with MMS-EASE 7.0).	*/
/************************************************************************/
#include "glbtypes.h"
#include "sysincs.h"
#include "mem_chk.h"
#include "tp4api.h"		/* User definitions for tp4	*/
#include "tp4.h"		/* Internal definitions for tp4	*/
#include "clnp_log.h"
#include "tp4_encd.h"
#include "acse2.h"
#include "cosp.h"
#include "memOBJTree.H"
//#include "common.h"

extern ST_LONG localIP1, localIP2;

/************************************************************************/
/* For debug version, use a static pointer to avoid duplication of 	*/
/* __FILE__ strings.							*/

#if defined(DEBUG_SISCO) && defined(S_MT_SUPPORT)
SD_CONST static ST_CHAR *SD_CONST thisFileName = __FILE__;
#endif

/************************************************************************/
/* Local function Prototypes						*/
/* These functions must only be used by the "Read" Task/Thread.		*/
/************************************************************************/
static ST_INT socket_connect (SOCK_INFO *sock_info);
static ST_UINT16 read_rfc1006_tpkt (SOCKET hSock, ST_UCHAR *tpkt_ptr,
									ST_UINT16 max_tpkt_len);

extern int ping(unsigned long IP);
ST_INT asn1_get_length(ST_UCHAR * pduptr)
{
	ST_UCHAR tmpByte;
	ST_INT offset = 0;

	tmpByte = *pduptr;
	if(tmpByte & 0x80){
		tmpByte &= 0x7f;  
		if(tmpByte == 0x01){
			offset=2;
		}else if(tmpByte == 0x02){
			offset=3;
		}
	}else{
		offset = 1;
	}
	return offset;
}

static ST_INT clarify_pdu(ST_UCHAR * pduptr)
{
	ST_UCHAR	type;
	ST_UCHAR    tag;
	ST_INT      ret = 0;

	pduptr += RFC1006_HEAD_LEN;
	/* get the TPDU type (from the second octet, bits 4-7) */
	type = pduptr [1] & TP_PDU_MASK_CDT;

	if(type == TP_PDU_TYPE_DT)
	{
		pduptr = pduptr + 8;
		/*fully encoded data*/
		pduptr = pduptr + asn1_get_length(pduptr)+1;
		/*sequence*/
		pduptr = pduptr + asn1_get_length(pduptr)+1;
		/*presentation context identifer*/
		pduptr = pduptr + (*pduptr & 0x7f) + 2;
		/*single ASN.1 type*/
		pduptr = pduptr + asn1_get_length(pduptr);
		/*user data*/
		/*mms unconfirmed pdu*/
		tag = *pduptr;
		pduptr = pduptr + asn1_get_length(pduptr+1)+1;

		if((0xa0 == *pduptr) && (tag == 0xa3))
		{
			/*information report*/
			pduptr = pduptr + asn1_get_length(pduptr+1)+1;
			
			/*variable list*/
			if((pduptr[4]=='R')&&(pduptr[5]=='P')&&(pduptr[6]=='T'))
			{
				pduptr = pduptr + 7;
				pduptr = pduptr + asn1_get_length(pduptr+1)+1;

				if((pduptr[2]=='U')&&(pduptr[3]=='R'))
				{
					ret = 1;
				}
			}
			else
			{
				ret = ret;
			}
		}
		else
		{
			ret = ret;
		}
	}
	else
	{
		ret = ret;
	}

	return ret;
}

/************************************************************************/
/*			handle_connect_success				*/
/************************************************************************/
ST_VOID handle_connect_success (SOCK_INFO *sock_info)
{
	/* Pass up N-CONNECT.cnf+ to user.	*/          
	np_connect_cnf_pos (sock_info, sock_info->user_conn_id);
	sock_info->state = SOCK_STATE_CONNECTED;
}

/************************************************************************/
/*			handle_connect_fail				*/
/************************************************************************/
ST_VOID handle_connect_fail (SOCK_INFO *sock_info)
{
	/* Pass up N-DISCONNECT.ind to user.	*/          
	np_disconnect_ind (sock_info);
	sock_info_free (sock_info);
}

ST_VOID np_connect_cnf_pos (SOCK_INFO *sock_info, ST_LONG user_conn_id)
{
	TP0_CONN *tp_conn = (TP0_CONN *) user_conn_id;

	/* Save sock_info ptr in tp_conn.	*/
	tp_conn->sock_info = sock_info;
	/* CRITICAL: Save sock_info in tp_conn->tpdu_cx before calling tp0_send_cr*/
	tp_conn->tpdu_cx.sock_info = tp_conn->sock_info;
	/* Send T-CONNECT.req		*/
	tp0_send_cr (&tp_conn->tpdu_cx);
	tp_conn->state = TP_STATE_WFCC;		/*wait for CC*/
}

ST_RET tcp_send(SOCK_INFO *sock_info, ST_CHAR *pdu, ST_INT pdu_len);

/* Send a CR (Connect Request) TPDU.*/
ST_RET tp0_send_cr (TPDU_CX *tpdu_cr)
{
	ST_RET ret = SD_FAILURE;
	ST_UINT16 data_len;

	/* Fill in g_tpkt_enc_buf with TPDU					*/
	data_len = tp_encode_cx (g_tpkt_enc_buf + RFC1006_HEAD_LEN, tpdu_cr,
		TP_PDU_TYPE_CR);
	if (data_len > 0)
	{
		/* Fill in g_tpkt_enc_buf HEADER					*/
		data_len += RFC1006_HEAD_LEN;	/* include header in len	*/
		g_tpkt_enc_buf [0] = 3;				/* vrsn		*/
		g_tpkt_enc_buf [1] = 0;				/* reserved	*/
		g_tpkt_enc_buf [2] = (ST_UCHAR) (data_len >> 8);	/* high byte	*/
		g_tpkt_enc_buf [3] = (ST_UCHAR) (data_len & 0xff);	/* low byte	*/
		ret = tcp_send(tpdu_cr->sock_info, g_tpkt_enc_buf, data_len);
	}
	return (ret);
}

/* This function is used to encode a Class 0 DT TPDU.*/
ST_UINT16 tp0_encode_dt (ST_UCHAR *enc_buf, TPDU_DT *tpdu_dt)
{
	ST_UINT16	enc_len;	/* The actual length of encoded TPDU	*/
	TP0_FHDR_DT *tp0_fhdr_dt;

	enc_len = (ST_UINT16) (TP0_HEAD_LEN_DT + tpdu_dt->udata_len);

	/*------------------------------------*/
	/* encode the TPDU header, fixed part	*/
	/*------------------------------------*/

	tp0_fhdr_dt = (TP0_FHDR_DT *) enc_buf;

	tp0_fhdr_dt->hdr_len = TP0_HEAD_LEN_DT - 1;	/* header length	*/
	/* don't count the hdr_len byte	*/
	tp0_fhdr_dt->type = TP_PDU_TYPE_DT;	/* TPDU type			*/

	/* set sequence number (make sure that bit 8 is not set) */
	tp0_fhdr_dt->eot_sn = (ST_UCHAR) 0;	/* sequence number always 0	*/
	if (tpdu_dt->eot)
		tp0_fhdr_dt->eot_sn |= TP_PDU_EOF;	/* set EOT flag			*/

	/*------------------------------------*/
	/* copy the udata to enc_buf		*/
	/*------------------------------------*/

	memcpy (&enc_buf [TP0_HEAD_LEN_DT], tpdu_dt->udata_ptr, tpdu_dt->udata_len);
	return (enc_len);
}

/* Send a DT (Data) TPDU.*/
ST_RET tp0_send_dt (TPDU_DT *tpdu_dt)
{
	ST_RET ret = SD_FAILURE;
	ST_UINT16 data_len;

	/* Fill in g_tpkt_enc_buf with TPDU					*/
	data_len = tp0_encode_dt (g_tpkt_enc_buf + RFC1006_HEAD_LEN, tpdu_dt);
	if (data_len > 0)
	{
		/* Fill in g_tpkt_enc_buf HEADER					*/
		data_len += RFC1006_HEAD_LEN;	/* include header in len	*/
		g_tpkt_enc_buf [0] = 3;				/* vrsn		*/
		g_tpkt_enc_buf [1] = 0;				/* reserved	*/
		g_tpkt_enc_buf [2] = (ST_UCHAR) (data_len >> 8);	/* high byte	*/
		g_tpkt_enc_buf [3] = (ST_UCHAR) (data_len & 0xff);	/* low byte	*/
		ret = tcp_send(tpdu_dt->sock_info, g_tpkt_enc_buf, data_len);
	}
	return (ret);
}

ST_RET tcp_send(SOCK_INFO *sock_info, ST_CHAR *pdu, ST_INT pdu_len)
{
	ST_INT nSend;
	ST_INT nLen;

	if(sock_info->net_error)
		return SD_FAILURE;

	nLen = pdu_len;

	do{
		nSend = send(sock_info->hSock, (ST_CHAR *) pdu, nLen, 0);
		if(nSend <= 0)
			break;
		nLen -= nSend;
		pdu += nSend;
		if(gExit)
			return SD_FAILURE;
	}while(nLen > 0);

	/*set_sock_lock(sock_info, FALSE);  */

	if((nLen > 0)||(nSend <= 0))
	{
		/*sock_info->net_error = SD_TRUE;*/
		sock_info->send_error++;
		CLNP_LOG_ERR1 ("Error %d sending data", WSAGetLastError());
		return (SD_FAILURE);
	}
	else 
	{
#ifdef _use_pip_use_counter
	sock_info->pip_use_counter = 0;
#endif

		sock_info->ulTickCount = 0;
		return (SD_SUCCESS);
	}
}

#if defined (_WIN32)

/************************************************************************/
/*			ThreadSockRead					*/
/* This thread is spawned from the main thread once for each active	*/
/* socket (connecting or connected).					*/
/* If "connecting", it waits for connect to complete. Once connected,	*/
/* it forever reads from the socket.					*/
/* If "connected", this thread allocates a buffer, as needed, to	*/
/* store a RFC1006 TPKT received.  When a complete TPKT is received, it	*/
/* sends a pipe_msg to the main thread.  The main thread must free	*/
/* the TPKT (passed in pipe_msg.tpkt_ptr).				*/
/************************************************************************/

#define SIZEPIPE		640*1024

void SelectNet(SOCK_INFO *sock_info)
{
	ST_INT ping_ret;

	gs_mutex_get(&gs_ping_mutex);
	ping_ret = ping(sock_info->ip_addr);  
	gs_mutex_free(&gs_ping_mutex);	

	if(1 == ping_ret)
	{
		sock_info->net_error = SD_FALSE;
		sock_info->nNet = 1;
	}
	else if(IsDualNet)
	{
		gs_mutex_get(&gs_ping_mutex);
		ping_ret = ping(sock_info->ip_addr2);
		gs_mutex_free(&gs_ping_mutex);	
		
		if(1 == ping_ret)
		{
			sock_info->net_error = SD_FALSE;
			sock_info->nNet = 2;
		}
		else 
			sock_info->nNet = 0;
	}
}

//#define _use_ThreadSockRead_sleep
#ifdef _not_use_PIPE_MSG
void ThreadSockRead_no_pipe(void *param)
{
	SOCK_INFO *sock_info;	/* CRITICAL: do not write to this struct*/
	/* Only Main Thread can write to it.	*/
	SOCKET hSock;			/* socket to read from	*/
	ST_INT state;			/* Socket state.	*/
	PIPE_MSG pipe_msg;
	DWORD	dwTemp;
	ST_UINT16 max_tpkt_len;
	ST_INT nPipe;
	fd_set readfds;
	struct timeval tv;
	ST_INT ret;
	ST_INT idle_time;
	ST_INT nACSI;
	ST_BOOLEAN  reconnect;
	DWORD TotalBytesAvail=0;
	ST_INT ping_count;
	ST_BOOLEAN bFirst = SD_TRUE;
	PIPE_MSG_BUFS *pMsgBuf = NULL;

	/* Process arguments to thread.	*/
	tv.tv_sec = 10;
	tv.tv_usec = 200;
	sock_info = (SOCK_INFO *) param;
	state = sock_info->state;
	max_tpkt_len = tp0_cfg.max_tpdu_len + RFC1006_HEAD_LEN;

	memset (&pipe_msg, 0, sizeof (PIPE_MSG));	/* Start with clean struct*/
	/* this part of pipe_msg never changes.	*/
	pipe_msg.sock_info = (SOCK_INFO *) sock_info;	/* cast removes const	*/
	hSock = sock_info->hSock;
	pipe_msg.tpkt_ptr = recv_buf_table + sock_info->idx * max_tpkt_len;
	idle_time = 0;

	nACSI = sock_info->idx;
	sock_info->watchdog = 0;
	sock_info->canRecv = SD_TRUE;
	ping_count = 0;
	dwTemp = 0;
	pMsgBuf = &g_pPipeMsgBuffs[sock_info->idx];

	//线程计数
	gThreadCounter = gThreadCounter + 1;

	while (!gExit)
	{
		if(bFirst)
		{
			SelectNet(sock_info);
			bFirst = SD_FALSE;
		}
		gs_mutex_get(&gs_sock_mutex);
		hSock =  sock_info->hSock;
		reconnect = req_pend_table[nACSI].reconnect;
		gs_mutex_free(&gs_sock_mutex);

		//是否需要重新连接
		if(reconnect == SD_TRUE)
		{
			req_pend_table[nACSI].reconnect = SD_FALSE;
			pipe_msg.connect_result = socket_connect(sock_info);
			pipe_msg.tpkt_len = 0;
			mms_add_pipe_msg(&g_pPipeMsgBuffs[nACSI], &pipe_msg);
			acsi_ctrl_table[nACSI].idleCount = 0;
		
			gs_signal_event_sem (hTcpEvent);
			hSock = sock_info->hSock;
		}//end if(reconnect == SD_TRUE)

		//网络错误，持续ping
		if(sock_info->net_error == SD_TRUE)
		{
			if(ping_count++>20)
			{
				ping_count = 0;
				SelectNet(sock_info);
			}

			Sleep(100);

			continue;
		}

		if(gExit == SD_TRUE)
			break;

		if (hSock == 0)
		{
			continue;
		}
// 		while(sock_info->canRecv == SD_FALSE)
// 		{
// 			SleepEx(1, TRUE);
// 			
// 			if(gExit == SD_TRUE)
// 				break;
// 
// 			continue;
// 		}

		tv.tv_sec = 10;
		tv.tv_usec = 200;
		FD_ZERO(&readfds);
		FD_SET(hSock, &readfds);
		ret = select(0, &readfds, NULL, NULL, &tv);

		if (ret == 0)
		{
			sock_info->watchdog = 0;
			Sleep(1);
			continue;
		}
		else if(ret < 0)
		{
			Sleep(1);
			continue;   
		}

// #ifdef _use_bunlink_buse_critcle
// 		if (pMsgBuf->bunlink == 1)
// 		{//如果是断开连接状态了，则不再接受报文  2018-10-17  lijq
// 			Sleep(1);
// 			continue;
// 		}
// #endif

		/* pipe_msc.tpkt_ptr freed from main thread (see tp0_w32.c).	*/
		/* CRITICAL: allocation function must support multithreading.	*/
		//    pipe_msg.tpkt_ptr = (ST_UCHAR *) M_MALLOC (MSMEM_TPKT, max_tpkt_len);
		pipe_msg.tpkt_len = read_rfc1006_tpkt (hSock, pipe_msg.tpkt_ptr, max_tpkt_len);

		//没有收到报文，继续最外层循环
		if (pipe_msg.tpkt_len == 0)
		{
			/* This means peer disconnected.*/
			Sleep(1);
			continue;		
		}

		//	set_sock_lock(sock_info, SD_TRUE);

		//lijq  2018-10-23
		//idle_time = 0;
		//sock_info->watchdog = 0;
		//sock_info->canRecv = SD_FALSE;   //Wait for data to be processed (np_event)

		nPipe = clarify_pdu(pipe_msg.tpkt_ptr);
		sock_info->ulTickCount = 0;
		/* Pass TPKT to main thread for decoding and processing.		*/
		/* NOTE: main thread must free TPKT (i.e. pipe_msg.tpkt_ptr).	*/
		/* NOTE: on NT, if the pipe is full, WriteFile may block until	*/
		/*       it is "TOTALLY" empty.					*/

		mms_add_pipe_msg(&g_pPipeMsgBuffs[nACSI], &pipe_msg);
		acsi_ctrl_table[nACSI].idleCount = 0;

		//	Sleep(100);
		gs_signal_event_sem (hTcpEvent);	/* Wake up main thread.		*/
	}

	gThreadCounter = gThreadCounter - 1;
}	/* End "ThreadSockRead"	*/

#else

void ThreadSockRead (void *param)
{
	SOCK_INFO *sock_info;	/* CRITICAL: do not write to this struct*/
	/* Only Main Thread can write to it.	*/
	SOCKET hSock;			/* socket to read from	*/
	ST_INT state;			/* Socket state.	*/
	PIPE_MSG pipe_msg;
	DWORD	dwTemp;
	ST_UINT16 max_tpkt_len;
	ST_INT nPipe;
	fd_set readfds;
	struct timeval tv;
	ST_INT ret;
	ST_INT idle_time;
	ST_INT nACSI;
	ST_BOOLEAN  reconnect;
	DWORD TotalBytesAvail=0;
	ST_INT ping_count;
	ST_BOOLEAN bFirst = SD_TRUE;

	/* Process arguments to thread.	*/
	tv.tv_sec = 10;
	tv.tv_usec = 200;
	sock_info = (SOCK_INFO *) param;
	state = sock_info->state;
	max_tpkt_len = tp0_cfg.max_tpdu_len + RFC1006_HEAD_LEN;

	memset (&pipe_msg, 0, sizeof (PIPE_MSG));	/* Start with clean struct*/
	/* this part of pipe_msg never changes.	*/
	pipe_msg.sock_info = (SOCK_INFO *) sock_info;	/* cast removes const	*/
	hSock = sock_info->hSock;
	pipe_msg.tpkt_ptr = recv_buf_table + sock_info->idx * max_tpkt_len;
	idle_time = 0;

	nACSI = sock_info->idx;
	sock_info->watchdog = 0;
	sock_info->canRecv = SD_TRUE;
	ping_count = 0;
	dwTemp = 0;

	//线程计数
	gThreadCounter = gThreadCounter + 1;

	while (!gExit)
	{
		if(bFirst)
		{
			SelectNet(sock_info);
			bFirst = SD_FALSE;
		}
		gs_mutex_get(&gs_sock_mutex);
		reconnect = req_pend_table[nACSI].reconnect;
		gs_mutex_free(&gs_sock_mutex);

		//是否需要重新连接
		if(reconnect == SD_TRUE)
		{
			req_pend_table[nACSI].reconnect = SD_FALSE;
			pipe_msg.connect_result = socket_connect(sock_info);

			while(!gExit)
			{
				gs_mutex_get(&gs_sock_mutex);

				ret = PeekNamedPipe(hPipeMainRead[0],
					(LPVOID) NULL,	// pointer to data buffer
					(DWORD) 0,		// size, in bytes, of data buffer
					(LPDWORD) NULL,	// ptr to number of bytes read
					&TotalBytesAvail,	// ptr to total number of bytes avail
					(LPDWORD) NULL);	// ptr to unread bytes in this message

				if(0 == ret)
				{
					gs_mutex_free(&gs_sock_mutex);
					//Sleep(20);
					Sleep(2);
					continue;
				}

				if((SIZEPIPE -TotalBytesAvail) > sizeof(pipe_msg))
				{
					WriteFile(hPipeMainWrite[0], &pipe_msg, sizeof(pipe_msg), &dwTemp, NULL);

					gs_mutex_free(&gs_sock_mutex);
					acsi_ctrl_table[nACSI].idleCount = 0;
					break;
				}
				else
				{       
					gs_mutex_free(&gs_sock_mutex);
					//Sleep(20);
					Sleep(2);
					continue;
				}
			}

			gs_signal_event_sem (hTcpEvent);
			hSock = sock_info->hSock;
		}//end if(reconnect == SD_TRUE)

		//网络错误，持续ping
		if(sock_info->net_error == SD_TRUE)
		{
			if(ping_count++>20)
			{
				ping_count = 0;
				SelectNet(sock_info);
			}

			Sleep(100);

			continue;
		}

		while(sock_info->canRecv == SD_FALSE)
		{
			//2016-11-14
			//SleepEx(10, TRUE);
#ifdef _use_ThreadSockRead_sleep
			SleepEx(5, TRUE);
#endif

			if(gExit == SD_TRUE)
				break;

			continue;
		}     

#ifdef _use_pip_use_counter
		if (sock_info->pip_use_counter >= PIP_USE_MAX_COUNT)
		{
			Sleep(50);
			sock_info->pip_use_counter = 0;
		}
#endif

		tv.tv_sec = 10;
		tv.tv_usec = 200;
		FD_ZERO(&readfds);
		FD_SET(hSock, &readfds);
		ret = select(0, &readfds, NULL, NULL, &tv);

		if (ret == 0)
		{
			sock_info->watchdog = 0;
			//Sleep(50);
#ifdef _use_ThreadSockRead_sleep
			Sleep(5);
#endif
			continue;
		}
		else if(ret < 0)
		{
			/*fault*/
			/*sock_info->net_error = SD_TRUE;*/
			//Sleep(50);
#ifdef _use_ThreadSockRead_sleep
			Sleep(1);
#endif
			continue;   
		}

		/* pipe_msc.tpkt_ptr freed from main thread (see tp0_w32.c).	*/
		/* CRITICAL: allocation function must support multithreading.	*/
		//    pipe_msg.tpkt_ptr = (ST_UCHAR *) M_MALLOC (MSMEM_TPKT, max_tpkt_len);
		pipe_msg.tpkt_len = read_rfc1006_tpkt (hSock, pipe_msg.tpkt_ptr, max_tpkt_len);

		//没有收到报文，继续最外层循环
		if (pipe_msg.tpkt_len == 0)
		{
			/* This means peer disconnected.*/
			//		Sleep(100);
			Sleep(1);
			continue;		
		}
		// 		else if (pipe_msg.tpkt_len > 2048)
		// 		{
		// 			//mvl_log_err("recv pkg len > 2048");
		// 			//continue;
		// 		}

		//	set_sock_lock(sock_info, SD_TRUE);
		idle_time = 0;
		sock_info->watchdog = 0;
		sock_info->canRecv = SD_FALSE;   //Wait for data to be processed (np_event)
		nPipe = clarify_pdu(pipe_msg.tpkt_ptr);
		sock_info->ulTickCount = 0;
		/* Pass TPKT to main thread for decoding and processing.		*/
		/* NOTE: main thread must free TPKT (i.e. pipe_msg.tpkt_ptr).	*/
		/* NOTE: on NT, if the pipe is full, WriteFile may block until	*/
		/*       it is "TOTALLY" empty.					*/

#ifdef _use_pip_use_counter
		sock_info->pip_use_counter = sock_info->pip_use_counter + 1;
#endif

		//等待管道使用
		while(!gExit)
		{
			gs_mutex_get(&gs_sock_mutex);
			ret = PeekNamedPipe(hPipeMainRead[nPipe],
				(LPVOID) NULL,	// pointer to data buffer
				(DWORD) 0,		// size, in bytes, of data buffer
				(LPDWORD) NULL,	// ptr to number of bytes read
				&TotalBytesAvail,	// ptr to total number of bytes avail
				(LPDWORD) NULL);	// ptr to unread bytes in this message

			if(0 == ret)
			{
				gs_mutex_free(&gs_sock_mutex);
				//Sleep(10);
#ifdef _use_ThreadSockRead_sleep
				Sleep(2);
#endif
				continue;
			}

			if((SIZEPIPE -TotalBytesAvail) > sizeof(pipe_msg))
			{
				WriteFile(hPipeMainWrite[nPipe], &pipe_msg, sizeof(pipe_msg), &dwTemp, NULL);
				gs_mutex_free(&gs_sock_mutex);
				acsi_ctrl_table[nACSI].idleCount = 0;
				break;
			}
			else
			{       
				gs_mutex_free(&gs_sock_mutex);
				//Sleep(10);
#ifdef _use_ThreadSockRead_sleep
				Sleep(2);
#endif
				continue;
			}
		}
		//	Sleep(100);
		gs_signal_event_sem (hTcpEvent);	/* Wake up main thread.		*/
	}

	gThreadCounter = gThreadCounter - 1;
}	/* End "ThreadSockRead"	*/

#endif
#elif defined (VXWORKS)

/************************************************************************/
/*				 sreadd					*/
/* This task is spawned from the main task once for each active		*/
/* socket (connecting or connected).					*/
/*   If "connecting", it waits for connect to complete. Once connected,	*/
/* it forever reads from the socket.					*/
/*   Because the VXWORKS pipes are "message oriented", and memory is 	*/
/* automatically shared, this works more like the _WIN32 code.		*/
/*   If "connected", this task allocates a buffer, as needed, to	*/
/* store a RFC1006 TPKT received.  When a complete TPKT is received, it	*/
/* sends a pipe_msg to the main task.  The main task must free		*/
/* the TPKT (passed in pipe_msg.tpkt_ptr).				*/
/************************************************************************/
ST_VOID sreadd (int arg1, int arg2, int arg3, int arg4, int arg5)
{
	char *argv[5];		/* Only for faking argv [0]	*/
	SOCK_INFO *sock_info;
	SOCKET hSock;			/* socket to read from	*/
	ST_INT state;			/* Socket state.	*/
	PIPE_MSG pipe_msg;
	int pipe_to_main;
	ST_UINT16 max_tpkt_len;
	ST_UINT32 ip_addr;	/* IP addr as long int in network byte order.	*/

	/* Parse the command line	*/
	argv [0] = "sreadd";
	sock_info = (SOCK_INFO *) arg1;
	hSock = arg2;
	state = arg3;
	max_tpkt_len = (ST_UINT16) arg4;
	ip_addr = (ST_UINT32) arg5;

	signal (SIGINT, SIG_IGN);	/* only main task should catch ctrl-c	*/

	/* Open pipe to write.		*/
	if ((pipe_to_main = open (PIPE_TO_MAIN_NAME, O_WRONLY, 0)) < 0)
	{
		log_printf ("%s: FATAL ERROR: can't open pipe to write.\n", argv[0]);
		exit (96);
	}

	/* Fill in what we can of "pipe_msg".		*/
	memset (&pipe_msg, 0, sizeof (PIPE_MSG));	/* Start with clean struct*/
	pipe_msg.sock_info = sock_info;	/* this part of msg never changes.*/

	/*--------------------------------------------------------------------*/
	/* This code only for socket that needs to connect.			*/
	/* If connect fails, exit this task.					*/
	/*--------------------------------------------------------------------*/
	if (state == SOCK_STATE_CONNECTING)
	{
		pipe_msg.connect_result = socket_connect (sock_info);

		pipe_msg.tpkt_len = 0;	/* CRITICAL: or main expects data attached*/
		write (pipe_to_main, (ST_CHAR *) &pipe_msg, sizeof (pipe_msg));
		if (pipe_msg.connect_result)
		{
			close (pipe_to_main);
			exit (95);		/* Connect failed, so we're done.	*/
		}
	}	/* end "if (state == SOCK_STATE_CONNECTING)"	*/

	/*--------------------------------------------------------------------*/
	/* This code for any socket.  At this point socket IS connected.	*/
	/*--------------------------------------------------------------------*/
	while (1)
	{
		pipe_msg.tpkt_ptr = malloc (max_tpkt_len);
		pipe_msg.tpkt_len = read_rfc1006_tpkt (hSock, pipe_msg.tpkt_ptr, max_tpkt_len);
#ifdef DEBUG_CHILD	/* not normally defined	*/
		log_printf("read_rfc1006_tpkt returned len = %d\n", pipe_msg.tpkt_len);
#endif	/* DEBUG_CHILD	*/

		/* Pass TPKT to main thread for decoding and processing.		*/
		write (pipe_to_main, (ST_CHAR *) &pipe_msg, sizeof (pipe_msg));
		if (pipe_msg.tpkt_len == 0)	/* This means peer disconnected.*/
		{
			close (pipe_to_main);
			exit (1);      /* Don't need this task anymore.	*/
		}
	}
}

#else		/* All other systems	*/

/************************************************************************/
/*				 main					*/
/* This task is spawned from the main task once for each active	*/
/* socket (connecting or connected).					*/
/* If "connecting", it waits for connect to complete. Once connected,	*/
/* it forever reads from the socket.					*/
/* If "connected", this task allocates a reusable buffer to		*/
/* store a RFC1006 TPKT received.  When a complete TPKT is received, it	*/
/* sends a pipe_msg to the main task including the TPKT received.	*/
/* NOTE: This code should work for most UNIX, or UNIX-like systems.	*/
/************************************************************************/
int main (argc, argv)
int argc;
char *argv[];
{
	SOCK_INFO *sock_info;
	SOCKET hSock;			/* socket to read from	*/
	ST_INT state;			/* Socket state.	*/
	PIPE_MSG *pipe_msg;
	int pipe_to_main;
	ST_UINT16 max_tpkt_len;
	ST_UINT32 ip_addr;	/* IP addr as long int in network byte order.	*/

	/* Parse the command line	*/
	if (argc == 7)
	{
		sock_info = (SOCK_INFO *) atol (argv[1]);
		hSock = atoi (argv[2]);
		state = atoi (argv[3]);
		max_tpkt_len = (ST_UINT16) atoi (argv[4]);
		pipe_to_main = atoi (argv[5]);
		ip_addr = (ST_UINT32) atol (argv[6]);
	}
	else
	{
		log_printf ("%s: FATAL ERROR: number of arguments (%d) incorrect.\n",
			argv[0], argc-1);
		exit (99);
	}

	signal (SIGINT, SIG_IGN);	/* only main task should catch ctrl-c	*/

	/* Allocate and fill in what we can of "pipe_msg".		*/
	/* NOTE: malloc used here to avoid needing mem lib. This task is	*/
	/*       spawned for every connection, so the savings add up.		*/
	pipe_msg = malloc (max_tpkt_len + PIPE_MSG_HEAD_LEN);
	pipe_msg->sock_info = sock_info;	/* this part of msg never changes.*/

	/*--------------------------------------------------------------------*/
	/* This code only for socket that needs to connect.			*/
	/* If connect fails, exit this task.					*/
	/*--------------------------------------------------------------------*/
	if (state == SOCK_STATE_CONNECTING)
	{
		pipe_msg->connect_result = socket_connect (sock_info);

		pipe_msg->tpkt_len = 0;	/* CRITICAL: or main expects data attached*/
		write (pipe_to_main, pipe_msg, PIPE_MSG_HEAD_LEN);
		if (pipe_msg->connect_result)
		{
			close (pipe_to_main);
			exit (95);		/* Connect failed, so we're done.	*/
		}
	}	/* end "if (state == SOCK_STATE_CONNECTING)"	*/

	/*--------------------------------------------------------------------*/
	/* This code for any socket.  At this point socket IS connected.	*/
	/*--------------------------------------------------------------------*/
	while (1)
	{
		pipe_msg->tpkt_len = read_rfc1006_tpkt (hSock, pipe_msg->tpkt_buf, max_tpkt_len);
#ifdef DEBUG_CHILD	/* not normally defined	*/
		log_printf("read_rfc1006_tpkt returned len = %d\n", pipe_msg->tpkt_len);
#endif	/* DEBUG_CHILD	*/

		/* Pass TPKT to main thread for decoding and processing.		*/
		write (pipe_to_main, pipe_msg, PIPE_MSG_HEAD_LEN + pipe_msg->tpkt_len);
		if (pipe_msg->tpkt_len == 0)	/* This means peer disconnected.*/
		{
			close (pipe_to_main);
			exit (1);      /* Don't need this task anymore.	*/
		}
	}
	return (0);
}

#endif	/* All other systems.	*/


/************************************************************************/
/*			socket_connect												*/
/* Send "blocking" socket connect request.								*/
/*   hSock:	socket handle												*/
/*   ip_addr:	IP addr as long int in network byte order.				*/
/* RETURNS: SD_SUCCESS or "errno" (WSAGetLastError() on Windows).		*/
/************************************************************************/
static ST_INT socket_connect (SOCK_INFO *sock_info)
{
	SOCKADDR_IN RemoteAddr;		/* remote TCP port and IP addr	*/
	SOCKADDR_IN LocalAddr;
	ST_INT ping_ret = 0;

	ST_INT retCode = SD_FAILURE;
	SOCKET hSock;
	struct timeval TimeOut;
	int sockopt_on = 1;
	ST_UINT32  ip;

	SelectNet(sock_info);
	if(sock_info->hSock > 0)
	{
		shutdown(sock_info->hSock,2);
		closesocket(sock_info->hSock);
	}   

	hSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(hSock == INVALID_SOCKET){
		sock_info->hSock = 0;
		/*sock_info->net_error == SD_TRUE;*/
		return -1;
	}   

	TimeOut.tv_sec = TimeOut.tv_usec = 0;
	//  setsockopt (hSock, SOL_SOCKET, SO_RCVTIMEO, (ST_CHAR *) &TimeOut, sizeof (TimeOut));
	//  setsockopt (hSock, IPPROTO_TCP, TCP_NODELAY, (ST_CHAR *) &sockopt_on, sizeof (int));
	//  setsockopt (hSock, SOL_SOCKET, SO_KEEPALIVE, (ST_CHAR *) &sockopt_on, sizeof (int));

	/* NOTE: This is a "blocking" connect.	*/
	memset(&RemoteAddr,0,sizeof(RemoteAddr));  
	RemoteAddr.sin_family = AF_INET;
	RemoteAddr.sin_port = htons(IPPORT_RFC1006);
	RemoteAddr.sin_addr.s_addr = sock_info->ip_addr;
	sock_info->hSock = hSock;

	/*
	gs_mutex_get(&gs_ping_mutex);
	ping_ret = ping(sock_info->ip_addr);
	gs_mutex_free(&gs_ping_mutex);	
	*/

	if (LocalIp[sock_info->idx] > 0)
	{
// 		ping_ret = ping(LocalIp[sock_info->idx]);
//		nIPNum = (sock_info->idx)%g_SingleDevConnNum;//

// 		if (1 == ping_ret)//zhouhj  等于1表示ping成功
		{
			memset( &LocalAddr,0, sizeof( LocalAddr ) );
			LocalAddr.sin_family = AF_INET;
			LocalAddr.sin_addr.s_addr = LocalIp[sock_info->idx];
			LocalAddr.sin_port = htons(0);	
			bind(sock_info->hSock,(SOCKADDR*)&LocalAddr, sizeof( LocalAddr ));
		}
	}

	if(sock_info->nNet == 1)
	{
		if (connect(sock_info->hSock, (PSOCKADDR) &RemoteAddr, sizeof(RemoteAddr)) >= 0)
		{
			ip = sock_info->ip_addr;
			ip = ip/256;
			rem_dib_table[sock_info->idx].pres_addr.netAddr.nsap[3] = ip%256;
			ip = ip/256;
			rem_dib_table[sock_info->idx].pres_addr.netAddr.nsap[2] = ip%256;
			ip = ip/256;
			rem_dib_table[sock_info->idx].pres_addr.netAddr.nsap[1] = ip%256;
			ip = ip/256;
			rem_dib_table[sock_info->idx].pres_addr.netAddr.nsap[0] = ip%256;
			retCode = SD_SUCCESS;
			sock_info->nNet = 1;
			sock_info->net_error = SD_FALSE;
		}
	}
	else if(IsDualNet)
	{
		/*
		gs_mutex_get(&gs_ping_mutex);
		ping_ret = ping(sock_info->ip_addr2);
		gs_mutex_free(&gs_ping_mutex);	
		*/
		if(sock_info->nNet == 2)
		{ 
			memset(&RemoteAddr,0,sizeof(RemoteAddr));  
			RemoteAddr.sin_family = AF_INET;
			RemoteAddr.sin_port = htons(IPPORT_RFC1006);
			RemoteAddr.sin_addr.s_addr = sock_info->ip_addr2;
			if (connect(sock_info->hSock, (PSOCKADDR) &RemoteAddr, sizeof(RemoteAddr)) >= 0)
			{
				ip = sock_info->ip_addr2;
				ip = ip/256;
				rem_dib_table[sock_info->idx].pres_addr.netAddr.nsap[3] = ip%256;
				ip = ip/256;
				rem_dib_table[sock_info->idx].pres_addr.netAddr.nsap[2] = ip%256;
				ip = ip/256;
				rem_dib_table[sock_info->idx].pres_addr.netAddr.nsap[1] = ip%256;
				ip = ip/256;
				rem_dib_table[sock_info->idx].pres_addr.netAddr.nsap[0] = ip%256;
				retCode = SD_SUCCESS;
				sock_info->nNet = 2;
				sock_info->net_error = SD_FALSE;
			}
			else
			{
				sock_info->net_error = SD_TRUE;
				closesocket(sock_info->hSock);
				sock_info->hSock = 0;
				retCode = WSAGetLastError();	
			}
		}
		else
		{
			sock_info->net_error = SD_TRUE;
		}
	}
	else
	{
		retCode = WSAGetLastError();
		/*sock_info->net_error = SD_TRUE;*/
		closesocket(sock_info->hSock);
		sock_info->hSock = 0;
	}
	return (retCode);
}

/************************************************************************/
/*			read_rfc1006_tpkt				*/
/* Read RFC1006 PDU from socket.					*/
/* The Sockets interface does not break up PDUs for us, so we must	*/
/* read the header from a PDU first, get the length, and then read	*/
/* up to that length.							*/
/* RETURN:  tpkt_len (i.e. length of PDU received, in bytes)		*/
/*									*/
/* CRITICAL: only called from "Read" Task/Thread.			*/
/************************************************************************/
static ST_UINT16 read_rfc1006_tpkt (SOCKET hSock, ST_UCHAR *tpkt_ptr,
									ST_UINT16 max_tpkt_len)
{
	ST_UINT16 tpkt_len;		/* length of PDU received (in bytes)	*/
	ST_INT recv_ret;
	ST_INT count = 0;	/* counter for # of bytes received. Init to 0.	*/

	/* Read "RFC1006_HEAD_LEN" bytes of tpkt (use blocking recv).	*/
	while (count < RFC1006_HEAD_LEN)
	{
		recv_ret = recv (hSock, (ST_CHAR *) tpkt_ptr+count, RFC1006_HEAD_LEN-count, 0);
		if (recv_ret <= 0)	/* 0 if peer disconnected, negative if error.	*/
		{
			return (0);
		}
		else
			count += recv_ret;	/* add the # of bytes read to "count"	*/
	}	/* end 1st "while" loop	*/


	/* CRITICAL:  "tpkt_ptr" must be (ST_UCHAR *) or compiler will	*/
	/* sign extend before casting tpkt_ptr[2] to (ST_UINT16).	*/
	tpkt_len = ( ( (ST_UINT16) tpkt_ptr[2] ) << 8 ) | tpkt_ptr[3];
	if (tpkt_len > max_tpkt_len ||  tpkt_len == 0)
	{				/* PDU size illegal. Possibly bad PDU.	*/
#ifdef DEBUG_CHILD
		log_printf ("read_rfc1006_tpkt: tpkt_len = %d illegal\n", tpkt_len);
#endif	/* DEBUG_CHILD	*/
		return (0);
	}

	/* Read rest of tpkt (use blocking recv).	*/
	while (count < tpkt_len)
	{			/* keep reading until "tpkt_len" bytes are read	*/
		recv_ret = recv (hSock, (ST_CHAR *) tpkt_ptr+count, tpkt_len-count, 0);
		if (recv_ret <= 0)	/* 0 if peer disconnected, negative if error.	*/
		{
			return (0);
		}
		else
			count += recv_ret;	/* add the # of bytes read to "count"	*/
	}	/* end 2nd "while" loop	*/

	return (tpkt_len);
}		/* end function	"read_rfc1006_tpkt"	*/


#ifdef _not_use_PIPE_MSG

void mms_set_pipe_msg_buf_len(PIPE_MSG_BUF *pBuf, ST_INT len)
{
	if (len == 0)
	{
		len = 10;
	}

	if (pBuf->capacity < len)
	{
		mms_free_pipe_msg_buf(pBuf);
		pBuf->buff = malloc (len);
		pBuf->capacity = len;
	}
}

void mms_set_pipe_msg(PIPE_MSG_BUF *pBuf, PIPE_MSG *pipe_msg)
{
	mms_set_pipe_msg_buf_len(pBuf, pipe_msg->tpkt_len);
	memcpy(pBuf->buff, pipe_msg->tpkt_ptr, pipe_msg->tpkt_len);
	pBuf->sock_info = pipe_msg->sock_info;
	pBuf->len = pipe_msg->tpkt_len;
	pBuf->connect_result = pipe_msg->connect_result;
	pBuf->parse_flag = 1;
}

BOOL mms_add_pipe_msg(PIPE_MSG_BUFS *pBufs, PIPE_MSG *pipe_msg)
{
	PIPE_MSG_BUF *pBuf = &pBufs->buff[pBufs->write_index];

	//0:空的  //1:还未解析	//2:已经解析
	if (pBuf->parse_flag == 1)
	{
		mvl_log_err("mms_add_pipe_msg error...... buffer is full......");
		return 0;
	}

	mms_set_pipe_msg(pBuf, pipe_msg);
	pBufs->write_index = pBufs->write_index + 1;

	if (pBufs->write_index >= MAX_PIPE_MSG_BUFS)
	{
		pBufs->write_index = 0;
	}

	return TRUE;
}

PIPE_MSG_BUF* mms_has_pipe_msg(PIPE_MSG_BUFS *pBufs)
{
	ST_INT index = 0;
	PIPE_MSG_BUF *pBuf = &pBufs->buff[pBufs->read_index];

	//0:空的  //1:还未解析	//2:已经解析
	if (pBuf->parse_flag == 0 || pBuf->parse_flag == 2)
	{
		return NULL;
	}

	return pBuf;
}

PIPE_MSG_BUF* mms_get_pipe_msg(PIPE_MSG_BUFS *pBufs, PIPE_MSG *pipe_msg)
{
	PIPE_MSG_BUF *pBuf;// = &pBufs->buff[pBufs->read_index];

	pBuf = &pBufs->buff[pBufs->read_index];

	//0:空的  //1:还未解析	//2:已经解析
	if (pBuf->parse_flag == 0 || pBuf->parse_flag == 2)
	{
		return NULL;
	}

	pipe_msg->sock_info = pBuf->sock_info;
	pipe_msg->connect_result = pBuf->connect_result;
	pipe_msg->tpkt_ptr = pBuf->buff;
	pipe_msg->tpkt_len = pBuf->len;
	pBufs->read_index = pBufs->read_index + 1;

	if (pBufs->read_index >= MAX_PIPE_MSG_BUFS)
	{
		pBufs->read_index = 0;
	}

	return pBuf;
}


void mms_free_pipe_msg_buf(PIPE_MSG_BUF *pBuf)
{
	if (pBuf->buff != NULL)
	{
		free(pBuf->buff);
		pBuf->buff = NULL;
	}

	pBuf->capacity = 0;
	pBuf->len = 0;
}

void mms_free_pipe_msg_bufs(PIPE_MSG_BUFS *pBufs)
{
	ST_INT index;

	for (index=0; index<MAX_PIPE_MSG_BUFS; index++)
	{
		mms_free_pipe_msg_buf(&pBufs->buff[index]);
	}
}

void mms_free_pipe_msg_bufs_ex(PIPE_MSG_BUFS *pBufs, long nCount)
{
	ST_INT index;

	for (index=0; index<g_nMaxPipeMsgBufCount; index++)
	{
		mms_free_pipe_msg_bufs(&pBufs[index]);
	}
}

void mms_set_bufs_parse(PIPE_MSG_BUFS *pBufs)
{
	ST_INT index;

	for (index=0; index<g_nMaxPipeMsgBufCount; index++)
	{
		mms_set_buf_parse(&pBufs->buff[index]);
	}

	pBufs->read_index = 0;
	pBufs->write_index = 0;
}

ST_INT g_nCurrDeviceIndex = 0;
ST_INT g_nMaxPipeMsgBufCount = 0;
PIPE_MSG_BUF* mms_read_pipe_msg(PIPE_MSG *pipe_msg, int *nDvIndex)
{
	PIPE_MSG_BUF *pFind = NULL;
	ST_INT index;

	for (index=g_nCurrDeviceIndex; index<g_nMaxPipeMsgBufCount; index++)
	{
		pFind = mms_get_pipe_msg(&g_pPipeMsgBuffs[index], pipe_msg);

		if (pFind != NULL)
		{
			*nDvIndex = index;
			mms_set_buf_parse(pFind);
			break;
		}
	}

	index++;

	if (index >= g_nMaxPipeMsgBufCount)
	{
		g_nCurrDeviceIndex = 0;
	}
	else
	{
		g_nCurrDeviceIndex = index;
	}

	return pFind;
}

#endif