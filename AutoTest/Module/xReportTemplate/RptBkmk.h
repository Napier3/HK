#pragma once

//�������� �����е�λ�ö���,����Word/WPS��˵Ϊ��ǩ
#include "ReportTemplateDefine.h"

class CRptBkmk :	public CExBaseObject
{
public:
	CRptBkmk(void);
	~CRptBkmk(void);

//����
public:
	long m_dwIndex;		//��������ǩ�������
	void GetIndexFromID();

//��д���ຯ��
public:
	virtual UINT GetClassID()													{        return RPTCLASSID_RPTBKMK;												}  
	virtual BSTR GetXmlElementKey()								{      return CRptXmlRWKeys::g_pRptXmlRWKeys->m_strBkmkKey;		}
	virtual long XmlReadOwn(const MSXML2::IXMLDOMNodePtr &oNode, CXmlRWKeys *pXmlRWKeys);
	virtual long XmlWriteOwn(const MSXML2::IXMLDOMDocumentPtr &oXMLDoc, const MSXML2::IXMLDOMElementPtr &oElement, CXmlRWKeys *pXmlRWKeys);
	virtual long SerializeOwn(CBinarySerialBuffer &oBinaryBuffer);

	virtual BOOL CopyOwn(CBaseObject* pDest);
	virtual CBaseObject* Clone();
};

CExBaseList* _FindRptBkmkByID(CExBaseList *pList, const CString &strID, CExBaseList *pListDest);
