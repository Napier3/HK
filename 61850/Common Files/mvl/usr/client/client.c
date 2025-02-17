/************************************************************************/
#include "glbtypes.h"
#include "sysincs.h"
#include "signal.h"
#include "mmsdefs.h"
#include "mms_pvmd.h"
#include "mms_pvar.h"
#include "mms_vvar.h"
#include "mms_err.h"
#include "mms_pcon.h"
#include "asn1defs.h"
#include "mmsop_en.h"

#include "mvl_acse.h"
#include "acse2.h"
#include "tp0_sock.h"
#include "tp4.h"		
#include "mvl_log.h"
#include "tp4api.h"
#include "clntobj.h"

#include "client.h"
#include "61850.h"

/*----------------------------------------------------------------------*/
/* NOTE: The MMS-EASE Lite Secured applications (Client, Server) 		*/
/*	 are designed to work with Security Toolkit for MMS-EASE Lite		*/
/*	 (LITESECURE-000-001).												*/
/* The S_SEC_ENABLED delimits the security related code.				*/
/*----------------------------------------------------------------------*/
#if defined(S_SEC_ENABLED) && defined(ACSE_AUTH_ENABLED)
#error Only one S_SEC_ENABLED or ACSE_AUTH_ENABLED may be defined
#endif

#if defined(S_SEC_ENABLED)
#include "mmslusec.h"
#endif


/************************************************************************/
/* For debug version, use a static pointer to avoid duplication of 		*/
/* __FILE__ strings.													*/
/************************************************************************/

#ifdef DEBUG_SISCO
SD_CONST static ST_CHAR *SD_CONST thisFileName = __FILE__;
#endif

/************************************************************************/
/* Identify server information											*/

IDENT_RESP_INFO identify_response_info =
{
	"SISCO",  		/* Vendor 	*/
	MMSLITE_NAME,  	/* Model  	*/
	MMSLITE_VERSION,  0,	/* Version 	*/
};

/************************************************************************/
//static ST_VOID kbService (ST_VOID);

//ST_RET start_brcb_rpt (MVL_NET_INFO *clientNetInfo, ST_CHAR* domname, ST_CHAR* brcbname, ST_CHAR* entryid, RPT_TYPEIDS *rpt_typeids);
//ST_RET start_urcb_rpt (MVL_NET_INFO *clientNetInfo, ST_CHAR* domname, ST_CHAR* brcbname, RPT_TYPEIDS *rpt_typeids);

ST_INT g_timeOut = 10;	/* timeout (in seconds) passed to waitReqDone	*/  //为适应同时模拟500多个客户端链接，增加延时原来为20(zhouhj20190128:改为10s)
time_t startTime;


ST_BOOLEAN IsDualNet = SD_TRUE;
ST_LONG localIP1, localIP2;
// ST_INT  nSelPipe = 0;

ST_VOID init_mem (ST_VOID);
#if defined (DEBUG_SISCO)
ST_VOID init_log_cfg (ST_VOID);
#endif

/*扩充定义*/
MVL_CFG_INFO mvlCfg; 
RPT_TYPEIDS rpt_typeids;

TP0_CONN *tp0_conn_arr;
ST_INT num_rem_dib_entries;
DIB_ENTRY *rem_dib_table;
ACSE_CONN *acse_conn_table;
SOCK_INFO *sock_info_table;

ST_ULONG LocalIp[MAX_DEVICE];// zhouhj 增加对本地IP地址的设置

#ifdef _not_use_PIPE_MSG
PIPE_MSG_BUFS *g_pPipeMsgBuffs;
ST_INT g_nMaxPipeMsgBufCount;
#endif

ST_UCHAR  *recv_buf_table;
MVL_REQ_PEND *req_pend_table;
MVL_COMM_EVENT *commEvent_table;
ACSI_CTRL *acsi_ctrl_table;
DEVICE_NODE *device_node_table;
ST_INT g_nStopProtocolParseFlag = 0;

ST_CHAR CLIENT_PATH[255];
ST_CHAR LOGCFG_PATH[255];

ST_CHAR buff_mms_err_text[255];
ST_INT mms_log_error_infor = 0;
ST_INT mms_ena_read_before_write = 1;
ST_INT mms_ena_read_before_write_t = 100;
ST_INT g_n_mms_Add_DA_To_Rpts = 1;
MMS_ERROR_LOG_FUNC *func_mms_log_error_infor = NULL;
MMS_ERROR_MVL_REQ_PEND_FUNC *func_mms_error_mvl_req_pend = NULL;
ST_INT g_n_MVL_ERR_USR_TIMEOUT_Count = 0;

/************************************************************************/
/*			u_mvl_connect_ind_ex										*/
/*----------------------------------------------------------------------*/
/* This function is called when a remote node has connected to us. We	*/
/* can look at the assReqInfo to see who it is (assuming that the 		*/
/* AP-Titles are used), or at the cc->rem_init_info to see initiate 	*/
/* request parameters.													*/
/************************************************************************/
extern ST_ACSE_AUTH u_mvl_connect_ind_ex (MVL_NET_INFO *cc, INIT_INFO *init_info,
	ACSE_AUTH_INFO *req_auth_info, ACSE_AUTH_INFO *rsp_auth_info)
{
	ST_ACSE_AUTH ret = ACSE_AUTH_SUCCESS;

#if defined(S_SEC_ENABLED)
	/* this Client will reject the connection since there is no security */
	/* checking code in place (see Server for sample) */
	ret = ACSE_DIAG_NO_REASON;
#elif defined(ACSE_AUTH_ENABLED)
	/* this Client will reject the connection since there is no password */
	/* checking code in place (see Server for sample) */
	ret = ACSE_DIAG_NO_REASON;
#endif

	return (ret);
}

/************************************************************************/
/*			u_mvl_connect_cnf_ex   										*/
/*----------------------------------------------------------------------*/
/* This function is called when we have received an initiate response.	*/
/* Depending on the server's authentication scheme, we may have been 	*/
/* sent responding authentication that we can pull out of the response 	*/
/* PDU.																	*/
/************************************************************************/
ST_ACSE_AUTH u_mvl_connect_cnf_ex (MVL_NET_INFO *cc, AARE_APDU *ass_rsp_info)
{
	ST_RET ret = ACSE_AUTH_SUCCESS;

#if defined(S_SEC_ENABLED)
	/* check security parameters of the Associate Confirm */
	ret = ulCheckSecureAssocConf (cc);
#elif defined(ACSE_AUTH_ENABLED)
	{
		ACSE_AUTH_INFO *rsp_auth_info;

		rsp_auth_info = &ass_rsp_info->auth_info;
		if(rsp_auth_info->auth_pres == SD_TRUE)
		{
			/* Looks like we have some authentication to look at, simply print  */
			/* the password and continue as normal.	 */
			if(rsp_auth_info->mech_type == ACSE_AUTH_MECH_PASSWORD)
			{
				log_printf("\nPassword recieved from peer: %s\n", rsp_auth_info->u.pw_auth.password);
			}
			/* We were sent a mechanism we don't support, let's reject the 	*/
			/* the connection with the appropriate diagnostic. */
			else
			{
				ret = ACSE_DIAG_AUTH_MECH_NAME_NOT_RECOGNIZED;
			}
		}
		else
		{
			/* Hmm... looks like we weren't sent any authentication even though */
			/* we require it. Let's reject with the appropriate diagnostic.	*/
			ret = ACSE_DIAG_AUTH_REQUIRED;
		}
	}
#endif /* defined(ACSE_AUTH_ENABLED) */

	/* to accept the confirm ACSE_AUTH_SUCCESS need to be returned	*/
	return ((ST_ACSE_AUTH) ret);
}


/************************************************************************/
/*					disc_ind_fun										*/
/************************************************************************/
/* This function is called when connection is terminated.		*/

ST_VOID disc_ind_fun (MVL_NET_INFO *cc, ST_INT discType)
{
	/* Free up rcb_info if necessary.	*/
	cc->rem_vmd = NULL;
}

#if (MMS_IDENT_EN & RESP_EN)
/************************************************************************/
/*			u_mvl_ident_ind					*/
/************************************************************************/
ST_VOID u_mvl_ident_ind (MVL_IND_PEND *indCtrl)
{
#if 0	/* enable this to print when Ind received		*/
	log_printf ("\n Identify Indication received.");
#endif
	indCtrl->u.ident.resp_info = &identify_response_info;
	mplas_ident_resp (indCtrl);
}
#endif	/* #if (MMS_IDENT_EN & RESP_EN)	*/

/************************************************************************/
/*			getFile						*/
/************************************************************************/
ST_RET getFile (MVL_NET_INFO *clientNetInfo, ST_CHAR *loc_file, ST_CHAR *rem_file)
{
	FREAD_REQ_INFO   fread_req_info;
	FCLOSE_REQ_INFO  fclose_req_info;
	ST_RET ret;
	FILE *loc_fp;
	MVL_REQ_PEND *reqCtrl;
	ST_INT32 frsmid;
	ST_BOOLEAN more_follows;

	ret = mvla_fopen (clientNetInfo,
		rem_file,
		0,		/* init_pos: start at beginning of file	*/
		&reqCtrl);
	if (ret == SD_SUCCESS)
		ret = waitReqDone (reqCtrl, g_timeOut, clientNetInfo->nACSI);

	if (ret == SD_SUCCESS)
		frsmid = reqCtrl->u.fopen.resp_info->frsmid;	/* save frsmid	*/
	mvl_free_req_ctrl (reqCtrl);
	if (ret != SD_SUCCESS)
		return (ret);

	loc_fp = fopen (loc_file, "wb");
	if (loc_fp == NULL)
		return (SD_FAILURE);	/* Can't open local file.	*/

	fread_req_info.frsmid = frsmid;	/* "fread" request doesn't chg.	*/
	do
	{
		ret = mvla_fread (clientNetInfo, &fread_req_info, &reqCtrl);
		if (ret == SD_SUCCESS)
			ret = waitReqDone (reqCtrl, g_timeOut, clientNetInfo->nACSI);
		if (ret == SD_SUCCESS)
		{
			more_follows = reqCtrl->u.fread.resp_info->more_follows;
			fwrite (reqCtrl->u.fread.resp_info->filedata, 1,
				reqCtrl->u.fread.resp_info->fd_len, loc_fp);
		}
		mvl_free_req_ctrl (reqCtrl);
		if (ret != SD_SUCCESS)
			return (ret);
	} while (more_follows);

	fclose_req_info.frsmid = frsmid;
	ret = mvla_fclose (clientNetInfo, &fclose_req_info, &reqCtrl);
	if (ret == SD_SUCCESS)
		ret = waitReqDone (reqCtrl, g_timeOut, clientNetInfo->nACSI);
	if (ret != SD_SUCCESS)
		log_printf ("\n mvl_fclose failed, ret = 0x%X", ret);
	mvl_free_req_ctrl (reqCtrl);

	fclose (loc_fp);
	return (SD_SUCCESS);
}

/************************************************************************/
/*						init_log_cfg 									*/
/************************************************************************/

#ifdef DEBUG_SISCO
ST_VOID init_log_cfg (ST_VOID)
{
#if defined (HARD_CODED_CFG)
	/* Use File logging	*/
	sLogCtrl->logCtrl = LOG_FILE_EN;

	/* Use time/date time log */
	sLogCtrl->logCtrl |= (LOG_DIFFTIME_EN | LOG_TIME_EN);

	/* File Logging Control defaults */
	sLogCtrl->fc.fileName = CLIENT_PATH;
	sLogCtrl->fc.maxSize = 1000000L;
	sLogCtrl->fc.ctrl = (FIL_CTRL_WIPE_EN | FIL_CTRL_WRAP_EN | FIL_CTRL_NO_APPEND |
		FIL_CTRL_MSG_HDR_EN);

	mms_debug_sel |= MMS_LOG_NERR;
	mvl_debug_sel |= MVLLOG_ERR;
	mvl_debug_sel |= MVLLOG_NERR;
#if 0
	mvl_debug_sel |= MVLLOG_ACSE;
	mvl_debug_sel |= MVLLOG_ACSEDATA;
	mvl_debug_sel |= MVLLOG_TIMING;
#endif

	acse_debug_sel |= ACSE_LOG_ERR;
#if 0
	acse_debug_sel |= ACSE_LOG_ENC;
	acse_debug_sel |= ACSE_LOG_DEC;
	acse_debug_sel |= COPP_LOG_ERR;
	acse_debug_sel |= COPP_LOG_DEC;
	acse_debug_sel |= COPP_LOG_DEC_HEX;
	acse_debug_sel |= COPP_LOG_ENC;
	acse_debug_sel |= COPP_LOG_ENC_HEX;
	acse_debug_sel |= COSP_LOG_ERR;
	acse_debug_sel |= COSP_LOG_DEC;
	acse_debug_sel |= COSP_LOG_DEC_HEX;
	acse_debug_sel |= COSP_LOG_ENC;
	acse_debug_sel |= COSP_LOG_ENC_HEX;
#endif


	tp4_debug_sel |= TP4_LOG_ERR;
#if 0
	tp4_debug_sel |= TP4_LOG_FLOWUP;
	tp4_debug_sel |= TP4_LOG_FLOWDOWN;
#endif

#if !defined(REDUCED_STACK)
	clnp_debug_sel |= CLNP_LOG_ERR;
	clnp_debug_sel |= CLNP_LOG_NERR;
#if 0
	clnp_debug_sel |= CLNP_LOG_REQ;
	clnp_debug_sel |= CLNP_LOG_IND;
	clnp_debug_sel |= CLNP_LOG_ENC_DEC;
	clnp_debug_sel |= CLNP_LOG_LLC_ENC_DEC;
	clnp_debug_sel |= CLSNS_LOG_REQ;
	clnp_debug_sel |= CLSNS_LOG_IND;
#endif
#endif

#else	/* !defined (HARD_CODED_CFG)	*/
	if (logcfgx (LOGCFG_PATH))			/* Use new XML file	*/
	{
		log_printf ("\n Parsing of 'logging' configuration file failed.");
		if (sLogCtrl->fc.fileName)
			log_printf ("\n Check log file '%s'.", sLogCtrl->fc.fileName);
	}
#endif	/* !defined (HARD_CODED_CFG) */
}
#endif  /* DEBUG_SISCO */

/************************************************************************/
/*							init_mem									*/
/************************************************************************/

static ST_VOID mem_chk_error_detected (ST_VOID);
static ST_VOID *my_malloc_err (ST_UINT size);
static ST_VOID *my_calloc_err (ST_UINT num, ST_UINT size);
static ST_VOID *my_realloc_err (ST_VOID *old, ST_UINT size);

ST_CHAR *spareMem;

ST_VOID init_mem ()
{
#if defined(NO_GLB_VAR_INIT)
	mvl_init_glb_vars ();
#endif

	/* Allocate spare memory to allow logging/printing memory errors */
	spareMem = (ST_CHAR *) malloc (500);

	/* trap mem_chk errors */
	mem_chk_err = mem_chk_error_detected;
	m_memerr_fun = my_malloc_err;
	c_memerr_fun = my_calloc_err;
	r_memerr_fun = my_realloc_err;

#if 0
	m_heap_check_enable = SD_TRUE;
	m_check_list_enable = SD_TRUE;
	m_no_realloc_smaller = SD_TRUE;
	m_fill_en = SD_TRUE;
#endif
	m_mem_debug = SD_TRUE;
}

/************************************************************************/
/* This function is called from the DEBUG version of the mem library	*/
/* when an error of any type is detected.								*/
/************************************************************************/

static ST_INT memErrDetected;

static ST_VOID mem_chk_error_detected (ST_VOID)
{
	if (!memErrDetected)
	{
		free (spareMem);
		memErrDetected = SD_TRUE;
		log_printf ("\n Memory Error Detected! Check log file");
		dyn_mem_ptr_status ();
	}
}

/************************************************************************/
/* Memory Allocation Error Handling Functions.							*/
/* These functions are called from mem_chk when it is unable to 		*/
/* perform the requested operation. These functions must either return 	*/
/* a valid buffer or not return at all.									*/
/************************************************************************/

static ST_VOID *my_malloc_err (ST_UINT size)
{
	mem_chk_error_detected ();
	log_printf ("\n Malloc");
	return (NULL);   
}

static ST_VOID *my_calloc_err (ST_UINT num, ST_UINT size)
{
	mem_chk_error_detected ();
	return (NULL);   
}

static ST_VOID *my_realloc_err (ST_VOID *old, ST_UINT size)
{
	mem_chk_error_detected ();
	return (NULL);   
}
#if (MMS_FOPEN_EN & RESP_EN)
/************************************************************************/
/*			u_mvl_fopen_ind					*/
/************************************************************************/
ST_VOID u_mvl_fopen_ind (MVL_IND_PEND *indCtrl)
{
	FILE *fp;
	FOPEN_RESP_INFO resp_info;
	struct stat  stat_buf;

	fp = fopen (indCtrl->u.fopen.filename, "rb");	/* CRITICAL: use "b" flag for binary transfer*/
	if (fp == NULL)
	{
		_mplas_err_resp (indCtrl,11,6);		/* File-access denied	*/
		return;
	}
	if (fseek (fp, indCtrl->u.fopen.init_pos, SEEK_SET))
	{
		_mplas_err_resp (indCtrl,11,5);		/* Position invalid	*/
		return;
	}

	/* WARNING: this only works if (FILE *) is a 32-bit pointer.		*/
	resp_info.frsmid = (ST_INT32) fp;

	if (fstat (_fileno (fp), &stat_buf))
	{					/* Can't get file size or time	*/
		_mplas_err_resp (indCtrl,11,0);	/* File Problem, Other		*/
		return;
	}
	else
	{
		resp_info.ent.fsize    = stat_buf.st_size;
		resp_info.ent.mtimpres = SD_TRUE;
		resp_info.ent.mtime    = stat_buf.st_mtime;
	}

	indCtrl->u.fopen.resp_info = &resp_info;
	mplas_fopen_resp (indCtrl);
}
#endif 	/* MMS_FOPEN_EN & RESP_EN	*/


#if (MMS_FREAD_EN & RESP_EN)
/************************************************************************/
/*							u_mvl_fread_ind								*/
/************************************************************************/
ST_VOID u_mvl_fread_ind (MVL_IND_PEND *indCtrl)
{
	FILE *fp;
	ST_UCHAR *tmp_buf;
	MVLAS_FREAD_CTRL *fread_ctrl = &indCtrl->u.fread;
	FREAD_RESP_INFO resp_info;

	fp = (FILE *) fread_ctrl->req_info->frsmid;
	/* Do NOT read more than "max_size".				*/
	tmp_buf = (ST_UCHAR *) chk_malloc (fread_ctrl->max_size);

	resp_info.fd_len = fread (tmp_buf, 1, fread_ctrl->max_size, fp);
	if (resp_info.fd_len == 0  &&  ferror (fp))
	{
		_mplas_err_resp (indCtrl, 3, 0);
		return;
	}

	resp_info.filedata = tmp_buf;
	if (resp_info.fd_len == fread_ctrl->max_size)
		resp_info.more_follows = SD_TRUE;
	else
		resp_info.more_follows = SD_FALSE;

	fread_ctrl->resp_info = &resp_info;
	mplas_fread_resp (indCtrl);
	chk_free (tmp_buf);		/* Temporary buffer	*/
}
#endif	/* #if (MMS_FREAD_EN & RESP_EN)	*/

#if (MMS_FCLOSE_EN & RESP_EN)
/************************************************************************/
/*			u_mvl_fclose_ind				*/
/************************************************************************/
ST_VOID u_mvl_fclose_ind (MVL_IND_PEND *indCtrl)
{
	FILE *fp;
	MVLAS_FCLOSE_CTRL *fclose_ctrl = &indCtrl->u.fclose;

	fp = (FILE *) fclose_ctrl->req_info->frsmid;

	if (fclose (fp))
		_mplas_err_resp (indCtrl, 11, 0);	/* File problem, other	*/
	else
		mplas_fclose_resp (indCtrl);
}
#endif	/* #if (MMS_FCLOSE_EN & RESP_EN)	*/

/************************************************************************/
/*			waitReqDone					*/
/*----------------------------------------------------------------------*/
/* Wait for request to complete. Service communications while waiting.	*/
/* NOTE: if other processing should be done while waiting, add it to	*/
/*       this function.							*/
/* Parameters:								*/
/*	req		request to wait for.				*/
/*	timeout		time to wait (seconds). 0 means wait forever.	*/
/* RETURNS: SD_SUCCESS, MVL_ERR_USR_TIMEOUT or other MVL error code.	*/
/************************************************************************/
ST_RET waitReqDone (MVL_REQ_PEND *req, ST_INT timeout, ST_INT nACSI)
{
// 	ST_INT  nServeACSI0 = 0;
// 	ST_INT  nServeACSI1 = 0;
//	ST_INT  nSize = 0;

	ST_ULONG stopTime = time(NULL) + timeout;
	req->done = SD_FALSE;

// 	nSize = sizeof(req->u);
// 	nSize = sizeof(MVL_REQ_PEND);
	while (1)		/* wait until done	*/
	{ 
		if (req->done)
			break;

		if ((timeout != 0) && (time(NULL) > stopTime))
		{
			req->result = MVL_ERR_USR_TIMEOUT;
			if (req->net_info != NULL)
				req->net_info->numpend_req = 0;
			break;
		}

		//nSelPipe = 0;
// 		while(mvl_comm_serve (0))
// 		{
// 			if(nServeACSI0++>MAX_PIPE0_RPT)
// 				break;
// 		}
// 
// 		//nSelPipe = 1;
// 		while(mvl_comm_serve (1))
// 		{
// 			if(nServeACSI1++>MAX_PIPE1_RPT)
// 				break;
// 		}

		Sleep(1);
		//SleepEx(10, TRUE);
	}	/* end loop	*/

	acsi_ctrl_table[nACSI].g_timeOut = 0;	

	if (req->result  != SD_SUCCESS)
	{
		if (mms_log_error_infor)
		{
			if (req->error_info != NULL)
			{
				m_get_mms_err_text (req->error_info->eclass, req->error_info->code, buff_mms_err_text, 254);

				if (func_mms_log_error_infor != 0)
				{
					func_mms_log_error_infor();
				}
			}
		}

		if (func_mms_error_mvl_req_pend != NULL)
		{
			func_mms_error_mvl_req_pend(req, nACSI);
		}
	}
	else
	{
		g_n_MVL_ERR_USR_TIMEOUT_Count=0;
	}

	return (req->result);
}

ST_VOID InitACSIServerNet()
{
	ST_INT	i;

	num_rem_dib_entries =  numDevice;
	if (rem_dib_table!=NULL)
		chk_free(rem_dib_table);
	rem_dib_table = (DIB_ENTRY *) chk_calloc (num_rem_dib_entries, sizeof (DIB_ENTRY));
	if (acse_conn_table!=NULL)
		chk_free(acse_conn_table);
	acse_conn_table = (ACSE_CONN *) chk_calloc (num_rem_dib_entries, sizeof (ACSE_CONN));
	
	if (sock_info_table!=NULL)
		chk_free(sock_info_table);
	sock_info_table = (SOCK_INFO *) chk_calloc (num_rem_dib_entries, sizeof (SOCK_INFO));

#ifdef _not_use_PIPE_MSG
	if (g_pPipeMsgBuffs != NULL)
	{
		mms_free_pipe_msg_bufs_ex(g_pPipeMsgBuffs, num_rem_dib_entries);
	}

	i = num_rem_dib_entries * sizeof (PIPE_MSG_BUFS);
	g_pPipeMsgBuffs = (PIPE_MSG_BUFS*)malloc (i);
	memset(g_pPipeMsgBuffs, 0, i);
	g_nMaxPipeMsgBufCount = num_rem_dib_entries;
#endif


	if (recv_buf_table!=NULL)
		chk_free(recv_buf_table);
	recv_buf_table = chk_calloc (num_rem_dib_entries, tp0_cfg.max_tpdu_len + RFC1006_HEAD_LEN);

	if (req_pend_table!=NULL)
		chk_free(req_pend_table);
	req_pend_table = (MVL_REQ_PEND *) chk_calloc (num_rem_dib_entries, sizeof (MVL_REQ_PEND));
	if (commEvent_table!=NULL)
		chk_free(commEvent_table);
	commEvent_table = (MVL_COMM_EVENT *) chk_calloc (num_rem_dib_entries, sizeof (MVL_COMM_EVENT));
	for(i=0; i<numDevice; i++)
	{
		memset(&rem_dib_table[i], 0, sizeof(DIB_ENTRY));
		req_pend_table[i].result = SD_FAILURE;
		acsi_ctrl_table[i].CMD = CMD_NULL;
		acsi_ctrl_table[i].g_timeOut = 0;
		acsi_ctrl_table[i].pnet_info = NULL;
		acsi_ctrl_table[i].needConnect = SD_TRUE;
		acsi_ctrl_table[i].needDirectory = SD_FALSE;
		acsi_ctrl_table[i].needTest = SD_FALSE;
		acsi_ctrl_table[i].idleCount = 0;

		req_pend_table[i].reconnect = SD_FALSE;
		acse_conn_table[i].idx = i;

		sprintf(rem_dib_table[i].name, "acsi%d", i);
		rem_dib_table[i].idx = 0;		/*必须赋值*/
		rem_dib_table[i].local = 0;
		rem_dib_table[i].AP_title_pres = 1;
		rem_dib_table[i].AP_title.num_comps = 4;
		rem_dib_table[i].AP_title.comps[0] = 1;
		rem_dib_table[i].AP_title.comps[1] = 3;
		rem_dib_table[i].AP_title.comps[2] = 9999;
		rem_dib_table[i].AP_title.comps[3] = 106;

		rem_dib_table[i].AE_qual_pres = 1;
		rem_dib_table[i].AE_qual = 33;
		rem_dib_table[i].pres_addr.tp_type = TP_TYPE_TCP;
		rem_dib_table[i].pres_addr.psel_len = 4;
		rem_dib_table[i].pres_addr.psel[3] = 1;
		rem_dib_table[i].pres_addr.ssel_len = 2;
		rem_dib_table[i].pres_addr.ssel[1] = 1;
		rem_dib_table[i].pres_addr.tsel_len = 2;
		rem_dib_table[i].pres_addr.tsel[1] = 1;
		/*双网时IP地址要在socket_connect中换*/
		rem_dib_table[i].pres_addr.netAddr.nsap[0] = 10;
		rem_dib_table[i].pres_addr.netAddr.nsap[1] = 1;
		rem_dib_table[i].pres_addr.netAddr.nsap[2] = 1;
		rem_dib_table[i].pres_addr.netAddr.nsap[3] = 123;

		sock_info_table[i].bSpawn = SD_FALSE;
		sock_info_table[i].net_error = SD_TRUE;
		sock_info_table[i].idx = i;
		sock_info_table[i].state = SOCK_STATE_CONNECTING;
		sock_info_table[i].hSock = 0;
		sock_info_table[i].nNet = 0;
		sock_info_table[i].watchdog = 0;
		/*IP地址序和nsap是相反的*/
		sock_info_table[i].ip_addr = device_node_table[i].IP1;
		sock_info_table[i].ip_addr2 = device_node_table[i].IP2;
	}
	/*tp0_initialize 接收缓冲区按装置数分配*/
}

extern INIT_INFO callingInitInfo[];
extern INIT_INFO initRespInfo[];
extern MVL_NET_INFO *mvl_calling_conn_ctrl;

ST_VOID ResetNetInfo(ST_INT nACSI)
{
	if (acsi_ctrl_table[nACSI].pnet_info)
		acsi_ctrl_table[nACSI].pnet_info = NULL;
	memset(&acse_conn_table[nACSI], 0 ,sizeof (ACSE_CONN));
	acse_conn_table[nACSI].idx = nACSI;
	memset(&req_pend_table[nACSI], 0 ,sizeof (MVL_REQ_PEND));
	memset(&commEvent_table[nACSI], 0 ,sizeof (MVL_COMM_EVENT));
	memset(&callingInitInfo[nACSI], 0, sizeof (INIT_INFO));
	memset(&initRespInfo[nACSI], 0, sizeof (INIT_INFO));

	mvl_calling_conn_ctrl[nACSI].req_pend_list = NULL;
	//	memset(&mvl_calling_conn_ctrl[nACSI], 0, sizeof (MVL_NET_INFO));
	//	mvl_calling_conn_ctrl[nACSI].nACSI = nACSI;
}

ST_RET ConnectToServer()
{
	ST_RET ret = SD_FAILURE;
	ST_INT i = 0;

	for (i=0; i<numDevice; i++)
	{
		if (sock_info_table == NULL)
			break;

		if (sock_info_table[i].net_error && sock_info_table[i].bSpawn)
			continue;

		if ((sock_info_table[i].nNet < 1) && sock_info_table[i].bSpawn)
			continue;

		if (acsi_ctrl_table[i].CMD == CMD_CONNECT)
		{
			if (acsi_ctrl_table[i].g_timeOut++ > 30)
			{
				acsi_ctrl_table[i].g_timeOut = 0;
				acsi_ctrl_table[i].needConnect = SD_TRUE;
			}
			else
				continue;
		}
		
		if (NULL != acsi_ctrl_table[i].pnet_info)
		{
			disconnectFromServer((MVL_NET_INFO *)acsi_ctrl_table[i].pnet_info);
			ResetNetInfo(i);
		}

		ret = connect_proc(i, SD_TRUE, NULL);
		if (ret!=SD_SUCCESS)
			return SD_FAILURE;	
	}

	return ret;
}

ST_VOID SetThreadExit(ST_BOOLEAN bExit)
{
	gExit = bExit;
}

ST_BOOLEAN GetThreadExit()
{
	return gExit;
}

ST_VOID ThreadCountAddRef()
{
	gThreadCounter = gThreadCounter + 1;
}

ST_VOID ThreadCountRelease()
{
	gThreadCounter = gThreadCounter - 1;
}

ST_INT GetThreadCount()
{
	return gThreadCounter;
}
