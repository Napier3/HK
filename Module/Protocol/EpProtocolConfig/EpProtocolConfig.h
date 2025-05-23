//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//EpProtocolConfig.h  CEpProtocolConfig

#pragma once

#include "EpProtocolConfigGlobal.h"


#include "Ep101Config.h"
#include "Ep104Config.h"

class CEpProtocolConfig : public CExBaseList
{
public:
	CEpProtocolConfig();
	virtual ~CEpProtocolConfig();


//重载函数
public:
	virtual UINT GetClassID() {    return EPCCLASSID_CEPPROTOCOLCONFIG;   }
	virtual BSTR GetXmlElementKey()  {      return CEpProtocolConfigXmlRWKeys::CEpProtocolConfigKey();     }
	virtual long XmlReadOwn(const MSXML2::IXMLDOMNodePtr &oNode, CXmlRWKeys *pXmlRWKeys);
	virtual long XmlWriteOwn(const MSXML2::IXMLDOMDocumentPtr &oXMLDoc, const MSXML2::IXMLDOMElementPtr &oElement, CXmlRWKeys *pXmlRWKeys);
	virtual long SerializeOwn(CBinarySerialBuffer &oBinaryBuffer);
	virtual void InitAfterRead();
	virtual BOOL IsEqualOwn(CBaseObject* pObj);
	virtual BOOL CopyOwn(CBaseObject* pDest);
	virtual CBaseObject* Clone();
	virtual BOOL CanPaste(UINT nClassID);
	virtual CExBaseObject* CreateNewChild(const CString &strClassID, BOOL &bAddToTail, CXmlRWKeys *pXmlRWKeys);
	virtual CExBaseObject* CreateNewChild(long nClassID/*, BOOL &bAddToTail*/);

//私有成员变量
private:
	CEp101Config *m_p101Config;
	CEp104Config *m_p104Config;

//私有成员变量访问方法
public:
};

