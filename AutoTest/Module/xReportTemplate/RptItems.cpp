#include "StdAfx.h"
#include "RptItems.h"
#include "RptItem.h"
#include "RptData.h"
#include "RptDatas.h"
#include "RptArea.h"

CRptItems::CRptItems(void)
{
	m_pArea = NULL;
}

CRptItems::CRptItems(const CString  strName, const CString  strID)
{
	m_pArea = NULL;
	m_strName = strName;
	m_strID = strID;
}

CRptItems::~CRptItems(void)
{
	//DeleteAll();
}

CExBaseObject* CRptItems::AddNewItem(const CString  strName, const CString  strID)
{
	CRptItem *pRptItem = new CRptItem(strName, strID);
	ASSERT(pRptItem != NULL);
	AddTail(pRptItem);
	pRptItem->SetParent(this);

	return pRptItem;
}

CExBaseObject* CRptItems::AddNewItems(const CString  strName, const CString  strID)
{
	CRptItems *pRptItems = new CRptItems(strName, strID);
	ASSERT(pRptItems != NULL);
	AddTail(pRptItems);
	pRptItems->SetParent(this);

	return pRptItems;
}

CExBaseObject* CRptItems::CreateNewChild(const CString &strClassID, BOOL &bAddToTail)
{
	if (strClassID == CRptXmlRWKeys::g_pRptXmlRWKeys->m_strItemKey)
	{
		return new CRptItem();
	}
	else if (strClassID == CRptXmlRWKeys::g_pRptXmlRWKeys->m_strItemsKey)
	{
		return new CRptItems();
	}
	else if (strClassID == CRptXmlRWKeys::g_pRptXmlRWKeys->m_strDataKey)
	{
		return new CRptData();
	}
	else if (strClassID == CRptXmlRWKeys::g_pRptXmlRWKeys->m_strDatasKey)
	{
		return new CRptDatas();
	}
	else if (strClassID == CRptXmlRWKeys::g_pRptXmlRWKeys->m_strAreaKey)
	{
		m_pArea =  new CRptArea();
		return m_pArea;
	}

	return NULL;
}

CExBaseObject* CRptItems::CreateNewChild(long nClassID)
{
	if(nClassID == RPTCLASSID_RPTITEM)
	{
		return new CRptItem();
	}
	else if(nClassID == RPTCLASSID_RPTITEMS)
	{
		return new CRptItems();
	}
	else if(nClassID == RPTCLASSID_RPTDATA)
	{
		return new CRptData();
	}
	else if(nClassID == RPTCLASSID_RPTDATAS)
	{
		return new CRptDatas();
	}
	else if(nClassID == RPTCLASSID_RPTAREA)
	{
		m_pArea =  new CRptArea();
		return m_pArea;
	}

	return NULL;
}

void CRptItems::InitAfterRead()
{
	
}

