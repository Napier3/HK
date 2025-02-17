#pragma once


#include "..\..\Module\BaseClass\ExBaseList.h"
#include "AutoTestXMLRWKeys.h"
#include "..\..\Module\XfileMngrBase\XFolder.h"
#include "GuideBook\GuideBook.h"
#include "TaskMngr\TestTask.h"
#include "TCtrlCntrDefine.h"
#include "TaskMngr\TestGlobalDefine.h"
#include "..\..\Module\QRCode\QRCodeRead.h"

#include "AtsRpc\AtsRpcServerGlobalApi.h"

#define use_AtsNewTestTool


class CAtsNewTestTool : public CExBaseObject
{
private:
	CAtsNewTestTool();
	virtual ~CAtsNewTestTool();

	static CAtsNewTestTool* g_pAtsNewTestTool;
	static long g_nAtsNewTestToolRef;
	

public:
	static CAtsNewTestTool* Create();
	static void Release();

	void InitAtsNewTestTool(UINT nNewMode, CXFolder *pXCurrFolder, CTestTasks *pTestTasks = NULL);
	CString GetXTestDbGroupPath();
	DWORD GetReportType();

protected:
	
public:
	CTestTypes *m_pTestTypes;
	//从数据库获取的测试任务
	CTestTasks m_oTasksFromXDb;
	CXFolder *m_pXCurrFolder;

	CString m_strPpEngineProgID;
	CString m_strDeviceFile;
	CString m_strPpTemplateFile;
	CString m_strTemplateFile;
	DWORD   m_dwTkID_Index;       //当前的测试类型
	CString m_strTestType;

	CGuideBook *m_pTempGuideBook;
	CString m_strPrevExpandFile;
	CDvmDataset m_oExpandDatas;
	UINT  m_nNewMode;

	CTestTask *m_pTestTask;
	CTestTasks *m_pTestTasks;
	BOOL m_bTestTasksAttach;

	DWORD m_dwReportType;
	CString m_strGuideBookFile;
	CString m_strTestProjectName;

	//MdvMgrp
	CTestGlobalDefine m_oTestGlobalDefine;
	CDvmDataset *m_pExpandDatas;
	CDvmDataset *m_pExpandDatasAutoSet;
	CDvmDataset *m_pReportSNGen;
	CDvmDataset *m_pTaskReportSNGen;
	CDvmDataset *m_pDeviceAttrsDefine;
	CDvmDataset *m_pTestAppDefine;
	CString m_strMacroFileID;

// 	CDvmDataset *m_pTestAppDefine;
	CDvmDataset *m_pTestApp;
	CTestMacrosFile *m_pTestMacrosFile;

public:
	BOOL IsAuthority();
	void InitByGuideBookFile(const CString &strFile);
	void SetEngineProgID(const CString &strEngineProgID);
	void MdvMgrpTest_InsertDevices(const CString &strPpTemplateFile, const CString &strDevice, long nDvNum);

	void MdvMgrpTest_InsertPpDevices(const CString &strTemplate, const CString &strDevice, long nDvNum);
	void MdvMgrpTest_InsertPpDevices(CTestTasks *pSrcTestTasks);
	void MdvMgrpTest_InsertMmsDevices(const CString &strDvmFile, long nDvNum);
	void MdvMgrpTest_InsertMmsDevices(CTestTasks *pTestTasks);
	CDvmData* TestApp_AddTestApp(CValues *pValues);
	CDvmData* TestApp_AddTestApp(CDvmDataset *pTestAppDef);
	CDvmData* TestApp_AddTestApp(CDvmData *pTestApp);
	void BeforeCreate(const CString &strTestType);

public:
	CTestTask* GetTestTask()		{	ASSERT (m_pTestTask != NULL);	return m_pTestTask;	}
	CTestTasks* GetTestTasks()	{	ASSERT (m_pTestTasks != NULL);	return m_pTestTasks;	};
	void SetTestType(const CString &strTestType);

	void InitExpandMode();
	void InitProjectName(CAtsRpcTestDefine *pAtsRpcTestDefine=NULL);

	long GetExpandDataCount();
	BOOL IsMgbrptMode();
	CTestTypes* GetGbTestTypes();
	BOOL CanCreateMdTask(CString &strMsg);
	void SetGuideBookFile(const CString &strFile);
	CTestProject* InsertNewTestProject(CWnd *pWnd);
	BOOL OnBnClickedBtnDvmfile(CTestProject *pProject, CWnd *pWnd);
	BOOL OnBnClickedBtnImport(CWnd *pWnd);
	void OnBnClickedBtnExport(CWnd *pWnd);

	BOOL CanCreateSdvMppTask(CString &strMsg);
	CTestProject* SdvMppTest_OnBnClickedBtnInsert(CWnd *pWnd);
	BOOL SdvMppTest_OnBnClickedBtnImport(CWnd *pWnd);
	void SdvMppTest_OnBnClickedBtnExport(CWnd *pWnd);

	//////////////////////////////////////////////////////////////////////////
	BOOL MdvMgrpTest_InitExpandMode(const CString &strExpandFile);
	BOOL MdvMgrpTest_OnBnClickedBtnImport(CWnd *pWnd);
	void MdvMgrpTest_OnBnClickedBtnExport(CWnd *pWnd);

	void InsertPpDevicesCmmConfig(CDeviceCmmConfig *pCmmConfig);
	void InsertPpDevicesCmmConfig_Serial(CCmmSerialConfig *pCmmConfig);
	void InsertPpDevicesCmmConfig_Net(CCmmNetConfig *pCmmConfig);
	void InsertPpDevicesCmmConfig_Mms(CCmmMmsConfig *pCmmConfig);
	
	void AutoSetExpandDatas(CTestTask *pTestTask);
	void ReportSNGenClear();
	void ReportSNGen();
	void SetShowWordRpt(DWORD dwRptType);
	CTestTask* MdvMgrpTest_OnQRCodeInput();
	void MdvMgrpTest_OnBnClickedBtnDeleteall();
	void TestApp_InitExpandMode(CDvmDataset *pTestAppDefine);

public:
	void InitByAtsRpcTestDefine(CAtsRpcTestDefine *pAtsRpcTestDefine, CXFolder *pFolder);

private:
	void InitByAtsRpcTestDef_AddTestApp(CAtsRpcTestDefine *pAtsRpcTestDefine);
	void InitByAtsRpcTestDef_AddDevices(CAtsRpcTestDefine *pAtsRpcTestDefine);
	void InitByAtsRpcTestDef_AddDevices_Attrs(CAtsRpcTestDefine *pAtsRpcTestDefine);
	void InitByAtsRpcTestDef_AddDevices_Attrs(CDvmDataset *pDeviceAttrs, CDvmData *pAtsRpcDevice);
	void InitByAtsRpcTestDef_AddDevices_Attrs(CDvmDataset *pDeviceAttrs, CDvmValue *pAtsRpcAttr);
	void InitByAtsRpcTestDef_AddDevices_MMS(CAtsRpcTestDefine *pAtsRpcTestDefine);
	void InitByAtsRpcTestDef_AddDevices_PP(CAtsRpcTestDefine *pAtsRpcTestDefine);
	void InitByAtsRpcTestDef_AddDevices_PP_Net(CAtsRpcTestDefine *pAtsRpcTestDefine, CExBaseList &listTask);
	void InitByAtsRpcTestDef_AddDevices_PP_Serial(CAtsRpcTestDefine *pAtsRpcTestDefine, CExBaseList &listTask);
	void InitAtsRpcTestTaskName(CAtsRpcTestDefine *pAtsRpcTestDefine, CExBaseList &listTask);
};

void sdvmpp_UpdateProjectName(CTestProject *pTestProject);

extern CAtsNewTestTool *g_theAtsNewTestTool;