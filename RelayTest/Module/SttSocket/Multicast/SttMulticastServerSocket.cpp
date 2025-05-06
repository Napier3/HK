#include "stdafx.h"

#include "SttMulticastServerSocket.h"
#include "../../SttGlobalDef.h"
#include "../../API/NetworkInterface.h"
#ifdef _PSX_QT_LINUX_
#include "QProcess"
#include "../../SttTestMngr/RelayTest/SttTestMngr.h"
#endif
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


CSttMulticastServerSocket::CSttMulticastServerSocket()
{
	m_strSN = _T("PSL001");
	m_strModel = _T("PSL001");
#ifdef _PSX_QT_LINUX_
	m_strLocalIP=_T("");
	m_strLocalMASK=_T("");

	memset(&m_sktMultiCast,0,sizeof(struct sockaddr_in));
	m_sktMultiCast.sin_family = AF_INET;
	m_sktMultiCast.sin_port = htons(STT_Multicast_Port);
	m_sktMultiCast.sin_addr.s_addr = inet_addr(STT_Multicast_IP);
#endif
}

CSttMulticastServerSocket::~CSttMulticastServerSocket()
{

}

BOOL CSttMulticastServerSocket::CheckMatchSN(CSttPpDatasDriver vec)
{
	CSttPpDatas *pDatas = vec.GetDatas();

	CString strSN,strModel;
	pDatas->FindDataByID(STT_PP_DATAID_SN, strSN);
	pDatas->FindDataByID(STT_PP_DATAID_MODEL, strModel);

	return (strSN == m_strSN);
}

BOOL CSttMulticastServerSocket::Process_Multicast_QueryIP(CSttPpDatasDriver vec)
{
	CStringArray astrIP,astrMask,astrGw;
	long nMetric[100];
    CString strIP, strMask;
	//需更新上面四个参数

#ifdef _PSX_QT_LINUX_
	stt_file_get_deviceip(strIP, strMask);
        astrIP.Add(strIP);
        astrMask.Add(strMask);
	stt_file_get_subips(astrIP,astrMask,astrGw,nMetric);
#endif

	long nSendBufLen = 1024;
	BYTE *pSendBuf = new BYTE[nSendBufLen];
	BYTE *pHead = pSendBuf + STT_PKG_HEAD_LEN;
	BYTE *pPos = pHead;

	stt_pp_pkt_pack_stringVal(pPos, STT_PP_DATAID_SN,m_strSN);
	stt_pp_pkt_pack_stringVal(pPos, STT_PP_DATAID_MODEL, m_strModel);
    for(int i = 0;i < astrIP.GetCount();i++)
    {
        stt_pp_pkt_pack_ipV4Val(pPos, STT_PP_DATAID_IP, astrIP.GetAt(i), astrMask.GetAt(i));
    }

	stt_InitPktBuffer_Head(pSendBuf,MULTICAST_CMD_QUERYIPS_ACK, pPos - pHead, 0, 0, 0);

	long nRet = SendBuffer(pSendBuf,pPos - pSendBuf,&m_sktMultiCast);
	delete pSendBuf;

	return nRet;
}

BOOL CSttMulticastServerSocket::Process_Multicast_SetIPs(CSttPpDatasDriver vec)
{
	if (!CheckMatchSN(vec))
	{//判断序列号是否一致，不一致直接丢弃
		return FALSE;
	}

	CSttPpDatas *pDatas = vec.GetDatas();
	CStringArray astrIP,astrMask,astrGw;
	long nMetric[100];
	CString strIP = _T(""),strMask = _T("");

	//更新错误码
    int nErrCode = 2;

    POS pos = pDatas->GetHeadPosition();
    PSTT_PP_DATA p = NULL;

    while (pos != NULL)
    {
        p = pDatas->GetNext(pos);

        if (p->id == STT_PP_DATAID_IP)
        {
            stt_pp_data_get_ipVal(p, strIP, strMask);
			nMetric[astrIP.GetCount()] = -1;
            astrIP.Add(strIP);
            astrMask.Add(strMask);
			astrGw.Add("0.0.0.0");

            nErrCode = 0;
        }
    }

    if(nErrCode > 0)
    {
        Multicast_CommonACK(MULTICAST_CMD_SETIP_ACK,m_strSN,m_strModel,nErrCode);
    }
    else
    {
        CString strPreIP,strPreMask;
        stt_file_get_deviceip(strPreIP,strPreMask);

#ifdef _PSX_QT_LINUX_
		nErrCode = stt_file_save_deviceip(astrIP.GetAt(0),astrMask.GetAt(0));//nErrCode=1,设置失败
#endif
        Multicast_CommonACK(MULTICAST_CMD_SETIP_ACK,m_strSN,m_strModel,nErrCode);
#ifdef _PSX_QT_LINUX_        

		stt_file_save_subips(astrIP, astrMask, astrGw, nMetric, 1);

        strIP = astrIP.GetAt(0);
        if(strPreIP == strIP)
        {
			stt_net_set_subips(astrIP, astrMask,2);
        }
        else
        {
            system("reboot");
        }
#endif
    }

	return TRUE;
}

BOOL CSttMulticastServerSocket::Process_Multicast_StartOffProcess(CSttPpDatasDriver vec)
{
	if (!CheckMatchSN(vec))
	{//判断序列号是否一致，不一致直接丢弃
		return FALSE;
	}

	CSttPpDatas *pDatas = vec.GetDatas();
	POS pos = pDatas->GetHeadPosition();
	STT_PP_DATA *p = NULL;
	CString strProc;

#ifdef _PSX_QT_LINUX_
	std::string line;
	BOOL bRet = callcmd("ps -eo etime,args | grep Stt",line);
	if(!bRet)
	{
		return FALSE;
	}

	CString strRes = CString::fromStdString(line);
	CString strData;
		pos = pDatas->GetHeadPosition();
		while (pos!=NULL)
		{
			p = pDatas->GetNext(pos);
			if(!stt_pp_data_get_string(p,strProc))
				continue;

			if(p->id ==  STT_PP_DATAID_CLOSE_PROC)
			{
			if(strRes.contains(strProc))
				{
				int nPos = strRes.indexOf(strProc);
				strData = strRes.left(nPos);

				nPos = strData.lastIndexOf(":");
				strData = strData.mid(nPos+1,3);
				strData = strData.left(2);
				if(strData.toInt() < 10)
						{
							//更新错误码 底层服务未完全启动,不可关闭
							int nErrCode = 1;
							Multicast_CommonACK(MULTICAST_CMD_PROCESS_ACK,m_strSN,m_strModel,nErrCode);

							return TRUE;
						}
					}
				}
			}

#endif

	pos = pDatas->GetHeadPosition();
	while (pos!=NULL)
	{
		p = pDatas->GetNext(pos);
		if(!stt_pp_data_get_string(p,strProc))
			continue;

		if (p->id ==  STT_PP_DATAID_RUN_PROC)
		{			//启动进程
#ifdef _PSX_QT_LINUX_
			CSttTestMngr::g_pTestMngr->StartProcess(strProc);
#endif
		}
		else if (p->id ==  STT_PP_DATAID_CLOSE_PROC)
		{			//关闭进程
			CString strCmd;
			strCmd.Format(_T("pkill -9 %s"),strProc.GetString());
#ifdef _PSX_QT_LINUX_
			system(strCmd.toUtf8());
#endif
		}
	}

	//更新错误码
	int nErrCode = 0;
	Multicast_CommonACK(MULTICAST_CMD_PROCESS_ACK,m_strSN,m_strModel,nErrCode);

	return TRUE;
}

BOOL CSttMulticastServerSocket::Process_Multicast_QueryState(CSttPpDatasDriver vec)
{
	if (!CheckMatchSN(vec))
	{//判断序列号是否一致，不一致直接丢弃
		return FALSE;
	}

	//获取当前服务状态

	//更新错误码
	int nErrCode = 0;

	long nSendBufLen = 1024;
	BYTE *pSendBuf = new BYTE[nSendBufLen];

	BYTE *pHead = pSendBuf + STT_PKG_HEAD_LEN;
	BYTE *pPos = pHead;
	stt_pp_pkt_pack_stringVal(pPos,STT_PP_DATAID_SN,m_strSN);
	stt_pp_pkt_pack_stringVal(pPos,STT_PP_DATAID_MODEL,m_strModel);
	stt_pp_pkt_pack_longVal(pPos,STT_PP_DATAID_RUNSTATE, nErrCode);

	//获取当前服务状态
#ifdef _PSX_QT_LINUX_
	std::string line;
	BOOL bRet = callcmd("ps -eo etime,args | grep Stt",line);
	if(!bRet)
	{
		return FALSE;
	}

	CString strData = CString::fromStdString(line);
	CStringArray strProcessID;
	CSttTestMngr::g_pTestMngr->GetRunningProcess(strData,strProcessID);

	long nCount = strProcessID.GetCount();

	for (int i=0; i<nCount; i++)
	{
		stt_pp_pkt_pack_stringVal(pPos,STT_PP_DATAID_PROCESSID,strProcessID.GetAt(i));
	}

#endif

	stt_InitPktBuffer_Head(pSendBuf,MULTICAST_CMD_QUERYSERVERSTATE_ACK,pPos - pHead, 0, 0, 0);

	SendBuffer(pSendBuf, pPos - pSendBuf, &m_sktMultiCast);
	delete pSendBuf;

	return TRUE;
}

BOOL CSttMulticastServerSocket::Process_Multicast_QuerySystemCfg(CSttPpDatasDriver vec)
{
	if (!CheckMatchSN(vec))
	{//判断序列号是否一致，不一致直接丢弃
		return FALSE;
	}

	//获取当前服务状态

	//更新错误码
	int nErrCode = 0;

	long nSendBufLen = 1024;
	BYTE *pSendBuf = new BYTE[nSendBufLen];

	BYTE *pHead = pSendBuf + STT_PKG_HEAD_LEN;
	BYTE *pPos = pHead;
	stt_pp_pkt_pack_stringVal(pPos,STT_PP_DATAID_SN,m_strSN);
	stt_pp_pkt_pack_stringVal(pPos,STT_PP_DATAID_MODEL,m_strModel);
	stt_pp_pkt_pack_longVal(pPos,STT_PP_DATAID_RUNSTATE, nErrCode);

	CStringArray arrayBoot,arraySttApp,arrayDriver;
#ifdef _PSX_QT_LINUX_
	CSttTestMngr::g_pTestMngr->GetIniCfg(arrayBoot,arraySttApp,arrayDriver);
#endif

	CString strData;
	int i;

	for (i=0; i<arrayBoot.GetCount(); i++)
	{
		strData = arrayBoot.GetAt(i);
		stt_pp_pkt_pack_stringVal(pPos,STT_PP_DATAID_DEFAULT_RUNPROC,strData);
	}

	for (i=0; i<arraySttApp.GetCount(); i++)
	{
		strData = arraySttApp.GetAt(i);
		stt_pp_pkt_pack_stringVal(pPos,STT_PP_DATAID_CFG_PROC,strData);
	}

	for (i=0; i<arrayDriver.GetCount(); i++)
	{
		strData = arrayDriver.GetAt(i);
		stt_pp_pkt_pack_stringVal(pPos,STT_PP_DATAID_CFG_DRIVER,strData);
	}

	stt_InitPktBuffer_Head(pSendBuf,MULTICAST_CMD_QUERYSYSTEMCFG_ACK,pPos - pHead, 0, 0, 0);

	SendBuffer(pSendBuf, pPos - pSendBuf, &m_sktMultiCast);
	delete pSendBuf;

	return TRUE;
}
