#include "StdAfx.h"
#include "RptItem.h"
#include "RptData.h"
#include "RptDatas.h"
#include "RptArea.h"

CRptItem::CRptItem(void)
{
	m_pArea = NULL;
	m_pGbItemRef = NULL;
}

CRptItem::CRptItem(const CString  strName, const CString  strID, long nSelect/* = 0*/)
{
	m_pGbItemRef = NULL;
	m_pArea = NULL;
	m_strName = strName;
	m_strID = strID;
}

CRptItem::~CRptItem(void)
{
	//DeleteAll();
}

CExBaseObject* CRptItem::AddNewData(const CString  strName, const CString  strID, long nPrecision)
{
	CRptData *pRptData = new CRptData(strName, strID, nPrecision);
	ASSERT(pRptData != NULL);
	AddTail(pRptData);
	pRptData->SetParent(this);

	return pRptData;
}

CExBaseObject* CRptItem::AddNewDatas(const CString  strName, const CString  strID)
{
	CRptDatas *pRptDatas = new CRptDatas(strName, strID);
	ASSERT(pRptDatas != NULL);
	AddTail(pRptDatas);

	return pRptDatas;
}

CRptArea* CRptItem::AddArea()
{
	if (m_pArea == NULL)
	{
		m_pArea = new CRptArea();
		m_pArea->SetParent(this);
		AddTail(m_pArea);
	}

	return m_pArea;
}

CExBaseObject* CRptItem::CreateNewChild(const CString &strClassID, BOOL &bAddToTail)
{
	if (strClassID == CRptXmlRWKeys::g_pRptXmlRWKeys->m_strDataKey)
	{
		return new CRptData();
	}
	else if (strClassID == CRptXmlRWKeys::g_pRptXmlRWKeys->m_strDatasKey)
	{
		return new CRptDatas();
	}
	else if (strClassID == CRptXmlRWKeys::g_pRptXmlRWKeys->m_strItemKey)
	{
		return new CRptItem();
	}
	else if (strClassID == CRptXmlRWKeys::g_pRptXmlRWKeys->m_strAreaKey)
	{
		m_pArea =  new CRptArea();
		return m_pArea;
	}

	return NULL;
}

CExBaseObject* CRptItem::CreateNewChild(long nClassID)
{
	if(nClassID == RPTCLASSID_RPTDATA)
	{
		return new CRptData();
	}
	else if(nClassID == RPTCLASSID_RPTDATAS)
	{
		return new CRptDatas();
	}
	else if(nClassID == RPTCLASSID_RPTITEM)
	{
		return new CRptItem();
	}
	else if(nClassID == RPTCLASSID_RPTAREA)
	{
		m_pArea =  new CRptArea();
		return m_pArea;
	}

	return NULL;
}

void CRptItem::InitAfterRead()
{

}

