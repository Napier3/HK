#pragma once
#include "StUICfg.h"
#include "ReadSCDF.h"


typedef struct _tagComInfo
{
	CString appid;
	CString gocbref;
	CString mac;
	CString dataset;
	CString goid;
}COMINFO;

class CSaveShareFile
{
public:
	CSaveShareFile(void);
	virtual ~CSaveShareFile(void);

public:
	void SaveToGoose(UINT nType);
	void SaveToSMV(UINT nType);
	void InitAddToGooseCfg(GSECFG& gsecfg,const GOOSEOUTPtr& GooseOutPtr,LPCTSTR strDes);
	void InitAddToSMVCfg(MU_SETTING& musetting, const SMVOUTPtr& SMVOutPtr, LPCTSTR strDes);
	BOOL IsAddToGooseVector(const COMINFO& ComInfo);
	void InitGooseVector();
	void InitSMVVectro();
	void InitVector();
private:
	void CreateTempFile(CString& fileName);
	void SaveGoooseFile(const CXmlNodePtr& gNoodPtr,const CString& NodeName);
	void SaveGOOSEChnCfgXML(const CXmlNodePtr& chnNoodPtr,const vector<GSECHNCFG>& gsechncfg,const CString& NodeName);

	void SaveSMVFile(const CXmlNodePtr& gNoodPtr,const CString& NodeName);
	void SaveSMVChnCfgXML(const CXmlNodePtr& chnNoodPtr,const vector<MU_CHNSET>& mu_chnset,const CString& NodeName);

	vector<GSECFG> m_gsecfg;
	vector<MU_SETTING> m_mucfg;

	int m_nSMVType;

};

