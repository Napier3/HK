#pragma once

//功能描述 试验报告数据集合对象，子对象为CRptData

#include "ReportTemplateDefine.h"

class CRptDatas :	public CExBaseList
{
public:
	CRptDatas(void);
	CRptDatas(const CString  strName, const CString  strID);
	virtual ~CRptDatas(void);

//公共接口
public:
	CExBaseObject* AddNew(const CString  strName, const CString  strID, long nPrecision);

//重写父类方法
public:
	virtual UINT GetClassID() {        return RPTCLASSID_RPTDATAS;             }     
	virtual BSTR GetXmlElementKey()  {      return CRptXmlRWKeys::g_pRptXmlRWKeys->m_strDatasKey;	 }

	virtual CExBaseObject* CreateNewChild(const CString &strClassID, BOOL &bAddToTail);	
	virtual CExBaseObject* CreateNewChild(long nClassID);
};
