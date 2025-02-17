//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//SetsFileXml_Remark.cpp  CSetsFileXml_Remark


#include "stdafx.h"
#include "SetsFileXml_Remark.h"

#ifdef _DEBUG
#undef THIS_FILE
	static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CSetsFileXml_Remark::CSetsFileXml_Remark()
{
	//初始化属性
	m_nItemNum = 0;

	//初始化成员变量
}

CSetsFileXml_Remark::~CSetsFileXml_Remark()
{
}

long CSetsFileXml_Remark::XmlReadOwn(CXmlRWNodeBase &oNode, CXmlRWKeys *pXmlRWKeys)
{
	CSetFileXmlParseXmlRWKeys *pXmlKeys = (CSetFileXmlParseXmlRWKeys*)pXmlRWKeys;

	xml_GetAttibuteValue(pXmlKeys->m_strItemNumKey, oNode, m_nItemNum);
	xml_GetAttibuteValue(pXmlKeys->m_strMd5Key, oNode, m_strmd5);
	return 0;
}

long CSetsFileXml_Remark::XmlWriteOwn(CXmlRWDocBase &oXMLDoc, CXmlRWElementBase &oElement, CXmlRWKeys *pXmlRWKeys)
{
	CSetFileXmlParseXmlRWKeys *pXmlKeys = (CSetFileXmlParseXmlRWKeys*)pXmlRWKeys;

	xml_SetAttributeValue(pXmlKeys->m_strItemNumKey, oElement, m_nItemNum);
	xml_SetAttributeValue(pXmlKeys->m_strMd5Key, oElement, m_strmd5);
	return 0;
}

long CSetsFileXml_Remark::SerializeOwn(CBinarySerialBuffer &oBinaryBuffer)
{
	if(oBinaryBuffer.IsCalSizeMode())
	{
		BinarySerializeCalLen(oBinaryBuffer, m_nItemNum);
		BinarySerializeCalLen(oBinaryBuffer, m_strmd5);
	}
	else if(oBinaryBuffer.IsReadMode())
	{
		BinarySerializeRead(oBinaryBuffer, m_nItemNum);
		BinarySerializeRead(oBinaryBuffer, m_strmd5);
	}
	else if(oBinaryBuffer.IsWriteMode())
	{
		BinarySerializeWrite(oBinaryBuffer, m_nItemNum);
		BinarySerializeWrite(oBinaryBuffer, m_strmd5);
	}
	return 0;
}

void CSetsFileXml_Remark::InitAfterRead()
{
}

BOOL CSetsFileXml_Remark::IsEqualOwn(CBaseObject* pObj)
{
	if(this == pObj)
	{
		return TRUE;
	}

	CSetsFileXml_Remark *p = (CSetsFileXml_Remark*)pObj;

	if(m_nItemNum != p->m_nItemNum)
	{
		return FALSE;
	}

	if(m_strmd5 != p->m_strmd5)
	{
		return FALSE;
	}

	return TRUE;
}

BOOL CSetsFileXml_Remark::CopyOwn(CBaseObject* pDest)
{
	if(this == pDest)
	{
		return TRUE;
	}

	CSetsFileXml_Remark *p = (CSetsFileXml_Remark*)pDest;

	p->m_nItemNum = m_nItemNum;
	p->m_strmd5 = m_strmd5;
	return TRUE;
}

CBaseObject* CSetsFileXml_Remark::Clone()
{
	CSetsFileXml_Remark *p = new CSetsFileXml_Remark();
	Copy(p);
	return p;
}

CBaseObject* CSetsFileXml_Remark::CloneEx(BOOL bCopyOwn/*=TRUE*/, BOOL bCopyChildren/*=FALSE*/)
{
	CSetsFileXml_Remark *p = new CSetsFileXml_Remark();
	CopyEx(p, bCopyOwn, bCopyChildren);
	return p;
}

BOOL CSetsFileXml_Remark::CanPaste(UINT nClassID)
{
	if (nClassID == MNGRCLASSID_CSETSFILEXML_RI)
	{
		return TRUE;
	}

	return FALSE;
}

CExBaseObject* CSetsFileXml_Remark::CreateNewChild(const CString &strClassID, BOOL &bAddToTail, CXmlRWKeys *pXmlRWKeys)
{
	CExBaseObject *pNew  = NULL;
	CSetFileXmlParseXmlRWKeys *pXmlKeys = (CSetFileXmlParseXmlRWKeys*)pXmlRWKeys;


	if (strClassID == pXmlKeys->m_strCSetsFileXml_RIKey)
	{
		pNew = new CSetsFileXml_RI();
	}

	return pNew;
}

CExBaseObject* CSetsFileXml_Remark::CreateNewChild(long nClassID/*, BOOL &bAddToTail*/)
{
	CExBaseObject *pNew  = NULL;


	if (nClassID == MNGRCLASSID_CSETSFILEXML_RI)
	{
		pNew = new CSetsFileXml_RI();
	}

	return pNew;
}
