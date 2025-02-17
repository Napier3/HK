#pragma once
//�������� ���鱨�����ݼ��϶����Ӷ���ΪIRptItem��IRptItems��IRptDatas��IRptData
#include "ReportTemplateDefine.h"
#include "RptItem.h"

class CRptItems : public CRptItem
{
public:
	CRptItems(void);
	CRptItems(const CString  strName, const CString  strID);
	virtual ~CRptItems(void);

//�����ӿ�
public:
	CExBaseObject* AddNewItem(const CString  strName, const CString  strID);
	CExBaseObject* AddNewItems(const CString  strName, const CString  strID);

//��д���ຯ��
public:
	virtual UINT GetClassID() {        return RPTCLASSID_RPTITEMS;             }     
	virtual BSTR GetXmlElementKey()  {      return CRptXmlRWKeys::g_pRptXmlRWKeys->m_strItemsKey;     }

	virtual CExBaseObject* CreateNewChild(const CString &strClassID, BOOL &bAddToTail);
	virtual CExBaseObject* CreateNewChild(long nClassID);

	virtual void InitAfterRead();

};
