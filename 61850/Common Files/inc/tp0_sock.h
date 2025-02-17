#ifndef TP0_SOCK_INCLUDED
#define TP0_SOCK_INCLUDED
/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*	(c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*	1997 - 2004 All Rights Reserved					*/
/*									*/
/* MODULE NAME : tp0_sock.h						*/
/* PRODUCT(S)  : Lean-T Stack						*/
/*									*/
/* MODULE DESCRIPTION :							*/
/*	TP0/RFC1006 header file for "sockets" interface.		*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev     Comments					*/
/* --------  ---  ------   -------------------------------------------  */
/* 01/14/04  EJV    17     np_data_req: added eot param.		*/
/*			   Added np_get_tx_queue_cnt func.		*/
/* 10/23/03  JRB    16     Move all system includes to sysincs.h	*/
/* 10/16/03  JRB    15     SOCK_INFO: add genSock.			*/
/* 09/11/03  EJV    14	   Del winsock.h (windows.h gets right winsock)	*/
/*			   Added encrypt_ctrl arg to np_connect_req().	*/
/*			   SOCK_INFO: Add DBL_LNK l and encrypt_ctrl.	*/
/* 07/16/02  JRB    13     Add arg to sreadd proto.			*/
/* 06/20/02  JRB    12     Chg np_connect_req 2nd arg to ulong ipAddr.	*/
/* 05/08/02  JRB    11     Chg connect_result to int (to store errno).	*/
/* 05/03/02  JRB    10     Add ip_addr to SOCK_INFO to pass to Read task.*/
/* 02/02/01  EJV    09     _AIX: added forward references for inet.h.	*/
/* 01/02/01  EJV    08     Ported to _AIX.				*/
/* 08/15/00  EJV    07     WIN32: Del pipe_msg_crit_sec, pipe_msg_count.*/
/* 05/18/00  JRB    06     Del "select.h". See "sysincs.h".		*/
/*			   Add <netinet/tcp.h> for VXWORKS.		*/
/*			   Improve "ioctlsocket" macros for non-WIN32.	*/
/* 08/13/98  JRB    05     Lint cleanup.				*/
/*			   Add <netinet/tcp.h> for default system.	*/
/* 12/09/97  JRB    04     Added __OS2__ support.			*/
/* 11/14/97  JRB    03     Make PIPE_MSG for VXWORKS like _WIN32.	*/
/* 11/10/97  JRB    02     Add VXWORKS support.				*/
/* 08/01/97  JRB    01     Created (compatible with MMS-EASE 7.0).	*/
/************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#include "gensock2.h"		/* need GEN_SOCK definition	*/
#include "mvl_defs.h"		/* need GEN_SOCK definition	*/

/* Include sockets defs appropriate for this platform.			*/
#if !defined (_WIN32)
#define closesocket		close
#if defined (__OS2__)		/* OS/2 ioctl has extra arg	*/
#define ioctlsocket(hSock,opt,valptr)	ioctl(hSock, opt, (ST_CHAR *)valptr, sizeof(u_long))
#elif defined (VXWORKS)		/* VXWORKS wants arg to be int	*/
#define ioctlsocket(hSock,opt,valptr)	ioctl(hSock, opt, (int) valptr)
#else	/* all other systems (e.g. UNIX)	*/
#define ioctlsocket	ioctl
#endif
#define WSAEWOULDBLOCK		EWOULDBLOCK
#define WSAEINPROGRESS		EINPROGRESS
#if defined (__OS2__)
#define WSAGetLastError()	sock_errno()
#define GetLastError()		errno
#else	/* !__OS2__	*/
#define WSAGetLastError()	errno
#endif	/* !__OS2__	*/
#define SOCKET			int
#define SOCKADDR		struct sockaddr
#define SOCKADDR_IN		struct sockaddr_in
#define PSOCKADDR		struct sockaddr *
#define HOSTENT			struct hostent
#define INVALID_SOCKET		(-1)
#endif	/* !_WIN32	*/

/************************************************************************/
/* Constant definitions.						*/
/************************************************************************/
//#define _USE_DIFF_CONNECT_PORT_

#ifdef _USE_DIFF_CONNECT_PORT_
#define IPPORT_RFC1006		10002
#else
#define IPPORT_RFC1006		102
#endif

#define RFC1006_HEAD_LEN	4
#define INVALID_CONN_ID		(-1L)
#define LISTEN_TASK_NAME	"slistend"	/* "Listen" task exe name*/
#define READ_TASK_NAME		"sreadd"	/* "Read" task exe name	*/
#define PIPE_TO_MAIN_NAME	"/tmp/pipetp0main"
#define PIPE_TO_LISTEN_NAME	"/tmp/pipetp0list"

/************************************************************************/
/* Variable type definitions.						*/
/************************************************************************/

/* Defines of possible values for "state" in SOCK_INFO struct.		*/
#define SOCK_STATE_ACCEPTED		0
#define SOCK_STATE_CONNECTING		1
#define SOCK_STATE_CONNECTED		2
#define SOCK_STATE_DISCONNECTING	3

//#define _use_pip_use_counter

typedef struct
  {
  DBL_LNK l;		/* needed to store this struct on linked list	*/
  GEN_SOCK *genSock;	/* Use with gensock2. Otherwise, use "hSock"	*/
  SOCKET hSock;
  ST_INT state;
  ST_LONG user_conn_id;	/* Received from user on N-CONNECT.req/rsp	*/
  ST_UINT32 ip_addr;	/* IP addr as long int in network byte order.	*/
  ST_UINT32 ip_addr2;
  ST_INT	nNet;
  ST_INT	watchdog;	
  ST_BOOLEAN	net_error;
  ST_INT		send_error;
  ST_BOOLEAN	bSpawn;	
  ST_BOOLEAN	canRecv;
  ST_INT		idx;
  ST_ULONG      ulTickCount;

#ifdef _use_pip_use_counter
  ST_INT   pip_use_counter;
#endif

#if !(defined(_WIN32) || defined (__OS2__))
  pid_t pid_read;	/* Save READ process PID			*/
#endif
  S_SEC_ENCRYPT_CTRL encrypt_ctrl;

#ifdef _not_use_PIPE_MSG
	PIPE_MSG_BUFS buffs;
#endif

  } SOCK_INFO;

#define PIP_USE_MAX_COUNT   100

/* Info to pass to spawned thread. Can only pass 1 arg to thread, so	*/
/* make it a structure, and put whatever we need in it.			*/
typedef struct
  {
  SOCK_INFO *sock_info;		/* to pass back to main in PIPE_MSG.	*/
  SOCKET hSock;			/* copied from "sock_info"		*/
  ST_INT state;			/* copied from "sock_info"		*/
  ST_UINT16 max_tpkt_len;	/* Max len of RFC1006 TPKT.		*/
  } THREAD_INFO;


typedef struct
  {
  SOCK_INFO *sock_info;
  ST_INT connect_result;	/* errno (WSAGetLastErr() for Windows)*/
  ST_UINT16 tpkt_len;
#if (defined (_WIN32) || defined (VXWORKS) || defined (__OS2__))
  ST_UCHAR *tpkt_ptr;
#else
  ST_UCHAR tpkt_buf [1];	/* Beginning of buffer attached to this struct*/
#endif
  } PIPE_MSG;


#define _not_use_PIPE_MSG
typedef struct 
{
	ST_INT len;
	ST_INT capacity;
	ST_INT parse_flag;  
	ST_CHAR *buff;

	//PIPE_MSG
	SOCK_INFO *sock_info;
	ST_INT connect_result;
}PIPE_MSG_BUF;

#define  MAX_PIPE_MSG_BUFS    2000

#define _use_bunlink_buse_critcle

typedef struct 
{
#ifdef _use_bunlink_buse_critcle
	//是否处于断开连接的状态，断开连接后，不能再解析报文并进行后续的处理，否则会导致程序崩溃
	ST_INT bunlink;

	//缓冲区是否被使用，在解析过程中，如果断开释放连接，也会导致解析过程崩溃，以此设置此变量
	ST_INT buse;
#endif

#ifdef _MVL_TYPE_CTRL_use_one_device_
	MVL_TYPE_CTRL *p_mvl_type_ctrl;
#endif

	ST_INT read_index;
	ST_INT write_index;
	PIPE_MSG_BUF buff[MAX_PIPE_MSG_BUFS];
}PIPE_MSG_BUFS;

/* Use define for Length of PIPE_MSG without tpkt_buf at end.	*/
#define PIPE_MSG_HEAD_LEN	(sizeof(PIPE_MSG)-1)

/************************************************************************/
/* Global variables.							*/
/************************************************************************/
#define   MAX_DEVICE	395
#define MAX_CLIENT_NUM 30

extern ST_UCHAR *g_tpkt_enc_buf;	/* Buffer for encoding TPKTs.	*/
extern SOCKET	hSockListen;		/* listen socket handle		*/
extern SOCK_INFO *sock_info_table;
extern ST_ULONG LocalIp[MAX_DEVICE];//zhouhj 本地ip地址设置

#ifdef _not_use_PIPE_MSG
extern PIPE_MSG_BUFS *g_pPipeMsgBuffs;
extern ST_INT g_nMaxPipeMsgBufCount;

#endif

extern ST_UCHAR  *recv_buf_table;
extern MVL_REQ_PEND  *req_pend_table;
extern MVL_COMM_EVENT *commEvent_table;
extern ST_INT g_nStopProtocolParseFlag;

#if defined _WIN32
extern HANDLE	hPipeMainRead[];		/* read handle for pipe		*/
extern HANDLE	hPipeMainWrite[];		/* write handle for pipe	*/
#endif

/************************************************************************/
/* Function Prototypes.							*/
/************************************************************************/
ST_RET np_init (ST_INT max_num_conns);
ST_RET np_end (ST_VOID);
ST_BOOLEAN np_event (ST_INT nPipe);

SOCK_INFO * np_connect_req (ST_LONG user_conn_id, ST_ULONG ipAddr,
                            S_SEC_ENCRYPT_CTRL *encrypt_ctrl);
ST_VOID np_connect_cnf_pos (SOCK_INFO *sock_info, ST_LONG user_conn_id);
/* NOTE: np_connect_ind & np_connect_rsp not needed because user only	*/
/*       cares about Transport conn. Doesn't need to know about Network conn.*/

/*ST_RET np_data_req (SOCK_INFO *sock_info, ST_INT pdu_len, ST_UCHAR *pdu_ptr, ST_BOOLEAN eot);*/
ST_VOID np_data_ind (SOCK_INFO *sock_info, ST_UCHAR *pdu_ptr, ST_UINT16 pdu_len);
ST_UINT np_get_tx_queue_cnt (SOCK_INFO *sock_info);

ST_RET np_disconnect_req (SOCK_INFO *sock_info);
ST_VOID np_disconnect_ind (SOCK_INFO *sock_info);

ST_RET sockets_init (ST_INT max_num_conns);
ST_VOID sockets_end (ST_VOID);
ST_RET spawn_read (SOCK_INFO *sock_info);
ST_VOID handle_connect_success (SOCK_INFO *sock_info);
ST_VOID handle_connect_fail (SOCK_INFO *sock_info);
ST_VOID handle_data (SOCK_INFO *sock_info, ST_UCHAR *tpkt_ptr, ST_UINT16 tpkt_len);
ST_VOID handle_disconnect (SOCK_INFO *sock_info);
SOCK_INFO *sock_info_alloc (SOCKET hSock, ST_INT state, ST_LONG user_conn_id);
ST_VOID sock_info_free (SOCK_INFO *sock_info);

#if defined (_WIN32)
void ThreadSockListen (void *param);

#ifdef _not_use_PIPE_MSG
void ThreadSockRead_no_pipe (void *param);
#else
void ThreadSockRead (void *param);
#endif

#endif	/* _WIN32	*/
#if defined (__OS2__)
void _Optlink ThreadSockListen (void *param);

#ifdef _not_use_PIPE_MSG
void _Optlink ThreadSockRead_no_pipe (void *param);
#else
void _Optlink ThreadSockRead (void *param);
#endif

#endif	/* __OS2__	*/

ST_VOID slistend (int arg1);
ST_VOID sreadd (int arg1, int arg2, int arg3, int arg4, int arg5);

//PIPE_MSG_BUFS
#ifdef _not_use_PIPE_MSG
	static ST_BOOLEAN mms_is_buf_empty(PIPE_MSG_BUF *pBuf)
	{
		return (pBuf->parse_flag == 0) ;
	}
	static ST_BOOLEAN mms_is_buf_write(PIPE_MSG_BUF *pBuf)
	{
		return (pBuf->parse_flag == 1) ;
	}
	static ST_BOOLEAN mms_is_buf_parse(PIPE_MSG_BUF *pBuf)
	{
		return (pBuf->parse_flag == 2) ;
	}
	static void mms_set_buf_empty(PIPE_MSG_BUF *pBuf)
	{
		pBuf->parse_flag = 0 ;
	}
	static void mms_set_buf_write(PIPE_MSG_BUF *pBuf)
	{
		pBuf->parse_flag = 1;
	}
	static void mms_set_buf_parse(PIPE_MSG_BUF *pBuf)
	{
		pBuf->parse_flag = 2;
	}

	void mms_set_pipe_msg(PIPE_MSG_BUF *pBuf, PIPE_MSG *pipe_msg);
	BOOL mms_add_pipe_msg(PIPE_MSG_BUFS *pBufs, PIPE_MSG *pipe_msg);
	PIPE_MSG_BUF* mms_has_pipe_msg(PIPE_MSG_BUFS *pBufs);
	PIPE_MSG_BUF* mms_get_pipe_msg(PIPE_MSG_BUFS *pBufs, PIPE_MSG *pipe_msg);

	void mms_set_pipe_msg_buf_len(PIPE_MSG_BUF *pBuf, ST_INT len);
	void mms_free_pipe_msg_buf(PIPE_MSG_BUF *pBuf);
	void mms_free_pipe_msg_bufs(PIPE_MSG_BUFS *pBufs);
	void mms_free_pipe_msg_bufs_ex(PIPE_MSG_BUFS *pBufs, long nCount);
	void mms_set_bufs_parse(PIPE_MSG_BUFS *pBufs);

	PIPE_MSG_BUF* mms_read_pipe_msg(PIPE_MSG *pipe_msg, int *nDvIndex);

#endif


#ifdef __cplusplus
}
#endif

#endif	/* !TP0_SOCK_INCLUDED	*/

