#pragma once

#include "..\..\Module\XLanguage\XLanguageMngr.h"
#include "..\Module\XLanguageResourceAts.h"

class CXLanguageResourceAts_CharLibDev : public CXLanguageResourceAtsBase
{
// 构造
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
	static CString g_sLangID_RePrintDoc; //预览并打印文档
	static CString g_sLangTxt_RePrintDoc;
	static CString g_sLangID_PrintQuick; //快速打印
	static CString g_sLangTxt_PrintQuick;
	static CString g_sLangID_PrintPre; //打印预览
	static CString g_sLangTxt_PrintPre;
	static CString g_sLangID_PrintSet; //打印设置
	static CString g_sLangTxt_PrintSet;
	static CString g_sLangID_CurrentUseDoc; //最近使用的文档
	static CString g_sLangTxt_CurrentUseDoc;
	static CString g_sLangID_CharCurveOprt; //特性曲线操作
	static CString g_sLangTxt_CharCurveOprt;
	static CString g_sLangID_CurveOprt; //曲线操作
	static CString g_sLangTxt_CurveOprt;
	static CString g_sLangID_NewCurve; //新建曲线
	static CString g_sLangTxt_NewCurve;
	static CString g_sLangID_SaveCurve; //保存曲线
	static CString g_sLangTxt_SaveCurve;
	static CString g_sLangID_SaveAsCurve; //曲线另存为
	static CString g_sLangTxt_SaveAsCurve;
	static CString g_sLangID_DeleteCurve; //删除曲线
	static CString g_sLangTxt_DeleteCurve;
	static CString g_sLangID_ImportCurve; //导出曲线
	static CString g_sLangTxt_ImportCurve;
	static CString g_sLangID_ExportCurve; //导出曲线
	static CString g_sLangTxt_ExportCurve;
	static CString g_sLangID_ModifyCurve; //修改曲线
	static CString g_sLangTxt_ModifyCurve;
	static CString g_sLangID_CurveBar; //曲线栏
	static CString g_sLangTxt_CurveBar;
	static CString g_sLangID_CurveBarTip; //显示或隐藏特性曲线\n特性曲线栏
	static CString g_sLangTxt_CurveBarTip;
	static CString g_sLangID_NewCurveTip; //新建特性曲线\n新建
	static CString g_sLangTxt_NewCurveTip;
	static CString g_sLangID_SaveCurveTip; //保存特性曲线\n保存
	static CString g_sLangTxt_SaveCurveTip;
	static CString g_sLangID_SaveAsCurveTip; //特性曲线另存为\n另存为
	static CString g_sLangTxt_SaveAsCurveTip;
	static CString g_sLangID_DeleteCurveTip; //删除特性曲线\n删除
	static CString g_sLangTxt_DeleteCurveTip;
	static CString g_sLangID_ImportCurveTip; //导入特性曲线\n导入
	static CString g_sLangTxt_ImportCurveTip;
	static CString g_sLangID_ExportCurveTip; //导出特性曲线\n导出
	static CString g_sLangTxt_ExportCurveTip;
	static CString g_sLangID_ModifyCurveTip; //修改特性曲线\n修改
	static CString g_sLangTxt_ModifyCurveTip;
	static CString g_sLangID_Style; //样式
	static CString g_sLangTxt_Style;
	static CString g_sLangID_StyleTip1; //修改视觉样式
	static CString g_sLangTxt_StyleTip1;
	static CString g_sLangID_StyleTip2; //选择一个office 2007主题
	static CString g_sLangTxt_StyleTip2;
	static CString g_sLangID_CharCurveSave; //特性曲线库已经被修改，是否保存修改？
	static CString g_sLangTxt_CharCurveSave;
	static CString g_sLangID_Message1; //提示
	static CString g_sLangTxt_Message1;
	static CString g_sLangID_ModifyCharCurve; //修改特性曲线
	static CString g_sLangTxt_ModifyCharCurve;
	static CString g_sLangID_OutPut; //输出
	static CString g_sLangTxt_OutPut;
	static CString g_sLangID_CopyOutPut; //复制输出
	static CString g_sLangTxt_CopyOutPut;
	static CString g_sLangID_ClearOutPut; //清除输出
	static CString g_sLangTxt_ClearOutPut;
	static CString g_sLangID_FatherSame; //父文件夹“%s”存在相同名称的“%s”子文件夹！
	static CString g_sLangTxt_FatherSame;
	static CString g_sLangID_NewCharCurve; //新建特性曲线
	static CString g_sLangTxt_NewCharCurve;
	static CString g_sLangID_UnAddPic; //无法加载位图: %x\n
	static CString g_sLangTxt_UnAddPic;
	static CString g_sLangID_NotReali; //还没有实现
	static CString g_sLangTxt_NotReali;
	static CString g_sLangID_AddMemberFctn; //添加成员函数...
	static CString g_sLangTxt_AddMemberFctn;
	static CString g_sLangID_SureDelElement; //你确实要删除元素“%s”吗？
	static CString g_sLangTxt_SureDelElement;
	static CString g_sLangID_SureDelVarious; //是否删除变量“%s”？
	static CString g_sLangTxt_SureDelVarious;
	static CString g_sLangID_ExistNameCurve; //存在名称为“%s”的曲线
	static CString g_sLangTxt_ExistNameCurve;
	static CString g_sLangID_NewVarious; //新建变量
	static CString g_sLangTxt_NewVarious;
	static CString g_sLangID_DeleteVarious; //删除变量
	static CString g_sLangTxt_DeleteVarious;
	static CString g_sLangID_InportElement; //插入元素
	static CString g_sLangTxt_InportElement;
	static CString g_sLangID_DeleteElement; //删除元素
	static CString g_sLangTxt_DeleteElement;
	static CString g_sLangID_EdgeElementType; 
	static CString g_sLangTxt_EdgeElementType;
	static CString g_sLangID_ErrorBandLength; 
	static CString g_sLangTxt_ErrorBandLength;
	static CString g_sLangID_EdgTestPoints; 
	static CString g_sLangTxt_EdgTestPoints;
	static CString g_sLangID_CharCurveEdge; 
	static CString g_sLangTxt_CharCurveEdge;
	static CString g_sLangID_FolderName; //文件夹名称
	static CString g_sLangTxt_FolderName;
	static CString g_sLangID_CurveMageFolder; //曲线管理文件夹
	static CString g_sLangTxt_CurveMageFolder;

	static CString g_sLangID_CharCurve; //特性曲线
	static CString g_sLangTxt_CharCurve;
	static CString g_sLangID_DecSystem; //笛卡尔坐标系
	static CString g_sLangTxt_DecSystem;
	static CString g_sLangID_PolarSystem; //极坐标系
	static CString g_sLangTxt_PolarSystem;
	static CString g_sLangID_LogSystem; //对数坐标系
	static CString g_sLangTxt_LogSystem;
	static CString g_sLangID_Vertical; //垂线
	static CString g_sLangTxt_Vertical;
	static CString g_sLangID_VerticalLine; //垂直竖线
	static CString g_sLangTxt_VerticalLine;
	static CString g_sLangID_HorizontalLine; //水平横线
	static CString g_sLangTxt_HorizontalLine;
	static CString g_sLangID_SearchLineMode; //搜索线模式
	static CString g_sLangTxt_SearchLineMode;
	static CString g_sLangID_ElementDevelop; //元素开发中.....
	static CString g_sLangTxt_ElementDevelop;
	static CString g_sLangID_ClassView; //类视图
	static CString g_sLangTxt_ClassView;
	static CString g_sLangID_ToolTip_143;//新建文件夹\n新建文件夹
	static CString g_sLangTxt_ToolTip_143;
	static CString g_sLangID_ToolTip_32779;//编辑文件夹\n编辑文件夹
	static CString g_sLangTxt_ToolTip_32779;
	static CString g_sLangID_ToolTip_32780;//删除文件夹\n删除文件夹
	static CString g_sLangTxt_ToolTip_32780;
};

