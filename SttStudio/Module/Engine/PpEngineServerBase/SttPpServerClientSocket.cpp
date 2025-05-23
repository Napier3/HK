#include "stdafx.h"
#include "SttPpServerClientSocket.h"
#include "../SttTestEngineBase.h"
//sun #include "../../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineDeviceBase.h"
//sun #include "../../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineServer.h"

CSttPpServerClientSocket::CSttPpServerClientSocket()
{
	m_pszXmlBuffer = NULL;
	m_nXmlBufferLen = 0;
	SetXmlBufferLen(1048576); //1M
}

CSttPpServerClientSocket::~CSttPpServerClientSocket()
{
	if (m_pszXmlBuffer != NULL)
	{
		delete m_pszXmlBuffer;
		m_pszXmlBuffer = NULL;
	}
}

void CSttPpServerClientSocket::SetXmlBufferLen(long nLen)
{
	if (nLen <= m_nXmlBufferLen)
	{
		return;
	}

	if (m_pszXmlBuffer != NULL)
	{
		delete m_pszXmlBuffer;
		m_pszXmlBuffer = NULL;
	}

	m_pszXmlBuffer = new char [nLen+10];
	m_nXmlBufferLen = nLen;
	memset(m_pszXmlBuffer, 0, nLen);
}

long CSttPpServerClientSocket::PxSendBuffer(BYTE *pBuf, long nLen)
{
	return 0;
}

long CSttPpServerClientSocket::PxSendSysState(CSttSysState *pSysState)
{
	return CSttServerClientSocket::SendSysState(pSysState);
/*
	BYTE *pSendBuf = NULL;
	long nSendBufLen = 0;

	stt_InitRetSendBuf(&pSendBuf,nSendBufLen,pSysState, FALSE);

	long nRet = SendBuffer(pSendBuf,nSendBufLen);
	delete pSendBuf;

	return nRet;
*/
}


BOOL CSttPpServerClientSocket::ProcessRecvPacket(BYTE *pBuf,long nLen)
{
	if (CSttSocketDataBase_File::ProcessRecvPacket(pBuf, nLen))
	{
		return TRUE;
	}

	OnTestMsg(pBuf, nLen);

	return TRUE;
}


long CSttPpServerClientSocket::OnTestMsg(BYTE *pBuf, long nLen)
{
	long nCmdType = 0;
	char pszCmdID[64] = {0}, pszTestor[64] = {0}, pszRetCmdType[64]={0};
	BOOL bRet = FALSE;

	bRet = stt_pkg_get_cmd_id((char*)pBuf,nLen,nCmdType, pszCmdID, pszTestor, pszRetCmdType);

	if (!bRet)
	{
		stt_LogPkgHeadError(pBuf, nLen);
		return FALSE;
	}

	if (nCmdType == STT_CMD_TYPE_SYSTEM)
	{
		bRet = Process_Cmd_System(pBuf, nLen, pszCmdID, pszTestor);
	}
	else if (nCmdType == STT_CMD_TYPE_IOT)
	{
		bRet = Process_Cmd_IOT(pBuf, nLen, pszCmdID, pszTestor);
	}
	else
	{
		bRet = FALSE;
	}

//	CLogPrint::LogFormatString(XLOGLEVEL_TRACE,_T("收到测试消息--CSttPpServerClientSocket::OnTestMsg,nCmdType=%ld,Ret=%d"),nCmdType,bRet);
	return bRet;
}

long CSttPpServerClientSocket::Process_Cmd_System(BYTE *pBuf, long nLen, char *pszCmdID, char *pszTestor)
{
	return 0;
}

long CSttPpServerClientSocket::Process_Cmd_IOT(BYTE *pBuf, long nLen, char *pszCmdID, char *pszTestor)
{
	CSttIotCmdDriver oDrvIotCmd;
	CIotPxCommChannelInterface *pIotPxCommChannelInterface = this;
	CSttIotCmd *pIotCmd = oDrvIotCmd.NewSttIotCmd(pIotPxCommChannelInterface);
	oDrvIotCmd.AddRef();

	//2022-10-22 lijunqing   初始化没命令数据的格式
	InitSttCmdDataFormat(pBuf[STT_PKG_HEAD_LEN]);

	//2020-5-25 lijq
	SetXmlBufferLen(nLen * 2);
	pIotCmd->ParsePkgXml(pBuf,nLen, m_pszXmlBuffer, GetSttCmdDataFormat());
//	CLogPrint::LogFormatString(XLOGLEVEL_TRACE,_T("收到测试消息--CSttPpServerClientSocket::Process_Cmd_IOT,CmdID=%s"),oIotCmd.m_strID.GetString());

	if (pIotCmd->m_strID == STT_CMD_TYPE_IOT_CloseDevice)
	{
		pIotPxCommChannelInterface->AddRef();
	}

	CIotPxEngineServer::POST_WM_IOT_CMD_MSG(this, pIotCmd);

	return 0;
}

void CSttPpServerClientSocket::OnSocketClose(int nErrorCode, BOOL bDeleteSocket)
{
	CSttIotCmdDriver oDrvIotCmd;
	CIotPxCommChannelInterface *pIotPxCommChannelInterface = this;
	CSttIotCmd *pIotCmd = oDrvIotCmd.NewSttIotCmd(pIotPxCommChannelInterface);
	oDrvIotCmd.AddRef();
	pIotCmd->m_strID = STT_CMD_TYPE_IOT_CloseDevice;

	pIotPxCommChannelInterface->AddRef();
	CIotPxEngineServer::POST_WM_IOT_CMD_MSG(this, pIotCmd);

	//此处固定不删除。因为在CloseDevice的响应中，会删除对应的socket对象
	CSttServerClientSocket::OnSocketClose(nErrorCode,FALSE);
}

