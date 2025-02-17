//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//RptTemp_Text.cpp  CRptTemp_Text


#include "stdafx.h"
#include "RptTemp_Text.h"

#ifdef _DEBUG
#undef THIS_FILE
	static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CRptTemp_Text::CRptTemp_Text()
{
	//初始化属性

	//初始化成员变量
}

CRptTemp_Text::~CRptTemp_Text()
{
}

long CRptTemp_Text::XmlReadOwn(CXmlRWNodeBase &oNode, CXmlRWKeys *pXmlRWKeys)
{
	CTestMacroRptTemplateXmlRWKeys *pXmlKeys = (CTestMacroRptTemplateXmlRWKeys*)pXmlRWKeys;

	xml_GetAttibuteValue(pXmlKeys->m_strTextKey, oNode, m_strText);

	return 0;
}

long CRptTemp_Text::XmlWriteOwn(CXmlRWDocBase &oXMLDoc, CXmlRWElementBase &oElement, CXmlRWKeys *pXmlRWKeys)
{
	CTestMacroRptTemplateXmlRWKeys *pXmlKeys = (CTestMacroRptTemplateXmlRWKeys*)pXmlRWKeys;

	xml_SetAttributeValue(pXmlKeys->m_strTextKey, oElement, m_strText);

	return 0;
}

long CRptTemp_Text::SerializeOwn(CBinarySerialBuffer &oBinaryBuffer)
{
	if(oBinaryBuffer.IsCalSizeMode())
	{
		BinarySerializeCalLen(oBinaryBuffer, m_strText);
	}
	else if(oBinaryBuffer.IsReadMode())
	{
		BinarySerializeRead(oBinaryBuffer, m_strText);
	}
	else if(oBinaryBuffer.IsWriteMode())
	{
		BinarySerializeWrite(oBinaryBuffer, m_strText);
	}
	return 0;
}

void CRptTemp_Text::InitAfterRead()
{
}

BOOL CRptTemp_Text::IsEqualOwn(CBaseObject* pObj)
{
	if(this == pObj)
	{
		return TRUE;
	}

	CRptTemp_Text *p = (CRptTemp_Text*)pObj;

	if(m_strText != p->m_strText)
	{
		return FALSE;
	}

	return TRUE;
}

BOOL CRptTemp_Text::CopyOwn(CBaseObject* pDest)
{
	if(this == pDest)
	{
		return TRUE;
	}

	CRptTemp_Text *p = (CRptTemp_Text*)pDest;

	p->m_strText = m_strText;
	return TRUE;
}

CBaseObject* CRptTemp_Text::Clone()
{
	CRptTemp_Text *p = new CRptTemp_Text();
	Copy(p);
	return p;
}

CBaseObject* CRptTemp_Text::CloneEx(BOOL bCopyOwn/*=TRUE*/, BOOL bCopyChildren/*=FALSE*/)
{
	CRptTemp_Text *p = new CRptTemp_Text();
	CopyEx(p, bCopyOwn, bCopyChildren);
	return p;
}

