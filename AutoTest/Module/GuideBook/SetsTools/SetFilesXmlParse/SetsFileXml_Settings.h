//���Դ������ClassGenerator����
//��Ȩ���� LiJunqing  lijunqing1224@126.com
//��������Ȩ��

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


	CString  m_strLd;   //��ֵ����LD��ʵ����
	CString  m_strClass;   //��ֵ�������ݼ�����ȥ�����ֺ�׺
	long  m_nInfoGrpNum;  //��ֵ������
	long  m_nGrp;  //������ֵ����ֵ��������ֵ�����Բ�������������ֵ�Ͷ�����ֵ�ɶ�ֵ������ϢInfoGrp�е�setGrpNum���Ծ�����setGrpNumΪ1ʱ��ʾ���鶨ֵΪ������ֵ����
	CString m_strMd5_Cal;   //����õ���MD5
//���غ���
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

//˽�г�Ա����
private:

//˽�г�Ա�������ʷ���
public:

//���Ա������ʷ���
public:
	void ParseToDvm(CDvmLogicDevice *pLDevice);
	//����ֵ���ݣ�ƴ�ӳ�һ�����ַ������أ����ڼ���Md5ֵ
	void GetValStringTotal(CString &strValTotal);
	void GetMd5_ForCal(CString &strMd5, const CString &strValTotal);
};

