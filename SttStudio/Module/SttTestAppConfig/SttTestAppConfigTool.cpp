#include "stdafx.h"
#include "SttTestAppConfigTool.h"
#include "../../../Module/Socket/XPing.h"

#ifndef _PSX_IDE_QT_
#ifndef _Not_Use_CSttTestAppConfigDlg_
#include "Dialog\SttTestAppConfigDlg.h"
#endif
#endif

#ifdef _PSX_QT_LINUX_
#include "../API/NetworkInterface.h"
#endif


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//CSttTestAppConfigTool g_oSttTestAppConfigTool;

CSttTestAppConfigTool::CSttTestAppConfigTool()
{
	m_pSttTestMsgViewInterface = NULL;
	m_pClientEngine = NULL;
	m_strServerID = STT_SOFT_ID_TEST;
	m_strSoftID = STT_SOFT_ID_TEST;
	m_pSttTestAppCfg = NULL;
}

CSttTestAppConfigTool::~CSttTestAppConfigTool()
{
	//FreeClientEngine();
}

#ifndef _PSX_IDE_QT_
void CSttTestAppConfigTool::TestAppConfig(CSttTestEngineClientData **ppXClientEngine, CSttTestMsgViewInterface *pMsgView, CWnd *pParentWnd)
{
#ifndef _Not_Use_CSttTestAppConfigDlg_
	m_pSttTestMsgViewInterface = pMsgView;
	CSttTestAppConfigDlg oDlg;
	oDlg.m_pSttTestAppConfigTool = this;
	oDlg.m_pSttTestAppCfg = m_pSttTestAppCfg;

	if (oDlg.DoModal() == IDOK)
	{
		pParentWnd->KillTimer(1);

		if (*ppXClientEngine != NULL)
		{
			delete *ppXClientEngine;
		}

		GetSttTestEngineClientData(ppXClientEngine);
		pParentWnd->SetTimer(1,1000,NULL);
	}
#endif
}
#endif

CSttTestEngineClientData* CSttTestAppConfigTool::CreateTestEngine(CSttTestAppCfg *pSttTestAppCfg)
{
	if (m_strServerID.GetLength() == 0)
	{
		m_strServerID = STT_SOFT_ID_TEST;
	}
    m_strServerID = STT_SOFT_ID_TEST;
    CSttTestEngineClientData *pClientEngine = nullptr;
	if (m_strServerID == STT_SOFT_ID_ATS)
	{
		pClientEngine = CreateAtsEngine(pSttTestAppCfg, m_strSoftID);
	}
	else
	{
		pClientEngine = CreateTestCtrlEngine(pSttTestAppCfg, m_strSoftID);
	}

    m_pClientEngine = nullptr;
	return pClientEngine;
}

CSttTestEngineClientData* CSttTestAppConfigTool::CreateTestCtrlEngine(CSttTestAppCfg *pSttTestAppCfg, const CString &strSoftID)
{
	if (pSttTestAppCfg->IsLocal())
	{
        CString strTestAppIP;
        CString strMask;
        stt_net_get_deviceip(strTestAppIP, strMask);
        Local_ConnectServer(pSttTestAppCfg, strTestAppIP, STT_PORT_TEST_SERVER, strSoftID);
    }
	else
	{
		Remote_ConnectServer(pSttTestAppCfg, pSttTestAppCfg->GetCloudIP(), pSttTestAppCfg->GetCloudServerPort());
	}
	return m_pClientEngine;
}

CSttTestEngineClientData* CSttTestAppConfigTool::CreateAtsEngine(CSttTestAppCfg *pSttTestAppCfg, const CString &strSoftID)
{
	if (pSttTestAppCfg->IsLocal())
	{
		Local_ConnectServer(pSttTestAppCfg, pSttTestAppCfg->GetTestAppIP(), STT_PORT_NATIVE_SERVER, strSoftID);
	}
	else
	{
		Remote_ConnectServer(pSttTestAppCfg, pSttTestAppCfg->GetCloudIP(), pSttTestAppCfg->GetCloudServerPort());
	}

	return m_pClientEngine;
}


void CSttTestAppConfigTool::FreeClientEngine()
{
	if(m_pClientEngine != NULL)
	{
		m_pClientEngine->PrepareFreeClientEngine();

		delete m_pClientEngine;
		m_pClientEngine = NULL;
	}
}

void CSttTestAppConfigTool::GetSttTestEngineBase(CSttTestAppCfg *pSttTestAppCfg, CSttTestEngineBase** ppTestEngineBase)
{
	CSttTestEngineBase *p = GetSttTestEngineBase(pSttTestAppCfg);

	if (p == NULL)
	{
		*ppTestEngineBase = p;
	}
}

CSttTestEngineBase *CSttTestAppConfigTool::GetSttTestEngineBase(CSttTestAppCfg *pSttTestAppCfg)
{
	if (m_pClientEngine == NULL)
	{
		return NULL;
	}

	CSttTestEngineBase *pRet = NULL;
	CSttTestEngineClientData *pClientEngine = m_pClientEngine;

	if (pSttTestAppCfg->IsLocal())
	{
		pRet = (CSttTestEngineBase *)((CSttRemoteClientTestEngine *)pClientEngine);
	}
	else
	{
		pRet = (CSttTestEngineBase *)((CSttClientTestEngine *)pClientEngine);
	}

	m_pClientEngine = NULL;

	return pRet;
}

void CSttTestAppConfigTool::GetSttTestEngineClientData(CSttTestEngineClientData** ppTestEngineClientData)
{
	CSttTestEngineClientData *p = GetSttTestEngineClientData();

	if (p != NULL)
	{
		*ppTestEngineClientData = p;
	}
}

CSttTestEngineClientData* CSttTestAppConfigTool::GetSttTestEngineClientData()
{
	if (m_pClientEngine != NULL)
	{
		CSttTestEngineClientData *p = m_pClientEngine;
		m_pClientEngine = NULL;
		return p;
	}
	else
	{
		return NULL;
	}
}


BOOL CSttTestAppConfigTool::Local_ConnectServer()
{
	return TRUE;
}

BOOL CSttTestAppConfigTool::Remote_ConnectServer()
{
	return TRUE;
}

BOOL CSttTestAppConfigTool::Remote_DisconnectServer()
{
	if (m_pClientEngine == NULL)
	{
		CLogPrint::LogString(XLOGLEVEL_INFOR,_T("m_pClientEngine == NULL"));
		return FALSE;
	}

	m_pClientEngine->DisConnect();

	return TRUE;
}

BOOL CSttTestAppConfigTool::Local_ConnectServer(CSttTestAppCfg *pSttTestAppCfg, const CString &strIP,long nPort
												,const CString &strIdSoft, CTestEventBaseInterface *pTestEventRcv)
{
 	if (! pSttTestAppCfg->IsLocal())
 	{
 		FreeClientEngine();
 	}
	pSttTestAppCfg->SetLocalApp();
    if (m_pClientEngine == nullptr)
	{
		CSttClientTestEngine *pNew = new CSttClientTestEngine();
		pNew->AttatchSttTestMsgViewInterface(m_pSttTestMsgViewInterface);
		m_pClientEngine = pNew;

        if (pTestEventRcv != nullptr)
		{
			m_pClientEngine->SetTestEventInterface(pTestEventRcv);
		}
	}
	BOOL bRet = m_pClientEngine->ConnectServer(strIP,nPort);
	if(!bRet)
	{
        CLogPrint::LogFormatString(XLOGLEVEL_ERROR,_T("Connect Server [%s] failed"), strIP.GetString());
		return bRet;
	}
    CString strMask;
    stt_net_get_deviceip( m_pClientEngine->m_pSttClientSocket->m_strIPLocal, strMask);

    m_pClientEngine->m_oCurrUser.ID_Terminal(STT_TERMINAL_TYPE_NATIVE);
    m_pClientEngine->m_pSttClientSocket->SetSocketType(STT_SOCKET_TYPE_LOCAL);
    m_pClientEngine->m_oCurrUser.ID_Tester(g_nIDTester);
	m_pClientEngine->m_oCurrUser.IP_User(m_pClientEngine->m_pSttClientSocket->m_strIPLocal);
	m_pClientEngine->m_oCurrUser.Name_User(m_pClientEngine->m_pSttClientSocket->m_strIPLocal);
	m_pClientEngine->m_oCurrUser.id_soft(strIdSoft);
	CSttCmdData oRetData;
	long nExecStatus = m_pClientEngine->System_Login(TRUE, &oRetData);
	if (nExecStatus != STT_CMD_ExecStatus_SUCCESS)
	{
        qDebug()<< "login failed with code %d" << nExecStatus;
		bRet = FALSE;
		CLogPrint::LogFormatString(XLOGLEVEL_INFOR,_T("Login失败"));
	}
	return bRet;
}

BOOL CSttTestAppConfigTool::ConnectServer(CSttTestAppCfg *pSttTestAppCfg, const CString &strIP,long nPort)
{
	if (! pSttTestAppCfg->IsLocal())
	{
		FreeClientEngine();
	}

	pSttTestAppCfg->SetLocalApp();

	if (m_pClientEngine == NULL)
	{
		CSttClientTestEngine *pNew = new CSttClientTestEngine();
		pNew->AttatchSttTestMsgViewInterface(m_pSttTestMsgViewInterface);
		m_pClientEngine = pNew;
	}

	BOOL bRet = m_pClientEngine->ConnectServer(strIP,nPort);

	return bRet;
}

BOOL CSttTestAppConfigTool::Remote_ConnectServer(CSttTestAppCfg *pSttTestAppCfg, const CString &strIP,long nPort)
{
	if (pSttTestAppCfg->IsLocal())
	{
		FreeClientEngine();
	}

	pSttTestAppCfg->SetRemoteApp();

	if (m_pClientEngine == NULL)
	{
		CSttRemoteClientTestEngine *pNew = new CSttRemoteClientTestEngine();
		pNew->AttatchSttTestMsgViewInterface(m_pSttTestMsgViewInterface);
		m_pClientEngine = pNew;
	}

	BOOL bRet = m_pClientEngine->ConnectServer(strIP,nPort);

	return bRet;
}

BOOL CSttTestAppConfigTool::Remote_BindAndLogin(CSttTestAppCfg *pSttTestAppCfg, CSttTestRemoteRegister *pRegister,CSttTestClientUser *pUser)
{
	ASSERT(m_pClientEngine != NULL);
	ASSERT(pRegister != NULL);
	ASSERT(pUser != NULL);

	if (pSttTestAppCfg->IsLocal())
	{
		return FALSE;
	}

	long nExecStatus = m_pClientEngine->Remote_Bind(pRegister);
	if (nExecStatus != STT_CMD_ExecStatus_SUCCESS)
	{
		return FALSE;
	}

	m_pClientEngine->m_oCurrUser.DeleteAll();
	m_pClientEngine->m_oCurrUser.AppendEx(*pUser);
	pUser->RemoveAll();

	//设置LocalIP
	m_pClientEngine->m_pSttClientSocket->m_strIPLocal = pSttTestAppCfg->GetLocalIP();

	m_pClientEngine->m_oCurrUser.ID_Terminal(STT_TERMINAL_TYPE_REMOTE);
	m_pClientEngine->m_pSttClientSocket->SetSocketType(STT_SOCKET_TYPE_REMOTE);
	m_pClientEngine->m_oCurrUser.ID_Tester(g_nIDTester);
	m_pClientEngine->m_oCurrUser.IP_User(m_pClientEngine->m_pSttClientSocket->m_strIPLocal);

	CSttCmdData oRetData;
	nExecStatus = m_pClientEngine->System_Login(TRUE, &oRetData);
	if (nExecStatus != STT_CMD_ExecStatus_SUCCESS)
	{
		return FALSE;
	}

	return TRUE;
}

BOOL CSttTestAppConfigTool::IsTestAppExist(CSttTestAppCfg *pSttTestAppCfg)
{
#ifdef _PSX_QT_LINUX_
    return TRUE;
#else
	char* pszIP = NULL;
	CString strTestAppIP = pSttTestAppCfg->GetTestAppIP();
	CString_to_char(strTestAppIP,&pszIP);

	BOOL bConnect = xping(pszIP);
	delete pszIP;

	if (!bConnect)
	{
        CLogPrint::LogFormatString(XLOGLEVEL_DEBUG,_T("测试仪：%s 网络连接不通！"),strTestAppIP.GetString());
	}

	return bConnect;
#endif
}

BOOL CSttTestAppConfigTool::IsCloudServerExist(CSttTestAppCfg *pSttTestAppCfg)
{
	char* pszIP = NULL;
	CString strCloudIP = pSttTestAppCfg->GetCloudIP();
	CString_to_char(strCloudIP,&pszIP);

	BOOL bConnect = xping(pszIP);
	delete pszIP;

	if (!bConnect)
	{
        CLogPrint::LogFormatString(XLOGLEVEL_TRACE,_T("云服务器：%s 网络连接不通！"),strCloudIP.GetString());
	}

	return bConnect;
}
