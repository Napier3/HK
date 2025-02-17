//���Դ������ClassGenerator����
//��Ȩ���� LiJunqing  lijunqing1224@126.com
//��������Ȩ��

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

	long m_nSetsZone;   //���ļ��н������ĵ�ǰ��ֵ����
	CDvmLogicDevice *m_pLDevice;

	CString m_strMd5_Cal_Parameter;   //�����õ�MD5
	CString m_strMd5_Cal_Setting;   //�����õ�MD5
	CString m_strMd5_Cal_Ena;   //�����õ�MD5
//���غ���
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

//˽�г�Ա����
private:
	CSetsFileXml_Header *m_pHeader;
	CSetsFileXml_HashInfo *m_pHashInfo;
	CSetsFileXml_DevInfo *m_pDevInfo;
	CSetsFileXml_FileInfo *m_pFileInfo;

//˽�г�Ա�������ʷ���
public:
	CSetsFileXml_Header* GetHeader()	{	return m_pHeader;	}
	void SetHeader(CSetsFileXml_Header* pHeader)	{	m_pHeader = pHeader;	}
	CSetsFileXml_HashInfo* GetHashInfo()	{	return m_pHashInfo;	}
	void SetHashInfo(CSetsFileXml_HashInfo* pHashInfo)	{	m_pHashInfo = pHashInfo;	}
	CSetsFileXml_DevInfo* GetDevInfo()	{	return m_pDevInfo;	}
	void SetDevInfo(CSetsFileXml_DevInfo* pDevInfo)	{	m_pDevInfo = pDevInfo;	}
	CSetsFileXml_FileInfo* GetFileInfo()	{	return m_pFileInfo;	}
	void SetFileInfo(CSetsFileXml_FileInfo* pFileInfo)	{	m_pFileInfo = pFileInfo;	}

//���Ա������ʷ���
public:
	void ParseToDvm();
	CSetsFileXml_Settings* FindSettingsByClass(const CString &strClass);
	void GetSettingsValTotl(CString &strValTotal);
	void GetSettingsValTotl(const CString &strClass, CString &strValTotal);
	//���ض�ֵ���ļ��еĹ�ϣֵ
	void GetMd5_FromFile(const CString &strClass, CString &strMd5);
	void GetMd5_FromCal(const CString &strClass, CString &strMd5);
};

