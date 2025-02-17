//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//SetFilesXml_DSC.cpp  CSetFilesXml_DSC


#include "stdafx.h"
#include "SetFilesXml_DSC.h"
#include "..\..\..\..\..\Module\API\Xmd5.h"
#include "..\..\..\..\..\Module\API\StringConvert\String_Gbk_To_Utf8.h"

#ifdef _DEBUG
#undef THIS_FILE
	static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CSetFilesXml_DSC::CSetFilesXml_DSC()
{
	//初始化属性

	//初始化成员变量
	m_pHeader = NULL;
	m_pHashInfo = NULL;
	m_pDevInfo = NULL;
	m_pFileInfo = NULL;
	m_nSetsZone = 1;
	m_pLDevice = NULL;
}

CSetFilesXml_DSC::~CSetFilesXml_DSC()
{
}

long CSetFilesXml_DSC::XmlReadOwn(CXmlRWNodeBase &oNode, CXmlRWKeys *pXmlRWKeys)
{
	CSetFileXmlParseXmlRWKeys *pXmlKeys = (CSetFileXmlParseXmlRWKeys*)pXmlRWKeys;

	xml_GetAttibuteValue(pXmlKeys->m_strConfigVersionKey, oNode, m_strConfigVersion);
	return 0;
}

long CSetFilesXml_DSC::XmlWriteOwn(CXmlRWDocBase &oXMLDoc, CXmlRWElementBase &oElement, CXmlRWKeys *pXmlRWKeys)
{
	CSetFileXmlParseXmlRWKeys *pXmlKeys = (CSetFileXmlParseXmlRWKeys*)pXmlRWKeys;

	xml_SetAttributeValue(pXmlKeys->m_strConfigVersionKey, oElement, m_strConfigVersion);
	return 0;
}

long CSetFilesXml_DSC::SerializeOwn(CBinarySerialBuffer &oBinaryBuffer)
{
	if(oBinaryBuffer.IsCalSizeMode())
	{
		BinarySerializeCalLen(oBinaryBuffer, m_strConfigVersion);
	}
	else if(oBinaryBuffer.IsReadMode())
	{
		BinarySerializeRead(oBinaryBuffer, m_strConfigVersion);
	}
	else if(oBinaryBuffer.IsWriteMode())
	{
		BinarySerializeWrite(oBinaryBuffer, m_strConfigVersion);
	}
	return 0;
}

void CSetFilesXml_DSC::InitAfterRead()
{
	POS pos = GetHeadPosition();
	CBaseObject *p = NULL;
	UINT nClassID = 0;

	while (pos != NULL)
	{
		p = GetNext(pos);
		nClassID = p->GetClassID();

		if (nClassID == MNGRCLASSID_CSETSFILEXML_HEADER)
		{
			m_pHeader = (CSetsFileXml_Header*)p;
		}
		else if (nClassID == MNGRCLASSID_CSETSFILEXML_HASHINFO)
		{
			m_pHashInfo = (CSetsFileXml_HashInfo*)p;
		}
		else if (nClassID == MNGRCLASSID_CSETSFILEXML_DEVINFO)
		{
			m_pDevInfo = (CSetsFileXml_DevInfo*)p;
		}
		else if (nClassID == MNGRCLASSID_CSETSFILEXML_FILEINFO)
		{
			m_pFileInfo = (CSetsFileXml_FileInfo*)p;
		}
	}

	if (m_pHeader == NULL)
	{
		m_pHeader = (CSetsFileXml_Header*)AddNewChild(new CSetsFileXml_Header());
	}

	if (m_pHashInfo == NULL)
	{
		m_pHashInfo = (CSetsFileXml_HashInfo*)AddNewChild(new CSetsFileXml_HashInfo());
	}

	if (m_pDevInfo == NULL)
	{
		m_pDevInfo = (CSetsFileXml_DevInfo*)AddNewChild(new CSetsFileXml_DevInfo());
	}

	if (m_pFileInfo == NULL)
	{
		m_pFileInfo = (CSetsFileXml_FileInfo*)AddNewChild(new CSetsFileXml_FileInfo());
	}

	ParseToDvm();
}

BOOL CSetFilesXml_DSC::IsEqualOwn(CBaseObject* pObj)
{
	if(this == pObj)
	{
		return TRUE;
	}

	CSetFilesXml_DSC *p = (CSetFilesXml_DSC*)pObj;

	if(m_strConfigVersion != p->m_strConfigVersion)
	{
		return FALSE;
	}

	return TRUE;
}

BOOL CSetFilesXml_DSC::CopyOwn(CBaseObject* pDest)
{
	if(this == pDest)
	{
		return TRUE;
	}

	CSetFilesXml_DSC *p = (CSetFilesXml_DSC*)pDest;

	p->m_strConfigVersion = m_strConfigVersion;
	return TRUE;
}

CBaseObject* CSetFilesXml_DSC::Clone()
{
	CSetFilesXml_DSC *p = new CSetFilesXml_DSC();
	Copy(p);
	return p;
}

CBaseObject* CSetFilesXml_DSC::CloneEx(BOOL bCopyOwn/*=TRUE*/, BOOL bCopyChildren/*=FALSE*/)
{
	CSetFilesXml_DSC *p = new CSetFilesXml_DSC();
	CopyEx(p, bCopyOwn, bCopyChildren);
	return p;
}

BOOL CSetFilesXml_DSC::CanPaste(UINT nClassID)
{
	if (nClassID == MNGRCLASSID_CSETSFILEXML_HEADER)
	{
		return TRUE;
	}

	if (nClassID == MNGRCLASSID_CSETSFILEXML_HASHINFO)
	{
		return TRUE;
	}

	if (nClassID == MNGRCLASSID_CSETSFILEXML_DEVINFO)
	{
		return TRUE;
	}

	if (nClassID == MNGRCLASSID_CSETSFILEXML_FILEINFO)
	{
		return TRUE;
	}

	if (nClassID == MNGRCLASSID_CSETSFILEXML_SETTINGS)
	{
		return TRUE;
	}

	if (nClassID == MNGRCLASSID_CSETSFILEXML_REMARK)
	{
		return TRUE;
	}

	return FALSE;
}

CExBaseObject* CSetFilesXml_DSC::CreateNewChild(const CString &strClassID, BOOL &bAddToTail, CXmlRWKeys *pXmlRWKeys)
{
	CExBaseObject *pNew  = NULL;
	CSetFileXmlParseXmlRWKeys *pXmlKeys = (CSetFileXmlParseXmlRWKeys*)pXmlRWKeys;


	if (strClassID == pXmlKeys->m_strCSetsFileXml_HeaderKey)
	{
		pNew = new CSetsFileXml_Header();
	}
	else if (strClassID == pXmlKeys->m_strCSetsFileXml_HashInfoKey)
	{
		pNew = new CSetsFileXml_HashInfo();
	}
	else if (strClassID == pXmlKeys->m_strCSetsFileXml_DevInfoKey)
	{
		pNew = new CSetsFileXml_DevInfo();
	}
	else if (strClassID == pXmlKeys->m_strCSetsFileXml_FileInfoKey)
	{
		pNew = new CSetsFileXml_FileInfo();
	}
	else if (strClassID == pXmlKeys->m_strCSetsFileXml_SettingsKey)
	{
		pNew = new CSetsFileXml_Settings();
	}
	else if (strClassID == pXmlKeys->m_strCSetsFileXml_RemarkKey)
	{
		pNew = new CSetsFileXml_Remark();
	}

	return pNew;
}

CExBaseObject* CSetFilesXml_DSC::CreateNewChild(long nClassID/*, BOOL &bAddToTail*/)
{
	CExBaseObject *pNew  = NULL;


	if (nClassID == MNGRCLASSID_CSETSFILEXML_HEADER)
	{
		pNew = new CSetsFileXml_Header();
	}
	else if (nClassID == MNGRCLASSID_CSETSFILEXML_HASHINFO)
	{
		pNew = new CSetsFileXml_HashInfo();
	}
	else if (nClassID == MNGRCLASSID_CSETSFILEXML_DEVINFO)
	{
		pNew = new CSetsFileXml_DevInfo();
	}
	else if (nClassID == MNGRCLASSID_CSETSFILEXML_FILEINFO)
	{
		pNew = new CSetsFileXml_FileInfo();
	}
	else if (nClassID == MNGRCLASSID_CSETSFILEXML_SETTINGS)
	{
		pNew = new CSetsFileXml_Settings();
	}
	else if (nClassID == MNGRCLASSID_CSETSFILEXML_REMARK)
	{
		pNew = new CSetsFileXml_Remark();
	}

	return pNew;
}

void CSetFilesXml_DSC::ParseToDvm()
{
	POS pos = GetHeadPosition();
	CExBaseObject *pObj = NULL;
	UINT nClassID = 0;

	while (pos != NULL)
	{
		pObj = GetNext(pos);
		nClassID = pObj->GetClassID();

		if (nClassID != MNGRCLASSID_CSETSFILEXML_SETTINGS)
		{
			continue;
		}

		CSetsFileXml_Settings *pSettings = (CSetsFileXml_Settings *)pObj;
		pSettings->ParseToDvm(m_pLDevice);
	}
}

CSetsFileXml_Settings* CSetFilesXml_DSC::FindSettingsByClass(const CString &strClass)
{
	POS pos = GetHeadPosition();
	CExBaseObject *pObj = NULL;
	UINT nClassID = 0;
	CSetsFileXml_Settings *pSettings = NULL;

	while (pos != NULL)
	{
		pObj = GetNext(pos);
		nClassID = pObj->GetClassID();

		if (nClassID != MNGRCLASSID_CSETSFILEXML_SETTINGS)
		{
			continue;
		}

		pSettings = (CSetsFileXml_Settings *)pObj;
		
		if (pSettings->m_strClass == strClass)
		{
			break;
		}
	}

	return pSettings;
}

void CSetFilesXml_DSC::GetSettingsValTotl(CString &strValTotal)
{
	CString strVal;
	strValTotal.Empty();
	POS pos = GetHeadPosition();
	CExBaseObject *pObj = NULL;
	UINT nClassID = 0;
	CSetsFileXml_Settings *pSettings = NULL;

	while (pos != NULL)
	{
		pObj = GetNext(pos);
		nClassID = pObj->GetClassID();

		if (nClassID != MNGRCLASSID_CSETSFILEXML_SETTINGS)
		{
			continue;
		}

		pSettings = (CSetsFileXml_Settings *)pObj;
		pSettings->GetValStringTotal(strVal);
		strValTotal.AppendFormat(_T("%s"), strVal);
	}
}

void CSetFilesXml_DSC::GetSettingsValTotl(const CString &strClass, CString &strValTotal)
{
	strValTotal.Empty();
	CSetsFileXml_Settings *pSettings = FindSettingsByClass(strClass);

	if (pSettings == NULL)
	{
		GetSettingsValTotl(strValTotal);
		return;
	}

	pSettings->GetValStringTotal(strValTotal);
}

//返回定值单文件中的哈希值
void CSetFilesXml_DSC::GetMd5_FromFile(const CString &strClass, CString &strMd5)
{
	if (strClass == _T(""))
	{
		//为空  返回总的哈希值
		if (m_pHeader == NULL)
		{
			return ;
		}

		strMd5 = m_pHeader->m_strmd5;
		return;
	}

	if (m_pHashInfo == NULL)
	{
		return ;
	}

	m_pHashInfo->GetMd5_FromFile(strClass, strMd5);
}

void CSetFilesXml_DSC::GetMd5_FromCal(const CString &strClass, CString &strMd5)
{
	if (strClass == SETTING_CLASS_PARAMETER)
	{
		if (m_strMd5_Cal_Parameter.GetLength() > 0)
		{
			strMd5 = m_strMd5_Cal_Parameter;
			return;
		}
	}
	else if (strClass == SETTING_CLASS_SETTING)
	{
		if (m_strMd5_Cal_Setting.GetLength() > 0)
		{
			strMd5 = m_strMd5_Cal_Setting;
			return;
		}
	}
	else if (strClass == SETTING_CLASS_RELAYENA)
	{
		if (m_strMd5_Cal_Ena.GetLength() > 0)
		{
			strMd5 = m_strMd5_Cal_Ena;
			return;
		}
	}

	CString strValTotal;
	GetSettingsValTotl(strClass, strValTotal);
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

	if (strClass == SETTING_CLASS_PARAMETER)
	{
		m_strMd5_Cal_Parameter = strMd5;
	}
	else if (strClass == SETTING_CLASS_SETTING)
	{
		m_strMd5_Cal_Setting = strMd5;
	}
	else if (strClass == SETTING_CLASS_RELAYENA)
	{
		m_strMd5_Cal_Ena = strMd5;
	}
}