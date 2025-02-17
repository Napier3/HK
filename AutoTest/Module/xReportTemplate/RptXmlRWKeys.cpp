#include "StdAfx.h"
#include "RptXmlRWKeys.h"

CRptXmlRWKeys* CRptXmlRWKeys::g_pRptXmlRWKeys = NULL;
long  CRptXmlRWKeys::g_nRptXmlRWKeysRef = 0;

CRptXmlRWKeys::CRptXmlRWKeys(void)
{
	m_strPrecisionKey = _T("precision");//m_strSelectKey = _T("Select");
	m_strBkmkKey = _T("bkmk");
	m_strAreaKey = _T("Area");
	m_strDataKey = _T("Data");
	m_strDatasKey = _T("Datas");
	m_strItemKey = _T("Item");
	m_strItemsKey = _T("Items");
	m_strMapFileKey = _T("ReportMap");	
}

CRptXmlRWKeys::~CRptXmlRWKeys(void)
{
}

CRptXmlRWKeys* CRptXmlRWKeys::Create()
{
	g_nRptXmlRWKeysRef++;

	if (g_pRptXmlRWKeys == NULL)
	{
		g_pRptXmlRWKeys = new CRptXmlRWKeys();
	}

	return g_pRptXmlRWKeys;
}

void CRptXmlRWKeys::Release()
{
	g_nRptXmlRWKeysRef--;

	if (g_nRptXmlRWKeysRef == 0)
	{
		delete g_pRptXmlRWKeys;
		g_pRptXmlRWKeys = NULL;
	}
}