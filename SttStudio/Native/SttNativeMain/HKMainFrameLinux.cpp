#include "HKMainFrameLinux.h"
#include "../../../AutoTest/Module/AutoTestGlobalDefine.h"
#include "../../../Module/API/StringConvertApi.h"
#include "../../Module/SttTestBase/SttMacroXmlKeys.h"
#include "../../Module/SttSocket/SttCmdOverTimeMngr.h"
#include "../../Module/SttCmd/SttCmdDefineGlobal.h"
#include "../../Module/SttTestAppConfig/SttTestAppConfigTool.h"
#include "../../Module/TestClient/SttTestClientBase.h"

#include "../../../61850/Module/XLanguageResourceIec.h"
#include "XLangResource_SttNativeMain.h"
#include <QMouseEvent>
#include <QApplication>

CSttTestAppConfigTool g_oSttTestAppConfigTool;
extern CSttTestClientBase *g_theSingleSttTestClient;
HKMainFrameLinux::HKMainFrameLinux(QWidget *parent) :
    HKMainFrameBase(parent)
{
    CMacroXmlKeys::Create();
    CSttCmdOverTimeTool::Create();
    CSttCmdDefineXmlRWKeys::Create();
    CCfgDataMngrConstGlobal::Create();

    stt_CreateSingleSttTestClient();
    g_oSttTestAppConfigTool.m_strServerID = STT_SOFT_ID_TEST;
    g_oSttTestAppConfigTool.m_strSoftID = STT_SOFT_ID_DEBUG;
    m_bConnected = 0;
    m_bConnected = g_theSingleSttTestClient->ConnectSttServer(&g_oSttTestAppConfigTool);
    m_nConnectCnt = 1;//第一次联机，如果未成功，后面3秒一次继续尝试9次
    if (m_bConnected)
    {
        g_oSttTestAppConfigTool.m_pClientEngine = g_theSingleSttTestClient->GetTestEngineClient();
        g_oSttTestAppConfigTool.m_pClientEngine->SetTestEventInterface((CTestEventBaseInterface*)this);
    }
    else
    {
        m_oTimerForConnect.start(3000);
        connect(&m_oTimerForConnect,SIGNAL(timeout()),this,SLOT(slot_SttConnect()));
    }
    m_nTesterVerIdx = -1;
    InitBatteryBtn();
    connect(this,SIGNAL(sig_UpdateBatteryState()),this,SLOT(slot_UpdateBatteryState()),Qt::QueuedConnection);
}

HKMainFrameLinux::~HKMainFrameLinux()
{
	CMacroXmlKeys::Release();
	CSttCmdOverTimeTool::Release();
	CCfgDataMngrConstGlobal::Release();
	CSttCmdDefineXmlRWKeys::Release();
	stt_RelaseSingleSttTestClient();
}

void HKMainFrameLinux::InitBatteryBtn()
{
	if (m_pMainConfig->m_nShowBatteryBtn != 1)
	{
		return;
	}
	m_nBatCapValue = 0;
	m_nPowerAC = 0;
	m_oBatteryBtn.setToolButtonStyle(Qt::ToolButtonIconOnly);
	m_oBatteryBtn.setStyleSheet("QToolButton {border: none;}");
	int nWidth = 38;
	int nHeight = 40;
    m_oBatteryBtn.setParent(this);

	m_oBatteryBtn.setFixedSize(nWidth*g_dUIShowCoef,nHeight*g_dUIShowCoef);
	m_oBatteryBtn.setIconSize(QSize(nWidth*g_dUIShowCoef, nWidth*g_dUIShowCoef));
    m_oBatteryBtn.move(960*g_dUIShowCoef,11*g_dUIShowCoef);

	UpdateBatteryState(0);
	m_strBatCapString = "0%";
	m_oBatteryBtn.setText(m_strBatCapString);
}

void HKMainFrameLinux::UpdateBatteryState(int nState)
{
	CString strText;

	switch(nState)
	{
	case 1:
		strText = "margin-top:9px;margin-bottom:9px; border-image: url(:/power/images/MAINPOWER-1.png) center";
		break;
	case 2:
		strText = "margin-top:9px;margin-bottom:9px; border-image: url(:/power/images/MAINPOWER-2.png) center"/*,_P_GetResourcePath()*/;
		break;
	case 3:
		strText = "margin-top:9px;margin-bottom:9px; border-image: url(:/power/images/MAINPOWER-3.png) center";
		break;
	case 4:
		strText = "margin-top:9px;margin-bottom:9px; border-image: url(:/power/images/MAINPOWER-4.png) center";
		break;
	case 5:
		strText = "margin-top:9px;margin-bottom:9px; border-image: url(:/power/images/MAINPOWER-5.png) center";//20 round;
		break;
	default:
		strText = "margin-top:9px;margin-bottom:9px; border-image: url(:/power/images/MAINPOWER-0.png) center";//padding-top:5px;
		break;
	} 
	if (m_strCurrStyleString != strText)
	{
		m_strCurrStyleString = strText;
		m_oBatteryBtn.setStyleSheet(m_strCurrStyleString);
	}
}

long HKMainFrameLinux::OnRtData(CSttParas *pParas)
{
    CExBaseObject *pChildObj = nullptr;
	POS pos = pParas->GetHeadPosition();
    CDataGroup *pRtDataGroup = nullptr;
	long nPowerAC = m_nPowerAC;
	long nBatCapValue = m_nBatCapValue;

	while(pos)
	{
		pChildObj = pParas->GetNext(pos);

		if (pChildObj->GetClassID() != DTMCLASSID_CDATAGROUP)
		{
			continue;
		}
		pRtDataGroup = (CDataGroup *)pChildObj;
		if (pRtDataGroup->m_strID == SYS_STATE_XEVENT_EVENTID_SYNCTIME)
		{
			stt_GetDataValueByID(pRtDataGroup, _T("PowerAC"), nPowerAC);
			stt_GetDataValueByID(pRtDataGroup, _T("BatCap"), nBatCapValue);
		}
	}

	if ((nPowerAC != m_nPowerAC)||(nBatCapValue != m_nBatCapValue))
	{
		m_nPowerAC = nPowerAC;
		m_nBatCapValue = nBatCapValue;
		emit sig_UpdateBatteryState();
	}
	return 1;
}

void HKMainFrameLinux::slot_UpdateBatteryState()
{
	if (isHidden())//后台运行时,不更新
	{
		m_nPowerAC = -1;
		m_nBatCapValue = -1;
		return;
	}

	if (m_nPowerAC == 1)
	{
		UpdateBatteryState(5);
	}
	if (m_nPowerAC == 0)
	{
		if (m_nBatCapValue > 0 && m_nBatCapValue <= 20)
		{
			UpdateBatteryState(1);
		}
		else if (m_nBatCapValue > 20 && m_nBatCapValue <= 50)
		{
			UpdateBatteryState(2);
		}
		else if (m_nBatCapValue > 50 && m_nBatCapValue <= 80)
		{
			UpdateBatteryState(3);
		}
        else if (m_nBatCapValue > 80 && m_nBatCapValue <= 100)//2024-1-22 修改电量显示图标
		{
			UpdateBatteryState(4);
		}
	}
	m_strBatCapString.Format(_T("%d%"), m_nBatCapValue);
	m_oBatteryBtn.setText(m_strBatCapString);

}

long HKMainFrameLinux::OnDisConnect()
{
	m_nPowerAC = 0;
	m_nBatCapValue = 0;
	emit sig_UpdateBatteryState();
	return 0;
}

void HKMainFrameLinux::slot_SttConnect()
{
	m_nConnectCnt ++;
	if (m_nConnectCnt == 10)
	{
		m_oTimerForConnect.stop();//10次都未联机上，关闭该计时器
		return;
	}
	m_bConnected = g_theSingleSttTestClient->ConnectSttServer(&g_oSttTestAppConfigTool);
	if (m_bConnected)
	{
		g_oSttTestAppConfigTool.m_pClientEngine = g_theSingleSttTestClient->GetTestEngineClient();
		g_oSttTestAppConfigTool.m_pClientEngine->SetTestEventInterface((CTestEventBaseInterface*)this);
		m_oTimerForConnect.stop();//联机成功，关闭该计时器
	}
}
