// D:\WorkPM\Source\PMTest\Module\TestControlWnd.cpp : 实现文件
//

#include "stdafx.h"
#include "TestControlWnd.h"
#include "TestControl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTestControlWnd

IMPLEMENT_DYNAMIC(CTestControlWnd, CWnd)

CTestControlWnd::CTestControlWnd()
{
	m_bTIMER_TEST_CTRL_MACROFINISH = FALSE;
	m_bTIMER_TEST_FOR_APPEXCEPTION = FALSE;
}

CTestControlWnd::~CTestControlWnd()
{
}


BEGIN_MESSAGE_MAP(CTestControlWnd, CWnd)
	ON_MESSAGE(WM_ELECTRIC_TEST, &CTestControlWnd::OnElectricTestMsg)
	ON_MESSAGE(WM_COMM_COMMAND, &CTestControlWnd::OnCommCommandMsg)
	ON_MESSAGE(WM_SAFETY_TEST_FINISHED, &CTestControlWnd::OnSafetyTestFinished)
	ON_MESSAGE(WM_SYSPARAEDIT_TEST_FINISHED, &CTestControlWnd::OnSysParaEditTestFinished)
	ON_MESSAGE(WM_COMMCMD_TEST_FINISHED, &CTestControlWnd::OnCommCmdMamualTestFinished)
	ON_WM_TIMER()
	ON_MESSAGE(WM_MANUAL_TEST, &CTestControlWnd::OnManualTestMsg)
	ON_MESSAGE(WM_ENGINE_SYSTEM_MSG, &CTestControlWnd::OnEngineSystemMessage)
	ON_MESSAGE(WM_TIMER_TRIGGER, &CTestControlWnd::OnTimerTrigger)
END_MESSAGE_MAP()

// CTestControlWnd 消息处理程序
void CTestControlWnd::Gbs_SetTmTriggerCounter_Minute(long nMinute)
{
	m_oTimeTrgger.SetTmTriggerCounter_Minute(nMinute);
}

void CTestControlWnd::Gbs_SetTmTriggerSecond(long nSecond, long nOptr)
{
	m_oTimeTrgger.SetTmTriggerSecond(nSecond, nOptr);
}

void CTestControlWnd::Gbs_StartTmTrigger()
{
	m_oTimeTrgger.AttachMsgRcvWnd(this, WM_TIMER_TRIGGER);
	m_oTimeTrgger.StartTimerTigger();
}

void CTestControlWnd::Gbs_EnterTmTrigger()
{
	m_oTimeTrgger.EnterTimerTrigger();
}

void CTestControlWnd::Gbs_StopTmTrigger()
{
	m_oTimeTrgger.StopTimerTigger();
}

LRESULT CTestControlWnd::OnElectricTestMsg(WPARAM wParam, LPARAM lParam)
{
	CAutoSimpleLock oLock(CTestControl::m_oTestCriticSection);
	KillTimer(TIMER_TEST_CTRL_MACROFINISH);
	m_bTIMER_TEST_CTRL_MACROFINISH = FALSE;

	//CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("TestControlWnd::OnElectricTestMsg(%d, %d)"), wParam, lParam);
	return m_pTestControl->OnElectricTestMsg(wParam,lParam);
}

LRESULT CTestControlWnd::OnCommCommandMsg(WPARAM wParam, LPARAM lParam)
{
	CAutoSimpleLock oLock(CTestControl::m_oTestCriticSection);

	//CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("TestControlWnd::OnCommCommandMsg:%s "), m_pTestControl->m_strName);
	return m_pTestControl->OnCommCommandMsg(wParam,lParam);
}

LRESULT CTestControlWnd::OnSafetyTestFinished(WPARAM wParam, LPARAM lParam)
{
	//CLogPrint::LogString(XLOGLEVEL_TRACE, L"TestControlWnd::OnSafetyTestFinished");
	return m_pTestControl->OnSafetyTestFinished(wParam,lParam);
}

LRESULT CTestControlWnd::OnSysParaEditTestFinished(WPARAM wParam, LPARAM lParam)
{
	//CLogPrint::LogString(XLOGLEVEL_TRACE, L"TestControlWnd::OnSysParaEditTestFinished");

	return m_pTestControl->OnSysParaEditTestFinished(wParam,lParam);
}

LRESULT CTestControlWnd::OnCommCmdMamualTestFinished(WPARAM wParam, LPARAM lParam)
{
	//CLogPrint::LogString(XLOGLEVEL_TRACE, L"TestControlWnd::OnCommCmdMamualTestFinished");

	return m_pTestControl->OnCommCmdMamualTestFinished(wParam,lParam);
}

BOOL CTestControlWnd::CreateTestControlWnd()
{
	CreateEx(0, AfxRegisterWndClass(0), _T("_Test_Ctrl_Wnd_"), WS_OVERLAPPED, CRect(0,0,0,0), NULL, NULL);
	//2016-12-16  屏蔽测试仪异常定时判断
	SetTimer(TIMER_TEST_CTRL_EXCEPTION, TIMER_TEST_CTRL_EXCEPTION_LONG, NULL);
	return TRUE;
}

// #define TIMER_BEFORE_CMM_CMD   4
// #define TIMER_AFTER_CMM_CMD    5

void CTestControlWnd::OnTimer(UINT_PTR nIDEvent)
{
	CAutoSimpleLock oLock(CTestControl::m_oTestCriticSection);
	//CLogPrint::LogFormatString(XLOGLEVEL_TRACE, L"TestControlWnd::OnTimer(%d)", nIDEvent);
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if (TIMER_DELAY_BEFORE_CMM_CMD == nIDEvent)
	{
		KillTimer(TIMER_DELAY_BEFORE_CMM_CMD);
		m_pTestControl->ExcuteCommCmdOnDelayBeforeFinish((CCommCmd*)m_pTestItemRef);
	}
	else if (TIMER_DELAY_AFTER_CMM_CMD == nIDEvent)
	{
		KillTimer(TIMER_DELAY_AFTER_CMM_CMD);
		m_pTestControl->ExcuteCommCmdOnDelayAfterFinish((CCommCmd*)m_pTestItemRef);
	}
	else if (TIMER_DELAY_CMM_CMD_ITEMSEXPR == nIDEvent)
	{
		KillTimer(TIMER_DELAY_CMM_CMD_ITEMSEXPR);
		m_pTestControl->ExcuteCommCmdOnDelayBeforeFinish((CCommCmd*)m_pTestItemRef);
	}
	else if (TIMER_TEST_FOR_OVERTIME == nIDEvent)
	{
		KillTimer(TIMER_TEST_FOR_OVERTIME);
		m_pTestControl->TestOverTimerItem();
	}
	else if (TIMER_TEST_CTRL_EXCEPTION == nIDEvent)
	{
		m_pTestControl->IsMacroTCtrlException();
	}
	else if (TIMER_RETRY_CMM_CMD == nIDEvent)
	{
		KillTimer(TIMER_RETRY_CMM_CMD);
		m_pTestControl->TestItemCommCmd((CCommCmd*)m_pTestItemRef);
	}
	else if (TIMER_TEST_CTRL_MACROFINISH == nIDEvent)
	{
		KillTimer(TIMER_TEST_CTRL_MACROFINISH);

		if (m_bTIMER_TEST_CTRL_MACROFINISH )
		{
			if (g_nLog_TestControl_Msg == 1)
			{
				CLogPrint::LogString(XLOGLEVEL_TRACE, _T("CTestControlWnd::OnTimer(TIMER_TEST_CTRL_MACROFINISH) ==>> OnElectricTestMsg"));
			}

			m_bTIMER_TEST_CTRL_MACROFINISH = FALSE;
			OnElectricTestMsg(MacroTest::MTMSG_TestFinished, MacroTest::MTMSG_TestFinished);
		}
	}
	else if (TIMER_PPENGINE_EXCEPTION == nIDEvent)
	{
		m_pTestControl->OnPpEngineExceptionTimer();
		KillTimer(TIMER_PPENGINE_EXCEPTION);
	}
	else if (TIMER_TEST_FOR_APPEXCEPTION == nIDEvent)
	{
		KillTimer(TIMER_TEST_FOR_APPEXCEPTION);
		m_pTestControl->TestFrom((CGbItemBase *)m_pTestItemRef);
	}

	CWnd::OnTimer(nIDEvent);
}

void CTestControlWnd::Set_TIMER_TEST_CTRL_MACROFINISH()
{
	m_bTIMER_TEST_CTRL_MACROFINISH = TRUE;
	SetTimer(TIMER_TEST_CTRL_MACROFINISH, TIMER_TEST_CTRL_MACROFINISH_LONG, NULL);
}

void CTestControlWnd::SetPpEngineTimer()
{
	SetTimer(TIMER_PPENGINE_EXCEPTION, TIMER_PPENGINE_EXCEPTION_LONG, NULL);
}

void CTestControlWnd::KillPpEngineTimer()
{
	KillTimer(TIMER_PPENGINE_EXCEPTION);
}

void CTestControlWnd::StopTest()
{
	KillTimer(TIMER_DELAY_BEFORE_CMM_CMD);
	KillTimer(TIMER_DELAY_AFTER_CMM_CMD);
	KillTimer(TIMER_TEST_FOR_OVERTIME);
	KillTimer(TIMER_TEST_CTRL_EXCEPTION);
	KillTimer(TIMER_PPENGINE_EXCEPTION);
	KillTimer(TIMER_TEST_FOR_APPEXCEPTION);
	KillTimer(TIMER_TEST_CTRL_MACROFINISH);

	KillPpEngineTimer();

	m_oTimeTrgger.StopTimerTigger();
}

LRESULT CTestControlWnd::OnManualTestMsg(WPARAM wParam, LPARAM lParam)
{
	return m_pTestControl->OnManualTestMsg(wParam,lParam);
}

DWORD g_dwEngineSystemMessageTick = 0;
LRESULT CTestControlWnd::OnEngineSystemMessage(WPARAM wParam, LPARAM lParam)
{
	CAutoSimpleLock oLock(CTestControl::m_oTestCriticSection);
	DWORD dwCurr = ::GetTickCount();

	//if (dwCurr - g_dwEngineSystemMessageTick > 30000)
	{
		m_pTestControl->OnEngineSystemMessage(wParam,lParam);
	}

	g_dwEngineSystemMessageTick = dwCurr;

	return 0;
}

LRESULT CTestControlWnd::OnTimerTrigger(WPARAM wParam, LPARAM lParam)
{
	m_pTestControl->ExcuteCommCmdOnDelayBeforeFinish((CCommCmd*)m_pTestItemRef);

	return 0;
}
