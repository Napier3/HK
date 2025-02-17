//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//SetFilesXml_DSC.h  CSetFilesXml_DSC

#pragma once

#include "SetFileXmlParseGlobal.h"


#include "SetsFileXml_Header.h"
#include "SetsFileXml_HashInfo.h"
#include "SetsFileXml_DevInfo.h"
#include "SetsFileXml_FileInfo.h"
#include "SetsFileXml_Settings.h"
#include "SetsFileXml_Remark.h"
#include "..\..\..\..\..\Module\DataMngr\DvmLogicDevice.h"

class CSetFilesXml_DSC : public CExBaseList
{
public:
	CSetFilesXml_DSC();
	virtual ~CSetFilesXml_DSC();


	CString  m_strConfigVersion;

	long m_nSetsZone;   //从文件中解析到的当前定值区号
	CDvmLogicDevice *m_pLDevice;

	CString m_strMd5_Cal_Parameter;   //计算获得的MD5
	CString m_strMd5_Cal_Setting;   //计算获得的MD5
	CString m_strMd5_Cal_Ena;   //计算获得的MD5
//重载函数
public:
	virtual UINT GetClassID() {    return MNGRCLASSID_CSETFILESXML_DSC;   }
	virtual BSTR GetXmlElementKey()  {      return CSetFileXmlParseXmlRWKeys::CSetFilesXml_DSCKey();     }
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
	CSetsFileXml_Header *m_pHeader;
	CSetsFileXml_HashInfo *m_pHashInfo;
	CSetsFileXml_DevInfo *m_pDevInfo;
	CSetsFileXml_FileInfo *m_pFileInfo;

//私有成员变量访问方法
public:
	CSetsFileXml_Header* GetHeader()	{	return m_pHeader;	}
	void SetHeader(CSetsFileXml_Header* pHeader)	{	m_pHeader = pHeader;	}
	CSetsFileXml_HashInfo* GetHashInfo()	{	return m_pHashInfo;	}
	void SetHashInfo(CSetsFileXml_HashInfo* pHashInfo)	{	m_pHashInfo = pHashInfo;	}
	CSetsFileXml_DevInfo* GetDevInfo()	{	return m_pDevInfo;	}
	void SetDevInfo(CSetsFileXml_DevInfo* pDevInfo)	{	m_pDevInfo = pDevInfo;	}
	CSetsFileXml_FileInfo* GetFileInfo()	{	return m_pFileInfo;	}
	void SetFileInfo(CSetsFileXml_FileInfo* pFileInfo)	{	m_pFileInfo = pFileInfo;	}

//属性变量访问方法
public:
	void ParseToDvm();
	CSetsFileXml_Settings* FindSettingsByClass(const CString &strClass);
	void GetSettingsValTotl(CString &strValTotal);
	void GetSettingsValTotl(const CString &strClass, CString &strValTotal);
	//返回定值单文件中的哈希值
	void GetMd5_FromFile(const CString &strClass, CString &strMd5);
	void GetMd5_FromCal(const CString &strClass, CString &strMd5);
};

