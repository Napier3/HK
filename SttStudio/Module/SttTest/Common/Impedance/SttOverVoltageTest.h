#pragma once

#include "SttImpBaseTest.h"
#include "tmt_over_voltage_test.h"


class CSttOverVoltageTest : public CSttImpBaseTest ,public tmt_OverVoltageParas
{
public:
    CSttOverVoltageTest();
    virtual ~CSttOverVoltageTest(void);

	static CString m_strMacroName;
	static CString m_strMacroID;
	static CString m_strMacroVer;
	static CString m_strFilePostFix;

    static CSttTestBase* CreateTest()
	{
        return new CSttOverVoltageTest();
	}
public:

	virtual void AfterSetParameter();
	virtual long CalReport(UINT nState=0);

	virtual void Para_XmlSerialize(CSttXmlSerializeBase *pXmlSerialize);
	virtual void Report_XmlSerialize(CSttXmlSerializeBase *pXmlSerialize);

public:
    virtual void Init();
	virtual long SetParameter(DWORD dwState=0);

protected:
	 virtual void TranslateToStateParas();//在此函数中实现将重合闸后加速参数转换为状态序列参数

protected:
    tmt_OverVoltageResults m_oResults;
};
