
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
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_File1                   = _T("�ļ�");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_Print1                    = _T("sPrint1");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_Print1                   = _T("��ӡ");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_FileClose1                    = _T("sFileClose1");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_FileClose1                   = _T("�ر��ļ�");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_Exit1                    = _T("sExit1");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_Exit1                   = _T("�˳�");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_Exit1Tip                    = _T("sExit1Tip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_Exit1Tip                   = _T("�˳�Ӧ�ó�����ʾ�����ĵ�\n�˳�");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_View1                    = _T("sView1");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_View1                   = _T("��ͼ");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_OutputBar1                    = _T("sOutputBar1");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_OutputBar1                   = _T("�����");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_OutputBar1Tip                    = _T("sOutputBar1Tip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_OutputBar1Tip                   = _T("��ʾ�����������\n�����");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_About1                    = _T("sAbout1");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_About1                   = _T("����");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_About1Tip                    = _T("sAbout1Tip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_About1Tip                   = _T("��ʾ������Ϣ���汾�źͰ�Ȩ\n����");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_NewFileCreat                    = _T("sNewFileCreat");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_NewFileCreat                   = _T("�½��ļ�");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_NewFileCreatTip                    = _T("sNewFileCreatTip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_NewFileCreatTip                   = _T("�������ĵ�\n�½�");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_Open0                    = _T("sOpen0");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_Open0                   = _T("��");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_Open0Tip                    = _T("sOpen0Tip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_Open0Tip                   = _T("�������ĵ�\n��");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SaveS                    = _T("sSaveS");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveS                   = _T("����");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SaveSTip                    = _T("sSaveSTip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveSTip                   = _T("�����ĵ�\n����");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SaveAsA                    = _T("sSaveAsA");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveAsA                   = _T("���Ϊ");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SaveAsATip                    = _T("sSaveAsATip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveAsATip                   = _T("�������Ʊ����ĵ�\n���Ϊ");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_RePrintDoc                    = _T("sRePrintDoc");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_RePrintDoc                   = _T("Ԥ������ӡ�ĵ�");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_PrintQuick                    = _T("sPrintQuick");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_PrintQuick                   = _T("���ٴ�ӡ");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_PrintPre                    = _T("sPrintPre");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_PrintPre                   = _T("��ӡԤ��");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_PrintSet                    = _T("sPrintSet");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_PrintSet                   = _T("��ӡ����");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_CurrentUseDoc                    = _T("sCurrentUseDoc");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_CurrentUseDoc                   = _T("���ʹ�õ��ĵ�");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_CharCurveOprt                    = _T("sCharCurveOprt");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_CharCurveOprt                   = _T("�������߲���");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_CurveOprt                    = _T("sCurveOprt");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_CurveOprt                   = _T("���߲���");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_NewCurve                    = _T("sNewCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_NewCurve                   = _T("�½�����");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SaveCurve                    = _T("sSaveCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveCurve                   = _T("��������");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SaveAsCurve                    = _T("sSaveAsCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveAsCurve                    = _T("�������Ϊ");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_DeleteCurve                    = _T("sDeleteCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_DeleteCurve                   = _T("ɾ������");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ImportCurve                    = _T("sImportCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ImportCurve                   = _T("��������");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ExportCurve                    = _T("sExportCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ExportCurve                   = _T("��������");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ModifyCurve                    = _T("sModifyCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ModifyCurve                   = _T("�޸�����");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_CurveBar                    = _T("sCurveBar");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_CurveBar                   = _T("������");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_CurveBarTip                    = _T("sCurveBarTip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_CurveBarTip                   = _T("��ʾ��������������\n����������");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_NewCurveTip                    = _T("sNewCurveTip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_NewCurveTip                   = _T("�½���������\n�½�");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SaveCurveTip                    = _T("sSaveCurveTip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveCurveTip                   = _T("������������\n����");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SaveAsCurveTip                    = _T("sSaveAsCurveTip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveAsCurveTip                    = _T("�����������Ϊ\n���Ϊ");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_DeleteCurveTip                    = _T("sDeleteCurveTip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_DeleteCurveTip                   = _T("ɾ����������\nɾ��");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ImportCurveTip                    = _T("sImportCurveTip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ImportCurveTip                   = _T("������������\n����");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ExportCurveTip                    = _T("sExportCurveTip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ExportCurveTip                   = _T("������������\n����");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ModifyCurveTip                    = _T("sModifyCurveTip");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ModifyCurveTip                   = _T("�޸���������\n�޸�");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_Style                    = _T("sStyle");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_Style                   = _T("��ʽ");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_StyleTip1                    = _T("sStyleTip1");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_StyleTip1                   = _T("�޸��Ӿ���ʽ");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_StyleTip2                    = _T("sStyleTip2");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_StyleTip2                   = _T("ѡ��һ��office 2007����");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_CharCurveSave                    = _T("sCharCurveSave");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_CharCurveSave                   = _T("�������߿��Ѿ����޸ģ��Ƿ񱣴��޸ģ�");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_Message1                    = _T("sMessage1");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_Message1                   = _T("��ʾ");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ModifyCharCurve                    = _T("sModifyCharCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ModifyCharCurve                    = _T("�޸���������");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_OutPut                    = _T("sOutPut");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_OutPut                    = _T("���");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_CopyOutPut                    = _T("sCopyOutPut");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_CopyOutPut                    = _T("�������");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ClearOutPut                    = _T("sClearOutPut");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ClearOutPut                    = _T("������");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_FatherSame                    = _T("sFatherSame");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_FatherSame                    = _T("���ļ��С�%s��������ͬ���Ƶġ�%s�����ļ��У�");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_NewCharCurve                    = _T("sNewCharCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_NewCharCurve                    = _T("�½���������");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_UnAddPic                    = _T("sUnAddPic");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_UnAddPic                    = _T("�޷�����λͼ: %x\n");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_NotReali                    = _T("sNotReali");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_NotReali                     = _T("��û��ʵ��");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_AddMemberFctn                    = _T("sAddMemberFctn");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_AddMemberFctn                    = _T("��ӳ�Ա����...");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SureDelElement                    = _T("sSureDelElement");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SureDelElement                     = _T("��ȷʵҪɾ��Ԫ�ء�%s����");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SureDelVarious                    = _T("sSureDelVarious");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SureDelVarious                     = _T("�Ƿ�ɾ��������%s����");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ExistNameCurve                    = _T("sExistNameCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ExistNameCurve                     = _T("��������Ϊ��%s��������");

CString CXLanguageResourceAts_CharLibDev::g_sLangID_NewVarious                    = _T("sNewVarious");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_NewVarious                     = _T("�½�����");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_DeleteVarious                    = _T("sDeleteVarious");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_DeleteVarious                     = _T("ɾ������");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_InportElement                    = _T("sInportElement");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_InportElement                     = _T("����Ԫ��");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_DeleteElement                    = _T("sDeleteElement");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_DeleteElement                     = _T("ɾ��Ԫ��");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_EdgeElementType                    = _T("sEdgeElementType");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_EdgeElementType                     = _T("��Ԫ������");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ErrorBandLength                    = _T("sErrorBandLength");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ErrorBandLength                     = _T("��������");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_EdgTestPoints                    = _T("sEdgTestPoints");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_EdgTestPoints                     = _T("�߲��Ե���");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_CharCurveEdge                    = _T("sCharCurveEdge");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_CharCurveEdge                     = _T("�������߱�Ԫ��");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_FolderName                    = _T("sFolderName");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_FolderName                     = _T("�ļ�������");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_CurveMageFolder                    = _T("sCurveMageFolder");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_CurveMageFolder                     = _T("���߹����ļ���");

CString CXLanguageResourceAts_CharLibDev::g_sLangID_CharCurve                    = _T("sCharCurve");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_CharCurve                     = _T("��������");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_DecSystem                    = _T("sDecSystem");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_DecSystem                     = _T("�ѿ�������ϵ");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_PolarSystem                    = _T("sPolarSystem");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_PolarSystem                     = _T("������ϵ");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_LogSystem                    = _T("sLogSystem");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_LogSystem                      = _T("��������ϵ");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_Vertical                    = _T("sVertical");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_Vertical                     = _T("����");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_VerticalLine                    = _T("sVerticalLine");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_VerticalLine                     = _T("��ֱ����");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_HorizontalLine                    = _T("sHorizontalLine");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_HorizontalLine                     = _T("ˮƽ����");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_SearchLineMode                    = _T("sSearchLineMode");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_SearchLineMode                     = _T("������ģʽ");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ElementDevelop                    = _T("sElementDevelop");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ElementDevelop                     = _T("Ԫ�ؿ�����.....");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ClassView                    = _T("sClassView");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ClassView                     = _T("����ͼ");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ToolTip_143                    = _T("sToolTip_143");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ToolTip_143                     = _T("�½��ļ���\n�½��ļ���");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ToolTip_32779                    = _T("sToolTip_32779");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ToolTip_32779                     = _T("�༭�ļ���\n�༭�ļ���");
CString CXLanguageResourceAts_CharLibDev::g_sLangID_ToolTip_32780                    = _T("sToolTip_32780");
CString CXLanguageResourceAts_CharLibDev::g_sLangTxt_ToolTip_32780                     = _T("ɾ���ļ���\nɾ���ļ���");