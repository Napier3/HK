//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//SetsFileXml_SI.h  CSetsFileXml_SI

#pragma once

#include "SetFileXmlParseGlobal.h"


#include "SetsFileXml_Val.h"
#include "..\..\..\..\..\Module\DataMngr\DvmDataset.h"

class CSetsFileXml_SI : public CExBaseList
{
public:
	CSetsFileXml_SI();
	virtual ~CSetsFileXml_SI();


	CString  m_strDesc;
	CString  m_strType;
	CString  m_strUnit;
	CString  m_strMin;
	CString  m_strMax;
	CString  m_strStep;
	CString  m_strRef;
//重载函数
public:
	virtual UINT GetClassID() {    return MNGRCLASSID_CSETSFILEXML_SI;   }
	virtual BSTR GetXmlElementKey()  {      return CSetFileXmlParseXmlRWKeys::CSetsFileXml_SIKey();     }
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
	CSetsFileXml_Val* GetValByGrp(long nGrp);
	CString GetValByGrp_String(long nGrp);
};

