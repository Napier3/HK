//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XSclFileMngr.cpp  CXSclFileMngr


#include "stdafx.h"
#include "XSclFileMngr.h"
#include "../../../../Module/API/FileApi.h"
#include "../../../../Module/API/GlobalConfigApi.h"

#ifdef _DEBUG
#undef THIS_FILE
	static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CXSclFileMngr g_oXSclFileMngr;

CXSclFileMngr::CXSclFileMngr()
{
	//初始化属性

	//初始化成员变量
	m_bHasOpenCfgFile = FALSE;
}

CXSclFileMngr::~CXSclFileMngr()
{
}

long CXSclFileMngr::XmlReadOwn(CXmlRWNodeBase &oNode, CXmlRWKeys *pXmlRWKeys)
{
	CExBaseObject::XmlReadOwn(oNode, pXmlRWKeys);

	CSclFileMngrXmlRWKeys *pXmlKeys = (CSclFileMngrXmlRWKeys*)pXmlRWKeys;

	return 0;
}

long CXSclFileMngr::XmlWriteOwn(CXmlRWDocBase &oXMLDoc, CXmlRWElementBase &oElement, CXmlRWKeys *pXmlRWKeys)
{
	CExBaseObject::XmlWriteOwn(oXMLDoc, oElement, pXmlRWKeys);

	CSclFileMngrXmlRWKeys *pXmlKeys = (CSclFileMngrXmlRWKeys*)pXmlRWKeys;

	return 0;
}

long CXSclFileMngr::SerializeOwn(CBinarySerialBuffer &oBinaryBuffer)
{
	CExBaseObject::SerializeOwn(oBinaryBuffer);

	if(oBinaryBuffer.IsCalSizeMode())
	{
	}
	else if(oBinaryBuffer.IsReadMode())
	{
	}
	else if(oBinaryBuffer.IsWriteMode())
	{
	}
	return 0;
}

void CXSclFileMngr::InitAfterRead()
{
}

BOOL CXSclFileMngr::IsEqualOwn(CBaseObject* pObj)
{
	if(this == pObj)
	{
		return TRUE;
	}

	if (!CExBaseObject::IsEqualOwn(pObj))
	{
		return FALSE;
	}

	CXSclFileMngr *p = (CXSclFileMngr*)pObj;


	return TRUE;
}

BOOL CXSclFileMngr::CopyOwn(CBaseObject* pDest)
{
	if(this == pDest)
	{
		return TRUE;
	}

	CExBaseObject::CopyOwn(pDest);

	CXSclFileMngr *p = (CXSclFileMngr*)pDest;

	return TRUE;
}

CBaseObject* CXSclFileMngr::Clone()
{
	CXSclFileMngr *p = new CXSclFileMngr();
	Copy(p);
	return p;
}

CBaseObject* CXSclFileMngr::CloneEx(BOOL bCopyOwn/*=TRUE*/, BOOL bCopyChildren/*=FALSE*/)
{
	CXSclFileMngr *p = new CXSclFileMngr();
	CopyEx(p, bCopyOwn, bCopyChildren);
	return p;
}

BOOL CXSclFileMngr::CanPaste(UINT nClassID)
{
	if (nClassID == MNGRCLASSID_CXSCLFILEOBJ)
	{
		return TRUE;
	}

	return FALSE;
}

CExBaseObject* CXSclFileMngr::CreateNewChild(const CString &strClassID, BOOL &bAddToTail, CXmlRWKeys *pXmlRWKeys)
{
	CExBaseObject *pNew  = NULL;
	CSclFileMngrXmlRWKeys *pXmlKeys = (CSclFileMngrXmlRWKeys*)pXmlRWKeys;


	if (strClassID == pXmlKeys->m_strCXSclFileObjKey)
	{
		pNew = new CXSclFileObj();
	}

	return pNew;
}

CExBaseObject* CXSclFileMngr::CreateNewChild(long nClassID/*, BOOL &bAddToTail*/)
{
	CExBaseObject *pNew  = NULL;


	if (nClassID == MNGRCLASSID_CXSCLFILEOBJ)
	{
		pNew = new CXSclFileObj();
	}

	return pNew;
}

BOOL CXSclFileMngr::OpenSclFileMngrCfg(const CString &strPath)
{
	DeleteAll();

	if (!strPath.IsEmpty())
	{
		return OpenXmlFile(strPath,CSclFileMngrXmlRWKeys::g_pXmlKeys);
	}

	m_bHasOpenCfgFile = TRUE;
	CString strDefautPath;
	strDefautPath = _P_GetConfigPath();
	strDefautPath += (_T("SclFileMngrConfig.xml"));

	if (!IsFileExist(strDefautPath))
	{
		CLogPrint::LogFormatString(XLOGLEVEL_INFOR,_T("SCL历史记录文件(%s)不存在."),strDefautPath.GetString());
		return FALSE;
	}

	return OpenXmlFile(strDefautPath,CSclFileMngrXmlRWKeys::g_pXmlKeys);
}

BOOL CXSclFileMngr::SaveSclFileMngrCfg(const CString &strPath)
{
	if (!strPath.IsEmpty())
	{
		return SaveXmlFile(strPath,CSclFileMngrXmlRWKeys::g_pXmlKeys);
	}

	CString strDefautPath;
	strDefautPath = _P_GetConfigPath();
	strDefautPath += (_T("SclFileMngrConfig.xml"));
	return SaveXmlFile(strDefautPath,CSclFileMngrXmlRWKeys::g_pXmlKeys);
}

BOOL CXSclFileMngr::ValidSetSelectState(CXSclFileObj *pXSclFileObj)
{
	if (pXSclFileObj->m_nUse == 0)
	{
		return TRUE;
	}

	CXSclFileObj *pCurrObj = NULL;
	BOOL bSuccess = TRUE;
	POS pos = GetHeadPosition();

	while(pos)
	{
		pCurrObj = (CXSclFileObj *)GetNext(pos);

		if (pXSclFileObj == pCurrObj)
		{
			continue;
		}

		if (pCurrObj->m_nUse)
		{
			pCurrObj->m_nUse = 0;
			bSuccess = FALSE;
		}
	}

	return bSuccess;
}

void CXSclFileMngr::ClearAll_WithFolderFiles()
{
	CXSclFileObj *pXSclFileObj = NULL;
	CString strFolderPath;
	POS pos = GetHeadPosition();

	while(pos)
	{
		pXSclFileObj = (CXSclFileObj *)GetNext(pos);
		strFolderPath = GetPathFromFilePathName(pXSclFileObj->m_strSsclPath);
		DeleteAllDirectorys(strFolderPath);
	}

	DeleteAll();
}

CString CXSclFileMngr::GetCurrSelSsclFilePah()
{
	CString strSsclPath;

	CXSclFileObj *pXSclFileObj = NULL;
	POS pos = GetHeadPosition();

	while(pos)
	{
		pXSclFileObj = (CXSclFileObj *)GetNext(pos);
		

		if (pXSclFileObj->m_nUse)
		{
			strSsclPath = pXSclFileObj->m_strSsclPath;
			break;
		}
	}

	return strSsclPath;
}

CString CXSclFileMngr::GetCurrSelTscdFilePah()
{
	CString strSsclPath,strTscdPath;
	strSsclPath = GetCurrSelSsclFilePah();

	if (strSsclPath.IsEmpty())
	{
		return _T("");
	}

	strTscdPath = ChangeFilePostfix(strSsclPath,_T("tscd"));
	return strTscdPath;
}