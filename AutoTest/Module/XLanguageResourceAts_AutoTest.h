#pragma once

#include "../../Module/XLanguage/XLanguageMngr.h"
#include "../Module/XLanguageResourceAts.h"

class CXLanguageResourceAts_AutoTest : public CXLanguageResourceAtsBase
{
// ����
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
	extern CString g_sLangID_AutoTestVTip;//�����Զ�����ϵͳV1.0
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
	extern CString g_sLangTxt_TestInfBar;//����������
	extern CString g_sLangID_SdvMgrpReTest; 
	extern CString g_sLangTxt_SdvMgrpReTest;//����������
	extern CString g_sLangID_CharCurTest; 
	extern CString g_sLangTxt_CharCurTest;//�������߲���
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
	extern CString g_sLangID_NewTestWork; //�½���������
	extern CString g_sLangTxt_NewTestWork;
	extern CString g_sLangID_TestInf; 
	extern CString g_sLangTxt_TestInf;
	extern CString g_sLangID_TaskName; 
	extern CString g_sLangTxt_TaskName;
	extern CString g_sLangID_TestType; 
	extern CString g_sLangTxt_TestType;
	extern CString g_sLangID_ProSet; 
	extern CString g_sLangTxt_ProSet;
	extern CString g_sLangID_ChoProTem; //ѡ���Լģ��
	extern CString g_sLangTxt_ChoProTem;
	extern CString g_sLangID_PoFile; 
	extern CString g_sLangTxt_PoFile;
	extern CString g_sLangID_ChoTest; 
	extern CString g_sLangTxt_ChoTest;
	extern CString g_sLangID_SelPoFile; //ѡ�����ļ�
	extern CString g_sLangTxt_SelPoFile;
	extern CString g_sLangID_TitleTask; 
	extern CString g_sLangTxt_TitleTask;
	extern CString g_sLangID_NewBuilt; //�½�
	extern CString g_sLangTxt_NewBuilt;
	extern CString g_sLangID_ReportAdjSh;//���������ʾ 
	extern CString g_sLangTxt_ReportAdjSh;
	extern CString g_sLangID_TestChoPro;//������ѡ�񣨲�������ѡ��ı䣬�����������Զ����Գ�������Ǹı���Ч�� 
	extern CString g_sLangTxt_TestChoPro;
	extern CString g_sLangID_AutoTestSysSet;//�Զ�����ϵͳ���� 
	extern CString g_sLangTxt_AutoTestSysSet;
	extern CString g_sLangID_AlarmAutoMain;//���桪�Զ����������� 
	extern CString g_sLangTxt_AlarmAutoMain;
	extern CString g_sLangID_TestFileName; //�����ļ���
	extern CString g_sLangTxt_TestFileName;
	extern CString g_sLangID_TesTyp; //��������
	extern CString g_sLangTxt_TesTyp;
	extern CString g_sLangID_ProTypeCho; //��Լ����ѡ��
	extern CString g_sLangTxt_ProTypeCho;
	extern CString g_sLangID_TestTempFile; //����ģ���ļ�
	extern CString g_sLangTxt_TestTempFile;
	extern CString g_sLangID_ProTempFile; //��Լģ���ļ�
	extern CString g_sLangTxt_ProTempFile;
	extern CString g_sLangID_ProHighSet; //��Լ�߼�����
	extern CString g_sLangTxt_ProHighSet;
	extern CString g_sLangID_ProTabFile; //��Լ����ļ�
	extern CString g_sLangTxt_ProTabFile;
	extern CString g_sLangID_RptData; //��������
	extern CString g_sLangTxt_RptData;
	extern CString g_sLangID_RptData2; //��������2
	extern CString g_sLangTxt_RptData2;
	extern CString g_sLangID_RptLog; //��������
	extern CString g_sLangTxt_RptLog;
	extern CString g_sLangID_TestTemp; //����ģ��
	extern CString g_sLangTxt_TestTemp;
	extern CString g_sLangID_AppTestNo; //���ֲ��Բ��ϸ���Ŀ����
	extern CString g_sLangTxt_AppTestNo;
	extern CString g_sLangID_CTestCNum; //�ظ�������Ŀ�ظ�����
	extern CString g_sLangTxt_CTestCNum;
	extern CString g_sLangID_CoeMus; //��ʾ����
	extern CString g_sLangTxt_CoeMus;
	extern CString g_sLangID_AlarmMode; //�澯��ʽ
	extern CString g_sLangTxt_AlarmMode;
	extern CString g_sLangID_ContTest; //��������
	extern CString g_sLangTxt_ContTest;
	extern CString g_sLangID_LongAlarm; //������
	extern CString g_sLangTxt_LongAlarm;
	extern CString g_sLangID_ShortAlarm; //�̾���
	extern CString g_sLangTxt_ShortAlarm;
	extern CString g_sLangID_CusRepeat; //�Զ�������ظ�����
	extern CString g_sLangTxt_CusRepeat;
	extern CString g_sLangID_ComFaReNu; //ͨѶʧ�ܺ����Դ���
	extern CString g_sLangTxt_ComFaReNu;
	extern CString g_sLangID_RetComS; //����ͨѶǰ��ʱ
	extern CString g_sLangTxt_RetComS;
	extern CString g_sLangID_TestCoDe; //������Ŀ������ɳ���
	extern CString g_sLangTxt_TestCoDe;
	extern CString g_sLangID_CoNuShow; //���һ����Ŀʱ������ʾ
	extern CString g_sLangTxt_CoNuShow;
	extern CString g_sLangID_TestCoRe; //������ɣ������Զ�����·��������ģ������á�����
	extern CString g_sLangTxt_TestCoRe;
	extern CString g_sLangID_AdjustReportInfo; //��������������²���
	extern CString g_sLangTxt_AdjustReportInfo;
// 	extern CString g_sLangID_DeNoChTe; //1.ɾ��û��ѡ����Ե���Ŀ���౨�沿��
// 	extern CString g_sLangTxt_DeNoChTe;
// 	extern CString g_sLangID_RepUse; //2.����û�в��ԵĲ��Ե㣬�հײ��ֱ���ʹ�á��������滻
// 	extern CString g_sLangTxt_RepUse;
// 	extern CString g_sLangID_AdjustSure; //�������ֲ����Իظ���ȷ��Ҫ������
// 	extern CString g_sLangTxt_AdjustSure;
	extern CString g_sLangID_StartX; //���X
	extern CString g_sLangTxt_StartX;	
	extern CString g_sLangID_StartY; //���Y
	extern CString g_sLangTxt_StartY;	
	extern CString g_sLangID_NowX; //��ǰX
	extern CString g_sLangTxt_NowX;
	extern CString g_sLangID_NowY; //��ǰY
	extern CString g_sLangTxt_NowY;
	extern CString g_sLangID_EndPointX; //�յ�X
	extern CString g_sLangTxt_EndPointX;
	extern CString g_sLangID_EndPointY; //�յ�Y
	extern CString g_sLangTxt_EndPointY;
	extern CString g_sLangID_TestConR; //������ǿ��ƽӿڳ������֣�30s������ʧ�ܣ�����ֹ���̣��������������ǽӿڳ���
	extern CString g_sLangTxt_TestConR;
	extern CString g_sLangID_WarningProTest; //�����⵽ϵͳ���к�ϵͳ��صĽ����������У��������ֹ���̡��ر����н���
	extern CString g_sLangTxt_WarningProTest;
	extern CString g_sLangID_StopProcess; //��ֹ����
	extern CString g_sLangTxt_StopProcess;
	extern CString g_sLangID_NeedCloPro; //��Ҫ�رյĽ���
	extern CString g_sLangTxt_NeedCloPro;
	extern CString g_sLangID_SouRepPath;      //Դ����·��
	extern CString g_sLangTxt_SouRepPath;
	extern CString g_sLangID_ExportSet;       //��������
	extern CString g_sLangTxt_ExportSet;
	extern CString g_sLangID_ExportPath;      //����·��
	extern CString g_sLangTxt_ExportPath;
	extern CString g_sLangID_ExFileName;      //�����ļ�����
	extern CString g_sLangTxt_ExFileName;
	extern CString g_sLangID_ChoFileModel;    //ѡ���ļ�ģ��
	extern CString g_sLangTxt_ChoFileModel;
	extern CString g_sLangID_RepViewRat;    //������ʾ����
	extern CString g_sLangTxt_RepViewRat;
	extern CString g_sLangID_RepViRaCho;    //������ʾ����ѡ��
	extern CString g_sLangTxt_RepViRaCho;
	extern CString g_sLangID_TestRepViRaSet;    //���鱨����ʾ��������
	extern CString g_sLangTxt_TestRepViRaSet;
	extern CString g_sLangID_NoChProTem;//û��ѡ���Լģ��
	extern CString g_sLangTxt_NoChProTem;
	extern CString g_sLangID_NoChTestTem;//û��ѡ�����ģ��
	extern CString g_sLangTxt_NoChTestTem;
	extern CString g_sLangID_ChTemplet;//ѡ��ģ��
	extern CString g_sLangTxt_ChTemplet;
	extern CString g_sLangID_ChProtocol;//ѡ���Լ
	extern CString g_sLangTxt_ChProtocol;
	extern CString g_sLangID_SettingsChoose;//������ѡ��
	extern CString g_sLangTxt_SettingsChoose;
	extern CString g_sLangID_SetMulDev;//���ö�װ��
	extern CString g_sLangTxt_SetMulDev;
	extern CString g_sLangID_SetMulDevMgrp;//���ö�װ�ö���
	extern CString g_sLangTxt_SetMulDevMgrp;
	extern CString g_sLangID_NoChTemFile;//û��ѡ��ģ���ļ�
	extern CString g_sLangTxt_NoChTemFile;
	extern CString g_sLangID_RepFileNameNu;//�����ļ���Ϊ��
	extern CString g_sLangTxt_RepFileNameNu;
	extern CString g_sLangID_NoChTestType;//û��ѡ���������
	extern CString g_sLangTxt_NoChTestType;
	extern CString g_sLangID_CommSetInf;//ͨѶ������Ϣ��ȫ
	extern CString g_sLangTxt_CommSetInf;
	extern CString g_sLangID_TabFileNoSel;//����ļ�û��ѡ��
	extern CString g_sLangTxt_TabFileNoSel;
	extern CString g_sLangID_AlreadyExists;//%s �Ѿ�����
	extern CString g_sLangTxt_AlreadyExists;
	extern CString g_sLangID_UnquaItem;//���ϸ���Ŀ
	extern CString g_sLangTxt_UnquaItem;
// 	extern CString g_sLangID_ModelFile;//ģ���ļ�
// 	extern CString g_sLangTxt_ModelFile;
	extern CString g_sLangID_NoAddDevTestRep;//û�����װ�ò��Ա���
	extern CString g_sLangTxt_NoAddDevTestRep;
	extern CString g_sLangID_OlAddOnRep;//ֻ�����һ��װ�ò��Ա���
	extern CString g_sLangTxt_OlAddOnRep;
	extern CString g_sLangID_ProtocoTemplate;//��Լģ��
	extern CString g_sLangTxt_ProtocoTemplate;
	extern CString g_sLangID_ProtocoMatching;//��Լ����
	extern CString g_sLangTxt_ProtocoMatching;
	extern CString g_sLangID_ChRptRe;//ѡ�񱨸浼��Ŀ��Ŀ¼
	extern CString g_sLangTxt_ChRptRe;
	extern CString g_sLangID_AlOpen;//�Ѿ��򿪡�%s������رպ��ڴ������Ա��棡
	extern CString g_sLangTxt_AlOpen;
	extern CString g_sLangID_TaskTotalTime;//������ʱ��
	extern CString g_sLangTxt_TaskTotalTime;
	extern CString g_sLangID_RptTotalTime;//������ʱ��
	extern CString g_sLangTxt_RptTotalTime;
	extern CString g_sLangID_NoTitle;//�ޱ���
	extern CString g_sLangTxt_NoTitle;
	extern CString g_sLangID_TestingClose;//���ڲ����У����ܹر�...
	extern CString g_sLangTxt_TestingClose;
	extern CString g_sLangID_FileUnExistS;//�ļ�\"%s\"������
	extern CString g_sLangTxt_FileUnExistS;
	extern CString g_sLangID_SelOrCretFile;//�ļ��С�%s�������в��Ա����ļ�\n��ѡ����ߴ���һ���յ��ļ���
	extern CString g_sLangTxt_SelOrCretFile;
	extern CString g_sLangID_SelFilePath;//��ѡ�񱨸��ļ��洢��·����
	extern CString g_sLangTxt_SelFilePath;
	extern CString g_sLangID_DelTaskYOrN;//�Ƿ�Ҫɾ������ %s ��������
	extern CString g_sLangTxt_DelTaskYOrN;
	extern CString g_sLangID_SureDelAgain;//���ٴ�ȷ��ɾ��
	extern CString g_sLangTxt_SureDelAgain;
	extern CString g_sLangID_DelFailItem;//ɾ���������а����Ѿ����򿪵Ĺ��̣�ɾ��ʧ��
	extern CString g_sLangTxt_DelFailItem;
	extern CString g_sLangID_DelItemYOrN;//�Ƿ�Ҫɾ������ %s
	extern CString g_sLangTxt_DelItemYOrN;
	extern CString g_sLangID_DelFailure;//�ù����Ѿ����򿪣�ɾ��ʧ��
	extern CString g_sLangTxt_DelFailure;
	extern CString g_sLangID_StartRptYOrN;//����ʼ���桱����ֻ���Ե�ǰ�򿪵Ĳ��Ա��棬\r\n��ȷʵֻҪ���Բ��������еĵ������Ա�����\r\n\r\nѡ���ǡ����Ե�������\r\nѡ�񡰷񡱿�ʼ�������\r\nѡ��ȡ������ֹ����")
	extern CString g_sLangTxt_StartRptYOrN;
	extern CString g_sLangID_NewTestClear;//�½����ԣ������ǰ����������\r\n
	extern CString g_sLangTxt_NewTestClear;
	extern CString g_sLangID_SelYes;//ѡ���ǡ������ǰ�������ݣ��½�����\r\n
	extern CString g_sLangTxt_SelYes;
	extern CString g_sLangID_SelNo;//ѡ�񡰷񡱣��������ǰ�������ݣ��½�����\r\n
	extern CString g_sLangTxt_SelNo;
	extern CString g_sLangID_SelCancel;//ѡ��ȡ����������ʼ����
	extern CString g_sLangTxt_SelCancel;
	extern CString g_sLangID_WavCpntNotExist;//¼�����������
	extern CString g_sLangTxt_WavCpntNotExist;
	extern CString g_sLangID_UnAutoTest;//û�������Զ����ԣ��޷�ִ������
	extern CString g_sLangTxt_UnAutoTest;
	extern CString g_sLangID_ToolUnExitS;//���ߡ�%s����%s��������
	extern CString g_sLangTxt_ToolUnExitS;
	extern CString g_sLangID_TestTaskFnshS;//��������%s���������
	extern CString g_sLangTxt_TestTaskFnshS;
	extern CString g_sLangID_StartTestS;//��ʼ���ԡ�%s��
	extern CString g_sLangTxt_StartTestS;
	extern CString g_sLangID_TestTempS;//����ģ��*******%s
	extern CString g_sLangTxt_TestTempS;
	extern CString g_sLangID_ReportFileS;//�����ļ�*******%s
	extern CString g_sLangTxt_ReportFileS;
	extern CString g_sLangID_ModelFileS;//ģ���ļ�********%s
	extern CString g_sLangTxt_ModelFileS;
	extern CString g_sLangID_PrtcTemS;//��Լģ��********%s
	extern CString g_sLangTxt_PrtcTemS;
	extern CString g_sLangID_AutoTestContrl;//�Զ����Կ�������
	extern CString g_sLangTxt_AutoTestContrl;
// 	extern CString g_sLangID_SGroupS;//%s%s-��%d.%s
// 	extern CString g_sLangTxt_SGroupS;
// 	extern CString g_sLangID_SGroupFileName;//%s%s-��%d.%s
// 	extern CString g_sLangTxt_SGroupFileName;
	extern CString g_sLangID_RightBuy;//Demo�汾��ֻ��ʹ��ģ�塾Demo-PSL-641U�����빺����ʽ�汾��
	extern CString g_sLangTxt_RightBuy;
	extern CString g_sLangID_MainView2;//����ͼ:
	extern CString g_sLangTxt_MainView2;
	extern CString g_sLangID_GroupReport;//��%d����
	extern CString g_sLangTxt_GroupReport;
	extern CString g_sLangID_ProcessStop;//�Ͳ�����صĽ����Ѿ�����ֹ
	extern CString g_sLangTxt_ProcessStop;
	extern CString g_sLangID_SelObjPath;//ѡ��Ŀ��·��
	extern CString g_sLangTxt_SelObjPath;
	extern CString g_sLangID_FileNameIncl;//�ļ����ư����Ƿ��ַ�: %s
	extern CString g_sLangTxt_FileNameIncl;
	extern CString g_sLangID_ReportEptFinsh;//���浼�����
	extern CString g_sLangTxt_ReportEptFinsh;
	extern CString g_sLangID_ObjFileExistOvwt;//Ŀ���ļ��Ѿ�����,������?
	extern CString g_sLangTxt_ObjFileExistOvwt;
	extern CString g_sLangID_ReportTestTempt;//���桾%s����Ӧ�Ĳ���ģ��:��%s��
	extern CString g_sLangTxt_ReportTestTempt;
	extern CString g_sLangID_SureToDele;//��ȷʵҪɾ����%s����
	extern CString g_sLangTxt_SureToDele;
	extern CString g_sLangID_UnQualifadS;//[%s]���ϸ�
	extern CString g_sLangTxt_UnQualifadS;
	extern CString g_sLangID_TestOver;//********���Խ���********
	extern CString g_sLangTxt_TestOver;
	extern CString g_sLangID_CopyOutput;//�������
	extern CString g_sLangTxt_CopyOutput;
	extern CString g_sLangID_ClearOutput;//������
	extern CString g_sLangTxt_ClearOutput;
// 	extern CString g_sLangID_Unqualified2;//%s[���ϸ�]
// 	extern CString g_sLangTxt_Unqualified2;
	extern CString g_sLangID_NoAddTestRpt;//û����Ӳ��Ա���
	extern CString g_sLangTxt_NoAddTestRpt;
	extern CString g_sLangID_OneTestRpt;//ֻ�����һ�����Ա���
	extern CString g_sLangTxt_OneTestRpt;
	extern CString g_sLangID_NoSelPrtcTem;//װ�ñ����б�ڡ�%d��û��ѡ���Լģ��
	extern CString g_sLangTxt_NoSelPrtcTem;
	extern CString g_sLangID_NoSelFile;//װ�ñ����б�ڡ�%d��û��ѡ�����ļ�
	extern CString g_sLangTxt_NoSelFile;
	extern CString g_sLangID_NameSame;//װ�ñ����б�ڡ�%d����ڡ�%d�����ơ�%s����ͬ
	extern CString g_sLangTxt_NameSame;
	extern CString g_sLangID_PrtcSame;//װ�ñ����б�ڡ�%d����ڡ�%d����Լģ�塾%s����ͬ
	extern CString g_sLangTxt_PrtcSame;
	extern CString g_sLangID_IPSame;//װ�ñ����б�ڡ�%d����ڡ�%d��IP��%s����ͬ
	extern CString g_sLangTxt_IPSame;
	extern CString g_sLangID_ToolTip_32781;//�򿪱���
	extern CString g_sLangTxt_ToolTip_32781;
	extern CString g_sLangID_ToolTip_32776;//��ӱ���
	extern CString g_sLangTxt_ToolTip_32776;
	extern CString g_sLangID_ToolTip_32777;//ɾ������
	extern CString g_sLangTxt_ToolTip_32777;
	extern CString g_sLangID_ToolTip_32783;//�ָ���δ��ɵ�״̬
	extern CString g_sLangTxt_ToolTip_32783;
	extern CString g_sLangID_ToolTip_32778;//���Ʊ���
    extern CString g_sLangTxt_ToolTip_32778;
	extern CString g_sLangID_ToolTip_32779;//���Ʊ���
	extern CString g_sLangTxt_ToolTip_32779;
	extern CString g_sLangID_ToolTip_32784;//��ʾ�����Ӧ��ģ��
	extern CString g_sLangTxt_ToolTip_32784;
	extern CString g_sLangID_ToolTip_32775;//�������񱨸�
	extern CString g_sLangTxt_ToolTip_32775;
	extern CString g_sLangID_ToolTip_32782;//�ر�����
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
