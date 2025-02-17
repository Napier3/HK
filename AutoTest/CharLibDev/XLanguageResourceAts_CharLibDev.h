#pragma once

#include "..\..\Module\XLanguage\XLanguageMngr.h"
#include "..\Module\XLanguageResourceAts.h"

class CXLanguageResourceAts_CharLibDev : public CXLanguageResourceAtsBase
{
// ����
public:
	CXLanguageResourceAts_CharLibDev();
	virtual ~CXLanguageResourceAts_CharLibDev();
	
private:
	CXLanguage m_oXLangRsAts_CharLibDev;
	static const CString  g_strXLangRsAts_CharLibDevFile;

public:
	CXLangItem* rs_AddString(const CString &strID, CString *pstrString);	

	virtual void InitLangRsByFile();
	virtual void RegisterLanguageResource();

public:
	static CString g_sLangID_File1; 
	static CString g_sLangTxt_File1;
	static CString g_sLangID_Print1; 
	static CString g_sLangTxt_Print1;
	static CString g_sLangID_FileClose1; 
	static CString g_sLangTxt_FileClose1;
	static CString g_sLangID_Exit1; 
	static CString g_sLangTxt_Exit1;
	static CString g_sLangID_Exit1Tip; 
	static CString g_sLangTxt_Exit1Tip;
	static CString g_sLangID_View1; 
	static CString g_sLangTxt_View1;
	static CString g_sLangID_OutputBar1; 
	static CString g_sLangTxt_OutputBar1;
	static CString g_sLangID_OutputBar1Tip; 
	static CString g_sLangTxt_OutputBar1Tip;
	static CString g_sLangID_About1; 
	static CString g_sLangTxt_About1;
	static CString g_sLangID_About1Tip; 
	static CString g_sLangTxt_About1Tip;
	static CString g_sLangID_NewFileCreat; 
	static CString g_sLangTxt_NewFileCreat;
	static CString g_sLangID_NewFileCreatTip; 
	static CString g_sLangTxt_NewFileCreatTip;
    static CString g_sLangID_Open0; 
	static CString g_sLangTxt_Open0;
	static CString g_sLangID_Open0Tip; 
	static CString g_sLangTxt_Open0Tip;
	static CString g_sLangID_SaveS; 
	static CString g_sLangTxt_SaveS;
	static CString g_sLangID_SaveSTip; 
	static CString g_sLangTxt_SaveSTip;
	static CString g_sLangID_SaveAsA; 
	static CString g_sLangTxt_SaveAsA;
	static CString g_sLangID_SaveAsATip; 
	static CString g_sLangTxt_SaveAsATip;
	static CString g_sLangID_RePrintDoc; //Ԥ������ӡ�ĵ�
	static CString g_sLangTxt_RePrintDoc;
	static CString g_sLangID_PrintQuick; //���ٴ�ӡ
	static CString g_sLangTxt_PrintQuick;
	static CString g_sLangID_PrintPre; //��ӡԤ��
	static CString g_sLangTxt_PrintPre;
	static CString g_sLangID_PrintSet; //��ӡ����
	static CString g_sLangTxt_PrintSet;
	static CString g_sLangID_CurrentUseDoc; //���ʹ�õ��ĵ�
	static CString g_sLangTxt_CurrentUseDoc;
	static CString g_sLangID_CharCurveOprt; //�������߲���
	static CString g_sLangTxt_CharCurveOprt;
	static CString g_sLangID_CurveOprt; //���߲���
	static CString g_sLangTxt_CurveOprt;
	static CString g_sLangID_NewCurve; //�½�����
	static CString g_sLangTxt_NewCurve;
	static CString g_sLangID_SaveCurve; //��������
	static CString g_sLangTxt_SaveCurve;
	static CString g_sLangID_SaveAsCurve; //�������Ϊ
	static CString g_sLangTxt_SaveAsCurve;
	static CString g_sLangID_DeleteCurve; //ɾ������
	static CString g_sLangTxt_DeleteCurve;
	static CString g_sLangID_ImportCurve; //��������
	static CString g_sLangTxt_ImportCurve;
	static CString g_sLangID_ExportCurve; //��������
	static CString g_sLangTxt_ExportCurve;
	static CString g_sLangID_ModifyCurve; //�޸�����
	static CString g_sLangTxt_ModifyCurve;
	static CString g_sLangID_CurveBar; //������
	static CString g_sLangTxt_CurveBar;
	static CString g_sLangID_CurveBarTip; //��ʾ��������������\n����������
	static CString g_sLangTxt_CurveBarTip;
	static CString g_sLangID_NewCurveTip; //�½���������\n�½�
	static CString g_sLangTxt_NewCurveTip;
	static CString g_sLangID_SaveCurveTip; //������������\n����
	static CString g_sLangTxt_SaveCurveTip;
	static CString g_sLangID_SaveAsCurveTip; //�����������Ϊ\n���Ϊ
	static CString g_sLangTxt_SaveAsCurveTip;
	static CString g_sLangID_DeleteCurveTip; //ɾ����������\nɾ��
	static CString g_sLangTxt_DeleteCurveTip;
	static CString g_sLangID_ImportCurveTip; //������������\n����
	static CString g_sLangTxt_ImportCurveTip;
	static CString g_sLangID_ExportCurveTip; //������������\n����
	static CString g_sLangTxt_ExportCurveTip;
	static CString g_sLangID_ModifyCurveTip; //�޸���������\n�޸�
	static CString g_sLangTxt_ModifyCurveTip;
	static CString g_sLangID_Style; //��ʽ
	static CString g_sLangTxt_Style;
	static CString g_sLangID_StyleTip1; //�޸��Ӿ���ʽ
	static CString g_sLangTxt_StyleTip1;
	static CString g_sLangID_StyleTip2; //ѡ��һ��office 2007����
	static CString g_sLangTxt_StyleTip2;
	static CString g_sLangID_CharCurveSave; //�������߿��Ѿ����޸ģ��Ƿ񱣴��޸ģ�
	static CString g_sLangTxt_CharCurveSave;
	static CString g_sLangID_Message1; //��ʾ
	static CString g_sLangTxt_Message1;
	static CString g_sLangID_ModifyCharCurve; //�޸���������
	static CString g_sLangTxt_ModifyCharCurve;
	static CString g_sLangID_OutPut; //���
	static CString g_sLangTxt_OutPut;
	static CString g_sLangID_CopyOutPut; //�������
	static CString g_sLangTxt_CopyOutPut;
	static CString g_sLangID_ClearOutPut; //������
	static CString g_sLangTxt_ClearOutPut;
	static CString g_sLangID_FatherSame; //���ļ��С�%s��������ͬ���Ƶġ�%s�����ļ��У�
	static CString g_sLangTxt_FatherSame;
	static CString g_sLangID_NewCharCurve; //�½���������
	static CString g_sLangTxt_NewCharCurve;
	static CString g_sLangID_UnAddPic; //�޷�����λͼ: %x\n
	static CString g_sLangTxt_UnAddPic;
	static CString g_sLangID_NotReali; //��û��ʵ��
	static CString g_sLangTxt_NotReali;
	static CString g_sLangID_AddMemberFctn; //��ӳ�Ա����...
	static CString g_sLangTxt_AddMemberFctn;
	static CString g_sLangID_SureDelElement; //��ȷʵҪɾ��Ԫ�ء�%s����
	static CString g_sLangTxt_SureDelElement;
	static CString g_sLangID_SureDelVarious; //�Ƿ�ɾ��������%s����
	static CString g_sLangTxt_SureDelVarious;
	static CString g_sLangID_ExistNameCurve; //��������Ϊ��%s��������
	static CString g_sLangTxt_ExistNameCurve;
	static CString g_sLangID_NewVarious; //�½�����
	static CString g_sLangTxt_NewVarious;
	static CString g_sLangID_DeleteVarious; //ɾ������
	static CString g_sLangTxt_DeleteVarious;
	static CString g_sLangID_InportElement; //����Ԫ��
	static CString g_sLangTxt_InportElement;
	static CString g_sLangID_DeleteElement; //ɾ��Ԫ��
	static CString g_sLangTxt_DeleteElement;
	static CString g_sLangID_EdgeElementType; 
	static CString g_sLangTxt_EdgeElementType;
	static CString g_sLangID_ErrorBandLength; 
	static CString g_sLangTxt_ErrorBandLength;
	static CString g_sLangID_EdgTestPoints; 
	static CString g_sLangTxt_EdgTestPoints;
	static CString g_sLangID_CharCurveEdge; 
	static CString g_sLangTxt_CharCurveEdge;
	static CString g_sLangID_FolderName; //�ļ�������
	static CString g_sLangTxt_FolderName;
	static CString g_sLangID_CurveMageFolder; //���߹����ļ���
	static CString g_sLangTxt_CurveMageFolder;

	static CString g_sLangID_CharCurve; //��������
	static CString g_sLangTxt_CharCurve;
	static CString g_sLangID_DecSystem; //�ѿ�������ϵ
	static CString g_sLangTxt_DecSystem;
	static CString g_sLangID_PolarSystem; //������ϵ
	static CString g_sLangTxt_PolarSystem;
	static CString g_sLangID_LogSystem; //��������ϵ
	static CString g_sLangTxt_LogSystem;
	static CString g_sLangID_Vertical; //����
	static CString g_sLangTxt_Vertical;
	static CString g_sLangID_VerticalLine; //��ֱ����
	static CString g_sLangTxt_VerticalLine;
	static CString g_sLangID_HorizontalLine; //ˮƽ����
	static CString g_sLangTxt_HorizontalLine;
	static CString g_sLangID_SearchLineMode; //������ģʽ
	static CString g_sLangTxt_SearchLineMode;
	static CString g_sLangID_ElementDevelop; //Ԫ�ؿ�����.....
	static CString g_sLangTxt_ElementDevelop;
	static CString g_sLangID_ClassView; //����ͼ
	static CString g_sLangTxt_ClassView;
	static CString g_sLangID_ToolTip_143;//�½��ļ���\n�½��ļ���
	static CString g_sLangTxt_ToolTip_143;
	static CString g_sLangID_ToolTip_32779;//�༭�ļ���\n�༭�ļ���
	static CString g_sLangTxt_ToolTip_32779;
	static CString g_sLangID_ToolTip_32780;//ɾ���ļ���\nɾ���ļ���
	static CString g_sLangTxt_ToolTip_32780;
};

