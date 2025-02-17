/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*	(c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*	1997-2002, All Rights Reserved					*/
/*									*/
/* MODULE NAME : tp0_w32.c						*/
/* PRODUCT(S)  : Lean-T Stack						*/
/*									*/
/* MODULE DESCRIPTION :							*/
/*	TP0 functions ported for WIN32 operating systems using Winsock.	*/
/*	Also ported for OS/2 because functions very similar.		*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev     Comments					*/
/* --------  ---  ------   -------------------------------------------  */
/* 09/22/04  JRB    35     Change "..Connect error.." log to NERR.	*/
/* 06/20/02  JRB    17     Save remote IP addr in sock_info after accept.*/
/* 05/16/02  JRB    16     spawn_read: Pass IP addr to Read task.	*/
/*			   Log connect_result on err (now holds errno).	*/
/* 08/01/01  JRB    15     WIN/OS2: Log only when pipe msg count	*/
/*			   increases by 100.				*/
/* 07/24/01  JRB    14     Set Read Thread priority lower so it cannot	*/
/*			   flood the pipe.				*/
/* 03/14/01  JRB    13     Use new SMEM allocation functions.		*/
/* 03/14/01  JRB    12     Chg arg to read thread to (SOCK_INFO *).	*/
/* 12/13/00  DWL    11     Added SD_FALSE param to gs_get_event_sem	*/
/* 08/15/00  EJV    10     WIN32: Del pipe_msg_crit_sec, pipe_msg_count.*/
/*			     Caused deadlock when pipe filled up on NT.	*/
/*			     Instead use PeekNamedPipe before ReadFile.	*/
/* 07/25/00  JRB    09     Close socket ONLY from sock_info_free.	*/
/* 05/18/00  JRB    08     Create TCP event sem in sockets_init,	*/
/*			   instead of spawn_listen.			*/
/* 10/28/99  JRB    07     Fix memory leak when abort received. Add	*/
/*			   free in np_event DISCONNECTING state.	*/
/* 09/30/99  JRB    06     Don't use "chk_*" functions for thread_info	*/
/*			   (was causing linked list tearing).		*/
/* 08/05/99  JRB    05     Use hTcpEvent, gs_*_event_sem.		*/
/* 10/22/98  JRB    04     Chg LOG_ALWAYS macros to LOG_REQ.		*/
/* 08/13/98  JRB    03     Lint cleanup.				*/
/* 12/09/97  JRB    02     Added __OS2__ support. OS/2 functions very	*/
/*			   simalar so included here.			*/
/* 08/01/97  JRB    01     Created (compatible with MMS-EASE 7.0).	*/
/************************************************************************/
static char *thisFileName = __FILE__;	/* For TP4_EXCEPT and slog macros*/

#include "glbtypes.h"
#include "sysincs.h"
#include "mem_chk.h"
#include "tp4api.h"		/* User definitions for tp4	*/
#include "tp4.h"		/* Internal definitions for tp4	*/
#include "clnp_log.h"
#include "sharemem.h"

//2018-10-16  lijq
extern ACSI_CTRL *acsi_ctrl_table;

#ifdef _MVL_TYPE_CTRL_use_one_device_
extern MVL_TYPE_CTRL *g_mvl_type_ctrl;
#endif
/************************************************************************/
/* Global variables.							*/
/************************************************************************/
/*MAX_SERVE_THREAD说明：0－BR型报告 遥控 请求应答 1－UR型报告  2－其他厂家装置*/
ST_EVENT_SEM hTcpEvent;
HANDLE hPipeMainRead[MAX_SERVE_THREAD+1];	/* read handle for pipe		*/
HANDLE hPipeMainWrite[MAX_SERVE_THREAD+1];	/* write handle for pipe	*/

ST_INT pipe_msg_count_max[MAX_SERVE_THREAD+1];	/* Max # msgs there ever was in pipe.	*/
ST_BOOLEAN gExit = FALSE;
ST_INT gThreadCounter = 0;
/************************************************************************/
/*			sockets_init					*/
/* 1. Init Winsock.							*/
/* 2. Create Main Pipe.							*/
/* 3. Create Critical Section.						*/
/* 4. Create "TCP" Event Semaphore.					*/
/************************************************************************/
ST_RET sockets_init (ST_INT max_num_conns)
{
	WSADATA	wsaData;	/* WinSock data	*/
	DWORD PipeSize=0;

	/* init WinSock interface	*/
	if (WSAStartup(0x0101, &wsaData)){
		CLNP_LOG_ERR0 ("Can't initialize WinSock interface");
		return (SD_FAILURE);
	}
	if (wsaData.wVersion != 0x0101){
		CLNP_LOG_ERR0 ("WinSock 1.1 not supported");
		return (SD_FAILURE);
	}

	CLNP_LOG_REQ1 ("Max num sockets = %d", wsaData.iMaxSockets);
	if (wsaData.iMaxSockets < max_num_conns)
	{
		CLNP_LOG_ERR2("ERROR np_init: Max num conns (%d) > Max num sockets (%d)",
			max_num_conns, wsaData.iMaxSockets);
		return (TP4E_INVAL_NUM_CONNS);
	}

#ifndef _not_use_PIPE_MSG
	/* create pipes and events we need	*/
	PipeSize = SIZEPIPE;			/* System will use default size.	*/
	if (!CreatePipe(&hPipeMainRead[0], &hPipeMainWrite[0], NULL, PipeSize))
	{
		CLNP_LOG_ERR0 ("Can't create pipe");
		return (SD_FAILURE);
	}

	if (!CreatePipe(&hPipeMainRead[1], &hPipeMainWrite[1], NULL, PipeSize))
	{
		CLNP_LOG_ERR0 ("Can't create pipe");
		return (SD_FAILURE);
	}
#endif

	/* Create "TCP" Event Semaphore.	*/
	if (!(hTcpEvent = gs_get_event_sem (SD_FALSE)))
	{
		CLNP_LOG_ERR0 ("Error creating TCP Event Semaphore.");
		return (SD_FAILURE);
	}

	return (SD_SUCCESS);
}
/************************************************************************/
/*			sockets_end					*/
/************************************************************************/
ST_VOID sockets_end (ST_VOID)
{
#if 0	/* DEBUG: OS seems to clean up OK. Do we need any of this?	*/
	close (hPipeMainRead);
	close (hPipeMainWrite);
#endif
}
/************************************************************************/
/*			spawn_read					*/
/* If connecting, the IP addr is passed to the thread (in sock_info)	*/
/* and the socket "connect" call is made from the thread.		*/
/************************************************************************/
ST_RET spawn_read (SOCK_INFO *sock_info)
{
	/* DEBUG: _beginthread returns ulong, but SetThreadPriority expects HANDLE.*/
	/* Are they the same?	*/
	unsigned long threadHandle;

#ifdef _not_use_PIPE_MSG
	if ((threadHandle = _beginthread (ThreadSockRead_no_pipe, 0, (void *) sock_info)) == -1)
#else
	if ((threadHandle = _beginthread (ThreadSockRead, 0, (void *) sock_info)) == -1)
#endif
	{
		CLNP_LOG_ERR0 ("Can't create 'Read' Thread");
		return (SD_FAILURE);
	}
	if (SetThreadPriority ((HANDLE) threadHandle, THREAD_PRIORITY_BELOW_NORMAL)
		== 0)
	{
		CLNP_LOG_ERR0 ("Can't change 'Read' Thread priority");
	}
	return (SD_SUCCESS);
}

/************************************************************************/
/*			np_event					*/
/************************************************************************/
//#define use_np_event_time_test

ST_BOOLEAN np_event (ST_INT nPipe)
{
	SOCK_INFO *sock_info;
	PIPE_MSG pipe_msg;
	ST_ULONG BytesRead;
	ST_BOOLEAN do_read;	/* flag to tell if ReadFile should be called	*/
	ST_INT pipe_msg_count_chk;	/* Count usable outside CriticalSection	*/

#ifdef _not_use_PIPE_MSG
	PIPE_MSG_BUF *pReadBuf = NULL;
	PIPE_MSG_BUFS *pMsgBufs = NULL;
#endif

#if defined (_WIN32)
	DWORD TotalBytesAvail=0;  /* for PeekNamedPipe */
#endif

#ifdef use_np_event_time_test
	DWORD dwBegin = 0, dwEnd = 0;
	ST_CHAR  DataSetName[120];
#endif

	ST_INT ret;
	int nDvIndex = 0;

	/* This code makes sure Pipe contains full msg before blocking read.	*/
	/* Only want to know how many bytes available in pipe, so most	*/
	/* arguments are 0 or NULL. Should be faster because no bytes copied.	*/

#ifdef _not_use_PIPE_MSG
	pReadBuf = mms_read_pipe_msg(&pipe_msg, &nDvIndex);

#ifdef _use_bunlink_buse_critcle
	pMsgBufs = g_pPipeMsgBuffs+nDvIndex;


#endif

	if (pReadBuf == NULL)
	{
		CLNP_LOG_ERR1 ("ERROR: np_event: ReadFile error %d", GetLastError());
		return (SD_FALSE);
	}

#ifdef _MVL_TYPE_CTRL_use_one_device_
	g_mvl_type_ctrl = pMsgBufs->p_mvl_type_ctrl;
#endif

#ifdef _use_bunlink_buse_critcle
	pMsgBufs = &g_pPipeMsgBuffs[nDvIndex];
	pMsgBufs->buse = 1;
#endif

	BytesRead = sizeof (pipe_msg);
	ret = 1;
	TotalBytesAvail = sizeof(pipe_msg);
	pipe_msg_count_chk = TotalBytesAvail/sizeof(pipe_msg);
	do_read = SD_TRUE;
	pipe_msg_count_max[nPipe] = pipe_msg_count_chk;
#else
	gs_mutex_get(&gs_sock_mutex);

	ret = PeekNamedPipe(hPipeMainRead[nPipe],	// handle to pipe to copy from
		(LPVOID) NULL,	// pointer to data buffer
		(DWORD) 0,		// size, in bytes, of data buffer
		(LPDWORD) NULL,	// ptr to number of bytes read
		&TotalBytesAvail,	// ptr to total number of bytes avail
		(LPDWORD) NULL);	// ptr to unread bytes in this message

	gs_mutex_free(&gs_sock_mutex);

	if(ret == 0)
	{
		TotalBytesAvail = 0;	/* in case Peek changed it before failing*/
	}
	
	pipe_msg_count_chk = TotalBytesAvail/sizeof(pipe_msg);

	if (pipe_msg_count_chk > 0)
		do_read = SD_TRUE;
	else
		do_read = SD_FALSE;

	if (pipe_msg_count_chk > pipe_msg_count_max[nPipe] + 100)
	{
		CLNP_LOG_ERR1 ("INFO: np_event: Num msgs in pipe = %d", pipe_msg_count_chk);
		pipe_msg_count_max[nPipe] = pipe_msg_count_chk;
	}

	if (do_read == SD_FALSE)
		return (SD_FALSE);

	if (!ReadFile(hPipeMainRead[nPipe], &pipe_msg, sizeof (pipe_msg), &BytesRead, NULL) )
	{
		CLNP_LOG_ERR1 ("ERROR: np_event: ReadFile error %d", GetLastError());
		return (SD_FALSE);
	}
#endif

	if (BytesRead != sizeof (pipe_msg))
	{
#ifdef _not_use_PIPE_MSG
		mms_set_buf_parse(pReadBuf);
#endif
		CLNP_LOG_ERR0 ("ERROR: np_event: Incomplete msg read from pipe.");
#ifdef _use_bunlink_buse_critcle
		pMsgBufs->buse = 0;
#endif
		return (SD_FALSE);
	}

	/* If sock_info is NULL, this msg is from ThreadSockListen. It means	*/
	/* a connect was received.  Call "accept" now to accept it, and	*/
	/* allocate new "sock_info".						*/
	if (pipe_msg.sock_info == NULL)
	{
#ifdef _not_use_PIPE_MSG
		mms_set_buf_parse(pReadBuf);
#endif
		
#ifdef _use_bunlink_buse_critcle
		pMsgBufs->buse = 0;
#endif
		return (SD_FALSE);
	}
	
#ifdef use_np_event_time_test
	dwBegin=GetTickCount();
#endif

	//2018-10-15  lijq - [$$$$]
	sock_info = pipe_msg.sock_info;

	switch (sock_info->state)
	{
	case SOCK_STATE_CONNECTING:		/* From ThreadSockRead.		*/
		if (pipe_msg.connect_result == SD_SUCCESS)
		{
			handle_connect_success (sock_info);
		}
		else
		{
			handle_connect_fail (sock_info);
		}
		break;

	case SOCK_STATE_CONNECTED:		/* From ThreadSockRead.		*/
		if (pipe_msg.tpkt_len)
		{
#ifdef _use_bunlink_buse_critcle
			//if (pMsgBufs->bunlink == 0)
			//2018-10-18  lijq
			//if (acsi_ctrl_table[nDvIndex].pnet_info != NULL)
#endif
			{
				handle_data (sock_info, pipe_msg.tpkt_ptr, pipe_msg.tpkt_len);
			}

		}
		else
		{
			handle_disconnect (sock_info);
		}

		/* CRITICAL: ThreadSockRead allocated tpkt. MUST FREE IT NOW.	*/
		/*没有处理完就不处理，总是分配不太安全*/
		//      M_FREE (MSMEM_TPKT, pipe_msg.tpkt_ptr);	/* CRITICAL: must be thread-safe*/
		//	  set_sock_lock(sock_info, SD_FALSE);
		sock_info->canRecv = SD_TRUE;
		break;

	case SOCK_STATE_DISCONNECTING:	/* From ThreadSockRead.		*/
		/* Ignore data if received. Free "sock_info" when no more data.	*/
		if (pipe_msg.tpkt_len == 0)
			sock_info_free (sock_info);

		/* CRITICAL: ThreadSockRead allocated tpkt. MUST FREE IT NOW.	*/
		//      M_FREE (MSMEM_TPKT, pipe_msg.tpkt_ptr);	/* CRITICAL: must be thread-safe*/
		//	  set_sock_lock(sock_info, SD_FALSE);
		sock_info->canRecv = SD_TRUE;
		break;

	default:
		TP4_EXCEPT ();	/* should never happen 	*/
		break;
	}	/* end "switch"	*/

#ifdef use_np_event_time_test
	dwEnd=GetTickCount();
	sprintf(DataSetName, "np_event(%d)=%d ms", 
		sock_info->idx, dwEnd - dwBegin);
	mvl_log_err(DataSetName);
#endif

#ifdef _not_use_PIPE_MSG
	mms_set_buf_parse(pReadBuf);
#endif

#ifdef _use_bunlink_buse_critcle
	pMsgBufs->buse = 0;
#endif

	return (SD_TRUE);
}	/* end "np_event"	*/
