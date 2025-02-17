#include "StdAfx.h"
#include "RptDatas.h"
#include "RptData.h"

CRptDatas::CRptDatas(void)
{
}

CRptDatas::CRptDatas(CString  strName, CString  strID)
{
	m_strName = strName;
	m_strID = strID;
}

CRptDatas::~CRptDatas(void)
{
	//DeleteAll();
}

CExBaseObject* CRptDatas::AddNew(const CString  strName,const CString  strID,const long nPrecision)
{
	CRptData *pRptData = new CRptData(strName,strID,nPrecision);
	ASSERT(pRptData != NULL);
	AddTail(pRptData);
	pRptData->SetParent(this);

	return pRptData;
}

CExBaseObject* CRptDatas::CreateNewChild(const CString &strClassID, BOOL &bAddToTail)
{
	if (strClassID == CRptXmlRWKeys::g_pRptXmlRWKeys->m_strDataKey)
	{
		return new CRptData();
	}
	else
	{
		return NULL;
	}
}

CExBaseObject* CRptDatas::CreateNewChild(long nClassID)
{
	if(nClassID == RPTCLASSID_RPTDATAS)
	{
		return new CRptData();
	}
	
	return NULL;
}