//这段源代码由ClassGenerator创建
//版权所有 Eric  Eric1224@126.com
//保留所有权利

//IecCfgChs6044.cpp  CIecCfgChs6044


#include "stdafx.h"
#include "IecCfg6044Chs.h"
#include "IecCfg6044CommonChIn.h"

CIecCfg6044Chs::CIecCfg6044Chs()
{
	//初始化属性

	//初始化成员变量
}

CIecCfg6044Chs::~CIecCfg6044Chs()
{
}

long CIecCfg6044Chs::XmlReadOwn(CXmlRWNodeBase &oNode, CXmlRWKeys *pXmlRWKeys)
{
	CCfgDataMngrXmlRWKeys *pXmlKeys = (CCfgDataMngrXmlRWKeys*)pXmlRWKeys;

	return 0;
}

long CIecCfg6044Chs::XmlWriteOwn(CXmlRWDocBase &oXMLDoc, CXmlRWElementBase &oElement, CXmlRWKeys *pXmlRWKeys)
{
	CCfgDataMngrXmlRWKeys *pXmlKeys = (CCfgDataMngrXmlRWKeys*)pXmlRWKeys;

	return 0;
}

BOOL CIecCfg6044Chs::IsEqualOwn(CBaseObject* pObj)
{
	if(this == pObj)
	{
		return TRUE;
	}

	CIecCfg6044Chs *p = (CIecCfg6044Chs*)pObj;

	return TRUE;
}

BOOL CIecCfg6044Chs::CopyOwn(CBaseObject* pDest)
{
	if(this == pDest)
	{
		return TRUE;
	}

	CIecCfg6044Chs *p = (CIecCfg6044Chs*)pDest;

	return TRUE;
}

CBaseObject* CIecCfg6044Chs::Clone()
{
	CIecCfg6044Chs *p = new CIecCfg6044Chs();
	Copy(p);
	return p;
}

CExBaseObject* CIecCfg6044Chs::CreateNewChild(const CString &strClassID, BOOL &bAddToTail, CXmlRWKeys *pXmlRWKeys)
{
	CExBaseObject *pNew  = NULL;
	CCfgDataMngrXmlRWKeys *pXmlKeys = (CCfgDataMngrXmlRWKeys*)pXmlRWKeys;


	if (strClassID == pXmlKeys->m_strCIecCfg6044ChKey)
	{
		pNew = new CIecCfg6044Ch();
	}
	else if (strClassID == pXmlKeys->m_strCIecCfg6044CommonChKey)
	{
		pNew = new CIecCfg6044CommonCh();
	}
	else if (strClassID == pXmlKeys->m_strCIecCfg6044CommonChInKey)
	{
		pNew = new CIecCfg6044CommonChIn();
	}

	return pNew;
}

CExBaseObject* CIecCfg6044Chs::CreateNewChild(long nClassID/*, BOOL &bAddToTail*/)
{
	CExBaseObject *pNew  = NULL;


	if (nClassID == CFGCLASSID_CIECCFG6044CH)
	{
		pNew = new CIecCfg6044Ch();
	}
	else if (nClassID == CFGCLASSID_CIECCFG6044COMMONCH)
	{
		pNew = new CIecCfg6044CommonCh();
	}
	else if (nClassID == CFGCLASSID_CIECCFG6044COMMONCHIN)
	{
		pNew = new CIecCfg6044CommonChIn();
	}

	return pNew;
}

CIecCfgDataChBase* CIecCfg6044Chs::CreateChannel()
{
	CIecCfgDataChBase *pNew = NULL;

	if (m_pParent->GetClassID() == CFGCLASSID_CIECCFG6044DATA)
	{
		pNew = new CIecCfg6044Ch();
	}
	else if (m_pParent->GetClassID() == CFGCLASSID_CIECCFG6044COMMONDATA)
	{
		pNew = new CIecCfg6044CommonCh();
	}
	else if (m_pParent->GetClassID() == CFGCLASSID_CIECCFG6044COMMONINDATA)
	{
		pNew = new CIecCfg6044CommonChIn();
	}
	else if (m_pParent->GetClassID() == CFGCLASSID_CIECCFG2MDATA)
	{
		pNew = new CIecCfg6044CommonCh();
	}
	else if (m_pParent->GetClassID() == CFGCLASSID_CIECCFG2MINDATA)
	{
		pNew = new CIecCfg6044CommonCh();
	}	
	ASSERT(pNew);
	return pNew;
}


void CIecCfg6044Chs::InitAfterRead()
{
//	SetChannelNum(22);   周宏军  20200510  无需将通道数固定为22通道
}

#ifdef _USE_IN_AT02D_MODE_
void CIecCfg6044Chs::SetAT02D_ChannelID(CExBaseList *pSVList,long &nCBIndex)
{
	CExBaseObject *pCurObj = NULL;
	CIecCfg6044CommonCh *pIecCfg6044CommonCh = NULL;

	long nDelayIndex = 1;
	long nCurChannelIndex = 1;
	long nVolChannelIndex = 1;
	CString strAT02D_ID;

	POS pos = GetHeadPosition();

	while(pos)
	{
		pCurObj = GetNext(pos);

		if ((pCurObj->GetClassID() != CFGCLASSID_CIECCFG6044COMMONCH) &&
			(pCurObj->GetClassID() != CFGCLASSID_CIECCFG6044COMMONCHIN))
		{
			continue;
		}

		pIecCfg6044CommonCh = (CIecCfg6044CommonCh*)pCurObj;

		if ((pIecCfg6044CommonCh->m_strChType == iecfg_SmvChDataType_Val_DCCur)
			||(pIecCfg6044CommonCh->m_strChType == iecfg_SmvChDataType_Val_6CurrProt)
			||(pIecCfg6044CommonCh->m_strChType == iecfg_SmvChDataType_Val_6CurrMeasure)
			||(pIecCfg6044CommonCh->m_strChType == iecfg_SmvChDataType_Val_Curr)
			||(pIecCfg6044CommonCh->m_strChType == iecfg_SmvChDataType_Val_CurrMeasure))
		{
			strAT02D_ID.Format(_T("SV%ld_I%ld"),nCBIndex,nCurChannelIndex);
			nCurChannelIndex++;

			if (!pIecCfg6044CommonCh->m_strAppChID.IsEmpty())
			{
				strAT02D_ID += _T("_");
				strAT02D_ID += pIecCfg6044CommonCh->m_strAppChID;
			}

			pIecCfg6044CommonCh->m_strID = strAT02D_ID;
		}
		else if ((pIecCfg6044CommonCh->m_strChType == iecfg_SmvChDataType_Val_Vol)
			||(pIecCfg6044CommonCh->m_strChType == iecfg_SmvChDataType_Val_DCVol)
			||(pIecCfg6044CommonCh->m_strChType == iecfg_SmvChDataType_Val_6Vol))
		{
			strAT02D_ID.Format(_T("SV%ld_U%ld"),nCBIndex,nVolChannelIndex);
			nVolChannelIndex++;

			if (!pIecCfg6044CommonCh->m_strAppChID.IsEmpty())
			{
				strAT02D_ID += _T("_");
				strAT02D_ID += pIecCfg6044CommonCh->m_strAppChID;
			}

			pIecCfg6044CommonCh->m_strID = strAT02D_ID;
		}
		else if (pIecCfg6044CommonCh->m_strChType == iecfg_SmvChDataType_Val_StateValue)
		{
			pIecCfg6044CommonCh->m_strID.Format(_T("SV%ld_B%ld"),nCBIndex,nDelayIndex);
			nDelayIndex++;
		}
		else if (pIecCfg6044CommonCh->m_strChType == iecfg_SmvChDataType_Val_Other)
		{
			pIecCfg6044CommonCh->m_strID.Format(_T("SV%ld_O%ld"),nCBIndex,nDelayIndex);
			nDelayIndex++;
		}
		else
		{
			pIecCfg6044CommonCh->m_strID = _T("");
		}
	}
}
#endif