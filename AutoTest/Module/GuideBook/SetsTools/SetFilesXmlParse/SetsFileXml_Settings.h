//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//SetsFileXml_Settings.h  CSetsFileXml_Settings

#pragma once

#include "SetFileXmlParseGlobal.h"


#include "SetsFileXml_InfoGrp.h"
#include "..\..\..\..\..\Module\DataMngr\DvmLogicDevice.h"

class CSetsFileXml_Settings : public CExBaseList
{
public:
	CSetsFileXml_Settings();
	virtual ~CSetsFileXml_Settings();


	CString  m_strLd;   //定值归属LD的实例名
	CString  m_strClass;   //定值所处数据集名称去掉数字后缀
	long  m_nInfoGrpNum;  //定值分组数
	long  m_nGrp;  //多区定值区号值，单区定值该属性不声明（单区定值和多区定值由定值分组信息InfoGrp中的setGrpNum属性决定，setGrpNum为1时表示该组定值为单区定值）。
	CString m_strMd5_Cal;   //计算得到的MD5
//重载函数
public:
	virtual UINT GetClassID() {    return MNGRCLASSID_CSETSFILEXML_SETTINGS;   }
	virtual BSTR GetXmlElementKey()  {      return CSetFileXmlParseXmlRWKeys::CSetsFileXml_SettingsKey();     }
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
	void ParseToDvm(CDvmLogicDevice *pLDevice);
	//将定值数据，拼接成一个大字符串返回，用于计算Md5值
	void GetValStringTotal(CString &strValTotal);
	void GetMd5_ForCal(CString &strMd5, const CString &strValTotal);
};

