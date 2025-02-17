#pragma once
//功能描述 试验报告数据集合对象，子对象为IRptDatas、IRptData
#include "ReportTemplateDefine.h"
#include "RptArea.h"

class CRptItem :	public CExBaseList
{
public:
	CRptItem(void);
	CRptItem(const CString  strName, const CString  strID, long bSelect = 0);
	virtual ~CRptItem(void);

//属性
public:
	CRptArea *m_pArea;
	CExBaseList *m_pGbItemRef;

//公共接口
public:
	CExBaseObject* AddNewData(const CString  strName, const CString  strID, long nPrecision);
	CExBaseObject* AddNewDatas(const CString  strName, const CString  strID);
	CRptArea* AddArea();

//重写父类方法
public:
	virtual UINT GetClassID() {        return RPTCLASSID_RPTITEM;             }     
	virtual BSTR GetXmlElementKey()  {      return CRptXmlRWKeys::g_pRptXmlRWKeys->m_strItemKey;     }
	
	virtual CExBaseObject* CreateNewChild(const CString &strClassID, BOOL &bAddToTail);
	virtual CExBaseObject* CreateNewChild(long nClassID);
	virtual void InitAfterRead();
};
