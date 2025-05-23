#include "SttTestCtrlCntrBase.h"
#include "../UI/Interface/SttHtmlViewApi.h"
#include "../SttTestResourceMngr/TestResource/SttTestResource_4U3I.h"
#include "../SttTestResourceMngr/TestResource/SttTestResource_6U6I.h"
#include "../SttTestResourceMngr/TestResource/SttTestResource_Sync.h"
#include "../SttTestResourceMngr/TestResource/SttTestResource_Async.h"
#include "../../../Module/XLanguage/XLanguageMngr.h"

//sun #include "../../../AutoTest/Module/GbItemsGen/GbSmartGenWzd/GbWzdAi/GbWzdAiTool.h"

extern long g_nLogDebugInfor;

CSttTestCtrlCntrBase::CSttTestCtrlCntrBase()
{
    m_pCurrTestItem = nullptr;
    m_pTestCtrlCntrMsg = nullptr;
    m_pCurrTestMacroUI = nullptr;
    m_pSttTestResouce = nullptr;
	
	OpenReportHead();//读取报告头文件，因为只需要调用一次，所以考虑放在构造函数中，后续再改 sf 20220218
}

CSttTestCtrlCntrBase::~CSttTestCtrlCntrBase()
{
    if (m_pSttTestResouce != nullptr)
	{
		delete m_pSttTestResouce;
        m_pSttTestResouce = nullptr;
	}
}

void CSttTestCtrlCntrBase::SetCurrTestItem(CExBaseObject *pCurrTestItem)
{
    if(pCurrTestItem != nullptr)
    {
        m_pCurrTestItem = pCurrTestItem;
    }
}

CExBaseObject* CSttTestCtrlCntrBase::GetCurrTestItem()
{ 
	return m_pCurrTestItem;
}

CExBaseObject* CSttTestCtrlCntrBase::GetGuideBook()
{
    return nullptr;
}

BOOL CSttTestCtrlCntrBase::StartTest(CDataGroup *pCurrentUIParas)
{
	return FALSE;
}

BOOL CSttTestCtrlCntrBase::StopTest()
{
	return FALSE;
}

long CSttTestCtrlCntrBase::SendManuTrigger()
{
	return 0;
}

void CSttTestCtrlCntrBase::GetAllItemsByID(const CString &strItemID, CExBaseList &oItemList)
{

}

//2022-3-29  lijunqing
long CSttTestCtrlCntrBase::TestItem(const CString &strItemPath)
{
	return 0;
}

long CSttTestCtrlCntrBase::TestFrom(const CString &strItemPath)
{
	return 0;
}


void CSttTestCtrlCntrBase::ConnectAtsServer()
{

}

void CSttTestCtrlCntrBase::OpenMacroTestUI(CSttMacroTestUI_TestMacroUI *pTestMacroUI)
{
	m_pCurrTestMacroUI = pTestMacroUI;

    if (pTestMacroUI == nullptr)
	{
		return;
	}


	m_oTestMacroUI_Paras.DeleteAll();

	if (pTestMacroUI->IsUIWeb()||(!pTestMacroUI->m_strUI_ParaFile.IsEmpty()))//20220803 zhouhj 原生界面也采用此方式读取参数
	{
		if (g_nLogDebugInfor == 1)		CLogPrint::LogString(XLOGLEVEL_TRACE, "***** begin OpenParasFile >>");
        //stt_ui_OpenParasFile(pTestMacroUI->m_strUI_ParaFile, &m_oTestMacroUI_Paras);
		if (g_nLogDebugInfor == 1)		CLogPrint::LogString(XLOGLEVEL_TRACE, "***** end  OpenParasFile >>");

		//2023-2-7  lijunqing 根据装置模型智能生成模板参数
        //sun if (g_theGbWzdAiTool != nullptr)
        //sun {
        //sun 	CString strAiFile = stt_ui_GetParasAiFile(pTestMacroUI->m_strUI_ParaFile);
        //sun 	g_theGbWzdAiTool->GbWzdAi(strAiFile, &m_oTestMacroUI_Paras);
        //sun
        //sun 	//调试模式下，查看智能匹配的结果
        //sun 	//stt_ui_SaveParasFile("GbWzdAiTool_After_Ai.xml", &m_oTestMacroUI_Paras);
        //sun }
	}
	
	if (g_nLogDebugInfor == 1)		CLogPrint::LogString(XLOGLEVEL_TRACE, ">> begin OpenHdRsFile >>");
	stt_OpenHdRsFile(pTestMacroUI->m_strHdRsFile);
	if (g_nLogDebugInfor == 1)		CLogPrint::LogString(XLOGLEVEL_TRACE, ">> end  OpenHdRsFile >>");


}

void CSttTestCtrlCntrBase::stt_OpenHdRsFile(const CString &strHdRsFile)
{
    if ((m_pSttTestResouce != nullptr)&&(m_pSttTestResouce->GetChMapFileName() == strHdRsFile))//如果软件资源与当前的一致,则返回
	{
		return;
	}

    if (m_pSttTestResouce != nullptr)
	{
		delete m_pSttTestResouce;
	}

	if (strHdRsFile == STT_TEST_RESOURCE_FILENAME_ASYNC)
	{
		m_pSttTestResouce = new CSttTestResource_Async;
	}
	else if (strHdRsFile == STT_TEST_RESOURCE_FILENAME_SYNC)
	{
		m_pSttTestResouce = new CSttTestResource_Sync;
	}
	else if (strHdRsFile == STT_TEST_RESOURCE_FILENAME_4U3I)
	{
		m_pSttTestResouce = new CSttTestResource_4U3I;
	}
	else if (strHdRsFile == STT_TEST_RESOURCE_FILENAME_6U6I)
	{
		m_pSttTestResouce = new CSttTestResource_6U6I;
	}
	else
		m_pSttTestResouce = new CSttTestResource_4U3I;

	g_oSttTestResourceMngr.m_pTestResouce = m_pSttTestResouce;
	g_oSttTestResourceMngr.CreateChMaps();
	g_oSttTestResourceMngr.InitLocalSysPara();
	g_oSttTestResourceMngr.ValidHardRsChMaps();
	g_oSttTestResourceMngr.CreateSoftRsCh();
	g_oSttTestResourceMngr.CreateRtDataMngr();
	g_oSttTestResourceMngr.m_oIecDatasMngr.UpdateFT3ChsType(g_oSystemParas.m_nIecFormat,g_oSystemParas.m_nIecFormatMeas);//20240117 suyang 初始化时转换FT3通道类型
//	g_theTestCntrFrame->m_pSttTestResource = m_pSttTestResouce;
}



void CSttTestCtrlCntrBase::InitDefaultHdRs()
{
	stt_OpenHdRsFile(STT_TEST_RESOURCE_FILENAME_SYNC);
}

void CSttTestCtrlCntrBase::GetMacroUI_GbItems(CString &strMacroUI_Items)
{
	//获取m_pCurrEditMacroItems的概要信息
}

void CSttTestCtrlCntrBase::GetReportHeadFile(CString &strFile)
{
    //sun strFile = stt_ui_GetParasFile("ReportHead_Paras.xml");
}

void CSttTestCtrlCntrBase::OpenReportHead()
{
	CString strPath;
	GetReportHeadFile(strPath);

	dvm_IncGroupUseDvmData(CSttCmdDefineXmlRWKeys::g_pXmlKeys);
	m_oTestReportHead.OpenXmlFile(strPath, CSttCmdDefineXmlRWKeys::g_pXmlKeys);

#ifndef NOT_USE_XLANGUAGE
	xlang_TranslateByResourceFileEx(&m_oTestReportHead,_T("ReportHead_Paras.xml"));
#endif

	dvm_DecGroupUseDvmData(CSttCmdDefineXmlRWKeys::g_pXmlKeys);
}

void CSttTestCtrlCntrBase::SaveReportHead()
{
	CString strPath;
	GetReportHeadFile(strPath);
	m_oTestReportHead.SaveXmlFile(strPath, CSttCmdDefineXmlRWKeys::g_pXmlKeys);
}

//模板生成相关的接口
//单个功能的模板生成
long CSttTestCtrlCntrBase::Ats_GenerateTemplate()
{
	return 0;
}

long CSttTestCtrlCntrBase::Ats_GenerateItems(const CString &strItemParentPath, const CString &strItemsName, const CString &strItemsID
											 , CDataGroup *pCommCmd, const CString &strDvmFile, const CString strTestClass, long nRepeatTimes
											 , long nRptTitle, long nTitleLevel, long nSynMode)
{
	return 0;
}

long CSttTestCtrlCntrBase::Ats_SetItemPara(const CString &strItemPath, const CString& strMacroID)
{
	return 0;
}

long CSttTestCtrlCntrBase::Ats_SetItemPara_RsltExpr(const CString &strItemPath, const CString& strRlstExpr)
{
	return 0;
}

long CSttTestCtrlCntrBase::Ats_AddMacro(const CString &strParentItemPath, const CString &strItemName, const CString &strItemID, const CString &strMacroID, const CString &strItemParas)
{
	return 0;
}

long CSttTestCtrlCntrBase::Ats_UpdateItem(const CString &strItemPath)
{
	return 0;
}

long CSttTestCtrlCntrBase::Ats_UpdateItem(const CString &strItemPath, const CString &strItemParas, const CString &strItemType)
{
	return 0;
}

long CSttTestCtrlCntrBase::Ats_QueryItem(const CString &strItemPath)
{
	return 0;
}

long CSttTestCtrlCntrBase::Ats_SetParameter(const CString &strMacroID, CDataGroup *pParas)
{
	return 0;
}

//2022-3-29  lijunqing
long CSttTestCtrlCntrBase::Ats_NewItems(CExBaseList *pParent, CExBaseObject *pItems)
{
	return 0;
}

long CSttTestCtrlCntrBase::Ats_EditItems(CExBaseList *pParent, CExBaseObject *pItems, const CString &strItemsID)
{
	return 0;
}

long CSttTestCtrlCntrBase::Ats_DeleteItems(CExBaseList *pParent, CExBaseObject *pItems)
{
	return 0;
}

//2022-10-20  shaolei
long CSttTestCtrlCntrBase::Ats_MoveUpItem(CExBaseList *pParent, CExBaseObject *pItems, long nMoveTimes)
{
	return 0;
}

long CSttTestCtrlCntrBase::Ats_MoveDownItem(CExBaseList *pParent, CExBaseObject *pItems, long nMoveTimes)
{
	return 0;
}

//2023-2-1  shaolei
long CSttTestCtrlCntrBase::Ats_ItemPaste(CExBaseList *pParent, const CString& strSrcItemPath)
{
	return 0;
}

//2023-8-11 shaolei //添加测试前、后通讯组合
long CSttTestCtrlCntrBase::Ats_CmdAddGrp(CExBaseList *pParent, long nAftUseReset, long nAddCommCmd)
{
	return 0;
}

//2023-8-14 shaolei  //导入模型文件(模型映射)
long CSttTestCtrlCntrBase::Ats_ImportDvmFile(const CString &strDvmFile, long nIsDvmMap)
{
	return 0;
}

//2023-8-28 shaolei  //遥测参数映射
long CSttTestCtrlCntrBase::Ats_AinDataMap(CDataGroup *pMapParas, CDataGroup *pAinDevRatios)
{
	return 0;
}

//2023-8-29 shaolei  //配置装置
long CSttTestCtrlCntrBase::Ats_ConfigDevice(CDataGroup *pCommCfg)
{
	return 0;
}

//2022-08-31 shaolei
long CSttTestCtrlCntrBase::Ats_GenrateItems_CmdWzd(CExBaseList *pParent, CDataGroup *pCommCmd, const CString &strMacroName, const CString &strTestClass, long nSynMode)
{
	return 0;
}

long CSttTestCtrlCntrBase::Ats_GenrateItems_CmdAdd(const CString &strParentItemPath, CDataGroup *pCommCmd, CSttContents *pContents)
{
	return 0;
}

long CSttTestCtrlCntrBase::Ats_GenerateItems_AddSafety(CDataGroup *pParas, CExBaseList *pListDatas, CExBaseList *pMsgs)
{
	return 0;
}
//模板、报告数据等相关的接口  2022-3-14  lijunqing
CString CSttTestCtrlCntrBase::SaveTestFile(const CString &strRealPath, const CString &strTemplateFileName)
{
	return "";
}
CString CSttTestCtrlCntrBase::SaveSysTemplateFile(const CString &strTemplateFileName)
{
	return "";
}
CString CSttTestCtrlCntrBase::SaveTemplateFile(const CString &strTemplateFileName)
{
	return "";
}

BOOL CSttTestCtrlCntrBase::SaveTemplate(const CString &strPath, const CString &strFileName, CDataGroup *pCurrentUIParas, long nSynMode)
{
	return FALSE;
}

BOOL CSttTestCtrlCntrBase::SaveTest(const CString &strPath, const CString &strFileName, CDataGroup *pCurrentUIParas, long nSynMode)
{
	return FALSE;
}

BOOL CSttTestCtrlCntrBase::ExportWordRpt(const CString &strPath, const CString &strFileName, CDataGroup *pParas)
{
	return FALSE;
}

BOOL CSttTestCtrlCntrBase::OpenTemplate(const CString &strFileWithPath, const CString &strDvmFile)
{
	return FALSE;
}

BOOL CSttTestCtrlCntrBase::OpenTest(const CString &strFileWithPath, const CString &strDvmFile)
{
	return FALSE;
}

//清除报告数据，形参是预留的参数，可以不传递参数
BOOL CSttTestCtrlCntrBase::ClearReportsRslts(CDataGroup *pParas)
{
	return FALSE;
}

//2022-4-14 lijunqing
void CSttTestCtrlCntrBase::Ats_IecDetect(long bEnable)
{
	
}

void CSttTestCtrlCntrBase::Ats_IecRecord(CDataGroup *pIecRecordParas)
{
	
}


//2022-3-11 lijunqing
void CSttTestCtrlCntrBase::OpenMacroTestUI_ParaFile(long nFileIndex)
{
    if (m_pCurrTestMacroUI == nullptr)
	{
		return;
	}

	CString strFile = m_pCurrTestMacroUI->m_strUI_ParaFile;

	if (nFileIndex > 0)
	{
		strFile = GetFileTitleFromFilePath(strFile);
		strFile.AppendFormat("%d", nFileIndex);
		strFile += ".xml";
	}

    //sun stt_ui_OpenParasFile(strFile, &m_oTestMacroUI_Paras);
}

void CSttTestCtrlCntrBase::SaveMacroTestUI_ParaFile(const CString &strTitleAdd)
{
    if (m_pCurrTestMacroUI == nullptr)
	{
		return;
	}

	CString strFile = m_pCurrTestMacroUI->m_strUI_ParaFile;

	if (strTitleAdd.GetLength() > 0)
	{
		strFile = GetFileTitleFromFilePath(strFile);
		strFile += strTitleAdd;
		strFile += ".xml";
	}

    //sun stt_ui_SaveParasFile(strFile, &m_oTestMacroUI_Paras);
}

void CSttTestCtrlCntrBase::SaveCurrTestMacroUITemplateFile()
{
    if (m_pCurrTestMacroUI == nullptr)
	{
		return;
	}

	CString strFile = SaveSysTemplateFile(m_pCurrTestMacroUI->m_strID);
}

long CSttTestCtrlCntrBase::GetGbItemCount()
{
	ASSERT(FALSE);

	return 0;
}

//是否已有测试任务，以是否创建测试（创建CSttDevice）为判断依据
BOOL CSttTestCtrlCntrBase::IsHasTestTask()
{
	ASSERT(FALSE);

	return FALSE;
}
