//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//SetsFileXml_InfoGrp.h  CSetsFileXml_InfoGrp

#pragma once

#include "SetFileXmlParseGlobal.h"


#include "SetsFileXml_SI.h"
#include "..\..\..\..\..\Module\DataMngr\DvmDataset.h"

class CSetsFileXml_InfoGrp : public CExBaseList
{
public:
	CSetsFileXml_InfoGrp();
	virtual ~CSetsFileXml_InfoGrp();


	CString  m_strDesc;
	long  m_nSetGrpNum;
	long  m_nItemNum;
	long  m_nRemote;
//重载函数
public:
	virtual UINT GetClassID() {    return MNGRCLASSID_CSETSFILEXML_INFOGRP;   }
	virtual BSTR GetXmlElementKey()  {      return CSetFileXmlParseXmlRWKeys::CSetsFileXml_InfoGrpKey();     }
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

//私有成员变量
private:

//私有成员变量访问方法
public:

//属性变量访问方法
public:
	void ParseToDvm(CDvmDataset *pDataset, long nGrp);
	void GetValStringTotal(long nGrp, CString &strVal);
};

