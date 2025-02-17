#include "StdAfx.h"
#include "RptArea.h"
#include "RptBkmk.h"


CRptArea::CRptArea(void)
{
	m_pBkmkBegin = NULL;
	m_pBkmkEnd = NULL;
	m_strName = L"区域定义";
	m_strID = L"Area";
}

CRptArea::~CRptArea(void)
{
	DeleteAll();
}

//新建标签对象,根据特定的规则自动生成IRptBkmk的标签
// CExBaseObject* CRptArea::AddNew()
// {
// 	CRptBkmk *pRptBkmk = new CRptBkmk();
// 	ASSERT(pRptBkmk != NULL);
// 	AddTail(pRptBkmk);
// 	pRptBkmk->SetParent(this);
// 	
// 	return pRptBkmk;
// }
// 
// CExBaseObject* CRptArea::AddNew2(const CString  strRptBkmk)
// {
// 	CRptBkmk *pRptBkmk = new CRptBkmk();
// 	ASSERT(pRptBkmk != NULL);
// 
// 	//pRptBkmk->m_strName = strRptBkmk;
// 	pRptBkmk->m_strID = strRptBkmk;
// 	AddTail(pRptBkmk);
// 	pRptBkmk->SetParent(this);
// 
// 	return pRptBkmk;
// }

//ReadXML && WriteXML
long CRptArea::XmlReadOwn(const MSXML2::IXMLDOMNodePtr &oNode, CXmlRWKeys *pXmlRWKeys)
{
	CExBaseObject::XmlReadOwn(oNode, pXmlRWKeys);

	return 0;
}

CExBaseObject* CRptArea::CreateNewChild(const CString &strClassID, BOOL &bAddToTail)
{
	if (strClassID == CRptXmlRWKeys::g_pRptXmlRWKeys->m_strBkmkKey)
	{
		return new CRptBkmk();
	}
	else
	{
		return NULL;
	}

}

long CRptArea::XmlWriteOwn(const MSXML2::IXMLDOMDocumentPtr &oXMLDoc, const MSXML2::IXMLDOMElementPtr &oElement, CXmlRWKeys *pXmlRWKeys)
{
	CExBaseObject::XmlWriteOwn(oXMLDoc, oElement, pXmlRWKeys);
		
	return 0;
}

long CRptArea::SerializeOwn(CBinarySerialBuffer &oBinaryBuffer)
{
	CExBaseObject::SerializeOwn(oBinaryBuffer);

// 	if(oBinaryBuffer->IsCalSizeMode())
// 	{
// 		BinarySerializeCalLen(oBinaryBuffer,m_nPrecision);
// 		BinarySerializeCalLen(oBinaryBuffer,m_strDataType);
// 	}
// 	else if(oBinaryBuffer->IsReadMode())
// 	{
// 		BinarySerializeRead(oBinaryBuffer,m_nPrecision);
// 		BinarySerializeRead(oBinaryBuffer,m_strDataType);
// 	}
// 	else if(oBinaryBuffer->IsWriteMode())
// 	{
// 		BinarySerializeWrite(oBinaryBuffer,m_nPrecision);
// 		BinarySerializeWrite(oBinaryBuffer,m_strDataType);
// 	}

	return 0;
}

CExBaseObject* CRptArea::CreateNewChild(long nClassID)
{
	if(nClassID == RPTCLASSID_RPTBKMK)
	{
		return new CRptBkmk();
	}

	return NULL;
}

void CRptArea::InitAfterRead()
{
	if (GetCount() != 2)
	{
		return;
	}

	m_pBkmkBegin = (CRptBkmk*)GetHead();
	m_pBkmkEnd = (CRptBkmk*)GetTail();
}

