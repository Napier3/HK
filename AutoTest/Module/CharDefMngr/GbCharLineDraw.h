//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//GbCharLineDraw.h  CGbCharLineDraw

#pragma once

#include "GbCharDefMngrGlobal.h"



class CGbCharLineDraw : public CExBaseObject
{
public:
	CGbCharLineDraw();
	virtual ~CGbCharLineDraw();


	CString  m_strXbid;
	CString  m_strYbid;
	CString  m_strXeid;
	CString  m_strYeid;
//重载函数
public:
	virtual UINT GetClassID() {    return CHRCLASSID_CGBCHARLINEDRAW;   }
	virtual BSTR GetXmlElementKey()  {      return CGbCharDefMngrXmlRWKeys::CGbCharLineDrawKey();     }
	virtual long XmlReadOwn(const MSXML2::IXMLDOMNodePtr &oNode, CXmlRWKeys *pXmlRWKeys);
	virtual long XmlWriteOwn(const MSXML2::IXMLDOMDocumentPtr &oXMLDoc, const MSXML2::IXMLDOMElementPtr &oElement, CXmlRWKeys *pXmlRWKeys);
	virtual long SerializeOwn(CBinarySerialBuffer &oBinaryBuffer);
	virtual BOOL IsEqualOwn(CBaseObject* pObj);
	virtual BOOL CopyOwn(CBaseObject* pDest);
	virtual CBaseObject* Clone();

//私有成员变量
private:

//私有成员变量访问方法
public:
};

