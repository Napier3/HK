#include "stdafx.h"
#include "TctrlCntrBaseApp.h"
#include	"../../Module/api/GlobalConfigApi.h"
#include "../../Module/api/GloblaDrawFunctions.h"
#include "AutoTestXMLRWKeys.h"
#include "../../Module\API\SingleAppMutexApi.h"
#include "..\..\Module\EpotoInterface\EpotoInterface.h"
#include "..\..\Module\Encrypt\EncryptTool.h"
#include "..\..\61850\Module\MMS_STACK_CFG\MMS_STACK_CFG.h"

#include "RecorderPpEngine.h"
#include "RecorderInterfaceCOM.h"

#include "XLanguageResourceAts.h"
#include "..\..\Protocol\Module\ProcotolProject\ClassProcotolProjectGlobal.h"
#include "..\..\Module\QRCode\QRCodeRead.h"
#include "GuideBook\GuideBookTool.h"
#include "..\..\Module\Record\XRecordDrawComtradeDib.h"


#define _use_TerminateProgram

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CString g_strRcdFilePathRoot;
BOOL g_bCreateTestTimesDir = 0;

//////////////////////////////////////////////////////////////////////////
//
CTCtrlCntrBaseApp *g_theTCtrlCntrApp = NULL;
CRptFillAppBase *g_theRptFillApp = NULL;

CTCtrlCntrBaseApp::CTCtrlCntrBaseApp()
{
	srand(time(0));

	g_theTCtrlCntrApp = this;
	m_pWaveFileMngr = NULL;
	m_oRecorder = NULL;

	//m_pTestTasks = new CTestLibraryTasks;
#ifndef GUIDEBOOK_DEV_MODE
	m_pMttTestTask = NULL;
#endif

	m_pSystemConfig = new CTCtrlSystemConfig;

	CTCtrlCntrWorkSpace::Create();
	ASSERT(CTCtrlCntrWorkSpace::g_pWorkSpace != NULL);

	CAutoTestXMLRWKeys::Create();
	ASSERT(CAutoTestXMLRWKeys::g_pAutoTestRWKeys != NULL);

	m_pFontTestItem = NULL;
	
	m_pXTestMsgWnd = NULL;
	m_oRecorder = NULL;
	m_dwTestMode = TEST_MODE_REPORT;
	m_nDsvImage = 0;

#ifdef _use_ppengine_exception
	m_nPpMmsEngineCpuCounts = 0;
#endif

	m_pRptFillAppBase = NULL;
	//m_WordApp = NULL;
}

CTCtrlCntrBaseApp::~CTCtrlCntrBaseApp()
{
	CTCtrlCntrWorkSpace::Release();
	CAutoTestXMLRWKeys::Release();

	if (m_pSystemConfig != NULL)
	{
		delete m_pSystemConfig;
		m_pSystemConfig = NULL;
	}

	if (m_pRptFillAppBase != NULL)
	{
		delete m_pRptFillAppBase;
		m_pRptFillAppBase = NULL;
	}
}

BOOL CTCtrlCntrBaseApp::Is_UsePowerTestTrans()
{
	return TRUE;	
}

void CTCtrlCntrBaseApp::CreateReportApp()
{
	if(m_pCtrlCntrConfig->IsReportControlWPS())
	{
		CreateApp(CRptFillWPSApp::New);
	}
	else
	{
		CreateApp(CRptFillWordApp::New);
	}
}

void CTCtrlCntrBaseApp::CreateApp(PFUNC_RPTFILLAPP_CREATE pCreateFunc)
{
	if (m_pRptFillAppBase != NULL)
	{
		return;
	}

	m_pRptFillAppBase = pCreateFunc();
	g_theRptFillApp = m_pRptFillAppBase;
}

BOOL CTCtrlCntrBaseApp::ats_IsRegisterTrue(BOOL bShowMsg, BOOL bFromTest)
{
#ifdef GUIDEBOOK_DEV_MODE
	return CSafenet_Login::hasp_has_catalog(FETUREID_AUTOTEST, bShowMsg);
#else
	ASSERT (m_pCtrlCntrConfig != NULL);

	if (bFromTest)
	{
		return TRUE;
	}

	if (Encrypt_IsUseRegisterFile())
	{
		return Encrypt_IsEncrypt();
	}
	else
	{
		return CSafenet_Login::hasp_has_catalog(FETUREID_AUTOTEST, bShowMsg);
	}
#endif
}

/*
	初始化：在应用程序App的COM环境初始化之后调用
	过程：	初始化m_oSystemConfig
						初始化m_oTCtrlCntrConfig
						初始化m_oTestTasks
						初始化m_oTCtrlCntrWorkspace
*/
long CTCtrlCntrBaseApp::InitTCtrlBaseApp()
{
	CRcdComtradeFileMngr::Create();
	m_pCtrlCntrConfig = CTCtrlCntrConfig::Create();

	if (CTCtrlCntrConfig::Get_IsSingleApp())
	{
		if (!CreateSingleAppMutex(_T("AutoTest_TCtrlCntr_Inst_Lock")))
		{
			return FALSE;
		}
	}

	//初始化系统路径
	_P_InitSystemPath();

	m_pTestFileMngr = new CXFileMngr();

	InitTCtrlCntrPath();
// 	g_strTCtrlCntrWorkspacePath = (CString)_P_GetSystemPath();
// 	g_strTCtrlCntrTemplatePath = g_strTCtrlCntrWorkspacePath;
// 	g_strTCtrlCntrLibraryPath = g_strTCtrlCntrWorkspacePath;
// 
// 	g_strTCtrlCntrWorkspacePath += L"Workspace\\";
// 	g_strTCtrlCntrTemplatePath += L"Template\\";
// 	g_strTCtrlCntrLibraryPath += L"Library\\";

	//测试功能数据接口
	TM_CreateTestMacros();

	m_pSystemConfig->Init();
	//m_pCtrlCntrConfig->Open();
	CTCtrlCntrWorkSpace::g_pWorkSpace->Open();

	InitTaskMngr();

	CTestMacrosFileMngr::Create();

	//初始化数据类型
	CGbDataTypeMngr::Create();

	//初始化脚本
	Gb_InitLua();

//	m_WordCommandBarMngr.Init();
//
// 	m_pXTestMsgWnd = new CTestMsgWnd();
// 	m_pXTestMsgWnd->Create(CWnd::GetDesktopWindow());

#ifdef _use_MACROTEST_MEM_
	//与TCtrl交互的接口定义
	char pszPath[MAX_PATH];
	sprintf(pszPath, "%s%s", _P_GetBinPath(), MACROTEST_MEMFILENAME);
	m_pMemServer = new CShareMemServer(pszPath, MACROTEST_MAPNAME, MACROTEST_MAPSIZE);
#endif

	CString strPath;
	Gb_GetWavePath(strPath);

#ifdef GB_USE_XFILEMNGRBASE
	m_pWaveFileMngr = new CXFileMngr();
	m_pWaveFileMngr->SearchFiles(_T("wav"), _T("wav"),  strPath);
#else
	m_oWaveFileMngr.Traverse(strPath, _T("wav"),  FALSE);
#endif

	//KeyDB  2013.4.15
	CKeyDbXmlRWKeys::Create();
	m_oKeyDB.OpenKeyDbFile(_T(""), TRUE);

	//CCharacteristicXmlRWKeys::Create();
	//初始化测试任务文件管理对象
	CString strWorkSpacePath;
	strWorkSpacePath = GetWorkSpacePath();

	ATS_InitSysReportFileMngr(m_pTestFileMngr, strWorkSpacePath);
// 	m_pTestFileMngr->m_strName = CXLanguageResourceAtsBase::g_sLangTxt_TestLogMngmt/*_T("测试记录文件管理")*/;
// 
// 	CXFileType *pXFileType = m_pTestFileMngr->AddFileType(CXLanguageResourceAtsBase::g_sLangTxt_TestRptRecodFile/*_T("测试报告记录文件")*/, g_strGuideBookBinaryPostfix, _T(""), _T(""));
// 	pXFileType->AddNewPostfix(CXLanguageResourceAtsBase::g_sLangTxt_TestRptRecodFile/*_T("测试报告记录文件")*/, g_strGuideBookBinaryPostfix);
// 	pXFileType->AddNewPostfix(CXLanguageResourceAtsBase::g_sLangTxt_TestRptFile/*_T("测试报告文件")*/, g_strDocFilePostfix);
// 
// 	pXFileType = m_pTestFileMngr->AddFileType(CXLanguageResourceAtsBase::g_sLangTxt_TestTaskFile/*_T("测试任务文件")*/, g_strTestTaskFilePostfix, _T(""), _T(""));
// 	pXFileType->AddNewPostfix(CXLanguageResourceAtsBase::g_sLangTxt_TestTaskFile/*_T("测试任务文件")*/, g_strTestTaskFilePostfix);
// 
// 	//2015-6-10添加：多测试报告文件
// 	pXFileType = m_pTestFileMngr->AddFileType(CXLanguageResourceAtsBase::g_sLangTxt_SngDeviceRpt/*_T("单装置多通道测试报告文件")*/, g_strGuideBookBinaryPostfix_SdvSpoMgrp, _T(""), _T(""));
// 	pXFileType->AddNewPostfix(CXLanguageResourceAtsBase::g_sLangTxt_SngDeviceRpt/*_T("单装置多通道测试报告文件")*/, g_strGuideBookBinaryPostfix_SdvSpoMgrp);
// 
// 	//2015-6-10添加：多测试报告文件
// 	pXFileType = m_pTestFileMngr->AddFileType(CXLanguageResourceAtsBase::g_sLangTxt_MulDeviceRpt/*_T("多装置测试报告文件")*/, g_strGuideBookMdTaskPostfix, _T(""), _T(""));
// 	pXFileType->AddNewPostfix(CXLanguageResourceAtsBase::g_sLangTxt_MulDeviceRpt/*_T("多装置测试报告文件")*/, g_strGuideBookMdTaskPostfix);
// 
// 	pXFileType = m_pTestFileMngr->AddFileType(CXLanguageResourceAtsBase::g_sLangTxt_SngDeviceRpt2/*_T("单装置多规约测试报告文件")*/, g_strGuideBookSdvMppTaskPostfix, _T(""), _T(""));
// 	pXFileType->AddNewPostfix(CXLanguageResourceAtsBase::g_sLangTxt_SngDeviceRpt2/*_T("单装置多规约测试报告文件")*/, g_strGuideBookSdvMppTaskPostfix);
// 	
// 	pXFileType = m_pTestFileMngr->AddFileType(CXLanguageResourceAtsBase::g_sLangTxt_MdvMgrpFile/*_T("单装置多规约测试报告文件")*/, g_strGuideBookMdvMgrpTaskPostfix, _T(""), _T(""));
// 	pXFileType->AddNewPostfix(CXLanguageResourceAtsBase::g_sLangTxt_MdvMgrpFile/*_T("单装置多规约测试报告文件")*/, g_strGuideBookMdvMgrpTaskPostfix);
// 
// 	m_pTestFileMngr->SetOnllySearchMainTypeFile(TRUE);
// 	m_pTestFileMngr->InitByXFileTypes();
// 	m_pTestFileMngr->SetLibraryPath(strWorkSpacePath);
// 
// 	CString strTemp;
// 	strTemp.Format(_T(".%s"), g_strTestTaskFilePostfix);
// 	XFile_BringFileHead(m_pTestFileMngr, strTemp);

	CReportTemplateConfigXmlRWKeys::Create();
	m_oReportTemplateConfig.OpenReportTemplateConfigFile();

	CreateAllEngine();

	//动态库调用初始化
	CSafetyDllCallMngr::Create();

#ifndef GUIDEBOOK_DEV_MODE
	CClassProcotolProjectXmlRWKeys::Create();
#endif

	//二维码
	CQRCodeRead::Create();

#ifndef GUIDEBOOK_DEV_MODE
	CDeviceModelXmlKeys::Create();
#endif

	//是否为工厂模式  2018-11-10
	if (CTCtrlCntrConfig::IsFacBatchTestMode())
	{
		CFactoryBatchTestMngr::Create();
	}

	CGuideBookTool::Create();

	return 1;
}

void CTCtrlCntrBaseApp::SetRecorderProgID(const CString &strProgID)	
{	
	if (m_oRecorder != NULL)
	{
		if (m_oRecorder->m_strRecordProgID != strProgID)
		{
			CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("Warning : Record [%s] is Running! Set Record ProgID [%s]")
				, m_oRecorder->m_strRecordProgID, strProgID);
		}
	}

	return m_pCtrlCntrConfig->SetRecorderProgID(strProgID);	
}

CString CTCtrlCntrBaseApp::GetWorkSpacePath()
{
	CString strWorkSpacePath;
	strWorkSpacePath = m_pCtrlCntrConfig->m_strWorkSpacePath;

	if (IsFileExist(strWorkSpacePath))
	{

	}
	else
	{
		strWorkSpacePath = g_strTCtrlCntrWorkspacePath;
	}

	return strWorkSpacePath;
}

/*
	释放测试环境：在应用程序的ExitInstance中调用
	一定要在ExitInstance中调用，否则应用程序会因释放环境顺序问题导致错误
*/
long CTCtrlCntrBaseApp::ExitTCtrlCntrBaseApp()
{
	//是否为工厂模式  2018-11-10
	if (CTCtrlCntrConfig::IsFacBatchTestMode())
	{
		CFactoryBatchTestMngr::Release();
	}

	ReleaseRecorder();

	if(m_pCtrlCntrConfig != NULL)
	{
		CTCtrlCntrConfig::Release();
		m_pCtrlCntrConfig = NULL;
	}

	if(m_pSystemConfig != NULL)
	{
		delete m_pSystemConfig;
		m_pSystemConfig = NULL;
	}

	if(m_pFontTestItem != NULL)
	{
		delete m_pFontTestItem;
		m_pFontTestItem = NULL;
	}

	CAutoTestXMLRWKeys::Release();
	CTCtrlCntrWorkSpace::Release();

	TM_ReleaseTestMacros();
	CTestMacrosFileMngr::Release();

	//脚本
	Gb_CloseLua();

	//初始化数据类型
	CGbDataTypeMngr::Release();

	ReleasePpEngine();

	ReleaseMacroTestEngine();

	ReleaseSingleAppMutex();

#ifdef _use_MACROTEST_MEM_
	if (m_pMemServer != NULL)
	{
		delete m_pMemServer;
		m_pMemServer = NULL;
	}
#endif

	CKeyDbXmlRWKeys::Release();

	//CCharacteristicXmlRWKeys::Release();
	CReportTemplateConfigXmlRWKeys::Release();

#ifndef GUIDEBOOK_DEV_MODE
	CloseTestTask();
#endif

	try
	{
/*		if(m_WordApp)
		{
			COleVariant covTrue((long)TRUE);
			COleVariant covFalse((long)FALSE);
			COleVariant covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

			m_WordApp.Quit(covFalse, covOptional, covOptional);
			m_WordApp = NULL;
		}
*/
		if (m_pRptFillAppBase != NULL)
		{
			m_pRptFillAppBase->CloseApplication();
		}
	}
	catch (...) 
	{
		TRACE("catch error-----");
	}

	if (m_oRecorder != NULL)
	{
		delete m_oRecorder;
		m_oRecorder = NULL;
	}

	if (m_pWaveFileMngr != NULL)
	{
		delete m_pWaveFileMngr;
		m_pWaveFileMngr = NULL;
	}

	if (m_pTestFileMngr != NULL)
	{
		delete m_pTestFileMngr;
		m_pTestFileMngr = NULL;
	}

	CSafetyDllCallMngr::Release();	//动态库调用

#ifndef GUIDEBOOK_DEV_MODE
	CClassProcotolProjectXmlRWKeys::Release();
#endif

	//二维码
	CQRCodeRead::Release();

#ifndef GUIDEBOOK_DEV_MODE
	CDeviceModelXmlKeys::Release();
#endif

	CGuideBookTool::Release();
	CRcdComtradeFileMngr::Release();

	return 0;
}

void CTCtrlCntrBaseApp::InitRecorder(CTestControl *pTestControl)
{
	if (!HasRecorder())
	{
		return;
	}

	if (m_oRecorder != NULL)
	{
		if (m_oRecorder->m_strRecordProgID == CRecorderPpEngine::g_strRecorderPpEngineProgID)
		{
			CRecorderPpEngine *p = (CRecorderPpEngine*)m_oRecorder;
			p->m_pTestControl = pTestControl;
		}

		return;
	}

	if (m_pCtrlCntrConfig->m_strRecordProgID == CRecorderPpEngine::g_strRecorderPpEngineProgID)
	{
		CRecorderPpEngine *pNew = new CRecorderPpEngine();
		pNew->CreateCrecorder(m_pCtrlCntrConfig->m_strRecordProgID);
		pNew->m_pTestControl = pTestControl;
		m_oRecorder = pNew;
	}

	if (m_oRecorder == NULL)
	{
		CRecorderCOM *pNew = new CRecorderCOM();
		pNew->CreateCrecorder(m_pCtrlCntrConfig->m_strRecordProgID);
		m_oRecorder = pNew;
	}
}

void CTCtrlCntrBaseApp::ReleaseRecorder()
{
	if (m_pCtrlCntrConfig == NULL)
	{
		return;
	}

	if (!HasRecorder())
	{
		return;
	}

	try
	{
		if (m_oRecorder != NULL)
		{
			m_oRecorder->Quit();
			delete m_oRecorder;
			m_oRecorder = NULL;
		}
	}
	catch (...)
	{
		TRACE("catch error-----");
	}

	m_oRecorder = NULL;
}

/*
	从文件读入任务管理
	因为任务管理的数据可能比较多，不提倡一开始就读入全部的任务
	在需要的时候再读入
*/
void CTCtrlCntrBaseApp::InitTaskMngr()
{
	//用于测试
	//m_pTestTasks->Open();
}

void CTCtrlCntrBaseApp::SaveTaskMngr()
{
	//m_pTestTasks->Save();
}

void CTCtrlCntrBaseApp::CreateGbTreeImageList(UINT nBitmapID, int cx, int nGrow, COLORREF crMask)
{
	m_GbTreeImageList.DeleteImageList();
	m_GbTreeImageList.Create (nBitmapID, cx, nGrow, crMask);

	LOGFONT lf = InitLogFont();
	lf.lfHeight = 14;
	lf.lfWeight = 400;

#ifdef UNICODE
	lstrcpy(lf.lfFaceName,L"宋体");
#else
	strcpy(lf.lfFaceName,"宋体");	
#endif // UNICODE
	
	if (m_pFontTestItem == NULL)
	{
		m_pFontTestItem =  new CFont;
		m_pFontTestItem->CreateFontIndirect(&lf);	
	}
}

#ifdef _use_ppengine_exception
BOOL CTCtrlCntrBaseApp::IsPpMmsEngineException()
{
	int nCpuUsage = m_oSysExeCpuUsage.get_cpu_usage();

	if (nCpuUsage > 50)
	{
		m_nPpMmsEngineCpuCounts++;
	}

	if (m_nPpMmsEngineCpuCounts > 3)
	{
		m_nPpMmsEngineCpuCounts = 0;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
#endif

PpEngine::IPpEnginePtr CTCtrlCntrBaseApp::GetPpEngine(const CString &strProgID)
{
	PpEngine::IPpEnginePtr oEngine = m_oPpEngineCreateMngr.GetPpEngine(strProgID);

#ifdef _use_ppengine_exception
	if (strProgID == g_strPpEngineProgIDMms)
	{
		m_oSysExeCpuUsage.setpid(g_strPpMmsEngineExeName);
		m_oSysExeCpuUsage.get_cpu_usage();
	}
#endif

	return oEngine;
}

BOOL CTCtrlCntrBaseApp::HasPpEngine()
{
	return m_oPpEngineCreateMngr.HasPpEngine();
}

void CTCtrlCntrBaseApp::ReleasePpEngine()
{
	m_oPpEngineCreateMngr.ReleasePpEngine();
}

void CTCtrlCntrBaseApp::ReleasePpEngine(const CString &strProgID)
{
	m_oPpEngineCreateMngr.ReleasePpEngine(strProgID);
// 	if (m_pPpEngine != NULL)
// 	{
// 		try
// 		{
// 			m_pPpEngine = NULL;
// 		}
// 		catch (...)
// 		{
// 			TRACE("catch error-----");
// 		}
// 	}
}

MacroTest::IMacroTestEngine CTCtrlCntrBaseApp::GetMacroTestEngine(const CString &strType, const CString &strProgID, const CString &strMacroFile)
{
	CString strActiveMacroTestEngineProgID;
	strActiveMacroTestEngineProgID = CTestMacrosFileMngr::GetActiveMacroTestProgID(strMacroFile, strType);
	ASSERT (strActiveMacroTestEngineProgID == strProgID);

	return m_oMacroTestEngineCreateMngr.GetMacroTestEngine(strActiveMacroTestEngineProgID);
}

MacroTest::IMacroTest CTCtrlCntrBaseApp::GetMacroTest(const CString &strType, const CString &strProgID, const CString &strMacroFile, const CString &strTestAppGroup)
{
	CString strActiveMacroTestEngineProgID;
	strActiveMacroTestEngineProgID = CTestMacrosFileMngr::GetActiveMacroTestProgID(strMacroFile, strType);
	//ASSERT (strActiveMacroTestEngineProgID == strProgID);

	return m_oMacroTestEngineCreateMngr.GetMacroTest(strActiveMacroTestEngineProgID, strTestAppGroup);
}

void CTCtrlCntrBaseApp::ReleaseMacroTestEngine()
{
	m_oMacroTestEngineCreateMngr.ReleaseMacroTestEngine();
// 	try
// 	{
// 		if (m_pMacroTestEngine != NULL)
// 		{
// 			m_pMacroTestEngine.ExitEngine();
// 		}
// 	}
// 	catch (...)
// 	{
// 		TRACE("catch error-----");
// 	}
// 
// 	m_pMacroTestEngine = NULL;
}

void CTCtrlCntrBaseApp::InitMacroTestEngineShowSpyWnd()
{
	try
	{
// 		if (m_pMacroTestEngine != NULL)
// 		{
// 			m_pMacroTestEngine.ShowSpyWnd(g_bShowTestWndTop);
// 		}
		m_oMacroTestEngineCreateMngr.ShowSpyWnd();
	}
	catch (...)
	{
		
	}
}

void CTCtrlCntrBaseApp::CreateMacroTestEngine(const CString &strMacroFile)
{
// 	try
// 	{
// 		m_pMacroTestEngine = NULL;
// 	}
// 	catch(...)
// 	{
// 		TRACE("catch error-----");
// 	}

	//开启控制接口程序
	try
	{
		CString strActiveProgID;
		strActiveProgID = CTestMacrosFileMngr::GetActiveMacroTestProgID(strMacroFile, g_strDefaultMacroType);
		m_oMacroTestEngineCreateMngr.GetMacroTestEngine(strActiveProgID);
		//MacroTest::IMacroTestEngine pMacroEngine = GetMacroTestEngine(_T(""), strMacroFile);
	}
	catch(...)
	{
	}
}

void CTCtrlCntrBaseApp::CreatePpEngine()
{
	//关闭进程
#ifdef _use_TerminateProgram
	TerminateProgram(g_strPpEngineExeName);
	TerminateProgram(g_strPpMmsEngineExeName);
#endif

	//开启通讯引擎程序
	// 	try
	// 	{
	// 		PpEngine::IPpEnginePtr pEngine = GetPpEngine();
	// 	}
	// 	catch(...)
	// 	{
	// 	}
}

void CTCtrlCntrBaseApp::CreateAllEngine()
{
	//CreateMacroTestEngine();
	CreatePpEngine();
}

void CTCtrlCntrBaseApp::InitPpEngineShowSpyWnd()
{
	POS pos = m_oPpEngineCreateMngr.GetHeadPosition();
	CPpEngineCreate *p = NULL;

	while (pos != NULL)
	{
		p = (CPpEngineCreate *)m_oPpEngineCreateMngr.GetNext(pos);
		p->ShowSpyWnd();
	}
}


void CTCtrlCntrBaseApp::StopProtocolParseForReadSoe(BOOL bStop)
{
	if (m_pCtrlCntrConfig->IsStopProtocolParseWhileReadSoe())
	{
		m_oPpEngineCreateMngr.StopProtocolParseForReadSoe(bStop);
	}
}

BOOL CTCtrlCntrBaseApp::IsMacroTCtrlException()
{
	return FALSE;

#ifdef _use_MACROTEST_MEM_

	if (m_pMemServer == NULL)
	{
		return FALSE;
	}

	static LONG EXCEPTION_COUNT = 10;
	DWORD *pdwBuffer = (DWORD*)m_pMemServer->GetBuffer();
	*pdwBuffer = *pdwBuffer + 1;
	*(pdwBuffer + 1) = *(pdwBuffer + 1) + 1;
	*(pdwBuffer + 2) = *(pdwBuffer + 2) + 1;

	if (*pdwBuffer > EXCEPTION_COUNT ||  *(pdwBuffer + 1) > EXCEPTION_COUNT || *(pdwBuffer + 2) > EXCEPTION_COUNT)
	{
		memset(pdwBuffer, 0, 3 * sizeof(DWORD));
		return TRUE;
	}
	else
	{
		return FALSE;
	}
#endif
}

void CTCtrlCntrBaseApp::ExecuteMtCmd(const CString &strCmdID, const CString &strCmdPara)
{
	m_oMacroTestEngineCreateMngr.ExecuteMtCmd(strCmdID, strCmdPara);
// 	if (m_pMacroTestEngine == NULL)
// 	{
// 		return;
// 	}
// 
// 	m_pMacroTestEngine.ExcuteCmd(_bstr_t(strCmdID), _bstr_t(strCmdPara));
}

void CTCtrlCntrBaseApp::ExecutePpEngineCmd(CTestControl *pTestControl, const CString &strCmdID, const CString &strCmdPara)
{
	if (pTestControl == NULL)
	{
		return;
	}

	UINT nTestControlMode = pTestControl->GetTestControlMode();

	switch (nTestControlMode)
	{
	case TESTCONTROLMODE_NORMAL:
		ExecutePpEngineCmd_NORMAL(pTestControl, strCmdID, strCmdPara);
		break;

	case TESTCONTROLMODE_MGBRPT:
		ExecutePpEngineCmd_MGBRPT(pTestControl, strCmdID, strCmdPara);
		break;

	case TESTCONTROLMODE_MDGBRPT:
		ExecutePpEngineCmd_MDGBRPT(pTestControl, strCmdID, strCmdPara);
		break;

	default:
		break;
	}
}

void CTCtrlCntrBaseApp::ExecutePpEngineCmd_NORMAL(CTestControl *pTestControl, const CString &strCmdID, const CString &strCmdPara)
{
	m_strPpEngineCmdID = strCmdID;
	m_strPpEngineCmdPara = strCmdPara;
	pTestControl->Out_RunProcedure(strCmdID, _T(""), 0, 0, ProcedureType_EngineCmd);
}

void CTCtrlCntrBaseApp::ExecutePpEngineCmd_MGBRPT(CTestControl *pTestControl, const CString &strCmdID, const CString &strCmdPara)
{
	m_strPpEngineCmdID = strCmdID;
	m_strPpEngineCmdPara = strCmdPara;
	pTestControl->Out_RunProcedure(strCmdID, _T(""), 0, 0, ProcedureType_EngineCmd);
}

void CTCtrlCntrBaseApp::ExecutePpEngineCmd_MDGBRPT(CTestControl *pTestControl, const CString &strCmdID, const CString &strCmdPara)
{
	m_strPpEngineCmdID = strCmdID;
	m_strPpEngineCmdPara = strCmdPara;
	pTestControl->Out_RunProcedure(strCmdID, _T(""), 0, 0, ProcedureType_EngineCmd);
}

/*
MSWord::_Application CTCtrlCntrBaseApp::GetWordApp(BOOL bShow)
{
// 	if(TCC_IsDebugWithoutReport())
// 	{ 
// 		return NULL;
// 	}
// 
	if (m_WordApp == NULL)
	{
		//创建对象
		CreateWordApplication(bShow);
	}

	return m_WordApp;
}

void CTCtrlCntrBaseApp::CreateWordApplication(BOOL bShow)
{
	COleVariant covTrue((long)TRUE),covFalse((long)FALSE),covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	try
	{
		if (!m_WordApp.CreateDispatch(_T("Word.Application")))
		{
			AfxMessageBox(_T("没有安装Word"));
			return ;
		}

		m_WordApp.SetVisible(bShow);  //This shows the application.
	}
	catch (...)
	{
		TRACE("catch error-----");
	}

	//关闭全部的工具条
	MSO9::_CommandBars cmdbars;
	try
	{
		if (m_pCtrlCntrConfig->m_nHideAllCmdbars != 0)
		{
			cmdbars = m_WordApp.GetCommandBars();
			m_WordCommandBarMngr.InitWordCommandBarMngr(cmdbars);
		}
	}
	catch (...)
	{
		TRACE("catch error-----");
	}
}


void CTCtrlCntrBaseApp::RestoreWordCommandBars()
{
// 	if (TCC_IsDebugWithoutReport())
// 	{
// 		return;
// 	}

	if (m_pCtrlCntrConfig->m_nHideAllCmdbars == 0)
	{
		return;
	}

	if (m_WordApp == NULL)
	{
		return;
	}

	MSO9::_CommandBars cmdbars;
	try
	{
		cmdbars = m_WordApp.GetCommandBars();
		m_WordCommandBarMngr.LoadWordCommandBarMngr(cmdbars);
	}
	catch (...)
	{
		TRACE("catch error-----");
	}	

}


void CTCtrlCntrBaseApp::CloseWordApplication()
{
	if (m_WordApp == NULL)
	{
		return;
	}

	COleVariant covTrue((long)TRUE);
	COleVariant covFalse((long)FALSE);
	COleVariant covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

	try
	{
		MSWord::Documents oDocs = m_WordApp.GetDocuments();

		if (oDocs.GetCount() > 0)
		{
			return;
		}
	}
	catch (...)
	{
		TRACE("catch error-----");
	}

	RestoreWordCommandBars();

	try
	{
		if(m_WordApp)
		{
			m_WordApp.Quit(covFalse, covOptional, covOptional);
			m_WordApp = NULL;
		}
	}
	catch (...) 
	{
		TRACE("catch error-----");
	}

	m_WordApp = NULL;
}

void CTCtrlCntrBaseApp::SetDocViewSettings()
{
	if (m_WordApp == NULL)
	{
		return;
	}

	// 	try
	// 	{
	// 		MSWord::Documents oDocs = m_WordApp.GetDocuments();
	// 
	// 		if (oDocs.GetCount() > 1)
	// 		{
	// 			return;
	// 		}
	// 	}
	// 	catch (...)
	// 	{
	// 
	// 	}

	try
	{
		MSWord::View vw;
		MSWord::Window wnd;
		wnd = m_WordApp.GetActiveWindow();

		if (wnd != NULL)
		{
			wnd.SetDocumentMap(FALSE);
			vw = wnd.GetView();

			if (vw != NULL)
			{
				m_bShowParagraphs = vw.GetShowParagraphs();
				m_bShowBookmarks = vw.GetShowBookmarks();
				vw.SetShowParagraphs(FALSE);
				vw.SetShowBookmarks(FALSE);
				m_WordApp.SetDisplayStatusBar(FALSE);
			}
		}
	}
	catch(...)
	{
	}
}

void CTCtrlCntrBaseApp::RestoreDocViewSettings()
{
	if (m_WordApp == NULL)
	{
		return;
	}

	try
	{
		MSWord::Documents oDocs = m_WordApp.GetDocuments();

		if (oDocs.GetCount() > 1)
		{
			return;
		}
	}
	catch (...)
	{
		TRACE("catch error-----");
	}

	try
	{
		MSWord::View vw;
		MSWord::Window wnd;
		wnd = m_WordApp.GetActiveWindow();

		if (wnd != NULL)
		{
			vw = wnd.GetView();

			if (vw != NULL)
			{
				vw.SetShowParagraphs(m_bShowParagraphs);
				vw.SetShowParagraphs(m_bShowBookmarks);
				m_WordApp.SetDisplayStatusBar(TRUE);
			}
		}
	}
	catch(...)
	{
	}
}
*/

void CTCtrlCntrBaseApp::FireTestItemErrorMsg(CGbItemBase *pItem, long nStopByError)
{
	if (pItem->m_nState == TEST_STATE_INLEGIBLE)
	{
		if (m_pXTestMsgWnd != NULL)
		{
			m_pXTestMsgWnd->PostMessage(WM_GBITEM_TEST_STATE, (WPARAM)pItem, (WPARAM)nStopByError);
		}
	}

	PostThreadMessage(WM_GBITEM_TEST_STATE, (WPARAM)pItem, (WPARAM)nStopByError);
}

void CTCtrlCntrBaseApp::FireTestFinishMessage(BOOL bMttTaskFinish)
{
	if (m_pXTestMsgWnd != NULL)
	{
#ifndef GUIDEBOOK_DEV_MODE
		if (m_pMttTestTask == NULL)
		{
			m_pXTestMsgWnd->PostMessage(WM_GBITEM_TEST_STATE, 0, 0);
		}
		else
		{
			if (bMttTaskFinish)
			{
				m_pXTestMsgWnd->PostMessage(WM_GBITEM_TEST_STATE, 0, 0);
			}
		}
#else
		m_pXTestMsgWnd->PostMessage(WM_GBITEM_TEST_STATE, 0, 0);
#endif
	}

	PostThreadMessage(WM_GBITEM_TEST_STATE, 0, 0);
}

#ifndef GUIDEBOOK_DEV_MODE
CTestTask* CTCtrlCntrBaseApp::CreateNewTask(CTestTask *pTestTask)
{
	CloseTestTask();
	m_pMttTestTask = (CTestTask*)pTestTask->Clone();

	return m_pMttTestTask;
}

void CTCtrlCntrBaseApp::OpenTaskFile(const CString &strTaskFile)
{
	CloseTestTask();

	m_pMttTestTask = new CTestTask();
	m_pMttTestTask->OpenTaskFile(strTaskFile);
}

void CTCtrlCntrBaseApp::SaveTaskFile()
{
	ASSERT (m_pMttTestTask != NULL);
}

void CTCtrlCntrBaseApp::ReleaseMttDevice()
{
	try
	{
		m_oMttPpDevice = NULL;
	}
	catch (...)
	{
	}

}

void CTCtrlCntrBaseApp::CloseTestTask()
{
	if (m_pMttTestTask == NULL)
	{
		return;
	}

	ReleaseMttDevice();
	m_pMttTestTask->Save(TRUE);
	delete m_pMttTestTask;
	m_pMttTestTask = NULL;
}
#endif

CString CTCtrlCntrBaseApp::GetPpTemplateFilePath()
{
	CString strPath;
	strPath = _P_GetInstallPath();

// 	if (strPath.Right(1) == "\\")
// 	{
// 		strPath = strPath.Left(strPath.GetLength()-1);
// 	}
// 
// 	long nPos = strPath.ReverseFind('\\');
// 	strPath = strPath.Left(nPos+1);
	strPath.AppendFormat(_T("%s\\"), m_pCtrlCntrConfig->m_strProtocolPath);
	
	return strPath;
}

#ifndef GUIDEBOOK_DEV_MODE

void CTCtrlCntrBaseApp::WritePpMmsEngineConfig(CTestTask *pTestTask)
{
	//释放MMS规约引擎程序
	ReleasePpEngine(g_strPpEngineProgIDMms);
	pTestTask->WritePpMmsEngineConfig();
// 	CTestProject *pProject = NULL;
// 	CMMS_STACK_CFG oMMS_STACK_CFG;
// 	oMMS_STACK_CFG.Open_MMS_STACK_CFG_Outer();
// 	CStkCfg_RemoteAddressList *pRemoteAddressList = oMMS_STACK_CFG.GetRemoteAddressList();
// 	long nIndex = 0;
// 	pRemoteAddressList->SetCount(m_pTestTask->GetCount());
// 	CStkCfg_RemoteAddress *pAddress = NULL;
// 	POS pos = pTestTask->GetHeadPosition();
// 
// 	while (pos != NULL)
// 	{
// 		pProject = (CTestProject *)pTestTask->GetNext(pos);
// 		pAddress = (CStkCfg_RemoteAddress *)pRemoteAddressList->GetAtIndex(nIndex);
// 		pAddress->SetIP(pProject->m_strLocalID);
// 		pAddress->m_strModel = pProject->m_strName;
// 		nIndex++;
// 	}
// 
// 	oMMS_STACK_CFG.Save_MMS_STACK_CFG_Outer();
// 	oMMS_STACK_CFG.WriteIpToVMDFile();
}

#endif

void CTCtrlCntrBaseApp::WritePpMmsEngineConfig()
{
#ifndef GUIDEBOOK_DEV_MODE
	WritePpMmsEngineConfig(m_pMttTestTask);
#endif
}

BOOL TCC_IsDebugWithoutReport()
{
	ASSERT (g_theTCtrlCntrApp != NULL);
	return g_theTCtrlCntrApp->IsDebugWithoutReport();
}

COLORREF TCC_GetItemStateColor(CGbItemBase *pItem, BOOL bEnable)
{
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();
	COLORREF color;
	int nItemState = pItem->GetState();
	CTCtrlCntrConfig *pCtrlCntrCfg = pApp->GetCntrConfig();

	if (!bEnable)
	{
		return pCtrlCntrCfg->m_crProhibit;
	}

	switch(nItemState)
	{
	case TEST_STATE_NORMAL:
		color = pCtrlCntrCfg->m_crNormal;
		break;
	case TEST_STATE_TESTING:
		color = pCtrlCntrCfg->m_crTesting;
		break;
	case TEST_STATE_ELIGIBLE:
		color = pCtrlCntrCfg->m_crEligible;
		break;
	case TEST_STATE_STOPED:
		color = pCtrlCntrCfg->m_crStopped;
		break;
	case TEST_STATE_INLEGIBLE:
	case TEST_STATE_SKIP:
		color = pCtrlCntrCfg->m_crInlegible;
		break;
		//	case g_nNotStandard:
		//		color = pCtrlCntrCfg->m_crNotStandard;
		//		break;
	default:
		color = RGB(0,0,0);
		break;
	}

	//取消选择的项目、项目Enable==0
	if (pItem->m_nSelect == 0 || pItem->m_nEnable == 0)
	{
		color = pCtrlCntrCfg->m_crProhibit;
	}

	return color;
}


void Init_ShowTestWndTop(BOOL bMinimize)
{
	if ( CTCtrlCntrConfig::g_pTCtrlCntrConfig->Is_TestWndMode_HideWhenMinize())
	{
		if (bMinimize)
		{
			g_bShowTestWndTop = FALSE;
		}
		else
		{
			g_bShowTestWndTop = TRUE;
		}
	}
	else
	{
		g_bShowTestWndTop = TRUE;
	}

	g_theTCtrlCntrApp->InitMacroTestEngineShowSpyWnd();
	g_theTCtrlCntrApp->InitPpEngineShowSpyWnd();
}
