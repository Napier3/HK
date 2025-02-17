#pragma once

//功能描述 报告中的位置定义,对于Word/WPS来说为书签
#include "ReportTemplateDefine.h"

class CRptBkmk :	public CExBaseObject
{
public:
	CRptBkmk(void);
	~CRptBkmk(void);

//属性
public:
	long m_dwIndex;		//索引，标签后的数字
	void GetIndexFromID();

//重写父类函数
public:
	virtual UINT GetClassID()													{        return RPTCLASSID_RPTBKMK;												}  
	virtual BSTR GetXmlElementKey()								{      return CRptXmlRWKeys::g_pRptXmlRWKeys->m_strBkmkKey;		}
	virtual long XmlReadOwn(const MSXML2::IXMLDOMNodePtr &oNode, CXmlRWKeys *pXmlRWKeys);
	virtual long XmlWriteOwn(const MSXML2::IXMLDOMDocumentPtr &oXMLDoc, const MSXML2::IXMLDOMElementPtr &oElement, CXmlRWKeys *pXmlRWKeys);
	virtual long SerializeOwn(CBinarySerialBuffer &oBinaryBuffer);

	virtual BOOL CopyOwn(CBaseObject* pDest);
	virtual CBaseObject* Clone();
};

CExBaseList* _FindRptBkmkByID(CExBaseList *pList, const CString &strID, CExBaseList *pListDest);
