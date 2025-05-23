#include "StdAfx.h"
#include "RptTemplate_GenXmlTool.h"
#include "..\..\..\SttStudio\Module\UI\Config\MacroTestUI\SttMacroTestUI_TestMacroUIDB.h"
#include "RptTemp_Png.h"

CRptTemplate_GenXmlTool::CRptTemplate_GenXmlTool(void)
{
	m_pRptTemp_GuideBook = NULL;
	m_pRptTemp_TestMacroUiRpt = NULL;
	m_pGuideBook = NULL;

	CString strSysPath;
	strSysPath = _P_GetInstallPath();
	strSysPath += _T("STT/");
	InitGbGenSysPath(strSysPath); 
	InitRptTemplateCfg();
}

CRptTemplate_GenXmlTool::~CRptTemplate_GenXmlTool(void)
{
	if (m_pRptTemp_GuideBook != NULL)
	{
		delete m_pRptTemp_GuideBook;
		m_pRptTemp_GuideBook = NULL;
	}

	if (m_pRptTemp_TestMacroUiRpt != NULL)
	{
		delete m_pRptTemp_TestMacroUiRpt;
		m_pRptTemp_TestMacroUiRpt = NULL;
	}
}

void CRptTemplate_GenXmlTool::InitRptTemplateCfg()
{
	m_oRptTemplateCfg.OpenReportTemplateConfigFile();
}

void CRptTemplate_GenXmlTool::InitGbGenSysPath(const CString &strSysPath)
{
	CString strPath = strSysPath;

	if (strPath.GetLength() == 0)
	{
		strPath = _P_GetSystemPath();
	}

	m_strConfigPath = strPath;
	m_strConfigPath += g_pszKeyConfig;
	m_strConfigPath += _T("/");

	m_strDbPath = strPath;
	m_strDbPath += g_pszKeyDB;
	m_strDbPath += _T("/");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//以下是导出XML格式的报告数据文件的部分
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Dat(const CString &strXmlFile, CGuideBook *pGuideBook)
{
	if (pGuideBook == NULL)
	{
		return FALSE;
	}

	m_strXmlFile_Dat = strXmlFile;
	BOOL bRet = TRUE;

	if (m_pRptTemp_GuideBook == NULL)
	{
		m_pRptTemp_GuideBook = new CRptTemp_GuideBook();
	}

	m_pRptTemp_GuideBook->DeleteAll();

	m_pGuideBook = pGuideBook;
	CDevice *pDevice = pGuideBook->GetDevice();
	bRet = GenRpt_Xml_Dat_Device(m_pRptTemp_GuideBook, pDevice);

	m_pRptTemp_GuideBook->SaveXmlFile(m_strXmlFile_Dat, CTestMacroRptTemplateXmlRWKeys::g_pXmlKeys);

	return bRet;
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Dat_Device(CRptTemp_GuideBook *pRptTemp_GuideBook, CDevice *pDevice)
{
	if (pDevice == NULL || pRptTemp_GuideBook == NULL)
	{
		return FALSE;
	}

	BOOL bRet = TRUE;
	POS pos = pDevice->GetHeadPosition();
	CExBaseObject *pObj = NULL;
	UINT nClassID = 0;

	while (pos != NULL)
	{
		pObj = pDevice->GetNext(pos);
		nClassID = pObj->GetClassID();

		if (nClassID != GBCLASSID_ITEMS)
		{
			continue;
		}

		CItems *pItems = (CItems *)pObj;

		if (! GenRpt_Xml_Dat_Items(pRptTemp_GuideBook, pItems))
		{
			bRet = FALSE;
		}
	}

	return bRet;
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Dat_Items(CExBaseList *pParent, CItems *pItems)
{
	if (pParent == NULL || pItems == NULL)
	{
		return FALSE;
	}

	if (pItems->IsTypeRootNode())
	{
		return GenRpt_Xml_Items_Dat_RootNode(pParent, pItems);
	}

	return GenRpt_Xml_Items_Dat_Normal(pParent, pItems);
}

//递归调用，只针对人工创建的CItems
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Items_Dat_Normal(CExBaseList *pParent, CItems *pItems)
{
	if (pParent == NULL || pItems == NULL)
	{
		return FALSE;
	}

	//对于人工创建的CItems节点，只需要导出子的CItems即可
	//因为就算人工创建的CItems节点，子对象包含CMacroTest，也不知道需要导出的报告数据有哪些
	CRptTemp_Items *pRptTemp_Items = GenRpt_Xml_NewItems(pParent, pItems);

	if (pRptTemp_Items == NULL)
	{
		return FALSE;
	}

	BOOL bRet = TRUE;
	POS pos = pItems->GetHeadPosition();
	UINT nClassID = 0;
	CExBaseObject *pObj = NULL;

	while (pos != NULL)
	{
		pObj = pItems->GetNext(pos);
		nClassID = pObj->GetClassID();

		if (nClassID != GBCLASSID_ITEMS)
		{
			continue;
		}

		CItems *pChildItems = (CItems *)pObj;

		if (pChildItems->IsTypeRootNode())
		{
			if (! GenRpt_Xml_Items_Dat_RootNode(pRptTemp_Items, pChildItems))
			{
				bRet = FALSE;
			}
		}
		else
		{
			if (! GenRpt_Xml_Items_Dat_Normal(pRptTemp_Items, pChildItems))
			{
				bRet = FALSE;
			}
		}
	}

	return bRet;
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Items_Dat_RootNode(CExBaseList *pParent, CItems *pItems)
{
	if (pParent == NULL || pItems == NULL)
	{
		return FALSE;
	}

	CRptTemp_Items *pRptTemp_Items = GenRpt_Xml_NewItems(pParent, pItems);

	if (pRptTemp_Items == NULL)
	{
		return FALSE;
	}

	CSttMacroTestUI_TestMacroUIs *pUIs = CSttMacroTestUI_TestMacroUIDB::g_pSttTestMacroUIDB->GetTestMacroUIs();
	CSttMacroTestUI_TestMacroUI *pUI = (CSttMacroTestUI_TestMacroUI *)pUIs->FindByID(pItems->m_strStxmlFile);

	if (pUI == NULL)
	{
		return FALSE;
	}

	CRptTemp_TestMacroUiRptDef oRptDef;
	CString strFile;
	strFile = GetDBPath(); 
	strFile += STT_MACROTEST_UI_REALPATH_ATSGEN;
	strFile += _T("/");
	strFile += pUI->m_strrpt_Data_CfgFile;
	BOOL bRet = TRUE;

	if (!IsFileExist(strFile))
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("报告数据配置文件【%s】不存在"), strFile.GetString());
		return FALSE;
	}

	CTestMacroRptTemplateXmlRWKeys::g_pXmlKeys->m_nIsGroupUseDvmData++;
	bRet = oRptDef.OpenXmlFile(strFile, CTestMacroRptTemplateXmlRWKeys::g_pXmlKeys);
	CTestMacroRptTemplateXmlRWKeys::g_pXmlKeys->m_nIsGroupUseDvmData--;
	
	if (!bRet)
	{
		return FALSE;
	}
	
	CString strItemPath;
	strItemPath = pItems->GetIDPathEx(GBCLASSID_DEVICE, FALSE);

	if (!GenRpt_Xml_Items_Dat_RootNode_UpdateItemsTec(&oRptDef, strItemPath))
	{
		return FALSE;
	}

	bRet = GenRpt_Xml_Items_Dat_RootNode_Items(&oRptDef, pRptTemp_Items, pItems);

	return bRet;
}

/*
<group id="items-tecs" data-type="items-tecs">【技术要求编辑+数据小数位数配置】
	<group id="item-path" data-type="items-tec">【一个group，代表一个项目的技术要求+报告数据保留小数位数，id填写为实际项目路径】
		<data id="rpt_tec_data1" value=""/>【技术要求，id用固定前缀：“rpt_tec_”。技术要求可以有多个】
		<data name="动作值小数点位数" data-type="int" id="rpt_precision_data1" value="1" min="0" max="4"/>【报告数据小数位数编辑，id用固定前缀：“rpt_precision_”。小数位数编辑可以有多个】
	</group>
	<group id="item-path" data-type="items-tec">
		<data id="rpt_tec_data1" value=""/>
	</group>
	<group id="item-path" data-type="items-tec">
		<data id="rpt_tec_data1" value=""/>
	</group>
	……
</group>
*/
//更新“技术要求” + “报告数据保留小数位数”数据接口
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Items_Dat_RootNode_UpdateItemsTec(CRptTemp_TestMacroUiRptDef *pRptDef, const CString &strItemPath)
{
	if (pRptDef == NULL)
	{
		return FALSE;
	}

	if (m_pGuideBook == NULL)
	{
		return FALSE;
	}

	CDataGroup *pSrc = m_pGuideBook->GetItemsTec();
	CDataGroup *pDest = pRptDef->GetItemsTec();

	if (pDest == NULL)
	{
		return TRUE;
	}

	if (pSrc == NULL)
	{
		return FALSE;
	}

	CDataGroup *pItemTec = (CDataGroup *)pSrc->FindByID(strItemPath);

	if (pItemTec == NULL)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("未找到项目【%s】对应的技术要求 + 报告数据保留小数位数配置"), strItemPath.GetString());
		return FALSE;
	}

	pDest->InitDataValues(pItemTec, FALSE);

	return TRUE;
}

//rootnode下，可以只考虑items、macrotest和char-macro-items
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Items_Dat_RootNode_Items(CRptTemp_TestMacroUiRptDef *pRptDef, CRptTemp_Items *pRptItems, CItems *pItems)
{
	if (pRptItems == NULL || pRptDef == NULL)
	{
		return FALSE;
	}

	BOOL bRet = TRUE;
	UINT nClassID = 0;
	CExBaseObject *pObj = NULL;
	POS pos = pItems->GetHeadPosition();

	while (pos != NULL)
	{
		pObj = pItems->GetNext(pos);
		nClassID = pObj->GetClassID();

		if (nClassID == GBCLASSID_ITEMS)
		{
			CItems *pItemsChild = (CItems *)pObj;
			CRptTemp_Items *pRptTemp_ItemsChild = GenRpt_Xml_NewItems(pRptItems, pItemsChild);

			if (pRptTemp_ItemsChild == NULL)
			{
				bRet = FALSE;
				continue;
			}

			if (! GenRpt_Xml_Items_Dat_RootNode_Items(pRptDef, pRptTemp_ItemsChild, pItemsChild))
			{
				bRet = FALSE;
			}
		}
		else if (nClassID == GBCLASSID_MACROTEST)
		{
			CMacroTest *pMacroTest = (CMacroTest *)pObj;
			
			if (! GenRpt_Xml_Items_Dat_RootNode_MacroTest(pRptDef, pRptItems, pMacroTest))
			{
				bRet = FALSE;
			}
		}
		else if (nClassID == GBCLASSID_MACROCHARITEMS)
		{
			CMacroCharItems *pMacroCharItems = (CMacroCharItems *)pObj;

			if (! GenRpt_Xml_Items_Dat_RootNode_MacroCharItems(pRptDef, pRptItems, pMacroCharItems))
			{
				bRet = FALSE;
			}
		}
	}

	return bRet;
}

//电气量项目的父节点，有两种：CItems，CMacroCharItems。应该区分处理
//处理父项目是CItems的电气量
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Items_Dat_RootNode_MacroTest(CRptTemp_TestMacroUiRptDef *pRptDef, CRptTemp_Items *pRptItems, CMacroTest *pMacroTest)
{
	CString strMacroID = pMacroTest->GetTestMacroID();
	CExBaseList oListParas;
	GetMacroTest_AllParas(&oListParas, pMacroTest);
	CRptTemp_MacroTest *pRptTemp_MacroTestDef = pRptDef->FindMacroTestByMacroID(strMacroID, &oListParas);

	if (pRptTemp_MacroTestDef == NULL)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("报告数据配置文件中，找不到macrotest节点【%s】"), strMacroID.GetString());
		//找不到，可能是不需要导出报告数据的电气量项目，所以返回TRUE
		return TRUE;
	}

	CRptTemp_ReportsDef* pRptTemp_ReportsDef = pRptTemp_MacroTestDef->GetRpeortsDef();

	if (pRptTemp_ReportsDef == NULL)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("报告数据配置文件中，macrotest节点【%s】未定义reports-def"), strMacroID.GetString());
		return FALSE;
	}

	CRptTemp_MacroTest* pRptMacroTestNew = GenRpt_Xml_NewMacroTest(pRptItems, pMacroTest);
	CExBaseList oRptLists;
	GetItemReports(&oRptLists, pMacroTest);

	BOOL bRet = GenRpt_Xml_MacroTest_Dat_Reports(pRptTemp_ReportsDef, &oRptLists, pRptMacroTestNew, pMacroTest);
	oRptLists.RemoveAll();
	return bRet;
}

//处理父项目是CMacroCharItems的电气量
//形参1：报告数据配置文件中定义的macro-char-items模板；
//形参2：实例化的macro-char-items节点
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Items_Dat_RootNode_MacroTest(CRptTemp_MacroCharItems *pMacroCharItemsDef, CRptTemp_MacroCharItems *pNewMacroCharItems, CMacroTest *pMacroTest)
{
	CRptTemp_MacroTest *pMacroTestDef = pMacroCharItemsDef->GetMacroTest();

	if (pMacroTestDef == NULL)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("报告数据配置文件中，macro-char-items节点【%s】，未配置macrotest子节点"), pMacroCharItemsDef->m_strMacro_Id.GetString());
		return FALSE;
	}

	CString strMacroID = pMacroTest->GetTestMacroID();

	if (strMacroID != pMacroTestDef->m_strMacro_Id)
	{
		//直接返回TRUE。过滤掉功能ID不匹配的电气量项目
		return TRUE;
	}

	CRptTemp_ReportsDef* pRptTemp_ReportsDef = pMacroTestDef->GetRpeortsDef();

	if (pRptTemp_ReportsDef == NULL)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("报告数据配置文件中，macrotest节点【%s】未定义reports-def"), strMacroID.GetString());
		return FALSE;
	}

	CRptTemp_MacroTest* pRptMacroTestNew = GenRpt_Xml_NewMacroTest(pNewMacroCharItems, pMacroTest);
	CExBaseList oRptLists;
	GetItemReports(&oRptLists, pMacroTest);

	BOOL bRet = GenRpt_Xml_MacroTest_Dat_Reports(pRptTemp_ReportsDef, &oRptLists, pRptMacroTestNew, pMacroTest);
	oRptLists.RemoveAll();
	return bRet;
}

//macro-char-items节点，一般不会重复测试，不考虑重复测试次数。
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Items_Dat_RootNode_MacroCharItems(CRptTemp_TestMacroUiRptDef *pRptDef, CRptTemp_Items *pRptItems, CMacroCharItems *pMacroCharItems)
{
	BOOL bRet = TRUE;
	CString strMacroID = pMacroCharItems->GetTestMacroID();
	CRptTemp_MacroCharItems *pRptTemp_MacroCharItemsDef = pRptDef->FindMacroCharItemsByMacroID(strMacroID);

	if (pRptTemp_MacroCharItemsDef == NULL)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("报告数据配置文件中，找不到macro-char-items节点【%s】"), strMacroID.GetString());
		//对于特性曲线项目，必须要配置对应的节点
		return FALSE;
	}
	
	CRptTemp_MacroCharItems* pNewMacroCharItems = GenRpt_Xml_NewMacroCharItems(pRptItems, pMacroCharItems);

	if (pNewMacroCharItems == NULL)
	{
		return FALSE;
	}

	//先处理macro-char-items下的report-def节点
	CRptTemp_ReportDef *pReportDef = pRptTemp_MacroCharItemsDef->GetReportDef();
	CReport *pReport = pMacroCharItems->GetReport(-1);
	CString strItemPath;
	strItemPath = pMacroCharItems->GetIDPathEx(GBCLASSID_DEVICE, FALSE);

	if (pReportDef != NULL && pReport != NULL)
	{
		CRptTemp_Report *pNewReport = GenRpt_Xml_NewReport(pNewMacroCharItems, pReport);	

		if (! GenRpt_Xml_MacroCharItems_Dat_Report_Value(pReportDef, pNewReport, pReport, strItemPath))
		{
			bRet = FALSE;
		}
	}

	POS pos = pMacroCharItems->GetHeadPosition();
	UINT nClassID = 0;
	CExBaseObject *pObj = NULL;

	while (pos != NULL)
	{
		pObj = pMacroCharItems->GetNext(pos);
		nClassID = pObj->GetClassID();

		if (nClassID != GBCLASSID_MACROTEST)
		{
			continue;
		}

		CMacroTest *pMacroTest = (CMacroTest *)pObj;

		if (! GenRpt_Xml_Items_Dat_RootNode_MacroTest(pRptTemp_MacroCharItemsDef, pNewMacroCharItems, pMacroTest))
		{
			bRet = FALSE;
		}
	}
	
	return bRet;
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_MacroCharItems_Dat_Report_Value(CRptTemp_ReportDef* pRptDef, CRptTemp_Report* pNewRpt, CReport* pReport, const CString &strItemPath)
{
	BOOL bRet = TRUE;
	POS pos = pRptDef->GetHeadPosition();

	while (pos != NULL)
	{
		CRptTemp_ValueDef *pValueDef = (CRptTemp_ValueDef *)pRptDef->GetNext(pos);

		if (pValueDef->m_strID == RPT_TEMPLATE_VALUE_ID_PNG)
		{
			//特性图，特殊处理
			GenRpt_Xml_NewValue(pNewRpt, pValueDef, strItemPath);
			continue;
		}

		if (! GenRpt_Xml_NewValue(pNewRpt, pValueDef, pReport->m_pValues))
		{
			bRet = FALSE;
		}
	}

	return bRet;
}

//pRptMacroTestNew是需要实例化的macrotest节点
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_MacroTest_Dat_Reports(CRptTemp_ReportsDef* pRptDef, CExBaseList *pRptLists, CRptTemp_MacroTest* pRptMacroTestNew, CMacroTest *pMacroTest)
{
	if (pRptDef->GetCount() == 0)
	{
		return FALSE;
	}

	if (pRptLists->GetCount() == 0)
	{
		return FALSE;
	}

	BOOL bRet = TRUE;
	CRptTemp_Reports *pRptTemp_Reports = pRptMacroTestNew->AddReprots();
	POS pos = pRptDef->GetHeadPosition();
	UINT nClassID = 0;
	CExBaseObject *pObj = NULL;

	while (pos != NULL)
	{
		pObj = pRptDef->GetNext(pos);
		nClassID = pObj->GetClassID();

		if (nClassID == MNGRCLASSID_CRPTTEMP_VALUEDEF)
		{
			//公共的报告数据，取最后一次报告中的
			CReport *pRpt = (CReport *)pRptLists->GetTail();

			if (! GenRpt_Xml_NewValue(pRptTemp_Reports, (CRptTemp_ValueDef *)pObj, pRpt->m_pValues))
			{
				bRet = FALSE;
			}
		}
		else if (nClassID == MNGRCLASSID_CRPTTEMP_REPORTDEF)
		{
			//模板中，应该只有一个report-def。需要根据pRptLists的数量，实例化对应数量的report
			CRptTemp_ReportDef *pRptTemp_ReportDef = (CRptTemp_ReportDef *)pObj;

			if (! GenRpt_Xml_MacroTest_Dat_Report(pRptTemp_ReportDef, pRptTemp_Reports, pRptLists, pMacroTest))
			{
				bRet = FALSE;
			}
		}
	}

	return bRet;
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_MacroTest_Dat_Report(CRptTemp_ReportDef* pRptDef, CExBaseList *pParent, CExBaseList* pRptLists, CMacroTest *pMacroTest)
{
	if (pRptLists->GetCount() == 0)
	{
		return FALSE;
	}

	BOOL bRet = TRUE;
	long nIndex = 1;
	POS pos = pRptLists->GetHeadPosition();
	long nCalIndex = 0;
	long nRepeatTimes = pMacroTest->m_nRepeatTimes;

	while (pos != NULL)
	{
		CReport *pReport = (CReport *)pRptLists->GetNext(pos);
		CRptTemp_Report *pNewRpt = new CRptTemp_Report();
		pParent->AddNewChild(pNewRpt);

		if (nRepeatTimes > 1)
		{
			if (nIndex % nRepeatTimes == 1 && nIndex > nRepeatTimes)
			{
				nCalIndex++;
				pNewRpt->m_strName.Format(_T("计算报告%d"), nCalIndex);
				pNewRpt->m_strID.Format(_T("Cal_%2d"), nCalIndex);
				pNewRpt->m_nIndex = nCalIndex-1;
				nIndex++;

				if (! GenRpt_Xml_MacroTest_Dat_Report_Value(pRptDef, pNewRpt, pReport, pMacroTest))
				{
					bRet = FALSE;
				}

				continue;
			}
		}

		nIndex++;
		pNewRpt->m_strName.Format(_T("测次%d"), nIndex-nCalIndex-1);
		pNewRpt->m_strID.Format(_T("Rpt%2d"), nIndex-nCalIndex);
		pNewRpt->m_nIndex = nIndex-1-nCalIndex;

		if (! GenRpt_Xml_MacroTest_Dat_Report_Value(pRptDef, pNewRpt, pReport, pMacroTest))
		{
			bRet = FALSE;
		}
	}

	return bRet;
}

//考虑从结果判断脚本中获取结果参数，形参pMacroTest作保留用
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_MacroTest_Dat_Report_Value(CRptTemp_ReportDef* pRptDef, CRptTemp_Report* pNewRpt, CReport* pReport, CMacroTest *pMacroTest)
{
	BOOL bRet = TRUE;
	POS pos = pRptDef->GetHeadPosition();

	while (pos != NULL)
	{
		CRptTemp_ValueDef *pValueDef = (CRptTemp_ValueDef *)pRptDef->GetNext(pos);

		if (! GenRpt_Xml_NewValue(pNewRpt, pValueDef, pReport->m_pValues))
		{
			bRet = FALSE;
		}
	}

	return bRet;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//以下是导出XML格式的doc结构文件的部分
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc(const CString &strXmlFile, CGuideBook *pGuideBook)
{
	if (pGuideBook == NULL)
	{
		return FALSE;
	}

	m_strXmlFile_Doc = strXmlFile;
	BOOL bRet = TRUE;

	if (m_pRptTemp_TestMacroUiRpt == NULL)
	{
		m_pRptTemp_TestMacroUiRpt = new CRptTemp_TestMacroUiRpt();
	}

	m_pRptTemp_TestMacroUiRpt->DeleteAll();

	CDevice *pDevice = pGuideBook->GetDevice();
	bRet = GenRpt_Xml_Doc_Device(m_pRptTemp_TestMacroUiRpt, pDevice);

	m_pRptTemp_TestMacroUiRpt->SaveXmlFile(m_strXmlFile_Doc, CTestMacroRptTemplateXmlRWKeys::g_pXmlKeys);

	return bRet;
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_Device(CRptTemp_TestMacroUiRpt *pRptTemp_TestMacroUiRpt, CDevice *pDevice)
{
	if (pDevice == NULL || pRptTemp_TestMacroUiRpt == NULL)
	{
		return FALSE;
	}

	BOOL bRet = TRUE;
	POS pos = pDevice->GetHeadPosition();
	CExBaseObject *pObj = NULL;
	UINT nClassID = 0;

	while (pos != NULL)
	{
		pObj = pDevice->GetNext(pos);
		nClassID = pObj->GetClassID();

		if (nClassID != GBCLASSID_ITEMS)
		{
			continue;
		}

		CItems *pItems = (CItems *)pObj;

		if (! GenRpt_Xml_Doc_Items(pRptTemp_TestMacroUiRpt, pItems))
		{
			bRet = FALSE;
		}
	}

	return bRet;
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_Items(CExBaseList *pParent, CItems *pItems)
{
	if (pParent == NULL || pItems == NULL)
	{
		return FALSE;
	}

	if (pItems->IsTypeRootNode())
	{
		return GenRpt_Xml_Items_Doc_RootNode(pParent, pItems);
	}

	return GenRpt_Xml_Items_Doc_Normal(pParent, pItems);
}

//递归调用，只针对人工创建的CItems
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Items_Doc_Normal(CExBaseList *pParent, CItems *pItems)
{
	if (pParent == NULL || pItems == NULL)
	{
		return FALSE;
	}

	//对于人工创建的CItems节点，只需要导出子的CItems即可
	//因为就算人工创建的CItems节点，子对象包含CMacroTest，也不知道需要导出的报告数据有哪些
	CRptTemp_Items *pRptTemp_Items = GenRpt_Xml_NewItems(pParent, pItems);

	if (pRptTemp_Items == NULL)
	{
		return FALSE;
	}

	BOOL bRet = TRUE;
	POS pos = pItems->GetHeadPosition();
	UINT nClassID = 0;
	CExBaseObject *pObj = NULL;

	while (pos != NULL)
	{
		pObj = pItems->GetNext(pos);
		nClassID = pObj->GetClassID();

		if (nClassID != GBCLASSID_ITEMS)
		{
			continue;
		}

		CItems *pChildItems = (CItems *)pObj;

		if (pChildItems->IsTypeRootNode())
		{
			if (! GenRpt_Xml_Items_Doc_RootNode(pRptTemp_Items, pChildItems))
			{
				bRet = FALSE;
			}
		}
		else
		{
			if (! GenRpt_Xml_Items_Doc_Normal(pRptTemp_Items, pChildItems))
			{
				bRet = FALSE;
			}
		}
	}

	return bRet;
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Items_Doc_RootNode(CExBaseList *pParent, CItems *pItems)
{
	if (pParent == NULL || pItems == NULL)
	{
		return FALSE;
	}

	CRptTemp_Items *pRptTemp_Items = GenRpt_Xml_NewItems(pParent, pItems);

	if (pRptTemp_Items == NULL)
	{
		return FALSE;
	}

	CSttMacroTestUI_TestMacroUIs *pUIs = CSttMacroTestUI_TestMacroUIDB::g_pSttTestMacroUIDB->GetTestMacroUIs();
	CSttMacroTestUI_TestMacroUI *pUI = (CSttMacroTestUI_TestMacroUI *)pUIs->FindByID(pItems->m_strStxmlFile);

	if (pUI == NULL)
	{
		return FALSE;
	}

	CRptTemp_TestMacroUiRptDef oRptDef;
	CString strFile;
	strFile = GetDBPath(); 
	strFile += STT_MACROTEST_UI_REALPATH_ATSGEN;
	strFile += _T("/");
	strFile += pUI->m_strrpt_Data_CfgFile;
	BOOL bRet = TRUE;

	CTestMacroRptTemplateXmlRWKeys::g_pXmlKeys->m_nIsGroupUseDvmData++;
	bRet = oRptDef.OpenXmlFile(strFile, CTestMacroRptTemplateXmlRWKeys::g_pXmlKeys);
	CTestMacroRptTemplateXmlRWKeys::g_pXmlKeys->m_nIsGroupUseDvmData--;

	if (!bRet)
	{
		return FALSE;
	}

	CString strItemPath;
	strItemPath = pItems->GetIDPathEx(GBCLASSID_DEVICE, FALSE);

	if (! GenRpt_Xml_Items_Doc_RootNode_UpdateItemsTec(&oRptDef, strItemPath))
	{
		return FALSE;
	}

	//最多定义一个report-template-def节点
	CRptTemp_ReportTemplateDef *pRptTemp_ReportTemplateDef = oRptDef.GetReportTemplateDef();

	if (pRptTemp_ReportTemplateDef != NULL)
	{
		//若oRptDef根节点定义了report-template-def。则说明是一个rootnode导出一个固化的报告。不是动态的
		return GenRpt_Xml_Doc_ReportTemplateDef_Head(&oRptDef, pRptTemp_Items, pItems);
	}

	bRet = GenRpt_Xml_Items_Doc_RootNode_Items(&oRptDef, pRptTemp_Items, pItems);

	return bRet;
}

//rootnode下，可以只考虑items、macrotest和char-macro-items
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Items_Doc_RootNode_Items(CRptTemp_TestMacroUiRptDef *pRptDef, CRptTemp_Items *pRptItems, CItems *pItems)
{
	if (pRptItems == NULL || pRptDef == NULL)
	{
		return FALSE;
	}

	BOOL bRet = TRUE;
	UINT nClassID = 0;
	CExBaseObject *pObj = NULL;
	POS pos = pItems->GetHeadPosition();

	while (pos != NULL)
	{
		pObj = pItems->GetNext(pos);
		nClassID = pObj->GetClassID();

		if (nClassID == GBCLASSID_ITEMS)
		{
			CItems *pItemsChild = (CItems *)pObj;
			CRptTemp_Items *pRptTemp_ItemsChild = GenRpt_Xml_NewItems(pRptItems, pItemsChild);

			if (pRptTemp_ItemsChild == NULL)
			{
				bRet = FALSE;
				continue;
			}

			if (! GenRpt_Xml_Items_Doc_RootNode_Items(pRptDef, pRptTemp_ItemsChild, pItemsChild))
			{
				bRet = FALSE;
			}
		}
		else if (nClassID == GBCLASSID_MACROTEST)
		{
			CMacroTest *pMacroTest = (CMacroTest *)pObj;

			if (! GenRpt_Xml_Items_Doc_RootNode_MacroTest(pRptDef, pRptItems, pMacroTest))
			{
				bRet = FALSE;
			}
		}
		else if (nClassID == GBCLASSID_MACROCHARITEMS)
		{
			CMacroCharItems *pMacroCharItems = (CMacroCharItems *)pObj;

			if (! GenRpt_Xml_Items_Doc_RootNode_MacroCharItems(pRptDef, pRptItems, pMacroCharItems))
			{
				bRet = FALSE;
			}
		}
	}

	return bRet;
}

//items下的电气量项目。根据pRptDef中定义的macrotest的报告模式
//报告模式 = item，单独生成表格。
//items，则遍历形参pItems下所有的macrotest，统一生成表格
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Items_Doc_RootNode_MacroTest(CRptTemp_TestMacroUiRptDef *pRptDef, CRptTemp_Items *pRptItems, CMacroTest *pMacroTest)
{
	CString strMacroID = pMacroTest->GetTestMacroID();
	CExBaseList oListParas;
	GetMacroTest_AllParas(&oListParas, pMacroTest);
	CRptTemp_MacroTest *pMacroTestDef = pRptDef->FindMacroTestByMacroID(strMacroID, &oListParas);

	if (pMacroTestDef == NULL)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("报告数据配置文件中，找不到macrotest节点【%s】"), strMacroID.GetString());
		return FALSE;
	}

	if (pMacroTestDef->m_strRpt_Mode == RPT_TEMPLATE_RPT_MODE_ITEM)
	{
		return GenRpt_Xml_Items_Doc_RootNode_MacroTest_RptMode_Item(pMacroTestDef, pRptItems, pMacroTest);
	}
	else if (pMacroTestDef->m_strRpt_Mode == RPT_TEMPLATE_RPT_MODE_ITEMS)
	{
		CItems *pItems = (CItems *)pMacroTest->GetParent();
		return GenRpt_Xml_Items_Doc_RootNode_MacroTest_RptMode_Items(pMacroTestDef, pRptItems, pItems);
	}

	return FALSE;
}

//曲线搜索项目。应当直接获取pRptDef定义的macro-char-items节点，找到定义的report-template-def。
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Items_Doc_RootNode_MacroCharItems(CRptTemp_TestMacroUiRptDef *pRptDef, CRptTemp_Items *pRptItems, CMacroCharItems *pMacroCharItems)
{
	CRptTemp_MacroCharItems *pMacroCharItemsDef = pRptDef->FindMacroCharItemsByMacroID(pMacroCharItems->GetTestMacroID());

	if (pMacroCharItemsDef == NULL)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("报告数据配置文件中，找不到macro-char-items节点【%s】"), pMacroCharItems->GetTestMacroID().GetString());
		//对于特性曲线项目，必须要配置对应的节点
		return FALSE;
	}

	CRptTemp_MacroCharItems* pNewMacroCharItems = GenRpt_Xml_NewMacroCharItems(pRptItems, pMacroCharItems);

	if (pNewMacroCharItems == NULL)
	{
		return FALSE;
	}

	CRptTemp_ReportTemplateDef *pReportTemplateDef = pMacroCharItemsDef->GetReportTemplateDef();

	if (pReportTemplateDef == NULL)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("报告数据配置文件中，macro-char-items下未定义report-template-def节点【%s】"), pMacroCharItemsDef->m_strMacro_Id.GetString());
		return FALSE;
	}

	return GenRpt_Xml_Doc_ReportTemplateDef_MacroTestCharItems(pReportTemplateDef, pNewMacroCharItems, pMacroCharItems);
}

//更新“技术要求” + “报告数据保留小数位数”数据接口
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Items_Doc_RootNode_UpdateItemsTec(CRptTemp_TestMacroUiRptDef *pRptDef, const CString &strItemPath)
{
	return GenRpt_Xml_Items_Dat_RootNode_UpdateItemsTec(pRptDef, strItemPath);
}

//报告导出模式：
//item：表示一个电气量项目，单独生成一个word表格。用于动作时间、动作值测试
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Items_Doc_RootNode_MacroTest_RptMode_Item(CRptTemp_MacroTest *pMacroTestDef, CRptTemp_Items *pRptItems, CMacroTest *pMacroTest)
{
	if (pRptItems == NULL || pMacroTestDef == NULL)
	{
		return FALSE;
	}

	if (pMacroTestDef->m_strMacro_Id != pMacroTest->GetTestMacroID())
	{
		//过滤掉测试功能ID不一致的电气量项目
		return TRUE;
	}

	CRptTemp_ReportTemplateDef *pReportTemplateDef = pMacroTestDef->GetReportTemplateDef();

	if (pReportTemplateDef == NULL)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("报告数据配置文件中，macrotest下未定义report-template-def节点【%s】"), pMacroTestDef->m_strMacro_Id.GetString());
		return FALSE;
	}

	return GenRpt_Xml_Doc_ReportTemplateDef_MacroTest(pReportTemplateDef, pRptItems, pMacroTest);
}

//报告导出模式：
//items：表示最小的叶子CItems节点，下面所有的电气量项目，生成一个统一的表格
//report-template-def下定义的title-def和text-def。也是针对最小的叶子CItems节点。
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Items_Doc_RootNode_MacroTest_RptMode_Items(CRptTemp_MacroTest *pMacroTestDef, CRptTemp_Items *pRptItems, CItems *pItems)
{
	if (pRptItems == NULL || pMacroTestDef == NULL)
	{
		return FALSE;
	}

	//对于items模式，所有的电气量项目统一到一个表格，只需要生成一次
	if (pRptItems->IsHasGen())
	{
		return TRUE;
	}

	CRptTemp_ReportTemplateDef *pReportTemplateDef = pMacroTestDef->GetReportTemplateDef();

	if (pReportTemplateDef == NULL)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("报告数据配置文件中，macrotest下未定义report-template-def节点【%s】"), pMacroTestDef->m_strMacro_Id.GetString());
		return FALSE;
	}

	pRptItems->SetHasGen(TRUE);
	return GenRpt_Xml_Doc_ReportTemplateDef_Items(pReportTemplateDef, pRptItems, pItems, pMacroTestDef->m_strMacro_Id);
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_ReportTemplateDef_Head(CRptTemp_TestMacroUiRptDef *pRptDef, CExBaseList *pParent_RptTemp, CGbItemBase *pItemBase)
{
	//最多定义一个report-template-def节点
	CRptTemp_ReportTemplateDef *pRptTemp_ReportTemplateDef = pRptDef->GetReportTemplateDef();

	if (pRptTemp_ReportTemplateDef == NULL)
	{
		//可以不定义report-template-def节点
		return TRUE;
	}

	CRptTemp_ReportTemplate *pNewReportTemplate = GenRpt_Xml_NewReportTemplate(pParent_RptTemp);
	BOOL bRet = TRUE;
	POS pos = pRptTemp_ReportTemplateDef->GetHeadPosition();
	UINT nClassID = 0;
	CExBaseObject *pObj = NULL;

	while (pos != NULL)
	{
		pObj = pRptTemp_ReportTemplateDef->GetNext(pos);
		nClassID = pObj->GetClassID();

		if (nClassID == MNGRCLASSID_CRPTTEMP_TITLEDEF)
		{
			CRptTemp_TitleDef *pTitleDef = (CRptTemp_TitleDef *)pObj;

			if (! GenRpt_Xml_Doc_TitleDef_Head(pTitleDef, pNewReportTemplate, pItemBase))
			{
				bRet = FALSE;
			}
		}
		else if (nClassID == MNGRCLASSID_CRPTTEMP_TEXTDEF)
		{
			CRptTemp_TextDef *pTextDef = (CRptTemp_TextDef *)pObj;

			if (! GenRpt_Xml_Doc_TextDef_Head(pTextDef, pNewReportTemplate, pItemBase))
			{
				bRet = FALSE;
			}
		}
		else if (nClassID == MNGRCLASSID_CRPTTEMP_GRIDDEF)
		{
			CRptTemp_GridDef *pGridDef = (CRptTemp_GridDef *)pObj;

			if (! GenRpt_Xml_Doc_GridDef_Head(pGridDef, pNewReportTemplate, pItemBase))
			{
				bRet = FALSE;
			}
		}
	}

	return TRUE;
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_TitleDef_Head(CRptTemp_TitleDef *pTitleDef, CRptTemp_ReportTemplate *pParent, CGbItemBase *pItemBase)
{
	CItems *pRootNode = (CItems *)Gb_GetFirstParentItems(pItemBase, TRUE);
	BOOL bRet = TRUE;
	CString strText = pTitleDef->m_strText;
	CString strTemp, strText2;
	long nPos = strText.Find(_T("%s"));
	long nIndex = 0;

	while(nPos >= 0)
	{
		strTemp = strText.Left(nPos + 2);

		if (nIndex == 0)
		{
			CString strName = GetItemName(pRootNode, pTitleDef->m_nItem_Level);

			if (strName.IsEmpty())
			{
				CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("未找到对应等级【%d】的项目"), pTitleDef->m_nItem_Level);
				bRet = FALSE;
			}

			strTemp.Replace(_T("%s"), strName);
		}
		else if (nIndex == 1)
		{
			CString strName = GetItemName(pRootNode, pTitleDef->m_nItem_Level_2);

			if (strName.IsEmpty())
			{
				CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("未找到对应等级【%d】的项目"), pTitleDef->m_nItem_Level);
				bRet = FALSE;
			}

			strTemp.Replace(_T("%s"), strName);
		}
		else if (nIndex == 2)
		{
			CString strName = GetItemName(pRootNode, pTitleDef->m_nItem_Level_3);

			if (strName.IsEmpty())
			{
				CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("未找到对应等级【%d】的项目"), pTitleDef->m_nItem_Level);
				bRet = FALSE;
			}

			strTemp.Replace(_T("%s"), strName);
		}
		
		strText = strText.Mid(nPos + 2);
		strText2 += strTemp;
		nIndex++;
		nPos = strText.Find(_T("%s"));
	}

	strText2 += strText;
	strText2.AppendFormat(pItemBase->m_strName); //固定添加上项目自身的名称

	CRptTemp_Title* pNewTitle = GenRpt_Xml_NewTitle(pParent);
	pNewTitle->m_strText = strText2;
	pNewTitle->m_nLevel = pNewTitle->GetRelTitleLevel() + pTitleDef->m_nLevel;

	return bRet;
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_TextDef_Head(CRptTemp_TextDef *pTextDef, CRptTemp_ReportTemplate *pParent, CGbItemBase *pItemBase)
{
	BOOL bRet = TRUE;
	CString strText = pTextDef->m_strText;
	CString strTemp, strText2;
	long nPos = strText.Find(_T("%s"));
	long nIndex = 0;

	while(nPos >= 0)
	{
		strTemp = strText.Left(nPos + 2);

		if (nIndex == 0)
		{
			//先从数据接口查找，找不到再从报告数据查找
			CString strValue = GetItemsTec(pTextDef, pTextDef->m_strData1_Id);

			if (strValue.IsEmpty())
			{
				strValue = GetItemReportValue(pItemBase, pTextDef->m_strData1_Id);
			}	

			if (strValue.IsEmpty())
			{
				CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("未找到项目【%s】的报告数据【%s】"), pItemBase->m_strName, pTextDef->m_strData1_Id);
				bRet = FALSE;
			}

			strTemp.Replace(_T("%s"), strValue);
		}
		else if (nIndex == 1)
		{
			//先从数据接口查找，找不到再从报告数据查找
			CString strValue = GetItemsTec(pTextDef, pTextDef->m_strData2_Id);

			if (strValue.IsEmpty())
			{
				strValue = GetItemReportValue(pItemBase, pTextDef->m_strData2_Id);
			}

			if (strValue.IsEmpty())
			{
				CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("未找到项目【%s】的报告数据【%s】"), pItemBase->m_strName, pTextDef->m_strData4_Id);
				bRet = FALSE;
			}

			strTemp.Replace(_T("%s"), strValue);
		}
		else if (nIndex == 2)
		{
			//先从数据接口查找，找不到再从报告数据查找
			CString strValue = GetItemsTec(pTextDef, pTextDef->m_strData3_Id);

			if (strValue.IsEmpty())
			{
				strValue = GetItemReportValue(pItemBase, pTextDef->m_strData3_Id);
			}

			if (strValue.IsEmpty())
			{
				CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("未找到项目【%s】的报告数据【%s】"), pItemBase->m_strName, pTextDef->m_strData3_Id);
				bRet = FALSE;
			}

			strTemp.Replace(_T("%s"), strValue);
		}
		else if (nIndex == 3)
		{
			//先从数据接口查找，找不到再从报告数据查找
			CString strValue = GetItemsTec(pTextDef, pTextDef->m_strData4_Id);

			if (strValue.IsEmpty())
			{
				strValue = GetItemReportValue(pItemBase, pTextDef->m_strData4_Id);
			}

			if (strValue.IsEmpty())
			{
				CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("未找到项目【%s】的报告数据【%s】"), pItemBase->m_strName, pTextDef->m_strData4_Id);
				bRet = FALSE;
			}

			strTemp.Replace(_T("%s"), strValue);
		}
		else if (nIndex == 4)
		{
			//先从数据接口查找，找不到再从报告数据查找
			CString strValue = GetItemsTec(pTextDef, pTextDef->m_strData5_Id);

			if (strValue.IsEmpty())
			{
				strValue = GetItemReportValue(pItemBase, pTextDef->m_strData5_Id);
			}

			if (strValue.IsEmpty())
			{
				CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("未找到项目【%s】的报告数据【%s】"), pItemBase->m_strName, pTextDef->m_strData5_Id);
				bRet = FALSE;
			}

			strTemp.Replace(_T("%s"), strValue);
		}
		else if (nIndex == 5)
		{
			//先从数据接口查找，找不到再从报告数据查找
			CString strValue = GetItemsTec(pTextDef, pTextDef->m_strData6_Id);

			if (strValue.IsEmpty())
			{
				strValue = GetItemReportValue(pItemBase, pTextDef->m_strData6_Id);
			}

			if (strValue.IsEmpty())
			{
				CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("未找到项目【%s】的报告数据【%s】"), pItemBase->m_strName, pTextDef->m_strData6_Id);
				bRet = FALSE;
			}

			strTemp.Replace(_T("%s"), strValue);
		}

		strText = strText.Mid(nPos + 2);
		strText2 += strTemp;
		nIndex++;
		nPos = strText.Find(_T("%s"));
	}

	strText2 += strText;
	
	CRptTemp_Text* pNewText = GenRpt_Xml_NewText(pParent);
	pNewText->m_strText = strText2;

	return bRet;
}

//目前只考虑行填写模式：即子对象只考虑head、row。grid不定义cols-def、rows-def
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_GridDef_Head(CRptTemp_GridDef *pGridDef, CRptTemp_ReportTemplate *pParent, CGbItemBase *pItemBase)
{
	if (! pGridDef->IsDataMode_Row())
	{
		CLogPrint::LogString(XLOGLEVEL_TRACE, _T("检测到表格定义为列填写模式，暂不处理……"));
		return FALSE;
	}

	BOOL bRet = TRUE;
	CRptTemp_Grid *pNewGrid = GenRpt_Xml_NewGrid(pParent, pGridDef); //同时处理了head
	UINT nClassID = 0;
	CExBaseObject *pObj = NULL;
	POS pos = pGridDef->GetHeadPosition();

	//循环只处理row
	while (pos != NULL)
	{
		pObj = pGridDef->GetNext(pos);
		nClassID = pObj->GetClassID();

		if (nClassID != MNGRCLASSID_CRPTTEMP_ROW)
		{
			continue;
		}

		CRptTemp_Row *pRow = (CRptTemp_Row *)pObj;
		CRptTemp_Row *pNewRow = (CRptTemp_Row *)pRow->CloneEx(TRUE, TRUE);
		pNewGrid->AddNewChild(pNewRow);

		if (! GenRpt_Xml_Doc_GridDef_Head_FillRow(pNewRow, pItemBase))
		{
			bRet = FALSE;
		}
	}

	return bRet;
}

//pItemBase一定是rootnode节点
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_GridDef_Head_FillRow(CRptTemp_Row *pRow, CGbItemBase *pItemBase)
{
	ASSERT(pItemBase->GetClassID() == GBCLASSID_ITEMS);

	if (pItemBase->GetClassID() != GBCLASSID_ITEMS)
	{
		CLogPrint::LogString(XLOGLEVEL_TRACE, _T("导出XML报告，检测到项目类型不对……"));
		return FALSE;
	}

	CItems *pItems = (CItems *)pItemBase;
	ASSERT(pItems->IsTypeRootNode());

	if (!pItems->IsTypeRootNode())
	{
		CLogPrint::LogString(XLOGLEVEL_TRACE, _T("导出XML报告，检测到项目非rootnode节点……"));
		return FALSE;
	}

	BOOL bRet = TRUE;
	POS pos = pRow->GetHeadPosition();

	while (pos != NULL)
	{
		CRptTemp_Cell *pCell = (CRptTemp_Cell *)pRow->GetNext(pos);
		
		if (! GenRpt_Xml_Doc_GridDef_Head_FillCell(pCell, pItems))
		{
			bRet = FALSE;
		}
	}

	return bRet;
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_GridDef_Head_FillCell(CRptTemp_Cell *pCell, CItems *pItems)
{
	if (pCell->m_strType.IsEmpty())
	{
		return FALSE;
	}

	//固定文本或者是测试索引号，直接返回TRUE。实际上。此处不应该出现测试索引号
	if (pCell->m_strType == RPT_TEMPLATE_COL_DEF_TYPE_TEST_INDEX ||
		pCell->m_strType == RPT_TEMPLATE_COL_DEF_TYPE_TEXT)
	{
		return TRUE;
	}

	CReport *pReport = NULL;

	if (pCell->m_strData_Path.IsEmpty())
	{
		pReport = pItems->GetReport(-1);
	}
	else 
	{
		CGbItemBaseList oDestList;
		//通过项目相对路径，查找项目
		pItems->SelectItems(pCell->m_strData_Path, oDestList);
		long nCount = oDestList.GetCount();

		if (nCount != 1)
		{
			CLogPrint::LogFormatString(XLOGLEVEL_DEBUG, _T("项目【%s】查找结果不唯一！找到【%d】个目标项目"), pCell->m_strData_Path.GetString(), nCount);
			oDestList.RemoveAll();
			return FALSE;
		}

		CGbItemBase *pDestItem = (CGbItemBase *)oDestList.GetHead();
		pReport = pDestItem->GetReport(-1);
		oDestList.RemoveAll();
	}

	if (pReport == NULL)
	{
		pCell->m_strText = _T("未找到报告");
		return FALSE;
	}

	CValue *pFind = (CValue*)pReport->m_pValues->FindByID(pCell->m_strText);

	if (pFind == NULL)
	{
		pCell->m_strText = _T("未找到报告数据");
		return FALSE;
	}

	//待处理：此处未处理报告数据保留小数位数修约。
	pCell->m_strText = pFind->m_strValue;
	return TRUE;
}

//以下四个，只处理macrotest节点定义的report-template-def。且rpt-mode=item
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_ReportTemplateDef_MacroTest(CRptTemp_ReportTemplateDef *pReportTemplateDef, CExBaseList *pParent_RptTemp, CMacroTest *pMacroTest)
{
	CRptTemp_ReportTemplate *pNewReportTemplate = GenRpt_Xml_NewReportTemplate(pParent_RptTemp);
	BOOL bRet = TRUE;
	POS pos = pReportTemplateDef->GetHeadPosition();
	UINT nClassID = 0;
	CExBaseObject *pObj = NULL;

	while (pos != NULL)
	{
		pObj = pReportTemplateDef->GetNext(pos);
		nClassID = pObj->GetClassID();

		if (nClassID == MNGRCLASSID_CRPTTEMP_TITLEDEF)
		{
			CRptTemp_TitleDef *pTitleDef = (CRptTemp_TitleDef *)pObj;

			if (! GenRpt_Xml_Doc_TitleDef_MacroTest(pTitleDef, pNewReportTemplate, pMacroTest))
			{
				bRet = FALSE;
			}
		}
		else if (nClassID == MNGRCLASSID_CRPTTEMP_TEXTDEF)
		{
			CRptTemp_TextDef *pTextDef = (CRptTemp_TextDef *)pObj;

			if (! GenRpt_Xml_Doc_TextDef_MacroTest(pTextDef, pNewReportTemplate, pMacroTest))
			{
				bRet = FALSE;
			}
		}
		else if (nClassID == MNGRCLASSID_CRPTTEMP_GRIDDEF)
		{
			CRptTemp_GridDef *pGridDef = (CRptTemp_GridDef *)pObj;

			if (! GenRpt_Xml_Doc_GridDef_MacroTest(pGridDef, pNewReportTemplate, pMacroTest))
			{
				bRet = FALSE;
			}
		}
	}

	return bRet;
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_TitleDef_MacroTest(CRptTemp_TitleDef *pTitleDef, CRptTemp_ReportTemplate *pParent_RptTemp, CMacroTest *pMacroTest)
{
	return GenRpt_Xml_Doc_TitleDef_Head(pTitleDef, pParent_RptTemp, pMacroTest);
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_TextDef_MacroTest(CRptTemp_TextDef *pTextDef, CRptTemp_ReportTemplate *pParent_RptTemp, CMacroTest *pMacroTest)
{
	CExBaseList oListParas;
	GetMacroTest_AllParas(&oListParas, pMacroTest);

	//若不使能，则直接跳过
	if (!pTextDef->IsEnable(&oListParas))
	{
		return TRUE;
	}

	return GenRpt_Xml_Doc_TextDef_Head(pTextDef, pParent_RptTemp, pMacroTest);
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_GridDef_MacroTest(CRptTemp_GridDef *pGridDef, CRptTemp_ReportTemplate *pParent_RptTemp, CMacroTest *pMacroTest)
{
	//目前暂时只考虑row-rpt模式。
	ASSERT(pGridDef->m_strData_Mode == RPT_TEMPLATE_DATAMODE_ROW_RPT);
	CRptTemp_Grid *pNewGrid = GenRpt_Xml_NewGrid(pParent_RptTemp, pGridDef);
	return GenRpt_Xml_GridDef_RowRpt(pNewGrid, pGridDef, pMacroTest);
}

//以下四个，只处理macro-char-items节点定义的report-template-def
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_ReportTemplateDef_MacroTestCharItems(CRptTemp_ReportTemplateDef *pReportTemplateDef, CExBaseList *pParent_RptTemp, CMacroCharItems *pMacroCharItems)
{
	CRptTemp_ReportTemplate *pNewReportTemplate = GenRpt_Xml_NewReportTemplate(pParent_RptTemp);
	BOOL bRet = TRUE;
	POS pos = pReportTemplateDef->GetHeadPosition();
	UINT nClassID = 0;
	CExBaseObject *pObj = NULL;

	while (pos != NULL)
	{
		pObj = pReportTemplateDef->GetNext(pos);
		nClassID = pObj->GetClassID();

		if (nClassID == MNGRCLASSID_CRPTTEMP_TITLEDEF)
		{
			CRptTemp_TitleDef *pTitleDef = (CRptTemp_TitleDef *)pObj;

			if (! GenRpt_Xml_Doc_TitleDef_MacroCharItems(pTitleDef, pNewReportTemplate, pMacroCharItems))
			{
				bRet = FALSE;
			}
		}
		else if (nClassID == MNGRCLASSID_CRPTTEMP_TEXTDEF)
		{
			CRptTemp_TextDef *pTextDef = (CRptTemp_TextDef *)pObj;

			if (! GenRpt_Xml_Doc_TextDef_MacroCharItems(pTextDef, pNewReportTemplate, pMacroCharItems))
			{
				bRet = FALSE;
			}
		}
		else if (nClassID == MNGRCLASSID_CRPTTEMP_GRIDDEF)
		{
			CRptTemp_GridDef *pGridDef = (CRptTemp_GridDef *)pObj;

			if (! GenRpt_Xml_Doc_GridDef_MacroCharItems(pGridDef, pNewReportTemplate, pMacroCharItems))
			{
				bRet = FALSE;
			}
		}
		else if (nClassID == MNGRCLASSID_CRPTTEMP_PNGDEF)
		{
			CRptTemp_PngDef *pPngDef = (CRptTemp_PngDef *)pObj;
			
			if (! GenRpt_Xml_Doc_PngDef_MacroCharItems(pPngDef, pNewReportTemplate, pMacroCharItems))
			{
				bRet = FALSE;
			}
		}
	}

	return bRet;
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_TitleDef_MacroCharItems(CRptTemp_TitleDef *pTitleDef, CRptTemp_ReportTemplate *pParent_RptTemp, CMacroCharItems *pMacroCharItems)
{
	return GenRpt_Xml_Doc_TitleDef_Head(pTitleDef, pParent_RptTemp, pMacroCharItems);
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_TextDef_MacroCharItems(CRptTemp_TextDef *pTextDef, CRptTemp_ReportTemplate *pParent_RptTemp, CMacroCharItems *pMacroCharItems)
{
	return GenRpt_Xml_Doc_TextDef_Head(pTextDef, pParent_RptTemp, pMacroCharItems);
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_PngDef_MacroCharItems(CRptTemp_PngDef *pPngDef, CRptTemp_ReportTemplate *pParent_RptTemp, CMacroCharItems *pMacroCharItems)
{
	CString strItemPath;
	strItemPath = pMacroCharItems->GetIDPathEx(GBCLASSID_DEVICE, FALSE);
	CString strPngFile;
	GetPngFilePath(strItemPath, strPngFile);

	CRptTemp_Png *pNewPng = new CRptTemp_Png();
	pNewPng->m_strPngPath = strPngFile;
	pParent_RptTemp->AddNewChild(pNewPng);

	return TRUE;
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_GridDef_MacroCharItems(CRptTemp_GridDef *pGridDef, CRptTemp_ReportTemplate *pParent_RptTemp, CMacroCharItems *pMacroCharItems)
{
	//目前暂时只考虑row-item模式。
	ASSERT(pGridDef->m_strData_Mode == RPT_TEMPLATE_DATAMODE_ROW_ITEM);
	CRptTemp_Grid *pNewGrid = GenRpt_Xml_NewGrid(pParent_RptTemp, pGridDef);
	return GenRpt_Xml_GridDef_RowItem(pNewGrid, pGridDef, pMacroCharItems, pMacroCharItems->GetTestMacroID());
}

//以下四个，只处理macro节点定义的report-template-def。且rpt-mode=items
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_ReportTemplateDef_Items(CRptTemp_ReportTemplateDef *pReportTemplateDef, CExBaseList *pParent_RptTemp, CItems *pItems, const CString &strMacroID)
{
	CRptTemp_ReportTemplate *pNewReportTemplate = GenRpt_Xml_NewReportTemplate(pParent_RptTemp);
	BOOL bRet = TRUE;
	POS pos = pReportTemplateDef->GetHeadPosition();
	UINT nClassID = 0;
	CExBaseObject *pObj = NULL;

	while (pos != NULL)
	{
		pObj = pReportTemplateDef->GetNext(pos);
		nClassID = pObj->GetClassID();

		if (nClassID == MNGRCLASSID_CRPTTEMP_TITLEDEF)
		{
			CRptTemp_TitleDef *pTitleDef = (CRptTemp_TitleDef *)pObj;

			if (! GenRpt_Xml_Doc_TitleDef_Items(pTitleDef, pNewReportTemplate, pItems))
			{
				bRet = FALSE;
			}
		}
		else if (nClassID == MNGRCLASSID_CRPTTEMP_TEXTDEF)
		{
			CRptTemp_TextDef *pTextDef = (CRptTemp_TextDef *)pObj;

			if (! GenRpt_Xml_Doc_TextDef_Items(pTextDef, pNewReportTemplate, pItems))
			{
				bRet = FALSE;
			}
		}
		else if (nClassID == MNGRCLASSID_CRPTTEMP_GRIDDEF)
		{
			CRptTemp_GridDef *pGridDef = (CRptTemp_GridDef *)pObj;

			if (! GenRpt_Xml_Doc_GridDef_Items(pGridDef, pNewReportTemplate, pItems, strMacroID))
			{
				bRet = FALSE;
			}
		}
	}

	return bRet;
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_TitleDef_Items(CRptTemp_TitleDef *pTitleDef, CRptTemp_ReportTemplate *pParent_RptTemp, CItems *pItems)
{
	return GenRpt_Xml_Doc_TitleDef_Head(pTitleDef, pParent_RptTemp, pItems);
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_TextDef_Items(CRptTemp_TextDef *pTextDef, CRptTemp_ReportTemplate *pParent_RptTemp, CItems *pItems)
{
	return GenRpt_Xml_Doc_TextDef_Head(pTextDef, pParent_RptTemp, pItems);
}

//rpt-mode = row_item
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_Doc_GridDef_Items(CRptTemp_GridDef *pGridDef, CRptTemp_ReportTemplate *pParent_RptTemp, CItems *pItems, const CString &strMacroID)
{
	//目前暂时只考虑row-item模式。
	ASSERT(pGridDef->m_strData_Mode == RPT_TEMPLATE_DATAMODE_ROW_ITEM);
	CRptTemp_Grid *pNewGrid = GenRpt_Xml_NewGrid(pParent_RptTemp, pGridDef);
	return GenRpt_Xml_GridDef_RowItem(pNewGrid, pGridDef, pItems, strMacroID);
}

//row-item模式下，pItemBase为电气量项目的父节点（CItems、CMacroCharItems）
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_GridDef_RowItem(CRptTemp_Grid *pNewGrid, CRptTemp_GridDef *pGridDef, CGbItemBase *pItemBase, const CString &strMacroID)
{
	CRptTemp_ColsDef *pColsDef = (CRptTemp_ColsDef *)pGridDef->FindByClassID(MNGRCLASSID_CRPTTEMP_COLSDEF);
	ASSERT(pColsDef != NULL);

	if (pColsDef == NULL)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("报告数据配置文件中，grid-def下未定义cols-def 【%s】"), pItemBase->m_strName.GetString());
		return FALSE;
	}

	long nIndex = 0;
	POS pos = pItemBase->GetHeadPosition();
	CExBaseObject *pObj = NULL;
	UINT nClassID = 0;
	BOOL bRet = TRUE;

	while (pos != NULL)
	{
		pObj = pItemBase->GetNext(pos);
		nClassID = pObj->GetClassID();

		if (nClassID != GBCLASSID_MACROTEST)
		{
			continue;
		}

		CMacroTest *pMacroTest = (CMacroTest *)pObj;

		if (pMacroTest->GetTestMacroID() != strMacroID)
		{
			//过滤掉测试功能ID 不一致的电气量项目
			continue;
		}

		nIndex++;
		CReport *pReport = pMacroTest->GetReport(-1);

		if (! GenRpt_Xml_GridDef_NewRow(pNewGrid, pColsDef, pReport, nIndex))
		{
			bRet = FALSE;
		}
	}

	return bRet;
}

//row-rpt模式下。pGridDef中是定义了所有的row的
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_GridDef_RowRpt(CRptTemp_Grid *pNewGrid, CRptTemp_GridDef *pGridDef, CMacroTest *pMacroTest)
{
	CRptTemp_ColsDef *pColsDef = (CRptTemp_ColsDef *)pGridDef->FindByClassID(MNGRCLASSID_CRPTTEMP_COLSDEF);
	ASSERT(pColsDef != NULL);

	if (pColsDef == NULL)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("报告数据配置文件中，grid-def下未定义cols-def 【%s】"), pMacroTest->m_strName.GetString());
		return FALSE;
	}

	CExBaseList oReportLists;
	GetItemReports(&oReportLists, pMacroTest);
	long nIndex = 0;

	POS pos = pGridDef->GetHeadPosition();
	CExBaseObject *pObj = NULL;
	UINT nClassID = 0;
	BOOL bRet = TRUE;

	while (pos != NULL)
	{
		pObj = pGridDef->GetNext(pos);
		nClassID = pObj->GetClassID();

		if (nClassID != MNGRCLASSID_CRPTTEMP_ROW)
		{
			continue;
		}

		CRptTemp_Row *pRow = (CRptTemp_Row *)pObj;
		CRptTemp_Row *pNewRow = (CRptTemp_Row *)pRow->CloneEx(TRUE, TRUE);
		pNewGrid->AddNewChild(pNewRow);
		CReport *pReport = (CReport *)oReportLists.GetAt(nIndex);

		if (! GenRpt_Xml_GridDef_FillRow(pNewRow, pColsDef, pReport, nIndex))
		{
			bRet = FALSE;
		}

		nIndex++;
	}

	oReportLists.RemoveAll();
	return bRet;
}

//nIndex从1开始
BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_GridDef_NewRow(CRptTemp_Grid *pNewGrid, CRptTemp_ColsDef *pColsDef, CReport *pReport, long nIndex)
{
	if (pReport == NULL)
	{
		return FALSE;
	}

	if (pReport->m_pValues == NULL)
	{
		return FALSE;
	}

	BOOL bRet = TRUE;
	CRptTemp_Row *pNewRow = new CRptTemp_Row;
	pNewGrid->AddNewChild(pNewRow);

	POS pos = pColsDef->GetHeadPosition();

	while (pos != NULL)
	{
		CRptTemp_ColDef *pColDef = (CRptTemp_ColDef *)pColsDef->GetNext(pos);

		CRptTemp_Cell *pNewCell = new CRptTemp_Cell;
		pNewRow->AddNewChild(pNewCell);

		if (pColDef->m_strType == RPT_TEMPLATE_COL_DEF_TYPE_TEST_INDEX)
		{
			pNewCell->m_strText.Format(_T("%d"), nIndex); //编号
		}
		else if (pColDef->m_strType == RPT_TEMPLATE_COL_DEF_TYPE_DATA_ID)
		{
			CValue *pValue = (CValue *)pReport->m_pValues->FindByID(pColDef->m_strID);

			if (pValue == NULL)
			{
				CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("报告中找不到结果参数【%s】"), pColDef->m_strID);
				pNewCell->m_strText = _T("未找到结果参数值");
				bRet = FALSE;
			}
			else
			{
				pColDef->UpdatePrecision();
				
				if (! GenRpt_Xml_GridDef_FillRow_ProcessVal(pValue->m_strValue, pNewCell->m_strText, pColDef->m_strProcess, pColDef->m_nPrecision))
				{
					bRet = FALSE;
				}
				
				//pNewCell->m_strText = pValue->m_strValue;
			}
		}
		else
		{
			bRet = FALSE;
		}
	}

	return bRet;
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_GridDef_FillRow(CRptTemp_Row *pNewRow, CRptTemp_ColsDef *pColsDef, CReport *pReport, long nTestIndex)
{
	long nColIndex = 0;
	BOOL bRet = TRUE;

	if (pReport == NULL)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("测次【%d】的报告为空"), nTestIndex + 1);
		bRet = FALSE;
	}

	POS pos = pColsDef->GetHeadPosition();

	while (pos != NULL)
	{
		CRptTemp_ColDef *pColDef = (CRptTemp_ColDef *)pColsDef->GetNext(pos);
		CRptTemp_Cell *pCell = (CRptTemp_Cell *)pNewRow->GetAt(nColIndex);

		if (pCell == NULL)
		{
			CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("测次【%d】的grid-def中，row缺少第【%d】列的cell定义"), nTestIndex + 1, nColIndex + 1);
			pCell = new CRptTemp_Cell();
			pNewRow->AddNewChild(pCell);
			bRet = FALSE;
		}

		if (pColDef->m_strType == RPT_TEMPLATE_COL_DEF_TYPE_TEST_INDEX)
		{
			//实际上，测次是预填的
			pCell->m_strText.Format(_T("%d"), nTestIndex+1); //测次
		}
		else if (pColDef->m_strType == RPT_TEMPLATE_COL_DEF_TYPE_DATA_ID)
		{
			if (pReport == NULL)
			{
				pCell->m_strText = _T("未找到报告");
			}
			else
			{
				CValue *pValue = (CValue *)pReport->m_pValues->FindByID(pColDef->m_strID);

				if (pValue == NULL)
				{
					CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("报告中找不到结果参数【%s】"), pColDef->m_strID);
					pCell->m_strText = _T("未找到结果参数值");
					bRet = FALSE;
				}
				else
				{
					pColDef->UpdatePrecision();

					if (! GenRpt_Xml_GridDef_FillRow_ProcessVal(pValue->m_strValue, pCell->m_strText, pColDef->m_strProcess, pColDef->m_nPrecision))
					{
						bRet = FALSE;
					}
					
					//pCell->m_strText = pValue->m_strValue;
				}
			}
		}
		else
		{
			bRet = FALSE;
		}

		nColIndex++;
	}
	return bRet;
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_GridDef_FillRow_ProcessVal(const CString& strSrcVal, CString &strVal, const CString &strProcess, long nPrecision)
{
	//表格填写时，与value-def处理一致
	return GenRpt_Xml_NewValue_ProcessVal(strSrcVal, strVal, strProcess, nPrecision);
}

CRptTemp_Items* CRptTemplate_GenXmlTool::GenRpt_Xml_NewItems(CExBaseList *pParent, CItems *pItems)
{
	if (pParent == NULL || pItems == NULL)
	{
		return NULL;
	}

	CRptTemp_Items *pNewItems = new CRptTemp_Items();
	pNewItems->m_strName = pItems->m_strName;
	pNewItems->m_strID = pItems->m_strID;
	pNewItems->m_nRpt_Title = pItems->m_nRptTitle;
	pNewItems->m_ntitle_level = pItems->m_nTitleLevel;
	pParent->AddNewChild(pNewItems);

	return pNewItems;
}

CRptTemp_MacroTest* CRptTemplate_GenXmlTool::GenRpt_Xml_NewMacroTest(CExBaseList *pParent, CMacroTest *pMacroTest)
{
	if (pParent == NULL || pMacroTest == NULL)
	{
		return NULL;
	}

	CRptTemp_MacroTest *pNewMacroTest = new CRptTemp_MacroTest();
	pNewMacroTest->m_strName = pMacroTest->m_strName;
	pNewMacroTest->m_strID = pMacroTest->m_strID;
	pParent->AddNewChild(pNewMacroTest);

	return pNewMacroTest;
}

CRptTemp_MacroCharItems* CRptTemplate_GenXmlTool::GenRpt_Xml_NewMacroCharItems(CExBaseList *pParent, CMacroCharItems *pMacroCharItems)
{
	if (pParent == NULL || pMacroCharItems == NULL)
	{
		return NULL;
	}

	CRptTemp_MacroCharItems *pNewMacroCharItems = new CRptTemp_MacroCharItems();
	pNewMacroCharItems->m_strName = pMacroCharItems->m_strName;
	pNewMacroCharItems->m_strID = pMacroCharItems->m_strID;
	pNewMacroCharItems->m_strMacro_Id = pMacroCharItems->GetTestMacroID();
	pParent->AddNewChild(pNewMacroCharItems);

	return pNewMacroCharItems;
}

CRptTemp_Report* CRptTemplate_GenXmlTool::GenRpt_Xml_NewReport(CExBaseList *pParent, CReport *pReport)
{
	if (pParent == NULL || pReport == NULL)
	{
		return NULL;
	}

	CRptTemp_Report *pNewReport = new CRptTemp_Report();
	pNewReport->m_strName = pReport->m_strName;
	pNewReport->m_strID = pReport->m_strID;
	pParent->AddNewChild(pNewReport);

	return pNewReport;
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_NewValue(CExBaseList *pParent, CRptTemp_ValueDef* pValueDef, const CString &strItemPath)
{
	CString strPngFile;
	CRptTemp_Value *pNewValue = new CRptTemp_Value();
	pNewValue->m_strName = pValueDef->m_strName;
	pNewValue->m_strID = pValueDef->m_strID;
	GetPngFilePath(strItemPath, strPngFile);
	pNewValue->m_strVal = strPngFile;
	pParent->AddNewChild(pNewValue);

	return TRUE;
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_NewValue(CExBaseList *pParent, CRptTemp_ValueDef* pValueDef, CValues *pValues)
{
	if (pValues == NULL)
	{
		return FALSE;
	}

	BOOL bRet = TRUE;
	CValue* pValue = (CValue *)pValues->FindByID(pValueDef->m_strID);

	CRptTemp_Value *pNewValue = new CRptTemp_Value();
	pNewValue->m_strName = pValueDef->m_strName;
	pNewValue->m_strID = pValueDef->m_strID;

	if (pValue == NULL)
	{
		pNewValue->m_strVal = _T("未找到结果值");
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("报告中找不到结果参数【%s】"), pValueDef->m_strID);
		bRet = FALSE;
	}
	else
	{
		pValueDef->UpdatePrecision();
		bRet = GenRpt_Xml_NewValue_ProcessVal(pValue->m_strValue, pNewValue->m_strVal, pValueDef->m_strProcess, pValueDef->m_nPrecision);
		//pNewValue->m_strVal = pValue->m_strValue;
	}

	pParent->AddNewChild(pNewValue);
	return bRet;
}

BOOL CRptTemplate_GenXmlTool::GenRpt_Xml_NewValue_ProcessVal(const CString& strSrcVal, CString &strVal, const CString &strProcess, long nPrecision)
{
	BOOL bRet = TRUE;
	CString strAdd;
	double dVal = CString_To_double(strSrcVal);
	strVal = strSrcVal;

	if (strProcess.IsEmpty() && nPrecision < 0)
	{
		//不处理也不修约，比如：结果描述
		return TRUE;
	}

	//目前对于报告数据处理的，只涉及到比例系数（s到ms，要乘以1000）
	//所以在修约和报告比例系数时，先处理比例系数
	//后面若扩充其它的报告数据处理，则需要根据strProcess，进行特殊处理。以此确定先处理strProcess还是先处理修约。
	if (! strProcess.IsEmpty())
	{
		CBkmkDataProcess *pProcess = FindDataProcessByID(strProcess);

		if (pProcess == NULL)
		{
			CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("未找到报告数据处理的定义【%s】"), strProcess.GetString());
			bRet = FALSE;
		}
		else
		{
			bRet = pProcess->ProcessData(strVal, strAdd, -1);
			dVal = CString_To_double(strVal);
		}
	}

	if (nPrecision >= 0)
	{
// 		long nCoef = 1;
// 		double dCoef = 1.0;
// 		long nCount = nPrecision;
// 		
// 		while (nCount > 0)
// 		{
// 			nCoef *= 10;
// 			dCoef *= 10;
// 			nCount--;
// 		}
// 
// 		//dVal = math_ValueRevised(dVal, nPrecision);
// 		dVal = ((int)(dVal*nCoef+0.5))/dCoef; 
		CString strFormat;
		strFormat.Format(_T("%%.%df"), nPrecision);
		strVal.Format(strFormat, dVal);
	}
	else
	{
		strVal.Format(_T("%f"), dVal);
	}

	if (! strAdd.IsEmpty())
	{
		strVal = strVal + strAdd;
	}
	
	return bRet;
}

CRptTemp_ReportTemplate* CRptTemplate_GenXmlTool::GenRpt_Xml_NewReportTemplate(CExBaseList *pParent)
{
	CRptTemp_ReportTemplate* pNew = new CRptTemp_ReportTemplate();
	pParent->AddNewChild(pNew);
	return pNew;
}

CRptTemp_Title* CRptTemplate_GenXmlTool::GenRpt_Xml_NewTitle(CExBaseList *pParent)
{
	CRptTemp_Title* pNew = new CRptTemp_Title();
	pParent->AddNewChild(pNew);
	return pNew;
}

CRptTemp_Text* CRptTemplate_GenXmlTool::GenRpt_Xml_NewText(CExBaseList *pParent)
{
	CRptTemp_Text* pNew = new CRptTemp_Text();
	pParent->AddNewChild(pNew);
	return pNew;
}

CRptTemp_Grid* CRptTemplate_GenXmlTool::GenRpt_Xml_NewGrid(CExBaseList *pParent, CRptTemp_GridDef *pGridDef)
{
	CRptTemp_Grid* pNew = new CRptTemp_Grid();
	pParent->AddNewChild(pNew);
	pNew->m_strData_Mode = pGridDef->m_strData_Mode;

	//处理head
	POS pos = pGridDef->GetHeadPosition();
	UINT nClassID = 0;
	CExBaseObject *pObj = NULL;

	while (pos != NULL)
	{
		pObj = pGridDef->GetNext(pos);
		nClassID = pObj->GetClassID();

		if (nClassID != MNGRCLASSID_CRPTTEMP_HEAD)
		{
			continue;
		}

		CRptTemp_Head *pHead = (CRptTemp_Head *)pObj;
		CRptTemp_Head *pNewHead = (CRptTemp_Head *)pHead->CloneEx(TRUE, TRUE);
		pNew->AddNewChild(pNewHead);
	}

	return pNew;
}

//根据项目等级，查找相对等级的父项目：CItems节点。并返回名称
CString CRptTemplate_GenXmlTool::GetItemName(CGbItemBase *pItemBase, long nItemLevel)
{
	//查找相对项目时，一定是基于rootnode的CItems查找的
	ASSERT(pItemBase->GetClassID() == GBCLASSID_ITEMS);

	if (pItemBase->GetClassID() != GBCLASSID_ITEMS)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("查找项目名称出错，基准项目不是CItems【%s】"), pItemBase->m_strName.GetString());
		return _T("");
	}

	CItems *pItems = (CItems *)pItemBase;
	ASSERT(pItems->IsTypeRootNode());

	if (! pItems->IsTypeRootNode())
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("查找项目名称出错，基准项目不是rootnode【%s】"), pItemBase->m_strName.GetString());
		return _T("");
	}

	CExBaseObject *pParentItem = pItemBase;
	UINT nClassID = 0;
	CString strTextFind;

	while (nItemLevel > 0)
	{
		pParentItem = (CExBaseObject *)pParentItem->GetParent();
		nClassID = pParentItem->GetClassID();

		if (nClassID != GBCLASSID_ITEMS)
		{
			break;
		}

		nItemLevel--;

		if (nItemLevel == 0)
		{
			strTextFind = pParentItem->m_strName;
		}
	}

	return strTextFind;
}

//根据参数ID，获取项目的报告值
CString CRptTemplate_GenXmlTool::GetItemReportValue(CGbItemBase *pItemBase, const CString &strDataID)
{
	UINT nClassID = pItemBase->GetClassID();

	//只考虑电气量项目和阻抗搜索项目
	if ((nClassID != GBCLASSID_MACROTEST) && (nClassID != GBCLASSID_MACROCHARITEMS))
	{
		return _T("");
	}

	CReport *pReport = pItemBase->GetReport(-1);

	if (pReport == NULL)
	{
		return _T("");
	}

	CValue *pValue = (CValue *)pReport->m_pValues->FindByID(strDataID);

	if (pValue != NULL)
	{
		return pValue->m_strValue;
	}

	return _T("");
}

//从数据接口中，查找对应的接口数据值
CString CRptTemplate_GenXmlTool::GetItemsTec(CRptTemp_TextDef *pTextDef, const CString &strDataID)
{
	CDataGroup *pItemsTec = pTextDef->GetItemsTec();

	if (pItemsTec == NULL)
	{
		return _T("");
	}

	CDvmData *pData = (CDvmData *)pItemsTec->FindByID(strDataID);

	if (pData == NULL)
	{
		return _T("");
	}

	return pData->m_strValue;
}

void CRptTemplate_GenXmlTool::GetItemReports(CExBaseList *pRptLists, CGbItemBase *pItemBase)
{
	pRptLists->RemoveAll();

	if (pItemBase == NULL)
	{
		return;
	}

	long nTestCount = pItemBase->GetItemTestCount();
	CReports *pRpts = pItemBase->GetReports();

	if (pRpts->GetCount() == 0 )
	{
		return;
	}

	if (pRpts->GetCount() < nTestCount)
	{
		//说明报告数量与测试次数对应不起来，只取最后一次
		pRptLists->AddTail(pRpts->GetTail());
		return;
	}

	UINT nClassID = pItemBase->GetClassID();

	if (nClassID == GBCLASSID_MACROTEST)
	{
		//对于电气量项目，此处还要处理电气量项目本身的重复次数
		CMacroTest *pMacroTest = (CMacroTest *)pItemBase;
		long nMacroTestRepeatTimes = pMacroTest->m_nRepeatTimes;

		if (nMacroTestRepeatTimes > 1)
		{
			nTestCount += nTestCount/nMacroTestRepeatTimes;  //对于电气量自己重复测试的部分，应当加上计算的报告数量
		}
	}

	POS pos = pRpts->GetTailPosition();

	while(nTestCount > 0 &&  pos != NULL)
	{
		CReport *pRpt = (CReport *)pRpts->GetPrev(pos);
		pRptLists->AddTail(pRpt);
		pRptLists->BringToHead(pRpt);
		nTestCount--;
	}
}

void CRptTemplate_GenXmlTool::GetPngFilePath(const CString &strItemPath, CString &strPngFile)
{
	strPngFile = _P_GetInstallPath();
	strPngFile += _T("Stt\\Workspace\\Img\\");
	strPngFile += strItemPath;
	strPngFile += _T("Img.png");  //特性图，以固定的命名方式，存在固定的路径
}	

void CRptTemplate_GenXmlTool::GetMacroTest_AllParas(CExBaseList *pParas, CMacroTest *pMacroTest)
{
	if (pMacroTest == NULL)
	{
		return;
	}

	pParas->DeleteAll();

	CMacroTestPara *pMacroTestPara = pMacroTest->GetMacroTestPara();
	CMacroTestParaDatas *pFaultParas = pMacroTestPara->GetFaultParaDatas();

	POS pos = pFaultParas->GetHeadPosition();

	while (pos != NULL)
	{
		CMacroTestParaData *p = (CMacroTestParaData *)pFaultParas->GetNext(pos);
		CDvmData *pData = new CDvmData();
		pData->m_strValue = p->m_strExpression;
		pData->m_strID = p->m_strID;
		pParas->AddNewChild(pData);
	}

	CTestMacroUiParas *pUiParas = pMacroTest->GetTestMacroUiParas();

	if (pUiParas == NULL)
	{
		CItems *pItems = Gb_GetFirstParentItems(pMacroTest, TRUE);

		if (pItems != NULL)
		{
			pUiParas = pItems->GetTestMacroUiParas();

			if (pUiParas == NULL)
			{
				return;
			}
		}
	}

	CDataGroup oUiParas;
	BSTR bstrText = pUiParas->m_strParaText.AllocSysString();
	CDataMngrXmlRWKeys::g_pXmlKeys->m_nIsGroupUseDvmData++;
	BOOL bRet = oUiParas.SetXml(bstrText, CDataMngrXmlRWKeys::g_pXmlKeys);
	CDataMngrXmlRWKeys::g_pXmlKeys->m_nIsGroupUseDvmData++;
	SysFreeString(bstrText);

	GetMacroTest_AllParas_UIParas(pParas, &oUiParas, &oUiParas);
}

void CRptTemplate_GenXmlTool::GetMacroTest_AllParas_UIParas(CExBaseList *pParas, CDataGroup *pUIParas, CExBaseList *pRoot)
{
	UINT nClassID = 0;
	CExBaseObject *pObj = NULL;
	POS pos = pUIParas->GetHeadPosition();

	while (pos != NULL)
	{
		pObj = pUIParas->GetNext(pos);
		nClassID = pObj->GetClassID();

		if (nClassID == DVMCLASSID_CDVMDATA)
		{
			CDvmData *pData = (CDvmData *)pObj;
			CDvmData *pNew = new CDvmData();
			pNew->m_strID = pData->GetIDPathEx(pRoot, FALSE);//pData->m_strID;
			pNew->m_strValue = pData->m_strValue;
			pParas->AddNewChild(pNew);
		}
		else if (nClassID == DTMCLASSID_CDATAGROUP)
		{
			CDataGroup *pGrp = (CDataGroup *)pObj;
			GetMacroTest_AllParas_UIParas(pParas, pGrp, pRoot);
		}
	}
}

CBkmkDataProcess* CRptTemplate_GenXmlTool::FindDataProcessByID(const CString &strID)
{
	CBkmkDataProcessMngr* pProcessMngr = m_oRptTemplateCfg.GetBkmkDataProcessMngr();

	if (pProcessMngr == NULL)
	{
		return NULL;
	}

	return (CBkmkDataProcess *)pProcessMngr->FindByID(strID);
}