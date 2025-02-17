#pragma once

//功能描述 试验报告区域对象，子对象为CRptBkmk

#include "ReportTemplateDefine.h"
#include "RptBkmk.h"

class CRptArea :	public CExBaseList
{
public:
	CRptArea(void);
	virtual ~CRptArea(void);

//属性
public:
	CRptBkmk *m_pBkmkBegin;
	CRptBkmk *m_pBkmkEnd;

//公共接口
public:
// 	CExBaseObject* AddNew();					//新建标签对象,根据特定的规则自动生成IRptBkmk的标签
// 	CExBaseObject* AddNew2(const CString  strRptBkmk);

	//重写父类方法
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
