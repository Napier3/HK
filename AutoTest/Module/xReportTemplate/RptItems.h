#pragma once
//功能描述 试验报告数据集合对象，子对象为IRptItem、IRptItems、IRptDatas、IRptData
#include "ReportTemplateDefine.h"
#include "RptItem.h"

class CRptItems : public CRptItem
{
public:
	CRptItems(void);
	CRptItems(const CString  strName, const CString  strID);
	virtual ~CRptItems(void);

//公共接口
public:
	CExBaseObject* AddNewItem(const CString  strName, const CString  strID);
	CExBaseObject* AddNewItems(const CString  strName, const CString  strID);

//重写父类函数
public:
	virtual UINT GetClassID() {        return RPTCLASSID_RPTITEMS;             }     
	virtual BSTR GetXmlElementKey()  {      return CRptXmlRWKeys::g_pRptXmlRWKeys->m_strItemsKey;     }

	virtual CExBaseObject* CreateNewChild(const CString &strClassID, BOOL &bAddToTail);
	virtual CExBaseObject* CreateNewChild(long nClassID);

	virtual void InitAfterRead();

};
