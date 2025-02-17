#include "StdAfx.h"
#include "SaveShareFile.h"
#include "UI\StPublicFun.h"


CSaveShareFile::CSaveShareFile(void)
{
	m_nSMVType = 0;
}


CSaveShareFile::~CSaveShareFile(void)
{
}



void CSaveShareFile::SaveToGoose(UINT nType)
{

	CString FilePath;
	CreateTempFile(FilePath);

	CXml xmlfile;

	if(xmlfile.Create(_T("ADD")))
	{
		CXmlNodePtr rootPtr = xmlfile.GetRoot();
		rootPtr->SetAttribute(_T("type"),(int)nType);

		CString strType = _T("");

		if (nType == 0)
		{
			strType = _T("GOOSE输入");
		}else
		{
			strType = _T("GOOSE输出");
		}

		SaveGoooseFile(rootPtr,strType);
		xmlfile.Save(FilePath);
		xmlfile.Close();
	}

	/*
	DWORD dBytesWritten = 0;

	//创建一个文件
	HANDLE hFile = CreateFile(_T("share.dat"),
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	//判断文件是否创建成功
	if (hFile == INVALID_HANDLE_VALUE)
	{
		printf("CreateFile error\n", GetLastError);
		return;
	}


	// 写入数据

	//依次写入整数，一共写入65535个整数
	for (int i = 0; i < 65535; i++)
	{
		WriteFile(hFile, &i, sizeof( i ), &dBytesWritten, NULL);
	}

	HANDLE hFileMapping = ::CreateFileMapping(hFile,
		NULL,
		PAGE_READWRITE,
		0, 0,
		_T("TestFileMap"));

	//拷贝数据到共享文件里。
// 	LPTSTR lpMapAddr = (LPTSTR)MapViewOfFile(hFileMapping,FILE_MAP_ALL_ACCESS,
// 		0,0,0);
// 	std::wstring strTest(_T("TestFileMap"));

//	wcscpy(lpMapAddr,strTest.c_str());                
//	FlushViewOfFile(lpMapAddr,strTest.length()+1);

	CloseHandle(hFile);
	*/
}

void CSaveShareFile::CreateTempFile(CString& fileName)
{
	// 取得程序的路径
	TCHAR path[MAX_PATH];
	GetTempPath(MAX_PATH,path);

	fileName.Format(_T("%s"),path);
	fileName += _T("exitsavecfg.f66cfg");
	SetFileAttributes(fileName,FILE_ATTRIBUTE_HIDDEN);
}


void CSaveShareFile::InitAddToGooseCfg(GSECFG& gsecfg,const GOOSEOUTPtr& GooseOutPtr,LPCTSTR strDes)
{
	GSECHNCFG gsechncfg;
	int nCountChn = 0;
	GOOSEOUTPUTCHNPtr goptchnPtr;
	std::list<CString>::iterator lstr,lstrE;

	gsecfg.nIndex = -1;
	gsecfg.AppID = ST_StringToHex(GooseOutPtr->scgsData.address.AppID);
	gsecfg.GocbRef = GooseOutPtr->strgocbRef;
	gsecfg.GoID = GooseOutPtr->strgoID;
	gsecfg.ConfRev = _ttoi(GooseOutPtr->strVersion);
	gsecfg.DataSet = GooseOutPtr->strDataset;
	gsecfg.MacAddr = GooseOutPtr->scgsData.address.MacAddress;
	gsecfg.SourceMac = _T("48-49-4A-4B-4C-4D");

	gsecfg.ChnCfg.clear();
	gsecfg.ChnCfg.reserve(GooseOutPtr->gseoutputchn.size());


	lstr = GooseOutPtr->chnAddr.begin();
	lstrE = GooseOutPtr->chnAddr.end();

	for (; lstr != lstrE; lstr++)
	{
		goptchnPtr = GooseOutPtr->gseoutputchn[(*lstr)];
		gsechncfg.nIndex = nCountChn++;
		gsechncfg.nIOIndex = 0;
		if (goptchnPtr->strDOIDes.IsEmpty())
		{
			gsechncfg.strChnName = goptchnPtr->strLNDes;
		}else
		{
			gsechncfg.strChnName = goptchnPtr->strDOIDes;
		}

		gsechncfg.bInStruct = FALSE;
		gsechncfg.nType = goptchnPtr->nType;
		gsechncfg.strValue = _T("");
		gsecfg.ChnCfg.push_back(gsechncfg);
	}

	gsecfg.BinNum = GooseOutPtr->gseoutputchn.size();
	gsecfg.OldBinNum = gsecfg.BinNum;
	gsecfg.NdsCom = 0;
	gsecfg.Priority = _ttoi(GooseOutPtr->scgsData.address.VLanpriority);
	gsecfg.strDes = strDes;
	gsecfg.T0 = (_ttoi)(GooseOutPtr->scgsData.MaxTime);
	gsecfg.T1 = (_ttoi)(GooseOutPtr->scgsData.MinTime);
	gsecfg.T2 = gsecfg.T1 * 2;;
	gsecfg.T3 = gsecfg.T2 * 2;;
	gsecfg.Test = 0;
	gsecfg.TMult = 2;

	gsecfg.Used = FALSE;
	gsecfg.LanNo = 1;
	gsecfg.VID = (GooseOutPtr->scgsData.address.VLanID);
//	gsecfg.ChkMask = GICM_BIT_GOCBREF|GICM_BIT_GOID|GICM_BIT_DATASET|GICM_BIT_MACADDR|GICM_BIT_APPID;

	m_gsecfg.push_back(gsecfg);
}

BOOL CSaveShareFile::IsAddToGooseVector(const COMINFO& ComInfo)
{
	BOOL bAdd = FALSE;
	DWORD APPID;
	CString strAppID;
	vector<GSECFG>::iterator itr,itre;
	itr = m_gsecfg.begin();
	itre = m_gsecfg.end();

	for (; itr != itre; itr++)
	{
		
		APPID = itr->AppID;
		strAppID.Format(_T("%d"),APPID);

		if (strAppID == ComInfo.appid && 
			itr->MacAddr == ComInfo.mac && 
			itr->GocbRef == ComInfo.gocbref && 
			itr->GoID == ComInfo.goid && 
			itr->DataSet == ComInfo.dataset)
		{
			bAdd = TRUE;
			break;
		}
	}

	return bAdd;
}


void CSaveShareFile::InitVector()
{
	m_gsecfg.clear();
	m_mucfg.clear();
}

void CSaveShareFile::InitGooseVector()
{
	m_gsecfg.clear();
}

void CSaveShareFile::SaveGoooseFile(const CXmlNodePtr& gNoodPtr,const CString& NodeName)
{
	int nSize = m_gsecfg.size();
	vector<GSECFG>::const_iterator itr,itrB,itrE;

	int Index = 0;
	itrB = m_gsecfg.begin();
	itrE = m_gsecfg.end();
	CXmlNodePtr childPtr,tchildPtr;
	for (itr = itrB; itr != itrE; itr++)
	{
		ADDCHILDSETATTR(gNoodPtr,NodeName,_T("id"),Index,childPtr);
		ADDCHILDSETVALUE(childPtr,_T("AppID"),itr->AppID,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("BinNum"),(int)itr->BinNum,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("ChkMask"),(int)itr->ChkMask,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("ConfRev"),(int)itr->ConfRev,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("DataSet"),itr->DataSet,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("GocbRef"),itr->GocbRef,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("GoID"),itr->GoID,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("LanNo"),(int)itr->LanNo,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("MacAddr"),itr->MacAddr,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("SourceMac"),itr->SourceMac,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("NdsCom"),itr->NdsCom,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("nIndex"),itr->nIndex,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("Priority"),itr->Priority,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("strDes"),itr->strDes,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("T0"),(int)itr->T0,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("T1"),(int)itr->T1,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("T2"),(int)itr->T2,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("T3"),(int)itr->T3,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("Test"),itr->Test,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("TMult"),(int)itr->TMult,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("Used"),itr->Used,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("VID"),itr->VID,tchildPtr);

		ADDCHILDSETATTR(childPtr,_T("GSECHNCFG"),_T("name"),_T("ChnCfg"),tchildPtr);
		SaveGOOSEChnCfgXML(tchildPtr,itr->ChnCfg,_T("ChnCfg"));
		Index++;
	}
}


void CSaveShareFile::SaveGOOSEChnCfgXML(const CXmlNodePtr& chnNoodPtr,const vector<GSECHNCFG>& gsechncfg,const CString& NodeName)
{	
	int nSize = gsechncfg.size();
	vector<GSECHNCFG>::const_iterator itr,itrB,itrE;
	itrB = gsechncfg.begin();
	itrE = gsechncfg.end();

	int Index = 0;
	CString strNodeName;
	CXmlNodePtr childPtr,tchildPtr;

	for (itr = itrB;itr != itrE; itr++)
	{
		ADDCHILDSETATTR(chnNoodPtr,NodeName,_T("id"),Index,childPtr);
		ADDCHILDSETVALUE(childPtr,_T("nIndex"),itr->nIndex,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("nIOIndex"),itr->nIOIndex,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("nType"),itr->nType,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("strChnName"),itr->strChnName,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("strValue"),itr->strValue,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("bInStruct"),itr->bInStruct,tchildPtr);
		Index++;
	}
}



void CSaveShareFile::SaveToSMV(UINT nType)
{
	CString FilePath;
	CreateTempFile(FilePath);

	m_nSMVType = nType;

	CXml xmlfile;

	if(xmlfile.Create(_T("ADD")))
	{
		CXmlNodePtr rootPtr = xmlfile.GetRoot();
		rootPtr->SetAttribute(_T("type"),(int)nType);

		CString strType = _T("");

		switch(nType)
		{
		case 2:
			strType = _T("SMV92");
			break;
		case 3:
			strType = _T("SMVFT3");
			break;
		}
		SaveSMVFile(rootPtr,strType);
		xmlfile.Save(FilePath);
		xmlfile.Close();
	}
}

void CSaveShareFile::InitAddToSMVCfg(MU_SETTING& musetting, const SMVOUTPtr& SMVOutPtr, LPCTSTR strDes)
{
	MU_CHNSET muchnset;
	musetting.AppId = ST_StringToHex(SMVOutPtr->scgsData.address.AppID);
	musetting.bSyn = TRUE;

	musetting.nIndex = -1;
	musetting.bUsed = FALSE;
	musetting.nLanNo = 1;
	musetting.strMac = SMVOutPtr->scgsData.address.MacAddress;
	musetting.SourceMac = _T("48-49-4A-4B-4C-4D");
	musetting.nTCIPr = _ttoi(SMVOutPtr->scgsData.address.VLanpriority);
	musetting.nTciVid = (SMVOutPtr->scgsData.address.VLanID);
	musetting.nVersion = _ttoi(SMVOutPtr->strVersion);
	musetting.strSvid = SMVOutPtr->strsmvID;
	musetting.bSyn = TRUE;
	musetting.nChnNum = SMVOutPtr->smvoutputchn.size();
	musetting.CurrentA = 1;
	musetting.CurrentNeut = 1;
	musetting.VoltA = 1;
	musetting.CurrentScp = 0x01CF;
	musetting.fCTBitRate = 1.0f;
	musetting.fPTBitRate = 10.0f;
	musetting.strDes = strDes;

	musetting.LDName = 0x01;
	musetting.LNName = 0x02;
	musetting.dwState1 = 0x00;
	musetting.dwState2 = 0x00;
	musetting.CurrentDelay = 0;
	musetting.DataName = 0xFE;

	musetting.pmu_chnset.clear();
	musetting.pmu_chnset.reserve(musetting.nChnNum);

	std::list<CString>::iterator lstr,lstrE;
	lstr = SMVOutPtr->chnAddr.begin();
	lstrE = SMVOutPtr->chnAddr.end();;

	BOOL bVol = FALSE;

	int nCountChn = 0;
	CString str = _T("");
	SMVOUTPUTCHNPtr smvoptchnPtr;
	for (; lstr != lstrE; lstr++)
	{
		smvoptchnPtr = SMVOutPtr->smvoutputchn[(*lstr)];
		// FT3扩展只有22个通道
		if (m_nSMVType == 1 && nCountChn >= 22)
		{
			break;
		}

		if (smvoptchnPtr->strAddress.Find(_T(".q")) == -1)
		{
			bVol = FALSE;
			muchnset.m_DOWD_Q = 0; 
			muchnset.nIndex = nCountChn++;
			muchnset.nChnSel = 0;
			muchnset.bCheck = 0;
			if (smvoptchnPtr->strLNDes.IsEmpty())
			{
				str = smvoptchnPtr->strDOIDes;
			}else
			{
				str = smvoptchnPtr->strLNDes;
			}

			muchnset.strChnName = str;
			if (str.Find(_T("I")) != -1 || str.Find(_T("i")) != -1 )
			{
				bVol = FALSE;
			}

			if (str.Find(_T("U")) != -1 || str.Find(_T("u")) != -1)
			{
				bVol = TRUE;
			}


			if (str.Find(_T("电流")) != -1)
			{
				bVol = FALSE;
			}

			if(str.Find(_T("电压")) != -1)
			{
				bVol = TRUE;
			}


			if (bVol == TRUE)
			{
				muchnset.nTypeSel = 0;
			}else
			{
				muchnset.nTypeSel = 1;
			}

			if (str.Find(_T("A")) != -1 || str.Find(_T("a")) != -1/* || str.Find(_T("1")) != -1 */)
			{
				muchnset.nChnSel = 1;
			}else if (str.Find(_T("B")) != -1 || str.Find(_T("b")) != -1/* || str.Find(_T("2")) != -1 */)
			{
				muchnset.nChnSel = 2;
			}else if (str.Find(_T("C")) != -1 || str.Find(_T("c")) != -1 /*|| str.Find(_T("3")) != -1 */)
			{
				muchnset.nChnSel = 3;
			}else if (str.Find(_T("X")) != -1 || str.Find(_T("x")) != -1 /*|| str.Find(_T("4")) != -1 */)
			{
				muchnset.nChnSel = 4;
			}else if (str.Find(_T("Y")) != -1 || str.Find(_T("y")) != -1 /*|| str.Find(_T("5")) != -1 */)
			{
				muchnset.nChnSel = 5;
			}else if (str.Find(_T("Z")) != -1 || str.Find(_T("z")) != -1/* || str.Find(_T("6")) != -1 */)
			{
				muchnset.nChnSel = 6;
			}else
			{
				muchnset.nChnSel = 1;
			}

			if (smvoptchnPtr->strAddress.Find(_T("DelayTRtg")) != -1 || str.Find(_T("延时")) != -1 || str.Find(_T("延迟")) != -1)
			{
				muchnset.nChnSel = -1;
				muchnset.strInput = _T("50 us");
				muchnset.nTypeSel = 2;
			}


			musetting.pmu_chnset.push_back(muchnset);
		}
	}

	musetting.nChnNum = nCountChn;

	m_mucfg.push_back(musetting);
}

void CSaveShareFile::InitSMVVectro()
{
	m_mucfg.clear();
}

void CSaveShareFile::SaveSMVFile(const CXmlNodePtr& gNoodPtr,const CString& NodeName)
{
	int nSize = m_mucfg.size();
	vector<MU_SETTING>::const_iterator itr,itrB,itrE;

	itrB = m_mucfg.begin();
	itrE = m_mucfg.end();

	int Index = 0;
	CXmlNodePtr childPtr,tchildPtr;
	for (itr = itrB; itr != itrE; itr++)
	{
		ADDCHILDSETATTR(gNoodPtr,NodeName,_T("id"),Index,childPtr);
		ADDCHILDSETVALUE(childPtr,_T("AppId"),itr->AppId,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("bSyn"),itr->bSyn,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("bUsed"),itr->bUsed,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("CurrentA"),(int)itr->CurrentA,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("CurrentDelay"),(DWORD)itr->CurrentDelay,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("CurrentNeut"),(int)itr->CurrentNeut,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("CurrentScp"),(int)itr->CurrentScp,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("DataName"),(int)itr->DataName,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("dwState1"),(DWORD)itr->dwState1,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("dwState2"),(DWORD)itr->dwState2,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("fCTBitRate"),(float)itr->fCTBitRate,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("fPTBitRate"),(float)itr->fPTBitRate,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("LDName"),(int)itr->LDName,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("LNName"),(int)itr->LNName,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("nChnNum"),(int)itr->nChnNum,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("nIndex"),Index,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("nLanNo"),itr->nLanNo,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("nTCIPr"),itr->nTCIPr,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("nTciVid"),itr->nTciVid,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("nVersion"),itr->nVersion,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("strDes"),itr->strDes,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("strMac"),itr->strMac,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("SourceMac"),itr->SourceMac,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("strSvid"),itr->strSvid,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("VoltA"),(int)itr->VoltA,tchildPtr);

		ADDCHILDSETATTR(childPtr,_T("MU_CHNSET"),_T("name"),_T("pmu_chnset"),tchildPtr);
		SaveSMVChnCfgXML(tchildPtr,(itr->pmu_chnset),_T("pmu_chnset"));
		Index++;
	}
}

void CSaveShareFile::SaveSMVChnCfgXML(const CXmlNodePtr& chnNoodPtr,const vector<MU_CHNSET>& mu_chnset,const CString& NodeName)
{
	vector<MU_CHNSET>::const_iterator itr,itrB,itrE;
	itrB = mu_chnset.begin();
	itrE = mu_chnset.end();

	int Index = 0;
	CString strNodeName;
	int nSize = mu_chnset.size();
	CXmlNodePtr childPtr,tchildPtr;
	for (itr = itrB; itr != itrE; itr++)
	{
		ADDCHILDSETATTR(chnNoodPtr,NodeName,_T("id"),Index,childPtr);
		ADDCHILDSETVALUE(childPtr,_T("m_DOWD_Q"),itr->m_DOWD_Q,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("nChnSel"),itr->nChnSel,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("strInput"),itr->strInput,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("nIndex"),itr->nIndex,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("strChnName"),itr->strChnName,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("bCheck"),itr->bCheck,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("nTypeSel"),itr->nTypeSel,tchildPtr);
		Index++;
	}
}