#include "stdafx.h"
#include "AtsNewTestTool.h"
#include "XLanguageResourceAts_AutoTest.h"
#include "..\..\Protocol\Module\ProcotolProject\ClassProcotolProjectGlobal.h"
#include "..\..\Module\TestMacro\TestMacrosFileMngr.h"
#include "TCtrlCntrWorkSpace.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void sdvmpp_UpdateProjectName(CTestProject *pTestProject)
{
	CString strName, strPostfix, strFile;
	strFile = GetPathFileNameFromFilePathName(pTestProject->m_strPpDeviceFile);
	ParseFileNameAndPostfix(strFile, strName, strPostfix);

	if (pTestProject->m_strPpEngineProgID == g_strPpEngineProgIDMms)
	{
		pTestProject->m_strName.Format(_T("%s-%s"), engine_GetEngineEngineText(pTestProject->m_strPpEngineProgID), strName);
	}
	else if (pTestProject->m_strPpEngineProgID == g_strPpEngineProgID)
	{
		pTestProject->m_strName = strName;
		strFile = pTestProject->tsk_GetPpxmlFile(FALSE);
		ParseFileNameAndPostfix(strFile, strName, strPostfix);
		strName.AppendFormat(_T("-%s"), pTestProject->m_strName);
		pTestProject->m_strName = strName;
	}
	else
	{
		pTestProject->m_strName.Format(_T("%s-%s"), engine_GetEngineEngineText(pTestProject->m_strPpEngineProgID), strName);
	}

	pTestProject->m_strID = pTestProject->m_strName;
}


CAtsNewTestTool *g_theAtsNewTestTool;

CAtsNewTestTool* CAtsNewTestTool::g_pAtsNewTestTool = NULL;
long CAtsNewTestTool::g_nAtsNewTestToolRef = 0;


CAtsNewTestTool* CAtsNewTestTool::Create()
{
	g_nAtsNewTestToolRef++;

	if (g_nAtsNewTestToolRef == 1)
	{
		CAutoTestXMLRWKeys::Create();
		g_pAtsNewTestTool = new CAtsNewTestTool();
// 		g_pAtsNewTestTool->m_nNewMode = nNewMode;
// 		g_pAtsNewTestTool->m_pXCurrFolder = pXCurrFolder;
// 		g_pAtsNewTestTool->InitAtsNewTestTool();
	}

	return g_pAtsNewTestTool;
}

void CAtsNewTestTool::Release()
{
	g_nAtsNewTestToolRef--;

	if (g_nAtsNewTestToolRef == 0)
	{
		CAutoTestXMLRWKeys::Release();
		delete g_pAtsNewTestTool;
		g_pAtsNewTestTool = NULL;
	}
}

CAtsNewTestTool::CAtsNewTestTool()
{
	g_theAtsNewTestTool = this;

	m_pTempGuideBook = new CGuideBook();
	m_pTempGuideBook->m_strGuideBookFileType = g_strGbFileFilter;
	m_pTestTask  = NULL;
	m_pTestTasks = NULL;
	m_dwReportType = REPORTFILL_INDEX_NONE;

	m_pExpandDatas = NULL;
	m_pExpandDatasAutoSet = NULL;
	m_pReportSNGen = NULL;
	m_pTaskReportSNGen = NULL;
	m_pDeviceAttrsDefine = NULL;
	m_pTestAppDefine = NULL;
	m_pTestApp = NULL;
	m_dwTkID_Index = 0;
	m_pTestTypes = NULL;
	m_pTestMacrosFile = NULL;
	m_bTestTasksAttach = FALSE;
}

CAtsNewTestTool::~CAtsNewTestTool()
{
	delete m_pTempGuideBook;
	m_pTempGuideBook = NULL;

	if (m_pTestTask != NULL)
	{
		delete m_pTestTask;
		m_pTestTask = NULL;
	}

	if (m_pTestTasks != NULL)
	{
		if (!m_bTestTasksAttach)
		{
			delete m_pTestTasks;
		}

		m_pTestTasks = NULL;
	}
}

void CAtsNewTestTool::InitAtsNewTestTool(UINT nNewMode, CXFolder *pXCurrFolder, CTestTasks *pTestTasks)
{
	m_nNewMode = nNewMode;
	m_pXCurrFolder = pXCurrFolder;

	if (m_nNewMode == TESTCONTROLMODE_MDGBRPT)
	{
		m_pTestTask = new CTestTask();
	}
	else if (m_nNewMode == TESTCONTROLMODE_SDVMPP)
	{
		m_pTestTask = new CTestTask();
	}
	else
	{
		
	}

	if (m_nNewMode == TESTCONTROLMODE_MDVMGRP)
	{
		if (pTestTasks == NULL)
		{
			m_pTestTasks = new CTestTasks();
		}
		else
		{
			m_pTestTasks = pTestTasks;
			m_bTestTasksAttach = TRUE;
		}

		m_pTestTasks->m_strTasksParentPath = m_pXCurrFolder->GetFolderPath(TRUE);
	}
	
}


CString CAtsNewTestTool::GetXTestDbGroupPath()
{
	return m_oTasksFromXDb.m_strXTestDbGroupPath;
}

DWORD CAtsNewTestTool::GetReportType()
{
	return m_dwReportType;
}

void CAtsNewTestTool::SetTestType(const CString &strTestType)
{
	m_strTestType = strTestType;

	if (m_strTestType.GetLength() == 0)
	{
		if (m_pTestTypes != NULL)
		{
			CTestType *pTestType = (CTestType*)m_pTestTypes->GetHead();

			if (pTestType != NULL)
			{
				m_strTestType = pTestType->m_strName;
			}
		}
	}

	if (m_pTestTasks != NULL)
	{
		m_pTestTasks->SetTestType(m_strTestType);
	}

	m_dwTkID_Index = ATS_GetTkIDIndex(m_strTestType, m_pTestTypes);
}

BOOL CAtsNewTestTool::IsAuthority()
{
	if (m_pTempGuideBook == NULL)
	{
		return TRUE;
	}

	return m_pTempGuideBook->IsAuthority();
}

void CAtsNewTestTool::InitByGuideBookFile(const CString &strFile)
{
	m_pTempGuideBook->InitGuideBookAttrs();
	m_pTempGuideBook->Open(strFile, TRUE);
	CXFile *pPpFile = NULL;
	m_strGuideBookFile = GetPathFileNameFromFilePathName(strFile);

	SetEngineProgID(m_pTempGuideBook->m_strPpEngineProgID);

	if (m_pTestTasks != NULL)
	{
		///m_pTestTasks->m_strTemplateFile = strFile;
		m_pTestTasks->tsk_SetGbxmlFile(strFile);
	}

	GetGbTestTypes();

	CTestMacrosFileMngr *pTestMacroFileMngr = CTestMacrosFileMngr::g_pTestMacrosFileMngr;;
	m_pTestMacrosFile = pTestMacroFileMngr->FindByFile(m_pTempGuideBook->m_strTestMacroFileID, m_pTempGuideBook->m_strCommCmdConfigFile);

	if (m_nNewMode == TESTCONTROLMODE_MDVMGRP)
	{
		if (m_pTestMacrosFile != NULL)
		{
			m_strMacroFileID = m_pTestMacrosFile->m_strID;
		}
		else
		{
			m_strMacroFileID.Empty();
		}
	}

	InitExpandMode();
}

void CAtsNewTestTool::SetEngineProgID(const CString &strEngineProgID)
{
	m_strPpEngineProgID = strEngineProgID;

	if (m_pTestTasks != NULL)
	{
		m_pTestTasks->m_strPpEngineProgID = m_strPpEngineProgID;
	}

	if (m_pTestTask != NULL)
	{
		m_pTestTask->m_strPpEngineProgID = m_strPpEngineProgID;
	}
}


void CAtsNewTestTool::InitProjectName(CAtsRpcTestDefine *pAtsRpcTestDefine)
{
	BOOL bHasName = FALSE;

	if (pAtsRpcTestDefine != NULL)
	{
		if (pAtsRpcTestDefine->m_strName.GetLength() > 5)
		{
			m_strTestProjectName = pAtsRpcTestDefine->m_strName;
			bHasName = TRUE;
		}
	}

	if (!bHasName)
	{
		m_strTestProjectName = m_strGuideBookFile;
		long nPos = m_strTestProjectName.ReverseFind('.');

		if (nPos > 0)
		{
			m_strTestProjectName = m_strTestProjectName.Left(nPos);
		}

		m_strTestProjectName.AppendFormat(_T("(%s)"), _P_GetProjectID());
	}

	if (m_nNewMode == TESTCONTROLMODE_MDVMGRP)
	{
		m_pTestTasks->SetTasksNameAndID(m_strTestProjectName, m_strTestProjectName);
	}

	if (m_pTestTasks != NULL)
	{
		m_pTestTasks->m_strTasksPath.Format(_T("%s%s\\"), m_pTestTasks->m_strTasksParentPath, m_strTestProjectName);
	}
}

void CAtsNewTestTool::InitExpandMode()
{
	if (TESTCONTROLMODE_MDGBRPT == m_nNewMode 
		|| m_nNewMode == TESTCONTROLMODE_SDVMPP)
	{
		return;
	}

	if (m_nNewMode == TESTCONTROLMODE_MDVMGRP)
	{
		m_oExpandDatas.DeleteAll();
		m_pTempGuideBook->OpenExpandFile(&m_oExpandDatas);
		MdvMgrpTest_InitExpandMode(m_pTempGuideBook->GetExpandFile());
		TestApp_InitExpandMode(m_pTestAppDefine);

		return;
	}

	if (m_pTempGuideBook == NULL)
	{
		return;
	}

	m_oExpandDatas.DeleteAll();
	m_pTempGuideBook->OpenExpandFile(&m_oExpandDatas);
}


long CAtsNewTestTool::GetExpandDataCount()
{
	POS pos = m_oExpandDatas.GetHeadPosition();
	CDvmData *pData = NULL;
	long nSelCount = 0;

	while (pos != NULL)
	{
		pData = (CDvmData *)m_oExpandDatas.GetNext(pos);

		if (pData->m_strValue == _T("1"))
		{
			nSelCount++;
		}
	}

	return nSelCount;
}

BOOL CAtsNewTestTool::IsMgbrptMode()
{
	if (m_pTempGuideBook == NULL)
	{
		return FALSE;
	}

	if (m_pTempGuideBook->m_nTestControlMode == 1)
	{
		if (GetExpandDataCount() > 1)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}

CTestTypes* CAtsNewTestTool::GetGbTestTypes()
{
	if (m_pTempGuideBook == NULL)
	{
		m_pTestTypes = Gb_GetTestTypes(NULL);
	}
	else if (m_pTempGuideBook->m_oTestTypes.GetCount() == 0)
	{
		m_pTestTypes = Gb_GetTestTypes(NULL);
	}
	else
	{
		m_pTestTypes = Gb_GetTestTypes(m_pTempGuideBook);
	}

	return m_pTestTypes;
}


BOOL CAtsNewTestTool::CanCreateMdTask(CString &strMsg)
{
	if (m_pTestTask == NULL)
	{
		return FALSE;
	}

	if (m_pTestTask->GetCount() == 0)
	{
		strMsg = CXLanguageResourceAts_AutoTest::g_sLangTxt_NoAddDevTestRep/*_T("没有添加装置测试报告")*/;
		return FALSE;
	}

	if (m_pTestTask->GetCount() == 1)
	{
		strMsg = CXLanguageResourceAts_AutoTest::g_sLangTxt_OlAddOnRep/*_T("只添加了一个装置测试报告")*/;
		return FALSE;
	}

	POS pos = m_pTestTask->GetHeadPosition();
	POS posCurr = NULL;
	CTestProject *p = NULL, *pCurr = NULL;
	BOOL bCan = TRUE;

	while (pos != NULL)
	{
		p = (CTestProject *)m_pTestTask->GetAt(pos);
		m_pTestTask->GetNext(pos);
		posCurr = pos;

		while (posCurr != NULL)
		{
			pCurr = (CTestProject *)m_pTestTask->GetNext(posCurr);

			if (pCurr->m_strID == p->m_strID)
			{
				strMsg.Format(CXLanguageResourceAts_AutoTest::g_sLangTxt_NameSame/*_T("装置报告列表第【%d】与第【%d】名称【%s】相同")*/
					, m_pTestTask->FindIndex(p), m_pTestTask->FindIndex(pCurr), p->m_strName);
				bCan = FALSE;
				break;
			}

			if (pCurr->m_strLocalID == p->m_strLocalID)
			{
				strMsg.Format(CXLanguageResourceAts_AutoTest::g_sLangTxt_IPSame/*_T("装置报告列表第【%d】与第【%d】IP【%s】相同")*/
					, m_pTestTask->FindIndex(p), m_pTestTask->FindIndex(pCurr), p->m_strLocalID);
				bCan = FALSE;
				break;
			}
		}

		if (!bCan)
		{
			break;
		}
	}

	return bCan;
}


void CAtsNewTestTool::SetGuideBookFile(const CString &strFile)
{
	m_strGuideBookFile = strFile;
	POS pos = m_pTestTask->GetHeadPosition();
	CTestProject *p = NULL;

	while (pos != NULL)
	{
		p = (CTestProject *)m_pTestTask->GetNext(pos);
		p->tsk_SetGbxmlFile(strFile);
	}
}


CTestProject* CAtsNewTestTool::InsertNewTestProject(CWnd *pWnd)
{
	CString strDeviceFile;

	if (!ats_GetDeviceModeleFiles(strDeviceFile, pWnd))
	{
		return NULL;
	}

	CString strName, strPostfix, strFile;
	strFile = GetPathFileNameFromFilePathName(strDeviceFile);
	ParseFileNameAndPostfix(strFile, strName, strPostfix);

	CTestProject *pNew = new CTestProject();
	strName.Trim();
	pNew->m_strName = strName;
	pNew->m_strID = strName;
	pNew->m_strLocalID = _T("192.168.1.10");
	pNew->m_strPpDeviceFile = strDeviceFile;
	pNew->m_strPpEngineProgID = g_strPpEngineProgIDMms;
	pNew->tsk_SetGbxmlFile(m_strGuideBookFile);
	m_pTestTask->AddNewChild(pNew, TRUE);

	return pNew;
}


BOOL CAtsNewTestTool::OnBnClickedBtnDvmfile(CTestProject *pProject, CWnd *pWnd)
{
	if (pProject == NULL)
	{
		return FALSE;
	}

	CString strDeviceFile;

	if (!ats_GetDeviceModeleFiles(strDeviceFile, pWnd))
	{
		return FALSE;
	}

	CString strName, strPostfix, strFile;
	strFile = GetPathFileNameFromFilePathName(strDeviceFile);
	ParseFileNameAndPostfix(strFile, strName, strPostfix);

	pProject->m_strName = strName;
	pProject->m_strID = strName;
	pProject->m_strPpDeviceFile = strDeviceFile;
	
	return TRUE;
}

BOOL CAtsNewTestTool::OnBnClickedBtnImport(CWnd *pWnd)
{
	CString strTaskFile;

	if (!ats_GetMdTestFile(strTaskFile, pWnd))
	{
		return FALSE;
	}

	m_pTestTask->OpenTaskFile(strTaskFile);
	SetGuideBookFile(m_strGuideBookFile);
	
	return TRUE;
}


void CAtsNewTestTool::OnBnClickedBtnExport(CWnd *pWnd)
{
	CString strFilter;
	ats_GetMdTestFileFilter(strFilter);

	CString strMdTaskFile;
	CString strRoot;
	strRoot = _P_GetSoftRegKey();

	if( !PopupSaveAsFileDialog(pWnd, strMdTaskFile, strRoot, _T("MdTestFilePath"),strFilter, g_strGuideBookMdTaskPostfix) )
	{
		return;
	}

	m_pTestTask->SaveAs(strMdTaskFile);
}

BOOL CAtsNewTestTool::CanCreateSdvMppTask(CString &strMsg)
{
	if (m_pTestTask == NULL)
	{
		return FALSE;
	}

	if (m_pTestTask->GetCount() == 0)
	{
		strMsg = CXLanguageResourceAts_AutoTest::g_sLangTxt_NoAddTestRpt/*_T("没有添加测试报告")*/;
		return FALSE;
	}

	if (m_pTestTask->GetCount() == 1)
	{
		strMsg = CXLanguageResourceAts_AutoTest::g_sLangTxt_OneTestRpt/*_T("只添加了一个测试报告")*/;
		return FALSE;
	}

	POS pos = m_pTestTask->GetHeadPosition();
	POS posCurr = NULL;
	CTestProject *p = NULL, *pCurr = NULL;
	BOOL bCan = TRUE;

	while (pos != NULL)
	{
		p = (CTestProject *)m_pTestTask->GetAt(pos);
		m_pTestTask->GetNext(pos);
		posCurr = pos;

		if (p->m_strPpEngineProgID == g_strPpEngineProgID)
		{
			if (p->tsk_GetPpxmlFile().GetLength() == 0)
			{
				strMsg.Format(CXLanguageResourceAts_AutoTest::g_sLangTxt_NoSelPrtcTem/*_T("装置报告列表第【%d】没有选择规约模板")*/
					, m_pTestTask->FindIndex(p));
				bCan = FALSE;
				break;
			}
		}

		if (p->m_strPpDeviceFile.GetLength() == 0)
		{
			strMsg.Format(CXLanguageResourceAts_AutoTest::g_sLangTxt_NoSelFile/*_T("装置报告列表第【%d】没有选择点表文件")*/
				, m_pTestTask->FindIndex(p));
			bCan = FALSE;
			break;
		}

		while (posCurr != NULL)
		{
			pCurr = (CTestProject *)m_pTestTask->GetNext(posCurr);

			if (pCurr->m_strID == p->m_strID)
			{
				strMsg.Format(CXLanguageResourceAts_AutoTest::g_sLangTxt_NameSame/*_T("装置报告列表第【%d】与第【%d】名称【%s】相同")*/
					, m_pTestTask->FindIndex(p), m_pTestTask->FindIndex(pCurr), p->m_strName);
				bCan = FALSE;
				break;
			}

			//if (pCurr->m_strPpTemplateFile == p->m_strPpTemplateFile)
			if (pCurr->tsk_GetPpxmlFile() == p->tsk_GetPpxmlFile())
			{
				strMsg.Format(CXLanguageResourceAts_AutoTest::g_sLangTxt_PrtcSame/*_T("装置报告列表第【%d】与第【%d】规约模板【%s】相同")*/
					, m_pTestTask->FindIndex(p), m_pTestTask->FindIndex(pCurr), p->tsk_GetPpxmlFile(FALSE));
				bCan = FALSE;
				break;
			}
		}

		if (!bCan)
		{
			break;
		}
	}

	return bCan;
}


CTestProject* CAtsNewTestTool::SdvMppTest_OnBnClickedBtnInsert(CWnd *pWnd)
{
	CTestProject *pNew = InsertNewTestProject(pWnd);

	if (pNew != NULL)
	{
		sdvmpp_UpdateProjectName(pNew);
	}

	return pNew;
}



BOOL CAtsNewTestTool::SdvMppTest_OnBnClickedBtnImport(CWnd *pWnd)
{
	CString strTaskFile;

	if (!ats_GetSdvMppTestFile(strTaskFile, pWnd))
	{
		return FALSE;
	}
	
	m_pTestTask->OpenTaskFile(strTaskFile);
	SetGuideBookFile(m_strGuideBookFile);

	return TRUE;
}

void CAtsNewTestTool::SdvMppTest_OnBnClickedBtnExport(CWnd *pWnd)
{
	CString strFilter;
	ats_GetSdvMppTestFileFilter(strFilter);

	CString strMdTaskFile;
	CString strRoot;
	strRoot = _P_GetSoftRegKey();

	if( !PopupSaveAsFileDialog(pWnd, strMdTaskFile, strFilter, g_strGuideBookSdvMppTaskPostfix) )
	{
		return;
	}

	m_pTestTask->SaveAs(strMdTaskFile);
}


BOOL CAtsNewTestTool::MdvMgrpTest_InitExpandMode(const CString &strExpandFile)
{
	//BOOL bRet = m_oTestGlobalDefine.OpenXmlFile(strExpandFile, CGbXMLKeys::TestDefineKey(), CGbXMLKeys::g_pGbXMLKeys);
	BOOL bRet = m_oTestGlobalDefine.OpenTestDefineFile(strExpandFile, CGbXMLKeys::TestDefineKey(), CGbXMLKeys::g_pGbXMLKeys);

	m_pExpandDatas = (CDvmDataset*)m_oTestGlobalDefine.FindByID(DSID_COMMCMDMCONFIG);
	m_pExpandDatasAutoSet = (CDvmDataset*)m_oTestGlobalDefine.FindByID(DSID_COMMCMDMCONFIG_AUTOSET);
	m_pReportSNGen = (CDvmDataset*)m_oTestGlobalDefine.FindByID(DSID_REPORT_SN_GEN);
	m_pTaskReportSNGen = (CDvmDataset*)m_oTestGlobalDefine.FindByID(DSID_TASK_REPORT_SN_GEN);
	m_pTestAppDefine = (CDvmDataset*)m_oTestGlobalDefine.FindByID(DSID_TESTAPP_DEF);
	m_pDeviceAttrsDefine = (CDvmDataset*)m_oTestGlobalDefine.FindByID(DSID_DEVICEATTR);
	m_dwReportType = m_oTestGlobalDefine.m_nShowWordRpt;
	bRet = FALSE;

#ifdef _UNICODE
	if (_wcsicmp(m_strPrevExpandFile, strExpandFile) != 0)
#else
	if (stricmp(m_strPrevExpandFile, strExpandFile) != 0)
#endif
	{
		if (!m_bTestTasksAttach)
		{
			m_pTestTasks->DeleteTestTasks();
		}

		bRet = TRUE;
	}

	m_strPrevExpandFile = strExpandFile;

	return bRet;
}



BOOL CAtsNewTestTool::MdvMgrpTest_OnBnClickedBtnImport(CWnd *pWnd)
{
	CString strFilter;
	ats_GetMdvMgrpTestFileFilter(strFilter);

	CString strMdvMgrpTaskFile;

	if( !PopupOpenFileDialog(pWnd, strMdvMgrpTaskFile, strFilter, g_strGuideBookMdvMgrpTaskPostfix) )
	{
		return FALSE;
	}

	m_pTestTasks->DeleteTestTasks();
	m_pTestTasks->Init();
	m_pTestTasks->OpenTasksFile(strMdvMgrpTaskFile);
	m_pTestTasks->InitAllCmdCfgChannels();

	return TRUE;
}

void CAtsNewTestTool::MdvMgrpTest_OnBnClickedBtnExport(CWnd *pWnd)
{
	CString strFilter;
	ats_GetMdvMgrpTestFileFilter(strFilter);

	CString strMdvMgrpTaskFile;

	if( !PopupSaveAsFileDialog(pWnd, strMdvMgrpTaskFile, strFilter, g_strGuideBookMdvMgrpTaskPostfix) )
	{
		return;
	}

	m_pTestTasks->SaveTasksFile(strMdvMgrpTaskFile);
	m_pTestTasks->SavePoProjectFile();
}

void CAtsNewTestTool::MdvMgrpTest_InsertDevices(const CString &strPpTemplateFile, const CString &strDevice, long nDvNum)
{
	if (m_strPpEngineProgID == g_strPpEngineProgIDMms)
	{
		MdvMgrpTest_InsertMmsDevices(strDevice, nDvNum);
	}
	else if (m_strPpEngineProgID == g_strPpEngineProgID)
	{
		MdvMgrpTest_InsertPpDevices(strPpTemplateFile, strDevice, nDvNum);
	}
	else
	{
		MdvMgrpTest_InsertMmsDevices(strDevice, nDvNum);
	}
}

void CAtsNewTestTool::MdvMgrpTest_InsertPpDevices(const CString &strTemplate, const CString &strDevice, long nDvNum)
{
	CString strCmmCfgFile;
	CTestTask *pNew = NULL;

	//通讯配置文件，获取配置信息
	CDeviceCmmConfig oDeviceCmmConfig;
	strCmmCfgFile = pp_GetDeviceCmmCfgFile(strDevice);
	oDeviceCmmConfig.OpenXmlFile(strCmmCfgFile, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strCmmConfigKey, CDeviceModelXmlKeys::g_pXmlRWKeys);

	//多组扩展配置对象
	CDvmData *pMaxID = NULL;//(CDvmData*)m_pExpandDatas->GetTail();

	if (m_pExpandDatas != NULL)
	{
		pMaxID = (CDvmData*)m_pExpandDatas->GetTail();
	}

	while (nDvNum > 0)
	{
		pNew = new CTestTask();
		pNew->m_strDeviceFile = strDevice;
		pNew->tsk_SetPpxmlFile(strTemplate);
		pNew->m_strID = Pp_GetPopCfgDeviceName(strTemplate, strDevice, m_pTestTasks, FALSE);
		pNew->m_strName = pNew->m_strID;
		pNew->m_strLocalID = pNew->m_strID;
		pNew->tsk_SetGbxmlFile(m_pTestTasks->tsk_GetGbxmlFile());//m_strTemplateFile;
		pNew->m_strPpEngineProgID = m_pTestTasks->m_strPpEngineProgID;
		pNew->InitCommCmdManyConfig(m_pExpandDatas);

		if (pMaxID != NULL)
		{
			pNew->m_strMaxMgrpID = pMaxID->m_strID;
		}

		pNew->InitDeviceAttr(m_pDeviceAttrsDefine); //装置属性
		pNew->InitDeviceCmmConfig(&oDeviceCmmConfig); //通讯配置

		m_pTestTasks->AddNewChild(pNew);
		m_pTestTasks->InitProjectByCommCmdManyConfig(pNew);
		nDvNum--;
	}

	InsertPpDevicesCmmConfig(&oDeviceCmmConfig);
	m_pTestTasks->InitAllCmdCfgChannels();
}

void CAtsNewTestTool::InsertPpDevicesCmmConfig(CDeviceCmmConfig *pCmmConfig)
{
	CCmmSerialConfig *pCmmSerialConfig = pCmmConfig->GetConfigSerial();

	if (pCmmSerialConfig != NULL)
	{
		InsertPpDevicesCmmConfig_Serial(pCmmSerialConfig);
		return;
	}

	CCmmNetConfig *pCmmNetConfig = pCmmConfig->GetConfigNet();

	if (pCmmNetConfig != NULL)
	{
		InsertPpDevicesCmmConfig_Net(pCmmNetConfig);
		return;
	}

	CCmmMmsConfig *pCmmMmsConfig = pCmmConfig->GetConfigMms();

	if (pCmmMmsConfig != NULL)
	{
		InsertPpDevicesCmmConfig_Mms(pCmmMmsConfig);
		return;
	}
}

void CAtsNewTestTool::InsertPpDevicesCmmConfig_Serial(CCmmSerialConfig *pCmmConfig)
{
	CDeviceCmmConfig *pTestDefine = (CDeviceCmmConfig*)m_oTestGlobalDefine.FindByID(DSID_CommConfig_Serial);

	m_pTestTasks->InsertPpDevicesCmmConfig_Serial(pTestDefine);
}

void CAtsNewTestTool::InsertPpDevicesCmmConfig_Net(CCmmNetConfig *pCmmConfig)
{
	CDeviceCmmConfig *pTestDefine = (CDeviceCmmConfig*)m_oTestGlobalDefine.FindByID(DSID_CommConfig_Net);

	m_pTestTasks->InsertPpDevicesCmmConfig_Net(pTestDefine);
}

void CAtsNewTestTool::InsertPpDevicesCmmConfig_Mms(CCmmMmsConfig *pCmmConfig)
{
	CDeviceCmmConfig *pTestDefine = (CDeviceCmmConfig*)m_oTestGlobalDefine.FindByID(DSID_CommConfig_Mms);

	m_pTestTasks->InsertPpDevicesCmmConfig_Mms(pTestDefine);
}


void CAtsNewTestTool::MdvMgrpTest_InsertPpDevices(CTestTasks *pSrcTestTasks)
{
	CString strTemplate, strDevice, strCmmCfgFile;
	strTemplate = pSrcTestTasks->tsk_GetPpxmlFile();
	strDevice = pSrcTestTasks->m_strDeviceFile;
	long nDvNum = pSrcTestTasks->GetCount();
	CTestTask *pNew = NULL;
	CTestTask *pSrc = NULL;
	long nTaskIndex = 0;
	CDvmDataset *pDeviceAttr = NULL;

	//通讯配置文件，获取配置信息
	CDeviceCmmConfig oDeviceCmmConfig;
	strCmmCfgFile = pp_GetDeviceCmmCfgFile(strDevice);
	oDeviceCmmConfig.OpenXmlFile(strCmmCfgFile, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strCmmConfigKey, CDeviceModelXmlKeys::g_pXmlRWKeys);

	//多组扩展配置对象
	CDvmData *pMaxID = NULL;//(CDvmData*)m_pExpandDatas->GetTail();

	if (m_pExpandDatas != NULL)
	{
		pMaxID = (CDvmData*)m_pExpandDatas->GetTail();
	}

	while (nDvNum > 0)
	{
		pSrc = (CTestTask *)pSrcTestTasks->GetAtIndex(nTaskIndex);
		pDeviceAttr = pSrc->GetDeviceAttr(FALSE);
		pNew = new CTestTask();

		pNew->m_strDeviceFile = strDevice;
		pNew->tsk_SetPpxmlFile( strTemplate);
		//pNew->m_strID = Pp_GetPopCfgDeviceName(strTemplate, strDevice, m_pTestTasks, FALSE);
		//pNew->m_strName = pNew->m_strID;
		pNew->m_strName = pSrc->m_strName;
		pNew->m_strID = pSrc->m_strID;
		pNew->tsk_SetGbxmlFile(m_pTestTasks->tsk_GetGbxmlFile(FALSE));//m_strTemplateFile;
		pNew->m_strPpEngineProgID = m_pTestTasks->m_strPpEngineProgID;
		pNew->InitCommCmdManyConfig(m_pExpandDatas);

		if (pMaxID != NULL)
		{
			pNew->m_strMaxMgrpID = pMaxID->m_strID;
		}


		pNew->InitDeviceAttr(m_pDeviceAttrsDefine); //装置属性

		if (pDeviceAttr != NULL)
		{
			pNew->InitDeviceAttrValueEx(pDeviceAttr); //装置属性
		}

		pNew->InitDeviceCmmConfig(&oDeviceCmmConfig); //通讯配置

		m_pTestTasks->AddNewChild(pNew);
		m_pTestTasks->InitProjectByCommCmdManyConfig(pNew);
		nDvNum--;
		nTaskIndex++;
	}

	InsertPpDevicesCmmConfig(&oDeviceCmmConfig);
	m_pTestTasks->InitAllCmdCfgChannels();
}


void CAtsNewTestTool::MdvMgrpTest_InsertMmsDevices(const CString &strDvmFile, long nDvNum)
{
	CTestTask *pNew = NULL;

	//通讯配置文件，获取配置信息
	CDeviceCmmConfig oDeviceCmmConfig;
	oDeviceCmmConfig.AddConfigMms();

	//多组扩展配置对象
	CDvmData *pMaxID = NULL;//(CDvmData*)m_pExpandDatas->GetTail();

	if (m_pExpandDatas != NULL)
	{
		pMaxID = (CDvmData*)m_pExpandDatas->GetTail();
	}

	while (nDvNum > 0)
	{
		pNew = new CTestTask();
		pNew->m_strDeviceFile = strDvmFile;
		pNew->m_strID = Pp_GetPopCfgDeviceName(_T(""), strDvmFile, m_pTestTasks, FALSE);
		pNew->m_strLocalID = pNew->m_strID;
		pNew->m_strName = pNew->m_strID;
		pNew->tsk_SetGbxmlFile(m_pTestTasks->tsk_GetGbxmlFile(FALSE));
		pNew->m_strPpEngineProgID = m_pTestTasks->m_strPpEngineProgID;
		pNew->InitCommCmdManyConfig(m_pExpandDatas);

		if (pMaxID != NULL)
		{
			pNew->m_strMaxMgrpID = pMaxID->m_strID;
		}

		pNew->InitDeviceAttr(m_pDeviceAttrsDefine); //装置属性
		pNew->InitDeviceCmmConfig(&oDeviceCmmConfig); //通讯配置

		m_pTestTasks->AddNewChild(pNew);
		m_pTestTasks->InitProjectByCommCmdManyConfig(pNew);     //ShaoL   2019.04.15 注释此行
		nDvNum--;
	}

	InsertPpDevicesCmmConfig(&oDeviceCmmConfig);
	m_pTestTasks->InitAllCmdCfgChannels();
}


void CAtsNewTestTool::MdvMgrpTest_InsertMmsDevices(CTestTasks *pTestTasks)
{
	ASSERT (FALSE);
}

void CAtsNewTestTool::AutoSetExpandDatas(CTestTask *pTestTask)
{
	if (m_pExpandDatasAutoSet == NULL)
	{
		return;
	}

	CDvmData *pAttr = (CDvmData*)m_pExpandDatasAutoSet->FindByID(DSID_DEVICEATTR);

	if (pAttr == NULL)
	{
		return;
	}

	CDvmData *pAttrExpand = (CDvmData*)m_pDeviceAttrsDefine->FindByID(pAttr->m_strValue);

	if (pAttrExpand == NULL)
	{
		return;
	}

	CDvmData *pOptrFunc = (CDvmData*)m_pExpandDatasAutoSet->FindByID(_T("OptrFunc"));

	if (pOptrFunc == NULL)
	{
		return;
	}

	if (pOptrFunc->m_strValue == _T("right"))
	{
		CDvmValue *pValue = (CDvmValue*)pOptrFunc->GetHead();

		if (pValue == NULL)
		{
			return;
		}

		long nLen = CString_To_long(pValue->m_strValue);
		CString strText = pAttrExpand->m_strValue.Right(nLen);
		long nIndex = CString_To_long(strText) - 1;
		CDvmData *pMaxID = (CDvmData*)m_pExpandDatas->GetAtIndex(nIndex);

		if (pMaxID != NULL)
		{
			pTestTask->m_strMaxMgrpID = pMaxID->m_strID;
			pTestTask->SetCommCmdManyConfigValue(pTestTask->m_strMaxMgrpID);
			m_pTestTasks->InitProjectByCommCmdManyConfig(pTestTask);
		}
	}
}

void CAtsNewTestTool::ReportSNGenClear()
{
	m_pTestTasks->ReportSNGenClear();
}

void CAtsNewTestTool::ReportSNGen()
{
	m_pTestTasks->InitProjectID();
	m_pTestTasks->TaskReportSNGen(m_pTaskReportSNGen, m_strMacroFileID);
	m_pTestTasks->ReportSNGen(m_pReportSNGen, m_strMacroFileID);
}

void CAtsNewTestTool::SetShowWordRpt(DWORD dwReportType)
{
	ats_SetReportFillProgID(dwReportType);
	m_dwReportType = dwReportType;

	if (m_dwReportType == m_oTestGlobalDefine.m_nShowWordRpt)
	{
		return;
	}

	m_oTestGlobalDefine.m_nShowWordRpt = m_dwReportType;
	m_oTestGlobalDefine.SaveTestDefineFile(CGbXMLKeys::g_pGbXMLKeys);
}

CTestTask* CAtsNewTestTool::MdvMgrpTest_OnQRCodeInput()
{
	// 	m_edtDeviceAttrBarCode.SetWindowText(m_oXBarcodeStrParser.GetQRCodeData());
	// 	m_oXBarcodeStrParser.GetDatas(m_pDeviceAttrsDefine);
	CQRCodeRead::GetDatas(m_pDeviceAttrsDefine);

	CTestTask *pFind = m_pTestTasks->FindTestTask(m_pDeviceAttrsDefine);

	if (pFind != NULL)
	{
		return NULL;
	}

	pFind = m_pTestTasks->FindTestTaskByEmptyDeviceAttr();

	if (pFind == NULL)
	{
		return pFind;
	}

	pFind->InitDeviceAttrValue(m_pDeviceAttrsDefine);
	AutoSetExpandDatas(pFind);

	return pFind;
}

void CAtsNewTestTool::MdvMgrpTest_OnBnClickedBtnDeleteall()
{
	CExBaseList listTask;
	m_pTestTasks->SelectAllTestTask(listTask);
	POS pos = listTask.GetHeadPosition();
	CTestTask *pTestTask = NULL;
	long nRow = 2;

	while (pos != NULL)
	{
		pTestTask = (CTestTask *)listTask.GetNext(pos);
		m_pTestTasks->Delete(pTestTask);
	}

	listTask.RemoveAll();
	m_pTestTasks->InitAllCmdCfgChannels();
}


void CAtsNewTestTool::TestApp_InitExpandMode(CDvmDataset *pTestAppDefine)
{
	m_pTestAppDefine = pTestAppDefine;
	m_pTestApp = m_pTestTasks->GetTestApp();
}

CDvmData*  CAtsNewTestTool::TestApp_AddTestApp(CValues *pValues)
{
	CDvmData *pTestApp = m_pTestTasks->AddTestApp(pValues, m_pTestAppDefine);

	return pTestApp;
}

CDvmData* CAtsNewTestTool::TestApp_AddTestApp(CDvmDataset *pTestApp)
{
	CValues oValues;
	POS pos = pTestApp->GetHeadPosition();
	CDvmData *pData = NULL;

	while (pos != NULL)
	{
		pData = (CDvmData *)pTestApp->GetNext(pos);
		oValues.AddNew(pData->m_strID, pData->m_strValue);
	}

	return TestApp_AddTestApp(&oValues);
}

CDvmData* CAtsNewTestTool::TestApp_AddTestApp(CDvmData *pTestApp)
{
	return m_pTestTasks->AddTestApp(pTestApp);
}

void CAtsNewTestTool::BeforeCreate(const CString &strTestType)
{
	SetTestType(strTestType);
	CTCtrlCntrWorkSpace::s_SetTkIDIndex(m_dwTkID_Index);

	//报告序列号自动生成
	if (m_nNewMode == TESTCONTROLMODE_MDVMGRP)
	{
		ReportSNGen();
	}
}

//////////////////////////////////////////////////////////////////////////
//
void CAtsNewTestTool::InitByAtsRpcTestDefine(CAtsRpcTestDefine *pAtsRpcTestDefine, CXFolder *pFolder)
{
	CString strGbFile, strEngineProgID;
	long nDeviceCount = pAtsRpcTestDefine->m_pDevices->GetCount();

	if (nDeviceCount == 0)
	{
		return;
	}

	if (!pAtsRpcTestDefine->GetGuideBookFile(strGbFile))
	{
		return;
	}

	//兼容之前的版本，默认为多装置多组
	BOOL bMdvMode = TRUE;

	if (pAtsRpcTestDefine->m_strTestMode == g_strGuideBookBinaryPostfix)
	{
		bMdvMode = FALSE;
	}

	if (bMdvMode)
	{
		InitAtsNewTestTool(TESTCONTROLMODE_MDVMGRP, pFolder);
	}

	pAtsRpcTestDefine->GetEngineProgID(strEngineProgID);
	pAtsRpcTestDefine->GetPpxmlFile(m_strPpTemplateFile);
	pAtsRpcTestDefine->GetDvmFile(m_strDeviceFile);
	InitByGuideBookFile(strGbFile);
	SetEngineProgID(strEngineProgID);
	InitProjectName(pAtsRpcTestDefine);

	m_strTemplateFile = strGbFile;
	m_strGuideBookFile = strGbFile;

	//添加测试仪
	InitByAtsRpcTestDef_AddTestApp(pAtsRpcTestDefine);

	if (!bMdvMode)
	{
		return;
	}

	//添加装置
	InitByAtsRpcTestDef_AddDevices(pAtsRpcTestDefine);

	m_dwReportType = REPORTFILL_INDEX_NONE;
	m_pTestTasks->SaveTasksFileByParentPath();
}

void CAtsNewTestTool::InitByAtsRpcTestDef_AddTestApp(CAtsRpcTestDefine *pAtsRpcTestDefine)
{

	POS pos = pAtsRpcTestDefine->m_pTestApps->GetHeadPosition();
	CDvmData *p = NULL;

	while (pos != NULL)
	{
		p = (CDvmData *)pAtsRpcTestDefine->m_pTestApps->GetNext(pos);
		TestApp_AddTestApp(p);
	}

}


void CAtsNewTestTool::InitByAtsRpcTestDef_AddDevices(CAtsRpcTestDefine *pAtsRpcTestDefine)
{
// 	m_strPpEngineProgID = g_strPpEngineProgIDMms;
// 	pAtsRpcTestDefine->GetEngineProgID(m_strPpEngineProgID);

	if (m_strPpEngineProgID == g_strPpEngineProgIDMms)
	{
		InitByAtsRpcTestDef_AddDevices_MMS(pAtsRpcTestDefine);
	}
	else if (m_strPpEngineProgID == g_strPpEngineProgID)
	{
		InitByAtsRpcTestDef_AddDevices_PP(pAtsRpcTestDefine);
	}
	else
	{
		InitByAtsRpcTestDef_AddDevices_MMS(pAtsRpcTestDefine);
	}

	//设置装置属性
	InitByAtsRpcTestDef_AddDevices_Attrs(pAtsRpcTestDefine);
}

void CAtsNewTestTool::InitByAtsRpcTestDef_AddDevices_Attrs(CAtsRpcTestDefine *pAtsRpcTestDefine)
{
	CTestTask *p = NULL;
	CExBaseList listTask;
	m_pTestTasks->SelectAllTestTask(listTask);
	POS pos = listTask.GetHeadPosition();
	CDvmDataset *pDeviceAttr = NULL;
	CDvmData *pAtsRpcDevice = NULL;
	long nIndex = 0;

	while (pos != NULL)
	{
		p = (CTestTask *)listTask.GetNext(pos);
		pDeviceAttr = p->GetDeviceAttr(FALSE);

		if (pDeviceAttr == NULL)
		{
			continue;
		}

		pAtsRpcDevice = (CDvmData *)pAtsRpcTestDefine->m_pDevices->GetAtIndex(nIndex);
		InitByAtsRpcTestDef_AddDevices_Attrs(pDeviceAttr, pAtsRpcDevice);

		//测试代码
// 		CString strPath;
// 		strPath.AppendFormat(_T("D:\\0\\InitByAtsRpcTestDef_AddDevices_Attrs_%d.xml"), nIndex);
// 		pDeviceAttr->SaveXmlFile(strPath, CDataMngrXmlRWKeys::g_pXmlKeys);

		nIndex++;
	}

	listTask.RemoveAll();
}

void CAtsNewTestTool::InitByAtsRpcTestDef_AddDevices_Attrs(CDvmDataset *pDeviceAttrs, CDvmData *pAtsRpcDevice)
{
	CDvmValue *pValue = NULL;
	POS pos = pAtsRpcDevice->GetHeadPosition();

	while (pos != NULL)
	{
		pValue = (CDvmValue *)pAtsRpcDevice->GetNext(pos);
		InitByAtsRpcTestDef_AddDevices_Attrs(pDeviceAttrs, pValue);
	}
// 	CDvmValue *pValue = (CDvmValue*)pAtsRpcDevice->FindByID(AtsRpcTestDef_bin_offset);
// 
// 	if (pValue != NULL)
// 	{
// 		InitByAtsRpcTestDef_AddDevices_Attrs(pDeviceAttrs, pValue);
// 	}
// 
// 	pValue = (CDvmValue*)pAtsRpcDevice->FindByID(AtsRpcTestDef_bout_offset);
// 
// 	if (pValue != NULL)
// 	{
// 		InitByAtsRpcTestDef_AddDevices_Attrs(pDeviceAttrs, pValue);
// 	}
// 
// 	pValue = (CDvmValue*)pAtsRpcDevice->FindByID(_T("udc-power"));
// 
// 	if (pValue != NULL)
// 	{
// 		InitByAtsRpcTestDef_AddDevices_Attrs(pDeviceAttrs, pValue);
// 	}
}

void CAtsNewTestTool::InitByAtsRpcTestDef_AddDevices_Attrs(CDvmDataset *pDeviceAttrs, CDvmValue *pAtsRpcAttr)
{
	CDvmData *pAttr = NULL;
	pAttr = new CDvmData();
	pDeviceAttrs->AddNewChild(pAttr);
	pAttr->m_strName = pAtsRpcAttr->m_strName;
	pAttr->m_strID = pAtsRpcAttr->m_strID;
	pAttr->m_strValue = pAtsRpcAttr->m_strValue;
}

void CAtsNewTestTool::InitByAtsRpcTestDef_AddDevices_MMS(CAtsRpcTestDefine *pAtsRpcTestDefine)
{
	CString strDvmFile, strIP;
	CDvmData *pData = NULL;
	long nCount = pAtsRpcTestDefine->m_pDevices->GetCount();
	POS pos = pAtsRpcTestDefine->m_pDevices->GetHeadPosition();
	CExBaseList listTask;
	CTestTask *pTask = NULL;
	long nTaskIndex = 0;
	CDeviceCmmConfig *pCmmConfig = NULL;
	CCmmMmsConfig *pMmsCfg = NULL;
	
	pData = (CDvmData *)pAtsRpcTestDefine->m_pDevices->GetAt(pos);
	strDvmFile = m_strDeviceFile;//pData->GetValueByID(XPARA_ID_DVMFILE);

	MdvMgrpTest_InsertMmsDevices(strDvmFile, nCount);   //此函数根据装置数量创建测试任务
	m_pTestTasks->SelectAllTestTask(listTask);
	InitAtsRpcTestTaskName(pAtsRpcTestDefine, listTask);   //ShaoL  2019.04.15

	//配置IP
	while (pos != NULL)
	{
		pData = (CDvmData *)pAtsRpcTestDefine->m_pDevices->GetNext(pos);
		strIP = pData->GetValueByID(AtsRpcTestDef_ip);
		pTask = (CTestTask *)listTask.GetAtIndex(nTaskIndex);
		pCmmConfig = pTask->GetDeviceCmmConfig();
		ASSERT (pCmmConfig != NULL);

		if (pCmmConfig == NULL)
		{
			CLogPrint::LogString(XLOGLEVEL_TRACE, _T(" InitByAtsRpcTestDef_AddDevices_MMS::pTask->GetDeviceCmmConfig() == NULL"));
			continue;
		}

		pMmsCfg = pCmmConfig->GetConfigMms();

		if (pMmsCfg == NULL)
		{
			CLogPrint::LogString(XLOGLEVEL_TRACE, _T(" InitByAtsRpcTestDef_AddDevices_MMS::pCmmConfig->GetConfigMms() == NULL"));
			continue;
		}

		pMmsCfg->m_strRemoteIP = strIP;
		nTaskIndex++;
	}

	//InitAtsRpcTestTaskName(pAtsRpcTestDefine, listTask);  //ShaoL  2019.04.15 注释此行，挪到上面了

	listTask.RemoveAll();
}

void CAtsNewTestTool::InitByAtsRpcTestDef_AddDevices_PP(CAtsRpcTestDefine *pAtsRpcTestDefine)
{
	CString strDvmFile, strIP, strPpTemplate;
	CDvmData *pData = NULL;
	POS pos = pAtsRpcTestDefine->m_pDevices->GetHeadPosition();
	CExBaseList listTask;
	long nCount = 0;

	pData = (CDvmData *)pAtsRpcTestDefine->m_pDevices->GetAt(pos);
	nCount = pAtsRpcTestDefine->m_pDevices->GetCount();
	strDvmFile = m_strDeviceFile;//pData->GetValueByID(XPARA_ID_DVMFILE);
	strPpTemplate = pData->GetValueByID(XPARA_ID_PPXMLFILE);
	strIP = pData->GetValueByID(AtsRpcTestDef_ip);

	if (strPpTemplate.GetLength() == 0)
	{
		strPpTemplate = m_strPpTemplateFile;
	}

	if (strDvmFile.GetLength() == 0)
	{
		strDvmFile = m_strDeviceFile;
	}

	MdvMgrpTest_InsertPpDevices(strPpTemplate, strDvmFile, nCount);
	m_pTestTasks->SelectAllTestTask(listTask);

	if (strIP.GetLength() > 0)
	{
		InitByAtsRpcTestDef_AddDevices_PP_Net(pAtsRpcTestDefine, listTask);
	}
	else
	{
		InitByAtsRpcTestDef_AddDevices_PP_Serial(pAtsRpcTestDefine, listTask);
	}

	listTask.RemoveAll();
}

void CAtsNewTestTool::InitByAtsRpcTestDef_AddDevices_PP_Net(CAtsRpcTestDefine *pAtsRpcTestDefine, CExBaseList &listTask)
{
	CString strDvmFile, strIP;
	CDvmData *pData = NULL;
	POS pos = pAtsRpcTestDefine->m_pDevices->GetHeadPosition();
	CTestTask *pTask = NULL;
	long nTaskIndex = 0;
	CDeviceCmmConfig *pCmmConfig = NULL;
	CCmmNetConfig *pNetCfg = NULL;
	long nPort = 0;

	pData = (CDvmData *)pAtsRpcTestDefine->m_pDevices->GetAt(pos);
	strDvmFile = m_strDeviceFile;//pData->GetValueByID(XPARA_ID_DVMFILE);

	while (pos != NULL)
	{
		pData = (CDvmData *)pAtsRpcTestDefine->m_pDevices->GetNext(pos);
		strIP = pData->GetValueByID(AtsRpcTestDef_ip);
		nPort = CString_To_long( pData->GetValueByID(AtsRpcTestDef_port) );
		pTask = (CTestTask *)listTask.GetAtIndex(nTaskIndex);
		pCmmConfig = pTask->GetDeviceCmmConfig();
		ASSERT (pCmmConfig != NULL);

		if (pCmmConfig == NULL)
		{
			CLogPrint::LogString(XLOGLEVEL_TRACE, _T(" InitByAtsRpcTestDef_AddDevices_MMS::pTask->GetDeviceCmmConfig() == NULL"));
			continue;
		}

		pNetCfg = pCmmConfig->GetNetConfig();

		if (pNetCfg == NULL)
		{
			CLogPrint::LogString(XLOGLEVEL_TRACE, _T(" InitByAtsRpcTestDef_AddDevices_MMS::pCmmConfig->GetNetConfig() == NULL"));
			continue;
		}

		pNetCfg->SetRemoteIP(strIP, nPort);
		nTaskIndex++;
	}
}

void CAtsNewTestTool::InitByAtsRpcTestDef_AddDevices_PP_Serial(CAtsRpcTestDefine *pAtsRpcTestDefine, CExBaseList &listTask)
{
	CString strDvmFile, strIP;
	CDvmData *pData = NULL;
	POS pos = pAtsRpcTestDefine->m_pDevices->GetHeadPosition();
	CTestTask *pTask = NULL;
	long nTaskIndex = 0;
	CDeviceCmmConfig *pCmmConfig = NULL;
	CCmmSerialConfig *pSerialCfg = NULL;
	long nPort = 0;

	pData = (CDvmData *)pAtsRpcTestDefine->m_pDevices->GetAt(pos);
	strDvmFile = m_strDeviceFile;//pData->GetValueByID(XPARA_ID_DVMFILE);

	while (pos != NULL)
	{
		pData = (CDvmData *)pAtsRpcTestDefine->m_pDevices->GetNext(pos);
		pTask = (CTestTask *)listTask.GetAtIndex(nTaskIndex);
		pCmmConfig = pTask->GetDeviceCmmConfig();
		ASSERT (pCmmConfig != NULL);

		if (pCmmConfig == NULL)
		{
			CLogPrint::LogString(XLOGLEVEL_TRACE, _T(" InitByAtsRpcTestDef_AddDevices_MMS::pTask->GetDeviceCmmConfig() == NULL"));
			continue;
		}

		pSerialCfg = pCmmConfig->GetConfigSerial();

		if (pSerialCfg == NULL)
		{
			CLogPrint::LogString(XLOGLEVEL_TRACE, _T(" InitByAtsRpcTestDef_AddDevices_MMS::pCmmConfig->GetConfigSerial() == NULL"));
			continue;
		}

		pSerialCfg->m_nPortNum = CString_To_long( pData->GetValueByID(AtsRpcTestDef_port) );
		pSerialCfg->m_nDataBit = CString_To_long( pData->GetValueByID(AtsRpcTestDef_byte_size) );
		pSerialCfg->m_fStopBit = CString_To_long( pData->GetValueByID(AtsRpcTestDef_stop_bit) );
		pSerialCfg->m_nParity = CString_To_long( pData->GetValueByID(AtsRpcTestDef_parity) );
		pSerialCfg->m_nBaudRate = CString_To_long( pData->GetValueByID(AtsRpcTestDef_baud_rate) );

		nTaskIndex++;
	}
}

void CAtsNewTestTool::InitAtsRpcTestTaskName(CAtsRpcTestDefine *pAtsRpcTestDefine, CExBaseList &listTask)
{
	CString strDvmFile, strIP;
	CDvmData *pData = NULL;
	POS pos = pAtsRpcTestDefine->m_pDevices->GetHeadPosition();
	CTestTask *pTask = NULL;
	long nTaskIndex = 0;

	while (pos != NULL)
	{
		pData = (CDvmData *)pAtsRpcTestDefine->m_pDevices->GetNext(pos);
		pTask = (CTestTask *)listTask.GetAtIndex(nTaskIndex);

		if (pData->m_strName.GetLength() > 0)
		{
			pTask->m_strName = pData->m_strName;
		}

		if (pData->m_strID.GetLength() > 0)
		{
			pTask->m_strID = pData->m_strID;
			pTask->m_strLocalID = pData->m_strID;
		}

		m_pTestTasks->InitProjectByCommCmdManyConfig(pTask);    //ShaoL 2019.04.15 根据pTask的name，id配置多装置多组
		nTaskIndex++;
	}
}

