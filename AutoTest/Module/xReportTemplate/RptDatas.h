#pragma once

//�������� ���鱨�����ݼ��϶����Ӷ���ΪCRptData

#include "ReportTemplateDefine.h"

class CRptDatas :	public CExBaseList
{
public:
	CRptDatas(void);
	CRptDatas(const CString  strName, const CString  strID);
	virtual ~CRptDatas(void);

//�����ӿ�
public:
	CExBaseObject* AddNew(const CString  strName, const CString  strID, long nPrecision);

//��д���෽��
public:
	virtual UINT GetClassID() {        return RPTCLASSID_RPTDATAS;             }     
	virtual BSTR GetXmlElementKey()  {      return CRptXmlRWKeys::g_pRptXmlRWKeys->m_strDatasKey;	 }

	virtual CExBaseObject* CreateNewChild(const CString &strClassID, BOOL &bAddToTail);	
	virtual CExBaseObject* CreateNewChild(long nClassID);
};
