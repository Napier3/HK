#pragma once

//功能描述 用来管理映射文件

#include "ReportTemplateDefine.h"
#include "RptData.h"

class CReportMap : public CExBaseList
{
public:
	CReportMap(void);
	CReportMap(const CString strFilePath);
	virtual ~CReportMap(void);

//属性
public:
	CString  m_strFilePath;

private:
	//为FindBkmk调用；
	CExBaseObject* FindBkmkInList(const CString&  strBkmk,CExBaseList* pList);

	CExBaseList *m_pGuideBookRef;

//公共接口
public:
	
	CExBaseObject* FindBkmk(const CString  strBkmk);

	void InsertBkmk(const CString  strBkmk);
	CExBaseObject* FindItemByID(const CString  strID);//可以查找的有Items，Item，Datas，Data
	CExBaseObject* FindItem(long nIndex);
	
	//与文件相关
	void Open(const CString  strFilePath);
	void SaveAs(const CString  strFilePath);
	void Save();
	void Save(const CString  strFilePath);

	//关联作业指导书对象，为每一个报告节点对应GbItem对象
	void AttachGuideBook(CExBaseList *pGuideBook);  

//重写父类方法
public:
	virtual UINT GetClassID() {        return RPTCLASSID_RPTREPORTMAP;             }     
	virtual BSTR GetXmlElementKey()  {      return CRptXmlRWKeys::g_pRptXmlRWKeys->m_strMapFileKey;     }
	virtual CExBaseObject* CreateNewChild(const CString &strClassID, BOOL &bAddToTail);
	virtual CExBaseObject* CreateNewChild(long nClassID);

};


//CExBaseObject* _FindTheItemByID(CExBaseList *pList, CString strID);