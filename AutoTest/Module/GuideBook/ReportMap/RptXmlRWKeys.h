#pragma once
#include "ReportTemplateDefine.h"

class CRptXmlRWKeys :	public CXmlRWKeys
{
public:
	CRptXmlRWKeys(void);
	virtual ~CRptXmlRWKeys(void);

public:
	static CRptXmlRWKeys* g_pRptXmlRWKeys;
	static long g_nRptXmlRWKeysRef;
	static CRptXmlRWKeys* Create();
	static void Release();

public:
	BSTR m_strPrecisionKey;//BSTR m_strSelectKey;
	BSTR m_strBkmkKey;
	BSTR m_strAreaKey;
	BSTR m_strDataKey;
	BSTR m_strDatasKey;
	BSTR m_strItemKey;
	BSTR m_strItemsKey;
	BSTR m_strMapFileKey;	
};
