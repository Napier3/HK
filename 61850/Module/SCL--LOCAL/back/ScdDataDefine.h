#pragma once

#include "..\..\..\Module\BaseClass\TStLinkList.h"

#define  SCDDATA_CBase   0x0001
#define  SCDDATA_CBaseList   0x0001
#define  SCDDATA_CExtRef   0x0001
#define  SCDDATA_CInputChn   0x0001
#define  SCDDATA_CGooseIn   0x0001
#define  SCDDATA_CGooseOutputChn   0x0001
#define  SCDDATA_CGooseOut   0x0001
#define  SCDDATA_CSmvIn   0x0001
#define  SCDDATA_CSMVOutputChn   0x0001
#define  SCDDATA_CSmvOut   0x0001
#define  SCDDATA_SCGSData   0x0001
#define  SCDDATA_CShowIEDR   0x0001
#define  SCDDATA_CSConnectedAP   0x0001
#define  SCDDATA_CClientIED   0x0001

class CScdDataBase
{
public:
	CScdDataBase()	{}
	virtual ~CScdDataBase()	{}
	virtual UINT GetClassID()	{	return SCDDATA_CBase;	}

};

class CScdDataList : public CScdDataBase , public TStLinkList<CScdDataBase> 
{
public:
	CScdDataList()	{}
	virtual ~CScdDataList()	{}
	virtual UINT GetClassID()	{	return SCDDATA_CBaseList;	}

	virtual void Append(CScdDataList &oListSrc)
	{
		TPOS pos = oListSrc.GetHeadPosition();
		CScdDataBase *pObj = NULL;

		while (pos != NULL)
		{
			pObj = oListSrc.GetNext(pos);
			AddTail(pObj);
		}
	}

};


class CScdDataMapBase
{
public:
	CScdDataMapBase(const CString &strID, CScdDataBase *pData)
	{
		m_strID = strID;
		m_pData = pData;
	}
	virtual ~CScdDataMapBase()	
	{
		delete m_pData;
	}

	CScdDataBase *m_pData;
	CString m_strID;
};

class CScdDataMapList : public TStLinkList<CScdDataMapBase> 
{
public:
	CScdDataMapList(){}
	virtual ~CScdDataMapList()	{	DeleteAll();	}
	
	void DeleteAllOnllyMap()
	{
		TPOS pos = GetHeadPosition();
		CScdDataMapBase *p = NULL;

		while (pos != NULL)
		{
			p = GetNext(pos);
			p->m_pData = NULL;
			delete p;
		}

		RemoveAll();
	}

	CScdDataMapBase* FindByID(const CString &strID)
	{
		TPOS pos = GetHeadPosition();
		CScdDataMapBase *p = NULL;
		CScdDataMapBase *pFind = NULL;

		while (pos != NULL)
		{
			p = GetNext(pos);

			if (p->m_strID == strID)
			{
				pFind = p;
				break;
			}
		}

		return pFind;
	}

	CScdDataBase* FindByID2(const CString &strID)
	{
		CScdDataMapBase *pFind = FindByID(strID);

		if (pFind != NULL)
		{
			return pFind->m_pData;
		}
		else
		{
			return NULL;
		}
	}

	CScdDataMapBase* AddNewMap(const CString &strID, CScdDataBase *pData)
	{
		CScdDataMapBase *pNew ;//= FindByID(strID);
	
		pNew = new CScdDataMapBase(strID, pData);
		AddTail(pNew);

// 		if (pNew == NULL)
// 		{
// 			pNew = new CScdDataMapBase(strID, pData);
// 			AddTail(pNew);
// 		}
// 		else
// 		{
// 			ASSERT(FALSE);
// 		}

		return pNew;
	}

	CScdDataBase* operator[](const CString &strID)
	{
		return FindByID2(strID);
	}

};



static const CString g_strSclTypeTitle_GIN = _T("GOOSE输入");
static const CString g_strSclTypeTitle_GOUT = _T("GOOSE输出");
static const CString g_strSclTypeTitle_SMVIN = _T("SMV输入");
static const CString g_strSclTypeTitle_SMVOUT = _T("SMV输出");

#define SCLTYPE_ID_GIN 2
#define SCLTYPE_ID_GOUT 0
#define SCLTYPE_ID_SMVIN 3
#define SCLTYPE_ID_SMVOUT 1

inline CString st_GetSclTypeTitle(UINT nSclType)
{
	switch(nSclType)
	{
	case SCLTYPE_ID_GIN:
		return g_strSclTypeTitle_GIN;
		break;
	case SCLTYPE_ID_GOUT:
		return g_strSclTypeTitle_GOUT;
		break;
	case SCLTYPE_ID_SMVIN:
		return g_strSclTypeTitle_SMVIN;
		break;
	case SCLTYPE_ID_SMVOUT:
		return g_strSclTypeTitle_SMVOUT;
		break;
	default:
		return _T("");
		break;
	}
}

inline BOOL st_IsSclTypeSmv(UINT nSclType)
{
	return ( (nSclType == SCLTYPE_ID_SMVIN) || (nSclType == SCLTYPE_ID_SMVOUT) );
}

inline BOOL st_IsSclTypeGoose(UINT nSclType)
{
	return ( (nSclType == SCLTYPE_ID_GIN) || (nSclType == SCLTYPE_ID_GOUT) );
}


// GOOSE输出通道 
class CGooseOutputChn : public CScdDataBase
{
public:
	CGooseOutputChn()	{}
	virtual ~CGooseOutputChn()	{}
	virtual UINT GetClassID()	{	return SCDDATA_CGooseOutputChn;	}

	int nIndex;
	int nType;
	CString strLNDes;
	CString strDOIDes;
	CString strDAIDes;
	CString strType;
	CString strAddress;
	CString strValue;

};
typedef CGooseOutputChn GOOSEOUTPUTCHN,*PGOOSEOUTPUTCHN;

// typedef struct _tagGooseOutputChn
// {
// 	int nIndex;
// 	int nType;
// 	CString strLNDes;
// 	CString strDOIDes;
// 	CString strDAIDes;
// 	CString strType;
// 	CString strAddress;
// 	CString strValue;
// }GOOSEOUTPUTCHN,*PGOOSEOUTPUTCHN;

// SMV输出通道 
class CSMVOutputChn : public CScdDataBase
{
public:
	CSMVOutputChn()	{}
	virtual ~CSMVOutputChn()	{}
	virtual UINT GetClassID()	{	return SCDDATA_CSMVOutputChn; }

	int nIndex;
	CString strLNDes;
	CString strDOIDes;
	CString strAddress;

};
typedef CSMVOutputChn SMVOUTPUTCHN,*PSMVOUTPUTCHN;
// typedef struct _tagSMVOutputChn
// {
// 	int nIndex;
// 	CString strLNDes;
// 	CString strDOIDes;
// 	CString strAddress;
// }SMVOUTPUTCHN,*PSMVOUTPUTCHN;

// SCL文件结构体
// Communication/SubNetWork/ConnnectedAP/GSE/Address
typedef struct _tagSCGAddress
{
	long VLanID;
	CString VLanpriority;
	CString MacAddress;
	CString AppID;
}SCGADDRESS,*PSCGADDRESS;

// Communication/SubNetWork/ConnnectedAP/GSEa or SMV
class CSCGSData : public CScdDataBase
{
public:
	CSCGSData()	{}
	virtual ~CSCGSData()	{}
	virtual UINT GetClassID()	{	return SCDDATA_SCGSData;	}

	int nType;			// 节点类型 GSE or SMV  0---GSE,1---SMV
	CString cbName;
	CString ldInst;
	CString strAPName;
	CString MinTime;
	CString MaxTime;

	SCGADDRESS address;
};
typedef CSCGSData SCGSDATA,*PSCGSDATA;
// typedef struct _tagSCGSData
// {
// 	int nType;			// 节点类型 GSE or SMV  0---GSE,1---SMV
// 	CString cbName;
// 	CString ldInst;
// 	CString strAPName;
// 	CString MinTime;
// 	CString MaxTime;
// 
// 	SCGADDRESS address;
// }SCGSDATA,*PSCGSDATA;


// Communication/SubNetWork/ConnnectedAP
class CSConnectedAP : public CScdDataBase
{
public:
	CSConnectedAP()	{}
	virtual ~CSConnectedAP()	{}
	virtual UINT GetClassID()	{	return SCDDATA_CSConnectedAP;	}

	CString iedName;
	CString apName;
	CString desc;

	CScdDataList listgsData;

};

typedef CSConnectedAP SCONNECTEDAP,*PSCONNECTEDAP;
// typedef struct _tagSConnectedAP
// {
// 
// 	CString iedName;
// 	CString apName;
// 	CString desc;
// 
// 	// Address节点暂不添加
// 	// GSE 节点
// 	CONTAINER_LIST_TYPE(SCGSDATA) listgsData;
// }SCONNECTEDAP,*PSCONNECTEDAP;


// IED 描述
class CDAI : public CScdDataBase
{
public:
	CDAI(){}
	virtual ~CDAI(){}

	CString desc;
	CString name;
	CString sAddr;
	CString valKind;
	CString ix;
};
typedef CDAI DAI,*PDAI;
// 
// typedef struct _tagDAI
// {
// 	CString desc;
// 	CString name;
// 	CString sAddr;
// 	CString valKind;
// 	CString ix;
// }DAI,*PDAI;

class CSDI : public CScdDataList
{
public:
	CSDI(){}
	virtual ~CSDI(){}

	CString desc;
	CString name;
	CString ix;
};
typedef CSDI SDI,*PSDI;;
// typedef struct _tagSDI
// {
// 	CString desc;
// 	CString name;
// 	CString ix;
// 
// 	CONTAINER_LIST_TYPE(DAI) listDAI;
// 
// }SDI,*PSDI;

class CDOI : public CScdDataBase
{
public:
	CDOI(){sdiPtr=NULL;}
	virtual ~CDOI(){	if (sdiPtr != NULL) delete sdiPtr;	sdiPtr = NULL;	}

	CString desc;
	CString name;
	CString Ix;
	CString accesscontrol;

	CScdDataList listDAI;
	PSDI sdiPtr;
};
typedef CDOI DOI,*PDOI;
// typedef struct _tagDOI
// {
// 	CString desc;
// 	CString name;
// 	CString Ix;
// 	CString accesscontrol;
// 
// 	CONTAINER_LIST_TYPE(DAI) listDAI;
// 	SHARED_PTR(SDI) sdiPtr;
// 
// }DOI,*PDOI;

class CSampledValueControl : public CScdDataBase
{
public:
	CSampledValueControl(){}
	virtual ~CSampledValueControl(){}

	CString smVID;
	CString desc;
	CString multicase;
	CString nofASDU;
	CString confRev;
	CString smpRate;
	CString datSet;
	CString name;

};
typedef CSampledValueControl SAMPLEDVALUECONTROL,*PSAMPLEDVALUECONTROL;
// typedef struct _tagSampledValueControl
// {
// 	CString smVID;
// 	CString desc;
// 	CString multicase;
// 	CString nofASDU;
// 	CString confRev;
// 	CString smpRate;
// 	CString datSet;
// 	CString name;
// }SAMPLEDVALUECONTROL,*PSAMPLEDVALUECONTROL;

class CGSEControl : public CScdDataBase
{
public:
	CGSEControl(){}
	virtual ~CGSEControl(){}

	CString desc;
	CString appID;
	CString confRev;
	CString type;
	CString datSet;
	CString name;

};
typedef CGSEControl GSECONTROL,*PGSECONTROL;

// typedef struct _tagGSEControl
// {
// 	CString desc;
// 	CString appID;
// 	CString confRev;
// 	CString type;
// 	CString datSet;
// 	CString name;
// 
// }GSECONTROL,*PGSECONTROL;

class CFCDA : public CScdDataBase
{
public:
	CFCDA(){}
	virtual ~CFCDA(){}

	int nIndex;
	CString doName;
	CString lnInst;
	CString daName;
	CString ldInst;
	CString fc;
	CString lnClass;
	CString prefix;
};
typedef CFCDA FCDA,*PFCDA;
// typedef struct _tagFCDA 
// {
// 	int nIndex;
// 	CString doName;
// 	CString lnInst;
// 	CString daName;
// 	CString ldInst;
// 	CString fc;
// 	CString lnClass;
// 	CString prefix;
// }FCDA,*PFCDA;

class CDataSet : public CScdDataList
{
public:
	CDataSet(){}
	virtual ~CDataSet()	{}

	CString desc;
	CString name;
};
typedef CDataSet DATASET,*PDATASET;

// typedef struct _tagDataSet
// {
// 	CString desc;
// 	CString name;
// 	
// 	CONTAINER_LIST_TYPE(FCDA) listFcda;
// }DATASET,*PDATASET;

// class CExtRef : public CScdDataBase
// {
// public:
// 	CExtRef()	{}
// 	virtual ~CExtRef()	{};
// 	virtual UINT GetClassID()	{	return SCDDATA_CExtRef;	}
// 	CString prefix;
// 	CString intAddr;
// 	CString doName;
// 	CString lnInst;
// 	CString iedName;
// 	CString daName;
// 	CString ldInst;
// 	CString lnClass;
// };

class CExtRef : public CScdDataBase
{
public:
	CExtRef(){}
	virtual ~CExtRef(){}

	CString prefix;
	CString intAddr;
	CString doName;
	CString lnInst;
	CString iedName;
	CString daName;
	CString ldInst;
	CString lnClass;
};
typedef CExtRef EXTREF,*PEXTREF;

// typedef struct _tagExtRef
// {
// 	CString prefix;
// 	CString intAddr;
// 	CString doName;
// 	CString lnInst;
// 	CString iedName;
// 	CString daName;
// 	CString ldInst;
// 	CString lnClass;
// }CExtRef, EXTREF,*PEXTREF;

inline void eq_EXTREF(const EXTREF &src, EXTREF &dest)
{
	dest.prefix = src.prefix;
	dest.intAddr = src.intAddr;
	dest.doName = src.doName;
	dest.lnInst = src.lnInst;
	dest.iedName = src.iedName;
	dest.daName = src.daName;
	dest.ldInst = src.ldInst;
	dest.lnClass = src.lnClass;
}

class CInputs  : public CScdDataList
{
public:
	CInputs(){}
	virtual ~CInputs(){}

};

typedef CInputs INPUTS,*PINPUTS;

// typedef struct _tagInputs 
// {
// 	CONTAINER_LIST_TYPE(EXTREF) listExtref;
// }INPUTS,*PINPUTS;

class CLN0 : public CScdDataBase
{
public:
	CLN0(){}
	virtual ~CLN0(){}

	CString inst;
	CString lnType;
	CString lnClass;
	CString desc;

	INPUTS inputs;
	CScdDataList listDataset;
	CScdDataList listGsecontrol;
	CScdDataList listSvctrl;
	CScdDataList listDOI;
};
typedef  CLN0 LN0,*PLN0;
// typedef struct _tagLN0
// {
// 	CString inst;
// 	CString lnType;
// 	CString lnClass;
// 	CString desc;
// 
// 	INPUTS inputs;
// 	CONTAINER_LIST_TYPE(DATASET) listDataset;
// 	CONTAINER_LIST_TYPE(GSECONTROL) listGsecontrol;
// 	CONTAINER_LIST_TYPE(SAMPLEDVALUECONTROL) listSvctrl;
// 	CONTAINER_LIST_TYPE(DOI) listDOI;
// 
// }LN0,*PLN0;

class CLN : public CScdDataBase
{
public:
	CLN(){}
	virtual ~CLN(){}

	CString inst;
	CString lnType;
	CString lnClass;
	CString desc;
	CString prefix;

	CScdDataList listDOI;
};
typedef CLN LN, *PLN;
// typedef struct _tagLN
// {
// 	CString inst;
// 	CString lnType;
// 	CString lnClass;
// 	CString desc;
// 	CString prefix;
// 
// 	CONTAINER_LIST_TYPE(DOI) listDOI;
// }LN,*PLN;

class CLDevice : public CScdDataBase
{
public:
	CLDevice(){}
	virtual ~CLDevice(){}

	CString desc;
	CString inst;

	LN0 ln0;

	CScdDataList listLn;

};
typedef CLDevice LDEVICE,*PLDEVICE;
// typedef struct _tagLDevice
// {
// 	CString desc;
// 	CString inst;
// 
// 	LN0 ln0;
// 
// 	CONTAINER_LIST_TYPE(LN) listLn;
// 
// }LDEVICE,*PLDEVICE;

class CAccessPoint : public CScdDataList
{
public:
	CAccessPoint(){}
	virtual ~CAccessPoint(){}

	CString desc;
	CString name;
};
typedef CAccessPoint ACCESSPOINT,*PACCESSPOINT;
// typedef struct _tagAccessPoint
// {
// 	CString desc;
// 	CString name;
// 
// 	CONTAINER_LIST_TYPE(LDEVICE) listLDevice;
// }ACCESSPOINT,*PACCESSPOINT;

class CIED : public CScdDataList
{
public:
	CIED(){}
	virtual ~CIED(){}

	CString configVersion;
	CString desc;
	CString type;
	CString manufacturer;
	CString name;
};
typedef CIED IED,*PIED;
// typedef struct _tagIED
// {
// 	CString configVersion;
// 	CString desc;
// 	CString type;
// 	CString manufacturer;
// 	CString name;
// 
// 	CONTAINER_LIST_TYPE(ACCESSPOINT) listAccesspoint;
// 
// }IED,*PIED;

///DataTypeTemplates
class CEnumVal : public CScdDataBase
{
public:
	CEnumVal(){}
	virtual ~CEnumVal()	{}

	CString ord;
	CString val;
};

typedef CEnumVal ENUMVAL,*PENUMVAL;
// typedef struct _tagEnumVal
// {
// 	CString ord;
// 	CString val;
// }ENUMVAL,*PENUMVAL;

class CEnumType : public CScdDataList
{
public:
	CEnumType(){}
	virtual ~CEnumType(){}

	CString id;
	CString desc;

};
typedef CEnumType ENUMTYPE,*PENUMTYPE;
// typedef struct _tagEnumType
// {
// 	CString id;
// 	CString desc;
// 
// 	CONTAINER_LIST_TYPE(ENUMVAL) listEnumval;
// 
// }ENUMTYPE,*PENUMTYPE;

class CBDA : public CScdDataBase
{
public:
	CBDA(){}
	virtual ~CBDA(){}

	CString desc;
	CString name;
	CString sAddr;
	CString bType;
	CString type;
	CString count;
	CString valKind;
};

typedef CBDA BDA,*PBDA;
// typedef struct _tagBDA
// {
// 	CString desc;
// 	CString name;
// 	CString sAddr;
// 	CString bType;
// 	CString type;
// 	CString count;
// 	CString valKind;
// }BDA,*PBDA;

class CDAType : public CScdDataList
{
public:
	CDAType(){}
	virtual ~CDAType()	{}

	CString id;
};

typedef CDAType DATYPE,*PDATYPE;
// typedef struct _tagDAType
// {
// 	CString id;
// 
// 	CONTAINER_LIST_TYPE(BDA) listBda;
// }DATYPE,*PDATYPE;

class CDA : public CScdDataBase
{
public:
	CDA(){}
	virtual ~CDA(){}

	CString desc;
	CString name;
	CString Fc;
	CString dchg;
	CString qchg;
	CString dupb;
	CString sAddr;
	CString bType;
	CString type;
	CString count;
	CString valKind;
};
typedef CDA DA, *PDA;
// typedef struct _tagDA
// {
// 	CString desc;
// 	CString name;
// 	CString Fc;
// 	CString dchg;
// 	CString qchg;
// 	CString dupb;
// 	CString sAddr;
// 	CString bType;
// 	CString type;
// 	CString count;
// 	CString valKind;
// 
// }DA,*PDA;

class CDOType : public CScdDataList
{
public:
	CDOType(){}
	virtual ~CDOType(){}

	CString id;
	CString iedType;
	CString cdc;

};

typedef CDOType DOTYPE,*PDOTYPE;
// typedef struct _tagDOType
// {
// 	CString id;
// 	CString iedType;
// 	CString cdc;
// 
// 	CONTAINER_LIST_TYPE(DA) listDA;
// }DOTYPE,*PDOTYPE;

class CDO : public CScdDataBase
{
public:
	CDO(){}
	virtual ~CDO(){}

	CString name;
	CString type;
	CString accessControl;
	CString transient;
};
typedef CDO DO, *PDO;
// typedef struct _tagDO
// {
// 	CString name;
// 	CString type;
// 	CString accessControl;
// 	CString transient;
// }DO,*PDO;

class CLNodeType : public CScdDataList
{
public:
	CLNodeType(){}
	virtual ~CLNodeType(){}

	CString id;
	CString desc;
	CString ideType;
	CString lnClass;
};
typedef CLNodeType LNODETYPE,*PLNODETYPE;
// typedef struct _tagLNodeType
// {
// 	CString id;
// 	CString desc;
// 	CString ideType;
// 	CString lnClass;
// 
// 	CONTAINER_LIST_TYPE(DO) listDoo;
// }LNODETYPE,*PLNODETYPE;

class CDataTypeTemplates : public CScdDataBase
{
public:
	CDataTypeTemplates(){}
	virtual ~CDataTypeTemplates(){}

	LNODETYPE listLNodetype;
	DOTYPE list_dotype;
	DATYPE list_datype;
	ENUMTYPE list_enumtype;
};
typedef CDataTypeTemplates DATATYPETEMPLATES,*PDATATYPETEMPLATES;
// typedef struct _tagDataTypeTemplates
// {
// 	CONTAINER_LIST_TYPE(LNODETYPE) listLNodetype;
// 	CONTAINER_LIST_TYPE(DOTYPE) list_dotype;
// 	CONTAINER_LIST_TYPE(DATYPE) list_datype;
// 	CONTAINER_LIST_TYPE(ENUMTYPE) list_enumtype;
// }DATATYPETEMPLATES,*PDATATYPETEMPLATES;


// typedef std::tr1::shared_ptr<SCGSDATA> SCGSDATAPtr;
typedef CSCGSData* SCGSDATAPtr;

//*************************ReadSCDF***************************
typedef map<UINT,CString> INDEXCSTRING;
// typedef map<CString,SHARED_PTR(GOOSEOUTPUTCHN)> GSEOUTPUTMAP;
// typedef map<CString,SHARED_PTR(SMVOUTPUTCHN)> SMVOUTPUTMAP;
typedef CScdDataMapList GSEOUTPUTMAP;
typedef CScdDataMapList SMVOUTPUTMAP;

class CInputChn : public CScdDataBase
{
public:
	CInputChn()	{}
	virtual ~CInputChn()	{}
	virtual UINT GetClassID()	{	return SCDDATA_CInputChn;	}

	CString strIntAddress;
	CString strIntSigDes;
	int nExtSigIndex;
	CString strExtSigAddress;
	CString strExtSigDes;
	CExtRef extrefPtr;
};

// 输入通道 
// typedef struct _tagInputChn
// {
// 	CString strIntAddress;
// 	CString strIntSigDes;
// 	int nExtSigIndex;
// 	CString strExtSigAddress;
// 	CString strExtSigDes;
// 	SHARED_PTR(EXTREF) extrefPtr;
// }INPUTCHN,*PINPUTCHN;

// GOOSE输出
class CGooseOut : public CScdDataList
{
public:
	CGooseOut()	{}
	virtual ~CGooseOut()	{}
	virtual UINT GetClassID()	{	return SCDDATA_CGooseOut; }

	BOOL bSelect;
	BOOL bRead;     // 是否已经读取

	CString strgocbRef;
	CString strDataset;
	CString strgoID;
	CString strDes; // 输入的数据集描述
	CString strVersion;

	// 2011-11-25 
	CString strAPName;
	//	SCGSDATAPtr scgsDataPtr;
	SCGSDATA scgsData;

	std::list<CString> chnAddr;

	CGooseOutputChn* FindByAddress(const CString &strAddress)
	{
		CGooseOutputChn *p = NULL;
		CGooseOutputChn *pFind = NULL;
		TPOS pos = GetHeadPosition();

		while (pos != NULL)
		{
			p = (CGooseOutputChn *)GetNext(pos);

			if (p->strAddress == strAddress)
			{
				pFind = p;
				break;
			}
		}

		return pFind;
	}
};

typedef CGooseOut GOOSEOUT,*PGOOSEOUT;

// typedef struct _tagGooseOut
// {
// 	BOOL bSelect;
// 	BOOL bRead;     // 是否已经读取
// 
// 	CString strgocbRef;
// 	CString strDataset;
// 	CString strgoID;
// 	CString strDes; // 输入的数据集描述
// 	CString strVersion;
// 
// 	// 2011-11-25 
// 	CString strAPName;
// //	SCGSDATAPtr scgsDataPtr;
// 	SCGSDATA scgsData;
// 
// 	std::list<CString> chnAddr;
// 	GSEOUTPUTMAP gseoutputchn;
// 
// }GOOSEOUT,*PGOOSEOUT;

// GOOSE输入
class CGooseIn : public CScdDataList
{
public:
	CGooseIn()	{}
	virtual ~CGooseIn()	{}
	virtual UINT GetClassID()	{	return SCDDATA_CGooseIn;	}

	BOOL bSelect;
	CString strAppID;
	CString strMac;
	int nChnCount;
	int nRefCount;
	CString strDes;
	CString strgocbRef;
	CString strDataSet;
	CString strgoID;
	CString strOutputIEDName;
	CString strOutputIEDDesc;
};

typedef CGooseIn GOOSEIN,*PGOOSEIN;

// typedef struct _tagGooseIn
// {
// 	BOOL bSelect;
// 	CString strAppID;
// 	CString strMac;
// 	int nChnCount;
// 	int nRefCount;
// 	CString strDes;
// 	CString strgocbRef;
// 	CString strDataSet;
// 	CString strgoID;
// 	CString strOutputIEDName;
// 	CString strOutputIEDDesc;
// 
// 	CONTAINER_LIST_TYPE(INPUTCHN) list_gseinputchn;
// 
// }GOOSEIN,*PGOOSEIN;


// SMV输出
class CSmvOut : public CScdDataList
{
public:
	CSmvOut()	{}
	virtual ~CSmvOut()	{}
	virtual UINT GetClassID()	{	return SCDDATA_CSmvOut;	}

	BOOL bSelect;
	BOOL bRead;

	CString strsmvID;
	CString strVersion;

	SCGSDATA scgsData;
	std::list<CString> chnAddr;

	CSMVOutputChn* FindByAddress(const CString &strAddress)
	{
		CSMVOutputChn *p = NULL;
		CSMVOutputChn *pFind = NULL;
		TPOS pos = GetHeadPosition();

		while (pos != NULL)
		{
			p = (CSMVOutputChn *)GetNext(pos);

			if (p->strAddress == strAddress)
			{
				pFind = p;
				break;
			}
		}

		return pFind;
	}
};
typedef CSmvOut SMVOUT,*PSMVOUT;

// typedef struct _tagSMVOut
// {
// 	BOOL bSelect;
// 	BOOL bRead;
// 
// 	CString strsmvID;
// 	CString strVersion;
// 
// 	SCGSDATA scgsData;
// 	std::list<CString> chnAddr;
// 	SMVOUTPUTMAP smvoutputchn;
// 
// }SMVOUT,*PSMVOUT;

// SMV输入
class CSmvIn : public CScdDataList
{
public:
	CSmvIn(){};
	virtual ~CSmvIn()	{}
	virtual UINT GetClassID()	{	return SCDDATA_CSmvIn;	}


	int nIndex;
	BOOL bSelect;
	CString strAppID;
	CString strMac;
	int nChnCount;
	int nRefCount;
	CString strCtrlIED;
	CString strOutputIEDName;
	CString strOutputIEDDesc;
	CString strsmvID;
};

typedef CSmvIn SMVIN,*PSMVIN;
// typedef struct _tagSMVInp
// {
// 	int nIndex;
// 	BOOL bSelect;
// 	CString strAppID;
// 	CString strMac;
// 	int nChnCount;
// 	int nRefCount;
// 	CString strCtrlIED;
// 	CString strOutputIEDName;
// 	CString strOutputIEDDesc;
// 	CString strsmvID;
// 
// 	CONTAINER_LIST_TYPE(INPUTCHN) list_smvinputchn;
// }SMVIN,*PSMVIN;


typedef struct _tagDATypeR
{
	CString id;
}DATYPER,*PDATYPER;


typedef struct _tagDOTypeR
{
	CString id;
	CString iedType;
	CString cdc;

}DOTYPER,*PDOTYPER;


typedef struct _tagLNodeTypeR
{
	CString id;
	CString desc;
	CString ideType;
	CString lnClass;

}LNODETYPER,*PLNODETYPER;

// typedef map<CString, CString> CStringMap;
/*
typedef struct _tagShowIEDR
{	

	CXmlNodePtr iedNodePtr;
	CString iedDesc;
	CString iedName;

	// 是否已经检查()
	BOOL bCheckSMV;
	BOOL bCheckGSE;

	// 是否有SMV输入
	BOOL bHSMV;
	// 是否有GSE输入
	BOOL bHGSE;

	// 是否已经读入SMV及GOOSE
	BOOL bReadSMVGSEIn;

	CONTAINER_LIST_TYPE(GOOSEIN) gooseinput;
	CONTAINER_LIST_TYPE(GOOSEOUT) gooseoutput;
	CONTAINER_LIST_TYPE(SMVIN) smvinput;
	CONTAINER_LIST_TYPE(SMVOUT) smvoutput;

}SHOWIEDR,*PSHOWIEDR;
*/



// 此结构体中只客户使用
class CClientIED : public CScdDataBase
{
public:
	CClientIED(){}
	virtual ~CClientIED()	
	{
		list_gooseinput.DeleteAll();
		list_gooseoutput.DeleteAll();
		list_smvinput.DeleteAll();
		list_smvoutput.DeleteAll();
	}	
	virtual UINT GetClassID()	{	return SCDDATA_CClientIED;	}

	CString iedName;
	CString iedDesc;

	BOOL bReadIN;
	BOOL bReadOUT;

	CScdDataList list_gooseinput;
	CScdDataList list_gooseoutput;
	CScdDataList list_smvinput;
	CScdDataList list_smvoutput;
};
// typedef struct _tagClientIED 
// {
// 	CString iedName;
// 	CString iedDesc;
// 
// 	BOOL bReadIN;
// 	BOOL bReadOUT;
// 
// 	CONTAINER_LIST_TYPE(GOOSEIN) list_gooseinput;
// 	CONTAINER_LIST_TYPE(GOOSEOUT) list_gooseoutput;
// 	CONTAINER_LIST_TYPE(SMVIN) list_smvinput;
// 	CONTAINER_LIST_TYPE(SMVOUT) list_smvoutput;
// 
// }CLIENTIED,*PCLIENTIED;


// typedef std::tr1::shared_ptr<GOOSEOUT> GOOSEOUTPtr;
typedef CGooseOut* GOOSEOUTPtr;
// typedef std::tr1::shared_ptr<GOOSEIN> GOOSEINPtr;
typedef CGooseIn* GOOSEINPtr;
// typedef std::tr1::shared_ptr<SMVIN> SMVINPtr;
typedef CSmvIn* SMVINPtr;
// typedef std::tr1::shared_ptr<SMVOUT> SMVOUTPtr;
typedef CSmvOut* SMVOUTPtr;
// typedef std::tr1::shared_ptr<INPUTCHN> INPUTCHNPtr;
typedef CInputChn* INPUTCHNPtr;
typedef CInputChn INPUTCHN, *PINPUTCHN;

// typedef std::tr1::shared_ptr<CLIENTIED> CLIENTIEDPTR;
typedef CClientIED* CLIENTIEDPTR;

// typedef map<CString, CString> CStringMap;
// typedef std::tr1::shared_ptr<FCDA> FCDAPtr;
// typedef std::tr1::shared_ptr<ENUMTYPE> ENUMTYPEPtr;
typedef FCDA* FCDAPtr;
typedef ENUMTYPE* ENUMTYPEPtr;

// typedef std::tr1::shared_ptr<GOOSEOUTPUTCHN> GOOSEOUTPUTCHNPtr;
typedef CGooseOutputChn* GOOSEOUTPUTCHNPtr;
// typedef std::tr1::shared_ptr<SCONNECTEDAP> SCONNECTEDAPPtr;
typedef CSConnectedAP* SCONNECTEDAPPtr;
// typedef std::tr1::shared_ptr<EXTREF> EXTREFPtr;
typedef CExtRef* EXTREFPtr;
// typedef std::tr1::shared_ptr<SMVOUTPUTCHN> SMVOUTPUTCHNPtr;
typedef CSMVOutputChn* SMVOUTPUTCHNPtr;
