//这段源代码由ClassGenerator创建
//版权所有 Eric  Eric1224@126.com
//保留所有权利

//RptTemp_Cell.cpp  CRptTemp_Cell


#include "stdafx.h"
#include "RptTemp_Cell.h"

#ifdef _DEBUG
#undef THIS_FILE
	static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CRptTemp_Cell::CRptTemp_Cell()
{
	//初始化属性
	m_nRow_Span = 1;
	m_nCol_Span = 1;

	//初始化成员变量
}

CRptTemp_Cell::~CRptTemp_Cell()
{
}

long CRptTemp_Cell::XmlReadOwn(CXmlRWNodeBase &oNode, CXmlRWKeys *pXmlRWKeys)
{
	CTestMacroRptTemplateXmlRWKeys *pXmlKeys = (CTestMacroRptTemplateXmlRWKeys*)pXmlRWKeys;

	xml_GetAttibuteValue(pXmlKeys->m_strRow_SpanKey, oNode, m_nRow_Span);
	xml_GetAttibuteValue(pXmlKeys->m_strCol_SpanKey, oNode, m_nCol_Span);
	xml_GetAttibuteValue(pXmlKeys->m_strTextKey, oNode, m_strText);
	xml_GetAttibuteValue(pXmlKeys->m_strData_PathKey, oNode, m_strData_Path);
	xml_GetAttibuteValue(pXmlKeys->m_strTypeKey, oNode, m_strType);
	return 0;
}

long CRptTemp_Cell::XmlWriteOwn(CXmlRWDocBase &oXMLDoc, CXmlRWElementBase &oElement, CXmlRWKeys *pXmlRWKeys)
{
	CTestMacroRptTemplateXmlRWKeys *pXmlKeys = (CTestMacroRptTemplateXmlRWKeys*)pXmlRWKeys;

	if (m_nRow_Span > 1)
	{
		xml_SetAttributeValue(pXmlKeys->m_strRow_SpanKey, oElement, m_nRow_Span);
	}

	if (m_nCol_Span > 1)
	{
		xml_SetAttributeValue(pXmlKeys->m_strCol_SpanKey, oElement, m_nCol_Span);
	}
	
	xml_SetAttributeValue(pXmlKeys->m_strTextKey, oElement, m_strText);
	//xml_SetAttributeValue(pXmlKeys->m_strData_PathKey, oElement, m_strData_Path);
	//xml_SetAttributeValue(pXmlKeys->m_strTypeKey, oElement, m_strType);
	return 0;
}

long CRptTemp_Cell::SerializeOwn(CBinarySerialBuffer &oBinaryBuffer)
{
	if(oBinaryBuffer.IsCalSizeMode())
	{
		BinarySerializeCalLen(oBinaryBuffer, m_nRow_Span);
		BinarySerializeCalLen(oBinaryBuffer, m_nCol_Span);
		BinarySerializeCalLen(oBinaryBuffer, m_strText);
		BinarySerializeCalLen(oBinaryBuffer, m_strData_Path);
		BinarySerializeCalLen(oBinaryBuffer, m_strType);
	}
	else if(oBinaryBuffer.IsReadMode())
	{
		BinarySerializeRead(oBinaryBuffer, m_nRow_Span);
		BinarySerializeRead(oBinaryBuffer, m_nCol_Span);
		BinarySerializeRead(oBinaryBuffer, m_strText);
		BinarySerializeRead(oBinaryBuffer, m_strData_Path);
		BinarySerializeRead(oBinaryBuffer, m_strType);
	}
	else if(oBinaryBuffer.IsWriteMode())
	{
		BinarySerializeWrite(oBinaryBuffer, m_nRow_Span);
		BinarySerializeWrite(oBinaryBuffer, m_nCol_Span);
		BinarySerializeWrite(oBinaryBuffer, m_strText);
		BinarySerializeWrite(oBinaryBuffer, m_strData_Path);
		BinarySerializeWrite(oBinaryBuffer, m_strType);
	}
	return 0;
}

void CRptTemp_Cell::InitAfterRead()
{
}

BOOL CRptTemp_Cell::IsEqualOwn(CBaseObject* pObj)
{
	if(this == pObj)
	{
		return TRUE;
	}

	CRptTemp_Cell *p = (CRptTemp_Cell*)pObj;

	if(m_nRow_Span != p->m_nRow_Span)
	{
		return FALSE;
	}

	if(m_nCol_Span != p->m_nCol_Span)
	{
		return FALSE;
	}

	if(m_strText != p->m_strText)
	{
		return FALSE;
	}

	if(m_strData_Path != p->m_strData_Path)
	{
		return FALSE;
	}

	if(m_strType != p->m_strType)
	{
		return FALSE;
	}

	return TRUE;
}

BOOL CRptTemp_Cell::CopyOwn(CBaseObject* pDest)
{
	if(this == pDest)
	{
		return TRUE;
	}

	CRptTemp_Cell *p = (CRptTemp_Cell*)pDest;

	p->m_nRow_Span = m_nRow_Span;
	p->m_nCol_Span = m_nCol_Span;
	p->m_strText = m_strText;
	p->m_strData_Path = m_strData_Path;
	p->m_strType = m_strType;
	return TRUE;
}

CBaseObject* CRptTemp_Cell::Clone()
{
	CRptTemp_Cell *p = new CRptTemp_Cell();
	Copy(p);
	return p;
}

CBaseObject* CRptTemp_Cell::CloneEx(BOOL bCopyOwn/*=TRUE*/, BOOL bCopyChildren/*=FALSE*/)
{
	CRptTemp_Cell *p = new CRptTemp_Cell();
	CopyEx(p, bCopyOwn, bCopyChildren);
	return p;
}

