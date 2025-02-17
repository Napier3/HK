#include "stdafx.h"
#include "MacroTest.h"
#include "Safety.h"
#include "GuideBook.h"


#include "..\..\..\Module\TestMacro\TestMacroInterface.h"

CMacroTest::CMacroTest()
{
	m_strType = _T("macrotest");
	m_nRepeatTimes = 0;
	m_pPara = NULL;
	m_nTestTimes = 0;
}

CMacroTest::~CMacroTest()
{
	m_oListMsgs.RemoveAll();
}

void CMacroTest::InitMacroID()
{
// 	CTestMacros *pMacros = Gb_GetMacrosPtr(this);
// 	CTestMacro  *pMacro = (CTestMacro*)pMacros->GetHead();
// 
// 	if (pMacro != NULL)
// 	{
// 		m_pPara->SetMacroID(pMacro->m_strID);
// 	}
	CItems *pItems = GetRsltExprScriptItems();

	if (pItems == NULL)
	{
		m_pPara->InitMacroID();
	}
	else
	{
		CItemsRsltExprScript *pRsltExpr = pItems->GetItemsRsltExprScript(FALSE);
		m_pPara->SetMacroID(pRsltExpr->m_strTestMacroID);
	}
}

BOOL CMacroTest::GetItemParaValue(const CString &strValueID, double &dValue)
{
	CValues* pValues;
	CValue *pVal = NULL;
	BOOL bTrue = FALSE;

	m_pPara->InitTestParaDatas();
	pValues = m_pPara->GetParaValues();
	int nCount = pValues->GetCount();

	CString str;

	pVal = (CValue*)pValues->FindByID(strValueID);

	if (pVal != NULL)
	{
		bTrue = TRUE;
		dValue = _wtof(pVal->m_strValue);
	}
	else
	{
		//显示：数据不存在
	}

	return bTrue;
}

long CMacroTest::SetItemParaValue(const CString & strValueID, const CString & strValue, BOOL bAddNew)
{
	CValues* pValues;
	CValue *pVal = NULL;
	BOOL bTrue = FALSE;

	m_pPara->InitTestParaDatas();
	pValues = m_pPara->GetParaValues();
	pVal = (CValue*)pValues->FindByID(strValueID);

	if (pVal != NULL)
	{
		bTrue = TRUE;
		pVal->m_strValue = strValue;
		pVal->m_dwReserved = 1;
	}
	else
	{
		if (bAddNew)
		{
			pVal = new CValue();
			bTrue = TRUE;
			pVal->m_strValue = strValue;
			pVal->m_strID = strValueID;
			pVal->m_dwReserved = 1;
			pValues->AddNewChild(pVal);
		}
		//显示：数据不存在
	}

	return bTrue;
}

void GB_FinishTest_ActTime(CValue *pValue)
{
	double dVal = _wtof(pValue->m_strValue);

	if (dVal <= 0.001)
	{
		pValue->m_strValue = /*g_pszTripTimeDesc_NoTrip*/CXLanguageResourceAtsBase::g_sLangTxt_Unact;
	}
	else
	{
		pValue->m_strValue = /*g_pszTripTimeDesc_Trip*/CXLanguageResourceAtsBase::g_sLangTxt_Act;
	}
}

double GB_FinishTest_TtripTime(CValue *pValue, BOOL bIsAngle)
{
	double dVal = _wtof(pValue->m_strValue);

	//如果是角度，则判断小于-360
	if (bIsAngle)
	{
		if (dVal < -360.0)
		{
			pValue->m_strValue = /*g_pszTripTimeDesc_NoTrip*/CXLanguageResourceAtsBase::g_sLangTxt_Unact;
		}
	}
	else
	{
		if (dVal <= 0.001)
		{
			pValue->m_strValue = /*g_pszTripTimeDesc_NoTrip*/CXLanguageResourceAtsBase::g_sLangTxt_Unact;
		}
	}

	return dVal;
}

void GB_FinishTest_RsltDsc(CValue *pValue)
{
	double dVal = _wtof(pValue->m_strValue);

	if (dVal <= 0.001)
	{
		pValue->m_strValue = /*g_strResultDescValueIncorrect*/CXLanguageResourceAtsBase::g_sLangTxt_Unqualified;
	}
	else
	{
		pValue->m_strValue = /*g_strResultDescValueCorrect*/CXLanguageResourceAtsBase::g_sLangTxt_Qualified;
	}
}

void CMacroTest::AdjustReprtDatas()
{
	CValue *pVal = NULL;
	CValue *pActVal = NULL;
	CValues* oVals = NULL;
	CReport *pReport = GetReport(-1);

	if (pReport == NULL)
	{
		return;
	}

	oVals = pReport->m_pValues;
	POS pos = oVals->GetHeadPosition();
	CString strActID;

	while (pos != NULL)
	{
		pVal = (CValue*)oVals->GetNext(pos);
		BOOL bIsAngle = FALSE;

		//if (pVal->m_strID.Find(g_pszTripTimeKey_Trip) >= 0)
		if (Gb_IsTripKeyID(pVal->m_strID, bIsAngle))
		{
			double dVal = GB_FinishTest_TtripTime(pVal, bIsAngle);
			strActID = Gb_GetActKeyIDByTripKeyID(pVal->m_strID);
			pActVal = (CValue *)oVals->FindByID(strActID);

			if (pActVal != NULL)
			{
				if (bIsAngle)
				{
					if (dVal > -360.0)
					{
						pActVal->m_strValue =/* g_pszTripTimeDesc_Trip*/CXLanguageResourceAtsBase::g_sLangTxt_Act;
					}
					else
					{
						pActVal->m_strValue = /*g_pszTripTimeDesc_NoTrip*/CXLanguageResourceAtsBase::g_sLangTxt_Unact;
					}
				}
				else
				{
					if (dVal > 0)
					{
						pActVal->m_strValue = /*g_pszTripTimeDesc_Trip*/CXLanguageResourceAtsBase::g_sLangTxt_Act;
					}
					else
					{
						pActVal->m_strValue = /*g_pszTripTimeDesc_NoTrip*/CXLanguageResourceAtsBase::g_sLangTxt_Unact;
					}
				}
			}
		}
// 		else if (pVal->m_strID.Find(g_pszTripTimeKey_Act) >= 0)
// 		{
// 			GB_FinishTest_ActTime(pVal);
// 		}
		else
		{
		}
	}
}

long CMacroTest::SerializeOwn(CBinarySerialBuffer &oBinaryBuffer)
{
	CGbItemBase::SerializeOwn(oBinaryBuffer);

	if (oBinaryBuffer.IsCalSizeMode())
	{
		BinarySerializeCalLen(oBinaryBuffer, m_strType);
		BinarySerializeCalLen(oBinaryBuffer, m_nRepeatTimes);
		BinarySerializeCalLen(oBinaryBuffer, m_strReportMode);
		BinarySerializeCalLen(oBinaryBuffer, m_nTestTimes);
	}
	else if (oBinaryBuffer.IsReadMode())
	{
		BinarySerializeRead(oBinaryBuffer, m_strType);
		BinarySerializeRead(oBinaryBuffer, m_nRepeatTimes);

		if (oBinaryBuffer.m_dwVersion >= GBVERSION_1_5)
		{
			BinarySerializeRead(oBinaryBuffer, m_strReportMode);
		}
		if (oBinaryBuffer.m_dwVersion >= GBVERSION_1_6)
		{
			BinarySerializeRead(oBinaryBuffer, m_nTestTimes);
		}
	}
	else if (oBinaryBuffer.IsWriteMode())
	{
		BinarySerializeWrite(oBinaryBuffer, m_strType);
		BinarySerializeWrite(oBinaryBuffer, m_nRepeatTimes);
		BinarySerializeWrite(oBinaryBuffer, m_strReportMode);
		BinarySerializeWrite(oBinaryBuffer, m_nTestTimes);
	}
	return 0;
}

long CMacroTest::XmlReadOwn(const MSXML2::IXMLDOMNodePtr &oNode, CXmlRWKeys *pXmlRWKeys)
{
	CGbItemBase::XmlReadOwn(oNode,pXmlRWKeys);

	xml_GetAttibuteValue(CGbXMLKeys::g_pGbXMLKeys->m_strTypeKey,oNode,m_strType);
	xml_GetAttibuteValue(CGbXMLKeys::g_pGbXMLKeys->m_strRepeatTimes,oNode,m_nRepeatTimes);
	xml_GetAttibuteValue(CGbXMLKeys::g_pGbXMLKeys->m_strCalModeKey,oNode,m_strReportMode);

	return 0;
}

long CMacroTest::XmlWriteOwn(const MSXML2::IXMLDOMDocumentPtr &oXMLDoc, const MSXML2::IXMLDOMElementPtr &oElement, CXmlRWKeys *pXmlRWKeys)
{
	CGbItemBase::XmlWriteOwn(oXMLDoc,oElement,pXmlRWKeys);

	xml_SetAttributeValue(CGbXMLKeys::g_pGbXMLKeys->m_strTypeKey,oElement,m_strType);
	xml_SetAttributeValue(CGbXMLKeys::g_pGbXMLKeys->m_strRepeatTimes,oElement,m_nRepeatTimes);
	xml_SetAttributeValue(CGbXMLKeys::g_pGbXMLKeys->m_strCalModeKey,oElement,m_strReportMode);

	return 0;
}

void CMacroTest::InitAfterRead()
{
	CGbItemBase::InitAfterRead();

	m_oListMsgs.RemoveAll();

	POS pos = GetHeadPosition();
	CExBaseObject *p = NULL;
	UINT nClassID = 0;

	while (pos != NULL)
	{
		p = GetNext(pos);
		nClassID = p->GetClassID();

		switch (nClassID)
		{
		case GBCLASSID_MSG:
			m_oListMsgs.AddTail(p);
			break;
// 		case GBCLASSID_COMMCMD:
// 		case GBCLASSID_SAFETY:
// 			m_oSubGbItems.AddTail(p);
// 			break;
		case GBCLASSID_MACROPARA:
			m_pPara = (CMacroTestPara*)p;
			break;

		case GBCLASSID_COMMCMD:
		case GBCLASSID_SAFETY:
			m_oSubGbItems.AddTail(p);
			((CGbItemBase*)p)->m_bIsSubItem = TRUE;
			break;

		default:
			break;
		}
	}

	if (m_pPara == NULL)
	{
		m_pPara = new CMacroTestPara();
		m_pPara->InitAfterRead();
		AddNewChild(m_pPara);
	}
}

CExBaseObject* CMacroTest::CreateNewChild(const CString &strClassID, BOOL &bAddToTail, CXmlRWKeys *pXmlRWKeys)
{
	if(strClassID == CGbXMLKeys::g_pGbXMLKeys->m_strMsgKey)
	{
		CMsg* pMsg = new CMsg();
		return pMsg;
	}
	else if(strClassID == CGbXMLKeys::g_pGbXMLKeys->m_strParaKey)
	{
		m_pPara = new CMacroTestPara();
		return m_pPara;
	}
	else if(strClassID == CGbXMLKeys::g_pGbXMLKeys->m_strCommCmdKey)
	{
		CCommCmd* pCmd = new CCommCmd();
		return pCmd;
	}
	else if (strClassID == CGbXMLKeys::g_pGbXMLKeys->m_strSafetyKey)
	{
		CSafety* pObject = new CSafety;
		return pObject;
	}

	return CGbItemBase::CreateNewChild(strClassID,bAddToTail,pXmlRWKeys);
}

CExBaseObject* CMacroTest::CreateNewChild(long nClassID)
{
	if(nClassID == GBCLASSID_MSG)
	{
		CMsg* pMsg = new CMsg();
		return pMsg;
	}
	else if(nClassID == GBCLASSID_MACROPARA)
	{
		m_pPara = new CMacroTestPara();
		return m_pPara;
	}
	else if(nClassID == GBCLASSID_COMMCMD)
	{
		CCommCmd* pCmd = new CCommCmd();
		return pCmd;
	}
	else if (nClassID == GBCLASSID_SAFETY)
	{
		CSafety* pObject = new CSafety;
		return pObject;
	}

	return CGbItemBase::CreateNewChild(nClassID);
}

BOOL CMacroTest::IsEqual(CBaseObject* pObj)
{
	return FALSE;
}

BOOL CMacroTest::CopyOwn(CBaseObject* pDesObj)
{
	ASSERT(pDesObj != NULL);
	if(pDesObj == this)
		return TRUE;

 	CMacroTest* pMacroTest = (CMacroTest*)pDesObj;
	pMacroTest->m_strType = m_strType;
	pMacroTest->m_nRepeatTimes = m_nRepeatTimes;
	pMacroTest->m_strReportMode = m_strReportMode;

	CGbItemBase::CopyOwn(pDesObj);

	return TRUE;
}

CBaseObject* CMacroTest::Clone()
{
	CMacroTest* pMacroTest = new CMacroTest();
	Copy(pMacroTest);

	return pMacroTest;
}

BOOL CMacroTest::CanPaste(UINT nClassID)
{
	if (nClassID == GBCLASSID_COMMCMD || nClassID == GBCLASSID_SAFETY)
	{
		return TRUE;
	}

	return FALSE;
}

void CMacroTest::SetTestMacroID(const CString &strTestMacroID)
{
	ASSERT (m_pPara != NULL);
	return m_pPara->SetMacroID(strTestMacroID);
}

CString CMacroTest::GetTestMacroID()
{
	if (m_pPara == NULL)
	{
		return _T("");
	}

	return m_pPara->GetMacroID();
}

CMacroTestPara* CMacroTest::GetMacroTestPara()
{		
	return m_pPara;		
}

CMacroTestParaDatas* CMacroTest::GetFaultParaDatas()
{
	CMacroTestParaDatas *pPara = NULL;

	if (m_pPara != NULL)
	{
		pPara = m_pPara->GetFaultParaDatas();
	}

	return pPara;
}

CMacroTestParaDatas* CMacroTest::GetFultParaDatasUser()
{
	CMacroTestParaDatas *pPara = NULL;

	if (m_pPara != NULL)
	{
		pPara = m_pPara->GetFaultParaDatasUser();
	}

	return pPara;
}

void CMacroTest::ClearReport()
{
	CGbItemBase::ClearReport();

	POS pos = GetHeadPosition();
	CExBaseObject *p = NULL;

	while (pos != NULL)
	{
		p = GetNext(pos);

		if(p->GetClassID() == GBCLASSID_COMMCMD)
		{
			CCommCmd *pCommCmd = (CCommCmd*)p;
			pCommCmd->ClearReport();
		}	
	}	
}


void CMacroTest::ReplaceSrciptText(CScriptText *pScript, UINT nScriptClassID, CGbItemBase *pSrcGbItem, BOOL bShowLog)
{
	CMacroTest *pSrcMacroTest = (CMacroTest*)pSrcGbItem;

	if (pSrcMacroTest->GetTestMacroID() != GetTestMacroID())
	{
		return;
	}

	if (nScriptClassID == GBCLASSID_SCRIPTTEXT)
	{
		CScriptText *pDest = m_pPara->GetScriptText();
		pScript->CopyOwn(pDest);
		return;
	}

	CGbItemBase::ReplaceSrciptText(pScript, nScriptClassID, pSrcGbItem, bShowLog);
}

#ifdef GUIDEBOOK_DEV_MODE

void CMacroTest::GenerateDevReports()
{
	CReport* pReport = GetCurrReport();

	if (pReport == NULL)
	{
		pReport = AddReport(-1, -1);
	}
	else
	{
		pReport->m_pValues->DeleteAll();
	}

	CValues* oValsTemp = NULL;
	CTestMacro* oTestMacro = Gb_GetMacroPtr(this);
	
	ASSERT(oTestMacro != NULL);

	if(oTestMacro != NULL)
	{
		CShortDatas  *pDatas = oTestMacro->GetFaultParas();
		pDatas->AppendValues(pReport->m_pValues);

		pDatas = oTestMacro->GetSysParas();
		pDatas->AppendValues(pReport->m_pValues);

		pDatas = oTestMacro->GetResults();
		pDatas->AppendValues(pReport->m_pValues);
	}
	
}

#endif

void Gb_ResetMacroParas(CTestMacro* pMacro)
{
	if (pMacro == NULL)
	{
		return;
	}

	CShortDatas  *pDatas = pMacro->GetFaultParas();
	Gb_ResetDatas(pDatas);

	pDatas = pMacro->GetSysParas();
	Gb_ResetDatas(pDatas);
}

void Gb_ResetDatas(CShortDatas *pDatas)
{
	if (pDatas == NULL)
	{
		return;
	}

	pDatas->ResetDatas();
}

CString Gb_GetMacroScriptUiDll(CMacroTest *pMacroTest)
{
	if (pMacroTest == NULL)
	{
		return _T("");
	}

	CMacroTestPara *pTestPara = pMacroTest->GetMacroTestPara();
	CString strMacroID = pTestPara->GetMacroID();
	CTestMacros* pMacros = Gb_GetMacrosPtr(pMacroTest);

	if (pMacros == NULL)
	{
		return _T("");
	}

	CTestMacro *pMacro = (CTestMacro*)pMacros->FindByID(strMacroID);

	if (pMacro == NULL)
	{
		return _T("");
	}

	CTestMacroScript *pScript = TM_GetTestMacroScript(pMacro);

	if (pScript != NULL)
	{
		return pScript->m_strUIDLL;
	}

	return _T("");
}

