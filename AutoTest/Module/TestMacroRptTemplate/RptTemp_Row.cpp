//���Դ������ClassGenerator����
//��Ȩ���� LiJunqing  lijunqing1224@126.com
//��������Ȩ��

//RptTemp_Row.cpp  CRptTemp_Row


#include "stdafx.h"
#include "RptTemp_Row.h"

#ifdef _DEBUG
#undef THIS_FILE
	static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CRptTemp_Row::CRptTemp_Row()
{
	//��ʼ������
	m_nMergeCol = 0;
	//��ʼ����Ա����
}

CRptTemp_Row::~CRptTemp_Row()
{
}

long CRptTemp_Row::XmlReadOwn(CXmlRWNodeBase &oNode, CXmlRWKeys *pXmlRWKeys)
{
	CTestMacroRptTemplateXmlRWKeys *pXmlKeys = (CTestMacroRptTemplateXmlRWKeys*)pXmlRWKeys;

	return 0;
}

long CRptTemp_Row::XmlWriteOwn(CXmlRWDocBase &oXMLDoc, CXmlRWElementBase &oElement, CXmlRWKeys *pXmlRWKeys)
{
	CTestMacroRptTemplateXmlRWKeys *pXmlKeys = (CTestMacroRptTemplateXmlRWKeys*)pXmlRWKeys;

	return 0;
}

long CRptTemp_Row::SerializeOwn(CBinarySerialBuffer &oBinaryBuffer)
{
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

void CRptTemp_Row::InitAfterRead()
{
}

BOOL CRptTemp_Row::IsEqualOwn(CBaseObject* pObj)
{
	if(this == pObj)
	{
		return TRUE;
	}

	CRptTemp_Row *p = (CRptTemp_Row*)pObj;

	return TRUE;
}

BOOL CRptTemp_Row::CopyOwn(CBaseObject* pDest)
{
	if(this == pDest)
	{
		return TRUE;
	}

	CRptTemp_Row *p = (CRptTemp_Row*)pDest;

	return TRUE;
}

CBaseObject* CRptTemp_Row::Clone()
{
	CRptTemp_Row *p = new CRptTemp_Row();
	Copy(p);
	return p;
}

CBaseObject* CRptTemp_Row::CloneEx(BOOL bCopyOwn/*=TRUE*/, BOOL bCopyChildren/*=FALSE*/)
{
	CRptTemp_Row *p = new CRptTemp_Row();
	CopyEx(p, bCopyOwn, bCopyChildren);
	return p;
}

BOOL CRptTemp_Row::CanPaste(UINT nClassID)
{
	if (nClassID == MNGRCLASSID_CRPTTEMP_CELL)
	{
		return TRUE;
	}

	return FALSE;
}

CExBaseObject* CRptTemp_Row::CreateNewChild(const CString &strClassID, BOOL &bAddToTail, CXmlRWKeys *pXmlRWKeys)
{
	CExBaseObject *pNew  = NULL;
	CTestMacroRptTemplateXmlRWKeys *pXmlKeys = (CTestMacroRptTemplateXmlRWKeys*)pXmlRWKeys;


	if (strClassID == pXmlKeys->m_strCRptTemp_CellKey)
	{
		pNew = new CRptTemp_Cell();
	}

	return pNew;
}

CExBaseObject* CRptTemp_Row::CreateNewChild(long nClassID/*, BOOL &bAddToTail*/)
{
	CExBaseObject *pNew  = NULL;


	if (nClassID == MNGRCLASSID_CRPTTEMP_CELL)
	{
		pNew = new CRptTemp_Cell();
	}

	return pNew;
}
