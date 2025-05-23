//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//GoutRule.h  CGoutRule

#pragma once

#include "IecfgGenMngrGlobal.h"

#include "Bout.h"
#include "CtrlBlock.h"

class CGoutRule : public CExBaseList
{
public:
	CGoutRule();
	virtual ~CGoutRule();


//重载函数
public:
	virtual UINT GetClassID() {    return MNGRCLASSID_CGOUTRULE;   }
	virtual BSTR GetXmlElementKey()  {      return CIecfgGenMngrXmlRWKeys::CGoutRuleKey();     }
	virtual long XmlReadOwn(CXmlRWNodeBase &oNode, CXmlRWKeys *pXmlRWKeys);
	virtual long XmlWriteOwn(CXmlRWDocBase &oXMLDoc, CXmlRWElementBase &oElement, CXmlRWKeys *pXmlRWKeys);
	virtual long SerializeOwn(CBinarySerialBuffer &oBinaryBuffer);
	virtual void InitAfterRead();
	virtual BOOL IsEqualOwn(CBaseObject* pObj);
	virtual BOOL CopyOwn(CBaseObject* pDest);
	virtual CBaseObject* Clone();
	virtual CBaseObject* CloneEx(BOOL bCopyOwn=TRUE, BOOL bCopyChildren=FALSE);
	virtual BOOL CanPaste(UINT nClassID);
	virtual CExBaseObject* CreateNewChild(const CString &strClassID, BOOL &bAddToTail, CXmlRWKeys *pXmlRWKeys);
	virtual CExBaseObject* CreateNewChild(long nClassID/*, BOOL &bAddToTail*/);
	virtual BSTR DB_GetOwnTableName(CXmlRWKeys *pXmlRWKeys)  {      return CIecfgGenMngrXmlRWKeys::CGoutRuleKey();     }

//私有成员变量
private:

//私有成员变量访问方法
public:

//属性变量访问方法
public:
	BOOL GenarateIecCfgGoutDatas(CIecCfgGoutDatas* pGoutMngr);
	BOOL GenerateIecCfgDatas_Bout(CIecCfgGoutDatas* pGoutMngr);
};

