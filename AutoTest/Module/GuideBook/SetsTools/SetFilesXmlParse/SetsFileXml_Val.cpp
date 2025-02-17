//���Դ������ClassGenerator����
//��Ȩ���� LiJunqing  lijunqing1224@126.com
//��������Ȩ��

//SetsFileXml_Val.cpp  CSetsFileXml_Val


#include "stdafx.h"
#include "SetsFileXml_Val.h"

#ifdef _DEBUG
#undef THIS_FILE
	static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CSetsFileXml_Val::CSetsFileXml_Val()
{
	//��ʼ������
	//����װ�ò�����ѹ�����ݼ����ǵ�����ֵ��û�ж��嶨ֵ���ţ�
	//�˴���Ҫ����ֵ����Ĭ��Ϊ1��
	m_nGrp = 1;

	//��ʼ����Ա����
}

CSetsFileXml_Val::~CSetsFileXml_Val()
{
}

long CSetsFileXml_Val::XmlReadOwn(CXmlRWNodeBase &oNode, CXmlRWKeys *pXmlRWKeys)
{
	CSetFileXmlParseXmlRWKeys *pXmlKeys = (CSetFileXmlParseXmlRWKeys*)pXmlRWKeys;

	xml_GetAttibuteValue(pXmlKeys->m_strGrpKey, oNode, m_nGrp);
	xml_GetCDATA(oNode, m_strVal);
	return 0;
}

long CSetsFileXml_Val::XmlWriteOwn(CXmlRWDocBase &oXMLDoc, CXmlRWElementBase &oElement, CXmlRWKeys *pXmlRWKeys)
{
	CSetFileXmlParseXmlRWKeys *pXmlKeys = (CSetFileXmlParseXmlRWKeys*)pXmlRWKeys;

	xml_SetAttributeValue(pXmlKeys->m_strGrpKey, oElement, m_nGrp);
	xml_SetCDATA(oXMLDoc,oElement, m_strVal);
	return 0;
}

long CSetsFileXml_Val::SerializeOwn(CBinarySerialBuffer &oBinaryBuffer)
{
	if(oBinaryBuffer.IsCalSizeMode())
	{
		BinarySerializeCalLen(oBinaryBuffer, m_nGrp);
		BinarySerializeCalLen(oBinaryBuffer, m_strVal);
	}
	else if(oBinaryBuffer.IsReadMode())
	{
		BinarySerializeRead(oBinaryBuffer, m_nGrp);
		BinarySerializeRead(oBinaryBuffer, m_strVal);
	}
	else if(oBinaryBuffer.IsWriteMode())
	{
		BinarySerializeWrite(oBinaryBuffer, m_nGrp);
		BinarySerializeWrite(oBinaryBuffer, m_strVal);
	}
	return 0;
}

void CSetsFileXml_Val::InitAfterRead()
{
}

BOOL CSetsFileXml_Val::IsEqualOwn(CBaseObject* pObj)
{
	if(this == pObj)
	{
		return TRUE;
	}

	CSetsFileXml_Val *p = (CSetsFileXml_Val*)pObj;

	if(m_nGrp != p->m_nGrp)
	{
		return FALSE;
	}

	if(m_strVal != p->m_strVal)
	{
		return FALSE;
	}

	return TRUE;
}

BOOL CSetsFileXml_Val::CopyOwn(CBaseObject* pDest)
{
	if(this == pDest)
	{
		return TRUE;
	}

	CSetsFileXml_Val *p = (CSetsFileXml_Val*)pDest;

	p->m_nGrp = m_nGrp;
	p->m_strVal = m_strVal;
	return TRUE;
}

CBaseObject* CSetsFileXml_Val::Clone()
{
	CSetsFileXml_Val *p = new CSetsFileXml_Val();
	Copy(p);
	return p;
}

CBaseObject* CSetsFileXml_Val::CloneEx(BOOL bCopyOwn/*=TRUE*/, BOOL bCopyChildren/*=FALSE*/)
{
	CSetsFileXml_Val *p = new CSetsFileXml_Val();
	CopyEx(p, bCopyOwn, bCopyChildren);
	return p;
}

