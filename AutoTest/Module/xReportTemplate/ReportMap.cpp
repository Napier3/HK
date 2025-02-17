#include "StdAfx.h"
#include "ReportMap.h"
#include "RptBkmk.h"
#include "RptData.h"
#include "RptDatas.h"
#include "RptItem.h"
#include "RptItems.h"

CReportMap::CReportMap(void)
:m_strFilePath(_T(""))
{
}

CReportMap::CReportMap(CString strFilePath)
:m_strFilePath(strFilePath)
{
}

CReportMap::~CReportMap(void)
{
	//DeleteAll();
}


CExBaseObject* CReportMap::FindBkmk(const CString  strBkmk)
{

	return FindBkmkInList(strBkmk ,(CExBaseList*)this);
}

void CReportMap::InsertBkmk(const CString  strBkmk)//在什么位置插入书签
{

}

CExBaseObject* CReportMap::FindItemByID(const CString  strID)//可以查找的有Items，Item，Datas，Data
{
	//return _FindTheItemByID(this, strID);
	return NULL;
}

CExBaseObject* CReportMap::FindItem(long nIndex)
{
	return NULL;
}

//与文件相关
void CReportMap::Open(const CString  strFilePath)
{
	MSXML2::IXMLDOMDocumentPtr oDoc = NULL;
	HRESULT hr = oDoc.CreateInstance(__uuidof(MSXML2::DOMDocument));

	if(!SUCCEEDED(hr)) 
	{ 
		return ;
	} 

	MSXML2::IXMLDOMNodePtr oMapFile = NULL;
	BOOL bTrue = oDoc->load(_variant_t(_bstr_t(strFilePath)));
	//strFilePath.ReleaseBuffer();

	if (!bTrue)
	{
		TRACE("\nRead RecordTest file failed......\n");
	}
	CRptXmlRWKeys::Create();
	ASSERT(CRptXmlRWKeys::g_pRptXmlRWKeys != NULL);
	oMapFile = oDoc->selectSingleNode(_bstr_t(CRptXmlRWKeys::g_pRptXmlRWKeys->m_strMapFileKey));
	
	if (oMapFile == NULL)
	{
		CRptXmlRWKeys::Release();
		return;
	}

	XmlRead(oMapFile,CRptXmlRWKeys::g_pRptXmlRWKeys);
	CRptXmlRWKeys::Release();
}

void CReportMap::SaveAs(const CString  strFilePath)
{
	m_strFilePath = strFilePath;
	Save();
}

void CReportMap::Save()
{
	MSXML2::IXMLDOMDocumentPtr oDoc = NULL;
	HRESULT hr = oDoc.CreateInstance(__uuidof(MSXML2::DOMDocument));

	if(!SUCCEEDED(hr)) 
	{ 
		return ;
	} 

	MSXML2::IXMLDOMNodePtr oMapFile = NULL;
	CRptXmlRWKeys rptXmlKeys;
	rptXmlKeys.Create();
	XmlWrite(oDoc, oMapFile, &rptXmlKeys);	
	
	oDoc->save(_bstr_t(m_strFilePath));

	rptXmlKeys.Release();
}

void CReportMap::Save(const CString  strFilePath)
{
	SaveAs(strFilePath);
}

//关联作业指导书对象，为每一个报告节点对应GbItem对象
void CReportMap::AttachGuideBook(CExBaseList *pGuideBook)
{
	m_pGuideBookRef = pGuideBook;

}

CExBaseObject* CReportMap::CreateNewChild(const CString &strClassID, BOOL &bAddToTail)
{
 	if (strClassID == CRptXmlRWKeys::g_pRptXmlRWKeys->m_strItemKey)
 	{
 		return new CRptItem();
 	}
 	else if (strClassID == CRptXmlRWKeys::g_pRptXmlRWKeys->m_strItemsKey)
 	{
 		return new CRptItems();
 	}
 	//else if (strClassID == CRptXmlRWKeys::g_pRptXmlRWKeys->m_strDataKey)
 	//{
 	//	return new CRptData();
 	//}
 	//else if (strClassID == CRptXmlRWKeys::g_pRptXmlRWKeys->m_strDatasKey)
 	//{
 	//	return new CRptDatas();
 	//}
 	else
 	{
 		return NULL;
 	}

}

CExBaseObject* CReportMap::CreateNewChild(long nClassID)
{
	if(nClassID == RPTCLASSID_RPTITEM)
	{
		return new CRptItem();
	}
	else if(nClassID == RPTCLASSID_RPTITEMS)
	{
		return new CRptItems();
	}

	return NULL;
}


CExBaseObject* CReportMap::FindBkmkInList(const CString&  strBkmk, CExBaseList* pList)
{
	ASSERT(pList != NULL);
	LONG nCount = pList->GetCount();
	CExBaseObject* pRObj = NULL;
	CExBaseObject* pObj = NULL;

	for (int i=0; i<nCount; i++)
	{
		pObj = pList->GetAt(i);

		if (pObj->IsBaseList())
		{
			pRObj = FindBkmkInList(strBkmk,(CExBaseList*)pObj);
			if (pRObj != NULL)
			{
				break;
			}
		}
		else
		{
			if (strBkmk == pObj->m_strID)
			{
				pRObj = pObj;
				break;
			}
		}
	}

	return pRObj;
}
