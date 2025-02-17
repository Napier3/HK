#pragma once
//�������� ���鱨�����ݼ��϶����Ӷ���ΪIRptDatas��IRptData
#include "ReportTemplateDefine.h"
#include "RptArea.h"

class CRptItem :	public CExBaseList
{
public:
	CRptItem(void);
	CRptItem(const CString  strName, const CString  strID, long bSelect = 0);
	virtual ~CRptItem(void);

//����
public:
	CRptArea *m_pArea;
	CExBaseList *m_pGbItemRef;

//�����ӿ�
public:
	CExBaseObject* AddNewData(const CString  strName, const CString  strID, long nPrecision);
	CExBaseObject* AddNewDatas(const CString  strName, const CString  strID);
	CRptArea* AddArea();

//��д���෽��
public:
	virtual UINT GetClassID() {        return RPTCLASSID_RPTITEM;             }     
	virtual BSTR GetXmlElementKey()  {      return CRptXmlRWKeys::g_pRptXmlRWKeys->m_strItemKey;     }
	
	virtual CExBaseObject* CreateNewChild(const CString &strClassID, BOOL &bAddToTail);
	virtual CExBaseObject* CreateNewChild(long nClassID);
	virtual void InitAfterRead();
};
