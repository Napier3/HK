#include "StdAfx.h"
#include "RptBkmk.h"

CRptBkmk::CRptBkmk(void)
{
	m_dwIndex = 0;
}

CRptBkmk::~CRptBkmk(void)
{
}

long CRptBkmk::XmlReadOwn(const MSXML2::IXMLDOMNodePtr &oNode, CXmlRWKeys *pXmlRWKeys)
{
	BSTR bstrID;
	bstrID = oNode->Gettext();
	m_strID = bstrID;
	m_strName = m_strID;

	GetIndexFromID();

	return 0; 
}

long CRptBkmk::XmlWriteOwn(const MSXML2::IXMLDOMDocumentPtr &oXMLDoc, const MSXML2::IXMLDOMElementPtr &oElement, CXmlRWKeys *pXmlRWKeys)
{
	BSTR bstrID = m_strID.AllocSysString();
	oElement->put_text(bstrID);
	::SysFreeString(bstrID);

	oElement->Puttext(_bstr_t(m_strID));
	return 0;
}


//缓冲区串行化
long CRptBkmk::SerializeOwn(CBinarySerialBuffer &oBinaryBuffer)
{
	CExBaseObject::SerializeOwn(oBinaryBuffer);

	if(oBinaryBuffer->IsCalSizeMode())
	{
		BinarySerializeCalLen(oBinaryBuffer,m_dwIndex);
	}
	else if(oBinaryBuffer->IsReadMode())
	{
		BinarySerializeRead(oBinaryBuffer,m_dwIndex);
	}
	else if(oBinaryBuffer->IsWriteMode())
	{
		BinarySerializeWrite(oBinaryBuffer,m_dwIndex);
	}

	return 0;
}

//CRptBkmk的Copy先不做处理 2010-07-30 zah
BOOL CRptBkmk::CopyOwn(CBaseObject* pDest)
{
	ASSERT(pDest != NULL);

	if(this == pDest)
		return TRUE;

	return TRUE;
}

CBaseObject* CRptBkmk::Clone()
{
	CRptBkmk *pNew = new CRptBkmk();
	Copy(pNew);
	return pNew;
}

CExBaseList* _FindRptBkmkByID(CExBaseList *pList, const CString &strID, CExBaseList *pListDest)
{
	ASSERT (pList != NULL);
	CRptBkmk *pBkmk = NULL;
	UINT nClassID = 0;
	
	if (pList->IsBaseObject())
	{
		return NULL;
	}

	nClassID = pList->GetClassID();

	if (nClassID == RPTCLASSID_RPTDATA  || nClassID == RPTCLASSID_RPTAREA)
	{
		pBkmk = (CRptBkmk*)pList->FindByID(strID);
		pListDest->AddTail(pBkmk);
	}
	else
	{
		POS pos = pList->GetHeadPosition();
		CExBaseList *pSubList = NULL;

		while (pos != NULL)
		{
			pSubList = (CExBaseList*)pList->GetNext(pos);
			_FindRptBkmkByID(pSubList, strID, pListDest);
		}
	}

	return pListDest;
}

void CRptBkmk::GetIndexFromID()
{
	DWORD nPos = m_strID.Find(L"_");
	DWORD nLength = m_strID.GetLength();
	CString strTemp = m_strID.Right(nLength - nPos-1);
	m_dwIndex = _wtoi(strTemp);
}