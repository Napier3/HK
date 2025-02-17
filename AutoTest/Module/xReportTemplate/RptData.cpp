#include "StdAfx.h"
#include "RptData.h"
#include "RptBkmk.h"


CRptData::CRptData(void)
{
	m_nPrecision = _RPTDATA_PRECISION_INIT;
	m_nDataFill = 0;
}

CRptData::CRptData(const CString  strName, const CString  strID, long nPrecision)
{
	m_strName = strName;
	m_strID = strID;
	m_nPrecision = nPrecision;
	m_nDataFill = 0;
}

CRptData::~CRptData(void)
{
	DeleteAll();
}

//新建标签对象,根据特定的规则自动生成IRptBkmk的标签
// CExBaseObject* CRptData::AddNew()
// {
// 	CRptBkmk *pRptBkmk = new CRptBkmk();
// 	ASSERT(pRptBkmk != NULL);
// 	AddTail(pRptBkmk);
// 	pRptBkmk->SetParent(this);
// 	
// 	return pRptBkmk;
// }

CExBaseObject* CRptData::AddNew2(const CString  strRptBkmk)
{
	CRptBkmk *pRptBkmk = new CRptBkmk();
	ASSERT(pRptBkmk != NULL);

	//pRptBkmk->m_strName = strRptBkmk;
	pRptBkmk->m_strID = strRptBkmk;
	pRptBkmk->m_strName = strRptBkmk;
	AddTail(pRptBkmk);
	pRptBkmk->SetParent(this);

	return pRptBkmk;
}

//ReadXML && WriteXML
long CRptData::XmlReadOwn(const MSXML2::IXMLDOMNodePtr &oNode, CXmlRWKeys *pXmlRWKeys)
{
	CExBaseObject::XmlReadOwn(oNode, pXmlRWKeys);

	xml_GetAttibuteValue(((CRptXmlRWKeys *)pXmlRWKeys)->m_strPrecisionKey, oNode, m_nPrecision);

	return 0;
}

CExBaseObject* CRptData::CreateNewChild(const CString &strClassID, BOOL &bAddToTail)
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

long CRptData::XmlWriteOwn(const MSXML2::IXMLDOMDocumentPtr &oXMLDoc, const MSXML2::IXMLDOMElementPtr &oElement, CXmlRWKeys *pXmlRWKeys)
{
	CExBaseObject::XmlWriteOwn(oXMLDoc, oElement, pXmlRWKeys);
	
	//if (m_nPrecision != _RPTDATA_PRECISION_INIT)
	//{
		xml_SetAttributeValue(((CRptXmlRWKeys *)pXmlRWKeys)->m_strPrecisionKey, oElement, m_nPrecision);
	//}
	
	return 0;
}

long CRptData::SerializeOwn(CBinarySerialBuffer &oBinaryBuffer)
{
	CExBaseObject::SerializeOwn(oBinaryBuffer);

	if(oBinaryBuffer->IsCalSizeMode())
	{
		BinarySerializeCalLen(oBinaryBuffer,m_nPrecision);
		BinarySerializeCalLen(oBinaryBuffer,m_strDataType);
		BinarySerializeCalLen(oBinaryBuffer,m_nDataFill);
	}
	else if(oBinaryBuffer->IsReadMode())
	{
		BinarySerializeRead(oBinaryBuffer,m_nPrecision);
		BinarySerializeRead(oBinaryBuffer,m_strDataType);
		BinarySerializeRead(oBinaryBuffer,m_nDataFill);
	}
	else if(oBinaryBuffer->IsWriteMode())
	{
		BinarySerializeWrite(oBinaryBuffer,m_nPrecision);
		BinarySerializeWrite(oBinaryBuffer,m_strDataType);
		BinarySerializeWrite(oBinaryBuffer,m_nDataFill);
	}

	return 0;
}

CExBaseObject* CRptData::CreateNewChild(long nClassID)
{
	if(nClassID == RPTCLASSID_RPTBKMK)
	{
		return new CRptBkmk();
	}

	return NULL;
}