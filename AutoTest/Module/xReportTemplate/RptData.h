#pragma once

//�������� ���鱨�����ݶ����Ӷ���ΪCRptBkmk
//���������������Ҫ���뱨���һ�����ݣ��������ݾ���

#include "ReportTemplateDefine.h"

#define _RPTDATA_PRECISION_INIT -1

class CRptData :	public CExBaseList
{
public:
	CRptData(void);
	CRptData(const CString  strName, const CString  strID, long nPrecision);
	virtual ~CRptData(void);

//����
public:
	long m_nPrecision;										//���ݵľ��ȣ�������д����ʱʹ��
	CString m_strDataType;
	long m_nDataFill;

//�����ӿ�
public:
//	CExBaseObject* AddNew();					//�½���ǩ����,�����ض��Ĺ����Զ�����IRptBkmk�ı�ǩ
	CExBaseObject* AddNew2(const CString  strRptBkmk);
	void SetPrecision(long nPrecision)				{		m_nPrecision = nPrecision;		}
	long GetPrecision()												{		return m_nPrecision;					}

	//��д���෽��
public:
	virtual UINT GetClassID()									{        return RPTCLASSID_RPTDATA;             }
	virtual BSTR GetXmlElementKey()				{      return CRptXmlRWKeys::g_pRptXmlRWKeys->m_strDataKey;     }
	virtual long XmlReadOwn(const MSXML2::IXMLDOMNodePtr &oNode, CXmlRWKeys *pXmlRWKeys);
	virtual long XmlWriteOwn(const MSXML2::IXMLDOMDocumentPtr &oXMLDoc, const MSXML2::IXMLDOMElementPtr &oElement, CXmlRWKeys *pXmlRWKeys);
	
	virtual long SerializeOwn(CBinarySerialBuffer &oBinaryBuffer);
	virtual CExBaseObject* CreateNewChild(const CString &strClassID, BOOL &bAddToTail);
	virtual CExBaseObject* CreateNewChild(long nClassID);

};
