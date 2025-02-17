#pragma once

#include "TCtrlCntrDefine.h"
#include "..\..\Module\System\TimeTrigger.h"
/*
	�������������Թ����У����ղ�������������Ϣ�Ĵ���
	���磺 ��װ�ò��ԣ��ײ���Թ���ģ��������֮���͸��Զ����Գ���Ĵ�����Ϣ
	       �뱣��/����װ�õ�ͨѶ��ͨѶ���֮���͸��Զ����Ե������Ϣ
*/

class CTestControl;

#define TIMER_DELAY_BEFORE_CMM_CMD    4
#define TIMER_DELAY_AFTER_CMM_CMD     5

//������������Ŀ��ʱ�ز�
#define TIMER_TEST_FOR_OVERTIME         6
#define TIMER_TEST_FOR_OVERTIME_LONG         1000

//������������Ŀ��ʱ�ز�
#define TIMER_TEST_CTRL_EXCEPTION        7
#define TIMER_TEST_CTRL_EXCEPTION_LONG         10000
#define TIMER_TEST_CTRL_MACROFINISH        9
#define TIMER_TEST_CTRL_MACROFINISH_LONG         20000

//ͨѶʧ�ܣ�����ͨѶ��ʱ��
#define TIMER_RETRY_CMM_CMD    8

//ͨѶ��Լ���������쳣����ʱ��
#define TIMER_PPENGINE_EXCEPTION        10
#define TIMER_PPENGINE_EXCEPTION_LONG   20000

//������������Ŀ��ʱ�ز�
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


