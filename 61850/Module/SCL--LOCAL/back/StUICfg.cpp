#include "StdAfx.h"
#include "StUICfg.h"
#include "UI\StPublicFun.h"

CStUICfg::CStUICfg(BOOL bSaveCfgFlg)
{
	m_nVersion = 0;
	m_bSaveCfgFlg = bSaveCfgFlg;
}


CStUICfg::~CStUICfg(void)
{

}

BOOL CStUICfg::SaveF66CfgXML(LPCTSTR strPath,const MU_GENERALSETTTING& mu_gset, const GSEUI& gseui,
	const vector<MU_SETTING>& muset91, const vector<MU_SETTING>& muset92,
	const vector<MU_SETTING>& muset91Ex,const vector<MU_SETTING>& musetft3)
{
	CXml xmlfile;

	if(xmlfile.Create(_T("F66")))
	{
		CXmlNodePtr rootPtr = xmlfile.GetRoot();
		CXmlNodePtr childPtr,tchildPtr;

		//写入版本号
		rootPtr->SetAttribute(_T("Version"),XMLVERSION);

		// 通用配置
		ADDCHILDSETVALUE(rootPtr,_T("m_mugersetting"),_T(""),childPtr);

		SaveMUGerSet(childPtr,mu_gset);

		// MU
		ADDCHILDSETATTR(rootPtr,_T("MU_SETTING"),_T("name"),_T("m_muset91"),childPtr);
		SaveMUCfgXML(childPtr,muset91,_T("m_muset91"));

		ADDCHILDSETATTR(rootPtr,_T("MU_SETTING"),_T("name"),_T("m_muset92"),childPtr);
		SaveMUCfgXML(childPtr,muset92,_T("m_muset92"));

		ADDCHILDSETATTR(rootPtr,_T("MU_SETTING"),_T("name"),_T("m_muset91Ex"),childPtr);
		SaveMUCfgXML(childPtr,muset91Ex,_T("m_muset91Ex"));

		ADDCHILDSETATTR(rootPtr,_T("MU_SETTING"),_T("name"),_T("m_musetft3"),childPtr);
		SaveMUCfgXML(childPtr,musetft3,_T("m_musetft3"));

		/*
		ADDCHILDSETATTR(rootPtr,_T("MU_SETTING"),_T("name"),_T("m_musetft3Ex"),childPtr);
		SaveMUCfgXML(childPtr,m_musetft3ex,_T("m_musetft3Ex"));
		*/

		// GOOSE
		ADDCHILDSETVALUE(rootPtr,_T("m_gseui"),_T(""),childPtr);
		ADDCHILDSETVALUE(childPtr,_T("Version"),(int)gseui.Version,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("GseInNumSel"),gseui.GseInNumSel,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("GseOutNumSel"),gseui.GseOutNumSel,tchildPtr);

		ADDCHILDSETATTR(childPtr,_T("GSECFG"),_T("name"),_T("GseInCfg"),tchildPtr);
		SaveGOOSECfgXML(tchildPtr,gseui.GseInCfg,_T("GseInCfg"));
		ADDCHILDSETATTR(childPtr,_T("GSECFG"),_T("name"),_T("GseOutCfg"),tchildPtr);
		SaveGOOSECfgXML(tchildPtr,gseui.GseOutCfg,_T("GseOutCfg"));

// 		ADDCHILDSETATTR(childPtr,_T("TestCtrl"),_T("id"),_T("mucfgdata"),tchildPtr);
// 		SaveTestCtrlData();

		xmlfile.Save(strPath);
		xmlfile.Close();

		return TRUE;
	}

	return FALSE;
}

BOOL CStUICfg::ReadF66CfgXML(LPCTSTR strPath,MU_GENERALSETTTING& mu_gset, GSEUI& gseui,
	vector<MU_SETTING>& muset91, vector<MU_SETTING>& muset92,
	vector<MU_SETTING>& muset91Ex,vector<MU_SETTING>& musetft3)
{
	CXml xmlfile;
	if (xmlfile.Open(strPath))
	{
		CXmlNodePtr rootPtr = xmlfile.GetRoot();
		CString strText;
		CXmlNodePtr childPtr,tchildPtr;

		// 获取版本号
		m_nVersion = rootPtr->GetAttribute(_T("Version"),0);

		// 通用配置
		READCHILDVALUE(rootPtr,_T("m_mugersetting"),strText,_T(""),childPtr);

		ReadMUGerSet(childPtr,mu_gset);

		CXmlNodesPtr childsPtr = rootPtr->SelectNodes(_T("MU_SETTING"));
		int nSizes = childsPtr->GetCount();

		CXmlNodePtr muPtr;
		for (int i = 0; i < nSizes; i++)
		{
			muPtr = childsPtr->GetItem(i);
			strText = muPtr->GetAttribute(_T("name"));

			if (strText == _T("m_muset91"))
			{
				ReadMUCfgXML(muPtr,muset91,strText);
			}
			else if (strText == _T("m_muset92"))
			{
				ReadMUCfgXML(muPtr,muset92,strText);
			}
			else if (strText == _T("m_muset91Ex"))
			{
				ReadMUCfgXML(muPtr,muset91Ex,strText);
			}
			else if (strText == _T("m_musetft3") || strText == _T("m_musetft3Ex"))
			{
				ReadMUCfgXML(muPtr,musetft3,strText);
			} 
		}

		// GOOSE
		READCHILDVALUE(rootPtr,_T("m_gseui"),strText,_T(""),childPtr);
		READCHILDVALUE(childPtr,_T("Version"),gseui.Version,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("GseInNumSel"),gseui.GseInNumSel,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("GseOutNumSel"),gseui.GseOutNumSel,0,tchildPtr);

		childsPtr = childPtr->SelectNodes(_T("GSECFG"));
		nSizes = childsPtr->GetCount();
		for (int i = 0; i < nSizes; i++)
		{
			muPtr = childsPtr->GetItem(i);
			strText = muPtr->GetAttribute(_T("name"));

			if (strText == _T("GseInCfg"))
			{
				ReadGOOSECfgXML(muPtr,gseui.GseInCfg,strText);
			}
			else if (strText == _T("GseOutCfg"))
			{
				ReadGOOSECfgXML(muPtr,gseui.GseOutCfg,strText);
			}
		}

		xmlfile.Close();

		return TRUE;
	}

	return FALSE;
}

long CStUICfg::GetF66XMLVersion()
{
	return m_nVersion;
}

void CStUICfg::ConvertToNewData(MU_CHNSET& chnset, int nSampleType)
{
	switch(nSampleType)
	{
	case SAMPLE_TYPE_9_1: 
	case SAMPLE_TYPE_9_1_EX:
	case SAMPLE_TYPE_FT3:
		if (chnset.nChnSel > 0 && chnset.nChnSel < 10)      // 电流（保护）
		{
			chnset.nTypeSel = 1;
		}else if(chnset.nChnSel > 9 && chnset.nChnSel < 19) // 电流（测量）
		{
			chnset.nTypeSel = 2;
			chnset.nChnSel -= 9;
		}else if(chnset.nChnSel > 18 && chnset.nChnSel < 22) // 电流（保护）
		{
			chnset.nTypeSel = 1;
			chnset.nChnSel -= 9;
		}else if(chnset.nChnSel > 21 && chnset.nChnSel < 34 ) // 电压
		{
			chnset.nTypeSel = 0;
			chnset.nChnSel -= 21;
		}if(chnset.nChnSel <= -1)
		{
			chnset.nTypeSel = 0;

			if (!chnset.strInput.IsEmpty())
			{
				chnset.nTypeSel = 3;
			}
		}

		break;
	case SAMPLE_TYPE_9_2:
		if (chnset.nChnSel > 12 && chnset.nChnSel < 25)
		{
			chnset.nTypeSel = 0;
			chnset.nChnSel -= 12;
		}else if(chnset.nChnSel >= 0 && chnset.nChnSel < 13)
		{
			chnset.nTypeSel = 1;

		}else if(chnset.nChnSel <= -1)
		{
			chnset.nTypeSel = 0;

			if (!chnset.strInput.IsEmpty())
			{
				chnset.nTypeSel = 2;
			}
		}

		break;
	default:
		break;
	}
}


void CStUICfg::ConvertToNewData_24(MU_CHNSET& chnset, int nSampleType)
{
	switch(nSampleType)
	{
	case SAMPLE_TYPE_9_1: 
	case SAMPLE_TYPE_9_2:
	case SAMPLE_TYPE_9_1_EX:
	case SAMPLE_TYPE_FT3:
		if (chnset.nChnSel > 9 && chnset.nChnSel <13)
		{
			chnset.nChnSel+=3;
		}
		break;
	default:
		break;
	}
}


void CStUICfg::ConvertToNewData_XML_24(vector<MU_SETTING>& muset,int nSampleType)
{
	vector<MU_CHNSET>::iterator itrchn,itrchne;
	vector<MU_SETTING>::iterator itr,itre;
	itre = muset.end();

	for (itr = muset.begin(); itr != muset.end(); itr++)
	{
		itrchne = itr->pmu_chnset.end();
		for (itrchn = itr->pmu_chnset.begin(); itrchn != itrchne; itrchn++)
		{
			ConvertToNewData_24((*itrchn),nSampleType);
		}
	}
}


void CStUICfg::ConvertToNewData_XML(vector<MU_SETTING>& muset,int nSampleType)
{
	vector<MU_CHNSET>::iterator itrchn,itrchne;
	vector<MU_SETTING>::iterator itr,itre;
	itre = muset.end();

	for (itr = muset.begin(); itr != muset.end(); itr++)
	{
		itrchne = itr->pmu_chnset.end();
		for (itrchn = itr->pmu_chnset.begin(); itrchn != itrchne; itrchn++)
		{
			ConvertToNewData((*itrchn),nSampleType);
		}
	}
}

void CStUICfg::SaveMUCfgXML(const CXmlNodePtr& muNoodPtr,const vector<MU_SETTING>& mu_setting,const CString& NodeName)
{
	int nSize = mu_setting.size();
	vector<MU_SETTING>::const_iterator itr,itrB,itrE;	

	itrB = mu_setting.begin();
	itrE = mu_setting.end();

	int Index = 0;
	CXmlNodePtr childPtr,tchildPtr;
	for (itr = itrB; itr != itrE; itr++)
	{
		ADDCHILDSETATTR(muNoodPtr,NodeName,_T("id"),Index,childPtr);
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
		ADDCHILDSETVALUE(childPtr,_T("bSynAuto"),itr->bSynAuto,tchildPtr)

		ADDCHILDSETATTR(childPtr,_T("MU_CHNSET"),_T("name"),_T("pmu_chnset"),tchildPtr);
		SaveMUChnCfgXML(tchildPtr,itr->pmu_chnset,_T("pmu_chnset"));

//		if (m_bSaveCfgFlg)
		{
			ADDCHILDSETATTR(childPtr,_T("MU_CHNDATA"),_T("id"),_T("mucfgdata"),tchildPtr);
			int nNum = itr->pmu_chnset.size();
			SaveMUMSGCfgDataXml(tchildPtr,itr->UIs,nNum,_T("mucfgdata"));

			ADDCHILDSETVALUE(childPtr,_T("MSGTESTSET"),_T(""),tchildPtr);
			if (itr->msgtestsetPtr != NULL)
			{
				SaveMUMSGTestSetXML(tchildPtr,itr->msgtestsetPtr);
			}
		}

		Index++;
	}
}

void CStUICfg::SaveMUChnCfgXML(const CXmlNodePtr& chnNoodPtr,const vector<MU_CHNSET>& mu_chnset,const CString& NodeName)
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

void CStUICfg::SaveGOOSECfgXML(const CXmlNodePtr& gNoodPtr,const vector<GSECFG>& gsecfg,const CString& NodeName)
{
	int nSize = gsecfg.size();
	vector<GSECFG>::const_iterator itr,itrB,itrE;

	int Index = 0;
	itrB = gsecfg.begin();
	itrE = gsecfg.end();
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

		/************************************************************************/
		/* zy 2012-4-12 保存Goose报文测试数据                                   */
		/************************************************************************/

		if (m_bSaveCfgFlg && itr->GsetestsetPtr != NULL)
		{
			ADDCHILDSETVALUE(childPtr,_T("GSETESTSET"),_T(""),tchildPtr);
			SaveGsePktTestSetXML(tchildPtr,itr->GsetestsetPtr);
		}

		Index++;
	}
}

void CStUICfg::SaveGOOSEChnCfgXML(const CXmlNodePtr& chnNoodPtr,const vector<GSECHNCFG>& gsechncfg,const CString& NodeName)
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

void CStUICfg::ReadMUCfgXML(const CXmlNodePtr& muNoodPtr,vector<MU_SETTING>& mu_setting,const CString& NodeName)
{
	CString str;
	MU_SETTING mu;
	mu_setting.clear();
	CXmlNodePtr childPtr,tchildPtr;
	CXmlNodesPtr childsPtr = muNoodPtr->SelectNodes(NodeName);
	int nSize = childsPtr->GetCount();
	mu_setting.reserve(nSize);

	for (int i = 0; i < nSize; i++)
	{
		childPtr = childsPtr->GetItem(i);

		READCHILDVALUE(childPtr,_T("AppId"),mu.AppId,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("bSyn"),mu.bSyn,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("bUsed"),mu.bUsed,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("CurrentA"),mu.CurrentA,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("CurrentDelay"),(DWORD)mu.CurrentDelay,(DWORD)0,tchildPtr);
		READCHILDVALUE(childPtr,_T("CurrentNeut"),mu.CurrentNeut,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("CurrentScp"),mu.CurrentScp,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("DataName"),mu.DataName,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("dwState1"),(DWORD)mu.dwState1,(DWORD)0,tchildPtr);
		READCHILDVALUE(childPtr,_T("dwState2"),(DWORD)mu.dwState2,(DWORD)0,tchildPtr);
		READCHILDVALUE(childPtr,_T("fCTBitRate"),(float)mu.fCTBitRate,0.00f,tchildPtr);
		READCHILDVALUE(childPtr,_T("fPTBitRate"),(float)mu.fPTBitRate,0.00f,tchildPtr);
		READCHILDVALUE(childPtr,_T("LDName"),mu.LDName,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("LNName"),mu.LNName,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("nChnNum"),mu.nChnNum,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("nIndex"),mu.nIndex,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("nLanNo"),mu.nLanNo,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("nTCIPr"),mu.nTCIPr,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("nTciVid"),mu.nTciVid,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("nVersion"),mu.nVersion,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("strDes"),mu.strDes,_T(""),tchildPtr);
		READCHILDVALUE(childPtr,_T("strMac"),mu.strMac,_T(""),tchildPtr);
		READCHILDVALUEEX(childPtr,_T("SourceMac"),mu.SourceMac,_T(""),tchildPtr,_T("48-49-4A-4B-4C-4D"));
		READCHILDVALUE(childPtr,_T("strSvid"),mu.strSvid,_T(""),tchildPtr);
		READCHILDVALUE(childPtr,_T("VoltA"),mu.VoltA,0,tchildPtr);
		READCHILDVALUEEX(childPtr,_T("bSynAuto"),mu.bSynAuto,0,tchildPtr,0);

		mu.pmu_chnset.clear();
		READCHILDATTR(childPtr,_T("MU_CHNSET"),str,_T("name"),tchildPtr);
		ReadMUChnCfgXML(tchildPtr,mu.pmu_chnset,str);

		READCHILDATTR(childPtr,_T("MU_CHNDATA"),str,_T("id"),tchildPtr);
		int nNum = mu.pmu_chnset.size();

		// 通道数根据实际读取到的通道数确定
		mu.nChnNum = nNum;

		//////////////////////////////////////////////////////////////////////////
		// 初始化数据
		{
			BOOL bChk = FALSE;
			MU_CHNSET *pChSet = NULL;
			int nOffSetCount = 0;
			float fAng = 0.0f;
			for (int k=0;k<MAX_TST_MUCHN;k++)
			{
				if (k<nNum)
					pChSet = &mu.pmu_chnset.at(k);

				mu.UIs[k].uIndex = k;
				if (NodeName==_T("m_muset92")&&pChSet->nTypeSel==2)
					nOffSetCount++;
				switch(k%3)
				{
				case 0: fAng = 0.0f;    break;
				case 1: fAng = -120.0f; break;
				case 2: fAng = 120.0f;  break;
				}

				fAng += nOffSetCount*120;
				mu.UIs[k].Ang = AdjustAngle(fAng);

				mu.UIs[k].Fre = 50.0f;
				mu.UIs[k].uChnType = ((k/3)==0||(k/3)==2)?0:1;

				if (k%3==0)
					bChk = !bChk;

				mu.UIs[k].nSetData = (bChk)?57:1;
				mu.UIs[k].Mag = (bChk)?57.735f:1.0f;
				mu.UIs[k].fData1 = (bChk)?220000.0f:1000.0f;
				mu.UIs[k].fData2 = (bChk)?100.0f:1.0f;

				if (NodeName==_T("m_muset92"))
				{
					mu.UIs[k].Quo = (bChk)?2200.0f:1000.0f;
				}
				else
				{
					mu.UIs[k].Quo = 0x0000;
				}

				mu.UIs[k].uChnType = (bChk)?0:1;
				mu.UIs[k].fFirstData = 0.0f;
				mu.UIs[k].fLastData = 0.0f;
				mu.UIs[k].fStep = 0.0f;
				mu.UIs[k].bQuaTest = TRUE;
				mu.UIs[k].bVar = TRUE;

				//////////////////////////////////////////////////////////////////////////
				if (pChSet)
				{
					mu.UIs[k].strName = pChSet->strChnName;

					if (NodeName==_T("m_muset91")||
						NodeName==_T("m_muset91Ex"))
					{	//类型选择
						mu.UIs[k].uChnType = pChSet->nTypeSel;
						switch(pChSet->nTypeSel)
						{
						case 0://电压	
							mu.UIs[k].Mag = 57.735f;
							mu.UIs[k].nSetData = 57;
							mu.UIs[k].Quo = 0x2d41;
							break;
						case 1://电流（保护）
							mu.UIs[k].Mag = 1.0f;
							mu.UIs[k].nSetData = 1;
							mu.UIs[k].Quo = 0x01cf;
							break;
						case 2://电流（测量）
							mu.UIs[k].uChnType = 1;
							mu.UIs[k].Mag = 1.0f;
							mu.UIs[k].nSetData = 1;
							mu.UIs[k].Quo = 0x2d41;
							break;
						}
					}

					if (NodeName==_T("m_muset92"))
					{
						mu.UIs[k].uChnType = pChSet->nTypeSel;
						switch(pChSet->nTypeSel)
						{
						case 0://电压
							mu.UIs[k].Mag = 57.735f;
							mu.UIs[k].nSetData = 57;
							mu.UIs[k].fData1 = 220000.0f;
							mu.UIs[k].fData2 = 100.0f;
							mu.UIs[k].Quo = 2200.0f;
							break;
						case 1://电流
							mu.UIs[k].Mag = 1.0f;
							mu.UIs[k].nSetData = 1;
							mu.UIs[k].fData1 = 1000.0f;
							mu.UIs[k].fData2 = 1.0f;
							mu.UIs[k].Quo = 1000.0f;
							break;
						case 2://时间
							mu.UIs[k].uChnType = 3;
							mu.UIs[k].nSetData = 0;
							mu.UIs[k].fData1 = 0.0f;
							mu.UIs[k].fData2 = 1.0f;
							mu.UIs[k].Quo = 0.0f;
							mu.UIs[k].Mag = _wtof(pChSet->strInput);
							mu.UIs[k].Ang = 0.0f;
							mu.UIs[k].Fre = 0.0f;
							break;
						}
					}
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////
		ReadMUMSGCfgDataXml(tchildPtr,mu.UIs,nNum,str);

		READCHILDVALUE(childPtr,_T("MSGTESTSET"),str,_T(""),tchildPtr);
		mu.msgtestsetPtr = MSGTESTSETPtr(new MSGTESTSET);
		if (!tchildPtr->IsNull())
		{	
			ReadMUMSGTestSetXML(tchildPtr,mu.msgtestsetPtr);
		}
		else
		{
			InitMSGTestSet(mu.msgtestsetPtr);
		}

		mu_setting.push_back(mu);
	}
}

void CStUICfg::ReadMUMSGTestSetXML(const CXmlNodePtr& NodePtr,MSGTESTSETPtr& MuPtr)
{
	CXmlNodePtr ChildNodePtr;
	READCHILDVALUEEX(NodePtr,_T("nIndex"),MuPtr->nIndex,0,ChildNodePtr,0);
	READCHILDVALUE(NodePtr,_T("bCheck"),MuPtr->bCheck,0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("nNum"),MuPtr->nNum,0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("nTestType"),MuPtr->nTestType,0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestBeginPt"),MuPtr->TestBeginPt,0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet1-0"),MuPtr->TestTypeSet[1][0],0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet2-0"),MuPtr->TestTypeSet[2][0],0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet2-1"),MuPtr->TestTypeSet[2][1],0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet3-0"),MuPtr->TestTypeSet[3][0],0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet3-1"),MuPtr->TestTypeSet[3][1],0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet4-0"),MuPtr->TestTypeSet[4][0],0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet4-1"),MuPtr->TestTypeSet[4][1],0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet5-0"),MuPtr->TestTypeSet[5][0],0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet5-1"),MuPtr->TestTypeSet[5][1],0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet5-2"),MuPtr->TestTypeSet[5][2],0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet6-0"),MuPtr->TestTypeSet[6][0],0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet6-1"),MuPtr->TestTypeSet[6][1],0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet6-2"),MuPtr->TestTypeSet[6][2],0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet7-1"),MuPtr->TestTypeSet[7][1],0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet7-2"),MuPtr->TestTypeSet[7][2],0,ChildNodePtr);
	READCHILDVALUEEX(NodePtr,_T("logicCheck"),MuPtr->logicCheck,(__int64)0,ChildNodePtr,0);
	READCHILDVALUEEX(NodePtr,_T("nStartType"),MuPtr->nStartType,0,ChildNodePtr,0);
}

/************************************************************************/
/* zy 2012-4-12 读Goose报文测试数据										*/
/************************************************************************/
void CStUICfg::ReadGsePktTestSetXML(const CXmlNodePtr& NodePtr,GsePktTestSetPtr& GsePtr)
{
	CXmlNodePtr ChildNodePtr;
	READCHILDVALUE(NodePtr,_T("bCheck"),GsePtr->bLimit,0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("nNum"),GsePtr->nLmNum,0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("nTestType"),GsePtr->nTestType,0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("nTestPT"),GsePtr->nTestPT,0,ChildNodePtr);

	READCHILDVALUE(NodePtr,_T("TestTypeSet1-0"),GsePtr->TestParam[0][0],0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet2-0"),GsePtr->TestParam[0][1],0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet2-1"),GsePtr->TestParam[1][0],0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet3-0"),GsePtr->TestParam[1][1],0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet3-1"),GsePtr->TestParam[2][0],0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet4-0"),GsePtr->TestParam[3][0],0,ChildNodePtr);
	READCHILDVALUE(NodePtr,_T("TestTypeSet4-1"),GsePtr->TestParam[3][1],0,ChildNodePtr);
}

void CStUICfg::InitMSGTestSet(const MSGTESTSETPtr& msgtestsetptr)
{
	msgtestsetptr->nIndex = 0;
	msgtestsetptr->bCheck = FALSE;
	msgtestsetptr->nNum = 100;
	msgtestsetptr->nTestType = 0;
	msgtestsetptr->TestBeginPt = 0;
	memset(&msgtestsetptr->TestTypeSet,0,sizeof(int)*TestType*MaxItem);

	msgtestsetptr->TestTypeSet[1][0] = 10;

	for (int i = 2; i < 8; i++)
	{
		msgtestsetptr->TestTypeSet[i][0] = 20;
		msgtestsetptr->TestTypeSet[i][1] = 5;
	}

	msgtestsetptr->TestTypeSet[5][2] = 2;
	msgtestsetptr->TestTypeSet[6][2] = 0;
	msgtestsetptr->logicCheck = 1;
	msgtestsetptr->nStartType = 0;
}

/************************************************************************/
/* zy 2012-4-12 初始化Goose报文测试数据                                 */
/************************************************************************/
void CStUICfg::InitGseTestSet(const GsePktTestSetPtr& GsePtr)
{
	GsePtr->bLimit = FALSE;
	GsePtr->nLmNum = 100;
	GsePtr->nTestType = 0;
	GsePtr->nTestPT = 0;
	memset(&GsePtr->TestParam,0,sizeof(int)*4*3);

	for (int i = 0; i < 4; i++)
	{
		GsePtr->TestParam[i][0] = 20;
		GsePtr->TestParam[i][1] = 5;
	}
}

void CStUICfg::ReadMUChnCfgXML(const CXmlNodePtr& chnNoodPtr,vector<MU_CHNSET>& mu_chnset,const CString& NodeName)
{
	CString str;
	CXmlNodePtr childPtr,tchildPtr;
	CXmlNodesPtr childsPtr = chnNoodPtr->SelectNodes(NodeName);
	int nSize = childsPtr->GetCount();
	mu_chnset.reserve(nSize);
	MU_CHNSET chnset;
	for (int i = 0; i < nSize; i++)
	{
		childPtr = childsPtr->GetItem(i);

		READCHILDVALUE(childPtr,_T("m_DOWD_Q"),chnset.m_DOWD_Q,(DWORD)0,tchildPtr);
		READCHILDVALUE(childPtr,_T("nChnSel"),chnset.nChnSel,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("strInput"),chnset.strInput,_T(""),tchildPtr);
		READCHILDVALUE(childPtr,_T("nIndex"),chnset.nIndex,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("strChnName"),chnset.strChnName,_T(""),tchildPtr);
		READCHILDVALUE(childPtr,_T("bCheck"),chnset.bCheck,0,tchildPtr);
		READCHILDVALUEEX(childPtr,_T("nTypeSel"),chnset.nTypeSel,0,tchildPtr,-1);
		mu_chnset.push_back(chnset);
	}
}

void CStUICfg::ReadGOOSECfgXML(const CXmlNodePtr& gNoodPtr,vector<GSECFG>& GseCfg,const CString& NodeName)
{
	CString str;
	GSECFG gsecfg;
	GseCfg.clear();
	CXmlNodePtr childPtr,tchildPtr;
	CXmlNodesPtr childsPtr = gNoodPtr->SelectNodes(NodeName);
	int nSize = childsPtr->GetCount();
	GseCfg.reserve(nSize);

	for (int i = 0; i < nSize; i++)
	{
		childPtr = childsPtr->GetItem(i);

		READCHILDVALUE(childPtr,_T("AppID"),gsecfg.AppID,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("BinNum"),gsecfg.BinNum,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("ChkMask"),gsecfg.ChkMask,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("ConfRev"),gsecfg.ConfRev,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("DataSet"),gsecfg.DataSet,_T(""),tchildPtr);
		READCHILDVALUE(childPtr,_T("GocbRef"),gsecfg.GocbRef,_T(""),tchildPtr);
		READCHILDVALUE(childPtr,_T("GoID"),gsecfg.GoID,_T(""),tchildPtr);
		READCHILDVALUE(childPtr,_T("LanNo"),gsecfg.LanNo,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("MacAddr"),gsecfg.MacAddr,_T(""),tchildPtr);
		READCHILDVALUEEX(childPtr,_T("SourceMac"),gsecfg.SourceMac,_T(""),tchildPtr,_T("48-49-4A-4B-4C-4D"));
		READCHILDVALUE(childPtr,_T("NdsCom"),gsecfg.NdsCom,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("nIndex"),gsecfg.nIndex,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("Priority"),gsecfg.Priority,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("strDes"),gsecfg.strDes,_T(""),tchildPtr);
		READCHILDVALUE(childPtr,_T("T0"),gsecfg.T0,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("T1"),gsecfg.T1,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("T2"),gsecfg.T2,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("T3"),gsecfg.T3,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("Test"),gsecfg.Test,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("TMult"),gsecfg.TMult,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("Used"),gsecfg.Used,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("VID"),gsecfg.VID,0,tchildPtr);
		gsecfg.OldBinNum = gsecfg.BinNum;

		gsecfg.ChnCfg.clear();
		READCHILDATTR(childPtr,_T("GSECHNCFG"),str,_T("name"),tchildPtr);
		ReadGOOSEChnCfgXML(tchildPtr,gsecfg.ChnCfg,str);

		/************************************************************************/
		/* zy 2012-4-12 读取Goose报文测试数据                                   */
		/************************************************************************/
		if (m_bSaveCfgFlg)
		{
			READCHILDVALUE(childPtr,_T("GSETESTSET"),str,_T(""),tchildPtr);
			gsecfg.GsetestsetPtr = GsePktTestSetPtr(new GsePktTestSet);
			if (!tchildPtr->IsNull())
			{	
				ReadGsePktTestSetXML(tchildPtr,gsecfg.GsetestsetPtr);
			}
			else
			{
				InitGseTestSet(gsecfg.GsetestsetPtr);
			}
		}

		GseCfg.push_back(gsecfg);
	}
}

void CStUICfg::ReadGOOSEChnCfgXML(const CXmlNodePtr& chnNoodPtr,vector<GSECHNCFG>& gsechncfg,const CString& NodeName)
{
	CString str;
	GSECHNCFG chncfg;
	CXmlNodePtr childPtr,tchildPtr;
	CXmlNodesPtr childsPtr = chnNoodPtr->SelectNodes(NodeName);
	int nSize = childsPtr->GetCount();
	gsechncfg.reserve(nSize);

	for (int i = 0; i < nSize; i++)
	{
		childPtr = childsPtr->GetItem(i);

		READCHILDVALUE(childPtr,_T("nIndex"),chncfg.nIndex,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("nIOIndex"),chncfg.nIOIndex,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("nType"),chncfg.nType,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("strChnName"),chncfg.strChnName,_T(""),tchildPtr);
		READCHILDVALUE(childPtr,_T("strValue"),chncfg.strValue,_T(""),tchildPtr);
		//READCHILDVALUE(childPtr,_T("bInStruct"),chncfg.bInStruct,0,tchildPtr);
		READCHILDVALUEEX(childPtr,_T("bInStruct"),chncfg.bInStruct,0,tchildPtr,0);
		gsechncfg.push_back(chncfg);
	}
}

void CStUICfg::SaveMUGerSet(const CXmlNodePtr& MUSetNodePtr, const MU_GENERALSETTTING& mu_gset)
{
	CXmlNodePtr tchildPtr;
	ADDCHILDSETVALUE(MUSetNodePtr,_T("nSampleType"),mu_gset.nSampleType,tchildPtr);
	ADDCHILDSETVALUE(MUSetNodePtr,_T("dSampleRate"),mu_gset.dSampleRate,tchildPtr);
	ADDCHILDSETVALUE(MUSetNodePtr,_T("nMode1588"),mu_gset.nMode1588,tchildPtr);
	ADDCHILDSETVALUE(MUSetNodePtr,_T("nMuCfgNum"),mu_gset.nMuCfgNum,tchildPtr);
	ADDCHILDSETVALUE(MUSetNodePtr,_T("nAsduNum"),mu_gset.nAsduNum,tchildPtr);
	ADDCHILDSETVALUE(MUSetNodePtr,_T("dSecondCurrent"),mu_gset.dSecondCurrent,tchildPtr);
	ADDCHILDSETVALUE(MUSetNodePtr,_T("dwConfRev"),mu_gset.dwConfRev,tchildPtr);
	ADDCHILDSETVALUE(MUSetNodePtr,_T("dFTSampleRate"),mu_gset.dFTSampleRate,tchildPtr);
	ADDCHILDSETVALUE(MUSetNodePtr,_T("nFT3Format"),mu_gset.nFT3Format,tchildPtr);
	ADDCHILDSETVALUE(MUSetNodePtr,_T("bConver"),mu_gset.bConver,tchildPtr);
	//2012-02-03
	ADDCHILDSETVALUE(MUSetNodePtr,_T("bSynMode"),mu_gset.bSynMode,tchildPtr);
	//2012-03-05
	ADDCHILDSETVALUE(MUSetNodePtr,_T("nCurSelCtrl"),mu_gset.nCurSelCtrl,tchildPtr);

}

void CStUICfg::ReadMUGerSet(const CXmlNodePtr& MUSetNodePtr, MU_GENERALSETTTING& mu_gset)
{
	CXmlNodePtr tchildPtr;
	READCHILDVALUE(MUSetNodePtr,_T("nSampleType"),mu_gset.nSampleType,0,tchildPtr);
	READCHILDVALUE(MUSetNodePtr,_T("dSampleRate"),mu_gset.dSampleRate,0e+0,tchildPtr);
	READCHILDVALUE(MUSetNodePtr,_T("nMode1588"),mu_gset.nMode1588,0,tchildPtr);
	READCHILDVALUE(MUSetNodePtr,_T("nMuCfgNum"),mu_gset.nMuCfgNum,0,tchildPtr);
	READCHILDVALUE(MUSetNodePtr,_T("nAsduNum"),mu_gset.nAsduNum,0,tchildPtr);
	READCHILDVALUE(MUSetNodePtr,_T("dSecondCurrent"),mu_gset.dSecondCurrent,0e+0,tchildPtr);
	READCHILDVALUE(MUSetNodePtr,_T("dwConfRev"),mu_gset.dwConfRev,(DWORD)0,tchildPtr);
	READCHILDVALUE(MUSetNodePtr,_T("dFTSampleRate"),mu_gset.dFTSampleRate,0e+0,tchildPtr);
	READCHILDVALUEEX(MUSetNodePtr,_T("nFT3Format"),mu_gset.nFT3Format,0,tchildPtr,1);
	READCHILDVALUEEX(MUSetNodePtr,_T("bConver"),mu_gset.bConver,0,tchildPtr,0);
	//2012-02-03
	READCHILDVALUEEX(MUSetNodePtr,_T("bSynMode"),mu_gset.bSynMode,0,tchildPtr,0);
	//2012-03-05
	READCHILDVALUEEX(MUSetNodePtr,_T("nCurSelCtrl"),mu_gset.nCurSelCtrl,0,tchildPtr,-1);

}

void CStUICfg::SaveMUMSGTestSetXML(const CXmlNodePtr& NodePtr,const MSGTESTSETPtr& MuPtr)
{
	CXmlNodePtr ChildNodePtr;
	ADDCHILDSETVALUE(NodePtr,_T("nIndex"),MuPtr->nIndex,ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("bCheck"),MuPtr->bCheck,ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("nNum"),(int)MuPtr->nNum,ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("nTestType"),(int)MuPtr->nTestType,ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestBeginPt"),(int)MuPtr->TestBeginPt,ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet1-0"),MuPtr->TestTypeSet[1][0],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet2-0"),MuPtr->TestTypeSet[2][0],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet2-1"),MuPtr->TestTypeSet[2][1],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet3-0"),MuPtr->TestTypeSet[3][0],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet3-1"),MuPtr->TestTypeSet[3][1],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet4-0"),MuPtr->TestTypeSet[4][0],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet4-1"),MuPtr->TestTypeSet[4][1],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet5-0"),MuPtr->TestTypeSet[5][0],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet5-1"),MuPtr->TestTypeSet[5][1],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet5-2"),MuPtr->TestTypeSet[5][2],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet6-0"),MuPtr->TestTypeSet[6][0],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet6-1"),MuPtr->TestTypeSet[6][1],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet6-2"),MuPtr->TestTypeSet[6][2],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet7-1"),MuPtr->TestTypeSet[7][1],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet7-2"),MuPtr->TestTypeSet[7][2],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("logicCheck"),(__int64)MuPtr->logicCheck,ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("nStartType"),MuPtr->nStartType,ChildNodePtr);
}

/************************************************************************/
/* zy 2012-4-12 保存Goose报文测试数据                                   */
/************************************************************************/
void CStUICfg::SaveGsePktTestSetXML(const CXmlNodePtr& NodePtr,const GsePktTestSetPtr& GsePtr)
{
	CXmlNodePtr ChildNodePtr;
	ADDCHILDSETVALUE(NodePtr,_T("bCheck"),GsePtr->bLimit,ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("nNum"),(int)GsePtr->nLmNum,ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("nTestType"),(int)GsePtr->nTestType,ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("nTestPT"),(int)GsePtr->nTestPT,ChildNodePtr);

	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet1-0"),GsePtr->TestParam[0][0],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet2-0"),GsePtr->TestParam[0][1],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet2-1"),GsePtr->TestParam[1][0],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet3-0"),GsePtr->TestParam[1][1],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet3-1"),GsePtr->TestParam[2][1],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet4-0"),GsePtr->TestParam[3][0],ChildNodePtr);
	ADDCHILDSETVALUE(NodePtr,_T("TestTypeSet4-1"),GsePtr->TestParam[3][1],ChildNodePtr);
}

void CStUICfg::SaveMUMSGCfgDataXml(const CXmlNodePtr& NodePtr, const MuCfgData *ChDataPtr, int nSize, CString NodeNames)
{
	if (NodePtr->IsNull())
		return;

	CXmlNodePtr childPtr,tchildPtr;
	for (int i=0; i<nSize; i++)
	{
		ADDCHILDSETATTR(NodePtr,NodeNames,_T("id"),i,childPtr);

		ADDCHILDSETVALUE(childPtr,_T("uIndex"),(int)ChDataPtr[i].uIndex,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("uChnType"),(int)ChDataPtr[i].uChnType,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("Mag"),ChDataPtr[i].Mag,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("Ang"),ChDataPtr[i].Ang,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("Fre"),ChDataPtr[i].Fre,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("Quo"),ChDataPtr[i].Quo,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("fStep"),ChDataPtr[i].fStep,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("nSetData"),ChDataPtr[i].nSetData,tchildPtr);

		ADDCHILDSETVALUE(childPtr,_T("fData1"),ChDataPtr[i].fData1,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("fData2"),ChDataPtr[i].fData2,tchildPtr);

		ADDCHILDSETVALUE(childPtr,_T("fFirstData"),ChDataPtr[i].fFirstData,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("fLastData"),ChDataPtr[i].fLastData,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("bQuaTest"),(int)ChDataPtr[i].bQuaTest,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("bVar"),(int)ChDataPtr[i].bVar,tchildPtr);
		ADDCHILDSETVALUE(childPtr,_T("strName"),ChDataPtr[i].strName,tchildPtr);
	}
}

void CStUICfg::ReadMUMSGCfgDataXml(const CXmlNodePtr& NodePtr,MuCfgData *ChDataPtr,int nSize, CString NodeName)
{
	if (NodePtr->IsNull())
		return;

	CXmlNodePtr childPtr,tchildPtr;
	CXmlNodesPtr childsPtr = NodePtr->SelectNodes(NodeName);
	int nCount = childsPtr->GetCount();

	for (int i = 0; i < nCount; i++)
	{
		childPtr = childsPtr->GetItem(i);

		READCHILDVALUE(childPtr,_T("uIndex"),ChDataPtr[i].uIndex,0,tchildPtr);//(int)
		READCHILDVALUE(childPtr,_T("uChnType"),ChDataPtr[i].uChnType,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("Mag"),ChDataPtr[i].Mag,0.000f,tchildPtr);
		READCHILDVALUE(childPtr,_T("Ang"),ChDataPtr[i].Ang,0.000f,tchildPtr);
		READCHILDVALUE(childPtr,_T("Fre"),ChDataPtr[i].Fre,0.000f,tchildPtr);
		READCHILDVALUE(childPtr,_T("Quo"),ChDataPtr[i].Quo,0.000f,tchildPtr);
		READCHILDVALUE(childPtr,_T("fStep"),ChDataPtr[i].fStep,0.000f,tchildPtr);
		READCHILDVALUEEX(childPtr,_T("nSetData"),ChDataPtr[i].nSetData,0,tchildPtr,0);

		READCHILDVALUE(childPtr,_T("fData1"),ChDataPtr[i].fData1,0.000f,tchildPtr);
		READCHILDVALUE(childPtr,_T("fData2"),ChDataPtr[i].fData2,0.000f,tchildPtr);

		READCHILDVALUE(childPtr,_T("fFirstData"),ChDataPtr[i].fFirstData,0.000f,tchildPtr);
		READCHILDVALUE(childPtr,_T("fLastData"),ChDataPtr[i].fLastData,0.000f,tchildPtr);
		READCHILDVALUE(childPtr,_T("bQuaTest"),ChDataPtr[i].bQuaTest,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("bVar"),ChDataPtr[i].bVar,0,tchildPtr);
		READCHILDVALUE(childPtr,_T("strName"),ChDataPtr[i].strName,_T(""),tchildPtr);
	}
}


void CStUICfg::InitMUCFGUIData(vector<MU_SETTING>& muset91, vector<MU_SETTING>& muset92,vector<MU_SETTING>& muset91Ex)
{
	vector<MU_SETTING>::iterator itr,itre;

	itr = muset91.begin();
	itre = muset91.end();
	for (; itr != itre;itr++)
	{
		InitMUMSGCfgData(_T("m_muset91"),itr->UIs,itr->pmu_chnset);
	}

	itr = muset91Ex.begin();
	itre = muset91Ex.end();
	for (; itr != itre;itr++)
	{
		InitMUMSGCfgData(_T("m_muset91Ex"),itr->UIs,itr->pmu_chnset);
	}

	itr = muset92.begin();
	itre = muset92.end();
	for (; itr != itre;itr++)
	{
		InitMUMSGCfgData(_T("m_muset92"),itr->UIs,itr->pmu_chnset);
	}
}