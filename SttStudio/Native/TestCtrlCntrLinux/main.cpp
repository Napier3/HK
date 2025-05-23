#include "SttTestCntrFrameLinux.h"
#include "SttTestCntrApplication.h"
#include <QTextCodec>
#include <QSharedMemory>
#include <QMessageBox>
#include<QDebug>
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

//  #ifndef _PSX_QT_LINUX_
//  #include "../../../Module/XMinidmp/XMinidmp.h"
//  #endif

//2022-9-23  lijunqing
#include "../../Module/HtmlReport/IECTest/SttIecTestHtmlRptGenFactory.h"
#include "../../Module/SttTestCtrl/SttArgcArgvParser.h"
// extern bool g_bIsOpenMacroFromMain;

//2022-10-8  lijunqing
#include "../../Module/SmartTestInterface/QT/PpSttIotEngineDebugWidget.h"

#include "../../Module/UI/SttTestCntrCmdDefine.h"
#include "../../Module/UI/Module/CommonCtrl_QT/QSttProgDlg.h"
#include "../../../Module/OSInterface/QT/CDateTime_QT.h"
#include"../../../AutoTest/Module/Characteristic/CharInterfaceVariable.h"

#ifdef _PSX_OS_CENTOS_
#include "QX11Info"
#endif

QSttEventFilter *g_pSttEventFilter = NULL;
QSttProgDlg *g_pSttGlobalProgDlg = NULL;


//t2022-12-02  lijunqing
//macrotest macro_id=MUAccuracyTest;assist=admutest;iec=1;meas_svr=0;macro_file=AdmuTest;
//macrotest macro_id=MUAccuracyTest;assist=mutest;iec=1;meas_svr=0;macro_file=MuTest;
//macrotest macro_id=MUAccurAutoTest;assist=mutest;iec=1;meas_svr=1;macro_file=MuTest;
//open_dialog dialog_id=IecCapDialog;assist=relaytest;iec=0;meas_svr=0;
//open_dialog dialog_id=PpIotEngineClient;assist=relaytest;iec=0;meas_svr=0;
//open_dialog dialog_id=CommConfig;assist=relaytest;iec=0;meas_svr=0;
//macrotest macro_id=ManualTest;macro_file=RelayTest;assist=RelayTest;iec=0;meas_svr=0;
//macrotest macro_id=RemoteCtrlTest;macro_file=RemoteCtrlTest;assist=remotectrltest;iec=0;meas_svr=0;
//macrotest macro_id=RemoteMeasTest;macro_file=RelayTest;assist=RelayTest;iec=0;meas_svr=0;
//macrotest macro_id=DistSearchOneTest;macro_file=RelayTest;assist=RelayTest;iec=0;meas_svr=0;
//macrotest macro_id=ManualTest;sscl_path=D:/11/PONOVO/PONOVO.sscl;iec=0;meas_svr=0;macro_file=RelayTest;assist=RelayTest;
//macrotest macro_id=MUTimingAccurTest;assist=mutest;iec=1;meas_svr=0;macro_file=MuTest;
//macrotest macro_id=DistanceTest_I;macro_file=RelayTest;assist=RelayTest;iec=0;meas_svr=0;
//macrotest macro_id=IecCapTest;iec=1;meas_svr=0;macro_file=MuTest;assist=ieccaptest;



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
    volatile short i = 2;
    while (i--)
    {
        if(shareMem->attach(QSharedMemory::ReadOnly))
        {
            shareMem->detach();
        }
    }

    if(! shareMem->create(1))
	{//
		delete shareMem;
//		qDebug() << "Error: Stt_TestCtrlCntr_Native is exist !";
		return 0;
	}

#ifdef USE_Custom_CDateTime
	CDateTime::CreateClientDataTime();
#endif
	CreateSttTestCntrThread();
//	const qint64 current_msecs_since_epoch = QDateTime::currentMSecsSinceEpoch();

	//2022-10-5  lijunqing
	CSttArgcArgvParser oParser;
	oParser.Parser(argc, argv);

//    oParser.m_strCmdID = ARGV_CMD_ID_MACROTEST;
//     oParser.m_strMacroID = _T("ReplayTest");
//    oParser.m_strMacroFile = _T("RelayTest");
//    oParser.m_strAssistID = _T("RelayTest");

//       oParser.m_strCmdID = ARGV_CMD_ID_MACROTEST;
//       oParser.m_strMacroID = _T("MUAccuracyTest");
//       oParser.m_strMacroFile = _T("MuTest");
//       oParser.m_strAssistID = _T("mutest");
	CSttMacroTestUI_TestMacroUIDB::g_strMacroFileID = oParser.m_strMacroFile;
	//2022-9-23  lijunqing
    //sun CSttIecTestHtmlRptGenFactory *pHtmlRptGenFactory = new CSttIecTestHtmlRptGenFactory();
#ifdef _PSX_OS_CENTOS_
    Display *pDisplay = QX11Info::display();
    CSttTestCntrApplication oSttTestCntrApplication(pDisplay);
#else
	CSttTestCntrApplication oSttTestCntrApplication(argc, argv);
#endif

	oSttTestCntrApplication.InitSttTestApp(new CXLangResource_Native());

#ifndef _PSX_OS_CENTOS_
	g_pSttGlobalProgDlg = new QSttProgDlg(NULL);
	g_pSttGlobalProgDlg->initUI(g_sLangTxt_Native_LoadingBar,g_sLangTxt_Native_LoadingMacroTest);
	g_pSttGlobalProgDlg->setModal(false);
	g_pSttGlobalProgDlg->Start(0,100,50);
#endif
	
	CTickCount32 oTickCount;

#ifdef _PSX_QT_LINUX_
#ifndef _PSX_OS_CENTOS_
	if ((oParser.m_nWaitingTime>0)&&(oParser.m_nWaitingTime<=10000))
	{
		oTickCount.DoEvents(oParser.m_nWaitingTime + 10);
	}
	else
#endif
#endif
	{
		oTickCount.DoEvents(10);
	}

    //2023-3-1  lijunqing
    //QSttStartInfoWidget wndStartInfor;
    //wndStartInfor.show();
	CSttTestCtrlCntrNative *pSttTestCtrlCntrNative = new CSttTestCtrlCntrNative();
	oSttTestCntrApplication.SetSttTestCtrlCntr(pSttTestCtrlCntrNative);
    //sun pHtmlRptGenFactory->OpenDataTypesByMacroFileID(oParser.m_strMacroFile);
	CString strMacroID,strDialogID;
	//strMacroID = argv[1];
	strMacroID = oParser.m_strMacroID;
	strDialogID = oParser.m_strDialogID;

    //CSttMacroTestUI_TestMacroUIDB::g_strMacroFileID;
	oSttTestCntrApplication.SetCurrTestMacroUI(strMacroID);
    CSttMacroParaEditViewMngr::Create();
    QSttTestCntrFrameLinux oSttTestCntrFrameLinux;
	CString strFrameConfigPath;
//	oParser.m_strMacroFile = _T("RelayTest");

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
 	oSttTestCntrFrameLinux.InitFrame(strFrameConfigPath);
 	oSttTestCntrFrameLinux.SetTestCtrlCntrBase(oSttTestCntrApplication.m_pTestCtrlCntr);

	if (oParser.m_strCmdID == ARGV_CMD_ID_MACROTEST)
	{	//2022-10-5  lijunqing macrotest
		g_nTimeOut_Ats = 8000;//zhouhj 2024.3.21 增加超时时间,防止模板生成超时(合并单元精度测试)
// 		g_pSttMUTestIecCbSelWidget = new QSttMUTestIecCbSelWidget();
// 		g_pSttMUTestIecCbSelWidget->show();
#ifdef _PSX_OS_CENTOS_
        oSttTestCntrFrameLinux.setVisible(true);
#else
        oSttTestCntrFrameLinux.setWindowFlags(oSttTestCntrFrameLinux.windowFlags()
                                              | Qt::WindowStaysOnTopHint);
		oSttTestCntrFrameLinux.show();
#endif
        oSttTestCntrFrameLinux.raise();
        oSttTestCntrFrameLinux.activateWindow();
        oTickCount.DoEvents(50);//zhouhj 2024.3.22 解决打开界面后,只显示进度条,不显示主窗口问题
		oSttTestCntrFrameLinux.OpenMacroTestUI_Test(oSttTestCntrApplication.m_pTestMacroUI, "", "");
qDebug() << "Debug sun: from TestCtrlCntrLinux!!!! O";
        //sun if (oParser.m_nUseIec)
        //sun {
        //sun 	oSttTestCntrFrameLinux.InitSttIecRecord();
        //sun 	g_bSmartCap_RecordNow = 0;//
        //sun }
        //sun
        //sun if (oParser.m_nUseMeasServer)
        //sun {
        //sun 	pSttTestCtrlCntrNative->InitMeasServer();
        //sun }
qDebug() << "Debug sun: from TestCtrlCntrLinux!!!! P";
        //sun if (strMacroID == STT_ORG_MACRO_ReplayTest)
        //sun {
        //sun 	g_theBigComtradeTransPlay->CreateSttComtradeSocket();
        //sun }
        //sun else if (strMacroID == STT_ORG_MACRO_IecCapTest)
        //sun {
        //sun 	if (!g_oSttTestResourceMngr.HasLoadDevice())//
        //sun 	{
        //sun 		if (g_oSttTestResourceMngr.SelectDeviceFromLocalDB())
        //sun 		{
        //sun 			g_oSttTestResourceMngr.InitLocalSysPara();
        //sun 		}
        //sun 	}
        //sun }
qDebug() << "Debug sun: from TestCtrlCntrLinux!!!! Q";
        //sun if (g_theSttIecRecordMainWidget != NULL)
        //sun {
        //sun 	if ((oParser.m_strAssistID == STT_AssistID_MUTEST/*_T("mutest")*/))
        //sun 	{
        //sun 		oSttTestCntrFrameLinux.InitSttIecRecord();
        //sun 		g_bSmartCap_RecordNow = 0;//
        //sun 		g_theSttIecRecordMainWidget->InitIecRecordCbWidget(strMacroID,STT_IEC_DETECT_TYPE_61850_92);
        //sun 	}
        //sun 	else if (oParser.m_strAssistID == STT_AssistID_ADMUTEST)
        //sun 	{
        //sun 		oSttTestCntrFrameLinux.InitSttIecRecord();
        //sun 		g_bSmartCap_RecordNow = 0;//
        //sun 		g_theSttIecRecordMainWidget->InitIecRecordCbWidget(strMacroID,STT_IEC_DETECT_TYPE_60044);
        //sun 	}
        //sun }
qDebug() << "Debug sun: from TestCtrlCntrLinux!!!! Q";
		//2022-12-01  lijunqing
        //su assist_create(oSttTestCntrFrameLinux, oParser.m_strAssistID);

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
//		CLogPrint::LogFormatString(XLOGLEVEL_RESULT,_T("WaitingTime(%ld)."),oParser.m_nWaitingTime);
        //wndStartInfor.HideWidget();


// 		CString strDefautQssFilePath;
// 		strDefautQssFilePath = _P_GetBinPath();
// 		strDefautQssFilePath += "qt.qss";
// 
// 		QFile file(strDefautQssFilePath);  
// 		if (file.open(QFile::ReadOnly | QFile::Text)) 
// 		{  
// 			QString styleSheet = QLatin1String(file.readAll());  
// 			oSttTestCntrApplication.setStyleSheet(styleSheet);  
// 			file.close();  
// 		}

//		CXMessageBox::information(NULL,"008","000000" );

		CLogPrint::LogFormatString(XLOGLEVEL_INFOR,_T("%s(%ld)"),oParser.m_strMacroID.GetString(),
			oParser.m_nWaitingTime);
#ifndef _USE_IN_IED_QT5    //xueyangfan 隐藏鼠标光标
#ifdef _PSX_QT_LINUX_
#ifndef _PSX_OS_CENTOS_
        QApplication::setOverrideCursor(Qt::BlankCursor);
#endif
#endif
#endif
		oSttTestCntrApplication.exec();
qDebug() << "Debug sun: from TestCtrlCntrLinux!!!! S";
#ifdef _PSX_QT_LINUX_
		delete g_pSttEventFilter;
#endif
	}
	else if (oParser.m_strCmdID == ARGV_CMD_ID_OPENFILE)
	{////2022-10-5  lijunqing open auto test file : gbxml, gbrpt
		oSttTestCntrFrameLinux.SetAddMacroEnable(false);

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
		oSttTestCntrFrameLinux.OpenDialog(oParser.m_strDialogID);
	}
	else
	{
//		CXMessageBox::information(NULL,"032","000000" );
		if (g_pSttGlobalProgDlg)
		{
			g_pSttGlobalProgDlg->Stop();
		}
		oSttTestCntrFrameLinux.SetAddMacroEnable(true);
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
