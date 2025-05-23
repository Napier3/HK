#pragma once

#include "VerUpdateCfgMngrGlobal.h"

class CVerUpdateCfgYun : public CExBaseObject
{
public:
	CVerUpdateCfgYun();
	virtual ~CVerUpdateCfgYun();

private:
	CString m_strIP;
	long m_nPort;
	long m_nFtpPort;

	void Init();

	//���غ���
public:
	virtual UINT GetClassID() {    return VERUPDATECFGCLASSID_YUN;   }
	virtual BSTR GetXmlElementKey()  {      return CVerUpdateCfgXmlRWKeys::YunKey();     }
	virtual long XmlReadOwn(CXmlRWNodeBase &oNode, CXmlRWKeys *pXmlRWKeys);
	virtual long XmlWriteOwn(CXmlRWDocBase &oXMLDoc, CXmlRWElementBase &oElement, CXmlRWKeys *pXmlRWKeys);
	virtual long SerializeOwn(CBinarySerialBuffer &oBinaryBuffer);
	virtual BOOL IsEqualOwn(CBaseObject* pObj);
	virtual BOOL CopyOwn(CBaseObject* pDest);
	virtual CBaseObject* CloneEx(BOOL bCopyOwn=TRUE,BOOL bCopyChildren=FALSE);

public:
	CString GetIP()	{	return m_strIP;	  }
	long GetPort()	{	return m_nPort;	  }
	long GetFtpPort(){	return m_nFtpPort;	}

	void SetIP(const CString& strIP)	{	m_strIP = strIP;	}
	void SetPort(long nPort)	{	m_nPort = nPort;	}
	void SetFtpPort(long nFtpPort)	{	m_nFtpPort = nFtpPort;	}
};


