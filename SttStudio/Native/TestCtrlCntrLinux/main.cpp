#include "SttTestCntrFrameLinux.h"
#include "SttTestCntrApplication.h"
#include "hkmainwindow.h"
#include <QTextCodec>
#include <QSharedMemory>
#include <QMessageBox>
#include <QDebug>
#include "../../../Module/API/GlobalConfigApi.h"
#include "../../../Module/OSInterface/QT/XMessageBox.h"
#include "../../../Module/XLanguage/XLanguageMngr.h"
#include "../../Module/XLangResource_Native.h"
#include "../../Module/SttTestCtrl/SttTestCtrlCntrNative.h"
#include "../../../Module/API/StringConvertApi.h"
#include "../../Module/ReplayTest/BigComtradeTransPlay.h"
#include "../../Module/UI/SttEventFilter/SttEventFilter.h"
#include "../../Module/SttTest/Common/LineVolt/tmt_linevolt_gradient_test.h"
#include "../../Module/RecordTest/UI/SttIecRecordDetectWidget.h"
#include "../../Module/RecordTest/UI/MUTest/SttMUTestIecCbSelWidget.h"

#include "../../Module/HtmlReport/IECTest/SttIecTestHtmlRptGenFactory.h"
#include "../../Module/SttTestCtrl/SttArgcArgvParser.h"
#include "../../Module/SmartTestInterface/QT/PpSttIotEngineDebugWidget.h"
#include "../../Module/UI/SttTestCntrCmdDefine.h"
#include "../../Module/UI/Module/CommonCtrl_QT/QSttProgDlg.h"
#include "../../../Module/OSInterface/QT/CDateTime_QT.h"
#include"../../../AutoTest/Module/Characteristic/CharInterfaceVariable.h"

QSttEventFilter *g_pSttEventFilter = NULL;
QSttProgDlg *g_pSttGlobalProgDlg = NULL;

#include "../../Module/UI/SttTestCntrThread.h"

void assist_create(QSttTestCntrFrameLinux &oSttTestCntrFrameLinux, const CString &strAssistID)
{
	assist_create(strAssistID);

	QSttToolButtonBase *pButton = NULL;
	CSttFrame_Button *pBtnAssist = oSttTestCntrFrameLinux.m_pSttFrameConfig->FindBtnByID(STT_CNTR_CMD_Assist);

	if (pBtnAssist != NULL)
	{
		pButton = (QSttToolButtonBase*)pBtnAssist->m_dwItemData;
	}

	assist_set_entry_wnd(pButton);
}

int main(int argc, char *argv[])
{
    QSharedMemory *shareMem = new QSharedMemory(QString("Stt_TestCtrlCntr_Native"));

#ifdef USE_Custom_CDateTime
	CDateTime::CreateClientDataTime();
#endif
	CreateSttTestCntrThread();

	CSttArgcArgvParser oParser;
	oParser.Parser(argc, argv);
	CSttMacroTestUI_TestMacroUIDB::g_strMacroFileID = oParser.m_strMacroFile;
	CSttTestCntrApplication oSttTestCntrApplication(argc, argv);
	oSttTestCntrApplication.InitSttTestApp(new CXLangResource_Native());

	g_pSttGlobalProgDlg = new QSttProgDlg(NULL);
	g_pSttGlobalProgDlg->initUI(g_sLangTxt_Native_LoadingBar,g_sLangTxt_Native_LoadingMacroTest);
	g_pSttGlobalProgDlg->setModal(false);
	g_pSttGlobalProgDlg->Start(0,100,50);
	
	CTickCount32 oTickCount;
	if ((oParser.m_nWaitingTime>0)&&(oParser.m_nWaitingTime<=10000))
	{
		oTickCount.DoEvents(oParser.m_nWaitingTime + 10);
	}
	else
	{
		oTickCount.DoEvents(10);
	}
	CSttTestCtrlCntrNative *pSttTestCtrlCntrNative = new CSttTestCtrlCntrNative();
	oSttTestCntrApplication.SetSttTestCtrlCntr(pSttTestCtrlCntrNative);
	CString strMacroID,strDialogID;
    //strMacroID = argv[1];
    strMacroID = oParser.m_strMacroID;
	strDialogID = oParser.m_strDialogID;
	oSttTestCntrApplication.SetCurrTestMacroUI(strMacroID);
    CSttMacroParaEditViewMngr::Create();
    //sun QSttTestCntrFrameLinux oSttTestCntrFrameLinux;
    HKMainWindow testHKMainWindow;
	CString strFrameConfigPath;
    stt_xml_serialize_write_LineVolGradientTest();
	if (!oParser.m_strMacroFile.IsEmpty())
	{
		strFrameConfigPath.Format(_T("%s/TestCntrlFrameConfig.xml"),oParser.m_strMacroFile.GetString());
	}
	else
	{
		strFrameConfigPath = _T("TestCntrlFrameConfig.xml");
	}

	if (IsFileExist(oParser.m_strSsclFilePath))
	{
		pSttTestCtrlCntrNative->m_oSclStation.OpenSclStationFile(oParser.m_strSsclFilePath);
	}
    //sun oSttTestCntrFrameLinux.InitFrame(strFrameConfigPath);
    //sun oSttTestCntrFrameLinux.SetTestCtrlCntrBase(oSttTestCntrApplication.m_pTestCtrlCntr);

	if (oParser.m_strCmdID == ARGV_CMD_ID_MACROTEST)
    {
        g_nTimeOut_Ats = 8000;
        //sun oSttTestCntrFrameLinux.setWindowFlags(oSttTestCntrFrameLinux.windowFlags() | Qt::WindowStaysOnTopHint);
        testHKMainWindow.show();
        testHKMainWindow.raise();
        testHKMainWindow.activateWindow();
        oTickCount.DoEvents(50);//zhouhj 2024.3.22 解决打开界面后,只显示进度条,不显示主窗口问题
        //sun oSttTestCntrFrameLinux.OpenMacroTestUI_Test(oSttTestCntrApplication.m_pTestMacroUI, "", "");
#ifdef _PSX_QT_LINUX_
		g_pSttEventFilter = new QSttEventFilter();
		oSttTestCntrApplication.installEventFilter(g_pSttEventFilter);
        //	CLogPrint::LogFormatString(XLOGLEVEL_TRACE,strFrameConfigPath.GetString());
#endif

		if (g_pSttGlobalProgDlg)
		{
			g_pSttGlobalProgDlg->Stop();
		}
qDebug() << "Debug sun: from TestCtrlCntrLinux!!!! R";

		CLogPrint::LogFormatString(XLOGLEVEL_INFOR,_T("%s(%ld)"),oParser.m_strMacroID.GetString(),
			oParser.m_nWaitingTime);
#ifndef _USE_IN_IED_QT5    //xueyangfan 隐藏鼠标光标
#ifdef _PSX_QT_LINUX_
#ifndef _PSX_OS_CENTOS_
        QApplication::setOverrideCursor(Qt::BlankCursor);
#endif
#endif
#endif
        QApplication::setOverrideCursor(Qt::BlankCursor);
		oSttTestCntrApplication.exec();
qDebug() << "Debug sun: from TestCtrlCntrLinux!!!! S";
#ifdef _PSX_QT_LINUX_
		delete g_pSttEventFilter;
#endif
	}
	else if (oParser.m_strCmdID == ARGV_CMD_ID_OPENFILE)
    {////2022-10-5  lijunqing open auto test file : gbxml, gbrpt
        //sun oSttTestCntrFrameLinux.SetAddMacroEnable(false);

		if (g_pSttGlobalProgDlg)
		{
			g_pSttGlobalProgDlg->Stop();
		}
	}
	else if (oParser.m_strCmdID == ARGV_CMD_ID_OPENDIALOG)
	{
  //      CXMessageBox::information(NULL,"022","000000" );
        if (g_pSttGlobalProgDlg)
		{
			g_pSttGlobalProgDlg->Stop();
		}
        //sun oSttTestCntrFrameLinux.OpenDialog(oParser.m_strDialogID);
	}
	else
	{
//		CXMessageBox::information(NULL,"032","000000" );
        if (g_pSttGlobalProgDlg)
		{
			g_pSttGlobalProgDlg->Stop();
		}
        //sun oSttTestCntrFrameLinux.SetAddMacroEnable(true);
	}

//	CXMessageBox::information(NULL,"042","000000" );
    if (g_pSttGlobalProgDlg)
	{
		delete g_pSttGlobalProgDlg;
		g_pSttGlobalProgDlg = NULL;
	}

    if(shareMem->isAttached())
        shareMem->detach();
    delete shareMem;

    CSttMacroParaEditViewMngr::Release();

    //2022-9-23  lijunqing
    //sun delete pHtmlRptGenFactory;

	ReleaseSttTestCntrThread();

#ifdef USE_Custom_CDateTime
	CDateTime::ReleaseClientDataTime();
#endif
    return 0;
}
