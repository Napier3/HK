//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//SetsFileXml_Settings.cpp  CSetsFileXml_Settings


#include "stdafx.h"
#include "SetsFileXml_Settings.h"

#include "..\..\..\..\..\Module\API\Xmd5.h"
#include "..\..\..\..\..\Module\API\StringConvert\String_Gbk_To_Utf8.h"

#ifdef _DEBUG
#undef THIS_FILE
	static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CSetsFileXml_Settings::CSetsFileXml_Settings()
{
	//初始化属性
	m_nInfoGrpNum = 0;
	//由于装置参数和压板数据集，是单区定值。没有定义定值区号；
	//此处需要将定值区号默认为1；
	m_nGrp = 1;

	//初始化成员变量
}

CSetsFileXml_Settings::~CSetsFileXml_Settings()
{
}

long CSetsFileXml_Settings::XmlReadOwn(CXmlRWNodeBase &oNode, CXmlRWKeys *pXmlRWKeys)
{
	CSetFileXmlParseXmlRWKeys *pXmlKeys = (CSetFileXmlParseXmlRWKeys*)pXmlRWKeys;

	xml_GetAttibuteValue(pXmlKeys->m_strLdKey, oNode, m_strLd);
	xml_GetAttibuteValue(pXmlKeys->m_strClassKey, oNode, m_strClass);
	xml_GetAttibuteValue(pXmlKeys->m_strInfoGrpNumKey, oNode, m_nInfoGrpNum);
	xml_GetAttibuteValue(pXmlKeys->m_strGrpKey, oNode, m_nGrp);
	return 0;
}

long CSetsFileXml_Settings::XmlWriteOwn(CXmlRWDocBase &oXMLDoc, CXmlRWElementBase &oElement, CXmlRWKeys *pXmlRWKeys)
{
	CSetFileXmlParseXmlRWKeys *pXmlKeys = (CSetFileXmlParseXmlRWKeys*)pXmlRWKeys;

	xml_SetAttributeValue(pXmlKeys->m_strLdKey, oElement, m_strLd);
	xml_SetAttributeValue(pXmlKeys->m_strClassKey, oElement, m_strClass);
	xml_SetAttributeValue(pXmlKeys->m_strInfoGrpNumKey, oElement, m_nInfoGrpNum);
	xml_SetAttributeValue(pXmlKeys->m_strGrpKey, oElement, m_nGrp);
	return 0;
}

long CSetsFileXml_Settings::SerializeOwn(CBinarySerialBuffer &oBinaryBuffer)
{
	if(oBinaryBuffer.IsCalSizeMode())
	{
		BinarySerializeCalLen(oBinaryBuffer, m_strLd);
		BinarySerializeCalLen(oBinaryBuffer, m_strClass);
		BinarySerializeCalLen(oBinaryBuffer, m_nInfoGrpNum);
		BinarySerializeCalLen(oBinaryBuffer, m_nGrp);
	}
	else if(oBinaryBuffer.IsReadMode())
	{
		BinarySerializeRead(oBinaryBuffer, m_strLd);
		BinarySerializeRead(oBinaryBuffer, m_strClass);
		BinarySerializeRead(oBinaryBuffer, m_nInfoGrpNum);
		BinarySerializeRead(oBinaryBuffer, m_nGrp);
	}
	else if(oBinaryBuffer.IsWriteMode())
	{
		BinarySerializeWrite(oBinaryBuffer, m_strLd);
		BinarySerializeWrite(oBinaryBuffer, m_strClass);
		BinarySerializeWrite(oBinaryBuffer, m_nInfoGrpNum);
		BinarySerializeWrite(oBinaryBuffer, m_nGrp);
	}
	return 0;
}

void CSetsFileXml_Settings::InitAfterRead()
{
}

BOOL CSetsFileXml_Settings::IsEqualOwn(CBaseObject* pObj)
{
	if(this == pObj)
	{
		return TRUE;
	}

	CSetsFileXml_Settings *p = (CSetsFileXml_Settings*)pObj;

	if(m_strLd != p->m_strLd)
	{
		return FALSE;
	}

	if(m_strClass != p->m_strClass)
	{
		return FALSE;
	}

	if(m_nInfoGrpNum != p->m_nInfoGrpNum)
	{
		return FALSE;
	}

	if(m_nGrp != p->m_nGrp)
	{
		return FALSE;
	}

	return TRUE;
}

BOOL CSetsFileXml_Settings::CopyOwn(CBaseObject* pDest)
{
	if(this == pDest)
	{
		return TRUE;
	}

	CSetsFileXml_Settings *p = (CSetsFileXml_Settings*)pDest;

	p->m_strLd = m_strLd;
	p->m_strClass = m_strClass;
	p->m_nInfoGrpNum = m_nInfoGrpNum;
	p->m_nGrp = m_nGrp;
	return TRUE;
}

CBaseObject* CSetsFileXml_Settings::Clone()
{
	CSetsFileXml_Settings *p = new CSetsFileXml_Settings();
	Copy(p);
	return p;
}

CBaseObject* CSetsFileXml_Settings::CloneEx(BOOL bCopyOwn/*=TRUE*/, BOOL bCopyChildren/*=FALSE*/)
{
	CSetsFileXml_Settings *p = new CSetsFileXml_Settings();
	CopyEx(p, bCopyOwn, bCopyChildren);
	return p;
}

BOOL CSetsFileXml_Settings::CanPaste(UINT nClassID)
{
	if (nClassID == MNGRCLASSID_CSETSFILEXML_INFOGRP)
	{
		return TRUE;
	}

	return FALSE;
}

CExBaseObject* CSetsFileXml_Settings::CreateNewChild(const CString &strClassID, BOOL &bAddToTail, CXmlRWKeys *pXmlRWKeys)
{
	CExBaseObject *pNew  = NULL;
	CSetFileXmlParseXmlRWKeys *pXmlKeys = (CSetFileXmlParseXmlRWKeys*)pXmlRWKeys;


	if (strClassID == pXmlKeys->m_strCSetsFileXml_InfoGrpKey)
	{
		pNew = new CSetsFileXml_InfoGrp();
	}

	return pNew;
}

CExBaseObject* CSetsFileXml_Settings::CreateNewChild(long nClassID/*, BOOL &bAddToTail*/)
{
	CExBaseObject *pNew  = NULL;


	if (nClassID == MNGRCLASSID_CSETSFILEXML_INFOGRP)
	{
		pNew = new CSetsFileXml_InfoGrp();
	}

	return pNew;
}

void CSetsFileXml_Settings::ParseToDvm(CDvmLogicDevice *pLDevice)
{
	//long nGrp = 1;   //定值区号
	CString strName;
 	if (m_strClass == SETTING_CLASS_SETTING)
 	{
 		strName = _T("保护定值");
 	}
 
 	if (m_strClass == SETTING_CLASS_PARAMETER)
 	{
 		strName = _T("设备参数");
 	}
 
 	if (m_strClass == SETTING_CLASS_RELAYENA)
 	{
 		strName = _T("软压板");
 	}
	
	//定值数据集，是多区定值，装置参数和功能软压板数据集，是单区定值
	//单区定值，不定义定值区号
	//但为了后续代码一致性，构造函数中，将单区定值的定值区号，默认为1
	CDvmDataset *pDataset = new CDvmDataset;
	pLDevice->AddNewChild(pDataset);
	pDataset->m_strID = m_strClass;
	pDataset->m_strName = strName;

	POS pos = GetHeadPosition();
	CSetsFileXml_InfoGrp *pInfoGrp = NULL;

	while (pos != NULL)
	{
		pInfoGrp = (CSetsFileXml_InfoGrp *)GetNext(pos);
		pInfoGrp->ParseToDvm(pDataset, m_nGrp);
	}
}

//将定值数据，拼接成一个大字符串返回，用于计算Md5值
void CSetsFileXml_Settings::GetValStringTotal(CString &strValTotal)
{
	strValTotal.Empty();
	CString strVal;

	POS pos = GetHeadPosition();
	CSetsFileXml_InfoGrp *pInfoGrp = NULL;

	while (pos != NULL)
	{
		pInfoGrp = (CSetsFileXml_InfoGrp *)GetNext(pos);
		pInfoGrp->GetValStringTotal(m_nGrp, strVal);
		strValTotal.AppendFormat(_T("%s"), strVal);
	}

	CString strMd5;
	GetMd5_ForCal(strMd5, strValTotal);
}

void CSetsFileXml_Settings::GetMd5_ForCal(CString &strMd5, const CString &strValTotal)
{
	if (m_strMd5_Cal.GetLength() > 0)
	{
		strMd5 = m_strMd5_Cal;
		return;
	}

	char *pchVal = NULL;
	char *pszUtf8 = NULL;
	int nSize = CString_to_char(strValTotal,&pchVal);
	int nDestLen = 0;
	gbk_to_utf8_r((unsigned char*)pchVal, nSize, (unsigned char**)&pszUtf8, &nDestLen, 0);

	CXMD5 oMD5;
	oMD5.update(pszUtf8, nDestLen);
	string str = oMD5.toString();
	strMd5 = str.c_str();

	delete []pchVal;
	delete []pszUtf8;
}