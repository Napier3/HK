#pragma once

//�������� ���鱨����������Ӷ���ΪCRptBkmk

#include "ReportTemplateDefine.h"
#include "RptBkmk.h"

class CRptArea :	public CExBaseList
{
public:
	CRptArea(void);
	virtual ~CRptArea(void);

//����
public:
	CRptBkmk *m_pBkmkBegin;
	CRptBkmk *m_pBkmkEnd;

//�����ӿ�
public:
// 	CExBaseObject* AddNew();					//�½���ǩ����,�����ض��Ĺ����Զ�����IRptBkmk�ı�ǩ
// 	CExBaseObject* AddNew2(const CString  strRptBkmk);

	//��д���෽��
public:
	virtual UINT GetClassID()									{        return RPTCLASSID_RPTAREA;             }
	virtual BSTR GetXmlElementKey()				{      return CRptXmlRWKeys::g_pRptXmlRWKeys->m_strAreaKey;     }
	virtual long XmlReadOwn(const MSXML2::IXMLDOMNodePtr &oNode, CXmlRWKeys *pXmlRWKeys);
	virtual long XmlWriteOwn(const MSXML2::IXMLDOMDocumentPtr &oXMLDoc, const MSXML2::IXMLDOMElementPtr &oElement, CXmlRWKeys *pXmlRWKeys);
	
	virtual long SerializeOwn(CBinarySerialBuffer &oBinaryBuffer);
	virtual CExBaseObject* CreateNewChild(const CString &strClassID, BOOL &bAddToTail);
	virtual CExBaseObject* CreateNewChild(long nClassID);

	virtual void InitAfterRead();

};
