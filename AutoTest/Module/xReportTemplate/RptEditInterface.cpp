#include "StdAfx.h"
#include "RptEditInterface.h"
#include "RptItem.h"
#include "RptItems.h"
//#include "RptMapFile.h"
#include "ReportMap.h"

CRptEditInterface::CRptEditInterface(void):m_pReportMap(NULL),m_pGuideBook(NULL),m_bHasModified(FALSE),m_bSave(FALSE)
{
	m_pGuideBook = new CGuideBook;
	m_pReportMap = new CReportMap;
	m_bTreeChange = FALSE;
}

CRptEditInterface::~CRptEditInterface(void)
{
	if (m_pGuideBook != NULL)
	{
		delete m_pGuideBook;
		m_pGuideBook = NULL;
	}

	if (m_pReportMap!=NULL)
	{
		delete m_pReportMap;
		m_pReportMap = NULL;
	}
}


CExBaseObject* CRptEditInterface::FindRptBkmk(const CString & strBkmk)
{
	return m_pReportMap->FindBkmk(strBkmk);
}

//由派生类实现
long CRptEditInterface::DeleteBkmk(const CString & strBkmk)
{
	return 0;
}

long CRptEditInterface::DeleteBkmk(CExBaseObject *pObj)
{
	if (pObj->IsBaseList())
	{
		POS nPos = ((CExBaseList*)pObj)->GetHeadPosition();
		CExBaseObject* pObjTemp = NULL;

		while(nPos !=NULL)
		{
			pObjTemp = ((CExBaseList*)pObj)->GetNext(nPos);
			DeleteBkmk(pObjTemp);
		}

		CExBaseList* pParent = (CExBaseList*)pObj->GetParent();
		ASSERT(pParent != NULL);
		pParent->Delete(pObj);
	}
	else
	{
		DeleteBkmk(pObj->m_strID);
	}

	return 1;
}


long CRptEditInterface::AddBkmk(CString strBkmk)
{
	
	return 0;
}


CExBaseObject* CRptEditInterface::AddRptData(CGbItemBase *pItem, const SystemTool::IShortDataPtr& oData,long nPrecision)
{
	CRptItem* pRptItem = InsertMapItemByGbItem(pItem);
	
	ASSERT(pRptItem != NULL);
	CExBaseObject* pObj;
	CString strName,strID;
	strName = (BSTR)oData->GetName();
	strID = (BSTR)oData->GetID();
	pObj = pRptItem->FindByID(strID);

	if (pObj == NULL)
	{
		pObj = pRptItem->AddNewData(strName,strID,nPrecision);

		//设置树控件已改变，需要刷新；
		m_bTreeChange = TRUE;
	}

	return pObj;
}

CExBaseObject*  CRptEditInterface::AddRptData(CGbItemBase *pItem, const SystemTool::IValuePtr &oValue,long nPrecision)
{
	CRptItem* pRptItem = InsertMapItemByGbItem(pItem);

	ASSERT(pRptItem != NULL);
 	CString strID;
	BSTR bstr = oValue->GetID();
 	strID = bstr;
	CExBaseObject* pObj = NULL;
	pObj = pRptItem->FindByID(strID);

	if (pObj == NULL)
	{
		 pObj = pRptItem->AddNewData(L"", strID, nPrecision);

		 //设置树控件已改变，需要刷新；
		 m_bTreeChange = TRUE;
	}

	return pObj;
}

//通过GbItem查找MapItem，没有则创建
CRptItem* CRptEditInterface::InsertMapItemByGbItem(CGbItemBase* pItem)
{
	ASSERT (m_pReportMap != NULL);

	if (m_pReportMap == NULL)
	{
		return NULL;
	}

	CExBaseList listTemp;
	CGbItemBase* pParent = (CGbItemBase*) pItem->GetParent();

	while(pParent!=NULL&&pParent->GetClassID()!=GBCLASSID_GUIDEBOOK)
	{
		listTemp.AddHead(pParent);
		pParent = (CGbItemBase*)pParent->GetParent();
	}

	POS pos = listTemp.GetHeadPosition();
	CExBaseList* pRptItems= m_pReportMap;
	CExBaseList* pRptItemsTemp = NULL;
	CGbItemBase *pGbTemp = NULL;

	while (pos != NULL)
	{
		pGbTemp = (CGbItemBase*)listTemp.GetNext(pos);
		pRptItemsTemp = (CExBaseList*)pRptItems->FindByID(pGbTemp->m_strID);

		//如果Rpt结构中还没有这个节点则创建
		if (pRptItemsTemp == NULL)
		{
			pRptItemsTemp = (CExBaseList*)((CRptItems*)pRptItems)->AddNewItems(pGbTemp->m_strName, pGbTemp->m_strID);
			m_bTreeChange = TRUE;//提示树已改变，需要重新更新树，否则插入其子节点的位置将错乱。
		}

		pRptItems = pRptItemsTemp;
	}

	ASSERT (pRptItems != NULL);
	CRptItem* pRptItem = (CRptItem*)pRptItems->FindByID(pItem->m_strID);

	if (pRptItem == NULL)
	{
		pRptItem = (CRptItem*)((CRptItems*)pRptItems)->AddNewItem(pItem->m_strName,pItem->m_strID);
		m_bTreeChange = TRUE;//提示树已改变，需要重新更新树，否则插入其子节点的位置将错乱。
	}

	listTemp.RemoveAll();
	return pRptItem;
}

CRptItem* CRptEditInterface::FindMapItemByGbItem(CGbItemBase* pItem)
{
	ASSERT (m_pReportMap != NULL);

	if (m_pReportMap == NULL)
	{
		return NULL;
	}

	CExBaseList listTemp;
	CGbItemBase* pParent = (CGbItemBase*) pItem->GetParent();

	while(pParent!=NULL&&pParent->GetClassID()!=GBCLASSID_GUIDEBOOK)
	{
		listTemp.AddHead(pParent);
		pParent = (CGbItemBase*)pParent->GetParent();
	}

	POS pos = listTemp.GetHeadPosition();
	CExBaseList* pRptItems= m_pReportMap;
	CExBaseList* pRptItemsTemp = NULL;
	CGbItemBase *pGbTemp = NULL;
	BOOL bHas = TRUE;

	while (pos != NULL)
	{
		pGbTemp = (CGbItemBase*)listTemp.GetNext(pos);
		pRptItemsTemp = (CExBaseList*)pRptItems->FindByID(pGbTemp->m_strID);

		//如果Rpt结构中还没有这个节点则创建
		if (pRptItemsTemp == NULL)
		{
			bHas = FALSE;
			break;
		}

		pRptItems = pRptItemsTemp;
	}

	CRptItem* pRptItemFind = NULL;

	if (bHas &&  pRptItems != NULL)
	{
		pRptItemFind = (CRptItem*)pRptItems->FindByID(pItem->m_strID);
	}

	listTemp.RemoveAll();
	
	return pRptItemFind;
}

CExBaseObject*  CRptEditInterface::AddRptData(CGbItemBase* pItem,CString strName, CString strID, long nPrecision)
{
	CRptItem* pRptItem = InsertMapItemByGbItem(pItem);
	ASSERT(pRptItem != NULL);
	CExBaseObject* pObj = NULL;
	pObj = pRptItem->FindByID(strID);

	if (pObj == NULL)
	{
		pObj = pRptItem->AddNewData(strName,strID,nPrecision);

		//设置树控件已改变，需要刷新；
		m_bTreeChange = TRUE;
	}

	return pObj;
}

CExBaseObject*  CRptEditInterface::AddRptData(CGbItemBase* pItem, CString ID, long nPrecision)
{
	CRptItem* pRptItem = InsertMapItemByGbItem(pItem);
	ASSERT(pRptItem != NULL);
	CExBaseObject* pObj = NULL;
	pObj = pRptItem->FindByID(ID);

	if (pObj == NULL)
	{
		pObj = pRptItem->AddNewData(L"", ID, nPrecision);

		//设置树控件已改变，需要刷新；
		m_bTreeChange = TRUE;
	}

	return pObj;
}

CExBaseObject* CRptEditInterface::AddRptData(CGbItemBase* pItem,CExBaseObject* pObj, long nPrecision)
{
	CRptItem* pRptItem = InsertMapItemByGbItem(pItem);

	ASSERT(pRptItem != NULL);
	CExBaseObject* pObject = NULL;

	pObject = pRptItem->FindByID(pObj->m_strID);

	if (pObject == NULL)
	{
		pObject = pRptItem->AddNewData(pObj->m_strName, pObj->m_strID, nPrecision);

		//设置树控件已改变，需要刷新；
		m_bTreeChange = TRUE;
	}

	return pObject;
}

