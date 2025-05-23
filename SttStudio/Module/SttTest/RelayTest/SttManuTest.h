#pragma once

#include"../../SttTestBase/SttTestBase.h"
#include"../../SttTestBase/SttComplexp.h"
#include"tmt_manu_test.h"
#include"drv_manu_test.h"
#include "GradientBase.h"
#include "drv_gradient_test.h"


class CSttManuTest : public CGradientBase, public tmt_ManualTest
{
public:
    CSttManuTest();
    virtual ~CSttManuTest(void);

    drv_manu_gradient_test m_oDrvManuGradient;
	structRampResult            m_oDrvResults[100];

	static CString m_strMacroName;
	static CString m_strMacroID;
	static CString m_strFilePostFix;

    static CSttTestBase* CreateTest()
	{
        return new CSttManuTest();
	}
public:
    UINT m_uStartTimeS;
    UINT m_uStartTimeMS;
    UINT m_uChangeTime;
    UINT m_uChangeTimeMS;
    UINT m_uStartTimeNS;
    bool m_bIsReturn;
    UINT m_uReturnTimeMS;
    UINT m_uReturnTime;

public:
//	virtual UINT GetClassID()         {    return TMCLASSID_STATE;    }
	virtual void AfterSetParameter();
	virtual double GetTestTimeLong();
	virtual long CalReport(UINT nState=0);
    virtual void CalStepValue(float fCurValue);

public:
    virtual void Init();
	virtual long SetParameter(DWORD dwState=0);
    virtual long OnTimer(BOOL &bFinish, long nTimerLongMs);
    virtual void StartTest();

    virtual void Para_XmlSerialize(CSttXmlSerializeBase *pXmlSerialize);
	virtual void Stop();

public:
    virtual void TtmToDrv();
};
