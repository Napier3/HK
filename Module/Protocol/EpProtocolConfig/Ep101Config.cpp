//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//Ep101Config.cpp  CEp101Config


#include "stdafx.h"
#include "Ep101Config.h"

CEp101Config::CEp101Config()
{
	//初始化属性
	m_nOddr = 0;
	m_nYxAddr = 0;
	m_nYcAddr = 0;
	m_nYtAddr = 0;

	//初始化成员变量
}

CEp101Config::~CEp101Config()
{
}

long CEp101Config::XmlReadOwn(const MSXML2::IXMLDOMNodePtr &oNode, CXmlRWKeys *pXmlRWKeys)
{
	CEpProtocolConfigXmlRWKeys *pXmlKeys = (CEpProtocolConfigXmlRWKeys*)pXmlRWKeys;

	xml_GetAttibuteValue(pXmlKeys->m_strOddrKey, oNode, m_nOddr);
	xml_GetAttibuteValue(pXmlKeys->m_strYxAddrKey, oNode, m_nYxAddr);
	xml_GetAttibuteValue(pXmlKeys->m_strYcAddrKey, oNode, m_nYcAddr);
	xml_GetAttibuteValue(pXmlKeys->m_strYtAddrKey, oNode, m_nYtAddr);
	return 0;
}

long CEp101Config::XmlWriteOwn(const MSXML2::IXMLDOMDocumentPtr &oXMLDoc, const MSXML2::IXMLDOMElementPtr &oElement, CXmlRWKeys *pXmlRWKeys)
{
	CEpProtocolConfigXmlRWKeys *pXmlKeys = (CEpProtocolConfigXmlRWKeys*)pXmlRWKeys;

	xml_SetAttributeValue(pXmlKeys->m_strOddrKey, oElement, m_nOddr);
	xml_SetAttributeValue(pXmlKeys->m_strYxAddrKey, oElement, m_nYxAddr);
	xml_SetAttributeValue(pXmlKeys->m_strYcAddrKey, oElement, m_nYcAddr);
	xml_SetAttributeValue(pXmlKeys->m_strYtAddrKey, oElement, m_nYtAddr);
	return 0;
}

long CEp101Config::SerializeOwn(CBinarySerialBuffer &oBinaryBuffer)
{
	if(oBinaryBuffer.IsCalSizeMode())
	{
		BinarySerializeCalLen(oBinaryBuffer, m_nOddr);
		BinarySerializeCalLen(oBinaryBuffer, m_nYxAddr);
		BinarySerializeCalLen(oBinaryBuffer, m_nYcAddr);
		BinarySerializeCalLen(oBinaryBuffer, m_nYtAddr);
	}
	else if(oBinaryBuffer.IsReadMode())
	{
		BinarySerializeRead(oBinaryBuffer, m_nOddr);
		BinarySerializeRead(oBinaryBuffer, m_nYxAddr);
		BinarySerializeRead(oBinaryBuffer, m_nYcAddr);
		BinarySerializeRead(oBinaryBuffer, m_nYtAddr);
	}
	else if(oBinaryBuffer.IsWriteMode())
	{
		BinarySerializeWrite(oBinaryBuffer, m_nOddr);
		BinarySerializeWrite(oBinaryBuffer, m_nYxAddr);
		BinarySerializeWrite(oBinaryBuffer, m_nYcAddr);
		BinarySerializeWrite(oBinaryBuffer, m_nYtAddr);
	}
	return 0;
}

void CEp101Config::InitAfterRead()
{
}

BOOL CEp101Config::IsEqualOwn(CBaseObject* pObj)
{
	if(this == pObj)
	{
		return TRUE;
	}

	CEp101Config *p = (CEp101Config*)pObj;

	if(m_nOddr != p->m_nOddr)
	{
		return FALSE;
	}

	if(m_nYxAddr != p->m_nYxAddr)
	{
		return FALSE;
	}

	if(m_nYcAddr != p->m_nYcAddr)
	{
		return FALSE;
	}

	if(m_nYtAddr != p->m_nYtAddr)
	{
		return FALSE;
	}

	return TRUE;
}

BOOL CEp101Config::CopyOwn(CBaseObject* pDest)
{
	if(this == pDest)
	{
		return TRUE;
	}

	CEp101Config *p = (CEp101Config*)pDest;

	p->m_nOddr = m_nOddr;
	p->m_nYxAddr = m_nYxAddr;
	p->m_nYcAddr = m_nYcAddr;
	p->m_nYtAddr = m_nYtAddr;
	return TRUE;
}

CBaseObject* CEp101Config::Clone()
{
	CEp101Config *p = new CEp101Config();
	Copy(p);
	return p;
}

