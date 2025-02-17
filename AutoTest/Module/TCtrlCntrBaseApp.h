#pragma once

/*
	功能描述：自动测试的管理基类
	自动测试主程序、单机主程序的应用程序App类都从此类派生
	实现：工作任务的管理、测试管理
*/

#include "TaskMngr/TestLibraryTasks.h"

#include "TCtrlCntrConfig.h"
#include "TCtrlSystemConfig.h"
#include "TCtrlCntrWorkSpace.h"
#include "TestControl.h"
#include "TestControlManyReport.h"
#include "TestControlManyDevice.h"
#include "TestControlSdvMpp.h"
#include "TestControlMdvMgrp.h"

#include "..\..\Module\TestMacro\TestMacroInterface.h"
#include "..\..\Module\TestMacro\TestMacrosFileMngr.h"

#include "GuideBook\GbScriptFunctions.h"
#include "GuideBook\GbCommCmdConfig\GbCommCmdConfig.h"
//#include "..\..\Module\Office\WordCommandBarMngr.h"
//#include "..\..\Module\Office\WPSCommandBarMngr.h"
#include "..\..\Module\KeyDb\XKeyDB.h"
#include "..\..\Module\XfileMngrBase\XFileMngr.h"
#include "GuideBook\ReportMap\ReportTemplateConfig\ReportTemplateConfig.h"

#include "RecorderInterface.h"
#define _use_ppengine_exception  1

#ifdef _use_ppengine_exception
#include "..\..\Module\System\SysExeCpuUsage.h"
#endif

#include "PpEngineCreateMngr.h"
#include "MacroTestEngineCreateMngr.h"

#include "FactoryBatchTestMngr.h"

#include "..\..\Module\Office\WPS.h"
#include "..\..\Module\Office\KSO.h"
#include "GuideBook\ReportMap\WordReport\WordRptFill.h"
#include "GuideBook\ReportMap\WPSReport\WPSRptFill.h"

class CAutoTestXMLRWKeys;

UINT UI_GetGbTreeImageListID();			//获取GuideBookTreeImageList的图标ID，在CPAautoTest.cpp中实现

// #define _use_MACROTEST_MEM_

#ifdef _use_MACROTEST_MEM_
#include "..\..\Module\ShareMem\ShareMemServer.h"
#define	MACROTEST_MEMFILENAME	"_macro_test_ctrl.mrsm"
#define	MACROTEST_MAPNAME			"_macro_test_ctrl"
#define	MACROTEST_MAPSIZE			32768 //(64k*8)524288 + 1000
#endif

#define TEST_MODE_REPORT      0
#define TEST_MODE_TASK        1

//////////////////////////////////////////////////////////////////////////
//CTCtrlCntrBaseApp
class CTCtrlCntrBaseApp : public CWinAppEx
{
public:
	CTCtrlCntrBaseApp();
	virtual ~CTCtrlCntrBaseApp();

	virtual BOOL ats_IsRegisterTrue(BOOL bShowMsg, BOOL bFromTest=FALSE);

protected:
	DWORD m_dwTestMode;   //测试模式

#ifndef GUIDEBOOK_DEV_MODE
	CTestTask* m_pMttTestTask;
	PpEngine::IDevicePtr m_oMttPpDevice; //2019-6-4  测试任务对应的装置对象
#endif

	//CTestLibraryTasks* m_pTestTasks;  
	CTCtrlCntrConfig* m_pCtrlCntrConfig;
	CTCtrlSystemConfig* m_pSystemConfig;
	
	//支持多规约功能，即传统规约和61850MMS规约兼容  2016-8-15
	CPpEngineCreateMngr m_oPpEngineCreateMngr;

	//MacroTest::IMacroTestEngine m_pMacroTestEngine; //增加多测试仪控制功能，基于IO测试仪
	CMacroTestEngineCreateMngr m_oMacroTestEngineCreateMngr;

	//CTestMsgWnd *m_pTestMsgWnd;
	CWnd *m_pXTestMsgWnd;
	
	
#ifdef _use_MACROTEST_MEM_
	CShareMemServer *m_pMemServer;
#endif

#ifdef GB_USE_XFILEMNGRBASE
	CXFileMngr *m_pWaveFileMngr;
#else
	CFileMngrBase m_oWaveFileMngr;
#endif

	CXKeyDB m_oKeyDB;
	CRecorderInterface *m_oRecorder;
	CXFileMngr *m_pTestFileMngr;
	CReportTemplateConfig m_oReportTemplateConfig;

protected:
	//初始化方法
	long InitTCtrlBaseApp();
	long ExitTCtrlCntrBaseApp();
	void InitTaskMngr();
	void SaveTaskMngr();

	CImageList m_GbTreeImageList;
	CFont *m_pFontTestItem;
	void CreateGbTreeImageList(UINT nBitmapID, int cx, int nGrow, COLORREF crMask);

public:
#ifdef _use_ppengine_exception
	CSysExeCpuUsage m_oSysExeCpuUsage;
	long m_nPpMmsEngineCpuCounts;
	BOOL IsPpMmsEngineException();
#endif

#ifndef GUIDEBOOK_DEV_MODE
	CTestTask* GetMttTestTask()						{	return m_pMttTestTask;			}
	PpEngine::IDevicePtr GetMttPpDevice()						{	return m_oMttPpDevice;			}
	void SetMttPpDevice(PpEngine::IDevicePtr  oMttPpDevoce)						{	m_oMttPpDevice = oMttPpDevoce;			}
#endif

	CTCtrlCntrConfig* GetCntrConfig()				{	return m_pCtrlCntrConfig;	}
	CTCtrlSystemConfig* GetSystemConfig()			{	return m_pSystemConfig;		}
	CImageList* GetGbTreeImageList()				{	return &m_GbTreeImageList;	}
	
	//PpEngine
	PpEngine::IPpEnginePtr GetPpEngine(const CString &strProgID);
	BOOL HasPpEngine();

	//MacroTest
	MacroTest::IMacroTestEngine GetMacroTestEngine(const CString &strType, const CString &strProgID, const CString &strMacroFile);
	MacroTest::IMacroTest GetMacroTest(const CString &strType, const CString &strProgID, const CString &strMacroFile, const CString &strTestAppGroup);
	void ReleaseMacroTestEngine();
	virtual void InitMacroTestEngineShowSpyWnd();

	virtual void CreateMacroTestEngine(const CString &strMacroFile);
	virtual void CreatePpEngine();
	virtual void CreateAllEngine();
	virtual void InitPpEngineShowSpyWnd();
	virtual void StopProtocolParseForReadSoe(BOOL bStop);

	virtual BOOL IsMacroTCtrlException();
#ifdef GB_USE_XFILEMNGRBASE
	CXFileMngr* GetWaveFileMngr()	{	return m_pWaveFileMngr;		}
#else
	CFileMngrBase* GetWaveFileMngr()	{	return &m_oWaveFileMngr;		}
#endif
	void ExecuteMtCmd(const CString &strCmdID, const CString &strCmdPara);
	void ExecutePpEngineCmd(CTestControl *pTestControl, const CString &strCmdID, const CString &strCmdPara);

	CXKeyDB* GetXKeyDB()	{	return &m_oKeyDB;	}
	void InitRecorder(CTestControl *pTestControl);
	CRecorderInterface* GetRecorder()	{	return m_oRecorder;	}
	BOOL HasRecorder()	{	return m_pCtrlCntrConfig->HasRecorder();	}
	BOOL Is_UsePowerTestTrans();
	long GetSysRptShowMaxCount()	{	return m_pCtrlCntrConfig->GetSysRptShowMaxCount();	}
	void SetRecorderProgID(const CString &strProgID);
	long GetRecorderDelay()	{	return m_pCtrlCntrConfig->m_nRecordDelay;	}
	long GetAddRecorderReport()	{	return m_pCtrlCntrConfig->m_nAddRecordReport;	}
	BOOL GetAddRecorderReport_Engine()	{	return (m_pCtrlCntrConfig->m_nAddRecordReport == 2);	}
	BOOL GetAddRecorderReport_Recorder()	{	return (m_pCtrlCntrConfig->m_nAddRecordReport == 1);	}
	void ReleaseRecorder();

	CXFileMngr* GetTestFileMngr()	{	return m_pTestFileMngr;	}
	CString GetWorkSpacePath();

	//////////////////////////////////////////////////////////////////////////
	//测试任务部分
#ifndef GUIDEBOOK_DEV_MODE
	CTestTask* CreateNewTask(CTestTask *pTestTask);
	void OpenTaskFile(const CString &strTaskFile);
	void SaveTaskFile();
	void CloseTestTask();
	void ReleaseMttDevice();
#endif

	void SetTestMode_Task()		{	m_dwTestMode = TEST_MODE_TASK;				}
	void SetTestMode_Report()	{	m_dwTestMode = TEST_MODE_REPORT;			}
	BOOL IsTestMode_Task()		{	return (m_dwTestMode == TEST_MODE_TASK);	}
	BOOL IsTestMode_Report()	{	return (m_dwTestMode == TEST_MODE_REPORT);	}

	CBkmkDataProcessMngr* GetBkmkDataProcessMngr()		{	return m_oReportTemplateConfig.GetBkmkDataProcessMngr();	}

//报告处理部分
public:
	CRptFillAppBase* m_pRptFillAppBase;
	void CreateApp(PFUNC_RPTFILLAPP_CREATE pCreateFunc);
	void CreateReportApp();
/*	MSWord::_Application m_WordApp;
	MSWord::_Application GetWordApp(BOOL bShow=FALSE);
	void SetDocViewSettings();
	void RestoreDocViewSettings();
	void CloseWordApplication();

private:
	BOOL m_bShowParagraphs;
	BOOL m_bShowBookmarks;
	CWordCommandBarMngr m_WordCommandBarMngr;

	void CreateWordApplication(BOOL bShow=FALSE);
	void RestoreWordCommandBars();
*/
public:
	void FireTestItemErrorMsg(CGbItemBase *pItem, long nStopByError);
	void FireTestFinishMessage(BOOL bMttTaskFinish=FALSE);

	BOOL IsDebugWithoutReport()	{	return m_pCtrlCntrConfig->m_nDebugWithoutReport;	}
	BOOL IsDebugWithoutGbTree()	{	return m_pCtrlCntrConfig->m_nDebugWithoutGbTree;	}
	BOOL IsInsertDataLinkWhenEligible()	{	return m_pCtrlCntrConfig->m_nInsertDataLinkWhenEligible;	}
	BOOL IsSaveRptToDB()	{	return m_pCtrlCntrConfig->m_nSaveRptToDB;	}
	BOOL IsWriteTestTempFile()	{	return m_pCtrlCntrConfig->m_nWriteTestTempFile;	}
	BOOL IsFillReport()	{	return m_pCtrlCntrConfig->m_nFillReport;	}
	void SetSaveRptToDB(BOOL b)	{	m_pCtrlCntrConfig->m_nSaveRptToDB = b;	}
	long GetReportControl()	{	return m_pCtrlCntrConfig->GetReportControl();	}

	CString GetPpTemplateFilePath();

//其他
public:
	UINT m_nDsvImage;

public:
	CString GetPpEngineCmdID()		{	return m_strPpEngineCmdID;		}
	CString GetPpEngineCmdPara()	{	return m_strPpEngineCmdPara;	}
	void ResetPpEngineCmd()			{	m_strPpEngineCmdID.Empty();		}
	void WritePpMmsEngineConfig();
#ifndef GUIDEBOOK_DEV_MODE
	void WritePpMmsEngineConfig(CTestTask *pTestTask);
#endif

	void ReleasePpEngine(const CString &strProgID);
	void ReleasePpEngine();

protected:
	CString m_strPpEngineCmdID;
	CString m_strPpEngineCmdPara;

	void ExecutePpEngineCmd_NORMAL(CTestControl *pTestControl, const CString &strCmdID, const CString &strCmdPara);
	void ExecutePpEngineCmd_MGBRPT(CTestControl *pTestControl, const CString &strCmdID, const CString &strCmdPara);
	void ExecutePpEngineCmd_MDGBRPT(CTestControl *pTestControl, const CString &strCmdID, const CString &strCmdPara);
};

BOOL TCC_IsDebugWithoutReport();
COLORREF TCC_GetItemStateColor(CGbItemBase *pItem, BOOL bEnable=TRUE);
extern CTCtrlCntrBaseApp *g_theTCtrlCntrApp;
extern CRptFillAppBase *g_theRptFillApp;

void Init_ShowTestWndTop(BOOL bMinimize);

