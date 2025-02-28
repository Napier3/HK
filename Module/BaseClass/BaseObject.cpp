// BaseObject.cpp: implementation of the CBaseObject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BaseObject.h"
#include "../API/FileApi.h"
#include <QtDebug>

const char* CXmlRWKeys::g_pszNameKeyString  = "name";
const char* CXmlRWKeys::g_pszIDKeyString    = "id";

long CXmlRWKeys::ReadFromXmlFile(const CString &strFile)
{
	return 0;
}

BSTR GetXml();

CBaseObject::CBaseObject()
{
    m_pParent = nullptr;
}

CBaseObject::~CBaseObject()
{

}

CBaseObject* CBaseObject::GetAncestor(UINT nClassID)
{
    CBaseObject *pAncestor = nullptr;
    CBaseObject *pAncestorFind = nullptr;

	pAncestor = this;//m_pParent;

    while (pAncestor != nullptr)
	{
		if (nClassID == pAncestor->GetClassID())
		{
			pAncestorFind = pAncestor;
			break;
		}

		pAncestor = pAncestor->GetParent();
	}

	return pAncestorFind;
}

CBaseObject* CBaseObject::GetAncestorEx(UINT nClassID)
{
    CBaseObject *pAncestor = nullptr;
    CBaseObject *pAncestorFind = nullptr;

	pAncestor = m_pParent;

    while (pAncestor != nullptr)
	{
		if (nClassID == (pAncestor->GetClassID() & nClassID) )
		{
			pAncestorFind = pAncestor;
			break;
		}

		pAncestor = pAncestor->GetParent();
	}

	return pAncestorFind;
}

/*
 *	根据节点的深度获取祖先节点
 *  节点的深度：
 *           例如：A->B->C->D->E->F
 *                 F为叶子节点对象，E为F的Ancestor，其深度为0
 *                 D为F的Ancestor，其深度为1
 *                 B为F的Ancestor，其深度为3
 */
CBaseObject* CBaseObject::GetAncestorByDepth(long nDepth)
{
    CBaseObject *pAncestor = nullptr;
    CBaseObject *pAncestorFind = nullptr;
	
	pAncestor = m_pParent;
	long nTemp = nDepth;
	
    while (pAncestor != nullptr)
	{
		if (nTemp == 0)
		{
			pAncestorFind = pAncestor;
			break;
		}

		pAncestor = pAncestor->GetParent();

		nTemp--;
	}
	
	return pAncestorFind;
}

long CBaseObject::GetDepth()
{
    CBaseObject *pTemp = nullptr;
	CBaseObject *pParent = GetParent();
	long nDepth = 0;
	
    while (pParent != nullptr)
	{
		pTemp = pParent->GetParent();
		
        if (pTemp == nullptr)
		{
			break;
		}
		
		nDepth++;
		pParent = pTemp;
	}

	return nDepth;
}

CBaseObject* CBaseObject::GetRoot()
{
    CBaseObject *pTemp = nullptr;
	CBaseObject *pRoot = this;

    while (pRoot != nullptr)
	{
		pTemp = pRoot->GetParent();

        if (pTemp == nullptr)
		{
			break;
		}

		pRoot = pTemp;
	}

	return pRoot;
}

BOOL CBaseObject::HasParent(CBaseObject *pParent)
{
	CBaseObject *pTemp = GetParent();

    while (pTemp != nullptr)
	{
		if (pTemp == pParent)
		{
			return TRUE;
		}

		pTemp = pTemp->GetParent();
	}

	return FALSE;
}

long CBaseObject::XmlRead(CXmlRWNodeBase &oNode, CXmlRWKeys *pXmlRWKeys)
{
	try
	{
		XmlReadOwn(oNode, pXmlRWKeys);
	}
	catch (...)
	{
    }

	try
	{
		CXmlRWNodeListBase *pChildNodeList = oNode.GetChildNodes();
		XmlReadChildren(*pChildNodeList, pXmlRWKeys);
	}
	catch (...)
	{
    }

	InitAfterRead();

	return 0;
}

long CBaseObject::XmlReadOwn(CXmlRWNodeBase &oNode, CXmlRWKeys *pXmlRWKeys)
{
	return 0;
}

long CBaseObject::XmlReadChildren(CXmlRWNodeListBase &oNodes, CXmlRWKeys *pXmlRWKeys)
{
	return 0;
}

//2020-12-1  lijunqing
long CBaseObject::XmlWriteEx(CXmlRWDocBase &oXMLDoc, CXmlRWElementBase &oParent, CXmlRWKeys *pXmlRWKeys, CXmlRWElementBase* &pRetElement)
{
	BSTR pszElementKey = GetXmlElementKey();
    ASSERT(pszElementKey != nullptr);

    if (pszElementKey == nullptr)
	{
		return -1;
	}

#ifdef _UNICODE
	if (lstrlen(pszElementKey) == 0)
	{
		return -1;
	}
#else
	if (wcslen(pszElementKey) == 0)
	{
		return -1;
	}
#endif

	pRetElement = oXMLDoc.CreateElement(pszElementKey,&oParent);
	XmlWriteOwn(oXMLDoc, *pRetElement, pXmlRWKeys);

	return 0;
}

long CBaseObject::XmlWrite(CXmlRWDocBase &oXMLDoc,CXmlRWElementBase &oParent, BSTR pszElementKey, CXmlRWKeys *pXmlRWKeys)
{
    ASSERT(pszElementKey != nullptr);

    if (pszElementKey == nullptr)
	{
		return -1;
	}

#ifdef _UNICODE
	if (lstrlen(pszElementKey) == 0)
	{
		return -1;
	}
#else
	if (wcslen(pszElementKey) == 0)
	{
		return -1;
	}
#endif

	CXmlRWElementBase *pElement = oXMLDoc.CreateElement(pszElementKey,&oParent);

	XmlWriteOwn(oXMLDoc, *pElement, pXmlRWKeys);
	XmlWriteChildren(oXMLDoc, *pElement, pXmlRWKeys);

	return 0;
}

long CBaseObject::XmlWrite(CXmlRWDocBase &oXMLDoc,CXmlRWElementBase &oParent, CXmlRWKeys *pXmlRWKeys)
{
	BSTR pszElementKey = GetXmlElementKey();
	return XmlWrite(oXMLDoc, oParent, pszElementKey, pXmlRWKeys);
}

long CBaseObject::XmlWriteOwn(CXmlRWDocBase &oXMLDoc, CXmlRWElementBase &oElement, CXmlRWKeys *pXmlRWKeys)
{
	return 0;
}

long CBaseObject::XmlWriteChildren(CXmlRWDocBase &oXMLDoc, CXmlRWElementBase &oElement, CXmlRWKeys *pXmlRWKeys)
{
	return 0;
};

long CBaseObject::Serialize(CBinarySerialBuffer &oBinaryBuffer)
{
	SerializeOwn(oBinaryBuffer);
	SerializeChildren(oBinaryBuffer);
	
	if (oBinaryBuffer.IsReadMode())
	{
		InitAfterRead();
	}

	return 0;
}

long CBaseObject::SerializeOwn(CBinarySerialBuffer &oBinaryBuffer)
{

	return 0;
}

long CBaseObject::SerializeChildren(CBinarySerialBuffer &oBinaryBuffer)
{ 
	return 0;
}


long CBaseObject::SerializeRead(char *pBuffer, long nLen)
{
	CBinarySerialBuffer oBinaryBuffer;
	oBinaryBuffer.AttachBuffer(pBuffer, nLen);
	oBinaryBuffer.SetCharSet(CHAR_SET_ASCII);
	oBinaryBuffer.SetReadMode();

	return SerializeRead(oBinaryBuffer);
}

long CBaseObject::SerializeRead(CBinarySerialBuffer &oBinaryBuffer)
{
	ASSERT (oBinaryBuffer.IsReadMode());
	return Serialize(oBinaryBuffer);
}

long CBaseObject::SerializeWrite(CBinarySerialBuffer &oBinaryBuffer)
{
	oBinaryBuffer.SetCharSet(CHAR_SET_ASCII);
	oBinaryBuffer.SetCalSizeMode();
	Serialize(oBinaryBuffer);
	oBinaryBuffer.AllocBuffer(0);
	oBinaryBuffer.SetWriteMode();
	Serialize(oBinaryBuffer);

	return 0;
}

BOOL CBaseObject::BinarySerializeReadFromFile(const CString &strFile)
{
	CBinarySerialBuffer oBuffer;
	return FALSE;
}

BOOL CBaseObject::BinarySerializeWriteToFile(const CString &strFile)
{
	return FALSE;
}

BOOL CBaseObject::CopyEx(CBaseObject* pDest, BOOL bCopyOwn,BOOL bCopyChildren)	
{
	if (bCopyOwn)
	{
		CopyOwn(pDest); 
	}

	if (bCopyChildren)
	{
		CopyChildren(pDest); 
		pDest->InitAfterRead(); 
	}
	
	return TRUE;
}

BOOL CBaseObject::CopyOwn(CBaseObject* pDest)	
{
	return TRUE;
}

BOOL CBaseObject::CopyChildren(CBaseObject* pDest)
{
	return TRUE;
}

BOOL CBaseObject::UpdateOwn(CBaseObject* pDest)
{	
	return TRUE;
}

BOOL CBaseObject::UpdateChildren(CBaseObject* pDest)
{
	return TRUE;
}

BOOL CBaseObject::IsSame(CBaseObject* pObj)
{
	return FALSE;
}

CBaseObject* CBaseObject::FindSame(CBaseObject* pObj)
{
    return nullptr;
}

long CBaseObject::ValCmp(CBaseObject* pRightObj)
{
	ASSERT (FALSE);
	return 1;
}

long CBaseObject::ValCmp(CBaseObject* pRightObj, DWORD dwAttrID)
{
	ASSERT (FALSE);
	return 1;
}

long CBaseObject::ValCmp(CBaseObject* pRightObj, const CString &strAttrID)
{
	ASSERT (FALSE);
	return 1;
}

BOOL CBaseObject::IsEqual(CBaseObject* pObj)
{
	if (IsEqualOwn(pObj) == FALSE)
	{
		return FALSE;
	}
	if (IsEqualChildren(pObj) == FALSE)
	{
		return FALSE;
	}
	return TRUE;
}

BOOL CBaseObject::IsEqualOwn(CBaseObject* pObj)
{	
	return TRUE;
}

BOOL CBaseObject::IsEqualChildren(CBaseObject* pObj)	
{
	return TRUE;
}

BOOL CBaseObject::OpenXmlFile(const CString &strFile, BSTR bstrElementKey, CXmlRWKeys *pXmlRWKeys,const long &nXmlRWType)
{
    qDebug() << "Trying to opening file: << " << strFile << " >>";
	if (!IsFileExist(strFile))
	{
		return FALSE;
	}
	CXmlRWDocBase *pRWDoc = xml_CreateXmlRWDoc(nXmlRWType);
	try
	{
        if ( !xml_OpenFile(pRWDoc, strFile) )
		{
			delete pRWDoc;
			return FALSE;
		}
	}
	catch (...)
	{
		delete pRWDoc;
		return FALSE;
	}
	CXmlRWNodeBase *pDocRoot = pRWDoc->GetDocNode();
	
    if (bstrElementKey != nullptr)
	{
		pDocRoot = pDocRoot->GetChildNode(bstrElementKey);
	}
	else
	{
		delete pRWDoc;
		return FALSE;
	}

    if (pDocRoot == nullptr)
	{
		delete pRWDoc;
		return FALSE;
	}

	if(!pDocRoot->IsValid())
	{
		delete pRWDoc;
		return FALSE;
	}
	XmlRead(*pDocRoot, pXmlRWKeys);
	delete pRWDoc;

	return TRUE;
}

BOOL CBaseObject::OpenXmlFile(const CString &strFile, CXmlRWKeys *pXmlRWKeys,const long &nXmlRWType)
{
    BSTR bstrElementKey = GetXmlElementKey();//虚函数，利用多态直接调用子类的此函数，返回静态成员变量的值；实际操作为{      return CXLanguageXmlRWKeys::CXLanguageMngrKey();     }
    return OpenXmlFile(strFile, bstrElementKey, pXmlRWKeys,nXmlRWType);//中间参数为刚刚在语言关键子里静态变量指针指向的对象成员变量的值；其对应了根节点的名称；
}

BOOL CBaseObject::SaveXmlFile(const CString &strFile, CXmlRWKeys *pXmlRWKeys ,const long &nXmlRWType)
{
	if (strFile.GetLength() < 3)
	{
		return FALSE;
	}

	try
	{
		CXmlRWDocBase *pRWDoc = xml_CreateXmlRWDoc(nXmlRWType);

		CXmlRWElementBase *pElement = pRWDoc->GetDocElement();
		XmlWrite(*pRWDoc,*pElement,pXmlRWKeys);

		ClearFileReadOnlyAttr(strFile);

		CString strPath = GetPathFromFilePathName(strFile);
		CreateAllDirectories(strPath);

		pRWDoc->SaveXml(strFile);

		delete pRWDoc;
	}
	catch (...)
	{
		return 0;
	}
	
	return 1;
}

BSTR CBaseObject::GetXml(CXmlRWKeys *pXmlRWKeys,const long &nXmlRWType)
{
	CXmlRWDocBase *pRWDoc = xml_CreateXmlRWDoc(nXmlRWType);
	CXmlRWElementBase *pRWElement = pRWDoc->GetDocElement();
	XmlWrite(*pRWDoc, *pRWElement,  pXmlRWKeys);
	CString strXML;
	pRWDoc->GetXml(strXML);
	delete pRWDoc;
	return strXML.AllocSysString();
}

void CBaseObject::GetXml(CXmlRWKeys *pXmlRWKeys, CString &bstrXml,const long &nXmlRWType)
{
	CXmlRWDocBase *pRWDoc = xml_CreateXmlRWDoc(nXmlRWType);
	CXmlRWElementBase *pRWElement = pRWDoc->GetDocElement();
	XmlWrite(*pRWDoc, *pRWElement,  pXmlRWKeys);
	pRWDoc->GetXml(bstrXml);
	delete pRWDoc;
}

long CBaseObject::GetXml(CXmlRWKeys *pXmlRWKeys, char **ppszRetBuffer, long nOffset,const long &nXmlRWType)
{
	CXmlRWDocBase *pRWDoc = xml_CreateXmlRWDoc(nXmlRWType);
	CXmlRWElementBase *pRWElement = pRWDoc->GetDocElement();
	XmlWrite(*pRWDoc, *pRWElement,  pXmlRWKeys);

	long nLen = pRWDoc->GetXml(ppszRetBuffer, nOffset);
	delete pRWDoc;
	return nLen;
}

long CBaseObject::GetXml_UTF8(CXmlRWKeys *pXmlRWKeys, char **ppszRetBuffer, long nOffset,const long &nXmlRWType)
{
	return GetXml(pXmlRWKeys, ppszRetBuffer, nOffset, nXmlRWType);
}

long CBaseObject::GetXml_ASCII(CXmlRWKeys *pXmlRWKeys, char **ppszRetBuffer, long nOffset,const long &nXmlRWType)
{
	CXmlRWDocBase *pRWDoc = xml_CreateXmlRWDoc(nXmlRWType);
	CXmlRWElementBase *pRWElement = pRWDoc->GetDocElement();
	XmlWrite(*pRWDoc, *pRWElement,  pXmlRWKeys);

	long nLen = pRWDoc->GetXml_ASCII(ppszRetBuffer, nOffset);
	delete pRWDoc;
	return nLen;
}

BOOL CBaseObject::SetXml(CXmlRWDocBase *pRWDoc, BSTR bstrElementKey, CXmlRWKeys *pXmlRWKeys)
{
    CXmlRWNodeBase *pDocRoot = pRWDoc->GetDocNode();

    if (bstrElementKey != nullptr)
    {
        pDocRoot = pDocRoot->GetChildNode(bstrElementKey);
    }
    else
    {
        pDocRoot = pRWDoc->GetDocNode();
    }

    if (pDocRoot == nullptr)
	{
        CLogPrint::LogString(XLOGLEVEL_TRACE, _T("SetXml Error: oDocRoot == nullptr"));
		return 0;
	}

    if(!pDocRoot->IsValid())
    {
        return FALSE;
    }
    XmlRead(*pDocRoot, pXmlRWKeys);
    return TRUE;
}

BOOL CBaseObject::SetXml(const CString &strXml, CXmlRWKeys *pXmlRWKeys,const long &nXmlRWType)
{
	BSTR bstrXml = strXml.AllocSysString();
	BOOL bRet = SetXml(bstrXml, pXmlRWKeys, nXmlRWType);
	delete bstrXml;
	return bRet;
}

BOOL CBaseObject::SetXml(BSTR strXml, BSTR bstrElementKey, CXmlRWKeys *pXmlRWKeys,const long &nXmlRWType)
{
	if (wcslen(strXml) == 0)
	{
		return FALSE;
	}

	CXmlRWDocBase *pRWDoc = xml_CreateXmlRWDoc(nXmlRWType);

	if (!pRWDoc->SetXml(strXml))
	{
		delete pRWDoc;
		return FALSE;
	}

    BOOL bRet = SetXml(pRWDoc, bstrElementKey, pXmlRWKeys);
    delete pRWDoc;

    return bRet;
}

BOOL CBaseObject::SetXml(BSTR strXml, CXmlRWKeys *pXmlRWKeys,const long &nXmlRWType)
{
	BSTR bstrElementKey = GetXmlElementKey();

	return SetXml(strXml, bstrElementKey, pXmlRWKeys,nXmlRWType);
}

BOOL CBaseObject::SetXml_ASCII(char *strXml,long nLen, CXmlRWKeys *pXmlRWKeys,const long &nXmlRWType)
{
    CXmlRWDocBase *pRWDoc = xml_CreateXmlRWDoc(nXmlRWType);
    if (!pRWDoc->SetXml_ASCII(strXml,nLen))
    {
        delete pRWDoc;
        return FALSE;
    }
    BSTR bstrElementKey = GetXmlElementKey();
    BOOL bRet = SetXml(pRWDoc, bstrElementKey, pXmlRWKeys);
    delete pRWDoc;

    return bRet;
}

BOOL CBaseObject::SetXml_UTF8(char *strXml,long nLen, CXmlRWKeys *pXmlRWKeys,const long &nXmlRWType)
{
    CXmlRWDocBase *pRWDoc = xml_CreateXmlRWDoc(nXmlRWType);

	if (!pRWDoc->SetXml_UTF8(strXml,nLen))
    {
        delete pRWDoc;
        return FALSE;
    }
    BSTR bstrElementKey = GetXmlElementKey();
    BOOL bRet = SetXml(pRWDoc, bstrElementKey, pXmlRWKeys);
    delete pRWDoc;

    return bRet;
}

void CBaseObject::SetModifiedFlag(BOOL bModified)
{
	CBaseObject *pRoot = GetRoot();

	pRoot->SetModifiedFlagOwn(bModified);
}

void CBaseObject::SetModifiedFlagOwn(BOOL bModified) {}

BOOL CBaseObject::GetModifiedFlagOwn()
{
	return FALSE;
}

void CBaseObject::SaveBaseObject()
{
	SetModifiedFlagOwn(FALSE);
}

BOOL CBaseObject::GetModifiedFlag(BOOL bRoot)
{
	if (bRoot)
	{
		CBaseObject *pRoot = GetRoot();
		return pRoot->GetModifiedFlagOwn();
	}
	else
	{
		return GetModifiedFlagOwn();
	}
}

