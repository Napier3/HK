//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//SetFileXmlParseGlobal.cpp

#include "stdafx.h"
#include "SetFileXmlParseGlobal.h"
#ifdef _DEBUG
#undef THIS_FILE
	static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


//////////////////////////////////////////////////////////////////////////
//CSetFileXmlParseXmlRWKeys

CSetFileXmlParseXmlRWKeys* CSetFileXmlParseXmlRWKeys::g_pXmlKeys = NULL;
long CSetFileXmlParseXmlRWKeys::g_nMngrRef = 0;


CSetFileXmlParseXmlRWKeys::CSetFileXmlParseXmlRWKeys()
{
	m_strCSetsFileXml_RIKey = L"RI";
	m_strCSetsFileXml_ValKey = L"Val";
	m_strCSetsFileXml_SIKey = L"SI";
	m_strCSetsFileXml_RemarkKey = L"Remark";
	m_strCSetsFileXml_InfoGrpKey = L"InfoGrp";
	m_strCSetsFileXml_SettingsKey = L"Settings";
	m_strCSetsFileXml_FIKey = L"FI";
	m_strCSetsFileXml_FileInfoKey = L"FileInfo";
	m_strCSetsFileXml_HIKey = L"HI";
	m_strCSetsFileXml_DIKey = L"DI";
	m_strCSetsFileXml_DevInfoKey = L"DevInfo";
	m_strCSetsFileXml_HashInfoKey = L"HashInfo";
	m_strCSetsFileXml_HeaderKey = L"Header";
	m_strCSetFilesXml_DSCKey = L"DSC";
	m_strConfigVersionKey = L"configVersion";
	m_strDevTypeKey = L"devType";
	m_strDevIdKey = L"devId";
	m_strIedNameKey = L"iedName";
	m_strUpdateTimeKey = L"updateTime";
	m_strmd5Key = L"md5";
	m_strItemNumKey = L"itemNum";
	m_strDescKey = L"desc";
	m_strKey = L"";
	m_strClassKey = L"class";
	m_strMd5Key = L"md5";
	m_strLdKey = L"ld";
	m_strInfoGrpNumKey = L"infoGrpNum";
	m_strGrpKey = L"grp";
	m_strSetGrpNumKey = L"setGrpNum";
	m_strRemoteKey = L"remote";
	m_strTypeKey = L"type";
	m_strUnitKey = L"unit";
	m_strMinKey = L"min";
	m_strMaxKey = L"max";
	m_strStepKey = L"step";
	m_strRefKey = L"ref";
}

CSetFileXmlParseXmlRWKeys::~CSetFileXmlParseXmlRWKeys()
{
}

CSetFileXmlParseXmlRWKeys* CSetFileXmlParseXmlRWKeys::Create()
{
	g_nMngrRef++;

	if (g_nMngrRef == 1)
	{
		g_pXmlKeys = new CSetFileXmlParseXmlRWKeys();
	}

	return g_pXmlKeys;
}

void CSetFileXmlParseXmlRWKeys::Release()
{
	g_nMngrRef--;

	if (g_nMngrRef == 0)
	{
		delete g_pXmlKeys;
		g_pXmlKeys = NULL;
	}
}


//////////////////////////////////////////////////////////////////////////
//CSetFileXmlParseConstGlobal

long CSetFileXmlParseConstGlobal::g_nGlobalRef = 0;
CSetFileXmlParseConstGlobal* CSetFileXmlParseConstGlobal::g_pGlobal = NULL;


CSetFileXmlParseConstGlobal::CSetFileXmlParseConstGlobal()
{

//定义全局常量管理对象初始化函数，例如  InitVariableDataTypes()

}

CSetFileXmlParseConstGlobal::~CSetFileXmlParseConstGlobal()
{
}

CSetFileXmlParseConstGlobal* CSetFileXmlParseConstGlobal::Create()
{
	g_nGlobalRef++;

	if (g_nGlobalRef == 1)
	{
		g_pGlobal = new CSetFileXmlParseConstGlobal();
	}

	return g_pGlobal;
}

void CSetFileXmlParseConstGlobal::Release()
{
	g_nGlobalRef--;

	if (g_nGlobalRef == 0)
	{
		delete g_pGlobal;
		g_pGlobal = NULL;
	}
}

//定义全局常量管理对象初始化函数，例如  void InitVariableDataTypes()
//	m_oFuncParaDataTypes.AddNew(g_pstrVariableType_CString, g_pstrVariableType_CString);

//定义全局常量，例如  static CString g_pstrVariableType_CString;
