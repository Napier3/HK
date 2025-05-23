#-------------------------------------------------
#
# Project created by QtCreator 2022-01-09T11:03:48
#
#-------------------------------------------------

#QT       += core gui webkit network xml webkitwidgets
QT       += core gui network xml printsupport
QT += widgets

DEFINES +=_PSX_IDE_QT_  _QT_IN_LINUX_ OS_QT_LINUX _PSX_QT_LINUX_ _USE_SoftKeyBoard_ #not_use_FreqCalFix50Hz
DEFINES +=XML_USE_PUGIXML  NO_XDbBaseLib UNICODE #_CHAR_LIB_DEV_
DEFINES +=CURLINUX NOT_USE_GB_SCRIPT #_PSX_OS_CENTOS_
DEFINES +=DEBUG_MODE _PSX_QT_SRCFILE_GBK_ _DVMDATASET_USE_ADDR_ USE_Custom_CDateTime
DEFINES +=_USE_SMARTTEST_INTERFACE_STT_ _USE_SMARTTEST_INTERFACE_ENGINE_STT_ _STT_NOT_IN_TEST_SERVER_
DEFINES +=STT_CMD_PARAS_HAS_GUIDEBOOK _USE_IN_IED_QT5 #USE_IN_Astra_LINUX
DEFINES +=_SCRIPT_USE_XVM JSON_USE_ _not_use_CTCtrlCntrConfig Not_USE_IECCFGFILES #NOT_USE_XLANGUAGE
DEFINES +=_no_use_RecordCompare_ _USE_IN_AT02D_MODE_ XDrawMngr_NO_MemBufferDC
DEFINES += USE_AXIS_CONFIG SST_AT02_PKT_HEAD_USE_RESERVE CHARELEUIVP not_use_GbWzdAiTool

INCLUDEPATH += ../../../Module/BaseClass
INCLUDEPATH += ../../../Module/OSInterface
INCLUDEPATH += ../../../Module/OSInterface/QT
INCLUDEPATH += ../../Module/UI/Controls
INCLUDEPATH += ../../Module/UI/Module/CharLibWidget

INCLUDEPATH += /usr/local/qwt-6.1.2/include
LIBS += -L "/usr/local/qwt-6.1.2/lib" -lqwt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestCtrlCntrLinux
TEMPLATE = app


SOURCES += main.cpp\
    ../../Module/SttCmdToolMngr.cpp \
    ../../Module/SttTestSysGlobalPara.cpp \
    ../../../Module/XLanguage/XLanguageResource.cpp \
    ../../../61850/Module/XLanguageResourceIec.cpp \
    ../../../61850/Module/XLanguageResourcePp_Mms.cpp \
    ../../../AutoTest/Module/XLanguageResourceAts.cpp \
    ../../Module/XLangResource_Native.cpp \
    ../../Module/SttCmd/SttAssistCmd.cpp \
    ../../Module/SttCmd/SttAtsCmd.cpp \
    ../../Module/SttCmd/SttCmdBase.cpp \
    ../../Module/SttCmd/SttCmdCreator.cpp \
    ../../Module/SttCmd/SttCmdDefineGlobal.cpp \
    ../../Module/SttCmd/SttMacro.cpp \
    ../../Module/SttCmd/SttParas.cpp \
    ../../Module/SttCmd/SttRemoteCmd.cpp \
    ../../Module/SttCmd/SttSysState.cpp \
    ../../Module/SttCmd/SttSystemCmd.cpp \
    ../../Module/SttCmd/SttTestCmd.cpp \
    ../../Module/SttCmd/SttCmdData.cpp \
    ../../Module/SttCmd/SttMsg.cpp \
    ../../Module/SttCmd/SttMsgs.cpp \
    ../../Module/SttCmd/SttAdjustCmd.cpp \
    ../../Module/SttCmd/GuideBook/SttCommCmd.cpp \
    ../../Module/SttCmd/GuideBook/SttDataObj.cpp \
    ../../Module/SttCmd/GuideBook/SttDevice.cpp \
    ../../Module/SttCmd/GuideBook/SttGuideBook.cpp \
    ../../Module/SttCmd/GuideBook/SttItemBase.cpp \
    ../../Module/SttCmd/GuideBook/SttItems.cpp \
    ../../Module/SttCmd/GuideBook/SttJobGuide.cpp \
    ../../Module/SttCmd/GuideBook/SttMacroTest.cpp \
    ../../Module/SttCmd/GuideBook/SttReport.cpp \
    ../../Module/SttCmd/GuideBook/SttReports.cpp \
    ../../Module/SttCmd/GuideBook/SttRptData.cpp \
    ../../Module/SttCmd/GuideBook/SttSafety.cpp \
    ../../Module/SttCmd/GuideBook/SttSysParaEdit.cpp \
    ../../Module/SttCmd/GuideBook/SttSysParas.cpp \
    ../../Module/SttCmd/SttChMap.cpp \
    ../../Module/SttCmd/SttChMaps.cpp \
    ../../Module/SttCmd/SttHdCh.cpp \
    ../../Module/SttCmd/SttHdChs.cpp \
    ../../Module/SttCmd/SttIotDevice.cpp \
    ../../Module/SttCmd/SttIotDevices.cpp \
    ../../Module/SttCmd/SttIotNode.cpp \
    ../../Module/SttCmd/SttIotTopo.cpp \
    ../../Module/SttCmd/SttDebugCmd.cpp \
    ../../Module/SttCmd/SttRptMapDatas.cpp \
    ../../Module/SttCmd/GuideBook/SttReportMap.cpp \
    ../../Module/SttCmd/GuideBook/SttContents.cpp \
    ../../Module/SttCmd/GuideBook/SttItemStateObject.cpp \
    ../../Module/SttCmd/GuideBook/SttMacroCharItems.cpp \
    ../../Module/SttCmd/SttIotCmd.cpp \
    ../../Module/SttCmd/GuideBook/SttItemRsltExpr.cpp \
    ../../Module/SttCmd/GuideBook/SttTestMacroCharParas.cpp \
    ../../Module/SttCmd/GuideBook/SttTestMacroUiParas.cpp \
    ../../Module/Engine/SttClientTestEngine.cpp \
    ../../Module/Engine/SttTestEngineBase.cpp \
    ../../Module/Engine/SttTestEngineClientData.cpp \
    ../../Module/Engine/SttServerNativeConfig.cpp \
    ../../Module/Engine/SttRemoteClientTestEngine.cpp \
    ../../Module/Engine/SttTestEngineRemoteClientData.cpp \
    ../../Module/Engine/SttTestServerBase.cpp \
    ../../Module/Engine/SttTestEngineServerBase.cpp \
    ../../Module/Engine/SttTestEngineServerData.cpp \
   ../../Module/Engine/SttServerTestCtrlCntr.cpp \
    #sun ../../Module/Engine/PpMeas/PpSttIotEngineDeviceBase.cpp \
    #sun ../../Module/Engine/PpMeas/PpSttIotMeasDevice.cpp \
    #sun ../../Module/Engine/PpMeas/PpSttIotMeasServer.cpp \
    #sun ../../Module/Engine/PpEngineServerBase/SttPxPotoEngineBase.cpp \
    #sun ../../Module/Engine/PpEngineServerBase/SttPpServerSocket.cpp \
    #sun ../../Module/Engine/PpEngineServerBase/SttPpServerClientSocket.cpp \
    #sun ../../Module/Engine/PpEngineServerBase/SttPpEngineServer.cpp \
    ../../Module/SttSocket/SttServerSocketDataBase.cpp \
    ../../Module/SttSocket/SttSocketDataBase_File.cpp \
    ../../Module/SttSocket/SttCmdOverTimeMngr.cpp \
    ../../Module/SttSocket/TestTerminal/SttClientSocketBase.cpp \
    ../../Module/SttSocket/TestTerminal/QT/SttClientSocket.cpp \
    ../../Module/SttSocket/TestServer/SttNativeRemoteClientSocketBase.cpp \
    ../../Module/SttSocket/TestServer/SttServerClientSocketBase.cpp \
    ../../Module/SttSocket/TestServer/SttTestServerSocketBase.cpp \
    ../../Module/SttSocket/TestServer/QT/SttNativeRemoteClientSocket.cpp \
    ../../Module/SttSocket/TestServer/QT/SttServerClientSocket.cpp \
    ../../Module/SttSocket/TestServer/QT/SttTestServerSocket.cpp \
    ../../Module/SttSocket/SttSocketDataBase.cpp \
    ../../Module/SttSocket/Multicast/SttMulticastClientSocket.cpp \
    ../../Module/SttSocket/Multicast/SttUdpSocketDataBase.cpp \
    ../../Module/TestClient/SttAtsTestClient.cpp \
    ../../Module/TestClient/SttTestClientBase.cpp \
    ../../Module/TestClient/PpSttIotClient.cpp \
    ../../Module/SttAuthority/SttTestClientUser.cpp \
    ../../Module/SttAuthority/SttTestClientUserMngr.cpp \
    ../../Module/SttAuthority/SttTestRemoteRegister.cpp \
    ../../Module/SttProtocolBufBase.cpp \
    ../../Module/SttRegisterCode.cpp \
    ../../Module/SttFileToolMngr.cpp \
    ../../Module/UI/Module/ScrollCtrl/ScrollComboBox.cpp \
    ../../Module/UI/Module/ScrollCtrl/ScrollListView.cpp \
    ../../Module/UI/Module/ScrollCtrl/ScrollTableWidget.cpp \
    ../../Module/UI/Module/ScrollCtrl/ScrollWebView.cpp  \
    ../../Module/RecordTest/RingMemBuf.cpp \
    ../../Module/RecordTest/RingMemBufShm.cpp \
    ../../Module/RecordTest/QT/SttLocalRcdMemBufferMngrLinux.cpp \
    ../../Module/RecordTest/UI/SttIecCbGrid.cpp \
    ../../Module/RecordTest/UI/SttIecRecordMainWidget.cpp \
    ../../Module/RecordTest/UI/SttIecChsGridBase.cpp \
    ../../Module/RecordTest/UI/SttIecRcdFuncInterface.cpp \
    ../../Module/RecordTest/UI/SttIecRecordCbWidget.cpp \
    ../../Module/RecordTest/UI/SttIecSmvGrid_EffecValue.cpp \
    ../../Module/RecordTest/UI/SttIecSmvWaveWidget.cpp \
    ../../Module/RecordTest/UI/SttIecGooseGrid_TurnList.cpp \
    ../../Module/RecordTest/UI/SttIecGooseGrid_RT.cpp \
    ../../Module/RecordTest/UI/SttIecSmvGrid_AD.cpp \
    ../../Module/RecordTest/UI/SttIecSmvGrid_Harm.cpp \
    ../../Module/RecordTest/UI/SttIecSmvGrid_Power.cpp \
    ../../Module/RecordTest/UI/SttIecEmptyWidget.cpp \
    ../../Module/RecordTest/UI/SttIecSmvPolarWidget.cpp \
    ../../Module/RecordTest/UI/SttIecSmvSequenceWidget.cpp \
    ../../Module/RecordTest/UI/SttIecSmvVectorWidget.cpp \
    ../../Module/RecordTest/UI/SttIecSmvGrid_ChAttr.cpp \
    ../../Module/RecordTest/UI/SttIecSmvMeterAxisWidget.cpp \
    ../../Module/RecordTest/UI/SttIecSmvGrid_PkgAnalyze.cpp \
    ../../Module/RecordTest/UI/SttIecSmvGrid_PkgError.cpp \
    ../../Module/RecordTest/UI/SttIecGooseGrid_PkgAnalyze.cpp \
    ../../Module/RecordTest/UI/SttIecGooseTurnSpyWidget.cpp \
    ../../Module/RecordTest/UI/SttIecGsBinaryDrawView.cpp \
    ../../Module/RecordTest/UI/SttIecGsBinaryDraw.cpp \
    ../../Module/RecordTest/UI/SttIecRecordSysSetDlg.cpp \
    ../../Module/RecordTest/UI/SttIecRecordWriteFileWidget.cpp \
    ../../Module/RecordTest/UI/SttIecSmvGrid_MUAccuracy.cpp \
    ../../Module/RecordTest/UI/SttIecMUAccuracyWidget.cpp \
    ../../Module/RecordTest/UI/SttIecSmvGrid_MUErrorStatis.cpp \
    ../../Module/RecordTest/UI/SttIecMUTimeWidget.cpp \
    ../../Module/ReplayTest/SttModuleChComtradeBind.cpp \
    ../../Module/ReplayTest/SttCmtrdCfgDefineGlobal.cpp \
    ../../Module/ReplayTest/ComtradeSendSocket.cpp \
    ../../Module/ReplayTest/ComtradePlayConfig.cpp \
    ../../Module/ReplayTest/ComtradeDataBuffer.cpp \
    ../../Module/ReplayTest/ComtradeBufMngr.cpp \
    ../../Module/ReplayTest/BigComtradeTransPlay.cpp \
    ../../Module/ReplayTest/BigComtradeFileRead.cpp \
    ../../Module/RecordTest/UI/SttIecSmvGrid_ChQualitySpy.cpp \
    ../../Module/RecordTest/UI/MUTest/SttMUTestIecCbSelWidget.cpp \
    ../../Module/RecordTest/UI/SttIecCapDialog.cpp \
    ../../Module/RecordTest/UI/MUTest/SttIecRecordCbInterface.cpp \
    ../../Module/RecordTest/UI/MUTest/SttMUTestChsSetDlg.cpp \
    ../../Module/RecordTest/UI/MUTest/SttMUTestRecordCbWidget.cpp \
    ../../Module/RecordTest/UI/SttIecSmvMUAccuaryGrid.cpp \
    ../../Module/RecordTest/UI/SttIecSmvDiscretCharWidget.cpp \
    ../../Module/RecordTest/UI/SttIecSmvDiscretChartAxis.cpp \
    ../../Module/RecordTest/UI/SttIecSmvWidget_Harm_Histogram.cpp \
    ../../Module/RecordTest/UI/SttIecSmvWidget_Harm.cpp \
    ../../Module/RecordTest/UI/SttIecSmvGrid_Harm_Content.cpp \
    ../../Module/RecordTest/UI/SttIecSmvHistogramChartAxis.cpp \
    ../../Module/RecordTest/UI/FT3_Test/SttIecFT3Grid_RT.cpp \
    ../../Module/RecordTest/UI/SttRecordChComparePlot.cpp \
    ../../Module/RecordTest/UI/MUTest/FirstCircleWave/SttMUTestFirstCwWidget.cpp \
    ../../Module/RecordTest/UI/SttIecRecordDetectWidget.cpp \
    ../../Module/RecordTest/UI/FT3_Test/SttIecFT3LineNumberPlanTextEdit.cpp \
    ../../Module/RecordTest/UI/FT3_Test/SttIecFT3OriginalMsgWidget.cpp \
    ../../Module/RecordTest/UI/SttIecSmvWaveMainWidget.cpp \
    ../../Module/RecordTest/UI/SttIecGooseGrid_PkgError.cpp \
    ../../Module/SttTestAppConfig/SttTestAppCfg.cpp \
    ../../Module/SttTestAppConfig/SttTestAppConfigTool.cpp \
    ../../Module/SttTestAppConfig/SttTestDeviceCfg.cpp \
    ../../Module/AdjustTool/SttAdjBase.cpp \
    ../../Module/AdjustTool/SttAdjDevice.cpp \
    ../../Module/AdjustTool/SttAdjModule.cpp \
    ../../Module/AdjustTool/SttMesLocalDb.cpp \
    ../../Module/Protocol/SttProtocolDatas.cpp \
    ../../Module/SttTestBase/SttComplexCalApi.cpp \
    ../../Module/SttTestBase/SttMacroXmlKeys.cpp \
    ../../Module/SttTestBase/SttXmlSerialize.cpp \
    ../../Module/SttTestBase/SttXmlSerializeBase.cpp \
    ../../Module/SttTestBase/SttComplexp.cpp \
    ../../Module/SttTestBase/SttDiffCurrCalculatTool.cpp \
    ../../Module/SttTest/SttTestGlobaoConfig.cpp \
    ../../Module/SttTest/Common/tmt_adjust_sys_parameter.cpp \
    ../../Module/SttTest/Common/tmt_adjust_sys_para_trans.cpp \
    ../../Module/SttTest/Common/tmt_pt_test.cpp \
    ../../Module/SttTest/Common/tmt_soe_test.cpp \
    ../../Module/SttTest/Common/tmt_system_config.cpp \
    ../../Module/SttTest/Common/tmt_test_mngr.cpp \
    ../../Module/SttTest/Common/tmt_test_paras_head.cpp \
    ../../Module/SttTest/Common/Abnormal/tmt_abnormal_test.cpp \
    ../../Module/SttTest/Common/tmt_state_test.cpp \
    ../../Module/SttTest/Common/ActionTime/tmt_vol_inverse_time_test.cpp \
    ../../Module/SttTest/Common/Impedance/tmt_cb_operate_test.cpp \
    ../../Module/SttTest/Common/Impedance/tmt_distance_test.cpp \
    ../../Module/SttTest/Common/Impedance/tmt_impedance_test.cpp \
    ../../Module/SttTest/Common/Impedance/tmt_reclose_acc_test.cpp \
    ../../Module/SttTest/Common/SearchBase/tmt_complex_search.cpp \
    ../../Module/SttTest/Common/SearchBase/tmt_search_base.cpp \
    ../../Module/SttTest/Common/tmt_gradient_test.cpp \
    ../../Module/SttTest/Common/tmt_harm_test.cpp \
    ../../Module/SttTest/Common/Sequence/tmt_sequence_gradient_test.cpp \
    ../../Module/SttTest/Common/Sequence/tmt_sequence_manu_test.cpp \
    ../../Module/SttTest/Common/LineVolt/tmt_linevolt_gradient_test.cpp \
    ../../Module/SttTest/Common/LineVolt/tmt_linevolt_manu_test.cpp \
    ../../Module/SttTest/Common/tmt_short_time_over_test.cpp \
    ../../Module/SttTest/Common/Gradient/tmt_fault_gradient_test.cpp \
    ../../Module/SttTest/Common/FAParasSet/tmt_fa_Paras_set.cpp \
    ../../Module/SttTest/Common/tmt_manu_test.cpp \
    ../../Module/SttTest/Common/tmt_replay_test.cpp \
    ../../Module/SttSystemConfig/SttDevConfig.cpp \
    ../../Module/SttSystemConfig/SttModule.cpp \
    ../../Module/SttSystemConfig/SttModuleUse.cpp \
    ../../Module/SttSystemConfig/SttSystemConfig.cpp \
    ../../Module/SttSystemConfig/SttSystemConfigGlobal.cpp \
    ../../Module/SttTestResourceMngr/SttTestResourceMngr.cpp \
    ../../Module/SttTestResourceMngr/RtDataMngr/SttGlobalRtDataMngr.cpp \
    ../../Module/SttTestResourceMngr/RtDataMngr/SttMacroChannels.cpp \
    ../../Module/SttTestResourceMngr/RtDataMngr/SttMacroChannelsAsync.cpp \
    ../../Module/SttTestResourceMngr/TestResource/SttTestResource_4U3I.cpp \
    ../../Module/SttTestResourceMngr/TestResource/SttTestResource_6U6I.cpp \
    ../../Module/SttTestResourceMngr/TestResource/SttTestResource_Async.cpp \
    ../../Module/SttTestResourceMngr/TestResource/SttTestResourceBase.cpp \
    ../../Module/SttTestResourceMngr/TestResource/SttTestResource_Sync.cpp \
    ../../Module/BinaryDraw/XBinaryDrawBase.cpp \
    ../../Module/BinaryDraw/XBinaryDrawGlobal.cpp \
    ../../Module/BinaryDraw/XBinaryDrawView.cpp \
    ../../Module/LiveUpdate/UpdateConfig/VerUpdateCfgMngr.cpp \
    ../../Module/LiveUpdate/UpdateConfig/VerUpdateCfgMngrGlobal.cpp \
    ../../Module/LiveUpdate/UpdateConfig/VerUpdateCfgSys.cpp \
    ../../Module/LiveUpdate/UpdateConfig/VerUpdateCfgSyses.cpp \
    ../../Module/LiveUpdate/UpdateConfig/VerUpdateCfgYun.cpp \
    ../../Module/LiveUpdate/SttLiveUpdateShell.cpp \
    ../../Module/LiveUpdate/SttUpdateCfg.cpp \
    #sun ../../Module/SmartTestInterface/PpSttIotEngineClientApp.cpp \
    #sun ../../Module/SmartTestInterface/PpSttIotEngine.cpp \
    ../../Module/SmartTestInterface/PpSttCommConfig.cpp \
     #sun ../../Module/SmartTestInterface/QT/PpSttIotEngineClientAppWnd.cpp \
     #sun ../../Module/SmartTestInterface/QT/PpSttIotEngineClientWidget.cpp \
     #sun ../../Module/SmartTestInterface/QT/PpSttIotEngineClientWidgetMain.cpp \
    #sun ../../Module/SmartTestInterface/QT/SttPxEngineDsEditGrid.cpp \
    #sun ../../Module/SmartTestInterface/QT/SttPxEngineDvmTreeCtrl.cpp \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/ppcommconfigdlg.cpp \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommcfgtcpclientdlg.cpp \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommconfigcmsdlg.cpp \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommconfigmmsdlg.cpp \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommconfigserialmode.cpp \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommconfigtcpserverdlg.cpp \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommconfigudpclientdlg.cpp \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommconfigudpserver.cpp \
    #sun ../../Module/SmartTestInterface/QT/qsttmmsbrcbctrlwidget.cpp \
    #sun ../../Module/SmartTestInterface/QT/qsttzoneindexsetdlg.cpp \
    #sun ../../Module/SmartTestInterface/PpXIotEngineBase.cpp \
    ../../Module/API/NetworkInterface.cpp \
    ../../Module/API/QT/NetworkInterface_QT.cpp \
    #sun ../../Module/HtmlReport/SttModuleHtmlRptGenBase.cpp \
    #sun ../../Module/HtmlReport/SttXHtmlRptGenFactoryBase.cpp \
    #sun ../../Module/HtmlReport/SttXHtmlRptGenInterface.cpp \
    #sun ../../Module/HtmlReport/SttXmacroHtmlRptGenBase.cpp \
    #sun ../../Module/HtmlReport/IECTest/SttHtmlRptGen_MUAccuracy.cpp \
    #sun ../../Module/HtmlReport/IECTest/SttIecTestHtmlRptGenFactory.cpp \
    #sun ../../Module/HtmlReport/IECTest/SttHtmlRptGen_MUPunctAccur.cpp \
    #sun ../../Module/HtmlReport/IECTest/SttHtmlRptGen_MUTimingAccur.cpp \
    #sun ../../Module/HtmlReport/IECTest/SttHtmlRptGen_MUZeroDrift.cpp \
    #sun ../../Module/HtmlReport/IECTest/SttHtmlRptGen_IntelligentTerminal.cpp \
    ../../Module/Assist/SttAppWndAssistInterface.cpp \
    ../../Module/Assist/SttAssistEngine.cpp \
    ../../Module/Assist/SttAssistGlobalApi.cpp \
    ../../Module/Assist/SttAssistInterface.cpp \
    ../../Module/Assist/DynEffect/SttAssistWndDynEffectBase.cpp \
    ../../Module/Assist/DynEffect/SttAssistWndDynEffExecTool.cpp \
    ../../Module/Assist/DynEffect/SttAssistWndFlash.cpp \
    ../../Module/Assist/MU/SttAssistWzd_MuTest.cpp \
    ../../Module/Assist/Script/SttAssistWzd_ScriptRun.cpp \
    ../../Module/Assist/MU/SttAssistIecCbSelWidget.cpp \
    ../../Module/Assist/DynEffect/QSttAssistMsgWidget.cpp \
    ../../Module/Assist/DynEffect/QSttAssistTipsShowWidget.cpp \
    ../../Module/Assist/DynEffect/SttAssistShowTips.cpp \
    ../../Module/Assist/QSttAssistMenuWidget.cpp \
    ../../Module/Assist/QObjectGlobalApi.cpp \
    ../../Module/SttTestCtrl/SttTestAppBase.cpp \
    ../../Module/SttTestCtrl/SttTestCtrlCntrBase.cpp \
    ../../Module/SttTestCtrl/SttTestCtrlCntrNative.cpp \
    ../../Module/SttTestCtrl/SttArgcArgvParser.cpp \
    ../../Module/UI/SttTestCntrThread.cpp \
    ../../Module/UI/Interface/SttMacroParaEditInterface.cpp \
    ../../Module/UI/Interface/SttMacroParaEditViewMngr.cpp \
    ../../Module/UI/Interface/SttMacroParaEditViewOriginal.cpp \
    #sun ../../Module/UI/Interface/SttHtmlReportViewInterface.cpp \
    #sun ../../Module/UI/Interface/SttHtmlVIewApi.cpp \
    #sun ../../Module/UI/Webkit/SttMacroParaEditViewHtml.cpp \
    #sun ../../Module/UI/Webkit/SttWebViewBase.cpp \
    #sun ../../Module/UI/Webkit/SttReportViewHtml.cpp \
    ../../Module/UI/Config/Frame/SttFrame_Button.cpp \
    ../../Module/UI/Config/Frame/SttFrameConfig.cpp \
    ../../Module/UI/Config/Frame/SttFrame_Data.cpp \
    ../../Module/UI/Config/Frame/SttFrame_Font.cpp \
    ../../Module/UI/Config/Frame/SttFrame_GbTree.cpp \
    ../../Module/UI/Config/Frame/SttFrame_Item.cpp \
    ../../Module/UI/Config/Frame/SttFrame_MacroParaView.cpp \
    ../../Module/UI/Config/Frame/SttFrame_Menu.cpp \
    ../../Module/UI/Config/Frame/SttFrame_Menus.cpp \
    ../../Module/UI/Config/Frame/SttFrame_Panal.cpp \
    ../../Module/UI/Config/Frame/SttFrame_ReportView.cpp \
    ../../Module/UI/Config/Frame/SttFrame_RightPanes.cpp \
    ../../Module/UI/Config/Frame/SttFrame_Size.cpp \
    ../../Module/UI/Config/Frame/SttFrame_XBar.cpp \
    ../../Module/UI/Config/Frame/SttTestCtrlFrameCfgMngrGlobal.cpp \
    ../../Module/UI/Config/MacroTestUI/SttMacroTestUI_Group.cpp \
    ../../Module/UI/Config/MacroTestUI/SttMacroTestUI_TestMacroUI.cpp \
    ../../Module/UI/Config/MacroTestUI/SttMacroTestUI_TestMacroUIDB.cpp \
    ../../Module/UI/Config/MacroTestUI/SttMacroTestUI_TestMacroUIMngr.cpp \
    ../../Module/UI/Config/MacroTestUI/SttMacroTestUI_TestMacroUIRef.cpp \
    ../../Module/UI/Config/MacroTestUI/SttMacroTestUI_TestMacroUIs.cpp \
    ../../Module/UI/Config/MacroTestUI/SttTestCtrrlMacroTestUIMngrGlobal.cpp \
    ../../Module/UI/Config/Frame/SttFrame_GlobalDatas.cpp \
    ../../Module/UI/Config/Frame/SttFrame_GlobalData.cpp \
    ../../Module/UI/Controls/SttDataButtons.cpp \
    ../../Module/UI/Controls/SttToolButtonBase.cpp \
    ../../Module/UI/Controls/SttToolButton.cpp \
    ../../Module/UI/Controls/SttPanelBase.cpp \
    ../../Module/UI/Controls/SttGuideBookTreeCtrl.cpp \
    ../../Module/UI/Controls/SttMenuWidget.cpp \
    ../../Module/UI/Controls/SttItemButton.cpp \
    ../../Module/UI/Controls/SttAddMacroWidget.cpp \
    ../../Module/UI/Controls/SttGuideBookTreeWidget.cpp \
    ../../Module/UI/Controls/SttOutPutWidget.cpp \
    ../../Module/UI/Controls/SttLineEdit.cpp \
    ../../Module/UI/Controls/SttLanguageCfgDialog.cpp \
    ../../Module/UI/Controls/SttReportHeadSetDlg.cpp \
    ../../Module/UI/Controls/SttDvmEdit.cpp \
    ../../Module/UI/Controls/SttFileSaveAsDlg.cpp \
    ../../Module/UI/Controls/SttCustomSetDlg.cpp \
    ../../Module/UI/Controls/SttCustomSetTree.cpp \
    ../../Module/UI/Controls/SttCheckBox.cpp \
    ../../Module/UI/Controls/SttTabWidget.cpp \
    ../../Module/UI/Controls/FileMngr/SttFileMngrChildren.cpp \
    ../../Module/UI/Controls/FileMngr/SttFileMngrDlg.cpp \
    ../../Module/UI/Controls/FileMngr/SttFileTypeMngrGrid.cpp \
    ../../Module/UI/Controls/FileMngr/SttFileViewGrid.cpp \
    ../../Module/UI/Controls/FileMngr/SttXFolderButton.cpp \
    ../../Module/UI/Controls/NetworkConfig/qnetworkiptable.cpp \
    ../../Module/UI/Controls/NetworkConfig/QModifyIPAddrDlg.cpp \
    ../../Module/UI/Controls/FileMngr/SttFileMoveDlg.cpp \
    ../../Module/UI/Controls/SafetyMsgCfg/SttSafetyMsg.cpp \
    ../../Module/UI/Controls/SafetyMsgCfg/SttSafetyMsgCfg.cpp \
    ../../Module/UI/Controls/SafetyMsgCfg/SttSafetyMsgCfgGlobal.cpp \
    ../../Module/UI/Controls/SafetyMsgCfg/SttSafetyMsgCfgs.cpp \
    ../../Module/UI/Controls/NetworkConfig/qnetworkconfigwidget.cpp \
    ../../Module/UI/SoftKeyboard/SoftKeyBoard.cpp \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin.cpp \
    ../../Module/UI/SoftKeyboard/Keyboard/Keyboard.cpp \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/dictbuilder.cpp \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/dictlist.cpp \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/dicttrie.cpp \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/lpicache.cpp \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/matrixsearch.cpp \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/mystdlib.cpp \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/ngram.cpp \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/pinyinime.cpp \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/searchutility.cpp \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/spellingtable.cpp \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/spellingtrie.cpp \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/splparser.cpp \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/sync.cpp \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/userdict.cpp \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/utf16char.cpp \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/utf16reader.cpp \
    ../../Module/UI/Harm/SttMacroParaEditViewHarm.cpp \
    ../../Module/UI/State/StateButtonWidget.cpp \
    ../../Module/UI/State/StateParaTab.cpp \
    ../../Module/UI/State/StateParaWidget.cpp \
    ../../Module/UI/State/SttMacroParaEditViewState.cpp \
    ../../Module/UI/TransPlay/SttMacroParaEditViewTransPlay.cpp \
    ../../Module/UI/Module/ChannelParaSet/channelharmtable.cpp \
    ../../Module/UI/Module/ChannelParaSet/channeltable.cpp \
    ../../Module/UI/Module/ChannelParaSet/QBasicTestParaSet.cpp \
    ../../Module/UI/Module/ChannelParaSet/QParaSetBase.cpp \
    ../../Module/UI/Module/ExSwitchSet/exswitchset.cpp \
    ../../Module/UI/Module/CommonMethod/CommonMethod.cpp \
    SttTestCntrFrameLinux.cpp \
    SttTestCntrApplication.cpp \
    ../../Module/UI/Manual/ManualView_IV.cpp \
    ../../Module/UI/Manual/ManualView_Paras.cpp \
    ../../Module/UI/SttTestCntrCmdDefine.cpp \
    ../../Module/UI/SttTestCntrFrameBase.cpp \
    ../../Module/UI/State/CommonValueDialogState.cpp \
    ../../Module/UI/State/ShortCalcuDig.cpp \
    ../../Module/UI/State/Gradient/gradientchanneltable.cpp \
    ../../Module/UI/State/Gradient/gradientparaset.cpp \
    ../../Module/UI/State/Gradient/gradientparatab.cpp \
    ../../Module/UI/State/Gradient/GradientSetDlg.cpp \
    ../../Module/UI/Module/CommonMethod/FaultCalculat.cpp \
    ../../Module/UI/Module/VectorWidget/DiagramWidget.cpp \
    ../../Module/UI/Module/VectorWidget/vectorwidget.cpp \
    ../../Module/UI/Module/GooseParaWidget/GoosePubWidget.cpp \
    ../../Module/UI/Module/GooseParaWidget/IecCfgGoutChsGrid.cpp \
    ../../Module/UI/Module/GooseParaWidget/LineEdit.cpp \
    ../../Module/UI/Module/GooseParaWidget/qgooseparawidget.cpp \
    ../../Module/UI/Module/GooseParaWidget/WidgetDelegate.cpp \
    ../../Module/UI/Module/infoWidget/infowidget.cpp \
    ../../Module/UI/Module/QExBaseListGridBase/QExBaseListComBoxDelegBase.cpp \
    ../../Module/UI/Module/QExBaseListGridBase/QExBaseListGridBase.cpp \
    ../../Module/UI/Module/QExBaseListGridBase/QGridDefine.cpp \
    ../../Module/UI/Harm/HarmParaTable.cpp \
    ../../Module/UI/Harm/HarmParaWidget.cpp \
    ../../Module/UI/Harm/HarmWidget.cpp \
    ../../Module/UI/Harm/QHarmTable.cpp \
    ../../Module/UI/IEC61850Config/Grid/IecCfgSmvData92Grid.cpp \
    ../../Module/UI/Module/CommonCtrl_QT/QFloatLineEdit.cpp \
    ../../Module/UI/Module/CommonCtrl_QT/QIecLineEdit.cpp \
    ../../Module/UI/Module/CommonCtrl_QT/QIecWidgetDelegate.cpp \
    ../../Module/UI/Module/CommonCtrl_QT/QCovDoubleValidator.cpp \
    ../../Module/UI/Module/CommonCtrl_QT/QNumberCheckBox.cpp \
    ../../Module/UI/IEC61850Config/SttIecSMV92OtherSetDialog.cpp \
    ../../Module/UI/IEC61850Config/Grid/IecCfgSmvRateGrid.cpp \
    ../../Module/UI/Module/ChRsMap/ChMapsGrid.cpp \
    ../../Module/UI/Module/ChRsMap/QChMapsDlg.cpp \
    ../../Module/UI/Module/ChRsMap/QChMapsWidget.cpp \
    ../../Module/UI/IEC61850Config/SttSclCtrlsWidget.cpp \
    ../../Module/UI/IEC61850Config/SttSclFileParseDialog.cpp \
    ../../Module/UI/IEC61850Config/SttSclIedTreeItem.cpp \
    ../../Module/UI/IEC61850Config/Grid/IecCfgChsGridBase.cpp \
    ../../Module/UI/IEC61850Config/Grid/IecCfgDataGridBase.cpp \
    ../../Module/UI/IEC61850Config/Grid/IecCfgGinChsGrid.cpp \
    ../../Module/UI/IEC61850Config/Grid/IecCfgGinDataGrid.cpp \
    ../../Module/UI/IEC61850Config/Grid/IecCfgGoutChannelsGrid.cpp \
    ../../Module/UI/IEC61850Config/Grid/IecCfgGoutDataGrid.cpp \
    ../../Module/UI/IEC61850Config/Grid/IecCfgSmv92ChsGrid.cpp \
    ../../Module/UI/IEC61850Config/Grid/SclCtrlsGooseInGrid.cpp \
    ../../Module/UI/IEC61850Config/Grid/SclCtrlsGooseOutGrid.cpp \
    ../../Module/UI/IEC61850Config/Grid/SclCtrlsGridBase.cpp \
    ../../Module/UI/IEC61850Config/Grid/SclCtrlsSmvInGrid.cpp \
    ../../Module/UI/IEC61850Config/Grid/SclCtrlsSmvOutGrid.cpp \
    ../../Module/UI/IEC61850Config/SttIecChsEditDialog.cpp \
    ../../Module/UI/IEC61850Config/SttIecGinWidget.cpp \
    ../../Module/UI/IEC61850Config/SttIecGoutWidget.cpp \
    ../../Module/UI/Module/CommonCtrl_QT/QLongLineEdit.cpp \
    ../../Module/UI/IEC61850Config/SttIecQualitySetDialog.cpp \
    ../../Module/UI/Module/PopupDialog/SttFileSelectGrid.cpp \
    ../../Module/UI/Module/PopupDialog/SttPopupOpenDialog.cpp \
    ../../Module/UI/Module/StateMonitor/StateMonitorBinBout.cpp \
    ../../Module/UI/Module/StateMonitor/StateMonitorPlot.cpp \
    ../../Module/UI/Module/StateMonitor/StateMonitorTab.cpp \
    ../../Module/UI/Module/StateMonitor/StateMonitorVoltCur.cpp \
    ../../Module/UI/Module/StateMonitor/StateMonitorWidget.cpp \
    ../../Module/UI/Module/CharLibWidget/PsuCharDrawView.cpp \
    ../../Module/UI/Module/CharLibWidget/QImpCharactWidget.cpp \
    ../../Module/UI/Module/ZKCharaCurve/QZKFeatureAddDig.cpp \
    ../../Module/UI/Module/ScrollCtrl/ScrollTextEdit.cpp \
    ../../Module/UI/Module/SttAuxIPSetDlg/SttAuxIPSetDlg.cpp \
    ../../Module/UI/Module/PopupDialog/SttFileMngrTree.cpp \
    ../../Module/UI/State/GooseAbnormal/GooseAbnormalParaset.cpp \
    ../../Module/UI/State/GooseAbnormal/SttMacroParaEditViewGooseAbnormal.cpp \
    ../../Module/UI/State/SmvAbnormal/SmvAbnormalChannelSelect.cpp \
    ../../Module/UI/State/SmvAbnormal/SmvAbnormalMessageset.cpp \
    ../../Module/UI/State/SmvAbnormal/SmvAbnormalParaset.cpp \
    ../../Module/UI/State/SmvAbnormal/SmvAbnormalPointset.cpp \
    ../../Module/UI/State/SmvAbnormal/SmvAbnormalQualityset.cpp \
    ../../Module/UI/IEC61850Config/SttIecSMV92InWidget.cpp \
    ../../Module/UI/Module/ScrollCtrl/ScrollListWidget.cpp \
    ../../Module/UI/IEC61850Config/Grid/IecCfgSmvData92InGrid.cpp \
    ../../Module/UI/IEC61850Config/Grid/IecCfgSmv92InChsGrid.cpp \
    ../../Module/UI/IEC61850Config/SttIecSysCfgWidget.cpp \
    ../../Module/UI/IEC61850Config/SttIecSysCfgChildWidget.cpp \
    ../../Module/UI/IEC61850Config/Grid/IecCfgFiberSetGrid.cpp \
    ../../Module/UI/IEC61850Config/Grid/IecCfgPrimRateGrid.cpp \
    ../../Module/UI/Manual/QSttMUTimeTestWidget.cpp \
    ../../Module/UI/Manual/QSttMUParasWidget.cpp \
    ../../Module/UI/Module/CharLibWidget/QCharInverseSet.cpp \
    ../../Module/UI/Module/ZKCharaCurve/QCharElementDlg.cpp \
    ../../Module/UI/Module/CharLibWidget/CharEditMainWidget.cpp \
    ../../Module/UI/Module/CharLibWidget/CharEditWidget_Distance.cpp \
    ../../Module/UI/Module/CharLibWidget/CharEditWidget_Inverse.cpp \
    ../../Module/UI/Module/CharLibWidget/CharEditWidget_Diff.cpp \
    ../../Module/UI/Module/CharLibWidget/CharEditWidget_Syn.cpp \
    ../../Module/UI/Module/CharLibWidget/CharEditWidget_None.cpp \
    ../../Module/UI/Module/ZKCharaCurve/QCIFeatureAddDig.cpp \
    ../../Module/UI/Module/CharLibWidget/CharEditWidgetBase.cpp \
    ../../Module/UI/TransPlay/SttReplayTriggerWidget.cpp \
    ../../Module/UI/TransPlay/SttReplayModuleChWidget.cpp \
    ../../Module/UI/TransPlay/SttReplayAdjustComboBox.cpp \
    ../../Module/UI/Module/WaveGraphWidget/QWaveGraphWidget.cpp \
    ../../Module/UI/Module/CommonCtrl_QT/QSttProgDlg.cpp \
    ../../Module/UI/Module/ScrollCtrl/ScrollTreeWidget.cpp \
    ../../Module/UI/Module/ScrollCtrl/ScrollCtrlInterface.cpp \
    ../../Module/UI/SCL/QSttSelSclFileWidget.cpp \
    ../../Module/UI/SCL/QSttSelSclFileDlg.cpp \
    ../../Module/UI/SCL/SttSelSclFileGrid.cpp \
    ../../Module/UI/SCL/QSttSelSclIedWidget.cpp \
    ../../Module/UI/SCL/SttSelSclIedGrid.cpp \
    ../../Module/UI/Module/DeviceInforDlg/DeviceAttrsGrid.cpp \
    ../../Module/UI/Module/DeviceInforDlg/QDeviceInforDlg.cpp \
    ../../Module/UI/Module/DeviceInforDlg/SttModuleAttrsGrid.cpp \
    ../../Module/UI/Module/DeviceInforDlg/SttModulesGrid.cpp \
    ../../Module/UI/Module/PopupDialog/SttFileDlgBase.cpp \
    ../../Module/UI/SttEventFilter/SttEventFilter.cpp \
    ../../Module/UI/Module/PopupDialog/SttPopupSaveAsDialog.cpp \
    ../../Module/UI/Module/ModuleSetDlg/QModuleSetWidget.cpp \
    ../../Module/UI/Module/ModuleSetDlg/QModuleSetDlg.cpp \
    ../../Module/UI/Module/HardwareSetDlg/QHardwareSetDlg.cpp \
    ../../Module/UI/Module/CommonCtrl_QT/SttDiffCurrCalDlg.cpp \
    ../../Module/UI/State/StateBinarySetDlg.cpp \
    ../../Module/UI/State/StateTrigerWidget.cpp \
    ../../Module/UI/Gradient/GradientSettingDlg.cpp \
    ../../Module/UI/Manual/QSttManualBinBoutDlg.cpp \
    ../../Module/UI/Manual/SttMacroParaEditViewManual.cpp \
    ../../Module/UI/SequenceManu/SequenceManualWidget.cpp \
    ../../Module/UI/SequenceManu/SttMacroParaEditViewSequenceManu.cpp \
    ../../Module/UI/Gradient/GradientGroupWidget.cpp \
    ../../Module/UI/Gradient/GradientGroupGrid.cpp \
    ../../Module/UI/Module/PowerWidget/powerdiagramwidget.cpp \
    ../../Module/UI/State/StateEditDlg.cpp \
    ../../Module/UI/Harm/OscillogramGroupWidget.cpp \
    ../../Module/UI/Harm/OscillogramWidget.cpp \
    ../../Module/UI/Harm/PlotOscillogram.cpp \
    ../../Module/UI/Module/PopupDialog/SttFileMngrTool.cpp \
    ../../Module/UI/QSttInfWidgetBase.cpp \
    ../../Module/UI/Module/PowerWidget/QPowerDiagramWidgetImp.cpp \
    ../../Module/UI/Module/StateMonitor/QStateMonitorWidgetImp.cpp \
    ../../Module/UI/Module/ChannelParaSet/QBasicTestParaSetImp.cpp \
    ../../Module/UI/Module/DCOutput/QAuxDCOutputDlg.cpp \
    ../../Module/UI/Gradient/SttMacroParaEditViewGradient.cpp \
    ../../Module/UI/Module/CharLibWidget/QCharactWidgetForTest.cpp \
    ../../Module/UI/Module/CharLibWidget/QCharTestPointsGrid.cpp \
    ../../Module/UI/TransPlay/SttReplayParaSetWidget.cpp \
    ../../Module/UI/Module/CharLibWidget/QCharacteristicEditDlg.cpp \
    ../../Module/UI/Module/CharLibWidget/Grid/ImpCustomPointsGrid.cpp \
    ../../Module/UI/State/StateSettingValueDlg.cpp \
    ../../Module/UI/Module/LuminousPower/LuminousPowerDlg.cpp \
    ../../Module/UI/Module/LuminousPower/LuminousPowerGrid.cpp \
    ../../Module/UI/State/StateEstimateDlg.cpp \
    ../../Module/UI/Harm/InterharmonicsWidget.cpp \
    ../../Module/UI/IEC61850Config/SttIecSMVFT3InitValueSetDialog.cpp \
    ../../Module/UI/IEC61850Config/SttIecSMVFT3InMapSetDialog.cpp \
    ../../Module/UI/IEC61850Config/SttIecSMVFT3InWidget.cpp \
    ../../Module/UI/IEC61850Config/SttIecSMVFT3OtherSetDialog.cpp \
    ../../Module/UI/IEC61850Config/SttIecSMVFT3OutWidget.cpp \
    ../../Module/UI/IEC61850Config/Grid/IecCfgSmvFT3InChsGrid.cpp \
    ../../Module/UI/IEC61850Config/Grid/IecCfgSmvFT3OutChsGrid.cpp \
    ../../Module/UI/Module/CommonCtrl_QT/QDataTypeComboBox.cpp \
    ../../Module/UI/Gradient/GradientEstimateDlg.cpp \
    ../../Module/UI/Gradient/GradientSettingValueDlg.cpp \
    #sun ../../Module/UI/SOE/SttMacroParaEditViewSoeTable.cpp \
    #sun ../../Module/UI/SOE/SttMacroParaEditViewSoeWidget.cpp \
    ../../Module/UI/Module/FT3Widget/FT3OutParaWidget.cpp \
    ../../Module/UI/Module/FT3Widget/FT3OutSetDialog.cpp \
    ../../Module/UI/Module/FT3Widget/FT3OutWidget.cpp \
    ../../Module/UI/Module/FT3Widget/IecCfgFT3OutGrid.cpp \
    ../../Module/UI/IEC61850Config/SttIecConfigDialogLinux.cpp \
    ../../Module/UI/IEC61850Config/SttIecConfigDialogBase.cpp \
    ../../Module/UI/IEC61850Config/SttIecChsEditWidget.cpp \
    ../../Module/UI/Module/CharLibWidget/QCharEditRadioHarmWidget.cpp \
    ../../Module/UI/Module/CharLibWidget/QCharEditRadioNormalWidget.cpp \
    ../../Module/UI/Harm/HarmEstimateDlg.cpp \
    ../../Module/UI/Manual/ManualEstimateDlg.cpp \
    ../../Module/UI/SequenceManu/SequenceManualEstimateDlg.cpp \
    ../../Module/UI/SequenceGradient/SequenceGradientEstimateDlg.cpp \
    ../../Module/UI/SequenceGradient/SequenceGradientSettingDlg.cpp \
    ../../Module/UI/SequenceGradient/SequenceGradientWidget.cpp \
    ../../Module/UI/SequenceGradient/SttMacroParaEditViewSequenceGradient.cpp \
    ../../Module/UI/LineVolGradient/LineVolGradientGroupWidget.cpp \
    ../../Module/UI/LineVolGradient/SttMacroParaEditViewLineVolGradient.cpp \
    ../../Module/UI/LineVoltManu/LineVoltManualEstimateDlg.cpp \
    ../../Module/UI/LineVoltManu/LineVoltManualWidget.cpp \
    ../../Module/UI/LineVoltManu/SttMacroParaEditViewLineVoltManu.cpp \
    ../../Module/UI/LineVolGradient/LineVolGradientEstimateDlg.cpp \
    ../../Module/UI/IEC61850Config/Grid/SclCtrlGInChsGrid.cpp \
    ../../Module/UI/IEC61850Config/Grid/SclCtrlSmvInChsGrid.cpp \
    ../../Module/UI/IEC61850Config/Grid/SclCtrlSmvOutChsGrid.cpp \
    ../../Module/UI/IEC61850Config/Grid/SclCtrlGoutChsGrid.cpp \
    ../../Module/UI/IEC61850Config/Grid/SclCtrlChsGridBase.cpp \
    ../../Module/UI/IEC61850Config/Grid/QSclSelectCtrlsGrid.cpp \
    ../../Module/UI/IEC61850Config/SttIecSMVFT3DCOtherSetDialog.cpp \
    ../../Module/UI/IEC61850Config/Grid/IecCfgSMVFT3DCOtherSetGrid.cpp \
    ../../Module/UI/IEC61850Config/Grid/IecCfgSmvDataFT3Grid.cpp \
    ../../Module/UI/IEC61850Config/Grid/IecCfgSmvDataFT3InGrid.cpp \
    ../../Module/UI/MUAutoTest/SttMacroParaEditViewMuAutoTest.cpp \
    ../../Module/UI/MUAutoTest/SttMacroParaEditViewOtherSetDlg.cpp \
    ../../Module/UI/MUAutoTest/SttMacroParaEditViewMuTreeWidget.cpp \
    #sun ../../Module/UI/RemoteMeas/QRemoteMeasTable.cpp \
    #sun ../../Module/UI/RemoteMeas/RemoteMeasParaset.cpp \
    #sun ../../Module/UI/RemoteMeas/RemoteMeasParaTable.cpp \
    #sun ../../Module/UI/RemoteMeas/RemoteMeasRatWidget.cpp \
    #sun ../../Module/UI/RemoteMeas/RemoteMeasWidget.cpp \
    #sun ../../Module/UI/RemoteMeas/SttMacroParaEditViewRemoteMeas.cpp \
    ../../Module/UI/TerminalAutoTest/QTerminalSettingTabWidget.cpp \
    ../../Module/UI/TerminalAutoTest/QTerminalTabWidget.cpp \
    ../../Module/UI/TerminalAutoTest/QTerminalTreeWidget.cpp \
    ../../Module/UI/TerminalAutoTest/SttMacroParaEditViewTerminalAutoTest.cpp \
    ../../Module/UI/TerminalAutoTest/Grid/QTerminalGinDataChsGrid.cpp \
    ../../Module/UI/TerminalAutoTest/Grid/QTerminalGinDataGrid.cpp \
    ../../Module/UI/TerminalAutoTest/Grid/QTerminalGooseGrid.cpp \
    ../../Module/UI/TerminalAutoTest/Grid/QTerminalGoutDataChsGrid.cpp \
    ../../Module/UI/TerminalAutoTest/Grid/QTerminalGoutDataGrid.cpp \
    #sun ../../Module/UI/RemoteCtrl/RemoteCtrlBtnWidget.cpp \
    #sun ../../Module/UI/RemoteCtrl/RemoteCtrlTable.cpp \
    #sun ../../Module/UI/RemoteCtrl/SttMacroParaEditViewRemoteCtrl.cpp \
    ../../Module/UI/ShortTimeOver/QttMacroParaEditViewShortTimOver.cpp \
    ../../Module/UI/ShortTimeOver/ShortTimeOverGrid.cpp \
    ../../Module/UI/ShortTimeOver/ShortTimeOverGridImp.cpp \
    ../../Module/UI/IntelligentTerminal/IntellTerminalWidget.cpp \
    ../../Module/UI/IntelligentTerminal/SttMacroParaEditViewIntelligentTerminal.cpp \
    ../../Module/UI/Module/GooseParaWidget/SttIntelGoutToBinParaWidget.cpp \
    ../../Module/UI/Module/GooseParaWidget/SttIntelBoutToGinParaWidget.cpp \
    ../../Module/UI/Module/GooseParaWidget/SttIntelBoutToGinPubWidget.cpp \
    ../../Module/UI/Module/GooseParaWidget/SttIntelGoutToBinGrid.cpp \
    ../../Module/UI/Module/GooseParaWidget/SttIntelGoutToBinPubWidget.cpp \
    ../../Module/UI/Module/GooseParaWidget/SttIntelBoutToGinGrid.cpp \
    ../../Module/UI/Module/CommonCtrl_QT/Draw/QSttCustomArrowLine.cpp \
    ../../Module/UI/Module/CommonCtrl_QT/Draw/QSttCustomRect.cpp \
    ../../Module/UI/IEC61850Config/SCDView/SttSclIedDrawViewWidget.cpp \
    ../../Module/UI/IEC61850Config/SCDView/SttSclIedLineDialog.cpp \
    ../../Module/UI/IEC61850Config/SCDView/SttSclIedSketchMapWidget.cpp \
    #sun ../../Module/UI/Module/CommConfigurationDlg/CommCfg/QSttCommCfgMainDlg.cpp \
    #sun ../../Module/UI/Module/CommConfigurationDlg/CommCfg/SttCommCfgDeviceAttrsGrid.cpp \
    #sun ../../Module/UI/Module/CommConfigurationDlg/DevComm/QSttCommCfgDeviceDlg.cpp \
    #sun ../../Module/UI/Module/CommConfigurationDlg/DevComm/QSttCommCfgDeviceWidget.cpp \
    #sun ../../Module/UI/Module/CommConfigurationDlg/DevComm/SttDevCommTeleMeasureGrid.cpp \
    #sun ../../Module/UI/Module/CommConfigurationDlg/DevComm/SttDevCommTeleParaCommGrid.cpp \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PointTblFile/QSttCommCfgPointTblFileEditorDlg.cpp \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PointTblFile/QSttCommCfgPointTblFileImportDlg.cpp \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PointTblFile/SttCommCfgPointTblFileImportGrid.cpp \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PointTblFile/SttCommCfgPointTblFileImportTreeCtrl.cpp \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PointTblFile/SttPointTblEdtTabIntervalSetGrid.cpp \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PointTblFile/SttPointTblEdtTabTeleMeasureGrid.cpp \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PointTblFile/SttPointTblEdtTabTeleParaCommGrid.cpp \
    #sun ../../Module/UI/Module/CommConfigurationDlg/ProtocolTempl/QSttCommCfgProtocolTemplateDlg.cpp \
    #sun ../../Module/UI/Module/CommConfigurationDlg/ProtocolTempl/SttCommCfgProtocolTemplateGrid.cpp \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PkgMonitor/QSttCommCfgPkgMonitorDlg.cpp \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PkgMonitor/SttCommCfgPkgMonitorLeftGrid.cpp \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PkgMonitor/SttCommCfgPkgMonitorRightGrid.cpp \
    ../../Module/UI/VoltageTimeTypeSectorMode/QSttVoltageTimeGroupTestItemWidget.cpp \
    ../../Module/UI/FaultGradient/SttMacroParaEditViewFaultGradient.cpp \
    ../../Module/UI/FaultGradient/CFaultGradientSetting.cpp \
    ../../Module/UI/FaultGradient/FaultGradientEstimateDlg.cpp \
    ../../Module/UI/Module/FACommonSpyWidget/Grid/QSttFAStateSequenceGroupGrid.cpp \
    ../../Module/UI/Module/FACommonSpyWidget/Grid/QSttFATestResultViewGroupGrid.cpp \
    ../../Module/UI/Module/FAParasSetWidget/QSttFAParasSetDialog.cpp \
    ../../Module/UI/VoltageTimeTypeSectorMode/QSttMacroParaEditViewVolTimeTypeSec.cpp \
    ../../Module/UI/IEC61850Config/SttIecConfigDialog.cpp \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PkgMonitor/QSttCommCfgPkgMonitorWidget.cpp \
    ../../Module/UI/IEC61850Config/SttIecConfigWidgetBase.cpp \
    ../../Module/UI/IEC61850Config/SttIecSMV92Widget.cpp \
    ../../Module/UI/IEC61850Config/SttIecSysParasOtherSetDialog.cpp \
    ../../Module/UI/IEC61850Config/SttIecSysParasWidget.cpp \
    ../../../Module/BaseClass/ThreadProgressInterface.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgDatasMngr.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgGoutDatas.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgGoutData.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgGoutChs.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgGoutCh.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgGooseDataBase.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgGinDatas.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgGinData.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgGinChs.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgGinCh.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgDatasBase.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgDataMngrGlobal.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgDataGooseChBase.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgDataChBase.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgDataBase.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgChsBase.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg92Data.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg92ChsIn.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg92Chs.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgSMVDatas.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgSmvDataBase.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgGinAppChMaps.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgGinAppChMap.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg92ChQuality.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg92ChIn.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg92Ch.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg6044Ch.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg6044Chs.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg6044Data.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgDataSmvCommon.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg91Ch.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg91Chs.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg91Data.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgSmvRate.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgSmvRates.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgAdvanceException.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgDataSmvChBase.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg91StatusDataSet.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg91StatusDataSetCh.cpp \
    ../../../61850/Module/GlobalDataMngr/IecFiberConfig.cpp \
    ../../../61850/Module/GlobalDataMngr/IecGlobalDataMngr.cpp \
    ../../../61850/Module/GlobalDataMngr/IecGlobalDataMngrGlobal.cpp \
    ../../../61850/Module/GlobalDataMngr/IecGooseChDataTypeMngr.cpp \
    ../../../61850/Module/GlobalDataMngr/IecSmvChDataType.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgSysParas.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg6044CommonCh.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg6044CommonData.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg91StateWord.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg91StateWordMngr.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg91StcateWordBit.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgFiberPara.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgFiberParas.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgPrimRate.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgPrimRates.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgSystemConfig.cpp \
    ../../../Module/OSInterface/QT/XGlobalDefine_QT.cpp \
    ../../../Module/OSInterface/QT/CFile_QT.cpp \
    ../../../Module/OSInterface/QT/CString_QT.cpp \
    ../../../Module/OSInterface/QT/CTime_QT.cpp \
    ../../../Module/OSInterface/QT/CXArray_QT.cpp \
    ../../../Module/OSInterface/QT/CXCtrl_QT.cpp \
    ../../../Module/OSInterface/QT/CXCtrl_QT_CWinApp.cpp \
    ../../../Module/OSInterface/QT/CXCtrl_QT_CWnd.cpp \
    ../../../Module/OSInterface/QT/XMsgCycleBuffer.cpp \
    ../../../Module/OSInterface/QT/std_api_linux.cpp \
    ../../../Module/OSInterface/QT/CXDrawTypes_QT.cpp \
    ../../../Module/OSInterface/QT/CWinThread_QT.cpp \
    ../../../Module/MemBuffer/BufferBase.cpp \
    ../../../Module/MemBuffer/FormatTextBuffer.cpp \
    ../../../Module/MemBuffer/EquationBuffer.cpp \
    ../../../Module/MemBuffer/EquationKey.cpp \
    ../../../Module/MemBuffer/CycleMemBuffer.cpp \
    ../../../Module/MemBuffer/StringToSystimeBuffer.cpp \
    ../../../Module/MemBuffer/XMemBufferBse.cpp \
    ../../../Module/MemBuffer/ExpandMemBuf.cpp \
    ../../../Module/MemBuffer/CycleMemBufferMngr.cpp \
    ../../../Module/MemBuffer/TCycleMemBuffer.cpp \
    ../../../Module/BaseClass/WSerializeBuff.cpp \
    ../../../Module/BaseClass/SerializeBufferBase.cpp \
    ../../../Module/BaseClass/XObjectRefBase.cpp \
    ../../../Module/BaseClass/ComplexNumber.cpp \
    ../../../Module/BaseClass/BaseList.cpp \
    ../../../Module/BaseClass/StringSerializeBuffer.cpp \
    ../../../Module/BaseClass/BaseObject.cpp \
    ../../../Module/BaseClass/BinarySerialBuffer.cpp \
    ../../../Module/BaseClass/ExBaseList.cpp \
    ../../../Module/BaseClass/ExBaseObject.cpp \
    ../../../Module/API/StringApi.cpp \
    ../../../Module/Log/LogPrint.cpp \
    ../../../Module/API/GlobalConfigApi.cpp \
    ../../../Module/API/FileApi.cpp \
    ../../../Module/API/GlobalApi.cpp \
    ../../../Module/DataMngr/DataGroup.cpp \
    ../../../Module/DataMngr/DataMngrGlobal.cpp \
    ../../../Module/DataMngr/DataType.cpp \
    ../../../Module/DataMngr/DataTypes.cpp \
    ../../../Module/DataMngr/DataTypeValue.cpp \
    ../../../Module/DataMngr/DvmData.cpp \
    ../../../Module/DataMngr/DvmDataset.cpp \
    ../../../Module/DataMngr/DvmDevice.cpp \
    ../../../Module/DataMngr/DvmDevices.cpp \
    ../../../Module/DataMngr/DvmLog.cpp \
    ../../../Module/DataMngr/DvmLogicDevice.cpp \
    ../../../Module/DataMngr/DvmLogs.cpp \
    ../../../Module/DataMngr/DvmValue.cpp \
    ../../../Module/DataMngr/LogCtrl.cpp \
    ../../../Module/DataMngr/LogCtrls.cpp \
    ../../../Module/DataMngr/LongData.cpp \
    ../../../Module/DataMngr/LongDatas.cpp \
    ../../../Module/DataMngr/RptCtrl.cpp \
    ../../../Module/DataMngr/RptCtrls.cpp \
    ../../../Module/DataMngr/ShortData.cpp \
    ../../../Module/DataMngr/ShortDatas.cpp \
    ../../../Module/DataMngr/Value.cpp \
    ../../../Module/DataMngr/Values.cpp \
    ../../../Module/System/TickCount32.cpp \
    ../../../Module/System/StringTokenizer.cpp \
    ../../../Module/GpsPcTime/GpsPcTime.cpp \
    ../../../Module/xml/XmlRWBase.cpp \
    ../../../Module/xml/XmlRWFactory.cpp \
    ../../../Module/xml/XmlRW_Pugi.cpp \
    ../../../Module/xml/PugiXML/pugixml.cpp \
    ../../../Module/XLanguage/XLangItem.cpp \
    ../../../Module/XLanguage/XLanguage.cpp \
    ../../../Module/XLanguage/XLanguageGlobal.cpp \
    ../../../Module/XLanguage/XLanguageMngr.cpp \
    ../../../Module/XLanguage/XLanguageNameParser.cpp \
    ../../../Module/API/HexTransApi.cpp \
    ../../../Module/Socket/WinBaseSocket.cpp \
    ../../../Module/Socket/WinTcpSocket.cpp \
    ../../../Module/Socket/WinTcpSocketClient.cpp \
    ../../../Module/Socket/WinTcpSocketServer.cpp \
    ../../../AutoTest/Module/Characteristic/CharacteristicGlobal.cpp \
      ../../../AutoTest/Module/Characteristic/CharacterArea.cpp \
    ../../../AutoTest/Module/Characteristic/CharacterFolder.cpp \
    ../../../AutoTest/Module/Characteristic/Characteristic.cpp \
    ../../../AutoTest/Module/Characteristic/CharacteristicLib.cpp \
    ../../../AutoTest/Module/Characteristic/Characteristics.cpp \
    ../../../AutoTest/Module/Characteristic/CharacteristicTmplate.cpp \
    ../../../AutoTest/Module/Characteristic/CharElement.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementArc.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementArcBase.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementArcd.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementArcp.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementI2T.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementIAC.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementIEC.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementIEEE.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementInverse.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementInvOwnDef.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementLens.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementLine.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementLineBase.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementLined.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementLinep.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementLiner.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementMho.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementTestLine.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementTestPoint.cpp \
    ../../../AutoTest/Module/Characteristic/CharInterface.cpp \
    ../../../AutoTest/Module/Characteristic/CharInterfaceVariable.cpp \
    ../../../AutoTest/Module/Characteristic/CharTestLineDefine.cpp \
    ../../../Module/Expression/EpExpression.cpp \
    ../../../Module/Expression/EpExpressionTool.cpp \
    ../../../Module/DataMngr/DataMngrTrans.cpp \
    ../../../Module/Encrypt/XDes2.cpp \
    ../../../Module/XDrawBase/XDrawArc.cpp \
    ../../../Module/XDrawBase/XDrawBase.cpp \
    ../../../Module/XDrawBase/XDrawCircle.cpp \
    ../../../Module/XDrawBase/XDrawDataDef.cpp \
    ../../../Module/XDrawBase/XDrawElement.cpp \
    ../../../Module/XDrawBase/XDrawElements.cpp \
    ../../../Module/XDrawBase/XDrawGlobal.cpp \
    ../../../Module/XDrawBase/XDrawLine.cpp \
    ../../../Module/XDrawBase/XDrawList.cpp \
    ../../../Module/XDrawBase/XDrawMngr.cpp \
    ../../../Module/XDrawBase/XDrawMngrDescartes.cpp \
    ../../../Module/XDrawBase/XDrawMngrLogarithm.cpp \
    ../../../Module/XDrawBase/XDrawPoint.cpp \
    ../../../Module/XDrawBase/XDrawPolyline.cpp \
    ../../../Module/XDrawBase/XDrawViewBase.cpp \
    ../../../Module/Axis/AxisInterface.cpp \
    ../../../Module/Axis/DescartesAxis.cpp \
    ../../../Module/Axis/LogarithmAxis.cpp \
    ../../../Module/Axis/PolarAxis.cpp \
    ../../../Module/StringCmp/StringCmp.cpp \
    ../../../Module/StringCmp/StringCmpBlock.cpp \
    ../../../Module/StringCmp/StringCmpBlocks.cpp \
    ../../../Module/API/MathApi.cpp \
    ../../../Module/Socket/SocketGlobal.cpp \
    ../../../Module/DataMngr/DvmDatasetGroup.cpp \
    ../../../Module/System/StringTokenizerU.cpp \
    ../../../Module/Socket/XPing.cpp \
    ../../../Module/XfileMngrBase/XFileFindEx.cpp \
    ../../../Module/XfileMngrBase/QT/XFileFindExImp.cpp \
    ../../../Module/FilterText/FilterText.cpp \
    ../../../Module/FilterText/FilterTextGlobal.cpp \
    ../../../Module/FilterText/FilterTextMngr.cpp \
    ../../../AutoTest/Module/Characteristic/CharacterDrawView.cpp \
    ../../../AutoTest/Module/Characteristic/CharMacroDraw.cpp \
    ../../../AutoTest/Module/Characteristic/CharMacroDrawLine.cpp \
    ../../../AutoTest/Module/Characteristic/CharMacroDrawPoint.cpp \
    ../../../AutoTest/Module/Characteristic/CharMacroDraws.cpp \
    #sun ../../../Protocol/Module/Engine/DeviceModel/DeviceModelXmlKeys.cpp \
    ../../../Module/Expression/ExprParse.cpp \
    ../../../Module/XDrawBase/XDrawLineEx.cpp \
    ../../../Module/XDrawBase/XDrawPointEx.cpp \
    ../../../Module/XDrawBase/XDrawText.cpp \
    ../../../Module/API/GloblaDrawFunctions.cpp \
    ../../../Module/XLanguage/QT/XLanguageAPI_QT.cpp \
    ../../../Module/xml/JsonRW.cpp \
    ../../../Module/xml/JSON/CJSON.c \
    ../../../AutoTest/Module/AutoTestGlobalDefine.cpp \
    ../../../61850/Module/IecCfgSclTool/SclToIecCfgTool.cpp \
    ../../../61850/Module/SCL_Qt/QSclFileRead.cpp \
    ../../../61850/Module/SCL/SclIecCfgDatas.cpp \
    ../../../Module/API/StringConvert/String_Gbk_To_Utf8.cpp \
    ../../../Module/API/StringConvert/String_Utf8_To_Gbk.cpp \
    ../../../Module/BaseClass/QT/ExBaseListTreeCtrl.cpp \
../../../Module/Record/MR1200BaseApp.cpp  \
../../../Module/Record/RecordGlobalDefine.cpp  \
../../../Module/Record/RtTime.cpp  \
../../../Module/Record/Comtrade/ComtradeAnalogData.cpp  \
../../../Module/Record/Comtrade/ComtradeBinaryData.cpp  \
../../../Module/Record/Comtrade/ComtradeDataBase.cpp  \
../../../Module/Record/Comtrade/ComtradeFileGlobal.cpp  \
../../../Module/Record/Comtrade/ComtradeMngr.cpp  \
../../../Module/Record/Comtrade/ComtradeRateData.cpp  \
../../../Module/Record/DFT/DFT.cpp  \
../../../Module/Record/DFT/DFT_Long.cpp  \
../../../Module/Record/DFT/DFT_Short.cpp  \
../../../Module/Record/DFT/DFTBase.cpp  \
../../../Module/Record/Draw/DrawBase.cpp  \
../../../Module/Record/Draw/DrawGlobalDef.cpp  \
../../../Module/Record/Draw/DrawRangeStateAxis.cpp  \
../../../Module/Record/Draw/DrawTimeAxis.cpp  \
../../../Module/Record/Draw/DrawTimeAxisRange.cpp  \
../../../Module/Record/Draw/DrawAnalogComplexVariable.cpp  \
../../../Module/Record/Draw/DrawAnalogVariable.cpp  \
../../../Module/Record/Draw/DrawAnalogVariableCmp.cpp  \
../../../Module/Record/Draw/DrawAttrSpy.cpp  \
../../../Module/Record/Draw/DrawBinaryVariable.cpp  \
../../../Module/Record/Draw/DrawMultiPara.cpp  \
../../../Module/Record/Draw/DrawPara.cpp  \
../../../Module/Record/Draw/DrawParas.cpp  \
../../../Module/Record/Draw/DrawSysTime.cpp  \
../../../Module/Record/Draw/DrawTimeCursor.cpp  \
../../../Module/Record/Draw/DrawVariable.cpp  \
../../../Module/Record/Draw/RecordTestDrawBase.cpp  \
../../../Module/Record/Draw/ViewAnalyse.cpp  \
../../../Module/Record/Draw/XRecordDrawBase.cpp  \
../../../Module/Record/Draw/NameSort.cpp  \
../../../Module/Record/Draw/ParaSort.cpp  \
../../../Module/Record/RecordTest/CalFunctions.cpp  \
../../../Module/Record/RecordTest/RecordTest.cpp  \
../../../Module/Record/RecordTest/RecordTestCalThread.cpp  \
../../../Module/Record/RecordTest/RtAllocBuffer.cpp  \
../../../Module/Record/RecordTest/RtAttrSpyConfig.cpp  \
../../../Module/Record/RecordTest/RtAttrSpyConfigs.cpp  \
../../../Module/Record/RecordTest/RtBinaryVariable.cpp  \
../../../Module/Record/RecordTest/RtBufferConfig.cpp  \
../../../Module/Record/RecordTest/RtCalFilterData.cpp  \
../../../Module/Record/RecordTest/RtCfgRecordTest.cpp  \
../../../Module/Record/RecordTest/RtCfgRecordTests.cpp  \
../../../Module/Record/RecordTest/RtCfgVariable.cpp  \
../../../Module/Record/RecordTest/RtCfgVariables.cpp  \
../../../Module/Record/RecordTest/RtChannel.cpp  \
../../../Module/Record/RecordTest/RtChannels.cpp  \
../../../Module/Record/RecordTest/RtComplexVariable.cpp  \
../../../Module/Record/RecordTest/RtDataAttribute.cpp  \
../../../Module/Record/RecordTest/RtDataAttributes.cpp  \
../../../Module/Record/RecordTest/RtFileWrite.cpp  \
../../../Module/Record/RecordTest/RtMultiVariable.cpp  \
../../../Module/Record/RecordTest/RtScript.cpp  \
../../../Module/Record/RecordTest/RtSet.cpp  \
../../../Module/Record/RecordTest/RtSets.cpp  \
../../../Module/Record/RecordTest/RtSingleVariable.cpp  \
../../../Module/Record/RecordTest/RtSpy.cpp  \
../../../Module/Record/RecordTest/RtStartup.cpp  \
../../../Module/Record/RecordTest/RtVariable.cpp  \
../../../Module/Record/RecordTest/RtVariables.cpp  \
../../../Module/Record/RecordTest/SystemSetAttr.cpp  \
../../../Module/Record/RecordTest/SystemSetsConfig.cpp  \
../../../Module/Record/RtMemBuffer/ComplexMemBuffer_UnsignedShort.cpp  \
../../../Module/Record/RtMemBuffer/MemBuffer.cpp  \
../../../Module/Record/RtMemBuffer/MemBuffer_CPoint.cpp  \
../../../Module/Record/RtMemBuffer/MemBuffer_Double.cpp  \
../../../Module/Record/RtMemBuffer/MemBuffer_Float.cpp  \
../../../Module/Record/RtMemBuffer/MemBuffer_Long.cpp  \
../../../Module/Record/RtMemBuffer/MemBuffer_UnsignedShort.cpp  \
../../../Module/Record/RtMemBuffer/RtMemBufferChannel.cpp  \
../../../Module/Record/RtMemBuffer/RtMemBufferMngr.cpp  \
../../../Module/Record/RtMemBuffer/RtMemBufScript.cpp  \
../../../Module/Record/RtScriptBase/RtScriptBase.cpp  \
../../../Module/Record/FFT/FFT.cpp  \
../../../Module/Record/Algorithm/AlgorithmAPI.cpp  \
../../../Module/SmartCap/61850Cap/CapGlobalDef.cpp  \
../../../Module/SmartCap/SmartCapCtrl.cpp  \
../../../Module/SmartCap/61850Cap/SttRcdComtradeFileWrite.cpp  \
../../../Module/SmartCap/X61850CapBase.cpp  \
../../../Module/SmartCap/XSmartCapInterface.cpp  \
../../../Module/SmartCap/XSmartCapMngr.cpp  \
../../../Module/SmartCap/XSttCap_61850.cpp  \
../../../Module/SmartCap/XSttIecfgDataEdit.cpp  \
../../../Module/SmartCap/61850Cap/ProtocolBase/FrameMemBuffer.cpp  \
../../../Module/SmartCap/61850Cap/ProtocolBase/Protocol61850Analysis.cpp  \
../../../Module/SmartCap/61850Cap/ProtocolBase/61850ParseFrameList.cpp  \
../../../Module/SmartCap/61850Cap/ProtocolBase/BbInffor.cpp  \
../../../Module/SmartCap/61850Cap/ProtocolBase/ByteBlock.cpp  \
../../../Module/SmartCap/61850Cap/ProtocolBase/FrameBase.cpp  \
../../../Module/SmartCap/61850Cap/ProtocolBase/FrameBaseList.cpp  \
../../../Module/SmartCap/61850Cap/ProtocolBase/FrameDetail.cpp  \
../../../Module/SmartCap/61850Cap/ProtocolBase/61850FrameBase.cpp  \
../../../Module/SmartCap/61850Cap/ProtocolBase/91Frame.cpp  \
../../../Module/SmartCap/61850Cap/ProtocolBase/92Frame.cpp  \
../../../Module/SmartCap/61850Cap/ProtocolBase/GooseFrame.cpp  \
../../../Module/SmartCap/61850Cap/ProtocolBase/Protocol61850.cpp  \
../../../Module/SmartCap/61850Cap/ProtocolBase/ProtocolBase.cpp  \
../../../Module/SmartCap/61850Cap/ProtocolBase/SmvFrameBase.cpp  \
../../../Module/SmartCap/61850Cap/ProtocolBase/Stt/SttFrameMemBufferMngr.cpp  \
../../../Module/SmartCap/61850Cap/ProtocolBase/Stt/SttRcdMemBufferMngr.cpp  \
../../../Module/SmartCap/61850Cap/CapThreadBase.cpp  \
../../../Module/SmartCap/61850Cap/SttCapThread.cpp  \
../../../Module/SmDb/XSmMemBuffer.cpp  \
../../../Module/SmDb/XSmMemBufferMngr.cpp  \
../../../Module/SmartCap/61850Cap/Record/CapDeviceChRecordMngr.cpp  \
../../../Module/SmartCap/61850Cap/Record/CapViewAnalyse.cpp  \
../../../Module/SmartCap/61850Cap/CapDevice/CapDeviceMngr.cpp  \
../../../Module/SmartCap/61850Cap/CapDevice/CapDeviceChBase.cpp  \
../../../Module/SmartCap/61850Cap/CapDevice/CapDeviceGooseCh.cpp  \
../../../Module/SmartCap/61850Cap/CapDevice/CapDeviceSmvCh.cpp  \
../../../Module/SmartCap/61850Cap/CapDevice/CapDevice91.cpp  \
../../../Module/SmartCap/61850Cap/CapDevice/CapDevice92.cpp  \
../../../Module/SmartCap/61850Cap/CapDevice/CapDeviceBase.cpp  \
../../../Module/SmartCap/61850Cap/CapDevice/CapDeviceGoose.cpp  \
../../../Module/SmartCap/61850Cap/CapDevice/CapDeviceSmvBase.cpp \
    ../../../Module/OSInterface/QT/CXDraw_QT.cpp \
    ../../../Module/Axis/RulerAxis.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgDevice.cpp \
    ../../../Module/BaseClass/ExBaseCycleArray.cpp \
    ../../../Module/System/VariantData.cpp \
    ../../../Module/SmartCap/XSttRcdInitChDvmData.cpp \
    ../../../Module/BaseClass/QT/ExBaseListComboBox.cpp \
    ../../../Module/SmartCap/61850Cap/CapDevice/CapAnalysisConfig.cpp \
    ../../../Module/SmartCap/XIecDatasetSmartMatch.cpp \
    ../../../Module/KeyDb/KeyDbGlobal.cpp \
    ../../../Module/KeyDb/XKeyBase.cpp \
    ../../../Module/KeyDb/XKeyDB.cpp \
    ../../../Module/KeyDb/XKeyGroupBase.cpp \
    ../../../Module/KeyDb/XKeyRef.cpp \
    ../../../Module/KeyDb/XKeyStringParser.cpp \
    ../../../Module/KeyDb/XMatchConfig.cpp \
    ../../../Module/KeyDb/XMatchDataref.cpp \
    ../../../Module/KeyDb/XMatchDatarefs.cpp \
    ../../../Module/KeyDb/XMatchDatasetRef.cpp \
    ../../../Module/KeyDb/XMatchDatasetRefs.cpp \
    ../../../Module/KeyDb/XMatchList.cpp \
    ../../../Module/KeyDb/XMatchObject.cpp \
    ../../../Module/KeyDb/XMatchToolBase.cpp \
    ../../../Module/KeyDb/XMultiKeyBase.cpp \
    ../../../61850/Module/AT02DTool/AT02D_Tool.cpp \
    ../../../Module/Axis/MeterAxis.cpp \
    ../../../Module/SmartCap/XSmartCapFileWrite.cpp \
    ../../../Module/XfileMngrBase/XFile.cpp \
    ../../../Module/XfileMngrBase/XFileMngr.cpp \
    ../../../Module/XfileMngrBase/XFolder.cpp \
    ../../../Module/XfileMngrBase/XFileType.cpp \
    ../../../Module/XfileMngrBase/XFileTypes.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgPrimRatesIn.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgSmvInDatas.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg92InData.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg2MData.cpp \
    ../../../AutoTest/Module/Characteristic/QT/SttCharacterDrawPng.cpp \
    ../../../AutoTest/Module/Characteristic/SttCharacterDrawForTest.cpp \
    ../../../AutoTest/Module/Characteristic/XCharElementTestPoints.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementTestLines.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg2MInData.cpp \
    ../../../Module/FaultCal/DiffCharCal.cpp \
    ../../../Module/QT/Png64/DrawPngBase64.cpp \
    #sun ../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineServer.cpp \
    #sun ../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineInterface.cpp \
    #sun ../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineFactoryMngr.cpp \
    #sun ../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineFactoryBase.cpp \
    #sun ../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineDeviceMngr.cpp \
    #sun ../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineDeviceBase.cpp \
    #sun ../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineDeviceWnd.cpp \
    #sun ../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineDeviceWnd_Linux.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementUIVP.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg6044CommonChIn.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfg6044CommonInData.cpp \
    #sun ../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineServerWnd.cpp \
    #sun ../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineServerWnd_Linux.cpp \
    #sun ../../../IotProtoServer/Module/SttPxCommCmdDef.cpp \
    ../../../Module/BaseClass/XTimer.cpp \
    ../../../61850/Module/SCL/SclFileMngr/XSclFileMngr.cpp \
    ../../../61850/Module/SCL/SclFileMngr/SclFileMngrGlobal.cpp \
    ../../../61850/Module/SCL/SclFileMngr/XSclFileObj.cpp \
    ../../../61850/Module/SCL_Qt/QScdFileRWDlg.cpp \
    ../../../Module/DataMngr/DvmValues.cpp \
    ../../../Module/API/StringConvertApi.cpp \
    #sun ../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbWzdAi/GbWzdAiParasBase.cpp \
    #sun ../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbWzdAi/GbWzdAiBase.cpp \
    #sun ../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbWzdAi/GbWzdAiDO.cpp \
    #sun ../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbWzdAi/GbWzdAiKeysFunc.cpp \
    #sun ../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbWzdAi/GbWzdAiMacroPara.cpp \
    #sun ../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbWzdAi/GbWzdAiOptr.cpp \
    #sun ../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbWzdAi/GbWzdAiScript.cpp \
    #sun ../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbWzdAi/GbWzdAiSwitch.cpp \
    #sun ../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbWzdAi/GbWzdAiTool.cpp \
    #sun ../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbSmartGenWzdGlobal.cpp \
    ../../../Module/Expression/XExprBase.cpp \
    ../../../Module/Expression/XExprCmp.cpp \
    ../../../Module/Expression/XExprError.cpp \
    ../../../Module/Expression/XExprGlobal.cpp \
    ../../../Module/Expression/XExprNode.cpp \
    ../../../Module/Expression/XExprRange.cpp \
    ../../../Module/Expression/XExprValue.cpp \
    ../../../Module/Expression/XExprValue_Ex.cpp \
    ../../../Module/Expression/XExprValueCal.cpp \
    ../../../Module/TestMacro/TestMacro.cpp \
    ../../../Module/TestMacro/TestMacroGlobal.cpp \
    ../../../Module/TestMacro/TestMacros.cpp \
    ../../../Module/TestMacro/TmFaultParas.cpp \
    ../../../Module/TestMacro/TmFaultParasEx.cpp \
    ../../../Module/TestMacro/TmResultParas.cpp \
    ../../../Module/TestMacro/TmResultParasEx.cpp \
    ../../../Module/TestMacro/TmSysParas.cpp \
    ../../../Module/Socket/WinUdpScoket.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementIUF.cpp \
    ../../../Module/Expression/XExprErrorCombined.cpp \
    ../../../Module/Expression/XExprErrorEx.cpp \
    ../../../Module/Expression/XExprValueCalEx.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgFiberParasIn.cpp \
    ../../../Module/Expression/XExprCal.cpp \
    ../../../Module/DataMngr/DvmCmp/DvmCmpKeyDataTypes.cpp \
    ../../../61850/Module/61850ClientConfig/61850ClientCfgMngrGlobal.cpp \
    ../../../61850/Module/61850ClientConfig/61850ClientConfig.cpp \
    ../../../61850/Module/61850ClientConfig/RemoteDev.cpp \
    ../../../61850/Module/61850ClientConfig/RemoteDevs.cpp \
    ../../../AutoTest/Module/Characteristic/CharElementDCOverLoad.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Cell.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Col.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_ColDef.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_ColsDef.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Enable.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Grid.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_GridDef.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_GuideBook.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Head.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Items.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_MacroCharItems.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_MacroTest.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Png.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_PngDef.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Reports.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_ReportsDef.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_ReportTemplate.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_ReportTemplateDef.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Row.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_RowDef.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_RowsDef.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Rpeort.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_RpeortDef.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_TestMacroUiRpt.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_TestMacroUiRptDef.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Text.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_TextDef.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Title.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_TitleDef.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Value.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_ValueDef.cpp \
    ../../../AutoTest/Module/TestMacroRptTemplate/TestMacroRptTemplateGlobal.cpp \
    ../../../Module/SmartCap/61850Cap/CapDevice/CapDevice6044.cpp \
    ../../../Module/OSInterface/QT/CDateTime_QT.cpp \
    ../../../Protocol/Module/PxiEngine/PxiDeviceCommCmdMessage.cpp \
    #sun ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Group.cpp \
    #sun ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Data.cpp \
    ../../../Module/SmartCap/61850Cap/ProtocolBase/6044Frame.cpp \
    ../../../Module/xml/XPugiXML/xpugixml.cpp \
    #sun ../../Module/HtmlReport/IECTest/SttHtmlRptGen_TerminalAuto.cpp \
    ../../Module/UI/Controls/SttGroupBox.cpp \
    #sun ../../Module/UI/AntiShakeTime/QSttMacroParaEditViewAntiShakeTime.cpp \
    #sun ../../Module/UI/AntiShakeTime/Grid/QSttAntiShakeTimeTestItemsGroupGrid.cpp \
    #sun ../../Module/UI/AntiShakeTime/Grid/QSttAntiShakeTimeDinEventGroupGrid.cpp \
    #sun ../../Module/HtmlReport/IECTest/SttHtmlRptGen_ShortTimeOver.cpp \
    ../../Module/UI/Module/ScrollCtrl/ScrollSlider.cpp \
    ../../../61850/Module/SCL/CcdFileRead.cpp \
    ../../Module/UI/TransPlay/SttReplayWaveformEditWidget.cpp \
    ../../Module/RecordTest/UI/SttIecSmvGrid_HarmAnalyze.cpp \
    ../../Module/UI/ADMUAccurAutoTest/ADMUAccurAutoTestParasSetDialog.cpp \
    ../../Module/UI/ADMUAccurAutoTest/SttMacroParaEditViewADMUAccurAutoTest.cpp \
    ../../Module/UI/PowerManu/ManualView_PV.cpp \
    ../../Module/UI/PowerManu/PowerManualEstimateDlg.cpp \
    ../../Module/UI/PowerManu/PowerManualGrid.cpp \
    ../../Module/UI/PowerManu/PowerManualGridImp.cpp \
    ../../Module/UI/PowerManu/PowerManualWidget.cpp \
    ../../Module/UI/PowerManu/SttMacroParaEditViewPowerManu.cpp \
    ../../Module/UI/CBOperate/QSttMacroParaEditViewCBOperate.cpp \
    ../../Module/UI/CBOperate/Grid/CBOperateResultAssessGrid.cpp \
    ../../Module/UI/CBOperate/Dlg/CBOperateCommonParasDlg.cpp \
    ../../Module/UI/Module/ChannelParaSet/channelpowertable.cpp \
    ../../Module/TestUI/Distance/DistanceAddMultDlg.cpp \
    ../../Module/TestUI/Distance/DistanceBinarysDlg.cpp \
    ../../Module/TestUI/Distance/DistanceCommonParasDlg.cpp \
    ../../Module/TestUI/Distance/DistanceItemParaEditWidget.cpp \
    ../../Module/TestUI/Distance/DistanceResultEstimateDlg.cpp \
    ../../Module/TestUI/Distance/SttMultiMacroParaEditViewDistance.cpp \
    ../../Module/TestUI/Module/CommonGrid/QSttMacroParaEditGrid.cpp \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdColDef.cpp \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdColDef_Fuc_Avg.cpp \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdColDef_Fuc_Max.cpp \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdColDef_Fuc_Min.cpp \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdColDef_Para.cpp \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdColDef_Script.cpp \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdColDef_TextComb.cpp \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdCondition.cpp \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdDataCal.cpp \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdDataProcess.cpp \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdGridDefine.cpp \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdGridInst.cpp \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdGridInsts.cpp \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdInst_Col.cpp \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdInst_Cols.cpp \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdParaCondition.cpp \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdTestMacro.cpp \
    ../../Module/TestUI/Module/SttTestGridDefine/SttTestGridDefine.cpp \
    ../../Module/TestUI/Module/SttTestGridDefine/SttTestGridDefineGlobal.cpp \
    ../../Module/TestUI/QSttMultiMacroParaEditViewBase.cpp \
    ../../Module/TestUI/Interface/QItemParaEditWidgetBase.cpp \
    ../../Module/SttTest/Common/Power/tmt_power_manu_test.cpp \
    ../../Module/UI/ImpedanceManu/ImpedanceManuEstimateDlg.cpp \
    ../../Module/UI/ImpedanceManu/ImpedanceManuWidget.cpp \
    ../../Module/UI/ImpedanceManu/SttMacroParaEditViewImpedanceManu.cpp \
    ../../Module/SttTest/Common/Impedance/tmt_manuImped_test.cpp \
    ../../Module/UI/TransPlay/SttReplayBoutModuleChWidget.cpp \
    ../../Module/UI/TransPlay/SttReplayDigitalMoudleWidget.cpp \
 #   ../../Module/UI/TransPlay/SttReplayWeekModuleChWidget .cpp
    ../../Module/UI/TransPlay/SttReplayWeekModuleChWidget.cpp \
    ../../../Module/Expression/XExprRangeEx.cpp


HEADERS  += \
    ../../Module/SttCmdToolMngr.h \
    ../../Module/SttGlobalDef.h \
    ../../Module/SttGlobalDef_File.h \
    ../../../Module/XLanguage/XLanguageResource.h \
    ../../../Module/XLanguage/XLangItem.h \
    ../../../Module/XLanguage/XLanguage.h \
    ../../../Module/XLanguage/XLanguageGlobal.h \
    ../../../Module/XLanguage/XLanguageMngr.h \
    ../../../Module/XLanguage/XLanguageNameParser.h \
    ../../../61850/Module/XLanguageResourceIec.h \
    ../../../61850/Module/XLanguageResourcePp_Mms.h \
    ../../../AutoTest/Module/XLanguageResourceAts.h \
    ../../Module/XLangResource_Native.h \
    ../../Module/SttCmd/SttAssistCmd.h \
    ../../Module/SttCmd/SttAtsCmd.h \
    ../../Module/SttCmd/SttCmdBase.h \
    ../../Module/SttCmd/SttCmdCreator.h \
    ../../Module/SttCmd/SttCmdDefineGlobal.h \
    ../../Module/SttCmd/SttMacro.h \
    ../../Module/SttCmd/SttParas.h \
    ../../Module/SttCmd/SttRemoteCmd.h \
    ../../Module/SttCmd/SttSysState.h \
    ../../Module/SttCmd/SttSystemCmd.h \
    ../../Module/SttCmd/SttTestCmd.h \
    ../../Module/SttCmd/SttCmdData.h \
    ../../Module/SttCmd/SttMsg.h \
    ../../Module/SttCmd/SttMsgs.h \
    ../../Module/SttCmd/SttAdjustCmd.h \
    ../../Module/SttCmd/GuideBook/SttCommCmd.h \
    ../../Module/SttCmd/GuideBook/SttDataObj.h \
    ../../Module/SttCmd/GuideBook/SttDevice.h \
    ../../Module/SttCmd/GuideBook/SttGuideBook.h \
    ../../Module/SttCmd/GuideBook/SttItemBase.h \
    ../../Module/SttCmd/GuideBook/SttItems.h \
    ../../Module/SttCmd/GuideBook/SttJobGuide.h \
    ../../Module/SttCmd/GuideBook/SttMacroTest.h \
    ../../Module/SttCmd/GuideBook/SttReport.h \
    ../../Module/SttCmd/GuideBook/SttReportMap.h \
    ../../Module/SttCmd/GuideBook/SttReports.h \
    ../../Module/SttCmd/GuideBook/SttRptData.h \
    ../../Module/SttCmd/GuideBook/SttSafety.h \
    ../../Module/SttCmd/GuideBook/SttSysParaEdit.h \
    ../../Module/SttCmd/GuideBook/SttSysParas.h \
    ../../Module/SttCmd/SttChMap.h \
    ../../Module/SttCmd/SttChMaps.h \
    ../../Module/SttCmd/SttHdCh.h \
    ../../Module/SttCmd/SttHdChs.h \
    ../../Module/SttCmd/SttIotDevice.h \
    ../../Module/SttCmd/SttIotDevices.h \
    ../../Module/SttCmd/SttIotNode.h \
    ../../Module/SttCmd/SttIotTopo.h \
    ../../Module/SttCmd/SttDebugCmd.h \
    ../../Module/SttCmd/SttRptMapDatas.h \
    ../../Module/SttCmd/GuideBook/SttContents.h \
    ../../Module/SttCmd/GuideBook/SttTestMacroUiParas.h \
    ../../Module/SttCmd/GuideBook/SttItemStateObject.h \
    ../../Module/SttCmd/GuideBook/SttMacroCharItems.h \
    ../../Module/SttCmd/SttIotCmd.h \
    ../../Module/SttCmd/GuideBook/SttItemRsltExpr.h \
    ../../Module/SttCmd/GuideBook/SttTestMacroCharParas.h \
    ../../Module/Engine/SttClientTestEngine.h \
    ../../Module/Engine/SttTestEngineBase.h \
    ../../Module/Engine/SttTestEngineClientData.h \
    ../../Module/Engine/SttServerNativeConfig.h \
    ../../Module/Engine/SttRemoteClientTestEngine.h \
    ../../Module/Engine/SttTestEngineRemoteClientData.h \
    ../../Module/Engine/SttTestServerBase.h \
    ../../Module/Engine/SttTestEngineServerBase.h \
    ../../Module/Engine/SttTestEngineServerData.h \
   ../../Module/Engine/SttServerTestCtrlCntr.h \
    #sun ../../Module/Engine/PpMeas/PpSttIotEngineDeviceBase.h \
    #sun ../../Module/Engine/PpMeas/PpSttIotMeasDevice.h \
    #sun ../../Module/Engine/PpMeas/PpSttIotMeasServer.h \
    #sun ../../Module/Engine/PpEngineServerBase/SttPxPotoEngineBase.h \
    #sun ../../Module/Engine/PpEngineServerBase/SttPpServerSocket.h \
    #sun ../../Module/Engine/PpEngineServerBase/SttPpServerClientSocket.h \
    #sun ../../Module/Engine/PpEngineServerBase/SttPpEngineServer.h \
    ../../Module/SttSocket/SttServerSocketDataBase.h \
    ../../Module/SttSocket/SttSocketDataBase.h \
    ../../Module/SttSocket/SttSocketDataBase_File.h \
    ../../Module/SttSocket/SttCmdOverTimeMngr.h \
    ../../Module/SttSocket/TestTerminal/SttClientSocketBase.h \
    ../../Module/SttSocket/TestTerminal/QT/SttClientSocket.h \
    ../../Module/SttSocket/TestServer/SttNativeRemoteClientSocketBase.h \
    ../../Module/SttSocket/TestServer/SttServerClientSocketBase.h \
    ../../Module/SttSocket/TestServer/SttTestServerSocketBase.h \
    ../../Module/SttSocket/TestServer/QT/SttNativeRemoteClientSocket.h \
    ../../Module/SttSocket/TestServer/QT/SttServerClientSocket.h \
    ../../Module/SttSocket/TestServer/QT/SttTestServerSocket.h \
    ../../Module/SttSocket/Multicast/SttMulticastClientSocket.h \
    ../../Module/SttSocket/Multicast/SttUdpSocketDataBase.h \
    ../../Module/TestClient/SttMacroTestInterface.h \
    ../../Module/TestClient/SttAtsTestClient.h \
    ../../Module/TestClient/SttTestClientBase.h \
    ../../Module/TestClient/PpSttIotClient.h \
    ../../Module/SttAuthority/SttTestClientUser.h \
    ../../Module/SttAuthority/SttTestClientUserMngr.h \
    ../../Module/SttAuthority/SttTestRemoteRegister.h \
    ../../Module/SttProtocolBufBase.h \
    ../../Module/SttRegisterCode.h \
    ../../Module/SttFileToolMngr.h \
    ../../Module/UI/Module/ScrollCtrl/ScrollComboBox.h \
    ../../Module/UI/Module/ScrollCtrl/ScrollListView.h \
    ../../Module/UI/Module/ScrollCtrl/ScrollTableWidget.h \
    ../../Module/UI/Module/ScrollCtrl/ScrollWebView.h  \
    ../../Module/RecordTest/RingMemBuf.h \
    ../../Module/RecordTest/RingMemBufShm.h \
    ../../Module/RecordTest/QT/SttLocalRcdMemBufferMngrLinux.h \
    ../../Module/RecordTest/UI/SttIecCbGrid.h \
    ../../Module/RecordTest/UI/SttIecRecordMainWidget.h \
    ../../Module/RecordTest/UI/SttIecChsGridBase.h \
    ../../Module/RecordTest/UI/SttIecRcdFuncInterface.h \
    ../../Module/RecordTest/UI/SttIecRecordCbWidget.h \
    ../../Module/RecordTest/UI/SttIecSmvGrid_EffecValue.h \
    ../../Module/RecordTest/UI/SttIecSmvWaveWidget.h \
    ../../Module/RecordTest/UI/SttIecGooseGrid_RT.h \
    ../../Module/RecordTest/UI/SttIecGooseGrid_TurnList.h \
    ../../Module/RecordTest/UI/SttIecSmvGrid_Harm.h \
    ../../Module/RecordTest/UI/SttIecSmvGrid_Power.h \
    ../../Module/RecordTest/UI/SttIecSmvGrid_AD.h \
    ../../Module/RecordTest/UI/SttIecEmptyWidget.h \
    ../../Module/RecordTest/UI/SttIecSmvPolarWidget.h \
    ../../Module/RecordTest/UI/SttIecSmvSequenceWidget.h \
    ../../Module/RecordTest/UI/SttIecSmvVectorWidget.h \
    ../../Module/RecordTest/UI/SttIecSmvGrid_ChAttr.h \
    ../../Module/RecordTest/UI/SttIecSmvMeterAxisWidget.h \
    ../../Module/RecordTest/UI/SttIecSmvGrid_PkgAnalyze.h \
    ../../Module/RecordTest/UI/SttIecSmvGrid_PkgError.h \
    ../../Module/RecordTest/UI/SttIecGooseGrid_PkgAnalyze.h \
    ../../Module/RecordTest/UI/SttIecGooseTurnSpyWidget.h \
    ../../Module/RecordTest/UI/SttIecGsBinaryDrawView.h \
    ../../Module/RecordTest/UI/SttIecGsBinaryDraw.h \
    ../../Module/RecordTest/UI/SttIecRecordSysSetDlg.h \
    ../../Module/RecordTest/UI/SttIecRecordWriteFileWidget.h \
    ../../Module/RecordTest/UI/SttIecSmvGrid_MUAccuracy.h \
    ../../Module/RecordTest/UI/SttIecMUAccuracyWidget.h \
    ../../Module/RecordTest/UI/SttIecSmvGrid_MUErrorStatis.h \
    ../../Module/RecordTest/UI/SttIecMUTimeWidget.h \
    ../../Module/ReplayTest/SttModuleChComtradeBind.h \
    ../../Module/ReplayTest/SttCmtrdCfgDefineGlobal.h \
    ../../Module/ReplayTest/ComtradeSendSocket.h \
    ../../Module/ReplayTest/ComtradePlayConfig.h \
    ../../Module/ReplayTest/ComtradeDataBuffer.h \
    ../../Module/ReplayTest/ComtradeBufMngr.h \
    ../../Module/ReplayTest/BigComtradeTransPlay.h \
    ../../Module/ReplayTest/BigComtradeFileRead.h \
    ../../Module/RecordTest/UI/MUTest/SttMUTestIecCbSelWidget.h \
    ../../Module/RecordTest/UI/SttIecCapDialog.h \
    ../../Module/RecordTest/UI/MUTest/SttIecRecordCbInterface.h \
    ../../Module/RecordTest/UI/MUTest/SttMUTestChsSetDlg.h \
    ../../Module/RecordTest/UI/MUTest/SttMUTestRecordCbWidget.h \
    ../../Module/RecordTest/UI/SttIecSmvMUAccuaryGrid.h \
    ../../Module/RecordTest/UI/SttIecSmvDiscretChartAxis.h \
    ../../Module/RecordTest/UI/SttIecSmvDiscretCharWidget.h \
    ../../Module/RecordTest/UI/SttIecSmvWidget_Harm_Histogram.h \
    ../../Module/RecordTest/UI/SttIecSmvWidget_Harm.h \
    ../../Module/RecordTest/UI/SttIecSmvGrid_Harm_Content.h \
    ../../Module/RecordTest/UI/SttIecSmvHistogramChartAxis.h \
    ../../Module/RecordTest/UI/FT3_Test/SttIecFT3Grid_RT.h \
    ../../Module/RecordTest/UI/SttRecordChComparePlot.h \
    ../../Module/RecordTest/UI/MUTest/FirstCircleWave/SttMUTestFirstCwWidget.h \
    ../../Module/RecordTest/UI/SttIecRecordDetectWidget.h \
    ../../Module/RecordTest/UI/FT3_Test/SttIecFT3LineNumberPlanTextEdit.h \
    ../../Module/RecordTest/UI/FT3_Test/SttIecFT3OriginalMsgWidget.h \
    ../../Module/RecordTest/UI/SttIecSmvWaveMainWidget.h \
    ../../Module/RecordTest/UI/SttIecSmvGrid_ChQualitySpy.h \
    ../../Module/RecordTest/UI/SttIecGooseGrid_PkgError.h \
    ../../Module/SttTestAppConfig/SttTestAppCfg.h \
    ../../Module/SttTestAppConfig/SttTestAppConfigTool.h \
    ../../Module/SttTestAppConfig/SttTestDeviceCfg.h \
    ../../Module/AdjustTool/SttAdjBase.h \
    ../../Module/AdjustTool/SttAdjDevice.h \
    ../../Module/AdjustTool/SttAdjModule.h \
    ../../Module/AdjustTool/SttMesLocalDb.h \
    ../../Module/Protocol/SttProtocolDatas.h \
    ../../Module/SttTestBase/SttComplexCalApi.h \
    ../../Module/SttTestBase/SttMacroXmlKeys.h \
    ../../Module/SttTestBase/SttXmlSerialize.h \
    ../../Module/SttTestBase/SttXmlSerializeBase.h \
    ../../Module/SttTestBase/SttComplexp.h \
    ../../Module/SttTestBase/SttDiffCurrCalculatTool.h \
    ../../Module/SttTest/SttTestGlobaoConfig.h \
    ../../Module/SttTest/Common/tmt_adjust_sys_parameter.h \
    ../../Module/SttTest/Common/tmt_adjust_sys_para_trans.h \
    ../../Module/SttTest/Common/tmt_common_def.h \
    ../../Module/SttTest/Common/tmt_pt_test.h \
    ../../Module/SttTest/Common/tmt_result_def.h \
    ../../Module/SttTest/Common/tmt_soe_test.h \
    ../../Module/SttTest/Common/tmt_system_config.h \
    ../../Module/SttTest/Common/tmt_test_mngr.h \
    ../../Module/SttTest/Common/tmt_test_paras_head.h \
    ../../Module/SttTest/Common/Abnormal/tmt_abnormal_test.h \
    ../../Module/SttTest/Common/tmt_state_test.h \
    ../../Module/SttTest/Common/ActionTime/tmt_vol_inverse_time_test.h \
    ../../Module/SttTest/Common/Impedance/tmt_cb_operate_test.h \
    ../../Module/SttTest/Common/Impedance/tmt_distance_test.h \
    ../../Module/SttTest/Common/Impedance/tmt_impedance_test.h \
    ../../Module/SttTest/Common/Impedance/tmt_reclose_acc_test.h \
    ../../Module/SttTest/Common/SearchBase/tmt_complex_search.h \
    ../../Module/SttTest/Common/SearchBase/tmt_search_base.h \
    ../../Module/SttTest/Common/tmt_manu_test.h \
    ../../Module/SttTest/Common/tmt_gradient_test.h \
    ../../Module/SttTest/Common/tmt_harm_test.h \
    ../../Module/SttTest/Common/LineVolt/tmt_linevolt_gradient_test.h \
    ../../Module/SttTest/Common/LineVolt/tmt_linevolt_manu_test.h \
    ../../Module/SttTest/Common/tmt_short_time_over_test.h \
    ../../Module/SttTest/Common/tmt_replay_test.h \
    ../../Module/SttTest/Common/Sequence/tmt_sequence_gradient_test.h \
    ../../Module/SttTest/Common/Sequence/tmt_sequence_manu_test.h \
    ../../Module/SttTest/Common/Gradient/tmt_fault_gradient_test.h \
    ../../Module/SttTest/Common/FAParasSet/tmt_fa_Paras_set.h \
    ../../Module/SttSystemConfig/SttDevConfig.h \
    ../../Module/SttSystemConfig/SttModule.h \
    ../../Module/SttSystemConfig/SttModuleUse.h \
    ../../Module/SttSystemConfig/SttSystemConfig.h \
    ../../Module/SttSystemConfig/SttSystemConfigGlobal.h \
    #sun ../Module/SttNativeTestMainApp.h \
    #sun ../SttNativeMain/SttNativeTestMainApplication.h \
    ../../Module/SttTestResourceMngr/SttTestResourceMngr.h \
    ../../Module/SttTestResourceMngr/RtDataMngr/SttGlobalRtDataMngr.h \
    ../../Module/SttTestResourceMngr/RtDataMngr/SttMacroChannels.h \
    ../../Module/SttTestResourceMngr/RtDataMngr/SttMacroChannelsAsync.h \
    ../../Module/SttTestResourceMngr/TestResource/SttTestResource_4U3I.h \
    ../../Module/SttTestResourceMngr/TestResource/SttTestResource_6U6I.h \
    ../../Module/SttTestResourceMngr/TestResource/SttTestResource_Async.h \
    ../../Module/SttTestResourceMngr/TestResource/SttTestResourceBase.h \
    ../../Module/SttTestResourceMngr/TestResource/SttTestResource_Sync.h \
    ../../Module/BinaryDraw/XBinaryDrawBase.h \
    ../../Module/BinaryDraw/XBinaryDrawGlobal.h \
    ../../Module/BinaryDraw/XBinaryDrawView.h \
    ../../Module/LiveUpdate/UpdateConfig/VerUpdateCfgMngr.h \
    ../../Module/LiveUpdate/UpdateConfig/VerUpdateCfgMngrGlobal.h \
    ../../Module/LiveUpdate/UpdateConfig/VerUpdateCfgSys.h \
    ../../Module/LiveUpdate/UpdateConfig/VerUpdateCfgSyses.h \
    ../../Module/LiveUpdate/UpdateConfig/VerUpdateCfgYun.h \
    ../../Module/LiveUpdate/SttLiveUpdateDef.h \
    ../../Module/LiveUpdate/SttLiveUpdateShell.h \
    ../../Module/LiveUpdate/SttUpdateCfg.h \
    #sun ../../Module/SmartTestInterface/PpSttIotEngineClientApp.h \
    #sun ../../Module/SmartTestInterface/PpSttIotEngine.h \
    #sun ../../Module/SmartTestInterface/ProtocolEngineInterface.h \
    ../../Module/SmartTestInterface/PpSttCommConfig.h \
    #sun ../../Module/SmartTestInterface/QT/PpSttIotEngineClientAppWnd.h \
    #sun ../../Module/SmartTestInterface/QT/PpSttIotEngineClientWidget.h \
    #sun ../../Module/SmartTestInterface/QT/PpSttIotEngineClientWidgetMain.h \
    #sun ../../Module/SmartTestInterface/QT/SttPxEngineDsEditGrid.h \
    #sun ../../Module/SmartTestInterface/QT/SttPxEngineDvmTreeCtrl.h \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/ppcommconfigdlg.h \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommcfgtcpclientdlg.h \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommconfigcmsdlg.h \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommconfigmmsdlg.h \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommconfigserialmode.h \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommconfigtcpserverdlg.h \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommconfigudpclientdlg.h \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommconfigudpserver.h \
    #sun ../../Module/SmartTestInterface/QT/qsttmmsbrcbctrlwidget.h \
    #sun ../../Module/SmartTestInterface/QT/qsttzoneindexsetdlg.h \
    #sun ../../Module/SmartTestInterface/PpXIotEngineBase.h \
    ../../Module/API/NetworkInterface.h \
    #sun ../../Module/HtmlReport/SttModuleHtmlRptGenBase.h \
    #sun ../../Module/HtmlReport/SttXHtmlRptGenFactoryBase.h \
    #sun ../../Module/HtmlReport/SttXHtmlRptGenInterface.h \
    #sun ../../Module/HtmlReport/SttXmacroHtmlRptGenBase.h \
    #sun ../../Module/HtmlReport/IECTest/SttHtmlRptGen_MUAccuracy.h \
    #sun ../../Module/HtmlReport/IECTest/SttIecTestHtmlRptGenFactory.h \
    #sun ../../Module/HtmlReport/IECTest/SttHtmlRptGen_MUPunctAccur.h \
    #sun ../../Module/HtmlReport/IECTest/SttHtmlRptGen_MUTimingAccur.h \
    #sun ../../Module/HtmlReport/IECTest/SttHtmlRptGen_MUZeroDrift.h \
    #sun ../../Module/HtmlReport/IECTest/SttHtmlRptGen_IntelligentTerminal.h \
    ../../Module/Assist/SttAppWndAssistInterface.h \
    ../../Module/Assist/SttAssistEngine.h \
    ../../Module/Assist/SttAssistGlobalApi.h \
    ../../Module/Assist/SttAssistInterface.h \
    ../../Module/Assist/DynEffect/SttAssistWndDynEffectBase.h \
    ../../Module/Assist/DynEffect/SttAssistWndDynEffExecTool.h \
    ../../Module/Assist/DynEffect/SttAssistWndFlash.h \
    ../../Module/Assist/MU/SttAssistWzd_MuTest.h \
    ../../Module/Assist/Script/SttAssistWzd_ScriptRun.h \
    ../../Module/Assist/MU/SttAssistIecCbSelWidget.h \
    ../../Module/Assist/DynEffect/QSttAssistMsgWidget.h \
    ../../Module/Assist/DynEffect/QSttAssistTipsShowWidget.h \
    ../../Module/Assist/DynEffect/SttAssistShowTips.h \
    ../../Module/Assist/QSttAssistMenuWidget.h \
    ../../Module/Assist/QObjectGlobalApi.h \
    ../../Module/SttTestCtrl/SttTestAppBase.h \
    ../../Module/SttTestCtrl/SttTestCtrlCntrBase.h \
    ../../Module/SttTestCtrl/SttTestCtrlCntrNative.h \
    ../../Module/SttTestCtrl/SttArgcArgvParser.h \
    ../../Module/UI/SttTestCntrThread.h \
    ../../Module/UI/Interface/SttMacroParaEditInterface.h \
    ../../Module/UI/Interface/SttMacroParaEditViewMngr.h \
    ../../Module/UI/Interface/SttMacroParaEditViewOriginal.h \
    #sun ../../Module/UI/Interface/SttHtmlReportViewInterface.h \
    #sun ../../Module/UI/Interface/SttHtmlViewApi.h \
    #sun ../../Module/UI/Webkit/SttMacroParaEditViewHtml.h \
    #sun ../../Module/UI/Webkit/SttWebViewBase.h \
    #sun ../../Module/UI/Webkit/SttReportViewHtml.h \
    ../../Module/UI/Config/Frame/SttFrame_Button.h \
    ../../Module/UI/Config/Frame/SttFrameConfig.h \
    ../../Module/UI/Config/Frame/SttFrame_Data.h \
    ../../Module/UI/Config/Frame/SttFrame_Font.h \
    ../../Module/UI/Config/Frame/SttFrame_GbTree.h \
    ../../Module/UI/Config/Frame/SttFrame_Item.h \
    ../../Module/UI/Config/Frame/SttFrame_MacroParaView.h \
    ../../Module/UI/Config/Frame/SttFrame_Menu.h \
    ../../Module/UI/Config/Frame/SttFrame_Menus.h \
    ../../Module/UI/Config/Frame/SttFrame_Panal.h \
    ../../Module/UI/Config/Frame/SttFrame_ReportView.h \
    ../../Module/UI/Config/Frame/SttFrame_RightPanes.h \
    ../../Module/UI/Config/Frame/SttFrame_Size.h \
    ../../Module/UI/Config/Frame/SttFrame_XBar.h \
    ../../Module/UI/Config/Frame/SttTestCtrlFrameCfgMngrGlobal.h \
    ../../Module/UI/Config/MacroTestUI/SttMacroTestUI_Group.h \
    ../../Module/UI/Config/MacroTestUI/SttMacroTestUI_TestMacroUI.h \
    ../../Module/UI/Config/MacroTestUI/SttMacroTestUI_TestMacroUIDB.h \
    ../../Module/UI/Config/MacroTestUI/SttMacroTestUI_TestMacroUIMngr.h \
    ../../Module/UI/Config/MacroTestUI/SttMacroTestUI_TestMacroUIRef.h \
    ../../Module/UI/Config/MacroTestUI/SttMacroTestUI_TestMacroUIs.h \
    ../../Module/UI/Config/MacroTestUI/SttTestCtrrlMacroTestUIMngrGlobal.h \
    ../../Module/UI/Config/Frame/SttFrame_GlobalDatas.h \
    ../../Module/UI/Config/Frame/SttFrame_GlobalData.h \
    ../../Module/UI/Controls/SttDataButtons.h \
    ../../Module/UI/Controls/SttToolButtonBase.h \
    ../../Module/UI/Controls/SttToolButton.h \
    ../../Module/UI/Controls/SttPanelBase.h \
    ../../Module/UI/Controls/SttGuideBookTreeCtrl.h \
    ../../Module/UI/Controls/SttMenuWidget.h \
    ../../Module/UI/Controls/SttItemButton.h \
    ../../Module/UI/Controls/SttAddMacroWidget.h \
    ../../Module/UI/Controls/SttGuideBookTreeWidget.h \
    ../../Module/UI/Controls/SttOutPutWidget.h \
    ../../Module/UI/Controls/FileMngr/SttFileMngrChildren.h \
    ../../Module/UI/Controls/FileMngr/SttFileMngrDlg.h \
    ../../Module/UI/Controls/FileMngr/SttFileTypeMngrGrid.h \
    ../../Module/UI/Controls/FileMngr/SttFileViewGrid.h \
    ../../Module/UI/Controls/FileMngr/SttXFolderButton.h \
    ../../Module/UI/Controls/SttLineEdit.h \
    ../../Module/UI/Controls/SttLanguageCfgDialog.h \
    ../../Module/UI/Controls/SttReportHeadSetDlg.h \
    ../../Module/UI/Controls/SttDvmEdit.h \
    ../../Module/UI/Controls/SttFileSaveAsDlg.h \
    ../../Module/UI/Controls/SttCustomSetDlg.h \
    ../../Module/UI/Controls/SttCustomSetTree.h \
    ../../Module/UI/Controls/SttCheckBox.h \
    ../../Module/UI/Controls/SttTabWidget.h \
    ../../Module/UI/Controls/NetworkConfig/QModifyIPAddrDlg.h \
    ../../Module/UI/Controls/SafetyMsgCfg/SttSafetyMsg.h \
    ../../Module/UI/Controls/SafetyMsgCfg/SttSafetyMsgCfg.h \
    ../../Module/UI/Controls/SafetyMsgCfg/SttSafetyMsgCfgGlobal.h \
    ../../Module/UI/Controls/SafetyMsgCfg/SttSafetyMsgCfgs.h \
    ../../Module/UI/Controls/NetworkConfig/qnetworkconfigwidget.h \
    ../../Module/UI/Controls/NetworkConfig/qnetworkiptable.h \
    ../../Module/UI/Controls/FileMngr/SttFileMoveDlg.h \
    ../../Module/UI/SoftKeyboard/SoftKeyBoard.h \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin.h \
    ../../Module/UI/SoftKeyboard/Keyboard/Keyboard.h \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/atomdictbase.h \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/dictbuilder.h \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/dictdef.h \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/dictlist.h \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/dicttrie.h \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/lpicache.h \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/matrixsearch.h \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/mystdlib.h \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/ngram.h \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/pinyinime.h \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/searchutility.h \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/spellingtable.h \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/spellingtrie.h \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/splparser.h \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/sync.h \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/userdict.h \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/utf16char.h \
    ../../Module/UI/SoftKeyboard/Keyboard/googlepinyin/utf16reader.h \
    ../../Module/UI/Harm/SttMacroParaEditViewHarm.h \
    ../../Module/UI/State/StateButtonWidget.h \
    ../../Module/UI/State/StateParaTab.h \
    ../../Module/UI/State/StateParaWidget.h \
    ../../Module/UI/State/SttMacroParaEditViewState.h \
    ../../Module/UI/TransPlay/SttMacroParaEditViewTransPlay.h \
    ../../Module/UI/Module/ChannelParaSet/channelharmtable.h \
    ../../Module/UI/Module/ChannelParaSet/channeltable.h \
    ../../Module/UI/Module/ChannelParaSet/QBasicTestParaSet.h \
    ../../Module/UI/Module/ChannelParaSet/QParaSetBase.h \
    ../../Module/UI/Module/ExSwitchSet/exswitchset.h \
    ../../Module/UI/Module/CommonMethod/CommonMethod.h \
    SttTestCntrFrameLinux.h \
    SttTestCntrApplication.h \
    ../../Module/UI/Manual/ManualView_IV.h \
    ../../Module/UI/Manual/ManualView_Paras.h \
    ../../Module/UI/SttTestCntrCmdDefine.h \
    ../../Module/UI/SttTestCntrFrameBase.h \
    ../../Module/UI/State/CommonValueDialogState.h \
    ../../Module/UI/State/ShortCalcuDig.h \
    ../../Module/UI/State/Gradient/gradientchanneltable.h \
    ../../Module/UI/State/Gradient/gradientparaset.h \
    ../../Module/UI/State/Gradient/gradientparatab.h \
    ../../Module/UI/State/Gradient/GradientSetDlg.h \
    ../../Module/UI/Module/CommonMethod/FaultCalculat.h \
    ../../Module/UI/Module/VectorWidget/DiagramWidget.h \
    ../../Module/UI/Module/VectorWidget/vectorwidget.h \
    ../../Module/UI/Module/GooseParaWidget/GoosePubWidget.h \
    ../../Module/UI/Module/GooseParaWidget/IecCfgGoutChsGrid.h \
    ../../Module/UI/Module/GooseParaWidget/LineEdit.h \
    ../../Module/UI/Module/GooseParaWidget/qgooseparawidget.h \
    ../../Module/UI/Module/GooseParaWidget/WidgetDelegate.h \
    ../../Module/UI/Module/infoWidget/infowidget.h \
    ../../Module/UI/Module/QExBaseListGridBase/QExBaseListComBoxDelegBase.h \
    ../../Module/UI/Module/QExBaseListGridBase/QExBaseListGridBase.h \
    ../../Module/UI/Module/QExBaseListGridBase/QGridDefine.h \
    ../../Module/UI/Module/SttUIDefine.h \
    ../../Module/UI/Harm/HarmParaTable.h \
    ../../Module/UI/Harm/HarmParaWidget.h \
    ../../Module/UI/Harm/HarmWidget.h \
    ../../Module/UI/Harm/QHarmTable.h \
    ../../Module/UI/IEC61850Config/SttIecConfigGlobalDef.h \
    ../../Module/UI/IEC61850Config/SttIecConfigDialog.h \
    ../../Module/UI/IEC61850Config/SttIecConfigGlobalDef.h \
    ../../Module/UI/IEC61850Config/SttIecConfigWidgetBase.h \
    ../../Module/UI/IEC61850Config/SttIecSMV92Widget.h \
    ../../Module/UI/IEC61850Config/SttIecSysParasOtherSetDialog.h \
    ../../Module/UI/IEC61850Config/SttIecSysParasWidget.h \
    ../../Module/UI/IEC61850Config/Grid/IecCfgSmvData92Grid.h \
    ../../Module/UI/Module/CommonCtrl_QT/QFloatLineEdit.h \
    ../../Module/UI/Module/CommonCtrl_QT/QIecLineEdit.h \
    ../../Module/UI/Module/CommonCtrl_QT/QIecWidgetDelegate.h \
    ../../Module/UI/Module/CommonCtrl_QT/QCovDoubleValidator.h \
    ../../Module/UI/Module/CommonCtrl_QT/QNumberCheckBox.h \
    ../../Module/UI/IEC61850Config/SttIecSMV92OtherSetDialog.h \
    ../../Module/UI/IEC61850Config/Grid/IecCfgSmvRateGrid.h \
    ../../Module/UI/Module/ChRsMap/ChMapsGrid.h \
    ../../Module/UI/Module/ChRsMap/QChMapsDlg.h \
    ../../Module/UI/Module/ChRsMap/QChMapsWidget.h \
    ../../Module/UI/IEC61850Config/SttSclCtrlsWidget.h \
    ../../Module/UI/IEC61850Config/SttSclFileParseDialog.h \
    ../../Module/UI/IEC61850Config/SttSclIedTreeItem.h \
    ../../Module/UI/IEC61850Config/Grid/IecCfgChsGridBase.h \
    ../../Module/UI/IEC61850Config/Grid/IecCfgDataGridBase.h \
    ../../Module/UI/IEC61850Config/Grid/IecCfgGinChsGrid.h \
    ../../Module/UI/IEC61850Config/Grid/IecCfgGinDataGrid.h \
    ../../Module/UI/IEC61850Config/Grid/IecCfgGoutChannelsGrid.h \
    ../../Module/UI/IEC61850Config/Grid/IecCfgGoutDataGrid.h \
    ../../Module/UI/IEC61850Config/Grid/IecCfgSmv92ChsGrid.h \
    ../../Module/UI/IEC61850Config/Grid/SclCtrlsGooseInGrid.h \
    ../../Module/UI/IEC61850Config/Grid/SclCtrlsGooseOutGrid.h \
    ../../Module/UI/IEC61850Config/Grid/SclCtrlsGridBase.h \
    ../../Module/UI/IEC61850Config/Grid/SclCtrlsSmvInGrid.h \
    ../../Module/UI/IEC61850Config/Grid/SclCtrlsSmvOutGrid.h \
    ../../Module/UI/IEC61850Config/SttIecChsEditDialog.h \
    ../../Module/UI/IEC61850Config/SttIecGinWidget.h \
    ../../Module/UI/IEC61850Config/SttIecGoutWidget.h \
    ../../Module/UI/Module/CommonCtrl_QT/QLongLineEdit.h \
    ../../Module/UI/IEC61850Config/SttIecQualitySetDialog.h \
    ../../Module/UI/Module/PopupDialog/SttFileSelectGrid.h \
    ../../Module/UI/Module/StateMonitor/StateMonitorBinBout.h \
    ../../Module/UI/Module/StateMonitor/StateMonitorPlot.h \
    ../../Module/UI/Module/StateMonitor/StateMonitorTab.h \
    ../../Module/UI/Module/StateMonitor/StateMonitorVoltCur.h \
    ../../Module/UI/Module/StateMonitor/StateMonitorWidget.h \
    ../../Module/UI/Module/CharLibWidget/PsuCharDrawView.h \
    ../../Module/UI/Module/CharLibWidget/QImpCharactWidget.h \
    ../../Module/UI/Module/ZKCharaCurve/QZKFeatureAddDig.h \
    ../../Module/UI/Module/ScrollCtrl/ScrollTextEdit.h \
    ../../Module/UI/Module/SttAuxIPSetDlg/SttAuxIPSetDlg.h \
    ../../Module/UI/Module/PopupDialog/SttFileMngrTree.h \
    ../../Module/UI/State/GooseAbnormal/GooseAbnormalParaset.h \
    ../../Module/UI/State/GooseAbnormal/SttMacroParaEditViewGooseAbnormal.h \
    ../../Module/UI/State/SmvAbnormal/SmvAbnormalChannelSelect.h \
    ../../Module/UI/State/SmvAbnormal/SmvAbnormalMessageset.h \
    ../../Module/UI/State/SmvAbnormal/SmvAbnormalParaset.h \
    ../../Module/UI/State/SmvAbnormal/SmvAbnormalPointset.h \
    ../../Module/UI/State/SmvAbnormal/SmvAbnormalQualityset.h \
    ../../Module/UI/IEC61850Config/SttIecSMV92InWidget.h \
    ../../Module/UI/Module/ScrollCtrl/ScrollListWidget.h \
    ../../Module/UI/IEC61850Config/Grid/IecCfgSmvData92InGrid.h \
    ../../Module/UI/IEC61850Config/Grid/IecCfgSmv92InChsGrid.h \
    ../../Module/UI/IEC61850Config/SttIecSysCfgWidget.h \
    ../../Module/UI/IEC61850Config/SttIecSysCfgChildWidget.h \
    ../../Module/UI/IEC61850Config/Grid/IecCfgFiberSetGrid.h \
    ../../Module/UI/IEC61850Config/Grid/IecCfgPrimRateGrid.h \
    ../../Module/UI/Manual/QSttMUTimeTestWidget.h \
    ../../Module/UI/Manual/QSttMUParasWidget.h \
    ../../Module/UI/Module/CharLibWidget/QCharInverseSet.h \
    ../../Module/UI/Module/ZKCharaCurve/QCharElementDlg.h \
    ../../Module/UI/Module/CharLibWidget/CharEditMainWidget.h \
    ../../Module/UI/Module/CharLibWidget/CharEditWidget_Distance.h \
    ../../Module/UI/Module/CharLibWidget/CharEditWidget_Inverse.h \
    ../../Module/UI/Module/CharLibWidget/CharEditWidget_Diff.h \
    ../../Module/UI/Module/CharLibWidget/CharEditWidget_Syn.h \
    ../../Module/UI/Module/CharLibWidget/CharEditWidget_None.h \
    ../../Module/UI/Module/ZKCharaCurve/QCIFeatureAddDig.h \
    ../../Module/UI/Module/CharLibWidget/CharEditWidgetBase.h \
    ../../Module/UI/TransPlay/SttReplayTriggerWidget.h \
    ../../Module/UI/TransPlay/SttReplayModuleChWidget.h \
    ../../Module/UI/TransPlay/SttReplayAdjustComboBox.h \
    ../../Module/UI/Module/WaveGraphWidget/QWaveGraphWidget.h \
    ../../Module/UI/Module/CommonCtrl_QT/QSttProgDlg.h \
    ../../Module/UI/Module/ScrollCtrl/ScrollTreeWidget.h \
    ../../Module/UI/Module/ScrollCtrl/ScrollCtrlInterface.h \
    ../../Module/UI/SCL/QSttSelSclFileWidget.h \
    ../../Module/UI/SCL/QSttSelSclFileDlg.h \
    ../../Module/UI/SCL/QSttSelSclIedWidget.h \
    ../../Module/UI/SCL/SttSelSclIedGrid.h \
    ../../Module/UI/SCL/SttSelSclFileGrid.h \
    ../../Module/UI/Module/DeviceInforDlg/DeviceAttrsGrid.h \
    ../../Module/UI/Module/DeviceInforDlg/QDeviceInforDlg.h \
    ../../Module/UI/Module/DeviceInforDlg/SttModuleAttrsGrid.h \
    ../../Module/UI/Module/DeviceInforDlg/SttModulesGrid.h \
    ../../Module/UI/Module/PopupDialog/SttFileDlgBase.h \
    ../../Module/UI/SttEventFilter/SttEventFilter.h \
    ../../Module/UI/Module/PopupDialog/SttPopupSaveAsDialog.h \
    ../../Module/UI/Module/PopupDialog/SttPopupOpenDialog.h \
    ../../Module/UI/Module/ModuleSetDlg/QModuleSetWidget.h \
    ../../Module/UI/Module/ModuleSetDlg/QModuleSetDlg.h \
    ../../Module/UI/Module/HardwareSetDlg/QHardwareSetDlg.h \
    ../../Module/UI/Module/CommonCtrl_QT/SttDiffCurrCalDlg.h \
    ../../Module/UI/State/StateBinarySetDlg.h \
    ../../Module/UI/State/StateTrigerWidget.h \
    ../../Module/UI/Gradient/GradientSettingDlg.h \
    ../../Module/UI/Manual/QSttManualBinBoutDlg.h \
    ../../Module/UI/Manual/SttMacroParaEditViewManual.h \
    ../../Module/UI/SequenceManu/SequenceManualWidget.h \
    ../../Module/UI/SequenceManu/SttMacroParaEditViewSequenceManu.h \
    ../../Module/UI/Gradient/GradientGroupWidget.h \
    ../../Module/UI/Gradient/GradientGroupGrid.h \
    ../../Module/UI/Module/PowerWidget/powerdiagramwidget.h \
    ../../Module/UI/State/StateEditDlg.h \
    ../../Module/UI/Harm/OscillogramGroupWidget.h \
    ../../Module/UI/Harm/OscillogramWidget.h \
    ../../Module/UI/Harm/PlotOscillogram.h \
    ../../Module/UI/Module/PopupDialog/SttFileMngrTool.h \
    ../../Module/UI/QSttInfWidgetBase.h \
    ../../Module/UI/Module/PowerWidget/QPowerDiagramWidgetImp.h \
    ../../Module/UI/Module/StateMonitor/QStateMonitorWidgetImp.h \
    ../../Module/UI/Module/ChannelParaSet/QBasicTestParaSetImp.h \
    ../../Module/UI/Module/DCOutput/QAuxDCOutputDlg.h \
    ../../Module/UI/Gradient/SttMacroParaEditViewGradient.h \
    ../../Module/UI/Module/CharLibWidget/QCharactWidgetForTest.h \
    ../../Module/UI/Module/CharLibWidget/QCharTestPointsGrid.h \
    ../../Module/UI/TransPlay/SttReplayParaSetWidget.h \
    ../../Module/UI/Module/CharLibWidget/QCharacteristicEditDlg.h \
    ../../Module/UI/Module/CharLibWidget/Grid/ImpCustomPointsGrid.h \
    ../../Module/UI/State/StateSettingValueDlg.h \
    ../../Module/UI/Module/LuminousPower/LuminousPowerDlg.h \
    ../../Module/UI/Module/LuminousPower/LuminousPowerGrid.h \
    ../../Module/UI/State/StateEstimateDlg.h \
    ../../Module/UI/Harm/InterharmonicsWidget.h \
    ../../Module/UI/IEC61850Config/SttIecSMVFT3InitValueSetDialog.h \
    ../../Module/UI/IEC61850Config/SttIecSMVFT3InMapSetDialog.h \
    ../../Module/UI/IEC61850Config/SttIecSMVFT3InWidget.h \
    ../../Module/UI/IEC61850Config/SttIecSMVFT3OtherSetDialog.h \
    ../../Module/UI/IEC61850Config/SttIecSMVFT3OutWidget.h \
    ../../Module/UI/IEC61850Config/Grid/IecCfgSmvFT3InChsGrid.h \
    ../../Module/UI/IEC61850Config/Grid/IecCfgSmvFT3OutChsGrid.h \
    ../../Module/UI/Module/CommonCtrl_QT/QDataTypeComboBox.h \
    ../../Module/UI/Gradient/GradientEstimateDlg.h \
    ../../Module/UI/Gradient/GradientSettingValueDlg.h \
    #sun ../../Module/UI/SOE/SttMacroParaEditViewSoeTable.h \
    #sun ../../Module/UI/SOE/SttMacroParaEditViewSoeWidget.h \
    ../../Module/UI/Module/FT3Widget/FT3OutParaWidget.h \
    ../../Module/UI/Module/FT3Widget/FT3OutSetDialog.h \
    ../../Module/UI/Module/FT3Widget/FT3OutWidget.h \
    ../../Module/UI/Module/FT3Widget/IecCfgFT3OutGrid.h \
    ../../Module/UI/IEC61850Config/SttIecConfigDialogLinux.h \
    ../../Module/UI/IEC61850Config/SttIecConfigDialogBase.h \
    ../../Module/UI/IEC61850Config/SttIecChsEditWidget.h \
    ../../Module/UI/Module/CharLibWidget/QCharEditRadioHarmWidget.h \
    ../../Module/UI/Module/CharLibWidget/QCharEditRadioNormalWidget.h \
    ../../Module/UI/Harm/HarmEstimateDlg.h \
    ../../Module/UI/Manual/ManualEstimateDlg.h \
    ../../Module/UI/SequenceManu/SequenceManualEstimateDlg.h \
    ../../Module/UI/SequenceGradient/SequenceGradientEstimateDlg.h \
    ../../Module/UI/SequenceGradient/SequenceGradientSettingDlg.h \
    ../../Module/UI/SequenceGradient/SequenceGradientWidget.h \
    ../../Module/UI/SequenceGradient/SttMacroParaEditViewSequenceGradient.h \
    ../../Module/UI/LineVolGradient/LineVolGradientGroupWidget.h \
    ../../Module/UI/LineVolGradient/SttMacroParaEditViewLineVolGradient.h \
    ../../Module/UI/LineVoltManu/LineVoltManualEstimateDlg.h \
    ../../Module/UI/LineVoltManu/LineVoltManualWidget.h \
    ../../Module/UI/LineVoltManu/SttMacroParaEditViewLineVoltManu.h \
    ../../Module/UI/LineVolGradient/LineVolGradientEstimateDlg.h \
    ../../Module/UI/IEC61850Config/Grid/SclCtrlSmvOutChsGrid.h \
    ../../Module/UI/IEC61850Config/Grid/SclCtrlGInChsGrid.h \
    ../../Module/UI/IEC61850Config/Grid/SclCtrlGoutChsGrid.h \
    ../../Module/UI/IEC61850Config/Grid/SclCtrlChsGridBase.h \
    ../../Module/UI/IEC61850Config/Grid/SclCtrlSmvInChsGrid.h \
    ../../Module/UI/IEC61850Config/Grid/QSclSelectCtrlsGrid.h \
    ../../Module/UI/IEC61850Config/SttIecSMVFT3DCOtherSetDialog.h \
    ../../Module/UI/IEC61850Config/Grid/IecCfgSMVFT3DCOtherSetGrid.h \
    ../../Module/UI/IEC61850Config/Grid/IecCfgSmvDataFT3Grid.h \
    ../../Module/UI/IEC61850Config/Grid/IecCfgSmvDataFT3InGrid.h \
    ../../Module/UI/MUAutoTest/SttMacroParaEditViewMuTreeWidget.h \
    ../../Module/UI/MUAutoTest/SttMacroParaEditViewMuAutoTest.h \
    ../../Module/UI/MUAutoTest/SttMacroParaEditViewOtherSetDlg.h \
    #sun ../../Module/UI/RemoteMeas/QRemoteMeasTable.h \
    #sun ../../Module/UI/RemoteMeas/RemoteMeasParaset.h \
    #sun ../../Module/UI/RemoteMeas/RemoteMeasParaTable.h \
    #sun ../../Module/UI/RemoteMeas/RemoteMeasRatWidget.h \
    #sun ../../Module/UI/RemoteMeas/RemoteMeasWidget.h \
    #sun ../../Module/UI/RemoteMeas/SttMacroParaEditViewRemoteMeas.h \
    ../../Module/UI/TerminalAutoTest/QTerminalSettingTabWidget.h \
    ../../Module/UI/TerminalAutoTest/QTerminalTabWidget.h \
    ../../Module/UI/TerminalAutoTest/QTerminalTreeWidget.h \
    ../../Module/UI/TerminalAutoTest/SttMacroParaEditViewTerminalAutoTest.h \
    ../../Module/UI/TerminalAutoTest/Grid/QTerminalGinDataChsGrid.h \
    ../../Module/UI/TerminalAutoTest/Grid/QTerminalGinDataGrid.h \
    ../../Module/UI/TerminalAutoTest/Grid/QTerminalGooseGrid.h \
    ../../Module/UI/TerminalAutoTest/Grid/QTerminalGoutDataChsGrid.h \
    ../../Module/UI/TerminalAutoTest/Grid/QTerminalGoutDataGrid.h \
    #sun ../../Module/UI/RemoteCtrl/RemoteCtrlBtnWidget.h \
    #sun ../../Module/UI/RemoteCtrl/RemoteCtrlTable.h \
    #sun ../../Module/UI/RemoteCtrl/SttMacroParaEditViewRemoteCtrl.h \
    ../../Module/UI/ShortTimeOver/QttMacroParaEditViewShortTimOver.h \
    ../../Module/UI/ShortTimeOver/ShortTimeOverGrid.h \
    ../../Module/UI/ShortTimeOver/ShortTimeOverGridImp.h \
    ../../Module/UI/IntelligentTerminal/IntellTerminalWidget.h \
    ../../Module/UI/IntelligentTerminal/SttMacroParaEditViewIntelligentTerminal.h \
    ../../Module/UI/Module/GooseParaWidget/SttIntelGoutToBinPubWidget.h \
    ../../Module/UI/Module/GooseParaWidget/SttIntelGoutToBinParaWidget.h \
    ../../Module/UI/Module/GooseParaWidget/SttIntelGoutToBinGrid.h \
    ../../Module/UI/Module/GooseParaWidget/SttIntelBoutToGinParaWidget.h \
    ../../Module/UI/Module/GooseParaWidget/SttIntelBoutToGinPubWidget.h \
    ../../Module/UI/Module/GooseParaWidget/SttIntelBoutToGinGrid.h \
    ../../Module/UI/Module/CommonCtrl_QT/Draw/QSttCustomArrowLine.h \
    ../../Module/UI/Module/CommonCtrl_QT/Draw/QSttCustomRect.h \
    ../../Module/UI/IEC61850Config/SCDView/SttSclIedDrawViewWidget.h \
    ../../Module/UI/IEC61850Config/SCDView/SttSclIedLineDialog.h \
    ../../Module/UI/IEC61850Config/SCDView/SttSclIedSketchMapWidget.h \
    #sun ../../Module/UI/Module/CommConfigurationDlg/CommCfg/QSttCommCfgMainDlg.h \
    #sun ../../Module/UI/Module/CommConfigurationDlg/CommCfg/SttCommCfgDeviceAttrsGrid.h \
    #sun ../../Module/UI/Module/CommConfigurationDlg/DevComm/QSttCommCfgDeviceDlg.h \
    #sun ../../Module/UI/Module/CommConfigurationDlg/DevComm/QSttCommCfgDeviceWidget.h \
    #sun ../../Module/UI/Module/CommConfigurationDlg/DevComm/SttDevCommTeleMeasureGrid.h \
    #sun ../../Module/UI/Module/CommConfigurationDlg/DevComm/SttDevCommTeleParaCommGrid.h \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PointTblFile/QSttCommCfgPointTblFileEditorDlg.h \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PointTblFile/QSttCommCfgPointTblFileImportDlg.h \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PointTblFile/SttCommCfgPointTblFileImportGrid.h \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PointTblFile/SttCommCfgPointTblFileImportTreeCtrl.h \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PointTblFile/SttPointTblEdtTabIntervalSetGrid.h \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PointTblFile/SttPointTblEdtTabTeleMeasureGrid.h \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PointTblFile/SttPointTblEdtTabTeleParaCommGrid.h \
    #sun ../../Module/UI/Module/CommConfigurationDlg/ProtocolTempl/QSttCommCfgProtocolTemplateDlg.h \
    #sun ../../Module/UI/Module/CommConfigurationDlg/ProtocolTempl/SttCommCfgProtocolTemplateGrid.h \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PkgMonitor/QSttCommCfgPkgMonitorDlg.h \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PkgMonitor/SttCommCfgPkgMonitorLeftGrid.h \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PkgMonitor/SttCommCfgPkgMonitorRightGrid.h \
    ../../Module/UI/VoltageTimeTypeSectorMode/QSttVoltageTimeGroupTestItemWidget.h \
    ../../Module/UI/FaultGradient/SttMacroParaEditViewFaultGradient.h \
    ../../Module/UI/FaultGradient/CFaultGradientSetting.h \
    ../../Module/UI/FaultGradient/FaultGradientEstimateDlg.h \
    ../../Module/UI/Module/FACommonSpyWidget/Grid/QSttFAStateSequenceGroupGrid.h \
    ../../Module/UI/Module/FACommonSpyWidget/Grid/QSttFATestResultViewGroupGrid.h \
    ../../Module/UI/Module/FAParasSetWidget/QSttFAParasSetDialog.h \
    ../../Module/UI/VoltageTimeTypeSectorMode/QSttMacroParaEditViewVolTimeTypeSec.h \
    #sun ../../Module/UI/Module/CommConfigurationDlg/PkgMonitor/QSttCommCfgPkgMonitorWidget.h \
    ../../../61850/Module/CfgDataMngr/IecCfgDatasMngr.h \
    ../../../61850/Module/CfgDataMngr/IecCfgGoutDatas.h \
    ../../../61850/Module/CfgDataMngr/IecCfgGoutData.h \
    ../../../61850/Module/CfgDataMngr/IecCfgGoutChs.h \
    ../../../61850/Module/CfgDataMngr/IecCfgGoutCh.h \
    ../../../61850/Module/CfgDataMngr/IecCfgGooseDataBase.h \
    ../../../61850/Module/CfgDataMngr/IecCfgGinDatas.h \
    ../../../61850/Module/CfgDataMngr/IecCfgGinData.h \
    ../../../61850/Module/CfgDataMngr/IecCfgGinChs.h \
    ../../../61850/Module/CfgDataMngr/IecCfgGinCh.h \
    ../../../61850/Module/CfgDataMngr/IecCfgDatasBase.h \
    ../../../61850/Module/CfgDataMngr/IecCfgDataMngrGlobal.h \
    ../../../61850/Module/CfgDataMngr/IecCfgDataGooseChBase.h \
    ../../../61850/Module/CfgDataMngr/IecCfgDataChBase.h \
    ../../../61850/Module/CfgDataMngr/IecCfgDataBase.h \
    ../../../61850/Module/CfgDataMngr/IecCfgChsBase.h \
    ../../../61850/Module/CfgDataMngr/IecCfg92Data.h \
    ../../../61850/Module/CfgDataMngr/IecCfg92ChsIn.h \
    ../../../61850/Module/CfgDataMngr/IecCfg92Chs.h \
    ../../../61850/Module/CfgDataMngr/IecCfgSMVDatas.h \
    ../../../61850/Module/CfgDataMngr/IecCfgSmvDataBase.h \
    ../../../61850/Module/CfgDataMngr/IecCfgGinAppChMaps.h \
    ../../../61850/Module/CfgDataMngr/IecCfgGinAppChMap.h \
    ../../../61850/Module/CfgDataMngr/IecCfg92ChQuality.h \
    ../../../61850/Module/CfgDataMngr/IecCfg92ChIn.h \
    ../../../61850/Module/CfgDataMngr/IecCfg92Ch.h \
    ../../../61850/Module/CfgDataMngr/IecCfg6044Ch.h \
    ../../../61850/Module/CfgDataMngr/IecCfg6044Chs.h \
    ../../../61850/Module/CfgDataMngr/IecCfg6044Data.h \
    ../../../61850/Module/CfgDataMngr/IecCfgDataSmvCommon.h \
    ../../../61850/Module/CfgDataMngr/IecCfg91Ch.h \
    ../../../61850/Module/CfgDataMngr/IecCfg91Chs.h \
    ../../../61850/Module/CfgDataMngr/IecCfg91Data.h \
    ../../../61850/Module/CfgDataMngr/IecCfgSmvRate.h \
    ../../../61850/Module/CfgDataMngr/IecCfgSmvRates.h \
    ../../../61850/Module/CfgDataMngr/IecCfgAdvanceException.h \
    ../../../61850/Module/CfgDataMngr/IecCfgDataSmvChBase.h \
    ../../../61850/Module/CfgDataMngr/IecCfg91StatusDataSet.h \
    ../../../61850/Module/CfgDataMngr/IecCfg91StatusDataSetCh.h \
    ../../../61850/Module/GlobalDataMngr/IecFiberConfig.h \
    ../../../61850/Module/GlobalDataMngr/IecGlobalDataMngr.h \
    ../../../61850/Module/GlobalDataMngr/IecGlobalDataMngrGlobal.h \
    ../../../61850/Module/GlobalDataMngr/IecGooseChDataTypeMngr.h \
    ../../../61850/Module/GlobalDataMngr/IecSmvChDataType.h \
    ../../../61850/Module/CfgDataMngr/IecCfgSysParas.h \
    ../../../61850/Module/CfgDataMngr/IecCfg6044CommonCh.h \
    ../../../61850/Module/CfgDataMngr/IecCfg6044CommonData.h \
    ../../../61850/Module/CfgDataMngr/IecCfg91StateWord.h \
    ../../../61850/Module/CfgDataMngr/IecCfg91StateWordBit.h \
    ../../../61850/Module/CfgDataMngr/IecCfg91StateWordMngr.h \
    ../../../61850/Module/CfgDataMngr/IecCfgFiberPara.h \
    ../../../61850/Module/CfgDataMngr/IecCfgFiberParas.h \
    ../../../61850/Module/CfgDataMngr/IecCfgPrimRate.h \
    ../../../61850/Module/CfgDataMngr/IecCfgPrimRates.h \
    ../../../61850/Module/CfgDataMngr/IecCfgSystemConfig.h \
    ../../../Module/OSInterface/QT/stdafx.h \
    ../../../Module/OSInterface/QT/XGlobalDefine_QT.h \
    ../../../Module/OSInterface/QT/CFile_QT.h \
    ../../../Module/OSInterface/QT/CString_QT.h \
    ../../../Module/OSInterface/QT/CTime_QT.h \
    ../../../Module/OSInterface/QT/CXArray_QT.h \
    ../../../Module/OSInterface/QT/CXCtrl_QT.h \
    ../../../Module/OSInterface/QT/CWinThread_QT.h \
    ../../../Module/OSInterface/QT/CXDraw_QT_NOGUI.h \
    ../../../Module/OSInterface/OSInterface.h \
    ../../../Module/OSInterface/QT/std_api_linux.h \
    ../../../Module/OSInterface/QT/CXCtrl_QT_CWinApp.h \
    ../../../Module/OSInterface/QT/CXCtrl_QT_CWnd.h \
    ../../../Module/OSInterface/QT/XMsgCycleBuffer.h \
    ../../../Module/MemBuffer/BufferBase.h \
    ../../../Module/MemBuffer/FormatTextBuffer.h \
    ../../../Module/MemBuffer/CycleMemBufferMngr.h \
    ../../../Module/MemBuffer/TCycleMemBuffer.h \
    ../../../Module/MemBuffer/ExpandMemBuf.h \
    ../../../Module/MemBuffer/StringToSystimeBuffer.h \
    ../../../Module/MemBuffer/CycleMemBuffer.h \
    ../../../Module/MemBuffer/EquationBuffer.h \
    ../../../Module/MemBuffer/EquationKey.h \
    ../../../Module/MemBuffer/XMemBufferBse.h \
    ../../../Module/BaseClass/TLinkList.h \
    ../../../Module/BaseClass/WSerializeBuff.h \
    ../../../Module/BaseClass/SerializeBufferBase.h \
    ../../../Module/BaseClass/BaseObject.h \
    ../../../Module/BaseClass/BinarySerialBuffer.h \
    ../../../Module/BaseClass/BinarySerialInterface.h \
    ../../../Module/BaseClass/ExBaseList.h \
    ../../../Module/BaseClass/ExBaseObject.h \
    ../../../Module/BaseClass/BaseList.h \
    ../../../Module/BaseClass/ComplexNumber.h \
    ../../../Module/BaseClass/StringSerializeBuffer.h \
    ../../../Module/BaseClass/TLinkList_DW.h \
    ../../../Module/BaseClass/XObjectRefBase.h \
    ../../../Module/API/StringApi.h \
    ../../../Module/Log/LogPrint.h \
    ../../../Module/API/GlobalConfigApi.h \
    ../../../Module/API/FileApi.h \
    ../../../Module/API/GlobalApi.h \
    ../../../Module/DataMngr/DataGroup.h \
    ../../../Module/DataMngr/DataMngrGlobal.h \
    ../../../Module/DataMngr/DataType.h \
    ../../../Module/DataMngr/DataTypes.h \
    ../../../Module/DataMngr/DataTypeValue.h \
    ../../../Module/DataMngr/DvmData.h \
    ../../../Module/DataMngr/DvmDataset.h \
    ../../../Module/DataMngr/DvmDevice.h \
    ../../../Module/DataMngr/DvmDevices.h \
    ../../../Module/DataMngr/DvmLog.h \
    ../../../Module/DataMngr/DvmLogicDevice.h \
    ../../../Module/DataMngr/DvmLogs.h \
    ../../../Module/DataMngr/DvmValue.h \
    ../../../Module/DataMngr/LogCtrl.h \
    ../../../Module/DataMngr/LogCtrls.h \
    ../../../Module/DataMngr/LongData.h \
    ../../../Module/DataMngr/LongDatas.h \
    ../../../Module/DataMngr/RptCtrl.h \
    ../../../Module/DataMngr/RptCtrls.h \
    ../../../Module/DataMngr/ShortData.h \
    ../../../Module/DataMngr/ShortDatas.h \
    ../../../Module/DataMngr/Value.h \
    ../../../Module/DataMngr/Values.h \
    ../../../Module/System/TickCount32.h \
    ../../../Module/System/StringTokenizer.h \
    ../../../Module/GpsPcTime/GpsPcTime.h \
    ../../../Module/xml/XmlRWBase.h \
    ../../../Module/xml/XmlRWFactory.h \
    ../../../Module/xml/XmlRW_Pugi.h \
    ../../../Module/xml/PugiXML/pugiconfig.hpp \
    ../../../Module/xml/PugiXML/pugixml.hpp \
    ../../../Module/API/HexTransApi.h \
    ../../../Module/Socket/WinBaseSocket.h \
    ../../../Module/Socket/WinTcpSocket.h \
    ../../../Module/Socket/WinTcpSocketClient.h \
    ../../../Module/Socket/WinTcpSocketServer.h \
    ../../../AutoTest/Module/Characteristic/CharacterArea.h \
    ../../../AutoTest/Module/Characteristic/CharacterFolder.h \
    ../../../AutoTest/Module/Characteristic/Characteristic.h \
    ../../../AutoTest/Module/Characteristic/CharacteristicLib.h \
    ../../../AutoTest/Module/Characteristic/Characteristics.h \
    ../../../AutoTest/Module/Characteristic/CharacteristicTmplate.h \
    ../../../AutoTest/Module/Characteristic/CharElement.h \
    ../../../AutoTest/Module/Characteristic/CharElementArc.h \
    ../../../AutoTest/Module/Characteristic/CharElementArcBase.h \
    ../../../AutoTest/Module/Characteristic/CharElementArcd.h \
    ../../../AutoTest/Module/Characteristic/CharElementArcp.h \
    ../../../AutoTest/Module/Characteristic/CharElementI2T.h \
    ../../../AutoTest/Module/Characteristic/CharElementIAC.h \
    ../../../AutoTest/Module/Characteristic/CharElementIEC.h \
    ../../../AutoTest/Module/Characteristic/CharElementIEEE.h \
    ../../../AutoTest/Module/Characteristic/CharElementInverse.h \
    ../../../AutoTest/Module/Characteristic/CharElementInvOwnDef.h \
    ../../../AutoTest/Module/Characteristic/CharElementLens.h \
    ../../../AutoTest/Module/Characteristic/CharElementLine.h \
    ../../../AutoTest/Module/Characteristic/CharElementLineBase.h \
    ../../../AutoTest/Module/Characteristic/CharElementLined.h \
    ../../../AutoTest/Module/Characteristic/CharElementLinep.h \
    ../../../AutoTest/Module/Characteristic/CharElementLiner.h \
    ../../../AutoTest/Module/Characteristic/CharElementMho.h \
    ../../../AutoTest/Module/Characteristic/CharElementTestLine.h \
    ../../../AutoTest/Module/Characteristic/CharElementTestPoint.h \
    ../../../AutoTest/Module/Characteristic/CharInterface.h \
    ../../../AutoTest/Module/Characteristic/CharInterfaceVariable.h \
    ../../../AutoTest/Module/Characteristic/CharTestLineDefine.h \
    ../../../Module/Expression/EpExpression.h \
    ../../../Module/Expression/EpExpressionGlobal.h \
    ../../../Module/Expression/EpExpressionTool.h \
    ../../../Module/DataMngr/DataMngrTrans.h \
    ../../../Module/Encrypt/XDes2.h \
    ../../../Module/XDrawBase/XDrawArc.h \
    ../../../Module/XDrawBase/XDrawBase.h \
    ../../../Module/XDrawBase/XDrawCircle.h \
    ../../../Module/XDrawBase/XDrawDataDef.h \
    ../../../Module/XDrawBase/XDrawElement.h \
    ../../../Module/XDrawBase/XDrawElements.h \
    ../../../Module/XDrawBase/XDrawGlobal.h \
    ../../../Module/XDrawBase/XDrawLine.h \
    ../../../Module/XDrawBase/XDrawList.h \
    ../../../Module/XDrawBase/XDrawMngr.h \
    ../../../Module/XDrawBase/XDrawMngrDescartes.h \
    ../../../Module/XDrawBase/XDrawMngrLogarithm.h \
    ../../../Module/XDrawBase/XDrawPoint.h \
    ../../../Module/XDrawBase/XDrawPolyline.h \
    ../../../Module/XDrawBase/XDrawViewBase.h \
    ../../../Module/Axis/AxisInterface.h \
    ../../../Module/Axis/DescartesAxis.h \
    ../../../Module/Axis/LogarithmAxis.h \
    ../../../Module/Axis/PolarAxis.h \
    ../../../Module/API/GloblaDrawFunctions.h \
    ../../../Module/StringCmp/StringCmp.h \
    ../../../Module/StringCmp/StringCmpBlock.h \
    ../../../Module/StringCmp/StringCmpBlocks.h \
    ../../../Module/API/MathApi.h \
    ../../../Module/Socket/SocketGlobal.h \
    ../../../Module/DataMngr/DvmDatasetGroup.h \
    ../../../Module/System/StringTokenizerU.h \
    ../../../Module/Socket/XPing.h \
    ../../../Module/XfileMngrBase/XFileFindEx.h \
    ../../../Module/XfileMngrBase/QT/XFileFindExImp.h \
    ../../../Module/FilterText/FilterText.h \
    ../../../Module/FilterText/FilterTextGlobal.h \
    ../../../Module/FilterText/FilterTextMngr.h \
    ../../../AutoTest/Module/Characteristic/CharacteristicGlobal.h \
    ../../../AutoTest/Module/Characteristic/CharacterDrawView.h \
    ../../../AutoTest/Module/Characteristic/CharMacroDraw.h \
    ../../../AutoTest/Module/Characteristic/CharMacroDrawLine.h \
    ../../../AutoTest/Module/Characteristic/CharMacroDrawPoint.h \
    ../../../AutoTest/Module/Characteristic/CharMacroDraws.h \
    #sun ../../../Protocol/Module/Engine/DeviceModel/DeviceClassIDDefine.h \
    #sun ../../../Protocol/Module/Engine/DeviceModel/DeviceModelXmlKeys.h \
    ../../../Module/Expression/ExprParse.h \
    ../../../Module/XDrawBase/XDrawLineEx.h \
    ../../../Module/XDrawBase/XDrawPointEx.h \
    ../../../Module/XDrawBase/XDrawText.h \
    ../../../Module/XLanguage/QT/XLanguageAPI_QT.h \
    ../../Module/SttTestSysGlobalPara.h \
    ../../../Module/xml/JsonRW.h \
    ../../../Module/xml/XmlRWInterface.h \
    ../../../Module/xml/JSON/CJSON.h \
    ../../../AutoTest/Module/AutoTestGlobalDefine.h \
    ../../../61850/Module/IecCfgSclTool/SclToIecCfgTool.h \
    ../../../61850/Module/SCL_Qt/QSclFileRead.h \
    ../../../61850/Module/SCL/SclIecCfgDatas.h \
    ../../../Module/API/StringConvert/String_Gbk_To_Utf8.h \
    ../../../Module/API/StringConvert/String_Utf8_To_Gbk.h \
    ../../../Module/BaseClass/QT/ExBaseListTreeCtrl.h \
    ../../../Module/BaseClass/ThreadProgressInterface.h \
../../../Module/Record/MR1200BaseApp.h  \
../../../Module/Record/RecordGlobalDefine.h  \
../../../Module/Record/RecordSysMsgDef.h  \
../../../Module/Record/RtTime.h  \
../../../Module/Record/Comtrade/ComtradeAnalogData.h  \
../../../Module/Record/Comtrade/ComtradeBinaryData.h  \
../../../Module/Record/Comtrade/ComtradeDataBase.h  \
../../../Module/Record/Comtrade/ComtradeFileGlobal.h  \
../../../Module/Record/Comtrade/ComtradeMngr.h  \
../../../Module/Record/Comtrade/ComtradeRateData.h  \
../../../Module/Record/DFT/DFT.h  \
../../../Module/Record/DFT/DFT_Long.h  \
../../../Module/Record/DFT/DFT_Short.h  \
../../../Module/Record/DFT/DFTBase.h  \
../../../Module/Record/Draw/DrawBase.h  \
../../../Module/Record/Draw/DrawGlobalDef.h  \
../../../Module/Record/Draw/DrawRangeStateAxis.h  \
../../../Module/Record/Draw/DrawTimeAxis.h  \
../../../Module/Record/Draw/DrawTimeAxisRange.h  \
../../../Module/Record/Draw/DrawAnalogComplexVariable.h  \
../../../Module/Record/Draw/DrawAnalogVariable.h  \
../../../Module/Record/Draw/DrawAnalogVariableCmp.h  \
../../../Module/Record/Draw/DrawAttrSpy.h  \
../../../Module/Record/Draw/DrawBinaryVariable.h  \
../../../Module/Record/Draw/DrawMultiPara.h  \
../../../Module/Record/Draw/DrawPara.h  \
../../../Module/Record/Draw/DrawParas.h  \
../../../Module/Record/Draw/DrawSysTime.h  \
../../../Module/Record/Draw/DrawTimeCursor.h  \
../../../Module/Record/Draw/DrawVariable.h  \
../../../Module/Record/Draw/RecordTestDrawBase.h  \
../../../Module/Record/Draw/ViewAnalyse.h  \
../../../Module/Record/Draw/XRecordDrawBase.h  \
../../../Module/Record/Draw/NameSort.h  \
../../../Module/Record/Draw/ParaSort.h  \
../../../Module/Record/RecordTest/CalFunctions.h  \
../../../Module/Record/RecordTest/RecordTest.h  \
../../../Module/Record/RecordTest/RecordTestCalThread.h  \
../../../Module/Record/RecordTest/RecordTestClassDef.h  \
../../../Module/Record/RecordTest/RtAllocBuffer.h  \
../../../Module/Record/RecordTest/RtAttrSpyConfig.h  \
../../../Module/Record/RecordTest/RtAttrSpyConfigs.h  \
../../../Module/Record/RecordTest/RtBinaryVariable.h  \
../../../Module/Record/RecordTest/RtBufferConfig.h  \
../../../Module/Record/RecordTest/RtCalFilterData.h  \
../../../Module/Record/RecordTest/RtCfgRecordTest.h  \
../../../Module/Record/RecordTest/RtCfgRecordTests.h  \
../../../Module/Record/RecordTest/RtCfgVariable.h  \
../../../Module/Record/RecordTest/RtCfgVariables.h  \
../../../Module/Record/RecordTest/RtChannel.h  \
../../../Module/Record/RecordTest/RtChannels.h  \
../../../Module/Record/RecordTest/RtComplexVariable.h  \
../../../Module/Record/RecordTest/RtDataAttribute.h  \
../../../Module/Record/RecordTest/RtDataAttributes.h  \
../../../Module/Record/RecordTest/RtFileWrite.h  \
../../../Module/Record/RecordTest/RtMultiVariable.h  \
../../../Module/Record/RecordTest/RtScript.h  \
../../../Module/Record/RecordTest/RtSet.h  \
../../../Module/Record/RecordTest/RtSets.h  \
../../../Module/Record/RecordTest/RtSingleVariable.h  \
../../../Module/Record/RecordTest/RtSpy.h  \
../../../Module/Record/RecordTest/RtStartup.h  \
../../../Module/Record/RecordTest/RtVariable.h  \
../../../Module/Record/RecordTest/RtVariables.h  \
../../../Module/Record/RecordTest/SystemSetAttr.h  \
../../../Module/Record/RecordTest/SystemSetsConfig.h  \
../../../Module/Record/RtMemBuffer/ComplexMemBuffer_UnsignedShort.h  \
../../../Module/Record/RtMemBuffer/MemBuffer.h  \
../../../Module/Record/RtMemBuffer/MemBuffer_CPoint.h  \
../../../Module/Record/RtMemBuffer/MemBuffer_Double.h  \
../../../Module/Record/RtMemBuffer/MemBuffer_Float.h  \
../../../Module/Record/RtMemBuffer/MemBuffer_Long.h  \
../../../Module/Record/RtMemBuffer/MemBuffer_UnsignedShort.h  \
../../../Module/Record/RtMemBuffer/MemBufferDef.h  \
../../../Module/Record/RtMemBuffer/RtMemBufferChannel.h  \
../../../Module/Record/RtMemBuffer/RtMemBufferMngr.h  \
../../../Module/Record/RtMemBuffer/RtMemBufScript.h  \
../../../Module/Record/RtScriptBase/RtScriptBase.h  \
../../../Module/Record/FFT/FFT.h  \
../../../Module/Record/FFT/FFTEx.h  \
../../../Module/Record/Algorithm/AlgorithmAPI.h  \
../../../Module/SmartCap/61850Cap/CapGlobalDef.h  \
../../../Module/SmartCap/SmartCapCtrl.h  \
../../../Module/SmartCap/61850Cap/SttRcdComtradeFileWrite.h  \
../../../Module/SmartCap/X61850CapBase.h  \
../../../Module/SmartCap/XSmartCapInterface.h  \
../../../Module/SmartCap/XSmartCapMngr.h  \
../../../Module/SmartCap/XSttCap_61850.h  \
../../../Module/SmartCap/XSttIecfgDataEdit.h  \
../../../Module/SmartCap/61850Cap/ProtocolBase/FrameMemBuffer.h  \
../../../Module/SmartCap/61850Cap/ProtocolBase/Protocol61850Analysis.h  \
../../../Module/SmartCap/61850Cap/ProtocolBase/ProtocolGlobalDef.h  \
../../../Module/SmartCap/61850Cap/ProtocolBase/61850ParseFrameList.h  \
../../../Module/SmartCap/61850Cap/ProtocolBase/BbInffor.h  \
../../../Module/SmartCap/61850Cap/ProtocolBase/ByteBlock.h  \
../../../Module/SmartCap/61850Cap/ProtocolBase/FrameBase.h  \
../../../Module/SmartCap/61850Cap/ProtocolBase/FrameBaseList.h  \
../../../Module/SmartCap/61850Cap/ProtocolBase/FrameDetail.h  \
../../../Module/SmartCap/61850Cap/ProtocolBase/61850FrameBase.h  \
../../../Module/SmartCap/61850Cap/ProtocolBase/91Frame.h  \
../../../Module/SmartCap/61850Cap/ProtocolBase/92Frame.h  \
../../../Module/SmartCap/61850Cap/ProtocolBase/GooseFrame.h  \
../../../Module/SmartCap/61850Cap/ProtocolBase/Protocol61850.h  \
../../../Module/SmartCap/61850Cap/ProtocolBase/ProtocolBase.h  \
../../../Module/SmartCap/61850Cap/ProtocolBase/SmvFrameBase.h  \
../../../Module/SmartCap/61850Cap/ProtocolBase/Stt/SttFrameMemBufferMngr.h  \
../../../Module/SmartCap/61850Cap/ProtocolBase/Stt/SttRcdMemBufferMngr.h  \
../../../Module/SmartCap/61850Cap/CapThreadBase.h  \
../../../Module/SmartCap/61850Cap/SttCapThread.h  \
../../../Module/SmDb/XSmMemBuffer.h  \
../../../Module/SmDb/XSmMemBufferMngr.h  \
../../../Module/SmartCap/61850Cap/Record/CapDeviceChRecordMngr.h  \
../../../Module/SmartCap/61850Cap/Record/CapViewAnalyse.h  \
../../../Module/SmartCap/61850Cap/CapDevice/CapDeviceGlobal.h  \
../../../Module/SmartCap/61850Cap/CapDevice/CapDeviceMngr.h  \
../../../Module/SmartCap/61850Cap/CapDevice/CapDeviceChBase.h  \
../../../Module/SmartCap/61850Cap/CapDevice/CapDeviceGooseCh.h  \
../../../Module/SmartCap/61850Cap/CapDevice/CapDeviceSmvCh.h  \
../../../Module/SmartCap/61850Cap/CapDevice/CapDevice91.h  \
../../../Module/SmartCap/61850Cap/CapDevice/CapDevice92.h  \
../../../Module/SmartCap/61850Cap/CapDevice/CapDeviceBase.h  \
../../../Module/SmartCap/61850Cap/CapDevice/CapDeviceGoose.h  \
../../../Module/SmartCap/61850Cap/CapDevice/CapDeviceSmvBase.h \
    ../../../Module/OSInterface/QT/CXDraw_QT.h \
    ../../../Module/OSInterface/XWndInterface.h \
    ../../../Module/Axis/RulerAxis.h \
    ../../../61850/Module/CfgDataMngr/IecCfgDevice.h \
    ../../../Module/BaseClass/ExBaseCycleArray.h \
    ../../../Module/System/VariantData.h \
    ../../../Module/SmartCap/XSttRcdInitChDvmData.h \
    ../../../Module/BaseClass/QT/ExBaseListComboBox.h \
    ../../../Module/SmartCap/61850Cap/CapDevice/CapAnalysisConfig.h \
    ../../../Module/SmartCap/XIecDatasetSmartMatch.h \
    ../../../Module/KeyDb/KeyDbGlobal.h \
    ../../../Module/KeyDb/XKeyBase.h \
    ../../../Module/KeyDb/XKeyDB.h \
    ../../../Module/KeyDb/XKeyGroupBase.h \
    ../../../Module/KeyDb/XKeyRef.h \
    ../../../Module/KeyDb/XKeyStringParser.h \
    ../../../Module/KeyDb/XMatchConfig.h \
    ../../../Module/KeyDb/XMatchDataref.h \
    ../../../Module/KeyDb/XMatchDatarefs.h \
    ../../../Module/KeyDb/XMatchDatasetRef.h \
    ../../../Module/KeyDb/XMatchDatasetRefs.h \
    ../../../Module/KeyDb/XMatchList.h \
    ../../../Module/KeyDb/XMatchObject.h \
    ../../../Module/KeyDb/XMatchToolBase.h \
    ../../../Module/KeyDb/XMultiKeyBase.h \
    ../../../61850/Module/AT02DTool/AT02D_Tool.h \
    ../../../Module/Axis/MeterAxis.h \
    ../../../Module/SmartCap/XSmartCapFileWrite.h \
    ../../../Module/XfileMngrBase/XFile.h \
    ../../../Module/XfileMngrBase/XFileMngr.h \
    ../../../Module/XfileMngrBase/XFolder.h \
    ../../../Module/XfileMngrBase/XFileType.h \
    ../../../Module/XfileMngrBase/XFileTypes.h \
    ../../../61850/Module/CfgDataMngr/IecCfgPrimRatesIn.h \
    ../../../61850/Module/CfgDataMngr/IecCfg92InData.h \
    ../../../61850/Module/CfgDataMngr/IecCfgSmvInDatas.h \
    ../../../61850/Module/CfgDataMngr/IecCfg2MData.h \
    ../../../AutoTest/Module/Characteristic/QT/SttCharacterDrawPng.h \
    ../../../AutoTest/Module/Characteristic/SttCharacterDrawForTest.h \
    ../../../AutoTest/Module/Characteristic/XCharElementTestPoints.h \
    ../../../AutoTest/Module/Characteristic/CharElementTestLines.h \
    ../../../61850/Module/CfgDataMngr/IecCfg2MInData.h \
    ../../../Module/FaultCal/DiffCharCal.h \
    ../../../Module/QT/Png64/DrawPngBase64.h \
    #sun ../../../IotAtsMngr/Module/ProtocolBase/PxProtocolImpInterface.h \
    #sun ../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineServer.h \
    #sun ../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineInterface.h \
    #sun ../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineFactoryMngr.h \
    #sun ../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineFactoryBase.h \
    #sun ../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineDeviceMngr.h \
    #sun ../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineDeviceBase.h \
    #sun ../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineDeviceWnd.h \
    #sun ../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineDeviceWnd_Linux.h \
    ../../../AutoTest/Module/Characteristic/CharElementUIVP.h \
    ../../../61850/Module/CfgDataMngr/IecCfg6044CommonChIn.h \
    ../../../61850/Module/CfgDataMngr/IecCfg6044CommonInData.h \
    #sun ../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineServerWnd.h \
    #sun ../../../IotAtsMngr/Module/PxEngineServer/IotPxEngineServerWnd_Linux.h \
    #sun ../../../IotProtoServer/Module/SttPxCommCmdDef.h \
    ../../../Module/BaseClass/XTimer.h \
    ../../../61850/Module/SCL/SclFileMngr/XSclFileMngr.h \
    ../../../61850/Module/SCL/SclFileMngr/SclFileMngrGlobal.h \
    ../../../61850/Module/SCL/SclFileMngr/XSclFileObj.h \
    ../../../61850/Module/SCL_Qt/QScdFileRWDlg.h \
    ../../../Module/DataMngr/DvmValues.h \
    ../../../Module/API/StringConvertApi.h \
    #sun ../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbWzdAi/GbWzdAiParasBase.h \
    #sun ../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbWzdAi/GbWzdAiBase.h \
    #sun ../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbWzdAi/GbWzdAiDO.h \
    #sun ../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbWzdAi/GbWzdAiKeysFunc.h \
    #sun ../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbWzdAi/GbWzdAiMacroPara.h \
    #sun ../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbWzdAi/GbWzdAiOptr.h \
    #sun ../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbWzdAi/GbWzdAiScript.h \
    #sun ../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbWzdAi/GbWzdAiSwitch.h \
    #sun ../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbWzdAi/GbWzdAiTool.h \
    #sun ../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbSmartGenWzdGlobal.h \
    ../../../Module/Expression/XExprBase.h \
    ../../../Module/Expression/XExprCmp.h \
    ../../../Module/Expression/XExprError.h \
    ../../../Module/Expression/XExprGlobal.h \
    ../../../Module/Expression/XExprNode.h \
    ../../../Module/Expression/XExprRange.h \
    ../../../Module/Expression/XExprValue.h \
    ../../../Module/Expression/XExprValue_Ex.h \
    ../../../Module/Expression/XExprValueCal.h \
    ../../../Module/TestMacro/TestMacro.h \
    ../../../Module/TestMacro/TestMacroGlobal.h \
    ../../../Module/TestMacro/TestMacros.h \
    ../../../Module/TestMacro/TmFaultParas.h \
    ../../../Module/TestMacro/TmFaultParasEx.h \
    ../../../Module/TestMacro/TmResultParas.h \
    ../../../Module/TestMacro/TmResultParasEx.h \
    ../../../Module/TestMacro/TmSysParas.h \
    ../../../Module/Socket/WinUdpScoket.h \
    ../../../AutoTest/Module/Characteristic/CharElementIUF.h \
    ../../../Module/Expression/XExprErrorCombined.h \
    ../../../Module/Expression/XExprErrorEx.h \
    ../../../Module/Expression/XExprValueCalEx.h \
    ../../../61850/Module/CfgDataMngr/IecCfgFiberParasIn.h \
    ../../../Module/Expression/XExprCal.h \
    ../../../Module/DataMngr/DvmCmp/DvmCmpKeyDataTypes.h \
    ../../../61850/Module/61850ClientConfig/61850ClientCfgMngrGlobal.h \
    ../../../61850/Module/61850ClientConfig/61850ClientConfig.h \
    ../../../61850/Module/61850ClientConfig/RemoteDev.h \
    ../../../61850/Module/61850ClientConfig/RemoteDevs.h \
    ../../../AutoTest/Module/Characteristic/CharElementDCOverLoad.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Cell.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Col.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_ColDef.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_ColsDef.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Enable.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Grid.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_GridDef.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_GuideBook.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Head.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Items.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_MacroCharItems.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_MacroTest.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Png.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_PngDef.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Reports.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_ReportsDef.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_ReportTemplate.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_ReportTemplateDef.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Row.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_RowDef.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_RowsDef.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Rpeort.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_RpeortDef.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_TestMacroUiRpt.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_TestMacroUiRptDef.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Text.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_TextDef.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Title.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_TitleDef.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Value.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_ValueDef.h \
    ../../../AutoTest/Module/TestMacroRptTemplate/TestMacroRptTemplateGlobal.h \
    ../../../Module/SmartCap/61850Cap/CapDevice/CapDevice6044.h \
    ../../../Module/OSInterface/QT/CDateTime_QT.h \
    ../../../Protocol/Module/PxiEngine/PxiDeviceCommCmdMessage.h \
    #sun ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Group.h \
    #sun ../../../AutoTest/Module/TestMacroRptTemplate/RptTemp_Data.h \
    ../../../Module/SmartCap/61850Cap/ProtocolBase/6044Frame.h \
    ../../../Module/xml/XPugiXML/xpugiconfig.hpp \
    ../../../Module/xml/XPugiXML/xpugixml.hpp \
    #sun ../../Module/HtmlReport/IECTest/SttHtmlRptGen_TerminalAuto.h \
    ../../Module/UI/Controls/SttGroupBox.h \
    #sun ../../Module/UI/AntiShakeTime/QSttMacroParaEditViewAntiShakeTime.h \
    #sun ../../Module/UI/AntiShakeTime/Grid/QSttAntiShakeTimeTestItemsGroupGrid.h \
    #sun ../../Module/UI/AntiShakeTime/Grid/QSttAntiShakeTimeDinEventGroupGrid.h \
    #sun ../../Module/HtmlReport/IECTest/SttHtmlRptGen_ShortTimeOver.h \
    ../../Module/UI/Module/ScrollCtrl/ScrollSlider.h \
    ../../../61850/Module/SCL/CcdFileRead.h \
    ../../Module/UI/TransPlay/SttReplayWaveformEditWidget.h \
    ../../Module/RecordTest/UI/SttIecSmvGrid_HarmAnalyze.h \
    ../../Module/UI/ADMUAccurAutoTest/ADMUAccurAutoTestParasSetDialog.h \
    ../../Module/UI/ADMUAccurAutoTest/SttMacroParaEditViewADMUAccurAutoTest.h \
    ../../Module/UI/PowerManu/ManualView_PV.h \
    ../../Module/UI/PowerManu/PowerManualEstimateDlg.h \
    ../../Module/UI/PowerManu/PowerManualGrid.h \
    ../../Module/UI/PowerManu/PowerManualGridImp.h \
    ../../Module/UI/PowerManu/PowerManualWidget.h \
    ../../Module/UI/PowerManu/SttMacroParaEditViewPowerManu.h \
    ../../Module/UI/CBOperate/QSttMacroParaEditViewCBOperate.h \
    ../../Module/UI/CBOperate/Grid/CBOperateResultAssessGrid.h \
    ../../Module/UI/CBOperate/Dlg/CBOperateCommonParasDlg.h \
    ../../Module/UI/Module/ChannelParaSet/channelpowertable.h \
    ../../Module/TestUI/Distance/DistanceAddMultDlg.h \
    ../../Module/TestUI/Distance/DistanceBinarysDlg.h \
    ../../Module/TestUI/Distance/DistanceCommonParasDlg.h \
    ../../Module/TestUI/Distance/DistanceItemParaEditWidget.h \
    ../../Module/TestUI/Distance/DistanceResultEstimateDlg.h \
    ../../Module/TestUI/Distance/SttMultiMacroDistanceParasDefine.h \
    ../../Module/TestUI/Distance/SttMultiMacroParaEditViewDistance.h \
    ../../Module/TestUI/Module/CommonGrid/QSttMacroParaEditGrid.h \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdColDef.h \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdColDef_Fuc_Avg.h \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdColDef_Fuc_Max.h \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdColDef_Fuc_Min.h \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdColDef_Para.h \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdColDef_Script.h \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdColDef_TextComb.h \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdCondition.h \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdDataCal.h \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdDataProcess.h \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdGridDefine.h \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdGridInst.h \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdGridInsts.h \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdInst_Col.h \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdInst_Cols.h \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdParaCondition.h \
    ../../Module/TestUI/Module/SttTestGridDefine/SttGdTestMacro.h \
    ../../Module/TestUI/Module/SttTestGridDefine/SttTestGridDefine.h \
    ../../Module/TestUI/Module/SttTestGridDefine/SttTestGridDefineGlobal.h \
    ../../Module/TestUI/QSttMultiMacroParaEditViewBase.h \
    ../../Module/TestUI/Interface/QItemParaEditWidgetBase.h \
    ../../Module/SttTest/Common/Power/tmt_power_manu_test.h \
    ../../Module/UI/ImpedanceManu/ImpedanceManuEstimateDlg.h \
    ../../Module/UI/ImpedanceManu/ImpedanceManuWidget.h \
    ../../Module/UI/ImpedanceManu/SttMacroParaEditViewImpedanceManu.h \
    ../../Module/SttTest/Common/Impedance/tmt_manuImped_test.h \
    ../../Module/UI/TransPlay/SttReplayBoutModuleChWidget.h \
    ../../Module/UI/TransPlay/SttReplayDigitalMoudleWidget.h \
  #  ../../Module/UI/TransPlay/SttReplayWeekModuleChWidget .h
    ../../Module/UI/TransPlay/SttReplayWeekModuleChWidget.h \
    ../../../Module/Expression/XExprRangeEx.h

FORMS += \
    ../../Module/Assist/MU/SttAssistIecCbSelWidget.ui \
    ../../Module/Assist/DynEffect/QSttAssistMsgWidget.ui \
    ../../Module/Assist/DynEffect/QSttAssistTipsShowWidget.ui \
    ../../Module/Assist/QSttAssistMenuWidget.ui \
    #sun ../../Module/SmartTestInterface/QT/PpSttIotEngineClientWidget.ui \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/ppcommconfigdlg.ui \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommcfgtcpclientdlg.ui \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommconfigcmsdlg.ui \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommconfigmmsdlg.ui \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommconfigserialmode.ui \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommconfigtcpserverdlg.ui \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommconfigudpclientdlg.ui \
    #sun ../../Module/SmartTestInterface/QT/CommConfigWidget/qcommconfigudpserver.ui \
    ../../Module/RecordTest/UI/SttIecRecordMainWidget.ui \
    ../../Module/RecordTest/UI/SttIecRecordCbWidget.ui \
    ../../Module/RecordTest/UI/SttIecRecordWriteFileWidget.ui \
    ../../Module/RecordTest/UI/SttIecRecordDetectWidget.ui \
    ../../Module/UI/Controls/SttAddMacroWidget.ui \
    ../../Module/UI/Controls/SttOutPutWidget.ui \
    ../../Module/UI/Controls/SttReportHeadSetDlg.ui \
    ../../Module/UI/Controls/SttFileSaveAsDlg.ui \
    ../../Module/UI/Controls/SttCustomSetDlg.ui \
    ../../Module/UI/Controls/NetworkConfig/qnetworkconfigwidget.ui \
    ../../Module/UI/Module/ZKCharaCurve/QCIFeatureAddDig.ui \
    ../../Module/UI/Module/ZKCharaCurve/QZKFeatureAddDig.ui \
    ../../Module/UI/Module/ZKCharaCurve/ZKFeatureDig.ui \
    ../../Module/UI/State/GooseAbnormal/GooseAbnormalParaset.ui \
    ../../Module/UI/State/SmvAbnormal/SmvAbnormalChannelSelect.ui \
    ../../Module/UI/State/SmvAbnormal/SmvAbnormalMessageset.ui \
    ../../Module/UI/State/SmvAbnormal/SmvAbnormalParaset.ui \
    ../../Module/UI/State/SmvAbnormal/SmvAbnormalPointset.ui \
    ../../Module/UI/State/SmvAbnormal/SmvAbnormalQualityset.ui \
    ../../Module/UI/Module/CharLibWidget/QCharInverseSet.ui \
    ../../Module/UI/Module/CharLibWidget/CharEditMainWidget.ui \
    ../../Module/UI/Module/CharLibWidget/CharEditWidget_Distance.ui \
    ../../Module/UI/Module/CharLibWidget/CharEditWidget_Inverse.ui \
    ../../Module/UI/Module/CharLibWidget/CharEditWidget_Diff.ui \
    ../../Module/UI/Module/CharLibWidget/CharEditWidget_Syn.ui \
    ../../Module/UI/Gradient/GradientSettingDlg.ui \
    ../../Module/UI/Manual/QSttManualBinBoutDlg.ui \
    ../../Module/UI/Manual/SttMacroParaEditViewManual.ui \
    ../../Module/UI/Gradient/SttMacroParaEditViewGradient.ui \
    #sun ../../Module/SmartTestInterface/QT/qsttmmsbrcbctrlwidget.ui \
    #sun ../../Module/SmartTestInterface/QT/qsttzoneindexsetdlg.ui \
    ../../Module/UI/Module/CharLibWidget/QCharEditRadioHarmWidget.ui \
    ../../Module/UI/Module/CharLibWidget/QCharEditRadioNormalWidget.ui \
    ../../Module/UI/SequenceGradient/SequenceGradientSettingDlg.ui \
    ../../Module/UI/SequenceGradient/SttMacroParaEditViewSequenceGradient.ui \
    ../../Module/UI/ShortTimeOver/QttMacroParaEditViewShortTimOver.ui \
    ../../Module/UI/VoltageTimeTypeSectorMode/QSttVoltageTimeGroupTestItemWidget.ui \
    ../../Module/UI/FaultGradient/SttMacroParaEditViewFaultGradient.ui \
    ../../Module/UI/FaultGradient/FaultGradientEstimateDlg.ui \
    ../../Module/UI/FaultGradient/CFaultGradientSetting.ui \
    ../../Module/UI/Module/FAParasSetWidget/QSttFAParasSetDialog.ui \
    ../../Module/UI/SoftKeyboard/Keyboard/Keyboard.ui \
    ../../Module/UI/TransPlay/SttReplayWaveformEditWidget.ui \
    ../../Module/TestUI/Distance/DistanceAddMultDlg.ui \
    ../../Module/TestUI/Distance/DistanceBinarysDlg.ui \
    ../../Module/TestUI/Distance/DistanceCommonParasDlg.ui \
    ../../Module/TestUI/Distance/DistanceItemParaEditWidget.ui \
    ../../Module/TestUI/Distance/DistanceResultEstimateDlg.ui \
    ../../Module/UI/TransPlay/SttReplayBoutModuleChWidget.ui \
    ../../Module/UI/TransPlay/SttReplayParaSetWidget.ui

RESOURCES += \
    TestCtrlCntrLinux.qrc
