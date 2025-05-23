#include "SttTestCntrFrameBase.h"
#include "Module/DeviceInforDlg/QDeviceInforDlg.h"
//2022-12-02 修改功能ID，导致所有的都要编译，效率低下，所以从头文件中去掉，在任何需要包含的地方进行包含
#include "SttTestCntrCmdDefine.h" 

#include "State/SttMacroParaEditViewState.h"
#include "State/GooseAbnormal/SttMacroParaEditViewGooseAbnormal.h"
//sun #include "../../../Protocol/Module/Engine/DeviceModel/DeviceModelXmlKeys.h"
#include "../SttSystemConfig/SttSystemConfigGlobal.h"
#include "../SttTestResourceMngr/TestResource/SttTestResource_Sync.h"
#include "../SttSocket/SttCmdOverTimeMngr.h"
#include "../SttCmd/SttSysState.h"
#include "../SttCmd/SttTestCmd.h"
#include "../../../AutoTest/Module/AutoTestGlobalDefine.h"
#include "../SttSystemConfig/SttSystemConfig.h"
#include "Controls/SttFileSaveAsDlg.h"
#include "Module/PopupDialog/SttPopupOpenDialog.h"
#include "../../../Module/OSInterface/QT/XMessageBox.h"
#include "../../../Module/SmartCap/XSmartCapMngr.h"
#include "../SttCmd/GuideBook/SttItemStateObject.h"
#include "../SttTestCtrl/SttTestCtrlCntrNative.h"
#include "Manual/SttMacroParaEditViewManual.h"
#include "../../Module/UI/Controls/SttCustomSetDlg.h"
#include "Module/ModuleSetDlg/QModuleSetDlg.h"
#include "Controls/FileMngr/SttFileMngrDlg.h"
#include "Module/PopupDialog/SttFileMngrTool.h"
#include "Module/LuminousPower/LuminousPowerDlg.h"
#include "../../../SttStudio/Module/SttTest/Common/tmt_replay_test.h"
#include "../XLangResource_Native.h"
#include "../RecordTest/UI/SttIecCapDialog.h"
#include "../UI/Interface/SttHtmlViewApi.h" //sun
#ifndef _PSX_QT_LINUX_
#include "Module/SysParas/QSysParasDlg.h"
#endif

#ifdef _PSX_QT_LINUX_
#include "IEC61850Config/SttIecConfigDialogLinux.h"
#else
#include "IEC61850Config/SttIecConfigDialogWin.h"
#endif

#ifdef _USE_SoftKeyBoard_	
#include "SoftKeyboard/SoftKeyBoard.h"
#endif

#ifndef _NOT_USE_SttTestCntrThread_
#include "SttTestCntrThread.h"
#endif

#include "Module/PopupDialog/SttPopupSaveAsDialog.h"
#include "Module/HardwareSetDlg/QHardwareSetDlg.h"

#ifndef NOT_USE_ASSIST
#include "../Assist/DynEffect/SttAssistWndDynEffExecTool.h"
#endif
#include "Controls/SafetyMsgCfg/SttSafetyMsgCfgGlobal.h"

//sun #include "../UI/Module/CommConfigurationDlg/CommCfg/QSttCommCfgMainDlg.h"
//sun #include "../UI/Module/CommConfigurationDlg/DevComm/QSttCommCfgDeviceDlg.h"
//sun #include "../UI/Module/CommConfigurationDlg/ProtocolTempl/QSttCommCfgProtocolTemplateDlg.h"
//sun #include "../UI/Module/CommConfigurationDlg/PointTblFile/QSttCommCfgPointTblFileImportDlg.h"
//sun #include "Module/CommConfigurationDlg/PkgMonitor/QSttCommCfgPkgMonitorDlg.h"
#include "../RecordTest/UI/MUTest/SttMUTestIecCbSelWidget.h"
#include "../RecordTest/UI/MUTest/SttIecRecordCbInterface.h"

QSttTestCntrFrameBase *g_theTestCntrFrame = nullptr;
double g_dUIShowCoef = 1.0f; // 界面显示缩放比例

// bool g_bIsOpenMacroFromMain = FALSE;
CDataGroup *g_pGlobalDatas = nullptr;

BOOL QSttTestCntrFrameBase::HasManuTrigerBtn()
{
    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return FALSE;
	}

	CSttMacroTestUI_TestMacroUI *pTestMacroUI = g_pTheSttTestApp->m_pTestMacroUI;

	if (pTestMacroUI->m_strID == STT_ORG_MACRO_StateTest)
	{
		return TRUE;
	}
	else if (pTestMacroUI->m_strID == STT_ORG_MACRO_SmvAbnTest)
	{
		return TRUE;
	}
	else if (pTestMacroUI->m_strID == STT_ORG_MACRO_GseAbnTest)
	{
		return TRUE;
	}
	else if (pTestMacroUI->m_strID == STT_ORG_MACRO_ReplayTest)
	{
		return TRUE;
	}
	else if (pTestMacroUI->m_strID == STT_HTML_MACRO_ZeroTest)
	{
		return TRUE;
	}
	else if (pTestMacroUI->m_strID == STT_HTML_MACRO_DistanceTest)
	{
		return TRUE;
	}
	else if (pTestMacroUI->m_strID == STT_HTML_MACRO_OverCurrentTest)
	{
		return TRUE;
	}
	else if (pTestMacroUI->m_strID == STT_HTML_MACRO_RecloseAccTest)
	{
		return TRUE;
	}
	else if (pTestMacroUI->m_strID == STT_ORG_MACRO_CBOperateTest)
	{
		return TRUE;
	}

	return FALSE;
}

BOOL QSttTestCntrFrameBase::IsManuTriger_HtmlFaultTrigMode()
{
    if (m_pTestMacroUI_Paras == nullptr)
	{
		return FALSE;
	}

	CDvmData *pDvmData = (CDvmData*)m_pTestMacroUI_Paras->FindByID("FaultTrigMode");

    if (pDvmData == nullptr)
	{
		return FALSE;
	}

	long nFaultTrigMode = CString_To_long(pDvmData->m_strValue);

	if (nFaultTrigMode == 1)
	{
		return TRUE;
	}

	return FALSE;
}

BOOL QSttTestCntrFrameBase::IsMenuBtn(QWidget *pWidget)
{
    if (m_pMenu_FrameButton == nullptr)
	{
        if (m_pSttFrameConfig != nullptr)
		{
			CSttFrame_ToolBar *pToolBarParas = m_pSttFrameConfig->GetToolBar();

            if (pToolBarParas != nullptr)
			{
				m_pMenu_FrameButton = pToolBarParas->FindBtnByID(_T("Menu"));
			}
		}
		
        if (m_pMenu_FrameButton == nullptr)
		{
			return FALSE;
		}
	}

	return (m_pMenu_FrameButton->m_dwItemData == (DWORD)pWidget);
}

BOOL QSttTestCntrFrameBase::IsMenuWidget(QWidget *pWidget)
{
	return FALSE;
}

BOOL QSttTestCntrFrameBase::SetValues_dsRcdStep6U6I(BOOL bClearResult)
{
// 	if (!g_bSmartCap_RecordNow)
// 	{
// 		return FALSE;
// 	}

    if ((g_pTheSttTestApp->m_pTestMacroUI == nullptr)||(m_pMacroEditView == nullptr))
	{
		return FALSE;
	}

	if (g_pTheSttTestApp->IsMuTest())
	{
		CXSttCap_61850 *pXSttCap_61850 = CXSmartCapMngr::GetSttCap61850_Global();

        if (pXSttCap_61850 == nullptr)
		{
			return FALSE;
		}

		CDvmDataset *pDsRcdStep6U6I = pXSttCap_61850->AddDataset_dsRcdStep6U6I();
		BOOL bRet = FALSE;

		if (g_pTheSttTestApp->m_pTestMacroUI->IsUIOriginal())
		{
			bRet = ((CSttMacroParaEditViewOriginal*)m_pMacroEditView)->SetValues_dsRcdStep6U6I(pDsRcdStep6U6I);
		}
		
		pXSttCap_61850->UpdateUI_Paras(bRet);

		if (bClearResult)
		{
			pXSttCap_61850->ClearMUTestResults();
		}

		return bRet;
	}
	else
	{
		return FALSE;
	}
}


BOOL QSttTestCntrFrameBase::SetValues_dsRcdStep6U6I( CDataGroup *pDataGroup,BOOL bClearResult )
{
// 	if ((g_pTheSttTestApp->m_pTestMacroUI == nullptr)||(m_pMacroEditView == nullptr) || (pDataGroup ==  nullptr))
// 	{
// 		return FALSE;
// 	}
    if (pDataGroup ==  nullptr)
	{
		return FALSE;
	}

	if (g_pTheSttTestApp->IsMuTest())
	{
		CXSttCap_61850 *pXSttCap_61850 = CXSmartCapMngr::GetSttCap61850_Global();

        if (pXSttCap_61850 == nullptr)
		{
			return FALSE;
		}
// 		CDvmDataset *pDsRcdStep6U6I = pXSttCap_61850->AddDataset_dsRcdStep6U6I();
// 		BOOL bRet = FALSE;

		CDvmDataset *pDsRcdStep6U6I = pXSttCap_61850->m_pDataset_RcdStep6U6I;
		BOOL bRet = FALSE;

		if (pDsRcdStep6U6I)
		{
			bRet = TRUE;
		}

		POS pos = pDsRcdStep6U6I->GetHeadPosition();
		CString strSrcID;
        CDvmData *pSrcData = nullptr, *pDesData = nullptr;

		//这里可以获取XML文件中的值；
        while (pos != nullptr)
		{
			pSrcData  =  (CDvmData *)pDsRcdStep6U6I->GetNext(pos);
			strSrcID  =  pSrcData->m_strID;
			//	strID = strSrcID.Left(nCnt);
			if (strSrcID == X61850_CapID_ZeroDrift_Un)
			{
				pDesData = (CDvmData *)pDataGroup->FindByID(_T("Unom"));
				if(pDesData)
				{
					pSrcData->m_strValue = /*CString_To_double(*/pDesData->m_strValue;
//                     CLogPrint::LogFormatString(XLOGLEVEL_INFOR,_T("Unom: %s"),pSrcData->m_strValue.GetString());
					continue;
				}
			}
			else if (strSrcID == X61850_CapID_ZeroDrift_In)
			{
				pDesData = (CDvmData *)pDataGroup->FindByID(_T("Inom"));
				if(pDesData)
				{
					pSrcData->m_strValue = /*CString_To_double(*/pDesData->m_strValue/*)*/;
//                     CLogPrint::LogFormatString(XLOGLEVEL_INFOR,_T("Inom: %s"),pSrcData->m_strValue.GetString());
					continue;
				}
			}
		}

// 		pXSttCap_61850->UpdateUI_Paras(bRet);
// 
// 		if (bClearResult)
// 		{
// 			pXSttCap_61850->ClearMUTestResults();
// 		}

		return bRet;
	}
	else
	{
		return FALSE;
	}
}

void QSttTestCntrFrameBase::InitSttIecRecord()
{
}

// void QSttTestCntrFrameBase::InitSttCap_MUTerminal()
// {
// }

void QSttTestCntrFrameBase::InitAfterCreateSttMacroPara()
{
	CString strIDMacroUI = g_pTheSttTestApp->GetCurrTestMacroUI();

	if(strIDMacroUI == STT_ORG_MACRO_MUTimingAccurTest || strIDMacroUI == STT_ORG_MACRO_MUPunctAccurTest)
	{
		InitSttIecRecord();
		g_bSmartCap_RecordNow = FALSE;//进入监视界面时,停止报文解析
		CXSttCap_61850 *pXSttCap_61850 = CXSmartCapMngr::GetSttCap61850_Global();

        if (pXSttCap_61850 != nullptr)
		{
			pXSttCap_61850->MUTimeTestRlt_AddDataset();
		}
	}
	else if (strIDMacroUI == STT_ORG_MACRO_RemoteMeasTest || strIDMacroUI == STT_ORG_MACRO_RemoteCtrlTest)
	{
		CreateEngineClientWidget();
	}
}

void QSttTestCntrFrameBase::slot_UpdateHtmlManuTrigerBtn_Testing()
{
	if (HasManuTrigerBtn()&&(g_pTheSttTestApp->m_pTestMacroUI->IsUIWeb()))
	{
		if (IsManuTriger_HtmlFaultTrigMode())
		{
			EnableManualTriggerButton(true);
//			UpdateButtonStateByID(STT_CNTR_CMD_ManuTriger,true,true);
		} 
		else
		{
			EnableManualTriggerButton(false);
//			UpdateButtonStateByID(STT_CNTR_CMD_ManuTriger,false,true);
		}
	}
}

void QSttTestCntrFrameBase::slot_UpdateSysConfig()
{
	g_oSttTestResourceMngr.m_oIecDatasMngr.UpdateFT3ChsType(g_oSystemParas.m_nIecFormat,g_oSystemParas.m_nIecFormatMeas);
	//判断是否修改系统参数,当前是否加载了测试功能模块,当前测试功能模块是否为网页
    if (g_oSttSystemConfig.GetSelSysPata() &&(g_pTheSttTestApp->m_pTestMacroUI != nullptr) && (m_pMacroEditView!=nullptr))//判断当前是否加载了测试功能模块,并判断当前测试功能模块是否为网页
	{
		if (g_pTheSttTestApp->m_pTestMacroUI->IsUIOriginal())
		{	
			CSttMacroParaEditViewOriginal* pOriginal = (CSttMacroParaEditViewOriginal*)m_pMacroEditView;
			pOriginal->UpdateSerializeSysParas();
		}
	}

	OnUpdateTestResource(FALSE);
	Cmd_SendChMapsConfig();//20221026 zhouhj 先发送通道映射,后发送系统参数更新消息,系统更新后会上送新的模板生成文件,同时更新上位机界面相关内容
	Cmd_SendSystemConfig();

	//2024-6-27 wuxinyi 向底层发送完成系统参数，再开始刷新实时数据
	g_theTestCntrFrame->m_bUpdateHardCfgFromRealTime = true;

}

void QSttTestCntrFrameBase::slot_UpdatePowerGear()
{
	Cmd_SendSystemConfig();

	//2024-6-27 wuxinyi 向底层发送完成，再开始刷新实时数据
	g_theTestCntrFrame->m_bUpdateOutputPowerFromRealTime = true;

}

void QSttTestCntrFrameBase::slot_OnItemStateChanged_Frame(CExBaseObject *pItem)
{
	CSttItemStateObject* pObj = (CSttItemStateObject*)pItem;

	CSttItemBase *pSttItem = (CSttItemBase*)pObj->m_pItem;
//	CSttReports *pSttReports = pSttItem->GetSttReports();
	CString strItemID,strBeforeTestString;
	strBeforeTestString.Format(_T("$%s$"),STT_ITEMS_ID_BEFORETEST);
	//strItemID = pSttItem->GetIDPathEx(STTGBXMLCLASSID_CSTTDEVICE, FALSE);

	CString strParentItemsPath, /*strItemID,*/ strState;
	CExBaseObject *pParent = (CExBaseObject*)pSttItem->GetParent();
	strParentItemsPath = pParent->GetIDPathEx(STTGBXMLCLASSID_CSTTDEVICE, FALSE);
	//strItemID = pObj->m_pItem->GetIDPathEx(STTGBXMLCLASSID_CSTTDEVICE, FALSE);
	//如果是状态序列则重新生成id
	if (g_pTheSttTestApp->m_pTestMacroUI->IsUIOriginal())
	{
		CString strMacroID =  g_pTheSttTestApp->GetCurrTestMacroUI();
		if (strMacroID == STT_MACRO_ID_StateTest)
		{
			QSttMacroParaEditViewState *pState = (QSttMacroParaEditViewState *)m_pMacroEditView;
			if (pState->m_nCircle >= 2)
			{
				//收到下一个ItemChange时，将第一个循环的状态改为初始状态
				strItemID = pObj->m_pItem->GetIDPathEx(STTGBXMLCLASSID_CSTTDEVICE, FALSE);
				strState = TEST_STATE_DESC_NORMAL;

                //if ((m_pSttReportViewHtml != nullptr) && !m_bIsUpdateStateTestFirstReportColor)
                //{
                //	m_pSttReportViewHtml->ItemStateChanged(strParentItemsPath, strItemID, strState);
                //	m_bIsUpdateStateTestFirstReportColor = TRUE;
                //}
				CExBaseObject *pParent = (CExBaseObject *)pObj->m_pItem->GetParent();
				if (pParent)
				{
					pParent->m_strID.Format(_T("StateTest%d"), pState->m_nCircle);
				}
			}
		}
	}
	
	strItemID = pObj->m_pItem->GetIDPathEx(STTGBXMLCLASSID_CSTTDEVICE, FALSE);
	strState = Gb_GetTestStateByID(pSttItem->m_nState);

    //if (m_pSttReportViewHtml != nullptr)
    //{
    //	m_pSttReportViewHtml->ItemStateChanged(strParentItemsPath, strItemID, strState);
    //}

	if (pSttItem->m_nState == TEST_STATE_TESTING)//zhouhj 20220406 如果是测试过程中,更新手动触发按钮
	{
		slot_UpdateHtmlManuTrigerBtn_Testing();  //zhouhj 20220618 slot_OnItemStateChanged_Frame槽函数已经是主线程无需再发送信号,且主线程中发送信号给主线程可能会与子线程发送的信号互锁
//		emit sig_UpdateHtmlManuTrigerBtn_Testing();
	}

	UINT nClassID = pParent->GetClassID();

	if (nClassID == STTGBXMLCLASSID_CSTTMACROCHARITEMS)
	{
		CSttMacroCharItems *pCharItems = (CSttMacroCharItems *)pParent;
		CSttItems *pCharItemsParent = (CSttItems *)pCharItems->GetParent();
		CString strCharacterId/* = pCharItemsParent->m_strCharacteristicID*/;
		//ItemID与特性曲线ID保持一致
		CString strBase64;
		CDataGroup *pSearchLine = (CDataGroup *)pObj->m_pParas->FindByID("SearchLine");

		if(pSearchLine)
		{
			CString strCurItemStateChanged_SearchLineString,strValue;
			CSttCharacteristic* pSttChar = (CSttCharacteristic*)pCharItems->FindByClassID(STTGBXMLCLASSID_CSTTCHARACTERISTIC);
			strCharacterId = pSttChar->m_strID;
			m_pSttCharacterDrawPng->InitCharDrawTest(strCharacterId, CString_To_long(pSttChar->m_strIndex));
			CSttMacroTestUI_TestMacroUI *pTestMacroUI = m_pTestCtrlCntrBase->GetCurrTestMacroUI();
			if (pTestMacroUI->m_strID == STT_ORG_MACRO_CurrInverseTimeTest)
			{
				m_pSttCharacterDrawPng->InitCharDrawTestAxis(CSttCharacterDrawPng::CurrInverseTime);
			}
			else if (pTestMacroUI->m_strID == STT_ORG_MACRO_VolInverseTimeTest)
			{
				m_pSttCharacterDrawPng->InitCharDrawTestAxis(CSttCharacterDrawPng::VolInverseTime);
			}
			else if (pTestMacroUI->m_strID == STT_ORG_MACRO_UFInverseTimeTest)
			{
				m_pSttCharacterDrawPng->InitCharDrawTestAxis(CSttCharacterDrawPng::VolInverseTime);
			}
			else if ((pTestMacroUI->m_strID == STT_ORG_MACRO_DiffCurr6ITest)||(pTestMacroUI->m_strID == STT_ORG_MACRO_LineDiffCurr6ITest)
				||(pTestMacroUI->m_strID == STT_ORG_MACRO_BusDiffCurr6ITest)||(pTestMacroUI->m_strID == STT_ORG_MACRO_ElecRailwayDiffTest))
			{
				m_pSttCharacterDrawPng->InitCharDrawTestAxis(CSttCharacterDrawPng::DiffCurr6I);
			}
			else if ((pTestMacroUI->m_strID == STT_ORG_MACRO_DistanceTest)||(pTestMacroUI->m_strID == STT_ORG_MACRO_DistanceTest_I))
			{
				m_pSttCharacterDrawPng->InitCharDrawTestAxis(CSttCharacterDrawPng::Distance);
			}
			else if ((pTestMacroUI->m_strID == STT_ORG_MACRO_DistanceSearchTest)||(pTestMacroUI->m_strID == STT_ORG_MACRO_DistSearchOneTest))
			{
				m_pSttCharacterDrawPng->InitCharDrawTestAxis(CSttCharacterDrawPng::DistanceSearch);
			}
			else
			{
                m_pSttCharacterDrawPng->InitCharDrawTestAxis(NULL);
			}

			m_pSttCharacterDrawPng->GetSearchingPng(pSearchLine, strBase64);
			CString strCharactPath;
			strCharactPath = strParentItemsPath + _T("Img");

            //if (m_pSttReportViewHtml != nullptr)
            //{
            //	m_pSttReportViewHtml->FillReportImg("", strCharactPath, strBase64);//zhouhj 20230213 用于插入差动图片
            //}

//  		double dXb = CString_To_double(((CDvmData*)pSearchLine->FindByID("search-x-b"))->m_strValue);
//  		double dXe = CString_To_double(((CDvmData*)pSearchLine->FindByID("search-x-e"))->m_strValue);
//  		double dYb = CString_To_double(((CDvmData*)pSearchLine->FindByID("search-y-b"))->m_strValue);
// 			double dYe = CString_To_double(((CDvmData*)pSearchLine->FindByID("search-y-e"))->m_strValue);
			strCurItemStateChanged_SearchLineString = pObj->m_strItemID;
			pSearchLine->GetDataValue(_T("search-x-c"),strValue);
			strCurItemStateChanged_SearchLineString.AppendFormat(_T("(%s,"),strValue.GetString());
 			double dXc = CString_To_double(strValue);
			pSearchLine->GetDataValue(_T("search-y-c"),strValue);
			strCurItemStateChanged_SearchLineString.AppendFormat(_T("%s)"),strValue.GetString());
 			double dYc = CString_To_double(strValue);

			//zhouhj 2023.8.22 如果相同则不更新,由于自动测试上送的ItemChanged实际多于搜索点改变次数,此处防止重复更新
			if (strCurItemStateChanged_SearchLineString == m_strItemStateChanged_SearchLineString)
			{
				return;
			}

//			m_pSttCharacterDrawPng->ClearSearchPoints_png();
			m_strItemStateChanged_SearchLineString = strCurItemStateChanged_SearchLineString;

//			CLogPrint::LogFormatString(XLOGLEVEL_RESULT,_T("%s__(%lf,%lf)"),pObj->m_strItemID.GetString(),dXc,dYc);

			if ((strCharacterId == _T("PsuDiffHarmTest"))||(strCharacterId == _T("PsuDiffHarmTest")) && (dYc<0.001f))
			{
				dYc =  CString_To_double(((CDvmData*)pSearchLine->FindByID("y-set"))->m_strValue);
			}

			if (m_pCharTestPointsGrid)
			{
				m_pCharTestPointsGrid->UpdateCurrTestPoint(strCharacterId,pSttChar->m_strIndex,dXc,dYc);
			}

			if (m_pCharactWidgetForTest)//window版下采用此更新,创建该对象
			{
				m_pCharactWidgetForTest->UpdateCurrTestPoint(strCharacterId,pSttChar->m_strIndex,dXc,dYc);
			}
			else//linux下与之前保持一致
			{
				m_pCharLibWidget->m_pImpCharactWidget->m_pCharacterDrawView->UpdateCurrTestPoint(dXc, dYc);
				m_pCharLibWidget->m_pImpCharactWidget->update();
			}
		}
	}
}

void QSttTestCntrFrameBase::slot_OnInputData(CDataGroup *pParas, CExBaseList *pMsgs)
{

}

void QSttTestCntrFrameBase::slot_OnImportDvm(CExBaseList *pListItems)
{

}

QSttTestCntrFrameBase::QSttTestCntrFrameBase(QWidget *parent)
: QMainWindow(parent)
{
	//m_bAutoUpdateNameByTestCount = TRUE;
    m_pStartTestBtn = nullptr;
    m_pManualTriggerBtn = nullptr;
    m_pExitBtn = nullptr;
    m_pMenu_FrameButton = nullptr;
    //sun CLogPrint::Create();
    m_pStatusBar = nullptr;
    m_pResultBarUI = nullptr;
    m_pResultWidget = nullptr;
    m_pSttGbTreeView = nullptr;
    m_pOutputWidget = nullptr;

    m_pCurrEditMacroItems = nullptr;
    m_pTestCtrlCntrBase = nullptr;
    //sun m_pEngineClientWidget = nullptr;
	m_bIsRunningStartStopCmd = FALSE;

//	m_pSttTestResource = nullptr;
    m_pVectorWidget = nullptr;
    m_pStateMonitorWidget = nullptr;
    m_pPowerDiagramWidget=nullptr;
    m_pInfoWidget = nullptr;
    m_pCharLibWidget = nullptr;
    m_pCharactWidgetForTest = nullptr;
    m_pCharTestPointsGrid = nullptr;
    m_pMacroEditView = nullptr;
    //m_pSysParaEditView = nullptr;

    m_pActiveWidget = nullptr;
    m_pPrevActiveWidget = nullptr;
	m_nActiveWidgetType = ActiveWidgetType_None; 
	m_nPrevActiveWidgetType = ActiveWidgetType_None; 

	//m_bSelMacroShow = true;
    //m_pSttReportViewHtml = nullptr;
    m_pSttIecRecordMainWidget = nullptr;
	m_bHasClosedUI = FALSE;
	m_bHasUpdateRptStartTestTime = FALSE;
	m_bIsUpdateStateTestFirstReportColor = FALSE;

    //sun m_pRemoteCtrlWidget = nullptr;
	m_bUpdateHardCfgFromRealTime = TRUE;
	m_bUpdateOutputPowerFromRealTime = TRUE;
// 	m_bFirstUpadeIPowerMode = TRUE;

	m_pCharacteristics = new CCharacteristics();
	m_pSttCharacterDrawPng = new CSttCharacterDrawPng();
	m_pSttCharacterDrawPng->SetCharacteristics(m_pCharacteristics);
    //m_pItemState = nullptr;

	m_oItemStateList.AllocBuffer(50);
    m_pSttMulticastClientSocket = nullptr;
    m_tagAppState = APPSTATE_NULL;
    m_pSttFaParasSetDialog = nullptr;
    //sun m_pSttCommCfgPkgWidget = nullptr;
	m_oTimerAtsAutoSave.start(30000);
}

//2022-3-23  提取的公共框架函数，在Win、LINUX独立实现
void QSttTestCntrFrameBase::InitFrame(const CString &strFrameCfgFile)
{
    stt_xml_serialize_write_ReplayTest();
	InitConfig(strFrameCfgFile);
    m_pSttFrameConfig->InitAfterRead();
    if(!m_pSttFrameConfig->GetFont())
    {
qDebug() << "Debug sun: m_pSttFrameConfig->GetFont() is nullllllllllllll";
    }
    if(!m_pSttFrameConfig->GetMenus())
    {
qDebug() << "Debug sun: m_pSttFrameConfig->GetMenus() is nullllllllllllll";
    }
    if(!m_pSttFrameConfig->GetToolBar())
    {
qDebug() << "Debug sun: m_pSttFrameConfig->GetToolBar() is nullllllllllllll";
    }
    if(!m_pSttFrameConfig->GetResultBar())
    {
qDebug() << "Debug sun: m_pSttFrameConfig->GetResultBar() is nullllllllllllll";
    }
    if(!m_pSttFrameConfig->GetStatusBar())
    {
qDebug() << "Debug sun: m_pSttFrameConfig->GetStatusBar() is nullllllllllllll";
    }
	g_oFileMngrTool.OpenConfigFile();
	InitUI();
	InitIcon();
#ifdef _USE_SoftKeyBoard_
	InitPinyinLib();
	CreateKeyBoardWidget();
    //sun QSoftKeyBoard::AttachObj(this);
#endif

	//2022-2-26  lijunqing  如果文件不存在，输出提示信息的时候窗口还没创建成功，程序崩溃
	//g_oSttTestResourceMngr.LoadDefaultIec61850Config(FILENAME_STTIECCONCFIG);
// 
// 	//项目列表视图
// 	CSttFrame_GbTree *pTree = m_pSttFrameConfig->GetGbTree();
// 	m_pSttGbTreeView = new QSttGuideBookTreeWidget(nullptr, pTree, this);
// 	m_pSttGbTreeView->hide();
// 
// 	g_theTestCntrFrame = this;
// 	CalRectArea();
// 
// 	//输出视图一直存在
// 	m_pOutputWidget = new QSttOutPutWidget(this);
// 	m_pOutputWidget->hide();
// 
// 	//信息视图一直存在
// 	InitInfoWidget();
// 	m_pInfoWidget->hide();

	
//	connect(this,SIGNAL(sig_LogStringResult(long,CString)),this,SLOT(slot_LogStringResult(long,CString)),Qt::UniqueConnection);
	connect(this,SIGNAL(sig_OnViewTestLink(bool)),this,SLOT(slot_OnViewTestLink(bool)),Qt::QueuedConnection);//不同线程,槽函数需要使用队列模式在主线程执行
	connect(this,SIGNAL(sig_OnViewTestStart()),this,SLOT(slot_OnViewTestStart()),Qt::QueuedConnection);
	connect(this,SIGNAL(sig_OnViewTestStop()),this,SLOT(slot_OnViewTestStop()),Qt::QueuedConnection);
	connect(this,SIGNAL(sig_OnUpdateGpsTime(CDataGroup *)),this,SLOT(slot_OnUpdateRtSyncTime(CDataGroup*)),Qt::QueuedConnection);//不同线程,槽函数需要使用队列模式在主线程执行
	connect(this,SIGNAL(sig_OnUpdateException()),this,SLOT(slot_OnUpdateException()),Qt::QueuedConnection);
	connect(this,SIGNAL(sig_MenuButtonClick(QString)),this,SLOT(slot_MenuButtonClick(QString)),Qt::QueuedConnection);
	connect(this,SIGNAL(sig_UpdateToolButtons()),this,SLOT(slot_UpdateToolButtons()));
	connect(this,SIGNAL(sig_UpdateEnableState(QString)),this,SLOT(on_UpdateEnableState(QString))/*,Qt::BlockingQueuedConnection*/);
	connect(&m_oTimerAtsTest,SIGNAL(timeout()),this,SLOT(slot_Timer()));
	connect(&m_oTimerHtmlViewReturn,SIGNAL(timeout()),this,SLOT(slot_ReturnPrevActiveWidget()));
	connect(&m_oTimerAtsAutoSave,SIGNAL(timeout()),this,SLOT(slot_Timer_AutoSave()));

	connect(this,SIGNAL(sig_OnItemStateChanged(CExBaseObject *)),m_pSttGbTreeView,SLOT(slot_ItemStateChanged(CExBaseObject *)));
	connect(this,SIGNAL(sig_ShowItems_TreeView(CExBaseList *)),m_pSttGbTreeView,SLOT(slot_ShowItems(CExBaseList *)));
	connect(this, SIGNAL(sig_UpdateTestResource()), this, SLOT(slot_UpdateTestResource()),Qt::QueuedConnection);
	connect(this, SIGNAL(sig_UpdateHtmlManuTrigerBtn_Testing()), this, SLOT(slot_UpdateHtmlManuTrigerBtn_Testing()));

	connect(this, SIGNAL(sig_UpdateSysConfig()), this, SLOT(slot_UpdateSysConfig()),Qt::QueuedConnection);
	connect(this, SIGNAL(sig_UpdatePowerGear()), this, SLOT(slot_UpdatePowerGear()),Qt::QueuedConnection);
	connect(this, SIGNAL(sig_CloseMenu()), this, SLOT(slot_CloseMenu()),Qt::QueuedConnection);
	connect(this, SIGNAL(sig_UpdateRptHtml()), this, SLOT(slot_UpdateRptHtml()),Qt::QueuedConnection);
	connect(this, SIGNAL(sig_FillReportImg(QString)), this, SLOT(slot_FillReportImg(QString)),Qt::QueuedConnection);
//	connect(this, SIGNAL(sig_OnItemStateChanged_Frame(CExBaseObject *)), this, SLOT(slot_OnItemStateChanged_Frame(CExBaseObject *)));
	connect(this, SIGNAL(sig_OnInputData(CDataGroup *, CExBaseList *)), this, SLOT(slot_OnInputData(CDataGroup *, CExBaseList *)));
	connect(this,SIGNAL(sig_OnImportDvm(CExBaseList *)),this,SLOT(slot_OnImportDvm(CExBaseList *)));

	connect(this, SIGNAL(sig_MsgBox(QString,QString)), this, SLOT(slot_MsgBox(QString,QString)),Qt::QueuedConnection);

	m_bInited = false;
	if (g_nLogDebugInfor == 1)	{		CLogPrint::LogString(XLOGLEVEL_TRACE, ">> begin TestResourceMngr >>");	}
	g_oSttTestResourceMngr.SetIecConfigFileName(FILENAME_STTIECCONCFIG);//zhouhj 20220316 改为独立设置文件名的方式
	g_oSttSystemConfig.OpenSystemConfig();
	g_oSttTestResourceMngr.LoadDefaultIec61850Config();
	if (g_nLogDebugInfor == 1)	{		CLogPrint::LogString(XLOGLEVEL_TRACE, ">> end TestResourceMngr >>");	}

}

QSttTestCntrFrameBase::~QSttTestCntrFrameBase()
{
#ifdef _PSX_QT_LINUX_
	ReleaseKeyboardWidget();
#endif
	m_oTimerAtsAutoSave.stop();
	CAutoSimpleLock oLock(m_oCriticSection_AutoSave);

    CLogPrint::SetLog(nullptr);
	CLogPrint::Release();
	ReleaseConfig();

// 	if (m_pSttTestResource != nullptr)
// 	{
// 		delete m_pSttTestResource;
// 		m_pSttTestResource = nullptr;
// 	}

    if (m_pPowerDiagramWidget != nullptr)
	{
		delete m_pPowerDiagramWidget;
        m_pPowerDiagramWidget = nullptr;
	}
    if (m_pVectorWidget != nullptr)
	{
		delete m_pVectorWidget;
        m_pVectorWidget = nullptr;
	}

    if (m_pStateMonitorWidget != nullptr)
	{
		delete m_pStateMonitorWidget;
        m_pStateMonitorWidget = nullptr;
	}

    //if (m_pSttReportViewHtml != nullptr)
    //{
    //	delete m_pSttReportViewHtml;
    //	m_pSttReportViewHtml = nullptr;
    //}

    if (m_pInfoWidget != nullptr)
	{
		delete m_pInfoWidget;
        m_pInfoWidget = nullptr;
	}

    if (m_pCharLibWidget != nullptr)
	{
		delete m_pCharLibWidget;
        m_pCharLibWidget = nullptr;
	}	

    if (m_pCharactWidgetForTest != nullptr)
	{
		delete m_pCharactWidgetForTest;
        m_pCharactWidgetForTest = nullptr;
	}

    if (m_pCharTestPointsGrid != nullptr)
	{
		delete m_pCharTestPointsGrid;
        m_pCharTestPointsGrid = nullptr;
	}
	
    if(m_pCharacteristics != nullptr)
	{
		delete m_pCharacteristics;
        m_pCharacteristics = nullptr;
	}

    if(m_pSttCharacterDrawPng != nullptr)
	{
		delete m_pSttCharacterDrawPng;
        m_pSttCharacterDrawPng = nullptr;
	}

    if (m_pSttIecRecordMainWidget != nullptr)
	{
		delete m_pSttIecRecordMainWidget;
        m_pSttIecRecordMainWidget = nullptr;
	}


    //sun if(m_pSttCommCfgPkgWidget != nullptr)
    //sun {
    //sun 	delete m_pSttCommCfgPkgWidget;
    //sun     m_pSttCommCfgPkgWidget = nullptr;
    //sun }
}

//////////////////////////////////////////////////////////////////////////
//CSttWndAssistInterface
//查找窗口，保留用 找到返回窗口,      否则返回NULL
CSttWndAssistInterface* QSttTestCntrFrameBase::ast_FindWnd(const CString &strWndID)
{
	
    return nullptr;
}

//功能执行接口
bool QSttTestCntrFrameBase::ast_ExecCmd(const CString &strCmdID,const CString &strParas)
{
	if (strCmdID == "MenuCmd")
	{
		slot_MenuButtonClick(strParas);
		return true;
	}

	if (strCmdID == Event_ID_IecSelCb)
	{
		//弹出对话框，选择控制块

		return true;
	}

	if (strCmdID == STT_CMD_TYPE_ATS_StartDetect)
	{
		
		return true;
	}

	return false;
}

bool QSttTestCntrFrameBase::ast_ExecCmd_Data(const CString &strCmdID, const CString &strDataID)
{

	return false;
}

bool QSttTestCntrFrameBase::ast_ExecCmd_DataFile(const CString &strCmdID, const CString &strDataFile)
{

	return false;
}

//////////////////////////////////////////////////////////////////////////
void QSttTestCntrFrameBase::InitTestResource()
{	
	long nMergeCurrCoef = 1;

	if (g_oSttTestResourceMngr.GetAnalogCurrentMergeCoef(nMergeCurrCoef))
	{
		g_oLocalSysPara.m_fAC_CurMax *= nMergeCurrCoef;
		g_oLocalSysPara.m_fAC_CurMin *= nMergeCurrCoef;
		g_oLocalSysPara.m_fDC_CurMax *= nMergeCurrCoef;
		g_oLocalSysPara.m_fDC_CurMin *= nMergeCurrCoef;
	}
}

void QSttTestCntrFrameBase::OnUpdateTestResource(BOOL bCreateChMaps)
{
    if (m_pMacroEditView == nullptr)
    {
		if (!bCreateChMaps)//zhouhj 2024.5.22 在档位切换时,更新合并大电流通道映射功能
		{
			g_oSttTestResourceMngr.ValidHardRsChMaps();
		}

        return;
    }

	if (g_nLogDebugInfor)
	{
		CLogPrint::LogString(XLOGLEVEL_TRACE, _T(">> begin OnUpdateTestResource >>"));
	}

	if (bCreateChMaps)
	{
		g_oSttTestResourceMngr.CreateChMaps();//打开本地通道映射文件
	}

//	initLocalSysPara();
	g_oSttTestResourceMngr.InitLocalSysPara();
	g_oSttTestResourceMngr.ValidHardRsChMaps();//验证通道映射文件中硬件信息是否在Device中存在，删除不存在的硬件信息，如果不存在，则根据Device信息，创建缺省
	g_oSttTestResourceMngr.CreateSoftRsCh();
	g_oSttTestResourceMngr.CreateRtDataMngr();
	g_oSttTestResourceMngr.SaveSystemParasFile();
	long nMergeCurrCoef = 1;

	if (g_oSttTestResourceMngr.GetAnalogCurrentMergeCoef(nMergeCurrCoef))
	{
		g_oLocalSysPara.m_fAC_CurMax *= nMergeCurrCoef;
		g_oLocalSysPara.m_fAC_CurMin *= nMergeCurrCoef;
		g_oLocalSysPara.m_fDC_CurMax *= nMergeCurrCoef;
		g_oLocalSysPara.m_fDC_CurMin *= nMergeCurrCoef;
	}

	//当加载了测试功能且该功能是递变时，不需要对状态图进行重新初始化
	bool bIsOriginal = false;
	bool bIsGradient = false;

    if ((g_pTheSttTestApp->m_pTestMacroUI != nullptr) && (m_pMacroEditView!=nullptr))//判断当前是否加载了测试功能模块,并判断当前测试功能模块是否为网页
	{
		if (g_pTheSttTestApp->m_pTestMacroUI->IsUIOriginal())
		{
			m_pMacroEditView->UpdateTestResource(FALSE);//zhouhj20220319 在非网页界面界面时,更新
			UpdateRptHtml();//zhouhj 20220329 只有在原生界面,在更改软件资源映射后,需要更新报告中的通道
			bIsOriginal = true;
			bIsGradient = (strcmp(((CSttMacroParaEditViewOriginal*)m_pMacroEditView)->GetMacroID(), "GradientTest") == 0);
		}
		else
		{
			InitBinaryIn_WebUI(m_pTestMacroUI_Paras);
		}
	}

	if (m_pStateMonitorWidget)
	{
		//不是原生态模块或者是原生态但不是递变模块时，可以进行状态图的重新初始化
		if (!bIsOriginal || (bIsOriginal && !bIsGradient))
		{
			m_pStateMonitorWidget->UpdateStateMonitorChs();
		}
	}

	if(m_pVectorWidget)
	{
		//20231109 suyang 根据不同模块 矢量图表格是否增加滑差值显示
		CString strCurrUI_ID = GetCurrentUI_ID();
		int nType;

		if(strCurrUI_ID == STT_CMD_ATS_MACRO_ID_LowVolTest)
		{
			nType = STT_LowVolDvdt_VECTOR;
		}
		else if (strCurrUI_ID == STT_CMD_ATS_MACRO_ID_LowFreqTest)
		{
			nType = STT_LowFreqDfdt_VECTOR;
		}
		else
		{
			nType = STT_COMMON_VECTOR;
		}

		m_pVectorWidget->setPropertyOfParaSet(GetSttTestResource(),nType);
		m_pVectorWidget->updateData();
	}

	if(m_pPowerDiagramWidget)
	{
		m_pPowerDiagramWidget->setPropertyOfParaSet(GetSttTestResource());
		m_pPowerDiagramWidget->initData();
	}

	//系统参数页面，未勾选“数字”，应隐藏“IEC配置”按钮 sf 20220317
	if (!g_oSystemParas.HasDigitalInOrOut())
	{
		UpdateButtonStateByID(STT_CNTR_CMD_IECConfig,false,false);
	}
 	else//20220810 zhouhj
 	{
 		UpdateButtonStateByID(STT_CNTR_CMD_IECConfig,true,true);
 	}

	if (g_nLogDebugInfor)
	{
		CLogPrint::LogString(XLOGLEVEL_TRACE, _T(">> end OnUpdateTestResource >>"));
	}

	UpdateToolButtons();
}

// void QSttTestCntrFrameBase::initLocalSysPara()
// {
// 	g_oSttTestResourceMngr.InitLocalSysPara();
// }

void QSttTestCntrFrameBase::UpdateReportHead( CDataGroup *pSttReport )
{
    //if (m_pSttReportViewHtml)
    //{
    //	m_pSttReportViewHtml->UpdateReportHead(pSttReport);
    //}
}

void QSttTestCntrFrameBase::GetMacroItemsXml(const CString strItemID, char **ppszReport, long &nLen,const CString &strParentPath)
{
	CString strIDMacroUI = g_pTheSttTestApp->GetCurrTestMacroUI();
	CString strMacroID = g_pTheSttTestApp->m_pTestMacroUI->m_strID;

	if(g_pTheSttTestApp->IsTestMacro_CurrVolChAsItem())
	{
		nLen = m_pMacroEditView->GetMacroItemsXml(strMacroID, ppszReport);
	}
	else
	{
		nLen = m_pTestCtrlCntrBase->GetMacroItemsXml(strMacroID, ppszReport,strParentPath);
	}
}

void QSttTestCntrFrameBase::UpdateCustomReport()
{
    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return;
	}

	CString strMacroID = g_pTheSttTestApp->m_pTestMacroUI->m_strID;

	if(strMacroID == STT_ORG_MACRO_MUAccuracyTest
		|| strMacroID == STT_ORG_MACRO_MUFirstCycleTest
		|| strMacroID == STT_ORG_MACRO_MUTimingAccurTest
		|| strMacroID == STT_ORG_MACRO_MUPunctAccurTest)
	{
		CExBaseObject *pSel = m_pSttGbTreeView->GetCurrSelectGbItem();
		AddMacroTestReport(g_pTheSttTestApp->m_pTestMacroUI, pSel, "", "");
	}
}

void QSttTestCntrFrameBase::UpdateCharactWidgetForTest(long nPtIndex)
{
	//yzj 2023.10.19
	if(nPtIndex < 0)
	{
		return;
	}
	else if(nPtIndex == 0)
	{
		//从第0个点开始全部清空
        if (m_pCharactWidgetForTest != nullptr)
		{
			m_pCharactWidgetForTest->slot_UpdateDrawCharacters();
		}

        if (m_pCharTestPointsGrid != nullptr)
		{
			m_pCharTestPointsGrid->ClearSearchPoints();
		}

		if(m_pSttCharacterDrawPng)
		{
			m_pSttCharacterDrawPng->ClearSearchPoints_png();
		}

		m_strItemStateChanged_SearchLineString = _T("");
	}
	else
	{
        if (m_pCharactWidgetForTest != nullptr)
		{
			m_pCharactWidgetForTest->ClearSearchPointsFrom(nPtIndex);
		}

        if (m_pCharTestPointsGrid != nullptr)
		{
			m_pCharTestPointsGrid->ClearSearchPointsFrom(nPtIndex);
		}

		if(m_pSttCharacterDrawPng)
		{
			m_pSttCharacterDrawPng->ClearSearchPointsFrom_png(nPtIndex);
		}
	}
}

void QSttTestCntrFrameBase::UpdateCharactWidgetForCurTest(long nPtIndex)
{
    if (m_pCharactWidgetForTest != nullptr)
	{
		m_pCharactWidgetForTest->ClearSearchPoint(nPtIndex);
	}

    if (m_pCharTestPointsGrid != nullptr)
	{
		m_pCharTestPointsGrid->ClearSearchPoint(nPtIndex);
	}

	if(m_pSttCharacterDrawPng)
	{
		m_pSttCharacterDrawPng->ClearSearchPoints_png(nPtIndex);
	}
}

void QSttTestCntrFrameBase::UpdateResultWidget(CSttReport *pReport,const CString &strItemName,const CString &strMacroID)
{
    if (pReport == nullptr)
	{
		return;
	}

#ifdef _PSX_QT_LINUX_
	//windows版本是新的widget指针
    if (m_pResultWidget == nullptr)
	{
		return;
	}
#endif

	CDvmValues *pValues = (CDvmValues*)pReport->FindByClassID(DTMCLASSID_CDVMVALUES);

    if (pValues == nullptr)
	{
		return;
	}

	/*
	1）在测试结果集合对象(m_oTestMacroResults)中未查找到任何结果信息的，此报告结果无意义，不做展示；
	2）在测试结果中查找到结果，但结果都是未动作或者为非相位类结果值为负数，显示总的未动作结果；
	3）在测试结果中查找到有动作结果的信息，直接显示动作结果；
	*/

    CDvmData *pCurrData = nullptr;
    CDvmValue *pResultValue = nullptr;
	CString strResultsString = _T("$");
	strResultsString += strItemName;
	strResultsString += "[";
	double dValue = 0;
	BOOL bHasResult = FALSE,bHasActValue = FALSE;


	CSttItems* pItems = (CSttItems*)pValues->GetAncestor(STTGBXMLCLASSID_CSTTITEMS);

    if (pItems == nullptr)
	{
		return;
	}

	strResultsString = pItems->m_strName + strResultsString;

	if ((strMacroID == STT_MACRO_ID_GradientTest)||(strMacroID == STT_MACRO_ID_GradientMaxAngleTest))
	{
		//递变测试的结果与对应的故障参数相关,此处单独处理递变测试结果
		bHasResult = GetResultStringGradientTest(pValues,bHasActValue,strResultsString,m_oTestMacroResults);
	} //
	else if (strMacroID == STT_MACRO_ID_LineVolGradientTest)
	{
		//递变测试的结果与对应的故障参数相关,此处单独处理递变测试结果
		bHasResult = GetResultStringLineVolGradientTest(pValues,bHasActValue,strResultsString,m_oTestMacroResults);
	} //
	else if (strMacroID == STT_MACRO_ID_SequenceGradientTest)
	{
		//递变测试的结果与对应的故障参数相关,此处单独处理递变测试结果
		bHasResult = GetResultStringSequenceGradientTest(pValues,bHasActValue,strResultsString,m_oTestMacroResults);
	} //
	else if (strMacroID == STT_MACRO_ID_FaultGradientTest)  //2024-01-03 yuanting  故障递变测试
	{


	} //
	else if(strMacroID == STT_ORG_MACRO_SoeTest)
	{

	}
	else if (strMacroID == STT_MACRO_ID_ULockOverCurrent)
	{
		//复压闭锁测试时,根据实际测试类型显示测试结果
		bHasResult = GetResultStringULockOverCurrent(pValues,bHasActValue,strResultsString,m_oTestMacroResults);
	}
	else if (strMacroID == STT_MACRO_ID_PowerDirection)
	{
		//功率方向测试时,根据实际测试类型显示测试结果
		bHasResult = GetResultStringPowerDirection(pValues,bHasActValue,strResultsString,m_oTestMacroResults);
	}
	//合并单元对时守时测试等,不需要判断结果
	else if ((strMacroID == STT_ORG_MACRO_MUTimingAccurTest)||(strMacroID == STT_ORG_MACRO_MUPunctAccurTest))
	{
	}
	//yzj 2023.12.5 电压动作值部分结果不必要显示
	else if (strMacroID == STT_MACRO_ID_VoltageActValue)
	{
		bHasResult = GetResultStringVoltageActValue(pValues,bHasActValue,strResultsString,m_oTestMacroResults);
	}
	else if (strMacroID == STT_MACRO_ID_CurrentActValue)
	{
		bHasResult = GetResultStringCurrentActValue(pValues,bHasActValue,strResultsString,m_oTestMacroResults);
	}
	//yzj 2023.12.26 搜索阻抗边界
	else if (strMacroID == "DistanceSearch")
	{
		bHasResult = GetResultStringDistanceSearchTest(pValues,bHasActValue,strResultsString,m_oTestMacroResults);
	}
	//dingxy 20240510 状态序列动作值做处理
	else if (strMacroID == STT_MACRO_ID_StateTest)
	{
		bHasResult = GetResultStringStateTest(pValues,bHasActValue,strResultsString,m_oTestMacroResults);
	}
	else
	{
		POS pos = m_oTestMacroResults.GetHeadPosition();

		while(pos)
		{
			pCurrData = (CDvmData*)m_oTestMacroResults.GetNext(pos);
			pResultValue = (CDvmValue*)pValues->FindByID(pCurrData->m_strID);

            if (pResultValue !=nullptr)
			{
				bHasResult = TRUE;

				if (pResultValue->m_strValue != g_sLangTxt_State_NoActioned)
				{
					if (pResultValue->m_strValue == "未动作")
					{
						pResultValue->m_strValue = g_sLangTxt_State_NoActioned;
					}
					else
					{
						dValue = CString_To_double(pResultValue->m_strValue);

						if ((pCurrData->m_strUnit != "°")&&(dValue<= 0.00001))
						{
							pResultValue->m_strValue = g_sLangTxt_State_NoActioned;
						}
						else
						{
							bHasActValue = TRUE;
							strResultsString += pCurrData->m_strName;
							strResultsString += ":";
							long nPrecision = 3;

							if ((dValue>0.000f)&&(dValue<0.001f))
							{
								if (dValue<0.0001f)
								{
									nPrecision = 5;
								}
								else
								{
									nPrecision = 4;
								}
							}

							//strFormat.Format(_T("%%.%dlf"),nPrecision);
							pResultValue->m_strValue = QString::number(dValue,'f',nPrecision);//.Format("%.5lf",dValue);
							strResultsString += pResultValue->m_strValue;
							strResultsString += pCurrData->m_strUnit;
							strResultsString += ";";
						}
					}
					
				}
			}
		}
	}

	if (bHasResult)
	{
		if (!bHasActValue)
		{
			strResultsString += /*_T("未动作")*/g_sLangTxt_State_NoActioned;
		}

		strResultsString += "].";
		CLogPrint::LogString(XLOGLEVEL_RESULT,strResultsString);
	}
}

void QSttTestCntrFrameBase::OpenDialog(const CString &strDialogID)
{
    CString strCurrDialogID;
    strCurrDialogID = strDialogID;
 //   CXMessageBox::information(nullptr,"001","000000" );
	OnCmd_ConnectApp();//连接服务端
 //   CXMessageBox::information(nullptr,"002","000000" );

	//升级程序时,需要保证当前具有足够电量,先获取当前电量信息  20230106 zhouhj
    if ((strCurrDialogID == STT_CNTR_CMD_Liveupdate)||(strCurrDialogID == STT_CNTR_CMD_ULiveupdate))
	{
		CTickCount32 oTickCount;
		long nCurrIndex = 0;

		while((m_oDataBtnsMngr.GetBatCapValue()<0)&&(nCurrIndex<500))//等待获取当前电池电量,,最多等待5s
		{
			oTickCount.DoEvents(10);
			nCurrIndex++;
		}

		show();//在线升级或离线升级时,显示界面,用于在输出窗口界面显示打印信息
		OnCmd_DebugOutPutWidget();
	}

	if (!g_oSttTestResourceMngr.HasLoadDevice())
	{
		g_oSttTestResourceMngr.SelectDeviceFromLocalDB();
	}
	else if (strCurrDialogID == STT_CNTR_CMD_HardConfig || strCurrDialogID == STT_CNTR_CMD_OutputPower)
	{
		CTickCount32 oTickCount;
		long nCurrIndex = 0;

		while((g_oLocalSysPara.m_nRTData_Num <= 0) && (nCurrIndex<200))//dingxy 20240614 硬件设置界面首次等待获取当前风扇档位,最多等待2s
		{
			oTickCount.DoEvents(10);
			nCurrIndex++;
		}
	}

    if (strCurrDialogID == STT_CNTR_CMD_Liveupdate)
	{
		OnCmd_Liveupdate();
	}
    else if (strCurrDialogID == STT_CNTR_CMD_ULiveupdate)
	{
		OnCmd_ULiveupdate();
	}
    else if (strCurrDialogID == STT_CNTR_CMD_PpIotEngineClient)
	{
		OnCmd_PpIotEngineClientDlg();
	}
    else if (strCurrDialogID == STT_CNTR_CMD_CommConfig)
	{
		OnCmd_CommConfiguration();
	}
    else if (strCurrDialogID == STT_CNTR_CMD_PkgMonitor)
	{
		/*OnCmd_PkgMonitor();*/
        //sun OnCmd_PkgMonitorDlg();
	}
    else if (strCurrDialogID == STT_CNTR_CMD_PpXmlFileMngr)
	{
		OnCmd_PpXmlFileMngr();
	}
    else if (strCurrDialogID == STT_CNTR_CMD_DvmFileMngr)
	{
		OnCmd_DvmFileMngr();
	}

    else if (strCurrDialogID == STT_CNTR_CMD_OutputPower)
	{
		OnCmd_OutputPower();
	}
    else if (strCurrDialogID == STT_CNTR_CMD_HardConfig)
	{
		OnCmd_HardConfig();
	}
    else if (strCurrDialogID == STT_CNTR_CMD_VersionInfo)
	{
		OnCmd_VersionInfo();
	}
    else if (strCurrDialogID == STT_CNTR_CMD_FileMngr)
	{
		OnCmd_FileMngr();
	}
    else if (strCurrDialogID == STT_CNTR_CMD_LumPowerView)
	{
		OnCmd_LumPowerView();
	}
    else if (strCurrDialogID == STT_CNTR_CMD_LangSetting)
	{
		OnCmd_LangSettingView();
	}
    else if (strCurrDialogID == STT_CNTR_CMD_IecCapDialog)
	{
		OnCmd_IecCapDialog();
	}
    else if(strCurrDialogID == STT_CNTR_CMD_OutputDebug)
	{
	     OnCmd_OutputDebug();
	}
    else if(strCurrDialogID == STT_CNTR_CMD_LiveupdateDevice)
	{
		OnCmd_LiveupdateDevice();
	}

	m_pTestCtrlCntrBase->CloseTest();
//	g_pTheSttTestApp->ExitSttTestApp();
	this->close();
}

void QSttTestCntrFrameBase::slot_UpdateRptHtml()
{
#ifndef SttTestCntrThread_H
	UpdateRptHtml();
#else
//	CLogPrint::LogFormatString(XLOGLEVEL_RESULT,_T("slot_UpdateRptHtml[+++]."));
	g_theSttTestCntrThread->PostThreadMessage(12, 0, 0);
//	CLogPrint::LogFormatString(XLOGLEVEL_RESULT,_T("slot_UpdateRptHtml[---]."));
#endif
	
}

void QSttTestCntrFrameBase::UpdateRptHtml()
{
    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return;
	}

    char *strReport = nullptr;
	CString strMacroID = g_pTheSttTestApp->m_pTestMacroUI->m_strID;
	long nLen = 0;
	
	GetMacroItemsXml(strMacroID,&strReport, nLen,_T(""));

	if (nLen > 0)
	{
		//2022-4-6  lijunqing
		//m_pSttReportViewHtml->UpdateRptHtml("", strMacroID, strReport);	
		//delete strReport;
        //if (m_pSttReportViewHtml)
        //{
        //	m_pSttReportViewHtml->AddUpdateCmd(g_pTheSttTestApp->m_pTestMacroUI, "", strMacroID, strReport);
        //}
	}
}

long QSttTestCntrFrameBase::OnUpdateSyncTime(CDataGroup *pRtSyncTime)
//GpsTime( long nSyn, long nSecond,long nNSecend,long n4G, long nWifi, long nBle,
//											long nPowerAC, long nBatCap, long nUSB)
{
//	CLogPrint::LogFormatString(XLOGLEVEL_RESULT,_T("OnUpdateSyncTime"));
	emit sig_OnUpdateGpsTime(pRtSyncTime);
	return 0;
}

long QSttTestCntrFrameBase::OnUpdateException()
{
	emit sig_OnUpdateException();
	return 0;
}

void QSttTestCntrFrameBase::slot_OnUpdateException()
{
	UpdateToolButtons_Light();
}

long QSttTestCntrFrameBase::OnItemStateChanged(CExBaseObject *pItem)
{
	//emit sig_OnItemStateChanged_Frame(pItem);
	//m_pItemState = pItem;
	CAutoSimpleLock oLock(m_oCriticSection_ItemStateList);
	CSttItemStateObject* pObj = (CSttItemStateObject*)pItem;
	m_oItemStateList.Add(pItem);
	return 0;
}

void QSttTestCntrFrameBase::EndBinStateOnStarting()
{
	for (int i=0;i<g_nBinCount/*g_oLocalSysPara.m_nCHBinInNum*/;i++)
		m_pTestCtrlCntrBase->m_oCurrEventResult.m_BinIn[i] = 0;

	for (int i=0;i<g_nBinExCount;i++)
		m_pTestCtrlCntrBase->m_oCurrEventResult.m_BinInEx[i] = 0;

	for (int i=0;i<g_nBoutCount/*g_oLocalSysPara.m_nCHBinOutNum*/;i++)
		m_pTestCtrlCntrBase->m_oCurrEventResult.m_BinOut[i] = 0;

	for (int i=0;i<g_nBoutExCount;i++)
		m_pTestCtrlCntrBase->m_oCurrEventResult.m_BinOutEx[i] = 0;
}

long QSttTestCntrFrameBase::OnTestFinished()
{
	if (m_bHasClosedUI)//点击关闭按钮后,不再更新此处
	{
		return 0;
	}

	//2022-12-02  lijunqing
    assist_event(Event_ID_OnTestFinished, nullptr);

	EndBinStateOnStarting();
	emit sig_UpdateToolButtons();
	UpdateCmdButtonsState(STT_TEST_STATE_TEST_FINISHED);	
	emit sig_OnViewTestStop();   //暂时用Stoped来处理Finished的逻辑  shaolei
	UpdateCustomReport();
	return 0;
}

long QSttTestCntrFrameBase::OnTestStarted()
{
//	CLogPrint::LogFormatString(XLOGLEVEL_RESULT,_T("OnTestStarted[++++]."));
	//2022-12-02  lijunqing
    assist_event(Event_ID_OnTestStarted, nullptr);

//	UpdateCmdButtonsState(STT_TEST_STATE_TESTTING);
	emit sig_OnViewTestStart();
//	CLogPrint::LogFormatString(XLOGLEVEL_RESULT,_T("OnTestStarted[----."));
	return 0;
}

long QSttTestCntrFrameBase::OnTestStoped()
{
	if (m_bHasClosedUI)//点击关闭按钮后,不再更新此处
	{
		return 0;
	}

	EndBinStateOnStarting();
	emit sig_UpdateToolButtons();
	
	UpdateCmdButtonsState(STT_TEST_STATE_TEST_STOPED);	
	emit sig_OnViewTestStop();
	UpdateCustomReport();
    assist_event(Event_ID_OnTestFinished, nullptr);
	return 0;
}

void QSttTestCntrFrameBase::slot_UpdateToolButtons()
{
	UpdateToolButtons();
}

void QSttTestCntrFrameBase::slot_OnViewTestStart()
{
//	CLogPrint::LogFormatString(XLOGLEVEL_RESULT,_T("slot_OnViewTestStart[++++]."));
	EnableStartStopButton(TRUE);
//	CLogPrint::LogFormatString(XLOGLEVEL_ERROR,_T("[问题查找]slot_OnViewTestStart(%d)"),(int)m_bInited);

	if(m_bInited)
	{
		//zhouhj 2023.11.2 在每次开始测试后,进行重新的数据更新,启动矢量图等定时器
// 		if ((m_pMacroEditView == nullptr)||(g_pTheSttTestApp->m_pTestMacroUI == nullptr))
// 		{
// 			return;
// 		}
// 
// 		if(g_pTheSttTestApp->m_pTestMacroUI->m_strID == "SystemConfig")
// 		{
// 			//系统参数界面是弹出框，所以没有配置ui-file，会被认定为原生态模块而强转类型错误
// 			return;
// 		}
// 
// 		if (g_pTheSttTestApp->m_pTestMacroUI->IsUIOriginal())
// 		{
// 			((CSttMacroParaEditViewOriginal*)m_pMacroEditView)->OnViewTestStart();
// 		}
// 		//yzj 2022-2-20 仿照原生态功能启动网页的图表刷新
// 		else if(g_pTheSttTestApp->m_pTestMacroUI->IsUIWeb())
// 		{
// 			QSttMacroParaEditViewHtml *pSttMacroParaEditViewHtml = (QSttMacroParaEditViewHtml*)m_pMacroEditView;
// 			pSttMacroParaEditViewHtml->OnViewTestStart();
// 		}

		return;
	}

	m_bInited = true;

	CDataGroup dataGroup;
	dataGroup.AddNewData("Run","1");
	m_oDataBtnsMngr.UpdataDataButtons(&dataGroup);

	m_oTimerAtsTest.start(100);

    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{//Win模式下或者自动测试模式下，没有功能界面
		return;
	}

#ifndef _PSX_QT_LINUX_
	if(g_pTheSttTestApp->m_pTestMacroUI->m_strID == "SystemConfig")
	{
		//win下系统参数界面是弹出框，所以没有配置ui-file，会被认定为原生态模块而强转类型错误
		return;
	}
#endif

    if (m_pMacroEditView == nullptr)
	{
		return;
	}

	if (g_pTheSttTestApp->m_pTestMacroUI->IsUIOriginal())
	{
		((CSttMacroParaEditViewOriginal*)m_pMacroEditView)->OnViewTestStart();
	}
	//yzj 2022-2-20 仿照原生态功能启动网页的图表刷新
	else if(g_pTheSttTestApp->m_pTestMacroUI->IsUIWeb())
	{
        //sun QSttMacroParaEditViewHtml *pSttMacroParaEditViewHtml = (QSttMacroParaEditViewHtml*)m_pMacroEditView;
        //sun pSttMacroParaEditViewHtml->OnViewTestStart();
        //sun pSttMacroParaEditViewHtml->setEnabled(false);
	}

	//20230827  suyang 测试开始特性图不可编辑
    if (m_pCharLibWidget != nullptr)
	{
		m_pCharLibWidget->setEnabled(false);
	}

	//清空缓存的报告内特性曲线png
// 	if(m_pSttCharacterDrawPng)  //zhouhj 2023.8.28 在对应类的InitCharDrawTest函数中进行清除
// 	{
// 		m_pSttCharacterDrawPng->ClearSearchPoints();
// 		m_pSttCharacterDrawPng->ClearPngCache();
// 	}

//	CLogPrint::LogFormatString(XLOGLEVEL_RESULT,_T("slot_OnViewTestStart[----]."));
}

void QSttTestCntrFrameBase::slot_OnViewTestStop()
{
	EnableStartStopButton(TRUE);
	m_bInited = false;
//	CLogPrint::LogFormatString(XLOGLEVEL_ERROR,_T("[问题查找]slot_OnViewTestStop."));

	CDataGroup dataGroup;
	dataGroup.AddNewData("Run","0");
	m_oDataBtnsMngr.UpdataDataButtons(&dataGroup);
	m_oTimerAtsTest.stop();
	//yzj 2022-2-26 打印关闭测试时仍未打印完成的信息
	PrintEventInfo();
	//dingxy 20240704 解决因定时器被杀死，但是报告状态没有更新，更新报告状态
	if(m_oItemStateList.CanRead())
	{
		CExBaseObject *pObj = m_oItemStateList.Read();
		CSttItemStateObject* pObject = (CSttItemStateObject*)pObj;
		slot_OnItemStateChanged_Frame(pObj);
		//			emit sig_OnItemStateChanged_Frame(&pObj);
	}
	//zhouhj 2023.11.7 更新测试结束时间
    //if (m_pSttReportViewHtml)
    //{
    //	m_pSttReportViewHtml->UpdateReportHead_StartEndTestTime(FALSE,TRUE);
    //}

    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return;
	}

    if (m_pMacroEditView == nullptr)
	{
		return;
	}

// 	CString strTestMacroUI_id = g_pTheSttTestApp->m_pTestMacroUI->m_strID;
// 
// 	if (strTestMacroUI_id == STT_MACRO_ID_ChMapsConfig
// 		|| strTestMacroUI_id == STT_MACRO_ID_Iec61850Config
// 		|| strTestMacroUI_id == STT_MACRO_ID_SystemConfig)
// 	{
// 		return;
// 	}

	if (m_pMacroEditView->GetMacroEditViewType() == MACRO_EDIT_VIEW_TYPE_ORIGINAL)
	{
		((CSttMacroParaEditViewOriginal*)m_pMacroEditView)->OnViewTestStop();
	}
	else if (m_pMacroEditView->GetMacroEditViewType() == MACRO_EDIT_VIEW_TYPE_HTML)
	{
        //sun QSttMacroParaEditViewHtml *pSttMacroParaEditViewHtml = (QSttMacroParaEditViewHtml *)m_pMacroEditView;
        //sun pSttMacroParaEditViewHtml->OnViewTestStop();
        //sun pSttMacroParaEditViewHtml->setEnabled(true);
	}

	//20230827  suyang 测试结束特性图恢复编辑
    if (m_pCharLibWidget != nullptr)
	{
		m_pCharLibWidget->setEnabled(true);
	}
// 	if (g_pTheSttTestApp->m_pTestMacroUI->IsUIOriginal())
// 	{
// 		((CSttMacroParaEditViewOriginal*)m_pMacroEditView)->OnViewTestStop();
// 	}
// 	else if(g_pTheSttTestApp->m_pTestMacroUI->IsUIWeb())
// 	{
// 		QSttMacroParaEditViewHtml *pSttMacroParaEditViewHtml = (QSttMacroParaEditViewHtml *)m_pMacroEditView;
// 		pSttMacroParaEditViewHtml->OnViewTestStop();
// 		pSttMacroParaEditViewHtml->setEnabled(true);
// 	}
}

void QSttTestCntrFrameBase::slot_OnViewTestLink(bool b)
{
	if(!g_pTheSttTestApp->m_pTestMacroUI)
	{
		return;
	}

	if(!b)
	{
		m_oTimerAtsTest.stop();
        emit sig_OnUpdateGpsTime(nullptr);//0,0,0,-1,-1,-1,-1,-1,-1);//断开连接后,将对时状态改为未对时
	}

	if (g_pTheSttTestApp->m_pTestMacroUI->IsUIOriginal())
	{
		((CSttMacroParaEditViewOriginal*)m_pMacroEditView)->OnViewTestLink(b);
	}
	else if(g_pTheSttTestApp->m_pTestMacroUI->IsUIWeb())
	{
        //((QSttMacroParaEditViewHtml*)m_pMacroEditView)->OnViewTestLink(b);
	}
}

long QSttTestCntrFrameBase::OnTestCreated()
{
	return 0;
}

void QSttTestCntrFrameBase::OnReport(CExBaseObject *pItem) 
{
	
}

void QSttTestCntrFrameBase::OnReport_ReadDevice(CDataGroup *pDeviceGroup)
{
    if (pDeviceGroup == nullptr)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE,_T("OnReport_ReadDevice函数中pDeviceGroup为空."));
		return;
	}

//	CLogPrint::LogFormatString(XLOGLEVEL_TRACE,_T("OnReport_ReadDevice函数开始执行."));
	CSttAdjDevice oReadDevice;
	CSttAdjDevice *pCurDevice = &g_oSttTestResourceMngr.m_oCurrDevice;
	oReadDevice.AttatchAdjRef(pDeviceGroup);
	oReadDevice.GetAttrs();
	pCurDevice->GetAttrs();
	CString strSysVersion_Read,strSysVersion_Curr;
	strSysVersion_Read = _T("");
	strSysVersion_Curr = _T("");
	pDeviceGroup->GetDataValue(_T("SysVersion"), strSysVersion_Read);

    if (pCurDevice->m_pSttAdjRef == nullptr)
	{
		pCurDevice->m_pSttAdjRef = new CDataGroup();
		pCurDevice->m_pSttAdjRef->SetParent(pCurDevice);
	}

	pDeviceGroup->GetDataValue(_T("SysVersion"), strSysVersion_Curr);
	pCurDevice->m_pSttAdjRef->DeleteAll();
	pDeviceGroup->Copy(pCurDevice->m_pSttAdjRef);

	//如果型号或者装置SN不匹配，则需要重新读取Device信息
	if ((oReadDevice.m_strModel != pCurDevice->m_strModel)||(oReadDevice.m_strSN != pCurDevice->m_strSN)
		||((strSysVersion_Read.GetLength()>0)&&(strSysVersion_Read != strSysVersion_Curr))
		||(g_oSttSystemConfig.GetLockMaps() == 0))//wangtao 20240507 此处增加锁定映射判断
		//如果系统版本号更新,则更新界面参数显示,只有在测试仪重启后才会更新
	{
		pCurDevice->GetAttrs();
		pCurDevice->SortModules();
		pCurDevice->AddMaxVolCurrValue_VolCurrModule();
		g_oSttTestResourceMngr.SetCurSelDevice(pCurDevice->m_strModel,pCurDevice->m_strSN);
		g_oSttTestResourceMngr.SaveCurDeviceFile();
		g_oSttTestResourceMngr.GetAllModuleTags();

        if (g_oSttSystemConfig.GetLockMaps() == 0)
        {
            CSttChMaps oSttChMaps;
			oSttChMaps.DeleteAll();
			g_oSttTestResourceMngr.m_oChMaps.Copy(&oSttChMaps);
            
			if (!g_oSttTestResourceMngr.CreateDefaultChMapsByDevice(&oSttChMaps,g_oSystemParas.m_nIecFormat,g_oSystemParas.m_nHasDigital))
			{
				CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,g_sLangTxt_Gradient_MissingDefaultMappings.GetString()); //缺少硬件资源文件,无法创建缺省通道映射
				return;
			}
            oSttChMaps.Copy(&g_oSttTestResourceMngr.m_oChMaps);
			g_oSttTestResourceMngr.SaveCurChMapsFile();
        }

		emit sig_UpdateTestResource();//发送信号更新软件资源
	}
	else//需要将读取出来的模块的电流档位等信息更新到系统参数中去?????????????在装置型号及编号相同的情况下,无需再重新刷新界面
	{
		pCurDevice->GetAttrs();
		pCurDevice->SortModules();
		pCurDevice->AddMaxVolCurrValue_VolCurrModule();
		g_oSttTestResourceMngr.InitLocalSysPara();//对系统参数等进行重新初始化,将档位等信息填入
		g_oSttTestResourceMngr.SaveCurDeviceFile();
		CString strIDMacroUI = g_pTheSttTestApp->GetCurrTestMacroUI();

		if (strIDMacroUI == STT_ORG_MACRO_ReplayTest)//故障回放模块,需要更新测试资源
		{
			emit sig_UpdateTestResource();//发送信号更新软件资源
		}
	}

    oReadDevice.AttatchAdjRef(nullptr);
}

void QSttTestCntrFrameBase::slot_UpdateTestResource()
{
	OnUpdateTestResource(TRUE);
}

void QSttTestCntrFrameBase::OnAtsGenerate()
{
	if(!m_pMacroEditView)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_ERROR,/*_T("当前测试项为空.")*/g_sLangTxt_Gradient_EmptyCurTI.GetString()); //lcq
		return;
	}
	//20230213 zhangyq
	CSttGuideBook *pSttGuideBook= (CSttGuideBook *)m_pTestCtrlCntrBase->GetGuideBook();
	m_pMacroEditView->ProcessGbAfterGenTemplate(pSttGuideBook);
	emit sig_ShowItems_TreeView((CExBaseList *)pSttGuideBook);//zhouhj 20220326 改为发送信号的方式

    //if (m_pSttReportViewHtml)
    //{
    //	m_pMacroEditView->ProcessRptAfterGenTemplate(m_pSttReportViewHtml);
    //}

	//emit sig_ShowItems_TreeView((CExBaseList *)m_pTestCtrlCntrBase->GetGuideBook());//zhouhj 20220326 改为发送信号的方式
	emit sig_UpdateRptHtml();
}


void QSttTestCntrFrameBase::OnAtsGenerateItems(CExBaseObject *pItems, BOOL bUpdateParent)
{
	emit sig_ShowItems_TreeView((CExBaseList *)pItems);
	UpdateRptHtml();
}

void QSttTestCntrFrameBase::OnAtsGenerateItems_CmdWzd(CExBaseList *pCmdGrp)
{

}

void QSttTestCntrFrameBase::OnAtsGenerateItems_ImportDvm(CExBaseList *pItemsList)
{

}

//2022-9-13  lijunqing
void QSttTestCntrFrameBase::OnAtsQueryItem(CExBaseObject *pItemPara)
{

}

void QSttTestCntrFrameBase::OnInputData(CSttParas *pParas,CExBaseList *pMsgs)
{

}

void QSttTestCntrFrameBase::OnTestDisconnected()
{
	QSttTestCntrFrameBase::OnTestStoped();
}

void QSttTestCntrFrameBase::FillReport(CExBaseObject *pItem)
{

}

void QSttTestCntrFrameBase::FillReport()
{

}

void QSttTestCntrFrameBase::SetTestCtrlCntrBase(CSttTestCtrlCntrBase *pTestCtrlCntrBase)
{
	m_pTestCtrlCntrBase = pTestCtrlCntrBase;
	m_pTestMacroUI_Paras = &pTestCtrlCntrBase->m_oTestMacroUI_Paras;
	m_pTestCtrlCntrBase->SetSttTestCtrlCntrMsgInterface(this);

    if (g_theTestCntrFrame != nullptr)
	{
		g_pGlobalDatas = g_theTestCntrFrame->m_pTestMacroUI_Paras;
	}

    //if (m_pSttReportViewHtml != nullptr)
    //{
    //	m_pSttReportViewHtml->SetGlobalDatas(&m_pTestCtrlCntrBase->m_oTestReportHead);
    //}
}

CSttTestMacroUiParas* QSttTestCntrFrameBase::GetTestMacroUiParas(CSttItems *pRootNodeItems,BOOL bSetMacroTest)
{
	CSttMacroTestUI_TestMacroUI *pTestMacroUI = CSttMacroTestUI_TestMacroUIDB::FindTestMacroUI(pRootNodeItems->m_strstxmlFile);

    if (pTestMacroUI == nullptr)
	{
        return nullptr;
	}

    CSttTestMacroUiParas *pUIParas = nullptr;

	//chenling 20240808 存在个别模块打开模板，获取不到pMacroTest
	pUIParas = pRootNodeItems->GetSttTestMacroUiParas(FALSE);


	if (!pUIParas && pTestMacroUI->IsUIOriginal())
	{
		CSttMacroTest *pMacroTest = (CSttMacroTest *)pRootNodeItems->FindByID(pTestMacroUI->m_strID);

        if (pMacroTest == nullptr)
		{
            return nullptr;
		}

		if (bSetMacroTest)
		{
			SetMacroTest_Original(pMacroTest);
		}
		pUIParas = (CSttTestMacroUiParas *)pMacroTest->FindByClassID(STTGBXMLCLASSID_CSTTTESTMACROUIPARAS);
	}
	else if (pTestMacroUI->IsUIWeb())
	{
		if (bSetMacroTest)
		{
            SetMacroTest_Original(nullptr);
		}

		pUIParas = (CSttTestMacroUiParas *)pRootNodeItems->FindByClassID(STTGBXMLCLASSID_CSTTTESTMACROUIPARAS);
	}

	return pUIParas;
}

void QSttTestCntrFrameBase::AddMacroTestReport()
{//通过命令行的方式，执行单功能测试
	CSttMacroTestUI_TestMacroUI *pTestMacroUI = m_pTestCtrlCntrBase->GetCurrTestMacroUI();

    if (pTestMacroUI != nullptr)
	{
        AddMacroTestReport(pTestMacroUI, nullptr, g_pTheSttTestApp->m_pTestMacroUI->m_strName, g_pTheSttTestApp->m_pTestMacroUI->m_strID);
	}
}

void QSttTestCntrFrameBase::AddMacroTestReport(CSttMacroTestUI_TestMacroUI *pTestMacroUI, CExBaseObject *pParent, const CString &strItemsName, const CString &strItemsID)
{
    char *strReport = nullptr;
//	CString strMacroID = g_pTheSttTestApp->m_pTestMacroUI->m_strID;
	long nLen = 0;
	CString strParentPath;
	strParentPath = _T("");

    if (pParent != nullptr)
	{
		strParentPath = pParent->GetIDPathEx(STTGBXMLCLASSID_CSTTDEVICE, FALSE);
	} 

	GetMacroItemsXml(strItemsID,&strReport, nLen,strParentPath);
	//2022-4-6  lijunqing
	//m_pSttReportViewHtml->AddMacroTestReport("", pTestMacroUI->m_strID, pTestMacroUI, strReport);

    //if (m_pSttReportViewHtml)
    //{
    //	m_pSttReportViewHtml->AddInsertCmd(pTestMacroUI, "", pTestMacroUI->m_strID, strReport);
    //}

// 	if (strReport != nullptr)
// 	{
// 		delete strReport;
// 	}
}

CSttTestResourceBase* QSttTestCntrFrameBase::GetSttTestResource()
{
    if (m_pTestCtrlCntrBase == nullptr)
	{
        return nullptr;
	}

	return m_pTestCtrlCntrBase->m_pSttTestResouce;
}

CSttMacroParaEditInterface* QSttTestCntrFrameBase::CreateSttMacroParaEditView(const CString &strMacroID,const CString &strGridFile, BOOL bUseExist)
{
	return CSttMacroParaEditViewMngr::CreateSttMacroParaEditView(strMacroID,strGridFile,bUseExist);
}

void QSttTestCntrFrameBase::CreateSttMacroParaEditView(CSttMacroTestUI_TestMacroUI *pTestMacroUI)
{
// 	CString strUi_ID;
// 	strUi_ID = pTestMacroUI->m_strUI_ID;
// 
// 	if (strUi_ID.IsEmpty())//20220806 zhouhj 根据界面ID即ui-id打开测试功能界面,为兼容之前环境,如果该ID为空采用原有ID
// 	{
// 		strUi_ID = pTestMacroUI->m_strID;
// 	}

	m_pMacroEditView = CreateSttMacroParaEditView(pTestMacroUI->m_strID/*strUi_ID*/,pTestMacroUI->m_strGirdFile);//2023.7.16 仍改为采用MacroID方式,因为对应函数其他人在其它地方使用时都已默认当成MacroID处理
	QWidget *pMacroEditWidget = GetMacroEditWidget();
	pMacroEditWidget->setParent(this);
	pMacroEditWidget->setGeometry(m_rcWorkArea);

#ifdef _USE_SoftKeyBoard_
	QSoftKeyBoard::AttachObj(this);
#endif
}

void QSttTestCntrFrameBase::InitToolBtnFocusPos(const CString &strBtnID)
{
	CSttFrame_ToolBar *pToolBarParas = m_pSttFrameConfig->GetToolBar();

    if (pToolBarParas != nullptr)//20230301 zhouhj 打开测试功能参数时,切换显示焦点
	{
		CSttFrame_Button *pFrameButton = (CSttFrame_Button*)pToolBarParas->FindBtnByID(strBtnID);

        if (pFrameButton != nullptr)
		{
			QSttToolButtonBase *pPushBtn = (QSttToolButtonBase*)pFrameButton->m_dwItemData;
			pPushBtn->setFocus();
		}
	}
}

CXDrawLine* QSttTestCntrFrameBase::GetCharLibLeftButtonLine()
{
	if(m_pCharLibWidget)
	{
		return m_pCharLibWidget->m_pImpCharactWidget->GetLeftButtonLine();
	}	

    return nullptr;
}

void QSttTestCntrFrameBase::AdjustMacroEditWidgetToFrame(CSttMacroTestUI_TestMacroUI *pTestMacroUI)
{//2022-3-25  调整参数窗口
    //if(m_pSttGbTreeView->m_pTreeCtrl)
    //{
    //    disconnect(m_pSttGbTreeView->m_pTreeCtrl,SIGNAL(itemChanged(QTreeWidgetItem *, int)),m_pSttGbTreeView->m_pTreeCtrl,SLOT(slot_TreeItemChanged(QTreeWidgetItem *, int)));
    //    qDebug() << "Debug sun: before m_pSttGbTreeView->ShowBaseList!!!!";
    //
    //    m_pSttGbTreeView->ShowBaseList((CExBaseList *)m_pTestCtrlCntrBase->GetGuideBook());
    //
    //    qDebug() << "Debug sun: after m_pSttGbTreeView->ShowBaseList!!!!";
    //    connect(m_pSttGbTreeView->m_pTreeCtrl,SIGNAL(itemChanged(QTreeWidgetItem *, int)),m_pSttGbTreeView->m_pTreeCtrl,SLOT(slot_TreeItemChanged(QTreeWidgetItem *, int)));
    //}
	QWidget *pMacroEditWidget = GetMacroEditWidget();
	if (pTestMacroUI->IsUIOriginal())
	{
		SetActiveWidget(pMacroEditWidget, ActiveWidgetType_MacroUI_Original);
	}
	else
	{
		SetActiveWidget(pMacroEditWidget, ActiveWidgetType_MacroUI_Html);
	}

}

BOOL QSttTestCntrFrameBase::CreateEngineClientWidget()
{
	return FALSE;
}

void QSttTestCntrFrameBase::InitAllButtonStateByTestMacroUI(CSttMacroTestUI_TestMacroUI *pTestMacroUI)
{
    if (pTestMacroUI == nullptr)
	{
		return;
	}

	if (g_pTheSttTestApp->m_pTestMacroUI->HasCharLib())
	{
		UpdateButtonStateByID(STT_CNTR_CMD_CharDrawView,true,true);
	}
	else
	{
		UpdateButtonStateByID(STT_CNTR_CMD_CharDrawView,false,false);
	}

	//未选择测试功能时，“开始测试”按钮使能为FALSE
	if (pTestMacroUI->m_strID != _T(""))
	{
		UpdateButtonStateByID(STT_CNTR_CMD_StartTest,true,true);
	}
	else
	{
		UpdateButtonStateByID(STT_CNTR_CMD_StartTest,false,true);
	}

	//系统参数页面，未勾选“数字”，应隐藏“IEC配置”按钮 sf 20220317
	if (!g_oSystemParas.HasDigitalInOrOut())
	{
		UpdateButtonStateByID(STT_CNTR_CMD_IECConfig,false,false);
	}
	else 
	{
		UpdateButtonStateByID(STT_CNTR_CMD_IECConfig,true,true);
	}

	//状态序列才使用手动触发这个按钮，其他不用，隐藏 sf 20220218
	if (HasManuTrigerBtn()/*pTestMacroUI->m_strID == STT_ORG_MACRO_StateTest*/)
	{
		UpdateButtonStateByID(STT_CNTR_CMD_ManuTriger,false,true);
	}
	else
	{
		UpdateButtonStateByID(STT_CNTR_CMD_ManuTriger,false,false);
	}
}

void QSttTestCntrFrameBase::OpenMacroTestUI(CSttMacroTestUI_TestMacroUI *pTestMacroUI, const CString &strItemsName, const CString &strItemsID
											, long nRepeatTimes, long nRptTitle, long nTitleLevel)
{
    if (pTestMacroUI == nullptr)
	{
		return;
	}
	
	if (g_nLogDebugInfor == 1)
	{
		CLogPrint::LogString(XLOGLEVEL_TRACE, ">> begin OpenMacroTestUI >>");
	}

    SetActiveWidget(nullptr);

	//第一步：创建参数编辑页面、加载报告html页面
	m_pTestCtrlCntrBase->OpenMacroTestUI(pTestMacroUI);

	//2022-3-27  lijunqing  创建参数编辑窗口
	CreateSttMacroParaEditView(pTestMacroUI);

	if (g_nLogDebugInfor == 1)	{		CLogPrint::LogString(XLOGLEVEL_TRACE, ">> begin OpenMacroTestUI 2 >>");	}

	if (pTestMacroUI->IsUIOriginal())
	{//原生态网页，获取页面参数数据
        if (m_pMacroEditView != nullptr)
		{
			m_pMacroEditView->GetDatas(m_pTestMacroUI_Paras);
		}
	}
	else//网页界面的矢量图、状态图、信息图在此处统一初始化,原生界面在各自构造函数中初始化 zhouhj 20220329
	{
		InitBinaryIn_WebUI(m_pTestMacroUI_Paras);
        g_theTestCntrFrame->InitVectorWidget(nullptr,nullptr);
        g_theTestCntrFrame->InitPowerWidget(nullptr,nullptr);
		g_theTestCntrFrame->InitStateMonitor();
		g_theTestCntrFrame->ClearInfoWidget();	
	}

	InitAfterCreateSttMacroPara();

	if (pTestMacroUI->HasCharLib()) //2022-6-30  lijunqing
	{
		g_theTestCntrFrame->InitCharLibWidget();
	}

	if (pTestMacroUI->m_strUI_File.GetLength() > 0)
	{
        //QSttMacroParaEditViewHtml *pSttMacroParaEditViewHtml = (QSttMacroParaEditViewHtml*)m_pMacroEditView->m_pMacroParaEditWnd;
        //pSttMacroParaEditViewHtml->OpenHtmlFile(pTestMacroUI->m_strUI_File);
	}

	AdjustMacroEditWidgetToFrame(pTestMacroUI);
	InitAllButtonStateByTestMacroUI(pTestMacroUI);//根据测试功能初始化工具栏等按钮

	AdjustToolBarButtons();
	CExBaseObject *pSel = m_pSttGbTreeView->GetCurrSelectGbItem();

    if ((m_pSttGbTreeView!= nullptr)&&(pSel != nullptr))
	{
		CString strCurrRootNodePath;
		strCurrRootNodePath = pSel->GetIDPathEx(STTGBXMLCLASSID_CSTTDEVICE, FALSE);

		if (strCurrRootNodePath.IsEmpty())
		{
			strCurrRootNodePath = strItemsID;
		} 
		else
		{
			strCurrRootNodePath.AppendFormat(_T("$%s"),strItemsID.GetString());
		}

		m_pSttGbTreeView->m_strCurrSelRootNodePath = strCurrRootNodePath;
	}
	

	//if (! g_bIsOpenMacroFromMain)
	{
		AddMacroTestReport(pTestMacroUI, pSel, strItemsName, strItemsID);
	}

	//若有特性曲线，打开特性曲线定义，在测试模板生成后，返回的模板信息中如果不带测试模板，则使用默认测试模板
	CString strFile;
	GetCharacteristicsFile(pTestMacroUI, strFile);
	m_pCharacteristics->DeleteAll();

	if (IsFileExist(strFile))
	{
		m_pCharacteristics->OpenXmlFile(strFile,CCharacteristicXmlRWKeys::CCharacteristicsKey(),CCharacteristicXmlRWKeys::g_pXmlKeys);
	}

	//发送特性曲线改变事件
	if (pTestMacroUI->HasCharLib()) //2022-6-30  lijunqing
	{
		m_pCharLibWidget->InitCharacteristicsLib(pTestMacroUI->m_strUI_ID,pTestMacroUI->m_strCharlibFile);
		m_pCharLibWidget->GroupDatasToChar(m_pTestMacroUI_Paras);
		m_pCharLibWidget->ShowCharacteristics(m_pCharacteristics);
		m_pCharLibWidget->m_strCharParasFile = strFile;

        if (m_pCharactWidgetForTest != nullptr)
		{
			m_pCharactWidgetForTest->InitCharacteristic(pTestMacroUI->m_strID);
		}

		if (m_pCharTestPointsGrid)
		{
			m_pCharTestPointsGrid->InitMacroID(pTestMacroUI->m_strID);
		}
	}

	//2022-3-21 李俊庆 最后发送生成模板指令，保证添加报告完成
    CLogPrint::LogString(XLOGLEVEL_TRACE, ">> begin GenerateTemplate >>");

#ifndef SttTestCntrThread_H
	bool bGenSucc = GenerateTemplate(pSel, strItemsName, strItemsID, nRepeatTimes, nRptTitle, nTitleLevel);
#else
	g_theSttTestCntrThread->m_pParentItems = pSel;
	g_theSttTestCntrThread->m_strItemsName = strItemsName;
	g_theSttTestCntrThread->m_strItemsID = strItemsID;
	g_theSttTestCntrThread->PostThreadMessage(10, 0, 0);
#endif
	CLogPrint::LogString(XLOGLEVEL_TRACE, ">> end GenerateTemplate >>");

	if (g_nLogDebugInfor == 1)
	{
		CLogPrint::LogString(XLOGLEVEL_TRACE, ">> end OpenMacroTestUI >>");
	}

	UpdateToolButtons();
	InitToolBtnFocusPos(STT_CNTR_CMD_TemplateView);
}

void QSttTestCntrFrameBase::OpenMacroTestUI_Test(CSttMacroTestUI_TestMacroUI *pTestMacroUI, const CString &strItemsName, const CString &strItemsID
												 , long nRepeatTimes, long nRptTitle)
{
    if (pTestMacroUI == nullptr)
	{
        qDebug() << "pTestMacroUI is nulllllllllllllllllllllllllllllllllllllllll";
		return;
	}

	if (g_nLogDebugInfor == 1)
	{
		CLogPrint::LogString(XLOGLEVEL_TRACE, ">> begin OpenMacroTestUI >>");
	}

    SetActiveWidget(nullptr);

	//第一步：创建参数编辑页面、加载报告html页面
	m_pTestCtrlCntrBase->OpenMacroTestUI(pTestMacroUI);
qDebug() << "!!!!!!!! after m_pTestCtrlCntrBase->OpenMacroTestUI(pTestMacroUI)";
	//2022-3-27  lijunqing  创建参数编辑窗口
	CreateSttMacroParaEditView(pTestMacroUI);
qDebug() << "Debug sun: fQSttTestCntrFrameBase::OpenMacroTestUI_Test!!!! 1";
	if (g_nLogDebugInfor == 1)	{		CLogPrint::LogString(XLOGLEVEL_TRACE, ">> begin OpenMacroTestUI 2 >>");	}

	if (pTestMacroUI->IsUIOriginal())
	{//原生态网页，获取页面参数数据
        if (m_pMacroEditView != nullptr)
		{
			m_pMacroEditView->GetDatas(m_pTestMacroUI_Paras);
		}
	}
	else//网页界面的矢量图、状态图、信息图在此处统一初始化,原生界面在各自构造函数中初始化 zhouhj 20220329
	{
		InitBinaryIn_WebUI(m_pTestMacroUI_Paras);
        g_theTestCntrFrame->InitVectorWidget(nullptr,nullptr);
        g_theTestCntrFrame->InitPowerWidget(nullptr,nullptr);
		g_theTestCntrFrame->InitStateMonitor();
		g_theTestCntrFrame->ClearInfoWidget();	
	}
	InitAfterCreateSttMacroPara();
	if (pTestMacroUI->HasCharLib()) //2022-6-30  lijunqing
	{
		g_theTestCntrFrame->InitCharLibWidget();
	}

	if (pTestMacroUI->m_strUI_File.GetLength() > 0)
	{
        //sun QSttMacroParaEditViewHtml *pSttMacroParaEditViewHtml = (QSttMacroParaEditViewHtml*)m_pMacroEditView->m_pMacroParaEditWnd;
        //sun pSttMacroParaEditViewHtml->OpenHtmlFile(pTestMacroUI->m_strUI_File);
	}
	AdjustMacroEditWidgetToFrame(pTestMacroUI);
	InitAllButtonStateByTestMacroUI(pTestMacroUI);//根据测试功能初始化工具栏等按钮
	AdjustToolBarButtons();
    //CExBaseObject *pSel = m_pSttGbTreeView->GetCurrSelectGbItem();

    //if ((m_pSttGbTreeView!= nullptr)&&(pSel != nullptr))
    //{
    //	CString strCurrRootNodePath;
    //	strCurrRootNodePath = pSel->GetIDPathEx(STTGBXMLCLASSID_CSTTDEVICE, FALSE);
    //
    //	if (strCurrRootNodePath.IsEmpty())
    //	{
    //		strCurrRootNodePath = strItemsID;
    //	}
    //	else
    //	{
    //		strCurrRootNodePath.AppendFormat(_T("$%s"),strItemsID.GetString());
    //	}
    //
    //	m_pSttGbTreeView->m_strCurrSelRootNodePath = strCurrRootNodePath;
    //}


	//if (! g_bIsOpenMacroFromMain)
    //{
    //	AddMacroTestReport(pTestMacroUI, pSel, strItemsName, strItemsID);
    //}
	//若有特性曲线，打开特性曲线定义，在测试模板生成后，返回的模板信息中如果不带测试模板，则使用默认测试模板
    CString strFile;
    GetCharacteristicsFile(pTestMacroUI, strFile);
	m_pCharacteristics->DeleteAll();

    if (IsFileExist(strFile))
    {
        m_pCharacteristics->OpenXmlFile(strFile,CCharacteristicXmlRWKeys::CCharacteristicsKey(),CCharacteristicXmlRWKeys::g_pXmlKeys);
    }

	//发送特性曲线改变事件
	if (pTestMacroUI->HasCharLib()) //2022-6-30  lijunqing
	{
		m_pCharLibWidget->InitCharacteristicsLib(pTestMacroUI->m_strUI_ID,pTestMacroUI->m_strCharlibFile);
		m_pCharLibWidget->GroupDatasToChar(m_pTestMacroUI_Paras);
		m_pCharLibWidget->ShowCharacteristics(m_pCharacteristics);
        //sun m_pCharLibWidget->m_strCharParasFile = strFile;

        if (m_pCharactWidgetForTest != nullptr)
		{
			m_pCharactWidgetForTest->InitCharacteristic(pTestMacroUI->m_strID);
		}

		if (m_pCharTestPointsGrid)
		{
			m_pCharTestPointsGrid->InitMacroID(pTestMacroUI->m_strID);
		}
	}

	//2022-3-21 李俊庆 最后发送生成模板指令，保证添加报告完成
    CLogPrint::LogString(XLOGLEVEL_TRACE, ">> begin GenerateTemplate >>");

#ifdef _PSX_OS_CENTOS_
    bool bGenSucc = GenerateTemplate(pSel, strItemsName, strItemsID, nRepeatTimes, nRptTitle);
#else
#ifndef SttTestCntrThread_H
	bool bGenSucc = GenerateTemplate(pSel, strItemsName, strItemsID, nRepeatTimes, nRptTitle);
#else
    //g_theSttTestCntrThread->m_pParentItems = pSel;
    g_theSttTestCntrThread->m_strItemsName = strItemsName;
    g_theSttTestCntrThread->m_strItemsID = strItemsID;
    g_theSttTestCntrThread->PostThreadMessage(10, 0, 0);
#endif
#endif
	CLogPrint::LogString(XLOGLEVEL_TRACE, ">> end GenerateTemplate >>");

	if (g_nLogDebugInfor == 1)
	{
		CLogPrint::LogString(XLOGLEVEL_TRACE, ">> end OpenMacroTestUI >>");
	}

	UpdateToolButtons();
	InitToolBtnFocusPos(STT_CNTR_CMD_TemplateView);
}

void QSttTestCntrFrameBase::UpdateButtonsStateByID(const CString &strButtonID, BOOL bEnable)
{
	CSttFrame_Button *pBtn = m_pSttFrameConfig->FindBtnByID(strButtonID);

    if (pBtn != nullptr)
	{
		QSttToolButtonBase *pButton = (QSttToolButtonBase*)pBtn->m_dwItemData;

        if (pButton != nullptr)
		{
			pButton->setEnabled(bEnable);
		}
	}
}

void QSttTestCntrFrameBase::AdjustToolBarButtons()
{
}

void QSttTestCntrFrameBase::AdjustStatusBarButtons()
{
}

void QSttTestCntrFrameBase::Before_OnCmd()
{

}

void QSttTestCntrFrameBase::UpdateStartStopButtonByItemCount()
{
	long nCount = m_pTestCtrlCntrBase->GetGbItemCount();
	QSttToolButtonBase *pButton = (QSttToolButtonBase*)m_pStartTestBtn->m_dwItemData;

	if (nCount == 0)
	{
		pButton->setEnabled(FALSE);
	}
	else
	{
		pButton->setEnabled(TRUE);
	}
}

void QSttTestCntrFrameBase::UpdateToolButtons_FloatPanel()
{

}

CSttMacroParaEditInterface* QSttTestCntrFrameBase::GetMacroEditView()
{
	return m_pMacroEditView;
}

QCharTestPointsGrid* QSttTestCntrFrameBase::GetCharTestPointsGrid()
{
	return m_pCharTestPointsGrid;
}

void QSttTestCntrFrameBase::ClearItemStateList()
{
//	CAutoSimpleLock oLock(m_oCriticSection_ItemStateList);
	m_oItemStateList.Clear();
}

BOOL QSttTestCntrFrameBase::MUTestValid()
{
	if (g_bSmartCap_RecordNow)
	{
		return TRUE;
	}

	CString strIDMacroUI = g_pTheSttTestApp->GetCurrTestMacroUI();

	if ((strIDMacroUI != STT_ORG_MACRO_MUAccuracyTest)&&
		(strIDMacroUI != STT_ORG_MACRO_MUFirstCycleTest)&&
		(strIDMacroUI != STT_ORG_MACRO_MUAccurAutoTest)&&
		(strIDMacroUI != STT_ORG_MACRO_MUAutoTest))
	{
		return TRUE;
	}

	return FALSE;
}

void QSttTestCntrFrameBase::OpenMacroTestUI_OnlyCreate(CSttMacroTestUI_TestMacroUI *pTestMacroUI)
{
    if (pTestMacroUI == nullptr)
	{
		return;
	}
	
	//直接创建新的页面，CreateSttMacroParaEditView第二个参数设置为false
	m_pMacroEditView = CreateSttMacroParaEditView(pTestMacroUI->m_strID,pTestMacroUI->m_strGirdFile, FALSE);

	if (pTestMacroUI->IsUIOriginal())
	{//原生态网页，获取页面参数数据
		m_pMacroEditView->SetDatas(m_pTestMacroUI_Paras);
	}

	if (pTestMacroUI->m_strUI_File.GetLength() > 0)
	{
        //QSttMacroParaEditViewHtml *pSttMacroParaEditViewHtml = (QSttMacroParaEditViewHtml*)m_pMacroEditView->m_pMacroParaEditWnd;
        //pSttMacroParaEditViewHtml->OpenHtmlFile(pTestMacroUI->m_strUI_File);
	}

	QWidget *pMacroEditWidget = GetMacroEditWidget();
	pMacroEditWidget->setParent(this);
	pMacroEditWidget->setGeometry(m_rcWorkArea);
}

//多功能测试模板编辑模式
void QSttTestCntrFrameBase::AddMacroTestReport(const CString &strParentItemsPath, const CString &strItemsID, CSttMacroTestUI_TestMacroUI *pTestMacroUI)
{

}


BOOL QSttTestCntrFrameBase::SwitchMacroViewByCurrSel(CSttItems *pCurrSelRootNode)
{
	return FALSE;
}

void QSttTestCntrFrameBase::OpenMacroTestUI(CSttTestMacroUiParas *pUIParas, CSttMacroTestUI_TestMacroUI *pTestMacroUI
											,CSttTestMacroCharParas *pSttTestMacroCharParas)
{
    if (pUIParas == nullptr)
	{
		return;
	}

    if (pTestMacroUI == nullptr)
	{
		return;
	}

	if (g_nLogDebugInfor == 1)
	{
		CLogPrint::LogString(XLOGLEVEL_TRACE, ">> begin OpenMacroTestUI >>");
	}

	m_pTestCtrlCntrBase->SetCurrTestMacroUI(pTestMacroUI);//2023.3.23 zhouhj
    SetActiveWidget(nullptr);

	//2022-3-27  lijunqing  创建参数编辑窗口
	CreateSttMacroParaEditView(pTestMacroUI, TRUE);

	if (g_nLogDebugInfor == 1)	{		CLogPrint::LogString(XLOGLEVEL_TRACE, ">> begin OpenMacroTestUI 2 >>");	}

	m_pTestMacroUI_Paras->DeleteAll();

	BSTR bstrText = pUIParas->m_strParaText.AllocSysString();
	CDataMngrXmlRWKeys::g_pXmlKeys->m_nIsGroupUseDvmData++;
	m_pTestMacroUI_Paras->SetXml(bstrText, CDataMngrXmlRWKeys::g_pXmlKeys);
	CDataMngrXmlRWKeys::g_pXmlKeys->m_nIsGroupUseDvmData--;

#ifdef _PSX_IDE_QT_
	delete bstrText;
#else
	SysFreeString(bstrText);
#endif

	if (pTestMacroUI->IsUIOriginal())
	{
		if (pTestMacroUI->m_strID != STT_ORG_MACRO_Iec61850Config
			&& pTestMacroUI->m_strID != STT_ORG_MACRO_SystemConfig
			&& pTestMacroUI->m_strID != STT_ORG_MACRO_ChMapsConfig)
		{
            if (m_pMacroEditView != nullptr)
			{
				m_pMacroEditView->SetDatas(m_pTestMacroUI_Paras);

				//zhouhj 2023.9.15 暂时在此处处理，防止测试功能保存模板后,结构体增加了新的参数,导致后期获取的数据数量与之前不一致,
				//每次切换测试功能时,都会提示参数保存
				m_pTestMacroUI_Paras->DeleteAll();
				m_pMacroEditView->GetDatas(m_pTestMacroUI_Paras);
			}
		}
	}

	if (pTestMacroUI->m_strUI_File.GetLength() > 0)
	{
        //sun QSttMacroParaEditViewHtml *pSttMacroParaEditViewHtml = (QSttMacroParaEditViewHtml*)m_pMacroEditView->m_pMacroParaEditWnd;
        //sun pSttMacroParaEditViewHtml->OpenHtmlFile(pTestMacroUI->m_strUI_File);
		//重新刷新网页的矢量图、状态图、信息图
        g_theTestCntrFrame->InitVectorWidget(nullptr,nullptr);
        g_theTestCntrFrame->InitPowerWidget(nullptr,nullptr);
		g_theTestCntrFrame->InitStateMonitor();
		g_theTestCntrFrame->ClearInfoWidget();
		//g_theTestCntrFrame->InitFAParasSetDialog();
	}

	AdjustMacroEditWidgetToFrame(pTestMacroUI);

	AdjustToolBarButtons();

	if (g_nLogDebugInfor == 1)
	{
		CLogPrint::LogString(XLOGLEVEL_TRACE, ">> end OpenMacroTestUI >>");
	}

	if (pTestMacroUI->IsUIOriginal())
	{
        if (m_pMacroEditView != nullptr)
		{
			CSttMacroParaEditViewOriginal* pMacro = (CSttMacroParaEditViewOriginal*)m_pMacroEditView;
			pMacro->m_bIsOpenMacroFinished = TRUE;
		}
	}
}

void QSttTestCntrFrameBase::CreateSttMacroParaEditView(CSttMacroTestUI_TestMacroUI *pTestMacroUI, BOOL bUseExist)
{
	if (pTestMacroUI->m_strID == STT_ORG_MACRO_Iec61850Config
		|| pTestMacroUI->m_strID == STT_ORG_MACRO_SystemConfig
		|| pTestMacroUI->m_strID == STT_ORG_MACRO_ChMapsConfig)
	{
		return;
	}

	m_pMacroEditView = CreateSttMacroParaEditView(pTestMacroUI->m_strID,pTestMacroUI->m_strGirdFile, bUseExist);
	QWidget *pMacroEditWidget = GetMacroEditWidget();
	pMacroEditWidget->setParent(this);
	pMacroEditWidget->setGeometry(m_rcWorkArea);
}

void QSttTestCntrFrameBase::DeleteMacroTestReport(const CString &strParentItemsPath, const CString &strItemsID)
{
    //if (m_pSttReportViewHtml == nullptr)
    //{
    //	return;
    //}
    //
    //m_pSttReportViewHtml->DeleteMacroTestReport(strParentItemsPath, strItemsID);
}

void QSttTestCntrFrameBase::UpdateRptHtml(const CString &strItemsID,const CString &strMacroUI_ID,const CString &strParentPath)
{
    //if (m_pSttReportViewHtml == nullptr)
    //{
    //	return;
    //}

    char *strReport = nullptr;
	long nLen = 0;

	GetMacroItemsXml(strItemsID, &strReport, nLen,strParentPath);

	CSttMacroTestUI_TestMacroUI *pTestMacroUI = CSttMacroTestUI_TestMacroUIDB::FindTestMacroUI(strMacroUI_ID);

    //if ((nLen > 0)&& (pTestMacroUI!= nullptr))
    //{
    //	m_pSttReportViewHtml->AddUpdateCmd(pTestMacroUI, strParentPath, strItemsID, strReport);
    //}
// 	if (m_pSttReportViewHtml == nullptr)
// 	{
// 		return;
// 	}
// 
// 	char *strReport = nullptr;
// 	long nLen = 0;
// 
// 	GetMacroItemsXml(&strReport, nLen);
// 
// 	if (nLen > 0)
// 	{
// 		m_pSttReportViewHtml->AddUpdateCmd(g_pTheSttTestApp->m_pTestMacroUI, "", strItemsID, strReport);
// 	}
}

void QSttTestCntrFrameBase::SetMacroTest_Original(CExBaseObject *pMacroTest)
{

}

void QSttTestCntrFrameBase::SelectTestMacro_CmdWzd(const CString &strTestMacroUI, const CString &strItemsName
												   , const CString &strItemsID, CDataGroup *pCommCmd
												   , const CString &strTestClass, const CString &strDvmFile
												   , long nRepeatTimes, long nRptTitle, long nTitleLevel)
{

}

void QSttTestCntrFrameBase::OnDeleteCurr(CExBaseObject *pCurrObj)
{

}

void QSttTestCntrFrameBase::OnSaveCurr(CExBaseObject *pCurrObj)
{

}
//2022-9-11  lijunqing
void QSttTestCntrFrameBase::ViewCmdEditWidget(CExBaseObject *pSelObj)
{

}

//2022-9-13  lijunqing
void QSttTestCntrFrameBase::ViewMacroEditWidget(CExBaseObject *pSelObj)
{
	
}

//2022-9-12 lijunqing
void QSttTestCntrFrameBase::SaveMacroParasToCurrWzd(CDataGroup *pCommCmd)
{

}

BOOL QSttTestCntrFrameBase::OpenSclFile()
{
	return FALSE;
}

CString QSttTestCntrFrameBase::SelIedFromScl()
{
	return _T("");
}

void QSttTestCntrFrameBase::InitConfig(const CString &strFrameCfgFile)
{
	m_pSttFrameConfig = CSttFrameConfig::Create(strFrameCfgFile);

//	CXMessageBox::information(nullptr,"Title",m_pSttFrameConfig->m_strFile);
	CString strTestMacroResultsFilePath,strTestMacroBinSelected, strSafetyMsgCfgs;
	strTestMacroResultsFilePath = _P_GetConfigPath();
	strTestMacroResultsFilePath += _T("SttTestMacroResults.xml");//2023.3.11 zhouhj 用于测试结果输出栏显示需要的测试结果ID
	strTestMacroBinSelected = _P_GetConfigPath();//2023.3.11 zhouhj 用于配置网页功能界面参数中,不同测试功能开入选择ID不一样时,进行ID映射使用
	strTestMacroBinSelected += _T("SttTestMacroBinSelected.xml");

	//预置的接线提示信息配置
	strSafetyMsgCfgs = _P_GetConfigPath();
	strSafetyMsgCfgs += _T("SttSafetyMsgCfg.xml");

	CSttCmdDefineXmlRWKeys::g_pXmlKeys->m_nIsGroupUseDvmData++;
	m_oTestMacroResults.OpenXmlFile(strTestMacroResultsFilePath,CSttCmdDefineXmlRWKeys::g_pXmlKeys);
#ifndef NOT_USE_XLANGUAGE
	xlang_TranslateByResourceFileEx(&m_oTestMacroResults, _T("SttTestMacroResults.xml"));
#endif
	m_oBinaryInParas.OpenXmlFile(strTestMacroBinSelected,CSttCmdDefineXmlRWKeys::g_pXmlKeys);
#ifndef _PSX_QT_LINUX_//zhouhj 2024.4.11 在Linux下暂时不使用此方式
	m_oSafetyMsgCfgs.OpenXmlFile(strSafetyMsgCfgs, CSttSafetyMsgCfgXmlRWKeys::g_pXmlKeys);
#endif

	CSttCmdDefineXmlRWKeys::g_pXmlKeys->m_nIsGroupUseDvmData--;
	//xlang_TranslateByResourceFile(m_pSttFrameConfig,"TestCntrlFrameConfig.xml");
	g_nLogDebugInfor = m_pSttFrameConfig->m_nLogDebugInfor;
	m_nSelMacroShow = m_pSttFrameConfig->m_nSelMacroShow;
	CVerUpdateCfgXmlRWKeys::Create();
}

void QSttTestCntrFrameBase::ReleaseConfig()
{
	CVerUpdateCfgXmlRWKeys::Release();
	CSttFrameConfig::Release();
}

void QSttTestCntrFrameBase::GetCharacteristicsFile(CSttMacroTestUI_TestMacroUI *pTestMacroUI, CString &strFile)
{
    if (pTestMacroUI == nullptr)
	{
		return;
	}

	//2022-9-4  lijunqing 缺省、默认的特性曲线，保存到和测试参数相同的路径，文件名后面增加_Char
    //sun CString strTitle;
    //sun strTitle = GetFileTitleFromFilePath(g_pTheSttTestApp->m_pTestMacroUI->m_strUI_ParaFile);
    //sun strTitle += _T("_Char");
    //sun strFile = stt_ui_GetParasFile(g_pTheSttTestApp->m_pTestMacroUI->m_strUI_ParaFile);
    //sun strFile = ChangeFileName(strFile, strTitle);
}

//2022-9-4  lijunqing
void QSttTestCntrFrameBase::InitCharacteristics(CSttContents *pContents)
{
    if (m_pCharacteristics == nullptr || pContents == nullptr)
	{
		return;
	}

	if (pContents->m_strText.GetLength() <= 20)
	{
		return;
	}

	m_pCharacteristics->DeleteAll();
	BSTR bstrText = pContents->m_strText.AllocSysString();
	m_pCharacteristics->SetXml(bstrText, CCharacteristicXmlRWKeys::g_pXmlKeys);

#ifdef _PSX_IDE_QT_
	delete bstrText;
#else
	SysFreeString(bstrText);
#endif

	//发送特性曲线改变事件
	m_pCharLibWidget->ShowCharacteristics(m_pCharacteristics);
}

CSttFrame_Button* QSttTestCntrFrameBase::GetStartTestBtn()
{
    if (m_pStartTestBtn != nullptr)
	{
		return m_pStartTestBtn;
	}

	m_pStartTestBtn = m_pSttFrameConfig->FindStartStopBtn();
	return m_pStartTestBtn;
}

CSttFrame_Button* QSttTestCntrFrameBase::GetManualTriggerBtn()
{
    if (m_pManualTriggerBtn != nullptr)
	{
		return m_pManualTriggerBtn;
	}

	m_pManualTriggerBtn = m_pSttFrameConfig->FindBtnByID(STT_CNTR_CMD_ManuTriger);
	return m_pManualTriggerBtn;
}

CSttFrame_Button* QSttTestCntrFrameBase::GetExitBtn()
{
    if (m_pExitBtn != nullptr)
	{
		return m_pExitBtn;
	}

	m_pExitBtn = m_pSttFrameConfig->FindBtnByID(STT_CNTR_CMD_Exit);
	return m_pExitBtn;
}

void QSttTestCntrFrameBase::InitIcon(const CString& strItemID, const QIcon& icon)
{
    CSttFrame_Button* pTestBtn = nullptr;

	if ((strItemID == STT_CNTR_CMD_StartTest)||(strItemID == STT_CNTR_CMD_StopTest))
	{
		pTestBtn = GetStartTestBtn();
	}
	else
	{
		pTestBtn = m_pSttFrameConfig->FindBtnByID(strItemID);
	}
	
	if(pTestBtn)
	{
		QSttToolButtonBase *pButton = (QSttToolButtonBase*)pTestBtn->m_dwItemData;
		QRect rc = pButton->rect();	

		if(pTestBtn->m_strIcon.GetLength())
		{
			//存在用户自定义的图片名称
			QString strPath = _P_GetResourcePath();
			strPath += pTestBtn->m_strIcon;
			QPixmap pixmap = QIcon(strPath).pixmap(QSize(110, 110));
			QIcon tempIcon = QIcon(pixmap.scaled(pButton->width(), pButton->height()));
			pButton->setIcon(tempIcon);
		}
		else
		{
			//否则采用默认图片		
			QPixmap pixmap = icon.pixmap(QSize(110, 110));
			QIcon tempIcon = QIcon(pixmap.scaled(pButton->width(), pButton->height()));
			pButton->setIcon(tempIcon);
		}
		pButton->setIconSize(QSize(pButton->width(), pButton->height()));
		pButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
		pButton->setAutoRaise(true);
	}
}

void QSttTestCntrFrameBase::InitIcon(const CString& strItemID, const CString& strIcon)
{
    CSttFrame_Button* pTestBtn = nullptr;

	if ((strItemID == STT_CNTR_CMD_StartTest)||(strItemID == STT_CNTR_CMD_StopTest))
	{
		pTestBtn = GetStartTestBtn();
	}
	else
	{
		pTestBtn = m_pSttFrameConfig->GetToolBar()->FindBtnByID(strItemID);
	}

//	CSttFrame_Button* pTestBtn = m_pSttFrameConfig->GetToolBar()->FindBtnByID(strItemID);
	if(pTestBtn)
	{
		QSttToolButtonBase *pButton = (QSttToolButtonBase*)pTestBtn->m_dwItemData;
#ifdef _PSX_QT_LINUX_
		pButton->setStyleSheet(g_strQToolButtonStyleSheet);
#endif

// 		pButton->setStyleSheet("QToolButton:focus{ "
// 			"border: none; "
// 			"padding: 0px; "
// 			"background-color:rgb(255,0,0);"
// 			"}");
	}
}

void QSttTestCntrFrameBase::InitIcon()
{
	if (g_nLogDebugInfor == 1)	{		CLogPrint::LogString(XLOGLEVEL_TRACE, ">> begin InitIcon >>");	}

	//初始化按钮图标
	CSttFrame_ToolBar* pSttFrameButtons = m_pSttFrameConfig->GetToolBar();
	CSttFrame_Button* pBtnStart = m_pSttFrameConfig->FindStartStopBtn();
	CSttFrame_Button* pBtnTriger = m_pSttFrameConfig->FindBtnByID("ManuTriger");
	
#ifdef _PSX_QT_WINDOWS_
	CString strFilePath = _P_GetResourcePath();

    if (pBtnStart != nullptr)
	{
	m_imgStart.addFile(strFilePath + "start.png");
	}

	m_imgStop.addFile(strFilePath + "stop.png");
#else
     CString strFilePath;
	 strFilePath = ":/ctrls/images/";

    if (pBtnStart != nullptr)
	{
		m_imgStart.addFile(strFilePath + "start.png");
	}

	m_imgStop.addFile(strFilePath + "stop.png");
#endif

	if(pBtnTriger)
	{
		m_imgTriger.addFile(strFilePath + pBtnTriger->m_strIcon);
	}

	POS pos = pSttFrameButtons->GetHeadPosition();
	while (pos)
	{
		CSttFrame_Panal* pPanal = (CSttFrame_Panal*)pSttFrameButtons->GetNext(pos);
		if(pPanal->m_strID == "static-buttons"
			|| pPanal->m_strID == "float-buttons")
		{
			POS posBtn = pPanal->GetHeadPosition();
			while (posBtn)
			{
				CSttFrame_Button* pBtn = (CSttFrame_Button*)pPanal->GetNext(posBtn);
				InitIcon(pBtn->m_strID, strFilePath + "button_bk.png");
			}
		}
	}

	InitIcon(STT_CNTR_CMD_StartTest, m_imgStart);
	InitIcon(STT_CNTR_CMD_ManuTriger, m_imgTriger);

	if (g_nLogDebugInfor == 1)	{		CLogPrint::LogString(XLOGLEVEL_TRACE, ">> end InitIcon >>");	}
}

void QSttTestCntrFrameBase::InitPinyinLib()
{

}

//2022-9-16  lijunqing
QFont *g_pSttGlobalFont = nullptr;

void QSttTestCntrFrameBase::InitUI()
{
	g_oSttButtonIconMngr.Init();//初始化图片资源 sf 20220302
	CSttFrame_Font *pFont = m_pSttFrameConfig->GetFont();
    if(pFont)
    {

#ifndef _PSX_QT_WINDOWS_
	m_gFont.setFamily(pFont->m_strName);
	m_gFont.setPixelSize(pFont->m_nHeigth);
	m_gFont.setBold(pFont->m_nBold);
#endif
    }else
    {
        m_gFont.setFamily("WenQuanYi Micro Hei");
        m_gFont.setPixelSize(12);  // pick a reasonable default
        m_gFont.setBold(false);
    }
	g_pSttGlobalFont = &m_gFont;   //2022-9-16  lijunqing

// 	CSttFrame_ToolBar *pToolBarParas = m_pSttFrameConfig->GetToolBar();
// 	CSttFrame_StatusBar *pStatusBarParas = m_pSttFrameConfig->GetStatusBar();
	GetStartTestBtn();
	GetManualTriggerBtn();
// 	m_pToolBar = new QSttBarBase(pToolBarParas, m_oDataBtnsMngr,m_gFont,this);
// 	m_pToolBar->setGeometry(0,0,pToolBarParas->m_nWidth,pToolBarParas->m_nHeight);

	//初始化的时候隐藏手动触发按钮 sf 20220222
// 	UpdateButtonStateByID(STT_CNTR_CMD_ManuTriger,false,false);
// 	//刚打开的时候，开始测试不使能
// 	UpdateButtonStateByID(STT_CNTR_CMD_StartTest,false,true);
// 
// 	//系统参数页面，未勾选“数字”，应隐藏“IEC配置”按钮 sf 20220317
// 	if (g_oSystemParas.m_nHasDigital == 0)
// 	{
// 		UpdateButtonStateByID(STT_CNTR_CMD_IECConfig,false,false);
// 	}
// 	else
// 	{
// 		UpdateButtonStateByID(STT_CNTR_CMD_IECConfig,true,true);
// 	}
// 
// 	m_pToolBar->AdjustPanels();
// 
// 	m_pStatusBar = new QSttBarBase(pStatusBarParas, m_oDataBtnsMngr,m_gFont,this);
// 	m_pStatusBar->setGeometry(0,m_pSttFrameConfig->m_nHeight - pStatusBarParas->m_nHeight,pStatusBarParas->m_nWidth,pStatusBarParas->m_nHeight);
}

void QSttTestCntrFrameBase::CalRectArea()
{
	CSttFrame_GbTree *pGbTree = m_pSttFrameConfig->GetGbTree();

	CSttFrame_ToolBar *pToolBarParas = m_pSttFrameConfig->GetToolBar();
	int nHeight = m_pSttFrameConfig->m_nHeight - pToolBarParas->m_nHeight - pToolBarParas->m_nHeight - 2*SttFrame_Interval;

    if (m_pSttGbTreeView == nullptr || m_pSttGbTreeView->isVisible() == false)
	{
		m_rcWorkArea = QRect(0, pToolBarParas->m_nHeight + SttFrame_Interval, m_pSttFrameConfig->m_nWidth,nHeight);
	}
	else
	{
		CSttFrame_Size *pSize = pGbTree->GetSize();

		m_rcGbItemsArea = QRect(0,pToolBarParas->m_nHeight + SttFrame_Interval,pSize->m_nWidth,nHeight);
		m_rcWorkArea = QRect(pSize->m_nWidth, pToolBarParas->m_nHeight + SttFrame_Interval, m_pSttFrameConfig->m_nWidth - pSize->m_nWidth - SttFrame_Interval, nHeight);

        if (m_pSttGbTreeView != nullptr)
		{
			m_pSttGbTreeView->setGeometry(m_rcGbItemsArea);
		}
	}

    if (m_pActiveWidget != nullptr)
	{
		m_pActiveWidget->setGeometry(m_rcWorkArea);
	}
}

BOOL QSttTestCntrFrameBase::GetDatas()
{
    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return FALSE;
	}

    if (m_pMacroEditView == nullptr)
	{
		return FALSE;
	}

	CDataGroup oRetParas;

	if (g_pTheSttTestApp->m_pTestMacroUI->IsUIWeb())
	{
		oRetParas.AppendCloneEx(*m_pTestMacroUI_Paras);
	}

	//对于网页的，需要告诉网页期望获取哪些参数，因此不能直接传递一个空的形参
	m_pMacroEditView->GetDatas(&oRetParas);

	if (!oRetParas.IsEqual(m_pTestMacroUI_Paras))
	{
		oRetParas.UpdateChildren(m_pTestMacroUI_Paras);
		SaveUIParaFile(m_pTestMacroUI_Paras);
	}

	return TRUE;
}

void QSttTestCntrFrameBase::PromptToSave(CExBaseObject *pSelObj, BOOL bIsItemSame)
{
	//改到QSttTestCntrFrameWin中实现了
}

BOOL QSttTestCntrFrameBase::IsUiParasChanged(BOOL &bChanged, CDataGroup *pParas)
{
    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return FALSE;
	}

    if (m_pMacroEditView == nullptr)
	{
		return FALSE;
	}

	//从网页获取参数，需要先告诉网页获取哪部分的参数
	if (g_pTheSttTestApp->m_pTestMacroUI->IsUIWeb())
	{
		pParas->AppendCloneEx(*m_pTestMacroUI_Paras);
	}

	m_pMacroEditView->GetDatas(pParas);

	//判断参数是否发生改变时，只判断id和value
	CDataMngrXmlRWKeys::IncIsEqualOwn_Id_Value(CDataMngrXmlRWKeys::g_pXmlKeys);

	//判断参数是否发生改变时，只判断id和value
	CDataMngrXmlRWKeys::IncIsEqualOwn_Id_Value(CDataMngrXmlRWKeys::g_pXmlKeys);
	if (!pParas->IsEqualChildren(m_pTestMacroUI_Paras))
	{
		bChanged = TRUE;
		CDataMngrXmlRWKeys::DecIsEqualOwn_Id_Value(CDataMngrXmlRWKeys::g_pXmlKeys);
		return TRUE;
	}

	CDataMngrXmlRWKeys::DecIsEqualOwn_Id_Value(CDataMngrXmlRWKeys::g_pXmlKeys);

// 	else
// 	{
// 		CSttMacroParaEditViewOriginal* pOriginalView = (CSttMacroParaEditViewOriginal*)m_pMacroEditView;
// 		bChanged = pOriginalView->m_bTmtParaChanged;
// 		if(bChanged)
// 			return TRUE;
// 	}

    if (m_pCharLibWidget != nullptr)
	{
		bChanged = m_pCharLibWidget->m_bCharChanged;
	}

	return TRUE;
}

//2022-10-16  lijunqing 记录和保存当前页面设置的值：设置为默认值
void QSttTestCntrFrameBase::SaveUIParaFile(CDataGroup *pParas)
{
	//shaolei  2023-4-6   暂时屏蔽
	return;

    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return;
	}

	CString strPath = stt_ui_GetParasFile(g_pTheSttTestApp->m_pTestMacroUI->m_strUI_ParaFile);
	pParas->SaveXmlFile(strPath, CDataMngrXmlRWKeys::g_pXmlKeys);

//	CLogPrint::LogString(XLOGLEVEL_TRACE, strPath);
}

void QSttTestCntrFrameBase::UpdateCmdButtonsState(const CString &strState)
{
	//m_pToolBar->UpdateEnableState(strState);
	//m_pStatusBar->UpdateEnableState(strState);
	//线程调用的时候会奔溃，改成信号槽的形式 sf 20220218
	//不能在主线程调用这个信号槽函数，会死锁
	//主线程直接调用方法，不要触发信号 sf 20220223
	//调换了一下顺序，先换ID和显示再禁用，不然会把停止也禁用掉
	emit sig_UpdateEnableState(strState);
	
}

void QSttTestCntrFrameBase::UpdateButtonStateByID( const CString &strID,bool bState,bool bShow )
{
// 	if (m_pToolBar != nullptr)
// 	{
// 		for(int i = 0; i<m_pToolBar->m_plistPanel.size();i++)
// 		{
// 			QSttPanelBase* pPanel = m_pToolBar->m_plistPanel.at(i);
// 			for (int j = 0;j < pPanel->m_listCtrls.size(); j++)
// 			{
// 				QSttToolButtonBase* pButton = pPanel->m_listCtrls.at(j);
// 				if (pButton->m_pCfgData->m_strID == strID)
// 				{
// 					pButton->setDisabled(!bState);
// 					pButton->m_bShow = bShow;
// 					break;
// 				}
// 			}
// 		}
// 	}
// 	if (m_pMenuWidget != nullptr)
// 	{
// 		for(int i = 0; i < m_pMenuWidget->m_Btnlist.size(); i++)
// 		{
// 			QSttItemButton *pButton = m_pMenuWidget->m_Btnlist.at(i);
// 			if (pButton->m_pItem->m_strID == strID)
// 			{
// 				pButton->setDisabled(bState);
// 				pButton->setVisible(bShow);
// 				break;
// 			}
// 		}
// 	}
}

//选择功能是否显示 sf 20220318
void QSttTestCntrFrameBase::SetAddMacroEnable( bool bShow )
{
	//m_bSelMacroShow = bShow;
	m_nSelMacroShow = bShow;
	UpdateButtonStateByID(STT_CNTR_CMD_AddMacro,bShow,bShow);
	//m_pToolBar->AdjustPanels();
	AdjustToolBarButtons();
}

void QSttTestCntrFrameBase::UpdateStartStopTestButton(const CString &strState)
{
    if (m_pStartTestBtn == nullptr)
	{
		return;
	}

	QSttToolButtonBase *pButton = (QSttToolButtonBase*)m_pStartTestBtn->m_dwItemData;

	CSttFrame_ToolBar* pSttFrameButtons = m_pSttFrameConfig->GetToolBar();

	CString strFilePath = _P_GetResourcePath();
	if (strState == STT_TEST_STATE_TESTTING)
	{
		m_pStartTestBtn->m_strID = STT_CNTR_CMD_StopTest;
		m_pStartTestBtn->m_strName = g_sLangTxt_StopTest;
		InitIcon(STT_CNTR_CMD_StopTest, m_imgStop);
	}
	else
	{
		m_pStartTestBtn->m_strID = STT_CNTR_CMD_StartTest;
		m_pStartTestBtn->m_strName = g_sLangTxt_StartTest;
		InitIcon(STT_CNTR_CMD_StartTest, m_imgStart);
	}

	pButton->setText(m_pStartTestBtn->m_strName);
}

void QSttTestCntrFrameBase::LogString(long nLevel, const CString &strMsg)
{
	if (nLevel == XLOGLEVEL_RESULT)
	{
		LogStringResult(nLevel,strMsg);
		return;
	}
	else if (nLevel == XLOGLEVEL_ASSIST)
	{
#ifndef NOT_USE_ASSIST
        if (g_theAssistWndDynEffExecTool != nullptr)
		{
			g_theAssistWndDynEffExecTool->ShowMsg(strMsg,6000);
		}
#endif
	}

    if (m_pOutputWidget != nullptr)
	{
		m_pOutputWidget->LogString(nLevel, strMsg);
	}
	
	//ui->edtMsgLog->setText(strMsg);
}


void QSttTestCntrFrameBase::LogStringResult(long nLevel, const CString &strMsg)
{
    if (m_pResultWidget != nullptr)
	{
		m_pResultWidget->LogString(nLevel,strMsg);
	}
//	slot_LogStringResult(nLevel,strMsg);
//	emit sig_LogStringResult(nLevel,strMsg);
}

void QSttTestCntrFrameBase::ClearAll_ResultUI()
{
    if (m_pResultWidget != nullptr)
	{
		m_pResultWidget->ClearAll();
	}
}

void QSttTestCntrFrameBase::CloseIecCapDetect()
{
    if (m_pSttIecRecordMainWidget != nullptr)
	{
		m_pSttIecRecordMainWidget->CloseIecCapDetect();
	}
}

void QSttTestCntrFrameBase::LogString(long nLevel, const char *strMsg)
{
	if (nLevel == XLOGLEVEL_RESULT)
	{
		LogStringResult(nLevel,strMsg);
		return;
	}
	else if (nLevel == XLOGLEVEL_ASSIST)
	{
	}

	LogString(nLevel, CString(strMsg));
}
void QSttTestCntrFrameBase::InitPowerWidget(tmt_channel* pVOL,tmt_channel* pCUR,QWidget* pParent)
{
    if(pParent == nullptr)
	{
		pParent  =this;
	}

    if (m_pPowerDiagramWidget == nullptr)
	{
		m_pPowerDiagramWidget = new QPowerDiagramWidgetImp(pParent);
		m_pPowerDiagramWidget->setParent(pParent);
	}

	//20230222 不是相同的基类不能强制转换,且目前刷新采用的定时器,此处不需要赋值  zhouhj
//	g_oSttTestResourceMngr.m_oRtDataMngr.m_pEventToPower = (CSttRtDataChangeEvent *)m_pPowerDiagramWidget;
	m_pPowerDiagramWidget->setPropertyOfParaSet(GetSttTestResource());

	CSttMacroChannels *pMacroChs = g_oSttTestResourceMngr.m_oRtDataMngr.m_pMacroChannels;
	m_pPowerDiagramWidget->setData(pVOL,pCUR, &pMacroChs->m_oVolChListRef, &pMacroChs->m_oCurChListRef);
    
	m_pPowerDiagramWidget->setGeometry(m_rcWorkArea);

    if (m_pActiveWidget != nullptr)
	{
		m_pPowerDiagramWidget->hide();
	}
}

void QSttTestCntrFrameBase::UpdatePowerWidget(tmt_channel* pVOL,tmt_channel* pCUR,CExBaseList* pVolChList,CExBaseList* m_pCurChList)
{
	if(m_pPowerDiagramWidget)
	{
#ifndef _PSX_QT_LINUX_
		//windows端存在测试项不是初始测试项的情况,所以需要提前进行一次资源更新
		m_pPowerDiagramWidget->setPropertyOfParaSet(GetSttTestResource());
#endif
		m_pPowerDiagramWidget->setData(pVOL, pCUR, pVolChList, m_pCurChList);
	}
}

void QSttTestCntrFrameBase::UpdatePowerData()
{
	if((m_pPowerDiagramWidget)&&(!IsTestStarted()))//20230304 zhouhj 测试过程中,通过实时数据更新参数
	{
		m_pPowerDiagramWidget->initData();
	}
}


void QSttTestCntrFrameBase::InitVectorWidget(tmt_channel* pVOL,tmt_channel* pCUR,QWidget* pParent)
{
// 	if(m_pVectorWidget)
// 	{
// 		if(m_pActiveWidget == m_pVectorWidget)
// 		{
// 			m_pActiveWidget = nullptr;
// 		}
// 
// 		delete m_pVectorWidget;
// 		m_pVectorWidget = nullptr;
// 	}
    if(pParent == nullptr)
	{
		pParent  =this;
	}

    if (m_pVectorWidget == nullptr)
	{
		m_pVectorWidget = new QVectorWidget(pParent);
		m_pVectorWidget->setParent(pParent);
	}

	g_oSttTestResourceMngr.m_oRtDataMngr.m_pEventToVector = m_pVectorWidget;

	//20231109 suyang 根据不同模块 矢量图表格是否增加滑差值显示
	CString strCurrUI_ID = GetCurrentUI_ID();
	int nType;

	if(strCurrUI_ID == STT_CMD_ATS_MACRO_ID_LowVolTest)
	{
		nType = STT_LowVolDvdt_VECTOR;
	}
	else if (strCurrUI_ID == STT_CMD_ATS_MACRO_ID_LowFreqTest)
	{
		nType = STT_LowFreqDfdt_VECTOR;
	}
	else
	{
		nType = STT_COMMON_VECTOR;
	}
	m_pVectorWidget->setPropertyOfParaSet(GetSttTestResource(),nType);

	CSttMacroChannels *pMacroChs = g_oSttTestResourceMngr.m_oRtDataMngr.m_pMacroChannels;
	m_pVectorWidget->setData(pVOL,pCUR, &pMacroChs->m_oVolChListRef, &pMacroChs->m_oCurChListRef);

	m_pVectorWidget->setGeometry(m_rcWorkArea);

	if (m_pActiveWidget != m_pVectorWidget)
	{
		m_pVectorWidget->hide();
	}
}

void QSttTestCntrFrameBase::StartVectorWidget()
{
	if(m_pVectorWidget)
	{
		//2023.7.31 zhangyq 获取当前MacroID，判断是否为功率方向
		CString strCurrUI_ID = GetCurrentUI_ID();
		if(strCurrUI_ID == _T("PowerDirectionTest"))
		{
			CDataGroup oParas;
			oParas.AppendCloneEx(*m_pTestMacroUI_Paras);
			m_pMacroEditView->GetDatas(&oParas);
			m_pVectorWidget->SetVectorMode(VECTOR_POWERWORK,&oParas);
		}
		else
		{
            m_pVectorWidget->SetVectorMode(VECTOR_COMMON, nullptr);
		}

		m_pVectorWidget->TimerStart();
	}
}

void QSttTestCntrFrameBase::StartPowerWidget()
{
	if (m_pPowerDiagramWidget)
	{
		m_pPowerDiagramWidget->TimerStart();
	}
}

void QSttTestCntrFrameBase::StopVectorWidget(bool bUpdate)
{
	if(m_pVectorWidget)
	{
		m_pVectorWidget->TimerStop(bUpdate);
	}
}

void QSttTestCntrFrameBase::StopPowerWidget(bool bUpdate)
{
	if(m_pPowerDiagramWidget)
	{
		m_pPowerDiagramWidget->TimerStop(bUpdate);
	}
}

void QSttTestCntrFrameBase::UpdateVectorRange(float fUStart, float fUEnd, float fIStart, float fIEnd)
{
	if(m_pVectorWidget)
	{
		if(fUStart > fUEnd)
		{
			fUEnd = fUStart;
		}
		if(fIStart > fIEnd)
		{
			fIEnd = fIStart;
		}
		m_pVectorWidget->setUIMax(fUEnd, fIEnd);
	}
}

void QSttTestCntrFrameBase::UpdateVectorWidget(tmt_channel* pVOL,tmt_channel* pCUR,CExBaseList* pVolChList,CExBaseList* m_pCurChList)
{
	if(m_pVectorWidget)
	{
#ifndef _PSX_QT_LINUX_
		//windows端存在测试项不是初始测试项的情况,所以需要提前进行一次资源更新
		//20231109 suyang 根据不同模块 矢量图表格是否增加滑差值显示
		CString strCurrUI_ID = GetCurrentUI_ID();
		int nType;

		if(strCurrUI_ID == STT_CMD_ATS_MACRO_ID_LowVolTest)
		{
			nType = STT_LowVolDvdt_VECTOR;
		}
		else if (strCurrUI_ID == STT_CMD_ATS_MACRO_ID_LowFreqTest)
		{
			nType = STT_LowFreqDfdt_VECTOR;
		}
		else
		{
			nType = STT_COMMON_VECTOR;
		}
		m_pVectorWidget->setPropertyOfParaSet(GetSttTestResource(),nType);
#endif
		m_pVectorWidget->setData(pVOL, pCUR, pVolChList, m_pCurChList);
	}
}

void QSttTestCntrFrameBase::UpdateVectorData()
{
	if((m_pVectorWidget)&&(!IsTestStarted()))//20230304 zhouhj 测试过程中,通过实时数据更新参数
	{
		m_pVectorWidget->updateData();
	}
}

void QSttTestCntrFrameBase::OnSearchPointReport(const CString &strMacroID, CDataGroup *pSearchResults)
{
	CString strCurrUI_ID = GetCurrentUI_ID();
	CString strSearchResultDataID;

	if((strCurrUI_ID != STT_CMD_ATS_MACRO_ID_LowVolTest)&&(strCurrUI_ID != STT_CMD_ATS_MACRO_ID_LowFreqTest))
	{
		return;
	}

    if(pSearchResults == nullptr)
	{
		return;
	}

    if(m_pVectorWidget->m_pDiagram == nullptr)
	{
		return;
	}

	if (strCurrUI_ID == STT_CMD_ATS_MACRO_ID_LowVolTest)
	{
		strSearchResultDataID = _T("CurrSearchDvdt");
	}
	else
	{
		strSearchResultDataID = _T("CurrSearchDfdt");
	}

	CExBaseList* pSysState = (CExBaseList*)pSearchResults->GetParent()->GetParent();
	CSttMacro* pMacro = (CSttMacro*)pSysState->FindByClassID(STTCMDCLASSID_CSTTMACRO);
	if (pMacro)
	{
		CSttSearchResults* pResults = (CSttSearchResults*)pMacro->GetHead();
		CDvmData* pSearchDfdt = (CDvmData*)pResults->FindByID(/*_T("CurrSearchDfdt")*/strSearchResultDataID);//dingxy 20240702 低压减载du/dt数值不更新问题修改
		if (pSearchDfdt)
		{
			CString strValue = pSearchDfdt->m_strValue;
			m_pVectorWidget->m_pDiagram->fCurrSearchValue = atof(strValue.GetString());
			m_pVectorWidget->m_pDiagram->updateDiagram();
			
			//emit sig_updataVectorData();


		}
	}	
}

void QSttTestCntrFrameBase::InitStateMonitor(bool bIsEx, QWidget* pParent)
{
// 	if(m_pStateMonitor)
// 	{
// 		if(m_pActiveWidget == m_pStateMonitor)
// 		{
// 			m_pActiveWidget = nullptr;
// 		}
// 
// 		delete m_pStateMonitor;
// 		m_pStateMonitor = nullptr;
// 	}
// 
    if (pParent == nullptr)
	{
		pParent = this;
	}

    if (m_pStateMonitorWidget == nullptr)
	{
		m_pStateMonitorWidget = new QStateMonitorWidgetImp(pParent);
		m_pStateMonitorWidget->setParent(pParent);
	}

	CString strCurrUI_ID = GetCurrentUI_ID();
	if (strCurrUI_ID == STT_CMD_ATS_MACRO_ID_LowFreqTest)
	{
		m_pStateMonitorWidget->SetPlotDigitMaxMinValue();
	}

	m_pStateMonitorWidget->SetSingle(bIsEx);
	g_oSttTestResourceMngr.m_oRtDataMngr.m_pEventToProgress = m_pStateMonitorWidget;
	m_pStateMonitorWidget->setGeometry(m_rcWorkArea);
}	

void QSttTestCntrFrameBase::InitInfoWidget(QWidget* pParent)
{
    if (m_pInfoWidget == nullptr)
	{
		m_pInfoWidget = new QInfoWidget(pParent);
		m_pInfoWidget->setParent(this);
	}
}

void QSttTestCntrFrameBase::InitFAParasSetDialog(QWidget* pParent)
{
    if(pParent == nullptr)
	{
		pParent  =this;
	}

    if (m_pSttFaParasSetDialog == nullptr)
	{
		m_pSttFaParasSetDialog = new QSttFAParasSetDialog(pParent);
		m_pSttFaParasSetDialog->setParent(pParent);
	}

	m_pSttFaParasSetDialog->setGeometry(m_rcWorkArea);

    if (m_pActiveWidget != nullptr)
	{
		m_pSttFaParasSetDialog->hide();
	}
}

void QSttTestCntrFrameBase::ClearInfoWidget()
{
	if (m_pInfoWidget)
	{
		m_pInfoWidget->clear();
	}
}

void QSttTestCntrFrameBase::InitCharLibWidget(QWidget* pParent)
{
    if (m_pCharLibWidget == nullptr)
	{
		//2022-9-3  lijunqing
		m_pCharLibWidget = new QCharEditMainWidget(pParent);   //new QCharLibWidget(pParent);
		m_pCharLibWidget->setParent(this);
	}	
}

void QSttTestCntrFrameBase::InitIecRecordMain()
{
	//IEC测试
    if (m_pSttIecRecordMainWidget == nullptr)
	{
		m_pSttIecRecordMainWidget = new QSttIecRecordMainWidget(m_gFont, this);
		m_pSttIecRecordMainWidget->setParent(this);
		m_pSttIecRecordMainWidget->hide();
	}
}

void QSttTestCntrFrameBase::InitRemoteCtrl()
{
    //sun if (m_pRemoteCtrlWidget == nullptr)
    //sun {
    //sun 	m_pRemoteCtrlWidget = new QSttMacroParaEditViewRemoteCtrl(this);
    //sun 	m_pRemoteCtrlWidget->setParent(this);
    //sun 	m_pRemoteCtrlWidget->hide();
    //sun }
}

void QSttTestCntrFrameBase::UpdateDeviceModelRef()
{
    //sun if (m_pRemoteCtrlWidget != nullptr)
    //sun {
    //sun 	m_pRemoteCtrlWidget->UpdateDeviceModelRef();
    //sun 	m_pRemoteCtrlWidget->m_nReadCount = 0; //chenling 2024.5.7更新点表需要重新启动报告
    //sun }
    //sun
    //sun if (m_pEngineClientWidget != nullptr)
    //sun {
    //sun     m_pEngineClientWidget->m_pCurrSelDvmDataObj = nullptr;
    //sun }

    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return;
	}

	if (!g_pTheSttTestApp->m_pTestMacroUI->IsUIOriginal())
	{
		return;
	}

	((CSttMacroParaEditViewOriginal*)m_pMacroEditView)->UpdateDeviceModelRef();
}

void QSttTestCntrFrameBase::InitCommCmdWzdMain(CExBaseList *pParentItem)
{

}

void QSttTestCntrFrameBase::FreeCommCmdWzdMain()
{

}

QWidget* QSttTestCntrFrameBase::GetMacroEditWidget()
{
    if (m_pMacroEditView == nullptr)
	{
        return nullptr;
	}

	return (QWidget*)m_pMacroEditView->m_pMacroParaEditWnd;
}

CString QSttTestCntrFrameBase::GetMacroEditViewID()
{
    if (m_pMacroEditView == nullptr)
	{
		return "";
	}

	if(!m_pMacroEditView->m_pSttItems)
	{
		return "";
	}

	return m_pMacroEditView->m_pSttItems->m_strID;
}

BOOL QSttTestCntrFrameBase::IsHtmlParasEditOpen()
{
    //return (m_pSysParaEditView != nullptr);
    return false;
	//return (m_nActiveWidgetType == ActiveWidgetType_Paras_Html);
}

void QSttTestCntrFrameBase::SetActiveWidget(QWidget *pWidget, ActiveWidgetType nType)
{
	if (m_pActiveWidget==m_pCharLibWidget && m_pActiveWidget!=pWidget)
	{
		CString strFile;

        if(pWidget == nullptr)
		{
			strFile = m_pCharLibWidget->m_strCharParasFile;
		}

		SaveCharacteristicsData(strFile);
		TemplateView_Prepare();//zhouhj 2023.7.18 在离开特性曲线界面时,将参数同步到网页界面
	}

    if (pWidget == nullptr)
	{
        if (m_pActiveWidget != nullptr)
		{
			m_pActiveWidget->hide();
            m_pActiveWidget = nullptr;
		}

		m_nActiveWidgetType = ActiveWidgetType_None;
		m_nPrevActiveWidgetType = ActiveWidgetType_None;
        m_pPrevActiveWidget = nullptr;

		return;
	}

    if (m_pActiveWidget != nullptr)
	{
		if (m_pActiveWidget == pWidget)
		{
			return;
		}

		m_pActiveWidget->hide();
		pWidget->show();
	}
	else
	{
		m_pActiveWidget = pWidget;
		pWidget->show();
	}

	m_nPrevActiveWidgetType = m_nActiveWidgetType;
	m_pPrevActiveWidget = m_pActiveWidget;
	m_nActiveWidgetType = nType;
	m_pActiveWidget = pWidget;

	m_pActiveWidget->setParent(this);
	m_pActiveWidget->setGeometry(m_rcWorkArea);
	assist_widget_show("", m_pActiveWidget, true);
}

void QSttTestCntrFrameBase::ReturnPrevActiveWidget()
{//编辑Html参数页面结束，返回之前的窗口
	assist_widget_show("", m_pActiveWidget, false);//20220104 zhouhj 网页界面关闭时,去除关联
	m_oTimerHtmlViewReturn.start(50);
}

CString QSttTestCntrFrameBase::GetCharLibWidgetID()
{
	if(m_pCharLibWidget)
	{
		return m_pCharLibWidget->m_strUI_ID;
	}
	return "";
}

void QSttTestCntrFrameBase::slot_SelectTestMacro( CSttMacroTestUI_TestMacroUIRef *pTestMacroUIRef , const CString &strItemsName, const CString &strItemsID)
{
    //if ((g_pTheSttTestApp->m_pTestMacroUI != nullptr)&&(m_pSttReportViewHtml!= nullptr))//zhouhj 20220219 在第二次打开时,删除上一次选择的测试功能的报告
    //{
    //	m_pSttReportViewHtml->DeleteMacroTestReport("", g_pTheSttTestApp->m_pTestMacroUI->m_strID);
    //}

	g_pTheSttTestApp->SetCurrTestMacroUI(pTestMacroUIRef->m_strID);
	OpenMacroTestUI(g_pTheSttTestApp->m_pTestMacroUI, strItemsName, strItemsID);

	EndBinStateOnStarting();
	UpdateToolButtons();
	UpdateStartStopButtonByItemCount();
}

//线程调用的时候会奔溃，改成信号槽的形式 sf 20220218
void QSttTestCntrFrameBase::on_UpdateEnableState(QString strState)
{
	CString strButtonUpdateState;

	if (strState == STT_TEST_STATE_TEST_FINISHED)//按钮的更新状态只有两种,测试中和测试停止,通过比对当前测试状态,更新按钮的显示
	{
		strButtonUpdateState = STT_TEST_STATE_TEST_STOPED;
	}
	else
		strButtonUpdateState = strState;

//	CLogPrint::LogString(XLOGLEVEL_ERROR, "QSttTestCntrFrameBase::on_UpdateEnableState errorr......");
	UpdateStartStopTestButton(strButtonUpdateState);

	UpdateEnableState(strButtonUpdateState);
	//部分网页功能不应使能手动触发
	if (!HasManuTrigerBtn())
	{
		EnableManualTriggerButton(false);
	}

	if (!g_oSystemParas.HasDigitalInOrOut())//20220805 zhouhj 在开始测试、停止测试后,需要更新相关状态
	{
		UpdateButtonStateByID(STT_CNTR_CMD_IECConfig,false,false);
	}
// 	else
// 	{
// 		UpdateButtonStateByID(STT_CNTR_CMD_IECConfig,true,true);
// 	}

    if (m_pStatusBar != nullptr)
	{
		m_pStatusBar->UpdateEnableState(strButtonUpdateState);
	}
}

void QSttTestCntrFrameBase::UpdateEnableState(const CString &strState)
{

}

void QSttTestCntrFrameBase::slot_MenuButtonClick(QString strID)
{
	if (IsHtmlParasEditOpen())
	{//如果打开了参数编辑网页，则不处理任何按钮操作事件  lijunqing  2022-3-10

		if (strID == STT_CNTR_CMD_Exit)
		{
			CSttFrame_Button *pExitBtn = GetExitBtn();

            if (pExitBtn != nullptr)
			{
				QSttToolButtonBase *pButtonUI = (QSttToolButtonBase*)pExitBtn->m_dwItemData;

                if (pButtonUI != nullptr)
				{
					pButtonUI->setEnabled(true);
				}
			}
		}

		CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,/*_T("请先关闭网页界面,才能执行工具栏按钮功能.")*/g_sLangTxt_Gradient_ClosePerTBF.GetString());//lcq
		return;
	}

	if(strID == STT_CNTR_CMD_Exit)
	{
		m_bHasClosedUI = TRUE;
		SaveCharacteristicsData();
		CloseIecCapDetect();
		setEnabled(false);
		m_pResultWidget->LogString(0, /*"等待测试服务停止后关闭."*/g_sLangTxt_Gradient_WaitSASD.GetString()); //lcq
		m_pTestCtrlCntrBase->CloseTest();
		this->close();
        QApplication::setOverrideCursor(Qt::BlankCursor);    // xueyangfan 隐藏鼠标光标
		return;
	}
	if  (strID ==  STT_CNTR_CMD_Menu)
	{
		OnCmd_Menu();
		return;
	}

	Before_OnCmd();

	if  (strID ==  STT_CNTR_CMD_StartTest)
	{
		OnCmd_StartTest();
	}
	if  (strID ==  STT_CNTR_CMD_TestThis)
	{
		OnCmd_TestThis();
	}
	else if  (strID ==  STT_CNTR_CMD_ManuTriger)
	{
		OnCmd_ManuTriger();
	}
	else if  (strID ==  STT_CNTR_CMD_StopTest)
	{
		OnCmd_StopTest();
	}
	else if  (strID ==  STT_CNTR_CMD_AddMacro)
	{
		OnCmd_AddMacro(TRUE);
	}
	else if  (strID ==  STT_CNTR_CMD_ItemList)
	{
		OnCmd_ItemList();
	}
	else if  (strID ==  STT_CNTR_CMD_TemplateView)
	{
		OnCmd_TemplateView();
	}
	else if  (strID ==  STT_CNTR_CMD_ReportView)
	{
		OnCmd_ReportView();
	}
	else if  (strID ==  STT_CNTR_CMD_HardConfig)
	{
		OnCmd_HardConfig();
	}
	else if  (strID ==  STT_CNTR_CMD_IECConfig)
	{
		OnCmd_IECConfig();
	}
	else if  (strID ==  STT_CNTR_CMD_AinDataMapConfig)
	{
		OnCmd_AinDataMapConfig();
	}
	else if  (strID ==  STT_CNTR_CMD_VectorDrawView)
	{
		OnCmd_VectorDrawView();
	}
	else if  (strID ==  STT_CNTR_CMD_WaveDrawView)
	{
		OnCmd_WaveDrawView();
	}
	else if  (strID ==  STT_CNTR_CMD_StateDrawView)
	{
		OnCmd_StateDrawView();
	}
	else if (strID == STT_CNTR_CMD_PowerDrawView)
	{
		OnCmd_PowerDrawView();
	}
	else if  (strID ==  STT_CNTR_CMD_CharDrawView)
	{
		OnCmd_CharDrawView();
	}
	else if  (strID ==  STT_CNTR_CMD_NewTest)
	{
		OnCmd_NewTest();
	}
	else if  (strID ==  STT_CNTR_CMD_OpenTemplate)
	{
		OnCmd_OpenTemplate();
	}
	else if  (strID ==  STT_CNTR_CMD_OpenTest)
	{
		OnCmd_OpenTest();
	}
	else if  (strID ==  STT_CNTR_CMD_SaveTemplate)
	{
		OnCmd_SaveTemplate();
	}
	else if  (strID ==  STT_CNTR_CMD_SaveAsTemplate)
	{
		OnCmd_SaveAsTemplate();
	}
	else if  (strID ==  STT_CNTR_CMD_SaveTest)
	{
		OnCmd_SaveTest();
	}
	else if  (strID ==  STT_CNTR_CMD_SaveAsTest)
	{
		OnCmd_SaveAsTest();
	}
	else if  (strID ==  STT_CNTR_CMD_SaveAsRpt)
	{
		OnCmd_SaveAsRpt();
	}
	else if (strID == STT_CNTR_CMD_ExportWordRpt)
	{
		OnCmd_ExportWordRpt();
	}
	else if  (strID ==  STT_CNTR_CMD_SystemParas)
	{
		OnCmd_SystemParas();
	}
	else if  (strID ==  STT_CNTR_CMD_GeneralParas)
	{
		OnCmd_GeneralParas();
	}
// 	else if  (strID ==  STT_CNTR_CMD_SwitchSet)
// 	{
// 		8OnCmd_SwitchSet();
// 	}
	else if  (strID ==  STT_CNTR_CMD_DcSet)
	{
		OnCmd_DcSet();
	}
	else if  (strID ==  STT_CNTR_CMD_OutputPower)
	{
		OnCmd_OutputPower();
	}
	else if  (strID ==  STT_CNTR_CMD_DeviceCom)
	{
		OnCmd_DeviceCom();
	}
	else if  (strID ==  STT_CNTR_CMD_ItemListView)
	{
		OnCmd_ItemListView();
	}
	else if  (strID ==  STT_CNTR_CMD_DeviceComView)
	{
		OnCmd_DeviceComView();
	}
	else if  (strID ==  STT_CNTR_CMD_LangSetting)
	{
		OnCmd_LangSettingView();
	}
	else if  (strID ==  STT_CNTR_CMD_ReportSetting)
	{
		OnCmd_ReportSetting();
	}
	else if  (strID ==  STT_CNTR_CMD_ChRsMaps)
	{
		OnCmd_ChRsMaps();
	}
	else if  (strID ==  STT_CNTR_CMD_AuxDCOutput)
	{
		OnCmd_AuxDCOutput();
	}
// 	else if  (strID ==  STT_CNTR_CMD_CharaView)  //20220803 zhouhj 重复删除
// 	{
// 		OnCmd_CharaView();
// 	}
	else if  (strID ==  STT_CNTR_CMD_SequenceView)
	{
		OnCmd_SequenceView();
	}
	else if  (strID ==  STT_CNTR_CMD_InfoView)
	{
		OnCmd_InfoView();
	}
	else if  (strID ==  STT_CNTR_CMD_LogView)
	{
		OnCmd_LogView();
	}
	else if  (strID ==  STT_CNTR_CMD_VersionInfo)
	{
		OnCmd_VersionInfo();
	}
	else if (strID ==  STT_CNTR_CMD_AuxIPSet)
	{
		OnCmd_AuxIPSet();
	}
	else if  (strID ==  STT_CNTR_CMD_Liveupdate)
	{
		OnCmd_Liveupdate();
	}
	else if (strID ==  STT_CNTR_CMD_ULiveupdate)
	{
		OnCmd_ULiveupdate();
	}
	else if  (strID ==  STT_CNTR_CMD_LiveupdateDevice)
	{
		OnCmd_LiveupdateDevice();
	}
	else if  (strID ==  STT_CNTR_CMD_CloudConfig)
	{
		OnCmd_CloudConfig();
	}
	else if  (strID ==  STT_CNTR_CMD_UpdateAdjCoef)
	{
		OnCmd_UpdateAdjCoef();
	}
	else if  (strID ==  STT_CNTR_CMD_RegisterRemoteTest)
	{
		OnCmd_RegisterRemoteTest();
	}
	else if  (strID ==  STT_CNTR_CMD_RemoteRegistAssist)
	{
		OnCmd_RemoteRegistAssist();
	}
	else if  (strID ==  STT_CNTR_CMD_DownloadTestTemplate)
	{
		OnCmd_DownloadTestTemplate();
	}
	else if  (strID ==  STT_CNTR_CMD_DownloadPpTemplate)
	{
		OnCmd_DownloadPpTemplate();
	}
	else if  (strID ==  STT_CNTR_CMD_UploadingReport)
	{
		OnCmd_UploadingReport();
	}
	else if  (strID ==  STT_DEBUG_SetDatas)
	{
		OnCmd_DebugSetDatas();
	}
	else if  (strID ==  STT_DEBUG_SetDatasFile1)
	{
		OnCmd_DebugSetDatasFile1();
	}
	else if  (strID ==  STT_DEBUG_SetDatasFile2)
	{
		OnCmd_DebugSetDatasFile2();
	}
	else if  (strID ==  STT_DEBUG_SaveDatasFile)
	{
		OnCmd_DebugSaveDatasFile();
	}
	else if  (strID ==  STT_DEBUG_GetDatas)
	{
		OnCmd_DebugGetDatas();
	}
	else if  (strID ==  STT_DEBUG_UpdateReport)
	{
		OnCmd_DebugUpdateReport();
	}
	else if  (strID ==  STT_DEBUG_FillReport)
	{
		OnCmd_DebugFillReport();
	}
	else if  (strID ==  STT_DEBUG_ItemStateChanged)
	{
		OnCmd_DebugItemStateChanged();
	}
	else if  (strID ==  STT_DEBUG_OutPutWidget)
	{
		OnCmd_DebugOutPutWidget();
	}
	else if  (strID ==  STT_DEBUG_StartTest)
	{
		OnCmd_DebugStartTest();
	}
	else if  (strID ==  STT_DEBUG_StopTest)
	{
		OnCmd_DebugStopTest();
	}
	else if  (strID ==  STT_CNTR_CMD_ConnectApp)
	{
		OnCmd_ConnectApp();
	}
	else if  (strID ==  STT_CNTR_CMD_Debug)
	{
		OnCmd_Debug();
	}
	else if  (strID ==  STT_DEBUG_SaveTest)
	{
		OnCmd_DebugSaveTest();
	}
	else if  (strID ==  STT_DEBUG_GenForDebug)
	{
		OnCmd_DebugGenForDebug();
	}
	else if  (strID ==  STT_DEBUG_GenTemplate)
	{
		OnCmd_DebugGenTemplate();
	}
	else if  (strID ==  STT_DEBUG_SaveAsSysFiles)
	{
		OnCmd_DebugSaveAsSysFiles();
	}
	else if  (strID ==  STT_CNTR_CMD_IecCap)
	{
		OnCmd_IecCap();
	}
	else if  (strID ==  STT_CNTR_CMD_IecCapWriteFile)
	{
		OnCmd_IecCapWriteFile();
	}
	else if  (strID ==  STT_CNTR_CMD_IecCapDebugHead)
	{
		OnCmd_IecCapDebugHead();
	}
	else if  (strID ==  STT_CNTR_CMD_ScreenShot)
	{
		OnCmd_ScreenShot();
	}
	else if (strID == STT_CNTR_CMD_FAParasSetDialog)
	{
		OnCmd_FAParasSetDialog();
	}
	else if (strID == STT_CNTR_CMD_CustomSet)
	{
		OnCmd_CustomSet();
	}
	else if (strID == STT_CNTR_CMD_Assist)
	{//2022-12-02  lijunqing
		OnCmd_Assist();
	}
	else if (strID == STT_CNTR_CMD_SelSCLFile)
	{
		OnCmd_SelSCLFile();
	}
	else if (strID == STT_CNTR_CMD_SaveEdit)
	{
		OnCmd_SaveEdit();
	}
	else if (strID == STT_CNTR_CMD_FileMngr)
	{
		OnCmd_FileMngr();
	}
	else if (strID == STT_CNTR_CMD_LumPowerView)
	{
		OnCmd_LumPowerView();
	}
	else if (strID == STT_CNTR_CMD_PpIotEngineClient)
	{
		OnCmd_PpIotEngineClient();
	}
	else if (strID == STT_CNTR_CMD_CommConfig)
	{
		OnCmd_CommConfiguration();
	}
	else if (strID == STT_CNTR_CMD_PkgMonitor)
	{
		OnCmd_PkgMonitor();
	}
	else if (strID == STT_CNTR_CMD_RemoteCtrl)
	{
		OnCmd_RemoteCtrl();
	}
	else if (strID == STT_CNTR_CMD_PpXmlFileMngr)
	{
		OnCmd_PpXmlFileMngr();
	}
	else if (strID == STT_CNTR_CMD_DvmFileMngr)
	{
		OnCmd_DvmFileMngr();
	}
	else if (strID == STT_CNTR_CMD_NetworkConfig)
	{
		OnCmd_NetworkConfig();
	}
	else if (strID == STT_CNTR_CMD_ClearReportRslts)
	{
		OnCmd_ClearReportRslts();
	}
	else if (strID == STT_CNTR_CMD_TransPcapFile)
	{
		OnCmd_TransPcapFile();
	}
	else if (strID == STT_CNTR_CMD_ImportDvmFile)
	{
		OnCmd_ImportDvmFile();
	}
	else if (strID == STT_CNTR_CMD_OutputDebug)
	{
		OnCmd_OutputDebug();
	}
	else if (strID == STT_CNTR_CMD_Minimize)//2024-2-26 zhouyangyong 添加用于最小化
	{
		OnCmd_Minimize();
	}
}

//yyj 
bool QSttTestCntrFrameBase::GenerateTemplate(CExBaseObject *pParentItems, const CString &strItemsName, const CString &strItemsID
											 , long nRepeatTimes, long nRptTitle, long nTitleLevel)
{
	bool bTemplateGened = false;
	long nRet = m_pTestCtrlCntrBase->Ats_GenerateTemplate();

	if (nRet == STT_CMD_ExecStatus_SUCCESS)	//模板生成完成
	{
		bTemplateGened = true;
//		CLogPrint::LogFormatString(XLOGLEVEL_INFOR,_T("底层测试模板生成完成."));
	}
	else
	{
#ifdef _PSX_QT_LINUX_
		CString strTitile,strMsg;
		strTitile = g_sLangTxt_Message/*"提示"*/;
		strMsg = g_sLangTxt_Native_LowLevelTmplFail/*"底层测试模板生成失败."*/;
		sig_MsgBox(strTitile,strMsg);
//		CXMessageBox::information(this, strTitile, strMsg);
#endif
		CLogPrint::LogFormatString(XLOGLEVEL_INFOR,/*_T("底层测试模板生成失败.")*/g_sLangTxt_Native_LowLevelTmplFail.GetString());
	}

	return bTemplateGened;
}

bool QSttTestCntrFrameBase::IsTestStarted()
{
    if (m_pTestCtrlCntrBase == nullptr)
    {
        qDebug() << "debug sun:  m_pTestCtrlCntrBase ia nullptrrrrrrrrrrrrrrrrrrrrrrrrrrr " ;
		return false;
	}

 	return m_pTestCtrlCntrBase->IsTestStarted();
}

bool QSttTestCntrFrameBase::IsStateTest()
{
	if (CSttMacroParaEditViewMngr::GetCurMacroID() == STT_ORG_MACRO_StateTest)
	{
		return true;
	}
	else if (CSttMacroParaEditViewMngr::GetCurMacroID() == STT_ORG_MACRO_SmvAbnTest)
	{
		return true;
	}
	else if (CSttMacroParaEditViewMngr::GetCurMacroID() == STT_ORG_MACRO_GseAbnTest)
	{
		return true;
	}
	else
		return false;
}

bool QSttTestCntrFrameBase::IsMultiTestItems()
{
    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return false;
	}

	if (g_pTheSttTestApp->m_pTestMacroUI->IsUIOriginal())
	{
		if (g_pTheSttTestApp->m_pTestMacroUI->m_strID == STT_ORG_MACRO_MUAutoTest)
		{
			return true;
		}

		return false;
	}

	CString strMacroID = g_pTheSttTestApp->GetCurrTestMacroUI();

//	if (strMacroID == STT_HTML_MACRO_CBOperateTest)
//	{
//		return false;
//	}

	return true;
}

bool QSttTestCntrFrameBase::HasCharChanged()
{
    if (m_pCharLibWidget == nullptr)
	{
		return false;
	}

	return m_pCharLibWidget->m_bCharChanged;
}

void QSttTestCntrFrameBase::AddTestPoints(double dX, double dY,BOOL bAct)
{
	m_pSttCharacterDrawPng->AddSearchPoint(dX, dY, bAct);
}

void QSttTestCntrFrameBase::SetCharChanged(bool bCharChanged)
{
    if (m_pCharLibWidget == nullptr)
	{
		return;
	}

	m_pCharLibWidget->m_bCharChanged = bCharChanged;
}

void QSttTestCntrFrameBase::UpdateCharScriptByUIParas(CDataGroup *pCurrentUIParas)
{
    if ((m_pCharLibWidget == nullptr) || (pCurrentUIParas == nullptr))
	{
		return;
	}

	m_pCharLibWidget->UpdateCharScriptByUIParas(pCurrentUIParas);
}

void QSttTestCntrFrameBase::InitStateMonitor(int nChannel, int type, bool bStart, QWidget* pPlotExWidget)
{
	CString strCurrUI_ID = GetCurrentUI_ID();

	if (strCurrUI_ID == STT_CMD_ATS_MACRO_ID_LowFreqTest)
	{
		type = fre_type;
	}

	if (m_pStateMonitorWidget)
	{
		m_pStateMonitorWidget->InitStateMonitor(nChannel, type, bStart, pPlotExWidget);
	}
}

void QSttTestCntrFrameBase::StartStateMonitor()
{
	if (m_pStateMonitorWidget)
	{
		m_pStateMonitorWidget->StartStateMonitor();
	}
}

void QSttTestCntrFrameBase::StopStateMonitor()
{
	if (m_pStateMonitorWidget)
	{
		m_pStateMonitorWidget->StopStateMonitor();
	}
}

void QSttTestCntrFrameBase::CloseMenu()
{
	emit sig_CloseMenu();
}

void QSttTestCntrFrameBase::SetVectorGradient(bool bIsGradient)
{
	if (m_pVectorWidget)
	{
		m_pVectorWidget->setAutoChanged(bIsGradient);
	}
}

void QSttTestCntrFrameBase::keyPressEvent(QKeyEvent *event)
{
	keyPressEvent_Exec(event->key());
}

bool QSttTestCntrFrameBase::keyPressEvent_Exec(int nKeyValue)
{
	bool bRet = false;
	
    if(m_pStartTestBtn != nullptr)
	{
 	if(nKeyValue == Qt::Key_F2) 
 	{
			if (!IsTestStarted() && m_pStartTestBtn->m_strID == STT_CNTR_CMD_StartTest)
		{
			OnCmd_StartTest();
		}
		
 		bRet = true;
 	} 
 	else if(nKeyValue == Qt::Key_Escape) 
	{
			if (IsTestStarted() && m_pStartTestBtn->m_strID == STT_CNTR_CMD_StopTest)
		{
			OnCmd_StopTest();
		}
 
 		bRet = true;
 	}
 	else if(nKeyValue == Qt::Key_F3) 
 	{

            if (m_pManualTriggerBtn != nullptr)
			{
						QSttToolButtonBase *pManualTriggerBtn = (QSttToolButtonBase*)m_pManualTriggerBtn->m_dwItemData;
				if(HasManuTrigerBtn() && pManualTriggerBtn->isEnabled())
		{
 		OnCmd_ManuTriger();
		}
 		
 		bRet = true;
 	}
		}
	}
 	
	return bRet;
}


void QSttTestCntrFrameBase::slot_Timer_AutoSave()
{
	return;
}

void QSttTestCntrFrameBase::slot_Timer()
{
//	return;
	OnEventMsg();
	CAutoSimpleLock oLock(m_oCriticSection_ItemStateList);

	if(m_oItemStateList.CanRead())
	{
		CExBaseObject *pObj = m_oItemStateList.Read();
		slot_OnItemStateChanged_Frame(pObj);
		//			emit sig_OnItemStateChanged_Frame(&pObj);
	}
	//if(m_pItemState)
	//{
	//	emit sig_OnItemStateChanged_Frame(m_pItemState);
	//}

	/*避免多线程同时emit造成的死锁
	if(IsTestAppConnect())
	{
		emit sig_OnViewTestLink(TRUE);
	}
	else
	{
		emit sig_OnViewTestLink(FALSE);
	}
	*/
}

void QSttTestCntrFrameBase::OnViewTestStop_Common(BOOL bItemChanged)
{
	StopStateMonitor();

	if (!bItemChanged)
	{
		StopVectorWidget();
		StopPowerWidget();
	}
}

void QSttTestCntrFrameBase::OnEventMsg()
{
    if(m_pTestCtrlCntrBase == nullptr)
	{
		return;
	}

	if(!IsTestStarted())
	{
		return;
	}

	PrintEventInfo();
}

void QSttTestCntrFrameBase::UpdateEventMsg(CEventResult *pEventInfo)
{
	pEventInfo->Copy(&m_pTestCtrlCntrBase->m_oCurrEventResult);

	if (m_pTestCtrlCntrBase->m_oCurrEventResult.m_strEventID == SYS_STATE_REPORT_OnSwichInChanged 
		|| m_pTestCtrlCntrBase->m_oCurrEventResult.m_strEventID == SYS_STATE_REPORT_OnSwichOutChanged
		|| m_pTestCtrlCntrBase->m_oCurrEventResult.m_strEventID == SYS_STATE_RETTYPE_UPDATE)
	{
		SysStateReport_OnSwitchChanged(pEventInfo);
	}

	if(m_pTestCtrlCntrBase->m_oCurrEventResult.m_strEventID == SYS_STATE_REPORT_OnSwichInChanged 
		|| m_pTestCtrlCntrBase->m_oCurrEventResult.m_strEventID == SYS_STATE_REPORT_OnSwichOutChanged
		|| m_pTestCtrlCntrBase->m_oCurrEventResult.m_strEventID == SYS_STATE_EVENT_OnTestStarted
		|| m_pTestCtrlCntrBase->m_oCurrEventResult.m_strEventID == SYS_STATE_RETTYPE_UPDATE)
	{
		if(m_pStateMonitorWidget)
		{
			for (int i = 0; i < g_nBinCount; i++)
			{
				m_pStateMonitorWidget->AddBinBoutPoint(i, pEventInfo->m_fTime, pEventInfo->m_BinIn[i]);
			}
			for (int i = 0; i < g_nBoutCount; i++)
			{
				m_pStateMonitorWidget->AddBinBoutPoint(i + g_nBinCount, pEventInfo->m_fTime, pEventInfo->m_BinOut[i]);
			}
		}
	}

	if (m_pTestCtrlCntrBase->m_oCurrEventResult.m_strEventID == SYS_STATE_REPORT_OnSwichInChanged)
	{
		//2024/1/3 wangjunsheng  低周 低压模块不显示开入变位
		CString strCurrUI_ID = GetCurrentUI_ID();
		if(strCurrUI_ID == STT_CMD_ATS_MACRO_ID_LowVolTest || strCurrUI_ID == STT_CMD_ATS_MACRO_ID_LowFreqTest)
		{
			return;
		}
		m_pInfoWidget->ShowBinInResultMsg(&m_pTestCtrlCntrBase->m_oCurrEventResult);
	}

	if (IsStateTest())
	{
		//dingxy 20240523 都采用下面重写方式
// 		if (m_pTestCtrlCntrBase->m_oCurrEventResult.m_fActTime>0.00001)
// 		{
// 			CString strResultMsg;
// 			strResultMsg.Format(g_sLangTxt_Native_StatusLDActTime.GetString()/*_T("状态%ld动作时间%.4lfs.")*/,
// 				pEventInfo->m_nCurrStateIndex+1,pEventInfo->m_fActTime);
// 			CLogPrint::LogString(XLOGLEVEL_RESULT,strResultMsg);
// 		}

		m_pInfoWidget->InsertSwitchInfoTable(&m_pTestCtrlCntrBase->m_oCurrEventResult,true);
	}
	else
	{
		m_pInfoWidget->InsertSwitchInfoTable(&m_pTestCtrlCntrBase->m_oCurrEventResult);
	}

    if (m_pMacroEditView != nullptr)
	{
		m_pMacroEditView->UpdateEventMsg(&m_pTestCtrlCntrBase->m_oCurrEventResult);
	}

	//yzj 2023.11.06 状态序列重复测试应先切换至第一个状态
	if(m_pTestCtrlCntrBase->m_oCurrEventResult.m_strEventID == SYS_STATE_REPORT_OnStateChanged
		|| m_pTestCtrlCntrBase->m_oCurrEventResult.m_strEventID == SYS_STATE_EVENT_OnTestStarted)
	{
		SysStateReport_OnStateChanged(pEventInfo);
	}

	if(IsTestStarted())
	{
		UpdateToolButtons();
	}
}

void QSttTestCntrFrameBase::PrintEventInfo()
{
	CExBaseList oEventInfoList;
	m_pTestCtrlCntrBase->GetEventInfo(oEventInfoList);
	POS pos = oEventInfoList.GetHeadPosition();
    CEventResult *p = nullptr;

    while(pos != nullptr)
	{
		p = (CEventResult *)oEventInfoList.GetNext(pos);
		UpdateEventMsg(p);
	}

	oEventInfoList.RemoveAll();
}

bool QSttTestCntrFrameBase::IsTestAppConnect()
{
    if (m_pTestCtrlCntrBase == nullptr)
	{
		return false;
	}

	return m_pTestCtrlCntrBase->IsTestAppConnect();
}

void QSttTestCntrFrameBase::UpdateToolButtons_ParaEdit()
{
    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return;
	}

	if (!g_pTheSttTestApp->m_pTestMacroUI->IsUIOriginal())
	{
		return;
	}

	CSttMacroParaEditViewOriginal *pView = (CSttMacroParaEditViewOriginal*)m_pMacroEditView;

    if (pView == nullptr)
	{
		return;
	}

	UpdateToolButtons_Bin();
}

void QSttTestCntrFrameBase::UpdateToolButtons_Bin()
{
    QSttToolButtonBase *pButton = nullptr;
	BOOL bHasChangedShowState = FALSE;

	//开入（最多10个)
	for(int i=0; i<MAX_BINARYOUT_COUNT; i++)
	{
		CString str;
		str.Format(_T("Bin%03d"),i+1);
		pButton = m_oDataBtnsMngr.FindButtonByID(str);

        if (pButton == nullptr)
		{
			continue;
		} 

		if (i>=g_nBinCount)
		{
			if (pButton->isVisible())
			{
				pButton->ShowBtn(false);
				bHasChangedShowState = TRUE;
			}
		} 
		else if (!pButton->isVisible())
		{
			pButton->ShowBtn(true);
			bHasChangedShowState = TRUE;
		}

		if (m_pTestCtrlCntrBase->m_oBinaryConfig.m_binIn[i].nSelect)
		{	
			if (m_pTestCtrlCntrBase->m_oCurrEventResult.m_BinIn[i] != 0 && IsTestStarted())
			{
				pButton->SetPic(3);
			}
			else
			{
				pButton->SetPic(1);
			}
		}
		else
		{
			if (m_pTestCtrlCntrBase->m_oCurrEventResult.m_BinIn[i] != 0)
			{
				pButton->SetPic(2);
			}
			else
			{
				pButton->SetPic(0);
			}
		}
	}

	if (bHasChangedShowState)
	{
		AdjustStatusBarButtons();
	}
}

void QSttTestCntrFrameBase::InitBinaryIn_WebUI(CDataGroup *pParas)
{
    if (pParas == nullptr)
	{
		return;
	}

	CDvmData *pCurrData = (CDvmData*)pParas->FindByID("BinSelect");
	long nTmpValue = 0;

    if (pCurrData != nullptr)
	{
		nTmpValue = CString_To_long(pCurrData->m_strValue);

		if (nTmpValue == 0)
		{
			m_pTestCtrlCntrBase->m_oBinaryConfig.m_binIn[0].nSelect = 1;
			m_pTestCtrlCntrBase->m_oBinaryConfig.m_binIn[1].nSelect = 1;
			m_pTestCtrlCntrBase->m_oBinaryConfig.m_binIn[2].nSelect = 1;
			m_pTestCtrlCntrBase->m_oBinaryConfig.m_binIn[3].nSelect = 1;

			m_pTestCtrlCntrBase->m_oBinaryConfig.m_binIn[4].nSelect = 0;
			m_pTestCtrlCntrBase->m_oBinaryConfig.m_binIn[5].nSelect = 0;
			m_pTestCtrlCntrBase->m_oBinaryConfig.m_binIn[6].nSelect = 0;
			m_pTestCtrlCntrBase->m_oBinaryConfig.m_binIn[7].nSelect = 0;
		} 
		else
		{
			m_pTestCtrlCntrBase->m_oBinaryConfig.m_binIn[0].nSelect = 0;
			m_pTestCtrlCntrBase->m_oBinaryConfig.m_binIn[1].nSelect = 0;
			m_pTestCtrlCntrBase->m_oBinaryConfig.m_binIn[2].nSelect = 0;
			m_pTestCtrlCntrBase->m_oBinaryConfig.m_binIn[3].nSelect = 0;

			m_pTestCtrlCntrBase->m_oBinaryConfig.m_binIn[4].nSelect = 1;
			m_pTestCtrlCntrBase->m_oBinaryConfig.m_binIn[5].nSelect = 1;
			m_pTestCtrlCntrBase->m_oBinaryConfig.m_binIn[6].nSelect = 1;
			m_pTestCtrlCntrBase->m_oBinaryConfig.m_binIn[7].nSelect = 1;
		}

		return;
	}

	CString strBinID;
    CExBaseList *pBinList = nullptr;
    CExBaseObject *pBinValue = nullptr;
    POS pos = nullptr;
	BOOL bFind = FALSE;

	for(int nIndex = 0;nIndex<8;nIndex++)
	{
		strBinID.Format(_T("Bin%d"),nIndex+1);
		pBinList = (CExBaseList *)m_oBinaryInParas.FindByID(strBinID);

        if (pBinList != nullptr)
		{
			pos = pBinList->GetHeadPosition();

			while(pos)
			{
				pBinValue = pBinList->GetNext(pos);
				pCurrData = (CDvmData*)pParas->FindByID(pBinValue->m_strID);

                if (pCurrData != nullptr)
				{
					m_pTestCtrlCntrBase->m_oBinaryConfig.m_binIn[nIndex].nSelect = CString_To_long(pCurrData->m_strValue);
					bFind = TRUE;
					break;
				}
			}
		}
	}

	if (!bFind)
	{
		for(int nIndex = 0;nIndex<g_nBinCount;nIndex++)
		{
			m_pTestCtrlCntrBase->m_oBinaryConfig.m_binIn[nIndex].nSelect = 1;
		}
	}
}

void QSttTestCntrFrameBase::UpdateToolButtons_Bout()
{
    QSttToolButtonBase *pButton = nullptr;
	BOOL bHasChangedShowState = FALSE;

	for(int i=0; i<MAX_BINARYOUT_COUNT; i++)
	{
		CString str;
		str.Format(_T("Bout%03d"),i+1);
		pButton = m_oDataBtnsMngr.FindButtonByID(str);

        if (pButton == nullptr)
		{
			continue;
		}

		if (i>=g_nBoutCount)
		{
			if (pButton->isVisible())
			{
				pButton->ShowBtn(false);
				bHasChangedShowState = TRUE;
			}
		} 
		else if (!pButton->isVisible())
		{
			pButton->ShowBtn(true);
			bHasChangedShowState = TRUE;
		}

		if (m_pTestCtrlCntrBase->m_oCurrEventResult.m_BinOut[i] != 0 && IsTestStarted())
		{
			pButton->SetPic(2);
		}
		else
		{
			pButton->SetPic(0);
		}
	}

	if (bHasChangedShowState)
	{
		AdjustStatusBarButtons();
	}
}

void QSttTestCntrFrameBase::UpdateToolButtons_Light()
{
	if (IsTestStarted())
	{
		m_oDataBtnsMngr.UpdatePicSet("Run",STT_LIGHT_BTN_INDEX_Run);
	}
	else
	{
		m_oDataBtnsMngr.UpdatePicSet("Run",STT_LIGHT_BTN_INDEX_ShutOff);
	}

	if (m_pTestCtrlCntrBase->m_oCurrEventResult.m_nUdc != 0)
	{
		m_oDataBtnsMngr.UpdatePicSet("Udc",STT_LIGHT_BTN_INDEX_Yellow);
	}
	else
	{
		m_oDataBtnsMngr.UpdatePicSet("Udc",STT_LIGHT_BTN_INDEX_Red);
	}

    if (g_pTheSttTestApp->m_pTestCtrlCntr == nullptr)
	{
		return;
	}

	CExBaseList *pTestGlobalParas = g_pTheSttTestApp->m_pTestCtrlCntr->GetTestGlobalParas();

    if (pTestGlobalParas == nullptr)
	{
		return;
	}

	if (/*m_pTestCtrlCntrBase->m_oCurrEventResult.m_nIOverLoad*/stt_GetDataValueByID2(pTestGlobalParas, STT_SYS_STATE_ID_IBreak, 0) > 0)
	{
		m_oDataBtnsMngr.UpdatePicSet("OI",STT_LIGHT_BTN_INDEX_Yellow);
	} 
	else
	{
		m_oDataBtnsMngr.UpdatePicSet("OI",STT_LIGHT_BTN_INDEX_Red);
	}

	if (/*m_pTestCtrlCntrBase->m_oCurrEventResult.m_nUOverLoad*/stt_GetDataValueByID2(pTestGlobalParas, STT_SYS_STATE_ID_UShort, 0) > 0)
	{
		m_oDataBtnsMngr.UpdatePicSet("U",STT_LIGHT_BTN_INDEX_Yellow);
	} 
	else
	{
		m_oDataBtnsMngr.UpdatePicSet("U",STT_LIGHT_BTN_INDEX_Red);
	}

	if (/*m_pTestCtrlCntrBase->m_oCurrEventResult.m_nOverHeat*/stt_GetDataValueByID2(pTestGlobalParas, STT_SYS_STATE_ID_OverHeat, 0) > 0)
	{
		m_oDataBtnsMngr.UpdatePicSet("OH",STT_LIGHT_BTN_INDEX_Yellow);
	} 
	else
	{
		m_oDataBtnsMngr.UpdatePicSet("OH",STT_LIGHT_BTN_INDEX_Red);
	}
}

tmt_BinaryConfig* QSttTestCntrFrameBase::GetBinaryConfig()
{
	return &m_pTestCtrlCntrBase->m_oBinaryConfig;
}

//2022-4-3  lijunqing 暂时不考虑不使用的情况
void QSttTestCntrFrameBase::UpdateToolButtons()
{
	if (g_nLogDebugInfor == 1)	{		CLogPrint::LogString(XLOGLEVEL_TRACE, ">> begin UpdateToolButtons -  >>");	}

	//UpdateToolButtons_ParaEdit();
//	QSttToolButtonBase *pButton = m_oDataBtnsMngr.FindButtonByID("Run");
	UpdateToolButtons_FloatPanel();
	UpdateToolButtons_Light();
	UpdateToolButtons_Bin();
	UpdateToolButtons_Bout();

	if (g_nLogDebugInfor == 1)	{		CLogPrint::LogString(XLOGLEVEL_TRACE, ">> end UpdateToolButtons -  >>");	}
}

//m_pTestCtrlCntrBase这是个保护的对象，没有办法才放到这里的 后面再考虑放别的地方 sf 20220219
void QSttTestCntrFrameBase::SyncBinOutDatas( BOOL b/*=TRUE*/ )
{
	CSttMacroParaEditViewOriginal *pView = (CSttMacroParaEditViewOriginal*)m_pMacroEditView;

	for(int i = 0;i <  MAX_BINARYOUT_COUNT; i++)
	{
		if(b)		//从结构体参数->当前事件对象
		{
			m_pTestCtrlCntrBase->m_oCurrEventResult.m_BinOut[i] = m_pTestCtrlCntrBase->m_oBinaryConfig.m_binOut[i].nState;
		}
		else
		{
			m_pTestCtrlCntrBase->m_oBinaryConfig.m_binOut[i].nState = m_pTestCtrlCntrBase->m_oCurrEventResult.m_BinOut[i];
		}
	}

	for (int j = 0;j < MAX_ExBINARY_COUNT;j++)
	{
		if (b)
		{
			m_pTestCtrlCntrBase->m_oCurrEventResult.m_BinOutEx[j] = m_pTestCtrlCntrBase->m_oBinaryConfig.m_binOutEx[j].nState;
		}
		else
		{
			m_pTestCtrlCntrBase->m_oBinaryConfig.m_binOutEx[j].nState = m_pTestCtrlCntrBase->m_oCurrEventResult.m_BinOutEx[j];
		}
	}
}

void QSttTestCntrFrameBase::SysStateReport_OnSwitchChanged(CEventResult *pEventInfo)
{
/*UpdateToolButtons()已有
    ASSERT(pEventInfo != nullptr);

	CDataGroup dataGroup;
	if(g_pTheSttTestApp->m_pTestMacroUI->IsUIOriginal())
	{
		pEventInfo->GenEventDataGroup(dataGroup,&((CSttMacroParaEditViewOriginal*)m_pMacroEditView)->m_oBinaryConfig);
	}
	else
	{
        pEventInfo->GenEventDataGroup(dataGroup,nullptr);
	}

	m_oDataBtnsMngr.UpdataDataButtons(&dataGroup);
*/
}

void QSttTestCntrFrameBase::Ats_UpdateParameter()
{
	CDataGroup oRetParas;

	m_pMacroEditView->GetDatas(&oRetParas);
	SaveUIParaFile(&oRetParas);	//2022-10-16  lijunqing 记录和保存当前页面设置的值：设置为默认值

	InitCommonParasByDatas(&oRetParas);
	//比较oRetParas 与 m_pTestMacroUI_Paras
	if (!m_pTestMacroUI_Paras->IsEqual(&oRetParas))
	{
		oRetParas.CopyChildren(m_pTestMacroUI_Paras);

		if (g_pTheSttTestApp->m_pTestMacroUI->IsUIWeb()
			|| g_pTheSttTestApp->m_pTestMacroUI->m_strID == STT_ORG_MACRO_MUAutoTest)
		{
			m_pTestCtrlCntrBase->Ats_GenerateTemplate();
		}
		else
		{
			CString strItemPath = g_pTheSttTestApp->m_pTestMacroUI->m_strID;
			CString strMacroID = _T("");

			if(g_pTheSttTestApp->m_pTestMacroUI->IsUIOriginal())
			{
				strMacroID = g_pTheSttTestApp->m_pTestMacroUI->m_strID;
			}

			strItemPath += "$" + strItemPath;
			if(g_pTheSttTestApp->m_pTestMacroUI->m_strID == STT_ORG_MACRO_IntelligentTest
				||g_pTheSttTestApp->m_pTestMacroUI->m_strID == STT_ORG_MACRO_RemoteMeasTest)
			{
				//CString strItemPathNodes=strItemPath.Left(strItemPath.Find(_T("Test")));
				CString strID = g_pTheSttTestApp->m_pTestMacroUI->m_strID;
				long nIndex = strID.Find(_T("Test"));

				if (nIndex>=0)
				{
					CString strItemPathNodes = strItemPath.Left(nIndex);
				strItemPath+= "$" + strItemPathNodes;
				}

				if(g_pTheSttTestApp->m_pTestMacroUI->m_strID == STT_ORG_MACRO_IntelligentTest)
				{
					strMacroID=STT_ORG_MACRO_BinaryManuTest;//开关量手动测试MarcoID
				}
				else
				{
					strMacroID=STT_ORG_MACRO_ManualTest;
				}		
			}
			m_pTestCtrlCntrBase->Ats_SetItemPara(strItemPath, strMacroID);
			SetValues_dsRcdStep6U6I(TRUE);
		}
	}
}

void QSttTestCntrFrameBase::SysStateReport_OnStateChanged(CEventResult *pEventInfo)
{
	if((CSttMacroParaEditViewMngr::GetCurMacroID() == STT_ORG_MACRO_StateTest)||(CSttMacroParaEditViewMngr::GetCurMacroID() == STT_ORG_MACRO_SmvAbnTest)
		||(CSttMacroParaEditViewMngr::GetCurMacroID() == STT_ORG_MACRO_GseAbnTest))
	{
		((QSttMacroParaEditViewState*)m_pMacroEditView)->SysStateReport_OnStateChanged(pEventInfo);
	}
	else if (g_pTheSttTestApp->m_pTestMacroUI->IsUIWeb()&&HasManuTrigerBtn()&&(pEventInfo->m_nCurrStateIndex == 1))//zhouhj 20220403 在网页模块 进入第二个状态后,都需要将手动触发灰掉
	{
		EnableManualTriggerButton(false);
//		UpdateButtonStateByID(STT_CNTR_CMD_ManuTriger,false,true);
	}
}

void QSttTestCntrFrameBase::OnCmd_DebugSetDatas()
{
	if (g_pTheSttTestApp->m_pTestMacroUI->IsUIWeb())
	{
        //QSttMacroParaEditViewHtml *pSttMacroParaEditViewHtml = (QSttMacroParaEditViewHtml*)m_pMacroEditView->m_pMacroParaEditWnd;
		m_pMacroEditView->SetDatas(m_pTestMacroUI_Paras);
	}
}

void QSttTestCntrFrameBase::OnCmd_DebugGetDatas()
{
	if (g_pTheSttTestApp->m_pTestMacroUI->IsUIWeb())
	{
        //QSttMacroParaEditViewHtml *pSttMacroParaEditViewHtml = (QSttMacroParaEditViewHtml*)m_pMacroEditView->m_pMacroParaEditWnd;
		m_pMacroEditView->GetDatas(m_pTestMacroUI_Paras);
	}
}

void QSttTestCntrFrameBase::OnCmd_DebugSetDatasFile(long nFileIndex)
{
    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return;
	}

	if (! g_pTheSttTestApp->m_pTestMacroUI->IsUIWeb())
	{
		return;
	}

	m_pTestCtrlCntrBase->OpenMacroTestUI_ParaFile(nFileIndex);
    //QSttMacroParaEditViewHtml *pSttMacroParaEditViewHtml = (QSttMacroParaEditViewHtml*)m_pMacroEditView->m_pMacroParaEditWnd;
	m_pMacroEditView->SetDatas(m_pTestMacroUI_Paras);
}

void QSttTestCntrFrameBase::OnCmd_DebugSetDatasFile1()
{
	OnCmd_DebugSetDatasFile(1);
}

void QSttTestCntrFrameBase::OnCmd_DebugSetDatasFile2()
{
	OnCmd_DebugSetDatasFile(2);
}

void QSttTestCntrFrameBase::OnCmd_DebugSaveDatasFile()
{
	SaveMacroTestUI_ParaFile("_dbug");
}

void QSttTestCntrFrameBase::OnCmd_DebugUpdateReport()
{
    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return;
	}

	UpdateRptHtml();
}

#include "../../../Module/QT/Png64/DrawPngBase64.h"

void QSttTestCntrFrameBase::OnCmd_DebugFillReport()
{

    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return;
	}

	FillReport();


// 	//调试FillReportImg
// 	CDrawPngBase64 oPngDraw;
// 	oPngDraw.CreatePngDraw(600, 400);
// 	oPngDraw.FillBack(RGB(0, 0, 255));
// 	oPngDraw.PngDrawDemo();
// 	oPngDraw.GetPngBase64();
// 
// 	m_pSttReportViewHtml->FillReportImg("", "TestPng", oPngDraw.m_strPngBase64);
// 
// 	//调试FillReportDataset
// 	CDvmDataset oDataset;
 //	CString strFile;
// 	strFile = _P_GetDBPath();
// 	strFile += _T("SttReportDebug_Dataset.xml");
// 	if  (! oDataset.OpenXmlFile(strFile, CDataMngrXmlRWKeys::g_pXmlKeys) )
// 	{
// 		return;
// 	}
// 
// 	m_pSttReportViewHtml->FillReportDataset("", "TestFillDataset", &oDataset);

// 	//调试FillRptMapDatas
// 	CSttRptMapDatas oSttRptMapDatas;
// 	strFile = _P_GetDBPath();
// 	strFile += _T("SttReportDebug_RptMapDatas.xml");
// 	if  (! oSttRptMapDatas.OpenXmlFile(strFile, CSttCmdDefineXmlRWKeys::g_pXmlKeys) )
// 	{
// 		return;
// 	}
// 
// 	m_pSttReportViewHtml->FillRptMapDatas(&oSttRptMapDatas, "INLEGIBLE");
}

void QSttTestCntrFrameBase::OnCmd_DebugItemStateChanged()
{
    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return;
	}

    //if (m_pSttReportViewHtml == nullptr)
    //{
    //	return;
    //}
    //
    //m_pSttReportViewHtml->ItemStateChanged("DistanceTest$GPDis1", "DistanceTest$GPDis1$A095", "TESTING");
}

void QSttTestCntrFrameBase::OnCmd_DebugOutPutWidget()
{
	//bool bShow = m_pOutputWidget->isVisible();
	//m_pOutputWidget->setVisible(!bShow);
	SetActiveWidget(m_pOutputWidget, ActiveWidgetType_Other);
}

void QSttTestCntrFrameBase::OnCmd_DebugStartTest()
{
	UpdateCmdButtonsState(STT_TEST_STATE_TESTTING);
}

void QSttTestCntrFrameBase::OnCmd_DebugStopTest()
{
	UpdateCmdButtonsState(STT_TEST_STATE_TEST_STOPED);
}

void QSttTestCntrFrameBase::OnCmd_ConnectApp()
{
	m_pTestCtrlCntrBase->ConnectAtsServer();
}

void QSttTestCntrFrameBase::OnCmd_Debug()
{
    //CSttMacroParaEditInterface *pSttMacroParaEditInterface = CSttMacroParaEditViewMngr::GetSttMacroParaEditViewHtml();//获取网页界面
    //
    //if (pSttMacroParaEditInterface == nullptr)
    //{
    //	return;
    //}

    //QSttMacroParaEditViewHtml *pSttMacroParaEditViewHtml = (QSttMacroParaEditViewHtml*)pSttMacroParaEditInterface->m_pMacroParaEditWnd;

    //if (pSttMacroParaEditViewHtml == nullptr)
    //{
    //	return;
    //}
    //
    //pSttMacroParaEditViewHtml->Debug();
}

void QSttTestCntrFrameBase::OnCmd_DebugSaveTest()
{
	CString strFile = m_pTestCtrlCntrBase->SaveTestFile("", "");

	if (strFile.GetLength() < 5)
	{
		return;
	}

	strFile = ChangeFilePostfix(strFile, "html");

    //if (m_pSttReportViewHtml != nullptr)
    //{
    //	m_pSttReportViewHtml->SaveHtmlReportFile(strFile);
    //}
}

extern long g_nAtsGenTemplateForDebug;

void QSttTestCntrFrameBase::OnCmd_DebugGenForDebug()
{
	if (g_nAtsGenTemplateForDebug == 0)
	{
		g_nAtsGenTemplateForDebug = 1;
	}
	else
	{
		g_nAtsGenTemplateForDebug = 0;
	}

	CLogPrint::LogFormatString(XLOGLEVEL_TRACE, "g_nAtsGenTemplateForDebug == %d", g_nAtsGenTemplateForDebug);
}

void QSttTestCntrFrameBase::OnCmd_DebugGenTemplate()
{
    GenerateTemplate(nullptr, "", "");
}

void QSttTestCntrFrameBase::OnCmd_DebugSaveAsSysFiles()
{
    if (m_pTestCtrlCntrBase == nullptr)
	{
		return;
	}

	//保存缺省文件
	SaveMacroTestUI_ParaFile("");

	//保存缺省模板文件：用于上位机端显示测试项目
	m_pTestCtrlCntrBase->SaveCurrTestMacroUITemplateFile();
}

void QSttTestCntrFrameBase::OnCmd_RemoteCtrl()
{
    //sun SetActiveWidget(m_pRemoteCtrlWidget, ActiveWidgetType_Other);
}

void QSttTestCntrFrameBase::OnCmd_IecCap()
{
	SetActiveWidget(m_pSttIecRecordMainWidget, ActiveWidgetType_Other);
}

void QSttTestCntrFrameBase::OnCmd_IecCapWriteFile()
{
	SetActiveWidget(m_pSttIecRecordMainWidget, ActiveWidgetType_Other);
}

void QSttTestCntrFrameBase::OnCmd_IecCapDebugHead()
{
	SetActiveWidget(m_pSttIecRecordMainWidget, ActiveWidgetType_Other);
}

// #include "../RecordTest/QT/RingMemBufShmDebugWidget.h"
// extern QRingMemBufShmDebugWidget *g_pRingMemBufShmDebugWidget;

void QSttTestCntrFrameBase::OnCmd_ScreenShot()
{
// 	g_pRingMemBufShmDebugWidget->show();
// 	return;
// 	CTickCount32 oTick;
// 	long nIndex = 0;
// 
// 	while(nIndex<50)
// 	{
// 		m_oTimerAtsTest.start(100);
// 		oTick.DoEvents(105);
// 		m_oTimerAtsTest.stop(1);
// 		nIndex++;
// 	}
// 
// 	CString strTmp1,strTmp2,strTmp3;
// 	strTmp1 = "测试1%lf测试3";
// 	strTmp3 = "测试2";
// 	double dValue = 2.33f;
// 	strTmp2.Format(strTmp1/*.GetString()*/,dValue/*strTmp3.GetString()*/);
// 	strTmp3.Format(strTmp1.GetString(),dValue);
//  	return;

	CString strFilePath  = g_oFileMngrTool.GetFolderPath_STD(STT_FILE_MNGR_PrintScreen);

//是否使用自定义的时间对象
#ifdef USE_Custom_CDateTime
	int nYear = 1970, nMon = 1, nDay = 1, nHour = 0, nMin = 0, nSec = 0,nMs = 0;
	CDateTime::GetTime(nYear,nMon,nDay,nHour,nMin,nSec,nMs);
	CString strFileName;
	strFileName.Format(_T("%04d_%02d_%02d_%02d_%02d_%02d"),nYear,nMon,nDay,nHour,nMin,nSec);
#else
 	QDateTime tmData = QDateTime::currentDateTime();
 	CString strFileName = tmData.toString("yyyy_MM_dd_hh_mm_ss"); 
#endif
	strFilePath += "/";
//  CreateAllDirectories(strFilePath);
    strFilePath += strFileName;
    QPixmap *pPixMainScreen = new QPixmap();
    *pPixMainScreen = QPixmap::grabWindow(QApplication::desktop()->winId()/*,0,0,1024,768*/);/*QPixmap::grabWindow(QApplication::desktop()->winId())*/;

    if(pPixMainScreen->isNull())
    {
		CLogPrint::LogFormatString(XLOGLEVEL_ERROR,/*_T("保存截屏(%s)(isNull)失败.")*/g_sLangTxt_Gradient_INUnSavescreen.GetString(),strFilePath.GetString()); //lcq
		delete pPixMainScreen;
        return;
    }

	strFilePath += ".png";

	if(false == pPixMainScreen->save(strFilePath,"PNG"))
    {
		CLogPrint::LogFormatString(XLOGLEVEL_ERROR,/*_T("保存截屏(%s)(save)失败.")*/g_sLangTxt_Gradient_UnSavescreen.GetString(),strFilePath.GetString()); //lcq
		delete pPixMainScreen;
        return;
    }

#ifdef CURLINUX
    ::system("sync");
#endif
	//CXMessageBox::information(this,tr("提示"),tr("截屏成功."));
	
	CXMessageBox::information(this,g_sLangTxt_Message.GetString(),g_sLangTxt_Gradient_ShotScreenSus.GetString());//lcq
//	pPixMainScreen->toImage();
	CLogPrint::LogFormatString(XLOGLEVEL_TRACE,/*_T("保存截屏(%s)成功.")*/g_sLangTxt_Gradient_Savescreen.GetString(),strFilePath.GetString()); //lcq
	delete pPixMainScreen;
}

//2022-12-02  lijunqing
void QSttTestCntrFrameBase::OnCmd_Assist()
{
	assist_show_menu();
}

//2022-12-27  lijunqing
void QSttTestCntrFrameBase::InitIecCapTest(bool bActiveIecCap, bool bStartDetect,bool bShowMenuBtns)
{
	if (!bShowMenuBtns)
	{
		UpdateButtonStateByID(STT_CNTR_CMD_Menu,true);//2023-10-31 suayang 北京需求开放菜单选项
		UpdateButtonStateByID(STT_CNTR_CMD_AddMacro,false,false);
		UpdateButtonStateByID(STT_CNTR_CMD_TemplateView,false,false);
		UpdateButtonStateByID(STT_CNTR_CMD_ItemList,false,false);
		UpdateButtonStateByID(STT_CNTR_CMD_ReportView,false,false);
		UpdateButtonStateByID(STT_CNTR_CMD_ChRsMaps,false,false);
		AdjustToolBarButtons();
	}

	if (bActiveIecCap)
	{
		OnCmd_IecCap();
	}

	if (bStartDetect)
	{
        if (m_pSttIecRecordMainWidget != nullptr)
		{
			m_pSttIecRecordMainWidget->StartDetect();
		}
	}
}

void QSttTestCntrFrameBase::InitRemoteCtrlTest(bool bActiveRemoteCtrl, bool bStart,bool bShowMenuBtns)
{
	if (bActiveRemoteCtrl)
	{
		OnCmd_RemoteCtrl();

        if (m_pTestCtrlCntrBase != nullptr)//zhouhj 2024.3.19 在单独的遥控测试功能时,连接底层服务端,显示电池电量等信息
		{
			m_pTestCtrlCntrBase->ConnectAtsServer();
		}
	}

	if (bStart)
	{
		CreateEngineClientWidget();
	}

}

void QSttTestCntrFrameBase::EnableStartStopButton(BOOL bEanble)
{
    if (m_pStartTestBtn != nullptr)
	{
		QSttToolButtonBase *pStartStopButton = (QSttToolButtonBase*)m_pStartTestBtn->m_dwItemData;

        if (pStartStopButton != nullptr)
		{
			pStartStopButton->setEnabled(bEanble);
		}
	}
}

void QSttTestCntrFrameBase::EnableManualTriggerButton(BOOL bEanble)
{
    if (m_pManualTriggerBtn != nullptr)
	{
		QSttToolButtonBase *pButtonUI = (QSttToolButtonBase*)m_pManualTriggerBtn->m_dwItemData;

        if (pButtonUI != nullptr)
		{
			pButtonUI->setEnabled(bEanble);
		}
	}
}

void QSttTestCntrFrameBase::OnCmd_Menu()
{
	
}

bool QSttTestCntrFrameBase::PrepStartTest()
{
    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return false;
	}

    if (m_pMacroEditView == nullptr)
	{
		return false;
	}

	if (g_pTheSttTestApp->m_pTestMacroUI->IsUIOriginal())
	{
		CSttMacroParaEditViewOriginal *pViewOriginal = (CSttMacroParaEditViewOriginal*)m_pMacroEditView;

		if (!pViewOriginal->PrepStartTest())
		{
			return false;
		}

		if (pViewOriginal->m_bSystemParasChanged)
		{
			pViewOriginal->m_bSystemParasChanged = FALSE;
			Ats_SetItemPara(STT_CMD_TYPE_SYSTEM_SystemConfig);
		}
	}

	if (g_oSystemParas.HasDigitalInOrOut())//zhouhj 20220404 数字量输出,并且当前IEC配置为空的情况下，不能开始测试
	{
		if (!g_oSttTestResourceMngr.HasContrlBlockSelected_IecConfig())
		{
			CXMessageBox::information(this,/*tr("警告")*/g_sLangTxt_warning.GetString(),/*tr("当前IEC配置为空.")*/g_sLangTxt_NullIEC.GetString()); //lcq
			return false;
		}

		if (g_pTheSttTestApp->m_pTestMacroUI->IsUIOriginal() && ((CSttMacroParaEditViewOriginal*)m_pMacroEditView)->m_bIECGoutMapChanged)
		{
			Ats_SetItemPara(STT_CMD_TYPE_SYSTEM_IECConfig);//在手动试验、谐波模块,更新GOOSE发布数据类型或者修改通道映射后,此处更新IEC配置相关内容
			((CSttMacroParaEditViewOriginal*)m_pMacroEditView)->m_bIECGoutMapChanged = FALSE;
		}
	}

	if (m_pCharLibWidget)
	{
		m_pCharLibWidget->m_pImpCharactWidget->ClearSearchPoints();

		if (m_pCharLibWidget == m_pActiveWidget)//zhouhj 2023.8.8如果当前激活界面为特性曲线,在开始测试时,将特性曲线数据同步到网页
		{
			TemplateView_Prepare();
		}
	}

    if (m_pCharactWidgetForTest != nullptr)
	{
		m_pCharactWidgetForTest->ClearSearchPoints();
	} 

    if (m_pSttCharacterDrawPng != nullptr)
	{
		m_pSttCharacterDrawPng->ClearSearchPoints_png();
		m_pSttCharacterDrawPng->ClearPngCache();
	}

	return true;
}

void QSttTestCntrFrameBase::InitCommonParasByDatas(CDataGroup *pDataGroup_Paras)
{
    if (pDataGroup_Paras == nullptr)
	{
		return;
	}

	g_nMuTimeTest_UseNoPPS = 0;

	if (!pDataGroup_Paras->GetDataValue("PPS_SetType",g_nMuTimeTest_UseNoPPS))
	{
		CExBaseObject *pCurrObj = pDataGroup_Paras->FindByID("MU");

        if (pCurrObj != nullptr)
		{
			if (pCurrObj->GetClassID() == DTMCLASSID_CDATAGROUP)
			{
				CDataGroup *pMU_Obj = (CDataGroup*)pCurrObj;
				pMU_Obj->GetDataValue("PPS_SetType",g_nMuTimeTest_UseNoPPS);
			}
		}
	}
}

void QSttTestCntrFrameBase::OnCmd_StartTest()
{
#ifdef _PSX_QT_LINUX_
	if(m_oDataBtnsMngr.IsLowPower())
	{
		CLogPrint::LogString(XLOGLEVEL_ASSIST,/*_T("当前测试仪剩余电量过低,请先充电!!!")*/g_sLangTxt_Native_LowBatteryLevel);
		//		CXMessageBox::information(this,tr("警告"),tr("当前测试仪剩余电量过低,请先充电!!!"));
		return;
	}
#endif


	//2024/1/3 wangjunsheng 当在报文探测界面时，禁止开始测试
	CString strIDMacroUI = g_pTheSttTestApp->GetCurrTestMacroUI();

	if (strIDMacroUI == "")
	{
		CString strMsgText;

		if (CSttMacroTestUI_TestMacroUIDB::g_strMacroFileID == "RemoteCtrlTest")
		{
			strMsgText = _T("遥控界面无法直接开始测试.");
		} 
		else
		{
			strMsgText = _T("报文探测界面无法直接开始测试.");
		}

		CLogPrint::LogString(XLOGLEVEL_ASSIST,strMsgText);
		return;
	}


	if (!MUTestValid())
	{
		CLogPrint::LogString(XLOGLEVEL_ASSIST,/*_T("合并单元测试,需要先进入IEC探测监视界面.")*/g_sLangTxt_Native_IecDetection);
		//		CXMessageBox::information(this,tr("警告"),tr("合并单元测试,需要先进入IEC探测监视界面."));
		return;
	}

	if (!PrepStartTest())
	{
		return;
	}

	//2022-12-02  lijunqing 触发助手开始测试事件，判断是否可以开始测试
    if (!assist_event(STT_CNTR_CMD_StartTest, nullptr))
	{
		return;
	}

	SaveCharacteristicsData();
	EnableStartStopButton(FALSE);
	on_UpdateEnableState(STT_TEST_STATE_TESTTING);
	EnableManualTriggerButton(FALSE);
	ClearAll_ResultUI();//清除测试结果显示内容
	ClearItemStateList();
//	CLogPrint::LogFormatString(XLOGLEVEL_TRACE,_T("开始禁用"));
	CDataGroup oRetParas;

	if (g_pTheSttTestApp->m_pTestMacroUI->IsUIWeb())
	{
		oRetParas.AppendCloneEx(*m_pTestMacroUI_Paras);
		m_pMacroEditView->GetDatas(&oRetParas);
        SetValues_dsRcdStep6U6I(&oRetParas,TRUE);
		InitBinaryIn_WebUI(&oRetParas);//网页界面需要根据获取的界面参数开入选择状态,更新开入选择图标  zhouhj 20220426
	}
	else
	{
		m_pMacroEditView->GetDatas(&oRetParas);
		SetValues_dsRcdStep6U6I(TRUE);
//		oRetParas.SaveXmlFile("D://123456.xml",CDataMngrXmlRWKeys::g_pXmlKeys);
	}
	
	InitCommonParasByDatas(&oRetParas);
	SaveUIParaFile(&oRetParas);	//2022-10-16  lijunqing 记录和保存当前页面设置的值：设置为默认值

//	CLogPrint::LogFormatString(XLOGLEVEL_TRACE,_T("解除禁用"));

//	CLogPrint::LogFormatString(XLOGLEVEL_RESULT,_T("OnCmd_StartTest[++++]."));
	if (m_pTestCtrlCntrBase->StartTest(&oRetParas))
	{
        //if (m_pSttReportViewHtml != nullptr)
        //{
        //	m_pSttReportViewHtml->UpdateReportHead_StartEndTestTime(!m_bHasUpdateRptStartTestTime,TRUE);
        //}

		m_bHasUpdateRptStartTestTime = TRUE;
	}
	else
	{
#ifdef _PSX_QT_LINUX_
		CString strTitile,strMsg;
		strTitile = g_sLangTxt_Message/*"提示"*/;
		strMsg = g_sLangTxt_Native_StartTestSendFail/*"开始测试命令下发失败."*/;
		CXMessageBox::information(this, strTitile, strMsg);
#endif
		EnableStartStopButton(TRUE);
		on_UpdateEnableState(STT_TEST_STATE_TEST_STOPED);
	}

//	CLogPrint::LogFormatString(XLOGLEVEL_RESULT,_T("OnCmd_StartTest[----]."));
}

void QSttTestCntrFrameBase::OnCmd_TestThis()
{

}

void QSttTestCntrFrameBase::OnCmd_ManuTriger()
{
    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return;
	}

	if (m_pTestCtrlCntrBase->SendManuTrigger() == STT_CMD_ExecStatus_SUCCESS)
	{
		g_theTestCntrFrame->UpdateButtonStateByID(STT_CNTR_CMD_ManuTriger,false);
	}
}

void QSttTestCntrFrameBase::OnCmd_StopTest()
{
    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return;
	}

	EnableStartStopButton(FALSE);

	if (!m_pTestCtrlCntrBase->StopTest())
	{
#ifdef _PSX_QT_LINUX_
		CString strTitile,strMsg;
		strTitile = g_sLangTxt_Message/*"提示"*/;
		strMsg = g_sLangTxt_Native_StopTestSendFail/*"停止测试命令下发失败."*/;
		CXMessageBox::information(this, strTitile, strMsg);
#endif
		EnableStartStopButton(TRUE);
	}
}

BOOL QSttTestCntrFrameBase::CanAddTestMacroUI()
{
	return TRUE;
}

void QSttTestCntrFrameBase::closeEvent( QCloseEvent * event )
{
	g_pTheSttTestApp->ExitSttTestApp();
#ifndef NOT_USE_ASSIST
	assist_release();
#endif
	QMainWindow::closeEvent(event);
}

void QSttTestCntrFrameBase::OnCmd_AddMacro(BOOL bUseNameID)
{
	if (!CanAddTestMacroUI())
	{
		CLogPrint::LogString(XLOGLEVEL_TRACE, /*_T("请在测试项目树形控件中选择合法的项目分类")*/g_sLangTxt_Gradient_Selectleg.GetString()); //lcq
		return;
	}

	QSttAddMacroWidget dlg(m_gFont,this);
	dlg.Use_Name_ID(bUseNameID);  //lijunqing 2022-6-24  lijunqing LINUX 不使用Name
	dlg.m_pCurrentSelGbItem = (CExBaseList *)m_pSttGbTreeView->GetCurrSelectGbItem();
//	connect(&dlg,SIGNAL(sig_TreeItemSelect(CSttMacroTestUI_TestMacroUIRef *)),this,
//		SLOT(slot_SelectTestMacro(CSttMacroTestUI_TestMacroUIRef *)));
	
	if (dlg.exec() != 1)
	{
		return;
	}

	slot_SelectTestMacro(dlg.m_pCurrUIRef, dlg.m_strItemsName, dlg.m_strItemsID);
}

void QSttTestCntrFrameBase::OnCmd_ItemList()
{
	//观察效果，暂时先显示test-macro-uis中的内容，后续改成GuideBook显示 sf 20220111
    if(m_pSttGbTreeView == nullptr)
	{
		return;
	}

	BOOL bIsVisible = ! m_pSttGbTreeView->isVisible();
	m_pSttGbTreeView->setVisible(bIsVisible);
	CalRectArea();
	m_pSttGbTreeView->setGeometry(m_rcGbItemsArea);
}

void QSttTestCntrFrameBase::SendMenuButtonClick(QString strFuncID)
{
#ifndef NOT_USE_ASSIST
	g_theAssistWndDynEffExecTool->Flash(strFuncID,"","",5000);
#endif

	emit sig_MenuButtonClick(strFuncID);
}

CString QSttTestCntrFrameBase::FindNameFromTestMacros(CTestMacros* pTestMacros, CString strMacroID, CString strID)
{
	CTestMacro* pTestMacro = (CTestMacro*)pTestMacros->FindByID(strMacroID);
	if(pTestMacros)
	{
        CShortData* pData = nullptr;
		if(pTestMacro->GetFaultParas())
		{
			pData = (CShortData*)pTestMacro->GetFaultParas()->SelectData(strID);
			if(pData)
			{
				return pData->m_strName;
			}
		}

		if(pTestMacro->GetSysParas())
		{
			pData = (CShortData*)pTestMacro->GetSysParas()->SelectData(strID);
			if(pData)
			{
				return pData->m_strName;
			}
		}

		if(pTestMacro->GetResults())
		{
			pData = (CShortData*)pTestMacro->GetResults()->SelectData(strID);
			if(pData)
			{
				return pData->m_strName;
			}
		}

		strID = strID.Mid(strID.indexOf('$') + 1);
		pData = (CShortData*)pTestMacro->m_list_FaultParasEx.SelectData(strID);
		if(pData)
		{
			return pData->m_strName;
		}

		pData = (CShortData*)pTestMacro->m_list_ResultParasEx.SelectData(strID);
		if(pData)
		{
			return pData->m_strName;
		}
	}

	CString strText;
	if(strID.indexOf(g_strTestResultJudgeKey) != -1)
	{
		xlang_GetLangStrByFile(strText, "Native_ResultJudge");
		return strText;
	}
	else if(strID.indexOf(strID == g_strTestResultDescriptKey) != -1)
	{
		xlang_GetLangStrByFile(strText, "Native_ResultDescript");
		return strText;
	}
	else if(strID.indexOf(strID == g_strTestResultTimeKey) != -1)
	{
		xlang_GetLangStrByFile(strText, "Native_ResultTime");
		return strText;
	}
	else if(strID.indexOf(strID == g_strTestResultAbsRsltCal1Key) != -1)
	{
		xlang_GetLangStrByFile(strText, "Native_ResultAbsRsltCal1");
		return strText;
	}
	else if(strID.indexOf(strID == g_strTestResultAbsRsltCal2Key) != -1)
	{				 
		xlang_GetLangStrByFile(strText, "Native_ResultAbsRsltCal2");
		return strText;
	}
	else if(strID.indexOf(strID == g_strTestResultRelRsltCal1Key) != -1)
	{
		xlang_GetLangStrByFile(strText, "Native_ResultRelRsltCal1");
		return strText;
	}
	else if(strID.indexOf(strID == g_strTestResultRelRsltCal2Key) != -1)
	{
		xlang_GetLangStrByFile(strText, "Native_ResultRelRsltCal2");
		return strText;
	}   

	return "";
}

void QSttTestCntrFrameBase::SetErrorValueFromWzd(CDataGroup* pDataGroup)
{
	if(m_pTestCtrlCntrBase->GetCurrTestMacroUI()->m_strID == STT_CMD_ATS_MACRO_ID_StateTest)
	{
		CDataGroup* pParasData = (CDataGroup*)m_pTestMacroUI_Paras->FindByID("rslt_evaluation");
		pParasData->InitDataValues(pDataGroup, FALSE);
// 		for(int i = 0; i < pParasData->GetCount(); i++)
// 		{
// 			CDataGroup* pErrorGroup = (CDataGroup*)pParasData->GetAt(i);
// 			CDvmData* pData = (CDvmData*)pErrorGroup->FindByID("ActT_AbsErr");
// 			CShortData* pShortData = (CShortData*)pDataGroup->GetAt(i);
// 			pData->m_strValue = pShortData->m_strValue;
// 			pData = (CDvmData*)pErrorGroup->FindByID("ActT_RelErr");
// 			pShortData = (CShortData*)pDataGroup->GetAt(i + 10);
// 			pData->m_strValue = pShortData->m_strValue;
// 		}
	}
	else
	{
		POS pos = pDataGroup->GetHeadPosition();
		while (pos)
		{
			CDvmData* pData = (CDvmData*)pDataGroup->GetNext(pos);
			CDvmData* pParasData = (CDvmData*)m_pTestMacroUI_Paras->FindByID(pData->m_strID);
			if(pParasData)
			{
				pParasData->m_strValue = pData->m_strValue;
			}
		}
	}
}

void QSttTestCntrFrameBase::OnCmd_TemplateView()
{
	QWidget *pMacroEditWidget = GetMacroEditWidget();

    if (pMacroEditWidget == nullptr)
	{
		return;
	}

	TemplateView_Prepare();//打开模板视图时,提前准备,如：差动同步特性曲线界面参数


	if (g_pTheSttTestApp->m_pTestMacroUI->IsUIOriginal())
	{
		SetActiveWidget(pMacroEditWidget, ActiveWidgetType_MacroUI_Original);
	}
	else
	{
		SetActiveWidget(pMacroEditWidget, ActiveWidgetType_MacroUI_Html);
	}
}	

void QSttTestCntrFrameBase::OnCmd_ReportView()
{
    //SetActiveWidget(m_pSttReportViewHtml, ActiveWidgetType_Other);
}

void QSttTestCntrFrameBase::OnCmd_HardConfig()
{
	QHardwareSetDlg oHardwareSetDlg(this);
	oHardwareSetDlg.setFont(*g_pSttGlobalFont);
	oHardwareSetDlg.initUI(&g_oSystemParas);
	Global_SoftKeyBoardAttachObj(&oHardwareSetDlg);
	m_bUpdateHardCfgFromRealTime = false;

	if (oHardwareSetDlg.exec() == QDialog::Accepted)
	{
		g_oSttTestResourceMngr.SaveSystemParasFile();
		Cmd_SendSystemConfig();
	}

#ifdef _USE_SoftKeyBoard_
	QSoftKeyBoard::ReAttachObj();
#endif

	m_bUpdateHardCfgFromRealTime = true;

}

void QSttTestCntrFrameBase::OnCmd_IECConfig()
{	
	UpdateButtonsStateByID(STT_CNTR_CMD_IECConfig, FALSE);//2024-6-21 wuxinyi 在IEC配置界面没关闭之前禁用该按钮

#ifdef _PSX_QT_LINUX_
	QSttIecConfigDialog oIecConfigDlg(&g_oSttTestResourceMngr.m_oIecDatasMngr, this);
#else
	QSttIecConfigDialogWin oIecConfigDlg(&g_oSttTestResourceMngr.m_oIecDatasMngr, this);
#endif
	oIecConfigDlg.InitUI();
	oIecConfigDlg.setWindowModality(Qt::WindowModal);
	oIecConfigDlg.m_pSclStation = &m_pTestCtrlCntrBase->m_oSclStation;
	connect(&oIecConfigDlg, SIGNAL(sig_IecCfgDataMngrUpdate()),SLOT(slot_IecCfgDataMngrUpdate()));

#ifdef _USE_SoftKeyBoard_
	QSoftKeyBoard::AttachObj(&oIecConfigDlg);
#endif
	oIecConfigDlg.exec();
#ifdef _USE_SoftKeyBoard_
	QSoftKeyBoard::ReAttachObj();
#endif

	disconnect(&oIecConfigDlg, SIGNAL(sig_IecCfgDataMngrUpdate()),this,SLOT(slot_IecCfgDataMngrUpdate()));

	UpdateButtonsStateByID(STT_CNTR_CMD_IECConfig, TRUE);

}

void QSttTestCntrFrameBase::OnCmd_VectorDrawView()
{
    if (m_pVectorWidget != nullptr)
	{
		SetActiveWidget(m_pVectorWidget, ActiveWidgetType_Other);

		//2023.7.31 zhangyq 获取当前MacroID，判断是否为功率方向，如果是功率方向则设置当前矢量图的工作模式
		CString strCurrUI_ID = GetCurrentUI_ID();
		if(strCurrUI_ID == _T("PowerDirectionTest"))
		{
			CDataGroup oParas;
			oParas.AppendCloneEx(*m_pTestMacroUI_Paras);
			m_pMacroEditView->GetDatas(&oParas);
			m_pVectorWidget->SetVectorMode(VECTOR_POWERWORK,&oParas);
		}
		else
		{
            m_pVectorWidget->SetVectorMode(VECTOR_COMMON, nullptr);
		}
	}
}

void QSttTestCntrFrameBase::OnCmd_WaveDrawView()
{

}

void QSttTestCntrFrameBase::OnCmd_StateDrawView()
{
    if (m_pStateMonitorWidget != nullptr)
	{
		SetActiveWidget(m_pStateMonitorWidget, ActiveWidgetType_Other);
	}
}
void QSttTestCntrFrameBase::OnCmd_PowerDrawView()
{
    if (m_pPowerDiagramWidget != nullptr)
	{
		SetActiveWidget(m_pPowerDiagramWidget, ActiveWidgetType_Other);
		m_pPowerDiagramWidget->cmbVolSetChanged();
		m_pPowerDiagramWidget->cmbCurSetChanged();
                m_pPowerDiagramWidget->updatePowerData();
	}	
}

void QSttTestCntrFrameBase::OnCmd_FAParasSetDialog()
{
    if (m_pSttFaParasSetDialog != nullptr)
	{
		SetActiveWidget(m_pSttFaParasSetDialog, ActiveWidgetType_Other);
	}
}

void QSttTestCntrFrameBase::TemplateView_Prepare()
{
    if ((m_pCharLibWidget == nullptr)||(m_pMacroEditView == nullptr))
	{
		return;
	}

	CString strMacroID;
	strMacroID = g_pTheSttTestApp->GetCurrTestMacroUI();

	if ((strMacroID == STT_ORG_MACRO_DiffCurr6ITest)||(strMacroID == STT_ORG_MACRO_LineDiffCurr6ITest)
		||(strMacroID == STT_ORG_MACRO_BusDiffCurr6ITest)||(strMacroID == STT_ORG_MACRO_ElecRailwayDiffTest))
	{
		CDataGroup oParas;
		oParas.AppendCloneEx(*m_pTestMacroUI_Paras);
		m_pMacroEditView->GetDatas(&oParas);
		m_pCharLibWidget->CharToGroupDatas(&oParas);
		m_pMacroEditView->SetDatas(&oParas);
	}
}

void QSttTestCntrFrameBase::CharDrawView_Prepare()
{
    if ((m_pCharLibWidget == nullptr)||(m_pMacroEditView == nullptr))
	{
		return;
	}

	CString strMacroID;
	strMacroID = g_pTheSttTestApp->GetCurrTestMacroUI();

	if ((strMacroID == STT_ORG_MACRO_DiffCurr6ITest)||(strMacroID == STT_ORG_MACRO_CurrInverseTimeTest)
		||(strMacroID == STT_ORG_MACRO_LineDiffCurr6ITest)||(strMacroID == STT_ORG_MACRO_VolInverseTimeTest)
		||(strMacroID == STT_ORG_MACRO_UFInverseTimeTest)||(strMacroID == STT_ORG_MACRO_BusDiffCurr6ITest)
		||(strMacroID == STT_ORG_MACRO_ElecRailwayDiffTest))
	{
		CDataGroup oParas;
		oParas.AppendCloneEx(*m_pTestMacroUI_Paras);
		m_pMacroEditView->GetDatas(&oParas);
		m_pCharLibWidget->GroupDatasToChar(&oParas);
	}
}

void QSttTestCntrFrameBase::OnCmd_IecCap_Prepare()
{
	if (IsTestStarted())//测试过程中,不进行同步
	{
		return;
	}

	if (!g_bSmartCap_RecordNow)//只在进入录波状态后,才进行同步处理
	{
		return;
	}

	if (!g_pTheSttTestApp->IsMuTest())//非合并单元测试不进行同步处理
	{
		return;
	}

	SetValues_dsRcdStep6U6I(FALSE);
}

void QSttTestCntrFrameBase::OnCmd_CharDrawView()
{
	if(!g_pTheSttTestApp->m_pTestMacroUI)
	{
		return;
	}

	//2022-6-30  lijunqing
	if (! g_pTheSttTestApp->m_pTestMacroUI->HasCharLib())
	{
		return;
	}

    if ((m_pActiveWidget == m_pCharLibWidget)&&(!m_pCharLibWidget->isHidden()))//zhouhj 2023.7.17  如果当前特性图已经是激活,无需再处理
	{
		return;
	}

	CharDrawView_Prepare();
	InitCharLibWidget();
	SetActiveWidget(m_pCharLibWidget, ActiveWidgetType_Other);
}

void QSttTestCntrFrameBase::OnCmd_NewTest()
{
	CLogPrint::LogString(XLOGLEVEL_TRACE, /*_T("?????????????? OnCmd_NewTest: 关闭打开的测试功能页面，并弹框提示是否保存修改 ???????????")*/g_sLangTxt_Native_CloseFeatPromptSave.GetString());
    g_pTheSttTestApp->m_pTestCtrlCntr->NewTest(nullptr, nullptr, nullptr);
	disconnect(m_pSttGbTreeView->m_pTreeCtrl,SIGNAL(itemChanged(QTreeWidgetItem *, int)),m_pSttGbTreeView->m_pTreeCtrl,SLOT(slot_TreeItemChanged(QTreeWidgetItem *, int)));
	m_pSttGbTreeView->ShowBaseList((CExBaseList *)m_pTestCtrlCntrBase->GetGuideBook());
	connect(m_pSttGbTreeView->m_pTreeCtrl,SIGNAL(itemChanged(QTreeWidgetItem *, int)),m_pSttGbTreeView->m_pTreeCtrl,SLOT(slot_TreeItemChanged(QTreeWidgetItem *, int)));
}

BOOL QSttTestCntrFrameBase::OpenTemplate(CString strFilePath, const CString &strDvmFile)
{
	if (! OpenDscXmlFile(strFilePath))
	{
		return FALSE;
	}

	CSttGuideBook *pGuideBook = (CSttGuideBook *)m_pTestCtrlCntrBase->GetGuideBook();
	pGuideBook->m_strFile = strFilePath;

	if (! AfterOpenDscXmlFile(strFilePath))
	{
		return FALSE;
	}

	m_bHasUpdateRptStartTestTime = FALSE;
	//打开报告：（待处理）打开模板的模式下，报告中应当只有_Init_的报告。
	CSttItems* pRootNode = pGuideBook->FindFirstItems(STTITEMS_NODETYPE_ROOTNODE, TRUE);
	CSttMacroTestUI_TestMacroUI *pTestMacroUI = CSttMacroTestUI_TestMacroUIDB::FindTestMacroUI(pRootNode->m_strstxmlFile);

	strFilePath = ChangeFilePostfix(strFilePath, "html");
	CString strFilePath2 = _P_GetDBPath();
	strFilePath2 += _T("ui/");
	strFilePath2 += CXLanguageMngr::g_pXLanguageMngr->m_strCurrLanguage;
	strFilePath2.AppendFormat(_T("/%s.html"), pRootNode->m_strstxmlFile.GetString());
	::X_CopyFile(strFilePath, strFilePath2);//打开的报告，一定是需要在strFilePath2路径下
	strFilePath2 = GetPathFileNameFromFilePathName(strFilePath2, '/');

    //if (m_pSttReportViewHtml != nullptr)
    //{
    //	m_pSttReportViewHtml->InitReport(strFilePath2);
    //}

	//zhouhj 2023.9.26 对应函数中实际最新已不需要打开对应数据,只是类似判断文件是否存在
// 	if (! m_pSttReportViewHtml->OpenRptFileData(pTestMacroUI->m_strReportFile, "", pTestMacroUI->m_strID))
// 	{
// 		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("Open Report File [%s] error...."), pTestMacroUI->m_strReportFile.GetString());
// 		//shaolei 2022-1-7 注释此处。打开报告失败，应当也要下发打开模板的指令
// 		//return;
// 	}

	//下发OpenTemplate指令
	strFilePath = ChangeFilePostfix(strFilePath, "gbxml");
	return m_pTestCtrlCntrBase->OpenTemplate(strFilePath, strDvmFile);
}

BOOL QSttTestCntrFrameBase::OpenDscXmlFile(CString strFilePath)
{
	//打开模板文件
	CSttGuideBook *pGuideBook = (CSttGuideBook *)m_pTestCtrlCntrBase->GetGuideBook();
	strFilePath = ChangeFilePostfix(strFilePath, "dscxml");
	pGuideBook->DeleteAll();
    pGuideBook->m_pGlobalDatas = nullptr;
	CSttCmdDefineXmlRWKeys::g_pXmlKeys->m_nIsGroupUseDvmData++;
	BOOL bRet = pGuideBook->OpenXmlFile(strFilePath, CSttCmdDefineXmlRWKeys::g_pXmlKeys);
	CSttCmdDefineXmlRWKeys::g_pXmlKeys->m_nIsGroupUseDvmData--;
	return bRet;
}

//打开dscxml后，初始化页面
BOOL QSttTestCntrFrameBase::AfterOpenDscXmlFile(CString strFilePath)
{
	//查找第一个rootnode
	CSttGuideBook *pGuideBook = (CSttGuideBook *)m_pTestCtrlCntrBase->GetGuideBook();
	CSttItems* pRootNode = pGuideBook->FindFirstItems(STTITEMS_NODETYPE_ROOTNODE, TRUE);

	//刷新树形控件显示
	disconnect(m_pSttGbTreeView->m_pTreeCtrl,SIGNAL(itemChanged(QTreeWidgetItem *, int)),m_pSttGbTreeView->m_pTreeCtrl,SLOT(slot_TreeItemChanged(QTreeWidgetItem *, int)));
	m_pSttGbTreeView->ShowBaseList(pGuideBook);
	m_pSttGbTreeView->m_pTreeCtrl->UpdateItemColour();
	connect(m_pSttGbTreeView->m_pTreeCtrl,SIGNAL(itemChanged(QTreeWidgetItem *, int)),m_pSttGbTreeView->m_pTreeCtrl,SLOT(slot_TreeItemChanged(QTreeWidgetItem *, int)));

	//zhouhj 2023.9.27 此处写法有问题,传入的应该是当前测试项的路径,不是功能ID
	//在打开测试模板或者测试记录后,在打开对应的网页报告文件前,统一将当前网页报告内容清空
// 	//打开时,删除上一次选择的测试功能的报告
// 	if (g_pTheSttTestApp->m_pTestMacroUI != nullptr)
// 	{
// 		m_pSttReportViewHtml->DeleteMacroTestReport("", g_pTheSttTestApp->m_pTestMacroUI->m_strID);
// 	}

    if (pRootNode == nullptr)
	{
		//CLogPrint::LogString(XLOGLEVEL_DEBUG, _T("模板错误！找不到rootnode节点"));
		m_pSttGbTreeView->m_strCurrSelRootNodePath = _T("");
		return FALSE;
	}

	m_pSttGbTreeView->m_pCurrSelRootNode = pRootNode;
	m_pSttGbTreeView->m_strCurrSelRootNodePath = pRootNode->GetIDPathEx(STTGBXMLCLASSID_CSTTDEVICE, FALSE);

	//打开对应的功能视图
	CSttMacroTestUI_TestMacroUI *pTestMacroUI = CSttMacroTestUI_TestMacroUIDB::FindTestMacroUI(pRootNode->m_strstxmlFile);

    if (pTestMacroUI == nullptr)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_DEBUG, /*_T("模板错误！找不到rootnode节点对应的功能界面【%s】")*/g_sLangTxt_Gradient_TemplateErr.GetString(), pRootNode->m_strstxmlFile.GetString()); //lcq
        g_pTheSttTestApp->SetCurrTestMacroUI(nullptr);
		return FALSE;
	}

	g_pTheSttTestApp->m_pTestMacroUI = pTestMacroUI;
	CSttTestMacroUiParas *pUIParas = GetTestMacroUiParas(pRootNode);

    if (m_pMacroEditView == nullptr)
	{
		CreateSttMacroParaEditView(pTestMacroUI);
	}

	CSttTestMacroCharParas *pSttTestMacroCharParas = (CSttTestMacroCharParas *)pRootNode->FindByClassID(STTGBXMLCLASSID_CSTTTESTMACROCHARPARAS);
	g_pTheSttTestApp->SetCurrTestMacroUI(pTestMacroUI);
	g_pTheSttTestApp->m_pTestCtrlCntr->stt_OpenHdRsFile(pTestMacroUI->m_strHdRsFile);
	g_theTestCntrFrame->OpenMacroTestUI(pUIParas, pTestMacroUI,pSttTestMacroCharParas);

	return TRUE;
}

BOOL QSttTestCntrFrameBase::FillRptTitle(CExBaseObject *pCurrSelGbItem)
{
    //if ((pCurrSelGbItem == nullptr)||(m_pSttReportViewHtml == nullptr))
    //{
    //	return FALSE;
    //}

// 	if (pCurrSelGbItem->GetClassID() != STTGBXMLCLASSID_CSTTITEMS)
// 	{
// 		return FALSE;
// 	}

	CSttItems* pRootNode = Stt_GetFirstParentItems(pCurrSelGbItem, GBITEMS_NODETYPE_ROOTNODE, TRUE);

    if (pRootNode == nullptr)
	{
        return FALSE;
	}

	CString strRootItemPath,strCurrItemPath;
    stt_gb_get_itempath_id(pRootNode, strRootItemPath);
	stt_gb_get_itempath_id((CSttItemBase*)pCurrSelGbItem, strCurrItemPath);
	CDataGroup oDataGroup;
	CDvmData *pData = new CDvmData;
	oDataGroup.AddNewChild(pData);
	pData->m_strName = pCurrSelGbItem->m_strName;
	pData->m_strValue = pCurrSelGbItem->m_strName;

	if (strCurrItemPath.GetLength() > strRootItemPath.GetLength())
	{
		pData->m_strID = strCurrItemPath.Mid(strRootItemPath.GetLength());
	} 
	else
	{
		pData->m_strID = _T("$");
	}

    //m_pSttReportViewHtml->FillReportTitle(strRootItemPath,&oDataGroup);
    return true;
}

BOOL QSttTestCntrFrameBase::OpenTest(CString strFilePath, const CString &strDvmFile)
{
	if (! OpenDscXmlFile(strFilePath))
	{
		return FALSE;
	}

	CSttGuideBook *pGuideBook = (CSttGuideBook *)m_pTestCtrlCntrBase->GetGuideBook();
	pGuideBook->m_strFile_Gbrpt = strFilePath;

	if (! AfterOpenDscXmlFile(strFilePath))
	{
		return FALSE;
	}

	m_bHasUpdateRptStartTestTime = FALSE;
	//打开报告
	CSttItems* pRootNode = pGuideBook->FindFirstItems(STTITEMS_NODETYPE_ROOTNODE, TRUE);
	CSttMacroTestUI_TestMacroUI *pTestMacroUI = CSttMacroTestUI_TestMacroUIDB::FindTestMacroUI(pRootNode->m_strstxmlFile);

	strFilePath = ChangeFilePostfix(strFilePath, "html");
	CString strFilePath2 = _P_GetDBPath();
	strFilePath2 += _T("ui/");
	strFilePath2 += CXLanguageMngr::g_pXLanguageMngr->m_strCurrLanguage;
	strFilePath2.AppendFormat(_T("/%s.html"), pRootNode->m_strstxmlFile.GetString());
	::X_CopyFile(strFilePath, strFilePath2);//打开的报告，一定是需要在strFilePath2路径下
	strFilePath2 = GetPathFileNameFromFilePathName(strFilePath2, '/');

    //if (m_pSttReportViewHtml != nullptr)
    //{
    //	m_pSttReportViewHtml->InitReport(strFilePath2);
    //}

	//zhouhj 2023.9.26 对应函数中实际最新已不需要打开对应数据,只是类似判断文件是否存在
// 	if (! m_pSttReportViewHtml->OpenRptFileData(pTestMacroUI->m_strReportFile, "", pTestMacroUI->m_strID))
// 	{
// 		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("Open Report File [%s] error...."), pTestMacroUI->m_strReportFile.GetString());
// 		//shaolei 2022-1-7 注释此处。打开报告失败，应当也要下发打开模板的指令
// 		//return;
// 	}

	//下发OpenTest指令
	strFilePath = ChangeFilePostfix(strFilePath, "gbrpt");
	return m_pTestCtrlCntrBase->OpenTest(strFilePath, strDvmFile);
}

void QSttTestCntrFrameBase::OnCmd_OpenTemplate()
{
	QStringList astrPostfix;
	CString strFolderPath;
	strFolderPath = _P_GetTemplatePath();
	astrPostfix<<"*.gbxml";	
	QSttPopupOpenDialog oOpenDlg(strFolderPath,astrPostfix,this);
	oOpenDlg.setFont(font());
	oOpenDlg.InitUI();

	QDesktopWidget* desktopWidget = QApplication::desktop(); 
	QRect rect = desktopWidget->screenGeometry();
	if(rect.height()<650)
	{
		oOpenDlg.resize(850,500);
		oOpenDlg.setFixedHeight(500);
	}

	if (oOpenDlg.exec() != QDialog::Accepted)
		return;

	CString strFilePath;

	if (!oOpenDlg.GetFilePath(strFilePath))
	{
		return;
	}
	
	OpenTemplate(strFilePath, _T(""));
}

void QSttTestCntrFrameBase::OnCmd_SaveTemplate()
{	
    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return;
	}

    if (m_pMacroEditView == nullptr)
	{
		return;
	}

	CDataGroup oRetParas;

	if (g_pTheSttTestApp->m_pTestMacroUI->IsUIWeb())
	{
		oRetParas.AppendCloneEx(*m_pTestMacroUI_Paras);
	}

	m_pMacroEditView->GetDatas(&oRetParas);
	SaveUIParaFile(&oRetParas);	//2022-10-16  lijunqing 记录和保存当前页面设置的值：设置为默认值

	CString strFileName, strPath;
	strFileName.Format(_T("%s.gbxml"), g_pTheSttTestApp->m_pTestMacroUI->m_strID.GetString());

	if (!Global_GetUsbRootFolderPath(strPath))
	{
		strPath = _P_GetTemplatePath();
	}

	//此处保留传递当前测试参数的形参，以便后面扩展用
	if (m_pTestCtrlCntrBase->SaveTemplate(strPath, strFileName,&oRetParas))
	{
		//CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,_T("下发保存测试模板(%s%s)命令成功."),strPath.GetString(),strFileName.GetString());
		CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,g_sLangTxt_Gradient_TestTempSusCom.GetString(),strPath.GetString(),strFileName.GetString());  //lcq
	}
	else
	{
		//CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,_T("下发保存测试模板(%s%s)命令失败."),strPath.GetString(),strFileName.GetString());
		CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,g_sLangTxt_Gradient_TestTempDefCom.GetString(),strPath.GetString(),strFileName.GetString());  //lcq
	}

	//strPath = _P_GetWorkspacePath();
	strFileName = ChangeFilePostfix(strFileName, "html");

    //if (m_pSttReportViewHtml != nullptr)
    //{
    //	m_pSttReportViewHtml->SaveHtmlReportFile(strPath + strFileName);
    //}

	//CLogPrint::LogFormatString(XLOGLEVEL_INFOR,_T("保存网页模板文件(%s%s)成功."),strPath.GetString(),strFileName.GetString());
    CLogPrint::LogFormatString(XLOGLEVEL_INFOR,g_sLangTxt_Gradient_SavePageSus.GetString(),strPath.GetString(),strFileName.GetString());//lcq

// 	if(IsTestStarted())
// 	{
// 		Ats_UpdateParameter();
// 	}

	BOOL bRet = FALSE;
	if (g_pTheSttTestApp->m_pTestMacroUI->IsUIOriginal())
	{
		bRet = ((CSttMacroParaEditViewOriginal*)m_pMacroEditView)->SaveTestMngrFile(_T(""));
	}
	else if (!g_pTheSttTestApp->m_pTestMacroUI->m_strUI_ParaFile.IsEmpty())
	{
		CDataGroup  oDataGroup;
		oDataGroup.AppendCloneEx(*m_pTestMacroUI_Paras);
        //((QSttMacroParaEditViewHtml*)m_pMacroEditView)->GetDatas(&oDataGroup);

        if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
		{
			bRet = FALSE;
		}

        //sun CString strPath = stt_ui_GetParasFile(g_pTheSttTestApp->m_pTestMacroUI->m_strUI_ParaFile);
        //sun oDataGroup.SaveXmlFile(strPath, CDataMngrXmlRWKeys::g_pXmlKeys);
	}

	if(bRet)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_INFOR,g_sLangTxt_Native_TempSaveSucc.GetString());
	}
	else
	{
		CLogPrint::LogFormatString(XLOGLEVEL_INFOR,g_sLangTxt_Native_TempSaveFail.GetString());
	}
}

void QSttTestCntrFrameBase::OnCmd_SaveAsTemplate()
{
    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return;
	}

    if (m_pMacroEditView == nullptr)
	{
		return;
	}

	CString strCfgPath = _P_GetTemplatePath();
	CString fileName;

#ifdef _PSX_QT_LINUX_
	QStringList astrPostfix;
	CString strFolderPath;
	strFolderPath = _P_GetTemplatePath();
	astrPostfix<<"*.gbxml";	
	QSttPopupSaveAsDialog dlg(strFolderPath,astrPostfix, g_pTheSttTestApp->m_pTestMacroUI->m_strID, this);
	dlg.InitUI();
	QDesktopWidget* desktopWidget = QApplication::desktop(); 
	QRect rect = desktopWidget->screenGeometry();
	if(rect.height()<650)
	{
		dlg.resize(850,500);
		dlg.setFixedHeight(500);
	}
#ifdef _USE_SoftKeyBoard_
	QSoftKeyBoard::AttachObj(&dlg,Keyboard::ENGLISH);
#endif
	if (dlg.exec() != QDialog::Accepted)
	{
#ifdef _USE_SoftKeyBoard_
		QSoftKeyBoard::ReAttachObj();
#endif
		return;
	}

#ifdef _USE_SoftKeyBoard_
	QSoftKeyBoard::ReAttachObj();
#endif
	fileName = dlg.GetFilePath();
//	fileName += dlg.m_strFileName;
#else
	CreateAllDirectories(strCfgPath);

	fileName = QFileDialog::getSaveFileName(0, /*QObject::tr("模板另存为")*/g_sLangTxt_Gradient_SaveTemplateAs,
		strCfgPath,"gbxml"); //lcq

	if (fileName.isEmpty())
	{
		return;
	}
	fileName += _T(".gbxml");
#endif
	

	CDataGroup oRetParas;

	if (g_pTheSttTestApp->m_pTestMacroUI->IsUIWeb())
	{
		oRetParas.AppendCloneEx(*m_pTestMacroUI_Paras);
	}

	m_pMacroEditView->GetDatas(&oRetParas);
	SaveUIParaFile(&oRetParas);	//2022-10-16  lijunqing 记录和保存当前页面设置的值：设置为默认值

	CString strFileName, strPath;
#ifdef _PSX_QT_LINUX_
    strPath = GetPathFromFilePathName(fileName, '/');
    strFileName = GetPathFileNameFromFilePathName(fileName, '/');
	CreateAllDirectories(strPath);
#else
	strPath = GetPathFromFilePathName(fileName);
	strFileName = GetPathFileNameFromFilePathName(fileName);
#endif
	//此处保留传递当前测试参数的形参，以便后面扩展用
	if (m_pTestCtrlCntrBase->SaveTemplate(strPath, strFileName, &oRetParas))
	{
		//CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,_T("下发保存测试模板(%s%s)命令成功."),strPath.GetString(),strFileName.GetString());
		CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,g_sLangTxt_Gradient_TestTempSusCom.GetString(),strPath.GetString(),strFileName.GetString());  //lcq
	} 
	else
	{
		//CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,_T("下发保存测试模板(%s%s)命令失败."),strPath.GetString(),strFileName.GetString());
		CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,g_sLangTxt_Gradient_TestTempDefCom.GetString(),strPath.GetString(),strFileName.GetString());  //lcq
	}

	//strPath = _P_GetWorkspacePath();
	strFileName = ChangeFilePostfix(strFileName, "html");

    //if (m_pSttReportViewHtml != nullptr)
    //{
    //	m_pSttReportViewHtml->SaveHtmlReportFile(strPath + strFileName);
    //}

	//CLogPrint::LogFormatString(XLOGLEVEL_INFOR,_T("保存网页模板文件(%s%s)成功."),strPath.GetString(),strFileName.GetString());
	CLogPrint::LogFormatString(XLOGLEVEL_INFOR,g_sLangTxt_Gradient_SavePageSus.GetString(),strPath.GetString(),strFileName.GetString());  //lcq
}

void QSttTestCntrFrameBase::OnCmd_SaveTest()
{
// 	QSttFileSaveAsDlg dlg("", "", this);
// 
// 	if (dlg.exec() != 1)
// 	{
// 		return;
// 	}
// 
// 	CString strFile = m_pTestCtrlCntrBase->SaveTestFile(dlg.m_strFolderName, dlg.m_strFileName);
// 
// 	if (strFile.GetLength() < 5)
// 	{
// 		return;
// 	}

    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return;
	}

    if (m_pMacroEditView == nullptr)
	{
		return;
	}

	CDataGroup oRetParas;

	if (g_pTheSttTestApp->m_pTestMacroUI->IsUIWeb())
	{
		oRetParas.AppendCloneEx(*m_pTestMacroUI_Paras);
	}

	m_pMacroEditView->GetDatas(&oRetParas);
	SaveUIParaFile(&oRetParas);	//2022-10-16  lijunqing 记录和保存当前页面设置的值：设置为默认值

	CString strFileName, strPath;
	strFileName.Format(_T("%s.gbrpt"), g_pTheSttTestApp->m_pTestMacroUI->m_strID.GetString());

	if (!Global_GetUsbRootFolderPath(strPath))//默认存储到U盘对应的目录下,否则存储到_P_GetWorkspacePath
	{
		strPath = _P_GetWorkspacePath();
	}
	//此处保留传递当前测试参数的形参，以便后面扩展用

	if (m_pTestCtrlCntrBase->SaveTest(strPath, strFileName, &oRetParas))
	{
		//CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,_T("下发保存测试记录(%s%s)命令成功."),strPath.GetString(),strFileName.GetString());
		CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,g_sLangTxt_Gradient_TestRecordSus.GetString(),strPath.GetString(),strFileName.GetString()); //lcq

	} 
	else
	{
		//CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,_T("下发保存测试记录(%s%s)命令失败."),strPath.GetString(),strFileName.GetString());
		CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,g_sLangTxt_Gradient_TestRecordFai.GetString(),strPath.GetString(),strFileName.GetString()); //lcq
	}

	//strPath = _P_GetWorkspacePath();
	strFileName = ChangeFilePostfix(strFileName, "html");


    //if (m_pSttReportViewHtml != nullptr)
    //{
    //	m_pSttReportViewHtml->SaveHtmlReportFile(strPath + strFileName);
    //}
	//CLogPrint::LogFormatString(XLOGLEVEL_INFOR,_T("保存报告文件(%s%s)成功."),strPath.GetString(),strFileName.GetString());
	CLogPrint::LogFormatString(XLOGLEVEL_INFOR,g_sLangTxt_Gradient_SaveReportSus.GetString(),strPath.GetString(),strFileName.GetString()); //lcq
}

void QSttTestCntrFrameBase::OnCmd_SaveAsRpt()
{
    //if (m_pSttReportViewHtml == nullptr)
    //{
    //	return;
    //}


    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return;
	}

	QStringList astrPostfix;
	CString strFolderPath;
	strFolderPath = /*_P_GetLibraryPath()*/g_oFileMngrTool.GetFolderPath_STD(STT_FILE_MNGR_Workspace);
	astrPostfix<<"*.html";	
	QSttPopupSaveAsDialog dlg(strFolderPath, astrPostfix,g_pTheSttTestApp->m_pTestMacroUI->m_strID, this);
	dlg.InitUI();
	QDesktopWidget* desktopWidget = QApplication::desktop(); 
	QRect rect = desktopWidget->screenGeometry();
	if(rect.height()<650)
	{
		dlg.resize(850,500);
		dlg.setFixedHeight(500);
	}

#ifdef _USE_SoftKeyBoard_
	QSoftKeyBoard::AttachObj(&dlg,Keyboard::ENGLISH);
	if (dlg.exec() != QDialog::Accepted)
	{
		QSoftKeyBoard::ReAttachObj();
		return;
	}
	QSoftKeyBoard::ReAttachObj();
#else
	if (dlg.exec() != QDialog::Accepted)
	{
		return;
	}
#endif
	CString strFilePath;
	strFilePath += dlg.GetFilePath();


	CString strPath;
#ifdef _PSX_QT_LINUX_
	strPath = GetPathFromFilePathName(strFilePath, '/');
#else
	strPath = GetPathFromFilePathName(strFilePath);
#endif

	CreateAllDirectories(strPath);
    //m_pSttReportViewHtml->SaveHtmlReportFile(strFilePath);
	CLogPrint::LogFormatString(XLOGLEVEL_INFOR,_T("网页报告(%s)保存成功."),strFilePath.GetString());

}

void QSttTestCntrFrameBase::OnCmd_ExportWordRpt()
{

}

void QSttTestCntrFrameBase::OnCmd_SaveAsTest()
{
    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return;
	}

    if (m_pMacroEditView == nullptr)
	{
		return;
	}

	QStringList astrPostfix;
	CString strFolderPath;
	strFolderPath = /*_P_GetLibraryPath()*/g_oFileMngrTool.GetFolderPath_STD(STT_FILE_MNGR_Workspace);
	astrPostfix<<"*.html";	
	QSttPopupSaveAsDialog dlg(strFolderPath, astrPostfix,g_pTheSttTestApp->m_pTestMacroUI->m_strID, this);
	dlg.InitUI();
	QDesktopWidget* desktopWidget = QApplication::desktop(); 
	QRect rect = desktopWidget->screenGeometry();
	if(rect.height()<650)
	{
		dlg.resize(850,500);
		dlg.setFixedHeight(500);
	}

#ifdef _USE_SoftKeyBoard_
	QSoftKeyBoard::AttachObj(&dlg,Keyboard::ENGLISH);
	if (dlg.exec() != QDialog::Accepted)
	{
		QSoftKeyBoard::ReAttachObj();
		return;
	}
	QSoftKeyBoard::ReAttachObj();
#else
	if (dlg.exec() != QDialog::Accepted)
	{
		return;
	}
#endif
	CString strFilePath;
	strFilePath += dlg.GetFilePath();;
//	strFilePath += _T("/");
// 	strFilePath += dlg.m_strFileName;
// 	strFilePath += _T(".html");

// 	CString fileName;
// 	fileName = QFileDialog::getSaveFileName(0, QObject::tr("报告另存为"),
// 		strCfgPath,"html");
// 
// 	if (fileName.isEmpty())
// 	{
// 		return;
// 	}

	CDataGroup oRetParas;

	if (g_pTheSttTestApp->m_pTestMacroUI->IsUIWeb())
	{
		oRetParas.AppendCloneEx(*m_pTestMacroUI_Paras);
	}

	m_pMacroEditView->GetDatas(&oRetParas);
	SaveUIParaFile(&oRetParas);	//2022-10-16  lijunqing 记录和保存当前页面设置的值：设置为默认值

	CString strFileName, strPath;
#ifdef _PSX_QT_LINUX_
    strPath = GetPathFromFilePathName(strFilePath, '/');
    strFileName = GetPathFileNameFromFilePathName(strFilePath, '/');
#else
	strPath = GetPathFromFilePathName(strFilePath);
	strFileName = GetPathFileNameFromFilePathName(strFilePath);
#endif

	CreateAllDirectories(strPath);
	//此处保留传递当前测试参数的形参，以便后面扩展用

	if (m_pTestCtrlCntrBase->SaveTest(strPath, strFileName, &oRetParas))
	{
		//CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,_T("下发保存测试记录(%s%s)命令成功."),strPath.GetString(),strFileName.GetString());
		CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,g_sLangTxt_Gradient_TestRecordSus.GetString(),strPath.GetString(),strFileName.GetString()); //lcq
	} 
	else
	{
		//CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,_T("下发保存测试记录(%s%s)命令失败."),strPath.GetString(),strFileName.GetString());
        CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,g_sLangTxt_Gradient_TestRecordFai.GetString(),strPath.GetString(),strFileName.GetString()); //lcq
	}

	//strPath = _P_GetWorkspacePath();
	strFileName = ChangeFilePostfix(strFileName, "html");

    //sun if (m_pSttReportViewHtml != nullptr)
    //sun {
    //sun 	m_pSttReportViewHtml->SaveHtmlReportFile(strPath + strFileName);
    //sun }

	//CLogPrint::LogFormatString(XLOGLEVEL_INFOR,_T("保存报告文件(%s%s)成功."),strPath.GetString(),strFileName.GetString());
    CLogPrint::LogFormatString(XLOGLEVEL_INFOR,g_sLangTxt_Gradient_SaveReportSus.GetString(),strPath.GetString(),strFileName.GetString());  //lcq
}

void QSttTestCntrFrameBase::OnCmd_OpenTest()
{

}

void QSttTestCntrFrameBase::OnCmd_SelSCLFile()
{

}

void QSttTestCntrFrameBase::OnCmd_SaveEdit()
{

}

void QSttTestCntrFrameBase::OnCmd_PpIotEngineClient()
{

}

void QSttTestCntrFrameBase::OnCmd_PpIotEngineClientDlg()
{
// 	CString strDevMode;
// 	strDevMode = g_oSttSystemConfig.GetDevModel();
// 	g_pTheSttTestApp->IinitGbWzdAiTool();
// 
// 	if (m_pEngineClientWidget == nullptr)
// 	{
// 		CreateEngineClientWidget();
// 	}
// 
// 	QSttCommCfgDeviceDlg oSttComDlg(m_pEngineClientWidget,this);
// 	//oSttComDlg.setParent(this);
// 	//=====================
// #ifdef _USE_SoftKeyBoard_	
// 	QSoftKeyBoard::AttachObj(&oSttComDlg, Keyboard::NUMBER);
// #endif
// 	oSttComDlg.exec();
// #ifdef _USE_SoftKeyBoard_
// 	QSoftKeyBoard::ReAttachObj();
// #endif

// 	if (strDevMode == "PNS331")
// 	{
// 		
// 	}
// 	else
// 	{
// 		QPpSttIotEngineClientWidgetMain oMainWidget(this);
// 		oMainWidget.UpdateTitleAndSize(CString("装置通讯"),800, 630);
// #ifdef _USE_SoftKeyBoard_	
// 		QSoftKeyBoard::AttachObj(&oMainWidget, Keyboard::NUMBER);
// #endif
// 		//m_pEngineClientWidget = pMainWidget;
// 		//pMainWidget->setParent(this);
// 		//pMainWidget->hide();
// 		//pMainWidget->setGeometry(m_rcWorkArea);
// 
// 		if (g_pTheSttTestApp->m_pDvmDevice != nullptr)
// 		{
// 			oMainWidget.ShowDvmDevice( g_pTheSttTestApp->m_pDvmDevice );
// 			oMainWidget.NewPpSttIotDeviceClient(&g_pTheSttTestApp->m_oCommConfig, g_pTheSttTestApp->m_pDvmDevice);
// 		}	
// 
// 		oMainWidget.exec();
// 
// #ifdef _USE_SoftKeyBoard_
// 		QSoftKeyBoard::ReAttachObj();
// #endif
// 	}
}

void QSttTestCntrFrameBase::OnCmd_CommConfiguration()
{
//sun 	QSttCommCfgMainDlg oSttCommCfgMainDlg(this);
//sun 	//oSttCommCfgMainDlg.exec();
//sun #ifdef _USE_SoftKeyBoard_
//sun 	QSoftKeyBoard::AttachObj(&oSttCommCfgMainDlg, Keyboard::NUMBER);
//sun #endif
//sun 	oSttCommCfgMainDlg.exec();
//sun #ifdef _USE_SoftKeyBoard_
//sun 	QSoftKeyBoard::ReAttachObj();
//sun #endif
	UpdateDeviceModelRef();
}
void QSttTestCntrFrameBase::OnCmd_PkgMonitor()
{
// 	QSttCommCfgPkgMonitorDlg oSttCommCfgPkgMnDlg;
// 	oSttCommCfgPkgMnDlg.exec();
	CreateCommCfgPkgMnWidget();
    //sun SetActiveWidget(m_pSttCommCfgPkgWidget, ActiveWidgetType_Other);
}

void QSttTestCntrFrameBase::OnCmd_PpXmlFileMngr()
{
    //sun QSttCommCfgProtocolTemplateDlg oComCfgProTempDlg;
    //sun oComCfgProTempDlg.exec();

}
void QSttTestCntrFrameBase::OnCmd_DvmFileMngr()
{
//sun 	QSttCommCfgPointTblFileImportDlg oComCfgPntImpDlg(this);
//sun 	//oComCfgPntImpDlg.exec();
//sun
//sun #ifdef _USE_SoftKeyBoard_
//sun 	QSoftKeyBoard::AttachObj(&oComCfgPntImpDlg, Keyboard::NUMBER);
//sun #endif
//sun 	oComCfgPntImpDlg.exec();
//sun #ifdef _USE_SoftKeyBoard_
//sun 	QSoftKeyBoard::ReAttachObj();
//sun #endif
}
//////////////////////////////////////////////////

void QSttTestCntrFrameBase::OnCmd_NetworkConfig()
{

}

//2023/8/29 wjs 遥测试验
void QSttTestCntrFrameBase::OnCmd_AinDataMapConfig()
{
// 	QAinDataMapDlg oAinDataMapDlg(this);
// 	oAinDataMapDlg.setWindowTitle("摇杆映射");
// 	oAinDataMapDlg.exec();
}


// void QSttTestCntrFrameBase::OnCmd_SystemParas()
// {
// 	QSysParasDlg oSysParasDlg(this);
// 	oSysParasDlg.initUI();
// 	oSysParasDlg.setWindowModality(Qt::WindowModal);//模态窗口
// 
// //#ifdef _PSX_QT_LINUX_
// #ifdef _USE_SoftKeyBoard_
// 	QSoftKeyBoard::AttachObj(&oSysParasDlg,Keyboard::NUMBER);
// 	oSysParasDlg.exec();
// 	QSoftKeyBoard::ReAttachObj();
// #endif
// }

void QSttTestCntrFrameBase::OnCmd_ClearReportRslts()
{

}

void QSttTestCntrFrameBase::OnCmd_ImportDvmFile()
{

}

void QSttTestCntrFrameBase::OnCmd_SystemParas()
{
	if (g_oSttSystemConfig.GetSelSysPata())
	{
		m_oOldSysParasList.DeleteAll();
		m_oOldSysParasList.AddNewData(STT_XML_SERIALIZE_SYS_PARA_ID_OldVNom,g_oSystemParas.m_fVNom/SQRT3);
		m_oOldSysParasList.AddNewData(STT_XML_SERIALIZE_SYS_PARA_ID_OldINom,g_oSystemParas.m_fINom);
		m_oOldSysParasList.AddNewData(STT_XML_SERIALIZE_SYS_PARA_ID_OldFNom,g_oSystemParas.m_fFNom);
	}

//#ifdef _PSX_QT_LINUX_
    //OpenMenuHtmlFile(STT_MACROPARA_HTML_NAME_SYSCONFIG);
    //m_pSysParaEditView->m_nSysConfig_Mode = STT_HTML_SYSCONFIG_MODE_UPDATE;
#ifdef _USE_SoftKeyBoard_
	QSoftKeyBoard::AttachObj(this);
#endif
// #else
// 	QSysParasDlg oSysParasDlg;
// 	oSysParasDlg.initUI();
// #ifdef _USE_SoftKeyBoard_
// 	QSoftKeyBoard::AttachObj(&oSysParasDlg,Keyboard::NUMBER);
// 	oSysParasDlg.exec();
// 	QSoftKeyBoard::ReAttachObj();
// #else
// 	oSysParasDlg.exec();
// #endif
// #endif
}

void QSttTestCntrFrameBase::OnCmd_GeneralParas()
{

}

void QSttTestCntrFrameBase::OnCmd_DcSet()
{	
}

void QSttTestCntrFrameBase::OnCmd_OutputPower()
{
	QModuleSetDlg oModuleSetDlg(this);
	oModuleSetDlg.setFont(*g_pSttGlobalFont);
	oModuleSetDlg.initUI();

	m_bUpdateOutputPowerFromRealTime = false;

// 	if(m_bFirstUpadeIPowerMode)
// 	{
// 		if (g_oSystemParas.m_oGearSetCurModules.m_oCurModuleGear[0].m_nIPowerMode != STT_CurrentMODULE_POWER_LOW)
// 		{
// 			g_oSystemParas.m_oGearSetCurModules.m_oCurModuleGear[0].m_nIPowerMode = STT_CurrentMODULE_POWER_LOW;//20240415 suyang 北京要求 初始化时电流为1档
// 		}
// 		m_bFirstUpadeIPowerMode = false;
// 
// 	}
// 	oModuleSetDlg.InitDatas(&g_oSystemParas);
	connect(&oModuleSetDlg, SIGNAL(sig_UpdateModulesGear(BOOL)), this, SLOT(slot_UpdateModulesGear(BOOL)));
#ifdef _USE_SoftKeyBoard_
	QSoftKeyBoard::AttachObj(&oModuleSetDlg);
	oModuleSetDlg.exec();
	QSoftKeyBoard::ReAttachObj();
#else
	oModuleSetDlg.exec();
#endif
	disconnect(&oModuleSetDlg, SIGNAL(sig_UpdateModulesGear(BOOL)), this, SLOT(slot_UpdateModulesGear(BOOL)));

	m_bUpdateOutputPowerFromRealTime = true;

//	OpenMenuHtmlFile(STT_MACROPARA_HTML_NAME_POWERGEAR);
}

void QSttTestCntrFrameBase::slot_UpdateModulesGear(BOOL bMergeCurrHasChanged)
{
	if (bMergeCurrHasChanged)
	{
		OnUpdateTestResource(FALSE);

		if (g_oSystemParas.m_nHasAnalog)//zhouhj 2024.2.26 在有模拟量输出,并且bMergeCurrHasChanged==1,则通道映射已经更新
		{
			Cmd_SendChMapsConfig();
		}
	}

	//zhouhj 2024.5.23 增加用于档位切换
	CDataGroup oPowerGear;
	CSttDataGroupSerializeRegister oRegister(&oPowerGear);
	stt_xml_serialize_ModulesGearSwitch(&g_oSystemParas, &oRegister);
	m_pTestCtrlCntrBase->Ats_SetParameter(STT_MACRO_ID_ModulesGearSwitch,&oPowerGear);
//	Cmd_SendSystemConfig();
}

void QSttTestCntrFrameBase::slot_FillReportImg(QString strItemPath)
{
    //if (m_pSttReportViewHtml == nullptr)
    //{
    //	return;
    //}

	CString strImgBase64,strTmp;
	strTmp = strItemPath;
    m_pSttCharacterDrawPng->GetSearchingPng(nullptr, strImgBase64);
    //m_pSttReportViewHtml->FillReportImg("", strTmp, strImgBase64);//zhouhj 20230213 用于插入差动图片
#ifndef _PSX_QT_LINUX_ //在window下,测试结果后自动生成对应的图片
	CString strPngFilePath;
	strPngFilePath = _P_GetWorkspacePath();
	strPngFilePath += _T("Img/");
	CreateAllDirectories(strPngFilePath);
	strPngFilePath += strTmp;
	strPngFilePath += _T(".png");

	m_pSttCharacterDrawPng->SavePngFile(strPngFilePath);
#endif
}

void QSttTestCntrFrameBase::slot_MsgBox(QString strTitle,QString strMsg)
{
	BOOL bShowMUTestIecCbSelWidget = FALSE;

    if (g_pSttMUTestIecCbSelWidget != nullptr)
	{
		//合并单元相关测试时,防止控制块选择界面挡住对应弹窗
		if (!g_pSttMUTestIecCbSelWidget->isHidden())
		{
			g_pSttMUTestIecCbSelWidget->hide();
			CTickCount32 oTickCount;
			oTickCount.DoEvents(20);
			bShowMUTestIecCbSelWidget = TRUE;
		}
	}

	CXMessageBox::information(this, strTitle, strMsg);

	if (bShowMUTestIecCbSelWidget)
	{
		g_pSttMUTestIecCbSelWidget->show();
	}
}

//zhouhj 2023.12.6 从window派生类移入
void QSttTestCntrFrameBase::slot_OnConfigDevice(CDataGroup *pCommCfg)
{
    if (g_pTheSttTestApp->m_pTestCtrlCntr != nullptr)
	{
		g_pTheSttTestApp->m_pTestCtrlCntr->Ats_ConfigDevice(pCommCfg);
	}
}

void QSttTestCntrFrameBase::OnCmd_DeviceCom()
{
    //OpenMenuHtmlFile(STT_MACROPARA_HTML_NAME_DEVCOMM);
}

void QSttTestCntrFrameBase::OnCmd_LangSettingView()
{
	QSttLanguageCfgDialog dlg(this);
	dlg.exec();
}

void QSttTestCntrFrameBase::OnCmd_ReportSetting()
{
	QSttReportHeadSetDlg dlg(&m_pTestCtrlCntrBase->m_oTestReportHead, this);
#ifdef _USE_SoftKeyBoard_	
	QSoftKeyBoard::AttachObj(&dlg, Keyboard::ENGLISH);
#endif
	dlg.exec();

	if (dlg.m_nOkFlag == 1)
	{
		
// 		m_pTestCtrlCntrBase->FillReport(&m_pTestCtrlCntrBase->m_oTestReportHead);//刷新报告头

		if (!dlg.m_bUpataHeadHtml)//只有选中的时候才会插入
		{
			InsertReportHead(&m_pTestCtrlCntrBase->m_oTestReportHead);
		}

		UpdateReportHead(&m_pTestCtrlCntrBase->m_oTestReportHead);
		m_pTestCtrlCntrBase->SaveReportHead();
	}
#ifdef _USE_SoftKeyBoard_
	QSoftKeyBoard::ReAttachObj();
#endif
}

void QSttTestCntrFrameBase::InsertReportHead( CDataGroup *pSttReport )
{
    if (pSttReport == nullptr)
	{
		return;
	}

	POS pos = pSttReport->GetHeadPosition();
    CDataGroup *p = nullptr;
	CString strItemID;

	// 20240510 suyang 重新勾选后需要将全部删除，再进行填充
    while (pos != nullptr)
	{
		p = (CDataGroup*)pSttReport->GetNext(pos);

		strItemID = pSttReport->m_strID + "$" + p->m_strID;
        //m_pSttReportViewHtml->DeleteRptHtml("", strItemID);
	}
	

    //m_pSttReportViewHtml->AddInsertHeadCmd(pSttReport->m_strID,"");
	
}



void QSttTestCntrFrameBase::OnCmd_ChRsMaps()
{
	QChMapsDlg oChMapsDlg(this);
	oChMapsDlg.setFont(m_gFont);
	oChMapsDlg.initUI();
//	connect(&oChMapsDlg, SIGNAL(sig_UpdateChRsMaps(BOOL)), this, SLOT(slot_UpdateChRsMaps(BOOL)));
#ifdef _USE_SoftKeyBoard_
	QSoftKeyBoard::AttachObj(&oChMapsDlg, Keyboard::NUMBER);
	if (oChMapsDlg.exec() == QDialog::Accepted)
	{
		slot_UpdateChRsMaps(oChMapsDlg.m_bSysParasHasChanged);
	}
	QSoftKeyBoard::ReAttachObj();
#else
	if (oChMapsDlg.exec() == QDialog::Accepted)
	{
		slot_UpdateChRsMaps(oChMapsDlg.m_bSysParasHasChanged);
#ifdef _USE_SoftKeyBoard_//zhouhj 2023.8.28 系统参数修改后,更新键盘
		g_oSttTestResourceMngr.UpdateSoftKeyboardType();
#endif
	}
#endif

//	disconnect(&oChMapsDlg, SIGNAL(sig_UpdateChRsMaps(BOOL)), this, SLOT(slot_UpdateChRsMaps(BOOL)));
}

void QSttTestCntrFrameBase::OnCmd_ItemListView()
{

}

void QSttTestCntrFrameBase::OnCmd_DeviceComView()
{

}

void QSttTestCntrFrameBase::OnCmd_SequenceView()
{

}

void QSttTestCntrFrameBase::OnCmd_InfoView()
{
    if(m_pInfoWidget != nullptr)
	{
		SetActiveWidget(m_pInfoWidget, ActiveWidgetType_Other);
	}
}

void QSttTestCntrFrameBase::OnCmd_LogView()
{

}

void QSttTestCntrFrameBase::OpenMenuHtmlFile(const CString &strMemuFileName)
{
	if (IsHtmlParasEditOpen())
	{
		return;
	}

    //m_pSysParaEditView = new QSttMacroParaEditViewHtml();
    //m_pSysParaEditView->setParent(this);
    //m_pSysParaEditView->setGeometry(m_rcWorkArea);
    //m_pSysParaEditView->OpenHtmlFile(strMemuFileName);//
    //SetActiveWidget(m_pSysParaEditView, ActiveWidgetType_Paras_Html);
}

void QSttTestCntrFrameBase::OnCmd_VersionInfo()
{
	//OpenMenuHtmlFile(STT_MACROPARA_HTML_NAME_VERSIONINFOR);
	QDeviceInforDlg oDevInforDlg(this);
	oDevInforDlg.setFont(*g_pSttGlobalFont);
	oDevInforDlg.initUI(FALSE);
	QDesktopWidget* desktopWidget = QApplication::desktop(); 
	QRect rect = desktopWidget->screenGeometry();
	if(rect.height()<650)
	{
		oDevInforDlg.resize(850,500);
		oDevInforDlg.setFixedHeight(500);
	}

	connect(this, SIGNAL(sig_UpdateTestResource()), &oDevInforDlg, SLOT(slot_UpdateTestResource()));

#ifdef _USE_SoftKeyBoard_
	QSoftKeyBoard::AttachObj(&oDevInforDlg, Keyboard::NUMBER);
	oDevInforDlg.exec();
	QSoftKeyBoard::ReAttachObj();
#else
	oDevInforDlg.exec();
#endif

	disconnect(this, SIGNAL(sig_UpdateTestResource()), &oDevInforDlg, SLOT(slot_UpdateTestResource()));
}

void QSttTestCntrFrameBase::OnCmd_AuxIPSet()
{
}

void QSttTestCntrFrameBase::OnCmd_Liveupdate()
{
}

void QSttTestCntrFrameBase::OnCmd_ULiveupdate()
{

}

void QSttTestCntrFrameBase::OnCmd_LiveupdateDevice()
{

}

void QSttTestCntrFrameBase::OnCmd_CloudConfig()
{

}

void QSttTestCntrFrameBase::OnCmd_UpdateAdjCoef()
{

}

void QSttTestCntrFrameBase::OnCmd_RegisterRemoteTest()
{

}

void QSttTestCntrFrameBase::OnCmd_RemoteRegistAssist()
{

}

void QSttTestCntrFrameBase::OnCmd_DownloadTestTemplate()
{

}

void QSttTestCntrFrameBase::OnCmd_DownloadPpTemplate()
{

}

void QSttTestCntrFrameBase::OnCmd_UploadingReport()
{

}

void QSttTestCntrFrameBase::slot_OnUpdateRtSyncTime(CDataGroup *pRtSycTime)
//long nSyn, long nSecond,long nNSecend,long n4G, long nWifi, long nBle,
//												 long nPowerAC, long nBatCap,long nUSB )
{
	//0,0,0,-1,-1,-1,-1,-1,-1
	long nSyn = 0, nSecond = 0, nNSecend = 0,nTimeZone = 0, n4G = -1,  nWifi = -1,  nBle = -1;
	long nPowerAC = -1,  nBatCap = -1, nUSB = -1 ;

	// 			long nSecond = 0,nNSecend = 0,nSyn = 0;
	// 			stt_GetDataValueByID(pRtDataGroup, _T("Sync"), nSyn);
	// 			stt_GetDataValueByID(pRtDataGroup, _T("Utc_s"), nSecond);
	// 			stt_GetDataValueByID(pRtDataGroup, _T("Utc_ns"), nNSecend);
	// 
	// 			long n4G = 0,nWifi = 0,nBle = 0,nPowerAC = 0,nBatCap = 0, nUSB = 0;
	// 			stt_GetDataValueByID(pRtDataGroup, _T("4G"), n4G);
	// 			stt_GetDataValueByID(pRtDataGroup, _T("Wifi"), nWifi);
	// 			stt_GetDataValueByID(pRtDataGroup, _T("Ble"), nBle);
	// 			stt_GetDataValueByID(pRtDataGroup, _T("PowerAC"), nPowerAC);
	// 			stt_GetDataValueByID(pRtDataGroup, _T("BatCap"), nBatCap);
	// 			stt_GetDataValueByID(pRtDataGroup, _T("USB"), nUSB);


	//通过GPS所得的精确时间来同步软件资源内的计时器,尤其是画图计时器
	if(IsTestStarted() && m_pStateMonitorWidget)
	{
		stt_GetDataValueByID(pRtSycTime, _T("Utc_s"), nSecond);
		stt_GetDataValueByID(pRtSycTime, _T("Utc_ns"), nNSecend);
		stt_GetDataValueByID(pRtSycTime, _T("TimeZone"), nTimeZone);//zhouhj 20230613 补偿时区差

		double dLocalTime = nSecond + nTimeZone*60*60 + nNSecend * 0.000000001;
		m_pStateMonitorWidget->UpdateLocalTime(dLocalTime);
	}

    if ((m_pMacroEditView != nullptr)&&(CXSmartCapMngr::GetSttCap61850_Global() != nullptr))
	{
		CXSttCap_61850 *pXSttCap_61850 = CXSmartCapMngr::GetSttCap61850_Global();
		pXSttCap_61850->UpdateMUTimeRlt(pRtSycTime);

// 		if ((g_pTheSttTestApp->GetCurrUI_ID() == STT_ORG_MACRO_ManualTest)&&
// 			pXSttCap_61850->UpdateMUTimeRlt(pRtSycTime))
// 		{
// 			QSttMacroParaEditViewManual *pManualUI = (QSttMacroParaEditViewManual*)m_pMacroEditView;
// //			pManualUI->UpdateMUTimeAccurRlt_PPS();
// //			pManualUI->UpdateMUTimeAccurRlt_PPS(pXSttCap_61850->m_pDataset_MUTimeRlt);
// 		}
 	}

	//2022-6-10  lijunqing 整体更新对象，不处理个性化时间
	m_oDataBtnsMngr.UpdataDataButtons(pRtSycTime);

	//由于电源信息是一个group,需要特殊处理
	m_oDataBtnsMngr.UpdataDataButtons(pRtSycTime, "BatCap");

	//由于GPS是一个group,需要特殊处理
	m_oDataBtnsMngr.UpdataDataButtons(pRtSycTime, "GPS");
//	CLogPrint::LogFormatString(XLOGLEVEL_RESULT,_T("GPS"));

	//2022-6-10 yizejun 需要删除copy出来的rtsyctime

	//20230614 zhouhj 用于北京界面截图
// 	if (g_oLocalSysPara.m_nHasSyn)
// 	{
// 		OnCmd_ScreenShot();
// 	}

	//chenling 20230412	
	POS pos=pRtSycTime->GetHeadPosition();
    CDataGroup *pFiberMsgGroup=nullptr;
    CExBaseObject *pCurrObj = nullptr;
	g_oSttTestResourceMngr.m_oFiberMsgGroup.DeleteAll();

	while (pos)
	{
		pCurrObj = pRtSycTime->GetNext(pos);

		if (pCurrObj->GetClassID() != DTMCLASSID_CDATAGROUP)
		{
			continue;
		}

		pFiberMsgGroup = (CDataGroup *)pCurrObj;
		if (pFiberMsgGroup->m_strDataType=="LightPower")
		{		
			pRtSycTime->Remove(pCurrObj);
			POS pos2 = pFiberMsgGroup->GetHeadPosition();
            CExBaseObject * pData = nullptr;

			while(pos2)
			{
				pData = (CExBaseObject *)pFiberMsgGroup->GetNext(pos2);	
				g_oSttTestResourceMngr.m_oFiberMsgGroup.AddNewChild(pData);
			}
			
		}
	}

	if(m_bUpdateOutputPowerFromRealTime)//更新输出功率
	{
	OnUpdateRtCurrModules(pRtSycTime);
	}
	if(m_bUpdateHardCfgFromRealTime)//更新硬件设置
	{
		OnUpdateRtHardConfig(pRtSycTime);
	}

	g_oLocalSysPara.m_nRTData_Num++;
	OnUpdateRtInputDev(pRtSycTime);
	delete pRtSycTime;

	//各功能的更新参见如下
	/*
	QSttGpsButton::UpdateState(CDataGroup *pDataGroup)
	QSttBatteryButton::UpdateState(CDataGroup *pDataGroup)
	QSttBlueToothButton::UpdateState(CDataGroup *pDataGroup) //因为上送的数据和配置文件不一致，必须重载单独处理
	*/

/*
	QSttToolButtonBase* pButton = m_oDataBtnsMngr.FindButtonByID("GPS");

    if (pButton == nullptr)
	{
		return;
	}

	CString strGpsTime;

	if (nSyn != g_oLocalSysPara.m_nHasSyn)
	{
		g_oLocalSysPara.m_nHasSyn = nSyn;

		if (g_oLocalSysPara.m_nHasSyn == 0)
		{
			strGpsTime = tr("未对时");
		} 
		else
		{
			strGpsTime = QDateTime::fromTime_t(nSecond).toString("yyyy-MM-dd hh:mm:ss")/ *+QString("%1").arg((int)(nNSecend/1000000))* /;
		}
	}
	else if (nSyn > 0 )
	{
		strGpsTime = QDateTime::fromTime_t(nSecond).toString("yyyy-MM-dd hh:mm:ss")/ *+QString("%1").arg((int)(nNSecend/1000000))* /;
	}
	
	if (strGpsTime != _T(""))
	{
		pButton->setText(strGpsTime);
	}

	pButton = m_oDataBtnsMngr.FindButtonByID("4G");
	pButton->SetPic(n4G);

	pButton = m_oDataBtnsMngr.FindButtonByID("Wifi");
	pButton->SetPic(nWifi);

	pButton = m_oDataBtnsMngr.FindButtonByID("BlueTooth");
	pButton->SetPic(nBle);

	pButton = m_oDataBtnsMngr.FindButtonByID("USB");
	pButton->SetPic(nUSB);

	pButton = m_oDataBtnsMngr.FindButtonByID("Battery");
	if(nPowerAC > 0)
	{
		QSttBatteryButton* pBtn = (QSttBatteryButton*)pButton;
		if(pBtn->m_nCurPic == 4)
		{
			pBtn->SetPic(0);
		}
		else
		{
			pBtn->m_nCurPic++;
			pBtn->SetPic(pBtn->m_nCurPic);
		}
	}
	else
	{
		if (nBatCap > 70)
		{
			pButton->SetPic(4);
		}
		else if (nBatCap > 50 && nBatCap <= 70)
		{
			pButton->SetPic(3);
		}
		else if (nBatCap > 30 && nBatCap <= 50)
		{
			pButton->SetPic(2);
		}
		else if (nBatCap > 10 && nBatCap <= 20)
		{
			pButton->SetPic(1);
		}
		else if (nBatCap > 0 && nBatCap <= 5)
		{
			pButton->SetPic(0);
		}
	}
*/

}

void QSttTestCntrFrameBase::OnUpdateRtCurrModules(CDataGroup *pRtSycTime)	//20240530 xueyangfan 获取实时数据更新当前档位状态
{
    if (pRtSycTime == nullptr)
	{
		return;
	}

	long nValue = 0;								
	CExBaseObject* pFindObj = pRtSycTime->FindByID("CurrModules");

    if (pFindObj == nullptr)
	{
		return;
	}

	if (pFindObj->GetClassID() != DTMCLASSID_CDATAGROUP)
	{
		return;
	}

	CDataGroup *pCurrModules = (CDataGroup*)pFindObj;
	pFindObj = pCurrModules->FindByID("CurrModuleNum");

    if (pFindObj == nullptr)
	{
		return;
	}

	if (pFindObj->GetClassID() != DVMCLASSID_CDVMDATA)
	{
		return;
	}

	CDvmData *pDvmData = (CDvmData*)pFindObj;
	long nNumValue = CString_To_long(pDvmData->m_strValue);
	CString strModuleID;
    CExBaseList *pFindList = nullptr;

	for (int nIndex = 0; nIndex < nNumValue; nIndex++) 
	{
		strModuleID.Format("CurrModule%d",nIndex);

		pFindList = (CExBaseList*)pCurrModules->FindByID(strModuleID);

        if (pFindList == nullptr)
		{
			continue;
		}

		CDvmData *pCurModuleAttr = (CDvmData *)pFindList->FindByID("ModulePos");

        if (pCurModuleAttr != nullptr)
		{
			g_oSystemParas.m_oGearSetCurModules.m_oCurModuleGear[nIndex].m_nModulePos = CString_To_long(pCurModuleAttr->m_strValue);
		}

		pCurModuleAttr = (CDvmData *)pFindList->FindByID("CurModuleGear");

        if (pCurModuleAttr != nullptr)
		{
			g_oSystemParas.m_oGearSetCurModules.m_oCurModuleGear[nIndex].m_nIPowerMode = CString_To_long(pCurModuleAttr->m_strValue);
		}

		pCurModuleAttr = (CDvmData *)pFindList->FindByID("MaxPortVol");

        if (pCurModuleAttr != nullptr)
		{
			g_oSystemParas.m_oGearSetCurModules.m_oCurModuleGear[nIndex].m_fVoltSet = CString_To_double(pCurModuleAttr->m_strValue);
		}

		pCurModuleAttr = (CDvmData *)pFindList->FindByID("MergeCurTerminal");

        if (pCurModuleAttr != nullptr)
		{
			g_oSystemParas.m_oGearSetCurModules.m_oCurModuleGear[nIndex].m_nMergeCurTerminal = CString_To_double(pCurModuleAttr->m_strValue);
		}

		pCurModuleAttr = (CDvmData *)pFindList->FindByID("LargeCurOutTerm");

        if (pCurModuleAttr != nullptr)
		{
			g_oSystemParas.m_oGearSetCurModules.m_oCurModuleGear[nIndex].m_nLargeCurOutTerm = CString_To_double(pCurModuleAttr->m_strValue);
		}
	}
}

void QSttTestCntrFrameBase::OnUpdateRtInputDev(CDataGroup *pRtSycTime)		//20240530 xueyangfan 获取实时数据更新鼠标键盘命令
{
    if (pRtSycTime ==nullptr)
	{
		return;
	}

#ifdef _PSX_QT_LINUX_
	CExBaseObject *pFindObj = pRtSycTime->FindByID("InputDev");

    if (pFindObj == nullptr)
	{
		return;
	}

	if (pFindObj->GetClassID() != DTMCLASSID_CDATAGROUP)
	{
		return;
	}

	CDataGroup *pCurrMouseKeyBoard = (CDataGroup*)pFindObj;

	CDvmData *pVerIdxData = (CDvmData*)pCurrMouseKeyBoard->FindByID("VerIdx");
	CDvmData *pMouseData = (CDvmData*)pCurrMouseKeyBoard->FindByID("Mouse");
	CDvmData *pKeybData = (CDvmData*)pCurrMouseKeyBoard->FindByID("QWS_KEYBOARD");

    if (pVerIdxData != nullptr)
	{
		long nValue = CString_To_long(pVerIdxData->m_strValue);

		if (g_oLocalSysPara.m_nTesterVerIdx != nValue)
		{
			g_oLocalSysPara.m_nTesterVerIdx = nValue;

            if (pMouseData != nullptr)
			{
                nValue = CString_To_long(pMouseData->m_strValue);
                qputenv("Mouse", pMouseData->m_strValue.GetString());

				// 				if (g_oLocalSysPara.m_nTesterHasMouse != nValue)
				// 				{
				// 					g_oLocalSysPara.m_nTesterHasMouse = nValue;
				// 				}
                if(nValue == 0)
				{
                    QApplication::setOverrideCursor(Qt::BlankCursor);
				}
                if(nValue == 1)
				{
                    QApplication::setOverrideCursor(Qt::ArrowCursor);
                }
	
            if (pKeybData != nullptr)
			{
				qputenv("QWS_KEYBOARD", pKeybData->m_strValue.GetString());

				// 				if (g_oLocalSysPara.m_strTesterKeyBoardString != pKeybData->m_strValue)
				// 				{
				// 					g_oLocalSysPara.m_strTesterKeyBoardString = pKeybData->m_strValue;
				// 				}
			}
        }
	}
}
#endif
}

void QSttTestCntrFrameBase::slot_UpdateAuxDCOutput()
{
    if (m_pTestCtrlCntrBase == nullptr)
	{
		return;
	}

	CDataGroup oGroup;
	CSttDataGroupSerializeRegister oRegister(&oGroup);
	stt_xml_serialize_AuxDC(&g_oSystemParas, &oRegister);
	m_pTestCtrlCntrBase->Ats_SetParameter(STT_MACRO_ID_AuxDCOutput,&oGroup);

// 	emit sig_UpdateAuxDCEdit();//20240603 suyang L336D更新界面辅助直流编辑框
	((CSttMacroParaEditViewOriginal*)m_pMacroEditView)->UpdateAuxDCEdit();

//	Ats_SetItemPara(STT_CMD_TYPE_SYSTEM_SystemConfig);
}

void QSttTestCntrFrameBase::slot_UpdateChRsMaps( BOOL bSysParasHasChanged )
{
	if (g_pTheSttTestApp->m_pTestMacroUI->IsUIOriginal())
	{
		CSttMacroParaEditViewOriginal* pOri = (CSttMacroParaEditViewOriginal*)m_pMacroEditView;
		pOri->m_bChMapsChanged = TRUE;
		OnUpdateTestResource(FALSE);

// 		if (bSysParasHasChanged)//2023.7.4 zhouhj 后面已经下发系统参数更新命令,此处无需再标记
// 		{
// 			pOri->m_bSystemParasChanged = TRUE;
// //			pOri->m_bIECParasChanged = TRUE;
// 		}
	}

	if (bSysParasHasChanged)
	{
		Cmd_SendSystemConfig();
	}

	Cmd_SendChMapsConfig();
}


void QSttTestCntrFrameBase::slot_ReturnPrevActiveWidget()
{
	m_oTimerHtmlViewReturn.stop();
	
    m_pActiveWidget = nullptr;
    //m_pSysParaEditView->hide();
    //m_pSysParaEditView->stop();
    //m_pSysParaEditView->close();
    //m_pSysParaEditView->deleteLater();
    //m_pSysParaEditView = nullptr;

	if (m_nPrevActiveWidgetType == ActiveWidgetType_None)
	{
        SetActiveWidget(nullptr, ActiveWidgetType_None);
	}
	else
	{
		SetActiveWidget(m_pPrevActiveWidget, m_nPrevActiveWidgetType);
	}
}

void QSttTestCntrFrameBase::slot_IecCfgDataMngrUpdate()
{
	if (g_pSttIecRecordCbWidget)
	{
		g_pSttIecRecordCbWidget->m_bStopTimerUpdate = TRUE;
	}

	g_oSttTestResourceMngr.SaveDefaultIec61850Config();//保存xml

    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		Ats_SetItemPara(STT_CMD_TYPE_SYSTEM_IECConfig);//下发命令
		CLogPrint::LogFormatString(XLOGLEVEL_ERROR,/*_T("当前测试项为空.")*/g_sLangTxt_Gradient_EmptyCurTI.GetString()); //lcq

        if (m_pSttIecRecordMainWidget != nullptr)
		{
			m_pSttIecRecordMainWidget->UpdateIecfg();
		}
		return;
	}

	Ats_SetItemPara(STT_CMD_TYPE_SYSTEM_IECConfig);//下发命令

    if ((g_pTheSttTestApp->m_pTestMacroUI != nullptr)&&(m_pMacroEditView!=nullptr))//判断当前是否加载了测试功能模块,并判断当前测试功能模块是否为网页
	{
		if (!g_pTheSttTestApp->m_pTestMacroUI->IsUIWeb())//更新界面
		{
			CSttMacroParaEditViewOriginal* pOriginal = (CSttMacroParaEditViewOriginal*)m_pMacroEditView;
			pOriginal->UpdateGoutTab(TRUE);//zhouhj20220319 在非网页界面界面时,更新
			pOriginal->UpdateFT3Tab(TRUE);//chenling20230518
		}
	}

    if (m_pSttIecRecordMainWidget != nullptr)
	{
		m_pSttIecRecordMainWidget->UpdateIecfg();
	}
	// 	CString strItemPath = g_pTheSttTestApp->m_pTestMacroUI->m_strID;
	// 	CString strMacroID = _T("");
	// 
	// 	strItemPath.Format(_T("%s$%s$%s"),strItemPath.GetString(),STT_ITEMS_ID_BEFORETEST,STT_CMD_TYPE_SYSTEM_IECConfig);
	// 	m_pTestCtrlCntrBase->Ats_SetItemPara(strItemPath, STT_CMD_TYPE_SYSTEM_IECConfig);
}

void QSttTestCntrFrameBase::Cmd_SendChMapsConfig()
{
// 	if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
// 	{
// 		CLogPrint::LogFormatString(XLOGLEVEL_ERROR,_T("当前测试项为空,无法下发通道映射文件."));
// 		return;
// 	}

	Ats_SetItemPara(STT_CMD_TYPE_ADJUST_ChMapsConfig);
// 	CString strItemPath = g_pTheSttTestApp->m_pTestMacroUI->m_strID;
// 	strItemPath.Format(_T("%s$%s$%s"),strItemPath.GetString(),STT_ITEMS_ID_BEFORETEST,STT_CMD_TYPE_ADJUST_ChMapsConfig);
// 	m_pTestCtrlCntrBase->Ats_SetItemPara(strItemPath, STT_CMD_TYPE_ADJUST_ChMapsConfig);
}

void QSttTestCntrFrameBase::Cmd_SendSystemConfig()
{
// 	if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
// 	{
// 		CLogPrint::LogFormatString(XLOGLEVEL_ERROR,_T("当前测试项为空,无法下发系统参数命令."));
// 		return;
// 	}

	Ats_SetItemPara(STT_CMD_TYPE_SYSTEM_SystemConfig);
// 	CString strItemPath = g_pTheSttTestApp->m_pTestMacroUI->m_strID;
// 	strItemPath.Format(_T("%s$%s$%s"),strItemPath.GetString(),STT_ITEMS_ID_BEFORETEST,STT_CMD_TYPE_SYSTEM_SystemConfig);
// 	m_pTestCtrlCntrBase->Ats_SetItemPara(strItemPath, STT_CMD_TYPE_SYSTEM_SystemConfig);
}

void QSttTestCntrFrameBase::UpdateSysConfig()
{
	emit sig_UpdateSysConfig();
}

void QSttTestCntrFrameBase::UpdatePowerGear()
{
	emit sig_UpdatePowerGear();
}

void QSttTestCntrFrameBase::New_SysConfig()
{

}

void QSttTestCntrFrameBase::SaveMacroTestUI_ParaFile(const CString &strNameAdd)
{
    if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
	{
		return;
	}

	if (! g_pTheSttTestApp->m_pTestMacroUI->IsUIWeb())
	{
		return;
	}

	m_pTestCtrlCntrBase->SaveMacroTestUI_ParaFile(strNameAdd);
}

CEventResult* QSttTestCntrFrameBase::GetCurEventResult()
{
	return &m_pTestCtrlCntrBase->m_oCurrEventResult;
}

void QSttTestCntrFrameBase::Ats_SetItemPara(const CString &strItemID)
{
	if (g_nLogDebugInfor)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T(">> begin SttTestCntrFrameBase::Ats_SetItemPara(%s) >>"), strItemID.GetString());
	}

	CString strItemPath;
	CExBaseList oList;
	m_pTestCtrlCntrBase->GetAllItemsByID(strItemID, oList);

	POS pos = oList.GetHeadPosition();

    while (pos != nullptr)
	{
		CSttItemBase *pItemBase = (CSttItemBase *)oList.GetNext(pos);
		stt_gb_get_itempath_id(pItemBase, strItemPath);

		m_pTestCtrlCntrBase->Ats_SetItemPara(strItemPath, strItemID);
	}
	

	if (oList.GetCount() == 0)//如果为空时,且为系统配置、IEC配置等则直接下发
	{
		if ((strItemID == STT_CMD_TYPE_SYSTEM_SystemConfig)||
			(strItemID == STT_CMD_TYPE_SYSTEM_IECConfig)||
			(strItemID == STT_CMD_TYPE_ADJUST_ChMapsConfig))
		{
			m_pTestCtrlCntrBase->Ats_SetItemPara(_T(""), strItemID);
		}
	}

	oList.RemoveAll();

	if (g_nLogDebugInfor)
	{
		CLogPrint::LogString(XLOGLEVEL_TRACE, _T(">> end SttTestCntrFrameBase::Ats_SetItemPara >>"));
	}

}

void QSttTestCntrFrameBase::Ats_SetItemPara_RsltExpr(CExBaseObject *pItem)
{

}

void QSttTestCntrFrameBase::SaveCharacteristicsData(CString strFile)
{
    if (m_pCharLibWidget == nullptr)
	{
		return ;
	}

	//2022-9-3  lijunqing
	//2022-9-8 yizejun 在已经打开一个配置文件时切换功能会因为m_pTestMacroUI中获取的新名称而覆盖新功能的配置文件
	//所以在切换功能时传入旧的文件名来保存旧模块的配置
	if(!strFile.GetLength())
	{
        //sun GetCharacteristicsFile(g_pTheSttTestApp->m_pTestMacroUI, strFile);
	}
	
	m_pCharacteristics->SaveXmlFile(strFile,CCharacteristicXmlRWKeys::g_pXmlKeys);
}

void QSttTestCntrFrameBase::slot_OnFreeCommCmdWzdWidget()
{

}

void QSttTestCntrFrameBase::slot_CloseMenu()
{
}

BOOL QSttTestCntrFrameBase::IsContinueCreateNew()
{
	return FALSE;
}

long QSttTestCntrFrameBase::GetGbItemCount()
{
    if (m_pTestCtrlCntrBase == nullptr)
	{
		return 0;
	}

	return m_pTestCtrlCntrBase->GetGbItemCount();
}

CString QSttTestCntrFrameBase::GetCurrentUI_ID()
{
    if (m_pTestCtrlCntrBase == nullptr)
	{
		return "";
	}

	if(!m_pTestCtrlCntrBase->GetCurrTestMacroUI())
	{
		return "";
	}

	return m_pTestCtrlCntrBase->GetCurrTestMacroUI()->m_strUI_ID;
}

//根据装置类型，过滤可供选择的功能
void QSttTestCntrFrameBase::InitTestMacroUI_by_DeviceType(CSttMacroTestUI_TestMacroUIMngr *pTestMacroUIMngr)
{
	return;
}

CSclStation* QSttTestCntrFrameBase::GetSclStation()
{
	return &m_pTestCtrlCntrBase->m_oSclStation;
}

void QSttTestCntrFrameBase::SetDatas(CDataGroup *pParas)
{
	m_pMacroEditView->SetDatas(pParas);
}

void QSttTestCntrFrameBase::ClearReportRslts_Html()
{

}

BOOL QSttTestCntrFrameBase::IsNeedAddAft()
{
	//默认需要添加
	return TRUE;
}

//项目粘贴后，处理报告
void QSttTestCntrFrameBase::ItemPaste_RootNode(CSttItems *pDestItems, CExBaseObject *pCurrentSel)  
{

}

void QSttTestCntrFrameBase::UpdateStatusBar_Btns(const CString &strID, const CString &strValue)
{
	CDataGroup dataGroup;
	dataGroup.AddNewData(strID, strValue);
	m_oDataBtnsMngr.UpdataDataButtons(&dataGroup);
}

// void QSttTestCntrFrameBase::slot_UpdateMUTimeAccurRlt(CDvmData *pSVDelayData)
// {
// 	if (g_pTheSttTestApp->m_pTestMacroUI == nullptr)
// 	{
// 		return;
// 	}
// 
// 	if (m_pMacroEditView == nullptr)
// 	{
// 		return;
// 	}
// 
// 	if (!IsTestStarted())
// 	{
// 		return;
// 	}
// 
// 	if ((g_pTheSttTestApp->m_pTestMacroUI->m_strID == STT_ORG_MACRO_MUTimingAccurTest)||
// 		(g_pTheSttTestApp->m_pTestMacroUI->m_strID == STT_ORG_MACRO_MUPunctAccurTest))
// 	{
// 		QSttMacroParaEditViewManual *pManualUI = (QSttMacroParaEditViewManual*)m_pMacroEditView;
// 		pManualUI->UpdateMUTimeAccurRlt_NOPPS(pSVDelayData);
// 	}
// }

BOOL CharVar_CalScriptValue(CCharInterfaceVariable *pCharVar)
{
    if (g_pGlobalDatas == nullptr)
	{
		return FALSE;
	}

	double dValue = 0;

	if (Stt_CalParaExpression(pCharVar->m_strScript, dValue, TRUE))
	{
		pCharVar->m_strValue.Format(_T("%f"), dValue);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

CExBaseObject* CharVar_GetScriptValObj(CCharInterfaceVariable *pCharVar)
{
    if (g_pGlobalDatas == nullptr)
	{
        return nullptr;
	}

	CExBaseObject* pData = g_pGlobalDatas->FindByID(pCharVar->m_strScript);

	return pData;
}

CString* CharVar_CalScriptValue(CExBaseObject *pData)
{
    ASSERT (pData != nullptr);
	CDvmData *pDataObj = (CDvmData*)pData;
	return &pDataObj->m_strValue;
}

void CharVar_CalScriptValue(CExBaseObject *pData, CString &strValue)
{
    ASSERT (pData != nullptr);
	CDvmData *pDataObj = (CDvmData*)pData;
	strValue = pDataObj->m_strValue;
}

BOOL Stt_CalParaExpression(const CString &strExpress, double &dValue, BOOL bLogError, CValues *pValues)
{
	CEpExpression oEpExp;

	if (strExpress.GetLength() == 0)
	{
		return FALSE;
	}

	if (oEpExp.ChangeEpExpression(strExpress) == -1)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, g_sLangTxt_ExpressionError.GetString()/*_T("表达式【%s】 错误")*/, strExpress.GetString());
		return FALSE;
	}

	CString strValue;
	POS pos = oEpExp.GetHeadPosition();
    CEpExpVariable *pExpVar = nullptr;
	BOOL bTrue = TRUE;

    while (pos != nullptr)
	{
		pExpVar = oEpExp.GetNext(pos);

		if (Stt_CalParaExp_FindValue(pValues, pExpVar->m_strVarID, strValue))
		{
#ifdef _UNICODE
			pExpVar->m_dValue = _wtof(strValue);
#else
			pExpVar->m_dValue = atof(strValue.GetString());
#endif
		}
		else
		{
			if (bLogError)
			{
				CLogPrint::LogFormatString(XLOGLEVEL_TRACE, g_sLangTxt_ExpressionVariable.GetString()/*_T("表达式变量【%s】 错误")*/, pExpVar->m_strVarID.GetString());
				bTrue = FALSE;
			}
		}
	}

	oEpExp.Value(dValue);

	return bTrue;
}

BOOL Stt_CalParaExp_FindValue(CValues *pValues, const CString &strVarID, CString &strValue)
{
    if (pValues != nullptr)
	{
		if (pValues->GetValue(strVarID, strValue))
		{
			return TRUE;
		}
	}

    if (g_pGlobalDatas != nullptr)
	{
		if (g_pGlobalDatas->GetDataValue(strVarID, strValue))
		{
			return TRUE;
		}
	}

	return FALSE;
}


void QSttTestCntrFrameBase::OnCmd_CustomSet()
{
	//自定义设置

	SttCustomSetDlg dlg(this);
#ifdef _USE_SoftKeyBoard_
	QSoftKeyBoard::AttachObj(&dlg, Keyboard::NUMBER);
	dlg.exec();
	QSoftKeyBoard::ReAttachObj();
#else
	dlg.exec();
#endif
}

void QSttTestCntrFrameBase::OnCmd_FileMngr()
{
	QSttFileMngrDlg dlg(this);
#ifdef _USE_SoftKeyBoard_
	QSoftKeyBoard::AttachObj(&dlg, Keyboard::ENGLISH);
	dlg.exec();
	QSoftKeyBoard::ReAttachObj();
#else
	dlg.exec();
#endif
}

void QSttTestCntrFrameBase::OnCmd_LumPowerView()
{
	//zhouhj 2023.11.25 对于330等机器,发送命令启动光功率测量电源开关
    if (m_pTestCtrlCntrBase != nullptr)
	{
		CDataGroup oGroup;
		m_pTestCtrlCntrBase->Ats_SetParameter(STT_MACRO_ID_LcPowerTest,&oGroup);
	}

	QLuminousPowerDlg dlg(this);
	CDataGroup *pFiberCopy=(CDataGroup*)(&g_oSttTestResourceMngr.m_oFiberMsgGroup)->Clone();
	dlg.InitData(pFiberCopy);
#ifdef _USE_SoftKeyBoard_
	QSoftKeyBoard::AttachObj(&dlg, Keyboard::ENGLISH);
	dlg.exec();
	QSoftKeyBoard::ReAttachObj();
#else
	dlg.exec();	
#endif
}

void QSttTestCntrFrameBase::OnCmd_OutputDebug()
{
//     QOutPutDebug dlg(this);
// 	//dlg.InitUI();
// 
// #ifdef _USE_SoftKeyBoard_
// 	QSoftKeyBoard::AttachObj(&dlg, Keyboard::ENGLISH);
// 	dlg.exec();
// 	QSoftKeyBoard::ReAttachObj();
// #else
// 	dlg.exec();	
// #endif
}

void QSttTestCntrFrameBase::OnCmd_Minimize()
{
	this->showMinimized();
}

void QSttTestCntrFrameBase::OnCmd_AuxDCOutput()
{
	UpDateUdcVal();
	if (!xlang_IsCurrXLanguageChinese()/*g_oSttSystemConfig.GetDevModel() == "L336EXi"*/)
	{
		QAuxDCOutputDlg_L336EXi oAuxDCOutputDlg(this);
		oAuxDCOutputDlg.initUI();
#ifdef _USE_SoftKeyBoard_
		QSoftKeyBoard::AttachObj(&oAuxDCOutputDlg, Keyboard::NUMBER);
		if (oAuxDCOutputDlg.exec() == QDialog::Accepted)
		{
			slot_UpdateAuxDCOutput();
		}
		QSoftKeyBoard::ReAttachObj();
#else
		if (oAuxDCOutputDlg.exec() == QDialog::Accepted)
		{
			slot_UpdateAuxDCOutput();
		}
#endif
	}
	else
	{
	QAuxDCOutputDlg oAuxDCOutputDlg(this);
	oAuxDCOutputDlg.initUI();
#ifdef _USE_SoftKeyBoard_
    QSoftKeyBoard::AttachObj(&oAuxDCOutputDlg, Keyboard::NUMBER);
	if (oAuxDCOutputDlg.exec() == QDialog::Accepted)
	{
		slot_UpdateAuxDCOutput();
	}
	QSoftKeyBoard::ReAttachObj();
#else
	if (oAuxDCOutputDlg.exec() == QDialog::Accepted)
	{
		slot_UpdateAuxDCOutput();
	}
#endif
	}
	//connect(&oAuxDCOutputDlg, SIGNAL(sig_UpdateAuxDCOutput()), this, SLOT(slot_UpdateAuxDCOutput()));

	//disconnect(&oAuxDCOutputDlg, SIGNAL(sig_UpdateAuxDCOutput()), this, SLOT(slot_UpdateAuxDCOutput()));
}

void QSttTestCntrFrameBase::OnCmd_IecCapDialog()
{
	InitSttIecRecord();
	QSttIecCapDialog oSttIecCapDialog(this);
	oSttIecCapDialog.InitUI();
	connect(m_pOutputWidget, SIGNAL(sig_refreshLog(QString)), oSttIecCapDialog.m_pSttOutPutWidget, SLOT(slot_refreshOutput(QString)));
	oSttIecCapDialog.show();

	oSttIecCapDialog.StartDetect(true);
	oSttIecCapDialog.exec();
}

void QSttTestCntrFrameBase::OnCmd_TransPcapFile()
{

}

BOOL QSttTestCntrFrameBase::CreateCommCfgPkgMnWidget()
{
    //sun if(m_pSttCommCfgPkgWidget != nullptr)
    //sun {
    //sun 	return FALSE;
    //sun }
    //sun
    //sun m_pSttCommCfgPkgWidget = new QSttCommCfgPkgMonitorWidget(this);
    //sun m_pSttCommCfgPkgWidget->setParent(this);
    //sun m_pSttCommCfgPkgWidget->hide();
    //sun m_pSttCommCfgPkgWidget->setGeometry(m_rcWorkArea);
	return TRUE;
}

//sun BOOL QSttTestCntrFrameBase::CreateRemoteCtrlWidget()
//sun {
//sun     if(m_pRemoteCtrlWidget != nullptr)
//sun 	{
//sun 		return FALSE;
//sun 	}
//sun
//sun 	m_pRemoteCtrlWidget = new QSttMacroParaEditViewRemoteCtrl(this);
//sun 	m_pRemoteCtrlWidget->setParent(this);
//sun 	m_pRemoteCtrlWidget->hide();
//sun 	m_pRemoteCtrlWidget->setGeometry(m_rcWorkArea);
//sun 	return TRUE;
//sun }


//sun void QSttTestCntrFrameBase::OnCmd_PkgMonitorDlg()
//sun {
//sun     if (m_pSttCommCfgPkgWidget == nullptr)
//sun 	{
//sun 		CreateCommCfgPkgMnWidget();
//sun 	}
//sun 	QSttCommCfgPkgMonitorDlg oSttCommCfgPkgMnDlg(m_pSttCommCfgPkgWidget,this);
//sun 	oSttCommCfgPkgMnDlg.exec();
//sun }

void QSttTestCntrFrameBase::OnUpdateRtHardConfig( CDataGroup *pRtSycTime )
{
    if (pRtSycTime == nullptr/* || !m_bUpdateHardCfgFromRealTime*/)
	{
		return;
	}

	POS pos = pRtSycTime->GetHeadPosition();
    CExBaseObject *p = nullptr;
    CDvmData *pFind = nullptr;

    while (pos != nullptr)
	{
		p = pRtSycTime->GetNext(pos);
		if(p->GetClassID() == DVMCLASSID_CDVMDATA)
		{
			if (p->m_strID == _T("4G"))
			{
				pFind = (CDvmData *)p;
				g_oSystemParas.m_oPeripheral.m_b4G = CString_To_long(pFind->m_strValue);
			}
			else if (p->m_strID == _T("Wifi"))
			{
				pFind = (CDvmData *)p;
				g_oSystemParas.m_oPeripheral.m_bNetWifi = CString_To_long(pFind->m_strValue);
			}
			else if (p->m_strID == _T("Ble"))
			{
				pFind = (CDvmData *)p;
				g_oSystemParas.m_oPeripheral.m_bBle = CString_To_long(pFind->m_strValue);
			}
			else if (p->m_strID == _T("TimeZone"))
			{
				pFind = (CDvmData *)p;
				g_oSystemParas.m_nTimeZone = CString_To_long(pFind->m_strValue);
			}
			else if (p->m_strID == _T("WindSpeed"))
			{
				pFind = (CDvmData *)p;
				g_oSystemParas.m_nWindSpeed = CString_To_long(pFind->m_strValue);
			}
		}

	}
}


