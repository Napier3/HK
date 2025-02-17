
#include "stdafx.h"
#include "XLanguageResourceAts_CharLibDev.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// CXLanguageResourceAts_AutoTest
const CString  CXLanguageResourceAts_CharLibDev::g_strXLangRsAts_CharLibDevFile = _T("CharLibDev");

CXLanguageResourceAts_CharLibDev::CXLanguageResourceAts_CharLibDev()
{
	
}

CXLanguageResourceAts_CharLibDev::~CXLanguageResourceAts_CharLibDev()
{
	m_oXLangRsAts_CharLibDev.RemoveAll();
}

CXLangItem* CXLanguageResourceAts_CharLibDev::rs_AddString(const CString &strID, CString *pstrString)
{
	CXLangItem *p = CXLanguage::AddString(strID, pstrString);

	m_oXLangRsAts_CharLibDev.AddTail(p);

	return p;
}


void CXLanguageResourceAts_CharLibDev::InitLangRsByFile()
{
	CXLanguageResourceAtsBase::InitLangRsByFile();

	InitLangRsByFileEx(&m_oXLangRsAts_CharLibDev, g_strXLangRsAts_CharLibDevFile);
}

void CXLanguageResourceAts_CharLibDev::RegisterLanguageResource()
{
	CXLanguageResourceAtsBase::RegisterLanguageResource();

    rs_AddString(g_sLangID_File1, &g_sLangTxt_File1);
	rs_AddString(g_sLangID_Print1, &g_sLangTxt_Print1);
	rs_AddString(g_sLangID_FileClose1, &g_sLangTxt_FileClose1);
	rs_AddString(g_sLangID_Exit1, &g_sLangTxt_Exit1);
	rs_AddString(g_sLangID_Exit1Tip, &g_sLangTxt_Exit1Tip);
	rs_AddString(g_sLangID_View1, &g_sLangTxt_View1);
	rs_AddString(g_sLangID_OutputBar1, &g_sLangTxt_OutputBar1);
	rs_AddString(g_sLangID_OutputBar1Tip, &g_sLangTxt_OutputBar1Tip);
	rs_AddString(g_sLangID_About1, &g_sLangTxt_About1);
	rs_AddString(g_sLangID_About1Tip, &g_sLangTxt_About1Tip);
	rs_AddString(g_sLangID_NewFileCreat, &g_sLangTxt_NewFileCreat);
	rs_AddString(g_sLangID_NewFileCreatTip, &g_sLangTxt_NewFileCreatTip);

	rs_AddString(g_sLangID_Open0, &g_sLangTxt_Open0);
	rs_AddString(g_sLangID_Open0Tip, &g_sLangTxt_Open0Tip);
	rs_AddString(g_sLangID_SaveS, &g_sLangTxt_SaveS);
	rs_AddString(g_sLangID_SaveSTip, &g_sLangTxt_SaveSTip);
	rs_AddString(g_sLangID_SaveAsA, &g_sLangTxt_SaveAsA);
	rs_AddString(g_sLangID_SaveAsATip, &g_sLangTxt_SaveAsATip);
	rs_AddString(g_sLangID_RePrintDoc, &g_sLangTxt_RePrintDoc);
	rs_AddString(g_sLangID_PrintQuick, &g_sLangTxt_PrintQuick);
	rs_AddString(g_sLangID_PrintPre, &g_sLangTxt_PrintPre);
	rs_AddString(g_sLangID_PrintSet, &g_sLangTxt_PrintSet);
	rs_AddString(g_sLangID_CurrentUseDoc, &g_sLangTxt_CurrentUseDoc);

	rs_AddString(g_sLangID_CharCurveOprt, &g_sLangTxt_CharCurveOprt);
	rs_AddString(g_sLangID_CurveOprt, &g_sLangTxt_CurveOprt);
	rs_AddString(g_sLangID_NewCurve, &g_sLangTxt_NewCurve);
	rs_AddString(g_sLangID_SaveCurve, &g_sLangTxt_SaveCurve);
	rs_AddString(g_sLangID_SaveAsCurve, &g_sLangTxt_SaveAsCurve);
	rs_AddString(g_sLangID_DeleteCurve, &g_sLangTxt_DeleteCurve);
	rs_AddString(g_sLangID_ImportCurve, &g_sLangTxt_ImportCurve);
	rs_AddString(g_sLangID_ExportCurve, &g_sLangTxt_ExportCurve);
	rs_AddString(g_sLangID_ModifyCurve, &g_sLangTxt_ModifyCurve);
	rs_AddString(g_sLangID_CurveBar, &g_sLangTxt_CurveBar);
	rs_AddString(g_sLangID_CurveBarTip, &g_sLangTxt_CurveBarTip);
	rs_AddString(g_sLangID_NewCurveTip, &g_sLangTxt_NewCurveTip);
	rs_AddString(g_sLangID_SaveCurveTip, &g_sLangTxt_SaveCurveTip);
	rs_AddString(g_sLangID_SaveAsCurveTip, &g_sLangTxt_SaveAsCurveTip);
	rs_AddString(g_sLangID_DeleteCurveTip, &g_sLangTxt_DeleteCurveTip);
	rs_AddString(g_sLangID_ImportCurveTip, &g_sLangTxt_ImportCurveTip);
	rs_AddString(g_sLangID_ExportCurveTip, &g_sLangTxt_ExportCurveTip);
	rs_AddString(g_sLangID_ModifyCurveTip, &g_sLangTxt_ModifyCurveTip);
	rs_AddString(g_sLangID_Style, &g_sLangTxt_Style);
	rs_AddString(g_sLangID_StyleTip1, &g_sLangTxt_StyleTip1);
	rs_AddString(g_sLangID_StyleTip2, &g_sLangTxt_StyleTip2);
	rs_AddString(g_sLangID_CharCurveSave, &g_sLangTxt_CharCurveSave);
	rs_AddString(g_sLangID_Message1, &g_sLangTxt_Message1);
	rs_AddString(g_sLangID_ModifyCharCurve, &g_sLangTxt_ModifyCharCurve);
	rs_AddString(g_sLangID_OutPut, &g_sLangTxt_OutPut);
	rs_AddString(g_sLangID_CopyOutPut, &g_sLangTxt_CopyOutPut);
	rs_AddString(g_sLangID_ClearOutPut, &g_sLangTxt_ClearOutPut);

	rs_AddString(g_sLangID_FatherSame, &g_sLangTxt_FatherSame);
	rs_AddString(g_sLangID_NewCharCurve, &g_sLangTxt_NewCharCurve);
	rs_AddString(g_sLangID_UnAddPic, &g_sLangTxt_UnAddPic);
	rs_AddString(g_sLangID_NotReali, &g_sLangTxt_NotReali);
	rs_AddString(g_sLangID_AddMemberFctn, &g_sLangTxt_AddMemberFctn);
	rs_AddString(g_sLangID_SureDelElement, &g_sLangTxt_SureDelElement);
	rs_AddString(g_sLangID_SureDelVarious, &g_sLangTxt_SureDelVarious);
	rs_AddString(g_sLangID_ExistNameCurve, &g_sLangTxt_ExistNameCurve);

	rs_AddString(g_sLangID_NewVarious, &g_sLangTxt_NewVarious);
	rs_AddString(g_sLangID_DeleteVarious, &g_sLangTxt_DeleteVarious);
	rs_AddString(g_sLangID_InportElement, &g_sLangTxt_InportElement);
	rs_AddString(g_sLangID_DeleteElement, &g_sLangTxt_DeleteElement);
	rs_AddString(g_sLangID_EdgeElementType, &g_sLangTxt_EdgeElementType);
	rs_AddString(g_sLangID_ErrorBandLength, &g_sLangTxt_ErrorBandLength);
	rs_AddString(g_sLangID_EdgTestPoints, &g_sLangTxt_EdgTestPoints);
	rs_AddString(g_sLangID_CharCurveEdge, &g_sLangTxt_CharCurveEdge);
	rs_AddString(g_sLangID_FolderName, &g_sLangTxt_FolderName);
	rs_AddString(g_sLangID_CurveMageFolder, &g_sLangTxt_CurveMageFolder);

	rs_AddString(g_sLangID_CharCurve, &g_sLangTxt_CharCurve);
	rs_AddString(g_sLangID_DecSystem, &g_sLangTxt_DecSystem);
	rs_AddString(g_sLangID_PolarSystem, &g_sLangTxt_PolarSystem);
	rs_AddString(g_sLangID_LogSystem, &g_sLangTxt_LogSystem);
	rs_AddString(g_sLangID_Vertical, &g_sLangTxt_Vertical);
	rs_AddString(g_sLangID_VerticalLine, &g_sLangTxt_VerticalLine);
	rs_AddString(g_sLangID_HorizontalLine, &g_sLangTxt_HorizontalLine);
	rs_AddString(g_sLangID_SearchLineMode, &g_sLangTxt_SearchLineMode);
	rs_AddString(g_sLangID_ElementDevelop, &g_sLangTxt_ElementDevelop);
	rs_AddString(g_sLangID_ClassView, &g_sLangTxt_ClassView);
	rs_AddString(g_sLangID_ToolTip_143, &g_sLangTxt_ToolTip_143);
	rs_AddString(g_sLangID_ToolTip_32779, &g_sLangTxt_ToolTip_32779);
	rs_AddString(g_sLangID_ToolTip_32780, &g_sLangTxt_ToolTip_32780);
}

CString CXLanguageResourceAts_CharLibDev::g_sLangID_File1                    = _T("sFile1");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_File1                   = _T("文件");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_Print1                    = _T("sPrint1");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_Print1                   = _T("打印");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_FileClose1                    = _T("sFileClose1");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_FileClose1                   = _T("关闭文件");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_Exit1                    = _T("sExit1");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_Exit1                   = _T("退出");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_Exit1Tip                    = _T("sExit1Tip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_Exit1Tip                   = _T("退出应用程序；提示保存文档\n退出");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_View1                    = _T("sView1");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_View1                   = _T("视图");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_OutputBar1                    = _T("sOutputBar1");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_OutputBar1                   = _T("输出栏");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_OutputBar1Tip                    = _T("sOutputBar1Tip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_OutputBar1Tip                   = _T("显示或隐藏输出栏\n输出栏");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_About1                    = _T("sAbout1");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_About1                   = _T("关于");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_About1Tip                    = _T("sAbout1Tip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_About1Tip                   = _T("显示程序信息、版本号和版权\n关于");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_NewFileCreat                    = _T("sNewFileCreat");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_NewFileCreat                   = _T("新建文件");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_NewFileCreatTip                    = _T("sNewFileCreatTip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_NewFileCreatTip                   = _T("创建新文档\n新建");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_Open0                    = _T("sOpen0");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_Open0                   = _T("打开");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_Open0Tip                    = _T("sOpen0Tip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_Open0Tip                   = _T("打开现有文档\n打开");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SaveS                    = _T("sSaveS");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveS                   = _T("保存");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SaveSTip                    = _T("sSaveSTip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveSTip                   = _T("保存活动文档\n保存");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SaveAsA                    = _T("sSaveAsA");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveAsA                   = _T("另存为");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SaveAsATip                    = _T("sSaveAsATip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveAsATip                   = _T("用新名称保存活动文档\n另存为");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_RePrintDoc                    = _T("sRePrintDoc");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_RePrintDoc                   = _T("预览并打印文档");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_PrintQuick                    = _T("sPrintQuick");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_PrintQuick                   = _T("快速打印");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_PrintPre                    = _T("sPrintPre");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_PrintPre                   = _T("打印预览");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_PrintSet                    = _T("sPrintSet");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_PrintSet                   = _T("打印设置");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_CurrentUseDoc                    = _T("sCurrentUseDoc");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_CurrentUseDoc                   = _T("最近使用的文档");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_CharCurveOprt                    = _T("sCharCurveOprt");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_CharCurveOprt                   = _T("特性曲线操作");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_CurveOprt                    = _T("sCurveOprt");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_CurveOprt                   = _T("曲线操作");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_NewCurve                    = _T("sNewCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_NewCurve                   = _T("新建曲线");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SaveCurve                    = _T("sSaveCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveCurve                   = _T("保存曲线");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SaveAsCurve                    = _T("sSaveAsCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveAsCurve                    = _T("曲线另存为");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_DeleteCurve                    = _T("sDeleteCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_DeleteCurve                   = _T("删除曲线");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ImportCurve                    = _T("sImportCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ImportCurve                   = _T("导入曲线");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ExportCurve                    = _T("sExportCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ExportCurve                   = _T("导出曲线");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ModifyCurve                    = _T("sModifyCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ModifyCurve                   = _T("修改曲线");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_CurveBar                    = _T("sCurveBar");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_CurveBar                   = _T("曲线栏");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_CurveBarTip                    = _T("sCurveBarTip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_CurveBarTip                   = _T("显示或隐藏特性曲线\n特性曲线栏");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_NewCurveTip                    = _T("sNewCurveTip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_NewCurveTip                   = _T("新建特性曲线\n新建");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SaveCurveTip                    = _T("sSaveCurveTip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveCurveTip                   = _T("保存特性曲线\n保存");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SaveAsCurveTip                    = _T("sSaveAsCurveTip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveAsCurveTip                    = _T("特性曲线另存为\n另存为");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_DeleteCurveTip                    = _T("sDeleteCurveTip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_DeleteCurveTip                   = _T("删除特性曲线\n删除");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ImportCurveTip                    = _T("sImportCurveTip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ImportCurveTip                   = _T("导入特性曲线\n导入");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ExportCurveTip                    = _T("sExportCurveTip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ExportCurveTip                   = _T("导出特性曲线\n导出");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ModifyCurveTip                    = _T("sModifyCurveTip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ModifyCurveTip                   = _T("修改特性曲线\n修改");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_Style                    = _T("sStyle");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_Style                   = _T("样式");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_StyleTip1                    = _T("sStyleTip1");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_StyleTip1                   = _T("修改视觉样式");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_StyleTip2                    = _T("sStyleTip2");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_StyleTip2                   = _T("选择一个office 2007主题");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_CharCurveSave                    = _T("sCharCurveSave");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_CharCurveSave                   = _T("特性曲线库已经被修改，是否保存修改？");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_Message1                    = _T("sMessage1");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_Message1                   = _T("提示");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ModifyCharCurve                    = _T("sModifyCharCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ModifyCharCurve                    = _T("修改特性曲线");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_OutPut                    = _T("sOutPut");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_OutPut                    = _T("输出");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_CopyOutPut                    = _T("sCopyOutPut");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_CopyOutPut                    = _T("复制输出");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ClearOutPut                    = _T("sClearOutPut");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ClearOutPut                    = _T("清除输出");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_FatherSame                    = _T("sFatherSame");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_FatherSame                    = _T("父文件夹“%s”存在相同名称的“%s”子文件夹！");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_NewCharCurve                    = _T("sNewCharCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_NewCharCurve                    = _T("新建特性曲线");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_UnAddPic                    = _T("sUnAddPic");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_UnAddPic                    = _T("无法加载位图: %x\n");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_NotReali                    = _T("sNotReali");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_NotReali                     = _T("还没有实现");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_AddMemberFctn                    = _T("sAddMemberFctn");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_AddMemberFctn                    = _T("添加成员函数...");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SureDelElement                    = _T("sSureDelElement");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SureDelElement                     = _T("你确实要删除元素“%s”吗？");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SureDelVarious                    = _T("sSureDelVarious");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SureDelVarious                     = _T("是否删除变量“%s”？");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ExistNameCurve                    = _T("sExistNameCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ExistNameCurve                     = _T("存在名称为“%s”的曲线");

CString CXLanguageResourceAts_CharLibDev::g_sLangID_NewVarious                    = _T("sNewVarious");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_NewVarious                     = _T("新建变量");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_DeleteVarious                    = _T("sDeleteVarious");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_DeleteVarious                     = _T("删除变量");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_InportElement                    = _T("sInportElement");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_InportElement                     = _T("插入元素");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_DeleteElement                    = _T("sDeleteElement");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_DeleteElement                     = _T("删除元素");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_EdgeElementType                    = _T("sEdgeElementType");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_EdgeElementType                     = _T("边元素类型");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ErrorBandLength                    = _T("sErrorBandLength");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ErrorBandLength                     = _T("误差带长度");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_EdgTestPoints                    = _T("sEdgTestPoints");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_EdgTestPoints                     = _T("边测试点数");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_CharCurveEdge                    = _T("sCharCurveEdge");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_CharCurveEdge                     = _T("特性曲线边元素");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_FolderName                    = _T("sFolderName");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_FolderName                     = _T("文件夹名称");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_CurveMageFolder                    = _T("sCurveMageFolder");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_CurveMageFolder                     = _T("曲线管理文件夹");

CString CXLanguageResourceAts_CharLibDev::g_sLangID_CharCurve                    = _T("sCharCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_CharCurve                     = _T("特性曲线");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_DecSystem                    = _T("sDecSystem");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_DecSystem                     = _T("笛卡尔坐标系");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_PolarSystem                    = _T("sPolarSystem");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_PolarSystem                     = _T("极坐标系");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_LogSystem                    = _T("sLogSystem");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_LogSystem                      = _T("对数坐标系");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_Vertical                    = _T("sVertical");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_Vertical                     = _T("垂线");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_VerticalLine                    = _T("sVerticalLine");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_VerticalLine                     = _T("垂直竖线");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_HorizontalLine                    = _T("sHorizontalLine");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_HorizontalLine                     = _T("水平横线");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SearchLineMode                    = _T("sSearchLineMode");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SearchLineMode                     = _T("搜索线模式");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ElementDevelop                    = _T("sElementDevelop");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ElementDevelop                     = _T("元素开发中.....");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ClassView                    = _T("sClassView");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ClassView                     = _T("类视图");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ToolTip_143                    = _T("sToolTip_143");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ToolTip_143                     = _T("新建文件夹\n新建文件夹");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ToolTip_32779                    = _T("sToolTip_32779");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ToolTip_32779                     = _T("编辑文件夹\n编辑文件夹");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ToolTip_32780                    = _T("sToolTip_32780");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ToolTip_32780                     = _T("删除文件夹\n删除文件夹");