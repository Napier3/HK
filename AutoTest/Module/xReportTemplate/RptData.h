#pragma once

//功能描述 试验报告数据对象，子对象为CRptBkmk
//代表试验过程中需要填入报告的一个数据，包含数据精度

#include "ReportTemplateDefine.h"

#define _RPTDATA_PRECISION_INIT -1

class CRptData :	public CExBaseList
{
public:
	CRptData(void);
	CRptData(const CString  strName, const CString  strID, long nPrecision);
	virtual ~CRptData(void);

//属性
public:
	long m_nPrecision;										//数据的精度，定义填写报告时使用
	CString m_strDataType;
	long m_nDataFill;

//公共接口
public:
//	CExBaseObject* AddNew();					//新建标签对象,根据特定的规则自动生成IRptBkmk的标签
	CExBaseObject* AddNew2(const CString  strRptBkmk);
	void SetPrecision(long nPrecision)				{		m_nPrecision = nPrecision;		}
	long GetPrecision()												{		return m_nPrecision;					}

	//重写父类方法
public:
	virtual UINT GetClassID()									{        return RPTCLASSID_RPTDATA;             }
	virtual BSTR GetXmlElementKey()				{      return CRptXmlRWKeys::g_pRptXmlRWKeys->m_strDataKey;     }
	virtual long XmlReadOwn(const MSXML2::IXMLDOMNodePtr &oNode, CXmlRWKeys *pXmlRWKeys);
	virtual long XmlWriteOwn(const MSXML2::IXMLDOMDocumentPtr &oXMLDoc, const MSXML2::IXMLDOMElementPtr &oElement, CXmlRWKeys *pXmlRWKeys);
	
	virtual long SerializeOwn(CBinarySerialBuffer &oBinaryBuffer);
	virtual CExBaseObject* CreateNewChild(const CString &strClassID, BOOL &bAddToTail);
	virtual CExBaseObject* CreateNewChild(long nClassID);

};
