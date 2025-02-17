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
#include "memOBJTree.h"
#include "61850.h"
#include "time.h"
#include "..\..\..\inc\mvl_defs.h"

extern ST_BOOLEAN bSCADA;
extern ST_BOOLEAN bOBJTree;
extern HANDLE hmemOBJTree;
extern ST_UCHAR *pmemOBJTree;
extern ST_INT	numDevice;
extern ACSI_NODE *pACSINode;
extern ST_INT g_timeOut;
extern MVL_CFG_INFO mvlCfg; 
extern RPT_TYPEIDS rpt_typeids;

#ifdef _use_rptCtl
tagRptCtl rptCtl[MAX_DEVICE];
#endif

extern MVL_NET_INFO *connectToServer (ST_CHAR *clientARName, ST_CHAR *serverARName, ST_INT nACSI, ST_CHAR *psw);
extern ST_RET named_var_write ( MVL_NET_INFO *netInfo, ST_CHAR *varName,
	ST_INT scope, ST_CHAR *domName,
	ST_INT type_id,	ST_VOID *dataSrc, ST_INT timeOut);
extern ST_RET ReadnumZone(ST_INT nACSI);
extern ST_RET ReadActSG(ST_INT nACSI);

// extern ST_RET OperSBOw(ST_INT nACSI, ST_CHAR *pOper, ST_INT type_id, ST_INT iValue, 
// 	ST_INT fValue, ST_INT test, ST_INT check);

#ifdef DEBUG_SISCO
SD_CONST static ST_CHAR *SD_CONST thisFileName = __FILE__;
#endif




ST_VOID timer_proc(ST_INT addms)
{
	ST_INT i;
	for(i=0; i<numDevice; i++)
	{
		acsi_ctrl_table[i].g_timeOut +=addms;
	}
}

ST_RET connect_proc(ST_INT nACSI, ST_BOOLEAN isStart, ST_CHAR *psw)
{
	//static ST_INT i = 0;
// 	ST_CHAR buf[100];

	log_printf ("connect server %d\n", nACSI);
	acsi_ctrl_table[nACSI].g_timeOut = 0;
	acsi_ctrl_table[nACSI].needConnect = SD_FALSE;
	acsi_ctrl_table[nACSI].IsEnd = STAT_WAIT;
	acsi_ctrl_table[nACSI].CMD = CMD_CONNECT;
	req_pend_table[nACSI].done = SD_FALSE;
	acsi_ctrl_table[nACSI].pnet_info = 
		(ST_UCHAR*)connectToServer (mvlCfg.local_ar_name, rem_dib_table[nACSI].name, nACSI, psw);

	if(NULL != acsi_ctrl_table[nACSI].pnet_info)
	{
#ifdef _use_Prompt
		log_printf ("connect server %d success\n", nACSI);
		sprintf(buf,"成功连接装置%d-%d-%d-%d",
			*((ST_UCHAR *)&device_node_table[nACSI].IP1),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+1),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+2),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+3));
		Prompt(buf);
#endif
		acsi_ctrl_table[nACSI].g_timeOut = 0;
		acsi_ctrl_table[nACSI].CMD = CMD_NULL;
		acsi_ctrl_table[nACSI].IsEnd = STAT_END;
		((MVL_NET_INFO *)acsi_ctrl_table[nACSI].pnet_info)->nACSI = nACSI;

		return SD_SUCCESS;
	}
	else
	{
		//		acsi_ctrl_table[nACSI].needConnect = SD_TRUE;
		acsi_ctrl_table[nACSI].CMD = CMD_CONNECT;
		acsi_ctrl_table[nACSI].g_timeOut = 0;
		acsi_ctrl_table[nACSI].IsEnd = STAT_TIMEOUT;
	}

	return SD_FAILURE;
}

/************************************************************************/
/* 								connectToServer 						*/
/************************************************************************/
INIT_INFO callingInitInfo[MAX_DEVICE];
INIT_INFO initRespInfo[MAX_DEVICE];

static MVL_NET_INFO *connectToServer (ST_CHAR *clientARName, ST_CHAR *serverARName, ST_INT nACSI, ST_CHAR *psw)
{
	ST_RET ret;
	MVL_REQ_PEND *reqCtrl;
	MVL_NET_INFO *clientNetInfo = NULL;

//#if defined(S_SEC_ENABLED) || defined(ACSE_AUTH_ENABLED)
	ACSE_AUTH_INFO      authInfoStr = {0};
//#endif

#if defined(S_SEC_ENABLED)
	S_SEC_ENCRYPT_CTRL encryptCtrlStr = {0};
	S_SEC_LOC_AR       *loc_ar_sec = NULL;
	S_SEC_REM_AR       *rem_ar_sec = NULL;
#endif

	ACSE_AUTH_INFO     *authInfo = NULL;	/* conn authentication info	*/
	S_SEC_ENCRYPT_CTRL *encryptCtrl = NULL;	/* conn enctryption info	*/

	callingInitInfo[nACSI].mms_p_context_pres = SD_TRUE;
	callingInitInfo[nACSI].max_segsize_pres = SD_TRUE;
	callingInitInfo[nACSI].max_segsize = mvl_cfg_info->max_msg_size;
	callingInitInfo[nACSI].maxreq_calling = 1;
	callingInitInfo[nACSI].maxreq_called = 1;
	callingInitInfo[nACSI].max_nest_pres = SD_TRUE;
	callingInitInfo[nACSI].max_nest = 5;
	callingInitInfo[nACSI].mms_detail_pres = SD_TRUE;
	callingInitInfo[nACSI].version = 1;
	callingInitInfo[nACSI].num_cs_init = 0;
	callingInitInfo[nACSI].core_position = 0;
	callingInitInfo[nACSI].param_supp[0] = m_param[0];
	callingInitInfo[nACSI].param_supp[1] = m_param[1];
	memcpy (callingInitInfo[nACSI].serv_supp, m_service_resp,11);

#if defined(S_SEC_ENABLED)
	authInfo = &authInfoStr;
	encryptCtrl = &encryptCtrlStr;
	/* set authentication and encryption infor for this connection */
	ret = ulSetSecurityCalling (clientARName, serverARName,
		&loc_ar_sec, &rem_ar_sec,
		authInfo, encryptCtrl);
	if (ret != SD_SUCCESS)
	{
		log_printf ("\n Initialization of security info failed");
		return (NULL);	/* error	*/
	}
#elif defined(ACSE_AUTH_ENABLED)
	/* Fill out an authentication structure */
	authInfo = &authInfoStr;
	authInfo->auth_pres = SD_TRUE;
	authInfo->mech_type = ACSE_AUTH_MECH_PASSWORD;
	strcpy (authInfo->u.pw_auth.password, "mypassword");	/* this is the password */
#endif  /* defined(ACSE_AUTH_ENABLED) */

	if (psw != NULL)
	{
		if (*psw != 0)
		{
			authInfo = &authInfoStr;
			authInfo->auth_pres = SD_TRUE;
			authInfo->mech_type = ACSE_AUTH_MECH_PASSWORD;
			strcpy (authInfo->u.pw_auth.password, psw);	/* this is the password */
		}
	}

	ret = mvla_initiate_req_ex (serverARName, &callingInitInfo[nACSI], 
		&initRespInfo[nACSI], &clientNetInfo, &reqCtrl,
		authInfo, encryptCtrl);

	if (ret == SD_SUCCESS)
	{
#if defined(S_SEC_ENABLED)
		/* Save the AR Security pointers, for convenience when the confirm is rxd	*/
		clientNetInfo->loc_ar_sec = loc_ar_sec;
		clientNetInfo->rem_ar_sec = rem_ar_sec;
#endif

		req_pend_table[nACSI].reconnect = SD_TRUE;
		ret = waitReqDone (reqCtrl, g_timeOut, nACSI);
	}
	if (ret != SD_SUCCESS)
		clientNetInfo = NULL;
#if defined(S_SEC_ENABLED)
	ulFreeAssocSecurity (authInfo); /* free local auth info, not needed anymore	*/
#endif
	mvl_free_req_ctrl (reqCtrl);
	return (clientNetInfo);
}

/************************************************************************/
/*			disconnectFromServer										*/
/************************************************************************/
ST_RET disconnectFromServer (MVL_NET_INFO *clientNetInfo)
{
	MVL_REQ_PEND *reqCtrl;

	mvla_concl (clientNetInfo, &reqCtrl);

	//lijq 2018-10-23  断开连接等待的时间降低到5秒(zhouhj20190128: 2s)
	//waitReqDone (reqCtrl, g_timeOut, clientNetInfo->nACSI);
	waitReqDone (reqCtrl, 2, clientNetInfo->nACSI);
	
	mvl_free_req_ctrl (reqCtrl);
	clientNetInfo->numpend_req = 0;
	return (SD_SUCCESS);
}

ST_RET disconnectFromServerEx(ST_INT nDeviceIndex)
{
	SOCK_INFO *sock_info = NULL;
	ST_INT ping_ret = 0;
	PIPE_MSG_BUFS *pMsgBuf = NULL;
	sock_info = &sock_info_table[nDeviceIndex];

	if (sock_info_table == NULL)
	{
		return (SD_SUCCESS); 
	}

	if (sock_info->hSock == 0)
	{
		return (SD_SUCCESS);
	}

	ping_ret =ping(sock_info->ip_addr);  	

	if (ping_ret)
	{
		if (NULL != acsi_ctrl_table[nDeviceIndex].pnet_info)
		{
			disconnectFromServer((MVL_NET_INFO *)acsi_ctrl_table[nDeviceIndex].pnet_info);
		}
	}

	if (sock_info_table[nDeviceIndex].hSock != 0)
	{
		np_disconnect_req(&sock_info_table[nDeviceIndex]);
	}

	//请空所有的报文
	pMsgBuf = &g_pPipeMsgBuffs[nDeviceIndex];
	mms_set_bufs_parse(pMsgBuf);

	return (SD_SUCCESS);
}

#ifdef _use_rptCtl

VOID StartRCB(ST_INT nACSI)
{
	ST_INT	i;
	ST_CHAR rcbName[NAMESIZE];
	ST_CHAR *prcbName;
	ST_CHAR *pLDName;


	for(i=0; i<pACSINode[nACSI].numRCB; i++)
	{
		if(acsi_ctrl_table[nACSI].startRCB[i] == SD_FALSE)
			continue;
		acsi_ctrl_table[nACSI].bShow = SD_TRUE;
		strcpy(rcbName, pACSINode[nACSI].rcb[i].rcbName);
		prcbName = strpbrk(rcbName,"/");
		*(prcbName++) = 0;
		pLDName = rcbName;
		if(strstr(prcbName, "$BR$"))
			start_iec_brcb((MVL_NET_INFO *)acsi_ctrl_table[nACSI].pnet_info, 
			pLDName,	
			prcbName, 
			"", 
			&rpt_typeids,
			i);
		else
			start_iec_urcb((MVL_NET_INFO *)acsi_ctrl_table[nACSI].pnet_info,
			pLDName,
			prcbName,
			&rpt_typeids,
			i);
		acsi_ctrl_table[nACSI].startRCB[i] = SD_FALSE;
	}
}

VOID StopRCB(ST_INT nACSI)
{
	ST_INT	i;

	if(SD_TRUE != acsi_ctrl_table[nACSI].bShow)
		return;

	for(i=0; i<pACSINode[nACSI].numRCB; i++)
	{
		if(acsi_ctrl_table[nACSI].stopRCB[i] == SD_FALSE)
			continue;
		rcb_disable(nACSI, i);
		acsi_ctrl_table[nACSI].startRCB[i] = SD_FALSE;
	}
}

#endif

/************************************************************************/
/*						start_iec_brcb									*/
/*BRCB的rptid以BR开头，输入参数为domname，brcbname，entryid				*/
/*URCB的rptid以UR开头, 输入参数为domname，urcbname  					*/
/************************************************************************/

#define  RCB_CREATE_ERROR	1
#define  RCB_ENABLE_ERROR	2

#ifdef _use_rptCtl

ST_RET start_iec_brcb (MVL_NET_INFO *clientNetInfo, ST_CHAR* domname, ST_CHAR* brcbname, ST_CHAR* entryid, RPT_TYPEIDS *rpt_typeids, ST_INT nRCB)
{
	ST_RET ret;
	RCB_INFO *rcb_info;		/* UCA/IEC Report Control Block info */
	ST_UCHAR OptFlds [2];	/* 10 bit bitstring but only allow write of 9 bits*/
	ST_UCHAR TrgOps [1];	/* 8 bit bitstring	*/
	ST_CHAR  brname[80];

	rcb_info = rcb_info_create (clientNetInfo, rpt_typeids, nRCB);
	if (rcb_info)
	{
		/* Save the (RCB_INFO *) in "user_info" member of MVL_NET_INFO
		* (user_info must NOT be used for anything else). When a disconnect occurs,
		* "rcb_info_destroy" must be called to free up the resources
		* (see "disc_ind_fun").
		* NOTE: only ONE RCB can be monitored on a connection because there is no
		*     way to differentiate between reports received. If more than one RCB
		*     must be monitored, each RCB must be on a separate connection.
		*/ 
		sprintf(brname, "BR%02d", nRCB+1);
		//clientNetInfo->user_info[nRCB] = rcb_info;

		/* Enable options we want to see in IEC-61850 report. */
		OptFlds [0] = 0;
		BSTR_BIT_SET_ON(OptFlds, OPTFLD_BITNUM_SQNUM);
		BSTR_BIT_SET_ON(OptFlds, OPTFLD_BITNUM_TIMESTAMP);
		BSTR_BIT_SET_ON(OptFlds, OPTFLD_BITNUM_REASON);
		BSTR_BIT_SET_ON(OptFlds, OPTFLD_BITNUM_DATSETNAME);
		/* NOTE: these options ONLY available for IEC-61850 (not UCA)
		* SUBSEQNUM is only set by the server, so don't try to set it.
		* BUFOVFL valid for BRCB but meaningless for URCB, so don't set
		* BUFOVFL for URCB.
		*/
		BSTR_BIT_SET_ON(OptFlds, OPTFLD_BITNUM_BUFOVFL);	/* for BRCB only*/
		BSTR_BIT_SET_ON(OptFlds, OPTFLD_BITNUM_ENTRYID);
		BSTR_BIT_SET_ON(OptFlds, OPTFLD_BITNUM_DATAREF);
		BSTR_BIT_SET_ON(OptFlds, OPTFLD_BITNUM_CONFREV);
		BSTR_BIT_SET_ON(OptFlds, OPTFLD_BITNUM_SUBSEQNUM);

		TrgOps [0] = 0;	/* enable ALL triggers	*/
		BSTR_BIT_SET_ON(TrgOps, 1);
		BSTR_BIT_SET_ON(TrgOps, 4);
		BSTR_BIT_SET_ON(TrgOps, 5);

		ret = rcb_enable (clientNetInfo, domname, brcbname, OptFlds, TrgOps,
			10000,		/* Integrity Period (ms) */
			rpt_typeids,
			brname,
			rptCtl[clientNetInfo->nACSI].EntryID[nRCB],	
			10,
			SD_TRUE);		/* timeout (s)	*/
		if(ret)
			ret = RCB_ENABLE_ERROR;
		else
		{
			ret = 0;
			enable_gi(clientNetInfo->nACSI, nRCB);
		}
	}
	else
		ret = RCB_CREATE_ERROR;
	return ret;
}


ST_RET start_iec_urcb (MVL_NET_INFO *clientNetInfo,  ST_CHAR* domname, ST_CHAR* urcbname, RPT_TYPEIDS *rpt_typeids, ST_INT nRCB)
{
	ST_RET	 ret;
	RCB_INFO *rcb_info;		/* UCA/IEC Report Control Block info */
	ST_UCHAR OptFlds [2];	/* 10 bit bitstring but only allow write of 9 bits*/
	ST_UCHAR TrgOps [1];	/* 8 bit bitstring	*/
	ST_CHAR	 urname[80];

	rcb_info = rcb_info_create (clientNetInfo, rpt_typeids, nRCB);
	if (rcb_info)
	{
		/* Save the (RCB_INFO *) in "user_info" member of MVL_NET_INFO
		* (user_info must NOT be used for anything else). When a disconnect occurs,
		* "rcb_info_destroy" must be called to free up the resources
		* (see "disc_ind_fun").
		* NOTE: only ONE RCB can be monitored on a connection because there is no
		*     way to differentiate between reports received. If more than one RCB
		*     must be monitored, each RCB must be on a separate connection.
		*/ 
		sprintf(urname, "UR%02d", nRCB+1);
		//clientNetInfo->user_info[nRCB] = rcb_info;

		/* Enable options we want to see in IEC-61850 report.	*/
		OptFlds [0] = 0;
		BSTR_BIT_SET_ON(OptFlds, OPTFLD_BITNUM_SQNUM);
		BSTR_BIT_SET_ON(OptFlds, OPTFLD_BITNUM_TIMESTAMP);
		BSTR_BIT_SET_ON(OptFlds, OPTFLD_BITNUM_REASON);
		BSTR_BIT_SET_ON(OptFlds, OPTFLD_BITNUM_DATSETNAME);
		/* NOTE: these options ONLY available for IEC-61850 (not UCA)
		* SUBSEQNUM is only set by the server, so don't try to set it.
		* BUFOVFL valid for BRCB but meaningless for URCB, so don't set
		* BUFOVFL for URCB.
		*/
		//BSTR_BIT_SET_ON(OptFlds, OPTFLD_BITNUM_BUFOVFL);	/* for BRCB only*/
		//BSTR_BIT_SET_ON(OptFlds, OPTFLD_BITNUM_ENTRYID);
		BSTR_BIT_SET_ON(OptFlds, OPTFLD_BITNUM_DATAREF);
		//BSTR_BIT_SET_ON(OptFlds, OPTFLD_BITNUM_CONFREV);
		BSTR_BIT_SET_ON(OptFlds, OPTFLD_BITNUM_SUBSEQNUM);

		TrgOps [0] = 0;	/* enable ALL triggers	*/
		BSTR_BIT_SET_ON(TrgOps, 1);
		BSTR_BIT_SET_ON(TrgOps, 4);
		BSTR_BIT_SET_ON(TrgOps, 5);
		ret = rcb_enable (clientNetInfo, domname, urcbname, OptFlds, TrgOps,
			3000,		/* Integrity Period (ms)	*/
			rpt_typeids,
			urname,
			rptCtl[clientNetInfo->nACSI].EntryID[nRCB], 	
			10,
			SD_FALSE);		/* timeout (s)	*/
		if(ret)
			ret = RCB_ENABLE_ERROR;
		else
			ret = 0;
	}
	else
		ret = RCB_CREATE_ERROR;
	return ret;
}
#endif

ST_VOID enable_gi(ST_INT nACSI, ST_INT nRCB)
{
	ST_RET ret = SD_SUCCESS;
	ST_BOOLEAN GI = 1;
	ST_CHAR rcbName[NAMESIZE];
	ST_CHAR *prcbName;
	ST_CHAR *pLDName;
	ST_CHAR varName[NAMESIZE];
	ST_BOOLEAN RptEna = 0;

	strcpy(rcbName, pACSINode[nACSI].rcb[nRCB].rcbName);
	prcbName = strpbrk(rcbName,"/");
	*(prcbName++) = 0;
	pLDName = rcbName;
	sprintf (varName, "%s$GI", prcbName);
	ret = named_var_write ((MVL_NET_INFO *)acsi_ctrl_table[nACSI].pnet_info, varName, DOM_SPEC, pLDName, rpt_typeids.mmsbool, (ST_CHAR *) &GI, g_timeOut);
}

ST_VOID rcb_disable(ST_INT nACSI, ST_INT nRCB)
{
	ST_RET ret = SD_SUCCESS;
	ST_CHAR rcbName[NAMESIZE];
	ST_CHAR *prcbName;
	ST_CHAR *pLDName;
	ST_CHAR varName[NAMESIZE];
	ST_BOOLEAN RptEna = 0;

	if(acsi_ctrl_table[nACSI].stopRCB[nRCB] == SD_FALSE)
		return;

	acsi_ctrl_table[nACSI].stopRCB[nRCB] = SD_FALSE;
	strcpy(rcbName, pACSINode[nACSI].rcb[nRCB].rcbName);
	prcbName = strpbrk(rcbName,"/");
	*(prcbName++) = 0;
	pLDName = rcbName;
	sprintf (varName, "%s$RptEna", prcbName);
	ret = named_var_write ((MVL_NET_INFO *)acsi_ctrl_table[nACSI].pnet_info, varName, DOM_SPEC, pLDName, rpt_typeids.mmsbool, (ST_CHAR *) &RptEna, g_timeOut);
}

ST_RET get_rcb_member(ST_INT nACSI, ST_INT rcbIdx, RPT_TYPEIDS *rpt_typeids)
{
	ST_CHAR ldName[NAMESIZE];
	ST_CHAR *prcbName;
	ST_CHAR varName[NAMESIZE];
	ST_CHAR dsName[NAMESIZE];
	MVL_NET_INFO *net_info;

	net_info = (MVL_NET_INFO*)(acsi_ctrl_table[nACSI].pnet_info);
	_snprintf(ldName, NAMESIZE-1, "%s", pACSINode[nACSI].rcb[rcbIdx].rcbName);
	prcbName = strchr(ldName, '/');
	if(0 == prcbName)
		return SD_FAILURE;
	*prcbName = 0;
	prcbName++;

	strcpy (varName, prcbName);
	strcat (varName, "$DatSet");
	if (named_var_read (net_info, varName, DOM_SPEC, ldName, rpt_typeids->vstring65, dsName, g_timeOut))
	{	/* can't read data set name	*/
		return (SD_FAILURE);
	}
	_snprintf(pACSINode[nACSI].rcb[rcbIdx].dsName, NAMESIZE-1, "%s",dsName);
	return (SD_SUCCESS);
}

ST_RET test_net_proc(ST_INT nACSI, ST_BOOLEAN isStart)
{
	MVL_NET_INFO *net_info;
	NAMELIST_REQ_INFO getnam_req;
	ST_RET	ret;
	MVL_REQ_PEND *reqCtrl;

	net_info = (MVL_NET_INFO*)(acsi_ctrl_table[nACSI].pnet_info);
	acsi_ctrl_table[nACSI].CMD = CMD_NULL;
	acsi_ctrl_table[nACSI].g_timeOut = 0;
	acsi_ctrl_table[nACSI].IsEnd = STAT_END;
	acsi_ctrl_table[nACSI].idleCount = 0;

	acsi_ctrl_table[nACSI].needTest = SD_FALSE;

	getnam_req.cs_objclass_pres = SD_FALSE;
	getnam_req.obj.mms_class = 9;  /*9;*/	
	getnam_req.objscope = VMD_SPEC;
	getnam_req.cont_after_pres = SD_FALSE;
	req_pend_table[nACSI].done = SD_FALSE;
	net_info->numpend_req = 0;
	ret = mvla_getnam (net_info, &getnam_req, &reqCtrl);
	if (ret == SD_SUCCESS)
	{
		ret = waitReqDone (reqCtrl, g_timeOut, net_info->nACSI);
		if (ret != SD_SUCCESS)
		{
			log_printf ("test server %d timeout\n", nACSI);
			ret = SD_FAILURE;
		}
		else
		{
			log_printf ("test server %d success\n", nACSI);
			acsi_ctrl_table[nACSI].testCount = 0;
			acsi_ctrl_table[nACSI].CMD = CMD_NULL;
			acsi_ctrl_table[nACSI].g_timeOut = 0;
			acsi_ctrl_table[nACSI].IsEnd = STAT_END;
			acsi_ctrl_table[nACSI].idleCount = 0;
			ret = SD_SUCCESS;
		}
	}
	else
	{
		log_printf ("test server %d fail\n", nACSI);
		ret = SD_FAILURE;
	}

	if(ret == SD_FAILURE)
	{
		if(acsi_ctrl_table[nACSI].testCount++ > 1)
		{
			sock_info_table[nACSI].net_error = SD_TRUE;
			acsi_ctrl_table[nACSI].testCount = 0;
			acsi_ctrl_table[nACSI].idleCount = 0;
			acsi_ctrl_table[nACSI].needConnect = SD_TRUE;
			acsi_ctrl_table[nACSI].needDirectory = SD_FALSE;
			acsi_ctrl_table[nACSI].CMD = CMD_NULL;
			acsi_ctrl_table[nACSI].IsEnd = STAT_END;
			Sleep(1000);
		}
	}
	mvl_free_req_ctrl (reqCtrl);
	return ret;
}

/*已建立的MMS变量基本类型
BOOLEAN_TYPEID
INT8_TYPEID
INT16_TYPEID
INT32_TYPEID
INT128_TYPEID
INT8U_TYPEID
INT16U_TYPEID
INT32U_TYPEID
FLOAT32_TYPEID
FLOAT64_TYPEID
ENUMERATED8_TYPEID
ENUMERATED16_TYPEID
OCTET_STRING8_TYPEID
OCTET_STRING64_TYPEID
VISIBLE_STRING255_TYPEID
VISIBLE_STRING64_TYPEID
VISIBLE_STRING97_TYPEID
UTC_TM_TYPEID
CODED_ENUM2_TYPEID
UNICODE_STRING255_TYPEID
EntryTime_TYPEID
Quality_TYPEID
IDENT_TYPEID
*/

/************************************************************************/
/*                       named_var_read									*/
/* Read a single named variable.										*/
/*   scope = VMD_SPEC, DOM_SPEC, or AA_SPEC								*/
/* CRITICAL: the local variable "parse_info" is written indirectly 		*/
/*           from waitReqDone when the response is received. The call	*/
/*           to "waitReqDone" MUST NOT be moved outside this function.	*/
/************************************************************************/
ST_RET named_var_read ( MVL_NET_INFO *net_info, ST_CHAR *varName,
	ST_INT scope, ST_CHAR *domName,
	ST_INT type_id, ST_VOID *dataDest, ST_INT timeOut)
{
	ST_INT num_data;
	ST_CHAR buffer[512];
	MVL_READ_RESP_PARSE_INFO parse_info;
	READ_REQ_INFO *req_info;
	VARIABLE_LIST *vl;
	ST_INT ret;
	MVL_REQ_PEND *reqCtrl;

	/* Create a read request info struct  */
	req_info = (READ_REQ_INFO *) buffer;
	req_info->spec_in_result = SD_FALSE;
	req_info->va_spec.var_acc_tag = VAR_ACC_VARLIST;
	req_info->va_spec.num_of_variables = 1;
	vl = (VARIABLE_LIST *) (req_info + 1);

	vl->alt_access_pres = SD_FALSE;
	vl->var_spec.var_spec_tag = VA_SPEC_NAMED;
	vl->var_spec.vs.name.object_tag = scope;	/* set scope	*/
	if (scope == DOM_SPEC)
		vl->var_spec.vs.name.domain_id = domName;	/* set domain name	*/
	vl->var_spec.vs.name.obj_name.vmd_spec = varName;

	num_data = 1;     /* Number of named variables returned	*/

	/* IMPORTANT: start with clean structure, then set appropriate elements.*/
	memset (&parse_info, 0, sizeof (parse_info));
	parse_info.dest = dataDest;
	parse_info.type_id = type_id;
	parse_info.descr_arr = SD_FALSE;

	/* Send read request. */
	ret = mvla_read_variables (net_info,req_info,num_data,
		&parse_info, &reqCtrl);

	/* If request sent successfully, wait for reply. */
	if (ret == SD_SUCCESS)
		ret = waitReqDone (reqCtrl, timeOut, net_info->nACSI);

	mvl_free_req_ctrl (reqCtrl);

	if (ret != SD_SUCCESS)
		return (ret);

	return ( parse_info.result);	/* Return the single variable result */
}

/************************************************************************/
/*			named_var_write												*/
/* Write a single named variable.										*/
/*   scope = VMD_SPEC, DOM_SPEC, or AA_SPEC								*/
/* CRITICAL: the local variable "wr_info" is written indirectly 		*/
/*           from waitReqDone when the response is received. The call	*/
/*           to "waitReqDone" MUST NOT be moved outside this function.	*/
/************************************************************************/
ST_RET named_var_write (MVL_NET_INFO *netInfo, ST_CHAR *varName,
	ST_INT scope, ST_CHAR *domName,
	ST_INT type_id,	ST_VOID *dataSrc, ST_INT timeOut)
{
	ST_CHAR buffer[512];
	MVL_WRITE_REQ_INFO *wr_info;
	WRITE_REQ_INFO	*req_info;
	VARIABLE_LIST	*vl;
	ST_RET	ret;
	MVL_REQ_PEND	*reqCtrl;

	req_info = (WRITE_REQ_INFO *) buffer;
	req_info->num_of_data = 1;
	req_info->va_spec.var_acc_tag = VAR_ACC_VARLIST;
	req_info->va_spec.num_of_variables = 1;
	vl = (VARIABLE_LIST *) (req_info + 1);

	vl->alt_access_pres = SD_FALSE;
	vl->var_spec.var_spec_tag = VA_SPEC_NAMED;
	vl->var_spec.vs.name.object_tag = scope;		/* set scope */
	if (scope == DOM_SPEC)
		vl->var_spec.vs.name.domain_id = domName;	/* set domain name	*/
	vl->var_spec.vs.name.obj_name.vmd_spec = varName;

	/* Alloc array of structs. Here only one var so alloc one struct.	*/
	/* To read multiple vars, allocate more.							*/
	/* CRITICAL: response code writes to this struct. Do not free until	*/
	/*           response received.										*/ 
	wr_info = chk_calloc (1, sizeof (MVL_WRITE_REQ_INFO));

	wr_info->local_data = dataSrc;
	wr_info->type_id = type_id;
	wr_info->arr = SD_FALSE;

	/* Send write request.	*/
	ret = mvla_write_variables(netInfo, req_info, 1, wr_info, &reqCtrl);

	/* If request sent successfully, wait for response.	*/
	if (ret == SD_SUCCESS)
		ret = waitReqDone(reqCtrl, timeOut, netInfo->nACSI);

	mvl_free_req_ctrl(reqCtrl);
	if (ret == SD_SUCCESS)	/* response received OK.	*/
		ret = wr_info->result;	/* return single variable result	*/
	chk_free (wr_info);

	return (ret);
}

/*保护定值处理*/
/*
保护定值的CDC数据类包括：
单点状态定值SPG
整数定值ING
模拟定值ASG
定值曲线CURVE
保护定值的数据类型：
setVal       BOOLEAN       SPG
setVal       INT32	       ING
setMag$i	 INT32	       ING	
setMag$f     FLOAT32	   ASG  
*/
#ifdef _use_tagSGCB

tagSGCB SGCB;
/*获取与装置相关的所有定值变量的指针*/
ST_VOID BuildSGCB(ST_INT nACSI)
{
	ST_INT i;
	ST_INT num;
	ST_INT idx = 0;
	ST_INT index = 0;
	ST_CHAR VarName[NAMESIZE];
	num = pACSINode[nACSI].numDA;	
	for(i=0; i<num; i++)
	{
		if(pACSINode[nACSI].DA[i].DataType[0]=='S')
			continue;
		_snprintf(VarName, NAMESIZE-1, "%s", pACSINode[nACSI].DA[i].DAValue.mmsName);
		_strupr(VarName);
		if(strstr(VarName,"$SG$"))
			SGCB.pSG[idx++] = &pACSINode[nACSI].DA[i];
		else if(strstr(VarName,"$SE$"))
			SGCB.pSE[index++] = &pACSINode[nACSI].DA[i];
		else if(strstr(VarName,"$SGCB$NUMOFSG"))
			SGCB.pnumZone = &pACSINode[nACSI].DA[i];
		else if(strstr(VarName,"$SGCB$ACTSG"))
			SGCB.pActSG = &pACSINode[nACSI].DA[i];
		else if(strstr(VarName,"$SGCB$EDITSG"))
			SGCB.pEditSG = &pACSINode[nACSI].DA[i];
		else if(strstr(VarName,"$SGCB$CNFEDIT"))
			SGCB.pCnfEdit = &pACSINode[nACSI].DA[i];
		else if(strstr(VarName,"$SGCB$LACTTIM"))
			SGCB.pLActTm = &pACSINode[nACSI].DA[i];
	}
	SGCB.numSG = idx;

	ReadnumZone(nACSI);
	ReadActSG(nACSI);
}


/*读定值组数函数*/
ST_RET ReadnumZone(ST_INT nACSI)
{
	ST_RET	ret;
	MVL_NET_INFO *net_info;
	ST_CHAR VarName[NAMESIZE+1];
	ST_CHAR *pLDName;
	ST_CHAR *mmsVarName;
	ST_INT  var;
// 	ST_CHAR buf[100];

	_snprintf(VarName, NAMESIZE-1, "%s", SGCB.pnumZone->DAValue.mmsName);
	pLDName = strchr(VarName, '/');
	if(pLDName==NULL)
		return SD_SUCCESS;
	*pLDName = 0;
	mmsVarName = pLDName+1;
	net_info = (MVL_NET_INFO*)(acsi_ctrl_table[nACSI].pnet_info);
	ret = named_var_read(net_info,mmsVarName,DOM_SPEC,VarName,INT8U_TYPEID,&var,g_timeOut);
	if(SD_SUCCESS == ret)
	{
		SGCB.numZone = var;
		SGCB.pnumZone->DAValue.Value.l = var;

#ifdef _use_Prompt
		sprintf(buf, "装置%d-%d-%d-%d 定值组数=%d",
			*((ST_UCHAR *)&device_node_table[nACSI].IP1),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+1),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+2),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+3),
			SGCB.numZone
			);
		Prompt(buf);
#endif
	}
	return ret;
}

/*读运行定值区号函数*/
ST_RET ReadActSG(ST_INT nACSI)
{
	ST_RET ret;
	MVL_NET_INFO *net_info;
	ST_CHAR VarName[NAMESIZE+1];
	ST_CHAR *pLDName;
	ST_CHAR *mmsVarName;
// 	ST_CHAR buf[100];
	ST_INT var;

	_snprintf(VarName, NAMESIZE-1, "%s", SGCB.pActSG->DAValue.mmsName);
	pLDName = strchr(VarName, '/');
	if(pLDName==NULL)
		return SD_SUCCESS;
	*pLDName = 0;
	mmsVarName = pLDName+1;
	net_info = (MVL_NET_INFO*)(acsi_ctrl_table[nACSI].pnet_info);
	ret = named_var_read(net_info,mmsVarName,DOM_SPEC,VarName,INT8U_TYPEID,&var,g_timeOut);
	if(SD_SUCCESS == ret)
	{
		SGCB.ActSG = var;
		SGCB.pActSG->DAValue.Value.l = var;

#ifdef _use_Prompt
		sprintf(buf, "装置%d-%d-%d-%d 运行定值区=%d",
			*((ST_UCHAR *)&device_node_table[nACSI].IP1),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+1),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+2),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+3),
			SGCB.ActSG
			);
		Prompt(buf);
#endif
	}
	return ret;
}

/*读编辑定值区号函数*/
ST_RET ReadEditSG(ST_INT nACSI)
{
	ST_RET ret;
	MVL_NET_INFO *net_info;
	ST_CHAR VarName[NAMESIZE+1];
	ST_CHAR *pLDName;
	ST_CHAR *mmsVarName;
// 	ST_CHAR buf[100];
	ST_INT var;

	_snprintf(VarName, NAMESIZE-1, "%s", SGCB.pEditSG->DAValue.mmsName);
	pLDName = strchr(VarName, '/');
	if(pLDName==NULL)
		return SD_SUCCESS;
	*pLDName = 0;
	mmsVarName = pLDName+1;
	net_info = (MVL_NET_INFO*)(acsi_ctrl_table[nACSI].pnet_info);
	ret = named_var_read(net_info,mmsVarName,DOM_SPEC,VarName,INT8U_TYPEID,&var,g_timeOut);
	if(SD_SUCCESS == ret)
	{
		SGCB.EditSG = var;
		SGCB.pEditSG->DAValue.Value.l = var;

#ifdef _use_Prompt
		sprintf(buf, "装置%d-%d-%d-%d 运行定值区=%d",
			*((ST_UCHAR *)&device_node_table[nACSI].IP1),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+1),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+2),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+3),
			SGCB.EditSG
			);
		Prompt(buf);
#endif
	}
	return ret;
}

/*设置编辑定值区函数*/
ST_RET SetEditSGZone(ST_INT nACSI, ST_INT zone)
{
	ST_RET ret;
	MVL_NET_INFO *net_info;
	ST_CHAR VarName[NAMESIZE+1];
	ST_CHAR *pLDName;
	ST_CHAR *mmsVarName;
	//ST_CHAR buf[100];

	SGCB.EditSG = zone;
	_snprintf(VarName, NAMESIZE-1, "%s", SGCB.pEditSG->DAValue.mmsName);
	pLDName = strchr(VarName, '/');
	if(pLDName==NULL)
		return SD_SUCCESS;

	*pLDName = 0;
	mmsVarName = pLDName+1;
	net_info = (MVL_NET_INFO*)(acsi_ctrl_table[nACSI].pnet_info);
	ret = named_var_write(net_info,mmsVarName,DOM_SPEC,VarName,INT8U_TYPEID,&zone,g_timeOut);
	if(SD_SUCCESS == ret)
	{
#ifdef _use_Prompt
		sprintf(buf, "装置%d-%d-%d-%d 设定编辑定值区为%d",
			*((ST_UCHAR *)&device_node_table[nACSI].IP1),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+1),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+2),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+3),
			SGCB.EditSG
			);
		Prompt(buf);
#endif
	}
	return ret;
}

/*设置运行定值区函数*/
ST_RET SetActSGZone(ST_INT nACSI, ST_INT zone)
{
	ST_RET ret;
	MVL_NET_INFO *net_info;
	ST_CHAR VarName[NAMESIZE+1];
	ST_CHAR *pLDName;
	ST_CHAR *mmsVarName;
	//ST_CHAR buf[100];

	SGCB.ActSG = zone;
	_snprintf(VarName, NAMESIZE-1, "%s", SGCB.pActSG->DAValue.mmsName);
	pLDName = strchr(VarName, '/');
	if(pLDName==NULL)
		return SD_SUCCESS;
	*pLDName = 0;
	mmsVarName = pLDName+1;
	net_info = (MVL_NET_INFO*)(acsi_ctrl_table[nACSI].pnet_info);
	ret = named_var_write(net_info,mmsVarName,DOM_SPEC,VarName,INT8U_TYPEID,&zone,g_timeOut);

	if(SD_SUCCESS == ret)
	{
#ifdef _use_Prompt
		sprintf(buf, "装置%d-%d-%d-%d 设定运行定值区为%d",
			*((ST_UCHAR *)&device_node_table[nACSI].IP1),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+1),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+2),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+3),
			SGCB.ActSG
			);
		Prompt(buf);
#endif
	}
	return ret;
}
#endif

ST_INT ClarifymmsVarName(ST_CHAR *mmsVarName)
{
	ST_CHAR	*pstr;
	ST_INT count;
	count = 0;
	pstr = mmsVarName;
	for(;;)
	{
		pstr = strchr(pstr, '$');
		if(NULL == pstr)
			break;
		pstr++;
		count++;
	}
	return  count;
}

ST_RET set_FCDA_type(ST_INT el_tag, ST_CHAR *pType)
{
	switch(el_tag)
	{
	case RT_BOOL:
		sprintf(pType, "BOOL");
		break;
	case RT_BIT_STRING:
		sprintf(pType, "BIT_STR");
		break;
	case RT_INTEGER:
		sprintf(pType, "INT");
		break;
	case RT_UNSIGNED:
		sprintf(pType, "UINT");
		break;
	case RT_FLOATING_POINT:
		sprintf(pType, "FLOAT");
		break;
	case RT_OCTET_STRING:
		sprintf(pType, "OCT_STR");
		break;
	case RT_VISIBLE_STRING:
		sprintf(pType, "V_STR");
		break;
	case RT_GENERAL_TIME:
		sprintf(pType, "G_TIME");
		break;
	case RT_BINARY_TIME:
		sprintf(pType, "B_TIME");
		break;
	case RT_BOOLEANARRAY:
		sprintf(pType, "BOOL[]");
		break;
	case RT_UTC_TIME:
		sprintf(pType, "UTC_TIME");
		break;
	case RT_UTF8_STRING:
		sprintf(pType, "UTF8_STR");
		break;
	}

	return (SD_SUCCESS);
}

#ifdef _use_tagSGCB

/*设置确认服务函数*/
ST_RET SetCnfEdit(ST_INT nACSI)
{
	ST_RET ret;
	MVL_NET_INFO *net_info;
	ST_CHAR VarName[NAMESIZE+1];
	ST_CHAR *pLDName;
	ST_CHAR *mmsVarName;
	//ST_CHAR buf[100];

	SGCB.CnfEdit = 1;
	_snprintf(VarName, NAMESIZE-1, "%s", SGCB.pCnfEdit->DAValue.mmsName);
	pLDName = strchr(VarName, '/');
	if(pLDName==NULL)
		return SD_SUCCESS;
	*pLDName = 0;
	mmsVarName = pLDName+1;
	net_info = (MVL_NET_INFO*)(acsi_ctrl_table[nACSI].pnet_info);
	ret = named_var_write(net_info,mmsVarName,DOM_SPEC,VarName,BOOLEAN_TYPEID,&SGCB.CnfEdit,g_timeOut);
	if(SD_SUCCESS == ret)
	{
#ifdef _use_Prompt
		sprintf(buf, "装置%d-%d-%d-%d 成功执行定值区%d修改",
			*((ST_UCHAR *)&device_node_table[nACSI].IP1),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+1),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+2),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+3),
			SGCB.EditSG
			);
		Prompt(buf);
#endif
	}	
	return ret;
}

/*读服务函数*/
ST_RET ReadSG(ST_INT nACSI, ST_INT zone)
{
	ST_RET ret;
	MVL_NET_INFO *net_info;
	ST_CHAR VarName[NAMESIZE+1];
	ST_CHAR *pLDName;
	ST_CHAR *mmsVarName;
	ST_INT	i;
	ST_CHAR *p;
	ST_INT  type_id = -1;
	//ST_CHAR buf[100];

	if(-1 != zone)
	{
		ret = SetEditSGZone(nACSI, zone);
		if(ret != SD_SUCCESS)
			return SD_FAILURE;
	}

	net_info = (MVL_NET_INFO*)(acsi_ctrl_table[nACSI].pnet_info);
	for(i=0; i<SGCB.numSG; i++)
	{
		_snprintf(VarName, NAMESIZE-1, "%s", SGCB.pSG[i]->DAValue.mmsName);
		pLDName = strchr(VarName, '/');
		if(pLDName==NULL)
			return SD_SUCCESS;

		*pLDName = 0;
		mmsVarName = pLDName+1;

		if(-1!=zone)
		{
			//读编辑定值，将$SG$换成$SE$	
			p = strstr(mmsVarName,"$SG$");
			*(p+2) = 'E';
		}

		if(strstr(SGCB.pSG[i]->DataType,"BOOL")){
			type_id = BOOLEAN_TYPEID;
		}else if(strstr(SGCB.pSG[i]->DataType,"INT")){
			type_id = INT32_TYPEID;
		}else if(strstr(SGCB.pSG[i]->DataType,"UINT")){
			type_id = INT32U_TYPEID;
		}else if(strstr(SGCB.pSG[i]->DataType,"FLOAT")){
			type_id = FLOAT32_TYPEID;
		}

		if(-1 != type_id)
		{
			if(-1 == zone)
				ret = named_var_read(net_info,mmsVarName,DOM_SPEC,VarName,type_id, &SGCB.pSG[i]->DAValue.Value.l, g_timeOut);
			else
				ret = named_var_read(net_info,mmsVarName,DOM_SPEC,VarName,type_id, &SGCB.pSE[i]->DAValue.Value.l, g_timeOut);
		}
	}

	if(-1!=zone)
	{
#ifdef _use_Prompt
		sprintf(buf, "装置%d-%d-%d-%d 读定值区%d服务结束",
			*((ST_UCHAR *)&device_node_table[nACSI].IP1),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+1),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+2),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+3),
			SGCB.EditSG
			);
		Prompt(buf);
#endif
	}
	else
	{
#ifdef _use_Prompt
		sprintf(buf, "装置%d-%d-%d-%d 读运行定值区=%d服务结束",
			*((ST_UCHAR *)&device_node_table[nACSI].IP1),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+1),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+2),
			*((ST_UCHAR *)&device_node_table[nACSI].IP1+3),
			SGCB.ActSG
			);
		Prompt(buf);
#endif
	}
	return ret;
}

/*写服务函数*/
ST_RET WriteSG(ST_INT nACSI)
{
	/*首先判断数据是否修改，对修改的数据执行写操作*/
	ST_RET ret;
	MVL_NET_INFO *net_info;
	ST_CHAR VarName[NAMESIZE+1];
	ST_CHAR *pLDName;
	ST_CHAR *mmsVarName;
	ST_INT	i;
	ST_INT  type_id = -1;
	ST_UCHAR buf[80];

	for (i=0; i<SGCB.numSG; i++)
	{
		if (SGCB.pSE[i]->bModify!=1)
			continue;
		_snprintf(VarName, NAMESIZE-1, "%s", SGCB.pSE[i]->DAValue.mmsName);
		pLDName = strchr(VarName, '/');
		if(pLDName==NULL)
			return SD_FAILURE;
		*pLDName = 0;
		mmsVarName = pLDName+1;
		/*
		//读编辑定值，将$SG$换成$SE$	
		p = strstr(mmsVarName,"$SG$");
		*(p+2) = 'E';
		*/
		memset(buf, 0, 8);
		if(strstr(SGCB.pSG[i]->DataType,"BOOL")){
			type_id = BOOLEAN_TYPEID;
			*(ST_BOOLEAN *)buf = (ST_CHAR)SGCB.pSE[i]->DAValue.Value.l;
		}
		else if(strstr(SGCB.pSG[i]->DataType,"INT"))
		{
			type_id = INT32_TYPEID;
			*(ST_INT32 *)buf = SGCB.pSE[i]->DAValue.Value.l;
		}
		else if(strstr(SGCB.pSG[i]->DataType,"UINT"))
		{
			type_id = INT32U_TYPEID;
			*(ST_INT32 *)buf = SGCB.pSE[i]->DAValue.Value.l;
		}
		else if(strstr(SGCB.pSG[i]->DataType,"FLOAT"))
		{
			type_id = FLOAT32_TYPEID;
			*(ST_FLOAT *)buf = SGCB.pSE[i]->DAValue.Value.f;
		}

		if(-1 != type_id)
		{
			net_info = (MVL_NET_INFO*)(acsi_ctrl_table[nACSI].pnet_info);
			ret = named_var_write(net_info,mmsVarName,DOM_SPEC,VarName,type_id, buf, g_timeOut);
		}
		else
			ret = SD_FAILURE;
	}
	return ret;
}

#endif
/*遥控处理：带值选择，执行，取消*/
/*同期合闸：合闸方式字反映检无压*/
/*SBO非带值选择 SBOw带值选择*/
/*遥控选择对象：SBOw  ctlVal, Test=0, Check=1*/
/*遥控执行对象：Oper*/
/*遥控取消对象：Cancel*/

ST_INT typeID_Oper;
ST_INT typeID_Cancel;
ST_INT typeID_SBOw;

//ST_RET SelectTypeID(ST_INT nACSI, ST_CHAR *pOper)
//{
//	ST_INT  i, numDA;
//	ST_RET  ret = SD_FAILURE;
//
//	typeID_Oper = -1;
//	typeID_Cancel = -1;
//
//	numDA = pACSINode[nACSI].numDA;
//	for(i=0; i<numDA; i++)
//	{
//		if(0==strstr(pACSINode[nACSI].DA[i].mmsVARName, pOper))
//			continue;
//		if(pACSINode[nACSI].DA[i].DataType[0]=='U')
//		{
//			typeID_Oper = mvl_typename_to_typeid("SBOw_INTU");
//			typeID_Cancel = mvl_typename_to_typeid("Cancel_INTU");
//			ret = SD_SUCCESS;
//			break;
//		}
//		else if(pACSINode[nACSI].DA[i].DataType[0]=='I')
//		{
//			typeID_Oper = mvl_typename_to_typeid("SBOw_INT");
//			typeID_Cancel = mvl_typename_to_typeid("Cancel_INT");
//			ret = SD_SUCCESS;
//			break;
//		}
//		else if(0 == _stricmp(pACSINode[nACSI].DA[i].DataType, "BOOL"))
//		{
//			typeID_Oper = mvl_typename_to_typeid("SBOw_BOOL");
//			typeID_Cancel = mvl_typename_to_typeid("Cancel_BOOL");
//			ret = SD_SUCCESS;
//			break;
//		}
//	}
//	return ret;
//}

ST_VOID Prompt(ST_CHAR *p)
{
// 	gs_mutex_get(&gs_soe_mutex);
// 	if(pSOEFIFO->numSOE < MAX_SOE_RPT)
// 	{
// 		sprintf(&pSOEFIFO->SoeRPT[pSOEFIFO->writep%MAX_SOE_RPT][0], "%s", p);
// 		pSOEFIFO->numSOE++;
// 		pSOEFIFO->writep =  (pSOEFIFO->writep+1)%MAX_SOE_RPT;
// 	}
// 	gs_mutex_free(&gs_soe_mutex);					
}

/*
nACSI:  装置号
pOper_ctlVal :被控对象的变量名 例如：PRS311LD1/LLN0$CO$LEDRs$Oper$ctlVal
*/
ST_INT JudgeControlMode(ST_INT nACSI, ST_CHAR *pOper_ctlVal, ST_CHAR *pSBOw, ST_CHAR *pOper)
{
	return -1;
//	MVL_NET_INFO *net_info;	
//	ST_INT	ret = -1;
//	ST_CHAR *p;
//	ST_CHAR varname[NAMESIZE];
//	ST_CHAR *pLDName;
//	ST_CHAR *mmsVarName;
//	ST_INT  ctlmodel;
//
//	strcpy(varname, pOper_ctlVal);
//
//	p = strstr(varname, "$ctlVal");
//	if(p)
//		*(p) = 0;
//
//	sprintf(pOper,"%s",varname);
//
//	p = strstr(varname, "$Oper");
//	if(p)
//		*(p+1) = 0;
//	else
//	{
//		p = strstr(varname, "$oper");
//		if(p)
//			*(p+1) = 0;
//	}
//	sprintf(pSBOw,"%s$SBOw",varname);
//
//	strcat(varname, "$ctlModel");
//	p = strstr(varname, "$CO$");
//	if(p)
//		*(p+2) = 'F';
//	else 
//		return ret;
//
//// 	pLDName = strchr(varname, '/');
//// 	if( pLDName == NULL )
//// 		return SD_SUCCESS;
//// 
//// 	*pLDName = 0;
//// 	mmsVarName = pLDName + 1;
//
//	net_info = (MVL_NET_INFO*)(acsi_ctrl_table[nACSI].pnet_info);
////	ret = named_var_read(net_info, mmsVarName, DOM_SPEC,varname,INT8_TYPEID,&ctlmodel,timeOut);
//	ret = named_var_read(net_info, mmsVarName, DOM_SPEC,varname,INT8_TYPEID,&ctlmodel,timeOut);
//	if(ret == SD_SUCCESS)
//		return ctlmodel;
//	else
//		return -1;
}

ST_INT GetOper(MVL_NET_INFO *net_info, ST_CHAR *pOper, ST_INT nACSI)
{
	ST_CHAR OperName[NAMESIZE+1];
	GETVAR_REQ_INFO getvar_req;
	VAR_ACC_TSPEC *type_spec;
	ST_RET  ret = SD_SUCCESS;
	ST_INT  type_id;
	MVL_REQ_PEND *reqCtrl;
	ST_CHAR *pDOM, *mmsVarName;
	ACSI_NODE *pDvNode = &pACSINode[nACSI];

	_snprintf(OperName, NAMESIZE-1, "%s", pOper);
	pDOM = strchr(OperName, '/');
	if(pDOM==NULL)
		return SD_SUCCESS;
	*pDOM = 0;
	mmsVarName = pDOM+1;

	getvar_req.req_tag = GETVAR_NAME;
	getvar_req.name.domain_id = OperName;
	getvar_req.name.object_tag = DOM_SPEC;
	getvar_req.name.obj_name.item_id = mmsVarName;

	ret = mvla_getvar (net_info, &getvar_req, &reqCtrl);
	if(ret == SD_SUCCESS)
		ret = waitReqDone(reqCtrl,g_timeOut,nACSI);
	else
	{
		mvl_free_req_ctrl (reqCtrl);
		return -1;
	}

	if(ret == SD_SUCCESS)
	{
		type_spec = &(reqCtrl->u.getvar.resp_info->type_spec);
#ifdef _MVL_TYPE_CTRL_use_one_device_
		type_id = mvl_type_id_create (NULL, type_spec->data, type_spec->len, pDvNode->p_mvl_type_ctrl);
#else
		type_id = mvl_type_id_create (NULL, type_spec->data, type_spec->len);
#endif
	
		if(-1 == type_id)
		{
			log_printf("type_id = -1 getvar %s ", pOper);
			mvl_free_req_ctrl (reqCtrl);
			return  -1;
		}
		else
		{
			return type_id;
		}

		mvl_free_req_ctrl (reqCtrl);
	}

	return -1;
}

#ifdef _MVL_TYPE_CTRL_use_one_device_
ST_RET SelectSBOw(ST_INT nACSI, ST_CHAR *pOper, ST_INT iValue, ST_INT fValue, ST_INT test, ST_INT check, MVL_TYPE_CTRL *mvl_type_ctrl)
#else
ST_RET SelectSBOw(ST_INT nACSI, ST_CHAR *pOper, ST_INT iValue, ST_INT fValue, ST_INT test, ST_INT check)
#endif
{
	ST_RET ret;
	ST_INT i;
	MVL_NET_INFO *net_info;
	ST_CHAR OperName[NAMESIZE+1];
	ST_CHAR SBOwName[NAMESIZE+1];

	ST_CHAR	*pLDName;
	ST_CHAR	*mmsVarName;
	ST_UCHAR  buf[200];
	RUNTIME_TYPE *rt_out;
	ST_INT num_rt_out;
	ST_UCHAR *p;
	ST_INT8 ctlmodel = 0;

	ctlmodel = JudgeControlMode(nACSI, pOper, SBOwName, OperName);	
	if(-1 == ctlmodel)
	{
#ifdef _use_Prompt
		Prompt("获取遥控模式错误");
#endif
		return SD_FAILURE;
	}
	else
	{
#ifdef _use_Prompt
		sprintf(buf, "遥控模式=%d", ctlmodel);
		Prompt(buf);
#endif
	}

	//	ret = SelectTypeID(nACSI, pOper);
	//	if(ret == SD_FAILURE){
	//		Prompt("获取遥控数据类型错误");
	//		return SD_FAILURE;
	//	}

	net_info = (MVL_NET_INFO*)(acsi_ctrl_table[nACSI].pnet_info);
	typeID_Oper = GetOper(net_info,  OperName, nACSI);

	if((ctlmodel == 1)||(ctlmodel == 3))
	{
#ifdef _MVL_TYPE_CTRL_use_one_device_
		ret = OperSBOw(nACSI, OperName, typeID_Oper, iValue, iValue, 0, 0, mvl_type_ctrl);
#else
		ret = OperSBOw(nACSI, OperName, typeID_Oper, iValue, iValue, 0, 0);
#endif

#ifdef _use_Prompt
		if(ret == SD_SUCCESS)
			Prompt("遥控执行成功");		
		else
			Prompt("遥控执行失败");	
#endif

#ifdef _MVL_TYPE_CTRL_use_one_device_
		mvl_type_id_destroy(typeID_Oper, mvl_type_ctrl);
#else
		mvl_type_id_destroy(typeID_Oper);
#endif
		return ret;
	}

	pLDName = strchr(SBOwName, '/');
	if(pLDName==NULL)
		return SD_SUCCESS;
	*pLDName = 0;
	mmsVarName = pLDName+1;

#ifdef _MVL_TYPE_CTRL_use_one_device_
	if(SD_SUCCESS != mvl_get_runtime (typeID_Oper, &rt_out, &num_rt_out, mvl_type_ctrl))
		return SD_ERROR;	
#else
	if(SD_SUCCESS != mvl_get_runtime (typeID_Oper, &rt_out, &num_rt_out))
		return SD_ERROR;	
#endif
	p = buf;
	memset(buf, 0, 200);

	for(i=0; i<num_rt_out; i++)
	{
		if((rt_out+i)->comp_name_ptr==NULL)
			continue;
		if(!_stricmp((rt_out+i)->comp_name_ptr, "ctlVal"))
			*(ST_UCHAR *)p = iValue;
		else if(!_stricmp((rt_out+i)->comp_name_ptr, "setMag"))
			*(ST_FLOAT *)p = (ST_FLOAT)fValue;
		else if(!_stricmp((rt_out+i)->comp_name_ptr, "Test"))
			*(ST_UCHAR *)p = 0;     //iValue;
		else if(!_stricmp((rt_out+i)->comp_name_ptr, "orCat"))
			*(ST_UCHAR *)p = 2;
		else if(!_stricmp((rt_out+i)->comp_name_ptr, "orIdent"))
		{
			*(ST_UCHAR *)p = 1;
			*(ST_UCHAR *)(p+2) = 0x20;
		}
		else if(!_stricmp((rt_out+i)->comp_name_ptr, "Check"))
		{
			*(ST_UCHAR *)p = 0;     //check;
		}
		p = p + (rt_out+i)->el_size;
	}
	ret = named_var_write(net_info,mmsVarName,DOM_SPEC,SBOwName,typeID_Oper, buf, g_timeOut);

	if(ret == SD_SUCCESS)
	{
#ifdef _use_Prompt
		Prompt("遥控选择成功");
#endif

#ifdef _MVL_TYPE_CTRL_use_one_device_
		ret = OperSBOw(nACSI, OperName, typeID_Oper, iValue, iValue, 0, 0, mvl_type_ctrl);
#else
		ret = OperSBOw(nACSI, OperName, typeID_Oper, iValue, iValue, 0, 0);
#endif

#ifdef _use_Prompt
		if(ret == SD_SUCCESS)
			Prompt("遥控执行成功");		
		else    
			Prompt("遥控执行失败");	
#endif
	}
	else
	{
#ifdef _use_Prompt
		Prompt("遥控选择错误");
#endif
	
#ifdef _MVL_TYPE_CTRL_use_one_device_
		mvl_type_id_destroy(typeID_Oper, mvl_type_ctrl);
#else
		mvl_type_id_destroy(typeID_Oper);
#endif
		return ret;
	}

#ifdef _MVL_TYPE_CTRL_use_one_device_
	mvl_type_id_destroy(typeID_Oper, mvl_type_ctrl);
#else
	mvl_type_id_destroy(typeID_Oper);
#endif
	return ret;
}

#ifdef _MVL_TYPE_CTRL_use_one_device_
ST_RET OperSBOw(ST_INT nACSI, ST_CHAR *pOper, ST_INT type_id, ST_INT iValue, ST_INT fValue, ST_INT test, ST_INT check, MVL_TYPE_CTRL *mvl_type_ctrl)
#else
ST_RET OperSBOw(ST_INT nACSI, ST_CHAR *pOper, ST_INT type_id, ST_INT iValue, ST_INT fValue, ST_INT test, ST_INT check)
#endif
{
	ST_RET ret;
	ST_INT i;
	MVL_NET_INFO *net_info;
	ST_CHAR VarName[NAMESIZE+1];
	ST_CHAR	*pLDName;
	ST_CHAR	*mmsVarName;
	ST_UCHAR  buf[200];
	RUNTIME_TYPE *rt_out;
	ST_INT num_rt_out;
	ST_UCHAR *p;

	_snprintf(VarName, NAMESIZE-1, "%s", pOper);
	pLDName = strchr(VarName, '/');
	if(pLDName==NULL)
		return SD_SUCCESS;
	*pLDName = 0;
	mmsVarName = pLDName+1;

#ifdef _MVL_TYPE_CTRL_use_one_device_
	if(SD_SUCCESS != mvl_get_runtime (type_id, &rt_out, &num_rt_out, mvl_type_ctrl))
		return SD_ERROR;	
#else
	if(SD_SUCCESS != mvl_get_runtime (type_id, &rt_out, &num_rt_out))
		return SD_ERROR;	
#endif
	p = buf;
	memset(buf, 0, 200);
	for(i=0; i<num_rt_out; i++)
	{
		if((rt_out+i)->comp_name_ptr==NULL)
			continue;
		if(!_stricmp((rt_out+i)->comp_name_ptr, "ctlVal"))
			*(ST_UCHAR *)p = iValue;
		else if(!_stricmp((rt_out+i)->comp_name_ptr, "setMag"))
			*(ST_FLOAT *)p = (ST_FLOAT)fValue;
		else if(!_stricmp((rt_out+i)->comp_name_ptr, "Test"))
			*(ST_UCHAR *)p = 0;     //iValue;
		else if(!_stricmp((rt_out+i)->comp_name_ptr, "orCat"))
			*(ST_UCHAR *)p = 2;
		else if(!_stricmp((rt_out+i)->comp_name_ptr, "orIdent"))
		{
			*(ST_UCHAR *)p = 1;
			*(ST_UCHAR *)(p+2) = 0x20;
		}
		else if(!_stricmp((rt_out+i)->comp_name_ptr, "Check"))
			*(ST_UCHAR *)p = 0;     //check;

		p = p + (rt_out+i)->el_size;
	}
	net_info = (MVL_NET_INFO*)(acsi_ctrl_table[nACSI].pnet_info);
	ret = named_var_write(net_info,mmsVarName,DOM_SPEC,VarName,typeID_Oper, buf, g_timeOut);
	return ret;
}

#ifdef _MVL_TYPE_CTRL_use_one_device_
ST_RET CancelSBOw(ST_INT nACSI, ST_CHAR *pOper, ST_INT type_id, ST_INT iValue, ST_INT fValue, ST_INT test, MVL_TYPE_CTRL *mvl_type_ctrl)
#else
ST_RET CancelSBOw(ST_INT nACSI, ST_CHAR *pOper, ST_INT type_id, ST_INT iValue, ST_INT fValue, ST_INT test)
#endif
{
	ST_RET ret;
	ST_INT i;
	MVL_NET_INFO *net_info;
	ST_CHAR VarName[NAMESIZE+1];
	ST_CHAR	*pLDName;
	ST_CHAR	*mmsVarName;
	ST_UCHAR  buf[200];
	RUNTIME_TYPE *rt_out;
	ST_INT num_rt_out;
	ST_UCHAR *p;

	_snprintf(VarName, NAMESIZE-1, "%s", pOper);

	p = strstr(VarName, "SBOw");
	if(p == NULL)
	{
		p = strstr(VarName, "SBOw");
	}
	strcpy(p,"Cancel");

	pLDName = strchr(VarName, '/');
	if(pLDName==NULL)
		return SD_SUCCESS;
	*pLDName = 0;
	mmsVarName = pLDName+1;

#ifdef _MVL_TYPE_CTRL_use_one_device_
	if(SD_SUCCESS != mvl_get_runtime (type_id, &rt_out, &num_rt_out, mvl_type_ctrl))
		return SD_ERROR;	
#else
	if(SD_SUCCESS != mvl_get_runtime (type_id, &rt_out, &num_rt_out))
		return SD_ERROR;	
#endif

	p = buf;
	memset(buf, 0, 200);
	for(i=0; i<num_rt_out; i++)
	{
		if(_stricmp((rt_out+i)->comp_name_ptr, "ctlVal"))
			*(ST_UCHAR *)p = iValue;		
		else if(_stricmp((rt_out+i)->comp_name_ptr, "setMag"))
			*(ST_FLOAT *)p = (ST_FLOAT)fValue;
		else if(_stricmp((rt_out+i)->comp_name_ptr, "Test"))
			*(ST_UCHAR *)p = iValue;
		p = p + (rt_out+i)->el_size;
	}

	net_info = (MVL_NET_INFO*)(acsi_ctrl_table[nACSI].pnet_info);
	ret = named_var_write(net_info,mmsVarName,DOM_SPEC,VarName,type_id, buf, g_timeOut);
	return ret;
}

// tagDA * find_da_byname(ST_INT nACSI, ST_CHAR *mmsVarName)
// {
// 	ST_INT i;
// 	ST_INT numDA;
// 	tagDA *pRet = NULL;
// 	numDA = pACSINode[nACSI].numDA;
// 	for(i=0; i<numDA; i++)
// 	{
// 		if(0==_stricmp(mmsVarName, pACSINode[nACSI].DA[i].mmsVARName))
// 		{
// 			pRet = &pACSINode[nACSI].DA[i];
// 			break;
// 		}
// 	}
// 	return pRet;
// }

XMMS_FILE_SYS_OBJ* check_repeat_of_sysobj(char *pName, XMMS_FILE_SYS_OBJ *pFileDir)
{
	XMMS_FILE_SYS_OBJ *pFind = NULL;
	XMMS_FILE_SYS_OBJ *pSubFileDir = NULL;
	int nIndex = 0;

	for(nIndex = 0;nIndex<pFileDir->subFiles.numOfData;nIndex++)
	{
		pSubFileDir = (XMMS_FILE_SYS_OBJ *)*(pFileDir->subFiles.Datas + nIndex);

		if (strcmp(mms_string(&pSubFileDir->filedir.filename),pName) == 0)
		{
			pFind = pSubFileDir;
			break;
		}
	}

	return pFind;
}

ST_RET mark_old_file(XMMS_FILE_SYS_OBJ *pFileDir)
{
	XMMS_FILE_SYS_OBJ *pSubFileDir = NULL;
	ST_INT nIndex = 0;

	if (pFileDir == NULL)
	{
		return 0;
	}

	for(nIndex = 0;nIndex<pFileDir->subFiles.numOfData;nIndex++)
	{
		pSubFileDir = (XMMS_FILE_SYS_OBJ *)*(pFileDir->subFiles.Datas + nIndex);

		if (pSubFileDir->nType == 0)
		{
			pSubFileDir->bIsNew = FALSE;
		}
	}

	return 1;
}

/*SCADA由命令队列通知客户机：取目录 取文件*/
/*客户机取道后响应队列通知SCADA，目录存放在dir.txt中，录波文件在文件名后加yymmdd后缀*/
//pfilespec ="/COMTRADE/"   "/METR/"
ST_RET get_dir(ST_INT nACSI, ST_CHAR *pfilespec,XMMS_FILE_SYS_OBJ *pFileDir/*, ST_CHAR *ppathname*/,ST_BOOLEAN bOnlyReadCfg)
{
	MVL_FDIR_RESP_INFO *fdir_resp;
	MVL_REQ_PEND *reqCtrl = NULL;
	MVL_NET_INFO *net_info;
	ST_RET ret;
	//FILE *loc_fp;
	ST_INT i,j,nType,nLenth;
	ST_BOOLEAN more_follows;
	ST_CHAR  ca_name[100]="";
	//struct tm *pdate;
	PXMMS_FILE_SYS_OBJ pSubDir = NULL;
	XMMS_FILE_SYS_OBJ *pFind = NULL;
	char *pszName = NULL;

	more_follows = 0;

	mark_old_file(pFileDir);

	net_info = (MVL_NET_INFO *)acsi_ctrl_table[nACSI].pnet_info;

	do
	{
		ret = mvla_fdir(net_info,
			pfilespec,
			ca_name,
			&reqCtrl
			);

		if (ret == SD_SUCCESS)
			ret = waitReqDone (reqCtrl, g_timeOut, nACSI);

		if (ret != SD_SUCCESS)
		{
			log_printf ("\n mvl_fdir () Error, ret = 0x%X.", ret);
			pFileDir->readfailed = TRUE;
			break;
		}
		else
		{
			fdir_resp = reqCtrl->u.fdir.resp_info;


			for (i = 0; i < fdir_resp->num_dir_ent;  i++)
			{
				nLenth = mms_str_length(&fdir_resp->dir_ent[i].filename);
				nType = (mms_str_at(&fdir_resp->dir_ent[i].filename,nLenth-1) == '/');//根据最后一个字符查看是文件还是文件夹

				if (nType)
				{
						j = mms_reverse_find(&fdir_resp->dir_ent[i].filename,'/',2);

						if (j==-1)//zhouhj 20180321 南京易司拓装置在文件夹名称的前面没有 '/'
						pszName = mms_str_pos(&fdir_resp->dir_ent[i].filename,0);
						else
						pszName = mms_str_pos(&fdir_resp->dir_ent[i].filename,j);	
				} 
				else
				{
					if (bOnlyReadCfg)
					{
						if (nLenth>4)
						{
							if (strnicmp(mms_str_pos(&fdir_resp->dir_ent[i].filename,(nLenth-4)),".cfg",4) != 0)
							{
								continue;
							}
						}
					}

					j = mms_reverse_find(&fdir_resp->dir_ent[i].filename,'/',1);

					if (j==-1)//zhouhj 20180321 山东鲁能装置 非根目录下的文件，返回的文件名中不包括‘/’
						pszName = mms_str_pos(&fdir_resp->dir_ent[i].filename,0);
					else
						pszName = mms_str_pos(&fdir_resp->dir_ent[i].filename,j+1);//zhouhj 20180321 山东鲁能装置 根目录下用/device.icd读不出文件，参考山大软件使用device.icd可以
					// 此处读取文件时统一去掉前面的 '/'
				}

				pFind = check_repeat_of_sysobj(pszName,pFileDir);	

				if (pFind != NULL)
				{
					pFind->bIsNew = FALSE;
				} 
				else
				{
					vector_set_add_data(&pFileDir->subFiles,&pSubDir,sizeof(XMMS_FILE_SYS_OBJ));
					pSubDir->filedir = fdir_resp->dir_ent[i];
					pSubDir->bIsNew = TRUE;
					pSubDir->nType = nType;
					mms_str_init(&pSubDir->filedir.filename);
					mms_str_set(&pSubDir->filedir.filename,pszName);
					pSubDir->parent = pFileDir;
				}
			}

			more_follows = reqCtrl->u.fdir.resp_info->more_follows;

			if (more_follows)
			{
				strcpy(ca_name, mms_string(&fdir_resp->dir_ent[i-1].filename));
			}
		}

		mvl_free_req_ctrl (reqCtrl);//zhouhj 20180311 解决读取装置文件或目录数为0时，软件崩溃的问题
	}while(more_follows);

	return ret;
}

#define WAVEFILEPATH	""
ST_RET get_file(ST_INT nACSI, ST_CHAR *pfile, ST_CHAR *pszLocalPath)
{
	FREAD_REQ_INFO   fread_req_info;
	FCLOSE_REQ_INFO  fclose_req_info;
	ST_RET ret;
	FILE *loc_fp;
	MVL_REQ_PEND *reqCtrl;
	ST_INT32 frsmid;
	ST_BOOLEAN more_follows;
	MVL_NET_INFO *net_info;
	ST_CHAR pathname[200],szFileName[200];
//	memset(szFileName,0,200);
	//time_t t;
	//ST_CHAR *p;
	//struct tm *pdate;
	ST_INT i,len,pathLen;
	pathLen = -1;

	/*去除DeviceName*/
	//	pfilename = strpbrk(pfile, "/");
	//	*(pfilename++) = 0;

	net_info = (MVL_NET_INFO *)acsi_ctrl_table[nACSI].pnet_info;
	ret = mvla_fopen (net_info,
		pfile,
		0,		/* init_pos: start at beginning of file	*/
		&reqCtrl
		);

	if (ret == SD_SUCCESS)
		ret = waitReqDone (reqCtrl, g_timeOut, nACSI);

	if (ret == SD_SUCCESS)
		frsmid = reqCtrl->u.fopen.resp_info->frsmid;	/* save frsmid	*/
	mvl_free_req_ctrl (reqCtrl);

	if (ret != SD_SUCCESS)
		return (ret);

// 	time(&t);
// 	p = strrchr(pfile,'.');
// 	*p=0;
// 	pdate = localtime(&t);
	len = strlen(pfile);

	for(i=0; i<len; i++)
	{
		if(pfile[i]=='/')
		{
			pfile[i]='$';
			pathLen = i;
		}
	}

	if (pathLen != -1)
	{
		for(i=0; i<(len-pathLen); i++)
		{
			szFileName[i] = pfile[pathLen + i + 1];
		}
	} 
	else
	{
		strcpy(szFileName ,pfile);
	}

	pathLen = strlen(pszLocalPath);

	if ( pszLocalPath[pathLen-1] != '\\' )
	{
		sprintf(pathname,"%s\\%s",pszLocalPath, szFileName);
	}
	else
	{
		sprintf(pathname,"%s%s",pszLocalPath, szFileName);
	}
	
	loc_fp = fopen (pathname, "wb");
	if (loc_fp == NULL)
		return (SD_FAILURE);	/* Can't open local file. */

	fread_req_info.frsmid = frsmid;	/* "fread" request doesn't chg.	*/

	do{
		ret = mvla_fread (net_info, &fread_req_info, &reqCtrl);
		if (ret == SD_SUCCESS)
			ret = waitReqDone (reqCtrl, g_timeOut, nACSI);

		if (ret == SD_SUCCESS)
		{
			more_follows = reqCtrl->u.fread.resp_info->more_follows;
			fwrite (reqCtrl->u.fread.resp_info->filedata, 1,
				reqCtrl->u.fread.resp_info->fd_len, loc_fp);
		}

		mvl_free_req_ctrl (reqCtrl);

		if (ret != SD_SUCCESS)
			return (ret);

	}while (more_follows);

	fclose_req_info.frsmid = frsmid;
	ret = mvla_fclose (net_info, &fclose_req_info, &reqCtrl);
	if (ret == SD_SUCCESS)
		ret = waitReqDone (reqCtrl, g_timeOut, nACSI);

	if (ret != SD_SUCCESS)
		log_printf ("\n mvl_fclose failed, ret = 0x%X", ret);
	
	mvl_free_req_ctrl (reqCtrl);
	fclose (loc_fp);

	return (SD_SUCCESS);
}

//////////////////////////////////////////////////////////////////////////

// 2012-09-18  获取逻辑设备的数据
ST_RET get_varlistattri(MVL_NET_INFO *net_info, LD_NODE *pLD, ST_INT nDsIndex)
{
	ST_RET ret;
	ST_CHAR itemid[200];
	ST_INT i;

	GETVLIST_REQ_INFO  req_info;
	GETVLIST_RESP_INFO *pResp_info;
	MVL_REQ_PEND *reqCtrl;
	VARIABLE_LIST *varlist;

	memset(itemid,0,sizeof(ST_CHAR)*200);

	if (nDsIndex<0 || nDsIndex>=MAX_DASET_NUM)
		return SD_FAILURE;

	strcpy(itemid,pLD->DataInfo[nDsIndex].DataSetID); 

	/* 可以获取LD/LN0 下的定值数据 */
	req_info.vl_name.domain_id = pLD->LDName;
	req_info.vl_name.obj_name.item_id = itemid;
	req_info.vl_name.object_tag = DOM_SPEC;

	ret = mvla_getvlist(net_info,&req_info,&reqCtrl);  
	if (ret == SD_SUCCESS)
		ret = waitReqDone (reqCtrl, g_timeOut, net_info->nACSI);
	else
	{
		mvl_free_req_ctrl (reqCtrl);
	}

	if (ret != SD_SUCCESS)
	{
		mvl_free_req_ctrl (reqCtrl);
		return SD_FAILURE;
	}
	else
	{
		pResp_info = (GETVLIST_RESP_INFO*)reqCtrl->u.getvlist.resp_info;
		varlist = (VARIABLE_LIST*)(pResp_info+1);

#ifdef _use_dynamic_mem
		mms_New_LD_DATASET_INFO_numData(&pLD->DataInfo[nDsIndex], pResp_info->num_of_variables);
#else
		pLD->DataInfo[nDsIndex].numData = pResp_info->num_of_variables;	
#endif

		for (i = 0; i < pResp_info->num_of_variables; ++i)
		{
			assert (varlist->var_spec.var_spec_tag == VA_SPEC_NAMED);

#ifdef _use_mms_string
			mms_str_set(&pLD->DataInfo[nDsIndex].DataSet[i].DAValue.mmsName,
				varlist[i].var_spec.vs.name.obj_name.item_id);
#else
			strcpy(pLD->DataInfo[nDsIndex].DataSet[i].DAValue.mmsName,
				varlist[i].var_spec.vs.name.obj_name.item_id);
#endif
		}

		mvl_free_req_ctrl (reqCtrl);
	}

	return ret;
}

// 2012-09-18  获取变量的类型
#ifdef _MVL_TYPE_CTRL_use_one_device_
ST_RET get_varType(MVL_NET_INFO *net_info, ST_CHAR *LDName, ST_INT *nDAType, ST_CHAR *LNName, MVL_TYPE_CTRL *mvl_type_ctrl)
#else
ST_RET get_varType(MVL_NET_INFO *net_info, ST_CHAR *LDName, ST_INT *nDAType, ST_CHAR *LNName)
#endif
{
	ST_RET ret;
	GETVAR_REQ_INFO  getvar_req;
	MVL_REQ_PEND *reqCtrl;
	VAR_ACC_TSPEC *type_spec;
	ST_INT type_id;

	getvar_req.req_tag = GETVAR_NAME;
	getvar_req.name.domain_id = LDName;
	getvar_req.name.object_tag = DOM_SPEC;
	getvar_req.name.obj_name.item_id = LNName;

	net_info->conn_active = TRUE;

	ret = mvla_getvar(net_info, &getvar_req, &reqCtrl);  

	if (ret == SD_SUCCESS)
		ret = waitReqDone (reqCtrl, g_timeOut, net_info->nACSI);
	else
	{
		mvl_free_req_ctrl (reqCtrl);
	}

	if (ret != SD_SUCCESS)
	{
		mvl_free_req_ctrl (reqCtrl);
	}
	else
	{
		type_spec = &(reqCtrl->u.getvar.resp_info->type_spec);
#ifdef _MVL_TYPE_CTRL_use_one_device_
		type_id = mvl_type_id_create (NULL, type_spec->data, type_spec->len, mvl_type_ctrl);
#else
		type_id = mvl_type_id_create (NULL, type_spec->data, type_spec->len);
#endif

		if ( -1 == type_id)
		{
			mvl_free_req_ctrl (reqCtrl);
			return SD_FAILURE;
		}

		mvl_free_req_ctrl (reqCtrl);

		*nDAType = type_id;
	}

	return ret;
}

ST_RET get_varvalue_x(MVL_NET_INFO *net_info, ST_CHAR *varName, ST_CHAR *domName, ST_INT type_id, ST_VOID *dataDest, ST_INT num_dataDest, ST_INT nDataType)
{
	ST_INT ret;
	tagValue *pValue = (tagValue*)dataDest;
	tagValueX xValue;
	memset(&xValue, 0, sizeof(tagValueX));

	ret = get_varvalue(net_info, varName, domName, type_id, &xValue, num_dataDest);
	mms_SetValueX(pValue, &xValue,nDataType);

	return ret;
}

// 2012-09-19  读取变量的数值
ST_RET get_varvalue(MVL_NET_INFO *net_info, ST_CHAR *varName, ST_CHAR *domName, ST_INT type_id, ST_VOID *dataDest, ST_INT num_dataDest)
{
	ST_INT num_data;
	ST_CHAR buffer[512];
	MVL_READ_RESP_PARSE_INFO parse_info;
	READ_REQ_INFO *req_info;
	VARIABLE_LIST *vl;
	ST_INT ret;
	MVL_REQ_PEND *reqCtrl;

	/* Create a read request info struct */
	req_info = (READ_REQ_INFO *) buffer;
	req_info->spec_in_result = SD_FALSE;
	req_info->va_spec.var_acc_tag = VAR_ACC_VARLIST;
	req_info->va_spec.num_of_variables = 1;
	vl = (VARIABLE_LIST *) (req_info + 1);

	vl->alt_access_pres = SD_FALSE;
	vl->var_spec.var_spec_tag = VA_SPEC_NAMED;//VA_SPEC_DESCRIBED
	vl->var_spec.vs.name.object_tag = DOM_SPEC;	/* set scope */
	vl->var_spec.vs.name.domain_id = domName;	/* set domain name */
	vl->var_spec.vs.name.obj_name.vmd_spec = varName;

	num_data = num_dataDest;     /* Number of named variables returned	*/

	/* IMPORTANT: start with clean structure, then set appropriate elements.*/
	memset (&parse_info, 0, sizeof (parse_info));
	parse_info.dest = dataDest;
	parse_info.type_id = type_id;
	parse_info.descr_arr = SD_FALSE;
	
	/* Send read request. */
	ret = mvla_read_variables (net_info,req_info,num_data,&parse_info, &reqCtrl);

	/* If request sent successfully, wait for reply. */
	if (ret == SD_SUCCESS)
	{
		ret = waitReqDone (reqCtrl, g_timeOut, net_info->nACSI);
		mvl_free_req_ctrl (reqCtrl);	
	}
	else
	{
		mvl_free_req_ctrl (reqCtrl);	
		return ret;
	}

	return parse_info.result;	
}

/* 2012-10-16  设置数据的数值 */
ST_RET set_varvalue(MVL_NET_INFO *net_info, ST_CHAR *varName, ST_CHAR *domName, ST_INT type_id, ST_VOID *dataSrc)
{
	ST_CHAR buffer[512];
	MVL_WRITE_REQ_INFO *wr_info;
	WRITE_REQ_INFO	*req_info;
	VARIABLE_LIST	*vl;
	ST_RET	ret;
	MVL_REQ_PEND	*reqCtrl;

	req_info = (WRITE_REQ_INFO *) buffer;
	req_info->num_of_data = 1;
	req_info->va_spec.var_acc_tag = VAR_ACC_VARLIST;
	req_info->va_spec.num_of_variables = 1;
	vl = (VARIABLE_LIST *) (req_info + 1);

	vl->alt_access_pres = SD_FALSE;
	vl->var_spec.var_spec_tag = VA_SPEC_NAMED;
	vl->var_spec.vs.name.object_tag = DOM_SPEC;		/* set scope */
	vl->var_spec.vs.name.domain_id = domName;	/* set domain name	*/
	vl->var_spec.vs.name.obj_name.vmd_spec = varName;

	/* Alloc array of structs. Here only one var so alloc one struct.	*/
	/* To read multiple vars, allocate more.							*/
	/* CRITICAL: response code writes to this struct. Do not free until	*/
	/*           response received.										*/ 
	wr_info = chk_calloc (1, sizeof (MVL_WRITE_REQ_INFO));

	wr_info->local_data = dataSrc;
	wr_info->type_id = type_id;
	wr_info->arr = SD_FALSE;

	/* Send write request.	*/
	ret = mvla_write_variables(net_info, req_info, 1, wr_info, &reqCtrl);

	/* If request sent successfully, wait for response.	*/
	if (ret == SD_SUCCESS)
		ret = waitReqDone(reqCtrl, g_timeOut, net_info->nACSI);

	mvl_free_req_ctrl(reqCtrl);
	if (ret == SD_SUCCESS)	/* response received OK.	*/
		ret = wr_info->result;	/* return single variable result	*/
	chk_free (wr_info);

	return (ret);
}