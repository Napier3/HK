#include "stdatadef.h"
#include "CXml/Xml.h"
#include "CXml/XmlNode.h"
#include "CXml/XmlNodes.h"
#include "CXml/Xsl.h"
using namespace JWXml;

const long XMLVERSION = 20120709;
const long XMLVERSION_1 = 20120306;
// 发送比例
#define SEND_PROORTION 10000

#define ADDCHILDSETVALUE(NoodPtr,childName,value,childPtr) \
	childPtr = NoodPtr->NewChild(childName); \
	if (!childPtr->IsNull()) \
	{ \
	childPtr->SetValue(value); \
	} \

#define  ADDCHILDSETATTR(NoodPtr,childName,attrName,attrValue,childPtr) \
	childPtr = NoodPtr->NewChild(childName); \
	if (!childPtr->IsNull()) \
	{ \
	childPtr->SetAttribute(attrName,attrValue); \
	} \

#define READCHILDVALUE(NoodPtr,childName,outvalue,invalue,childPtr) \
	childPtr = NoodPtr->GetChild(childName,FALSE); \
	if (!childPtr->IsNull()) \
	{ \
	outvalue = childPtr->GetValue(invalue); \
	} \

#define READCHILDVALUEEX(NoodPtr,childName,outvalue,invalue,childPtr,defvalue) \
	childPtr = NoodPtr->GetChild(childName,FALSE); \
	if (!childPtr->IsNull()) \
	{ \
	outvalue = childPtr->GetValue(invalue); \
	}else  \
	{ \
	outvalue = defvalue; \
	} \


#define READCHILDATTR(NoodPtr,childName,outvalue,invalue,childPtr) \
	childPtr = NoodPtr->GetChild(childName,FALSE); \
	if (!childPtr->IsNull()) \
	{ \
	outvalue = childPtr->GetAttribute(invalue); \
} \

#pragma once
class CStUICfg
{
public:
	CStUICfg(BOOL bSaveCfgFlg);
	virtual ~CStUICfg(void);

public:
	/************************************************************************/
	/* zy 用于判断是否存储通道数据											*/
	/************************************************************************/
	BOOL m_bSaveCfgFlg;	
	long m_nVersion;  // 版本号

private:
	void SaveMUChnCfgXML(const CXmlNodePtr& chnNoodPtr,const vector<MU_CHNSET>& mu_chnset,const CString& NodeName);
	void SaveGOOSEChnCfgXML(const CXmlNodePtr& chnNoodPtr,const vector<GSECHNCFG>& gsechncfg,const CString& NodeName);
	void SaveMUMSGTestSetXML(const CXmlNodePtr& NodePtr, const MSGTESTSETPtr& MuPtr);
	void SaveMUMSGCfgDataXml(const CXmlNodePtr& NodePtr, const MuCfgData *ChDataPtr, int nSize, CString NodeNames);

	// 初始化报文测试参数 【zy 2012-4-12】 
	void InitMSGTestSet(const MSGTESTSETPtr& msgtestsetptr);

	void ReadMUMSGTestSetXML(const CXmlNodePtr& NodePtr,MSGTESTSETPtr& MuPtr);
	void ReadMUChnCfgXML(const CXmlNodePtr& chnNoodPtr,vector<MU_CHNSET>& mu_chnset,const CString& NodeName);
	void ReadGOOSEChnCfgXML(const CXmlNodePtr& chnNoodPtr,vector<GSECHNCFG>& gsechncfg,const CString& NodeName);
	void ReadMUMSGCfgDataXml(const CXmlNodePtr& NodePtr, MuCfgData *ChDataPtr, int nSize, CString NodeName);

	

	/************************************************************************/
	/* zy 2012-4-12 初始化Goose报文测试数据									*/
	/************************************************************************/
	void InitGseTestSet(const GsePktTestSetPtr& GsePtr);
	/************************************************************************/
	/* zy 2012-4-12 保存Goose报文测试数据									*/
	/************************************************************************/
	void SaveGsePktTestSetXML(const CXmlNodePtr& NodePtr,const GsePktTestSetPtr& GsePtr);
	/************************************************************************/
	/* zy 2012-4-12 读Goose报文测试数据										*/
	/************************************************************************/
	void ReadGsePktTestSetXML(const CXmlNodePtr& NodePtr,GsePktTestSetPtr& GsePtr);

public:
	BOOL SaveF66CfgXML(LPCTSTR strPath,const MU_GENERALSETTTING& mu_gset, const GSEUI& gseui,
		const vector<MU_SETTING>& muset91, const vector<MU_SETTING>& muset92,
		const vector<MU_SETTING>& muset91Ex,const vector<MU_SETTING>& musetft3);
	BOOL ReadF66CfgXML(LPCTSTR strPath,MU_GENERALSETTTING& mu_gset,GSEUI& gseui,
		vector<MU_SETTING>& muset91, vector<MU_SETTING>& muset92,
		vector<MU_SETTING>& muset91Ex,vector<MU_SETTING>& musetft3);

	long GetF66XMLVersion();
	void InitMUCFGUIData(vector<MU_SETTING>& muset91, vector<MU_SETTING>& muset92,vector<MU_SETTING>& muset91Ex);

	// 新的XML存储结构增加映射类型，为兼容旧格式，增加转换函数
	void ConvertToNewData_XML(vector<MU_SETTING>& muset,int nSampleType);
	void ConvertToNewData_XML_24(vector<MU_SETTING>& muset,int nSampleType);
	void ConvertToNewData(MU_CHNSET& chnset, int nSampleType);
	void ConvertToNewData_24(MU_CHNSET& chnset, int nSampleType);

	void SaveMUCfgXML(const CXmlNodePtr& muNoodPtr,const vector<MU_SETTING>& mu_setting,const CString& NodeName);
	void ReadMUCfgXML(const CXmlNodePtr& muNoodPtr,vector<MU_SETTING>& mu_setting,const CString& NodeName);

	void SaveGOOSECfgXML(const CXmlNodePtr& gNoodPtr,const vector<GSECFG>& gsecfg,const CString& NodeName);
	void ReadGOOSECfgXML(const CXmlNodePtr& gNoodPtr,vector<GSECFG>& GseCfg,const CString& NodeName);

public:
	void SaveMUGerSet(const CXmlNodePtr& MUSetNodePtr, const MU_GENERALSETTTING& mu_gset);
	void ReadMUGerSet(const CXmlNodePtr& MUSetNodePtr, MU_GENERALSETTTING& mu_gset);

};
