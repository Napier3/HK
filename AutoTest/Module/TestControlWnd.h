#pragma once

#include "TCtrlCntrDefine.h"
#include "..\..\Module\System\TimeTrigger.h"
/*
	功能描述：测试过程中，接收并处理测试相关消息的窗口
	例如： 带装置测试，底层测试功能模块测试完成之后发送给自动测试程序的处理消息
	       与保护/测试装置的通讯，通讯完成之后发送给自动测试的相关消息
*/

class CTestControl;

#define TIMER_DELAY_BEFORE_CMM_CMD    4
#define TIMER_DELAY_AFTER_CMM_CMD     5

//电气量测试项目超时重测
#define TIMER_TEST_FOR_OVERTIME         6
#define TIMER_TEST_FOR_OVERTIME_LONG         1000

//电气量测试项目超时重测
#define TIMER_TEST_CTRL_EXCEPTION        7
#define TIMER_TEST_CTRL_EXCEPTION_LONG         10000
#define TIMER_TEST_CTRL_MACROFINISH        9
#define TIMER_TEST_CTRL_MACROFINISH_LONG         20000

//通讯失败，重新通讯的时钟
#define TIMER_RETRY_CMM_CMD    8

//通讯规约引擎程序的异常处理时钟
#define TIMER_PPENGINE_EXCEPTION        10
#define TIMER_PPENGINE_EXCEPTION_LONG   20000

//电气量测试项目超时重测
#define TIMER_TEST_FOR_APPEXCEPTION        11

#define TIMER_DELAY_CMM_CMD_ITEMSEXPR    12


class CTestControlWnd : public CWnd
{
	DECLARE_DYNAMIC(CTestControlWnd)

public:
	CTestControlWnd();
	virtual ~CTestControlWnd();
	BOOL CreateTestControlWnd();
	void StopTest();

	void FireOnTimer(UINT_PTR nIDEvent)
	{
		OnTimer(nIDEvent);
	}

	void SetTestTimer(UINT nTimerID, UINT nTimerLong)
	{
		ASSERT (nTimerID == TIMER_DELAY_BEFORE_CMM_CMD || nTimerID ==  TIMER_DELAY_AFTER_CMM_CMD
			|| nTimerID == TIMER_TEST_FOR_OVERTIME);

		if (nTimerID == TIMER_DELAY_BEFORE_CMM_CMD)
		{
			if (!m_oTimeTrgger.NeedTrigger())
			{
				SetTimer(nTimerID, nTimerLong, NULL);
			}
		}
		else
		{
			SetTimer(nTimerID, nTimerLong, NULL);
		}
	}

	void KillTestTimer(UINT nTimerID)
	{
		ASSERT (nTimerID == TIMER_DELAY_BEFORE_CMM_CMD || nTimerID ==  TIMER_DELAY_AFTER_CMM_CMD
			|| nTimerID == TIMER_TEST_FOR_OVERTIME);
		KillTimer(nTimerID);

		if (nTimerID == TIMER_DELAY_BEFORE_CMM_CMD)
		{
			m_oTimeTrgger.SetTmTriggerNone();
		}
	}

	void SetPpEngineTimer();
	void KillPpEngineTimer();

	void Gbs_SetTmTriggerCounter_Minute(long nMinute);
	void Gbs_SetTmTriggerSecond(long nSecond, long nOptr);
	void Gbs_StartTmTrigger();
	void Gbs_EnterTmTrigger();
	void Gbs_StopTmTrigger();

public:
	CTestControl* m_pTestControl;
	CExBaseObject *m_pTestItemRef;
	BOOL m_bTIMER_TEST_FOR_APPEXCEPTION;

	void Set_TIMER_TEST_CTRL_MACROFINISH();

private:
	BOOL m_bTIMER_TEST_CTRL_MACROFINISH;
	CTimeTrigger m_oTimeTrgger;
	UINT m_nTimerID;

protected:
	afx_msg LRESULT OnElectricTestMsg(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnCommCommandMsg(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSafetyTestFinished(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSysParaEditTestFinished(WPARAM wPara,LPARAM lPara);
	afx_msg LRESULT OnCommCmdMamualTestFinished(WPARAM wPara,LPARAM lPara);
	afx_msg LRESULT OnManualTestMsg(WPARAM wPara,LPARAM lPara);
	afx_msg LRESULT OnEngineSystemMessage(WPARAM wPara,LPARAM lPara);
	afx_msg LRESULT OnTimerTrigger(WPARAM wPara,LPARAM lPara);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};


