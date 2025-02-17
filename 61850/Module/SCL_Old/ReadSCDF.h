#include "stdatadef.h"
#include "CXml/Xml.h"
#include "CXml/XmlNode.h"
#include "CXml/XmlNodes.h"
#include "CXml/Xsl.h"

#include "..\..\..\Module\BaseClass\ThreadProgressInterface.h"
#include "ScdDataDefine.h"
using namespace JWXml;

#pragma once

// �˽ṹ��ֻCReadSCDF���õ�
/*
typedef struct _tagShowIEDR
{	
	CString iedName;
	CString iedDesc;
	CXmlNodePtr iedNodePtr;

	CONTAINER_LIST_TYPE(SCGSDATA) list_gooseoutput;
	CONTAINER_LIST_TYPE(SCGSDATA) list_smvoutput;

}SHOWIEDR,*PSHOWIEDR;

typedef std::tr1::shared_ptr<SHOWIEDR> ShowIEDRPtr;
typedef map<CString, SHARED_PTR(SHOWIEDR)> SHOWIEDMAP;
typedef map<CString, SHARED_PTR(CLIENTIED)> CLIENTIEDMAP;
*/

class CShowIEDR : public CScdDataBase
{
public:
	CShowIEDR()	{};
	virtual ~CShowIEDR()	
	{

	}
	virtual UINT GetClassID()	{	return SCDDATA_CShowIEDR;	}
	CString iedName;
	CString iedDesc;
	CXmlNodePtr iedNodePtr;

	CScdDataList list_gooseoutput;
	CScdDataList list_smvoutput;
};

typedef CShowIEDR SHOWIEDR,*PSHOWIEDR;
typedef CShowIEDR* ShowIEDRPtr;


typedef CScdDataMapList SHOWIEDMAP;
typedef CScdDataMapList CLIENTIEDMAP;
typedef map<CString, CXmlNodePtr> CStringXmlNodePtrMap;

//*************************ReadSCDF***************************

class CReadSCDF
{
public:
	CReadSCDF(void);
	virtual ~CReadSCDF(void);

	CScdDataMapList m_showiedleft;
private:
	// �����ռ�
	CString m_strNameSpace;
	CXml m_xmlfile;
	CXmlNodePtr m_xmlroot;
	CXmlNodePtr m_xmlDTT;
	CStringXmlNodePtrMap m_LNodeType,m_DAType,m_DOType;

//��ȡ������ʾ
protected:
	CThreadProgressInterface *m_pReadProgress;
	void StepIt()
	{
		if (m_pReadProgress != NULL)
		{
			m_pReadProgress->Step();
		}
	}
	void ShowInfor(const CString &strInfor)
	{
		if (m_pReadProgress != NULL)
		{
			m_pReadProgress->ShowMsg(strInfor);
		}
	}
public:
	void AttachThreadProgress(CThreadProgressInterface *p)	{	m_pReadProgress = p;	}

public:
	BOOL OpenSCDFile(LPCTSTR lpszXmlFilePath);
	CString GetXmlFile(void) const;
	void Close();
	// ��ȡ��Ҫ��Ϣ
	BOOL GetIEDNeedInfo(std::list<CString>& IEDName,CScdDataMapList &ClientIEDMap);
	
	// ��ȡGOOSEOUT����
	UINT GetGooseOutSize(LPCTSTR strIEDName);
	UINT GetSMVOutSize(LPCTSTR strIEDName);

	// ����������ȡGOOSEOUT���ƿ�����
	BOOL GetGooseOutData(LPCTSTR IEDName,UINT nIndex,CScdDataList &list_GooseOut);//CONTAINER_LIST_TYPE(GOOSEOUT)& list_GooseOut);
	BOOL GetSMVOutData(LPCTSTR IEDName,UINT nIndex,CScdDataList &list_SMVOut);//CONTAINER_LIST_TYPE(SMVOUT)& list_SMVOut);

	// ��ȡ����ied����ϸ����
	void GetIEDInData(LPCTSTR strIEDName, CScdDataMapList &ClientMap);
	//void GetIEDSMVInData(const CSmvIn &smvInPtr,const CXmlNodePtr& iedNodePtr);

	// ���Ҵ�IED�Ƿ���SMV������GOOSE����
	void CheckIEDSMVAndGSEInput(LPCTSTR strIEDName,CScdDataMapList &ClientMap,UINT& nGSE,UINT& nSMV);

private:
	void GetAllIEDName(std::list<CString>& IEDName);

	void GetIEDGOOSEOutData(GOOSEOUTPtr gooseOutPtr,SCGSDATAPtr scgsDataPtr,const CXmlNodePtr& iedNodePtr);
// 	void GetIEDGOOSEOutData(const GOOSEOUTPtr& gooseOutPtr,const SCGSDATAPtr scgsDataPtr,const CXmlNodePtr& iedNodePtr);
	BOOL GetIEDSMVOutData(const SMVOUTPtr& smvOutPtr,const SCGSDATAPtr scgsDataPtr,const CXmlNodePtr& iedNodePtr);
	void GetSCGSData(SCGSDATA& scgsData,CSCGSData& scgsDataPtr);

	//Communication
	void ReadConnectedAP(const CXmlNodePtr& ConNodePtr);
	void ReadGSE(const CXmlNodePtr& gsDataPtr,CSCGSData& scgsDataPtr);
	void ReadSMV(const CXmlNodePtr& gsDataPtr,CSCGSData& scgsDataPtr);
	void ReadCommunication(const CXmlNodePtr& CommNodePtr);
	void ReadSubNetWork(const CXmlNodesPtr& ConNodesPtr);
	void ReadAddress(const CXmlNodePtr& AddressNodePtr,SCGADDRESS& scgaddress);

	void ReadFCDA(const CXmlNodePtr& FCDANodePtr, const FCDAPtr& fcdaPtr);
	void ReadExtRef(const CXmlNodePtr& ExtRefNodePtr, EXTREFPtr extrefPtr);
	// ��ȡIED������������
	void ReadIEDNameAndDesc(const CXmlNodePtr& iedNodePtr,ShowIEDRPtr iedPtr);
	// ��ȡ��Ҫ��Ϣ
	BOOL ReadNeedInfo(std::list<CString>& IEDName);

	//
	void ReadLNodeType(const CXmlNodePtr& LNTNodePtr,CString& idClass);
	void ReadDOType(const CXmlNodePtr& DOTypeNodePtr,CString& id);
	void ReadEnumType(const CXmlNodePtr& ETNodePtr,const ENUMTYPEPtr& enumtypePtr);
	void ReadDAType(const CXmlNodePtr& DOTypeNodePtr,CString& id);
};


/************************************************************************/
/*               CReadSCDF��ʹ�÷���                                     */
/*1����XML�ļ�OpenSCDFile();                                           */       
/*2�����ЩIED�Ƿ���SMV�Լ�GOOSE�������                                    */
/*   CheckIEDSMVAndGSEInput,CheckIEDSMVAndGSEOutput
/*3����ȡIED��GOOSE���룬���������(��Ϊ��IED���޷������Ƿ�SMV����GOOSE���룬����)
/*   ֻ����һ�������ڻ�ȡSMV��GOOSE���롣*/
/************************************************************************/

BOOL st_IsInLoadScdXmlFile();
