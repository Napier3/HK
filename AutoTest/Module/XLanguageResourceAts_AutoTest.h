#pragma once

#include "../../Module/XLanguage/XLanguageMngr.h"
#include "../Module/XLanguageResourceAts.h"

class CXLanguageResourceAts_AutoTest : public CXLanguageResourceAtsBase
{
// 构造
public:
	CXLanguageResourceAts_AutoTest();
	virtual ~CXLanguageResourceAts_AutoTest();
	
private:
	CXLanguage m_oXLangRsAutoTest;

public:
	CXLangItem* rs_AddString(const CString &strID, CString *pstrString);	

	virtual void InitLangRsByFile();
	virtual void RegisterLanguageResource();

	//2023-3-1  lijunqing
	virtual void InitLangTxt();

};

	extern CString  g_strXLangRsAutoTestFile;
	extern CString g_sLangID_AutoTestVTip;//智能自动测试系统V1.0
	extern CString g_sLangTxt_AutoTestVTip;
// 	extern CString g_sLangID_FileOpen; 
// 	extern CString g_sLangTxt_FileOpen;
	extern CString g_sLangID_FileOpenTip; 
	extern CString g_sLangTxt_FileOpenTip;
	extern CString g_sLangID_Quit; 
	extern CString g_sLangTxt_Quit;
	extern CString g_sLangID_QuitTip; 
	extern CString g_sLangTxt_QuitTip;
	extern CString g_sLangID_RibbonRecentDocs; 
	extern CString g_sLangTxt_RibbonRecentDocs;
	extern CString g_sLangID_Config; 
	extern CString g_sLangTxt_Config;
	extern CString g_sLangID_AutoTestOper; 
	extern CString g_sLangTxt_AutoTestOper;
// 	extern CString g_sLangID_UpLoad; 
// 	extern CString g_sLangTxt_UpLoad;
// 	extern CString g_sLangID_DownLoad; 
// 	extern CString g_sLangTxt_DownLoad;
	extern CString g_sLangID_NewTest; 
	extern CString g_sLangTxt_NewTest;
	extern CString g_sLangID_MultiDevTest; 
	extern CString g_sLangTxt_MultiDevTest;
	extern CString g_sLangID_SinDevMulPro; 
	extern CString g_sLangTxt_SinDevMulPro;
	extern CString g_sLangID_MdvMgrpTest; 
	extern CString g_sLangTxt_MdvMgrpTest;
	extern CString g_sLangID_SubTempTest; 
	extern CString g_sLangTxt_SubTempTest;
	extern CString g_sLangID_SingleDevTest;
	extern CString g_sLangTxt_SingleDevTest;
	extern CString g_sLangID_UsePowerTestTemplate;
	extern CString g_sLangTxt_UsePowerTestTemplate;
	extern CString g_sLangID_Test;
	extern CString g_sLangTxt_Test; 
    extern CString g_sLangID_StartTest; 
	extern CString g_sLangTxt_StartTest;
	extern CString g_sLangID_StartReport;
	extern CString g_sLangTxt_StartReport;	
	extern CString g_sLangID_Stop; 
	extern CString g_sLangTxt_Stop;
	extern CString g_sLangID_Report; 
	extern CString g_sLangTxt_Report;
	extern CString g_sLangID_ShowScale; 
	extern CString g_sLangTxt_ShowScale;
	extern CString g_sLangID_AdReport; 
	extern CString g_sLangTxt_AdReport;
	extern CString g_sLangID_PrintReport; 
	extern CString g_sLangTxt_PrintReport;
	extern CString g_sLangID_Settings; 
	extern CString g_sLangTxt_Settings;	
	extern CString g_sLangID_ReConfig; 
	extern CString g_sLangTxt_ReConfig;
// 	extern CString g_sLangID_View; 
// 	extern CString g_sLangTxt_View;	
// 	extern CString g_sLangID_StatusBarTip; 
// 	extern CString g_sLangTxt_StatusBarTip;
	extern CString g_sLangID_OutpWind; 
	extern CString g_sLangTxt_OutpWind;
	extern CString g_sLangID_FileManBar; 
	extern CString g_sLangTxt_FileManBar;
	extern CString g_sLangID_TestInfBar; 
	extern CString g_sLangTxt_TestInfBar;//测试任务栏
	extern CString g_sLangID_SdvMgrpReTest; 
	extern CString g_sLangTxt_SdvMgrpReTest;//测试任务栏
	extern CString g_sLangID_CharCurTest; 
	extern CString g_sLangTxt_CharCurTest;//特性曲线测试
	extern CString g_sLangID_TestTaskBar;
	extern CString g_sLangTxt_TestTaskBar;
	extern CString g_sLangID_ShowTestInf; 
	extern CString g_sLangTxt_ShowTestInf;
	extern CString g_sLangID_ShowTestSpyWnd; 
	extern CString g_sLangTxt_ShowTestSpyWnd;
	extern CString g_sLangID_WriteLogFile; 
	extern CString g_sLangTxt_WriteLogFile;
	extern CString g_sLangID_ViewWordRpt; 
	extern CString g_sLangTxt_ViewWordRpt;
// 	extern CString g_sLangID_AboutTip; 
	extern CString g_sLangTxt_AboutTip;
	extern CString g_sLangID_ToAndCom; 
	extern CString g_sLangTxt_ToAndCom;
	extern CString g_sLangID_SysTools; 
	extern CString g_sLangTxt_SysTools;
	extern CString g_sLangID_SysCom; 
	extern CString g_sLangTxt_SysCom;
	extern CString g_sLangID_TestFileMan; 
	extern CString g_sLangTxt_TestFileMan;
	extern CString g_sLangID_TestItemField; 
	extern CString g_sLangTxt_TestItemField;
	extern CString g_sLangID_NewTestWork; //新建测试任务
	extern CString g_sLangTxt_NewTestWork;
	extern CString g_sLangID_TestInf; 
	extern CString g_sLangTxt_TestInf;
	extern CString g_sLangID_TaskName; 
	extern CString g_sLangTxt_TaskName;
	extern CString g_sLangID_TestType; 
	extern CString g_sLangTxt_TestType;
	extern CString g_sLangID_ProSet; 
	extern CString g_sLangTxt_ProSet;
	extern CString g_sLangID_ChoProTem; //选择规约模板
	extern CString g_sLangTxt_ChoProTem;
	extern CString g_sLangID_PoFile; 
	extern CString g_sLangTxt_PoFile;
	extern CString g_sLangID_ChoTest; 
	extern CString g_sLangTxt_ChoTest;
	extern CString g_sLangID_SelPoFile; //选择点表文件
	extern CString g_sLangTxt_SelPoFile;
	extern CString g_sLangID_TitleTask; 
	extern CString g_sLangTxt_TitleTask;
	extern CString g_sLangID_NewBuilt; //新建
	extern CString g_sLangTxt_NewBuilt;
	extern CString g_sLangID_ReportAdjSh;//报告调整提示 
	extern CString g_sLangTxt_ReportAdjSh;
	extern CString g_sLangID_TestChoPro;//测试仪选择（测试仪器选择改变，需重新启动自动测试程序才能是改变生效） 
	extern CString g_sLangTxt_TestChoPro;
	extern CString g_sLangID_AutoTestSysSet;//自动测试系统配置 
	extern CString g_sLangTxt_AutoTestSysSet;
	extern CString g_sLangID_AlarmAutoMain;//警告—自动测试主程序 
	extern CString g_sLangTxt_AlarmAutoMain;
	extern CString g_sLangID_TestFileName; //测试文件名
	extern CString g_sLangTxt_TestFileName;
	extern CString g_sLangID_TesTyp; //测试类型
	extern CString g_sLangTxt_TesTyp;
	extern CString g_sLangID_ProTypeCho; //规约种类选择
	extern CString g_sLangTxt_ProTypeCho;
	extern CString g_sLangID_TestTempFile; //测试模板文件
	extern CString g_sLangTxt_TestTempFile;
	extern CString g_sLangID_ProTempFile; //规约模板文件
	extern CString g_sLangTxt_ProTempFile;
	extern CString g_sLangID_ProHighSet; //规约高级设置
	extern CString g_sLangTxt_ProHighSet;
	extern CString g_sLangID_ProTabFile; //规约点表文件
	extern CString g_sLangTxt_ProTabFile;
	extern CString g_sLangID_RptData; //报告数据
	extern CString g_sLangTxt_RptData;
	extern CString g_sLangID_RptData2; //报告数据2
	extern CString g_sLangTxt_RptData2;
	extern CString g_sLangID_RptLog; //报告数据
	extern CString g_sLangTxt_RptLog;
	extern CString g_sLangID_TestTemp; //测试模板
	extern CString g_sLangTxt_TestTemp;
	extern CString g_sLangID_AppTestNo; //出现测试不合格项目处理
	extern CString g_sLangTxt_AppTestNo;
	extern CString g_sLangID_CTestCNum; //重复测试项目重复次数
	extern CString g_sLangTxt_CTestCNum;
	extern CString g_sLangID_CoeMus; //提示音乐
	extern CString g_sLangTxt_CoeMus;
	extern CString g_sLangID_AlarmMode; //告警方式
	extern CString g_sLangTxt_AlarmMode;
	extern CString g_sLangID_ContTest; //继续测试
	extern CString g_sLangTxt_ContTest;
	extern CString g_sLangID_LongAlarm; //长警告
	extern CString g_sLangTxt_LongAlarm;
	extern CString g_sLangID_ShortAlarm; //短警告
	extern CString g_sLangTxt_ShortAlarm;
	extern CString g_sLangID_CusRepeat; //自定义最大重复次数
	extern CString g_sLangTxt_CusRepeat;
	extern CString g_sLangID_ComFaReNu; //通讯失败后重试次数
	extern CString g_sLangTxt_ComFaReNu;
	extern CString g_sLangID_RetComS; //重试通讯前延时
	extern CString g_sLangTxt_RetComS;
	extern CString g_sLangID_TestCoDe; //测试项目测试完成出来
	extern CString g_sLangTxt_TestCoDe;
	extern CString g_sLangID_CoNuShow; //完成一级项目时进行提示
	extern CString g_sLangTxt_CoNuShow;
	extern CString g_sLangID_TestCoRe; //测试完成，报告自动导出路径（测试模板须调用……）
	extern CString g_sLangTxt_TestCoRe;
	extern CString g_sLangID_AdjustReportInfo; //调整报告完成如下操作
	extern CString g_sLangTxt_AdjustReportInfo;
// 	extern CString g_sLangID_DeNoChTe; //1.删除没有选择测试的项目分类报告部分
// 	extern CString g_sLangTxt_DeNoChTe;
// 	extern CString g_sLangID_RepUse; //2.对于没有测试的测试点，空白部分报告使用“——”替换
// 	extern CString g_sLangTxt_RepUse;
// 	extern CString g_sLangID_AdjustSure; //调整部分不可以回复，确定要调整吗？
// 	extern CString g_sLangTxt_AdjustSure;
	extern CString g_sLangID_StartX; //起点X
	extern CString g_sLangTxt_StartX;	
	extern CString g_sLangID_StartY; //起点Y
	extern CString g_sLangTxt_StartY;	
	extern CString g_sLangID_NowX; //当前X
	extern CString g_sLangTxt_NowX;
	extern CString g_sLangID_NowY; //当前Y
	extern CString g_sLangTxt_NowY;
	extern CString g_sLangID_EndPointX; //终点X
	extern CString g_sLangTxt_EndPointX;
	extern CString g_sLangID_EndPointY; //终点Y
	extern CString g_sLangTxt_EndPointY;
	extern CString g_sLangID_TestConR; //与测试仪控制接口程序握手，30s内握手失败，则终止进程，重新启动测试仪接口程序
	extern CString g_sLangTxt_TestConR;
	extern CString g_sLangID_WarningProTest; //程序检测到系统中有和系统相关的进程正在运行，点击“终止进程”关闭所有进程
	extern CString g_sLangTxt_WarningProTest;
	extern CString g_sLangID_StopProcess; //终止进程
	extern CString g_sLangTxt_StopProcess;
	extern CString g_sLangID_NeedCloPro; //需要关闭的进程
	extern CString g_sLangTxt_NeedCloPro;
	extern CString g_sLangID_SouRepPath;      //源报告路径
	extern CString g_sLangTxt_SouRepPath;
	extern CString g_sLangID_ExportSet;       //导出设置
	extern CString g_sLangTxt_ExportSet;
	extern CString g_sLangID_ExportPath;      //导出路径
	extern CString g_sLangTxt_ExportPath;
	extern CString g_sLangID_ExFileName;      //导出文件名称
	extern CString g_sLangTxt_ExFileName;
	extern CString g_sLangID_ChoFileModel;    //选择文件模型
	extern CString g_sLangTxt_ChoFileModel;
	extern CString g_sLangID_RepViewRat;    //报告显示比例
	extern CString g_sLangTxt_RepViewRat;
	extern CString g_sLangID_RepViRaCho;    //报告显示比例选择
	extern CString g_sLangTxt_RepViRaCho;
	extern CString g_sLangID_TestRepViRaSet;    //试验报告显示比例设置
	extern CString g_sLangTxt_TestRepViRaSet;
	extern CString g_sLangID_NoChProTem;//没有选择规约模板
	extern CString g_sLangTxt_NoChProTem;
	extern CString g_sLangID_NoChTestTem;//没有选择测试模板
	extern CString g_sLangTxt_NoChTestTem;
	extern CString g_sLangID_ChTemplet;//选择模板
	extern CString g_sLangTxt_ChTemplet;
	extern CString g_sLangID_ChProtocol;//选择规约
	extern CString g_sLangTxt_ChProtocol;
	extern CString g_sLangID_SettingsChoose;//设置组选择
	extern CString g_sLangTxt_SettingsChoose;
	extern CString g_sLangID_SetMulDev;//设置多装置
	extern CString g_sLangTxt_SetMulDev;
	extern CString g_sLangID_SetMulDevMgrp;//设置多装置多组
	extern CString g_sLangTxt_SetMulDevMgrp;
	extern CString g_sLangID_NoChTemFile;//没有选择模板文件
	extern CString g_sLangTxt_NoChTemFile;
	extern CString g_sLangID_RepFileNameNu;//报告文件名为空
	extern CString g_sLangTxt_RepFileNameNu;
	extern CString g_sLangID_NoChTestType;//没有选择测试类型
	extern CString g_sLangTxt_NoChTestType;
	extern CString g_sLangID_CommSetInf;//通讯设置信息不全
	extern CString g_sLangTxt_CommSetInf;
	extern CString g_sLangID_TabFileNoSel;//点表文件没有选择
	extern CString g_sLangTxt_TabFileNoSel;
	extern CString g_sLangID_AlreadyExists;//%s 已经存在
	extern CString g_sLangTxt_AlreadyExists;
	extern CString g_sLangID_UnquaItem;//不合格项目
	extern CString g_sLangTxt_UnquaItem;
// 	extern CString g_sLangID_ModelFile;//模型文件
// 	extern CString g_sLangTxt_ModelFile;
	extern CString g_sLangID_NoAddDevTestRep;//没有添加装置测试报告
	extern CString g_sLangTxt_NoAddDevTestRep;
	extern CString g_sLangID_OlAddOnRep;//只添加了一个装置测试报告
	extern CString g_sLangTxt_OlAddOnRep;
	extern CString g_sLangID_ProtocoTemplate;//规约模板
	extern CString g_sLangTxt_ProtocoTemplate;
	extern CString g_sLangID_ProtocoMatching;//规约配型
	extern CString g_sLangTxt_ProtocoMatching;
	extern CString g_sLangID_ChRptRe;//选择报告导出目标目录
	extern CString g_sLangTxt_ChRptRe;
	extern CString g_sLangID_AlOpen;//已经打开【%s】，请关闭后在创建测试报告！
	extern CString g_sLangTxt_AlOpen;
	extern CString g_sLangID_TaskTotalTime;//任务总时间
	extern CString g_sLangTxt_TaskTotalTime;
	extern CString g_sLangID_RptTotalTime;//报告总时间
	extern CString g_sLangTxt_RptTotalTime;
	extern CString g_sLangID_NoTitle;//无标题
	extern CString g_sLangTxt_NoTitle;
	extern CString g_sLangID_TestingClose;//正在测试中，不能关闭...
	extern CString g_sLangTxt_TestingClose;
	extern CString g_sLangID_FileUnExistS;//文件\"%s\"不存在
	extern CString g_sLangTxt_FileUnExistS;
	extern CString g_sLangID_SelOrCretFile;//文件夹【%s】包含有测试报告文件\n请选择或者创建一个空的文件夹
	extern CString g_sLangTxt_SelOrCretFile;
	extern CString g_sLangID_SelFilePath;//请选择报告文件存储的路径！
	extern CString g_sLangTxt_SelFilePath;
	extern CString g_sLangID_DelTaskYOrN;//是否要删除任务 %s 及其子项
	extern CString g_sLangTxt_DelTaskYOrN;
	extern CString g_sLangID_SureDelAgain;//请再次确定删除
	extern CString g_sLangTxt_SureDelAgain;
	extern CString g_sLangID_DelFailItem;//删除的任务中包含已经被打开的工程，删除失败
	extern CString g_sLangTxt_DelFailItem;
	extern CString g_sLangID_DelItemYOrN;//是否要删除工程 %s
	extern CString g_sLangTxt_DelItemYOrN;
	extern CString g_sLangID_DelFailure;//该工程已经被打开，删除失败
	extern CString g_sLangTxt_DelFailure;
	extern CString g_sLangID_StartRptYOrN;//“开始报告”功能只测试当前打开的测试报告，\r\n你确实只要测试测试任务中的单个测试报告吗？\r\n\r\n选择“是”测试单个报告\r\n选择“否”开始任务测试\r\n选择“取消”终止操作")
	extern CString g_sLangTxt_StartRptYOrN;
	extern CString g_sLangID_NewTestClear;//新建测试，清除当前报告数据吗？\r\n
	extern CString g_sLangTxt_NewTestClear;
	extern CString g_sLangID_SelYes;//选择“是”清除当前报告数据，新建测试\r\n
	extern CString g_sLangTxt_SelYes;
	extern CString g_sLangID_SelNo;//选择“否”，不清除当前报告数据，新建测试\r\n
	extern CString g_sLangTxt_SelNo;
	extern CString g_sLangID_SelCancel;//选择“取消”，不开始测试
	extern CString g_sLangTxt_SelCancel;
	extern CString g_sLangID_WavCpntNotExist;//录波组件不存在
	extern CString g_sLangTxt_WavCpntNotExist;
	extern CString g_sLangID_UnAutoTest;//没有启动自动测试，无法执行命令
	extern CString g_sLangTxt_UnAutoTest;
	extern CString g_sLangID_ToolUnExitS;//工具【%s】【%s】不存在
	extern CString g_sLangTxt_ToolUnExitS;
	extern CString g_sLangID_TestTaskFnshS;//测试任务【%s】测试完成
	extern CString g_sLangTxt_TestTaskFnshS;
	extern CString g_sLangID_StartTestS;//开始测试【%s】
	extern CString g_sLangTxt_StartTestS;
	extern CString g_sLangID_TestTempS;//测试模板*******%s
	extern CString g_sLangTxt_TestTempS;
	extern CString g_sLangID_ReportFileS;//报告文件*******%s
	extern CString g_sLangTxt_ReportFileS;
	extern CString g_sLangID_ModelFileS;//模型文件********%s
	extern CString g_sLangTxt_ModelFileS;
	extern CString g_sLangID_PrtcTemS;//规约模板********%s
	extern CString g_sLangTxt_PrtcTemS;
	extern CString g_sLangID_AutoTestContrl;//自动测试控制中心
	extern CString g_sLangTxt_AutoTestContrl;
// 	extern CString g_sLangID_SGroupS;//%s%s-组%d.%s
// 	extern CString g_sLangTxt_SGroupS;
// 	extern CString g_sLangID_SGroupFileName;//%s%s-组%d.%s
// 	extern CString g_sLangTxt_SGroupFileName;
	extern CString g_sLangID_RightBuy;//Demo版本，只能使用模板【Demo-PSL-641U】，请购买正式版本！
	extern CString g_sLangTxt_RightBuy;
	extern CString g_sLangID_MainView2;//主视图:
	extern CString g_sLangTxt_MainView2;
	extern CString g_sLangID_GroupReport;//组%d报告
	extern CString g_sLangTxt_GroupReport;
	extern CString g_sLangID_ProcessStop;//和测试相关的进程已经被终止
	extern CString g_sLangTxt_ProcessStop;
	extern CString g_sLangID_SelObjPath;//选择目标路径
	extern CString g_sLangTxt_SelObjPath;
	extern CString g_sLangID_FileNameIncl;//文件名称包含非法字符: %s
	extern CString g_sLangTxt_FileNameIncl;
	extern CString g_sLangID_ReportEptFinsh;//报告导出完成
	extern CString g_sLangTxt_ReportEptFinsh;
	extern CString g_sLangID_ObjFileExistOvwt;//目标文件已经存在,覆盖吗?
	extern CString g_sLangTxt_ObjFileExistOvwt;
	extern CString g_sLangID_ReportTestTempt;//报告【%s】对应的测试模板:【%s】
	extern CString g_sLangTxt_ReportTestTempt;
	extern CString g_sLangID_SureToDele;//你确实要删除【%s】吗？
	extern CString g_sLangTxt_SureToDele;
	extern CString g_sLangID_UnQualifadS;//[%s]不合格
	extern CString g_sLangTxt_UnQualifadS;
	extern CString g_sLangID_TestOver;//********测试结束********
	extern CString g_sLangTxt_TestOver;
	extern CString g_sLangID_CopyOutput;//复制输出
	extern CString g_sLangTxt_CopyOutput;
	extern CString g_sLangID_ClearOutput;//清除输出
	extern CString g_sLangTxt_ClearOutput;
// 	extern CString g_sLangID_Unqualified2;//%s[不合格]
// 	extern CString g_sLangTxt_Unqualified2;
	extern CString g_sLangID_NoAddTestRpt;//没有添加测试报告
	extern CString g_sLangTxt_NoAddTestRpt;
	extern CString g_sLangID_OneTestRpt;//只添加了一个测试报告
	extern CString g_sLangTxt_OneTestRpt;
	extern CString g_sLangID_NoSelPrtcTem;//装置报告列表第【%d】没有选择规约模板
	extern CString g_sLangTxt_NoSelPrtcTem;
	extern CString g_sLangID_NoSelFile;//装置报告列表第【%d】没有选择点表文件
	extern CString g_sLangTxt_NoSelFile;
	extern CString g_sLangID_NameSame;//装置报告列表第【%d】与第【%d】名称【%s】相同
	extern CString g_sLangTxt_NameSame;
	extern CString g_sLangID_PrtcSame;//装置报告列表第【%d】与第【%d】规约模板【%s】相同
	extern CString g_sLangTxt_PrtcSame;
	extern CString g_sLangID_IPSame;//装置报告列表第【%d】与第【%d】IP【%s】相同
	extern CString g_sLangTxt_IPSame;
	extern CString g_sLangID_ToolTip_32781;//打开报告
	extern CString g_sLangTxt_ToolTip_32781;
	extern CString g_sLangID_ToolTip_32776;//添加报告
	extern CString g_sLangTxt_ToolTip_32776;
	extern CString g_sLangID_ToolTip_32777;//删除报告
	extern CString g_sLangTxt_ToolTip_32777;
	extern CString g_sLangID_ToolTip_32783;//恢复到未完成的状态
	extern CString g_sLangTxt_ToolTip_32783;
	extern CString g_sLangID_ToolTip_32778;//上移报告
    extern CString g_sLangTxt_ToolTip_32778;
	extern CString g_sLangID_ToolTip_32779;//下移报告
	extern CString g_sLangTxt_ToolTip_32779;
	extern CString g_sLangID_ToolTip_32784;//显示报告对应的模板
	extern CString g_sLangTxt_ToolTip_32784;
	extern CString g_sLangID_ToolTip_32775;//导出任务报告
	extern CString g_sLangTxt_ToolTip_32775;
	extern CString g_sLangID_ToolTip_32782;//关闭任务
	extern CString g_sLangTxt_ToolTip_32782;

	extern CString g_sLangID_Menu_57634;
	extern CString g_sLangTxt_Menu_57634;
	extern CString g_sLangID_Menu_57632;
	extern CString g_sLangTxt_Menu_57632;

	extern CString g_sLangID_ToolTip_32789;
	extern CString g_sLangTxt_ToolTip_32789;
	extern CString g_sLangID_StitchRptFinish;
	extern CString g_sLangTxt_StitchRptFinish;

	//2016-12-10
	extern CString g_sLangID_ToolTip_2000;
	extern CString g_sLangTxt_ToolTip_2000;
	extern CString g_sLangID_ToolTip_32786;
	extern CString g_sLangTxt_ToolTip_32786;
	extern CString g_sLangID_ToolTip_32788;
	extern CString g_sLangTxt_ToolTip_32788;
	extern CString g_sLangID_ToolTip_2001;
	extern CString g_sLangTxt_ToolTip_2001;
	extern CString g_sLangID_ToolTip_32785;
	extern CString g_sLangTxt_ToolTip_32785;
	extern CString g_sLangID_ToolTip_351;
	extern CString g_sLangTxt_ToolTip_351;
	extern CString g_sLangID_ToolTip_314;
	extern CString g_sLangTxt_ToolTip_314;
	extern CString g_sLangID_ToolTip_320;
	extern CString g_sLangTxt_ToolTip_320;
	extern CString g_sLangID_ToolTip_330;
	extern CString g_sLangTxt_ToolTip_330;
	extern CString g_sLangID_ToolTip_358;
	extern CString g_sLangTxt_ToolTip_358;
	extern CString g_sLangID_ToolTip_347;
	extern CString g_sLangTxt_ToolTip_347;
	extern CString g_sLangID_ToolTip_310;
	extern CString g_sLangTxt_ToolTip_310;
	extern CString g_sLangID_ToolTip_348;
	extern CString g_sLangTxt_ToolTip_348;
	extern CString g_sLangID_ToolTip_349;
	extern CString g_sLangTxt_ToolTip_349;
	extern CString g_sLangID_ToolTip_350;
	extern CString g_sLangTxt_ToolTip_350;
	extern CString g_sLangID_ToolTip_357;
	extern CString g_sLangTxt_ToolTip_357;
