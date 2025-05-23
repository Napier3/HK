#include "stdafx.h"
#include "XLangResource_Native.h"

CString g_strXLangRs_Test = _T("Lang_NativeTest");

CXLangResource_Native::CXLangResource_Native()
{
	m_pXLangRsExe = &m_oXLangRs_Test;
	m_oXLangRs_Test.m_strID = g_strXLangRs_Test;
	m_oXLangRs_Test.m_strName = g_strXLangRs_Test;
}

CXLangResource_Native::~CXLangResource_Native()
{
	m_oXLangRs_Test.RemoveAll();
}


CXLangItem* CXLangResource_Native::rs_AddString(const CString &strID, CString *pstrString)
{
	CXLangItem *p = CXLanguage::AddString(strID, pstrString);

	m_oXLangRs_Test.AddTail(p);

	return p;
}


void CXLangResource_Native::InitLangRsByFile()
{
	CXLanguageResourceAtsBase::InitLangRsByFile();

	InitLangRsByFileEx(&m_oXLangRs_Test, g_strXLangRs_Test);
}



void CXLangResource_Native::RegisterLanguageResource()
{
	CXLanguageResourceAtsBase::RegisterLanguageResource();
	rs_AddString(g_sLangID_Native_Amplitude, &g_sLangTxt_Native_Amplitude);
	rs_AddString(g_sLangID_Native_Phase, &g_sLangTxt_Native_Phase);
	rs_AddString(g_sLangID_Native_Freq, &g_sLangTxt_Native_Freq);
// 	rs_AddString(g_sLangID_Native_Unit, &g_sLangTxt_Native_Unit);
	rs_AddString(g_sLangID_Native_Channel, &g_sLangTxt_Native_Channel);
	rs_AddString(g_sLangID_Native_Validity, &g_sLangTxt_Native_Validity);
	rs_AddString(g_sLangID_Native_Overhaul, &g_sLangTxt_Native_Overhaul);
	rs_AddString(g_sLangID_Native_DC, &g_sLangTxt_Native_DC);
	rs_AddString(g_sLangID_Native_Fundamental, &g_sLangTxt_Native_Fundamental);
	rs_AddString(g_sLangID_Harm_Set, &g_sLangTxt_Harm_Set);
	rs_AddString(g_sLangID_Harm_Content, &g_sLangTxt_Harm_Content);
	rs_AddString(g_sLangID_Harm_Enable, &g_sLangTxt_Harm_Enable);
	rs_AddString(g_sLangID_Harm_UChannel, &g_sLangTxt_Harm_UChannel);
	rs_AddString(g_sLangID_Harm_IChannel, &g_sLangTxt_Harm_IChannel);
	rs_AddString(g_sLangID_Harm_UAllSelect, &g_sLangTxt_Harm_UAllSelect);
	rs_AddString(g_sLangID_Harm_IAllSelect, &g_sLangTxt_Harm_IAllSelect);
	rs_AddString(g_sLangID_Harm_UClear, &g_sLangTxt_Harm_UClear);
	rs_AddString(g_sLangID_Harm_IClear, &g_sLangTxt_Harm_IClear);


	rs_AddString(g_sLangID_Harm_Reset, &g_sLangTxt_Harm_Reset);
	rs_AddString(g_sLangID_Harm_FundFreq, &g_sLangTxt_Harm_FundFreq);
	rs_AddString(g_sLangID_Harm_Times, &g_sLangTxt_Harm_Times);
	rs_AddString(g_sLangID_Harm_InterHarm, &g_sLangTxt_Harm_InterHarm);

	rs_AddString(g_sLangID_Native_SelectTestFunction, &g_sLangTxt_Native_SelectTestFunction);
	rs_AddString(g_sLangID_Native_ReportHeadSet, &g_sLangTxt_Native_ReportHeadSet);

	rs_AddString(g_sLangID_Native_GndA, &g_sLangTxt_Native_GndA);
	rs_AddString(g_sLangID_Native_GndB, &g_sLangTxt_Native_GndB);
	rs_AddString(g_sLangID_Native_GndC, &g_sLangTxt_Native_GndC);
	rs_AddString(g_sLangID_Native_ShortAB, &g_sLangTxt_Native_ShortAB);
	rs_AddString(g_sLangID_Native_ShortBC, &g_sLangTxt_Native_ShortBC);
	rs_AddString(g_sLangID_Native_ShortCA, &g_sLangTxt_Native_ShortCA);
	rs_AddString(g_sLangID_Native_GndShortAB, &g_sLangTxt_Native_GndShortAB);
	rs_AddString(g_sLangID_Native_GndShortBC, &g_sLangTxt_Native_GndShortBC);
	rs_AddString(g_sLangID_Native_GndShortCA, &g_sLangTxt_Native_GndShortCA);
	rs_AddString(g_sLangID_Native_ShortABC, &g_sLangTxt_Native_ShortABC);
	rs_AddString(g_sLangID_Native_SinglePhase, &g_sLangTxt_Native_SinglePhase);
	rs_AddString(g_sLangID_Native_INotChange, &g_sLangTxt_Native_INotChange);
	rs_AddString(g_sLangID_Native_UNotChange, &g_sLangTxt_Native_UNotChange);
	rs_AddString(g_sLangID_Native_ZNotChange, &g_sLangTxt_Native_ZNotChange);	
	rs_AddString(g_sLangID_Native_UZoomOut, &g_sLangTxt_Native_UZoomOut);
	rs_AddString(g_sLangID_Native_UZoomIn, &g_sLangTxt_Native_UZoomIn);
	rs_AddString(g_sLangID_Native_IZoomOut, &g_sLangTxt_Native_IZoomOut);
	rs_AddString(g_sLangID_Native_IZoomIn, &g_sLangTxt_Native_IZoomIn);
	rs_AddString(g_sLangID_Native_PhaseO, &g_sLangTxt_Native_PhaseO);
	rs_AddString(g_sLangID_Native_Relay, &g_sLangTxt_Native_Relay);
	rs_AddString(g_sLangID_Native_Measure, &g_sLangTxt_Native_Measure);
	rs_AddString(g_sLangID_Native_Current, &g_sLangTxt_Native_Current);
	rs_AddString(g_sLangID_Native_Voltage, &g_sLangTxt_Native_Voltage);
	rs_AddString(g_sLangID_Native_EDPhaseV, &g_sLangTxt_Native_EDPhaseV);
	rs_AddString(g_sLangID_Native_EDCurrent, &g_sLangTxt_Native_EDCurrent);
	rs_AddString(g_sLangID_Native_EqualAmp, &g_sLangTxt_Native_EqualAmp);
	rs_AddString(g_sLangID_Native_EqualFreq, &g_sLangTxt_Native_EqualFreq);
	rs_AddString(g_sLangID_Native_PositiveSeq, &g_sLangTxt_Native_PositiveSeq);
	rs_AddString(g_sLangID_Native_NegativeSeq, &g_sLangTxt_Native_NegativeSeq);
	rs_AddString(g_sLangID_Native_ZeroSeq, &g_sLangTxt_Native_ZeroSeq);
	rs_AddString(g_sLangID_Native_Zero, &g_sLangTxt_Native_Zero);
	rs_AddString(g_sLangID_Native_AllGroup, &g_sLangTxt_Native_AllGroup);
	rs_AddString(g_sLangID_Native_CurGroup, &g_sLangTxt_Native_CurGroup);
	rs_AddString(g_sLangID_Native_LastGroup, &g_sLangTxt_Natve_LastGroup);
	rs_AddString(g_sLangID_Native_NextGroup, &g_sLangTxt_Natve_NextGroup);
	rs_AddString(g_sLangID_Native_ExBinSet, &g_sLangTxt_Native_ExBinSet);
	rs_AddString(g_sLangID_Native_ExBoutSet, &g_sLangTxt_Native_ExBoutSet);
	rs_AddString(g_sLangID_Native_GooseDataSet, &g_sLangTxt_Native_GooseDataSet);
	rs_AddString(g_sLangID_Native_GooseOutSet, &g_sLangTxt_Native_GooseOutSet);
	rs_AddString(g_sLangID_Native_GooseInSet, &g_sLangTxt_Native_GooseInSet);
	rs_AddString(g_sLangID_Native_Bin, &g_sLangTxt_Native_Bin);
	rs_AddString(g_sLangID_Native_Bout, &g_sLangTxt_Native_Bout);
	rs_AddString(g_sLangID_Native_BinX, &g_sLangTxt_Native_BinX);
	rs_AddString(g_sLangID_Native_BoutX, &g_sLangTxt_Native_BoutX);
	rs_AddString(g_sLangID_Native_BinEx, &g_sLangTxt_Native_BinEx);
	rs_AddString(g_sLangID_Native_BoutEx, &g_sLangTxt_Native_BoutEx);
	rs_AddString(g_sLangID_Native_ActType, &g_sLangTxt_Native_ActType);
	rs_AddString(g_sLangID_Native_ActionTime, &g_sLangTxt_Native_ActionTime);
	rs_AddString(g_sLangID_Native_ReturnVal, &g_sLangTxt_Native_ReturnVal);
	rs_AddString(g_sLangID_Native_ReturnCoeff, &g_sLangTxt_Native_ReturnCoeff);
	rs_AddString(g_sLangID_Native_CurTypeIdx, &g_sLangTxt_Native_CurTypeIdx);
	rs_AddString(g_sLangID_Native_Group, &g_sLangTxt_Native_Group);
	rs_AddString(g_sLangID_Native_LangSetting, &g_sLangTxt_Native_LangSetting);
	rs_AddString(g_sLangID_Native_CustomSetup, &g_sLangTxt_Native_CustomSetup);
	rs_AddString(g_sLangID_Native_LangTipContext, &g_sLangTxt_Native_LangTipContext);
	rs_AddString(g_sLangID_Native_Reverse, &g_sLangTxt_Native_Reverse);
	rs_AddString(g_sLangID_Native_Repair, &g_sLangTxt_Native_Repair);
	rs_AddString(g_sLangID_Native_Revert, &g_sLangTxt_Native_Revert);
	rs_AddString(g_sLangID_Native_IEDName, &g_sLangTxt_Native_IEDName);
	rs_AddString(g_sLangID_Native_APPID, &g_sLangTxt_Native_APPID);
	rs_AddString(g_sLangID_Native_Type,&g_sLangTxt_Native_Type);
	rs_AddString(g_sLangID_Native_LogicOr, &g_sLangTxt_Native_LogicOr);
	rs_AddString(g_sLangID_Native_LogicAnd, &g_sLangTxt_Native_LogicAnd);
	rs_AddString(g_sLangID_Native_Enter, &g_sLangTxt_Native_Enter);	
	rs_AddString(g_sLangID_Native_Group, &g_sLangTxt_Native_Group);
	rs_AddString(g_sLangID_Native_Caps, &g_sLangTxt_Native_Caps);
	rs_AddString(g_sLangID_Native_Space, &g_sLangTxt_Native_Space);
	rs_AddString(g_sLangID_Native_Maps, &g_sLangTxt_Native_Maps);
	rs_AddString(g_sLangID_Native_Chs, &g_sLangTxt_Native_Chs);
	rs_AddString(g_sLangID_Native_Eng, &g_sLangTxt_Native_Eng);

	rs_AddString(g_sLangID_Native_ConnectingTester, &g_sLangTxt_Native_ConnectingTester);
	rs_AddString(g_sLangID_Native_TesterConnectSucc, &g_sLangTxt_Native_TesterConnectSucc);
	rs_AddString(g_sLangID_Native_TesterConnectfail, &g_sLangTxt_Native_TesterConnectfail);
	rs_AddString(g_sLangID_Native_LCSTSendportSTGigabit, &g_sLangTxt_Native_LCSTSendportSTGigabit);

	rs_AddString(g_sLangID_Native_FileFolder, &g_sLangTxt_Native_FileFolder);
	rs_AddString(g_sLangID_Native_NoTimeSync, &g_sLangTxt_Native_NoTimeSync);
	rs_AddString(g_sLangID_Native_AllFreq, &g_sLangTxt_Native_AllFreq);
	rs_AddString(g_sLangID_Native_FileType, &g_sLangTxt_Native_FileType);
	rs_AddString(g_sLangID_Native_SCLPath, &g_sLangTxt_Native_SCLPath);
	rs_AddString(g_sLangID_Native_SCLFilter, &g_sLangTxt_Native_SCLFilter);
	rs_AddString(g_sLangID_Native_ResultJudge, &g_sLangTxt_Native_ResultJudge);
	rs_AddString(g_sLangID_Native_ResultDescript, &g_sLangTxt_Native_ResultDescript);
	rs_AddString(g_sLangID_Native_ResultTime, &g_sLangTxt_Native_ResultTime);
	rs_AddString(g_sLangID_Native_ResultAbsRsltCal1, &g_sLangTxt_Native_ResultAbsRsltCal1);
	rs_AddString(g_sLangID_Native_ResultAbsRsltCal2, &g_sLangTxt_Native_ResultAbsRsltCal2);
	rs_AddString(g_sLangID_Native_ResultRelRsltCal1, &g_sLangTxt_Native_ResultRelRsltCal1);
	rs_AddString(g_sLangID_Native_ResultRelRsltCal2, &g_sLangTxt_Native_ResultRelRsltCal2);
	rs_AddString(g_sLangID_Native_TimeSettingCoef, &g_sLangTxt_Native_TimeSettingCoef);

	rs_AddString(g_sLangID_Manual_IV, &g_sLangTxt_Manual_IV);
	rs_AddString(g_sLangID_Manual_OtherParam, &g_sLangTxt_Manual_OtherParam);
	rs_AddString(g_sLangID_Manual_GlobalParam, &g_sLangTxt_Manual_GlobalParam);
	rs_AddString(g_sLangID_Manual_Oscillogram,&g_sLangTxt_Manual_Oscillogram);
	rs_AddString(g_sLangID_Manual_Changing, &g_sLangTxt_Manual_Changing);
	rs_AddString(g_sLangID_Manual_InitVal, &g_sLangTxt_Manual_InitVal);
	rs_AddString(g_sLangID_Manual_ChangeType, &g_sLangTxt_Manual_ChangeType);
	rs_AddString(g_sLangID_Manual_Channel, &g_sLangTxt_Manual_Channel);
	rs_AddString(g_sLangID_Manual_FinishVal, &g_sLangTxt_Manual_FinishVal);
	rs_AddString(g_sLangID_Manual_Step, &g_sLangTxt_Manual_Step);
	rs_AddString(g_sLangID_Manual_Timer, &g_sLangTxt_Manual_Timer);
	rs_AddString(g_sLangID_Manual_Old, &g_sLangTxt_Manual_Old);
	rs_AddString(g_sLangID_Manual_Auto, &g_sLangTxt_Manual_Auto);
	rs_AddString(g_sLangID_Manual_Delayed, &g_sLangTxt_Manual_Delayed);
	rs_AddString(g_sLangID_Manual_OutSetting, &g_sLangTxt_Manual_OutSetting);
	rs_AddString(g_sLangID_Manual_Out1, &g_sLangTxt_Manual_Out1);
	rs_AddString(g_sLangID_Manual_Out2, &g_sLangTxt_Manual_Out2);
	rs_AddString(g_sLangID_Manual_Out3, &g_sLangTxt_Manual_Out3);
	rs_AddString(g_sLangID_Manual_Out4, &g_sLangTxt_Manual_Out4);
	rs_AddString(g_sLangID_Manual_Out5, &g_sLangTxt_Manual_Out5);
	rs_AddString(g_sLangID_Manual_Out6, &g_sLangTxt_Manual_Out6);
	rs_AddString(g_sLangID_Manual_Out7, &g_sLangTxt_Manual_Out7);
	rs_AddString(g_sLangID_Manual_Out8, &g_sLangTxt_Manual_Out8);
	rs_AddString(g_sLangID_Manual_InSetting, &g_sLangTxt_Manual_InSetting);
	rs_AddString(g_sLangID_Manual_InA, &g_sLangTxt_Manual_InA);
	rs_AddString(g_sLangID_Manual_InB, &g_sLangTxt_Manual_InB);
	rs_AddString(g_sLangID_Manual_InC, &g_sLangTxt_Manual_InC);
	rs_AddString(g_sLangID_Manual_InD, &g_sLangTxt_Manual_InD);
	rs_AddString(g_sLangID_Manual_InE, &g_sLangTxt_Manual_InE);
	rs_AddString(g_sLangID_Manual_InF, &g_sLangTxt_Manual_InF);
	rs_AddString(g_sLangID_Manual_InG, &g_sLangTxt_Manual_InG);
	rs_AddString(g_sLangID_Manual_InH, &g_sLangTxt_Manual_InH);
	rs_AddString(g_sLangID_Manual_Lock, &g_sLangTxt_Manual_Lock);
	rs_AddString(g_sLangID_Manual_UnLock, &g_sLangTxt_Manual_UnLock);
	rs_AddString(g_sLangID_Native_Action, &g_sLangTxt_Native_Action);
	rs_AddString(g_sLangID_Manual_ActionTime, &g_sLangTxt_Manual_ActionTime);
	rs_AddString(g_sLangID_Manual_ReturnTime, &g_sLangTxt_Manual_ReturnTime);
	rs_AddString(g_sLangID_Manual_S_E, &g_sLangTxt_Manual_S_E);
	rs_AddString(g_sLangID_Manual_S_E_S, &g_sLangTxt_Manual_S_E_S);

	rs_AddString(g_sLangID_Manual_Harm, &g_sLangTxt_Manual_Harm);
	rs_AddString(g_sLangID_Manual_TestMethod, &g_sLangTxt_Manual_TestMethod);
	rs_AddString(g_sLangID_Manual_MeasType, &g_sLangTxt_Manual_MeasType);
	rs_AddString(g_sLangID_Manual_BCode, &g_sLangTxt_Manual_BCode);
	rs_AddString(g_sLangID_Manual_TestReport, &g_sLangTxt_Manual_TestReport);
	rs_AddString(g_sLangID_Manual_TestTime, &g_sLangTxt_Manual_TestTime);
	rs_AddString(g_sLangID_Manual_PositiveLogic, &g_sLangTxt_Manual_PositiveLogic);
	rs_AddString(g_sLangID_Manual_NegativeLogic, &g_sLangTxt_Manual_NegativeLogic);
	rs_AddString(g_sLangID_Manual_SyncSet, &g_sLangTxt_Manual_SyncSet);
	rs_AddString(g_sLangID_Manual_SecSyncStatus, &g_sLangTxt_Manual_SecSyncStatus);
	rs_AddString(g_sLangID_Manual_OpenSecSync, &g_sLangTxt_Manual_OpenSecSync);
	rs_AddString(g_sLangID_Manual_CloseSecSync, &g_sLangTxt_Manual_CloseSecSync);
	rs_AddString(g_sLangID_Manual_IEC1588Sync, &g_sLangTxt_Manual_IEC1588Sync);
	rs_AddString(g_sLangID_Manual_PeerDelay, &g_sLangTxt_Manual_PeerDelay);
	rs_AddString(g_sLangID_Manual_DelayRequestReply, &g_sLangTxt_Manual_DelayRequestReply);
	rs_AddString(g_sLangID_Manual_Refresh, &g_sLangTxt_Manual_Refresh);

	rs_AddString(g_sLangID_ErrorSet, &g_sLangTxt_ErrorSet);
	rs_AddString(g_sLangID_CurAbsError, &g_sLangTxt_CurAbsError);
	rs_AddString(g_sLangID_CurRelError, &g_sLangTxt_CurRelError);
	rs_AddString(g_sLangID_VolAbsError, &g_sLangTxt_VolAbsError);
	rs_AddString(g_sLangID_VolRelError, &g_sLangTxt_VolRelError);
	rs_AddString(g_sLangID_ImpAbsError, &g_sLangTxt_ImpAbsError);
	rs_AddString(g_sLangID_ImpRelError, &g_sLangTxt_ImpRelError);
	rs_AddString(g_sLangID_TimeAbsError, &g_sLangTxt_TimeAbsError);
	rs_AddString(g_sLangID_TimeRelError, &g_sLangTxt_TimeRelError);
	rs_AddString(g_sLangID_AngError, &g_sLangTxt_AngError);
	rs_AddString(g_sLangID_FreqError, &g_sLangTxt_FreqError);
	rs_AddString(g_sLangID_DvDtError, &g_sLangTxt_DvDtError);
	rs_AddString(g_sLangID_DfDtError, &g_sLangTxt_DfDtError);
	rs_AddString(g_sLangID_DiffHarmCoefAbsError, &g_sLangTxt_DiffHarmCoefAbsError);
	rs_AddString(g_sLangID_DiffHarmCoefRelError, &g_sLangTxt_DiffHarmCoefRelError);
	rs_AddString(g_sLangID_DiffRateCoefAbsError, &g_sLangTxt_DiffRateCoefAbsError);
	rs_AddString(g_sLangID_DiffRateCoefRelError, &g_sLangTxt_DiffRateCoefRelError);

	rs_AddString(g_sLangID_State_TrigerSetup, &g_sLangTxt_State_TrigerSetup);
	rs_AddString(g_sLangID_State_TrigerCondition, &g_sLangTxt_State_TrigerCondition);
	rs_AddString(g_sLangID_State_OutTime, &g_sLangTxt_State_OutTime);
	rs_AddString(g_sLangID_State_TrigerTime, &g_sLangTxt_State_TrigerTime);
	rs_AddString(g_sLangID_State_Hour, &g_sLangTxt_State_Hour);
	rs_AddString(g_sLangID_State_Minute, &g_sLangTxt_State_Minute);
	rs_AddString(g_sLangID_State_Second, &g_sLangTxt_State_Second);
	rs_AddString(g_sLangID_State_TrigerHoldTime, &g_sLangTxt_State_TrigerHoldTime);
	rs_AddString(g_sLangID_State_HoldTime, &g_sLangTxt_State_HoldTime);
	rs_AddString(g_sLangID_State_ShortCalc, &g_sLangTxt_State_ShortCalc);
	rs_AddString(g_sLangID_State_GradientSet, &g_sLangTxt_State_GradientSet);
	rs_AddString(g_sLangID_State_PasteStateBf, &g_sLangTxt_State_PasteStateBf);
	rs_AddString(g_sLangID_State_InsertStateBf, &g_sLangTxt_State_InsertStateBf);
	rs_AddString(g_sLangID_State_InsertStateAf, &g_sLangTxt_State_InsertStateAf);
	rs_AddString(g_sLangID_State_PasteStateAf, &g_sLangTxt_State_PasteStateAf);
	rs_AddString(g_sLangID_State_CopyCurState, &g_sLangTxt_State_CopyCurState);
	rs_AddString(g_sLangID_State_DeleteCurState, &g_sLangTxt_State_DeleteCurState);
	rs_AddString(g_sLangID_State_UISet, &g_sLangTxt_State_UISet);
	rs_AddString(g_sLangID_State_StateParaSet, &g_sLangTxt_State_StateParaSet);
	rs_AddString(g_sLangID_State_JudgeCondition, &g_sLangTxt_State_JudgeCondition);
	rs_AddString(g_sLangID_State_DCOffSet, &g_sLangTxt_State_DCOffSet);
	rs_AddString(g_sLangID_State_Tou, &g_sLangTxt_State_Tou);
	rs_AddString(g_sLangID_State_StackByState, &g_sLangTxt_State_StackByState);
	rs_AddString(g_sLangID_State_RepeatTimes, &g_sLangTxt_State_RepeatTimes);
	rs_AddString(g_sLangID_State_ChGroup, &g_sLangTxt_State_ChGroup);
	rs_AddString(g_sLangID_Abnormal_APPID, &g_sLangTxt_Abnormal_APPID);
	rs_AddString(g_sLangID_State_FaultType, &g_sLangTxt_State_FaultType);
	rs_AddString(g_sLangID_State_CalcMode, &g_sLangTxt_State_CalcMode);
	rs_AddString(g_sLangID_State_ShortI, &g_sLangTxt_State_ShortI);
	rs_AddString(g_sLangID_State_ShortU, &g_sLangTxt_State_ShortU);
	rs_AddString(g_sLangID_State_ZeroCoeff, &g_sLangTxt_State_ZeroCoeff);
	rs_AddString(g_sLangID_State_CalcType, &g_sLangTxt_State_CalcType);
	rs_AddString(g_sLangID_State_Amp, &g_sLangTxt_State_Amp);
	rs_AddString(g_sLangID_State_Angle, &g_sLangTxt_State_Angle);
	rs_AddString(g_sLangID_State_Lsbalancefactor, &g_sLangTxt_State_Lsbalancefactor);
	rs_AddString(g_sLangID_LoadI, &g_sLangTxt_LoadI);
	rs_AddString(g_sLangID_State_BFtransformer, &g_sLangTxt_State_BFtransformer);
	rs_AddString(g_sLangID_State_NotconWindconnection, &g_sLangTxt_State_NotconWindconnection);
	rs_AddString(g_sLangID_State_Triangulationcorrection, &g_sLangTxt_State_Triangulationcorrection);

	rs_AddString(g_sLangID_State_LoadAngle, &g_sLangTxt_State_LoadAngle);
	rs_AddString(g_sLangID_State_Trigger_Time, &g_sLangTxt_State_Trigger_Time);
	rs_AddString(g_sLangID_State_Lswindwirtype, &g_sLangTxt_State_Lswindwirtype);
	rs_AddString(g_sLangID_State_Trigger_TimeAndBin, &g_sLangTxt_State_Trigger_TimeAndBin);
	rs_AddString(g_sLangID_State_Trigger_Bin, &g_sLangTxt_State_Trigger_Bin);
	rs_AddString(g_sLangID_State_Trigger_Manu, &g_sLangTxt_State_Trigger_Manu);
	rs_AddString(g_sLangID_State_Trigger_GPSB, &g_sLangTxt_State_Trigger_GPSB);
	rs_AddString(g_sLangID_State_LinearChange, &g_sLangTxt_State_LinearChange);
	rs_AddString(g_sLangID_State_FirHVoltageSide, &g_sLangTxt_State_FirHVoltageSide);
	rs_AddString(g_sLangID_State_StepChange, &g_sLangTxt_State_StepChange);
	rs_AddString(g_sLangID_State_StepTime, &g_sLangTxt_State_StepTime);
	rs_AddString(g_sLangID_State_BeginVal, &g_sLangTxt_State_BeginVal);
	rs_AddString(g_sLangID_State_EndVal, &g_sLangTxt_State_EndVal);
	rs_AddString(g_sLangID_State_BrakCurrentA, &g_sLangTxt_State_BrakCurrentA);
	rs_AddString(g_sLangID_State_Testphase, &g_sLangTxt_State_Testphase);
	rs_AddString(g_sLangID_State_OFtransformer, &g_sLangTxt_State_OFtransformer);
	rs_AddString(g_sLangID_State_Hswindwirtype, &g_sLangTxt_State_Hswindwirtype);
	rs_AddString(g_sLangID_State_Hsbalancefactor, &g_sLangTxt_State_Hsbalancefactor);
	rs_AddString(g_sLangID_State_Bfactorcalculation, &g_sLangTxt_State_Bfactorcalculation);
	rs_AddString(g_sLangID_State_SecHVoltageSide, &g_sLangTxt_State_SecHVoltageSide);
	rs_AddString(g_sLangID_State_AmpGradient, &g_sLangTxt_State_AmpGradient);
	rs_AddString(g_sLangID_State_FreqGradient, &g_sLangTxt_State_FreqGradient);
	rs_AddString(g_sLangID_State_LastState, &g_sLangTxt_State_LastState);
	rs_AddString(g_sLangID_State_FirstState, &g_sLangTxt_State_FirstState);
	rs_AddString(g_sLangID_State_ConWindconnection, &g_sLangTxt_State_ConWindconnection);
	rs_AddString(g_sLangID_State_Oclock, &g_sLangTxt_State_Oclock);
	rs_AddString(g_sLangID_State_HbdiffAngularwind, &g_sLangTxt_State_HbdiffAngularwind);
 	rs_AddString(g_sLangID_State_No, &g_sLangTxt_State_No);   //sun
 	rs_AddString(g_sLangID_State_Yes, &g_sLangTxt_State_Yes); //sun
	rs_AddString(g_sLangID_State_Correctionselection, &g_sLangTxt_State_Correctionselection);
	rs_AddString(g_sLangID_State_Bequation, &g_sLangTxt_State_Bequation);
	rs_AddString(g_sLangID_State_CTpolarity, &g_sLangTxt_State_CTpolarity);
	rs_AddString(g_sLangID_State_Difflowcalculation, &g_sLangTxt_State_Difflowcalculation);
	rs_AddString(g_sLangID_State_DiffCurrentA, &g_sLangTxt_State_DiffCurrentA);
	rs_AddString(g_sLangID_State_HarmCount, &g_sLangTxt_State_HarmCount);
	rs_AddString(g_sLangID_State_Trans1, &g_sLangTxt_State_Trans1);
	rs_AddString(g_sLangID_State_Trans2, &g_sLangTxt_State_Trans2);
	rs_AddString(g_sLangID_State_Winding, &g_sLangTxt_State_Winding);
	rs_AddString(g_sLangID_State_NoAdjust, &g_sLangTxt_State_NoAdjust);
	rs_AddString(g_sLangID_State_YAdjust, &g_sLangTxt_State_YAdjust);

	rs_AddString(g_sLangID_State_SettingValue, &g_sLangTxt_State_SettingValue);
	rs_AddString(g_sLangID_State_Estimate, &g_sLangTxt_State_Estimate);
	rs_AddString(g_sLangID_State_InState, &g_sLangTxt_State_InState);

	rs_AddString(g_sLangID_StateEstimate_Start, &g_sLangTxt_StateEstimate_State);
	rs_AddString(g_sLangID_StateEstimate_End, &g_sLangTxt_StateEstimate_End);
	rs_AddString(g_sLangID_StateEstimate_ErrorType, &g_sLangTxt_StateEstimate_ErrorType);
	rs_AddString(g_sLangID_StateEstimate_RelError, &g_sLangTxt_StateEstimate_RelError);
	rs_AddString(g_sLangID_StateEstimate_AbsError, &g_sLangTxt_StateEstimate_AbsError);
	rs_AddString(g_sLangID_StateEstimate_SettingValue, &g_sLangTxt_StateEstimate_SettingValue);
	rs_AddString(g_sLangID_StateEstimate_BinTrigger, &g_sLangTxt_StateEstimate_BinTrigger);
	rs_AddString(g_sLangID_StateEstimate_CombinationError, &g_sLangTxt_StateEstimate_CombinationError);
	rs_AddString(g_sLangID_StateEstimate_ResultEstimate, &g_sLangTxt_StateEstimate_ResultEstimate);

	rs_AddString(g_sLangID_State_Sysgenerated, &g_sLangTxt_State_Sysgenerated);								  // 系统生成  LCQ
	rs_AddString(g_sLangID_State_StatusEdition, &g_sLangTxt_State_StatusEdition);							  // 状态编辑LCQ
	rs_AddString(g_sLangID_State_HarmonicAmpInc, &g_sLangTxt_State_HarmonicAmpInc);							  // 谐波按幅值递变LCQ
	rs_AddString(g_sLangID_State_HarmonicAmpPer, &g_sLangTxt_State_HarmonicAmpPer);							  // 谐波按百分比递变LCQ
	rs_AddString(g_sLangID_State_PreviosState, &g_sLangTxt_State_PreviosState);								  // 上一状态LCQ
	rs_AddString(g_sLangID_State_NextState, &g_sLangTxt_State_NextState);									  // 下一状态LCQ
	rs_AddString(g_sLangID_Gradient_Npchannelgroupset, &g_sLangTxt_Gradient_Npchannelgroupset);				  // 非递变通道分组设置LCQ
	rs_AddString(g_sLangID_Gradient_Groupset, &g_sLangTxt_Gradient_Groupset);								  // 分组设置LCQ
	rs_AddString(g_sLangID_State_12Oclock, &g_sLangTxt_State_12Oclock);										  // 十二点LCQ
	rs_AddString(g_sLangID_Manual_FirGroup, &g_sLangTxt_Manual_FirGroup);									  // 第1组LCQ
	rs_AddString(g_sLangID_State_Test, &g_sLangTxt_State_Test);												  // 测试
	rs_AddString(g_sLangID_State_Description, &g_sLangTxt_State_Description);								  // 描述
	rs_AddString(g_sLangID_State_Statusname, &g_sLangTxt_State_Statusname);									  // 状态名
	rs_AddString(g_sLangID_State_FGBlueNetworkcar, &g_sLangTxt_State_FGBlueNetworkcar);						  // 4G、蓝牙、网卡使能
	rs_AddString(g_sLangID_State_Bluetooth, &g_sLangTxt_State_Bluetooth);									  // 蓝牙
	rs_AddString(g_sLangID_State_Wirelesscard, &g_sLangTxt_State_Wirelesscard);								  // 无线网卡
	rs_AddString(g_sLangID_State_NativeNetworkcard, &g_sLangTxt_State_NativeNetworkcard);					  // 本机网卡
	rs_AddString(g_sLangID_State_MinScreenBright, &g_sLangTxt_State_MinScreenBright);						  // 屏幕亮度(1-5)
	rs_AddString(g_sLangID_State_NoteFivemeansBrightest, &g_sLangTxt_State_NoteFivemeansBrightest);			  // 备注:5代表最亮
	rs_AddString(g_sLangID_State_MinBacklighttime, &g_sLangTxt_State_MinBacklighttime);						  // 背光时间(分钟)
	rs_AddString(g_sLangID_State_NoteZeromeansAlwayson, &g_sLangTxt_State_NoteZeromeansAlwayson);			  // 备注:0代表常亮
	rs_AddString(g_sLangID_State_FanMode, &g_sLangTxt_State_FanMode);										  // 机器散热风扇模式
	rs_AddString(g_sLangID_State_Normal, &g_sLangTxt_State_Normal);											  // 正常
	rs_AddString(g_sLangID_State_Mute, &g_sLangTxt_State_Mute);												  // 静音
	rs_AddString(g_sLangID_State_Timezonesetting, &g_sLangTxt_State_Timezonesetting);						  // 时区设置
	rs_AddString(g_sLangID_State_Othersettings, &g_sLangTxt_State_Othersettings);							  // 其它设置
	rs_AddString(g_sLangID_State_Datavalue, &g_sLangTxt_State_Datavalue);									  // 数据值
	rs_AddString(g_sLangID_State_AuxiliaryDCSettings, &g_sLangTxt_State_AuxiliaryDCSettings);				  // 辅助直流设置
	rs_AddString(g_sLangID_State_Others, &g_sLangTxt_State_Others);											  // 其它
	rs_AddString(g_sLangID_State_Voltagevalue, &g_sLangTxt_State_Voltagevalue);								  // 电压值(V):
	rs_AddString(g_sLangID_Gradient_Pleaselaterithasstarted, &g_sLangTxt_Gradient_Pleaselaterithasstarted);	  //"请稍后,已开始"
	rs_AddString(g_sLangID_State_Scanlinesegments, &g_sLangTxt_State_Scanlinesegments);						  // 扫描线段
	rs_AddString(g_sLangID_State_Testpoints, &g_sLangTxt_State_Testpoints);									  // 测试点
	rs_AddString(g_sLangID_State_Iecurrent, &g_sLangTxt_State_Iecurrent);									  // 电流(Ie)
	rs_AddString(g_sLangID_State_Acurrent, &g_sLangTxt_State_Acurrent);										  // 电流(A)
	rs_AddString(g_sLangID_State_Harmonicwave, &g_sLangTxt_State_Harmonicwave);								  // 谐波
	rs_AddString(g_sLangID_State_Interpolation, &g_sLangTxt_State_Interpolation);							  // 插值法
	rs_AddString(g_sLangID_State_Synchronousmethod, &g_sLangTxt_State_Synchronousmethod);					  // 同步法
	rs_AddString(g_sLangID_State_TestLogic, &g_sLangTxt_State_TestLogic);									  // 测试逻辑
	rs_AddString(g_sLangID_State_Risingedgeeffective, &g_sLangTxt_State_Risingedgeeffective);				  // 上升沿有效
	rs_AddString(g_sLangID_State_Downedgeeffective, &g_sLangTxt_State_Downedgeeffective);					  // 下降沿有效
	rs_AddString(g_sLangID_State_NOPPS, &g_sLangTxt_State_NOPPS);											  // 无PPS
	rs_AddString(g_sLangID_State_PPSsettings, &g_sLangTxt_State_PPSsettings);								  // PPS设置
	rs_AddString(g_sLangID_State_UsNoPPSdelaycompensation, &g_sLangTxt_State_UsNoPPSdelaycompensation);		  // 无PPS延时补偿(μs)
	rs_AddString(g_sLangID_State_SSyncduration, &g_sLangTxt_State_SSyncduration);							  // 同步时长(s):
	rs_AddString(g_sLangID_State_UsCurrenterror, &g_sLangTxt_State_UsCurrenterror);							  // 当前误差(μs):
	rs_AddString(g_sLangID_State_UsMaximumerror, &g_sLangTxt_State_UsMaximumerror);							  // 最大误差(μs):
	rs_AddString(g_sLangID_State_UsMinimumerror, &g_sLangTxt_State_UsMinimumerror);							  // 最小误差(μs):
	rs_AddString(g_sLangID_State_Remark, &g_sLangTxt_State_Remark);											  // 备注
	rs_AddString(g_sLangID_State_SPunctuality, &g_sLangTxt_State_SPunctuality);								  // 守时时长(s):
	rs_AddString(g_sLangID_State_Genexperfile, &g_sLangTxt_State_Genexperfile);								  // 通用试验模板文件
	rs_AddString(g_sLangID_State_Gooseexfile, &g_sLangTxt_State_Gooseexfile);								  // Goose异常模拟模板文件
	rs_AddString(g_sLangID_State_GOOSEmessageparameters, &g_sLangTxt_State_GOOSEmessageparameters);			  // GOOSE报文参数
	rs_AddString(g_sLangID_State_IlleInputCharac, &g_sLangTxt_State_IlleInputCharac);						  // 输入值含有非法字符
	rs_AddString(g_sLangID_State_Dropframes, &g_sLangTxt_State_Dropframes);									  // 丢帧
	rs_AddString(g_sLangID_State_Flypoint, &g_sLangTxt_State_Flypoint);										  // 飞点
	rs_AddString(g_sLangID_State_Dithering, &g_sLangTxt_State_Dithering);									  // 抖动
	rs_AddString(g_sLangID_State_OutofOrder, &g_sLangTxt_State_OutofOrder);									  // 错序
	rs_AddString(g_sLangID_State_VoltageandCurrent, &g_sLangTxt_State_VoltageandCurrent);					  // 电压电流
	rs_AddString(g_sLangID_State_StateSequencefile, &g_sLangTxt_State_StateSequencefile);					  // 状态序列模板文件
	rs_AddString(g_sLangID_State_SVexceptionSimulation, &g_sLangTxt_State_SVexceptionSimulation);			  // 异常模拟
	rs_AddString(g_sLangID_State_NumnotExceed, &g_sLangTxt_State_NumnotExceed);								  // 状态数目不能超过%d
	rs_AddString(g_sLangID_State_TheCurrentLoop, &g_sLangTxt_State_TheCurrentLoop);							  // 当前循环
	rs_AddString(g_sLangID_State_Enter, &g_sLangTxt_State_Enter);											  // 进入
	rs_AddString(g_sLangID_State_InVolOutofRange, &g_sLangTxt_State_InVolOutofRange);						  // 输入的电压超出范围
	rs_AddString(g_sLangID_State_InCurOutofrange, &g_sLangTxt_State_InCurOutofrange);						  // 输入的电流超出范围
	rs_AddString(g_sLangID_State_TheOnepercentHarmonic, &g_sLangTxt_State_TheOnepercentHarmonic);			  //%1次谐波
	rs_AddString(g_sLangID_State_HarmonicTestTemplatefile, &g_sLangTxt_State_HarmonicTestTemplatefile);		  // 谐波测试模板文件
	rs_AddString(g_sLangID_State_IncreExperfile, &g_sLangTxt_State_IncreExperfile);							  // 递变试验模板文件
	rs_AddString(g_sLangID_State_TBuildDate, &g_sLangTxt_State_TBuildDate);									  // TestCtrlCntrLinux生成日期
	rs_AddString(g_sLangID_State_Magnify, &g_sLangTxt_State_Magnify);										  // 放大
	rs_AddString(g_sLangID_State_Shrink, &g_sLangTxt_State_Shrink);											  // 缩小
	rs_AddString(g_sLangID_IECConfig_Screen, &g_sLangTxt_IECConfig_Screen); //筛选
	rs_AddString(g_sLangID_State_Reposition, &g_sLangTxt_State_Reposition);									  // 复位
	rs_AddString(g_sLangID_Gradient_CreateFolder, &g_sLangTxt_Gradient_CreateFolder);						  // 创建文件夹
	rs_AddString(g_sLangID_Gradient_FolderCreationFailed, &g_sLangTxt_Gradient_FolderCreationFailed);		  // 文件夹创建失败！
	rs_AddString(g_sLangID_Gradient_AddExperiment, &g_sLangTxt_Gradient_AddExperiment);						  // 添加试验
	rs_AddString(g_sLangID_State_FThreeStraight, &g_sLangTxt_State_FThreeStraight);							  // 柔直(FT3)
	rs_AddString(g_sLangID_State_SinglephaseImpedance, &g_sLangTxt_State_SinglephaseImpedance);				  // 单相阻抗
	rs_AddString(g_sLangID_State_Coincidence, &g_sLangTxt_State_Coincidence);								  // 重  合
	rs_AddString(g_sLangID_State_RearAcceleration, &g_sLangTxt_State_RearAcceleration);						  // 后 加 速
	rs_AddString(g_sLangID_State_VersionInformation, &g_sLangTxt_State_VersionInformation);					  // 版本信息
	rs_AddString(g_sLangID_State_ApplianceProperties, &g_sLangTxt_State_ApplianceProperties);				  // 装置属性
	rs_AddString(g_sLangID_State_AppNumber, &g_sLangTxt_State_AppNumber);									  // 编号:
	rs_AddString(g_sLangID_State_ModuleManagement, &g_sLangTxt_State_ModuleManagement);						  // 模块管理
	rs_AddString(g_sLangID_State_HardwareInformationSettings, &g_sLangTxt_State_HardwareInformationSettings); // 硬件信息设置
	rs_AddString(g_sLangID_State_EnterTheValueoutofRange, &g_sLangTxt_State_EnterTheValueoutofRange);		  // 输入值%f超出范围(%d).
	rs_AddString(g_sLangID_State_POpenCFile, &g_sLangTxt_State_POpenCFile);									  // 请打开COMTRADE波形文件
	rs_AddString(g_sLangID_State_TheEdgeElementType, &g_sLangTxt_State_TheEdgeElementType);					  // 边元素类型
	rs_AddString(g_sLangID_State_ErrorBandLength, &g_sLangTxt_State_ErrorBandLength);						  // 误差带长度
	rs_AddString(g_sLangID_State_EdgeTestPoints, &g_sLangTxt_State_EdgeTestPoints);							  // 边测试点数
	rs_AddString(g_sLangID_State_CharCurEdgeElements, &g_sLangTxt_State_CharCurEdgeElements);				  // 特性曲线边元素
	rs_AddString(g_sLangID_State_startingPointR, &g_sLangTxt_State_startingPointR);							  // 起始点-R
	rs_AddString(g_sLangID_State_startingPointX, &g_sLangTxt_State_EdgeTestPointX);							  ////起始点-X
	rs_AddString(g_sLangID_State_EndPointR, &g_sLangTxt_State_EndPointR);									  // 终止点-R
	rs_AddString(g_sLangID_State_EndPointX, &g_sLangTxt_State_EndPointX);									  // 终止点-X
	rs_AddString(g_sLangID_State_Direction, &g_sLangTxt_State_Direction);									  // 方向
	rs_AddString(g_sLangID_State_PositiveArrival, &g_sLangTxt_State_PositiveArrival);						  // 正向到达
	rs_AddString(g_sLangID_State_ANgle, &g_sLangTxt_State_ANgle);											  // 角度
	rs_AddString(g_sLangID_State_Offset, &g_sLangTxt_State_Offset);											  // 偏移
	rs_AddString(g_sLangID_State_Width, &g_sLangTxt_State_Width);											  // 宽度
	rs_AddString(g_sLangID_State_CenterX, &g_sLangTxt_State_CenterX);										  // x-圆心
	rs_AddString(g_sLangID_State_CenterY, &g_sLangTxt_State_CenterY);										  // y-圆心
	rs_AddString(g_sLangID_State_Radius, &g_sLangTxt_State_Radius);											  // 半径
	rs_AddString(g_sLangID_State_StartingAngle, &g_sLangTxt_State_StartingAngle);							  // 起始角度
	rs_AddString(g_sLangID_State_TerminationAngle, &g_sLangTxt_State_TerminationAngle);						  // 终止角度
	rs_AddString(g_sLangID_State_ClockDirection, &g_sLangTxt_State_ClockDirection);							  // 时钟方向
	rs_AddString(g_sLangID_State_LowVoltageprotection, &g_sLangTxt_State_LowVoltageprotection);				  // 低压保护
	rs_AddString(g_sLangID_State_Overvoltageprotection, &g_sLangTxt_State_Overvoltageprotection);			  // 过压保护
	rs_AddString(g_sLangID_State_HarmonicBrakingcoefficient, &g_sLangTxt_State_HarmonicBrakingcoefficient);	  // 谐波制动系数
	rs_AddString(g_sLangID_State_Harmonicbraking, &g_sLangTxt_State_Harmonicbraking);						  // 谐波制动
	rs_AddString(g_sLangID_State_IEEECurset, &g_sLangTxt_State_IEEECurset);									  // IEEE曲线参数设置
	rs_AddString(g_sLangID_State_IACCurSet, &g_sLangTxt_State_IACCurSet);									  // IAC曲线参数设置
	rs_AddString(g_sLangID_State_I2TCurSet, &g_sLangTxt_State_I2TCurSet);									  // I2T曲线参数设置
	rs_AddString(g_sLangID_State_IECCurSet, &g_sLangTxt_State_IECCurSet);									  // IEC曲线参数设置
	rs_AddString(g_sLangID_State_VolLimitSet, &g_sLangTxt_State_VolLimitSet);								  // 电压反时限参数设置
	rs_AddString(g_sLangID_State_NoActioned, &g_sLangTxt_State_NoActioned);									  // 未动作
	rs_AddString(g_sLangID_State_ActionValue, &g_sLangTxt_State_ActionValue);								  // 动作值
	rs_AddString(g_sLangID_State_Error, &g_sLangTxt_State_Error);											  // 误差
	rs_AddString(g_sLangID_State_HarContent, &g_sLangTxt_State_HarContent);									  // 谐波含量
	rs_AddString(g_sLangID_State_DifferentCur, &g_sLangTxt_State_DifferentCur);								  // 差动电流
	rs_AddString(g_sLangID_State_BrakingCur, &g_sLangTxt_State_BrakingCur);									  // 制动电流
	rs_AddString(g_sLangID_State_VoltageRat, &g_sLangTxt_State_VoltageRat);									  // 电压比值
	rs_AddString(g_sLangID_State_ZImpValue, &g_sLangTxt_State_ZImpValue);									  // 阻抗值(Z)
	rs_AddString(g_sLangID_State_DAngle, &g_sLangTxt_State_DAngle);											  // 角度(°)
	rs_AddString(g_sLangID_State_CurrentRat, &g_sLangTxt_State_CurrentRat);									  // 电流比值

	rs_AddString(g_sLangID_State_CurlfailedItems, &g_sLangTxt_State_CurlfailedItems);						// 特性曲线查找失败(strCharaID=%s;strIndex=%s),无法更新项目列表.
	rs_AddString(g_sLangID_State_UTC_TwelveWIntDLine, &g_sLangTxt_State_UTC_TwelveWIntDLine);				//(UTC-12:00)国际日期变更线西
	rs_AddString(g_sLangID_State_UTC_ElevenCUTime, &g_sLangTxt_State_UTC_ElevenCUTime);						// UTC-11:00)协调世界时-11
	rs_AddString(g_sLangID_State_UTC_TenAleutianIslands, &g_sLangTxt_State_UTC_TenAleutianIslands);			//(UTC-10:00)阿留申群岛
	rs_AddString(g_sLangID_State_UTC_NineAlaska, &g_sLangTxt_State_UTC_NineAlaska);							//(UTC-9:00)阿拉斯加
	rs_AddString(g_sLangID_State_UTC_EUCPacificTime, &g_sLangTxt_State_UTC_EUCPacificTime);					//(UTC-8:00)太平洋时间(美国和加拿大)
	rs_AddString(g_sLangID_State_UTC_SevenCLM, &g_sLangTxt_State_UTC_SevenCLM);								//(UTC-7:00)奇瓦瓦,拉巴斯,马萨特兰")
	rs_AddString(g_sLangID_State_UTC_SixCentralAmerica, &g_sLangTxt_State_UTC_SixCentralAmerica);			//(UTC-6:00)中美洲
	rs_AddString(g_sLangID_State_UTC_FiveUCEasternTime, &g_sLangTxt_State_UTC_FiveUCEasternTime);			//(UTC-5:00)东部时间(美国和加拿大)
	rs_AddString(g_sLangID_State_UTC_FourCanadaAtlanticTime, &g_sLangTxt_State_UTC_FourCanadaAtlanticTime); //(UTC-4:00)大西洋时间(加拿大)
	rs_AddString(g_sLangID_State_UTC_ThreeGreenland, &g_sLangTxt_State_UTC_ThreeGreenland);					//(UTC-3:00)格陵兰
	rs_AddString(g_sLangID_State_UTC_TwoCooUniversalTime, &g_sLangTxt_State_UTC_TwoCooUniversalTime);		//(UTC-2:00)协调世界时-2
	rs_AddString(g_sLangID_State_UTC_OneCapIslandsAzores, &g_sLangTxt_State_UTC_OneCapIslandsAzores);		//(UTC-1:00)佛得角群岛,亚速尔群岛
	rs_AddString(g_sLangID_State_UTC_DubEdinhLisLon, &g_sLangTxt_State_UTC_DubEdinhLisLon);					//(UTC)都柏林,爱丁堡,里斯本,伦敦
	rs_AddString(g_sLangID_State_UTC_POneBCMPWAfrica, &g_sLangTxt_State_UTC_POneBCMPWAfrica);				//(UTC+1:00)布鲁塞尔,哥本哈根,马德里,巴黎,中非西部
	rs_AddString(g_sLangID_State_UTC_PTwoCAJerusalem, &g_sLangTxt_State_UTC_PTwoCAJerusalem);				//(UTC+2:00)开罗,雅典,耶路撒冷
	rs_AddString(g_sLangID_State_UTC_PThreeBKMPeterby, &g_sLangTxt_State_UTC_PThreeBKMPeterby);				//(UTC+3:00)巴格达,科威特,莫斯科,圣彼得比")
	rs_AddString(g_sLangID_State_UTC_PFourAbuDhabiBaku, &g_sLangTxt_State_UTC_PFourAbuDhabiBaku);			//(UTC+4:00)阿布扎比,巴库
	rs_AddString(g_sLangID_State_UTC_PFiveIslamabadKarachi, &g_sLangTxt_State_UTC_PFiveIslamabadKarachi);	//(UTC+5:00)伊斯兰堡,卡拉奇
	rs_AddString(g_sLangID_State_UTC_PSixAstana, &g_sLangTxt_State_UTC_PSixAstana);							//(UTC+6:00)阿斯塔纳
	rs_AddString(g_sLangID_State_UTC_PSevenBHJakarta, &g_sLangTxt_State_UTC_PSevenBHJakarta);				//(UTC+7:00)曼谷,河内,雅加达
	rs_AddString(g_sLangID_State_UTC_PEightBCHUrumqi, &g_sLangTxt_State_UTC_PEightBCHUrumqi);				//(UTC+8:00)北京,重庆,香港,乌鲁木齐
	rs_AddString(g_sLangID_State_UTC_PNineTSPyongyang, &g_sLangTxt_State_UTC_PNineTSPyongyang);				//(UTC+9:00)东京,首尔,平壤
	rs_AddString(g_sLangID_State_UTC_PTenCMSydney, &g_sLangTxt_State_UTC_PTenCMSydney);						//(UTC+10:00)堪培拉,墨尔本,悉尼
	rs_AddString(g_sLangID_State_UTC_PSINCaledonia, &g_sLangTxt_State_UTC_PSINCaledonia);					//(UTC+11:00)所罗门群岛,新喀里多尼亚
	rs_AddString(g_sLangID_State_UTC_PTwelveFiji, &g_sLangTxt_State_UTC_PTwelveFiji);						//(UTC+12:00)斐济

	rs_AddString(g_sLangID_Gradient_Intotalcheckarow, &g_sLangTxt_Gradient_Intotalcheckarow);							  // 总计只能选择%d次谐波，假如想选择当前次谐波，需要取消勾选一行.
	rs_AddString(g_sLangID_Gradient_CurbanksatleastTwo, &g_sLangTxt_Gradient_CurbanksatleastTwo);						  // 当前电流组数为(%ld),至少需要2组电流才能进行差流计算.
	rs_AddString(g_sLangID_Gradient_CurselinNotFound, &g_sLangTxt_Gradient_CurselinNotFound);							  // 当前选择的递变通道(Index=%d)未查找到.
	rs_AddString(g_sLangID_Gradient_CurinDCincrement, &g_sLangTxt_Gradient_CurinDCincrement);							  // 当前为直流输出模式,不可切换为频率递变.
	rs_AddString(g_sLangID_Gradient_NoteThepthanoneus, &g_sLangTxt_Gradient_NoteThepthanoneus);							  // 备注:规程要求测试时间1分钟，最大对时误差不大于1μs.
	rs_AddString(g_sLangID_Gradient_NoteThepthanfourus, &g_sLangTxt_Gradient_NoteThepthanfourus);						  // 备注:规程要求测试时间10分钟，最大守时误差不大于4μs.
	rs_AddString(g_sLangID_Gradient_InPPSfreemodevaluecontrolblock, &g_sLangTxt_Gradient_InPPSfreemodevaluecontrolblock); // 无PPS模式下,需要先进行报文探测,选择对应采样值控制块.
	rs_AddString(g_sLangID_Gradient_GOOSEreleaseDataStatusIsempty, &g_sLangTxt_Gradient_GOOSEreleaseDataStatusIsempty);	  // 当前状态(%d)的GOOSE发布数据为空(出现异常).
	rs_AddString(g_sLangID_Gradient_MaintainatLeastOneState, &g_sLangTxt_Gradient_MaintainatLeastOneState);				  // 至少保留一个状态.
	rs_AddString(g_sLangID_Gradient_TheUsedfordebuggingNOexist, &g_sLangTxt_Gradient_TheUsedfordebuggingNOexist);		  // 调试使用的配置文件(%s)不存在.
	rs_AddString(g_sLangID_Gradient_FailedTestParameterfile, &g_sLangTxt_Gradient_FailedTestParameterfile);				  // 解析功能测试参数文件【%s】失败
	rs_AddString(g_sLangID_Gradient_MissingDefaultMappings, &g_sLangTxt_Gradient_MissingDefaultMappings);				  ////缺少硬件资源文件,无法创建缺省通道映射
	rs_AddString(g_sLangID_Gradient_FailDefaultPath, &g_sLangTxt_Gradient_FailDefaultPath);								  // 创建通道映射缺省路径失败
	rs_AddString(g_sLangID_Gradient_ExportfileSucceeded, &g_sLangTxt_Gradient_ExportfileSucceeded);						  // 导出通道映射文件[%s]成功
	rs_AddString(g_sLangID_Gradient_Failedtofile, &g_sLangTxt_Gradient_Failedtofile);									  // 导出通道映射文件[%s]失败
	rs_AddString(g_sLangID_Gradient_TheTesterfileFailedtoload, &g_sLangTxt_Gradient_TheTesterfileFailedtoload);			  // 测试仪硬件信息文件加载失败.
	rs_AddString(g_sLangID_Gradient_UnknownCommand, &g_sLangTxt_Gradient_UnknownCommand);								  // 未知的网页报告执行命令(%s).
	rs_AddString(g_sLangID_Gradient_Functionalfiledtexist, &g_sLangTxt_Gradient_Functionalfiledtexist);					  // 功能测试参数文件【%s】不存在
	rs_AddString(g_sLangID_Gradient_Inverse, &g_sLangTxt_Gradient_Inverse);												  // 反选
	rs_AddString(g_sLangID_Gradient_VActionValue, &g_sLangTxt_Gradient_VActionValue);									  //"电压动作值(V)"  lcq 7.06
	rs_AddString(g_sLangID_Gradient_CActionValue, &g_sLangTxt_Gradient_CActionValue);									  //"电流动作值(A)"  lcq 7.06
	rs_AddString(g_sLangID_Gradient_ReCoefficient, &g_sLangTxt_Gradient_ReCoefficient);									  //"返回系数" lcq 7.06
	rs_AddString(g_sLangID_Gradient_FirBoundAngle, &g_sLangTxt_Gradient_FirBoundAngle);									  //"边界角1(°)" lcq 7.06
	rs_AddString(g_sLangID_Gradient_SecBoundAngle, &g_sLangTxt_Gradient_SecBoundAngle);									  //"边界角2(°)" lcq 7.06
	rs_AddString(g_sLangID_Gradient_MaxSenAngle, &g_sLangTxt_Gradient_MaxSenAngle);										  //"最大灵敏角(°)" lcq 7.06
	rs_AddString(g_sLangID_Gradient_FreAction, &g_sLangTxt_Gradient_FreAction);											  //"动作频率(Hz)" lcq 7.06
	rs_AddString(g_sLangID_Gradient_PhaseAValue, &g_sLangTxt_Gradient_PhaseAValue);										  //"相位动作值(°)" lcq 7.06
	rs_AddString(g_sLangID_Gradient_ImpAValue, &g_sLangTxt_Gradient_ImpAValue);										  //"阻抗动作值(°)" lcq 7.06
	rs_AddString(g_sLangID_Gradient_TestTeach, &g_sLangTxt_Gradient_TestTeach);											  // 测试教学 lcq
	rs_AddString(g_sLangID_Gradient_ReportHeader, &g_sLangTxt_Gradient_ReportHeader);									  // 报告头信息 lcq
	rs_AddString(g_sLangID_Gradient_TestTempSusCom, &g_sLangTxt_Gradient_TestTempSusCom);								  // 下发保存测试模板(%s%s)命令成功. lcq
	rs_AddString(g_sLangID_Gradient_TestTempDefCom, &g_sLangTxt_Gradient_TestTempDefCom);								  // 下发保存测试模板(%s%s)命令失败. lcq
	rs_AddString(g_sLangID_Gradient_SavePageSus, &g_sLangTxt_Gradient_SavePageSus);										  // 保存网页模板文件(%s%s)成功. lcq
	rs_AddString(g_sLangID_Gradient_TestRecordSus, &g_sLangTxt_Gradient_TestRecordSus);									  // 下发保存测试记录(%s%s)命令成功. lcq
	rs_AddString(g_sLangID_Gradient_TestRecordFai, &g_sLangTxt_Gradient_TestRecordFai);									  // 下发保存测试记录(%s%s)命令失败. lcq
	rs_AddString(g_sLangID_Gradient_SaveReportSus, &g_sLangTxt_Gradient_SaveReportSus);									  // 保存报告文件(%s%s)成功. lcq
	rs_AddString(g_sLangID_Gradient_SameeXist, &g_sLangTxt_Gradient_SameeXist);											  // 路径(%s)下存在同名的文件,请修改文件名. lcq
	rs_AddString(g_sLangID_Gradient_ModuleType, &g_sLangTxt_Gradient_ModuleType);										  // 模块类型 lcq
	rs_AddString(g_sLangID_Gradient_LocNumber, &g_sLangTxt_Gradient_LocNumber);											  // 位置号 lcq
	rs_AddString(g_sLangID_Gradient_ModuleVersion, &g_sLangTxt_Gradient_ModuleVersion);									  // 模块版本 lcq
	rs_AddString(g_sLangID_Gradient_ManufactDate, &g_sLangTxt_Gradient_ManufactDate);									  // 生产日期 lc

	//     rs_AddString(g_sLangID_Gradient_InstrumentName, &g_sLangTxt_Gradient_InstrumentName);//仪器名称 lcq
	//     rs_AddString(g_sLangID_Gradient_BoardVersion, &g_sLangTxt_Gradient_BoardVersion);//主板版本 lcq
	//     rs_AddString(g_sLangID_Gradient_DriverVersion, &g_sLangTxt_Gradient_DriverVersion);//驱动版本 lcq
	//     rs_AddString(g_sLangID_Gradient_TestSVersion, &g_sLangTxt_Gradient_TestSVersion);//TestServer版本 lcq
	//     rs_AddString(g_sLangID_Gradient_LinuxBDate, &g_sLangTxt_Gradient_LinuxBDate);//Linux生成日期 lcq
	//     rs_AddString(g_sLangID_Gradient_MboardsNumIn, &g_sLangTxt_Gradient_MboardsNumIn);//主板开入数量（个） lcq
	//     rs_AddString(g_sLangID_Gradient_MboardsNumOut, &g_sLangTxt_Gradient_MboardsNumOut);//主板开出数量（个） lcq
	//     rs_AddString(g_sLangID_Gradient_AAcompensation, &g_sLangTxt_Gradient_AAcompensation);//模拟量绝对相位补偿(度) lcq
	//     rs_AddString(g_sLangID_Gradient_SsCapacity, &g_sLangTxt_Gradient_SsCapacity);//状态序列容量 lcq
	//     rs_AddString(g_sLangID_Gradient_TestSName, &g_sLangTxt_Gradient_TestSName);//TestServer名称 lcq
	//     rs_AddString(g_sLangID_Gradient_DriverName, &g_sLangTxt_Gradient_DriverName);//驱动名称 lcq
	//     rs_AddString(g_sLangID_Gradient_ModLocation, &g_sLangTxt_Gradient_ModLocation);//模块位置 lcq
	//     rs_AddString(g_sLangID_Gradient_HarmonicsNum, &g_sLangTxt_Gradient_HarmonicsNum);//谐波数 lcq
	//     rs_AddString(g_sLangID_Gradient_DCVolChaMax, &g_sLangTxt_Gradient_DCVolChaMax);//直流电压通道最大值 lcq
	//     rs_AddString(g_sLangID_Gradient_DCCurChaMax, &g_sLangTxt_Gradient_DCCurChaMax);//直流电流通道最大值 lcq
	//     rs_AddString(g_sLangID_Gradient_ACChanMax, &g_sLangTxt_Gradient_ACChanMax);//通道出交流最大值 lcq
	//     rs_AddString(g_sLangID_Gradient_DCChanMax, &g_sLangTxt_Gradient_DCChanMax);//通道出直流最大值 lcq
	//     rs_AddString(g_sLangID_Gradient_FreComFactor, &g_sLangTxt_Gradient_FreComFactor);//频率补偿系数 lcq
	//     rs_AddString(g_sLangID_Gradient_DigDeLHardware, &g_sLangTxt_Gradient_DigDeLHardware);//数字硬件相位延时 lcq
	//     rs_AddString(g_sLangID_Gradient_VCHardware, &g_sLangTxt_Gradient_VCHardware);//电压电流硬件特性 lcq
	//     rs_AddString(g_sLangID_Gradient_CCcoalescing, &g_sLangTxt_Gradient_CCcoalescing);//电流通道合并模式 lcq
	//     rs_AddString(g_sLangID_Gradient_FirSwitchoPen, &g_sLangTxt_Gradient_FirSwitchoPen);//第一组开关量配为开入 lcq
	//     rs_AddString(g_sLangID_Gradient_SecSwitchoPen, &g_sLangTxt_Gradient_SecSwitchoPen);//第二组开关量配为开入 lcq
	//     rs_AddString(g_sLangID_Gradient_ThirSwitchoPen, &g_sLangTxt_Gradient_ThirSwitchoPen);//第三组开关量配为开入 lcq
	//     rs_AddString(g_sLangID_Gradient_FourSwitchoPen, &g_sLangTxt_Gradient_FourSwitchoPen);//第四组开关量配为开入 lcq
	//     rs_AddString(g_sLangID_Gradient_FPGAVersion, &g_sLangTxt_Gradient_FPGAVersion);//模块FPGA版本 lcq
	//     rs_AddString(g_sLangID_Gradient_ModproVersion, &g_sLangTxt_Gradient_ModproVersion);//模块属性版本 lcq
	//     rs_AddString(g_sLangID_Gradient_BodianEleCor, &g_sLangTxt_Gradient_BodianEleCor);//北京博电新力电气股份有限公司 lcq
	//     rs_AddString(g_sLangID_Gradient_SCDfile, &g_sLangTxt_Gradient_SCDfile);//SCD文件 lcq
	//     rs_AddString(g_sLangID_Gradient_TemplateFile, &g_sLangTxt_Gradient_TemplateFile);//模板文件 lcq
	//     rs_AddString(g_sLangID_Gradient_ScreenFolder, &g_sLangTxt_Gradient_ScreenFolder);//截屏文件夹 lcq
	//     rs_AddString(g_sLangID_Gradient_SaveCast, &g_sLangTxt_Gradient_SaveCast);//保存截屏图片 lcq
	//     rs_AddString(g_sLangID_Gradient_OtherTypeFile, &g_sLangTxt_Gradient_OtherTypeFile);//其他类型文件 lcq
	rs_AddString(g_sLangID_Native_GroundDisSetV, &g_sLangTxt_Native_GroundDisSetV);			  // 接地距离定值（1-5段）
	rs_AddString(g_sLangID_Gradient_LocalNICIP, &g_sLangTxt_Gradient_LocalNICIP);			  // 本地网卡IP lcq
	rs_AddString(g_sLangID_Gradient_PrimaryIP, &g_sLangTxt_Gradient_PrimaryIP);				  // 主IP地址 lcq
	rs_AddString(g_sLangID_Gradient_CurGSetting, &g_sLangTxt_Gradient_CurGSetting);			  // 电流档位设置: lcq
	rs_AddString(g_sLangID_Gradient_HighCurPort, &g_sLangTxt_Gradient_HighCurPort);			  // 大电流输出端口: lcq
	rs_AddString(g_sLangID_Gradient_FirstFile, &g_sLangTxt_Gradient_FirstFile);				  // 1档(0.2Ω/10A) lcq
	rs_AddString(g_sLangID_Gradient_SecondFile, &g_sLangTxt_Gradient_SecondFile);			  // 2档(0.3Ω/10A) lcq
	rs_AddString(g_sLangID_Gradient_ThirdFile, &g_sLangTxt_Gradient_ThirdFile);				  // 3档(0.7Ω/10A) lcq

	rs_AddString(g_sLangID_Currentlevel1, &g_sLangTxt_Currentlevel1);	
	rs_AddString(g_sLangID_Currentlevel2, &g_sLangTxt_Currentlevel2);		
	rs_AddString(g_sLangID_Currentlevel3, &g_sLangTxt_Currentlevel3);				 
	rs_AddString(g_sLangID_CurrentHigh330, &g_sLangTxt_CurrentHigh330);	

	rs_AddString(g_sLangID_Gradient_ShotScreenSus, &g_sLangTxt_Gradient_ShotScreenSus);		  //"截屏成功." lcq
	rs_AddString(g_sLangID_Gradient_IECConfiguration, &g_sLangTxt_Gradient_IECConfiguration); //"IEC配置" lcq
	rs_AddString(g_sLangID_Gradient_MessageType, &g_sLangTxt_Gradient_MessageType);			  //"报文类型" lcq
	rs_AddString(g_sLangID_IEC_ChByteLen, &g_sLangTxt_IEC_ChByteLen);						  //"字节长度" lcq
	rs_AddString(g_sLangID_Gradient_SCLPars, &g_sLangTxt_Gradient_SCLPars);					  // SCL解析界面 lcq
	rs_AddString(g_sLangID_Gradient_VoltageSet, &g_sLangTxt_Gradient_VoltageSet);			  // 电压设置 lcq
	rs_AddString(g_sLangID_Gradient_CurrentSet, &g_sLangTxt_Gradient_CurrentSet);			  // 电流设置 lcq
	rs_AddString(g_sLangID_Gradient_FailedGfp, &g_sLangTxt_Gradient_FailedGfp);				  // 获取文件路径失败(%s). lcq
	rs_AddString(g_sLangID_Gradient_FailedTof, &g_sLangTxt_Gradient_FailedTof);				  // 打开文件失败(%s). lcq
	rs_AddString(g_sLangID_Gradient_FailedCwf, &g_sLangTxt_Gradient_FailedCwf);				  //[%s]创建写文件失败. lcq
	rs_AddString(g_sLangID_Gradient_FileIsize, &g_sLangTxt_Gradient_FileIsize);				  // 文件[%s]大小为(%ld). lcq
	rs_AddString(g_sLangID_Gradient_FailedTRlfile, &g_sLangTxt_Gradient_FailedTRlfile);		  // 读取指定长度的大文件内容失败. lcq
	rs_AddString(g_sLangID_Gradient_FileNoexist, &g_sLangTxt_Gradient_FileNoexist);			  // 文件不存在(%s). lcq
	rs_AddString(g_sLangID_Gradient_FreAValue, &g_sLangTxt_Gradient_FreAValue);				  // 频率动作值(Hz) lcq
	rs_AddString(g_sLangID_Gradient_ReleasedFTT, &g_sLangTxt_Gradient_ReleasedFTT);			  // FT3发布 lcq
	rs_AddString(g_sLangID_Gradient_CurSmvErr, &g_sLangTxt_Gradient_CurSmvErr);				  //"当前SMVFT3通道映射出错(%s). lcq
	rs_AddString(g_sLangID_Gradient_ExIEDdescrip, &g_sLangTxt_Gradient_ExIEDdescrip);		  // 外部IED描述 lcq
	rs_AddString(g_sLangID_Gradient_ParseLFile, &g_sLangTxt_Gradient_ParseLFile);			  // 解析文件( lcq
	rs_AddString(g_sLangID_Gradient_SCLNoSel, &g_sLangTxt_Gradient_SCLNoSel);				  //)不存在,无法进行SCL选择切换. lcq
	rs_AddString(g_sLangID_Gradient_NoParObjRisk, &g_sLangTxt_Gradient_NoParObjRisk);		  // 当前表格数据链表无父对象,删除当前行数据失败,存在内存泄漏风险. lcq
	rs_AddString(g_sLangID_Gradient_FailType, &g_sLangTxt_Gradient_FailType);				  // 故障类型 lcq
	rs_AddString(g_sLangID_Gradient_FailDirect, &g_sLangTxt_Gradient_FailDirect);			  // 故障方向 lcq
	rs_AddString(g_sLangID_Gradient_FailTime, &g_sLangTxt_Gradient_FailTime);				  // 故障时间 lcq
	rs_AddString(g_sLangID_Gradient_Slope, &g_sLangTxt_Gradient_Slope);						  // 斜率 lcq
	rs_AddString(g_sLangID_Gradient_StartTs, &g_sLangTxt_Gradient_StartTs);					  // 启动门槛 lcq
	rs_AddString(g_sLangID_Gradient_StartCur, &g_sLangTxt_Gradient_StartCur);				  // 启动电流 lcq
	rs_AddString(g_sLangID_Gradient_Inflectp, &g_sLangTxt_Gradient_Inflectp);				  // 拐点 lcq
	rs_AddString(g_sLangID_Gradient_DiffFlowEx, &g_sLangTxt_Gradient_DiffFlowEx);			  // 差流极值 lcq
	rs_AddString(g_sLangID_Gradient_AddCusp, &g_sLangTxt_Gradient_AddCusp);					  // 添加自定义点 lcq
	rs_AddString(g_sLangID_Gradient_Emptycusp, &g_sLangTxt_Gradient_Emptycusp);				  // 清空自定义点 lcq
	rs_AddString(g_sLangID_Gradient_NoLessCor, &g_sLangTxt_Gradient_NoLessCor);				  // 差流极值设置不能小于拐点电流对应差流值 lcq
	rs_AddString(g_sLangID_Gradient_RatioDiff, &g_sLangTxt_Gradient_RatioDiff);				  // 比率差动 lcq
	rs_AddString(g_sLangID_Gradient_Custestp, &g_sLangTxt_Gradient_Custestp);				  // 自定义测试点 lcq
	rs_AddString(g_sLangID_Gradient_Impedance, &g_sLangTxt_Gradient_Impedance);				  // 阻抗表达方式 lcq
	rs_AddString(g_sLangID_Gradient_SelectCur, &g_sLangTxt_Gradient_SelectCur);				  // 请先选择需要删除的特性曲线 lcq
	rs_AddString(g_sLangID_Gradient_CurveEditing, &g_sLangTxt_Gradient_CurveEditing);		  // 曲线编辑 lcq
	rs_AddString(g_sLangID_Gradient_InsertElement, &g_sLangTxt_Gradient_InsertElement);		  // 插入元素 lcq
	rs_AddString(g_sLangID_Gradient_ModifyElement, &g_sLangTxt_Gradient_ModifyElement);		  // 修改元素 lcq
	rs_AddString(g_sLangID_Gradient_PInitial, &g_sLangTxt_Gradient_PInitial);				  //"+:初始" lcq
	rs_AddString(g_sLangID_Gradient_PSelected, &g_sLangTxt_Gradient_PSelected);				  //+:选中 lcq
	rs_AddString(g_sLangID_Gradient_EndTrial, &g_sLangTxt_Gradient_EndTrial);				  //+:试验结束 lcq
	rs_AddString(g_sLangID_Gradient_UnUpdateGraph, &g_sLangTxt_Gradient_UnUpdateGraph);		  // 特性曲线查找失败(strCharaID=%s;strIndex=%s),无法更新曲线图 lcq

	rs_AddString(g_sLangID_Gradient_YNWirBlancer, &g_sLangTxt_Gradient_YNWirBlancer);	  // Y/V接线平衡变压器 lcq
	rs_AddString(g_sLangID_Gradient_YNoCorners, &g_sLangTxt_Gradient_YNoCorners);		  // Y/△-11接线(无转角) lcq
	rs_AddString(g_sLangID_Gradient_Sphase, &g_sLangTxt_Gradient_Sphase);				  // 单相变压器 lcq
	rs_AddString(g_sLangID_Gradient_YDSCornect, &g_sLangTxt_Gradient_YDSCornect);		  // Y/△/△接线 lcq
	rs_AddString(g_sLangID_Gradient_ImpedanceMB, &g_sLangTxt_Gradient_ImpedanceMB);		  // Y/A 接线阻抗匹配平衡变压器 lcq
	rs_AddString(g_sLangID_Gradient_ThrVWirceTF, &g_sLangTxt_Gradient_ThrVWirceTF);		  //"三相V/V接线变压器 lcq
	rs_AddString(g_sLangID_Gradient_SecThrVWirceTF, &g_sLangTxt_Gradient_SecThrVWirceTF); // 三相V/V接线变压器2 lcq
	rs_AddString(g_sLangID_Gradient_YSideCorner, &g_sLangTxt_Gradient_YSideCorner);		  // Y/△-11接线(Y侧转角) lcq
	rs_AddString(g_sLangID_Gradient_VThrPhase, &g_sLangTxt_Gradient_VThrPhase);			  // 三相V/V lcq
	rs_AddString(g_sLangID_Gradient_IRCurrent, &g_sLangTxt_Gradient_IRCurrent);			  // 基准电流(Ie) lcq
	rs_AddString(g_sLangID_Gradient_ARCurrent, &g_sLangTxt_Gradient_ARCurrent);			  // 基准电流(A) lcq
	rs_AddString(g_sLangID_Gradient_ActionTime, &g_sLangTxt_Gradient_ActionTime);		  // 动作时间 lcq
	rs_AddString(g_sLangID_Gradient_JumpA, &g_sLangTxt_Gradient_JumpA);					  //" 跳  A " lcq
	rs_AddString(g_sLangID_Gradient_JumpB, &g_sLangTxt_Gradient_JumpB);					  //" 跳  B " lcq
	rs_AddString(g_sLangID_Gradient_JumpC, &g_sLangTxt_Gradient_JumpC);					  //" 跳  C " lcq
	rs_AddString(g_sLangID_Gradient_Jjump, &g_sLangTxt_Gradient_Jjump);					  // 跳 lcq
	rs_AddString(g_sLangID_Gradient_CurPhaseErr, &g_sLangTxt_Gradient_CurPhaseErr);		  // 当前相位值越限出错(%f). lcq
	rs_AddString(g_sLangID_Gradient_Setting, &g_sLangTxt_Gradient_Setting);				  // 设置 lcq
	rs_AddString(g_sLangID_Gradient_FT3CurChanErr, &g_sLangTxt_Gradient_FT3CurChanErr);	  // 当前FT3通道映射出错(%s). lcq
	rs_AddString(g_sLangID_Gradient_OpticalPower, &g_sLangTxt_Gradient_OpticalPower);	  // 光功率 lcq
	rs_AddString(g_sLangID_Gradient_POpticalPort, &g_sLangTxt_Gradient_POpticalPort);	  // 光口%d lcq
	rs_AddString(g_sLangID_Gradient_FOpticalPower, &g_sLangTxt_Gradient_FOpticalPower);	  // 光功率(-dbm) lcq
	rs_AddString(g_sLangID_Gradient_FmFileName, &g_sLangTxt_Gradient_FmFileName);		  // 文件名称： lcq
	rs_AddString(g_sLangID_Gradient_DirectoryFile, &g_sLangTxt_Gradient_DirectoryFile);	  // 文件目录： lcq
	rs_AddString(g_sLangID_Gradient_SecondaryIPSet, &g_sLangTxt_Gradient_SecondaryIPSet); // 辅助IP设置 lcq
	rs_AddString(g_sLangID_Gradient_IPInputInvalid, &g_sLangTxt_Gradient_IPInputInvalid); // IP输入不合法 lcq
	rs_AddString(g_sLangID_Gradient_VAOnceValue, &g_sLangTxt_Gradient_VAOnceValue);		  // 一次值(V/A) lcq
	rs_AddString(g_sLangID_Gradient_VATwiceValue, &g_sLangTxt_Gradient_VATwiceValue);	  // 二次值(V/A) lcq
	rs_AddString(g_sLangID_Gradient_SameThreep, &g_sLangTxt_Gradient_SameThreep);		  // 三相相同 lcq
	rs_AddString(g_sLangID_Gradient_AllSamep, &g_sLangTxt_Gradient_AllSamep);			  // 全部相同 lcq
	rs_AddString(g_sLangID_Gradient_DPhase, &g_sLangTxt_Gradient_DPhase);				  // 相位(°) lcq
	rs_AddString(g_sLangID_Gradient_FRelCurempty, &g_sLangTxt_Gradient_FRelCurempty);	  // 当前状态(%d)的FT3发布数据为空(出现异常). lcq
	rs_AddString(g_sLangID_Gradient_EmptyCurTI, &g_sLangTxt_Gradient_EmptyCurTI);		  // 当前测试项为空 lcq
	rs_AddString(g_sLangID_Gradient_ClosePerTBF, &g_sLangTxt_Gradient_ClosePerTBF);		  // 请先关闭网页界面,才能执行工具栏按钮功能. lcq
	rs_AddString(g_sLangID_Gradient_WaitSASD, &g_sLangTxt_Gradient_WaitSASD);			  // 等待测试服务停止后关闭. lcq
	rs_AddString(g_sLangID_Gradient_INUnSavescreen, &g_sLangTxt_Gradient_INUnSavescreen); // 保存截屏(%s)(isNull)失败. lcq
	rs_AddString(g_sLangID_Gradient_UnSavescreen, &g_sLangTxt_Gradient_UnSavescreen);	  // 保存截屏(%s)(save)失败. lcq
	rs_AddString(g_sLangID_Gradient_Savescreen, &g_sLangTxt_Gradient_Savescreen);		  // 保存截屏(%s)成功. lcq
	rs_AddString(g_sLangID_Gradient_Selectleg, &g_sLangTxt_Gradient_Selectleg);			  // 请在测试项目树形控件中选择合法的项目分类 lcq
	rs_AddString(g_sLangID_Gradient_CLoseMMChanges, &g_sLangTxt_Gradient_CLoseMMChanges); //"?????????????? OnCmd_NewTest: 关闭打开的测试功能页面，并弹框提示是否保存修改 ???????????"
	rs_AddString(g_sLangID_Gradient_TemplateErr, &g_sLangTxt_Gradient_TemplateErr);		  // 模板错误！找不到rootnode节点对应的功能界面【%s】 lcq
	rs_AddString(g_sLangID_Gradient_SaveTemplateAs, &g_sLangTxt_Gradient_SaveTemplateAs); // 模板另存为 lcq
	rs_AddString(g_sLangID_Gradient_OpenfileFail, &g_sLangTxt_Gradient_OpenfileFail);	  // 打开文件失败 lcq
	rs_AddString(g_sLangID_Gradient_SendComplete, &g_sLangTxt_Gradient_SendComplete);	  // 发送完成 lcq
	rs_AddString(g_sLangID_Gradient_RecvChannel, &g_sLangTxt_Gradient_RecvChannel);		  // 接收通道设置 lcq
	rs_AddString(g_sLangID_Gradient_RatioPCT, &g_sLangTxt_Gradient_RatioPCT);			  // PT/CT变比 lcq
	rs_AddString(g_sLangID_Gradient_ControlB, &g_sLangTxt_Gradient_ControlB);			  // 请选择控制块 lcq
	rs_AddString(g_sLangID_Gradient_RecvChannnel, &g_sLangTxt_Gradient_RecvChannnel);	  // 接收通道 lcq
	rs_AddString(g_sLangID_Gradient_ResTimeErr, &g_sLangTxt_Gradient_ResTimeErr);		  // 响应时间误差 lcq
	rs_AddString(g_sLangID_Gradient_MessResTime, &g_sLangTxt_Gradient_MessResTime);		  // 报文响应时间 lcq
	rs_AddString(g_sLangID_Gradient_ChaDelay, &g_sLangTxt_Gradient_ChaDelay);			  // 通道延时 lcq
	rs_AddString(g_sLangID_Gradient_MergeUint, &g_sLangTxt_Gradient_MergeUint);			  // 合并单元测试功能ID()在配置文件中未查找到. lcq
	rs_AddString(g_sLangID_Gradient_NAbnormalRes, &g_sLangTxt_Gradient_NAbnormalRes);	  // 当前选择测试功能异常(%s),导致m_pSttIecRcdFuncInterface==NULL. lcq
	rs_AddString(g_sLangID_Gradient_TestDuration, &g_sLangTxt_Gradient_TestDuration);	  // 测试时长(s): lcq
	rs_AddString(g_sLangID_Gradient_TheCurDelay, &g_sLangTxt_Gradient_TheCurDelay);		  // 当前延时数据为空,清空时间精度结果失败. lcq
	rs_AddString(g_sLangID_Gradient_EmptyRes, &g_sLangTxt_Gradient_EmptyRes);			  // 清空时间精度结果成功 lcq
	rs_AddString(g_sLangID_Gradient_DiffRatio, &g_sLangTxt_Gradient_DiffRatio);			  // 比差(%) lcq
	rs_AddString(g_sLangID_Gradient_CurNullFa, &g_sLangTxt_Gradient_CurNullFa);			  // 当前数据集为空,清空误差统计结果失败. lcq
	rs_AddString(g_sLangID_Gradient_ZeroDrift, &g_sLangTxt_Gradient_ZeroDrift);			  // 零漂 lcq
	rs_AddString(g_sLangID_Gradient_ValueOutP, &g_sLangTxt_Gradient_ValueOutP);			  // 输出值 lcq
	rs_AddString(g_sLangID_Gradient_PhaseOutP, &g_sLangTxt_Gradient_PhaseOutP);			  // 输出相位 lcq
	rs_AddString(g_sLangID_Gradient_MeasurAmp, &g_sLangTxt_Gradient_MeasurAmp);			  // 实测幅值 lcq
	rs_AddString(g_sLangID_Gradient_ChanDelay, &g_sLangTxt_Gradient_ChanDelay);			  // 通道延时 lcq
	rs_AddString(g_sLangID_Gradient_CompError, &g_sLangTxt_Gradient_CompError);			  // 复合误差 lcq
	rs_AddString(g_sLangID_Gradient_MeaPhase, &g_sLangTxt_Gradient_MeaPhase);			  // 实测相位 lcq
	rs_AddString(g_sLangID_Gradient_FrequencyDiff, &g_sLangTxt_Gradient_FrequencyDiff);	  // 频差 lcq
	rs_AddString(g_sLangID_Gradient_DetectMessageI, &g_sLangTxt_Gradient_DetectMessageI); // 报文探测界面 lcq
	rs_AddString(g_sLangID_Gradient_Unrecorded, &g_sLangTxt_Gradient_Unrecorded);		  // 未录波 lcq
	rs_AddString(g_sLangID_Gradient_Appscribed, &g_sLangTxt_Gradient_Appscribed);		  // GOOSE控制块(AppID=0X%04X),已添加订阅到光口%ld,无需重复添加. lcq
	rs_AddString(g_sLangID_Gradient_SEcontrolSus, &g_sLangTxt_Gradient_SEcontrolSus);	  // GOOSE控制块(AppID=0X%04X),添加订阅到光口%ld成功. lcq
	rs_AddString(g_sLangID_Gradient_AppscribedFa, &g_sLangTxt_Gradient_AppscribedFa);	  //"GOOSE控制块(AppID=0X%04X),已添加发布到光口%ld,无需重复添加." lcq
	rs_AddString(g_sLangID_Gradient_AppFascribedFa, &g_sLangTxt_Gradient_AppFascribedFa); // GOOSE控制块(AppID=0X%04X),添加发布到光口%ld成功. lcq
	rs_AddString(g_sLangID_Gradient_ModifyTip, &g_sLangTxt_Gradient_ModifyTip);			  // 修改接线提示 lcq
	rs_AddString(g_sLangID_Gradient_WiringTip, &g_sLangTxt_Gradient_WiringTip);			  // 接线提示 lcq
	rs_AddString(g_sLangID_Gradient_WirPrompt, &g_sLangTxt_Gradient_WirPrompt);			  // 新建接线提示 lcq
	rs_AddString(g_sLangID_Gradient_EnterTips, &g_sLangTxt_Gradient_EnterTips);			  // 请在此处输入接线提示信息…… lcq
	rs_AddString(g_sLangID_Gradient_ClickCTest, &g_sLangTxt_Gradient_ClickCTest);		  // 请按照接线提示信息，完成接线后，点击“完成接线”按钮，继续测试…… lcq
	rs_AddString(g_sLangID_Gradient_CompleteWir, &g_sLangTxt_Gradient_CompleteWir);		  // 完成接线 lcq
	rs_AddString(g_sLangID_Gradient_WirpromptExit, &g_sLangTxt_Gradient_WirpromptExit);	  // 存在相同名称的接线提示 lcq
	rs_AddString(g_sLangID_Gradient_WEditNoChange, &g_sLangTxt_Gradient_WEditNoChange);	  // 接线提示信息编辑，未检测到内容发生变化…… lcq
	rs_AddString(g_sLangID_Gradient_WrongWayrun, &g_sLangTxt_Gradient_WrongWayrun);		  // 错误的运行方式！ lcq

	rs_AddString(g_sLangID_Gradient_VarType, &g_sLangTxt_Gradient_VarType);
	rs_AddString(g_sLangID_Gradient_Phase, &g_sLangTxt_Gradient_Phase);
	rs_AddString(g_sLangID_Gradient_Init, &g_sLangTxt_Gradient_Init);
	rs_AddString(g_sLangID_Gradient_Finish, &g_sLangTxt_Gradient_Finish);
	rs_AddString(g_sLangID_Gradient_Step, &g_sLangTxt_Gradient_Step);
	rs_AddString(g_sLangID_Gradient_Time, &g_sLangTxt_Gradient_Time);
	rs_AddString(g_sLangID_Gradient_Direction, &g_sLangTxt_Gradient_Direction);
	rs_AddString(g_sLangID_Gradient_MaxAngle, &g_sLangTxt_Gradient_MaxAngle);
	rs_AddString(g_sLangID_Gradient_Clockwise, &g_sLangTxt_Gradient_Clockwise);
	rs_AddString(g_sLangID_Gradient_Anticlockwise, &g_sLangTxt_Gradient_Anticlockwise);
	rs_AddString(g_sLangID_Gradient_AllFreq, &g_sLangTxt_Gradient_AllFreq);
	rs_AddString(g_sLangID_Gradient_TimeBeforeChange, &g_sLangTxt_Gradient_TimeBeforeChange);
	rs_AddString(g_sLangID_Gradient_TimeBeforeFail, &g_sLangTxt_Gradient_TimeBeforeFail);
	rs_AddString(g_sLangID_Gradient_CurBeforeChange, &g_sLangTxt_Gradient_CurBeforeChange);
	rs_AddString(g_sLangID_Gradient_Normal, &g_sLangTxt_Gradient_Normal);
	rs_AddString(g_sLangID_Gradient_Failure, &g_sLangTxt_Gradient_Failure);
	rs_AddString(g_sLangID_Gradient_VarSet, &g_sLangTxt_Gradient_VarSet);
	rs_AddString(g_sLangID_Gradient_ChangingSet, &g_sLangTxt_Gradient_ChangingSet);
	rs_AddString(g_sLangID_Gradient_UnChangingSet, &g_sLangTxt_Gradient_UnChangingSet);
	rs_AddString(g_sLangID_Gradient_OtherSet, &g_sLangTxt_Gradient_OtherSet);
	rs_AddString(g_sLangID_Gradient_TestResult, &g_sLangTxt_Gradient_TestResult);
	rs_AddString(g_sLangID_Gradient_ParaSet, &g_sLangTxt_Gradient_ParaSet);
	rs_AddString(g_sLangID_Gradient_BoutSet, &g_sLangTxt_Gradient_BoutSet);
	rs_AddString(g_sLangID_Gradient_BoutSets, &g_sLangTxt_Gradient_BoutSets);

	rs_AddString(g_sLangID_Report_TestChoose, &g_sLangTxt_Report_TestChoose);
	rs_AddString(g_sLangID_Report_TestObjInf, &g_sLangTxt_Report_TestObjInf);
	rs_AddString(g_sLangID_Report_SubInformation, &g_sLangTxt_Report_SubInformation);
	rs_AddString(g_sLangID_Report_SubName, &g_sLangTxt_Report_SubName);
	rs_AddString(g_sLangID_Report_SubAddr, &g_sLangTxt_Report_SubAddr);
	rs_AddString(g_sLangID_Report_LoopName, &g_sLangTxt_Report_LoopName);
	rs_AddString(g_sLangID_Report_LoopAddr, &g_sLangTxt_Report_LoopAddr);
	rs_AddString(g_sLangID_Report_Tester, &g_sLangTxt_Report_Tester);
	rs_AddString(g_sLangID_Report_ReportTitle, &g_sLangTxt_Report_ReportTitle);
	rs_AddString(g_sLangID_Report_DeviceName, &g_sLangTxt_Report_DeviceName);
	rs_AddString(g_sLangID_Report_DeviceInfor, &g_sLangTxt_Report_DeviceInfor);
	rs_AddString(g_sLangID_Report_DeviceModel, &g_sLangTxt_Report_DeviceModel);
	rs_AddString(g_sLangID_Report_DeviceAddr, &g_sLangTxt_Report_DeviceAddr);
	rs_AddString(g_sLangID_Report_DeviceFactory, &g_sLangTxt_Report_DeviceFactory);
	rs_AddString(g_sLangID_Report_SettingsNO, &g_sLangTxt_Report_SettingsNO);
	rs_AddString(g_sLangID_Report_AdditionalInf, &g_sLangTxt_Report_AdditionalInf);
	rs_AddString(g_sLangID_Report_RatedValue, &g_sLangTxt_Report_RatedValue);
	rs_AddString(g_sLangID_Report_DUTs, &g_sLangTxt_Report_DUTs);
	rs_AddString(g_sLangID_Report_Title, &g_sLangTxt_Report_Title);
	rs_AddString(g_sLangID_Report_Vnom, &g_sLangTxt_Report_Vnom);
	rs_AddString(g_sLangID_Report_Vdc, &g_sLangTxt_Report_Vdc);
	rs_AddString(g_sLangID_Report_SureTime, &g_sLangTxt_Report_SureTime);
	rs_AddString(g_sLangID_Report_AntiShakeTime, &g_sLangTxt_Report_AntiShakeTime);
	rs_AddString(g_sLangID_Report_Vprim, &g_sLangTxt_Report_Vprim);
	rs_AddString(g_sLangID_Report_Fnom, &g_sLangTxt_Report_Fnom);
	rs_AddString(g_sLangID_Report_Iprim, &g_sLangTxt_Report_Iprim);
	rs_AddString(g_sLangID_Report_TestAppInfor, &g_sLangTxt_Report_TestAppInfor);
	rs_AddString(g_sLangID_Report_AppModel, &g_sLangTxt_Report_AppModel);
	rs_AddString(g_sLangID_Report_Imax, &g_sLangTxt_Report_Imax);
	rs_AddString(g_sLangID_Report_AppSN, &g_sLangTxt_Report_AppSN);
	rs_AddString(g_sLangID_Report_TestStartTime, &g_sLangTxt_Report_TestStartTime);
	rs_AddString(g_sLangID_Report_ComPortType, &g_sLangTxt_Report_ComPortType);
	rs_AddString(g_sLangID_Report_TestEndTime, &g_sLangTxt_Report_TestEndTime);
	rs_AddString(g_sLangID_Report_Vmax, &g_sLangTxt_Report_Vmax);

	rs_AddString(g_sLangID_ChMaps_AnalogCh, &g_sLangTxt_ChMaps_AnalogCh);
	rs_AddString(g_sLangID_ChMaps_DigitalCh, &g_sLangTxt_ChMaps_DigitalCh);
	rs_AddString(g_sLangID_ChMaps_WeekCh, &g_sLangTxt_ChMaps_WeekCh);
	rs_AddString(g_sLangID_ChMaps_Title, &g_sLangTxt_ChMaps_Title);
	rs_AddString(g_sLangID_ChMaps_OutputSel, &g_sLangTxt_ChMaps_OutputSel);
	rs_AddString(g_sLangID_ChMaps_Analog, &g_sLangTxt_ChMaps_Analog);
	rs_AddString(g_sLangID_ChMaps_Digital, &g_sLangTxt_ChMaps_Digital);
	rs_AddString(g_sLangID_ChMaps_Week, &g_sLangTxt_ChMaps_Week);
	rs_AddString(g_sLangID_ChMaps_DigitalType, &g_sLangTxt_ChMaps_DigitalType);
	rs_AddString(g_sLangID_ChMaps_MeasSel, &g_sLangTxt_ChMaps_MeasSel);
	rs_AddString(g_sLangID_ChMaps_DigitalMeasType, &g_sLangTxt_ChMaps_DigitalMeasType);
	rs_AddString(g_sLangID_ChMaps_DefautMaps, &g_sLangTxt_ChMaps_DefautMaps);
	rs_AddString(g_sLangID_ChMaps_ImportChMaps, &g_sLangTxt_ChMaps_ImportChMaps);
	rs_AddString(g_sLangID_ChMaps_ExportChMaps, &g_sLangTxt_ChMaps_ExportChMaps);
	rs_AddString(g_sLangID_ChMaps_LockMaps, &g_sLangTxt_ChMaps_LockMaps);
	rs_AddString(g_sLangID_IEC_SysParasSet, &g_sLangTxt_IEC_SysParasSet);
	rs_AddString(g_sLangID_IEC_SysParasConfig, &g_sLangTxt_IEC_SysParasConfig);
	rs_AddString(g_sLangID_IEC_WeakSet, &g_sLangTxt_IEC_WeakSet);
	rs_AddString(g_sLangID_IEC_Message, &g_sLangTxt_IEC_Message);
	rs_AddString(g_sLangID_IEC_Publish, &g_sLangTxt_IEC_Publish);
	rs_AddString(g_sLangID_IEC_Subscription, &g_sLangTxt_IEC_Subscription);
	rs_AddString(g_sLangID_IEC_OpenConfig, &g_sLangTxt_IEC_OpenConfig);
	rs_AddString(g_sLangID_IEC_OpenConfigFile, &g_sLangTxt_IEC_OpenConfigFile);
	rs_AddString(g_sLangID_IEC_ConfigSaveAs, &g_sLangTxt_IEC_ConfigSaveAs);
	rs_AddString(g_sLangID_IEC_ConfigFileSaveAs, &g_sLangTxt_IEC_ConfigFileSaveAs);
	rs_AddString(g_sLangID_IEC_ImportSCL, &g_sLangTxt_IEC_ImportSCL);
	rs_AddString(g_sLangID_IEC_ImportSCLFile, &g_sLangTxt_IEC_ImportSCLFile);
	rs_AddString(g_sLangID_IEC_SaveDatas, &g_sLangTxt_IEC_SaveDatas);
	rs_AddString(g_sLangID_IEC_DeleteAllButFirst, &g_sLangTxt_IEC_DeleteAllButFirst);
	rs_AddString(g_sLangID_IEC_ChEdit, &g_sLangTxt_IEC_ChEdit);
	rs_AddString(g_sLangID_IEC_T1Times, &g_sLangTxt_IEC_T1Times);
	rs_AddString(g_sLangID_IEC_T0Times, &g_sLangTxt_IEC_T0Times);
	rs_AddString(g_sLangID_IEC_TimeQuality, &g_sLangTxt_IEC_TimeQuality);
	rs_AddString(g_sLangID_IEC_GroupDelay, &g_sLangTxt_IEC_GroupDelay);
	rs_AddString(g_sLangID_IEC_Details, &g_sLangTxt_IEC_Details);
	rs_AddString(g_sLangID_IEC_SamplingRate, &g_sLangTxt_IEC_SamplingRate);
	rs_AddString(g_sLangID_IEC_BaudRate, &g_sLangTxt_IEC_BaudRate);
	rs_AddString(g_sLangID_IEC_SmpByteNum, &g_sLangTxt_IEC_SmpByteNum);
	rs_AddString(g_sLangID_IEC_SmpCntType, &g_sLangTxt_IEC_SmpCntType);
	rs_AddString(g_sLangID_IEC_RatedDelay, &g_sLangTxt_IEC_RatedDelay);
	rs_AddString(g_sLangID_IEC_SetRecordParas, &g_sLangTxt_IEC_SetRecordParas);
	rs_AddString(g_sLangID_IEC_DcVolCodeValue, &g_sLangTxt_IEC_DcVolCodeValue);
	rs_AddString(g_sLangID_IEC_AcVolCodeValue, &g_sLangTxt_IEC_AcVolCodeValue);
	rs_AddString(g_sLangID_IEC_DcCurCodeValue, &g_sLangTxt_IEC_DcCurCodeValue);
	rs_AddString(g_sLangID_IEC_PrimtRatedVol, &g_sLangTxt_IEC_PrimtRatedVol);
	rs_AddString(g_sLangID_IEC_PrimtRatedCur, &g_sLangTxt_IEC_PrimtRatedCur);
	rs_AddString(g_sLangID_IEC_DcNeutralVolCodeValue, &g_sLangTxt_IEC_DcNeutralVolCodeValue);
	rs_AddString(g_sLangID_IEC_AcProtCurCodeValue, &g_sLangTxt_IEC_AcProtCurCodeValue);
	rs_AddString(g_sLangID_IEC_AcMeasCurCodeValue, &g_sLangTxt_IEC_AcMeasCurCodeValue);
	rs_AddString(g_sLangID_IEC_FT3PublishParameterSet, &g_sLangTxt_IEC_FT3PublishParameterSet);
	rs_AddString(g_sLangID_IEC_FT3MapParameterSet, &g_sLangTxt_IEC_FT3MapParameterSet);
	rs_AddString(g_sLangID_IEC_KeepSendAfterStop, &g_sLangTxt_IEC_KeepSendAfterStop);
	rs_AddString(g_sLangID_IEC_StopSending, &g_sLangTxt_IEC_StopSending);
	rs_AddString(g_sLangID_IEC_PacketSendingMode, &g_sLangTxt_IEC_PacketSendingMode);
	rs_AddString(g_sLangID_IEC_PTRatio, &g_sLangTxt_IEC_PTRatio);
	rs_AddString(g_sLangID_IEC_CTRatio, &g_sLangTxt_IEC_CTRatio);
	rs_AddString(g_sLangID_IEC_SMVCh, &g_sLangTxt_IEC_SMVCh);
	rs_AddString(g_sLangID_IEC_ChDescription, &g_sLangTxt_IEC_ChDescription);
	rs_AddString(g_sLangID_IEC_ChType, &g_sLangTxt_IEC_ChType);
	rs_AddString(g_sLangID_IEC_DIMap, &g_sLangTxt_IEC_DIMap);
	rs_AddString(g_sLangID_IEC_SetRepair, &g_sLangTxt_IEC_SetRepair);
	rs_AddString(g_sLangID_IEC_UnSetRepair, &g_sLangTxt_IEC_UnSetRepair);
	rs_AddString(g_sLangID_IEC_IMap, &g_sLangTxt_IEC_IMap);
	rs_AddString(g_sLangID_IEC_UMap, &g_sLangTxt_IEC_UMap);
	rs_AddString(g_sLangID_IEC_SetInitValue, &g_sLangTxt_IEC_SetInitValue);
	rs_AddString(g_sLangID_IEC_Choose, &g_sLangTxt_IEC_Choose);
	rs_AddString(g_sLangID_IEC_Target, &g_sLangTxt_IEC_Target);
	rs_AddString(g_sLangID_IEC_Entrance, &g_sLangTxt_IEC_Entrance);
	rs_AddString(g_sLangID_IEC_ChannelNumber, &g_sLangTxt_IEC_ChannelNumber);
	rs_AddString(g_sLangID_IEC_Version, &g_sLangTxt_IEC_Version);
	rs_AddString(g_sLangID_IEC_Test, &g_sLangTxt_IEC_Test);
	rs_AddString(g_sLangID_IEC_LifeTime, &g_sLangTxt_IEC_LifeTime);
	rs_AddString(g_sLangID_IEC_UnParse, &g_sLangTxt_IEC_UnParse);
	rs_AddString(g_sLangID_IEC_ChMaps, &g_sLangTxt_IEC_ChMaps);
	rs_AddString(g_sLangID_IEC_InitValue, &g_sLangTxt_IEC_InitValue);
	rs_AddString(g_sLangID_IEC_InputMap, &g_sLangTxt_IEC_InputMap);
	rs_AddString(g_sLangID_IEC_Source, &g_sLangTxt_IEC_Source);
	rs_AddString(g_sLangID_IEC_Intrance, &g_sLangTxt_IEC_Intrance);
	rs_AddString(g_sLangID_IEC_Quality, &g_sLangTxt_IEC_Quality);
	rs_AddString(g_sLangID_IEC_Delay, &g_sLangTxt_IEC_Delay);
	rs_AddString(g_sLangID_IEC_StartDelay, &g_sLangTxt_IEC_StartDelay);
	rs_AddString(g_sLangID_IEC_Synchronously, &g_sLangTxt_IEC_Synchronously);
	rs_AddString(g_sLangID_IEC_ScaleFactor, &g_sLangTxt_IEC_ScaleFactor);
	rs_AddString(g_sLangID_IEC_SetScaleFactor, &g_sLangTxt_IEC_SetScaleFactor);
	rs_AddString(g_sLangID_IEC_FMByte, &g_sLangTxt_IEC_FMByte);
	rs_AddString(g_sLangID_IEC_GMByte, &g_sLangTxt_IEC_GMByte);
	rs_AddString(g_sLangID_IEC_LCFI, &g_sLangTxt_IEC_LCFI);
	rs_AddString(g_sLangID_IEC_IRIGB, &g_sLangTxt_IEC_IRIGB);
	rs_AddString(g_sLangID_IEC_STFI, &g_sLangTxt_IEC_STFI);
	rs_AddString(g_sLangID_IEC_FI, &g_sLangTxt_IEC_FI);
	rs_AddString(g_sLangID_IEC_FIChoose, &g_sLangTxt_IEC_FIChoose);
	rs_AddString(g_sLangID_IEC_MACAddr, &g_sLangTxt_IEC_MACAddr);
	rs_AddString(g_sLangID_IEC_DataSetText, &g_sLangTxt_IEC_DataSetText);
	rs_AddString(g_sLangID_IEC_GOOSEIndex, &g_sLangTxt_IEC_GOOSEIndex);
	rs_AddString(g_sLangID_IEC_VlanPri, &g_sLangTxt_IEC_VlanPri);
	rs_AddString(g_sLangID_IEC_ConfigVersion, &g_sLangTxt_IEC_ConfigVersion);
	rs_AddString(g_sLangID_IEC_ChAllNumber, &g_sLangTxt_IEC_ChAllNumber);
	rs_AddString(g_sLangID_IEC_SubChNumber, &g_sLangTxt_IEC_SubChNumber);
	rs_AddString(g_sLangID_IEC_SubIED, &g_sLangTxt_IEC_SubIED);
	rs_AddString(g_sLangID_IEC_ASDU, &g_sLangTxt_IEC_ASDU);
	rs_AddString(g_sLangID_IEC_Find, &g_sLangTxt_IEC_Find);
	rs_AddString(g_sLangID_IEC_SMVPublish, &g_sLangTxt_IEC_SMVPublish);
	rs_AddString(g_sLangID_IEC_SMVSubscription, &g_sLangTxt_IEC_SMVSubscription);
	rs_AddString(g_sLangID_IEC_Configure, &g_sLangTxt_IEC_Configure);
	rs_AddString(g_sLangID_IEC_CancelConfigure, &g_sLangTxt_IEC_CancelConfigure);
	rs_AddString(g_sLangID_IEC_IEDList, &g_sLangTxt_IEC_IEDList);
	rs_AddString(g_sLangID_IEC_AccuratyLevel, &g_sLangTxt_IEC_AccuratyLevel);
	rs_AddString(g_sLangID_IEC_FiberInSet, &g_sLangTxt_IEC_FiberInSet);
	rs_AddString(g_sLangID_IEC_FiberOutSet, &g_sLangTxt_IEC_FiberOutSet);

	rs_AddString(g_sLangID_IEC_QualityParaSet, &g_sLangTxt_IEC_QualityParaSet);
	rs_AddString(g_sLangID_IEC_Validity, &g_sLangTxt_IEC_Validity);
	rs_AddString(g_sLangID_IEC_Overflow, &g_sLangTxt_IEC_Overflow);
	rs_AddString(g_sLangID_IEC_OutOfRange, &g_sLangTxt_IEC_OutOfRange);
	rs_AddString(g_sLangID_IEC_BadReference, &g_sLangTxt_IEC_BadReference);
	rs_AddString(g_sLangID_IEC_Oscillatory, &g_sLangTxt_IEC_Oscillatory);
	rs_AddString(g_sLangID_IEC_Failure, &g_sLangTxt_IEC_Failure);
	rs_AddString(g_sLangID_IEC_OldData, &g_sLangTxt_IEC_OldData);
	rs_AddString(g_sLangID_IEC_Inconsistent, &g_sLangTxt_IEC_Inconsistent);
	rs_AddString(g_sLangID_IEC_Inaccurate, &g_sLangTxt_IEC_Inaccurate);
	rs_AddString(g_sLangID_Channel_Source, &g_sLangTxt_Channel_Source);
	rs_AddString(g_sLangID_Channel_Test, &g_sLangTxt_Channel_Test);
	rs_AddString(g_sLangID_IEC_Opb, &g_sLangTxt_IEC_Opb);
	rs_AddString(g_sLangID_IEC_ModifyAllChs, &g_sLangTxt_IEC_ModifyAllChs);
	rs_AddString(g_sLangID_IEC_DirectSet, &g_sLangTxt_IEC_DirectSet);
	rs_AddString(g_sLangID_IEC_good, &g_sLangTxt_IEC_good);
	rs_AddString(g_sLangID_IEC_invalid, &g_sLangTxt_IEC_invalid);
	rs_AddString(g_sLangID_IEC_reserved, &g_sLangTxt_IEC_reserved);
	rs_AddString(g_sLangID_IEC_questionable, &g_sLangTxt_IEC_questionable);
	rs_AddString(g_sLangID_IEC_nooverflow, &g_sLangTxt_IEC_nooverflow);
	rs_AddString(g_sLangID_IEC_overflow, &g_sLangTxt_IEC_overflow);
	rs_AddString(g_sLangID_IEC_normal, &g_sLangTxt_IEC_normal);
	rs_AddString(g_sLangID_IEC_outofrange, &g_sLangTxt_IEC_outofrange);
	rs_AddString(g_sLangID_IEC_badreference, &g_sLangTxt_IEC_badreference);
	rs_AddString(g_sLangID_IEC_noOscillatory, &g_sLangTxt_IEC_noOscillatory);
	rs_AddString(g_sLangID_IEC_oscillatory, &g_sLangTxt_IEC_oscillatory);
	rs_AddString(g_sLangID_IEC_nofailure, &g_sLangTxt_IEC_nofailure);
	rs_AddString(g_sLangID_IEC_failure, &g_sLangTxt_IEC_failure);
	rs_AddString(g_sLangID_IEC_noovertime, &g_sLangTxt_IEC_noovertime);
	rs_AddString(g_sLangID_IEC_overtime, &g_sLangTxt_IEC_overtime);
	rs_AddString(g_sLangID_IEC_noinconsistent, &g_sLangTxt_IEC_noinconsistent);
	rs_AddString(g_sLangID_IEC_inconsistent, &g_sLangTxt_IEC_inconsistent);
	rs_AddString(g_sLangID_IEC_accurate, &g_sLangTxt_IEC_accurate);
	rs_AddString(g_sLangID_IEC_inaccurate, &g_sLangTxt_IEC_inaccurate);
	rs_AddString(g_sLangID_IEC_process, &g_sLangTxt_IEC_process);
	rs_AddString(g_sLangID_IEC_substituted, &g_sLangTxt_IEC_substituted);
	rs_AddString(g_sLangID_IEC_run, &g_sLangTxt_IEC_run);
	rs_AddString(g_sLangID_IEC_test, &g_sLangTxt_IEC_test);
	rs_AddString(g_sLangID_IEC_nolock, &g_sLangTxt_IEC_nolock);
	rs_AddString(g_sLangID_IEC_lock, &g_sLangTxt_IEC_lock);
	rs_AddString(g_sLangID_IEC_Msg_OverWriteCtrl, &g_sLangTxt_IEC_Msg_OverWriteCtrl);

	rs_AddString(g_sLangID_IEC_ImportIecfg, &g_sLangTxt_IEC_ImportIecfg);
	rs_AddString(g_sLangID_IEC_Detect, &g_sLangTxt_IEC_Detect);
	rs_AddString(g_sLangID_IEC_DetectStop, &g_sLangTxt_IEC_DetectStop);
	rs_AddString(g_sLangID_IEC_Clear, &g_sLangTxt_IEC_Clear);
	rs_AddString(g_sLangID_IEC_BeginRecord, &g_sLangTxt_IEC_BeginRecord);
	rs_AddString(g_sLangID_IEC_UseSmv, &g_sLangTxt_IEC_UseSmv);
	rs_AddString(g_sLangID_IEC_UseGoose, &g_sLangTxt_IEC_UseGoose);
	rs_AddString(g_sLangID_IEC_SmvFirstIsTime, &g_sLangTxt_IEC_SmvFirstIsTime);
	rs_AddString(g_sLangID_IEC_WriteDetectPkg, &g_sLangTxt_IEC_WriteDetectPkg);
	rs_AddString(g_sLangID_IEC_WriteRcvPkg, &g_sLangTxt_IEC_WriteRcvPkg);
	rs_AddString(g_sLangID_IEC_AutoWrite, &g_sLangTxt_IEC_AutoWrite);
	rs_AddString(g_sLangID_IEC_SendLength_2, &g_sLangTxt_IEC_SendLength_2);
	rs_AddString(g_sLangID_IEC_SendLength, &g_sLangTxt_IEC_SendLength);
	rs_AddString(g_sLangID_IEC_Writegen, &g_sLangTxt_IEC_Writegen);
	rs_AddString(g_sLangID_IEC_PacketSending, &g_sLangTxt_IEC_PacketSending);
	rs_AddString(g_sLangID_IEC_OnceValue, &g_sLangTxt_IEC_OnceValue);
	rs_AddString(g_sLangID_IEC_TwiceValue, &g_sLangTxt_IEC_TwiceValue);
	rs_AddString(g_sLangID_IEC_Coeff, &g_sLangTxt_IEC_Coeff);
	rs_AddString(g_sLangID_IEC_Sendratio, &g_sLangTxt_IEC_Sendratio);

	rs_AddString(g_sLangID_GOOSE_Single, &g_sLangTxt_GOOSE_Single);
	rs_AddString(g_sLangID_GOOSE_Double, &g_sLangTxt_GOOSE_Double);
	rs_AddString(g_sLangID_GOOSE_Float, &g_sLangTxt_GOOSE_Float);
	rs_AddString(g_sLangID_Goose_SwitchTime, &g_sLangTxt_Goose_SwitchTime);
	rs_AddString(g_sLangID_Goose_Value, &g_sLangTxt_Goose_Value);
	rs_AddString(g_sLangID_Goose_RelativeTime, &g_sLangTxt_Goose_RelativeTime);

	rs_AddString(g_sLangID_CharLib_ZoomIndex, &g_sLangTxt_CharLib_ZoomIndex);
	rs_AddString(g_sLangID_CharLib_FaultPhase, &g_sLangTxt_CharLib_FaultPhase);
	rs_AddString(g_sLangID_CharLib_AddChar, &g_sLangTxt_CharLib_AddChar);
	rs_AddString(g_sLangID_CharLib_StartCurr, &g_sLangTxt_CharLib_StartCurr);
	rs_AddString(g_sLangID_CharLib_Ratiobraking, &g_sLangTxt_CharLib_Ratiobraking);
	rs_AddString(g_sLangID_CharLib_Paragraph, &g_sLangTxt_CharLib_Paragraph);
	rs_AddString(g_sLangID_CharLib_Tripping, &g_sLangTxt_CharLib_Tripping);
	rs_AddString(g_sLangID_CharLib_TestPointsGrid, &g_sLangTxt_CharLib_TestPointsGrid);

	rs_AddString(g_sLangID_Smv_SelCb, &g_sLangTxt_Smv_SelCb);
	rs_AddString(g_sLangID_Smv_SelFunc, &g_sLangTxt_Smv_SelFunc);
	rs_AddString(g_sLangID_Smv_PrevPage, &g_sLangTxt_Smv_PrevPage);
	rs_AddString(g_sLangID_Smv_NextPage, &g_sLangTxt_Smv_NextPage);
	rs_AddString(g_sLangID_Smv_SysSet, &g_sLangTxt_Smv_SysSet);
	rs_AddString(g_sLangID_Smv_ChName, &g_sLangTxt_Smv_ChName);
	rs_AddString(g_sLangID_Smv_Item, &g_sLangTxt_Smv_Item);
	rs_AddString(g_sLangID_Smv_Number, &g_sLangTxt_Smv_Number);
	rs_AddString(g_sLangID_Smv_PkgValue, &g_sLangTxt_Smv_PkgValue);
	rs_AddString(g_sLangID_Smv_Category, &g_sLangTxt_Smv_Category);
	rs_AddString(g_sLangID_Smv_Rates, &g_sLangTxt_Smv_Rates);
	rs_AddString(g_sLangID_Smv_ShowOneValue, &g_sLangTxt_Smv_ShowOneValue);
	rs_AddString(g_sLangID_Smv_ShowTwoValue, &g_sLangTxt_Smv_ShowTwoValue);
	rs_AddString(g_sLangID_Native_EffectiveVol, &g_sLangTxt_Native_EffectiveVol);
	rs_AddString(g_sLangID_Native_EffectiveCurr, &g_sLangTxt_Native_EffectiveCurr);
	rs_AddString(g_sLangID_Native_Power, &g_sLangTxt_Native_Power);
	rs_AddString(g_sLangID_Native_ReactivePow, &g_sLangTxt_Native_ReactivePow);
	rs_AddString(g_sLangID_Native_ApparentPow, &g_sLangTxt_Native_ApparentPow);
	rs_AddString(g_sLangID_Native_PowFactor, &g_sLangTxt_Native_PowFactor);
	rs_AddString(g_sLangID_Native_TotalPow, &g_sLangTxt_Native_TotalPow);
	rs_AddString(g_sLangID_Native_Clear, &g_sLangTxt_Native_Clear);
	rs_AddString(g_sLangID_Native_Switch, &g_sLangTxt_Native_Switch);
	rs_AddString(g_sLangID_IEC_FileSaveAs, &g_sLangTxt_IEC_FileSaveAs);
	rs_AddString(g_sLangID_IEC_Receiveratio, &g_sLangTxt_IEC_Receiveratio);
	rs_AddString(g_sLangID_IEC_Opticalport, &g_sLangTxt_IEC_Opticalport);
	rs_AddString(g_sLangID_IEC_PTOnce, &g_sLangTxt_IEC_PTOnce);
	rs_AddString(g_sLangID_IEC_PTSecond, &g_sLangTxt_IEC_PTSecond);
	rs_AddString(g_sLangID_IEC_CTOnce, &g_sLangTxt_IEC_CTOnce);
	rs_AddString(g_sLangID_IEC_CTSecond, &g_sLangTxt_IEC_CTSecond);
	rs_AddString(g_sLangID_IEC_OPDES, &g_sLangTxt_IEC_OPDES);
	rs_AddString(g_sLangID_IEC_Protectcurrent, &g_sLangTxt_IEC_Protectcurrent);
	rs_AddString(g_sLangID_IEC_Measurcurrent, &g_sLangTxt_IEC_Measurcurrent);
	rs_AddString(g_sLangID_IEC_IEDselect, &g_sLangTxt_IEC_IEDselect);
	rs_AddString(g_sLangID_Samples, &g_sLangTxt_Samples);
	rs_AddString(g_sLangID_Momentaryvalue, &g_sLangTxt_Momentaryvalue);
	rs_AddString(g_sLangID_notrigger, &g_sLangTxt_notrigger);
	rs_AddString(g_sLangID_Cyclicwave, &g_sLangTxt_Cyclicwave);
	rs_AddString(g_sLangID_GPS, &g_sLangTxt_GPS);
	rs_AddString(g_sLangID_Timere, &g_sLangTxt_Timere);
	rs_AddString(g_sLangID_Switchtrigger, &g_sLangTxt_Switchtrigger);
	rs_AddString(g_sLangID_Faultcurve, &g_sLangTxt_Faultcurve);
	rs_AddString(g_sLangID_Display, &g_sLangTxt_Display);
	rs_AddString(g_sLangID_AChannel, &g_sLangTxt_AChannel);
	rs_AddString(g_sLangID_BChannel, &g_sLangTxt_BChannel);
	rs_AddString(g_sLangID_Open_Record, &g_sLangTxt_Open_Record);
	rs_AddString(g_sLangID_Instant, &g_sLangTxt_Instant);
	rs_AddString(g_sLangID_PT, &g_sLangTxt_PT);
	rs_AddString(g_sLangID_CT, &g_sLangTxt_CT);
	rs_AddString(g_sLangID_Module1, &g_sLangTxt_Module1);
	rs_AddString(g_sLangID_Outputpower, &g_sLangTxt_Outputpower);
	rs_AddString(g_sLangID_Currentmodule, &g_sLangTxt_Currentmodule);
	rs_AddString(g_sLangID_CurrModuleSelect, &g_sLangTxt_CurrModuleSelect);
	rs_AddString(g_sLangID_Currentgear, &g_sLangTxt_Currentgear);
	rs_AddString(g_sLangID_Maximumport, &g_sLangTxt_Maximumport);
	rs_AddString(g_sLangID_Combinedcurrent, &g_sLangTxt_Combinedcurrent);
	rs_AddString(g_sLangID_Highcurrent, &g_sLangTxt_Highcurrent);
	rs_AddString(g_sLangID_Onegear, &g_sLangTxt_Onegear);
	rs_AddString(g_sLangID_Twogear, &g_sLangTxt_Twogear);
	rs_AddString(g_sLangID_Threegear, &g_sLangTxt_Threegear);
	rs_AddString(g_sLangID_else, &g_sLangTxt_else);
	rs_AddString(g_sLangID_Onlyselect, &g_sLangTxt_Onlyselect);
	rs_AddString(g_sLangID_Clickratio, &g_sLangTxt_Clickratio);
	rs_AddString(g_sLangID_Clickmonitor, &g_sLangTxt_Clickmonitor);
	rs_AddString(g_sLangID_Selecttable, &g_sLangTxt_Selecttable);
	rs_AddString(g_sLangID_Reporttest, &g_sLangTxt_Reporttest);
	rs_AddString(g_sLangID_starttest, &g_sLangTxt_starttest);
	rs_AddString(g_sLangID_General, &g_sLangTxt_General);
	rs_AddString(g_sLangID_TestHelp, &g_sLangTxt_TestHelp);
	rs_AddString(g_sLangID_Currentfailed, &g_sLangTxt_Currentfailed);
	rs_AddString(g_sLangID_Succeeded, &g_sLangTxt_Succeeded);
	rs_AddString(g_sLangID_Clear, &g_sLangTxt_Clear);
	rs_AddString(g_sLangID_delay, &g_sLangTxt_delay);
	rs_AddString(g_sLangID_Measured, &g_sLangTxt_Measured);
	rs_AddString(g_sLangID_error, &g_sLangTxt_error);
	rs_AddString(g_sLangID_The, &g_sLangTxt_The);
	rs_AddString(g_sLangID_current, &g_sLangTxt_current);
	rs_AddString(g_sLangID_Node, &g_sLangTxt_Node);
	rs_AddString(g_sLangID_Items, &g_sLangTxt_Items);
	rs_AddString(g_sLangID_IEC_IEC61850, &g_sLangTxt_IEC_IEC61850);
	rs_AddString(g_sLangID_exist, &g_sLangTxt_exist);
	rs_AddString(g_sLangID_menu, &g_sLangTxt_menu);
	rs_AddString(g_sLangID_return, &g_sLangTxt_return);
	rs_AddString(g_sLangID_USBFile, &g_sLangTxt_USBFile);
	rs_AddString(g_sLangID_RepalceFile, &g_sLangTxt_RepalceFile);
	rs_AddString(g_sLangID_import, &g_sLangTxt_import);
	rs_AddString(g_sLangID_export, &g_sLangTxt_export);
	rs_AddString(g_sLangID_Importflie, &g_sLangTxt_Importflie);
	rs_AddString(g_sLangID_Win, &g_sLangTxt_Win);
	rs_AddString(g_sLangID_Lose, &g_sLangTxt_Lose);
	rs_AddString(g_sLangID_block, &g_sLangTxt_block);
	rs_AddString(g_sLangID_Controlblock, &g_sLangTxt_Controlblock);
	rs_AddString(g_sLangID_leastone, &g_sLangTxt_leastone);
	rs_AddString(g_sLangID_copyblock, &g_sLangTxt_copyblock);

	rs_AddString(g_sLangID_viewchannel, &g_sLangTxt_viewchannel);
	rs_AddString(g_sLangID_dataobject, &g_sLangTxt_dataobject);
	rs_AddString(g_sLangID_channelType, &g_sLangTxt_channelType);
	rs_AddString(g_sLangID_parameterport, &g_sLangTxt_parameterport);

	rs_AddString(g_sLangID_SMV92map, &g_sLangTxt_SMV92map);
	rs_AddString(g_sLangID_samplepublish, &g_sLangTxt_samplepublish);
	rs_AddString(g_sLangID_USB, &g_sLangTxt_USB);
	rs_AddString(g_sLangID_exportbar, &g_sLangTxt_exportbar);
	rs_AddString(g_sLangID_Fileguid, &g_sLangTxt_Fileguid);
	rs_AddString(g_sLangID_devicedesc, &g_sLangTxt_devicedesc);
	rs_AddString(g_sLangID_unittype, &g_sLangTxt_unittype);
	rs_AddString(g_sLangID_changelist, &g_sLangTxt_changelist);
	rs_AddString(g_sLangID_overwitten, &g_sLangTxt_overwitten);
	rs_AddString(g_sLangID_componenttest, &g_sLangTxt_componenttest);
	rs_AddString(g_sLangID_sequence, &g_sLangTxt_sequence);
	rs_AddString(g_sLangID_componentlinevolttest, &g_sLangTxt_componentlinevolttest);
	rs_AddString(g_sLangID_linevolt, &g_sLangTxt_linevolt);
	rs_AddString(g_sLangID_steplength, &g_sLangTxt_steplength);
    //rs_AddString(g_sLangID_Frequency, &g_sLangTxt_Frequency);  //移动到基类CXLanguageResourceBase  2024-1-4 shaolei
	rs_AddString(g_sLangID_selectchannel, &g_sLangTxt_selectchannel);
	rs_AddString(g_sLangID_currenttime, &g_sLangTxt_currenttime);
	rs_AddString(g_sLangID_channelname, &g_sLangTxt_channelname);
	rs_AddString(g_sLangID_errorclass, &g_sLangTxt_errorclass);
	rs_AddString(g_sLangID_numbertest, &g_sLangTxt_numbertest);
	rs_AddString(g_sLangID_realtime, &g_sLangTxt_realtime);
	rs_AddString(g_sLangID_emptydata, &g_sLangTxt_emptydata);
	rs_AddString(g_sLangID_ratioerror, &g_sLangTxt_ratioerror);
	rs_AddString(g_sLangID_angle, &g_sLangTxt_angle);
	rs_AddString(g_sLangID_Compound, &g_sLangTxt_Compound);
	rs_AddString(g_sLangID_statistic, &g_sLangTxt_statistic);
	rs_AddString(g_sLangID_outputvalue, &g_sLangTxt_outputvalue);
	rs_AddString(g_sLangID_Outputphase, &g_sLangTxt_Outputphase);
	rs_AddString(g_sLangID_Measureampl, &g_sLangTxt_Measureampl);
	rs_AddString(g_sLangID_Measuredphase, &g_sLangTxt_Measuredphase);
	rs_AddString(g_sLangID_zerodrift, &g_sLangTxt_zerodrift);
	rs_AddString(g_sLangID_posttrigger, &g_sLangTxt_posttrigger);
	rs_AddString(g_sLangID_Switchimmed, &g_sLangTxt_Switchimmed);
	rs_AddString(g_sLangID_loopwaveform, &g_sLangTxt_loopwaveform);
	rs_AddString(g_sLangID_faultreplay, &g_sLangTxt_faultreplay);
	rs_AddString(g_sLangID_downloaddata, &g_sLangTxt_downloaddata);
	rs_AddString(g_sLangID_ReplayStarttest, &g_sLangTxt_ReplayStarttest);
	rs_AddString(g_sLangID_playback, &g_sLangTxt_playback);
	rs_AddString(g_sLangID_outputvoltage, &g_sLangTxt_outputvoltage);
	rs_AddString(g_sLangID_outputcurrent, &g_sLangTxt_outputcurrent);
	rs_AddString(g_sLangID_deliverybar, &g_sLangTxt_deliverybar);
	rs_AddString(g_sLangID_cfgFile, &g_sLangTxt_cfgFile);
	rs_AddString(g_sLangID_parsebar, &g_sLangTxt_parsebar);
	rs_AddString(g_sLangID_recordfile, &g_sLangTxt_recordfile);
	rs_AddString(g_sLangID_hardwarefile, &g_sLangTxt_hardwarefile);
	rs_AddString(g_sLangID_channelphase, &g_sLangTxt_channelphase);
	rs_AddString(g_sLangID_tablechannel, &g_sLangTxt_tablechannel);
	rs_AddString(g_sLangID_faulttype, &g_sLangTxt_faulttype);
	rs_AddString(g_sLangID_rangenumber, &g_sLangTxt_rangenumber);
	rs_AddString(g_sLangID_maxblocks, &g_sLangTxt_maxblocks);
	rs_AddString(g_sLangID_valuesubscrip, &g_sLangTxt_valuesubscrip);
	rs_AddString(g_sLangID_emptyIed, &g_sLangTxt_emptyIed);
	rs_AddString(g_sLangID_emptyIEC, &g_sLangTxt_emptyIEC);
	rs_AddString(g_sLangID_addedblock, &g_sLangTxt_addedblock);
	rs_AddString(g_sLangID_configurationfile, &g_sLangTxt_configurationfile);
 	rs_AddString(g_sLangID_warning, &g_sLangTxt_warning); //sun
	rs_AddString(g_sLangID_NullIEC, &g_sLangTxt_NullIEC);
	rs_AddString(g_sLangID_IECpath, &g_sLangTxt_IECpath);
	rs_AddString(g_sLangID_IECdocument, &g_sLangTxt_IECdocument);
	rs_AddString(g_sLangID_zero, &g_sLangTxt_zero);
	rs_AddString(g_sLangID_step, &g_sLangTxt_step);
	rs_AddString(g_sLangID_datapath, &g_sLangTxt_datapath);
	rs_AddString(g_sLangID_guide, &g_sLangTxt_guide);
	rs_AddString(g_sLangID_wizard, &g_sLangTxt_wizard);
	rs_AddString(g_sLangID_period, &g_sLangTxt_period);
	rs_AddString(g_sLangID_quality, &g_sLangTxt_quality);
	rs_AddString(g_sLangID_mutate, &g_sLangTxt_mutate);
	rs_AddString(g_sLangID_leadtime, &g_sLangTxt_leadtime);
	rs_AddString(g_sLangID_change, &g_sLangTxt_change);
	rs_AddString(g_sLangID_instrument, &g_sLangTxt_instrument);
	rs_AddString(g_sLangID_instrumentnumber, &g_sLangTxt_instrumentnumber);
	rs_AddString(g_sLangID_testip, &g_sLangTxt_testip);
	rs_AddString(g_sLangID_IPaddress, &g_sLangTxt_IPaddress);
	rs_AddString(g_sLangID_correctlyform, &g_sLangTxt_correctlyform);
	rs_AddString(g_sLangID_assistantIP, &g_sLangTxt_assistantIP);
	rs_AddString(g_sLangID_validentry, &g_sLangTxt_validentry);
	rs_AddString(g_sLangID_listIP, &g_sLangTxt_listIP);
	rs_AddString(g_sLangID_cardIP, &g_sLangTxt_cardIP);
	rs_AddString(g_sLangID_scan, &g_sLangTxt_scan);
	rs_AddString(g_sLangID_query, &g_sLangTxt_query);
	rs_AddString(g_sLangID_running, &g_sLangTxt_running);
	rs_AddString(g_sLangID_nullIP, &g_sLangTxt_nullIP);
	rs_AddString(g_sLangID_automatic, &g_sLangTxt_automatic);
	rs_AddString(g_sLangID_networkcards, &g_sLangTxt_networkcards);
	rs_AddString(g_sLangID_validIP, &g_sLangTxt_validIP);
	rs_AddString(g_sLangID_cardlookup, &g_sLangTxt_cardlookup);
	rs_AddString(g_sLangID_modifyIP, &g_sLangTxt_modifyIP);
	rs_AddString(g_sLangID_stopscan, &g_sLangTxt_stopscan);

	// SOE
	rs_AddString(g_sLangID_SOE_state, &g_sLangTxt_SOE_state);
	rs_AddString(g_sLangID_SOE_ChangeBeforTimes, &g_sLangTxt_SOE_ChangeBeforTimes);
	rs_AddString(g_sLangID_SOE_ShuttingTimes, &g_sLangTxt_SOE_ShuttingTimes);
	rs_AddString(g_sLangID_SOE_DisconTimes, &g_sLangTxt_SOE_DisconTimes);
	rs_AddString(g_sLangID_SOE_Count, &g_sLangTxt_SOE_Count);
	rs_AddString(g_sLangID_SOE_SustainTimes, &g_sLangTxt_SOE_SustainTimes);
	rs_AddString(g_sLangID_SOE_Break, &g_sLangTxt_SOE_Break);
	rs_AddString(g_sLangID_SOE_Shutting, &g_sLangTxt_SOE_Shutting);
	rs_AddString(g_sLangID_SOE_ImmediateExperiment, &g_sLangTxt_SOE_ImmediateExperiment);
	rs_AddString(g_sLangID_SOE_PulseWidth, &g_sLangTxt_SOE_PulseWidth);
	rs_AddString(g_sLangID_SOE_Resolution, &g_sLangTxt_SOE_Resolution);
	rs_AddString(g_sLangID_SOE_SelectAll, &g_sLangTxt_SOE_SelectAll);
	rs_AddString(g_sLangID_SOE_CancelAll, &g_sLangTxt_SOE_CancelAll);
	rs_AddString(g_sLangID_SOE_InitialAll, &g_sLangTxt_SOE_InitialAll);
	rs_AddString(g_sLangID_SOE_InitialDivideAll, &g_sLangTxt_SOE_InitialDivideAll);
	rs_AddString(g_sLangID_SOE_TemplateFile, &g_sLangTxt_SOE_TemplateFile);

	rs_AddString(g_sLangID_FileMngr_FolderName, &g_sLangTxt_FileMngr_FolderName);
	rs_AddString(g_sLangID_FileMngr_FolderIllustrate, &g_sLangTxt_FileMngr_FolderIllustrate);
	rs_AddString(g_sLangID_FileMngr_Date, &g_sLangTxt_FileMngr_Date);
	rs_AddString(g_sLangID_FileMngr_File, &g_sLangTxt_FileMngr_File);
	rs_AddString(g_sLangID_FileMngr_Used, &g_sLangTxt_FileMngr_Used);
	rs_AddString(g_sLangID_FileMngr_Available, &g_sLangTxt_FileMngr_Available);

	rs_AddString(g_sLangID_Native_Toolbar, &g_sLangTxt_Native_Toolbar);
	rs_AddString(g_sLangID_Native_BtnRemove, &g_sLangTxt_Native_BtnRemove);
	rs_AddString(g_sLangID_Native_BtnEndInsert, &g_sLangTxt_Native_BtnEndInsert);
	rs_AddString(g_sLangID_Native_BtnInsertAfter, &g_sLangTxt_Native_BtnInsertAfter);
	rs_AddString(g_sLangID_Native_BtnInsertBefore, &g_sLangTxt_Native_BtnInsertBefore);

	rs_AddString(g_sLangID_Native_BtnConfigDevice, &g_sLangTxt_Native_BtnConfigDevice);
	rs_AddString(g_sLangID_Native_BtnConnectDevice, &g_sLangTxt_Native_BtnConnectDevice);
	rs_AddString(g_sLangID_Native_BtnEnumDevice, &g_sLangTxt_Native_BtnEnumDevice);
	rs_AddString(g_sLangID_Native_BtnReadDataset, &g_sLangTxt_Native_BtnReadDataset);
	rs_AddString(g_sLangID_Native_BtnWriteDataset, &g_sLangTxt_Native_BtnWriteDataset);
	rs_AddString(g_sLangID_Native_BtnReadZone, &g_sLangTxt_Native_BtnReadZone);
	rs_AddString(g_sLangID_Native_BtnWriteZone, &g_sLangTxt_Native_BtnWriteZone);
	rs_AddString(g_sLangID_Native_BtnReset, &g_sLangTxt_Native_BtnReset);
	rs_AddString(g_sLangID_Native_BtnStartRpt, &g_sLangTxt_Native_BtnStartRpt);
	rs_AddString(g_sLangID_Native_BtnStopReport, &g_sLangTxt_Native_BtnStopReportr);
	rs_AddString(g_sLangID_Native_BtnAddDevice, &g_sLangTxt_Native_BtnAddDevice);
	rs_AddString(g_sLangID_Native_BtnEnumLDevice, &g_sLangTxt_Native_BtnEnumLDevice);
	rs_AddString(g_sLangID_Native_BtnEnumDataset, &g_sLangTxt_Native_BtnEnumDataset);
	rs_AddString(g_sLangID_Native_BtnOpenDvmFile, &g_sLangTxt_Native_BtnOpenDvmFile);
	rs_AddString(g_sLangID_Native_BtnSaveDvmFile, &g_sLangTxt_Native_BtnSaveDvmFile);

	rs_AddString(g_sLangID_Native_VolSetTypeLN, &g_sLangTxt_Native_VolSetTypeLN);
	rs_AddString(g_sLangID_Native_VolSetTypeLL, &g_sLangTxt_Native_VolSetTypeLL);
	rs_AddString(g_sLangID_Native_VolSetTypeSE, &g_sLangTxt_Native_VolSetTypeSE);
	rs_AddString(g_sLangID_Native_CurSetTypeLN, &g_sLangTxt_Native_CurSetTypeLN);
	rs_AddString(g_sLangID_Native_CurSetTypeSE, &g_sLangTxt_Native_CurSetTypeSE);

	rs_AddString(g_sLangID_Native_Upgradation, &g_sLangTxt_Native_Upgradation);
	rs_AddString(g_sLangID_Native_UpdateSoftware, &g_sLangTxt_Native_UpdateSoftware);
	rs_AddString(g_sLangID_Native_OnlineUpgrade, &g_sLangTxt_Native_OnlineUpgrade);
	rs_AddString(g_sLangID_Native_UpgradeProgressBar, &g_sLangTxt_Native_UpgradeProgressBar);
	rs_AddString(g_sLangID_Native_NetworkConnectionFailed, &g_sLangTxt_Native_NetworkConnectionFailed);
	rs_AddString(g_sLangID_Native_VersionUpdateFailed, &g_sLangTxt_Native_VersionUpdateFailed);
	rs_AddString(g_sLangID_Native_CommandFailed, &g_sLangTxt_Native_CommandFailed);
	rs_AddString(g_sLangID_Native_LowBatteryLevel, &g_sLangTxt_Native_LowBatteryLevel);
	rs_AddString(g_sLangID_Native_IecDetection, &g_sLangTxt_Native_IecDetection);
	rs_AddString(g_sLangID_Native_UnrecognizedUSB, &g_sLangTxt_Native_UnrecognizedUSB);
	rs_AddString(g_sLangID_Native_ChargingUpgrade, &g_sLangTxt_Native_ChargingUpgrade);
	rs_AddString(g_sLangID_Native_OfflineUpgrade, &g_sLangTxt_Native_OfflineUpgrade);
	rs_AddString(g_sLangID_Native_PreparationUpgrade, &g_sLangTxt_Native_PreparationUpgrade);
	rs_AddString(g_sLangID_Native_LookupFailed, &g_sLangTxt_Native_LookupFailed);
	rs_AddString(g_sLangID_Native_LiveUpdate, &g_sLangTxt_Native_LiveUpdate);
	rs_AddString(g_sLangID_Native_ExcludingReportData, &g_sLangTxt_Native_ExcludingReportData);
	rs_AddString(g_sLangID_Native_ReportDataEmpty, &g_sLangTxt_Native_ReportDataEmpty);

	rs_AddString(g_sLangID_Native_SyStempoints, &g_sLangTxt_Native_SyStempoints);
	rs_AddString(g_sLangID_Native_Custompoints, &g_sLangTxt_Native_Custompoints);
	rs_AddString(g_sLangID_Native_Iecurrent, &g_sLangTxt_Native_Iecurrent);
	rs_AddString(g_sLangID_Native_Acurrent, &g_sLangTxt_Native_Acurrent);
	rs_AddString(g_sLangID_Native_Faultcurrent, &g_sLangTxt_Native_Faultcurrent);
	// 第七周许
	// xwd 10.16
	rs_AddString(g_sLangID_Native_SetOrigMsg, &g_sLangTxt_Native_SetOrigMsg);
	rs_AddString(g_sLangID_Native_DestMacAddr, &g_sLangTxt_Native_DestMacAddr);
	rs_AddString(g_sLangID_Native_Netid, &g_sLangTxt_Native_Netid);
	rs_AddString(g_sLangID_Native_FlyPntVolt, &g_sLangTxt_Native_FlyPntVolt);
	rs_AddString(g_sLangID_Native_FlyPntCurr, &g_sLangTxt_Native_FlyPntCurr);
	rs_AddString(g_sLangID_Native_FlyPntVoltUaEn, &g_sLangTxt_Native_FlyPntVoltUaEn);
	rs_AddString(g_sLangID_Native_FlyPntVoltUbEn, &g_sLangTxt_Native_FlyPntVoltUbEn);
	rs_AddString(g_sLangID_Native_FlyPntVoltUcEn, &g_sLangTxt_Native_FlyPntVoltUcEn);
	rs_AddString(g_sLangID_Native_FlyPntCurrIaEn, &g_sLangTxt_Native_FlyPntCurrIaEn);
	rs_AddString(g_sLangID_Native_FlyPntCurrIbEn, &g_sLangTxt_Native_FlyPntCurrIbEn);
	rs_AddString(g_sLangID_Native_FlyPntCurrIcEn, &g_sLangTxt_Native_FlyPntCurrIcEn);
	rs_AddString(g_sLangID_Native_JitterValns, &g_sLangTxt_Native_JitterValns);
	rs_AddString(g_sLangID_Native_Valid, &g_sLangTxt_Native_Valid);
	rs_AddString(g_sLangID_Native_Overflow, &g_sLangTxt_Native_Overflow);
	rs_AddString(g_sLangID_Native_OutOfRanges, &g_sLangTxt_Native_OutOfRanges);
	rs_AddString(g_sLangID_Native_BadBaseVal, &g_sLangTxt_Native_BadBaseVal);
	rs_AddString(g_sLangID_Native_OldData, &g_sLangTxt_Native_OldData);
	rs_AddString(g_sLangID_Native_Inconsistent, &g_sLangTxt_Native_Inconsistent);
	rs_AddString(g_sLangID_Native_Inaccurate, &g_sLangTxt_Native_Inaccurate);
	rs_AddString(g_sLangID_Native_Source, &g_sLangTxt_Native_Source);
	rs_AddString(g_sLangID_Native_OpLock, &g_sLangTxt_Native_OpLock);
	rs_AddString(g_sLangID_Native_AbnPointSel, &g_sLangTxt_Native_AbnPointSel);
	rs_AddString(g_sLangID_Native_AbnPoint, &g_sLangTxt_Native_AbnPoint);
	rs_AddString(g_sLangID_Native_SMVAbnParam, &g_sLangTxt_Native_SMVAbnParam);
	rs_AddString(g_sLangID_Native_SVAbnType, &g_sLangTxt_Native_SVAbnType);
	rs_AddString(g_sLangID_Native_SVMsgGrpNum, &g_sLangTxt_Native_SVMsgGrpNum);
	rs_AddString(g_sLangID_Native_SendFreq, &g_sLangTxt_Native_SendFreq);
	rs_AddString(g_sLangID_Native_SendFreqPerSec, &g_sLangTxt_Native_SendFreqPerSec);
	rs_AddString(g_sLangID_Native_AbnormDataSendTimeMode, &g_sLangTxt_Native_AbnormDataSendTimeMode);
	rs_AddString(g_sLangID_Native_SVSendTimeSecMode, &g_sLangTxt_Native_SVSendTimeSecMode);
	rs_AddString(g_sLangID_Native_GOOSEAbnormParam, &g_sLangTxt_Native_GOOSEAbnormParam);
	rs_AddString(g_sLangID_Native_AbnormGroupSeq, &g_sLangTxt_Native_AbnormGroupSeq);
	rs_AddString(g_sLangID_Native_SrcMACSelect, &g_sLangTxt_Native_SrcMACSelect);
	rs_AddString(g_sLangID_Native_DestMACSelect, &g_sLangTxt_Native_DestMACSelect);
	rs_AddString(g_sLangID_Native_GocbRefSelect, &g_sLangTxt_Native_GocbRefSelect);
	rs_AddString(g_sLangID_Native_GoIDSelect, &g_sLangTxt_Native_GoIDSelect);
	rs_AddString(g_sLangID_Native_DataSetSelect, &g_sLangTxt_Native_DataSetSelect);
	rs_AddString(g_sLangID_Native_DestMACs, &g_sLangTxt_Native_DestMACs);
	rs_AddString(g_sLangID_Native_AppIDSelect, &g_sLangTxt_Native_AppIDSelect);
	rs_AddString(g_sLangID_Native_StSelect, &g_sLangTxt_Native_StSelect);
	rs_AddString(g_sLangID_Native_StValue, &g_sLangTxt_Native_StValue);
	rs_AddString(g_sLangID_Native_SqSelect, &g_sLangTxt_Native_SqSelect);
	rs_AddString(g_sLangID_Native_SqValue, &g_sLangTxt_Native_SqValue);
	rs_AddString(g_sLangID_Native_AllowLiveTSelect, &g_sLangTxt_Native_AllowLiveTSelect);
	rs_AddString(g_sLangID_Native_AllowLiveT, &g_sLangTxt_Native_AllowLiveT);
	rs_AddString(g_sLangID_Native_DelegateSelect, &g_sLangTxt_Native_DelegateSelect);
	rs_AddString(g_sLangID_Native_TestMarkSelect, &g_sLangTxt_Native_TestMarkSelect);
	rs_AddString(g_sLangID_Native_Delegate, &g_sLangTxt_Native_Delegate);
	rs_AddString(g_sLangID_Native_TestMark, &g_sLangTxt_Native_TestMark);
	rs_AddString(g_sLangID_Native_VlanIDSelect, &g_sLangTxt_Native_VlanIDSelect);
	rs_AddString(g_sLangID_Native_VlanIDValue, &g_sLangTxt_Native_VlanIDValue);
	rs_AddString(g_sLangID_Native_NetIDSelect, &g_sLangTxt_Native_NetIDSelect);
	rs_AddString(g_sLangID_Native_NetIDValue, &g_sLangTxt_Native_NetIDValue);
	rs_AddString(g_sLangID_Native_ConfigVerSelect, &g_sLangTxt_Native_ConfigVerSelect);
	rs_AddString(g_sLangID_Native_ConfigVerValue, &g_sLangTxt_Native_ConfigVerValue);
	rs_AddString(g_sLangID_Native_NormalOpen1State, &g_sLangTxt_Native_NormalOpen1State);
	rs_AddString(g_sLangID_Native_NormalOpen2State, &g_sLangTxt_Native_NormalOpen2State);
	rs_AddString(g_sLangID_Native_NormalOpen3State, &g_sLangTxt_Native_NormalOpen3State);
	rs_AddString(g_sLangID_Native_NormalOpen4State, &g_sLangTxt_Native_NormalOpen4State);
	rs_AddString(g_sLangID_Native_NormalOpen5State, &g_sLangTxt_Native_NormalOpen5State);
	rs_AddString(g_sLangID_Native_NormalOpen6State, &g_sLangTxt_Native_NormalOpen6State);
	rs_AddString(g_sLangID_Native_NormalOpen7State, &g_sLangTxt_Native_NormalOpen7State);
	rs_AddString(g_sLangID_Native_NormalOpen8State, &g_sLangTxt_Native_NormalOpen8State);
	rs_AddString(g_sLangID_Native_FaultOpen1State, &g_sLangTxt_Native_FaultOpen1State);
	rs_AddString(g_sLangID_Native_FaultOpen2State, &g_sLangTxt_Native_FaultOpen2State);
	rs_AddString(g_sLangID_Native_FaultOpen3State, &g_sLangTxt_Native_FaultOpen3State);
	rs_AddString(g_sLangID_Native_FaultOpen4State, &g_sLangTxt_Native_FaultOpen4State);
	rs_AddString(g_sLangID_Native_FaultOpen5State, &g_sLangTxt_Native_FaultOpen5State);
	rs_AddString(g_sLangID_Native_FaultOpen6State, &g_sLangTxt_Native_FaultOpen6State);
	rs_AddString(g_sLangID_Native_FaultOpen7State, &g_sLangTxt_Native_FaultOpen7State);
	rs_AddString(g_sLangID_Native_FaultOpen8State, &g_sLangTxt_Native_FaultOpen8State);
	rs_AddString(g_sLangID_Native_HotOverloadTimeConst, &g_sLangTxt_Native_HotOverloadTimeConst);
	rs_AddString(g_sLangID_Native_HotOverloadBaseCurrent, &g_sLangTxt_Native_HotOverloadBaseCurrent);
	rs_AddString(g_sLangID_Native_HotOverloadActionValue, &g_sLangTxt_Native_HotOverloadActionValue);
	rs_AddString(g_sLangID_Native_OverloadCurrent, &g_sLangTxt_Native_OverloadCurrent);
	rs_AddString(g_sLangID_Native_FaultTimeMargin, &g_sLangTxt_Native_FaultTimeMargin);
	rs_AddString(g_sLangID_Native_CurrentChangeStartValue, &g_sLangTxt_Native_CurrentChangeStartValue);
	rs_AddString(g_sLangID_Native_CurrentChangeEndValue, &g_sLangTxt_Native_CurrentChangeEndValue);
	rs_AddString(g_sLangID_Native_CurrentChangeStep, &g_sLangTxt_Native_CurrentChangeStep);
	rs_AddString(g_sLangID_Native_HotOverloadTime, &g_sLangTxt_Native_HotOverloadTime);
	rs_AddString(g_sLangID_Native_HotOverloadBaseCurr, &g_sLangTxt_Native_HotOverloadBaseCurr);
	rs_AddString(g_sLangID_Native_HotOverloadActionValues, &g_sLangTxt_Native_HotOverloadActionValues);
	rs_AddString(g_sLangID_Native_ActionDesc, &g_sLangTxt_Native_ActionDesc);
	rs_AddString(g_sLangID_Native_FaultPreVoltageAmp, &g_sLangTxt_Native_FaultPreVoltageAmp);
	rs_AddString(g_sLangID_Native_FaultPreCurrentAmp, &g_sLangTxt_Native_FaultPreCurrentAmp);
	rs_AddString(g_sLangID_Native_FaultPreVoltageCurrentPhase, &g_sLangTxt_Native_FaultPreVoltageCurrentPhase);
	rs_AddString(g_sLangID_Native_FaultPreVoltageSeq, &g_sLangTxt_Native_FaultPreVoltageSeq);
	rs_AddString(g_sLangID_Native_FaultPreCurrentSeq, &g_sLangTxt_Native_FaultPreCurrentSeq);
	rs_AddString(g_sLangID_Native_FaultVoltage, &g_sLangTxt_Native_FaultVoltage);
	rs_AddString(g_sLangID_Native_FaultVoltageCurrentPhase, &g_sLangTxt_Native_FaultVoltageCurrentPhase);
	rs_AddString(g_sLangID_Native_ShortCircuitVoltageType, &g_sLangTxt_Native_ShortCircuitVoltageType);
	rs_AddString(g_sLangID_Native_ReferenceValue, &g_sLangTxt_Native_ReferenceValue);
	rs_AddString(g_sLangID_Native_CTPolarityPositive, &g_sLangTxt_Native_CTPolarityPositive);
	rs_AddString(g_sLangID_Native_PreFaultVCPAExpr, &g_sLangTxt_Native_PreFaultVCPAExpr);
	rs_AddString(g_sLangID_Native_ActionTimeSetValueExpr, &g_sLangTxt_Native_ActionTimeSetValueExpr);
	rs_AddString(g_sLangID_Native_FaultVoltageExpr, &g_sLangTxt_Native_FaultVoltageExpr);
	rs_AddString(g_sLangID_Native_FaultCurr, &g_sLangTxt_Native_FaultCurr);
	rs_AddString(g_sLangID_Native_FaultAngExp, &g_sLangTxt_Native_FaultAngExp);
	rs_AddString(g_sLangID_Native_CharCurveParam, &g_sLangTxt_Native_CharCurveParam);
	rs_AddString(g_sLangID_Native_VoltFreqRatio, &g_sLangTxt_Native_VoltFreqRatio);
	rs_AddString(g_sLangID_Native_ChangeMode, &g_sLangTxt_Native_ChangeMode);
	rs_AddString(g_sLangID_Native_CollectModPos, &g_sLangTxt_Native_CollectModPos);
	rs_AddString(g_sLangID_Native_CollectGear, &g_sLangTxt_Native_CollectGear);
	rs_AddString(g_sLangID_Native_ModPos, &g_sLangTxt_Native_ModPos);
	rs_AddString(g_sLangID_Native_TempZone, &g_sLangTxt_Native_TempZone);
	rs_AddString(g_sLangID_Native_MeterError, &g_sLangTxt_Native_MeterError);
	rs_AddString(g_sLangID_Native_RefFreq, &g_sLangTxt_Native_RefFreq);
	rs_AddString(g_sLangID_Native_Point1RefAmp, &g_sLangTxt_Native_Point1RefAmp);
	rs_AddString(g_sLangID_Native_Point2RefAmp, &g_sLangTxt_Native_Point2RefAmp);
	rs_AddString(g_sLangID_Native_Point1MeasAmp, &g_sLangTxt_Native_Point1MeasAmp);
	rs_AddString(g_sLangID_Native_Point2MeasAmp, &g_sLangTxt_Native_Point2MeasAmp);
	rs_AddString(g_sLangID_Native_OutputAmp, &g_sLangTxt_Native_OutputAmp);
	rs_AddString(g_sLangID_Native_PhaseMeasVal, &g_sLangTxt_Native_PhaseMeasVal);
	rs_AddString(g_sLangID_Native_MeasFreq, &g_sLangTxt_Native_MeasFreq);
	rs_AddString(g_sLangID_Native_ChannelHardGear, &g_sLangTxt_Native_ChannelHardGear);
	rs_AddString(g_sLangID_Native_ZeroDriftMeas, &g_sLangTxt_Native_ZeroDriftMeas);
	rs_AddString(g_sLangID_Native_Channel1ID, &g_sLangTxt_Native_Channel1ID);
	rs_AddString(g_sLangID_Native_Channel1Amp, &g_sLangTxt_Native_Channel1Amp);
	rs_AddString(g_sLangID_Native_Channel1Phase, &g_sLangTxt_Native_Channel1Phase);
	rs_AddString(g_sLangID_Native_Channel1Freq, &g_sLangTxt_Native_Channel1Freq);
	rs_AddString(g_sLangID_Native_Channel2Num, &g_sLangTxt_Native_Channel2Num);
	rs_AddString(g_sLangID_Native_Channel2Amp, &g_sLangTxt_Native_Channel2Amp);
	rs_AddString(g_sLangID_Native_Channel2Phase, &g_sLangTxt_Native_Channel2Phase);
	rs_AddString(g_sLangID_Native_Channel2Freq, &g_sLangTxt_Native_Channel2Freq);
	rs_AddString(g_sLangID_Native_Channel3Num, &g_sLangTxt_Native_Channel3Num);
	rs_AddString(g_sLangID_Native_Channel3Amp, &g_sLangTxt_Native_Channel3Amp);
	rs_AddString(g_sLangID_Native_Channel3Phase, &g_sLangTxt_Native_Channel3Phase);
	rs_AddString(g_sLangID_Native_Channel3Freq, &g_sLangTxt_Native_Channel3Freq);
	rs_AddString(g_sLangID_Native_IsHighCurrentCalib, &g_sLangTxt_Native_IsHighCurrentCalib);
	rs_AddString(g_sLangID_Native_Channel1AmpCoeff, &g_sLangTxt_Native_Channel1AmpCoeff);
	rs_AddString(g_sLangID_Native_Channel1ZeroOffset, &g_sLangTxt_Native_Channel1ZeroOffset);
	rs_AddString(g_sLangID_Native_Channel2AmpCoeff, &g_sLangTxt_Native_Channel2AmpCoeff);
	rs_AddString(g_sLangID_Native_Channel2ZeroOffset, &g_sLangTxt_Native_Channel2ZeroOffset);
	rs_AddString(g_sLangID_Native_Channel3AmpCoeff, &g_sLangTxt_Native_Channel3AmpCoeff);
	rs_AddString(g_sLangID_Native_Channel3ZeroOffset, &g_sLangTxt_Native_Channel3ZeroOffset);
	rs_AddString(g_sLangID_Native_WaveformSelection, &g_sLangTxt_Native_WaveformSelection);
	rs_AddString(g_sLangID_Native_Gear, &g_sLangTxt_Native_Gear);
	rs_AddString(g_sLangID_Native_ModuleNo2, &g_sLangTxt_Native_ModuleNo2);
	rs_AddString(g_sLangID_Native_TempZone2, &g_sLangTxt_Native_TempZone2);
	rs_AddString(g_sLangID_Native_ChannelNo2, &g_sLangTxt_Native_ChannelNo2);
	rs_AddString(g_sLangID_Native_Gear2, &g_sLangTxt_Native_Gear2);
	rs_AddString(g_sLangID_Native_OutputChannel, &g_sLangTxt_Native_OutputChannel);
	rs_AddString(g_sLangID_Native_HardwareGear, &g_sLangTxt_Native_HardwareGear);
	rs_AddString(g_sLangID_Native_ModuleNumber, &g_sLangTxt_Native_ModuleNumber);
	rs_AddString(g_sLangID_Native_SwitchMode, &g_sLangTxt_Native_SwitchMode);
	rs_AddString(g_sLangID_Native_Output1ConductValue, &g_sLangTxt_Native_Output1ConductValue);
	rs_AddString(g_sLangID_Native_Output2ConductValue, &g_sLangTxt_Native_Output2ConductValue);
	rs_AddString(g_sLangID_Native_Output3ConductValue, &g_sLangTxt_Native_Output3ConductValue);
	rs_AddString(g_sLangID_Native_Output4ConductValue, &g_sLangTxt_Native_Output4ConductValue);
	rs_AddString(g_sLangID_Native_Output5ConductValue, &g_sLangTxt_Native_Output5ConductValue);
	rs_AddString(g_sLangID_Native_Output6ConductValue, &g_sLangTxt_Native_Output6ConductValue);
	rs_AddString(g_sLangID_Native_Output7ConductValue, &g_sLangTxt_Native_Output7ConductValue);
	rs_AddString(g_sLangID_Native_Output8ConductValue, &g_sLangTxt_Native_Output8ConductValue);
	rs_AddString(g_sLangID_Native_RegAddrHex, &g_sLangTxt_Native_RegAddrHex);
	rs_AddString(g_sLangID_Native_RegValHex, &g_sLangTxt_Native_RegValHex);
	rs_AddString(g_sLangID_Native_Results, &g_sLangTxt_Native_Results);
	rs_AddString(g_sLangID_Native_FlipDelay, &g_sLangTxt_Native_FlipDelay);
	rs_AddString(g_sLangID_Native_InFlipCond, &g_sLangTxt_Native_InFlipCond);
	rs_AddString(g_sLangID_Native_IsSeqStateSeq, &g_sLangTxt_Native_IsSeqStateSeq);
	rs_AddString(g_sLangID_Native_RepeatCount, &g_sLangTxt_Native_RepeatCount);
	rs_AddString(g_sLangID_Native_StateNum, &g_sLangTxt_Native_StateNum);
	rs_AddString(g_sLangID_Native_InputExpand, &g_sLangTxt_Native_InputExpand);
	rs_AddString(g_sLangID_Native_NActionTime, &g_sLangTxt_Native_NActionTime);
	rs_AddString(g_sLangID_Native_LoopNum, &g_sLangTxt_Native_LoopNum);
	rs_AddString(g_sLangID_Native_StateNums, &g_sLangTxt_Native_StateNums);
	rs_AddString(g_sLangID_Native_OverCurrentI, &g_sLangTxt_Native_OverCurrentI);
	rs_AddString(g_sLangID_Native_OverCurrentII, &g_sLangTxt_Native_OverCurrentII);
	rs_AddString(g_sLangID_Native_OverCurrentIII, &g_sLangTxt_Native_OverCurrentIII);
	rs_AddString(g_sLangID_Native_OverCurrentIV, &g_sLangTxt_Native_OverCurrentIV);
	rs_AddString(g_sLangID_Native_OverCurrentITime, &g_sLangTxt_Native_OverCurrentITime);
	rs_AddString(g_sLangID_Native_OverCurrentIITime, &g_sLangTxt_Native_OverCurrentIITime);
	rs_AddString(g_sLangID_Native_OverCurrentIIITime, &g_sLangTxt_Native_OverCurrentIIITime);
	rs_AddString(g_sLangID_Native_OverCurrentIVTime, &g_sLangTxt_Native_OverCurrentIVTime);
	rs_AddString(g_sLangID_Native_Grouping, &g_sLangTxt_Native_Grouping);
	rs_AddString(g_sLangID_Native_SetActCurExp, &g_sLangTxt_Native_SetActCurExp);
	rs_AddString(g_sLangID_Native_OverCurrentValue, &g_sLangTxt_Native_OverCurrentValue);

	// 第八周吕
	// ly 8
	rs_AddString(g_sLangID_Native_volDefinition1, &g_sLangTxt_Native_volDefinition1);	  // 电压定义
	rs_AddString(g_sLangID_Native_refphase, &g_sLangTxt_Native_refphase);				  // 参考相
	rs_AddString(g_sLangID_Native_transfConnection, &g_sLangTxt_Native_transfConnection); // 变压器接线方式
	rs_AddString(g_sLangID_Native_maxSyncTime1, &g_sLangTxt_Native_maxSyncTime1);		  // 最大同步时间
	rs_AddString(g_sLangID_Native_breaker4HoldTime, &g_sLangTxt_Native_breaker4HoldTime); // 开出4保持时间
	rs_AddString(g_sLangID_Native_Grid_Vol, &g_sLangTxt_Native_Grid_Vol);				  // 待并侧电压
	rs_AddString(g_sLangID_Native_Grid_Freq, &g_sLangTxt_Native_Grid_Freq);				  // 待并侧频率
	rs_AddString(g_sLangID_Native_syncSignal, &g_sLangTxt_Native_syncSignal);			  // 同期信号
	rs_AddString(g_sLangID_Native_boostSignal, &g_sLangTxt_Native_boostSignal);			  // 增压信号
	rs_AddString(g_sLangID_Native_boostFreqSignal, &g_sLangTxt_Native_boostFreqSignal);	  // 增频信号
	rs_AddString(g_sLangID_Native_reducePresSignal, &g_sLangTxt_Native_reducePresSignal); // 减压信号
	rs_AddString(g_sLangID_Native_reduceFreqSignal, &g_sLangTxt_Native_reduceFreqSignal); // 减频信号
	rs_AddString(g_sLangID_Native_OutPut, &g_sLangTxt_Native_OutPut);					  // 开出%d

	rs_AddString(g_sLangID_Native_GvolChangeStep, &g_sLangTxt_Native_GvolChangeStep);		  // 待并侧电压变化步长
	rs_AddString(g_sLangID_Native_GridVol_Exp, &g_sLangTxt_Native_GridVol_Exp);				  // 待并侧电压(表达式)
	rs_AddString(g_sLangID_Native_GridFreq_Exp, &g_sLangTxt_Native_GridFreq_Exp);			  // 待并侧频率(表达式)
	rs_AddString(g_sLangID_Native_GvolChangeStepExp, &g_sLangTxt_Native_GvolChangeStepExp);	  // 待并侧电压变化步长(表达式)
	rs_AddString(g_sLangID_Native_GfreqChangeStep, &g_sLangTxt_Native_GfreqChangeStep);		  // 待并侧频率变化步长
	rs_AddString(g_sLangID_Native_GfreqChangeStepExp, &g_sLangTxt_Native_GfreqChangeStepExp); // 待并侧频率变化步长(表达式)

	rs_AddString(g_sLangID_Native_FreqSlip, &g_sLangTxt_Native_FreqSlip);						// 频率滑差
	rs_AddString(g_sLangID_Native_VoltSlip_Exp, &g_sLangTxt_Native_VoltSlip_Exp);				// 电压滑差(表达式)
	rs_AddString(g_sLangID_Native_FreqSlip_Exp, &g_sLangTxt_Native_FreqSlip_Exp);				// 频率滑差(表达式)
	rs_AddString(g_sLangID_Native_RegulatePulseWidth, &g_sLangTxt_Native_RegulatePulseWidth);	// 调压脉宽
	rs_AddString(g_sLangID_Native_FrequencyPulseWidth, &g_sLangTxt_Native_FrequencyPulseWidth); // 调频脉宽

	// 2
	rs_AddString(g_sLangID_Native_AngleStartPar1, &g_sLangTxt_Native_AngleStartPar1);				// 功角始值
	rs_AddString(g_sLangID_Native_AngleEndPar1, &g_sLangTxt_Native_AngleEndPar1);					// 功角终值(°)
	rs_AddString(g_sLangID_Native_OscilPeriod1, &g_sLangTxt_Native_OscilPeriod1);					// 振荡周期(s)
	rs_AddString(g_sLangID_Native_TripAccessPoint, &g_sLangTxt_Native_TripAccessPoint);				// 跳闸接入点
	rs_AddString(g_sLangID_Native_ReOscillat_ornot, &g_sLangTxt_Native_ReOscillat_ornot);			// 是否往复振荡
	rs_AddString(g_sLangID_Native_SpeedChange, &g_sLangTxt_Native_SpeedChange);						// 速度变化选择
	rs_AddString(g_sLangID_Native_ImpedanceChange_ornot, &g_sLangTxt_Native_ImpedanceChange_ornot); // 是否变阻抗
	rs_AddString(g_sLangID_Native_ImpedanceRateChange, &g_sLangTxt_Native_ImpedanceRateChange);		// 阻抗变化率

	rs_AddString(g_sLangID_Native_zeroseq_comp_calculat1, &g_sLangTxt_Native_zeroseq_comp_calculat1); // 零序补偿系数计算方式
	rs_AddString(g_sLangID_Native_ZeroSeqComp1, &g_sLangTxt_Native_ZeroSeqComp1);					  // 零序补偿系数(|K0|$KR$|Z0/Z1|)
	rs_AddString(g_sLangID_Native_ZeroSeqComp2, &g_sLangTxt_Native_ZeroSeqComp2);					  // 零序补偿系数(Phi(K0)$KX$Phi(Z0/Z1))
	rs_AddString(g_sLangID_Native_SysImpedAngle, &g_sLangTxt_Native_SysImpedAngle);					  // 系统侧阻抗角
	rs_AddString(g_sLangID_Native_TransImpedAngle, &g_sLangTxt_Native_TransImpedAngle);				  // 变压器阻抗角
	rs_AddString(g_sLangID_Native_GeneTransImped, &g_sLangTxt_Native_GeneTransImped);				  // 发电机暂态阻抗
	rs_AddString(g_sLangID_Out4_Situation, &g_sLangTxt_Out4_Situation);								  // 开出4状态
	rs_AddString(g_sLangID_Out5_Situation, &g_sLangTxt_Out5_Situation);								  // 开出5状态
	rs_AddString(g_sLangID_Out6_Situation, &g_sLangTxt_Out6_Situation);								  // 开出6状态
	rs_AddString(g_sLangID_Out7_Situation, &g_sLangTxt_Out7_Situation);								  // 开出7状态
	rs_AddString(g_sLangID_Out8_Situation, &g_sLangTxt_Out8_Situation);								  // 开出8状态
	rs_AddString(g_sLangID_Native_ProtRelayTime1, &g_sLangTxt_Native_ProtRelayTime1);				  // 保护出口时间
	rs_AddString(g_sLangID_Native_AccelSigOutTime1, &g_sLangTxt_Native_AccelSigOutTime1);			  // 加速信号出口时间
	rs_AddString(g_sLangID_Native_DecelSigOutTime1, &g_sLangTxt_Native_DecelSigOutTime1);			  // 减速信号出口时间

	// 3
	rs_AddString(g_sLangID_Native_VariablePhaseChange, &g_sLangTxt_Native_VariablePhaseChange);		// 递变相别
	rs_AddString(g_sLangID_Native_PreTestTimeS, &g_sLangTxt_Native_PreTestTimeS);					// 测试前时间(秒)
	rs_AddString(g_sLangID_Native_FaultPreTimeS, &g_sLangTxt_Native_FaultPreTimeS);					// 故障前时间(秒)
	rs_AddString(g_sLangID_Native_FaultPreUIPhaseAngle, &g_sLangTxt_Native_FaultPreUIPhaseAngle);	// 故障前电压电流相角(U-I)
	rs_AddString(g_sLangID_Native_VariableMode0123, &g_sLangTxt_Native_VariableMode0123);			// 递变模式(0-单机模式1-电压递变 2-电流递变 3-单机分组模式)
	rs_AddString(g_sLangID_Native_TestReturnCoefficient, &g_sLangTxt_Native_TestReturnCoefficient); // 测试返回系数
	rs_AddString(g_sLangID_Native_TestChannelType, &g_sLangTxt_Native_TestChannelType);				// 测试通道类型
	rs_AddString(g_sLangID_Native_VariableType, &g_sLangTxt_Native_VariableType);					// 递变类型

	rs_AddString(g_sLangID_Native_PhaseShiftDir01, &g_sLangTxt_Native_PhaseShiftDir01); // 相位递变方向(0:逆时针 1:顺时针)
	rs_AddString(g_sLangID_Native_IBeforeChange, &g_sLangTxt_Native_IBeforeChange);		// 变化前电流幅值
	rs_AddString(g_sLangID_Native_FaultGroup1VAmp, &g_sLangTxt_Native_FaultGroup1VAmp); // 故障态组1电压幅值
	rs_AddString(g_sLangID_Native_FaultGroup1IAmp, &g_sLangTxt_Native_FaultGroup1IAmp); // 故障态组1电压幅值

	rs_AddString(g_sLangID_Native_FaultGroupIPhaseDiff, &g_sLangTxt_Native_FaultGroupIPhaseDiff); // 故障态两组电流角差
	rs_AddString(g_sLangID_Native_FaultGroupFreq, &g_sLangTxt_Native_FaultGroupFreq);			  // 故障态频率
	rs_AddString(g_sLangID_Native_VActionValueAbsErr, &g_sLangTxt_Native_VActionValueAbsErr);	  // 电压动作值绝对误差
	rs_AddString(g_sLangID_Native_VActionValueRelErr, &g_sLangTxt_Native_VActionValueRelErr);	  // 电压动作值相对误差
	rs_AddString(g_sLangID_Native_VActionValueErrLogic, &g_sLangTxt_Native_VActionValueErrLogic); // 电压动作值误差判断逻辑
	rs_AddString(g_sLangID_Native_IActionValueAbsErr, &g_sLangTxt_Native_IActionValueAbsErr);	  // 电流动作值绝对误差
	rs_AddString(g_sLangID_Native_IActionValueRelErr, &g_sLangTxt_Native_IActionValueRelErr);	  // 电流动作值相对误差
	rs_AddString(g_sLangID_Native_IActionValueErrLogic, &g_sLangTxt_Native_IActionValueErrLogic); // 电流动作值误差判断逻辑
	rs_AddString(g_sLangID_Native_CoefficientAbsErr, &g_sLangTxt_Native_CoefficientAbsErr);		  // 返回系数绝对误差
	rs_AddString(g_sLangID_Native_CoefficientRelErr, &g_sLangTxt_Native_CoefficientRelErr);		  // 返回系数相对误差
	rs_AddString(g_sLangID_Native_CoefficientErrLogic, &g_sLangTxt_Native_CoefficientErrLogic);	  // 返回系数误差判断逻辑

	rs_AddString(g_sLangID_Native_relativeErr, &g_sLangTxt_Native_relativeErr);			  // 相对误差有效
	rs_AddString(g_sLangID_Native_criteria_logic, &g_sLangTxt_Native_criteria_logic);	  // 判据逻辑
	rs_AddString(g_sLangID_Native_VActionValueErr, &g_sLangTxt_Native_VActionValueErr);	  // 电压动作值误差
	rs_AddString(g_sLangID_Native_IActionValueErr, &g_sLangTxt_Native_IActionValueErr);	  // 电流动作值误差
	rs_AddString(g_sLangID_Native_input1_ActionVal, &g_sLangTxt_Native_input1_ActionVal); // 开入1动作值
	rs_AddString(g_sLangID_Native_input2_ActionVal, &g_sLangTxt_Native_input2_ActionVal); // 开入2动作值
	rs_AddString(g_sLangID_Native_input3_ActionVal, &g_sLangTxt_Native_input3_ActionVal); // 开入3动作值
	rs_AddString(g_sLangID_Native_input4_ActionVal, &g_sLangTxt_Native_input4_ActionVal); // 开入4动作值
	rs_AddString(g_sLangID_Native_input5_ActionVal, &g_sLangTxt_Native_input5_ActionVal); // 开入5动作值
	rs_AddString(g_sLangID_Native_input6_ActionVal, &g_sLangTxt_Native_input6_ActionVal); // 开入6动作值
	rs_AddString(g_sLangID_Native_input7_ActionVal, &g_sLangTxt_Native_input7_ActionVal); // 开入7动作值
	rs_AddString(g_sLangID_Native_input8_ActionVal, &g_sLangTxt_Native_input8_ActionVal); // 开入8动作值

	// 4
	rs_AddString(g_sLangID_Native_YNaging_test, &g_sLangTxt_Native_YNaging_test);					// 是否老化试验
	rs_AddString(g_sLangID_Native_varchannel_select, &g_sLangTxt_Native_varchannel_select);			// 递变通道选择
	rs_AddString(g_sLangID_Native_vartype_select, &g_sLangTxt_Native_vartype_select);				// 递变类型选择
	rs_AddString(g_sLangID_Native_change_mode, &g_sLangTxt_Native_change_mode);						// 变化模式
	rs_AddString(g_sLangID_Native_step_time, &g_sLangTxt_Native_step_time);							// 每步时间
	rs_AddString(g_sLangID_Native_trigger_delay, &g_sLangTxt_Native_trigger_delay);					// 触发延时
	rs_AddString(g_sLangID_Native_YN_locked, &g_sLangTxt_Native_YN_locked);							// 是否锁定
	rs_AddString(g_sLangID_Native_YN_autoevo, &g_sLangTxt_Native_YN_autoevo);						// 是否自动递变
	rs_AddString(g_sLangID_Native_max_outputtime, &g_sLangTxt_Native_max_outputtime);				// 最长输出时间(s)
	rs_AddString(g_sLangID_Native_acttuning_time, &g_sLangTxt_Native_acttuning_time);				// 动作整定时间
	rs_AddString(g_sLangID_Native_ActTimeValueAbsErr, &g_sLangTxt_Native_ActTimeValueAbsErr);		// 动作时间值绝对误差
	rs_AddString(g_sLangID_Native_ActTimeValueRelErr, &g_sLangTxt_Native_ActTimeValueRelErr);		// 动作时间值相对误差
	rs_AddString(g_sLangID_Native_ActTimeValueErrLogic, &g_sLangTxt_Native_ActTimeValueErrLogic);	// 动作时间误差判断逻辑
	rs_AddString(g_sLangID_Native_PhaseActValueAbsErr, &g_sLangTxt_Native_PhaseActValueAbsErr);		// 相位动作值绝对误差
	rs_AddString(g_sLangID_Native_PhaseActValueRelErr, &g_sLangTxt_Native_PhaseActValueRelErr);		// 相位动作值相对误差
	rs_AddString(g_sLangID_Native_PhaseActValueErrLogic, &g_sLangTxt_Native_PhaseActValueErrLogic); // 相位动作值误差判断逻辑
	rs_AddString(g_sLangID_Native_action_mark, &g_sLangTxt_Native_action_mark);						// 动作标记
	rs_AddString(g_sLangID_Native_result_status, &g_sLangTxt_Native_result_status);					// 结果状态
	rs_AddString(g_sLangID_Native_extend, &g_sLangTxt_Native_extend);								// 扩展%d

	// 5
	rs_AddString(g_sLangID_Native_KeepTime, &g_sLangTxt_Native_KeepTime);			  // 保持时间
	rs_AddString(g_sLangID_Native_SteadyTime, &g_sLangTxt_Native_SteadyTime);		  // 稳态时间
	rs_AddString(g_sLangID_Native_LowFreActValue, &g_sLangTxt_Native_LowFreActValue); // 低频动作值
	rs_AddString(g_sLangID_Native_InputASelect, &g_sLangTxt_Native_InputASelect);	  // 开入A-J选择
	rs_AddString(g_sLangID_Native_InputBSelect, &g_sLangTxt_Native_InputBSelect);
	rs_AddString(g_sLangID_Native_InputCSelect, &g_sLangTxt_Native_InputCSelect);
	rs_AddString(g_sLangID_Native_InputDSelect, &g_sLangTxt_Native_InputDSelect);
	rs_AddString(g_sLangID_Native_InputESelect, &g_sLangTxt_Native_InputESelect);
	rs_AddString(g_sLangID_Native_InputFSelect, &g_sLangTxt_Native_InputFSelect);
	rs_AddString(g_sLangID_Native_InputGSelect, &g_sLangTxt_Native_InputGSelect);
	rs_AddString(g_sLangID_Native_InputHSelect, &g_sLangTxt_Native_InputHSelect);
	rs_AddString(g_sLangID_Native_InputISelect, &g_sLangTxt_Native_InputISelect);
	rs_AddString(g_sLangID_Native_InputJSelect, &g_sLangTxt_Native_InputJSelect);

	rs_AddString(g_sLangID_Native_FreInitialValue, &g_sLangTxt_Native_FreInitialValue); // 频率变化始值
	rs_AddString(g_sLangID_Native_FreFinalValue, &g_sLangTxt_Native_FreFinalValue);		// 频率变化终值
	rs_AddString(g_sLangID_Native_FreChangeStep, &g_sLangTxt_Native_FreChangeStep);		// 频率变化步长
	rs_AddString(g_sLangID_Native_FreFinal, &g_sLangTxt_Native_FreFinal);				// 频率终值
	rs_AddString(g_sLangID_Native_IChangePhase, &g_sLangTxt_Native_IChangePhase);		// 电流变化相
	rs_AddString(g_sLangID_Native_SearchslipVal, &g_sLangTxt_Native_SearchslipVal);		// 当前搜索滑差值(dfdt)
	rs_AddString(g_sLangID_Native_KeepTimeExp, &g_sLangTxt_Native_KeepTimeExp);			// 保持时间(表达式)

	rs_AddString(g_sLangID_Native_FreInitialValueExp, &g_sLangTxt_Native_FreInitialValueExp);	// 频率变化始值(表达式)
	rs_AddString(g_sLangID_Native_FreFinalValueExp, &g_sLangTxt_Native_FreFinalValueExp);		// 频率变化终值(表达式)
	rs_AddString(g_sLangID_Native_FreChangeStepExp, &g_sLangTxt_Native_FreChangeStepExp);		// 频率变化步长(表达式)
	rs_AddString(g_sLangID_Native_SlipInitialValueExp, &g_sLangTxt_Native_SlipInitialValueExp); // 滑差变化始值(表达式)
	rs_AddString(g_sLangID_Native_SlipFinalValueExp, &g_sLangTxt_Native_SlipFinalValueExp);		// 滑差变化终值(表达式)
	rs_AddString(g_sLangID_Native_SlipChangeStepExp, &g_sLangTxt_Native_SlipChangeStepExp);		// 滑差变化步长(表达式)
	rs_AddString(g_sLangID_Native_IInitialValueExp, &g_sLangTxt_Native_IInitialValueExp);		// 电流变化始值(表达式)
	rs_AddString(g_sLangID_Native_IFinalValueExp, &g_sLangTxt_Native_IFinalValueExp);			// 电流变化终值(表达式)
	rs_AddString(g_sLangID_Native_IChangeStepExp, &g_sLangTxt_Native_IChangeStepExp);			// 电流变化步长(表达式)
	rs_AddString(g_sLangID_Native_VInitialValueExp, &g_sLangTxt_Native_VInitialValueExp);		// 电压变化始值(表达式)
	rs_AddString(g_sLangID_Native_VFinalValueExp, &g_sLangTxt_Native_VFinalValueExp);			// 电压变化终值(表达式)
	rs_AddString(g_sLangID_Native_VChangeStepExp, &g_sLangTxt_Native_VChangeStepExp);			// 电压变化步长(表达式)

	rs_AddString(g_sLangID_Native_FreActValue, &g_sLangTxt_Native_FreActValue);			// 频率动作值
	rs_AddString(g_sLangID_Native_LowCycleActDesc, &g_sLangTxt_Native_LowCycleActDesc); // 低周动作描述
	rs_AddString(g_sLangID_Native_SlipActValue, &g_sLangTxt_Native_SlipActValue);		// 滑差动作值
	rs_AddString(g_sLangID_Native_VBlockValue, &g_sLangTxt_Native_VBlockValue);			// 电压闭锁值
	rs_AddString(g_sLangID_Native_IBlockValue, &g_sLangTxt_Native_IBlockValue);			// 电流闭锁值

	// 6
	rs_AddString(g_sLangID_Native_VChangeRate_blockVal, &g_sLangTxt_Native_VChangeRate_blockVal); // 电压变化率闭锁值
	rs_AddString(g_sLangID_Native_SearchslipVal2, &g_sLangTxt_Native_SearchslipVal2);			  // 当前搜索滑差值(dvdt)
	rs_AddString(g_sLangID_Native_LowVActionDesc, &g_sLangTxt_Native_LowVActionDesc);			  // 低压动作描述
	rs_AddString(g_sLangID_Native_Uab1Amp, &g_sLangTxt_Native_Uab1Amp);							  // Uab1幅值
	rs_AddString(g_sLangID_Native_Uab1Ph, &g_sLangTxt_Native_Uab1Ph);							  // Uab1相位
	rs_AddString(g_sLangID_Native_Uab1Fre, &g_sLangTxt_Native_Uab1Fre);							  // Uab1频率
	rs_AddString(g_sLangID_Native_3U0_1Amp, &g_sLangTxt_Native_3U0_1Amp);						  // 3U0_1幅值
	rs_AddString(g_sLangID_Native_3U0_1Ph, &g_sLangTxt_Native_3U0_1Ph);							  // 3U0_1相位
	rs_AddString(g_sLangID_Native_3U0_1Fre, &g_sLangTxt_Native_3U0_1Fre);						  // 3U0_1频率
	rs_AddString(g_sLangID_Native_Uab2Amp, &g_sLangTxt_Native_Uab2Amp);							  // Uab2幅值
	rs_AddString(g_sLangID_Native_Uab2Ph, &g_sLangTxt_Native_Uab2Ph);							  // Uab2相位
	rs_AddString(g_sLangID_Native_Uab2Fre, &g_sLangTxt_Native_Uab2Fre);							  // Uab2频率
	rs_AddString(g_sLangID_Native_3U0_2Amp, &g_sLangTxt_Native_3U0_2Amp);						  // 3U0_2幅值
	rs_AddString(g_sLangID_Native_3U0_2Ph, &g_sLangTxt_Native_3U0_2Ph);							  // 3U0_2相位
	rs_AddString(g_sLangID_Native_3U0_2Fre, &g_sLangTxt_Native_3U0_2Fre);						  // 3U0_2频率
	rs_AddString(g_sLangID_Native_Ia1Fre, &g_sLangTxt_Native_Ia1Fre);							  // Ia1频率
	rs_AddString(g_sLangID_Native_Ib1Fre, &g_sLangTxt_Native_Ib1Fre);							  // Ib1频率
	rs_AddString(g_sLangID_Native_Ic1Fre, &g_sLangTxt_Native_Ic1Fre);							  // Ic1频率
	rs_AddString(g_sLangID_Native_Ia2Fre, &g_sLangTxt_Native_Ia2Fre);							  // Ia2频率
	rs_AddString(g_sLangID_Native_Ib2Fre, &g_sLangTxt_Native_Ib2Fre);							  // Ib2频率
	rs_AddString(g_sLangID_Native_Ic2Fre, &g_sLangTxt_Native_Ic2Fre);							  // Ic2频率
	rs_AddString(g_sLangID_Native_AuxiDCI, &g_sLangTxt_Native_AuxiDCI);							  // 辅助直流电流
	rs_AddString(g_sLangID_Native_AuxiDCV, &g_sLangTxt_Native_AuxiDCV);							  // 辅助直流电压

	rs_AddString(g_sLangID_Native_syspowerImp, &g_sLangTxt_Native_syspowerImp);						// 系统电源阻抗
	rs_AddString(g_sLangID_Native_syspowerImpangle, &g_sLangTxt_Native_syspowerImpangle);			// 系统电源阻抗角
	rs_AddString(g_sLangID_Native_syscomputModel012, &g_sLangTxt_Native_syscomputModel012);			// 系统计算模型(0-电流不变 1-电压不变 2-系统阻抗不变)
	rs_AddString(g_sLangID_Native_fault_switchtime, &g_sLangTxt_Native_fault_switchtime);			// 故障转换时间
	rs_AddString(g_sLangID_Native_switchErrtype, &g_sLangTxt_Native_switchErrtype);					// 转换故障类型
	rs_AddString(g_sLangID_Native_switchErr_shortImp, &g_sLangTxt_Native_switchErr_shortImp);		// 转换故障短路阻抗
	rs_AddString(g_sLangID_Native_switchErr_shortImpAng, &g_sLangTxt_Native_switchErr_shortImpAng); // 转换故障短路阻抗角
	rs_AddString(g_sLangID_Native_switchErr_shortI, &g_sLangTxt_Native_switchErr_shortI);			// 转换故障短路电流
	rs_AddString(g_sLangID_Native_switchErr_shortV, &g_sLangTxt_Native_switchErr_shortV);			// 转换故障短路电压
	rs_AddString(g_sLangID_Native_switchErr_direction, &g_sLangTxt_Native_switchErr_direction);		// 转换故障故障方向
	rs_AddString(g_sLangID_Native_testprocess, &g_sLangTxt_Native_testprocess);						// 试验过程
	rs_AddString(g_sLangID_Native_redundancy_mode, &g_sLangTxt_Native_redundancy_mode);				// 重合方式
	rs_AddString(g_sLangID_Native_redundancy_duration, &g_sLangTxt_Native_redundancy_duration);		// 重合持续时间
	rs_AddString(g_sLangID_Native_postswitch_duration, &g_sLangTxt_Native_postswitch_duration);		// 后加速开关跳开后持续时间

	// 9week ly
	rs_AddString(g_sLangID_Native_change_startangle, &g_sLangTxt_Native_change_startangle);			// 变化起始角度
	rs_AddString(g_sLangID_Native_change_endangle, &g_sLangTxt_Native_change_endangle);				// 变化终止角度
	rs_AddString(g_sLangID_Native_impedanceAng_measured, &g_sLangTxt_Native_impedanceAng_measured); // 待测阻抗角度定值
	rs_AddString(g_sLangID_Native_search_way, &g_sLangTxt_Native_search_way);						// 搜索方式
	rs_AddString(g_sLangID_Native_Zsearch_startAng, &g_sLangTxt_Native_Zsearch_startAng);			// Z搜索起点角度
	rs_AddString(g_sLangID_Native_Zsearch_startAct, &g_sLangTxt_Native_Zsearch_startAct);			// Z搜索起点动作
	rs_AddString(g_sLangID_Native_ZAng_currentVal, &g_sLangTxt_Native_ZAng_currentVal);				// Z当前值角度
	rs_AddString(g_sLangID_Native_Zsearch_endAng, &g_sLangTxt_Native_Zsearch_endAng);				// Z搜索终点角度
	rs_AddString(g_sLangID_Native_Zsearch_endAct, &g_sLangTxt_Native_Zsearch_endAct);				// Z搜索终点动作
	rs_AddString(g_sLangID_Native_action_impedance, &g_sLangTxt_Native_action_impedance);			// 动作阻抗
	rs_AddString(g_sLangID_Native_action_impedanceAng, &g_sLangTxt_Native_action_impedanceAng);		// 动作阻抗角
	rs_AddString(g_sLangID_Native_Desc_impedance_Act, &g_sLangTxt_Native_Desc_impedance_Act);		// 阻抗动作描述

	//
	rs_AddString(g_sLangID_Native_impedance_setting, &g_sLangTxt_Native_impedance_setting); // 阻抗定值
	rs_AddString(g_sLangID_Native_impedance_setExp, &g_sLangTxt_Native_impedance_setExp);	// 阻抗定值(表达式)
	//
	rs_AddString(g_sLangID_Native_ZeroSeqCompExp, &g_sLangTxt_Native_ZeroSeqCompExp);				// 零序补偿系数表达方式
	rs_AddString(g_sLangID_Native_ZeroSeqComp_RERL, &g_sLangTxt_Native_ZeroSeqComp_RERL);			// 零序补偿系数RE/RL
	rs_AddString(g_sLangID_Native_ZeroSeqComp_XEXL, &g_sLangTxt_Native_ZeroSeqComp_XEXL);			// 零序补偿系数XE/XL
	rs_AddString(g_sLangID_Native_load_current, &g_sLangTxt_Native_load_current);					// 负荷电流
	rs_AddString(g_sLangID_Native_loadpowerAng, &g_sLangTxt_Native_loadpowerAng);					// 负荷功角
	rs_AddString(g_sLangID_Native_PT_installPos, &g_sLangTxt_Native_PT_installPos);					// PT安装位置
	rs_AddString(g_sLangID_Native_closeAngmode01, &g_sLangTxt_Native_closeAngmode01);				// 合闸角方式( 0-随机 1-定值)
	rs_AddString(g_sLangID_Native_closing_angle, &g_sLangTxt_Native_closing_angle);					// 合闸角
	rs_AddString(g_sLangID_Native_Vz_outputDef, &g_sLangTxt_Native_Vz_outputDef);					// Vz输出定义
	rs_AddString(g_sLangID_Native_Vz_referPhase, &g_sLangTxt_Native_Vz_referPhase);					// Vz参考相
	rs_AddString(g_sLangID_Native_Vz_phase_angle, &g_sLangTxt_Native_Vz_phase_angle);				// Vz相角
	rs_AddString(g_sLangID_Native_reclose_timeset, &g_sLangTxt_Native_reclose_timeset);				// 重合闸时间定值
	rs_AddString(g_sLangID_Native_PostAccelerat_TimeSet, &g_sLangTxt_Native_PostAccelerat_TimeSet); // 后加速时间定值
	rs_AddString(g_sLangID_Native_auxiV_UxoutputMode, &g_sLangTxt_Native_auxiV_UxoutputMode);		// 辅助电压Ux 输出方式
	rs_AddString(g_sLangID_Native_synchronous_VAmp, &g_sLangTxt_Native_synchronous_VAmp);			// 同期电压幅值(检同期方式有效)
	rs_AddString(g_sLangID_Native_synchronous_VPh, &g_sLangTxt_Native_synchronous_VPh);				// 同期电压相位(检同期方式有效)
	rs_AddString(g_sLangID_Native_pressTestVal, &g_sLangTxt_Native_pressTestVal);					// 有压测试值
	rs_AddString(g_sLangID_Native_NOpressTestVal, &g_sLangTxt_Native_NOpressTestVal);				// 无压测试值
	rs_AddString(g_sLangID_Native_openflip_Control, &g_sLangTxt_Native_openflip_Control);			// 开出翻转控制方式
	rs_AddString(g_sLangID_Native_openflip_delay, &g_sLangTxt_Native_openflip_delay);				// 开出翻转延时
	rs_AddString(g_sLangID_Native_input_selection, &g_sLangTxt_Native_input_selection);				// 开入量选择
	rs_AddString(g_sLangID_Native_superimposed_ornot1, &g_sLangTxt_Native_superimposed_ornot1);		// 是否叠加非周期分量
	rs_AddString(g_sLangID_Native_jumpctrl, &g_sLangTxt_Native_jumpctrl);							// 跳合信号控制
	rs_AddString(g_sLangID_Native_timectrl, &g_sLangTxt_Native_timectrl);							// 时间控制
	rs_AddString(g_sLangID_Native_totalweight, &g_sLangTxt_Native_totalweight);						// 综重（单重+三重）
	rs_AddString(g_sLangID_Native_tripleweight, &g_sLangTxt_Native_tripleweight);					// 三重
	rs_AddString(g_sLangID_Native_norepeat, &g_sLangTxt_Native_norepeat);							// 不重合
	rs_AddString(g_sLangID_Native_Totransformer, &g_sLangTxt_Native_Totransformer);					// 指向变压器
	rs_AddString(g_sLangID_Native_lagrange, &g_sLangTxt_Native_lagrange);							// 拉格朗日插值法
	rs_AddString(g_sLangID_Native_linear, &g_sLangTxt_Native_linear);								// 线性插值法
	rs_AddString(g_sLangID_Native_faultvoltype, &g_sLangTxt_Native_faultvoltype);					// 故障电压类型
	rs_AddString(g_sLangID_Native_Difsetting, &g_sLangTxt_Native_Difsetting);						// 差动定值整定方式
	rs_AddString(g_sLangID_Native_DifCurChoose, &g_sLangTxt_Native_DifCurChoose);					// 差动基准电流选择
	rs_AddString(g_sLangID_Native_harmonicnumber, &g_sLangTxt_Native_harmonicnumber);				// 谐波次数选择
	rs_AddString(g_sLangID_Native_CuroutputPhase, &g_sLangTxt_Native_CuroutputPhase);				// 电流输出相
	rs_AddString(g_sLangID_Native_PhaseAshort, &g_sLangTxt_Native_PhaseAshort);						// A相短路
	rs_AddString(g_sLangID_Native_PhaseBshort, &g_sLangTxt_Native_PhaseBshort);						// B相短路
	rs_AddString(g_sLangID_Native_PhaseCshort, &g_sLangTxt_Native_PhaseCshort);						// C相短路
	rs_AddString(g_sLangID_Native_PhaseABCshort, &g_sLangTxt_Native_PhaseABCshort);					// ABC相短路

	// 第八周许
	rs_AddString(g_sLangID_Native_ExceptionMsgSet, &g_sLangTxt_Native_ExceptionMsgSet);
	rs_AddString(g_sLangID_Native_CharacteristicGraph, &g_sLangTxt_Native_CharacteristicGraph);
	rs_AddString(g_sLangID_Native_OV1SetValue, &g_sLangTxt_Native_OV1SetValue);
	rs_AddString(g_sLangID_Native_OV2SetValue, &g_sLangTxt_Native_OV2SetValue);
	rs_AddString(g_sLangID_Native_OV3SetValue, &g_sLangTxt_Native_OV3SetValue);
	rs_AddString(g_sLangID_Native_OV4SetValue, &g_sLangTxt_Native_OV4SetValue);
	rs_AddString(g_sLangID_Native_OV1Time, &g_sLangTxt_Native_OV1Time);
	rs_AddString(g_sLangID_Native_OV2Time, &g_sLangTxt_Native_OV2Time);
	rs_AddString(g_sLangID_Native_OV3Time, &g_sLangTxt_Native_OV3Time);
	rs_AddString(g_sLangID_Native_OV4Time, &g_sLangTxt_Native_OV4Time);
	rs_AddString(g_sLangID_Native_SimBrkDel, &g_sLangTxt_Native_SimBrkDel);
	rs_AddString(g_sLangID_Native_BrkTripDel, &g_sLangTxt_Native_BrkTripDel);
	rs_AddString(g_sLangID_Native_BrkClsDel, &g_sLangTxt_Native_BrkClsDel);
	rs_AddString(g_sLangID_Native_VoltType, &g_sLangTxt_Native_VoltType);
	rs_AddString(g_sLangID_Native_ActionVoltExpr, &g_sLangTxt_Native_ActionVoltExpr);
	rs_AddString(g_sLangID_Native_PhaseATime, &g_sLangTxt_Native_PhaseATime);
	rs_AddString(g_sLangID_Native_PhaseBTime, &g_sLangTxt_Native_PhaseBTime);
	rs_AddString(g_sLangID_Native_PhaseCTime, &g_sLangTxt_Native_PhaseCTime);
	rs_AddString(g_sLangID_Native_RecloseTime, &g_sLangTxt_Native_RecloseTime);
	rs_AddString(g_sLangID_Native_InputETime, &g_sLangTxt_Native_InputETime);
	rs_AddString(g_sLangID_Native_InputFTime, &g_sLangTxt_Native_InputFTime);
	rs_AddString(g_sLangID_Native_InputGTime, &g_sLangTxt_Native_InputGTime);
	rs_AddString(g_sLangID_Native_InputHTime, &g_sLangTxt_Native_InputHTime);
	rs_AddString(g_sLangID_Native_InputADesc, &g_sLangTxt_Native_InputADesc);
	rs_AddString(g_sLangID_Native_InputBDesc, &g_sLangTxt_Native_InputBDesc);
	rs_AddString(g_sLangID_Native_InputCDesc, &g_sLangTxt_Native_InputCDesc);
	rs_AddString(g_sLangID_Native_ReclActDesc, &g_sLangTxt_Native_ReclActDesc);
	rs_AddString(g_sLangID_Native_PostAccTime, &g_sLangTxt_Native_PostAccTime);
	rs_AddString(g_sLangID_Native_PostAccDesc, &g_sLangTxt_Native_PostAccDesc);
	rs_AddString(g_sLangID_Native_ActShortCur, &g_sLangTxt_Native_ActShortCur);
	rs_AddString(g_sLangID_Native_ActShortVol, &g_sLangTxt_Native_ActShortVol);
	rs_AddString(g_sLangID_Native_OverVoltVal, &g_sLangTxt_Native_OverVoltVal);
	rs_AddString(g_sLangID_Native_UaInitVal, &g_sLangTxt_Native_UaInitVal);
	rs_AddString(g_sLangID_Native_UbInitVal, &g_sLangTxt_Native_UbInitVal);
	rs_AddString(g_sLangID_Native_UcInitVal, &g_sLangTxt_Native_UcInitVal);
	rs_AddString(g_sLangID_Native_UzInitVal, &g_sLangTxt_Native_UzInitVal);
	rs_AddString(g_sLangID_Native_IaInitVal, &g_sLangTxt_Native_IaInitVal);
	rs_AddString(g_sLangID_Native_IbInitVal, &g_sLangTxt_Native_IbInitVal);
	rs_AddString(g_sLangID_Native_IcInitVal, &g_sLangTxt_Native_IcInitVal);
	rs_AddString(g_sLangID_Native_CurveSegments, &g_sLangTxt_Native_CurveSegments);
	rs_AddString(g_sLangID_Native_VarChnl, &g_sLangTxt_Native_VarChnl);
	rs_AddString(g_sLangID_Native_TimingCurve, &g_sLangTxt_Native_TimingCurve);
	rs_AddString(g_sLangID_Native_VarSel, &g_sLangTxt_Native_VarSel);
	rs_AddString(g_sLangID_Native_TransType, &g_sLangTxt_Native_TransType);
	rs_AddString(g_sLangID_Native_CurveSelect, &g_sLangTxt_Native_CurveSelect);
	rs_AddString(g_sLangID_Native_StartValue, &g_sLangTxt_Native_StartValue);
	rs_AddString(g_sLangID_Native_EndValue, &g_sLangTxt_Native_EndValue);
	rs_AddString(g_sLangID_Native_StepSize, &g_sLangTxt_Native_StepSize);
	rs_AddString(g_sLangID_Native_Curve, &g_sLangTxt_Native_Curve);
	rs_AddString(g_sLangID_Native_Slope, &g_sLangTxt_Native_Slope);
	rs_AddString(g_sLangID_Native_OutputTimems, &g_sLangTxt_Native_OutputTimems);
	rs_AddString(g_sLangID_Native_SearchStart, &g_sLangTxt_Native_SearchStart);
	rs_AddString(g_sLangID_Native_CurrentValue, &g_sLangTxt_Native_CurrentValue);
	rs_AddString(g_sLangID_Native_SearchEnd, &g_sLangTxt_Native_SearchEnd);
	rs_AddString(g_sLangID_Native_SearchLen, &g_sLangTxt_Native_SearchLen);
	rs_AddString(g_sLangID_Native_AutoSearch, &g_sLangTxt_Native_AutoSearch);
	rs_AddString(g_sLangID_Native_ComplexBrakeCurrent, &g_sLangTxt_Native_ComplexBrakeCurrent);
	rs_AddString(g_sLangID_Native_DiffCurrentSetVal, &g_sLangTxt_Native_DiffCurrentSetVal);
	rs_AddString(g_sLangID_Native_DiffType, &g_sLangTxt_Native_DiffType);
	rs_AddString(g_sLangID_Native_UaAmplitude, &g_sLangTxt_Native_UaAmplitude);
	rs_AddString(g_sLangID_Native_UbAmplitude, &g_sLangTxt_Native_UbAmplitude);
	rs_AddString(g_sLangID_Native_UcAmplitude, &g_sLangTxt_Native_UcAmplitude);
	rs_AddString(g_sLangID_Native_UaPhase, &g_sLangTxt_Native_UaPhase);
	rs_AddString(g_sLangID_Native_UbPhase, &g_sLangTxt_Native_UbPhase);
	rs_AddString(g_sLangID_Native_UcPhase, &g_sLangTxt_Native_UcPhase);
	rs_AddString(g_sLangID_Native_Gap1TARatio, &g_sLangTxt_Native_Gap1TARatio);
	rs_AddString(g_sLangID_Native_Gap2TARatio, &g_sLangTxt_Native_Gap2TARatio);
	rs_AddString(g_sLangID_Native_Gap3TARatio, &g_sLangTxt_Native_Gap3TARatio);
	rs_AddString(g_sLangID_Native_MaxTARatio, &g_sLangTxt_Native_MaxTARatio);
	rs_AddString(g_sLangID_Native_DiffThreshCurrent, &g_sLangTxt_Native_DiffThreshCurrent);
	rs_AddString(g_sLangID_Native_HighCompRatioCoef, &g_sLangTxt_Native_HighCompRatioCoef);
	rs_AddString(g_sLangID_Native_LowCompRatioCoef, &g_sLangTxt_Native_LowCompRatioCoef);
	rs_AddString(g_sLangID_Native_DiffActionVal, &g_sLangTxt_Native_DiffActionVal);
	rs_AddString(g_sLangID_Native_CurrSearchVal, &g_sLangTxt_Native_CurrSearchVal);
	rs_AddString(g_sLangID_Native_DiffActionDesc, &g_sLangTxt_Native_DiffActionDesc);
	rs_AddString(g_sLangID_Native_VoltLockElem, &g_sLangTxt_Native_VoltLockElem);
	rs_AddString(g_sLangID_Native_LockVoltValue, &g_sLangTxt_Native_LockVoltValue);
	rs_AddString(g_sLangID_Native_BrkCoeffType, &g_sLangTxt_Native_BrkCoeffType);
	rs_AddString(g_sLangID_Native_DiffCurrentIds, &g_sLangTxt_Native_DiffCurrentIds);
	rs_AddString(g_sLangID_Native_CompBrakeCurr, &g_sLangTxt_Native_CompBrakeCurr);
	rs_AddString(g_sLangID_Native_IrBrakeEq, &g_sLangTxt_Native_IrBrakeEq);
	rs_AddString(g_sLangID_Native_FirstVoltNormOutput, &g_sLangTxt_Native_FirstVoltNormOutput);
	rs_AddString(g_sLangID_Native_SecondVoltNormOutput, &g_sLangTxt_Native_SecondVoltNormOutput);
	rs_AddString(g_sLangID_Native_VoltFaultState, &g_sLangTxt_Native_VoltFaultState);
	rs_AddString(g_sLangID_Native_VoltFaultState2, &g_sLangTxt_Native_VoltFaultState2);
	rs_AddString(g_sLangID_Native_BalanceMode, &g_sLangTxt_Native_BalanceMode);
	rs_AddString(g_sLangID_Native_HVBalanceCoeff, &g_sLangTxt_Native_HVBalanceCoeff);
	rs_AddString(g_sLangID_Native_MVBalanceCoeff, &g_sLangTxt_Native_MVBalanceCoeff);
	rs_AddString(g_sLangID_Native_LVBalanceCoeff, &g_sLangTxt_Native_LVBalanceCoeff);
	rs_AddString(g_sLangID_Native_HVCTRatio, &g_sLangTxt_Native_HVCTRatio);
	rs_AddString(g_sLangID_Native_MVCTRatio, &g_sLangTxt_Native_MVCTRatio);
	rs_AddString(g_sLangID_Native_LVCTRatio, &g_sLangTxt_Native_LVCTRatio);
	rs_AddString(g_sLangID_Native_TestCoil, &g_sLangTxt_Native_TestCoil);
	rs_AddString(g_sLangID_Native_ProtPhaseCorr, &g_sLangTxt_Native_ProtPhaseCorr);
	rs_AddString(g_sLangID_Native_BaseCurrSet, &g_sLangTxt_Native_BaseCurrSet);
	rs_AddString(g_sLangID_Native_DiffQuickBreakCurr, &g_sLangTxt_Native_DiffQuickBreakCurr);
	rs_AddString(g_sLangID_Native_RatioBrakeTurnPts, &g_sLangTxt_Native_RatioBrakeTurnPts);
	rs_AddString(g_sLangID_Native_RatioBrakeTurn1Curr, &g_sLangTxt_Native_RatioBrakeTurn1Curr);
	rs_AddString(g_sLangID_Native_RatioBrakeTurn2Curr, &g_sLangTxt_Native_RatioBrakeTurn2Curr);
	rs_AddString(g_sLangID_Native_RatioBrakeTurn3Curr, &g_sLangTxt_Native_RatioBrakeTurn3Curr);
	rs_AddString(g_sLangID_Native_HarmonicBrakeCoeff, &g_sLangTxt_Native_HarmonicBrakeCoeff);
	rs_AddString(g_sLangID_Native_HarmonicBrakeDesc, &g_sLangTxt_Native_HarmonicBrakeDesc);
	rs_AddString(g_sLangID_Native_PhaseACurrent, &g_sLangTxt_Native_PhaseACurrent);
	rs_AddString(g_sLangID_Native_PhaseBCurrent, &g_sLangTxt_Native_PhaseBCurrent);
	rs_AddString(g_sLangID_Native_PhaseCCurrent, &g_sLangTxt_Native_PhaseCCurrent);
	rs_AddString(g_sLangID_Native_PhaseAHarmCur, &g_sLangTxt_Native_PhaseAHarmCur);
	rs_AddString(g_sLangID_Native_BHarmonicCurrent, &g_sLangTxt_Native_BHarmonicCurrent);
	rs_AddString(g_sLangID_Native_CHarmonicCurrent, &g_sLangTxt_Native_CHarmonicCurrent);
	rs_AddString(g_sLangID_Native_FirstGroupVoltageOut, &g_sLangTxt_Native_FirstGroupVoltageOut);
	rs_AddString(g_sLangID_Native_SecondGroupVoltageOut, &g_sLangTxt_Native_SecondGroupVoltageOut);
	rs_AddString(g_sLangID_Native_HVCTConnectionMode, &g_sLangTxt_Native_HVCTConnectionMode);
	rs_AddString(g_sLangID_Native_BalanceCoeffCalcMethod, &g_sLangTxt_Native_BalanceCoeffCalcMethod);
	rs_AddString(g_sLangID_Native_UnderTestValue, &g_sLangTxt_Native_UnderTestValue);
	rs_AddString(g_sLangID_Native_FaultImpedanceAngle, &g_sLangTxt_Native_FaultImpedanceAngle);
	rs_AddString(g_sLangID_Native_PTLineSimulate, &g_sLangTxt_Native_PTLineSimulate);
	rs_AddString(g_sLangID_Native_PTLineSimPhase, &g_sLangTxt_Native_PTLineSimPhase);
	rs_AddString(g_sLangID_Native_VarStartValue, &g_sLangTxt_Native_VarStartValue);
	rs_AddString(g_sLangID_Native_VarEndValue, &g_sLangTxt_Native_VarEndValue);
	rs_AddString(g_sLangID_Native_StepTime, &g_sLangTxt_Native_StepTime);
	rs_AddString(g_sLangID_Native_ShortVolt, &g_sLangTxt_Native_ShortVolt);
	rs_AddString(g_sLangID_Native_ShortCurr, &g_sLangTxt_Native_ShortCurr);
	rs_AddString(g_sLangID_Native_BoundaryAngle1, &g_sLangTxt_Native_BoundaryAngle1);
	rs_AddString(g_sLangID_Native_BoundaryAngle2, &g_sLangTxt_Native_BoundaryAngle2);
	rs_AddString(g_sLangID_Native_StepTimes, &g_sLangTxt_Native_StepTimes);
	rs_AddString(g_sLangID_Native_ShortCircuit, &g_sLangTxt_Native_ShortCircuit);
	rs_AddString(g_sLangID_Native_ImpedanceAngles, &g_sLangTxt_Native_ImpedanceAngles);
	rs_AddString(g_sLangID_Native_TestReturnValue, &g_sLangTxt_Native_TestReturnValue);
	rs_AddString(g_sLangID_Native_LowVoltagev, &g_sLangTxt_Native_LowVoltagev);
	rs_AddString(g_sLangID_Native_NegativeSeqVolt, &g_sLangTxt_Native_NegativeSeqVolt);
	rs_AddString(g_sLangID_Native_ActionCurrent, &g_sLangTxt_Native_ActionCurrent);
	rs_AddString(g_sLangID_Native_DelayTimes, &g_sLangTxt_Native_DelayTimes);
	rs_AddString(g_sLangID_Native_ActionAreaSize, &g_sLangTxt_Native_ActionAreaSize);
	rs_AddString(g_sLangID_Native_ImpedanceAnglexp, &g_sLangTxt_Native_ImpedanceAnglexp);
	rs_AddString(g_sLangID_Native_TestOutMode, &g_sLangTxt_Native_TestOutMode);
	rs_AddString(g_sLangID_Native_RatedVoltVal, &g_sLangTxt_Native_RatedVoltVal);
	rs_AddString(g_sLangID_Native_RatedCurrVal, &g_sLangTxt_Native_RatedCurrVal);
	rs_AddString(g_sLangID_Native_FirstPTVal, &g_sLangTxt_Native_FirstPTVal);
	rs_AddString(g_sLangID_Native_SecPTVal, &g_sLangTxt_Native_SecPTVal);
	rs_AddString(g_sLangID_Native_FirstCTVal, &g_sLangTxt_Native_FirstCTVal);
	rs_AddString(g_sLangID_Native_SecCTVal, &g_sLangTxt_Native_SecCTVal);
	rs_AddString(g_sLangID_Native_MsgFormat, &g_sLangTxt_Native_MsgFormat);
	rs_AddString(g_sLangID_Native_WeakSigOutSet, &g_sLangTxt_Native_WeakSigOutSet);
	rs_AddString(g_sLangID_Native_1588RecvOptPort, &g_sLangTxt_Native_1588RecvOptPort);
	rs_AddString(g_sLangID_Native_1588SyncMech, &g_sLangTxt_Native_1588SyncMech);
	rs_AddString(g_sLangID_Native_ParamSel, &g_sLangTxt_Native_ParamSel);
	rs_AddString(g_sLangID_Native_MsgOutSel, &g_sLangTxt_Native_MsgOutSel);
	rs_AddString(g_sLangID_Native_BCodeLogics, &g_sLangTxt_Native_BCodeLogics);
	rs_AddString(g_sLangID_Native_FiberConn, &g_sLangTxt_Native_FiberConn);
	rs_AddString(g_sLangID_Native_GroupCurrMod, &g_sLangTxt_Native_GroupCurrMod);
	rs_AddString(g_sLangID_Native_CurrModPos, &g_sLangTxt_Native_CurrModPos);
	rs_AddString(g_sLangID_Native_CurrModGearVal, &g_sLangTxt_Native_CurrModGearVal);
	rs_AddString(g_sLangID_Native_CurrChanMaxVolt, &g_sLangTxt_Native_CurrChanMaxVolt);
	rs_AddString(g_sLangID_Native_MergeCurrTerm, &g_sLangTxt_Native_MergeCurrTerm);
	rs_AddString(g_sLangID_Native_CurrModCount, &g_sLangTxt_Native_CurrModCount);
	rs_AddString(g_sLangID_Native_WirelessNet, &g_sLangTxt_Native_WirelessNet);
	rs_AddString(g_sLangID_Native_WiredNet, &g_sLangTxt_Native_WiredNet);
	rs_AddString(g_sLangID_Native_LcdBacklightTime, &g_sLangTxt_Native_LcdBacklightTime);
	rs_AddString(g_sLangID_Native_TouchSensitivity, &g_sLangTxt_Native_TouchSensitivity);
	rs_AddString(g_sLangID_Native_CurrentActionError, &g_sLangTxt_Native_CurrentActionError);
	rs_AddString(g_sLangID_Native_CurrentActionRelError, &g_sLangTxt_Native_CurrentActionRelError);
	rs_AddString(g_sLangID_Native_VoltageActionError, &g_sLangTxt_Native_VoltageActionError);
	rs_AddString(g_sLangID_Native_VoltageActionRelError, &g_sLangTxt_Native_VoltageActionRelError);
	rs_AddString(g_sLangID_Native_ImpedanceActionError, &g_sLangTxt_Native_ImpedanceActionError);
	rs_AddString(g_sLangID_Native_ImpedanceActionRelError, &g_sLangTxt_Native_ImpedanceActionRelError);
	rs_AddString(g_sLangID_Native_ActionTimeAbsError, &g_sLangTxt_Native_ActionTimeAbsError);
	rs_AddString(g_sLangID_Native_ActionTimeRelError, &g_sLangTxt_Native_ActionTimeRelError);
	rs_AddString(g_sLangID_Native_PhaseErrorValue, &g_sLangTxt_Native_PhaseErrorValue);
	rs_AddString(g_sLangID_Native_FreqErrorValue, &g_sLangTxt_Native_FreqErrorValue);
	rs_AddString(g_sLangID_Native_VoltSlipErrorValue, &g_sLangTxt_Native_VoltSlipErrorValue);
	rs_AddString(g_sLangID_Native_FreqSlipErrorValue, &g_sLangTxt_Native_FreqSlipErrorValue);
	rs_AddString(g_sLangID_Native_DiffRatioBrakeAbsError, &g_sLangTxt_Native_DiffRatioBrakeAbsError);
	rs_AddString(g_sLangID_Native_DiffRatioBrakeRelError, &g_sLangTxt_Native_DiffRatioBrakeRelError);
	rs_AddString(g_sLangID_Native_DiffHarmonicBrakeAbsError, &g_sLangTxt_Native_DiffHarmonicBrakeAbsError);
	rs_AddString(g_sLangID_Native_DiffHarmonicBrakeRelError, &g_sLangTxt_Native_DiffHarmonicBrakeRelError);
	rs_AddString(g_sLangID_Native_AuxDcVoltageValue, &g_sLangTxt_Native_AuxDcVoltageValue);
	rs_AddString(g_sLangID_Native_AuxDcCurrentValue, &g_sLangTxt_Native_AuxDcCurrentValue);
	rs_AddString(g_sLangID_Native_VoltageRatioPrimary1, &g_sLangTxt_Native_VoltageRatioPrimary1);
	rs_AddString(g_sLangID_Native_VoltageRatioPrimary2, &g_sLangTxt_Native_VoltageRatioPrimary2);
	rs_AddString(g_sLangID_Native_VoltageRatioPrimary3, &g_sLangTxt_Native_VoltageRatioPrimary3);
	rs_AddString(g_sLangID_Native_VoltageRatioPrimary4, &g_sLangTxt_Native_VoltageRatioPrimary4);
	rs_AddString(g_sLangID_Native_VoltageRatioPrimary5, &g_sLangTxt_Native_VoltageRatioPrimary5);
	rs_AddString(g_sLangID_Native_VoltageRatioPrimary6, &g_sLangTxt_Native_VoltageRatioPrimary6);
	rs_AddString(g_sLangID_Native_VoltageRatioSecondary1, &g_sLangTxt_Native_VoltageRatioSecondary1);
	rs_AddString(g_sLangID_Native_VoltageRatioSecondary2, &g_sLangTxt_Native_VoltageRatioSecondary2);
	rs_AddString(g_sLangID_Native_VoltageRatioSecondary3, &g_sLangTxt_Native_VoltageRatioSecondary3);
	rs_AddString(g_sLangID_Native_VoltageRatioSecondary4, &g_sLangTxt_Native_VoltageRatioSecondary4);
	rs_AddString(g_sLangID_Native_VoltageRatioSecondary5, &g_sLangTxt_Native_VoltageRatioSecondary5);
	rs_AddString(g_sLangID_Native_VoltageRatioSecondary6, &g_sLangTxt_Native_VoltageRatioSecondary6);
	rs_AddString(g_sLangID_Native_CurrentRatioPrimary1, &g_sLangTxt_Native_CurrentRatioPrimary1);
	rs_AddString(g_sLangID_Native_CurrentRatioPrimary2, &g_sLangTxt_Native_CurrentRatioPrimary2);
	rs_AddString(g_sLangID_Native_CurrentRatioPrimary3, &g_sLangTxt_Native_CurrentRatioPrimary3);
	rs_AddString(g_sLangID_Native_CurrentRatioPrimary4, &g_sLangTxt_Native_CurrentRatioPrimary4);
	rs_AddString(g_sLangID_Native_CurrentRatioPrimary5, &g_sLangTxt_Native_CurrentRatioPrimary5);
	rs_AddString(g_sLangID_Native_CurrentRatioPrimary6, &g_sLangTxt_Native_CurrentRatioPrimary6);
	rs_AddString(g_sLangID_Native_CurrentRatioSecondary1, &g_sLangTxt_Native_CurrentRatioSecondary1);
	rs_AddString(g_sLangID_Native_CurrentRatioSecondary2, &g_sLangTxt_Native_CurrentRatioSecondary2);
	rs_AddString(g_sLangID_Native_CurrentRatioSecondary3, &g_sLangTxt_Native_CurrentRatioSecondary3);
	rs_AddString(g_sLangID_Native_CurrentRatioSecondary4, &g_sLangTxt_Native_CurrentRatioSecondary4);
	rs_AddString(g_sLangID_Native_CurrentRatioSecondary5, &g_sLangTxt_Native_CurrentRatioSecondary5);
	rs_AddString(g_sLangID_Native_CurrentRatioSecondary6, &g_sLangTxt_Native_CurrentRatioSecondary6);
	rs_AddString(g_sLangID_Native_OutputAnalog, &g_sLangTxt_Native_OutputAnalog);
	rs_AddString(g_sLangID_Native_OutputDigital, &g_sLangTxt_Native_OutputDigital);
	rs_AddString(g_sLangID_Native_OutputWeakSig, &g_sLangTxt_Native_OutputWeakSig);
	rs_AddString(g_sLangID_Native_RatedLineVolt, &g_sLangTxt_Native_RatedLineVolt);
	rs_AddString(g_sLangID_Native_RatedZeroVolt, &g_sLangTxt_Native_RatedZeroVolt);
	rs_AddString(g_sLangID_Native_RatedZeroCurr, &g_sLangTxt_Native_RatedZeroCurr);
	rs_AddString(g_sLangID_Native_StartOverloadDelay, &g_sLangTxt_Native_StartOverloadDelay);
	rs_AddString(g_sLangID_Native_CheckTestEndHeartbeat, &g_sLangTxt_Native_CheckTestEndHeartbeat);
	rs_AddString(g_sLangID_Native_UseAnalogCapture, &g_sLangTxt_Native_UseAnalogCapture);
	rs_AddString(g_sLangID_Native_UseDigitalCapture, &g_sLangTxt_Native_UseDigitalCapture);
	rs_AddString(g_sLangID_Native_UseSmallSignalCapture, &g_sLangTxt_Native_UseSmallSignalCapture);
	rs_AddString(g_sLangID_Native_DigitalCaptureMsgType, &g_sLangTxt_Native_DigitalCaptureMsgType);
	rs_AddString(g_sLangID_Native_BCodeReceiveLogic, &g_sLangTxt_Native_BCodeReceiveLogic);
	rs_AddString(g_sLangID_Native_ReportExtInQty, &g_sLangTxt_Native_ReportExtInQty);
	rs_AddString(g_sLangID_Native_BaseReportTimeZone, &g_sLangTxt_Native_BaseReportTimeZone);
	rs_AddString(g_sLangID_Native_GPStoBCodeUserTZ, &g_sLangTxt_Native_GPStoBCodeUserTZ);
	rs_AddString(g_sLangID_Native_MachineFanMode, &g_sLangTxt_Native_MachineFanMode);
	rs_AddString(g_sLangID_Native_AmplitudeGradual, &g_sLangTxt_Native_AmplitudeGradual);
	rs_AddString(g_sLangID_Native_AmplitudeEndValue, &g_sLangTxt_Native_AmplitudeEndValue);
	rs_AddString(g_sLangID_Native_AmplitudeStep, &g_sLangTxt_Native_AmplitudeStep);
	rs_AddString(g_sLangID_Native_PhaseFlag, &g_sLangTxt_Native_PhaseFlag);
	rs_AddString(g_sLangID_Native_PhaseEndVal, &g_sLangTxt_Native_PhaseEndVal);
	rs_AddString(g_sLangID_Native_PhaseStep, &g_sLangTxt_Native_PhaseStep);
	rs_AddString(g_sLangID_Native_FreqFlag, &g_sLangTxt_Native_FreqFlag);
	rs_AddString(g_sLangID_Native_FreqEnd, &g_sLangTxt_Native_FreqEnd);
	rs_AddString(g_sLangID_Native_FreqStep, &g_sLangTxt_Native_FreqStep);
	rs_AddString(g_sLangID_Native_IsSelected, &g_sLangTxt_Native_IsSelected);
	rs_AddString(g_sLangID_Native_OpenState, &g_sLangTxt_Native_OpenState);
	rs_AddString(g_sLangID_Native_DCOverlay, &g_sLangTxt_Native_DCOverlay);
	rs_AddString(g_sLangID_Native_DCDampTime, &g_sLangTxt_Native_DCDampTime);
	rs_AddString(g_sLangID_Native_EnableEval, &g_sLangTxt_Native_EnableEval);
	rs_AddString(g_sLangID_Native_TimeStartState, &g_sLangTxt_Native_TimeStartState);
	rs_AddString(g_sLangID_Native_TimeEndState, &g_sLangTxt_Native_TimeEndState);
	rs_AddString(g_sLangID_Native_TimeStartInput, &g_sLangTxt_Native_TimeStartInput);
	rs_AddString(g_sLangID_Native_TimeEndInput, &g_sLangTxt_Native_TimeEndInput);
	rs_AddString(g_sLangID_Native_AbsErrorLimit, &g_sLangTxt_Native_AbsErrorLimit);
	rs_AddString(g_sLangID_Native_RelErrorLimit, &g_sLangTxt_Native_RelErrorLimit);
	rs_AddString(g_sLangID_Native_JudgeLogic, &g_sLangTxt_Native_JudgeLogic);
	rs_AddString(g_sLangID_Native_StepChangeID, &g_sLangTxt_Native_StepChangeID);
	rs_AddString(g_sLangID_Native_CustomActTime, &g_sLangTxt_Native_CustomActTime);
	rs_AddString(g_sLangID_Native_AbsError, &g_sLangTxt_Native_AbsError);
	rs_AddString(g_sLangID_Native_RelError, &g_sLangTxt_Native_RelError);
	rs_AddString(g_sLangID_Native_CurrLoop, &g_sLangTxt_Native_CurrLoop);
	rs_AddString(g_sLangID_Native_TrigModes, &g_sLangTxt_Native_TrigModes);
	rs_AddString(g_sLangID_Native_HwSelect, &g_sLangTxt_Native_HwSelect);
	rs_AddString(g_sLangID_Native_InAction, &g_sLangTxt_Native_InAction);
	rs_AddString(g_sLangID_Native_TotalTime, &g_sLangTxt_Native_TotalTime);
	rs_AddString(g_sLangID_Native_IsEnabled, &g_sLangTxt_Native_IsEnabled);
	rs_AddString(g_sLangID_Native_PreState, &g_sLangTxt_Native_PreState);
	rs_AddString(g_sLangID_Native_InitState, &g_sLangTxt_Native_InitState);
	rs_AddString(g_sLangID_Native_PreCutDur, &g_sLangTxt_Native_PreCutDur);
	rs_AddString(g_sLangID_Native_CloseDur, &g_sLangTxt_Native_CloseDur);
	rs_AddString(g_sLangID_Native_BreakDur, &g_sLangTxt_Native_BreakDur);
	rs_AddString(g_sLangID_Native_UzAmp, &g_sLangTxt_Native_UzAmp);
	rs_AddString(g_sLangID_Native_UzPhase, &g_sLangTxt_Native_UzPhase);
	rs_AddString(g_sLangID_Native_UzFreq, &g_sLangTxt_Native_UzFreq);
	rs_AddString(g_sLangID_Native_I0Amplitude, &g_sLangTxt_Native_I0Amplitude);
	rs_AddString(g_sLangID_Native_I0Phase, &g_sLangTxt_Native_I0Phase);
	rs_AddString(g_sLangID_Native_I0Frequency, &g_sLangTxt_Native_I0Frequency);
	rs_AddString(g_sLangID_Native_CurrentHighPowerMode, &g_sLangTxt_Native_CurrentHighPowerMode);
	rs_AddString(g_sLangID_Native_EnableCustomOutput, &g_sLangTxt_Native_EnableCustomOutput);
	rs_AddString(g_sLangID_Native_AbsoluteTime, &g_sLangTxt_Native_AbsoluteTime);
	rs_AddString(g_sLangID_Native_RelativeTime, &g_sLangTxt_Native_RelativeTime);
	// 9newly
	rs_AddString(g_sLangID_Native_ErrUaAmp, &g_sLangTxt_Native_ErrUaAmp); // 故障Ua幅值
	rs_AddString(g_sLangID_Native_ErrUbAmp, &g_sLangTxt_Native_ErrUbAmp); // 故障Ub幅值
	rs_AddString(g_sLangID_Native_ErrUcAmp, &g_sLangTxt_Native_ErrUcAmp); // 故障Uc幅值
	rs_AddString(g_sLangID_Native_ErrUzAmp, &g_sLangTxt_Native_ErrUzAmp); // 故障Uz幅值
	rs_AddString(g_sLangID_Native_ErrUaPh, &g_sLangTxt_Native_ErrUaPh);	  // 故障Ua相位
	rs_AddString(g_sLangID_Native_ErrUbPh, &g_sLangTxt_Native_ErrUbPh);	  // 故障Ub相位
	rs_AddString(g_sLangID_Native_ErrUcPh, &g_sLangTxt_Native_ErrUcPh);	  // 故障Uc相位
	rs_AddString(g_sLangID_Native_ErrUzPh, &g_sLangTxt_Native_ErrUzPh);	  // 故障Uz相位

	//
	rs_AddString(g_sLangID_Native_OverCurrentV, &g_sLangTxt_Native_OverCurrentV);		  // 过流V段定值
	rs_AddString(g_sLangID_Native_OverCurrentVTime, &g_sLangTxt_Native_OverCurrentVTime); // 过流V段时间
	rs_AddString(g_sLangID_Native_ShortZImpAngExp, &g_sLangTxt_Native_ShortZImpAngExp);	  // 短路阻抗角(表达式)

	//
	rs_AddString(g_sLangID_Native_first_fault_type, &g_sLangTxt_Native_first_fault_type);						  // 第一次故障类型
	rs_AddString(g_sLangID_Native_first_fault_current, &g_sLangTxt_Native_first_fault_current);					  // 第一次故障电流
	rs_AddString(g_sLangID_Native_first_faultact_time, &g_sLangTxt_Native_first_faultact_time);					  // 第一次故障动作时间
	rs_AddString(g_sLangID_Native_first_fault_impedance, &g_sLangTxt_Native_first_fault_impedance);				  // 第一次故障短路阻抗
	rs_AddString(g_sLangID_Native_first_fault_impedance_angle, &g_sLangTxt_Native_first_fault_impedance_angle);	  // 第一次故障短路阻抗角
	rs_AddString(g_sLangID_Native_second_fault_type, &g_sLangTxt_Native_second_fault_type);						  // 第二次故障类型
	rs_AddString(g_sLangID_Native_second_fault_current, &g_sLangTxt_Native_second_fault_current);				  // 第二次故障电流
	rs_AddString(g_sLangID_Native_second_faultact_time, &g_sLangTxt_Native_second_faultact_time);				  // 第二次故障动作时间
	rs_AddString(g_sLangID_Native_second_fault_impedance, &g_sLangTxt_Native_second_fault_impedance);			  // 第二次故障短路阻抗
	rs_AddString(g_sLangID_Native_second_fault_impedance_angle, &g_sLangTxt_Native_second_fault_impedance_angle); // 第二次故障短路阻抗角
	rs_AddString(g_sLangID_Native_first_fault_impAmp, &g_sLangTxt_Native_first_fault_impAmp);					  // 第一次故障短路阻抗(表达式)
	rs_AddString(g_sLangID_Native_first_fault_impAngAmp, &g_sLangTxt_Native_first_fault_impAngAmp);				  // 第一次故障短路阻抗角(表达式)
	rs_AddString(g_sLangID_Native_second_fault_impAmp, &g_sLangTxt_Native_second_fault_impAmp);					  // 第二次故障短路阻抗(表达式)
	rs_AddString(g_sLangID_Native_second_fault_impAngAmp, &g_sLangTxt_Native_second_fault_impAngAmp);			  // 第二次故障短路阻抗角(表达式)
	rs_AddString(g_sLangID_Native_synchronous_VAmpExp, &g_sLangTxt_Native_synchronous_VAmpExp);					  // 同期电压幅值(表达式)
	rs_AddString(g_sLangID_Native_synchronous_VPhExp, &g_sLangTxt_Native_synchronous_VPhExp);					  // 同期电压相位(表达式)
	rs_AddString(g_sLangID_Native_impedance_Set, &g_sLangTxt_Native_impedance_Set);								  // 阻抗定值(定值)
	rs_AddString(g_sLangID_Native_ImpedanceAnglesSet, &g_sLangTxt_Native_ImpedanceAnglesSet);					  // 阻抗角(定值)
	rs_AddString(g_sLangID_Native_Syn_closure_AngSet, &g_sLangTxt_Native_Syn_closure_AngSet);					  // 检同期合闸角(定值)
	rs_AddString(g_sLangID_Native_test_item_name, &g_sLangTxt_Native_test_item_name);							  // 测试项名称

	rs_AddString(g_sLangID_Native_0seqISet, &g_sLangTxt_Native_0seqISet);				// 零序电流定值
	rs_AddString(g_sLangID_Native_YN_autoTestMode, &g_sLangTxt_Native_YN_autoTestMode); // 是否自动测试模式
	rs_AddString(g_sLangID_Native_0SeqISet, &g_sLangTxt_Native_0SeqISet);				// 零序I-V段定值
	rs_AddString(g_sLangID_Native_0SeqIISet, &g_sLangTxt_Native_0SeqIISet);
	rs_AddString(g_sLangID_Native_0SeqIIISet, &g_sLangTxt_Native_0SeqIIISet);
	rs_AddString(g_sLangID_Native_0SeqIVSet, &g_sLangTxt_Native_0SeqIVSet);
	rs_AddString(g_sLangID_Native_0SeqVSet, &g_sLangTxt_Native_0SeqVSet);
	rs_AddString(g_sLangID_Native_0SeqITime, &g_sLangTxt_Native_0SeqITime); // 零序I-V段时间
	rs_AddString(g_sLangID_Native_0SeqIITime, &g_sLangTxt_Native_0SeqIITime);
	rs_AddString(g_sLangID_Native_0SeqIIITime, &g_sLangTxt_Native_0SeqIIITime);
	rs_AddString(g_sLangID_Native_0SeqIVTime, &g_sLangTxt_Native_0SeqIVTime);
	rs_AddString(g_sLangID_Native_0SeqVTime, &g_sLangTxt_Native_0SeqVTime);

	// 第八周马
	// tmt_adjust_sys_para_trans.cpp
	rs_AddString(g_sLangID_Native_ACVoltPlugin, &g_sLangTxt_Native_ACVoltPlugin);			  /*_T("交流电压插件")*/
	rs_AddString(g_sLangID_Native_ACCurrPlugin, &g_sLangTxt_Native_ACCurrPlugin);			  /*_T("交流电流插件")*/
	rs_AddString(g_sLangID_Native_8x100MbpsDB, &g_sLangTxt_Native_8x100MbpsDB);				  /*_T("8个百兆口数字板")*/
	rs_AddString(g_sLangID_Native_6x100M2x1000MDB, &g_sLangTxt_Native_6x100M2x1000MDB);		  /*_T("6个百兆口,2个千兆口数字板")*/
	rs_AddString(g_sLangID_Native_4x100M4x1000MDB, &g_sLangTxt_Native_4x100M4x1000MDB);		  /*_T("4个百兆口,4个千兆口数字板")*/
	rs_AddString(g_sLangID_Native_DCCurrPlugin, &g_sLangTxt_Native_DCCurrPlugin);			  /*_T("直流电流插件")*/
	rs_AddString(g_sLangID_Native_DCVoltPlugin, &g_sLangTxt_Native_DCVoltPlugin);			  /*_T("直流电压插件")*/
	rs_AddString(g_sLangID_Native_DI_O_ExpBoard, &g_sLangTxt_Native_DI_O_ExpBoard);			  /*_T("开关量扩展板")*/
	rs_AddString(g_sLangID_Native_LSModPlugin, &g_sLangTxt_Native_LSModPlugin);				  /*_T("小信号模块插件")*/
	rs_AddString(g_sLangID_Native_MBLowSignal, &g_sLangTxt_Native_MBLowSignal);				  /*_T("主板小信号")*/
	rs_AddString(g_sLangID_Native_FSFT3Board, &g_sLangTxt_Native_FSFT3Board);				  /*_T("柔直FT3板")*/
	rs_AddString(g_sLangID_Native_UIHybridPlugin, &g_sLangTxt_Native_UIHybridPlugin);		  /*_T("U、I混合插件")*/
	rs_AddString(g_sLangID_Native_VoltAcqPlugin, &g_sLangTxt_Native_VoltAcqPlugin);			  /*_T("电压采集插件")*/
	rs_AddString(g_sLangID_Native_CurrAcqPlugin, &g_sLangTxt_Native_CurrAcqPlugin);			  /*_T("电流采集插件")*/
	rs_AddString(g_sLangID_Native_Stable2MCommPlugin, &g_sLangTxt_Native_Stable2MCommPlugin); /*_T("稳控2M通讯插件")*/
	rs_AddString(g_sLangID_Native_Acquisition, &g_sLangTxt_Native_Acquisition);				  /*_T("采集")*/
	rs_AddString(g_sLangID_Native_Undefined, &g_sLangTxt_Native_Undefined);					  /*_T("未定义")*/
	rs_AddString(g_sLangID_Native_130VVoltageModule, &g_sLangTxt_Native_130VVoltageModule);	  /*_T("130伏电压模块")*/
	rs_AddString(g_sLangID_Native_248VVoltageModule, &g_sLangTxt_Native_248VVoltageModule);	  /*_T("248伏电压模块")*/
	rs_AddString(g_sLangID_Native_270VVMNoBoost, &g_sLangTxt_Native_270VVMNoBoost);			  /*_T("270伏电压模块无升压")*/
	rs_AddString(g_sLangID_Native_270VVModuleWBoost, &g_sLangTxt_Native_270VVModuleWBoost);	  /*_T("270伏电压模块有升压")*/
	rs_AddString(g_sLangID_Native_300VVMNoBoost, &g_sLangTxt_Native_300VVMNoBoost);			  /*_T("300伏电压模块无升压")*/
	rs_AddString(g_sLangID_Native_300VVModuleWBoost, &g_sLangTxt_Native_300VVModuleWBoost);	  /*_T("300伏电压模块有升压")*/
	rs_AddString(g_sLangID_Native_125ACModule, &g_sLangTxt_Native_125ACModule);				  /*_T("12.5安电流模块")*/
	rs_AddString(g_sLangID_Native_20ACModule, &g_sLangTxt_Native_20ACModule);				  /*_T("20安电流模块")*/
	rs_AddString(g_sLangID_Native_32ACModule, &g_sLangTxt_Native_32ACModule);				  /*_T("32安电流模块")*/
	rs_AddString(g_sLangID_Native_125V20AHM, &g_sLangTxt_Native_125V20AHM);					  /*_T("130伏20安混合模块")*/
	rs_AddString(g_sLangID_Native_310V60AHM, &g_sLangTxt_Native_310V60AHM);					  /*_T("310伏60安混合模块")*/
	rs_AddString(g_sLangID_Native_PFC6A, &g_sLangTxt_Native_PFC6A);							  /*_T("PFC_6A 模块")*/
	rs_AddString(g_sLangID_Native_P12DSM, &g_sLangTxt_Native_P12DSM);						  /*_T("PIA12DS 模块")*/
	rs_AddString(g_sLangID_Native_P48SM, &g_sLangTxt_Native_P48SM);							  /*_T("PIA48S 模块")*/
	rs_AddString(g_sLangID_Native_EVTM, &g_sLangTxt_Native_EVTM);							  /*_T("EVTECT 模块")*/
	rs_AddString(g_sLangID_Native_DCIPM, &g_sLangTxt_Native_DCIPM);							  /*_T("直流增量保护模块")*/
	rs_AddString(g_sLangID_Native_6C10VDCM, &g_sLangTxt_Native_6C10VDCM);					  /*_T("6路10伏直流模块")*/
	rs_AddString(g_sLangID_Native_6C20mADC, &g_sLangTxt_Native_6C20mADC);					  /*_T("6路20毫安直流模块")*/
	rs_AddString(g_sLangID_Native_PN6U6IDCSSM, &g_sLangTxt_Native_PN6U6IDCSSM);				  /*_T("PN6U6I直流小信号模块")*/
	rs_AddString(g_sLangID_Native_OutputNotSupported, &g_sLangTxt_Native_OutputNotSupported); /*_T("不支持输出合并")*/
	rs_AddString(g_sLangID_Native_6to1MergePossible, &g_sLangTxt_Native_6to1MergePossible);	  /*_T("6路可以合并为1路")*/
	rs_AddString(g_sLangID_Native_6to3MergePossible, &g_sLangTxt_Native_6to3MergePossible);	  /*_T("6路可以合并为3路")*/
	rs_AddString(g_sLangID_Native_6to3FixedMerge, &g_sLangTxt_Native_6to3FixedMerge);		  /*_T("6路固定合并为3路")*/
	rs_AddString(g_sLangID_Native_SeqComp, &g_sLangTxt_Native_SeqComp);

	// adjust_sys_parameter
	rs_AddString(g_sLangID_Native_AmpFactor, &g_sLangTxt_Native_AmpFactor);							  /*"幅值系数"*/
	rs_AddString(g_sLangID_Native_NumGears, &g_sLangTxt_Native_NumGears);							  /*"档位数"*/
	rs_AddString(g_sLangID_Native_HW1DCZeroDrift, &g_sLangTxt_Native_HW1DCZeroDrift);				  /*"硬件1档直流零漂"*/
	rs_AddString(g_sLangID_Native_HW2DCZeroDrift, &g_sLangTxt_Native_HW2DCZeroDrift);				  /*"硬件2档直流零漂"*/
	rs_AddString(g_sLangID_Native_HW3DCZeroDrift, &g_sLangTxt_Native_HW3DCZeroDrift);				  /*"硬件3档直流零漂"*/
	rs_AddString(g_sLangID_Native_LCNLCoeff, &g_sLangTxt_Native_LCNLCoeff);							  /*"大电流非线性系数"*/
	rs_AddString(g_sLangID_Native_NthHarmonic, &g_sLangTxt_Native_NthHarmonic);						  /*"%d次谐波"*/
	rs_AddString(g_sLangID_Native_Temp, &g_sLangTxt_Native_Temp);									  /*"温度"*/
	rs_AddString(g_sLangID_Native_ChnN, &g_sLangTxt_Native_ChnN);									  /*"通道%d"*/
	rs_AddString(g_sLangID_Native_GearID, &g_sLangTxt_Native_GearID);								  /*"档位ID"*/
	rs_AddString(g_sLangID_Native_GearVal, &g_sLangTxt_Native_GearVal);								  /*"档位值"*/
	rs_AddString(g_sLangID_Native_HwGearCount, &g_sLangTxt_Native_HwGearCount);						  /*"硬件档位数"*/
	rs_AddString(g_sLangID_Native_CalibCoeff, &g_sLangTxt_Native_CalibCoeff);						  /*"校准系数"*/
	rs_AddString(g_sLangID_Native_TempZoneCount, &g_sLangTxt_Native_TempZoneCount);					  /*"温区数"*/
	rs_AddString(g_sLangID_Native_HwChannel, &g_sLangTxt_Native_HwChannel);							  /*"硬件通道"*/
	rs_AddString(g_sLangID_Native_ChnID, &g_sLangTxt_Native_ChnID);									  /*"通道ID"*/
	rs_AddString(g_sLangID_Native_ChnIndex, &g_sLangTxt_Native_ChnIndex);							  /*"通道索引"*/
	rs_AddString(g_sLangID_Native_AssocSWRes, &g_sLangTxt_Native_AssocSWRes);						  /*"关联的软件资源"*/
	rs_AddString(g_sLangID_Native_ACMaxValue, &g_sLangTxt_Native_ACMaxValue);						  /*"交流最大值"*/
	rs_AddString(g_sLangID_Native_DCMaxValue, &g_sLangTxt_Native_DCMaxValue);						  /*"直流最大值"*/
	rs_AddString(g_sLangID_Native_ChAcqMapLoc, &g_sLangTxt_Native_ChAcqMapLoc);						  /*"通道采集映射位置"*/
	rs_AddString(g_sLangID_Native_OpMode, &g_sLangTxt_Native_OpMode);								  /*"工作模式"*/
	rs_AddString(g_sLangID_Native_ElecType, &g_sLangTxt_Native_ElecType);							  /*"电气类型"*/
	rs_AddString(g_sLangID_Native_HwChDef, &g_sLangTxt_Native_HwChDef);								  /*"硬件通道定义"*/
	rs_AddString(g_sLangID_Native_ChDrivePos, &g_sLangTxt_Native_ChDrivePos);						  /*"通道驱动位置"*/
	rs_AddString(g_sLangID_Native_ChPos, &g_sLangTxt_Native_ChPos);									  /*_T("通道%d位置")*/
	rs_AddString(g_sLangID_Native_ChMapDef, &g_sLangTxt_Native_ChMapDef);							  /*"通道映射定义"*/
	rs_AddString(g_sLangID_Native_ModProps, &g_sLangTxt_Native_ModProps);							  /*"模块属性"*/
	rs_AddString(g_sLangID_Native_LCOptPortCount, &g_sLangTxt_Native_LCOptPortCount);				  /*"LC光口数"*/
	rs_AddString(g_sLangID_Native_STTxOptPortCount, &g_sLangTxt_Native_STTxOptPortCount);			  /*"ST发送光口数"*/
	rs_AddString(g_sLangID_Native_STRxOptPortCount, &g_sLangTxt_Native_STRxOptPortCount);			  /*"ST接收光口数"*/
	rs_AddString(g_sLangID_Native_HarmOrder, &g_sLangTxt_Native_HarmOrder);							  /*"谐波数"*/
	rs_AddString(g_sLangID_Native_DCVoltChMax, &g_sLangTxt_Native_DCVoltChMax);						  /*"直流电压通道最大值"*/
	rs_AddString(g_sLangID_Native_DCCurrChMax, &g_sLangTxt_Native_DCCurrChMax);						  /*"直流电流通道最大值"*/
	rs_AddString(g_sLangID_Native_ChACOutMax, &g_sLangTxt_Native_ChACOutMax);						  /*"通道出交流最大值"*/
	rs_AddString(g_sLangID_Native_ChDCOutMax, &g_sLangTxt_Native_ChDCOutMax);						  /*"通道出直流最大值"*/
	rs_AddString(g_sLangID_Native_FreqCompCoeff, &g_sLangTxt_Native_FreqCompCoeff);					  /*"频率补偿系数"*/
	rs_AddString(g_sLangID_Native_DigiHWPhaseDelay, &g_sLangTxt_Native_DigiHWPhaseDelay);			  /*"数字硬件相位延时"*/
	rs_AddString(g_sLangID_Native_VoltCurrHWChar, &g_sLangTxt_Native_VoltCurrHWChar);				  /*"电压电流硬件特性"*/
	rs_AddString(g_sLangID_Native_CurrChMergeMode, &g_sLangTxt_Native_CurrChMergeMode);				  /*"电流通道合并模式"*/
	rs_AddString(g_sLangID_Native_1stSetDigInCfg, &g_sLangTxt_Native_1stSetDigInCfg);				  /*"第一组开关量配为开入"*/
	rs_AddString(g_sLangID_Native_2stSetDigInCfg, &g_sLangTxt_Native_2stSetDigInCfg);				  /*"第二组开关量配为开入"*/
	rs_AddString(g_sLangID_Native_3stSetDigInCfg, &g_sLangTxt_Native_3stSetDigInCfg);				  /*"第三组开关量配为开入"*/
	rs_AddString(g_sLangID_Native_4stSetDigInCfg, &g_sLangTxt_Native_4stSetDigInCfg);				  /*"第四组开关量配为开入"*/
	rs_AddString(g_sLangID_Native_ModFPGAVer, &g_sLangTxt_Native_ModFPGAVer);						  /*"模块FPGA版本"*/
	rs_AddString(g_sLangID_Native_ModAttrVer, &g_sLangTxt_Native_ModAttrVer);						  /*"模块属性版本"*/
	rs_AddString(g_sLangID_Native_IndepDCCurrChHWRange, &g_sLangTxt_Native_IndepDCCurrChHWRange);	  /*"独立直流电流通道硬件档位"*/
	rs_AddString(g_sLangID_Native_IndepDCVoltChHWRange, &g_sLangTxt_Native_IndepDCVoltChHWRange);	  /*"独立直流电压通道硬件档位"*/
	rs_AddString(g_sLangID_Native_ModChRange, &g_sLangTxt_Native_ModChRange);						  /*"模块通道档位"*/
	rs_AddString(g_sLangID_Native_TripRelayPickupDef, &g_sLangTxt_Native_TripRelayPickupDef);		  /*"开出量导通值定义"*/
	rs_AddString(g_sLangID_Native_TripRelay1Pickup, &g_sLangTxt_Native_TripRelay1Pickup);			  /*"开出1导通值"*/
	rs_AddString(g_sLangID_Native_TripRelay2Pickup, &g_sLangTxt_Native_TripRelay2Pickup);			  /*"开出2导通值"*/
	rs_AddString(g_sLangID_Native_TripRelay3Pickup, &g_sLangTxt_Native_TripRelay3Pickup);			  /*"开出3导通值"*/
	rs_AddString(g_sLangID_Native_TripRelay4Pickup, &g_sLangTxt_Native_TripRelay4Pickup);			  /*"开出4导通值"*/
	rs_AddString(g_sLangID_Native_TripRelay5Pickup, &g_sLangTxt_Native_TripRelay5Pickup);			  /*"开出5导通值"*/
	rs_AddString(g_sLangID_Native_TripRelay6Pickup, &g_sLangTxt_Native_TripRelay6Pickup);			  /*"开出6导通值"*/
	rs_AddString(g_sLangID_Native_TripRelay7Pickup, &g_sLangTxt_Native_TripRelay7Pickup);			  /*"开出7导通值"*/
	rs_AddString(g_sLangID_Native_TripRelay8Pickup, &g_sLangTxt_Native_TripRelay8Pickup);			  /*"开出8导通值"*/
	rs_AddString(g_sLangID_Native_StateSeqCapacity, &g_sLangTxt_Native_StateSeqCapacity);			  /*"状态序列容量(个)"*/
	rs_AddString(g_sLangID_Native_MainBrdDInQty, &g_sLangTxt_Native_MainBrdDInQty);					  /*"主板开入数量(个)"*/
	rs_AddString(g_sLangID_Native_MainBrdDOutQty, &g_sLangTxt_Native_MainBrdDOutQty);				  /*"主板开出数量(个)"*/
	rs_AddString(g_sLangID_Native_WSecMomentAnaPhAbsComp, &g_sLangTxt_Native_WSecMomentAnaPhAbsComp); /*"整秒时刻,模拟量绝对相位补偿(度)"*/
	rs_AddString(g_sLangID_Native_CtrlAuthCheck, &g_sLangTxt_Native_CtrlAuthCheck);					  /*"启用控制权限判断(0-不启用，1-启用)"*/
	rs_AddString(g_sLangID_Native_TestSrvName, &g_sLangTxt_Native_TestSrvName);						  /*"TestServer名称"*/
	rs_AddString(g_sLangID_Native_TestSrvVersion, &g_sLangTxt_Native_TestSrvVersion);				  /*"TestServer版本"*/
	rs_AddString(g_sLangID_Native_MainBrdVersion, &g_sLangTxt_Native_MainBrdVersion);				  /*"主板版本"*/
	rs_AddString(g_sLangID_Native_DrvVersion, &g_sLangTxt_Native_DrvVersion);						  /*"驱动版本"*/
	rs_AddString(g_sLangID_Native_DrvName, &g_sLangTxt_Native_DrvName);								  /*"驱动名称"*/
	rs_AddString(g_sLangID_Native_MainBrdSTPortModeCfg, &g_sLangTxt_Native_MainBrdSTPortModeCfg);	  /*"主板ST口模式可设置"*/
	rs_AddString(g_sLangID_Native_SysVerNumber, &g_sLangTxt_Native_SysVerNumber);					  /*"系统版本号"*/

	// tmt_adjust_test
	/*"校准项目"*/
	rs_AddString(g_sLangID_Native_CalibItem, &g_sLangTxt_Native_CalibItem); /*"校准项目"*/
	rs_AddString(g_sLangID_Native_Pt1Amp, &g_sLangTxt_Native_Pt1Amp);		/*"点1幅值"*/
	rs_AddString(g_sLangID_Native_Pt2Amp, &g_sLangTxt_Native_Pt2Amp);		/*"点2幅值"*/

	// tmt_dig_replay_test
	rs_AddString(g_sLangID_Native_SelCtrlBlock, &g_sLangTxt_Native_SelCtrlBlock);								  /*"发送(选择该控制块)"*/
	rs_AddString(g_sLangID_Native_CtrlBlkOutOptPortsCnt, &g_sLangTxt_Native_CtrlBlkOutOptPortsCnt);				  /*"控制块输出光口数量"*/
	rs_AddString(g_sLangID_Native_CtrlBlkAppID, &g_sLangTxt_Native_CtrlBlkAppID);								  /*"控制块AppID"*/
	rs_AddString(g_sLangID_Native_CtrlBlkOutTotalFrames, &g_sLangTxt_Native_CtrlBlkOutTotalFrames);				  /*"控制块输出总帧数"*/
	rs_AddString(g_sLangID_Native_CtrlBlkOutStartFrmNum, &g_sLangTxt_Native_CtrlBlkOutStartFrmNum);				  /*"控制块输出起始帧号(本控制块内排序)"*/
	rs_AddString(g_sLangID_Native_CtrlBlkOutEndFrmNum, &g_sLangTxt_Native_CtrlBlkOutEndFrmNum);					  /*"控制块输出结束帧号(本控制块内排序)"*/
	rs_AddString(g_sLangID_Native_CtrlBlkDelayCompValue, &g_sLangTxt_Native_CtrlBlkDelayCompValue);				  /*"控制块延时补偿值(单位:us)"*/
	rs_AddString(g_sLangID_Native_NumOfSVCBs, &g_sLangTxt_Native_NumOfSVCBs);									  /*"采样值控制块数量"*/
	rs_AddString(g_sLangID_Native_NumOfGCBs, &g_sLangTxt_Native_NumOfGCBs);										  /*"GOOSE控制块数量"*/
	rs_AddString(g_sLangID_Native_SVReplayMode, &g_sLangTxt_Native_SVReplayMode);								  /*"SV回放模式(0:按时间间隔,1:等间隔,2:自定义)"*/
	rs_AddString(g_sLangID_Native_GOOSEReplayMode, &g_sLangTxt_Native_GOOSEReplayMode);							  /*"GOOSE回放模式(0:按时间间隔,1:等间隔)"*/
	rs_AddString(g_sLangID_Native_SVEqReplayIntervalTime_us, &g_sLangTxt_Native_SVEqReplayIntervalTime_us);		  /*"SV等间隔回放间隔时间(us)"*/
	rs_AddString(g_sLangID_Native_GOOSEEqReplayIntervalTime_us, &g_sLangTxt_Native_GOOSEEqReplayIntervalTime_us); /*"GOOSE等间隔回放间隔时间(us)"*/
	rs_AddString(g_sLangID_Native_CustomReplayJitter_us, &g_sLangTxt_Native_CustomReplayJitter_us);				  /*"自定义回放抖动值(us)"*/
	rs_AddString(g_sLangID_Native_LoopingFlag, &g_sLangTxt_Native_LoopingFlag);									  /*"是否循环(0不循环,1循环)"*/
	rs_AddString(g_sLangID_Native_ReplayIntervalType, &g_sLangTxt_Native_ReplayIntervalType);					  /*"回放区间设置类型(0全部回放,1部分回放)"*/
	rs_AddString(g_sLangID_Native_StartFrameNum, &g_sLangTxt_Native_StartFrameNum);								  /*"输出起始帧号(全部控制块排序)"*/
	rs_AddString(g_sLangID_Native_EndFrameNum, &g_sLangTxt_Native_EndFrameNum);									  /*"输出结束帧号(全部控制块排序)"*/
	rs_AddString(g_sLangID_Native_GPSTriggerTime_hr, &g_sLangTxt_Native_GPSTriggerTime_hr);						  /*"GPS触发时刻(时)"*/
	rs_AddString(g_sLangID_Native_GPSTriggerTime_min, &g_sLangTxt_Native_GPSTriggerTime_min);					  /*"GPS触发时刻(分)"*/
	rs_AddString(g_sLangID_Native_GPSTriggerTime_sec, &g_sLangTxt_Native_GPSTriggerTime_sec);					  /*"GPS触发时刻(秒)"*/
	rs_AddString(g_sLangID_Native_OutputDuration_sec, &g_sLangTxt_Native_OutputDuration_sec);					  /*"输出时长(s)"*/
	rs_AddString(g_sLangID_Native_InputSelection, &g_sLangTxt_Native_InputSelection);							  /*"开入%c选择"*/

	// tmt_gradient_test
	rs_AddString(g_sLangID_Native_FeedbackCoefSettingVal, &g_sLangTxt_Native_FeedbackCoefSettingVal);		/*"返回系数整定值"*/
	rs_AddString(g_sLangID_Native_BoundaryAngle1SetVal, &g_sLangTxt_Native_BoundaryAngle1SetVal);			/*"边界角1整定值"*/
	rs_AddString(g_sLangID_Native_BoundaryAngle2SetVal, &g_sLangTxt_Native_BoundaryAngle2SetVal);			/*"边界角2整定值"*/
	rs_AddString(g_sLangID_Native_MaxSensitivityAngleSetVal, &g_sLangTxt_Native_MaxSensitivityAngleSetVal); /*"最大灵敏角整定值"*/
	rs_AddString(g_sLangID_Native_StepTimeSec, &g_sLangTxt_Native_StepTimeSec);								/*"步长时间(秒)"*/
	rs_AddString(g_sLangID_Native_FSG2VoltageAmplitude, &g_sLangTxt_Native_FSG2VoltageAmplitude);			/*"故障态组2电压幅值"*/
	rs_AddString(g_sLangID_Native_FSG2CurrentAmplitude, &g_sLangTxt_Native_FSG2CurrentAmplitude);			/*"故障态组2电流幅值"*/
	rs_AddString(g_sLangID_Native_RatedVoltageAmplitude, &g_sLangTxt_Native_RatedVoltageAmplitude);			/*"额定电压幅值"*/
	rs_AddString(g_sLangID_Native_NomVoltPhaseSeq, &g_sLangTxt_Native_NomVoltPhaseSeq);						/*"常态电压相序"*/
	rs_AddString(g_sLangID_Native_NomCurrPhaseSeq, &g_sLangTxt_Native_NomCurrPhaseSeq);						/*"常态电流相序"*/
	rs_AddString(g_sLangID_Native_NomVoltAmplitude, &g_sLangTxt_Native_NomVoltAmplitude);					/*"常态电压幅值"*/
	rs_AddString(g_sLangID_Native_NomCurrAmplitude, &g_sLangTxt_Native_NomCurrAmplitude);					/*"常态电流幅值"*/

	rs_AddString(g_sLangID_Native_Ua1Amp, &g_sLangTxt_Native_Ua1Amp); /*"Ua1幅值"*/
	rs_AddString(g_sLangID_Native_Ua1Ph, &g_sLangTxt_Native_Ua1Ph);	  /*"Ua1相位"*/
	rs_AddString(g_sLangID_Native_Ua2Amp, &g_sLangTxt_Native_Ua2Amp); /*"Ua2幅值"*/
	rs_AddString(g_sLangID_Native_Ua2Ph, &g_sLangTxt_Native_Ua2Ph);	  /*"Ua2相位"*/

	rs_AddString(g_sLangID_Native_Ub1Amp, &g_sLangTxt_Native_Ub1Amp); /*"Ub1幅值"*/
	rs_AddString(g_sLangID_Native_Ub1Ph, &g_sLangTxt_Native_Ub1Ph);	  /*"Ub1相位"*/
	rs_AddString(g_sLangID_Native_Ub2Amp, &g_sLangTxt_Native_Ub2Amp); /*"Ub2幅值"*/
	rs_AddString(g_sLangID_Native_Ub2Ph, &g_sLangTxt_Native_Ub2Ph);	  /*"Ub2相位"*/

	rs_AddString(g_sLangID_Native_Uc1Amp, &g_sLangTxt_Native_Uc1Amp); /*"Uc1幅值"*/
	rs_AddString(g_sLangID_Native_Uc1Ph, &g_sLangTxt_Native_Uc1Ph);	  /*"Uc1相位"*/
	rs_AddString(g_sLangID_Native_Uc2Amp, &g_sLangTxt_Native_Uc2Amp); /*"Uc2幅值"*/
	rs_AddString(g_sLangID_Native_Uc2Ph, &g_sLangTxt_Native_Uc2Ph);	  /*"Uc2相位"*/

	rs_AddString(g_sLangID_Native_Ia1Amp, &g_sLangTxt_Native_Ia1Amp); /*"Ia1幅值"*/
	rs_AddString(g_sLangID_Native_Ia1Ph, &g_sLangTxt_Native_Ia1Ph);	  /*"Ia1相位"*/
	rs_AddString(g_sLangID_Native_Ia2Amp, &g_sLangTxt_Native_Ia2Amp); /*"Ia2幅值"*/
	rs_AddString(g_sLangID_Native_Ia2Ph, &g_sLangTxt_Native_Ia2Ph);	  /*"Ia2相位"*/

	rs_AddString(g_sLangID_Native_Ib1Amp, &g_sLangTxt_Native_Ib1Amp); /*"Ib1幅值"*/
	rs_AddString(g_sLangID_Native_Ib1Ph, &g_sLangTxt_Native_Ib1Ph);	  /*"Ib1相位"*/
	rs_AddString(g_sLangID_Native_Ib2Amp, &g_sLangTxt_Native_Ib2Amp); /*"Ib2幅值"*/
	rs_AddString(g_sLangID_Native_Ib2Ph, &g_sLangTxt_Native_Ib2Ph);	  /*"Ib2相位"*/

	rs_AddString(g_sLangID_Native_Ic1Amp, &g_sLangTxt_Native_Ic1Amp); /*"Ic1幅值"*/
	rs_AddString(g_sLangID_Native_Ic1Ph, &g_sLangTxt_Native_Ic1Ph);	  /*"Ic1相位"*/
	rs_AddString(g_sLangID_Native_Ic2Amp, &g_sLangTxt_Native_Ic2Amp); /*"Ic2幅值"*/
	rs_AddString(g_sLangID_Native_Ic2Ph, &g_sLangTxt_Native_Ic2Ph);	  /*"Ic2相位"*/

	rs_AddString(g_sLangID_Native_FreqPickAbsErr, &g_sLangTxt_Native_FreqPickAbsErr);					  /*"频率动作值绝对误差"*/
	rs_AddString(g_sLangID_Native_FreqPickRelErr, &g_sLangTxt_Native_FreqPickRelErr);					  /*"频率动作值相对误差"*/
	rs_AddString(g_sLangID_Native_FreqPickErrDetectLogic, &g_sLangTxt_Native_FreqPickErrDetectLogic);	  /*"频率动作值误差判断逻辑"*/
	rs_AddString(g_sLangID_Native_MaxSensAngAbsErr, &g_sLangTxt_Native_MaxSensAngAbsErr);				  /*"最大灵敏角绝对误差"*/
	rs_AddString(g_sLangID_Native_MaxSensAngRelErr, &g_sLangTxt_Native_MaxSensAngRelErr);				  /*"最大灵敏角相对误差"*/
	rs_AddString(g_sLangID_Native_MaxSensAngErrDetectLogic, &g_sLangTxt_Native_MaxSensAngErrDetectLogic); /*"最大灵敏角误差判断逻辑"*/
	rs_AddString(g_sLangID_Native_BndryAng1AbsErr, &g_sLangTxt_Native_BndryAng1AbsErr);					  /*"边界角1绝对误差"*/
	rs_AddString(g_sLangID_Native_BndryAng1RelErr, &g_sLangTxt_Native_BndryAng1RelErr);					  /*"边界角1相对误差"*/
	rs_AddString(g_sLangID_Native_BndryAng1ErrDetectLogic, &g_sLangTxt_Native_BndryAng1ErrDetectLogic);	  /*"边界角1误差判断逻辑"*/
	rs_AddString(g_sLangID_Native_BndryAng2AbsErr, &g_sLangTxt_Native_BndryAng2AbsErr);					  /*"边界角2绝对误差"*/
	rs_AddString(g_sLangID_Native_BndryAng2RelErr, &g_sLangTxt_Native_BndryAng2RelErr);					  /*"边界角2相对误差"*/
	rs_AddString(g_sLangID_Native_BndryAng2ErrDetectLogic, &g_sLangTxt_Native_BndryAng2ErrDetectLogic);	  /*"边界角2误差判断逻辑"*/
	rs_AddString(g_sLangID_Native_RetCoeffValid, &g_sLangTxt_Native_RetCoeffValid);						  /*"返回系数有效"*/
	rs_AddString(g_sLangID_Native_AbsErrValid, &g_sLangTxt_Native_AbsErrValid);							  /*"绝对误差有效"*/
	rs_AddString(g_sLangID_Native_FreqTripValErr, &g_sLangTxt_Native_FreqTripValErr);					  /*"频率动作值误差"*/
	rs_AddString(g_sLangID_Native_PhaseTripValErr, &g_sLangTxt_Native_PhaseTripValErr);					  /*"相位动作值误差"*/
	rs_AddString(g_sLangID_Native_RetCoeffError, &g_sLangTxt_Native_RetCoeffError);						  /*"返回系数误差"*/
	rs_AddString(g_sLangID_Native_MaxSensAngleErr, &g_sLangTxt_Native_MaxSensAngleErr);					  /*"最大灵敏角误差"*/
	rs_AddString(g_sLangID_Native_BndryAngle1Err, &g_sLangTxt_Native_BndryAngle1Err);					  /*"边界角1误差"*/
	rs_AddString(g_sLangID_Native_BndryAngle2Err, &g_sLangTxt_Native_BndryAngle2Err);					  /*"边界角2误差"*/

	// tmt_harm_test
	rs_AddString(g_sLangID_Native_NthHarmPhase, &g_sLangTxt_Native_NthHarmPhase);	  /*"%d次谐波相位"*/
	rs_AddString(g_sLangID_Native_NthHarmAmpl, &g_sLangTxt_Native_NthHarmAmpl);		  /*"%d次谐波幅值"*/
	rs_AddString(g_sLangID_Native_DCCompVaule, &g_sLangTxt_Native_DCCompVaule);		  /*"直流分量"*/
	rs_AddString(g_sLangID_Native_AutoVarConfig, &g_sLangTxt_Native_AutoVarConfig);	  /*"自动变化设置"*/
	rs_AddString(g_sLangID_Native_AutoVarStatus, &g_sLangTxt_Native_AutoVarStatus);	  /*"是否自动变化"*/
	rs_AddString(g_sLangID_Native_VarSelect, &g_sLangTxt_Native_VarSelect);			  /*"变化量选择"*/
	rs_AddString(g_sLangID_Native_VarTypeSelect, &g_sLangTxt_Native_VarTypeSelect);	  /*"变化类型选择"*/
	rs_AddString(g_sLangID_Native_VarHarmonicNum, &g_sLangTxt_Native_VarHarmonicNum); /*"变化谐波次数"*/

	// tmt_manu_test
	rs_AddString(g_sLangID_Native_DCOutputMode, &g_sLangTxt_Native_DCOutputMode);							  /*"是否以直流模式输出"*/
	rs_AddString(g_sLangID_Native_HarmSuperposition, &g_sLangTxt_Native_HarmSuperposition);					  /*"谐波叠加"*/
	rs_AddString(g_sLangID_Native_HarmSelection, &g_sLangTxt_Native_HarmSelection);							  /*"谐波选择"*/
	rs_AddString(g_sLangID_Native_MrgUnit, &g_sLangTxt_Native_MrgUnit);										  /*"合并单元"*/
	rs_AddString(g_sLangID_Native_AlgorithmSelection, &g_sLangTxt_Native_AlgorithmSelection);				  /*"算法选择(0:插值法  1:同步法)"*/
	rs_AddString(g_sLangID_Native_PPSConfiguration, &g_sLangTxt_Native_PPSConfiguration);					  /*"PPS设置(0:上升沿有效  1:下降沿有效 2:无PPS)"*/
	rs_AddString(g_sLangID_Native_RatedV_Phase_ZeroDriftCalc, &g_sLangTxt_Native_RatedV_Phase_ZeroDriftCalc); /*"额定相电压(零漂计算)"*/
	rs_AddString(g_sLangID_Native_RatedI_Phase_ZeroDriftCalc, &g_sLangTxt_Native_RatedI_Phase_ZeroDriftCalc); /*"额定相电流(零漂计算)"*/
	rs_AddString(g_sLangID_Native_SyncDur_TAT, &g_sLangTxt_Native_SyncDur_TAT);								  /*"守时精度测试时同步时长(单位:s)"*/
	rs_AddString(g_sLangID_Native_DelayComp_NoPPS, &g_sLangTxt_Native_DelayComp_NoPPS);						  /*"无PPS时延时补偿值(对时守时测试用,单位:μs)"*/
	rs_AddString(g_sLangID_Native_CustomRepCnt_Use_MU, &g_sLangTxt_Native_CustomRepCnt_Use_MU);				  /*"是否使用自定义报告次数(合并单元)"*/
	rs_AddString(g_sLangID_Native_CustomRepTestCnt_MU, &g_sLangTxt_Native_CustomRepTestCnt_MU);				  /*"自定义报告测试次数(合并单元)"*/
	rs_AddString(g_sLangID_Native_TestDurPerTest_MU_sec, &g_sLangTxt_Native_TestDurPerTest_MU_sec);			  /*"每次测试时间(合并单元,单位秒)"*/
	rs_AddString(g_sLangID_Native_MUTimeTestResults, &g_sLangTxt_Native_MUTimeTestResults);					  /*"MU时间测试结果"*/
	rs_AddString(g_sLangID_Native_TestedDur, &g_sLangTxt_Native_TestedDur);									  /*"已测试时长"*/
	rs_AddString(g_sLangID_Native_MaxErrTime, &g_sLangTxt_Native_MaxErrTime);								  /*"最大误差时间"*/
	rs_AddString(g_sLangID_Native_MinErrTime, &g_sLangTxt_Native_MinErrTime);								  /*"最小误差时间"*/
	rs_AddString(g_sLangID_Native_AvgErrTime, &g_sLangTxt_Native_AvgErrTime);								  /*"平均误差时间"*/
	rs_AddString(g_sLangID_Native_TimeAccTestResults, &g_sLangTxt_Native_TimeAccTestResults);				  /*"时间精度测试结果"*/
	rs_AddString(g_sLangID_Native_UaFreq, &g_sLangTxt_Native_UaFreq);										  /*"Ua频率"*/
	rs_AddString(g_sLangID_Native_UbFreq, &g_sLangTxt_Native_UbFreq);										  /*"Ub频率"*/
	rs_AddString(g_sLangID_Native_UcFreq, &g_sLangTxt_Native_UcFreq);										  /*"Uc频率"*/

	rs_AddString(g_sLangID_Native_UapAmp, &g_sLangTxt_Native_UapAmp);	  /*"Uap幅值"*/
	rs_AddString(g_sLangID_Native_UapPhase, &g_sLangTxt_Native_UapPhase); /*"Uap相位"*/
	rs_AddString(g_sLangID_Native_UapFreq, &g_sLangTxt_Native_UapFreq);	  /*"Uap频率"*/

	rs_AddString(g_sLangID_Native_UbpAmp, &g_sLangTxt_Native_UbpAmp);	  /*"Ubp幅值"*/
	rs_AddString(g_sLangID_Native_UbpPhase, &g_sLangTxt_Native_UbpPhase); /*"Ubp相位"*/
	rs_AddString(g_sLangID_Native_UbpFreq, &g_sLangTxt_Native_UbpFreq);	  /*"Ubp频率"*/

	rs_AddString(g_sLangID_Native_UcpAmp, &g_sLangTxt_Native_UcpAmp);	  /*"Ucp幅值"*/
	rs_AddString(g_sLangID_Native_UcpPhase, &g_sLangTxt_Native_UcpPhase); /*"Ucp相位"*/
	rs_AddString(g_sLangID_Native_UcpFreq, &g_sLangTxt_Native_UcpFreq);	  /*"Ucp频率"*/

	rs_AddString(g_sLangID_Native_IaAmp, &g_sLangTxt_Native_IaAmp);		/*"Ia幅值"*/
	rs_AddString(g_sLangID_Native_IaPhase, &g_sLangTxt_Native_IaPhase); /*"Ia相位"*/
	rs_AddString(g_sLangID_Native_IaFreq, &g_sLangTxt_Native_IaFreq);	/*"Ia频率"*/

	rs_AddString(g_sLangID_Native_IbAmp, &g_sLangTxt_Native_IbAmp);		/*"Ib幅值"*/
	rs_AddString(g_sLangID_Native_IbPhase, &g_sLangTxt_Native_IbPhase); /*"Ib相位"*/
	rs_AddString(g_sLangID_Native_IbFreq, &g_sLangTxt_Native_IbFreq);	/*"Ib频率"*/

	rs_AddString(g_sLangID_Native_IcAmp, &g_sLangTxt_Native_IcAmp);		/*"Ic幅值"*/
	rs_AddString(g_sLangID_Native_IcPhase, &g_sLangTxt_Native_IcPhase); /*"Ic相位"*/
	rs_AddString(g_sLangID_Native_IcFreq, &g_sLangTxt_Native_IcFreq);	/*"Ic频率"*/

	rs_AddString(g_sLangID_Native_IapAmp, &g_sLangTxt_Native_IapAmp);	  /*"Iap幅值"*/
	rs_AddString(g_sLangID_Native_IapPhase, &g_sLangTxt_Native_IapPhase); /*"Iap相位"*/
	rs_AddString(g_sLangID_Native_IapFreq, &g_sLangTxt_Native_IapFreq);	  /*"Iap频率"*/

	rs_AddString(g_sLangID_Native_IbpAmp, &g_sLangTxt_Native_IbpAmp);	  /*"Ibp幅值"*/
	rs_AddString(g_sLangID_Native_IbpPhase, &g_sLangTxt_Native_IbpPhase); /*"Ibp相位"*/
	rs_AddString(g_sLangID_Native_IbpFreq, &g_sLangTxt_Native_IbpFreq);	  /*"Ibp频率"*/

	rs_AddString(g_sLangID_Native_IcpAmp, &g_sLangTxt_Native_IcpAmp);	  /*"Icp幅值"*/
	rs_AddString(g_sLangID_Native_IcpPhase, &g_sLangTxt_Native_IcpPhase); /*"Icp相位"*/
	rs_AddString(g_sLangID_Native_IcpFreq, &g_sLangTxt_Native_IcpFreq);	  /*"Icp频率"*/

	rs_AddString(g_sLangID_Native_TestFuncCategory, &g_sLangTxt_Native_TestFuncCategory); /*"测试功能类别(0:普通手动试验1:MU精度测试2:MU零漂测试)"*/

	// tmt_pt_test
	rs_AddString(g_sLangID_Native_PT1Impedance, &g_sLangTxt_Native_PT1Impedance); /*"PT1阻值"*/
	rs_AddString(g_sLangID_Native_PT2Impedance, &g_sLangTxt_Native_PT2Impedance); /*"PT2阻值"*/

	// tmt_record
	rs_AddString(g_sLangID_Native_RecvOptPort, &g_sLangTxt_Native_RecvOptPort); /*"接收光口"*/
	rs_AddString(g_sLangID_Native_TotalSubs, &g_sLangTxt_Native_TotalSubs);		/*"订阅总数"*/

	// tmt_NEW
	rs_AddString(g_sLangID_Native_UasAmp, &g_sLangTxt_Native_UasAmp);	  /*"Uas幅值"*/
	rs_AddString(g_sLangID_Native_UasPhase, &g_sLangTxt_Native_UasPhase); /*"Uas相位"*/
	rs_AddString(g_sLangID_Native_UasFreq, &g_sLangTxt_Native_UasFreq);	  /*"Uas频率"*/

	rs_AddString(g_sLangID_Native_UbsAmp, &g_sLangTxt_Native_UbsAmp);	  /*"Ubs幅值"*/
	rs_AddString(g_sLangID_Native_UbsPhase, &g_sLangTxt_Native_UbsPhase); /*"Ubs相位"*/
	rs_AddString(g_sLangID_Native_UbsFreq, &g_sLangTxt_Native_UbsFreq);	  /*"Ubs频率"*/

	rs_AddString(g_sLangID_Native_UcsAmp, &g_sLangTxt_Native_UcsAmp);	  /*"Ucs幅值"*/
	rs_AddString(g_sLangID_Native_UcsPhase, &g_sLangTxt_Native_UcsPhase); /*"Ucs相位"*/
	rs_AddString(g_sLangID_Native_UcsFreq, &g_sLangTxt_Native_UcsFreq);	  /*"Ucs频率"*/

	rs_AddString(g_sLangID_Native_UatAmp, &g_sLangTxt_Native_UatAmp);	  /*"Uat幅值"*/
	rs_AddString(g_sLangID_Native_UatPhase, &g_sLangTxt_Native_UatPhase); /*"Uat相位"*/
	rs_AddString(g_sLangID_Native_UatFreq, &g_sLangTxt_Native_UatFreq);	  /*"Uat频率"*/

	rs_AddString(g_sLangID_Native_UbtAmp, &g_sLangTxt_Native_UbtAmp);	  /*"Ubt幅值"*/
	rs_AddString(g_sLangID_Native_UbtPhase, &g_sLangTxt_Native_UbtPhase); /*"Ubt相位"*/
	rs_AddString(g_sLangID_Native_UbtFreq, &g_sLangTxt_Native_UbtFreq);	  /*"Ubt频率"*/

	rs_AddString(g_sLangID_Native_UctAmp, &g_sLangTxt_Native_UctAmp);	  /*"Uct幅值"*/
	rs_AddString(g_sLangID_Native_UctPhase, &g_sLangTxt_Native_UctPhase); /*"Uct相位"*/
	rs_AddString(g_sLangID_Native_UctFreq, &g_sLangTxt_Native_UctFreq);	  /*"Uct频率"*/

	rs_AddString(g_sLangID_Native_IasAmp, &g_sLangTxt_Native_IasAmp);	  /*"Ias幅值"*/
	rs_AddString(g_sLangID_Native_IasPhase, &g_sLangTxt_Native_IasPhase); /*"Ias相位"*/
	rs_AddString(g_sLangID_Native_IasFreq, &g_sLangTxt_Native_IasFreq);	  /*"Ias频率"*/

	rs_AddString(g_sLangID_Native_IbsAmp, &g_sLangTxt_Native_IbsAmp);	  /*"Ibs幅值"*/
	rs_AddString(g_sLangID_Native_IbsPhase, &g_sLangTxt_Native_IbsPhase); /*"Ibs相位"*/
	rs_AddString(g_sLangID_Native_IbsFreq, &g_sLangTxt_Native_IbsFreq);	  /*"Ibs频率"*/

	rs_AddString(g_sLangID_Native_IcsAmp, &g_sLangTxt_Native_IcsAmp);	  /*"Ics幅值"*/
	rs_AddString(g_sLangID_Native_IcsPhase, &g_sLangTxt_Native_IcsPhase); /*"Ics相位"*/
	rs_AddString(g_sLangID_Native_IcsFreq, &g_sLangTxt_Native_IcsFreq);	  /*"Ics频率"*/

	rs_AddString(g_sLangID_Native_IatAmp, &g_sLangTxt_Native_IatAmp);	  /*"Iat幅值"*/
	rs_AddString(g_sLangID_Native_IatPhase, &g_sLangTxt_Native_IatPhase); /*"Iat相位"*/
	rs_AddString(g_sLangID_Native_IatFreq, &g_sLangTxt_Native_IatFreq);	  /*"Iat频率"*/

	rs_AddString(g_sLangID_Native_IbtAmp, &g_sLangTxt_Native_IbtAmp);	  /*"Ibt幅值"*/
	rs_AddString(g_sLangID_Native_IbtPhase, &g_sLangTxt_Native_IbtPhase); /*"Ibt相位"*/
	rs_AddString(g_sLangID_Native_IbtFreq, &g_sLangTxt_Native_IbtFreq);	  /*"Ibt频率"*/

	rs_AddString(g_sLangID_Native_IctAmp, &g_sLangTxt_Native_IctAmp);	  /*"Ict幅值"*/
	rs_AddString(g_sLangID_Native_IctPhase, &g_sLangTxt_Native_IctPhase); /*"Ict相位"*/
	rs_AddString(g_sLangID_Native_IctFreq, &g_sLangTxt_Native_IctFreq);	  /*"Ict频率"*/

	// tmt_replay_test
	rs_AddString(g_sLangID_Native_ModReplace, &g_sLangTxt_Native_ModReplace);					  /*"模块%d"*/
	rs_AddString(g_sLangID_Native_TIC_A_Chn_Num, &g_sLangTxt_Native_TIC_A_Chn_Num);				  /*"测试仪通道%d_A通道序号"*/
	rs_AddString(g_sLangID_Native_TIC_B_Chn_Num, &g_sLangTxt_Native_TIC_B_Chn_Num);				  /*"测试仪通道%d_B通道序号"*/
	rs_AddString(g_sLangID_Native_TIC_TransfRatio, &g_sLangTxt_Native_TIC_TransfRatio);			  /*"测试仪通道%d_变比"*/
	rs_AddString(g_sLangID_Native_SampFreq, &g_sLangTxt_Native_SampFreq);						  /*"采样频率"*/
	rs_AddString(g_sLangID_Native_PT_TxRatio_Primary, &g_sLangTxt_Native_PT_TxRatio_Primary);	  /*"PT变比一次值"*/
	rs_AddString(g_sLangID_Native_PT_TxRatio_Secondary, &g_sLangTxt_Native_PT_TxRatio_Secondary); /*"PT变比二次值"*/
	rs_AddString(g_sLangID_Native_CT_TxRatio_Primary, &g_sLangTxt_Native_CT_TxRatio_Primary);	  /*"CT变比一次值"*/
	rs_AddString(g_sLangID_Native_CT_TxRatio_Secondary, &g_sLangTxt_Native_CT_TxRatio_Secondary); /*"CT变比二次值"*/
	rs_AddString(g_sLangID_Native_NumOfModules, &g_sLangTxt_Native_NumOfModules);				  /*"模块数"*/
	rs_AddString(g_sLangID_Native_WaveFileName, &g_sLangTxt_Native_WaveFileName);				  /*"录波文件名称"*/
	rs_AddString(g_sLangID_Native_NumCycles, &g_sLangTxt_Native_NumCycles);						  /*"周波数"*/
	rs_AddString(g_sLangID_Native_PostTrigMode, &g_sLangTxt_Native_PostTrigMode);				  /*"触发后模式"*/
	rs_AddString(g_sLangID_Native_ExpTrigTime, &g_sLangTxt_Native_ExpTrigTime);					  /*"实验触发时间"*/
	rs_AddString(g_sLangID_Native_CycleIndex, &g_sLangTxt_Native_CycleIndex);						  /*"全部循环次数"*/
	rs_AddString(g_sLangID_Native_ManualControl, &g_sLangTxt_Native_ManualControl);				  /*"手动控制"*/
	rs_AddString(g_sLangID_Native_ReplayInterval, &g_sLangTxt_Native_ReplayInterval);				  /*"时间间隔"*/

	rs_AddString(g_sLangID_Native_ImpedanceEditBox, &g_sLangTxt_Native_ImpedanceEditBox);

	// UI
	// Harm
	rs_AddString(g_sLangID_Native_VolactValue, &g_sLangTxt_Native_VolactValue);				  // 电压动作值(%)
	rs_AddString(g_sLangID_Native_CuractValue, &g_sLangTxt_Native_CuractValue);				  // 电流动作值(%)
	rs_AddString(g_sLangID_Native_harmonicNotChecked, &g_sLangTxt_Native_harmonicNotChecked); // 指定通道的谐波未被勾选!

	// IEC61850Config
	rs_AddString(g_sLangID_Native_DCVmapping, &g_sLangTxt_Native_DCVmapping); // 直流电压映射
	rs_AddString(g_sLangID_Native_DCImapping, &g_sLangTxt_Native_DCImapping); // 直流电流映射
	rs_AddString(g_sLangID_Native_ACVmapping, &g_sLangTxt_Native_ACVmapping); // 交流电压映射
	rs_AddString(g_sLangID_Native_ACImapping, &g_sLangTxt_Native_ACImapping); // 交流电流映射

	rs_AddString(g_sLangID_Native_FailtoGetsclPath, &g_sLangTxt_Native_FailtoGetsclPath); // 获取SCL文件路径失败(%s).
	rs_AddString(g_sLangID_Native_codesSetting, &g_sLangTxt_Native_codesSetting);		  // 码值设置
	rs_AddString(g_sLangID_Native_DCPart, &g_sLangTxt_Native_DCPart);					  // 直流部分
	rs_AddString(g_sLangID_Native_ACPart, &g_sLangTxt_Native_ACPart);					  // 交流部分
	rs_AddString(g_sLangID_Native_selected, &g_sLangTxt_Native_selected);				  // 已选中
	rs_AddString(g_sLangID_Native_schematic, &g_sLangTxt_Native_schematic);				  // 示意图

	rs_AddString(g_sLangID_Native_codesValue, &g_sLangTxt_Native_codesValue); // 码值
	rs_AddString(g_sLangID_Native_modifyto, &g_sLangTxt_Native_modifyto);	  // 修改为
	rs_AddString(g_sLangID_Native_function, &g_sLangTxt_Native_function);	  // 功能

	//
	rs_AddString(g_sLangID_Native_completeconfig, &g_sLangTxt_Native_completeconfig); // 完成配置
	rs_AddString(g_sLangID_Native_nextitem, &g_sLangTxt_Native_nextitem);			  // 下一项
	rs_AddString(g_sLangID_Native_previtem, &g_sLangTxt_Native_previtem);			  // 上一项
	rs_AddString(g_sLangID_Native_ttybzd, &g_sLangTxt_Native_ttybzd);				  //_投退压板整定
	rs_AddString(g_sLangID_Native_FixedValueSet, &g_sLangTxt_Native_FixedValueSet);	  //_修改定值整定

	rs_AddString(g_sLangID_Native_PYResnotFound, &g_sLangTxt_Native_PYResnotFound); // 没有找到中文拼音资源文件!

	rs_AddString(g_sLangID_Native_dataid, &g_sLangTxt_Native_dataid);			  // 数据ID
	rs_AddString(g_sLangID_Native_paramselect, &g_sLangTxt_Native_paramselect);	  // 参数选择
	rs_AddString(g_sLangID_Native_globalparams, &g_sLangTxt_Native_globalparams); // 全局参数
	rs_AddString(g_sLangID_Native_reportdata, &g_sLangTxt_Native_reportdata);	  // 报告数据
	rs_AddString(g_sLangID_Native_switchreport, &g_sLangTxt_Native_switchreport); // 切换报告

	rs_AddString(g_sLangID_Native_reportdataname, &g_sLangTxt_Native_reportdataname);	// 报告数据名称
	rs_AddString(g_sLangID_Native_paramone, &g_sLangTxt_Native_paramone);				// 参数一
	rs_AddString(g_sLangID_Native_paramtwo, &g_sLangTxt_Native_paramtwo);				// 参数二
	rs_AddString(g_sLangID_Native_baselineparams, &g_sLangTxt_Native_baselineparams);	// 基准参数
	rs_AddString(g_sLangID_Native_errorresult, &g_sLangTxt_Native_errorresult);			// 误差结果
	rs_AddString(g_sLangID_Native_errorlimit, &g_sLangTxt_Native_errorlimit);			// 误差限
	rs_AddString(g_sLangID_Native_notcalculated, &g_sLangTxt_Native_notcalculated);		// 未计算
	rs_AddString(g_sLangID_Native_baseline_min, &g_sLangTxt_Native_baseline_min);		// 基准-最小值
	rs_AddString(g_sLangID_Native_baseline_max, &g_sLangTxt_Native_baseline_max);		// 基准-最大值
	rs_AddString(g_sLangID_Native_operationresult, &g_sLangTxt_Native_operationresult); // 运算结果

	// 第九周许
	// 10.30
	rs_AddString(g_sLangID_Native_SelectParamFirst, &g_sLangTxt_Native_SelectParamFirst);
	rs_AddString(g_sLangID_Native_NoValidMapData, &g_sLangTxt_Native_NoValidMapData);
	rs_AddString(g_sLangID_Native_DeviceModel, &g_sLangTxt_Native_DeviceModel);
	rs_AddString(g_sLangID_Native_Dataset, &g_sLangTxt_Native_Dataset);
	rs_AddString(g_sLangID_Native_AddNew, &g_sLangTxt_Native_AddNew);
	rs_AddString(g_sLangID_Native_ClearMap, &g_sLangTxt_Native_ClearMap);
	rs_AddString(g_sLangID_Native_ClearSel, &g_sLangTxt_Native_ClearSel);
	rs_AddString(g_sLangID_Native_CustomName, &g_sLangTxt_Native_CustomName);
	rs_AddString(g_sLangID_Native_RealDevData, &g_sLangTxt_Native_RealDevData);
	rs_AddString(g_sLangID_Native_DataInSet, &g_sLangTxt_Native_DataInSet);
	rs_AddString(g_sLangID_Native_CurveName, &g_sLangTxt_Native_CurveName);
	rs_AddString(g_sLangID_Native_SingleTimeLimit, &g_sLangTxt_Native_SingleTimeLimit);
	rs_AddString(g_sLangID_Native_DoubleTimeLimit, &g_sLangTxt_Native_DoubleTimeLimit);
	rs_AddString(g_sLangID_Native_TripleTimeLimit, &g_sLangTxt_Native_TripleTimeLimit);
	rs_AddString(g_sLangID_Native_CurrentValueI, &g_sLangTxt_Native_CurrentValueI);
	rs_AddString(g_sLangID_Native_ActionThres, &g_sLangTxt_Native_ActionThres);
	rs_AddString(g_sLangID_Native_FeatCurveElem, &g_sLangTxt_Native_FeatCurveElem);
	rs_AddString(g_sLangID_Native_IEEECurveSet, &g_sLangTxt_Native_IEEECurveSet);
	rs_AddString(g_sLangID_Native_IACCurveSet, &g_sLangTxt_Native_IACCurveSet);
	rs_AddString(g_sLangID_Native_I2TCurveSet, &g_sLangTxt_Native_I2TCurveSet);
	rs_AddString(g_sLangID_Native_IECCurveSet, &g_sLangTxt_Native_IECCurveSet);
	rs_AddString(g_sLangID_Native_Threshold, &g_sLangTxt_Native_Threshold);
	rs_AddString(g_sLangID_Native_QuickBreak, &g_sLangTxt_Native_QuickBreak);
	rs_AddString(g_sLangID_Native_FirstPart, &g_sLangTxt_Native_FirstPart);
	rs_AddString(g_sLangID_Native_Inflection1, &g_sLangTxt_Native_Inflection1);
	rs_AddString(g_sLangID_Native_SecondPart, &g_sLangTxt_Native_SecondPart);
	rs_AddString(g_sLangID_Native_InflectionPoint2, &g_sLangTxt_Native_InflectionPoint2);
	rs_AddString(g_sLangID_Native_TestCtrlProgDate, &g_sLangTxt_Native_TestCtrlProgDate);
	rs_AddString(g_sLangID_Native_DebugOutput, &g_sLangTxt_Native_DebugOutput);
	//rs_AddString(g_sLangID_Native_StartOutput, &g_sLangTxt_Native_StartOutput);
	rs_AddString(g_sLangID_Native_StopOutput, &g_sLangTxt_Native_StopOutput);
	/*rs_AddString(g_sLangID_Native_TestAnomalies, &g_sLangTxt_Native_TestAnomalies);
	rs_AddString(g_sLangID_Native_RelieveTestAnomalies, &g_sLangTxt_Native_RelieveTestAnomalies);
	rs_AddString(g_sLangID_Native_StateSwitch, &g_sLangTxt_Native_StateSwitch);
	rs_AddString(g_sLangID_Native_SupDCSwitch, &g_sLangTxt_Native_SupDCSwitch);
	rs_AddString(g_sLangID_Native_BinDisPlace, &g_sLangTxt_Native_BinDisPlace);
	rs_AddString(g_sLangID_Native_BoutDisPlace, &g_sLangTxt_Native_BoutDisPlace);
	rs_AddString(g_sLangID_Native_ParaUpdata, &g_sLangTxt_Native_ParaUpdata);*/
	rs_AddString(g_sLangID_Native_OpenFail, &g_sLangTxt_Native_OpenFail);
	rs_AddString(g_sLangID_Native_Disconnect, &g_sLangTxt_Native_Disconnect);
	rs_AddString(g_sLangID_Native_StateGraph, &g_sLangTxt_Native_StateGraph);
	rs_AddString(g_sLangID_Native_SoftResID, &g_sLangTxt_Native_SoftResID);
	rs_AddString(g_sLangID_Native_EnterNum, &g_sLangTxt_Native_EnterNum);
	rs_AddString(g_sLangID_Native_SendByWave, &g_sLangTxt_Native_SendByWave);
	rs_AddString(g_sLangID_Native_SendBySec, &g_sLangTxt_Native_SendBySec);
	rs_AddString(g_sLangID_Native_StateNetID, &g_sLangTxt_Native_StateNetID);
	rs_AddString(g_sLangID_Native_ExportWords, &g_sLangTxt_Native_ExportWords);
	rs_AddString(g_sLangID_Native_WordDoc, &g_sLangTxt_Native_WordDoc);
	rs_AddString(g_sLangID_Native_ExportPath, &g_sLangTxt_Native_ExportPath);

	// 第九周马
	rs_AddString(g_sLangID_Native_UnzipError, &g_sLangTxt_Native_UnzipError);						/*_T("stt_rcd_unzip_file解压缩出错.")*/
	rs_AddString(g_sLangID_Native_ExpPcapInterf, &g_sLangTxt_Native_ExpPcapInterf);					/*_T("导出Pcap文件界面")*/
	rs_AddString(g_sLangID_Native_RawDataFile, &g_sLangTxt_Native_RawDataFile);						/*_T("原始数据文件:")*/
	rs_AddString(g_sLangID_Native_SelectOmit, &g_sLangTxt_Native_SelectOmit);						/*_T("选择...")*/
	rs_AddString(g_sLangID_Native_PcapFileN, &g_sLangTxt_Native_PcapFileN);							/*_T("Pcap文件名:")*/
	rs_AddString(g_sLangID_Native_StartConver, &g_sLangTxt_Native_StartConver);						/*_T("开始转换")*/
	rs_AddString(g_sLangID_Native_at02dCompFiles, &g_sLangTxt_Native_at02dCompFiles);				/*_T("at02d压缩文件(*.at02dz);;at02d文件(*.at02d)")*/
	rs_AddString(g_sLangID_Native_SelectRawFile, &g_sLangTxt_Native_SelectRawFile);					/*_T("请先选择原始数据文件.")*/
	rs_AddString(g_sLangID_Native_SetOutFileName, &g_sLangTxt_Native_SetOutFileName);				/*_T("请先设置生成文件名称.")*/
	rs_AddString(g_sLangID_Native_CurRawFileNotEx, &g_sLangTxt_Native_CurRawFileNotEx);				/*_T("当前原始数据文件(%s)不存在.")*/
	rs_AddString(g_sLangID_Native_PcapGenSuccess, &g_sLangTxt_Native_PcapGenSuccess);				/*_T("Pcap文件(%s)生成成功.")*/
	rs_AddString(g_sLangID_Native_PcapGenFailed, &g_sLangTxt_Native_PcapGenFailed);					/*_T("Pcap文件(%s)生成失败.")*/
	rs_AddString(g_sLangID_Native_BaudRate, &g_sLangTxt_Native_BaudRate);							/*"波特率"*/
	rs_AddString(g_sLangID_Native_MsgLength, &g_sLangTxt_Native_MsgLength);							/*"报文长度"*/
	rs_AddString(g_sLangID_Native_UnkwnMsgType, &g_sLangTxt_Native_UnkwnMsgType);					/*_T("未知的报文类型(%u).")*/
	rs_AddString(g_sLangID_Native_CurrPsdM0AssocAftRcvM, &g_sLangTxt_Native_CurrPsdM0AssocAftRcvM); /*_T("当前解析的报文帧数为0,需收到报文后,才能关联.")*/
	rs_AddString(g_sLangID_Native_RecTime, &g_sLangTxt_Native_RecTime);								/*("录波时间")*/
	rs_AddString(g_sLangID_Native_StopRecrd, &g_sLangTxt_Native_StopRecrd);							/*_T("停止录波")*/
	rs_AddString(g_sLangID_Native_ValdValue, &g_sLangTxt_Native_ValdValue);							/*_T("有效值")*/
	rs_AddString(g_sLangID_Native_IncRate, &g_sLangTxt_Native_IncRate);								/*_T("含有率")*/
	rs_AddString(g_sLangID_Native_BarChar, &g_sLangTxt_Native_BarChar);								/*_T("柱状图")*/
	rs_AddString(g_sLangID_Native_RecWaveform, &g_sLangTxt_Native_RecWaveform);						/*_T("录波")*/
	rs_AddString(g_sLangID_Native_CurrWrtFileEmpty, &g_sLangTxt_Native_CurrWrtFileEmpty);			/*_T("当前写文件路径为空.")*/
	rs_AddString(g_sLangID_Native_SaveAs, &g_sLangTxt_Native_SaveAs);								/*_T("文件保存为")*/
	rs_AddString(g_sLangID_Native_FileSavedSucc, &g_sLangTxt_Native_FileSavedSucc);					/*_T("文件(%s)保存成功.")*/
	rs_AddString(g_sLangID_Native_FileSaveFailed, &g_sLangTxt_Native_FileSaveFailed);				/*_T("文件(%s)保存失败.")*/
	rs_AddString(g_sLangID_Native_FileExist, &g_sLangTxt_Native_FileExist);							/*_T("文件已存在，是否替换？")*/
	rs_AddString(g_sLangID_Native_FileSave, &g_sLangTxt_Native_FileSave);							/*_T("文件保存成功")*/
	rs_AddString(g_sLangID_Native_Accept, &g_sLangTxt_Native_Accept);								/*_T("接收");*/
	rs_AddString(g_sLangID_Native_SVMsgDispersView, &g_sLangTxt_Native_SVMsgDispersView);			/*_T("SV报文离散度视图")*/
	rs_AddString(g_sLangID_Native_DCVoltAmp, &g_sLangTxt_Native_DCVoltAmp);							/*_T("直流(V/A)")*/
	rs_AddString(g_sLangID_Native_FundamentalVA, &g_sLangTxt_Native_FundamentalVA);					/*_T("基波(V/A)")*/
	rs_AddString(g_sLangID_Native_LowLevelTmplFail, &g_sLangTxt_Native_LowLevelTmplFail);			/*_T("底层测试模板生成失败.")*/
	rs_AddString(g_sLangID_Native_StartTestSendFail, &g_sLangTxt_Native_StartTestSendFail);			/*_T("开始测试命令下发失败.")*/
	rs_AddString(g_sLangID_Native_StopTestSendFail, &g_sLangTxt_Native_StopTestSendFail);			/*_T("停止测试命令下发失败.")*/
	rs_AddString(g_sLangID_Native_StatusLDActTime, &g_sLangTxt_Native_StatusLDActTime);				/*_T("状态%ld动作时间%.4lfs.")*/
	rs_AddString(g_sLangID_Native_CloseFeatPromptSave, &g_sLangTxt_Native_CloseFeatPromptSave);		/*_T("?????????????? OnCmd_NewTest: 关闭打开的测试功能页面，并弹框提示是否保存修改 ???????????")*/
	rs_AddString(g_sLangID_Native_InsData, &g_sLangTxt_Native_InsData);								// 插入数据
	rs_AddString(g_sLangID_Native_ExecComm, &g_sLangTxt_Native_ExecComm);							// 执行通信
	rs_AddString(g_sLangID_Native_DelSelData, &g_sLangTxt_Native_DelSelData);						// 删除选中数据
	rs_AddString(g_sLangID_Native_SendChanges, &g_sLangTxt_Native_SendChanges);						/*"是否变化上送"*/
	rs_AddString(g_sLangID_Native_CycleTm, &g_sLangTxt_Native_CycleTm);								// 周期时间
	rs_AddString(g_sLangID_Native_ErrName, &g_sLangTxt_Native_ErrName);								// 误差名称
	rs_AddString(g_sLangID_Native_ErrValue, &g_sLangTxt_Native_ErrValue);							// 误差值
	rs_AddString(g_sLangID_Native_TestCat, &g_sLangTxt_Native_TestCat);								// 测试分类
	rs_AddString(g_sLangID_Native_TitleLvl, &g_sLangTxt_Native_TitleLvl);							// 标题等级
	rs_AddString(g_sLangID_Native_ProjIdent, &g_sLangTxt_Native_ProjIdent);							// 项目标识
	rs_AddString(g_sLangID_Native_AsWordTitle, &g_sLangTxt_Native_AsWordTitle);						// 作为Word标题
	rs_AddString(g_sLangID_Native_ModProjName, &g_sLangTxt_Native_ModProjName);						// 修改项目名称
	rs_AddString(g_sLangID_Native_Wizard, &g_sLangTxt_Native_Wizard);								// 向导
	rs_AddString(g_sLangID_Native_PrevStep, &g_sLangTxt_Native_PrevStep);							// 上一步
	rs_AddString(g_sLangID_Native_WebPageNotExst, &g_sLangTxt_Native_WebPageNotExst);				/*_T("网页文件(%s)不存在.")*/
	rs_AddString(g_sLangID_Native_IEDNotSel, &g_sLangTxt_Native_IEDNotSel);							/*_T("未选择IED")*/

	// Controls
	rs_AddString(g_sLangID_Native_DevType, &g_sLangTxt_Native_DevType);													  // 设备类型
	rs_AddString(g_sLangID_Native_ProtoEngin, &g_sLangTxt_Native_ProtoEngin);											  // 规约引擎
	rs_AddString(g_sLangID_Native_DevIP, &g_sLangTxt_Native_DevIP);														  // 装置IP
	rs_AddString(g_sLangID_Native_DevPort, &g_sLangTxt_Native_DevPort);													  // 装置端口
	rs_AddString(g_sLangID_Native_ProtoTemp, &g_sLangTxt_Native_ProtoTemp);												  // 规约模板
	rs_AddString(g_sLangID_Native_SelSCDFile, &g_sLangTxt_Native_SelSCDFile);											  // 从SCD文件选择
	rs_AddString(g_sLangID_Native_AdvConfig, &g_sLangTxt_Native_AdvConfig);												  // 高级配置
	rs_AddString(g_sLangID_Native_TimeSetUnit, &g_sLangTxt_Native_TimeSetUnit);											  // 时间定值单位为ms
	rs_AddString(g_sLangID_Native_AddDevReset, &g_sLangTxt_Native_AddDevReset);											  // 添加装置复归态
	rs_AddString(g_sLangID_Native_NewCat, &g_sLangTxt_Native_NewCat);													  /*"新分类"*/
	rs_AddString(g_sLangID_Native_ProjSameExists, &g_sLangTxt_Native_ProjSameExists);									  /*"存在相同名称的项目"*/
	rs_AddString(g_sLangID_Native_ProjSameIDExists, &g_sLangTxt_Native_ProjSameIDExists);								  /*"存在相同ID的项目"*/
	rs_AddString(g_sLangID_Native_TestCntGt1AutoUpdtProjName, &g_sLangTxt_Native_TestCntGt1AutoUpdtProjName);			  // 测试次数 >1时，自动更新到项目名称
	rs_AddString(g_sLangID_Native_NameWordTitle, &g_sLangTxt_Native_NameWordTitle);										  // 名称作为word标题
	rs_AddString(g_sLangID_Native_PlsEntWiringInstruc, &g_sLangTxt_Native_PlsEntWiringInstruc);							  /*_T("请在此处输入接线提示信息……")*/
	rs_AddString(g_sLangID_Native_NoMatchPresetInstrucPlsEntWiring, &g_sLangTxt_Native_NoMatchPresetInstrucPlsEntWiring); /*_T("未找到对应的预置提示信息，请在此处输入接线提示信息……")*/
	rs_AddString(g_sLangID_Native_SelDesiredWiringInstruc, &g_sLangTxt_Native_SelDesiredWiringInstruc);					  // 选择需要的接线提示信息
	rs_AddString(g_sLangID_Native_DeletestrMsg, &g_sLangTxt_Native_DeletestrMsg);										  /*"确实要删除 ["*/
	rs_AddString(g_sLangID_Native_DeletestrMsg2, &g_sLangTxt_Native_DeletestrMsg2);										  /*"] 吗？"*/
	rs_AddString(g_sLangID_Native_DeletestrMsg3, &g_sLangTxt_Native_DeletestrMsg3);										  /*_T(" ] 吗？删除后无法恢复！")*/
	rs_AddString(g_sLangID_Native_RestoreAfterTest, &g_sLangTxt_Native_RestoreAfterTest);								  /*"测试后恢复"*/
	rs_AddString(g_sLangID_Native_PrepBeforeTest, &g_sLangTxt_Native_PrepBeforeTest);									  /*"测试前准备"*/
	rs_AddString(g_sLangID_Native_CreateProjCat, &g_sLangTxt_Native_CreateProjCat);										  /*tr("新建项目分类")*/
	rs_AddString(g_sLangID_Native_CreatePrepBeforeTest, &g_sLangTxt_Native_CreatePrepBeforeTest);						  /*tr("新建测试前准备")*/
	rs_AddString(g_sLangID_Native_CreateReplyAfterTest, &g_sLangTxt_Native_CreateReplyAfterTest);						  /*tr("新建测试后恢复")*/
	rs_AddString(g_sLangID_Native_DeleteCurrSelectedProj, &g_sLangTxt_Native_DeleteCurrSelectedProj);					  /*tr("删除当前选中项目")*/
	rs_AddString(g_sLangID_Native_EditCurrSelectedProj, &g_sLangTxt_Native_EditCurrSelectedProj);						  /*tr("编辑当前选中项目")*/
	rs_AddString(g_sLangID_Native_SaveCurrSelectedProj, &g_sLangTxt_Native_SaveCurrSelectedProj);						  /*tr("保存当前选中项目")*/
	rs_AddString(g_sLangID_Native_AddFuncWizard, &g_sLangTxt_Native_AddFuncWizard);										  /*tr("添加功能向导")*/
	rs_AddString(g_sLangID_Native_StartTestFromSelProj, &g_sLangTxt_Native_StartTestFromSelProj);						  /*tr("从当前选中项目开始测试")*/
	rs_AddString(g_sLangID_Native_TestCurrSelProj, &g_sLangTxt_Native_TestCurrSelProj);									  /*tr("测试当前选中项目")*/
	rs_AddString(g_sLangID_Native_CreateCommCommand, &g_sLangTxt_Native_CreateCommCommand);								  /*"新建通讯命令"*/
	rs_AddString(g_sLangID_Native_ConfirmDelProj, &g_sLangTxt_Native_ConfirmDelProj);									  /*_T("确认删除项目")*/
	rs_AddString(g_sLangID_Native_RenameCurrSelProj, &g_sLangTxt_Native_RenameCurrSelProj);								  /*_T("重命名当前选中项目")*/
	rs_AddString(g_sLangID_Native_DeleteWiringInstr, &g_sLangTxt_Native_DeleteWiringInstr);								  /*_T("删除接线提示")*/
	rs_AddString(g_sLangID_Native_AddPrePostCommCombo, &g_sLangTxt_Native_AddPrePostCommCombo);							  /*_T("添加测试前、后通讯组合")*/
	rs_AddString(g_sLangID_Native_CreateConfigProj, &g_sLangTxt_Native_CreateConfigProj);								  /*_T("新建配置项目")*/
	rs_AddString(g_sLangID_Native_HWChanMapping, &g_sLangTxt_Native_HWChanMapping);										  /*_T("硬件通道映射")*/
	rs_AddString(g_sLangID_Native_IEC61850Config, &g_sLangTxt_Native_IEC61850Config);									  /*_T("IEC61850配置")*/
	rs_AddString(g_sLangID_Native_ConfirmDelWiringInstr, &g_sLangTxt_Native_ConfirmDelWiringInstr);						  /*_T("确认删除接线提示")*/
	rs_AddString(g_sLangID_Native_SaveProjInstrFailCommCmd, &g_sLangTxt_Native_SaveProjInstrFailCommCmd);				  /*_T("保存项目指令，创建通讯命令失败！")*/
	rs_AddString(g_sLangID_Native_SelProjNotExistRetryTest, &g_sLangTxt_Native_SelProjNotExistRetryTest);				  /*_T("当前选中的项目，不存在！请重新选择项目后进行测试")*/
	rs_AddString(g_sLangID_Native_NotSupportFeature, &g_sLangTxt_Native_NotSupportFeature);								  /*_T("该功能暂不支持……")*/
	rs_AddString(g_sLangID_Native_AddSubitem, &g_sLangTxt_Native_AddSubitem);											  // 添加至:子项
	rs_AddString(g_sLangID_Native_AddBeforeItem, &g_sLangTxt_Native_AddBeforeItem);										  // 添加至:项之前
	rs_AddString(g_sLangID_Native_AddAfterItem, &g_sLangTxt_Native_AddAfterItem);										  // 添加至:项之后
	rs_AddString(g_sLangID_Native_ProjResults, &g_sLangTxt_Native_ProjResults);											  /*_T("项目结果")*/
	rs_AddString(g_sLangID_Native_AllRptData, &g_sLangTxt_Native_AllRptData);											  /*_T("全部报告数据")*/
	rs_AddString(g_sLangID_Native_RptDataDataset, &g_sLangTxt_Native_RptDataDataset);									  /*_T("报告数据-数据集")*/
	rs_AddString(g_sLangID_Native_TestConcl, &g_sLangTxt_Native_TestConcl);												  /*_T("测试结论")*/
	rs_AddString(g_sLangID_Native_ViewRpt, &g_sLangTxt_Native_ViewRpt);													  /*_T("查看报告")*/
	rs_AddString(g_sLangID_Native_TestRun, &g_sLangTxt_Native_TestRun);													  /*_T("次测试")*/
	rs_AddString(g_sLangID_Native_CalcResult, &g_sLangTxt_Native_CalcResult);											  /*_T("次计算结果")*/

	rs_AddString(g_sLangID_Adjustment_Time, &g_sLangTxt_Adjustment_Time); // 整定动作时间
	rs_AddString(g_sLangID_Native_GroundDisTimeI, &g_sLangTxt_Native_GroundDisTimeI);
	rs_AddString(g_sLangID_Native_GroundDisTimeII, &g_sLangTxt_Native_GroundDisTimeII);
	rs_AddString(g_sLangID_Native_GroundDisTimeIII, &g_sLangTxt_Native_GroundDisTimeIII);
	rs_AddString(g_sLangID_Native_GroundDisTimeIV, &g_sLangTxt_Native_GroundDisTimeIV);
	rs_AddString(g_sLangID_Native_GroundDisTimeV, &g_sLangTxt_Native_GroundDisTimeV); // 接地距离时间（1-5段）
	rs_AddString(g_sLangID_Native_AbnCurr, &g_sLangTxt_Native_AbnCurr);
	rs_AddString(g_sLangID_Native_harmonicOrder, &g_sLangTxt_Native_harmonicOrder); // 谐波次数
	rs_AddString(g_sLangID_Native_AbnData, &g_sLangTxt_Native_AbnData);
	rs_AddString(g_sLangID_Native_harmRepresent, &g_sLangTxt_Native_harmRepresent); // 谐波表示方式
	rs_AddString(g_sLangID_Native_Identifier, &g_sLangTxt_Native_Identifier);
	rs_AddString(g_sLangID_Native_InLogic, &g_sLangTxt_Native_InLogic);
	rs_AddString(g_sLangID_Native_InputSet, &g_sLangTxt_Native_InputSet);
	rs_AddString(g_sLangID_Native_InstCurr, &g_sLangTxt_Native_InstCurr); /*QObject::tr("速断电流")*/
	rs_AddString(g_sLangID_Native_IsDC, &g_sLangTxt_Native_IsDC);
	rs_AddString(g_sLangID_Native_AbnPointSet, &g_sLangTxt_Native_AbnPointSet);
	rs_AddString(g_sLangID_Native_JitterTest, &g_sLangTxt_Native_JitterTest);
	rs_AddString(g_sLangID_Native_JitterVal, &g_sLangTxt_Native_JitterVal);
	rs_AddString(g_sLangID_Native_AbnVolt, &g_sLangTxt_Native_AbnVolt);
	rs_AddString(g_sLangID_Native_JumpVal, &g_sLangTxt_Native_JumpVal);
	rs_AddString(g_sLangID_Native_MaxTimeMalf, &g_sLangTxt_Native_MaxTimeMalf);
	rs_AddString(g_sLangID_Native_actionSetting, &g_sLangTxt_Native_actionSetting); // 动作定值
	rs_AddString(g_sLangID_Native_ModAllChan, &g_sLangTxt_Native_ModAllChan);
	rs_AddString(g_sLangID_Native_MsgSel, &g_sLangTxt_Native_MsgSel);
	rs_AddString(g_sLangID_Native_BCodeLogic, &g_sLangTxt_Native_BCodeLogic);
	rs_AddString(g_sLangID_Native_MsgSet, &g_sLangTxt_Native_MsgSet);
	rs_AddString(g_sLangID_Native_Multiple, &g_sLangTxt_Native_Multiple);
	rs_AddString(g_sLangID_Native_PreFaultVolt, &g_sLangTxt_Native_PreFaultVolt);	/*tr("故障前电压")*/
	rs_AddString(g_sLangID_Native_PreFaultCurr, &g_sLangTxt_Native_PreFaultCurr);	/*tr("故障前电流")*/
	rs_AddString(g_sLangID_Native_PhSetActValue, &g_sLangTxt_Native_PhSetActValue); // 相位整定动作值
	rs_AddString(g_sLangID_Native_BoundAngle1, &g_sLangTxt_Native_BoundAngle1);		/*tr("边界角1")*/
	rs_AddString(g_sLangID_Native_BoundAngle2, &g_sLangTxt_Native_BoundAngle2);		/*tr("边界角2")*/
	rs_AddString(g_sLangID_Native_Number, &g_sLangTxt_Native_Number);
	rs_AddString(g_sLangID_Native_ChannelSelect, &g_sLangTxt_Native_ChannelSelect);
	rs_AddString(g_sLangID_Native_PhaseDisSetI, &g_sLangTxt_Native_PhaseDisSetI);
	rs_AddString(g_sLangID_Native_PhaseDisSetII, &g_sLangTxt_Native_PhaseDisSetII);
	rs_AddString(g_sLangID_Native_PhaseDisSetIII, &g_sLangTxt_Native_PhaseDisSetIII);
	rs_AddString(g_sLangID_Native_PhaseDisSetIV, &g_sLangTxt_Native_PhaseDisSetIV);
	rs_AddString(g_sLangID_Native_PhaseDisSetV, &g_sLangTxt_Native_PhaseDisSetV); // 相间距离定值（1-5段）
	rs_AddString(g_sLangID_Native_PhaseDisTimeI, &g_sLangTxt_Native_PhaseDisTimeI);
	rs_AddString(g_sLangID_Native_PhaseDisTimeII, &g_sLangTxt_Native_PhaseDisTimeII);
	rs_AddString(g_sLangID_Native_PhaseDisTimeIII, &g_sLangTxt_Native_PhaseDisTimeIII);
	rs_AddString(g_sLangID_Native_PhaseDisTimeIV, &g_sLangTxt_Native_PhaseDisTimeIV);
	rs_AddString(g_sLangID_Native_PhaseDisTimeV, &g_sLangTxt_Native_PhaseDisTimeV); // 接地距离时间（1-5段）

	// 接地距离 电阻定值（1-5段）
	rs_AddString(g_sLangID_Native_GroundResetI, &g_sLangTxt_Native_GroundResetI);
	rs_AddString(g_sLangID_Native_GroundResetII, &g_sLangTxt_Native_GroundResetII);
	rs_AddString(g_sLangID_Native_GroundResetIII, &g_sLangTxt_Native_GroundResetIII);
	rs_AddString(g_sLangID_Native_GroundResetIV, &g_sLangTxt_Native_GroundResetIV);
	rs_AddString(g_sLangID_Native_GroundResetV, &g_sLangTxt_Native_GroundResetV);

	// 相间距离 电阻定值（1-5段）
	rs_AddString(g_sLangID_Native_PhaseResetI, &g_sLangTxt_Native_PhaseResetI);
	rs_AddString(g_sLangID_Native_PhaseResetII, &g_sLangTxt_Native_PhaseResetII);
	rs_AddString(g_sLangID_Native_PhaseResetIII, &g_sLangTxt_Native_PhaseResetIII);
	rs_AddString(g_sLangID_Native_PhaseResetIV, &g_sLangTxt_Native_PhaseResetIV);
	rs_AddString(g_sLangID_Native_PhaseResetV, &g_sLangTxt_Native_PhaseResetV);
	// 接地距离电抗 （1-5段）
	rs_AddString(g_sLangID_Native_GroundXesetI, &g_sLangTxt_Native_GroundXesetI);
	rs_AddString(g_sLangID_Native_GroundXesetII, &g_sLangTxt_Native_GroundXesetII);
	rs_AddString(g_sLangID_Native_GroundXesetIII, &g_sLangTxt_Native_GroundXesetIII);
	rs_AddString(g_sLangID_Native_GroundXesetIV, &g_sLangTxt_Native_GroundXesetIV);
	rs_AddString(g_sLangID_Native_GroundXesetV, &g_sLangTxt_Native_GroundXesetV);
	// 相间距离电抗 （1-5段）
	rs_AddString(g_sLangID_Native_PhaseXesetI, &g_sLangTxt_Native_PhaseXesetI);
	rs_AddString(g_sLangID_Native_PhaseXesetII, &g_sLangTxt_Native_PhaseXesetII);
	rs_AddString(g_sLangID_Native_PhaseXesetIII, &g_sLangTxt_Native_PhaseXesetIII);
	rs_AddString(g_sLangID_Native_PhaseXesetIV, &g_sLangTxt_Native_PhaseXesetIV);
	rs_AddString(g_sLangID_Native_PhaseXesetV, &g_sLangTxt_Native_PhaseXesetV);

	rs_AddString(g_sLangID_Native_Confm, &g_sLangTxt_Native_Confm);					// 确认
	rs_AddString(g_sLangID_Native_NatureMalf, &g_sLangTxt_Native_NatureMalf);
	rs_AddString(g_sLangID_Native_OutTime, &g_sLangTxt_Native_OutTime);
	rs_AddString(g_sLangID_Native_CurSetActValue, &g_sLangTxt_Native_CurSetActValue); // 电流整定动作值
	rs_AddString(g_sLangID_Native_OutHoldTime, &g_sLangTxt_Native_OutHoldTime);
	rs_AddString(g_sLangID_Native_NetID, &g_sLangTxt_Native_NetID);
	rs_AddString(g_sLangID_Native_networkId, &g_sLangTxt_Native_networkId); // 网络标识
	rs_AddString(g_sLangID_Native_DelayDev, &g_sLangTxt_Native_DelayDev);
	rs_AddString(g_sLangID_Native_NormTime, &g_sLangTxt_Native_NormTime);	// 常态时间
	rs_AddString(g_sLangID_Native_oneToMany, &g_sLangTxt_Native_oneToMany); // 一个控制块对应多个线条
	rs_AddString(g_sLangID_Native_DelayTime, &g_sLangTxt_Native_DelayTime);
	rs_AddString(g_sLangID_Native_OpTimeSet, &g_sLangTxt_Native_OpTimeSet); // 动作时间定值
	rs_AddString(g_sLangID_Native_OrigMsgSet, &g_sLangTxt_Native_OrigMsgSet);
	rs_AddString(g_sLangID_Native_DelayVar, &g_sLangTxt_Native_DelayVar);
	rs_AddString(g_sLangID_Native_OutputHoldTimeS, &g_sLangTxt_Native_OutputHoldTimeS);
	rs_AddString(g_sLangID_Native_outputTimeLimit, &g_sLangTxt_Native_outputTimeLimit);			// 输出限时(s)
	rs_AddString(g_sLangID_Native_OverloadCurrChannel, &g_sLangTxt_Native_OverloadCurrChannel); /*"过负荷电流通道"*/
	rs_AddString(g_sLangID_Native_delegate, &g_sLangTxt_Native_delegate);						// 委托
	rs_AddString(g_sLangID_Native_phaseDifference, &g_sLangTxt_Native_phaseDifference);			// 相别
	rs_AddString(g_sLangID_Native_DestMAC, &g_sLangTxt_Native_DestMAC);
	rs_AddString(g_sLangID_Native_PreFaultTime, &g_sLangTxt_Native_PreFaultTime); // 故障前时间(s)
	rs_AddString(g_sLangID_Native_DevSetMethod, &g_sLangTxt_Native_DevSetMethod); /*_T("定值整定方式")*/
	rs_AddString(g_sLangID_Native_DevTime, &g_sLangTxt_Native_DevTime);
	rs_AddString(g_sLangID_Native_DevVal, &g_sLangTxt_Native_DevVal);
	rs_AddString(g_sLangID_Native_DiffSpdBrk, &g_sLangTxt_Native_DiffSpdBrk);	/*"差动速断"*/
	rs_AddString(g_sLangID_Native_DurProtTrip, &g_sLangTxt_Native_DurProtTrip); // 保护动作后持续时间
	rs_AddString(g_sLangID_Native_error, &g_sLangTxt_Native_error);				// 错误
	rs_AddString(g_sLangID_Native_ErrSeqTest, &g_sLangTxt_Native_ErrSeqTest);
	rs_AddString(g_sLangID_Native_Fault, &g_sLangTxt_Native_Fault);
	rs_AddString(g_sLangID_Native_FaultChnl, &g_sLangTxt_Native_FaultChnl);				// 故障通道
	rs_AddString(g_sLangID_Native_FaultCurrValue, &g_sLangTxt_Native_FaultCurrValue);	/*故障电流*/
	rs_AddString(g_sLangID_Native_FaultTrigMethod, &g_sLangTxt_Native_FaultTrigMethod); // 故障触发方式
	rs_AddString(g_sLangID_Native_FaultVoltDef, &g_sLangTxt_Native_FaultVoltDef);		// 故障电压定义
	rs_AddString(g_sLangID_Native_FileName, &g_sLangTxt_Native_FileName);				// 文件名称
	rs_AddString(g_sLangID_Native_FlipMoment, &g_sLangTxt_Native_FlipMoment);
	rs_AddString(g_sLangID_Native_FrameDrop, &g_sLangTxt_Native_FrameDrop);
	rs_AddString(g_sLangID_Native_FlyDot, &g_sLangTxt_Native_FlyDot);
	rs_AddString(g_sLangID_Native_FreqSetActValue, &g_sLangTxt_Native_FreqSetActValue);	  // 频率整定动作值
	rs_AddString(g_sLangID_Native_fundamentalAmp, &g_sLangTxt_Native_fundamentalAmp);	  // 基波幅值
	rs_AddString(g_sLangID_Native_fundamentalPhase, &g_sLangTxt_Native_fundamentalPhase); // 基波相位
	rs_AddString(g_sLangID_Native_fundamentalFreq, &g_sLangTxt_Native_fundamentalFreq);	  // 基波频率

	rs_AddString(g_sLangID_Native_PreFautTime, &g_sLangTxt_Native_PreFautTime); /*tr("故障时间(S)")*/
	rs_AddString(g_sLangID_Native_ProjName, &g_sLangTxt_Native_ProjName);		/*"项目名称"*/
	rs_AddString(g_sLangID_Native_QltyExcp, &g_sLangTxt_Native_QltyExcp);
	rs_AddString(g_sLangID_Native_quote, &g_sLangTxt_Native_quote);									// 引用
	rs_AddString(g_sLangID_Native_RatioBrakeCoefficient, &g_sLangTxt_Native_RatioBrakeCoefficient); // 比率制动系数
	rs_AddString(g_sLangID_Native_receive, &g_sLangTxt_Native_receive);								// 接收
	rs_AddString(g_sLangID_Native_ReturnTime, &g_sLangTxt_Native_ReturnTime);
	rs_AddString(g_sLangID_Native_ReturnValue, &g_sLangTxt_Native_ReturnValue);
	rs_AddString(g_sLangID_Native_SampDelay, &g_sLangTxt_Native_SampDelay);
	rs_AddString(g_sLangID_Native_SamplingFrequency, &g_sLangTxt_Native_SamplingFrequency);
	rs_AddString(g_sLangID_Native_saveFailed, &g_sLangTxt_Native_saveFailed); // 保存失败！\n
	rs_AddString(g_sLangID_Native_SeqDev, &g_sLangTxt_Native_SeqDev);
	rs_AddString(g_sLangID_Native_SetActVolt, &g_sLangTxt_Native_SetActVolt);
	rs_AddString(g_sLangID_Native_SetPickCurr, &g_sLangTxt_Native_SetPickCurr); // 整定动作电流
	rs_AddString(g_sLangID_Native_ShiftCount, &g_sLangTxt_Native_ShiftCount);
	rs_AddString(g_sLangID_Native_ShortCircuitVs, &g_sLangTxt_Native_ShortCircuitVs);
	rs_AddString(g_sLangID_Native_ShortZImpAng, &g_sLangTxt_Native_ShortZImpAng);
	rs_AddString(g_sLangID_Native_ShortZImp, &g_sLangTxt_Native_ShortZImp);	  /*短路阻抗*/
	rs_AddString(g_sLangID_Native_smvReceive, &g_sLangTxt_Native_smvReceive); // SMV 接收
	rs_AddString(g_sLangID_Native_SndFreq, &g_sLangTxt_Native_SndFreq);
	rs_AddString(g_sLangID_Native_SndFreqPS, &g_sLangTxt_Native_SndFreqPS);
	rs_AddString(g_sLangID_Native_SndTimeS, &g_sLangTxt_Native_SndTimeS);
	rs_AddString(g_sLangID_Native_SrcMAC, &g_sLangTxt_Native_SrcMAC);
	rs_AddString(g_sLangID_Native_StateD, &g_sLangTxt_Native_StateD);
	rs_AddString(g_sLangID_Native_subscriptionIndex, &g_sLangTxt_Native_subscriptionIndex);				// 订阅索引
	rs_AddString(g_sLangID_Native_subscriptionReference, &g_sLangTxt_Native_subscriptionReference);		// 订阅引用
	rs_AddString(g_sLangID_Native_subscriptionDescription, &g_sLangTxt_Native_subscriptionDescription); // 订阅描述
	rs_AddString(g_sLangID_Native_superimpose_ornot, &g_sLangTxt_Native_superimpose_ornot);				// 是否叠加非周期分量:
	rs_AddString(g_sLangID_Native_SVOrigMsg, &g_sLangTxt_Native_SVOrigMsg);
	rs_AddString(g_sLangID_Native_SwitchVal, &g_sLangTxt_Native_SwitchVal);
	rs_AddString(g_sLangID_Native_test_process, &g_sLangTxt_Native_test_process); // 试验过程:
	rs_AddString(g_sLangID_Native_TestPrecision, &g_sLangTxt_Native_TestPrecision);
	rs_AddString(g_sLangID_Native_TransConnForm, &g_sLangTxt_Native_TransConnForm);
	rs_AddString(g_sLangID_Native_TransientFault, &g_sLangTxt_Native_TransientFault);
	rs_AddString(g_sLangID_Native_TrigHoldTime, &g_sLangTxt_Native_TrigHoldTime);
	rs_AddString(g_sLangID_Native_TrigMode, &g_sLangTxt_Native_TrigMode);
	rs_AddString(g_sLangID_Native_ValidBit, &g_sLangTxt_Native_ValidBit);
	rs_AddString(g_sLangID_Native_VolSetActValue, &g_sLangTxt_Native_VolSetActValue);			// 电压整定动作值
	rs_AddString(g_sLangID_Native_vTerminalConnectDia, &g_sLangTxt_Native_vTerminalConnectDia); // 虚端子连接图
	rs_AddString(g_sLangID_Native_YNInputStop, &g_sLangTxt_Native_YNInputStop);					// 是否开入停止
	rs_AddString(g_sLangID_Out1_Situation, &g_sLangTxt_Out1_Situation);							// 开出1状态
	rs_AddString(g_sLangID_Out2_Situation, &g_sLangTxt_Out2_Situation);							// 开出2状态
	rs_AddString(g_sLangID_Out3_Situation, &g_sLangTxt_Out3_Situation);							// 开出3状态
	rs_AddString(g_sLangID_without, &g_sLangTxt_without);										// 无
	rs_AddString(g_sLangID_Native_VoltSlip, &g_sLangTxt_Native_VoltSlip);						// 电压滑差
	rs_AddString(g_sLangID_Native_GOOSEOrigMsg, &g_sLangTxt_Native_GOOSEOrigMsg);				// GOOSE原始报文
	rs_AddString(g_sLangID_Native_gooseReceive, &g_sLangTxt_Native_gooseReceive);				// GOOSE 接收
	rs_AddString(g_sLangID_Native_GPSTriggerHour, &g_sLangTxt_Native_GPSTriggerHour);
	rs_AddString(g_sLangID_Native_GPSTriggerMinute, &g_sLangTxt_Native_GPSTriggerMinute);
	rs_AddString(g_sLangID_Native_GPSTriggerSecond, &g_sLangTxt_Native_GPSTriggerSecond);
	rs_AddString(g_sLangID_Native_GradualTimeScale, &g_sLangTxt_Native_GradualTimeScale);
	rs_AddString(g_sLangID_Native_GroundDisSetI, &g_sLangTxt_Native_GroundDisSetI);
	rs_AddString(g_sLangID_Native_GroundDisSetII, &g_sLangTxt_Native_GroundDisSetII);
	rs_AddString(g_sLangID_Native_GroundDisSetIII, &g_sLangTxt_Native_GroundDisSetIII);
	rs_AddString(g_sLangID_Native_GroundDisSetIV, &g_sLangTxt_Native_GroundDisSetIV);


	rs_AddString(g_sLangID_Native_FinalVoltChange, &g_sLangTxt_Native_FinalVoltChange);	  // 电压变化终值
	rs_AddString(g_sLangID_Allow_FreqDifference, &g_sLangTxt_Allow_FreqDifference);				  // 允许频差
	rs_AddString(g_sLangID_LeadingAngle, &g_sLangTxt_LeadingAngle);								  // 导前角

	rs_AddString(g_sLangID_Vol_ReguPeriod, &g_sLangTxt_Vol_ReguPeriod);							  // 调压周期
	rs_AddString(g_sLangID_Freq_ReguPeriod, &g_sLangTxt_Freq_ReguPeriod);						  // 调频周期
	rs_AddString(g_sLangID_LeadingTime, &g_sLangTxt_LeadingTime);								  // 导前时间
	rs_AddString(g_sLangID_Allow_VolDifference, &g_sLangTxt_Allow_VolDifference);				  // 允许压差
	rs_AddString(g_sLangID_Grid_Rated_Voltage, &g_sLangTxt_Grid_Rated_Voltage);					  // 待并侧额定电压
	rs_AddString(g_sLangID_System_Rated_Voltage, &g_sLangTxt_System_Rated_Voltage);				  // 系统侧额定电压
	rs_AddString(g_sLangID_System_Rated_Frequency, &g_sLangTxt_System_Rated_Frequency);			  // 系统侧额定频率
	rs_AddString(g_sLangID_Freq_BoundValue, &g_sLangTxt_Freq_BoundValue);						  // 频率边界值
	rs_AddString(g_sLangID_FreqDif, &g_sLangTxt_FreqDif);										  // 频差
	rs_AddString(g_sLangID_Grid_FreqHZ, &g_sLangTxt_Grid_FreqHZ);								  // 待并侧频率（HZ）
	rs_AddString(g_sLangID_Native_InitVoltChange, &g_sLangTxt_Native_InitVoltChange);	  // 电压变化始值
	rs_AddString(g_sLangID_Native_LowVLockVal, &g_sLangTxt_Native_LowVLockVal);							/*_T("低压闭锁值")*/
	rs_AddString(g_sLangID_Native_LowVoltUnderloadTripSet, &g_sLangTxt_Native_LowVoltUnderloadTripSet); // 低压减载动作值
	rs_AddString(g_sLangID_Native_maxSyncTime, &g_sLangTxt_Native_maxSyncTime);			// 最大同步时间
	rs_AddString(g_sLangID_Out4_Mode, &g_sLangTxt_Out4_Mode);									  // 开出4输出方式
	rs_AddString(g_sLangID_Native_VoltChangeStep, &g_sLangTxt_Native_VoltChangeStep);	  // 电压变化步长
	rs_AddString(g_sLangID_Vol_BoundValue, &g_sLangTxt_Vol_BoundValue);							  // 电压边界值
	rs_AddString(g_sLangID_Native_VoltSlipAct, &g_sLangTxt_Native_VoltSlipAct);							/*QString::tr("电压滑差动作值")*/
	rs_AddString(g_sLangID_Native_LockVoltDef, &g_sLangTxt_Native_LockVoltDef);							/*_T("闭锁电压定义")*/
	rs_AddString(g_sLangID_VolDif, &g_sLangTxt_VolDif);											  // 压差
	rs_AddString(g_sLangID_Native_FaultProp, &g_sLangTxt_Native_FaultProp);
	rs_AddString(g_sLangID_Native_ControlCurrent, &g_sLangTxt_Native_ControlCurrent);
	rs_AddString(g_sLangID_Native_AngleDiffClockHrsTestWindings, &g_sLangTxt_Native_AngleDiffClockHrsTestWindings); /*tr("测试绕组之间角差(钟点数)")*/

	rs_AddString(g_sLangID_Native_StartSegSlope, &g_sLangTxt_Native_StartSegSlope);					/*_T("启动段斜率")*/
	rs_AddString(g_sLangID_Native_FundRatioBrkSlope1, &g_sLangTxt_Native_FundRatioBrkSlope1);		/*_T("基波比率制动特性斜率1")*/
	rs_AddString(g_sLangID_Native_FundRatioBrkSlope2, &g_sLangTxt_Native_FundRatioBrkSlope2);		/*_T("基波比率制动特性斜率2")*/
	rs_AddString(g_sLangID_Native_FundRatioBrkSlope3, &g_sLangTxt_Native_FundRatioBrkSlope3);		/*_T("基波比率制动特性斜率3")*/
	rs_AddString(g_sLangID_Native_SecHarBrkCoef, &g_sLangTxt_Native_SecHarBrkCoef);					/*_T("二次谐波制动系数")*/
	rs_AddString(g_sLangID_Native_ThiHarBrkCoef, &g_sLangTxt_Native_ThiHarBrkCoef);					/*_T("三次谐波制动系数")*/
	rs_AddString(g_sLangID_Native_FivHarBrkCoef, &g_sLangTxt_Native_FivHarBrkCoef);					/*_T("五次谐波制动系数")*/
	rs_AddString(g_sLangID_Native_HighVoltSideRatedVolt, &g_sLangTxt_Native_HighVoltSideRatedVolt);					/*tr("高压侧额定电压(kV)")*/
	rs_AddString(g_sLangID_Native_MedVoltSideRatedVolt, &g_sLangTxt_Native_MedVoltSideRatedVolt);					/*tr("中压侧额定电压(kV)")*/
	rs_AddString(g_sLangID_Native_SearchMeth, &g_sLangTxt_Native_SearchMeth);
	rs_AddString(g_sLangID_Native_MedVoltWindingConnType, &g_sLangTxt_Native_MedVoltWindingConnType);				/*tr("中压侧绕组接线型式")*/
	rs_AddString(g_sLangID_Native_LowVoltSideRatedVolt, &g_sLangTxt_Native_LowVoltSideRatedVolt);					/*tr("低压侧额定电压(kV)")*/
	rs_AddString(g_sLangID_Native_HVSideCTPrimVal, &g_sLangTxt_Native_HVSideCTPrimVal);								/*"高压侧CT一次值(A)"*/
	rs_AddString(g_sLangID_Native_HVSide2CTPrimVal, &g_sLangTxt_Native_HVSide2CTPrimVal);							/*"高压侧CT二次值(A)"*/

	rs_AddString(g_sLangID_Native_MVSideCTPrimVal, &g_sLangTxt_Native_MVSideCTPrimVal);	  /*"中压侧CT一次值(A)"*/
	rs_AddString(g_sLangID_Native_MVSide2CTPrimVal, &g_sLangTxt_Native_MVSide2CTPrimVal); /*"中压侧CT二次值(A)"*/
	rs_AddString(g_sLangID_Native_LVSideCTPrimVal, &g_sLangTxt_Native_LVSideCTPrimVal);	  /*"低压侧CT一次值(A)"*/
	rs_AddString(g_sLangID_Native_LVSide2CTPrimVal, &g_sLangTxt_Native_LVSide2CTPrimVal); /*"低压侧CT二次值(A)"*/
	rs_AddString(g_sLangID_Native_ProportionalBrakingFactor, &g_sLangTxt_Native_ProportionalBrakingFactor);
	rs_AddString(g_sLangID_Native_RefCurrentSel, &g_sLangTxt_Native_RefCurrentSel);					/*_T("基准电流选择")*/
	rs_AddString(g_sLangID_Native_TransfRatedCapacity, &g_sLangTxt_Native_TransfRatedCapacity);						/*tr("变压器额定容量(MVA)")*/
	rs_AddString(g_sLangID_lowfreqloadre_ActTime, &g_sLangTxt_lowfreqloadre_ActTime);	  // 低周减载动作时间
	rs_AddString(g_sLangID_interlock_vol, &g_sLangTxt_interlock_vol);					  // 闭锁电压
	rs_AddString(g_sLangID_interlock_cur, &g_sLangTxt_interlock_cur);					  // 闭锁电流
	rs_AddString(g_sLangID_Native_sliptripValue, &g_sLangTxt_Native_sliptripValue);		  // 滑差闭锁值
	rs_AddString(g_sLangID_Native_VoltChangeAmt, &g_sLangTxt_Native_VoltChangeAmt); // 电压变化量
	rs_AddString(g_sLangID_Native_AccelSignalCont, &g_sLangTxt_Native_AccelSignalCont); // 加速信号接点
	rs_AddString(g_sLangID_Native_DecelSignalCont, &g_sLangTxt_Native_DecelSignalCont); // 减速信号接点
	rs_AddString(g_sLangID_Native_TransImp, &g_sLangTxt_Native_TransImp);				// 变压器阻抗
	rs_AddString(g_sLangID_Native_SysImp, &g_sLangTxt_Native_SysImp);					// 系统侧阻抗
	rs_AddString(g_sLangID_Native_PreOscTime, &g_sLangTxt_Native_PreOscTime);			// 振荡前时间
	rs_AddString(g_sLangID_Native_OscilCount, &g_sLangTxt_Native_OscilCount);		  /*_T("振荡次数")*/
	rs_AddString(g_sLangID_Native_AngDef, &g_sLangTxt_Native_AngDef);				// 角度定义
	rs_AddString(g_sLangID_Native_ConnMethod, &g_sLangTxt_Native_ConnMethod);		// 接线方式
	rs_AddString(g_sLangID_Native_ActDirection, &g_sLangTxt_Native_ActDirection);
	rs_AddString(g_sLangID_Native_LowVoltageDef, &g_sLangTxt_Native_LowVoltageDef);
	rs_AddString(g_sLangID_Native_LeadAngle, &g_sLangTxt_Native_LeadAngle);				/*_T("超前角度")*/
	rs_AddString(g_sLangID_Native_LagAngle, &g_sLangTxt_Native_LagAngle);				/*_T("滞后角度")*/
	rs_AddString(g_sLangID_Native_FreqChgZSetting, &g_sLangTxt_Native_FreqChgZSetting);			/*_T("工频变化量阻抗定值")*/
	rs_AddString(g_sLangID_Native_CalcCoef, &g_sLangTxt_Native_CalcCoef);						// 计算系数
	rs_AddString(g_sLangID_Native_PosSeqSensAng, &g_sLangTxt_Native_PosSeqSensAng);				/*_T("正序灵敏角")*/
	rs_AddString(g_sLangID_Native_GndDistOffset, &g_sLangTxt_Native_GndDistOffset);				/*_T("接地距离偏移角")*/
	rs_AddString(g_sLangID_Native_PhaseDistOffset, &g_sLangTxt_Native_PhaseDistOffset);			/*_T("相间距离偏移角")*/
	rs_AddString(g_sLangID_Native_2HarBrkCoef, &g_sLangTxt_Native_2HarBrkCoef);							  /*QObject::tr("2次谐波制动系数")*/
	rs_AddString(g_sLangID_Native_3HarBrkCoef, &g_sLangTxt_Native_3HarBrkCoef);							  /*QObject::tr("3次谐波制动系数")*/
	rs_AddString(g_sLangID_Native_5HarBrkCoef, &g_sLangTxt_Native_5HarBrkCoef);		
	rs_AddString(g_sLangID_Native_BalCoeff, &g_sLangTxt_Native_BalCoeff);

	rs_AddString(g_sLangID_Native_ConnectFail, &g_sLangTxt_Native_ConnectFail);
	rs_AddString(g_sLangID_Native_TestrDisconn, &g_sLangTxt_Native_TestrDisconn);
	rs_AddString(g_sLangID_Native_UnBatteryInfor, &g_sLangTxt_Native_UnBatteryInfor);
	rs_AddString(g_sLangID_Native_LoadingMacroTest, &g_sLangTxt_Native_LoadingMacroTest);
	rs_AddString(g_sLangID_Native_LoadingBar, &g_sLangTxt_Native_LoadingBar);

	rs_AddString(g_sLangID_remotemeas,&g_sLangTxt_remotemeas);
	rs_AddString(g_sLangID_Internal, &g_sLangTxt_Internal);
	rs_AddString(g_sLangID_Operation, &g_sLangTxt_Operation);
	rs_AddString(g_sLangID_Record, &g_sLangTxt_Record);
	rs_AddString(g_sLangID_EventType, &g_sLangTxt_EventType);
	rs_AddString(g_sLangID_DeviceTime, &g_sLangTxt_DeviceTime);
	rs_AddString(g_sLangID_PCTime, &g_sLangTxt_PCTime);
	rs_AddString(g_sLangID_Native_TempSaveSucc, &g_sLangTxt_Native_TempSaveSucc);
	rs_AddString(g_sLangID_Native_TempSaveFail, &g_sLangTxt_Native_TempSaveFail);
	rs_AddString(g_sLangID_Native_Success, &g_sLangTxt_Native_Success);
	rs_AddString(g_sLangID_Native_Timeout, &g_sLangTxt_Native_Timeout);
	rs_AddString(g_sLangID_Native_Fail, &g_sLangTxt_Native_Fail);
	rs_AddString(g_sLangID_Native_TempSave, &g_sLangTxt_Native_TempSave);
	rs_AddString(g_sLangID_Native_ExportWordReport, &g_sLangTxt_Native_ExportWordReport);
	rs_AddString(g_sLangID_Native_ReportSave, &g_sLangTxt_Native_ReportSave);

	rs_AddString(g_sLangID_Impedance_CalMode, &g_sLangTxt_Impedance_CalMode);
	rs_AddString(g_sLangID_Impedance_Choose, &g_sLangTxt_Impedance_Choose);
	rs_AddString(g_sLangID_Impedance_ShortCurr, &g_sLangTxt_Impedance_ShortCurr);
	rs_AddString(g_sLangID_Impedance_Delayed, &g_sLangTxt_Impedance_Delayed);
	rs_AddString(g_sLangID_Impedance_VarChoose, &g_sLangTxt_Impedance_VarChoose);
	rs_AddString(g_sLangID_Impedance_Mode, &g_sLangTxt_Impedance_Mode);
	rs_AddString(g_sLangID_Impedance_Time, &g_sLangTxt_Impedance_Time);
	rs_AddString(g_sLangID_Impedance_ChangeType, &g_sLangTxt_Impedance_ChangeType);
	rs_AddString(g_sLangID_Impedance_Auto, &g_sLangTxt_Impedance_Auto);
	rs_AddString(g_sLangID_Impedance_Mutation, &g_sLangTxt_Impedance_Mutation);
 	rs_AddString(g_sLangID_ExpSucc, &g_sLangTxt_ExpSucc);											//sun				
 	rs_AddString(g_sLangID_ExpFail, &g_sLangTxt_ExpFail);											//sun
 	rs_AddString(g_sLangID_ImpSucc, &g_sLangTxt_ImpSucc);                                           //sun
 	rs_AddString(g_sLangID_ImpFail, &g_sLangTxt_ImpFail);                                           //sun
 	rs_AddString(g_sLangID_RemainingMemorySize, &g_sLangTxt_RemainingMemorySize);                   //sun
 	rs_AddString(g_sLangID_InsufficientSystemMemory, &g_sLangTxt_InsufficientSystemMemory);         //sun
 	rs_AddString(g_sLangID_ExistenceSCDFiles, &g_sLangTxt_ExistenceSCDFiles);	                    //sun
 	rs_AddString(g_sLangID_NoExistenceSCLFiles, &g_sLangTxt_NoExistenceSCLFiles);                   //sun
 	rs_AddString(g_sLangID_AnalysisSCLFiles, &g_sLangTxt_AnalysisSCLFiles);                         //sun
 	rs_AddString(g_sLangID_LoadSCLFiles, &g_sLangTxt_LoadSCLFiles);	                                //sun
 	rs_AddString(g_sLangID_LoadSCLFilesProgressBar, &g_sLangTxt_LoadSCLFilesProgressBar);           //sun
 	rs_AddString(g_sLangID_SaveSCLFiles, &g_sLangTxt_SaveSCLFiles);                                 //sun

	rs_AddString(g_sLangID_IEC_DescExternal, &g_sLangTxt_IEC_DescExternal);
	rs_AddString(g_sLangID_Impedance_FunParas, &g_sLangTxt_Impedance_FunParas);
	rs_AddString(g_sLangID_Impedance_Variable, &g_sLangTxt_Impedance_Variable);
	rs_AddString(g_sLangID_Impedance_ChangeStart, &g_sLangTxt_Impedance_ChangeStart);
	rs_AddString(g_sLangID_Impedance_ChangeEnd, &g_sLangTxt_Impedance_ChangeEnd);
	rs_AddString(g_sLangID_Impedance_ChangStep, &g_sLangTxt_Impedance_ChangStep);
	rs_AddString(g_sLangID_Impedance_NormalTime, &g_sLangTxt_Impedance_NormalTime);
	rs_AddString(g_sLangID_Impedance_FailTime, &g_sLangTxt_Impedance_FailTime);
	rs_AddString(g_sLangID_Impedance_ConstantCur, &g_sLangTxt_Impedance_ConstantCur);
	rs_AddString(g_sLangID_Impedance_ConstantVol, &g_sLangTxt_Impedance_ConstantVol);
	rs_AddString(g_sLangID_Impedance_FixedSystem, &g_sLangTxt_Impedance_FixedSystem);

	rs_AddString(g_sLangID_Gradient_FailModes, &g_sLangTxt_Gradient_FailModes);
	rs_AddString(g_sLangID_Gradient_Change, &g_sLangTxt_Gradient_Change);
	rs_AddString(g_sLangID_Gradient_ImpAngle, &g_sLangTxt_Gradient_ImpAngle);
	rs_AddString(g_sLangID_Gradient_ChangeTime, &g_sLangTxt_Gradient_ChangeTime);
	rs_AddString(g_sLangID_Gradient_FailBeforeTime, &g_sLangTxt_Gradient_FailBeforeTime);
	rs_AddString(g_sLangID_Gradient_FailVol, &g_sLangTxt_Gradient_FailVol);
	rs_AddString(g_sLangID_Gradient_FailCur, &g_sLangTxt_Gradient_FailCur);
	rs_AddString(g_sLangID_Gradient_FailAngle, &g_sLangTxt_Gradient_FailAngle);
	rs_AddString(g_sLangID_Gradient_RampParas, &g_sLangTxt_Gradient_RampParas);
	//rs_AddString(g_sLangID_Gradient_VarSet, &g_sLangTxt_Gradient_VarSet);
	rs_AddString(g_sLangID_Gradient_CommonParas, &g_sLangTxt_Gradient_CommonParas);
	rs_AddString(g_sLangID_Gradient_BinBout, &g_sLangTxt_Gradient_BinBout);
	rs_AddString(g_sLangID_Gradient_BoutNormal, &g_sLangTxt_Gradient_BoutNormal);
	rs_AddString(g_sLangID_Gradient_BoutFaultState, &g_sLangTxt_Gradient_BoutFaultState);


	rs_AddString(g_sLangID_Gradient_Test1, &g_sLangTxt_Gradient_Test1);
	rs_AddString(g_sLangID_Gradient_Test2, &g_sLangTxt_Gradient_Test2);
	rs_AddString(g_sLangID_Gradient_Test3, &g_sLangTxt_Gradient_Test3);
	rs_AddString(g_sLangID_Native_PhaseABshort, &g_sLangTxt_Native_PhaseABshort);
	rs_AddString(g_sLangID_Native_PhaseBCshort, &g_sLangTxt_Native_PhaseBCshort);
	rs_AddString(g_sLangID_Native_PhaseCAshort, &g_sLangTxt_Native_PhaseCAshort);
	rs_AddString(g_sLangID_Native_PhaseABshortCcur, &g_sLangTxt_Native_PhaseABshortCcur);
	rs_AddString(g_sLangID_Native_PhaseBCshortAcur, &g_sLangTxt_Native_PhaseBCshortAcur);
	rs_AddString(g_sLangID_Native_PhaseCAshortBcur, &g_sLangTxt_Native_PhaseCAshortBcur);
	rs_AddString(g_sLangID_Native_PhaseABshortBcur, &g_sLangTxt_Native_PhaseABshortBcur);
	rs_AddString(g_sLangID_Native_PhaseBCshortCcur, &g_sLangTxt_Native_PhaseBCshortCcur);
	rs_AddString(g_sLangID_Native_PhaseCAshortAcur, &g_sLangTxt_Native_PhaseCAshortAcur);
	rs_AddString(g_sLangID_Native_PosVol, &g_sLangTxt_Native_PosVol);
	rs_AddString(g_sLangID_Native_NegVol, &g_sLangTxt_Native_NegVol);
	rs_AddString(g_sLangID_Native_ZeroVol3U0, &g_sLangTxt_Native_ZeroVol3U0);
	rs_AddString(g_sLangID_Native_PosVolU1, &g_sLangTxt_Native_PosVolU1);
	rs_AddString(g_sLangID_Native_NegVolU2, &g_sLangTxt_Native_NegVolU2);
	rs_AddString(g_sLangID_Native_Zero3U0, &g_sLangTxt_Native_Zero3U0);

	rs_AddString(g_sLangID_CBOperate_TimeAfterTrigger, &g_sLangTxt_CBOperate_TimeAfterTrigger);
	rs_AddString(g_sLangID_CBOperate_PTVPos, &g_sLangTxt_CBOperate_PTVPos);
	rs_AddString(g_sLangID_CBOperate_CTPos, &g_sLangTxt_CBOperate_CTPos);
	rs_AddString(g_sLangID_CBOperate_AfterOpenTime, &g_sLangTxt_CBOperate_AfterOpenTime);
	rs_AddString(g_sLangID_CBOperate_RecloseTime, &g_sLangTxt_CBOperate_RecloseTime);
	rs_AddString(g_sLangID_CBOperate_AfterAccTime, &g_sLangTxt_CBOperate_AfterAccTime);
	rs_AddString(g_sLangID_CBOperate_PTPos, &g_sLangTxt_CBOperate_PTPos);
	rs_AddString(g_sLangID_CBOperate_TPos, &g_sLangTxt_CBOperate_TPos);
	rs_AddString(g_sLangID_CBOperate_CTPos1, &g_sLangTxt_CBOperate_CTPos1);
	rs_AddString(g_sLangID_CBOperate_TPos1, &g_sLangTxt_CBOperate_TPos1);
	rs_AddString(g_sLangID_CBOperate_Overall, &g_sLangTxt_CBOperate_Overall);
	rs_AddString(g_sLangID_CBOperate_Zs, &g_sLangTxt_CBOperate_Zs);
	rs_AddString(g_sLangID_CBOperate_ZsPh, &g_sLangTxt_CBOperate_ZsPh);
	rs_AddString(g_sLangID_CBOperate_SimulateBreakerDelay, &g_sLangTxt_CBOperate_SimulateBreakerDelay);
	rs_AddString(g_sLangID_CBOperate_BrkBreakTime, &g_sLangTxt_CBOperate_BrkBreakTime);
	rs_AddString(g_sLangID_CBOperate_BrkCloseTime, &g_sLangTxt_CBOperate_BrkCloseTime);
	rs_AddString(g_sLangID_CBOperate_FaultIncMode, &g_sLangTxt_CBOperate_FaultIncMode);
	rs_AddString(g_sLangID_CBOperate_FaultAngle, &g_sLangTxt_CBOperate_FaultAngle);
	rs_AddString(g_sLangID_CBOperate_BIPlusDC, &g_sLangTxt_CBOperate_BIPlusDC);
	rs_AddString(g_sLangID_CBOperate_VzDefine, &g_sLangTxt_CBOperate_VzDefine);
	rs_AddString(g_sLangID_CBOperate_PsuVzRefPhase, &g_sLangTxt_CBOperate_PsuVzRefPhase);
	rs_AddString(g_sLangID_CBOperate_VzPh, &g_sLangTxt_CBOperate_VzPh);
	rs_AddString(g_sLangID_CBOperate_NotSimulated, &g_sLangTxt_CBOperate_NotSimulated);
	rs_AddString(g_sLangID_CBOperate_Random, &g_sLangTxt_CBOperate_Random);
	rs_AddString(g_sLangID_CBOperate_FixedValue, &g_sLangTxt_CBOperate_FixedValue);
	rs_AddString(g_sLangID_CBOperate_UabPhase, &g_sLangTxt_CBOperate_UabPhase);
	rs_AddString(g_sLangID_CBOperate_UbcPhase, &g_sLangTxt_CBOperate_UbcPhase);
	rs_AddString(g_sLangID_CBOperate_UcaPhase, &g_sLangTxt_CBOperate_UcaPhase);
	rs_AddString(g_sLangID_CBOperate_SingleHop, &g_sLangTxt_CBOperate_SingleHop);
	rs_AddString(g_sLangID_CBOperate_TripleJump, &g_sLangTxt_CBOperate_TripleJump);
	rs_AddString(g_sLangID_CBOperate_Reclose, &g_sLangTxt_CBOperate_Reclose);
	rs_AddString(g_sLangID_CBOperate_BinBoutSelect, &g_sLangTxt_CBOperate_BinBoutSelect);
	rs_AddString(g_sLangID_CBOperate_BinABCD, &g_sLangTxt_CBOperate_BinABCD);
	rs_AddString(g_sLangID_CBOperate_BinEFGH, &g_sLangTxt_CBOperate_BinEFGH);
	rs_AddString(g_sLangID_CBOperate_OutputSwitchMode, &g_sLangTxt_CBOperate_OutputSwitchMode);
	rs_AddString(g_sLangID_CBOperate_OutputDelayTime, &g_sLangTxt_CBOperate_OutputDelayTime);
	rs_AddString(g_sLangID_CBOperate_StartTime, &g_sLangTxt_CBOperate_StartTime);
	rs_AddString(g_sLangID_CBOperate_BinStart, &g_sLangTxt_CBOperate_BinStart);
	rs_AddString(g_sLangID_CBOperate_AbsOrRelative, &g_sLangTxt_CBOperate_AbsOrRelative);
	rs_AddString(g_sLangID_CBOperate_AbsRelative, &g_sLangTxt_CBOperate_AbsRelative);
	rs_AddString(g_sLangID_CBOperate_CombError, &g_sLangTxt_CBOperate_CombError);
	rs_AddString(g_sLangID_CBOperate_Instan, &g_sLangTxt_CBOperate_Instan);
	rs_AddString(g_sLangID_CBOperate_Perpetual, &g_sLangTxt_CBOperate_Perpetual);
	rs_AddString(g_sLangID_CBOperate_MaxFaultTime, &g_sLangTxt_CBOperate_MaxFaultTime);
	rs_AddString(g_sLangID_CBOperate_FaultMoment, &g_sLangTxt_CBOperate_FaultMoment);
	rs_AddString(g_sLangID_CBOperate_Hour, &g_sLangTxt_CBOperate_Hour);
	rs_AddString(g_sLangID_CBOperate_Minute, &g_sLangTxt_CBOperate_Minute);
	rs_AddString(g_sLangID_CBOperate_Second, &g_sLangTxt_CBOperate_Second);
	rs_AddString(g_sLangID_CBOperate_ImpRepre, &g_sLangTxt_CBOperate_ImpRepre);
	rs_AddString(g_sLangID_CBOperate_AmpPhase, &g_sLangTxt_CBOperate_AmpPhase);
	rs_AddString(g_sLangID_CBOperate_ConversionTime, &g_sLangTxt_CBOperate_ConversionTime);
	rs_AddString(g_sLangID_CBOperate_Reverse, &g_sLangTxt_CBOperate_Reverse);
	rs_AddString(g_sLangID_CBOperate_Positive, &g_sLangTxt_CBOperate_Positive);
	rs_AddString(g_sLangID_CBOperate_ConversionFail, &g_sLangTxt_CBOperate_ConversionFail);
	rs_AddString(g_sLangID_Native_CommandTimeout, &g_sLangTxt_Native_CommandTimeout);

}

void CXLangResource_Native::InitLangTxt()
{
	CXLanguageResourceAtsBase::InitLangTxt();

	g_sLangID_Native_LangSetting = _T("Native_LangSetting");
	g_sLangTxt_Native_LangSetting = _T("语言设置");
	g_sLangID_Native_CustomSetup = _T("Native_CustomSetup");
	g_sLangTxt_Native_CustomSetup = _T("自定义设置");
	g_sLangID_Native_LangTipContext = _T("Native_LangTipContext");
	g_sLangTxt_Native_LangTipContext = _T("语言设置重启后生效");
	g_sLangID_Native_Amplitude = _T("Native_Amplitude");
	g_sLangTxt_Native_Amplitude = _T("幅值");
	g_sLangID_Native_Phase = _T("Native_Angle");
	g_sLangTxt_Native_Phase = _T("相位");
	g_sLangID_Native_Freq = _T("Native_Freq");
	g_sLangTxt_Native_Freq = _T("频率");
	g_sLangID_Native_Channel = _T("Native_Channel");
	g_sLangTxt_Native_Channel = _T("通道");
	g_sLangID_Native_DC = _T("Native_DC");
	g_sLangTxt_Native_DC = _T("直流");
	g_sLangID_Native_Fundamental = _T("Native_Fundamental");
	g_sLangTxt_Native_Fundamental = _T("基波");
	g_sLangID_Native_Validity = _T("Native_Validity");
	g_sLangTxt_Native_Validity = _T("有效性");
	g_sLangID_Native_Overhaul = _T("Native_Overhaul");
	g_sLangTxt_Native_Overhaul = _T("检修");
	g_sLangID_Native_SelectTestFunction = _T("Native_SelectTestFunction");
	g_sLangTxt_Native_SelectTestFunction = _T("选择测试功能");
	g_sLangID_Native_ReportHeadSet = _T("Native_ReportHeadSet"); // 报告头设置
	g_sLangTxt_Native_ReportHeadSet = _T("报告头设置");

	g_sLangID_Native_ConnectingTester = _T("Native_ConnectingTester");
	g_sLangTxt_Native_ConnectingTester = _T("正在连接测试仪......");	
	g_sLangID_Native_TesterConnectSucc = _T("Native_TesterConnectSucc");
	g_sLangTxt_Native_TesterConnectSucc = _T("测试仪连接成功");
	g_sLangID_Native_TesterConnectfail = _T("Native_TesterConnectfail");
	g_sLangTxt_Native_TesterConnectfail = _T("连接测试仪失败，请检查网络链路是否连通，IP地址及端口配置是否正确；然后点击网络连接按钮重新连接");
	g_sLangID_Native_LCSTSendportSTGigabit = _T("Native_LCSTSendportSTGigabit");
	g_sLangTxt_Native_LCSTSendportSTGigabit = _T("当前设备共包含LC光口%ld个,ST发送口%ld个,ST接收口%ld个,千兆光口%ld个.");

	g_sLangID_Harm_Set = _T("Harm_Set");
	g_sLangTxt_Harm_Set = _T("谐波设置");
	g_sLangID_Harm_Content = _T("Harm_Content");
	g_sLangTxt_Harm_Content = _T("谐波含有率");
	g_sLangID_Harm_Enable = _T("Harm_Enable");
	g_sLangTxt_Harm_Enable = _T("使能");
	g_sLangID_Harm_UChannel = _T("Harm_UChannel");
	g_sLangTxt_Harm_UChannel = _T("电压通道");
	g_sLangID_Harm_IChannel = _T("Harm_IChannel");
	g_sLangTxt_Harm_IChannel = _T("电流通道");

	g_sLangID_Harm_UAllSelect = _T("Harm_UAllSelect");
	g_sLangTxt_Harm_UAllSelect = _T("电压全选");
	g_sLangID_Harm_IAllSelect = _T("Harm_IAllSelect");
	g_sLangTxt_Harm_IAllSelect = _T("电流全选");
	g_sLangID_Harm_UClear = _T("Harm_UClear");
	g_sLangTxt_Harm_UClear = _T("电压清空");
	g_sLangID_Harm_IClear = _T("Harm_IClear");
	g_sLangTxt_Harm_IClear = _T("电流清空");

	g_sLangID_Harm_Reset = _T("Harm_Reset");
	g_sLangTxt_Harm_Reset = _T("谐波清零");
	g_sLangID_Harm_FundFreq = _T("Harm_FundFreq");
	g_sLangTxt_Harm_FundFreq = _T("基波频率");
	g_sLangID_Harm_Times = _T("Harm_Times");
	g_sLangTxt_Harm_Times = _T("次");
	g_sLangID_Harm_InterHarm = _T("Harm_InterHarm"); // 间谐波
	g_sLangTxt_Harm_InterHarm = _T("间谐波");

	g_sLangID_Native_PhaseO = _T("Native_PhaseO");
	g_sLangTxt_Native_PhaseO = _T("0相");
	g_sLangID_Native_Relay = _T("Native_Relay");
	g_sLangTxt_Native_Relay = _T("保护");
	g_sLangID_Native_Measure = _T("Native_Measure");
	g_sLangTxt_Native_Measure = _T("测量");
	g_sLangID_Native_Current = _T("Native_Current");
	g_sLangTxt_Native_Current = _T("电流");
	g_sLangID_Native_Voltage = _T("Native_Voltage");
	g_sLangTxt_Native_Voltage = _T("电压");
	g_sLangID_Native_GndA = _T("Native_GndA");
	g_sLangTxt_Native_GndA = _T("A相接地");
	g_sLangID_Native_GndB = _T("Native_GndB");
	g_sLangTxt_Native_GndB = _T("B相接地");
	g_sLangID_Native_GndC = _T("Native_GndC");
	g_sLangTxt_Native_GndC = _T("C相接地");
	g_sLangID_Native_ShortAB = _T("Native_ShortAB");
	g_sLangTxt_Native_ShortAB = _T("AB短路");
	g_sLangID_Native_ShortBC = _T("Native_ShortBC");
	g_sLangTxt_Native_ShortBC = _T("BC短路");
	g_sLangID_Native_ShortCA = _T("Native_ShortCA");
	g_sLangTxt_Native_ShortCA = _T("CA短路");
	g_sLangID_Native_GndShortAB = _T("Native_GndShortAB");
	g_sLangTxt_Native_GndShortAB = _T("AB接地短路");
	g_sLangID_Native_GndShortBC = _T("Native_GndShortBC");
	g_sLangTxt_Native_GndShortBC = _T("BC接地短路");
	g_sLangID_Native_GndShortCA = _T("Native_GndShortCA");
	g_sLangTxt_Native_GndShortCA = _T("CA接地短路");
	g_sLangID_Native_ShortABC = _T("Native_ShortABC");
	g_sLangTxt_Native_ShortABC = _T("三相短路");
	g_sLangID_Native_SinglePhase = _T("Native_SinglePhase");
	g_sLangTxt_Native_SinglePhase = _T("单相系统");
	g_sLangID_Native_INotChange = _T("Native_INotChange");
	g_sLangTxt_Native_INotChange = _T("电流不变");
	g_sLangID_Native_UNotChange = _T("Native_UNotChange");
	g_sLangTxt_Native_UNotChange = _T("电压不变");
	g_sLangID_Native_ZNotChange = _T("Native_ZNotChange");
	g_sLangTxt_Native_ZNotChange = _T("系统阻抗不变");
	g_sLangID_Native_UZoomOut = _T("Native_UZoomOut");
	g_sLangTxt_Native_UZoomOut = _T("电压放大");
	g_sLangID_Native_UZoomIn = _T("Native_UZoomIn");
	g_sLangTxt_Native_UZoomIn = _T("电压缩小");
	g_sLangID_Native_IZoomOut = _T("Native_IZoomOut");
	g_sLangTxt_Native_IZoomOut = _T("电流放大");
	g_sLangID_Native_IZoomIn = _T("Native_IZoomIn");
	g_sLangTxt_Native_IZoomIn = _T("电流缩小");
	g_sLangID_Native_EDPhaseV = _T("Native_EDPhaseV");
	g_sLangTxt_Native_EDPhaseV = _T("额定相电压");
	g_sLangID_Native_EDCurrent = _T("Native_EDCurrent");
	g_sLangTxt_Native_EDCurrent = _T("额定电流");
	g_sLangID_Native_EqualAmp = _T("Native_EqualAmp");
	g_sLangTxt_Native_EqualAmp = _T("等幅值");
	g_sLangID_Native_EqualFreq = _T("Native_EqualFreq");
	g_sLangTxt_Native_EqualFreq = _T("等频率");
	g_sLangID_Native_PositiveSeq = _T("Native_PositiveSeq");
	g_sLangTxt_Native_PositiveSeq = _T("正序");
	g_sLangID_Native_NegativeSeq = _T("Native_NegativeSeq");
	g_sLangTxt_Native_NegativeSeq = _T("负序");
	g_sLangID_Native_ZeroSeq = _T("Native_ZeroSeq");
	g_sLangTxt_Native_ZeroSeq = _T("零序");
	g_sLangID_Native_Zero = _T("Native_Zero");
	g_sLangTxt_Native_Zero = _T("零");
	g_sLangID_Native_AllGroup = _T("Native_AllGroup");
	g_sLangTxt_Native_AllGroup = _T("总组数:");
	g_sLangID_Native_CurGroup = _T("Native_CurGroup");
	g_sLangTxt_Native_CurGroup = _T("当前组:");
	g_sLangID_Native_LastGroup = _T("Native_LastGroup");
	g_sLangTxt_Natve_LastGroup = _T("上一组");
	g_sLangID_Native_NextGroup = _T("Native_NextGroup");
	g_sLangTxt_Natve_NextGroup = _T("下一组");
	g_sLangID_Native_ExBinSet = _T("Native_ExBinSet");
	g_sLangTxt_Native_ExBinSet = _T("扩展开入设置");
	g_sLangID_Native_ExBoutSet = _T("Native_ExBoutSet");
	g_sLangTxt_Native_ExBoutSet = _T("扩展开出设置");
	g_sLangID_Native_GooseDataSet = _T("Native_GooseDataSet");
	g_sLangTxt_Native_GooseDataSet = _T("Goose数据发送");
	g_sLangID_Native_GooseOutSet	= _T("Native_GooseOutSet");
	g_sLangTxt_Native_GooseOutSet	= _T("GOOSE OUT-->开入");
	g_sLangID_Native_GooseInSet	= _T("Native_GooseInSet");
	g_sLangTxt_Native_GooseInSet = _T("开出-->GOOSE IN");
	g_sLangID_Native_Bin = _T("Native_Bin");
	g_sLangTxt_Native_Bin = _T("开入量");
	g_sLangID_Native_Bout = _T("Native_Bout");
	g_sLangTxt_Native_Bout = _T("开出量");

	g_sLangID_Native_BinX = _T("Native_BinX");
	g_sLangTxt_Native_BinX = _T("开入");
	g_sLangID_Native_BoutX = _T("Native_BoutX");
	g_sLangTxt_Native_BoutX = _T("开出");
	g_sLangID_Native_BinEx = _T("Native_BinEx");
	g_sLangTxt_Native_BinEx = _T("扩展开入");
	g_sLangID_Native_BoutEx = _T("Native_BoutEx");
	g_sLangTxt_Native_BoutEx = _T("扩展开出");
	g_sLangID_Native_ActType = _T("Native_ActType");
	g_sLangTxt_Native_ActType = _T("动作类型");
	g_sLangID_Native_ActionTime = _T("Native_ActionTime");
	g_sLangTxt_Native_ActionTime = _T("动作时间(s)");
	g_sLangID_Native_CurTypeIdx = _T("Native_CurTypeIdx");
	g_sLangTxt_Native_CurTypeIdx = _T("当前状态号");
	g_sLangID_Native_Group = _T("Native_Group");
	g_sLangTxt_Native_Group = _T("组");
	g_sLangID_Native_Reverse = _T("Native_Reverse");
	g_sLangTxt_Native_Reverse = _T("取反");
	g_sLangID_Native_Repair = _T("Native_Repair");
	g_sLangTxt_Native_Repair = _T("置检修");
	g_sLangID_Native_Revert = _T("Native_Revert");
	g_sLangTxt_Native_Revert = _T("复归");
	g_sLangID_Native_IEDName = _T("Native_IEDName");
	g_sLangTxt_Native_IEDName = _T("IED名称");
	g_sLangID_Native_APPID = _T("Native_APPID");
	g_sLangTxt_Native_APPID = _T("应用标识(APPID)    0x");
	g_sLangID_Native_Type = _T("Native_Type");
	g_sLangTxt_Native_Type = _T("类型:");
	g_sLangID_Native_Action = _T("Native_Action");
	g_sLangTxt_Native_Action = _T("动作值(V):");
	g_sLangID_Native_ReturnVal = _T("Native_ReturnVal");
	g_sLangTxt_Native_ReturnVal = _T("返回值(V):");
	g_sLangID_Native_ReturnCoeff = _T("Native_ReturnCoeff");
	g_sLangTxt_Native_ReturnCoeff = _T("返回系数");
	g_sLangID_Native_LogicOr = _T("Native_LogicOr");
	g_sLangTxt_Native_LogicOr = _T("逻辑或");
	g_sLangID_Native_LogicAnd = _T("Native_LogicAnd");
	g_sLangTxt_Native_LogicAnd = _T("逻辑与");
	g_sLangID_Native_Enter = _T("Native_Enter");
	g_sLangTxt_Native_Enter = _T("完成");
	g_sLangID_Native_Caps = _T("Native_Caps");
	g_sLangTxt_Native_Caps = _T("大小写");
	g_sLangID_Native_Space = _T("Native_Space");
	g_sLangTxt_Native_Space = _T("空格");
	g_sLangID_Native_Maps = _T("Native_Maps");
	g_sLangTxt_Native_Maps = _T("映射");
	g_sLangID_Native_Chs = _T("Native_Chs");
	g_sLangTxt_Native_Chs = _T("中/英");
	g_sLangID_Native_Eng = _T("Native_Eng");
	g_sLangTxt_Native_Eng = _T("英/中");
	g_sLangID_Native_FileFolder = _T("Native_FileFolder");
	g_sLangTxt_Native_FileFolder = _T("文件目录");
	g_sLangID_Native_NoTimeSync = _T("Native_NoTimeSync");
	g_sLangTxt_Native_NoTimeSync = _T("未对时");
	g_sLangID_Native_AllFreq = _T("Native_AllFreq");
	g_sLangTxt_Native_AllFreq = _T("全部频率(前两组)");
	g_sLangID_Native_FileType = _T("Native_FileType");
	g_sLangTxt_Native_FileType = _T("文件类型");
	g_sLangID_Native_SCLPath = _T("Native_SCLPath");
	g_sLangTxt_Native_SCLPath = _T("选择SCL文件");
	g_sLangID_Native_SCLFilter = _T("Native_SCLFilter");
	g_sLangTxt_Native_SCLFilter = _T("SCL文件(*.scd *.icd *.cid *.ccd)");
	g_sLangID_Native_ResultJudge = _T("Native_ResultJudge");
	g_sLangTxt_Native_ResultJudge = _T("结果判断");
	g_sLangID_Native_ResultDescript = _T("Native_ResultDescript");
	g_sLangTxt_Native_ResultDescript = _T("结果描述");
	g_sLangID_Native_ResultTime = _T("Native_ResultTime");
	g_sLangTxt_Native_ResultTime = _T("结果时间");
	g_sLangID_Native_ResultAbsRsltCal1 = _T("Native_ResultAbsRsltCal1");
	g_sLangTxt_Native_ResultAbsRsltCal1 = _T("绝对误差计算值1");
	g_sLangID_Native_ResultAbsRsltCal2 = _T("Native_ResultAbsRsltCal2");
	g_sLangTxt_Native_ResultAbsRsltCal2 = _T("绝对误差计算值2");
	g_sLangID_Native_ResultRelRsltCal1 = _T("Native_ResultRelRsltCal1");
	g_sLangTxt_Native_ResultRelRsltCal1 = _T("相对误差计算值1");
	g_sLangID_Native_ResultRelRsltCal2 = _T("Native_ResultRelRsltCal2");
	g_sLangTxt_Native_ResultRelRsltCal2 = _T("相对误差计算值2");
	g_sLangID_Native_TimeSettingCoef = _T("Native_TimeSettingCoef");
	g_sLangTxt_Native_TimeSettingCoef = _T("时间定值比例系数");
	g_sLangID_Manual_FirGroup = _T("Manual_FirGroup");
	g_sLangTxt_Manual_FirGroup = _T("第1组");

	g_sLangID_Manual_IV = _T("Manual_IV");
	g_sLangTxt_Manual_IV = _T("电压电流");
	g_sLangID_Manual_OtherParam = _T("Manual_OtherParam");
	g_sLangTxt_Manual_OtherParam = _T("其它参数设置");
	g_sLangID_Manual_GlobalParam = _T("Manual_GlobalParam");
	g_sLangTxt_Manual_GlobalParam = _T("全局参数设置");
	g_sLangID_Manual_Oscillogram = _T("Manual_Oscillogram");
	g_sLangTxt_Manual_Oscillogram = _T("波形图");
	g_sLangID_Manual_Changing = _T("Manual_Changing");
	g_sLangTxt_Manual_Changing = _T("递变");
	g_sLangID_Manual_InitVal = _T("Manual_InitVal");
	g_sLangTxt_Manual_InitVal = _T("始值(V):");
	g_sLangID_Manual_ChangeType = _T("Manual_ChangeType");
	g_sLangTxt_Manual_ChangeType = _T("变化方式:");
	g_sLangID_Manual_Channel = _T("Manual_Channel");
	g_sLangTxt_Manual_Channel = _T("通道选择:");
	g_sLangID_Manual_FinishVal = _T("Manual_FinishVal");
	g_sLangTxt_Manual_FinishVal = _T("终值(V):");
	g_sLangID_Manual_Step = _T("Manual_Step");
	g_sLangTxt_Manual_Step = _T("步长(V):");
	g_sLangID_Manual_Timer = _T("Manual_Timer");
	g_sLangTxt_Manual_Timer = _T("时间(s):");
	g_sLangID_Manual_Old = _T("Manual_Old");
	g_sLangTxt_Manual_Old = _T("老化");
	g_sLangID_Manual_Auto = _T("Manual_Auto");
	g_sLangTxt_Manual_Auto = _T("自动");
	g_sLangID_Manual_Delayed = _T("Manual_Delayed");
	g_sLangTxt_Manual_Delayed = _T("触发后延时(s):");
	g_sLangID_Manual_OutSetting = _T("Manual_OutSetting");
	g_sLangTxt_Manual_OutSetting = _T("开出设置");
	g_sLangID_Manual_Out1 = _T("Manual_Out1");
	g_sLangTxt_Manual_Out1 = _T("开出1");
	g_sLangID_Manual_Out2 = _T("Manual_Out2");
	g_sLangTxt_Manual_Out2 = _T("开出2");
	g_sLangID_Manual_Out3 = _T("Manual_Out3");
	g_sLangTxt_Manual_Out3 = _T("开出3");
	g_sLangID_Manual_Out4 = _T("Manual_Out4");
	g_sLangTxt_Manual_Out4 = _T("开出4");
	g_sLangID_Manual_Out5 = _T("Manual_Out5");
	g_sLangTxt_Manual_Out5 = _T("开出5");
	g_sLangID_Manual_Out6 = _T("Manual_Out6");
	g_sLangTxt_Manual_Out6 = _T("开出6");
	g_sLangID_Manual_Out7 = _T("Manual_Out7");
	g_sLangTxt_Manual_Out7 = _T("开出7");
	g_sLangID_Manual_Out8 = _T("Manual_Out8");
	g_sLangTxt_Manual_Out8 = _T("开出8");
	g_sLangID_Manual_InSetting = _T("Manual_InSetting");
	g_sLangTxt_Manual_InSetting = _T("开入设置");
	g_sLangID_Manual_InA = _T("Manual_InA");
	g_sLangTxt_Manual_InA = _T("开入A");
	g_sLangID_Manual_InB = _T("Manual_InB");
	g_sLangTxt_Manual_InB = _T("开入B");
	g_sLangID_Manual_InC = _T("Manual_InC");
	g_sLangTxt_Manual_InC = _T("开入C");
	g_sLangID_Manual_InD = _T("Manual_InD");
	g_sLangTxt_Manual_InD = _T("开入D");
	g_sLangID_Manual_InE = _T("Manual_InE");
	g_sLangTxt_Manual_InE = _T("开入E");
	g_sLangID_Manual_InF = _T("Manual_InF");
	g_sLangTxt_Manual_InF = _T("开入F");
	g_sLangID_Manual_InG = _T("Manual_InG");
	g_sLangTxt_Manual_InG = _T("开入G");
	g_sLangID_Manual_InH = _T("Manual_InH");
	g_sLangTxt_Manual_InH = _T("开入H");
	g_sLangID_Manual_Lock = _T("Manual_Lock");
	g_sLangTxt_Manual_Lock = _T("锁");
	g_sLangID_Manual_UnLock = _T("Manual_UnLock");
	g_sLangTxt_Manual_UnLock = _T("解锁");
	g_sLangID_Manual_ActionTime = _T("Manual_ActionTime");
	g_sLangTxt_Manual_ActionTime = _T("动作时间(s):");
	g_sLangID_Manual_ReturnTime = _T("Manual_ReturnTime");
	g_sLangTxt_Manual_ReturnTime = _T("返回时间(s):");
	g_sLangID_Manual_S_E = _T("Manual_S_E");
	g_sLangTxt_Manual_S_E = _T("始-终");
	g_sLangID_Manual_S_E_S = _T("Manual_S_E_S");
	g_sLangTxt_Manual_S_E_S = _T("始-终-始");

	g_sLangID_Manual_Harm = _T("Manual_Harm");
	g_sLangTxt_Manual_Harm = _T("叠加谐波");
	g_sLangID_Manual_TestMethod = _T("Manual_TestMethod");
	g_sLangTxt_Manual_TestMethod = _T("测试方法");
	g_sLangID_Manual_MeasType = _T("Manual_MeasType");
	g_sLangTxt_Manual_MeasType = _T("接收报文类型");
	g_sLangID_Manual_BCode = _T("Manual_BCode");
	g_sLangTxt_Manual_BCode = _T("B码输出逻辑");
	g_sLangID_Manual_TestReport = _T("Manual_TestReport");
	g_sLangTxt_Manual_TestReport = _T("测试报告");
	g_sLangID_Manual_TestTime = _T("Manual_TestTime");
	g_sLangTxt_Manual_TestTime = _T("秒/次");
	g_sLangID_Manual_PositiveLogic = _T("Manual_PositiveLogic");
	g_sLangTxt_Manual_PositiveLogic = _T("正逻辑");
	g_sLangID_Manual_NegativeLogic = _T("Manual_NegativeLogic");
	g_sLangTxt_Manual_NegativeLogic = _T("负逻辑");

	g_sLangID_Manual_SyncSet = _T("Manual_SyncSet");
	g_sLangTxt_Manual_SyncSet = _T("同步设置");
	g_sLangID_Manual_SecSyncStatus = _T("Manual_SecSyncStatus");
	g_sLangTxt_Manual_SecSyncStatus = _T("秒同步状态");
	g_sLangID_Manual_OpenSecSync = _T("Manual_OpenSecSync");
	g_sLangTxt_Manual_OpenSecSync = _T("开启秒同步");
	g_sLangID_Manual_CloseSecSync = _T("Manual_CloseSecSync");
	g_sLangTxt_Manual_CloseSecSync = _T("关闭秒同步");
	g_sLangID_Manual_IEC1588Sync = _T("Manual_IEC1588Sync");
	g_sLangTxt_Manual_IEC1588Sync = _T("IEC1588同步机制:");
	g_sLangID_Manual_PeerDelay = _T("Manual_PeerDelay");
	g_sLangTxt_Manual_PeerDelay = _T("对等延时");
	g_sLangID_Manual_DelayRequestReply = _T("Manual_DelayRequestReply");
	g_sLangTxt_Manual_DelayRequestReply = _T("延时请求-响应");

	g_sLangID_Manual_Refresh = _T("Manual_Refresh");
	g_sLangTxt_Manual_Refresh = _T("刷新");

	g_sLangID_IEC_WeakSet = _T("IEC_WeakSet");
	g_sLangTxt_IEC_WeakSet = _T("弱信号设置");
	g_sLangID_ErrorSet = _T("sErrorSet");
	g_sLangTxt_ErrorSet = _T("误差值设置");
	g_sLangID_CurAbsError = _T("sCurAbsError");
	g_sLangTxt_CurAbsError = _T("电流动作值绝对误差(A):");
	g_sLangID_CurRelError = _T("sCurRelError");
	g_sLangTxt_CurRelError = _T("电流动作值相对误差(%):");
	g_sLangID_VolAbsError = _T("sVolAbsError");
	g_sLangTxt_VolAbsError = _T("电压动作值绝对误差(V):");
	g_sLangID_VolRelError = _T("sVolRelError");
	g_sLangTxt_VolRelError = _T("电压动作值相对误差(%):");
	g_sLangID_ImpAbsError = _T("sImpAbsError");
	g_sLangTxt_ImpAbsError = _T("阻抗动作值绝对误差(Ω):");
	g_sLangID_ImpRelError = _T("sImpRelError");
	g_sLangTxt_ImpRelError = _T("阻抗动作值相对误差(%):");
	g_sLangID_TimeAbsError = _T("sTimeAbsError");
	g_sLangTxt_TimeAbsError = _T("动作时间绝对误差(s):");
	g_sLangID_TimeRelError = _T("sTimeRelError");
	g_sLangTxt_TimeRelError = _T("动作时间相对误差(%):");
	g_sLangID_AngError = _T("sAngError");
	g_sLangTxt_AngError = _T("相位误差值(°):");
	g_sLangID_FreqError = _T("sFreqError");
	g_sLangTxt_FreqError = _T("频率误差值(Hz):");
	g_sLangID_DvDtError = _T("sDvDtError");
	g_sLangTxt_DvDtError = _T("电压滑差误差值(V/s):");
	g_sLangID_DfDtError = _T("sDfDtError");
	g_sLangTxt_DfDtError = _T("频率滑差误差值(Hz/s):");
	g_sLangID_DiffRateCoefAbsError = _T("sDiffRateCoefAbsError");
	g_sLangTxt_DiffRateCoefAbsError = _T("差动比率制动系数绝对误差:");
	g_sLangID_DiffRateCoefRelError = _T("sDiffRateCoefRelError");
	g_sLangTxt_DiffRateCoefRelError = _T("差动比率制动系数相对误差:");
	g_sLangID_DiffHarmCoefAbsError = _T("sDiffHarmCoefAbsError");
	g_sLangTxt_DiffHarmCoefAbsError = _T("差动谐波制动系数绝对误差:");
	g_sLangID_DiffHarmCoefRelError = _T("sDiffHarmCoefRelError");
	g_sLangTxt_DiffHarmCoefRelError = _T("差动谐波制动系数相对误差:");

	g_sLangID_State_TrigerSetup = _T("State_TrigerSetup");
	g_sLangTxt_State_TrigerSetup = _T("触发设置");
	g_sLangID_State_TrigerCondition = _T("State_TrigerCondition");
	g_sLangTxt_State_TrigerCondition = _T("触发条件");
	g_sLangID_State_OutTime = _T("State_OutTime");
	g_sLangTxt_State_OutTime = _T("输出时间(s)");
	g_sLangID_State_TrigerTime = _T("State_TrigerTime");
	g_sLangTxt_State_TrigerTime = _T("触发时刻");
	g_sLangID_State_Hour = _T("State_Hour");
	g_sLangTxt_State_Hour = _T("时");
	g_sLangID_State_Minute = _T("State_Minute");
	g_sLangTxt_State_Minute = _T("分");
	g_sLangID_State_Second = _T("State_Second");
	g_sLangTxt_State_Second = _T("秒");
	g_sLangID_State_TrigerHoldTime = _T("State_TrigerHoldTime");
	g_sLangTxt_State_TrigerHoldTime = _T("触发后保持时间(s)");
	g_sLangID_State_HoldTime = _T("State_HoldTime");
	g_sLangTxt_State_HoldTime = _T("保持时间(s):");
	g_sLangID_State_ShortCalc = _T("State_ShortCalc");
	g_sLangTxt_State_ShortCalc = _T("短路计算");
	g_sLangID_State_GradientSet = _T("State_GradientSet");
	g_sLangTxt_State_GradientSet = _T("递变设置");
	g_sLangID_State_PasteStateBf = _T("State_PasteStateBf");
	g_sLangTxt_State_PasteStateBf = _T("粘贴状态—前");
	g_sLangID_State_InsertStateBf = _T("State_InsertStateBf");
	g_sLangTxt_State_InsertStateBf = _T("插入状态—前");
	g_sLangID_State_InsertStateAf = _T("State_InsertStateAf");
	g_sLangTxt_State_InsertStateAf = _T("插入状态—后");
	g_sLangID_State_PasteStateAf = _T("State_PasteStateAf");
	g_sLangTxt_State_PasteStateAf = _T("粘贴状态—后");
	g_sLangID_State_CopyCurState = _T("State_CopyCurState");
	g_sLangTxt_State_CopyCurState = _T("拷贝当前状态");
	g_sLangID_State_DeleteCurState = _T("State_DeleteCurState");
	g_sLangTxt_State_DeleteCurState = _T("删除当前状态");
	g_sLangID_State_UISet = _T("State_UISet");
	g_sLangTxt_State_UISet = _T("电压电流设置");
	g_sLangID_State_SecHVoltageSide = _T("State_SecHVoltageSide"); // LCQ
	g_sLangTxt_State_SecHVoltageSide = _T("低压侧应用于(I2)");
	g_sLangID_State_StateParaSet = _T("State_StateParaSet");
	g_sLangTxt_State_StateParaSet = _T("状态参数设置");
	g_sLangID_State_JudgeCondition = _T("State_JudgeCondition");
	g_sLangTxt_State_JudgeCondition = _T("开入翻转参考状态");
	g_sLangID_State_DCOffSet = _T("State_DCOffSet");
	g_sLangTxt_State_DCOffSet = _T("叠加衰减直流分量");
	g_sLangID_State_Tou = _T("State_Tou");
	g_sLangTxt_State_Tou = _T("衰减时间常数");
	g_sLangID_State_StackByState = _T("State_StackByState");
	g_sLangTxt_State_StackByState = _T("按状态叠加");
	g_sLangID_State_RepeatTimes = _T("State_RepeatTimes");
	g_sLangTxt_State_RepeatTimes = _T("循环次数");
	g_sLangID_State_Oclock = _T("State_Oclock");
	g_sLangTxt_State_Oclock = _T("点");
	g_sLangID_State_Testphase = _T("State_Testphase");
	g_sLangTxt_State_Testphase = _T("测试相");
	g_sLangID_State_BFtransformer = _T("State_BFtransformer");
	g_sLangTxt_State_BFtransformer = _T("两侧指压变压器");
	g_sLangID_State_NotconWindconnection = _T("State_NotconWindconnection");
	g_sLangTxt_State_NotconWindconnection = _T("不考虑绕组接线型式");
	g_sLangID_State_Triangulationcorrection = _T("State_Triangulationcorrection");
	g_sLangTxt_State_Triangulationcorrection = _T("△侧校正");
	g_sLangID_State_Bfactorcalculation = _T("State_Bfactorcalculation");
	g_sLangTxt_State_Bfactorcalculation = _T("平衡系数计算");
	g_sLangID_State_ChGroup = _T("State_ChGroup");
	g_sLangTxt_State_ChGroup = _T("组号:");
	g_sLangID_Abnormal_APPID = _T("Abnormal_APPID");
	g_sLangTxt_Abnormal_APPID = _T("异常报文选择APPID:");
	g_sLangID_State_FaultType = _T("State_FaultType");
	g_sLangTxt_State_FaultType = _T("故障类型:");
	g_sLangID_State_CalcMode = _T("State_CalcMode");
	g_sLangTxt_State_CalcMode = _T("计算模型:");
	g_sLangID_State_ShortI = _T("State_ShortI");
	g_sLangTxt_State_ShortI = _T("短路电流(A):");
	g_sLangID_State_ShortU = _T("State_ShortU");
	g_sLangTxt_State_ShortU = _T("短路电压(V):");
	g_sLangID_State_Hswindwirtype = _T("State_Hswindwirtype"); // LCQ
	g_sLangTxt_State_Hswindwirtype = _T("高压侧绕组接线型式");
	g_sLangID_State_Lswindwirtype = _T("State_Lswindwirtype"); // LCQ
	g_sLangTxt_State_Lswindwirtype = _T("低压侧绕组接线型式");
	g_sLangID_State_HbdiffAngularwind = _T("State_HbdiffAngularwind"); // LCQ
	g_sLangTxt_State_HbdiffAngularwind = _T("绕组间角差(钟点数)");
	g_sLangID_State_ZeroCoeff = _T("State_ZeroCoeff");
	g_sLangTxt_State_ZeroCoeff = _T("零序补偿系数");
	g_sLangID_State_CalcType = _T("State_CalcType");
	g_sLangTxt_State_CalcType = _T("计算方式:");
	g_sLangID_State_Amp = _T("State_Amp");
	g_sLangTxt_State_Amp = _T("幅值:");
	g_sLangID_State_DiffCurrentA = _T("State_DiffCurrentA"); // LCQ
	g_sLangTxt_State_DiffCurrentA = _T("差动电流(A)");
	g_sLangID_State_BrakCurrentA = _T("State_BrakCurrentA"); // LCQ
	g_sLangTxt_State_BrakCurrentA = _T("制动电流(A)");
	g_sLangID_State_Bequation = _T("State_Bequation"); // LCQ
	g_sLangTxt_State_Bequation = _T("制动方程");
	g_sLangID_State_Hsbalancefactor = _T("State_Hsbalancefactor"); // LCQ
	g_sLangTxt_State_Hsbalancefactor = _T("高压侧平衡系数");
	g_sLangID_State_Angle = _T("State_Angle");
	g_sLangTxt_State_Angle = _T("相角:");
	g_sLangID_LoadI = _T("State_LoadI");
	g_sLangTxt_LoadI = _T("负荷电流(A):");
	g_sLangID_State_LoadAngle = _T("State_LoadAngle");
	g_sLangTxt_State_LoadAngle = _T("负荷功角(°):");
	g_sLangID_State_Trigger_Time = _T("State_Trigger_Time");
	g_sLangTxt_State_Trigger_Time = _T("时间触发");
	g_sLangID_State_Trigger_TimeAndBin = _T("State_Trigger_TimeAndBin");
	g_sLangTxt_State_Trigger_TimeAndBin = _T("时间或开入量翻转");
	g_sLangID_State_Trigger_Bin = _T("State_Trigger_Bin");
	g_sLangTxt_State_Trigger_Bin = _T("开入量触发");
	g_sLangID_State_Trigger_Manu = _T("State_Trigger_Manu");
	g_sLangTxt_State_Trigger_Manu = _T("手动触发");
	g_sLangID_State_Trigger_GPSB = _T("State_Trigger_GPSB");
	g_sLangTxt_State_Trigger_GPSB = _T("GPS/B码触发");
	g_sLangID_State_LinearChange = _T("State_LinearChange");
	g_sLangTxt_State_LinearChange = _T("线性变化");
	g_sLangID_State_StepChange = _T("State_StepChange");
	g_sLangTxt_State_StepChange = _T("阶梯变化");
	g_sLangID_State_StepTime = _T("State_StepTime");
	g_sLangTxt_State_StepTime = _T("步长时间(s)");
	g_sLangID_State_BeginVal = _T("State_BeginVal");
	g_sLangTxt_State_BeginVal = _T("始值");
	g_sLangID_State_EndVal = _T("State_EndVal");
	g_sLangTxt_State_EndVal = _T("终值");
	g_sLangID_State_AmpGradient = _T("State_AmpGradient");
	g_sLangTxt_State_AmpGradient = _T("幅值递变");
	g_sLangID_State_FreqGradient = _T("State_FreqGradient");
	g_sLangTxt_State_FreqGradient = _T("频率递变");
	g_sLangID_State_LastState = _T("State_LastState");
	g_sLangTxt_State_LastState = _T("上一个状态");
	g_sLangID_State_FirstState = _T("State_FirstState");
	g_sLangTxt_State_FirstState = _T("第一个状态");
 	g_sLangID_State_No = _T("State_No");   //sun 
 	g_sLangTxt_State_No = _T("否");        //sun
 	g_sLangID_State_Yes = _T("State_Yes"); //sun
 	g_sLangTxt_State_Yes = _T("是");       //sun
	g_sLangID_State_Difflowcalculation = _T("State_Difflowcalculation");
	g_sLangTxt_State_Difflowcalculation = _T("差流计算");
	g_sLangID_State_HarmCount = _T("State_HarmCount");
	g_sLangTxt_State_HarmCount = _T("次谐波");
	g_sLangID_State_NoActioned = _T("State_NoActioned");
	g_sLangTxt_State_NoActioned = _T("未动作");
	g_sLangID_State_ActionValue = _T("State_ActionValue");
	g_sLangTxt_State_ActionValue = _T("动作值");
	g_sLangID_State_Error = _T("State_Error");
	g_sLangTxt_State_Error = _T("误差");
	g_sLangID_State_CurlfailedItems = _T("State_CurlfailedItems");
	g_sLangTxt_State_CurlfailedItems = _T("特性曲线查找失败(strCharaID=%s;strIndex=%s),无法更新项目列表.");
	g_sLangID_State_Sysgenerated = _T("State_Sysgenerated");
	g_sLangTxt_State_Sysgenerated = _T("系统生成");

	g_sLangID_State_StatusEdition = _T("State_StatusEdition");
	g_sLangTxt_State_StatusEdition = _T("状态编辑");
	g_sLangID_State_HarmonicAmpInc = _T("State_HarmonicAmpInc");
	g_sLangTxt_State_HarmonicAmpInc = _T("谐波按幅值递变");
	g_sLangID_State_HarmonicAmpPer = _T("State_HarmonicAmpPer");
	g_sLangTxt_State_HarmonicAmpPer = _T("谐波按百分比递变");
	g_sLangID_State_PreviosState = _T("State_PreviosState");
	g_sLangTxt_State_PreviosState = _T("上一状态");
	g_sLangID_State_NextState = _T("State_NextState");
	g_sLangTxt_State_NextState = _T("下一状态");

	g_sLangID_Gradient_Npchannelgroupset = _T("Gradient_Npchannelgroupset");
	g_sLangTxt_Gradient_Npchannelgroupset = _T("非递变通道分组设置");
	g_sLangID_Gradient_Groupset = _T("Gradient_Groupset");
	g_sLangTxt_Gradient_Groupset = _T("分组设置");

	g_sLangID_State_CTpolarity = _T("State_CTpolarity");
	g_sLangTxt_State_CTpolarity = _T("CT极性");
	g_sLangID_State_Lsbalancefactor = _T("State_Lsbalancefactor");
	g_sLangTxt_State_Lsbalancefactor = _T("低压侧平衡系数");

	g_sLangID_State_Correctionselection = _T("State_Correctionselection"); // LCQ
	g_sLangTxt_State_Correctionselection = _T("校正选择");
	g_sLangID_State_OFtransformer = _T("State_OFtransformer"); // LCQ
	g_sLangTxt_State_OFtransformer = _T("一侧指压变压器");
	g_sLangID_State_HarContent = _T("State_HarContent"); // LCQ
	g_sLangTxt_State_HarContent = _T("谐波含量");
	g_sLangID_State_DifferentCur = _T("State_DifferentCur"); // LCQ
	g_sLangTxt_State_DifferentCur = _T("差动电流");
	g_sLangID_State_BrakingCur = _T("State_BrakingCur"); // LCQ
	g_sLangTxt_State_BrakingCur = _T("制动电流");
	g_sLangID_State_VoltageRat = _T("State_VoltageRat"); // LCQ
	g_sLangTxt_State_VoltageRat = _T("电压比值");

	g_sLangID_State_ZImpValue = _T("State_ZImpValue"); // LCQ
	g_sLangTxt_State_ZImpValue = _T("阻抗值(Z)");
	g_sLangID_State_DAngle = _T("State_DAngle"); // LCQ
	g_sLangTxt_State_DAngle = _T("角度(°)");
	g_sLangID_State_CurrentRat = _T("State_CurrentRat"); // LCQ
	g_sLangTxt_State_CurrentRat = _T("电流比值");
	g_sLangID_State_FirHVoltageSide = _T("State_FirHVoltageSide"); // LCQ
	g_sLangTxt_State_FirHVoltageSide = _T("高压侧应用于(I1)");
	g_sLangID_State_ConWindconnection = _T("State_ConWindconnection"); // LCQ
	g_sLangTxt_State_ConWindconnection = _T("虑绕组接线型式");

	g_sLangID_State_Trans1 = _T("State_Trans1");
	g_sLangTxt_State_Trans1 = _T("一侧指向变压器");
	g_sLangID_State_Trans2 = _T("State_Trans2");
	g_sLangTxt_State_Trans2 = _T("两侧指向变压器");
	g_sLangID_State_Winding = _T("State_Winding");
	g_sLangTxt_State_Winding = _T("考虑绕组接线型式");

	g_sLangID_State_NoAdjust = _T("State_NoAdjust");
	g_sLangTxt_State_NoAdjust = _T("无校正");

	g_sLangID_State_YAdjust = _T("State_YAdjust");
	g_sLangTxt_State_YAdjust = _T("Y侧校正");

	g_sLangID_State_SettingValue = _T("State_SettingValue");
	g_sLangTxt_State_SettingValue = _T("整定值");
	g_sLangID_State_Estimate = _T("State_Estimate");
	g_sLangTxt_State_Estimate = _T("整定及结果评估");
	g_sLangID_State_InState = _T("State_InState");
	g_sLangTxt_State_InState = _T("进入状态");
	g_sLangID_StateEstimate_Start = _T("StateEstimate_Start");
	; // 计时起点
	g_sLangTxt_StateEstimate_State = _T("计时起点");
	g_sLangID_StateEstimate_End = _T("StateEstimate_End ");
	; // 计时终点
	g_sLangTxt_StateEstimate_End = _T("计时终点");
	g_sLangID_StateEstimate_ErrorType = _T("StateEstimate_ErrorType");
	; // 误差类型
	g_sLangTxt_StateEstimate_ErrorType = _T("误差类型");
	g_sLangID_StateEstimate_RelError = _T("StateEstimate_RelError");
	; // 相对误差
	g_sLangTxt_StateEstimate_RelError = _T("相对误差");
	g_sLangID_StateEstimate_AbsError = _T("StateEstimate_AbsError");
	; // 绝对误差
	g_sLangTxt_StateEstimate_AbsError = _T("绝对误差");
	g_sLangID_StateEstimate_SettingValue = _T("StateEstimate_SettingValue");
	; // 整定值(s)
	g_sLangTxt_StateEstimate_SettingValue = _T("整定值(s)");
	g_sLangID_StateEstimate_BinTrigger = _T("StateEstimate_BinTrigger");
	; // 开入触发
	g_sLangTxt_StateEstimate_BinTrigger = _T("开入触发");
	g_sLangID_StateEstimate_CombinationError = _T("CombinationError");
	; // 组合误差
	g_sLangTxt_StateEstimate_CombinationError = _T("组合误差");
	g_sLangID_StateEstimate_ResultEstimate = _T("ResultEstimate ");
	; // 结果评估
	g_sLangTxt_StateEstimate_ResultEstimate = _T("结果评估");
	g_sLangID_State_12Oclock = _T("State_12Oclock"); // LCQ
	g_sLangTxt_State_12Oclock = _T("12点");

	g_sLangID_State_Test = _T("State_Test"); // LCQ
	g_sLangTxt_State_Test = _T("测试");
	g_sLangID_State_Description = _T("State_Description"); // LCQ
	g_sLangTxt_State_Description = _T("描述");
	g_sLangID_State_Statusname = _T("State_Statusname"); // LCQ
	g_sLangTxt_State_Statusname = _T("状态名");
	g_sLangID_State_FGBlueNetworkcar = _T("State_FGBlueNetworkcar"); // LCQ
	g_sLangTxt_State_FGBlueNetworkcar = _T("4G、蓝牙、网卡使能");
	g_sLangID_State_Bluetooth = _T("State_Bluetooth"); // LCQ
	g_sLangTxt_State_Bluetooth = _T("蓝牙");
	g_sLangID_State_Wirelesscard = _T("State_Wirelesscard"); // LCQ
	g_sLangTxt_State_Wirelesscard = _T("无线网卡");
	g_sLangID_State_NativeNetworkcard = _T("State_NativeNetworkcard"); // LCQ
	g_sLangTxt_State_NativeNetworkcard = _T("本机网卡");
 	g_sLangID_State_MinScreenBright = _T("State_MinScreenBright"); // Dingxy
 	g_sLangTxt_State_MinScreenBright = _T("屏幕亮度(1-5)");
	g_sLangID_State_NoteFivemeansBrightest = _T("State_NoteFivemeansBrightest"); // Dingxy
	g_sLangTxt_State_NoteFivemeansBrightest = _T("(备注:5代表最亮)");
	g_sLangID_State_MinBacklighttime = _T("State_MinBacklighttime"); // LCQ
	g_sLangTxt_State_MinBacklighttime = _T("背光时间(分钟)");
	g_sLangID_State_NoteZeromeansAlwayson = _T("State_NoteZeromeansAlwayson"); // LCQ
	g_sLangTxt_State_NoteZeromeansAlwayson = _T("(备注:0代表常亮)");
	g_sLangID_State_FanMode = _T("State_FanMode");
	g_sLangTxt_State_FanMode = _T("机器散热风扇模式");
	g_sLangID_State_Normal  = _T("State_Normal");
	g_sLangTxt_State_Normal  = _T("正常");
	g_sLangID_State_Mute  = _T("State_Mute");
	g_sLangTxt_State_Mute  = _T("静音");
	g_sLangID_State_Timezonesetting = _T("State_Timezonesetting"); // LCQ
	g_sLangTxt_State_Timezonesetting = _T("时区设置");
	g_sLangID_State_Othersettings = _T("State_Othersettings"); // LCQ
	g_sLangTxt_State_Othersettings = _T("其它设置");
	g_sLangID_State_Datavalue = _T("State_Datavalue"); // LCQ
	g_sLangTxt_State_Datavalue = _T("数据值");
	g_sLangID_State_AuxiliaryDCSettings = _T("State_AuxiliaryDCSettings"); // LCQ
	g_sLangTxt_State_AuxiliaryDCSettings = _T("辅助直流设置");
	g_sLangID_State_Others = _T("State_Others"); // LCQ
	g_sLangTxt_State_Others = _T("其它");
	g_sLangID_State_Voltagevalue = _T("State_Voltagevalue"); // LCQ
	g_sLangTxt_State_Voltagevalue = _T("电压值(V):");
	g_sLangID_Gradient_Pleaselaterithasstarted = _T("Gradient_Pleaselaterithasstarted"); // LCQ
	g_sLangTxt_Gradient_Pleaselaterithasstarted = _T("请稍侯,已开始");
	g_sLangID_State_Scanlinesegments = _T("State_Scanlinesegments"); // LCQ
	g_sLangTxt_State_Scanlinesegments = _T("扫描线段");
	g_sLangID_State_Testpoints = _T("State_Testpoints"); // LCQ
	g_sLangTxt_State_Testpoints = _T("测试点");
	g_sLangID_State_Iecurrent = _T("State_Iecurrent"); // LCQ
	g_sLangTxt_State_Iecurrent = _T("电流(Ie)");
	g_sLangID_State_Acurrent = _T("State_Acurrent"); // LCQ
	g_sLangTxt_State_Acurrent = _T("电流(A)");
	g_sLangID_State_Harmonicwave = _T("State_Harmonicwave"); // LCQ
	g_sLangTxt_State_Harmonicwave = _T("谐波");
	g_sLangID_State_Interpolation = _T("State_Interpolation"); // LCQ
	g_sLangTxt_State_Interpolation = _T("插值法");
	g_sLangID_State_Synchronousmethod = _T("State_Synchronousmethod"); // LCQ
	g_sLangTxt_State_Synchronousmethod = _T("同步法");
	g_sLangID_State_TestLogic = _T("State_TestLogic"); // LCQ
	g_sLangTxt_State_TestLogic = _T("测试逻辑");
	g_sLangID_State_Risingedgeeffective = _T("State_Risingedgeeffective"); // LCQ
	g_sLangTxt_State_Risingedgeeffective = _T("上升沿有效");
	g_sLangID_State_Downedgeeffective = _T("State_Downedgeeffective"); // LCQ
	g_sLangTxt_State_Downedgeeffective = _T("下降沿有效");
	g_sLangID_State_NOPPS = _T("State_NOPPS"); // LCQ
	g_sLangTxt_State_NOPPS = _T("无PPS");
	g_sLangID_State_PPSsettings = _T("State_PPSsettings"); // LCQ
	g_sLangTxt_State_PPSsettings = _T("PPS设置");
	g_sLangID_State_UsNoPPSdelaycompensation = _T("State_UsNoPPSdelaycompensation"); // LCQ
	g_sLangTxt_State_UsNoPPSdelaycompensation = _T("无PPS延时补偿(μs)");
	g_sLangID_State_SSyncduration = _T("State_SSyncduration"); // LCQ
	g_sLangTxt_State_SSyncduration = _T("同步时长(s):");
	g_sLangID_State_UsCurrenterror = _T("State_UsCurrenterror"); // LCQ
	g_sLangTxt_State_UsCurrenterror = _T("当前误差(μs):");
	g_sLangID_State_UsMaximumerror = _T("State_UsMaximumerror"); // LCQ
	g_sLangTxt_State_UsMaximumerror = _T("最大误差(μs):");
	g_sLangID_State_UsMinimumerror = _T("State_UsMinimumerror"); // LCQ
	g_sLangTxt_State_UsMinimumerror = _T("最小误差(μs):");
	g_sLangID_State_Remark = _T("State_Remark"); // LCQ
	g_sLangTxt_State_Remark = _T("备注");
	g_sLangID_State_SPunctuality = _T("State_SPunctuality"); // LCQ
	g_sLangTxt_State_SPunctuality = _T("守时时长(s):");
	g_sLangID_State_Dropframes = _T("State_Dropframes"); // LCQ
	g_sLangTxt_State_Dropframes = _T("丢帧");
	g_sLangID_State_Flypoint = _T("State_Flypoint"); // LCQ
	g_sLangTxt_State_Flypoint = _T("飞点");
	g_sLangID_State_Dithering = _T("State_Dithering"); // LCQ
	g_sLangTxt_State_Dithering = _T("抖动");
	g_sLangID_State_OutofOrder = _T("State_OutofOrder"); // LCQ
	g_sLangTxt_State_OutofOrder = _T("错序");
	g_sLangID_State_VoltageandCurrent = _T("State_VoltageandCurrent"); // LCQ
	g_sLangTxt_State_VoltageandCurrent = _T("电压电流");
	g_sLangID_State_StateSequencefile = _T("State_StateSequencefile"); // LCQ
	g_sLangTxt_State_StateSequencefile = _T("状态序列模板文件");
	g_sLangID_State_SVexceptionSimulation = _T("State_SVexceptionSimulation"); // LCQ
	g_sLangTxt_State_SVexceptionSimulation = _T("异常模拟");
	g_sLangID_State_NumnotExceed = _T("State_NumnotExceed"); // LCQ
	g_sLangTxt_State_NumnotExceed = _T("状态数目不能超过%d");
	g_sLangID_State_TheCurrentLoop = _T("State_TheCurrentLoop"); // LCQ
	g_sLangTxt_State_TheCurrentLoop = _T("当前循环");
	g_sLangID_State_Enter = _T("State_Enter"); // LCQ
	g_sLangTxt_State_Enter = _T("进入");
	g_sLangID_Gradient_Functionalfiledtexist = _T("Gradient_Functionalfiledtexist"); // LCQ
	g_sLangTxt_Gradient_Functionalfiledtexist = _T("功能测试参数文件【%s】不存在");
	g_sLangID_State_InVolOutofRange = _T("State_InVolOutofRange"); // LCQ
	g_sLangTxt_State_InVolOutofRange = _T("输入的电压超出范围");
	g_sLangID_State_InCurOutofrange = _T("State_TheInputCurrentisOutofrange"); // LCQ
	g_sLangTxt_State_InCurOutofrange = _T("输入的电流超出范围");
	g_sLangID_State_TheOnepercentHarmonic = _T("State_TheOnepercentHarmonic"); // LCQ
	g_sLangTxt_State_TheOnepercentHarmonic = _T("%1次谐波");
	g_sLangID_State_HarmonicTestTemplatefile = _T("State_HarmonicTestTemplatefile"); // LCQ
	g_sLangTxt_State_HarmonicTestTemplatefile = _T("谐波测试模板文件");
	g_sLangID_State_IncreExperfile = _T("State_IncreExperfile"); // LCQ
	g_sLangTxt_State_IncreExperfile = _T("递变试验模板文件");
	g_sLangID_State_IlleInputCharac = _T("State_IlleInputCharac"); // LCQ
	g_sLangTxt_State_IlleInputCharac = _T("输入值含有非法字符.");
	g_sLangID_State_EnterTheValueoutofRange = _T("State_EnterTheValueoutofRange"); // LCQ
	g_sLangTxt_State_EnterTheValueoutofRange = _T("输入值%f超出范围(%d).");
	g_sLangID_State_Gooseexfile = _T("State_Gooseexfile"); // LCQ
	g_sLangTxt_State_Gooseexfile = _T("Goose异常模拟模板文件");
	g_sLangID_State_GOOSEmessageparameters = _T("State_GOOSEmessageparameters"); // LCQ
	g_sLangTxt_State_GOOSEmessageparameters = _T("GOOSE报文参数");
	g_sLangID_State_Genexperfile = _T("State_Genexperfile"); // LCQ
	g_sLangTxt_State_Genexperfile = _T("通用试验模板文件");
	g_sLangID_State_TBuildDate = _T("State_TBuildDate"); // LCQ
	g_sLangTxt_State_TBuildDate = _T("TestCtrlCntrLinux生成日期");
	g_sLangID_State_IEEECurset = _T("State_IEEECurset"); // LCQ
	g_sLangTxt_State_IEEECurset = _T("IEEE曲线参数设置");
	g_sLangID_State_IACCurSet = _T("State_IACCurSet"); // LCQ
	g_sLangTxt_State_IACCurSet = _T("IAC曲线参数设置");
	g_sLangID_State_I2TCurSet = _T("State_I2TCurSet"); // LCQ
	g_sLangTxt_State_I2TCurSet = _T("I2T曲线参数设置");
	g_sLangID_State_IECCurSet = _T("State_IECCurSet"); // LCQ
	g_sLangTxt_State_IECCurSet = _T("IEC曲线参数设置");
	g_sLangID_State_VolLimitSet = _T("State_VolLimitSet"); // LCQ
	g_sLangTxt_State_VolLimitSet = _T("电压反时限参数设置");
	g_sLangID_State_Magnify = _T("State_Magnify"); // LCQ
	g_sLangTxt_State_Magnify = _T("放大");
	g_sLangID_State_Shrink = _T("State_Shrink"); // LCQ
	g_sLangTxt_State_Shrink = _T("缩小");

	g_sLangID_IECConfig_Screen = _T("IECConfig_Screen");
	g_sLangTxt_IECConfig_Screen = _T("筛选");

	g_sLangID_State_Reposition = _T("State_Reposition"); // LCQ
	g_sLangTxt_State_Reposition = _T("复位");
	g_sLangID_Native_Faultcurrent = _T("Native_Faultcurrent");
	g_sLangTxt_Native_Faultcurrent = _T("故障电压(V)");

	g_sLangID_Gradient_CreateFolder = _T("Gradient_CreateFolder"); // LCQ
	g_sLangTxt_Gradient_CreateFolder = _T("创建文件夹");
	g_sLangID_Gradient_FolderCreationFailed = _T("Gradient_FolderCreationFailed"); // LCQ
	g_sLangTxt_Gradient_FolderCreationFailed = _T("文件夹创建失败！");
	g_sLangID_Gradient_AddExperiment = _T("Gradient_AddExperiment"); // LCQ
	g_sLangTxt_Gradient_AddExperiment = _T("添加试验");

	g_sLangID_State_FThreeStraight = _T("State_FThreeStraight"); // LCQ
	g_sLangTxt_State_FThreeStraight = _T("柔直(FT3)");
	g_sLangID_State_SinglephaseImpedance = _T("State_SinglephaseImpedance"); // LCQ
	g_sLangTxt_State_SinglephaseImpedance = _T("单相阻抗");
	g_sLangID_State_Coincidence = _T("State_Coincidence"); // LCQ
	g_sLangTxt_State_Coincidence = _T("重  合");
	g_sLangID_State_RearAcceleration = _T("State_RearAcceleration"); // LCQ
	g_sLangTxt_State_RearAcceleration = _T("后 加 速");
	g_sLangID_State_VersionInformation = _T("State_VersionInformation"); // LCQ
	g_sLangTxt_State_VersionInformation = _T("版本信息");
	g_sLangID_State_ApplianceProperties = _T("State_ApplianceProperties"); // LCQ
	g_sLangTxt_State_ApplianceProperties = _T("装置属性");
	g_sLangID_State_AppNumber = _T("State_AppNumber"); // LCQ
	g_sLangTxt_State_AppNumber = _T("编号:");
	g_sLangID_State_ModuleManagement = _T("State_ModuleManagement"); // LCQ
	g_sLangTxt_State_ModuleManagement = _T("模块管理");
	g_sLangID_State_TheEdgeElementType = _T("State_TheEdgeElementType"); // LCQ
	g_sLangTxt_State_TheEdgeElementType = _T("边元素类型");
	g_sLangID_State_ErrorBandLength = _T("State_ErrorBandLength"); // LCQ
	g_sLangTxt_State_ErrorBandLength = _T("误差带长度");
	g_sLangID_State_EdgeTestPoints = _T("State_EdgeTestPoints"); // LCQ
	g_sLangTxt_State_EdgeTestPoints = _T("边测试点数");
	g_sLangID_State_startingPointR = _T("State_startingPointR"); // LCQ
	g_sLangTxt_State_startingPointR = _T("起始点-R");
	g_sLangID_State_startingPointX = _T("State_startingPointX"); // LCQ
	g_sLangTxt_State_EdgeTestPointX = _T("起始点-X");
	g_sLangID_State_EndPointR = _T("State_EndPointR"); // LCQ
	g_sLangTxt_State_EndPointR = _T("终止点-R");
	g_sLangID_State_EndPointX = _T("State_EndPointX"); // LCQ
	g_sLangTxt_State_EndPointX = _T("终止点-X");
	g_sLangID_State_Direction = _T("State_Direction"); // LCQ
	g_sLangTxt_State_Direction = _T("方向");
	g_sLangID_State_PositiveArrival = _T("State_PositiveArrival"); // LCQ
	g_sLangTxt_State_PositiveArrival = _T("正向到达");
	g_sLangID_State_ANgle = _T("State_ANgle"); // LCQ
	g_sLangTxt_State_ANgle = _T("角度");
	g_sLangID_State_Offset = _T("State_Offset"); // LCQ
	g_sLangTxt_State_Offset = _T("偏移");
	g_sLangID_State_Width = _T("State_Width"); // LCQ
	g_sLangTxt_State_Width = _T("宽度");
	g_sLangID_State_CenterX = _T("State_CenterX"); // LCQ
	g_sLangTxt_State_CenterX = _T("x-圆心");
	g_sLangID_State_CenterY = _T("State_CenterY"); // LCQ
	g_sLangTxt_State_CenterY = _T("y-圆心");
	g_sLangID_State_Radius = _T("State_Radius"); // LCQ
	g_sLangTxt_State_Radius = _T("半径");
	g_sLangID_State_StartingAngle = _T("State_StartingAngle"); // LCQ
	g_sLangTxt_State_StartingAngle = _T("起始角度");
	g_sLangID_State_TerminationAngle = _T("State_TerminationAngle"); // LCQ
	g_sLangTxt_State_TerminationAngle = _T("终止角度");
	g_sLangID_State_ClockDirection = _T("State_ClockDirection"); // LCQ
	g_sLangTxt_State_ClockDirection = _T("时钟方向");
	g_sLangID_State_CharCurEdgeElements = _T("State_CharCurEdgeElements"); // LCQ
	g_sLangTxt_State_CharCurEdgeElements = _T("特性曲线边元素");
	g_sLangID_State_POpenCFile = _T("State_POpenCFile"); // LCQ
	g_sLangTxt_State_POpenCFile = _T("请打开COMTRADE波形文件");
	g_sLangID_State_UTC_TwelveWIntDLine = _T("State_UTC_TwelveWIntDLine"); // LCQ
	g_sLangTxt_State_UTC_TwelveWIntDLine = _T("(UTC-12:00)国际日期变更线西");
	g_sLangID_State_UTC_ElevenCUTime = _T("State_UTC_ElevenCUTime"); // LCQ
	g_sLangTxt_State_UTC_ElevenCUTime = _T("(UTC-11:00)协调世界时-11");
	g_sLangID_State_UTC_TenAleutianIslands = _T("State_UTC_TenAleutianIslands"); // LCQ
	g_sLangTxt_State_UTC_TenAleutianIslands = _T("(UTC-10:00)阿留申群岛");
	g_sLangID_State_UTC_NineAlaska = _T("State_UTC_NineAlaska"); // LCQ
	g_sLangTxt_State_UTC_NineAlaska = _T("(UTC-9:00)阿拉斯加");
	g_sLangID_State_UTC_EUCPacificTime = _T("State_UTC_EUCPacificTime"); // LCQ
	g_sLangTxt_State_UTC_EUCPacificTime = _T("(UTC-8:00)太平洋时间(美国和加拿大)");
	g_sLangID_State_UTC_SevenCLM = _T("State_UTC_SevenCLM"); // LCQ
	g_sLangTxt_State_UTC_SevenCLM = _T("(UTC-7:00)奇瓦瓦,拉巴斯,马萨特兰");
	g_sLangID_State_UTC_SixCentralAmerica = _T("State_UTC_SixCentralAmerica"); // LCQ
	g_sLangTxt_State_UTC_SixCentralAmerica = _T("(UTC-6:00)中美洲");
	g_sLangID_State_UTC_FiveUCEasternTime = _T("State_UTC_FiveUCEasternTime"); // LCQ
	g_sLangTxt_State_UTC_FiveUCEasternTime = _T("(UTC-5:00)东部时间(美国和加拿大)");
	g_sLangID_State_UTC_FourCanadaAtlanticTime = _T("State_UTC_FourCanadaAtlanticTime"); // LCQ
	g_sLangTxt_State_UTC_FourCanadaAtlanticTime = _T("(UTC-4:00)大西洋时间(加拿大)");
	g_sLangID_State_UTC_ThreeGreenland = _T("State_UTC_ThreeGreenland"); // LCQ
	g_sLangTxt_State_UTC_ThreeGreenland = _T("(UTC-3:00)格陵兰");
	g_sLangID_State_UTC_TwoCooUniversalTime = _T("State_UTC_TwoCooUniversalTime"); // LCQ
	g_sLangTxt_State_UTC_TwoCooUniversalTime = _T("(UTC-2:00)协调世界时-2");
	g_sLangID_State_UTC_OneCapIslandsAzores = _T("State_UTC_OneCapIslandsAzores"); // LCQ
	g_sLangTxt_State_UTC_OneCapIslandsAzores = _T("(UTC-1:00)佛得角群岛,亚速尔群岛");
	g_sLangID_State_UTC_DubEdinhLisLon = _T("State_UTC_DubEdinhLisLon"); // LCQ
	g_sLangTxt_State_UTC_DubEdinhLisLon = _T("(UTC)都柏林,爱丁堡,里斯本,伦敦");
	g_sLangID_State_UTC_POneBCMPWAfrica = _T("State_UTC_POneBCMPWAfrica"); // LCQ
	g_sLangTxt_State_UTC_POneBCMPWAfrica = _T("(UTC+1:00)布鲁塞尔,哥本哈根,马德里,巴黎,中非西部");
	g_sLangID_State_UTC_PTwoCAJerusalem = _T("State_UTC_PTwoCAJerusalem"); // LCQ
	g_sLangTxt_State_UTC_PTwoCAJerusalem = _T("(UTC+2:00)开罗,雅典,耶路撒冷");
	g_sLangID_State_UTC_PThreeBKMPeterby = _T("State_UTC_PThreeBKMPeterby"); // LCQ
	g_sLangTxt_State_UTC_PThreeBKMPeterby = _T("(UTC+3:00)巴格达,科威特,莫斯科,圣彼得比");
	g_sLangID_State_UTC_PFourAbuDhabiBaku = _T("State_UTC_PFourAbuDhabiBaku"); // LCQ
	g_sLangTxt_State_UTC_PFourAbuDhabiBaku = _T("(UTC+4:00)阿布扎比,巴库");
	g_sLangID_State_UTC_PFiveIslamabadKarachi = _T("State_UTC_PFiveIslamabadKarachi"); // LCQ
	g_sLangTxt_State_UTC_PFiveIslamabadKarachi = _T("(UTC+5:00)伊斯兰堡,卡拉奇");
	g_sLangID_State_UTC_PSixAstana = _T("State_UTC_PSixAstana"); // LCQ
	g_sLangTxt_State_UTC_PSixAstana = _T("(UTC+6:00)阿斯塔纳");
	g_sLangID_State_UTC_PSevenBHJakarta = _T("State_UTC_PSevenBHJakarta"); // LCQ
	g_sLangTxt_State_UTC_PSevenBHJakarta = _T("(UTC+7:00)曼谷,河内,雅加达");
	g_sLangID_State_UTC_PEightBCHUrumqi = _T("State_UTC_PEightBCHUrumqi"); // LCQ
	g_sLangTxt_State_UTC_PEightBCHUrumqi = _T("(UTC+8:00)北京,重庆,香港,乌鲁木齐");
	g_sLangID_State_UTC_PNineTSPyongyang = _T("State_UTC_PNineTSPyongyang"); // LCQ
	g_sLangTxt_State_UTC_PNineTSPyongyang = _T("(UTC+9:00)东京,首尔,平壤");
	g_sLangID_State_UTC_PTenCMSydney = _T("State_UTC_PTenCMSydney"); // LCQ
	g_sLangTxt_State_UTC_PTenCMSydney = _T("(UTC+10:00)堪培拉,墨尔本,悉尼");
	g_sLangID_State_UTC_PSINCaledonia = _T("State_UTC_PSINCaledonia"); // LCQ
	g_sLangTxt_State_UTC_PSINCaledonia = _T("(UTC+11:00)所罗门群岛,新喀里多尼亚");
	g_sLangID_State_UTC_PTwelveFiji = _T("State_UTC_PTwelveFiji"); // LCQ
	g_sLangTxt_State_UTC_PTwelveFiji = _T("(UTC+12:00)斐济");
	g_sLangID_State_LowVoltageprotection = _T("State_LowVoltageprotection"); // LCQ
	g_sLangTxt_State_LowVoltageprotection = _T("低压保护");
	g_sLangID_State_Overvoltageprotection = _T("State_Overvoltageprotection"); // LCQ
	g_sLangTxt_State_Overvoltageprotection = _T("过压保护");
	g_sLangID_State_HarmonicBrakingcoefficient = _T("State_HarmonicBrakingcoefficient"); // LCQ
	g_sLangTxt_State_HarmonicBrakingcoefficient = _T("谐波制动系数");
	g_sLangID_State_Harmonicbraking = _T("State_Harmonicbraking"); // LCQ
	g_sLangTxt_State_Harmonicbraking = _T("谐波制动");

	g_sLangID_Gradient_CurbanksatleastTwo = _T("Gradient_CurbanksatleastTwo"); // LCQ
	g_sLangTxt_Gradient_CurbanksatleastTwo = _T("当前电流组数为%ld组,至少需要2组电流才能进行差流计算.");
	g_sLangID_Gradient_CurselinNotFound = _T("Gradient_CurselinNotFound"); // LCQ
	g_sLangTxt_Gradient_CurselinNotFound = _T("当前选择的递变通道(Index=%d)未查找到.");
	g_sLangID_Gradient_CurinDCincrement = _T("Gradient_CurinDCincrement"); // LCQ
	g_sLangTxt_Gradient_CurinDCincrement = _T("当前为直流输出模式,不可切换为频率递变.");
	g_sLangID_Gradient_NoteThepthanoneus = _T("Gradient_NoteThepthanoneus"); // LCQ
	g_sLangTxt_Gradient_NoteThepthanoneus = _T("备注:规程要求测试时间1分钟，最大对时误差不大于1μs.");
	g_sLangID_Gradient_NoteThepthanfourus = _T("Gradient_NoteThepthanfourus"); // LCQ
	g_sLangTxt_Gradient_NoteThepthanfourus = _T("备注:规程要求测试时间10分钟，最大守时误差不大于4μs.");

	g_sLangID_Gradient_InPPSfreemodevaluecontrolblock = _T("Gradient_InPPSfreemodevaluecontrolblock");
	g_sLangTxt_Gradient_InPPSfreemodevaluecontrolblock = _T("无PPS模式下,需要先进行报文探测,选择对应采样值控制块."); // LCQ
	g_sLangID_Gradient_GOOSEreleaseDataStatusIsempty = _T("Gradient_GOOSEreleaseDataStatusIsempty");
	g_sLangID_Gradient_GOOSEreleaseDataStatusIsempty = _T("当前状态(%d)的GOOSE发布数据为空(出现异常)."); // LCQ
	g_sLangID_Gradient_MaintainatLeastOneState = _T("Gradient_MaintainatLeastOneState");				 // LCQ
	g_sLangTxt_Gradient_MaintainatLeastOneState = _T("至少保留一个状态.");
	g_sLangID_Gradient_Intotalcheckarow = _T("Gradient_Intotalcheckarow"); // LCQ
	g_sLangTxt_Gradient_Intotalcheckarow = _T("总计只能选择%d次谐波，假如想选择当前次谐波，需要取消勾选一行.");
	g_sLangID_Gradient_TheUsedfordebuggingNOexist = _T("Gradient_TheUsedfordebuggingNOexist"); // LCQ
	g_sLangTxt_Gradient_TheUsedfordebuggingNOexist = _T("调试使用的配置文件(%s)不存在.");
	g_sLangID_Gradient_FailedTestParameterfile = _T("Gradient_FailedTestParameterfile"); // LCQ
	g_sLangTxt_Gradient_FailedTestParameterfile = _T("解析功能测试参数文件【%s】失败");
	g_sLangID_Gradient_MissingDefaultMappings = _T("Gradient_MissingDefaultMappings"); // LCQ
	g_sLangTxt_Gradient_MissingDefaultMappings = _T("缺少硬件资源文件,无法创建缺省通道映射.");
	g_sLangID_Gradient_FailDefaultPath = _T("Gradient_FailDefaultPath"); // LCQ
	g_sLangTxt_Gradient_FailDefaultPath = _T("创建通道映射缺省路径失败.");
	g_sLangID_Gradient_ExportfileSucceeded = _T("Gradient_ExportfileSucceeded"); // LCQ
	g_sLangTxt_Gradient_ExportfileSucceeded = _T("导出通道映射文件[%s]成功");
	g_sLangID_Gradient_Failedtofile = _T("Gradient_Failedtofile"); // LCQ
	g_sLangTxt_Gradient_Failedtofile = _T("导出通道映射文件[%s]失败");
	g_sLangID_Gradient_TheTesterfileFailedtoload = _T("Gradient_TheTesterfileFailedtoload"); // LCQ
	g_sLangTxt_Gradient_TheTesterfileFailedtoload = _T("测试仪硬件信息文件加载失败.");

	g_sLangID_State_HardwareInformationSettings = _T("State_HardwareInformationSettings"); // LCQ
	g_sLangTxt_State_HardwareInformationSettings = _T("硬件信息设置");

	g_sLangID_Gradient_UnknownCommand = _T("Gradient_UnknownCommand"); // LCQ
	g_sLangTxt_Gradient_UnknownCommand = _T("未知的网页报告执行命令(%s).");

	g_sLangID_Gradient_Inverse = _T("Gradient_Inverse"); // LCQ
	g_sLangTxt_Gradient_Inverse = _T("反选");

	g_sLangID_Gradient_VActionValue = _T("Gradient_VActionValue"); // LCQ;
	g_sLangTxt_Gradient_VActionValue = _T("电压动作值(V)");

	g_sLangID_Gradient_CActionValue = _T("Gradient_CActionValue"); // LCQ
	g_sLangTxt_Gradient_CActionValue = _T("电流动作值(A)");

	g_sLangID_Gradient_ReCoefficient = _T("Gradient_ReCoefficient"); // LCQ
	g_sLangTxt_Gradient_ReCoefficient = _T("返回系数");

	g_sLangID_Gradient_FirBoundAngle = _T("Gradient_FirBoundAngle"); // LCQ
	g_sLangTxt_Gradient_FirBoundAngle = _T("边界角1(°)");

	g_sLangID_Gradient_SecBoundAngle = _T("Gradient_SecBoundAngle"); // LCQ
	g_sLangTxt_Gradient_SecBoundAngle = _T("边界角2(°)");

	g_sLangID_Gradient_MaxSenAngle = _T("Gradient_MaxSenAngle"); // LCQ
	g_sLangTxt_Gradient_MaxSenAngle = _T("最大灵敏角(°)");

	g_sLangID_Gradient_FreAction = _T("Gradient_FreAction"); // LCQ
	g_sLangTxt_Gradient_FreAction = _T("动作频率(Hz)");

	g_sLangID_Gradient_PhaseAValue = _T("Gradient_PhaseAValue"); // LCQ
	g_sLangTxt_Gradient_PhaseAValue = _T("相位动作值(°)");

	g_sLangID_Gradient_ImpAValue = _T("Gradient_ImpAValue");
	g_sLangTxt_Gradient_ImpAValue = _T("阻抗动作值(Ω)");

	g_sLangID_Gradient_TestTeach = _T("Gradient_TestTeach"); // LCQ
	g_sLangTxt_Gradient_TestTeach = _T("测试教学");

	g_sLangID_Gradient_ReportHeader = _T("Gradient_ReportHeader"); // LCQ;
	g_sLangTxt_Gradient_ReportHeader = _T("报告头信息");

	g_sLangID_Gradient_TestTempSusCom = _T("Gradient_TestTempSusCom"); // LCQ;
	g_sLangTxt_Gradient_TestTempSusCom = _T("下发保存测试模板(%s%s)命令成功.");

	g_sLangID_Gradient_TestTempDefCom = _T("Gradient_TestTempDefCom"); // LCQ;
	g_sLangTxt_Gradient_TestTempDefCom = _T("下发保存测试模板(%s%s)命令失败.");

	g_sLangID_Gradient_SavePageSus = _T("Gradient_SavePageSus"); // LCQ;
	g_sLangTxt_Gradient_SavePageSus = _T("保存网页模板文件(%s%s)成功.");

	g_sLangID_Gradient_TestRecordSus = _T("Gradient_TestRecordSus"); // LCQ;
	g_sLangTxt_Gradient_TestRecordSus = _T("下发保存测试记录(%s%s)命令成功.");

	g_sLangID_Gradient_TestRecordFai = _T("Gradient_TestRecordFai"); // LCQ;
	g_sLangTxt_Gradient_TestRecordFai = _T("下发保存测试记录(%s%s)命令失败.");

	g_sLangID_Gradient_SaveReportSus = _T("Gradient_SaveReportSus"); // LCQ;
	g_sLangTxt_Gradient_SaveReportSus = _T("保存报告文件(%s%s)成功.");

	g_sLangID_Gradient_SameeXist = _T("Gradient_SameeXist"); // LCQ;
	g_sLangTxt_Gradient_SameeXist = _T("路径(%s)下存在同名的文件,请修改文件名.");

	g_sLangID_Gradient_LocalNICIP = _T("Gradient_LocalNICIP"); // LCQ;
	g_sLangTxt_Gradient_LocalNICIP = _T("本地网卡IP");

	g_sLangID_Gradient_PrimaryIP = _T("Gradient_PrimaryIP"); // LCQ;
	g_sLangTxt_Gradient_PrimaryIP = _T("主IP地址");

	g_sLangID_Gradient_CurGSetting = _T("Gradient_CurGSetting"); // LCQ;
	g_sLangTxt_Gradient_CurGSetting = _T("电流档位设置:");

	g_sLangID_Gradient_HighCurPort = _T("Gradient_HighCurPort"); // LCQ;
	g_sLangTxt_Gradient_HighCurPort = _T("大电流输出端口:");

	g_sLangID_Gradient_FirstFile = _T("Gradient_FirstFile"); // LCQ;
	g_sLangTxt_Gradient_FirstFile = _T("1档(0.2Ω/10A)");

	g_sLangID_Gradient_SecondFile = _T("Gradient_SecondFile"); // LCQ;
	g_sLangTxt_Gradient_SecondFile = _T("2档(0.3Ω/10A)");

	g_sLangID_Gradient_ThirdFile = _T("Gradient_ThirdFile"); // LCQ;
	g_sLangTxt_Gradient_ThirdFile = _T("3档(0.7Ω/10A)");

	//"1档(0.3Ω/10A)" lcq
	g_sLangID_Currentlevel1 = _T("Currentlevel1");
	g_sLangTxt_Currentlevel1 = _T("1档(0.3Ω/10A)");
	//"2档(0.7Ω/10A)" lcq
	g_sLangID_Currentlevel2= _T("Currentlevel2");
	g_sLangTxt_Currentlevel2 = _T("2档(0.7Ω/10A)");
	//"3档(1.5Ω/10A)" lcq
	g_sLangID_Currentlevel3 = _T("Currentlevel3");
	g_sLangTxt_Currentlevel3= _T("3档(1.5Ω/10A)");


	g_sLangID_Gradient_ShotScreenSus = _T("Gradient_ShotScreenSus"); // LCQ;
	g_sLangTxt_Gradient_ShotScreenSus = _T("截屏成功.");

	g_sLangID_Gradient_IECConfiguration = _T("Gradient_IECConfiguration"); // LCQ;
	g_sLangTxt_Gradient_IECConfiguration = _T("IEC配置");

	g_sLangID_Gradient_MessageType = _T("Gradient_MessageType"); // LCQ;
	g_sLangTxt_Gradient_MessageType = _T("报文类型");

	g_sLangID_Gradient_SCLPars = _T("Gradient_SCLPars"); // LCQ;
	g_sLangTxt_Gradient_SCLPars = _T("SCL解析界面");

	g_sLangID_Gradient_VoltageSet = _T("Gradient_VoltageSet"); // LCQ;
	g_sLangTxt_Gradient_VoltageSet = _T("电压设置");

	g_sLangID_Gradient_CurrentSet = _T("Gradient_CurrentSet"); // LCQ;
	g_sLangTxt_Gradient_CurrentSet = _T("电流设置");

	g_sLangID_Gradient_FailedGfp = _T("Gradient_FailedGfp"); // LCQ
	g_sLangTxt_Gradient_FailedGfp = _T("获取文件路径失败(%s).");

	g_sLangID_Gradient_FailedTof = _T("Gradient_FailedTof"); // LCQ
	g_sLangTxt_Gradient_FailedTof = _T("打开文件失败(%s).");

	g_sLangID_Gradient_FailedCwf = _T("Gradient_FailedCwf"); // LCQ
	g_sLangTxt_Gradient_FailedCwf = _T("[%s]创建写文件失败.");

	g_sLangID_Gradient_FileIsize = _T("Gradient_FileIsize"); // LCQ
	g_sLangTxt_Gradient_FileIsize = _T("文件[%s]大小为(%ld).");

	g_sLangID_Gradient_FailedTRlfile = _T("Gradient_FailedTRlfile"); // LCQ
	g_sLangTxt_Gradient_FailedTRlfile = _T("读取指定长度的大文件内容失败.");
	//
	// g_sLangID_Gradient_FileIsize           = _T("Gradient_FileIsize");     //LCQ   zhouhj 2023.7.31 删除重复
	// g_sLangTxt_Gradient_FileIsize          = _T("文件[%s]大小为(%ld).");

	g_sLangID_Gradient_FileNoexist = _T("Gradient_FileNoexist"); // LCQ
	g_sLangTxt_Gradient_FileNoexist = _T("文件不存在(%s).");

	g_sLangID_Gradient_FreAValue = _T("Gradient_FreAValue"); // LCQ
	g_sLangTxt_Gradient_FreAValue = _T("频率动作值(Hz)");

	g_sLangID_Gradient_ReleasedFTT = _T("Gradient_ReleasedFTT"); // LCQ
	g_sLangTxt_Gradient_ReleasedFTT = _T("FT3发布");

	g_sLangID_Gradient_CurSmvErr = _T("Gradient_CurSmvErr"); // LCQ
	g_sLangTxt_Gradient_CurSmvErr = _T("当前SMVFT3通道映射出错(%s).");

	g_sLangID_Gradient_ExIEDdescrip = _T("Gradient_ExIEDdescrip"); // LCQ
	g_sLangTxt_Gradient_ExIEDdescrip = _T("外部IED描述");

	g_sLangID_Gradient_ParseLFile = _T("Gradient_ParseLFile"); // LCQ
	g_sLangTxt_Gradient_ParseLFile = _T("解析文件(");

	g_sLangID_Gradient_SCLNoSel = _T("Gradient_SCLNoSel"); // LCQ;
	g_sLangTxt_Gradient_SCLNoSel = _T(")不存在,无法进行SCL选择切换.");

	g_sLangID_Gradient_NoParObjRisk = _T("Gradient_NoParObjRisk"); // LCQ
	g_sLangTxt_Gradient_NoParObjRisk = _T("当前表格数据链表无父对象,删除当前行数据失败,存在内存泄漏风险.");

	g_sLangID_Gradient_FailType = _T("Gradient_FailType"); // LCQ
	g_sLangTxt_Gradient_FailType = _T("故障类型");

	g_sLangID_Gradient_FailDirect = _T("Gradient_FailDirect"); // LCQ
	g_sLangTxt_Gradient_FailDirect = _T("故障方向");

	g_sLangID_Gradient_FailTime = _T("Gradient_FailTime"); // LCQ
	g_sLangTxt_Gradient_FailTime = _T("故障时间");

	g_sLangID_Gradient_Slope = _T("Gradient_Slope"); // LCQ
	g_sLangTxt_Gradient_Slope = _T("斜率");

	g_sLangID_Gradient_StartTs = _T("Gradient_StartTs"); // LCQ
	g_sLangTxt_Gradient_StartTs = _T("启动门槛");

	g_sLangID_Gradient_StartCur = _T("Gradient_StartCur"); // LCQ
	g_sLangTxt_Gradient_StartCur = _T("启动电流");

	g_sLangID_Gradient_Inflectp = _T("Gradient_Inflectp"); // LCQ
	g_sLangTxt_Gradient_Inflectp = _T("拐点");

	g_sLangID_Gradient_DiffFlowEx = _T("Gradient_DiffFlowEx"); // LCQ
	g_sLangTxt_Gradient_DiffFlowEx = _T("差流极值");

	g_sLangID_Gradient_AddCusp = _T("Gradient_AddCusp"); // LCQ
	g_sLangTxt_Gradient_AddCusp = _T("添加自定义点");

	g_sLangID_Gradient_Emptycusp = _T("Gradient_Emptycusp"); // LCQ
	g_sLangTxt_Gradient_Emptycusp = _T("清空自定义点");

	g_sLangID_Gradient_NoLessCor = _T("Gradient_NoLessCor"); // LCQ
	g_sLangTxt_Gradient_NoLessCor = _T("差流极值设置不能小于拐点电流对应差流值.");

	g_sLangID_Gradient_RatioDiff = _T("Gradient_RatioDiff"); // LCQ
	g_sLangTxt_Gradient_RatioDiff = _T("比率差动");

	g_sLangID_Gradient_Custestp = _T("Gradient_Custestp"); // LCQ;
	g_sLangTxt_Gradient_Custestp = _T("自定义测试点");

	g_sLangID_Gradient_Impedance = _T("Gradient_Impedance"); // LCQ
	g_sLangTxt_Gradient_Impedance = _T("阻抗表达方式");

	g_sLangID_Gradient_SelectCur = _T("Gradient_SelectCur"); // LCQ
	g_sLangTxt_Gradient_SelectCur = _T("请先选择需要删除的特性曲线");

	g_sLangID_Gradient_CurveEditing = _T("Gradient_CurveEditing"); // LCQ
	g_sLangTxt_Gradient_CurveEditing = _T("曲线编辑");

	g_sLangID_Gradient_InsertElement = _T("Gradient_InsertElement"); // LCQ
	g_sLangTxt_Gradient_InsertElement = _T("插入元素");

	g_sLangID_Gradient_ModifyElement = _T("Gradient_ModifyElement"); // LCQ
	g_sLangTxt_Gradient_ModifyElement = _T("修改元素");

	g_sLangID_Gradient_DeleteElement = _T("Gradient_DeleteElement"); // LCQ
	g_sLangTxt_Gradient_DeleteElement = _T("删除元素");

	g_sLangID_Gradient_PInitial = _T("Gradient_PInitial"); // LCQ
	g_sLangTxt_Gradient_PInitial = _T("+:初始");

	g_sLangID_Gradient_PSelected = _T("Gradient_PSelected"); // LCQ
	g_sLangTxt_Gradient_PSelected = _T("+:选中");

	g_sLangID_Gradient_EndTrial = _T("Gradient_EndTrial"); // LCQ
	g_sLangTxt_Gradient_EndTrial = _T("+:试验结束");

	g_sLangID_Gradient_UnUpdateGraph = _T("Gradient_UnUpdateGraph"); // LCQ
	g_sLangTxt_Gradient_UnUpdateGraph = _T("特性曲线查找失败(strCharaID=%s;strIndex=%s),无法更新曲线图");

	g_sLangID_Gradient_YNWirBlancer = _T("Gradient_YNWirBlancer"); // LCQ
	g_sLangTxt_Gradient_YNWirBlancer = _T("Y/V接线平衡变压器");

	g_sLangID_Gradient_YNoCorners = _T("Gradient_YNoCorners"); // LCQ
	g_sLangTxt_Gradient_YNoCorners = _T("Y/△-11接线(无转角)");

	g_sLangID_Gradient_Sphase = _T("Gradient_Sphase"); // LCQ
	g_sLangTxt_Gradient_Sphase = _T("单相变压器");

	g_sLangID_Gradient_YDSCornect = _T("Gradient_YDSCornect"); // LCQ
	g_sLangTxt_Gradient_YDSCornect = _T("Y/△/△接线");

	g_sLangID_Gradient_ImpedanceMB = _T("Gradient_ImpedanceMB"); // LCQ
	g_sLangTxt_Gradient_ImpedanceMB = _T("Y/A 接线阻抗匹配平衡变压器");

	g_sLangID_Gradient_ThrVWirceTF = _T("Gradient_ThrVWirceTF"); // LCQ
	g_sLangTxt_Gradient_ThrVWirceTF = _T("三相V/V接线变压器");

	g_sLangID_Gradient_SecThrVWirceTF = _T("Gradient_SecThrVWirceTF"); // LCQ
	g_sLangTxt_Gradient_SecThrVWirceTF = _T("三相V/V接线变压器2");

	g_sLangID_Gradient_YSideCorner = _T("Gradient_YSideCorner"); // LCQ
	g_sLangTxt_Gradient_YSideCorner = _T("Y/△-11接线(Y侧转角)");

	g_sLangID_Gradient_VThrPhase = _T("Gradient_VThrPhase"); // LCQ
	g_sLangTxt_Gradient_VThrPhase = _T("三相V/V");

	g_sLangID_Gradient_IRCurrent = _T("Gradient_IRCurrent"); // LCQ
	g_sLangTxt_Gradient_IRCurrent = _T("基准电流(Ie)");

	g_sLangID_Gradient_ARCurrent = _T("Gradient_ARCurrent"); // LCQ
	g_sLangTxt_Gradient_ARCurrent = _T("基准电流(A)");

	g_sLangID_Gradient_ActionTime = _T("Gradient_ActionTime "); // LCQ
	g_sLangTxt_Gradient_ActionTime = _T("动作时间");

	g_sLangID_Gradient_ModuleType = _T("Gradient_ModuleType"); // LCQ;
	g_sLangTxt_Gradient_ModuleType = _T("模块类型");

	g_sLangID_Gradient_LocNumber = _T("Gradient_LocNumber"); // LCQ;
	g_sLangTxt_Gradient_LocNumber = _T("位置号");

	g_sLangID_Gradient_ModuleVersion = _T("Gradient_ModuleVersion"); // LCQ;
	g_sLangTxt_Gradient_ModuleVersion = _T("模块版本");

	g_sLangID_Gradient_ManufactDate = _T("Gradient_ManufactDate"); // LCQ;
	g_sLangTxt_Gradient_ManufactDate = _T("生产日期");

	g_sLangID_Gradient_JumpA = _T("Gradient_JumpA"); // LCQ;
	g_sLangTxt_Gradient_JumpA = _T(" 跳  A ");

	g_sLangID_Gradient_JumpB = _T("Gradient_JumpB"); // LCQ;
	g_sLangTxt_Gradient_JumpB = _T(" 跳  B ");

	g_sLangID_Gradient_JumpC = _T("Gradient_JumpC"); // LCQ;
	g_sLangTxt_Gradient_JumpC = _T(" 跳  C ");

	g_sLangID_Gradient_Jjump = _T("Gradient_Jjump"); // LCQ;
	g_sLangTxt_Gradient_Jjump = _T("跳");

	g_sLangID_Gradient_CurPhaseErr = _T("Gradient_CurPhaseErr"); // LCQ;
	g_sLangTxt_Gradient_CurPhaseErr = _T("当前相位值越限出错(%f).");

	g_sLangID_Gradient_Setting = _T("Gradient_Setting"); // LCQ;
	g_sLangTxt_Gradient_Setting = _T("设置");

	g_sLangID_Gradient_FT3CurChanErr = _T("Gradient_FT3CurChanErr"); // LCQ;
	g_sLangTxt_Gradient_FT3CurChanErr = _T("当前FT3通道映射出错(%s).");

	g_sLangID_Gradient_OpticalPower = _T("Gradient_OpticalPower"); // LCQ;
	g_sLangTxt_Gradient_OpticalPower = _T("光功率");

	g_sLangID_Gradient_POpticalPort = _T("Gradient_POpticalPort"); // LCQ;
	g_sLangTxt_Gradient_POpticalPort = _T("光口%d");

	g_sLangID_Gradient_FOpticalPower = _T("Gradient_FOpticalPower"); // LCQ;
	g_sLangTxt_Gradient_FOpticalPower = _T("光功率(-dbm)");

	g_sLangID_Gradient_FmFileName = _T("Gradient_FmFileName"); // LCQ;
	g_sLangTxt_Gradient_FmFileName = _T("文件名称：");

	g_sLangID_Gradient_DirectoryFile = _T("Gradient_DirectoryFile"); // LCQ;
	g_sLangTxt_Gradient_DirectoryFile = _T("文件目录：");

	g_sLangID_Gradient_SecondaryIPSet = _T("Gradient_SecondaryIPSet"); // LCQ;
	g_sLangTxt_Gradient_SecondaryIPSet = _T("辅助IP设置");

	g_sLangID_Gradient_IPInputInvalid = _T("Gradient_IPInputInvalid"); // LCQ;
	g_sLangTxt_Gradient_IPInputInvalid = _T("IP输入不合法");

	g_sLangID_Gradient_VAOnceValue = _T("Gradient_VAOnceValue"); // LCQ;
	g_sLangTxt_Gradient_VAOnceValue = _T("一次值(V/A)");

	g_sLangID_Gradient_VATwiceValue = _T("Gradient_VATwiceValue"); // LCQ;
	g_sLangTxt_Gradient_VATwiceValue = _T("二次值(V/A)");

	g_sLangID_Gradient_SameThreep = _T("Gradient_SameThreep"); // LCQ;
	g_sLangTxt_Gradient_SameThreep = _T("三相相同");

	g_sLangID_Gradient_AllSamep = _T("Gradient_AllSamep"); // LCQ;
	g_sLangTxt_Gradient_AllSamep = _T("全部相同");

	g_sLangID_Gradient_DPhase = _T("Gradient_DPhase"); // LCQ;
	g_sLangTxt_Gradient_DPhase = _T("相位(°)");

	g_sLangID_Gradient_FRelCurempty = _T("Gradient_FRelCurempty"); // LCQ;
	g_sLangTxt_Gradient_FRelCurempty = _T("当前状态(%d)的FT3发布数据为空(出现异常).");

	g_sLangID_Gradient_EmptyCurTI = _T("Gradient_EmptyCurTI"); // LCQ;
	g_sLangTxt_Gradient_EmptyCurTI = _T("当前测试项为空.");

	g_sLangID_Gradient_ClosePerTBF = _T("Gradient_ClosePerTBF"); // LCQ;
	g_sLangTxt_Gradient_ClosePerTBF = _T("请先关闭网页界面,才能执行工具栏按钮功能.");

	g_sLangID_Gradient_WaitSASD = _T("Gradient_WaitSASD"); // LCQ;
	g_sLangTxt_Gradient_WaitSASD = _T("等待测试服务停止后关闭.");

	g_sLangID_Gradient_INUnSavescreen = _T("Gradient_INUnSavescreen"); // LCQ;
	g_sLangTxt_Gradient_INUnSavescreen = _T("保存截屏(%s)(isNull)失败.");

	g_sLangID_Gradient_UnSavescreen = _T("Gradient_UnSavescreen"); // LCQ;
	g_sLangTxt_Gradient_UnSavescreen = _T("保存截屏(%s)(save)失败.");

	g_sLangID_Gradient_Savescreen = _T("Gradient_Savescreen"); // LCQ;
	g_sLangTxt_Gradient_Savescreen = _T("保存截屏(%s)成功.");

	g_sLangID_Gradient_Selectleg = _T("Gradient_Selectleg"); // LCQ;
	g_sLangTxt_Gradient_Selectleg = _T("请在测试项目树形控件中选择合法的项目分类");

	g_sLangID_Gradient_CLoseMMChanges = _T("Gradient_CLoseMMChanges"); // LCQ;
	g_sLangTxt_Gradient_CLoseMMChanges = _T("?????????????? OnCmd_NewTest: 关闭打开的测试功能页面，并弹框提示是否保存修改 ???????????");

	g_sLangID_Gradient_TemplateErr = _T("Gradient_TemplateErr"); // LCQ;
	g_sLangTxt_Gradient_TemplateErr = _T("模板错误！找不到rootnode节点对应的功能界面【%s】");

	g_sLangID_Gradient_SaveTemplateAs = _T("Gradient_SaveTemplateAs"); // LCQ;
	g_sLangTxt_Gradient_SaveTemplateAs = _T("模板另存为");

	g_sLangID_Gradient_OpenfileFail = _T("Gradient_OpenfileFail"); // LCQ;
	g_sLangTxt_Gradient_OpenfileFail = _T("打开文件失败");

	g_sLangID_Gradient_SendComplete = _T("Gradient_SendComplete"); // LCQ;
	g_sLangTxt_Gradient_SendComplete = _T("发送完成");

	g_sLangID_Gradient_RecvChannel = _T("Gradient_RecvChannel"); // LCQ;
	g_sLangTxt_Gradient_RecvChannel = _T("接收通道设置");

	g_sLangID_Gradient_RatioPCT = _T("Gradient_RatioPCT"); // LCQ;
	g_sLangTxt_Gradient_RatioPCT = _T("PT/CT变比");

	g_sLangID_Gradient_ControlB = _T("Gradient_ControlB"); // LCQ;
	g_sLangTxt_Gradient_ControlB = _T("请选择控制块");

	g_sLangID_Gradient_RecvChannnel = _T("Gradient_RecvChannnel"); // LCQ;
	g_sLangTxt_Gradient_RecvChannnel = _T("接收通道");

	g_sLangID_Gradient_ResTimeErr = _T("Gradient_ResTimeErr"); // LCQ;
	g_sLangTxt_Gradient_ResTimeErr = _T("响应时间误差");

	g_sLangID_Gradient_MessResTime = _T("Gradient_MessResTime"); // LCQ;
	g_sLangTxt_Gradient_MessResTime = _T("报文响应时间");

	g_sLangID_Gradient_ChaDelay = _T("Gradient_ChaDelay"); // LCQ;
	g_sLangTxt_Gradient_ChaDelay = _T("通道延时");

	g_sLangID_Gradient_MergeUint = _T("Gradient_MergeUint"); // LCQ;
	g_sLangTxt_Gradient_MergeUint = _T("合并单元测试功能ID()在配置文件中未查找到.");

	g_sLangID_Gradient_NAbnormalRes = _T("Gradient_NAbnormalRes"); // LCQ;
	g_sLangTxt_Gradient_NAbnormalRes = _T("当前选择测试功能异常(%s),导致m_pSttIecRcdFuncInterface==NULL.");

	g_sLangID_Gradient_TestDuration = _T("Gradient_TestDuration"); // LCQ;
	g_sLangTxt_Gradient_TestDuration = _T("测试时长(s):");

	g_sLangID_Gradient_TheCurDelay = _T("Gradient_TheCurDelay"); // LCQ;
	g_sLangTxt_Gradient_TheCurDelay = _T("当前延时数据为空,清空时间精度结果失败.");

	g_sLangID_Gradient_EmptyRes = _T("Gradient_EmptyRes"); // LCQ;
	g_sLangTxt_Gradient_EmptyRes = _T("清空时间精度结果成功.");

	g_sLangID_Gradient_DiffRatio = _T("Gradient_DiffRatio"); // LCQ;
	g_sLangTxt_Gradient_DiffRatio = _T("比差(%)");

	g_sLangID_Gradient_CurNullFa = _T("Gradient_CurNullFa"); // LCQ;
	g_sLangTxt_Gradient_CurNullFa = _T("当前数据集为空,清空误差统计结果失败.");

	g_sLangID_Gradient_ZeroDrift = _T("Gradient_ZeroDrift"); // LCQ;
	g_sLangTxt_Gradient_ZeroDrift = _T("零漂");

	g_sLangID_Gradient_ValueOutP = _T("Gradient_ValueOutP"); // LCQ;
	g_sLangTxt_Gradient_ValueOutP = _T("输出值");

	g_sLangID_Gradient_PhaseOutP = _T("Gradient_PhaseOutP "); // LCQ;
	g_sLangTxt_Gradient_PhaseOutP = _T("输出相位");

	g_sLangID_Gradient_MeasurAmp = _T("Gradient_MeasurAmp"); // LCQ;
	g_sLangTxt_Gradient_MeasurAmp = _T("实测幅值");

	g_sLangID_Gradient_ChanDelay = _T("Gradient_ChanDelay"); // LCQ;
	g_sLangTxt_Gradient_ChanDelay = _T("通道延时");

	g_sLangID_Gradient_CompError = _T("Gradient_CompError"); // LCQ;
	g_sLangTxt_Gradient_CompError = _T("复合误差");

	g_sLangID_Gradient_MeaPhase = _T("Gradient_MeaPhase"); // LCQ;
	g_sLangTxt_Gradient_MeaPhase = _T("实测相位");

	g_sLangID_Gradient_FrequencyDiff = _T("Gradient_FrequencyDiff"); // LCQ;
	g_sLangTxt_Gradient_FrequencyDiff = _T("频差");

	g_sLangID_Gradient_DetectMessageI = _T("Gradient_DetectMessageI"); // LCQ;
	g_sLangTxt_Gradient_DetectMessageI = _T("报文探测界面");

	g_sLangID_Gradient_Unrecorded = _T("Gradient_Unrecorded"); // LCQ;
	g_sLangTxt_Gradient_Unrecorded = _T("未录波");

	g_sLangID_Gradient_Appscribed = _T("Gradient_Appscribed"); // LCQ;
	g_sLangTxt_Gradient_Appscribed = _T("GOOSE控制块(AppID=0X%04X),已添加订阅到光口%ld,无需重复添加.");

	g_sLangID_Gradient_SEcontrolSus = _T("Gradient_SEcontrolSus"); // LCQ;
	g_sLangTxt_Gradient_SEcontrolSus = _T("GOOSE控制块(AppID=0X%04X),添加订阅到光口%ld成功.");

	g_sLangID_Gradient_AppscribedFa = _T("Gradient_AppscribedFa"); // LCQ;
	g_sLangTxt_Gradient_AppscribedFa = _T("GOOSE控制块(AppID=0X%04X),已添加发布到光口%ld,无需重复添加.");

	g_sLangID_Gradient_AppFascribedFa = _T("Gradient_AppFascribedFa"); // LCQ;
	g_sLangTxt_Gradient_AppFascribedFa = _T("GOOSE控制块(AppID=0X%04X),添加发布到光口%ld成功.");

	g_sLangID_Gradient_ModifyTip = _T("Gradient_ModifyTip"); // LCQ;
	g_sLangTxt_Gradient_ModifyTip = _T("修改接线提示");

	g_sLangID_Gradient_WiringTip = _T("Gradient_WiringTip"); // LCQ;
	g_sLangTxt_Gradient_WiringTip = _T("接线提示");

	g_sLangID_Gradient_WirPrompt = _T("Gradient_WirPrompt"); // LCQ;
	g_sLangTxt_Gradient_WirPrompt = _T("新建接线提示");

	g_sLangID_Gradient_EnterTips = _T("Gradient_EnterTips"); // LCQ;
	g_sLangTxt_Gradient_EnterTips = _T("请在此处输入接线提示信息……");

	g_sLangID_Gradient_ClickCTest = _T("Gradient_ClickCTest"); // LCQ;
	g_sLangTxt_Gradient_ClickCTest = _T("请按照接线提示信息，完成接线后，点击“完成接线”按钮，继续测试……");

	g_sLangID_Gradient_CompleteWir = _T("Gradient_CompleteWir"); // LCQ;
	g_sLangTxt_Gradient_CompleteWir = _T("完成接线");

	g_sLangID_Gradient_WirpromptExit = _T("Gradient_WirpromptExit"); // LCQ;
	g_sLangTxt_Gradient_WirpromptExit = _T("存在相同名称的接线提示");

	g_sLangID_Gradient_WEditNoChange = _T("Gradient_WEditNoChange"); // LCQ;
	g_sLangTxt_Gradient_WEditNoChange = _T("接线提示信息编辑，未检测到内容发生变化……");

	g_sLangID_Gradient_WrongWayrun = _T("Gradient_WrongWayrun"); // LCQ;
	g_sLangTxt_Gradient_WrongWayrun = _T("错误的运行方式！");

	g_sLangID_Gradient_VarType = _T("Gradient_VarType");
	g_sLangTxt_Gradient_VarType = _T("变量类型");
	g_sLangID_Gradient_Phase = _T("Gradient_Phase");
	g_sLangTxt_Gradient_Phase = _T("相位差");
	g_sLangID_Gradient_VarSet = _T("Gradient_VarSet");
	g_sLangTxt_Gradient_VarSet = _T("变量设置");
	g_sLangID_Gradient_ChangingSet = _T("Gradient_ChangingSet");
	g_sLangTxt_Gradient_ChangingSet = _T("递变参数设置");
	g_sLangID_Gradient_UnChangingSet = _T("Gradient_UnChangingSet");
	g_sLangTxt_Gradient_UnChangingSet = _T("非递变通道设置");
	g_sLangID_Gradient_OtherSet = _T("Gradient_OtherSet");
	g_sLangTxt_Gradient_OtherSet = _T("其他参数");
	g_sLangID_Gradient_TestResult = _T("Gradient_TestResult");
	g_sLangTxt_Gradient_TestResult = _T("测试结果");
	g_sLangID_Gradient_Init = _T("Gradient_Init");
	g_sLangTxt_Gradient_Init = _T("变化始值");
	g_sLangID_Gradient_Finish = _T("Gradient_Finish");
	g_sLangTxt_Gradient_Finish = _T("变化终值");
	g_sLangID_Gradient_Step = _T("Gradient_Step");
	g_sLangTxt_Gradient_Step = _T("变化步长");
	g_sLangID_Gradient_Time = _T("Gradient_Time");
	g_sLangTxt_Gradient_Time = _T("故障时间");
	g_sLangID_Gradient_Direction = _T("Gradient_Direction");
	g_sLangTxt_Gradient_Direction = _T("递变方向");
	g_sLangID_Gradient_MaxAngle = _T("Gradient_MaxAngle");
	g_sLangTxt_Gradient_MaxAngle = _T("最大灵敏角");
	g_sLangID_Gradient_Clockwise = _T("Gradient_Clockwise");
	g_sLangTxt_Gradient_Clockwise = _T("顺时针");
	g_sLangID_Gradient_Anticlockwise = _T("Gradient_Anticlockwise");
	g_sLangTxt_Gradient_Anticlockwise = _T("逆时针");
	g_sLangID_Gradient_AllFreq = _T("Gradient_AllFreq");
	g_sLangTxt_Gradient_AllFreq = _T("全部频率");
	g_sLangID_Gradient_TimeBeforeChange = _T("Gradient_TimeBeforeChange");
	g_sLangTxt_Gradient_TimeBeforeChange = _T("变化前时间");
	g_sLangID_Gradient_TimeBeforeFail = _T("Gradient_TimeBeforeFail");
	g_sLangTxt_Gradient_TimeBeforeFail = _T("脉冲递变复归时间");
	g_sLangID_Gradient_CurBeforeChange = _T("Gradient_CurBeforeChange");
	g_sLangTxt_Gradient_CurBeforeChange = _T("变化前电流");
	g_sLangID_Gradient_Normal = _T("Gradient_Normal");
	g_sLangTxt_Gradient_Normal = _T("正常态");
	g_sLangID_Gradient_Failure = _T("Gradient_Failure");
	g_sLangTxt_Gradient_Failure = _T("故障态");
	g_sLangID_Gradient_ParaSet = _T("Gradient_ParaSet");
	g_sLangTxt_Gradient_ParaSet = _T("参数设置");
	g_sLangID_Gradient_BoutSet = _T("Gradient_BoutSet"); // 开出量设置
	g_sLangTxt_Gradient_BoutSet = _T("开出量设置");
	g_sLangID_Gradient_BoutSets = _T("Gradient_BoutSets"); // 更多开出量设置
	g_sLangTxt_Gradient_BoutSets = _T("更多开出量设置");
	g_sLangID_Report_TestChoose = _T("Report_TestChoose");
	g_sLangTxt_Report_TestChoose = _T("内容选择");
	g_sLangID_Report_TestObjInf = _T("Report_TestObjInf");
	g_sLangTxt_Report_TestObjInf = _T("测试对象信息");
	g_sLangID_Report_SubInformation = _T("Report_SubInformation");
	g_sLangTxt_Report_SubInformation = _T("变电站信息");
	g_sLangID_Report_SubName = _T("Report_SubName");
	g_sLangTxt_Report_SubName = _T("变电站名称");
	g_sLangID_Report_SubAddr = _T("Report_SubAddr");
	g_sLangTxt_Report_SubAddr = _T("变电站地址");
	g_sLangID_Report_LoopName = _T("Report_LoopName");
	g_sLangTxt_Report_LoopName = _T("回路名称");
	g_sLangID_Report_LoopAddr = _T("Report_LoopAddr");
	g_sLangTxt_Report_LoopAddr = _T("回路地址");
	g_sLangID_Report_Tester = _T("Report_Tester");
	g_sLangTxt_Report_Tester = _T("测试人员");
	g_sLangID_Report_ReportTitle = _T("Report_ReportTitle");
	g_sLangTxt_Report_ReportTitle = _T("报告标题");
	g_sLangID_Report_DeviceInfor = _T("Report_DeviceInfor");
	g_sLangTxt_Report_DeviceInfor = _T("装置信息");
	g_sLangID_Report_DeviceName = _T("Report_DeviceName");
	g_sLangTxt_Report_DeviceName = _T("装置名称");
	g_sLangID_Report_DeviceModel = _T("Report_DeviceModel");
	g_sLangTxt_Report_DeviceModel = _T("装置型号");
	g_sLangID_Report_DeviceAddr = _T("Report_DeviceAddr");
	g_sLangTxt_Report_DeviceAddr = _T("装置地址");
	g_sLangID_Report_DeviceFactory = _T("Report_DeviceFactory");
	g_sLangTxt_Report_DeviceFactory = _T("生产厂家");

	g_sLangID_Report_SettingsNO = _T("Report_SettingsNO");
	g_sLangTxt_Report_SettingsNO = _T("定制单编号");
	g_sLangID_Report_AdditionalInf = _T("Report_AdditionalInf");
	g_sLangTxt_Report_AdditionalInf = _T("附加信息");
	g_sLangID_Report_RatedValue = _T("Report_RatedValue");
	g_sLangTxt_Report_RatedValue = _T("额定值");
	g_sLangID_Report_DUTs = _T("Report_DUTs");
	g_sLangTxt_Report_DUTs = _T("被测装置");
	g_sLangID_Report_Title = _T("Report_Title");
	g_sLangTxt_Report_Title = _T("报告内容与格式");

	g_sLangID_Report_Vnom = _T("Report_Vnom");
	g_sLangTxt_Report_Vnom = _T("额定电压");
	g_sLangID_Report_Vdc = _T("Report_Vdc");
	g_sLangTxt_Report_Vdc = _T("辅助直流");
	g_sLangID_Report_SureTime = _T("Report_SureTime");
	g_sLangTxt_Report_SureTime = _T("开入防抖时间");
	g_sLangID_Report_AntiShakeTime = _T("Report_AntiShakeTime");
	g_sLangTxt_Report_AntiShakeTime = _T("防抖时间");
	g_sLangID_Report_Vprim = _T("Report_Vprim");
	g_sLangTxt_Report_Vprim = _T("一次侧电压");
	g_sLangID_Report_Fnom = _T("Report_Fnom");
	g_sLangTxt_Report_Fnom = _T("额定频率");
	g_sLangID_Report_Iprim = _T("Report_Iprim");
	g_sLangTxt_Report_Iprim = _T("一次侧电流");
	g_sLangID_Report_TestAppInfor = _T("Report_TestAppInfor");
	g_sLangTxt_Report_TestAppInfor = _T("测试设备信息");
	g_sLangID_Report_AppModel = _T("Report_AppModel");
	g_sLangTxt_Report_AppModel = _T("型号");
	g_sLangID_Report_Imax = _T("Report_Imax");
	g_sLangTxt_Report_Imax = _T("电流最大值");
	g_sLangID_Report_AppSN = _T("Report_AppSN");
	g_sLangTxt_Report_AppSN = _T("序列号");
	g_sLangID_Report_TestStartTime = _T("Report_TestStartTime");
	g_sLangTxt_Report_TestStartTime = _T("测试开始时间");
	g_sLangID_Report_ComPortType = _T("Report_ComPortType");
	g_sLangTxt_Report_ComPortType = _T("通讯口类型");
	g_sLangID_Report_TestEndTime = _T("Report_TestEndTime");
	g_sLangTxt_Report_TestEndTime = _T("测试终止时间");
	g_sLangID_Report_Vmax = _T("Report_Vmax");
	g_sLangTxt_Report_Vmax = _T("电压最大值");

	g_sLangID_ChMaps_AnalogCh = _T("ChMaps_AnalogCh");
	g_sLangTxt_ChMaps_AnalogCh = _T("模拟量通道");
	g_sLangID_ChMaps_DigitalCh = _T("ChMaps_DigitalCh");
	g_sLangTxt_ChMaps_DigitalCh = _T("数字量通道");
	g_sLangID_ChMaps_WeekCh = _T("ChMaps_WeekCh");
	g_sLangTxt_ChMaps_WeekCh = _T("弱信号通道");
	g_sLangID_ChMaps_Analog = _T("ChMaps_Analog");
	g_sLangTxt_ChMaps_Analog = _T("模拟");
	g_sLangID_ChMaps_Digital = _T("ChMaps_Digital");
	g_sLangTxt_ChMaps_Digital = _T("数字");
	g_sLangID_ChMaps_Week = _T("ChMaps_Week");
	g_sLangTxt_ChMaps_Week = _T("弱信号");
	g_sLangID_ChMaps_Title = _T("ChMaps_Title");
	g_sLangTxt_ChMaps_Title = _T("通道映射设置");
	g_sLangID_ChMaps_OutputSel = _T("ChMaps_OutputSel");
	g_sLangTxt_ChMaps_OutputSel = _T("输出类型选择");
	g_sLangID_ChMaps_DigitalType = _T("ChMaps_DigitalType");
	g_sLangTxt_ChMaps_DigitalType = _T("数字报文类型");
	g_sLangID_ChMaps_DefautMaps = _T("ChMaps_DefautMaps");
	g_sLangTxt_ChMaps_DefautMaps = _T("设置缺省映射");
	g_sLangID_ChMaps_ImportChMaps = _T("ChMaps_ImportChMaps");
	g_sLangTxt_ChMaps_ImportChMaps = _T("导入通道映射");
	g_sLangID_ChMaps_ExportChMaps = _T("ChMaps_ExportChMaps");
	g_sLangTxt_ChMaps_ExportChMaps = _T("导出通道映射");
	g_sLangID_ChMaps_LockMaps = _T("ChMaps_LockMaps");
	g_sLangTxt_ChMaps_LockMaps = _T("锁定映射");

	g_sLangID_ChMaps_MeasSel = _T("ChMaps_MeasSel");
	g_sLangTxt_ChMaps_MeasSel = _T("采集类型选择");
	g_sLangID_ChMaps_DigitalMeasType = _T("ChMaps_DigitalMeasType");
	g_sLangTxt_ChMaps_DigitalMeasType = _T("采集报文类型");

	g_sLangID_IEC_SysParasSet = _T("IEC_SysParasSet");
	g_sLangTxt_IEC_SysParasSet = _T("系统参数设置");
	g_sLangID_IEC_SysParasConfig = _T("IEC_SysParasConfig");
	g_sLangTxt_IEC_SysParasConfig = _T("系统参数配置");
	g_sLangID_IEC_IEC_WeakSet = _T("IEC_IEC_WeakSet");
	g_sLangTxt_IEC_IEC_WeakSet = _T("弱信号设置");
	g_sLangID_IEC_Message = _T("IEC_Message");
	g_sLangTxt_IEC_Message = _T("IEC61850-9-2报文");
	g_sLangID_IEC_Publish = _T("IEC_Publish");
	g_sLangTxt_IEC_Publish = _T("GOOSE发布");
	g_sLangID_IEC_Subscription = _T("IEC_Subscription");
	g_sLangTxt_IEC_Subscription = _T("GOOSE订阅");
	g_sLangID_IEC_OpenConfig = _T("IEC_OpenConfig");
	g_sLangTxt_IEC_OpenConfig = _T("打开配置");
	g_sLangID_IEC_OpenConfigFile = _T("IEC_OpenConfigFile");
	g_sLangTxt_IEC_OpenConfigFile = _T("打开配置文件");
	g_sLangID_IEC_ConfigSaveAs = _T("IEC_ConfigSaveAs");
	g_sLangTxt_IEC_ConfigSaveAs = _T("配置另存");
	g_sLangID_IEC_ConfigFileSaveAs = _T("IEC_ConfigFileSaveAs");
	g_sLangTxt_IEC_ConfigFileSaveAs = _T("配置文件另存为");
	g_sLangID_IEC_ImportSCL = _T("IEC_ImportSCL");
	g_sLangTxt_IEC_ImportSCL = _T("导入SCL");
	g_sLangID_IEC_ImportSCLFile = _T("IEC_ImportSCLFile");
	g_sLangTxt_IEC_ImportSCLFile = _T("导入SCL文件");
	g_sLangID_IEC_SaveDatas = _T("IEC_SaveDatas");
	g_sLangTxt_IEC_SaveDatas = _T("保存数据");
	g_sLangID_IEC_DeleteAllButFirst = _T("IEC_DeleteAllButFirst");
	g_sLangTxt_IEC_DeleteAllButFirst = _T("删除N-1");

	g_sLangID_IEC_Protectcurrent = _T("IEC_Protectcurrent");
	g_sLangTxt_IEC_Protectcurrent = _T("保护电流");
	g_sLangID_IEC_ChEdit = _T("IEC_ChEdit");
	g_sLangTxt_IEC_ChEdit = _T("通道编辑");
	g_sLangID_IEC_T1Times = _T("IEC_T1Times");
	g_sLangTxt_IEC_T1Times = _T("T1时间(ms)");
	g_sLangID_IEC_T0Times = _T("IEC_T0Times");
	g_sLangTxt_IEC_T0Times = _T("T0时间(ms)");
	g_sLangID_IEC_TimeQuality = _T("IEC_TimeQuality");
	g_sLangTxt_IEC_TimeQuality = _T("时间品质");
	g_sLangID_IEC_GroupDelay = _T("IEC_GroupDelay");
	g_sLangTxt_IEC_GroupDelay = _T("组间延时(ms)");
	g_sLangID_IEC_Details = _T("IEC_Details");
	g_sLangTxt_IEC_Details = _T("详细设置");
	g_sLangID_IEC_SmpByteNum = _T("IEC_SmpByteNum");
	g_sLangTxt_IEC_SmpByteNum = _T("采样位宽");
	g_sLangID_IEC_SmpCntType = _T("IEC_SmpCntType");
	g_sLangTxt_IEC_SmpCntType = _T("采样方式");
	g_sLangID_IEC_RatedDelay = _T("IEC_RatedDelay");
	g_sLangTxt_IEC_RatedDelay = _T("额定延时(us)");
	g_sLangID_IEC_SetRecordParas = _T("IEC_SetRecordParas");
	g_sLangTxt_IEC_SetRecordParas = _T("报文参数设置");
	g_sLangID_IEC_DcVolCodeValue = _T("IEC_DcVolCodeValue");
	g_sLangTxt_IEC_DcVolCodeValue = _T("直流电压码值");
	g_sLangID_IEC_AcVolCodeValue = _T("IEC_AcVolCodeValue");
	g_sLangTxt_IEC_AcVolCodeValue = _T("交流电压码值");
	g_sLangID_IEC_DcCurCodeValue = _T("IEC_DcCurCodeValue");
	g_sLangTxt_IEC_DcCurCodeValue = _T("直流电流码值");
	g_sLangID_IEC_PrimtRatedVol = _T("IEC_PrimtRatedVol");
	g_sLangTxt_IEC_PrimtRatedVol = _T("一次额定电压(kV)");
	g_sLangID_IEC_PrimtRatedCur = _T("IEC_PrimtRatedCur");
	g_sLangTxt_IEC_PrimtRatedCur = _T("一次额定电流(A)");
	g_sLangID_IEC_DcNeutralVolCodeValue = _T("IEC_DcNeutralVolCodeValue");
	g_sLangTxt_IEC_DcNeutralVolCodeValue = _T("中性母线电压码值");
	g_sLangID_IEC_AcProtCurCodeValue = _T("IEC_AcProtCurCodeValue");
	g_sLangTxt_IEC_AcProtCurCodeValue = _T("交流保护电流码值");
	g_sLangID_IEC_AcMeasCurCodeValue = _T("IEC_AcMeasCurCodeValue");
	g_sLangTxt_IEC_AcMeasCurCodeValue = _T("交流测量电流码值");

	g_sLangID_IEC_FT3PublishParameterSet = _T("IEC_FT3PublishParameterSet");
	g_sLangTxt_IEC_FT3PublishParameterSet = _T("FT3发布参数设置");
	g_sLangID_IEC_FT3MapParameterSet = _T("IEC_FT3MapParameterSet");
	g_sLangTxt_IEC_FT3MapParameterSet = _T("FT3映射参数设置");
	g_sLangID_IEC_SamplingRate = _T("IEC_SamplingRate");
	g_sLangTxt_IEC_SamplingRate = _T("采样率");
	g_sLangID_IEC_BaudRate = _T("IEC_BaudRate");
	g_sLangTxt_IEC_BaudRate = _T("波特率");
	g_sLangID_IEC_KeepSendAfterStop = _T("IEC_KeepSendAfterStop");
	g_sLangTxt_IEC_KeepSendAfterStop = _T("停止后保持发送");
	g_sLangID_IEC_StopSending = _T("IEC_StopSending");
	g_sLangTxt_IEC_StopSending = _T("停止后终止发送");
	g_sLangID_IEC_PacketSendingMode = _T("IEC_PacketSendingMode");
	g_sLangTxt_IEC_PacketSendingMode = _T("报文发送方式：");
	g_sLangID_IEC_PTRatio = _T("IEC_PTRatio");
	g_sLangTxt_IEC_PTRatio = _T("PT变比：");
	g_sLangID_IEC_CTRatio = _T("IEC_CTRatio");
	g_sLangTxt_IEC_CTRatio = _T("CT变比：");
	g_sLangID_IEC_SMVCh = _T("IEC_SMVCh");
	g_sLangTxt_IEC_SMVCh = _T("SMV通道");
	g_sLangID_IEC_ChByteLen = _T("IEC_ChByteLen");
	g_sLangTxt_IEC_ChByteLen = _T("字节长度");
	g_sLangID_IEC_ChDescription = _T("IEC_ChDescription");
	g_sLangTxt_IEC_ChDescription = _T("通道描述");
	g_sLangID_IEC_ChType = _T("IEC_ChType");
	g_sLangTxt_IEC_ChType = _T("通道类型");
	g_sLangID_IEC_DIMap = _T("IEC_DIMap");
	g_sLangTxt_IEC_DIMap = _T("开入映射");
	g_sLangID_IEC_SetRepair = _T("IEC_SetRepair");
	g_sLangTxt_IEC_SetRepair = _T("投检修");
	g_sLangID_IEC_UnSetRepair = _T("IEC_UnSetRepair");
	g_sLangTxt_IEC_UnSetRepair = _T("不投检修");
	g_sLangID_IEC_IMap = _T("IEC_IMap");
	g_sLangTxt_IEC_IMap = _T("电流映射:");
	g_sLangID_IEC_UMap = _T("IEC_UMap");
	g_sLangTxt_IEC_UMap = _T("电压映射:");
	g_sLangID_IEC_SetInitValue = _T("IEC_SetInitValue");
	g_sLangTxt_IEC_SetInitValue = _T("初值设置");
	g_sLangID_IEC_Choose = _T("IEC_Choose");
	g_sLangTxt_IEC_Choose = _T("选择:");
	g_sLangID_IEC_Sendratio = _T("IEC_Sendratio");
	g_sLangTxt_IEC_Sendratio = _T("发送变比设置");
	g_sLangID_IEC_Opticalport = _T("IEC_Opticalport");
	g_sLangTxt_IEC_Opticalport = _T("光口设置");
	g_sLangID_IEC_FiberInSet = _T("IEC_FiberInSet");
	g_sLangTxt_IEC_FiberInSet = _T("接收光口设置");
	g_sLangID_IEC_FiberOutSet = _T("IEC_FiberOutSet");
	g_sLangTxt_IEC_FiberOutSet = _T("输出光口设置");

	g_sLangID_IEC_Target = _T("IEC_Target");
	g_sLangTxt_IEC_Target = _T("目标MAC地址");
	g_sLangID_IEC_Entrance = _T("IEC_Entrance");
	g_sLangTxt_IEC_Entrance = _T("输入口选择");
	g_sLangID_IEC_ChannelNumber = _T("IEC_ChannelNumber");
	g_sLangTxt_IEC_ChannelNumber = _T("通道数");
	g_sLangID_IEC_Version = _T("IEC_Version");
	g_sLangTxt_IEC_Version = _T("版本号");
	g_sLangID_IEC_Test = _T("IEC_Test");
	g_sLangTxt_IEC_Test = _T("测试(Test)");
	g_sLangID_IEC_LifeTime = _T("IEC_LifeTime");
	g_sLangTxt_IEC_LifeTime = _T("允许生存时间(ms)");
	g_sLangID_IEC_UnParse = _T("IEC_ParseGoCB_GoID_Dataset");
	g_sLangTxt_IEC_UnParse = _T("解析GoCB,GoID,Dataset");
	g_sLangID_IEC_ChMaps = _T("IEC_ChMaps");
	g_sLangTxt_IEC_ChMaps = _T("通道映射");
	g_sLangID_IEC_InitValue = _T("IEC_InitValue");
	g_sLangTxt_IEC_InitValue = _T("初始值");
	g_sLangID_IEC_InputMap = _T("IEC_InputMap");
	g_sLangTxt_IEC_InputMap = _T("开入量映射");
	g_sLangID_IEC_Source = _T("IEC_Source");
	g_sLangTxt_IEC_Source = _T("源MAC地址");
	g_sLangID_IEC_Intrance = _T("IEC_Intrance");
	g_sLangTxt_IEC_Intrance = _T("输出口选择");
	g_sLangID_IEC_Quality = _T("IEC_Quality");
	g_sLangTxt_IEC_Quality = _T("品质");
	g_sLangID_IEC_DescExternal = _T("IEC_DescExternal");
	g_sLangTxt_IEC_DescExternal = _T("外部通道描述");
	g_sLangID_IEC_Delay = _T("IEC_Delay");
	g_sLangTxt_IEC_Delay = _T("采样延时(μs)");
	g_sLangID_IEC_StartDelay = _T("IEC_StartDelay");
	g_sLangTxt_IEC_StartDelay = _T("开始过载延时(s):");
	g_sLangID_IEC_Synchronously = _T("IEC_Synchronously");
	g_sLangTxt_IEC_Synchronously = _T("同步方式");
	g_sLangID_IEC_ScaleFactor = _T("IEC_ScaleFactor");
	g_sLangTxt_IEC_ScaleFactor = _T("比例因子");
	g_sLangID_IEC_SetScaleFactor = _T("IEC_SetScaleFactor");
	g_sLangTxt_IEC_SetScaleFactor = _T("比例因子设置");
	g_sLangID_IEC_FMByte = _T("IEC_FMByte");
	g_sLangTxt_IEC_FMByte = _T("百兆口");
	g_sLangID_IEC_GMByte = _T("IEC_GMByte");
	g_sLangTxt_IEC_GMByte = _T("千兆口");
	g_sLangID_IEC_LCFI = _T("IEC_LCFI");
	g_sLangTxt_IEC_LCFI = _T("LC光口");
	g_sLangID_IEC_IRIGB = _T("IEC_IRIGB");
	g_sLangTxt_IEC_IRIGB = _T("B码");
	g_sLangID_IEC_STFI = _T("IEC_STFI");
	g_sLangTxt_IEC_STFI = _T("ST光口");
	g_sLangID_IEC_AccuratyLevel = _T("IEC_AccuratyLevel");
	g_sLangTxt_IEC_AccuratyLevel = _T("准确级");
	g_sLangID_IEC_Msg_OverWriteCtrl = _T("IEC_Msg_OverWriteCtrl");
	g_sLangTxt_IEC_Msg_OverWriteCtrl = _T("是否覆盖如下控制块?");

	g_sLangID_IEC_FI = _T("IEC_FI");
	g_sLangTxt_IEC_FI = _T("光口");
	g_sLangID_IEC_FIChoose = _T("IEC_FIChoose");
	g_sLangTxt_IEC_FIChoose = _T("光口选择");
	g_sLangID_IEC_MACAddr = _T("IEC_MACAddr");
	g_sLangTxt_IEC_MACAddr = _T("MAC地址");
	g_sLangID_IEC_DataSetText = _T("IEC_DataSetText");
	g_sLangTxt_IEC_DataSetText = _T("数据集描述");
	g_sLangID_IEC_GOOSEIndex = _T("IEC_GOOSEIndex");
	g_sLangTxt_IEC_GOOSEIndex = _T("GOOSE控制块索引");
	g_sLangID_IEC_VlanPri = _T("IEC_VlanPri");
	g_sLangTxt_IEC_VlanPri = _T("Vlan优先级");
	g_sLangID_IEC_ConfigVersion = _T("IEC_ConfigVersion");
	g_sLangTxt_IEC_ConfigVersion = _T("配置版本");
	g_sLangID_IEC_ChAllNumber = _T("IEC_ChAllNumber");
	g_sLangTxt_IEC_ChAllNumber = _T("总通道数");
	g_sLangID_IEC_SubChNumber = _T("IEC_SubChNumber");
	g_sLangTxt_IEC_SubChNumber = _T("订阅通道数");
	g_sLangID_IEC_SubIED = _T("IEC_SubIED");
	g_sLangTxt_IEC_SubIED = _T("订阅IED");
	g_sLangID_IEC_ASDU = _T("IEC_ASDU");
	g_sLangTxt_IEC_ASDU = _T("ASDU数");
	g_sLangID_IEC_Find = _T("IEC_Find");
	g_sLangTxt_IEC_Find = _T("查找");
	g_sLangID_IEC_SMVPublish = _T("IEC_SMVPublish");
	g_sLangTxt_IEC_SMVPublish = _T("SMV发布");
	g_sLangID_IEC_SMVSubscription = _T("IEC_SMVSubscription");
	g_sLangTxt_IEC_SMVSubscription = _T("SMV订阅");
	g_sLangID_IEC_Configure = _T("IEC_Configure");
	g_sLangTxt_IEC_Configure = _T("一键配置");	
	g_sLangID_IEC_CancelConfigure = _T("IEC_CancelConfigure");
	g_sLangTxt_IEC_CancelConfigure = _T("取消一键配置");
	g_sLangID_IEC_IEDList = _T("IEC_IEDList");
	g_sLangTxt_IEC_IEDList = _T("IED列表");
	g_sLangID_IEC_QualityParaSet = _T("IEC_QualityParaSet");
	g_sLangTxt_IEC_QualityParaSet = _T("品质参数设置");
	g_sLangID_IEC_Validity = _T("IEC_Validity");
	g_sLangTxt_IEC_Validity = _T("有效[bit0-bit1]");
	g_sLangID_IEC_Overflow = _T("IEC_Overflow");
	g_sLangTxt_IEC_Overflow = _T("溢出[bit2]");
	g_sLangID_IEC_OutOfRange = _T("IEC_OutOfRange");
	g_sLangTxt_IEC_OutOfRange = _T("超值域[bit3]");
	g_sLangID_IEC_BadReference = _T("IEC_BadReference");
	g_sLangTxt_IEC_BadReference = _T("坏基准值[bit4]");
	g_sLangID_IEC_Oscillatory = _T("IEC_Oscillatory");
	g_sLangTxt_IEC_Oscillatory = _T("抖动[bit5]");
	g_sLangID_IEC_Failure = _T("IEC_Failure");
	g_sLangTxt_IEC_Failure = _T("故障[bit6]");
	g_sLangID_IEC_OldData = _T("IEC_OldData");
	g_sLangTxt_IEC_OldData = _T("旧数据[bit7]");
	g_sLangID_IEC_Inconsistent = _T("IEC_Inconsistent");
	g_sLangTxt_IEC_Inconsistent = _T("不一致[bit8]");
	g_sLangID_IEC_Inaccurate = _T("IEC_Inaccurate");
	g_sLangTxt_IEC_Inaccurate = _T("不精确[bit9]");
	g_sLangID_Channel_Source = _T("Channel_Source");
	g_sLangTxt_Channel_Source = _T("源[bit10]");
	g_sLangID_Channel_Test = _T("Channel_Test");
	g_sLangTxt_Channel_Test = _T("测试[bit11]");
	g_sLangID_IEC_Opb = _T("IEC_Opb");
	g_sLangTxt_IEC_Opb = _T("操作员闭锁[bit12]");
	g_sLangID_IEC_ModifyAllChs = _T("IEC_ModifyAllChs");
	g_sLangTxt_IEC_ModifyAllChs = _T("修改全部通道");
	g_sLangID_IEC_DirectSet = _T("IEC_DirectSet");
	g_sLangTxt_IEC_DirectSet = _T("直接设置");
	g_sLangID_IEC_good = _T("IEC_good");
	g_sLangTxt_IEC_good = _T("00:好");
	g_sLangID_IEC_invalid = _T("IEC_invalid");
	g_sLangTxt_IEC_invalid = _T("01:无效");
	g_sLangID_IEC_reserved = _T("IEC_reserved");
	g_sLangTxt_IEC_reserved = _T("10:保留");
	g_sLangID_IEC_questionable = _T("IEC_questionable");
	g_sLangTxt_IEC_questionable = _T("11:可疑");
	g_sLangID_IEC_nooverflow = _T("IEC_nooverflow");
	g_sLangTxt_IEC_nooverflow = _T("0:无溢出");
	g_sLangID_IEC_overflow = _T("IEC_overflow");
	g_sLangTxt_IEC_overflow = _T("1:溢出");
	g_sLangID_IEC_normal = _T("IEC_normal");
	g_sLangTxt_IEC_normal = _T("0:正常");
	g_sLangID_IEC_outofrange = _T("IEC_outofrange");
	g_sLangTxt_IEC_outofrange = _T("1:超值域");
	g_sLangID_IEC_badreference = _T("IEC_badreference");
	g_sLangTxt_IEC_badreference = _T("1:坏基准值");
	g_sLangID_IEC_noOscillatory = _T("IEC_noOscillatory");
	g_sLangTxt_IEC_noOscillatory = _T("0:无抖动");
	g_sLangID_IEC_oscillatory = _T("IEC_oscillatory");
	g_sLangTxt_IEC_oscillatory = _T("1:有抖动");
	g_sLangID_IEC_nofailure = _T("IEC_nofailure");
	g_sLangTxt_IEC_nofailure = _T("0:无故障");
	g_sLangID_IEC_failure = _T("IEC_failure");
	g_sLangTxt_IEC_failure = _T("1:有故障");
	g_sLangID_IEC_noovertime = _T("IEC_noovertime");
	g_sLangTxt_IEC_noovertime = _T("0:无超时");
	g_sLangID_IEC_overtime = _T("IEC_overtime");
	g_sLangTxt_IEC_overtime = _T("1:数据超时");
	g_sLangID_IEC_noinconsistent = _T("IEC_noinconsistent");
	g_sLangTxt_IEC_noinconsistent = _T("0:一致");
	g_sLangID_IEC_inconsistent = _T("IEC_inconsistent");
	g_sLangTxt_IEC_inconsistent = _T("1:不一致");
	g_sLangID_IEC_accurate = _T("IEC_accurate");
	g_sLangTxt_IEC_accurate = _T("0:精确");
	g_sLangID_IEC_inaccurate = _T("IEC_inaccurate");
	g_sLangTxt_IEC_inaccurate = _T("1:不精确");
	g_sLangID_IEC_process = _T("IEC_process");
	g_sLangTxt_IEC_process = _T("0:过程");
	g_sLangID_IEC_substituted = _T("IEC_substituted");
	g_sLangTxt_IEC_substituted = _T("1:被取代");
	g_sLangID_IEC_run = _T("IEC_run");
	g_sLangTxt_IEC_run = _T("0:运行");
	g_sLangID_IEC_test = _T("IEC_test");
	g_sLangTxt_IEC_test = _T("1:测试");
	g_sLangID_IEC_nolock = _T("IEC_nolock");
	g_sLangTxt_IEC_nolock = _T("0:不闭锁");
	g_sLangID_IEC_lock = _T("IEC_lock");
	g_sLangTxt_IEC_lock = _T("1:闭锁");

	g_sLangID_IEC_IEDselect = _T("IEC_IEDselect");
	g_sLangTxt_IEC_IEDselect = _T("IED选择");

	g_sLangID_IEC_ImportIecfg = _T("IEC_ImportIecfg");
	g_sLangTxt_IEC_ImportIecfg = _T("导入配置");
	g_sLangID_IEC_Detect = _T("IEC_Detect");
	g_sLangTxt_IEC_Detect = _T("开始探测");
	g_sLangID_IEC_DetectStop = _T("IEC_DetectStop");
	g_sLangTxt_IEC_DetectStop = _T("停止探测");
	g_sLangID_IEC_Clear = _T("IEC_Clear");
	g_sLangTxt_IEC_Clear = _T("清空列表");
	g_sLangID_IEC_BeginRecord = _T("IEC_BeginRecord");
	g_sLangTxt_IEC_BeginRecord = _T("进入监视");
	g_sLangID_IEC_UseSmv = _T("IEC_UseSmv");
	g_sLangTxt_IEC_UseSmv = _T("显示Smv");
	g_sLangID_IEC_UseGoose = _T("IEC_UseGoose");
	g_sLangTxt_IEC_UseGoose = _T("显示Goose");
	g_sLangID_IEC_SmvFirstIsTime = _T("IEC_SmvFirstIsTime");
	g_sLangTxt_IEC_SmvFirstIsTime = _T("SMV第1通道为延时");
	g_sLangID_IEC_WriteDetectPkg = _T("IEC_WriteDetectPkg");
	g_sLangTxt_IEC_WriteDetectPkg = _T("模拟探测");
	g_sLangID_IEC_WriteRcvPkg = _T("IEC_WriteRcvPkg");
	g_sLangTxt_IEC_WriteRcvPkg = _T("模拟接受报文");
	g_sLangID_IEC_AutoWrite = _T("IEC_AutoWrite");
	g_sLangTxt_IEC_AutoWrite = _T("自动模拟");
	g_sLangID_IEC_SendLength_2 = _T("IEC_SendLength_2");
	g_sLangTxt_IEC_SendLength_2 = _T("总长度");
	g_sLangID_IEC_SendLength = _T("IEC_SendLength");
	g_sLangTxt_IEC_SendLength = _T("发送长度");
	g_sLangID_IEC_Writegen = _T("IEC_Writegen");
	g_sLangTxt_IEC_Writegen = _T("模拟发生器");
	g_sLangID_IEC_PacketSending = _T("IEC_PacketSending");
	g_sLangTxt_IEC_PacketSending = _T("报文输出");
	g_sLangID_IEC_OnceValue = _T("IEC_OnceValue");
	g_sLangTxt_IEC_OnceValue = _T("一次值");
	g_sLangID_IEC_TwiceValue = _T("IEC_TwiceValue");
	g_sLangTxt_IEC_TwiceValue = _T("二次值");
	g_sLangID_IEC_Coeff = _T("IEC_Coeff");
	g_sLangTxt_IEC_Coeff = _T("系数");
	g_sLangID_IEC_FileSaveAs = _T("IEC_FileSaveAs");
	g_sLangTxt_IEC_FileSaveAs = _T("文件另存为");
	g_sLangID_IEC_Receiveratio = _T("IEC_Receiveratio");
	g_sLangTxt_IEC_Receiveratio = _T("接收变比设置");
	g_sLangID_IEC_PTOnce = _T("IEC_PTOnce");
	g_sLangTxt_IEC_PTOnce = _T("PT一次值(kV)");
	g_sLangID_IEC_PTSecond = _T("IEC_PTSecond");
	g_sLangTxt_IEC_PTSecond = _T("PT二次值(V)");
	g_sLangID_IEC_CTOnce = _T("IEC_CTOnce");
	g_sLangTxt_IEC_CTOnce = _T("CT一次值(A)");
	g_sLangID_IEC_CTSecond = _T("IEC_CTSecond");
	g_sLangTxt_IEC_CTSecond = _T("CT二次值(A)");
	g_sLangID_IEC_OPDES = _T("IEC_OPDES");
	g_sLangTxt_IEC_OPDES = _T("光口描述");
	g_sLangID_IEC_Measurcurrent = _T("IEC_Measurcurrent");
	g_sLangTxt_IEC_Measurcurrent = _T("测量电流");

	g_sLangID_IEC_IEC61850 = _T("IEC61850");
	g_sLangTxt_IEC_IEC61850 = _T("系统参数设置中，未勾选数字量，不能创建IEC61850配置……");
	g_sLangID_GOOSE_Single = _T("GOOSE_Single");
	g_sLangTxt_GOOSE_Single = _T("单点");
	g_sLangID_GOOSE_Double = _T("GOOSE_Double");
	g_sLangTxt_GOOSE_Double = _T("双点");
	g_sLangID_GOOSE_Float = _T("GOOSE_Float");
	g_sLangTxt_GOOSE_Float = _T("浮点");
	g_sLangID_Goose_SwitchTime = _T("Goose_SwitchTime");
	g_sLangTxt_Goose_SwitchTime = _T("切换时间");
	g_sLangID_Goose_Value = _T("Goose_Value");
	g_sLangTxt_Goose_Value = _T("值");
	g_sLangID_Goose_RelativeTime = _T("Goose_RelativeTime");
	g_sLangTxt_Goose_RelativeTime = _T("相对时间/us");

	g_sLangID_CharLib_ZoomIndex = _T("CharLib_ZoomIndex");
	g_sLangTxt_CharLib_ZoomIndex = _T("段号");
	g_sLangID_CharLib_FaultPhase = _T("CharLib_FaultPhase");
	g_sLangTxt_CharLib_FaultPhase = _T("故障相");
	g_sLangID_CharLib_AddChar = _T("CharLib_AddChar");
	g_sLangTxt_CharLib_AddChar = _T("特性曲线添加");
	g_sLangID_CharLib_StartCurr = _T("CharLib_StartCurr");
	g_sLangTxt_CharLib_StartCurr = _T("启动段");
	g_sLangID_CharLib_Ratiobraking = _T("CharLib_Ratiobraking");
	g_sLangTxt_CharLib_Ratiobraking = _T("比率制动");
	g_sLangID_CharLib_Paragraph = _T("CharLib_Paragraph");
	g_sLangTxt_CharLib_Paragraph = _T("段");
	g_sLangID_CharLib_Tripping = _T("CharLib_Tripping");
	g_sLangTxt_CharLib_Tripping = _T("速断");
	g_sLangID_CharLib_TestPointsGrid = _T("CharLib_TestPointsGrid");
	g_sLangTxt_CharLib_TestPointsGrid = _T("测试点列表");

	g_sLangID_Smv_SelCb = _T("Smv_SelCb");
	g_sLangTxt_Smv_SelCb = _T("选择控制块");
	g_sLangID_Smv_SelFunc = _T("Smv_SelFunc");
	g_sLangTxt_Smv_SelFunc = _T("选择功能");
	g_sLangID_Smv_PrevPage = _T("Smv_PrevPage");
	g_sLangTxt_Smv_PrevPage = _T("上一页");
	g_sLangID_Smv_NextPage = _T("Smv_NextPage");
	g_sLangTxt_Smv_NextPage = _T("下一页");
	g_sLangID_Smv_SysSet = _T("Smv_SysSet");
	g_sLangTxt_Smv_SysSet = _T("系统设置");
	g_sLangID_Smv_ChName = _T("Smv_ChName");
	g_sLangTxt_Smv_ChName = _T("通道名");
	g_sLangID_Smv_Item = _T("Smv_Item");
	g_sLangTxt_Smv_Item = _T("项目");
	g_sLangID_Smv_Number = _T("Smv_Number");
	g_sLangTxt_Smv_Number = _T("数目");
	g_sLangID_Smv_PkgValue = _T("Smv_PkgValue");
	g_sLangTxt_Smv_PkgValue = _T("报文值");
	g_sLangID_Smv_Category = _T("Smv_Category");
	g_sLangTxt_Smv_Category = _T("类别");
	g_sLangID_Smv_Rates = _T("Smv_Rates");
	g_sLangTxt_Smv_Rates = _T("变比设置");
	g_sLangID_Smv_ShowOneValue = _T("Smv_ShowOneValue");
	g_sLangTxt_Smv_ShowOneValue = _T("显示一次值");
	g_sLangID_Smv_ShowTwoValue = _T("Smv_ShowTwoValue");
	g_sLangTxt_Smv_ShowTwoValue = _T("显示二次值");

	g_sLangID_Native_EffectiveVol = _T("Native_EffectiveVol");
	g_sLangTxt_Native_EffectiveVol = _T("电压有效值");
	g_sLangID_Native_EffectiveCurr = _T("Native_EffectiveCurr");
	g_sLangTxt_Native_EffectiveCurr = _T("电流有效值");
	g_sLangID_Native_Power = _T("Native_Power");
	g_sLangTxt_Native_Power = _T("有功功率(W)");
	g_sLangID_Native_ReactivePow = _T("Native_ReactivePow");
	g_sLangTxt_Native_ReactivePow = _T("无功功率(Var)");
	g_sLangID_Native_ApparentPow = _T("Native_ApparentPow");
	g_sLangTxt_Native_ApparentPow = _T("视在功率(VA)");
	g_sLangID_Native_PowFactor = _T("Native_PowFactor");
	g_sLangTxt_Native_PowFactor = _T("功率因数");
	g_sLangID_Native_TotalPow = _T("Native_TotalPow");
	g_sLangTxt_Native_TotalPow = _T("总功率");
	g_sLangID_Native_Clear = _T("Native_Clear");
	g_sLangTxt_Native_Clear = _T("清空");
	g_sLangID_Native_Switch = _T("Native_Switch");
	g_sLangTxt_Native_Switch = _T("开关量设置");
	g_sLangID_Samples = _T("Samples");
	g_sLangTxt_Samples = _T("采样数");
	g_sLangID_Momentaryvalue = _T("Momentaryvalue");
	g_sLangTxt_Momentaryvalue = _T("瞬时值");
	g_sLangID_notrigger = _T("notrigger");
	g_sLangTxt_notrigger = _T("无触发");
	g_sLangID_Cyclicwave = _T("Cyclicwave");
	g_sLangTxt_Cyclicwave = _T("循环周波数[0,10]:");
	g_sLangID_GPS = _T("GPS");
	g_sLangTxt_GPS = _T("GPS触发");
	g_sLangID_Timere = _T("Timere");
	g_sLangTxt_Timere = _T("时刻(时分秒)：");
	g_sLangID_Switchtrigger = _T("Switchtrigger");
	g_sLangTxt_Switchtrigger = _T("开关量触发");
	g_sLangID_Faultcurve = _T("Faultcurve");
	g_sLangTxt_Faultcurve = _T("故障曲线图");
	g_sLangID_Display = _T("Display");
	g_sLangTxt_Display = _T("显示");
	g_sLangID_AChannel = _T("AChannel");
	g_sLangTxt_AChannel = _T("A通道选择");
	g_sLangID_BChannel = _T("BChannel");
	g_sLangTxt_BChannel = _T("B通道选择");
	g_sLangID_Open_Record = _T("Open_Record");
	g_sLangTxt_Open_Record = _T("打开录波文件");
	g_sLangID_Instant = _T("Instant");
	g_sLangTxt_Instant = _T("瞬时值显示");
	g_sLangID_PT = _T("PT");
	g_sLangTxt_PT = _T("PT变比");
	g_sLangID_CT = _T("CT");
	g_sLangTxt_CT = _T("CT变比");
	g_sLangID_Module1 = _T("Module1");
	g_sLangTxt_Module1 = _T("模块1(电压电流)");
	g_sLangID_Outputpower = _T("Outputpower");
	g_sLangTxt_Outputpower = _T("输出功率设置");
	g_sLangID_Currentmodule = _T("Currentmodule");
	g_sLangTxt_Currentmodule = _T("电流模块");
	g_sLangID_CurrModuleSelect = _T("CurrModuleSelect");
	g_sLangTxt_CurrModuleSelect = _T("电流模块选择:");
	g_sLangID_Currentgear = _T("Currentgear");
	g_sLangTxt_Currentgear = _T("电流档位设置");
	g_sLangID_Maximumport = _T("Maximumport");
	g_sLangTxt_Maximumport = _T("最大端口电压(Vrms):");
	g_sLangID_Combinedcurrent = _T("Combinedcurrent");
	g_sLangTxt_Combinedcurrent = _T("合并电流端子输出(6I合并为3I或采用大电流端子输出)");
	g_sLangID_Highcurrent = _T("Highcurrent");
	g_sLangTxt_Highcurrent = _T("大电流输出端口");
	g_sLangID_Onegear = _T("Onegear");
	g_sLangTxt_Onegear = _T("1档(0.2Ω/10A)");
	g_sLangID_Twogear = _T("Twogear");
	g_sLangTxt_Twogear = _T("2档(0.3Ω/10A)");
	g_sLangID_Threegear = _T("Threegear");
	g_sLangTxt_Threegear = _T("3档(0.7Ω/10A)");
	g_sLangID_else = _T("else");
	g_sLangTxt_else = _T("其他");
	g_sLangID_Onlyselect = _T("Onlyselect");
	g_sLangTxt_Onlyselect = _T("只能选择一个采样值控制块");
	g_sLangID_Clickratio = _T("Clickratio");
	g_sLangTxt_Clickratio = _T("点击按钮进行变比设置");
	g_sLangID_Clickmonitor = _T("Clickmonitor");
	g_sLangTxt_Clickmonitor = _T("点击此按钮,选择采样值控制块,进行报文监视.");
	g_sLangID_Selecttable = _T("Selecttable");
	g_sLangTxt_Selecttable = _T("在控制块表格中选择关联的控制块");
	g_sLangID_Reporttest = _T("Reporttest");
	g_sLangTxt_Reporttest = _T("报告视图，点击此按钮，查看测试报告");
	g_sLangID_starttest = _T("starttest");
	g_sLangTxt_starttest = _T("开始测试，点击此按钮，开始测试");
	g_sLangID_General = _T("General");
	g_sLangTxt_General = _T("通用提示信息，类似于输出栏显示的提示信息，此提示信息可以消失");
	g_sLangID_TestHelp = _T("TestHelp");
	g_sLangTxt_TestHelp = _T("测试助手，点击我获取测试帮助");
	g_sLangID_Currentfailed = _T("Currentfailed");
	g_sLangTxt_Currentfailed = _T("当前m_pCapDevice == NULL 清除失败.");
	g_sLangID_Succeeded = _T("Succeeded");
	g_sLangTxt_Succeeded = _T("清空报文统计结果成功.");
	g_sLangID_delay = _T("delay");
	g_sLangTxt_delay = _T("通道延时(μs):");
	g_sLangID_Measured = _T("Measured");
	g_sLangTxt_Measured = _T("实测延时(μs):");
	g_sLangID_error = _T("error");
	g_sLangTxt_error = _T("延时误差(μs):");
	g_sLangID_The = _T("The");
	g_sLangTxt_The = _T("当前选中的节点，已经包含相同   标识  的测试项……");
	g_sLangID_current = _T("current");
	g_sLangTxt_current = _T("当前选中的节点，已经包含相同  名称  的测试项……");
	g_sLangID_Node = _T("Node");
	g_sLangTxt_Node = _T("当前选中的节点为空，无法添加项目……");
	g_sLangID_Items = _T("Items");
	g_sLangTxt_Items = _T("当前选中的节点，其类型不支持添加项目……");
	g_sLangID_exist = _T("exist");
	g_sLangTxt_exist = _T("已存在");
	g_sLangID_menu = _T("menu");
	g_sLangTxt_menu = _T("菜单栏");
	g_sLangID_return = _T("return");
	g_sLangTxt_return = _T("返回上一级");
	g_sLangID_USBFile = _T("USBFile");
	g_sLangTxt_USBFile = _T("未检测到U盘,请插入U盘");
	g_sLangID_RepalceFile = _T("RepalceFile");
	g_sLangTxt_RepalceFile = _T("已存在相同名称文件,是否替换文件？");
	g_sLangID_import = _T("import");
	g_sLangTxt_import = _T("导入文件进度条");
	g_sLangID_export = _T("export");
	g_sLangTxt_export = _T("未识别USB路径，无法导出！");
	g_sLangID_Importflie = _T("Importflie");
	g_sLangTxt_Importflie = _T("导入文件[");
	g_sLangID_Win = _T("Win");
	g_sLangTxt_Win = _T("]成功.");
	g_sLangID_Lose = _T("Lose");
	g_sLangTxt_Lose = _T("]失败.");
	g_sLangID_block = _T("block");
	g_sLangTxt_block = _T("当前总控制块数量大于32个,无法继续添加.");
	g_sLangID_Controlblock = _T("Controlblock");
	g_sLangTxt_Controlblock = _T("当前未选择控制块,请先选择需要删除的控制块.");
	g_sLangID_leastone = _T("leastone");
	g_sLangTxt_leastone = _T("至少保留一个控制块,无法进行删除操作.");
	g_sLangID_copyblock = _T("copyblock");
	g_sLangTxt_copyblock = _T("当前未选择控制块,请先选择需要拷贝的控制块");
	g_sLangID_viewchannel = _T("viewchannel");
	g_sLangTxt_viewchannel = _T("当前未选择控制块,请先选择需要查看通道的控制块.");
	g_sLangID_dataobject = _T("dataobject");
	g_sLangTxt_dataobject = _T("当前数据对象ClassID=%d,未能识别.");
	g_sLangID_channelType = _T("channelType");
	g_sLangTxt_channelType = _T("当前通道类型(%d)识别出错.");
	g_sLangID_parameterport = _T("parameterport");
	g_sLangTxt_parameterport = _T("光口(%s)对应参数数据未找到");

	g_sLangID_SMV92map = _T("SMV92map");
	g_sLangTxt_SMV92map = _T("当前SMV92通道映射出错(%s).");
	g_sLangID_samplepublish = _T("samplepublish");
	g_sLangTxt_samplepublish = _T("采样值发布");
	g_sLangID_USB = _T("USB");
	g_sLangTxt_USB = _T("USB文件");
	g_sLangID_exportbar = _T("exportbar");
	g_sLangTxt_exportbar = _T("导出文件进度条");
	g_sLangID_Fileguid = _T("Fileguid");
	g_sLangTxt_Fileguid = _T("正在导文件...");
	g_sLangID_devicedesc = _T("devicedesc");
	g_sLangTxt_devicedesc = _T("装置描述");
	g_sLangID_unittype = _T("unittype");
	g_sLangTxt_unittype = _T("设备型号");
	g_sLangID_changelist = _T("changelist");
	g_sLangTxt_changelist = _T("清空变位列表成功.");
	g_sLangID_overwitten = _T("overwitten");
	g_sLangTxt_overwitten = _T("是否覆盖如下控制块？");
	g_sLangID_componenttest = _T("componenttest");
	g_sLangTxt_componenttest = _T("通用序分量试验模板文件");
	g_sLangID_sequence = _T("sequence");
	g_sLangTxt_sequence = _T("序分量");
	g_sLangID_componentlinevolttest = _T("componentLinevolttest");
	g_sLangTxt_componentlinevolttest = _T("通用线电压试验模板文件");
	g_sLangID_linevolt = _T("linevolt");
	g_sLangTxt_linevolt = _T("线电压");
	g_sLangID_steplength = _T("steplength");
	g_sLangTxt_steplength = _T("步长时间:");
//	g_sLangID_Frequency = _T("Frequency");   //移动到基类CXLanguageResourceBase  2024-1-4 shaolei
//	g_sLangTxt_Frequency = _T("频率(Hz):");
	g_sLangID_selectchannel = _T("selectchannel");
	g_sLangTxt_selectchannel = _T("当前选择的递变通道(Index=%d)未查找到.");
	g_sLangID_currenttime = _T("currenttime");
	g_sLangTxt_currenttime = _T("当前用时%ldms.");
	g_sLangID_channelname = _T("channelname");
	g_sLangTxt_channelname = _T("通道名称");
	g_sLangID_errorclass = _T("errorclass");
	g_sLangTxt_errorclass = _T("误差类别");
	g_sLangID_numbertest = _T("numbertest");
	g_sLangTxt_numbertest = _T("测试次数");
	g_sLangID_realtime = _T("realtime");
	g_sLangTxt_realtime = _T("实时值");

	g_sLangID_emptydata = _T("emptydata");
	g_sLangTxt_emptydata = _T("emptydata");

	g_sLangID_ratioerror = _T("ratioerror");
	g_sLangTxt_ratioerror = _T("比差");
	g_sLangID_ratioerror2 = _T("ratioerror2");
	g_sLangTxt_ratioerror2 = _T("比差%");
	g_sLangID_angle = _T("angle");
	g_sLangTxt_angle = _T("角差(′)");
	g_sLangID_Compound = _T("Compound");
	g_sLangTxt_Compound = _T("复合误差(%)");
	g_sLangID_statistic = _T("statistic");
	g_sLangTxt_statistic = _T("清空误差统计结果成功.");
	g_sLangID_outputvalue = _T("outputvalue");
	g_sLangTxt_outputvalue = _T("输出值(A/V)");
	g_sLangID_Outputphase = _T("Outputphase");
	g_sLangTxt_Outputphase = _T("输出相位(°)");
	g_sLangID_Measureampl = _T("Measureampl");
	g_sLangTxt_Measureampl = _T("实测幅值(A/V)");
	g_sLangID_Measuredphase = _T("Measuredphase");
	g_sLangTxt_Measuredphase = _T("实测相位(°)");
	g_sLangID_zerodrift = _T("zerodrift");
	g_sLangTxt_zerodrift = _T("零漂(dB)");
	g_sLangID_posttrigger = _T("posttrigger");
	g_sLangTxt_posttrigger = _T("触发后模式：");
	g_sLangID_Switchimmed = _T("Switchimmed");
	g_sLangTxt_Switchimmed = _T("立刻切换");
	g_sLangID_loopwaveform = _T("loopwaveform");
	g_sLangTxt_loopwaveform = _T("循环波形回放完成后切换");
	g_sLangID_faultreplay = _T("faultreplay");
	g_sLangTxt_faultreplay = _T("故障回放试验模板文件");
	g_sLangID_downloaddata = _T("downloaddata");
	g_sLangTxt_downloaddata = _T("正在下载波形数据..");
	g_sLangID_ReplayStarttest = _T("ReplayStarttest");
	g_sLangTxt_ReplayStarttest = _T("当前打开录波文件为空,请先打开故障回放录波,再运行\"开始测试\".");
	g_sLangID_playback = _T("playback");
	g_sLangTxt_playback = _T("当前勾选的回放通道数量为空,请先需要回放的通道.");
	g_sLangID_outputvoltage = _T("outputvoltage");
	g_sLangTxt_outputvoltage = _T("当前电压通道回放的最大电压值(%1V),大于测试仪最大输出电压(%2V).");
	g_sLangID_outputcurrent = _T("outputcurrent");
	g_sLangTxt_outputcurrent = _T("当前电流通道回放的最大电流值(%1A),大于测试仪最大输出电流(%2A).");
	g_sLangID_deliverybar = _T("deliverybar");
	g_sLangTxt_deliverybar = _T("波形数据下发进度条");
	g_sLangID_cfgFile = _T("cfgFile");
	g_sLangTxt_cfgFile = _T("cfg 文件(*.cfg)");
	g_sLangID_parsebar = _T("parsebar");
	g_sLangTxt_parsebar = _T("波形文件解析进度条");
	g_sLangID_recordfile = _T("recordfile");
	g_sLangTxt_recordfile = _T("打开录波文件[");
	g_sLangID_hardwarefile = _T("hardwarefile");
	g_sLangTxt_hardwarefile = _T("当前设备硬件信息文件为空,请先与测试仪联机获取硬件信息文件.");
	g_sLangID_channelphase = _T("channelphase");
	g_sLangTxt_channelphase = _T("通道相别");
	g_sLangID_tablechannel = _T("tablechannel");
	g_sLangTxt_tablechannel = _T("表格中当前通道(%s)数据未查找到.");
	g_sLangID_faulttype = _T("faulttype");
	g_sLangTxt_faulttype = _T("当前数据类型对应的表格出错.");
	g_sLangID_rangenumber = _T("rangenumber");
	g_sLangTxt_rangenumber = _T("通道数%d超出范围， 调整到%d");
	g_sLangID_maxblocks = _T("maxblocks");
	g_sLangTxt_maxblocks = _T("当前选择的控制块数量(%ld),大于最大设置控制块数量(%ld).");
	g_sLangID_valuesubscrip = _T("valuesubscrip");
	g_sLangTxt_valuesubscrip = _T("采样值订阅");
	g_sLangID_emptyIed = _T("emptyIed");
	g_sLangTxt_emptyIed = _T("当前选择的IED为空,请重新选择.");
	g_sLangID_emptyIEC = _T("emptyIEC");
	g_sLangTxt_emptyIEC = _T("当前IEC配置对象为空.");
	g_sLangID_addedblock = _T("addedblock");
	g_sLangTxt_addedblock = _T("当前控制块(%s)已添加.");
	g_sLangID_configurationfile = _T("configurationfile");
	g_sLangTxt_configurationfile = _T("打开配置文件(%s)失败.");
 	g_sLangID_warning = _T("warning"); //sun
 	g_sLangTxt_warning = _T("警告");    //sun
	g_sLangID_NullIEC = _T("NullIEC");
	g_sLangTxt_NullIEC = _T("当前IEC配置为空，请至少添加一个控制块！");
	g_sLangID_IECpath = _T("IECpath");
	g_sLangTxt_IECpath = _T("IEC配置文件路径");
	g_sLangID_IECdocument = _T("IECdocument");
	g_sLangTxt_IECdocument = _T("IEC文件(*.ixml)");

	g_sLangID_zero = _T("zero");
	g_sLangTxt_zero = _T("zero");

	g_sLangID_step = _T("step");
	g_sLangTxt_step = _T("步骤");
	g_sLangID_datapath = _T("datapath");
	g_sLangTxt_datapath = _T("数据集路径");

	g_sLangID_guide = _T("guide");
	g_sLangTxt_guide = _T("guide");

	g_sLangID_wizard = _T("wizard");
	g_sLangTxt_wizard = _T("项目【%s】对应的向导操作信息不正确！");
	g_sLangID_period = _T("period");
	g_sLangTxt_period = _T("是否周期上送");
	g_sLangID_quality = _T("quality");
	g_sLangTxt_quality = _T("是否品质上送");
	g_sLangID_mutate = _T("mutate");
	g_sLangTxt_mutate = _T("是否突变上送");
	g_sLangID_leadtime = _T("leadtime");
	g_sLangTxt_leadtime = _T("周期上送时间(ms)");

	g_sLangID_change = _T("change");
	g_sLangTxt_change = _T("change");

	g_sLangID_instrument = _T("instrument");
	g_sLangTxt_instrument = _T("仪器型号:");
	g_sLangID_instrumentnumber = _T("instrumentnumber");
	g_sLangTxt_instrumentnumber = _T("仪器编号:");
	g_sLangID_testip = _T("testip");
	g_sLangTxt_testip = _T("测试仪IP:");
	g_sLangID_IPaddress = _T("IPaddress");
	g_sLangTxt_IPaddress = _T("修改当前测试仪IP地址");
	g_sLangID_correctlyform = _T("correctlyform");
	g_sLangTxt_correctlyform = _T("IP地址或者子网掩码格式错误.");
	g_sLangID_assistantIP = _T("assistantIP");
	g_sLangTxt_assistantIP = _T("增加测试仪辅助IP");
	g_sLangID_validentry = _T("validentry");
	g_sLangTxt_validentry = _T("(%1)不是有效项。请指定一个介于0和255间的值。");
	g_sLangID_listIP = _T("listIP");
	g_sLangTxt_listIP = _T("列表已存在IP地址(%1)");
	g_sLangID_cardIP = _T("cardIP");
	g_sLangTxt_cardIP = _T("测试仪IP地址(%1)与当前网卡IP不在同一网段,是否添加?");
	g_sLangID_scan = _T("scan");
	g_sLangTxt_scan = _T("扫描");
	g_sLangID_query = _T("query");
	g_sLangTxt_query = _T("查询测试仪【SN=%1】【Model=%2】运行进程失败【ErrCode=%3】。");
	g_sLangID_running = _T("running");
	g_sLangTxt_running = _T("查询测试仪【SN=%1】【Model=%2】运行进程结果：");
	g_sLangID_automatic = _T("automatic");
	g_sLangTxt_automatic = _T("创建组播链接失败,无法进行扫描,5s后自动重连.");
	g_sLangID_networkcards = _T("networkcards");
	g_sLangTxt_networkcards = _T("当前选择的Index(%1),大于等于总的网卡数(%2).");
	g_sLangID_validIP = _T("validIP");
	g_sLangTxt_validIP = _T("当前选择的IP地址(%1)不合法.");
	g_sLangID_cardlookup = _T("cardlookup");
	g_sLangTxt_cardlookup = _T("当前网卡查找失败(%1).");
	g_sLangID_modifyIP = _T("modifyIP");
	g_sLangTxt_modifyIP = _T("测试仪IP地址(%1)与当前网卡IP不在同一网段,请修改.");
	g_sLangID_stopscan = _T("stopscan");
	g_sLangTxt_stopscan = _T("停止扫描");

	// SOE

	g_sLangID_SOE_state = _T("Soe_state");
	g_sLangTxt_SOE_state = _T("初始状态");
	g_sLangID_SOE_ChangeBeforTimes = _T("Soe_ChangeBeforTime");
	g_sLangTxt_SOE_ChangeBeforTimes = _T("变位前时长(ms)");
	g_sLangID_SOE_ShuttingTimes = _T("Soe_ShuttingTime");
	g_sLangTxt_SOE_ShuttingTimes = _T("闭合时长(ms)");
	g_sLangID_SOE_DisconTimes = _T("Soe_DisconTimes");
	g_sLangTxt_SOE_DisconTimes = _T("断开时长(ms)");
	g_sLangID_SOE_Count = _T("Soe_Count");
	g_sLangTxt_SOE_Count = _T("变位次数(次)");
	g_sLangID_SOE_SustainTimes = _T("Soe_SustainTimes");
	g_sLangTxt_SOE_SustainTimes = _T("持续时间(s)");
	g_sLangID_SOE_Break = _T("Soe_Break");
	g_sLangTxt_SOE_Break = _T("断开");
	g_sLangID_SOE_Shutting = _T("Soe_Shutting");
	g_sLangTxt_SOE_Shutting = _T("闭合");
	g_sLangID_SOE_ImmediateExperiment = _T("Soe_ImmediateExperiment");
	g_sLangTxt_SOE_ImmediateExperiment = _T("立即实验");
	g_sLangID_SOE_PulseWidth = _T("Soe_PulseWidth");
	g_sLangTxt_SOE_PulseWidth = _T("脉冲宽度(ms)");
	g_sLangID_SOE_Resolution = _T("Soe_Resolution");
	g_sLangTxt_SOE_Resolution = _T("SOE分辨率(ms)");
	g_sLangID_SOE_SelectAll = _T("Soe_SelectAll");
	g_sLangTxt_SOE_SelectAll = _T("全部选择");
	g_sLangID_SOE_CancelAll = _T("Soe_CancelAll");
	g_sLangTxt_SOE_CancelAll = _T("全部取消");
	g_sLangID_SOE_InitialAll = _T("Soe_InitialAll");
	g_sLangTxt_SOE_InitialAll = _T("初始全合");
	g_sLangID_SOE_InitialDivideAll = _T("Soe_InitialDivideAll");
	g_sLangTxt_SOE_InitialDivideAll = _T("初始全分");
	g_sLangID_SOE_TemplateFile = _T("Soe_TemplateFile");
	g_sLangTxt_SOE_TemplateFile = _T("SOE模板文件");
	g_sLangID_SOE_TemplateFile = _T("Soe_TemplateFile");
	g_sLangTxt_SOE_TemplateFile = _T("SOE模板文件");

	g_sLangID_FileMngr_FolderName = _T("FileMngr_FolderName");
	g_sLangTxt_FileMngr_FolderName = _T("文件夹名称");
	g_sLangID_FileMngr_FolderIllustrate = _T("FileMngr_FolderIllustrate");
	g_sLangTxt_FileMngr_FolderIllustrate = _T("文件夹说明");
	g_sLangID_FileMngr_Date = _T("FileMngr_Date");
	g_sLangTxt_FileMngr_Date = _T("修改日期");
	g_sLangID_FileMngr_Used = _T("FileMngr_Used");
	g_sLangTxt_FileMngr_Used = _T("已使用");
	g_sLangID_FileMngr_Available = _T("FileMngr_Available");
	g_sLangTxt_FileMngr_Available = _T("可用");

	g_sLangID_Native_Toolbar = _T("Native_Toolbar");
	g_sLangTxt_Native_Toolbar = _T("工具栏");

	g_sLangID_Native_BtnRemove = _T("BtnRemove ");
	g_sLangTxt_Native_BtnRemove = _T("移除");
	g_sLangID_Native_BtnEndInsert = _T("Native_BtnEndInsert");
	g_sLangTxt_Native_BtnEndInsert = _T("末尾插入");
	g_sLangID_Native_BtnInsertAfter = _T("BtnInsertAfter");
	g_sLangTxt_Native_BtnInsertAfter = _T("后面插入");
	g_sLangID_Native_BtnInsertBefore = _T("BtnInsertBefore");
	g_sLangTxt_Native_BtnInsertBefore = _T("前面插入");

	g_sLangID_Native_BtnConfigDevice = _T("Native_BtnConfigDevice");
	g_sLangTxt_Native_BtnConfigDevice = _T("配置");
	g_sLangID_Native_BtnConnectDevice = _T("Native_BtnConnectDevice");
	g_sLangTxt_Native_BtnConnectDevice = _T("连接");
	g_sLangID_Native_BtnEnumDevice = _T("Native_BtnEnumDevice");
	g_sLangTxt_Native_BtnEnumDevice = _T("枚举装置");
	g_sLangID_Native_BtnReadDataset = _T("Native_BtnReadDataset");
	g_sLangTxt_Native_BtnReadDataset = _T("读数据");
	g_sLangID_Native_BtnWriteDataset = _T("Native_BtnWriteDataset");
	g_sLangTxt_Native_BtnWriteDataset = _T("修改数据");
	g_sLangID_Native_BtnReadZone = _T("Native_BtnReadZone");
	g_sLangTxt_Native_BtnReadZone = _T("读定值区");
	g_sLangID_Native_BtnWriteZone = _T("Native_BtnWriteZone");
	g_sLangTxt_Native_BtnWriteZone = _T("修改定值区");
	g_sLangID_Native_BtnReset = _T("Native_BtnReset");
	g_sLangTxt_Native_BtnReset = _T("复归");
	g_sLangID_Native_BtnStartRpt = _T("Native_BtnStartRpt");
	g_sLangTxt_Native_BtnStartRpt = _T("启动报告");
	g_sLangID_Native_BtnStopReport = _T("Native_BtnStopReport");
	g_sLangTxt_Native_BtnStopReportr = _T("停止报告");
	g_sLangID_Native_BtnAddDevice = _T("Native_BtnAddDevice");
	g_sLangTxt_Native_BtnAddDevice = _T("添加装置");
	g_sLangID_Native_BtnEnumLDevice = _T("Native_BtnEnumLDevice");
	g_sLangTxt_Native_BtnEnumLDevice = _T("枚举逻辑设备");
	g_sLangID_Native_BtnEnumDataset = _T("Native_BtnEnumDataset");
	g_sLangTxt_Native_BtnEnumDataset = _T("枚举数据集");
	g_sLangID_Native_BtnOpenDvmFile = _T("Native_BtnOpenDvmFile");
	g_sLangTxt_Native_BtnOpenDvmFile = _T("导入模型");
	g_sLangID_Native_BtnSaveDvmFile = _T("Native_BtnSaveDvmFile");
	g_sLangTxt_Native_BtnSaveDvmFile = _T("导出模型");

	g_sLangID_Native_Upgradation = _T("_Native_Upgradation");
	g_sLangTxt_Native_Upgradation = _T("请插好充电线进行升级.");
	g_sLangID_Native_UpdateSoftware = _T("Native_UpdateSoftware");
	g_sLangTxt_Native_UpdateSoftware = _T("软件更新,请插好网线,是否更新？");
	g_sLangID_Native_OnlineUpgrade = _T("Native_OnlineUpgrade");
	g_sLangTxt_Native_OnlineUpgrade = _T("在线升级进行中,请稍侯...");
	g_sLangID_Native_UpgradeProgressBar = _T("Native_UpgradeProgressBa");
	g_sLangTxt_Native_UpgradeProgressBar = _T("升级进度条");
	g_sLangID_Native_NetworkConnectionFailed = _T("Native_NetworkConnectionFailed");
	g_sLangTxt_Native_NetworkConnectionFailed = _T("云平台IP未ping通,请检查网络连接是否正常.");
	g_sLangID_Native_VersionUpdateFailed = _T("Native_VersionUpdateFailed");
	g_sLangTxt_Native_VersionUpdateFailed = _T("连接版本更新程序失败.");
	g_sLangID_Native_CommandFailed = _T("Native_CommandFailed");
	g_sLangTxt_Native_CommandFailed = _T("发送版本升级命令失败.");
	g_sLangID_Native_LowBatteryLevel = _T("Native_LowBatteryLevel");
	g_sLangTxt_Native_LowBatteryLevel = _T("当前测试仪剩余电量过低,请先充电!!!");
	g_sLangID_Native_IecDetection = _T("Native_IecDetection");
	g_sLangTxt_Native_IecDetection = _T("合并单元测试,需要先进入IEC探测监视界面.");
	g_sLangID_Native_UnrecognizedUSB = _T("Native_UnrecognizedUSB");
	g_sLangTxt_Native_UnrecognizedUSB = _T("未识别到U盘,请插好U盘进行升级.");
	g_sLangID_Native_ChargingUpgrade = _T("Native_ChargingUpgrade");
	g_sLangTxt_Native_ChargingUpgrade = _T("请插好充电线进行升级.");
	g_sLangID_Native_OfflineUpgrade = _T("Native_OfflineUpgrade");
	g_sLangTxt_Native_OfflineUpgrade = _T("离线升级进行中,请稍侯...");
	g_sLangID_Native_PreparationUpgrade = _T("Native_PreparationUpgrade");
	g_sLangTxt_Native_PreparationUpgrade = _T("准备升级程序(%s).");
	g_sLangID_Native_LookupFailed = _T("Native_LookupFailed");
	g_sLangTxt_Native_LookupFailed = _T("查找版本升级包失败.");
	g_sLangID_Native_LiveUpdate = _T("Native_LiveUpdate");
	g_sLangTxt_Native_LiveUpdate = _T("升级程序(SttLiveUpdate)启动成功,开始准备升级.");
	g_sLangID_Native_ExcludingReportData = _T("Native_ExcludingReportData");
	g_sLangTxt_Native_ExcludingReportData = _T("当前测试项(%s)下不包含报告数据.");
	g_sLangID_Native_ReportDataEmpty = _T("Native_ReportDataEmpty");
	g_sLangTxt_Native_ReportDataEmpty = _T("当前测试项(%s)下包含的报告数据为空.");

	g_sLangID_Native_VolSetTypeLN = _T("Native_VolSetTypeLN");
	g_sLangTxt_Native_VolSetTypeLN = _T("相电压(Y)");
	g_sLangID_Native_VolSetTypeLL = _T("Native_VolSetTypeLL");
	g_sLangTxt_Native_VolSetTypeLL = _T("线电压(D)");
	g_sLangID_Native_VolSetTypeSE = _T("Native_VolSetTypeSE");
	g_sLangTxt_Native_VolSetTypeSE = _T("电压序分量(S)");
	g_sLangID_Native_CurSetTypeLN = _T("Native_CurSetTypeLN");
	g_sLangTxt_Native_CurSetTypeLN = _T("相电流(C)");
	g_sLangID_Native_CurSetTypeSE = _T("Native_CurSetTypeSE");
	g_sLangTxt_Native_CurSetTypeSE = _T("电流序分量(S)");

	g_sLangID_Native_SyStempoints = _T("Native_SyStempoints");
	g_sLangTxt_Native_SyStempoints = _T("系统点数");
	g_sLangID_Native_Custompoints = _T("Native_Custompoints");
	g_sLangTxt_Native_Custompoints = _T("自定义点数");
	g_sLangID_Native_Iecurrent = _T("Native_Iecurrent");
	g_sLangTxt_Native_Iecurrent = _T("制动电流(Ie)");
	g_sLangID_Native_Acurrent = _T("Native_Acurrent");
	g_sLangTxt_Native_Acurrent = _T("制动电流(A)");

	// 第七周许
	// xwd 10.16
	g_sLangID_Native_SetOrigMsg = _T("Native_SetOrigMsg");
	g_sLangTxt_Native_SetOrigMsg = _T("设置原始报文");
	g_sLangID_Native_DestMacAddr = _T("Native_DestMacAddr");
	g_sLangTxt_Native_DestMacAddr = _T("目的Mac地址");
	g_sLangID_Native_Netid = _T("Native_Netid");
	g_sLangTxt_Native_Netid = _T("网络标识");
	g_sLangID_Native_FlyPntVolt = _T("Native_FlyPntVolt");
	g_sLangTxt_Native_FlyPntVolt = _T("飞点电压值");
	g_sLangID_Native_FlyPntCurr = _T("Native_FlyPntCurr");
	g_sLangTxt_Native_FlyPntCurr = _T("飞点电流值");
	g_sLangID_Native_FlyPntVoltUaEn = _T("Native_FlyPntVoltUaEn");
	g_sLangTxt_Native_FlyPntVoltUaEn = _T("飞点电压Ua使能");
	g_sLangID_Native_FlyPntVoltUbEn = _T("Native_FlyPntVoltUbEn");
	g_sLangTxt_Native_FlyPntVoltUbEn = _T("飞点电压Ub使能");
	g_sLangID_Native_FlyPntVoltUcEn = _T("Native_FlyPntVoltUcEn");
	g_sLangTxt_Native_FlyPntVoltUcEn = _T("飞点电压Uc使能");
	g_sLangID_Native_FlyPntCurrIaEn = _T("Native_FlyPntCurrIaEn");
	g_sLangTxt_Native_FlyPntCurrIaEn = _T("飞点电流Ia使能");
	g_sLangID_Native_FlyPntCurrIbEn = _T("Native_FlyPntCurrIbEn");
	g_sLangTxt_Native_FlyPntCurrIbEn = _T("飞点电流Ib使能");
	g_sLangID_Native_FlyPntCurrIcEn = _T("Native_FlyPntCurrIcEn");
	g_sLangTxt_Native_FlyPntCurrIcEn = _T("飞点电流Ic使能");
	g_sLangID_Native_JitterValns = _T("Native_JitterValns");
	g_sLangTxt_Native_JitterValns = _T("抖动值(单位ns)");
	g_sLangID_Native_Valid = _T("Native_Valid");
	g_sLangTxt_Native_Valid = _T("有效");
	g_sLangID_Native_Overflow = _T("Native_Overflow");
	g_sLangTxt_Native_Overflow = _T("溢出");
	g_sLangID_Native_OutOfRanges = _T("Native_OutOfRange");
	g_sLangTxt_Native_OutOfRanges = _T("超值域");
	g_sLangID_Native_BadBaseVal = _T("Native_BadBaseVal");
	g_sLangTxt_Native_BadBaseVal = _T("坏基准值");
	g_sLangID_Native_OldData = _T("Native_OldData");
	g_sLangTxt_Native_OldData = _T("旧数据");
	g_sLangID_Native_Inconsistent = _T("Native_Inconsistent");
	g_sLangTxt_Native_Inconsistent = _T("不一致");
	g_sLangID_Native_Inaccurate = _T("Native_Inaccurate");
	g_sLangTxt_Native_Inaccurate = _T("不精确");
	g_sLangID_Native_Source = _T("Native_Source");
	g_sLangTxt_Native_Source = _T("源");
	g_sLangID_Native_OpLock = _T("Native_OpLock");
	g_sLangTxt_Native_OpLock = _T("操作员闭锁");
	g_sLangID_Native_AbnPointSel = _T("Native_AbnPointSel");
	g_sLangTxt_Native_AbnPointSel = _T("异常点选择");
	g_sLangID_Native_AbnPoint = _T("Native_AbnPoint");
	g_sLangTxt_Native_AbnPoint = _T("异常点");
	g_sLangID_Native_SMVAbnParam = _T("Native_SMVAbnParam");
	g_sLangTxt_Native_SMVAbnParam = _T("SMV异常参数");
	g_sLangID_Native_SVAbnType = _T("Native_SVAbnType");
	g_sLangTxt_Native_SVAbnType = _T("SV异常类型");
	g_sLangID_Native_SVMsgGrpNum = _T("Native_SVMsgGrpNum");
	g_sLangTxt_Native_SVMsgGrpNum = _T("SV报文组号(从0开始编号)");
	g_sLangID_Native_SendFreq = _T("Native_SendFreq");
	g_sLangTxt_Native_SendFreq = _T("发送周波数(周波模式)");
	g_sLangID_Native_SendFreqPerSec = _T("Native_SendFreqPerSec");
	g_sLangTxt_Native_SendFreqPerSec = _T("每秒发送周波数(秒模式)");
	g_sLangID_Native_AbnormDataSendTimeMode = _T("Native_AbnormDataSendTimeMode");
	g_sLangTxt_Native_AbnormDataSendTimeMode = _T("异常数据发送时间模式(0-周波;1-秒)");
	g_sLangID_Native_SVSendTimeSecMode = _T("Native_SVSendTimeSecMode");
	g_sLangTxt_Native_SVSendTimeSecMode = _T("SV发送时间(秒模式)");
	g_sLangID_Native_GOOSEAbnormParam = _T("Native_GOOSEAbnormParam");
	g_sLangTxt_Native_GOOSEAbnormParam = _T("GOOSE异常参数");
	g_sLangID_Native_AbnormGroupSeq = _T("Native_AbnormGroupSeq");
	g_sLangTxt_Native_AbnormGroupSeq = _T("异常组序号（从0计数）");
	g_sLangID_Native_SrcMACSelect = _T("Native_SrcMACSelect");
	g_sLangTxt_Native_SrcMACSelect = _T("源MAC(选择)");
	g_sLangID_Native_DestMACSelect = _T("Native_DestMACSelect");
	g_sLangTxt_Native_DestMACSelect = _T("目标MAC(选择)");
	g_sLangID_Native_GocbRefSelect = _T("Native_GocbRefSelect");
	g_sLangTxt_Native_GocbRefSelect = _T("GocbRef(选择)");
	g_sLangID_Native_GoIDSelect = _T("Native_GoIDSelect");
	g_sLangTxt_Native_GoIDSelect = _T("GoID(选择)");
	g_sLangID_Native_DataSetSelect = _T("Native_DataSetSelect");
	g_sLangTxt_Native_DataSetSelect = _T("DataSet(选择)");
	g_sLangID_Native_DestMACs = _T("Native_DestMACs");
	g_sLangTxt_Native_DestMACs = _T("目标MAC");
	g_sLangID_Native_AppIDSelect = _T("Native_AppIDSelect");
	g_sLangTxt_Native_AppIDSelect = _T("AppID(选择)");
	g_sLangID_Native_StSelect = _T("Native_StSelect");
	g_sLangTxt_Native_StSelect = _T("St(选择)");
	g_sLangID_Native_StValue = _T("Native_StValue");
	g_sLangTxt_Native_StValue = _T("St值");
	g_sLangID_Native_SqSelect = _T("Native_SqSelect");
	g_sLangTxt_Native_SqSelect = _T("Sq(选择)");
	g_sLangID_Native_SqValue = _T("Native_SqValue");
	g_sLangTxt_Native_SqValue = _T("Sq值");
	g_sLangID_Native_AllowLiveTSelect = _T("Native_AllowLiveTSelect");
	g_sLangTxt_Native_AllowLiveTSelect = _T("允许生存时间(选择)");
	g_sLangID_Native_AllowLiveT = _T("Native_AllowLiveT");
	g_sLangTxt_Native_AllowLiveT = _T("允许生存时间");
	g_sLangID_Native_DelegateSelect = _T("Native_DelegateSelect");
	g_sLangTxt_Native_DelegateSelect = _T("委托(选择)");
	g_sLangID_Native_TestMarkSelect = _T("Native_TestMarkSelect");
	g_sLangTxt_Native_TestMarkSelect = _T("测试标记(选择)");
	g_sLangID_Native_Delegate = _T("Native_Delegate");
	g_sLangTxt_Native_Delegate = _T("委托");
	g_sLangID_Native_TestMark = _T("Native_TestMark");
	g_sLangTxt_Native_TestMark = _T("测试标记");
	g_sLangID_Native_VlanIDSelect = _T("Native_VlanIDSelect");
	g_sLangTxt_Native_VlanIDSelect = _T("VlanID(选择)");
	g_sLangID_Native_VlanIDValue = _T("Native_VlanIDValue");
	g_sLangTxt_Native_VlanIDValue = _T("VlanID值");
	g_sLangID_Native_NetIDSelect = _T("Native_NetIDSelect");
	g_sLangTxt_Native_NetIDSelect = _T("网络标识(选择)");
	g_sLangID_Native_NetIDValue = _T("Native_NetIDValue");
	g_sLangTxt_Native_NetIDValue = _T("网络标识值");
	g_sLangID_Native_ConfigVerSelect = _T("Native_ConfigVerSelect");
	g_sLangTxt_Native_ConfigVerSelect = _T("配置版本(选择)");
	g_sLangID_Native_ConfigVerValue = _T("Native_ConfigVerValue");
	g_sLangTxt_Native_ConfigVerValue = _T("配置版本值");
	g_sLangID_Native_NormalOpen1State = _T("Native_NormalOpen1State");
	g_sLangTxt_Native_NormalOpen1State = _T("常态开出1状态");
	g_sLangID_Native_NormalOpen2State = _T("Native_NormalOpen2State");
	g_sLangTxt_Native_NormalOpen2State = _T("常态开出2状态");
	g_sLangID_Native_NormalOpen3State = _T("Native_NormalOpen3State");
	g_sLangTxt_Native_NormalOpen3State = _T("常态开出3状态");
	g_sLangID_Native_NormalOpen4State = _T("Native_NormalOpen4State");
	g_sLangTxt_Native_NormalOpen4State = _T("常态开出4状态");
	g_sLangID_Native_NormalOpen5State = _T("Native_NormalOpen5State");
	g_sLangTxt_Native_NormalOpen5State = _T("常态开出5状态");
	g_sLangID_Native_NormalOpen6State = _T("Native_NormalOpen6State");
	g_sLangTxt_Native_NormalOpen6State = _T("常态开出6状态");
	g_sLangID_Native_NormalOpen7State = _T("Native_NormalOpen7State");
	g_sLangTxt_Native_NormalOpen7State = _T("常态开出7状态");
	g_sLangID_Native_NormalOpen8State = _T("Native_NormalOpen8State");
	g_sLangTxt_Native_NormalOpen8State = _T("常态开出8状态");
	g_sLangID_Native_FaultOpen1State = _T("Native_FaultOpen1State");
	g_sLangTxt_Native_FaultOpen1State = _T("故障态开出1状态");
	g_sLangID_Native_FaultOpen2State = _T("Native_FaultOpen2State");
	g_sLangTxt_Native_FaultOpen2State = _T("故障态开出2状态");
	g_sLangID_Native_FaultOpen3State = _T("Native_FaultOpen3State");
	g_sLangTxt_Native_FaultOpen3State = _T("故障态开出3状态");
	g_sLangID_Native_FaultOpen4State = _T("Native_FaultOpen4State");
	g_sLangTxt_Native_FaultOpen4State = _T("故障态开出4状态");
	g_sLangID_Native_FaultOpen5State = _T("Native_FaultOpen5State");
	g_sLangTxt_Native_FaultOpen5State = _T("故障态开出5状态");
	g_sLangID_Native_FaultOpen6State = _T("Native_FaultOpen6State");
	g_sLangTxt_Native_FaultOpen6State = _T("故障态开出6状态");
	g_sLangID_Native_FaultOpen7State = _T("Native_FaultOpen7State");
	g_sLangTxt_Native_FaultOpen7State = _T("故障态开出7状态");
	g_sLangID_Native_FaultOpen8State = _T("Native_FaultOpen8State");
	g_sLangTxt_Native_FaultOpen8State = _T("故障态开出8状态");
	g_sLangID_Native_HotOverloadTimeConst = _T("Native_HotOTC");
	g_sLangTxt_Native_HotOverloadTimeConst = _T("热过负荷时间常数");
	g_sLangID_Native_HotOverloadBaseCurrent = _T("Native_HotOBC");
	g_sLangTxt_Native_HotOverloadBaseCurrent = _T("热过负荷基数电流");
	g_sLangID_Native_HotOverloadActionValue = _T("Native_HotOAV");
	g_sLangTxt_Native_HotOverloadActionValue = _T("热过负荷动作定值");
	g_sLangID_Native_OverloadCurrent = _T("Native_OverloadC");
	g_sLangTxt_Native_OverloadCurrent = _T("过负荷电流");
	g_sLangID_Native_FaultTimeMargin = _T("Native_FaultTM");
	g_sLangTxt_Native_FaultTimeMargin = _T("故障时间裕度");
	g_sLangID_Native_CurrentChangeStartValue = _T("Native_CurrChngStartV");
	g_sLangTxt_Native_CurrentChangeStartValue = _T("电流变化始值");
	g_sLangID_Native_CurrentChangeEndValue = _T("Native_CurrChngEndV");
	g_sLangTxt_Native_CurrentChangeEndValue = _T("电流变化终值");
	g_sLangID_Native_CurrentChangeStep = _T("Native_CurrChngStep");
	g_sLangTxt_Native_CurrentChangeStep = _T("电流变化步长");
	g_sLangID_Native_HotOverloadTime = _T("Native_HotOTConst");
	g_sLangTxt_Native_HotOverloadTime = _T("热过负荷时间常数(表达式)");
	g_sLangID_Native_HotOverloadBaseCurr = _T("Native_HotOBaseCurr");
	g_sLangTxt_Native_HotOverloadBaseCurr = _T("热过负荷基数电流(表达式)");
	g_sLangID_Native_HotOverloadActionValues = _T("Native_HotOActionVals");
	g_sLangTxt_Native_HotOverloadActionValues = _T("热过负荷动作定值(表达式)");
	g_sLangID_Native_ActionDesc = _T("Native_ActionDesc");
	g_sLangTxt_Native_ActionDesc = _T("动作描述");
	g_sLangID_Native_FaultPreVoltageAmp = _T("Native_FltPreVAmp");
	g_sLangTxt_Native_FaultPreVoltageAmp = _T("故障前电压幅值");
	g_sLangID_Native_FaultPreCurrentAmp = _T("Native_FltPreCAmp");
	g_sLangTxt_Native_FaultPreCurrentAmp = _T("故障前电流幅值");
	g_sLangID_Native_FaultPreVoltageCurrentPhase = _T("Native_FltPreVCP");
	g_sLangTxt_Native_FaultPreVoltageCurrentPhase = _T("故障前电压电流相角(U-I)");
	g_sLangID_Native_FaultPreVoltageSeq = _T("Native_FltPreVSeq");
	g_sLangTxt_Native_FaultPreVoltageSeq = _T("故障前电压相序");
	g_sLangID_Native_FaultPreCurrentSeq = _T("Native_FltPreCSeq");
	g_sLangTxt_Native_FaultPreCurrentSeq = _T("故障前电流相序");
	g_sLangID_Native_FaultVoltage = _T("Native_FltVoltage");
	g_sLangTxt_Native_FaultVoltage = _T("故障电压");
	g_sLangID_Native_FaultVoltageCurrentPhase = _T("Native_FltVCP");
	g_sLangTxt_Native_FaultVoltageCurrentPhase = _T("故障态电压电流相角(U-I)");
	g_sLangID_Native_ShortCircuitVoltageType = _T("Native_SCVT");
	g_sLangTxt_Native_ShortCircuitVoltageType = _T("短路电压类别");
	g_sLangID_Native_ReferenceValue = _T("Native_RefVal");
	g_sLangTxt_Native_ReferenceValue = _T("基准值");
	g_sLangID_Native_CTPolarityPositive = _T("Native_CTPP");
	g_sLangTxt_Native_CTPolarityPositive = _T("CT正极性");
	g_sLangID_Native_PreFaultVCPAExpr = _T("Native_PFVCPAE");
	g_sLangTxt_Native_PreFaultVCPAExpr = _T("故障前电压电流相角(表达式)");
	g_sLangID_Native_ActionTimeSetValueExpr = _T("Native_ATSE");
	g_sLangTxt_Native_ActionTimeSetValueExpr = _T("动作时间定值(表达式)");
	g_sLangID_Native_FaultVoltageExpr = _T("Native_FVE");
	g_sLangTxt_Native_FaultVoltageExpr = _T("故障电压(表达式)");
	g_sLangID_Native_FaultCurr = _T("Native_FaultCurr");
	g_sLangTxt_Native_FaultCurr = _T("故障电流(表达式)");
	g_sLangID_Native_FaultAngExp = _T("Native_FaultAngExp");
	g_sLangTxt_Native_FaultAngExp = _T("故障态电压电流相角(表达式)");
	g_sLangID_Native_CharCurveParam = _T("Native_CharCurveParam");
	g_sLangTxt_Native_CharCurveParam = _T("特性曲线参数(Vp)");
	g_sLangID_Native_VoltFreqRatio = _T("Native_VoltFreqRatio");
	g_sLangTxt_Native_VoltFreqRatio = _T("电压频率比");
	g_sLangID_Native_ChangeMode = _T("Native_ChangeMode");
	g_sLangTxt_Native_ChangeMode = _T("变化方式 0-频率不变,增电压  1-电压不变,降频率");
	g_sLangID_Native_CollectModPos = _T("Native_CollectModPos");
	g_sLangTxt_Native_CollectModPos = _T("采集模块位置");
	g_sLangID_Native_CollectGear = _T("Native_CollectGear");
	g_sLangTxt_Native_CollectGear = _T("采集档位");
	g_sLangID_Native_ModPos = _T("Native_ModPos");
	g_sLangTxt_Native_ModPos = _T("模块位置");
	g_sLangID_Native_TempZone = _T("Native_TempZone");
	g_sLangTxt_Native_TempZone = _T("温区");
	g_sLangID_Native_MeterError = _T("Native_MeterError");
	g_sLangTxt_Native_MeterError = _T("表计误差");
	g_sLangID_Native_RefFreq = _T("Native_RefFreq");
	g_sLangTxt_Native_RefFreq = _T("参考频率");
	g_sLangID_Native_Point1RefAmp = _T("Native_Point1RefAmp");
	g_sLangTxt_Native_Point1RefAmp = _T("点1参考幅值");
	g_sLangID_Native_Point2RefAmp = _T("Native_Point2RefAmp");
	g_sLangTxt_Native_Point2RefAmp = _T("点2参考幅值");
	g_sLangID_Native_Point1MeasAmp = _T("Native_Point1MeasAmp");
	g_sLangTxt_Native_Point1MeasAmp = _T("点1测量幅值");
	g_sLangID_Native_Point2MeasAmp = _T("Native_Point2MeasAmp");
	g_sLangTxt_Native_Point2MeasAmp = _T("点2测量幅值");
	g_sLangID_Native_OutputAmp = _T("Native_OutputAmp");
	g_sLangTxt_Native_OutputAmp = _T("输出幅值");
	g_sLangID_Native_PhaseMeasVal = _T("Native_PhaseMeasVal");
	g_sLangTxt_Native_PhaseMeasVal = _T("相位测量值");
	g_sLangID_Native_MeasFreq = _T("Native_MeasFreq");
	g_sLangTxt_Native_MeasFreq = _T("测量频率");
	g_sLangID_Native_ChannelHardGear = _T("Native_ChannelHardGear");
	g_sLangTxt_Native_ChannelHardGear = _T("通道硬件档位");
	g_sLangID_Native_ZeroDriftMeas = _T("Native_ZeroDriftMeas");
	g_sLangTxt_Native_ZeroDriftMeas = _T("零漂测量值");
	g_sLangID_Native_Channel1ID = _T("Native_Channel1ID");
	g_sLangTxt_Native_Channel1ID = _T("通道1编号");
	g_sLangID_Native_Channel1Amp = _T("Native_Channel1Amp");
	g_sLangTxt_Native_Channel1Amp = _T("通道1幅值");
	g_sLangID_Native_Channel1Phase = _T("Native_Channel1Phase");
	g_sLangTxt_Native_Channel1Phase = _T("通道1相位");
	g_sLangID_Native_Channel1Freq = _T("Native_Channel1Freq");
	g_sLangTxt_Native_Channel1Freq = _T("通道1频率");
	g_sLangID_Native_Channel2Num = _T("Native_Channel2Num");
	g_sLangTxt_Native_Channel2Num = _T("通道2编号");
	g_sLangID_Native_Channel2Amp = _T("Native_Channel2Amp");
	g_sLangTxt_Native_Channel2Amp = _T("通道2幅值");
	g_sLangID_Native_Channel2Phase = _T("Native_Channel2Phase");
	g_sLangTxt_Native_Channel2Phase = _T("通道2相位");
	g_sLangID_Native_Channel2Freq = _T("Native_Channel2Freq");
	g_sLangTxt_Native_Channel2Freq = _T("通道2频率");
	g_sLangID_Native_Channel3Num = _T("Native_Channel3Num");
	g_sLangTxt_Native_Channel3Num = _T("通道3编号");
	g_sLangID_Native_Channel3Amp = _T("Native_Channel3Amp");
	g_sLangTxt_Native_Channel3Amp = _T("通道3幅值");
	g_sLangID_Native_Channel3Phase = _T("Native_Channel3Phase");
	g_sLangTxt_Native_Channel3Phase = _T("通道3相位");
	g_sLangID_Native_Channel3Freq = _T("Native_Channel3Freq");
	g_sLangTxt_Native_Channel3Freq = _T("通道3频率");
	g_sLangID_Native_IsHighCurrentCalib = _T("Native_IsHighCurrentCalib");
	g_sLangTxt_Native_IsHighCurrentCalib = _T("是否大电流校准");
	g_sLangID_Native_Channel1AmpCoeff = _T("Native_Channel1AmpCoeff");
	g_sLangTxt_Native_Channel1AmpCoeff = _T("通道1幅值系数");
	g_sLangID_Native_Channel1ZeroOffset = _T("Native_Channel1ZeroOffset");
	g_sLangTxt_Native_Channel1ZeroOffset = _T("通道1零漂");
	g_sLangID_Native_Channel2AmpCoeff = _T("Native_Channel2AmpCoeff");
	g_sLangTxt_Native_Channel2AmpCoeff = _T("通道2幅值系数");
	g_sLangID_Native_Channel2ZeroOffset = _T("Native_Channel2ZeroOffset");
	g_sLangTxt_Native_Channel2ZeroOffset = _T("通道2零漂");
	g_sLangID_Native_Channel3AmpCoeff = _T("Native_Channel3AmpCoeff");
	g_sLangTxt_Native_Channel3AmpCoeff = _T("通道3幅值系数");
	g_sLangID_Native_Channel3ZeroOffset = _T("Native_Channel3ZeroOffset");
	g_sLangTxt_Native_Channel3ZeroOffset = _T("通道3零漂");
	g_sLangID_Native_WaveformSelection = _T("Native_WaveformSelection");
	g_sLangTxt_Native_WaveformSelection = _T("波形选择");
	g_sLangID_Native_Gear = _T("Native_Gear");
	g_sLangTxt_Native_Gear = _T("档位");
	g_sLangID_Native_ModuleNo2 = _T("Native_ModuleNo2");
	g_sLangTxt_Native_ModuleNo2 = _T("模块编号2");
	g_sLangID_Native_TempZone2 = _T("Native_TempZone2");
	g_sLangTxt_Native_TempZone2 = _T("温区2");
	g_sLangID_Native_ChannelNo2 = _T("Native_ChannelNo2");
	g_sLangTxt_Native_ChannelNo2 = _T("通道编号2");
	g_sLangID_Native_Gear2 = _T("Native_Gear2");
	g_sLangTxt_Native_Gear2 = _T("档位2");
	g_sLangID_Native_OutputChannel = _T("Native_OutputChannel");
	g_sLangTxt_Native_OutputChannel = _T("输出通道");
	g_sLangID_Native_HardwareGear = _T("Native_HardwareGear");
	g_sLangTxt_Native_HardwareGear = _T("硬件档位");
	g_sLangID_Native_ModuleNumber = _T("Native_ModuleNumber");
	g_sLangTxt_Native_ModuleNumber = _T("模块编号");
	g_sLangID_Native_SwitchMode = _T("Native_SwitchMode");
	g_sLangTxt_Native_SwitchMode = _T("切换模式");
	g_sLangID_Native_Output1ConductValue = _T("Native_Output1ConductValue");
	g_sLangTxt_Native_Output1ConductValue = _T("开出1导通值");
	g_sLangID_Native_Output2ConductValue = _T("Native_Output2ConductValue");
	g_sLangTxt_Native_Output2ConductValue = _T("开出2导通值");
	g_sLangID_Native_Output3ConductValue = _T("Native_Output3ConductValue");
	g_sLangTxt_Native_Output3ConductValue = _T("开出3导通值");
	g_sLangID_Native_Output4ConductValue = _T("Native_Output4ConductValue");
	g_sLangTxt_Native_Output4ConductValue = _T("开出4导通值");
	g_sLangID_Native_Output5ConductValue = _T("Native_Output5ConductValue");
	g_sLangTxt_Native_Output5ConductValue = _T("开出5导通值");
	g_sLangID_Native_Output6ConductValue = _T("Native_Output6ConductValue");
	g_sLangTxt_Native_Output6ConductValue = _T("开出6导通值");
	g_sLangID_Native_Output7ConductValue = _T("Native_Output7ConductValue");
	g_sLangTxt_Native_Output7ConductValue = _T("开出7导通值");
	g_sLangID_Native_Output8ConductValue = _T("Native_Output8ConductValue");
	g_sLangTxt_Native_Output8ConductValue = _T("开出8导通值");
	g_sLangID_Native_RegAddrHex = _T("Native_RegAddrHex");
	g_sLangTxt_Native_RegAddrHex = _T("寄存器地址(16进制)");
	g_sLangID_Native_RegValHex = _T("Native_RegValHex");
	g_sLangTxt_Native_RegValHex = _T("寄存器值(16进制)");
	g_sLangID_Native_Results = _T("Native_Results");
	g_sLangTxt_Native_Results = _T("结果");
	g_sLangID_Native_FlipDelay = _T("Native_FlipDelay");
	g_sLangTxt_Native_FlipDelay = _T("开出翻转延时");
	g_sLangID_Native_InFlipCond = _T("Native_InFlipCond");
	g_sLangTxt_Native_InFlipCond = _T("开入量翻转判别条件");
	g_sLangID_Native_IsSeqStateSeq = _T("Native_IsSeqStateSeq");
	g_sLangTxt_Native_IsSeqStateSeq = _T("是否为顺序状态序列");
	g_sLangID_Native_RepeatCount = _T("Native_RepeatCount");
	g_sLangTxt_Native_RepeatCount = _T("重复次数");
	g_sLangID_Native_StateNum = _T("Native_StateNum");
	g_sLangTxt_Native_StateNum = _T("状态数");
	g_sLangID_Native_InputExpand = _T("Native_InputExpand");
	g_sLangTxt_Native_InputExpand = _T("开入扩展");
	g_sLangID_Native_NActionTime = _T("Native_NActionTime");
	g_sLangTxt_Native_NActionTime = _T("次动作时间");
	g_sLangID_Native_LoopNum = _T("Native_LoopNum");
	g_sLangTxt_Native_LoopNum = _T("循环序号");
	g_sLangID_Native_StateNums = _T("Native_StateNums");
	g_sLangTxt_Native_StateNums = _T("状态序号");
	g_sLangID_Native_OverCurrentI = _T("Native_OverCurrentI");
	g_sLangTxt_Native_OverCurrentI = _T("过流I段定值");
	g_sLangID_Native_OverCurrentII = _T("Native_OverCurrentII");
	g_sLangTxt_Native_OverCurrentII = _T("过流II段定值");
	g_sLangID_Native_OverCurrentIII = _T("Native_OverCurrentIII");
	g_sLangTxt_Native_OverCurrentIII = _T("过流III段定值");
	g_sLangID_Native_OverCurrentIV = _T("Native_OverCurrentIV");
	g_sLangTxt_Native_OverCurrentIV = _T("过流IV段定值");
	g_sLangID_Native_OverCurrentITime = _T("Native_OverCurrentITime");
	g_sLangTxt_Native_OverCurrentITime = _T("过流I段时间");
	g_sLangID_Native_OverCurrentIITime = _T("Native_OverCurrentIITime");
	g_sLangTxt_Native_OverCurrentIITime = _T("过流II段时间");
	g_sLangID_Native_OverCurrentIIITime = _T("Native_OverCurrentIIITime");
	g_sLangTxt_Native_OverCurrentIIITime = _T("过流III段时间");
	g_sLangID_Native_OverCurrentIVTime = _T("Native_OverCurrentIVTime");
	g_sLangTxt_Native_OverCurrentIVTime = _T("过流IV段时间");
	g_sLangID_Native_Grouping = _T("Native_Grouping");
	g_sLangTxt_Native_Grouping = _T("分组");
	g_sLangID_Native_SetActCurExp = _T("Native_SetActCurExp");
	g_sLangTxt_Native_SetActCurExp = _T("整定动作电流(表达式)");
	g_sLangID_Native_OverCurrentValue = _T("Native_OverCurrentValue");
	g_sLangTxt_Native_OverCurrentValue = _T("过流值");

	// 第八周吕
	g_sLangID_Native_volDefinition1 = _T("Native_volDefinition1");
	g_sLangTxt_Native_volDefinition1 = _T("电压定义");
	g_sLangID_Native_refphase = _T("Native_refphase");
	g_sLangTxt_Native_refphase = _T("参考相");

	g_sLangID_Native_transfConnection = _T("Native_transfConnection");
	g_sLangTxt_Native_transfConnection = _T("变压器接线方式");
	g_sLangID_Native_maxSyncTime1 = _T("Native_maxSyncTime1");
	g_sLangTxt_Native_maxSyncTime1 = _T("最大同步时间");
	g_sLangID_Native_breaker4HoldTime = _T("Native_breaker4HoldTime");
	g_sLangTxt_Native_breaker4HoldTime = _T("开出4保持时间");
	g_sLangID_Native_Grid_Vol = _T("Native_Grid_Vol");
	g_sLangTxt_Native_Grid_Vol = _T("待并侧电压");
	g_sLangID_Native_Grid_Freq = _T("Native_Grid_Freq");
	g_sLangTxt_Native_Grid_Freq = _T("待并侧频率");
	g_sLangID_Native_syncSignal = _T("Native_syncSignal");
	g_sLangTxt_Native_syncSignal = _T("同期信号");
	g_sLangID_Native_boostSignal = _T("Native_boostSignal");
	g_sLangTxt_Native_boostSignal = _T("增压信号");
	g_sLangID_Native_boostFreqSignal = _T("Native_boostFreqSignal");
	g_sLangTxt_Native_boostFreqSignal = _T("增频信号");
	g_sLangID_Native_reducePresSignal = _T("Native_reducePresSignal");
	g_sLangTxt_Native_reducePresSignal = _T("减压信号");
	g_sLangID_Native_reduceFreqSignal = _T("Native_reduceFreqSignal");
	g_sLangTxt_Native_reduceFreqSignal = _T("减频信号");
	g_sLangID_Native_OutPut = _T("Native_OutPut");
	g_sLangTxt_Native_OutPut = _T("开出%d");

	g_sLangID_Native_GvolChangeStep = _T("Native_GvolChangeStep");
	g_sLangTxt_Native_GvolChangeStep = _T("待并侧电压变化步长");

	g_sLangID_Native_GridVol_Exp = _T("Native_GridVol_Exp");
	g_sLangTxt_Native_GridVol_Exp = _T("待并侧电压(表达式)");
	g_sLangID_Native_GridFreq_Exp = _T("Native_GridFreq_Exp");
	g_sLangTxt_Native_GridFreq_Exp = _T("待并侧频率(表达式)");
	g_sLangID_Native_GvolChangeStepExp = _T("Native_GvolChangeStepExp");
	g_sLangTxt_Native_GvolChangeStepExp = _T("待并侧电压变化步长(表达式)");

	g_sLangID_Native_GfreqChangeStep = _T("Native_GfreqChangeStep");
	g_sLangTxt_Native_GfreqChangeStep = _T("待并侧频率变化步长");
	g_sLangID_Native_GfreqChangeStepExp = _T("Native_GfreqChangeStepExp");
	g_sLangTxt_Native_GfreqChangeStepExp = _T("待并侧频率变化步长(表达式)");

	g_sLangID_Native_FreqSlip = _T("Native_FreqSlip");
	g_sLangTxt_Native_FreqSlip = _T("频率滑差");
	g_sLangID_Native_VoltSlip = _T("Native_VoltSlip_Exp");
	g_sLangTxt_Native_VoltSlip = _T("电压滑差(表达式)");
	g_sLangID_Native_FreqSlip_Exp = _T("Native_FreqSlip_Exp");
	g_sLangTxt_Native_FreqSlip_Exp = _T("频率滑差(表达式)");
	g_sLangID_Native_RegulatePulseWidth = _T("Native_RegulatePulseWidth");
	g_sLangTxt_Native_RegulatePulseWidth = _T("调压脉宽");
	g_sLangID_Native_FrequencyPulseWidth = _T("Native_FrequencyPulseWidth");
	g_sLangTxt_Native_FrequencyPulseWidth = _T("调频脉宽");

	// 2
	g_sLangID_Native_AngleStartPar1 = _T("Native_AngleStartPar1");
	g_sLangTxt_Native_AngleStartPar1 = _T("功角始值");
	g_sLangID_Native_AngleEndPar1 = _T("Native_AngleEndPar1");
	g_sLangTxt_Native_AngleEndPar1 = _T("功角终值");
	g_sLangID_Native_OscilPeriod1 = _T("Native_OscilPeriod1");
	g_sLangTxt_Native_OscilPeriod1 = _T("振荡周期");
	g_sLangID_Native_TripAccessPoint = _T("Native_TripAccessPoint");
	g_sLangTxt_Native_TripAccessPoint = _T("跳闸接入点");
	g_sLangID_Native_ReOscillat_ornot = _T("Native_ReOscillat_ornot");
	g_sLangTxt_Native_ReOscillat_ornot = _T("是否往复振荡");
	g_sLangID_Native_SpeedChange = _T("Native_SpeedChange");
	g_sLangTxt_Native_SpeedChange = _T("速度变化选择");
	g_sLangID_Native_ImpedanceChange_ornot = _T("Native_ImpedanceChange_ornot");
	g_sLangTxt_Native_ImpedanceChange_ornot = _T("是否变阻抗");
	g_sLangID_Native_ImpedanceRateChange = _T("Native_ImpedanceRateChange");
	g_sLangTxt_Native_ImpedanceRateChange = _T("阻抗变化率");

	g_sLangID_Native_zeroseq_comp_calculat1 = _T("Native_zeroseq_comp_calculat1");
	g_sLangTxt_Native_zeroseq_comp_calculat1 = _T("零序补偿系数计算方式");
	g_sLangID_Native_ZeroSeqComp1 = _T("Native_ZeroSeqComp1");
	g_sLangTxt_Native_ZeroSeqComp1 = _T("零序补偿系数(|K0|$KR$|Z0/Z1|)");
	g_sLangID_Native_ZeroSeqComp2 = _T("Native_ZeroSeqComp2");
	g_sLangTxt_Native_ZeroSeqComp2 = _T("零序补偿系数(Phi(K0)$KX$Phi(Z0/Z1))");

	g_sLangID_Native_SysImpedAngle = _T("Native_SysImpedAngle");
	g_sLangTxt_Native_SysImpedAngle = _T("系统侧阻抗角");
	g_sLangID_Native_TransImpedAngle = _T("Native_TransImpedAngle");
	g_sLangTxt_Native_TransImpedAngle = _T("变压器阻抗角");
	g_sLangID_Native_GeneTransImped = _T("Native_GeneTransImped");
	g_sLangTxt_Native_GeneTransImped = _T("发电机暂态阻抗");

	g_sLangID_Out4_Situation = _T("Out4_Situation");
	g_sLangTxt_Out4_Situation = _T("开出4状态");
	g_sLangID_Out5_Situation = _T("Out5_Situation");
	g_sLangTxt_Out5_Situation = _T("开出5状态");
	g_sLangID_Out6_Situation = _T("Out6_Situation");
	g_sLangTxt_Out6_Situation = _T("开出6状态");
	g_sLangID_Out7_Situation = _T("Out7_Situation");
	g_sLangTxt_Out7_Situation = _T("开出7状态");
	g_sLangID_Out8_Situation = _T("Out8_Situation");
	g_sLangTxt_Out8_Situation = _T("开出8状态");
	g_sLangID_Native_ProtRelayTime1 = _T("Native_ProtRelayTime1");
	g_sLangTxt_Native_ProtRelayTime1 = _T("保护出口时间");
	g_sLangID_Native_AccelSigOutTime1 = _T("Native_AccelSigOutTime1");
	g_sLangTxt_Native_AccelSigOutTime1 = _T("加速信号出口时间");
	g_sLangID_Native_DecelSigOutTime1 = _T("Native_DecelSigOutTime1");
	g_sLangTxt_Native_DecelSigOutTime1 = _T("减速信号出口时间");

	// 3
	g_sLangID_Native_VariablePhaseChange = _T("Native_VariablePhaseChange");
	g_sLangTxt_Native_VariablePhaseChange = _T("递变相别");
	g_sLangID_Native_PreTestTimeS = _T("Native_PreTestTimeS");
	g_sLangTxt_Native_PreTestTimeS = _T("测试前时间(秒)");
	g_sLangID_Native_FaultPreTimeS = _T("Native_FaultPreTimeS");
	g_sLangTxt_Native_FaultPreTimeS = _T("故障前时间(秒)");
	g_sLangID_Native_FaultPreUIPhaseAngle = _T("Native_FaultPreUIPhaseAngle");
	g_sLangTxt_Native_FaultPreUIPhaseAngle = _T("故障前电压电流相角(U-I)");
	g_sLangID_Native_VariableMode0123 = _T("Native_VariableMode0123");
	g_sLangTxt_Native_VariableMode0123 = _T("递变模式(0-单机模式1-电压递变 2-电流递变 3-单机分组模式)");
	g_sLangID_Native_TestReturnCoefficient = _T("Native_TestReturnCoefficient");
	g_sLangTxt_Native_TestReturnCoefficient = _T("测试返回系数");
	g_sLangID_Native_TestChannelType = _T("Native_TestChannelType");
	g_sLangTxt_Native_TestChannelType = _T("测试通道类型");
	g_sLangID_Native_VariableType = _T("Native_VariableType");
	g_sLangTxt_Native_VariableType = _T("递变类型");

	g_sLangID_Native_PhaseShiftDir01 = _T("Native_PhaseShiftDir01");
	g_sLangTxt_Native_PhaseShiftDir01 = _T("相位递变方向(0:逆时针 1:顺时针)");
	g_sLangID_Native_IBeforeChange = _T("Native_IBeforeChange");
	g_sLangTxt_Native_IBeforeChange = _T("变化前电流幅值");
	g_sLangID_Native_FaultGroup1VAmp = _T("Native_FaultGroup1VAmp");
	g_sLangTxt_Native_FaultGroup1VAmp = _T("故障态组1电压幅值");
	g_sLangID_Native_FaultGroup1IAmp = _T("Native_FaultGroup1IAmp");
	g_sLangTxt_Native_FaultGroup1IAmp = _T("故障态组1电流幅值");
	g_sLangID_Native_FaultGroupIPhaseDiff = _T("Native_FaultGroupIPhaseDiff");
	g_sLangTxt_Native_FaultGroupIPhaseDiff = _T("故障态两组电流角差");
	g_sLangID_Native_FaultGroupFreq = _T("Native_FaultGroupFreq");
	g_sLangTxt_Native_FaultGroupFreq = _T("故障态频率");
	g_sLangID_Native_VActionValueAbsErr = _T("Native_VActionValueAbsErr");
	g_sLangTxt_Native_VActionValueAbsErr = _T("电压动作值绝对误差");
	g_sLangID_Native_VActionValueRelErr = _T("Native_VActionValueRelErr");
	g_sLangTxt_Native_VActionValueRelErr = _T("电压动作值相对误差");
	g_sLangID_Native_VActionValueErrLogic = _T("Native_VActionValueErrLogic");
	g_sLangTxt_Native_VActionValueErrLogic = _T("电压动作值误差判断逻辑");
	g_sLangID_Native_IActionValueAbsErr = _T("Native_IActionValueAbsErr");
	g_sLangTxt_Native_IActionValueAbsErr = _T("电流动作值绝对误差");
	g_sLangID_Native_IActionValueRelErr = _T("Native_IActionValueRelErr");
	g_sLangTxt_Native_IActionValueRelErr = _T("电流动作值相对误差");
	g_sLangID_Native_IActionValueErrLogic = _T("Native_IActionValueErrLogic");
	g_sLangTxt_Native_IActionValueErrLogic = _T("电流动作值误差判断逻辑");

	g_sLangID_Native_CoefficientAbsErr = _T("Native_CoefficientAbsErr");
	g_sLangTxt_Native_CoefficientAbsErr = _T("返回系数绝对误差");
	g_sLangID_Native_CoefficientRelErr = _T("Native_CoefficientRelErr");
	g_sLangTxt_Native_CoefficientRelErr = _T("返回系数相对误差");
	g_sLangID_Native_CoefficientErrLogic = _T("Native_CoefficientErrLogic");
	g_sLangTxt_Native_CoefficientErrLogic = _T("返回系数误差判断逻辑");

	g_sLangID_Native_relativeErr = _T("Native_relativeErr");
	g_sLangTxt_Native_relativeErr = _T("相对误差有效");
	g_sLangID_Native_criteria_logic = _T("Native_criteria_logic");
	g_sLangTxt_Native_criteria_logic = _T("判据逻辑");
	g_sLangID_Native_VActionValueErr = _T("Native_VActionValueErr");
	g_sLangTxt_Native_VActionValueErr = _T("电压动作值误差");
	g_sLangID_Native_IActionValueErr = _T("Native_IActionValueErr");
	g_sLangTxt_Native_IActionValueErr = _T("电流动作值误差");
	g_sLangID_Native_input1_ActionVal = _T("Native_input1_ActionVal");
	g_sLangTxt_Native_input1_ActionVal = _T("开入1动作值");
	g_sLangID_Native_input2_ActionVal = _T("Native_input2_ActionVal");
	g_sLangTxt_Native_input2_ActionVal = _T("开入2动作值");
	g_sLangID_Native_input3_ActionVal = _T("Native_input3_ActionVal");
	g_sLangTxt_Native_input3_ActionVal = _T("开入3动作值");
	g_sLangID_Native_input4_ActionVal = _T("Native_input4_ActionVal");
	g_sLangTxt_Native_input4_ActionVal = _T("开入4动作值");
	g_sLangID_Native_input5_ActionVal = _T("Native_input5_ActionVal");
	g_sLangTxt_Native_input5_ActionVal = _T("开入5动作值");
	g_sLangID_Native_input6_ActionVal = _T("Native_input6_ActionVal");
	g_sLangTxt_Native_input6_ActionVal = _T("开入6动作值");
	g_sLangID_Native_input7_ActionVal = _T("Native_input7_ActionVal");
	g_sLangTxt_Native_input7_ActionVal = _T("开入7动作值");
	g_sLangID_Native_input8_ActionVal = _T("Native_input8_ActionVal");
	g_sLangTxt_Native_input8_ActionVal = _T("开入8动作值");

	// 4
	g_sLangID_Native_YNaging_test = _T("Native_YNaging_tes");
	g_sLangTxt_Native_YNaging_test = _T("是否老化试验");
	g_sLangID_Native_varchannel_select = _T("Native_varchannel_select");
	g_sLangTxt_Native_varchannel_select = _T("递变通道选择");
	g_sLangID_Native_vartype_select = _T("Native_vartype_select");
	g_sLangTxt_Native_vartype_select = _T("递变类型选择");
	g_sLangID_Native_change_mode = _T("Native_change_mode");
	g_sLangTxt_Native_change_mode = _T("变化模式");
	g_sLangID_Native_step_time = _T("Native_step_time");
	g_sLangTxt_Native_step_time = _T("每步时间");
	g_sLangID_Native_trigger_delay = _T("Native_trigger_delay");
	g_sLangTxt_Native_trigger_delay = _T("触发延时");
	g_sLangID_Native_YN_locked = _T("Native_YN_locked");
	g_sLangTxt_Native_YN_locked = _T("是否锁定");
	g_sLangID_Native_YN_autoevo = _T("Native_YN_autoevo");
	g_sLangTxt_Native_YN_autoevo = _T("是否自动递变");
	g_sLangID_Native_max_outputtime = _T("Native_max_outputtime");
	g_sLangTxt_Native_max_outputtime = _T("最长输出时间(s)");
	g_sLangID_Native_acttuning_time = _T("Native_acttuning_time");
	g_sLangTxt_Native_acttuning_time = _T("动作整定时间");
	g_sLangID_Native_ActTimeValueAbsErr = _T("Native_ActTimeValueAbsErr");
	g_sLangTxt_Native_ActTimeValueAbsErr = _T("动作时间值绝对误差");
	g_sLangID_Native_ActTimeValueRelErr = _T("Native_ActTimeValueRelErr");
	g_sLangTxt_Native_ActTimeValueRelErr = _T("动作时间值相对误差");
	g_sLangID_Native_ActTimeValueErrLogic = _T("Native_ActTimeValueErrLogic");
	g_sLangTxt_Native_ActTimeValueErrLogic = _T("动作时间误差判断逻辑");
	g_sLangID_Native_PhaseActValueAbsErr = _T("Native_PhaseActValueAbsErr");
	g_sLangTxt_Native_PhaseActValueAbsErr = _T("相位动作值绝对误差");
	g_sLangID_Native_PhaseActValueRelErr = _T("Native_PhaseActValueRelErr");
	g_sLangTxt_Native_PhaseActValueRelErr = _T("相位动作值相对误差");
	g_sLangID_Native_PhaseActValueErrLogic = _T("Native_PhaseActValueErrLogic");
	g_sLangTxt_Native_PhaseActValueErrLogic = _T("相位动作值误差判断逻辑");
	g_sLangID_Native_action_mark = _T("Native_action_mark");
	g_sLangTxt_Native_action_mark = _T("动作标记");
	g_sLangID_Native_result_status = _T("Native_result_status");
	g_sLangTxt_Native_result_status = _T("结果状态");
	g_sLangID_Native_extend = _T("Native_extend");
	g_sLangTxt_Native_extend = _T("扩展%d");

	// 5
	g_sLangID_Native_KeepTime = _T("Native_KeepTime");
	g_sLangTxt_Native_KeepTime = _T("保持时间");
	g_sLangID_Native_SteadyTime = _T("Native_SteadyTime");
	g_sLangTxt_Native_SteadyTime = _T("稳态时间");
	g_sLangID_Native_LowFreActValue = _T("Native_LowFreActValue");
	g_sLangTxt_Native_LowFreActValue = _T("低频动作值");
	g_sLangID_Native_InputASelect = _T("Native_InputASelect");
	g_sLangTxt_Native_InputASelect = _T("开入A选择");
	g_sLangID_Native_InputBSelect = _T("Native_InputBSelect");
	g_sLangTxt_Native_InputBSelect = _T("开入B选择");
	g_sLangID_Native_InputCSelect = _T("Native_InputCSelect");
	g_sLangTxt_Native_InputCSelect = _T("开入C选择");
	g_sLangID_Native_InputDSelect = _T("Native_InputDSelect");
	g_sLangTxt_Native_InputDSelect = _T("开入D选择");
	g_sLangID_Native_InputESelect = _T("Native_InputESelect");
	g_sLangTxt_Native_InputESelect = _T("开入E选择");
	g_sLangID_Native_InputFSelect = _T("Native_InputFSelect");
	g_sLangTxt_Native_InputFSelect = _T("开入F选择");
	g_sLangID_Native_InputGSelect = _T("Native_InputGSelect");
	g_sLangTxt_Native_InputGSelect = _T("开入G选择");
	g_sLangID_Native_InputHSelect = _T("Native_InputHSelect");
	g_sLangTxt_Native_InputHSelect = _T("开入H选择");
	g_sLangID_Native_InputISelect = _T("Native_InputISelect");
	g_sLangTxt_Native_InputISelect = _T("开入I选择");
	g_sLangID_Native_InputJSelect = _T("Native_InputJSelect");
	g_sLangTxt_Native_InputJSelect = _T("开入J选择");

	g_sLangID_Native_FreInitialValue = _T("Native_FreInitialValue");
	g_sLangTxt_Native_FreInitialValue = _T("频率变化始值");
	g_sLangID_Native_FreFinalValue = _T("Native_FreFinalValue");
	g_sLangTxt_Native_FreFinalValue = _T("频率变化终值");
	g_sLangID_Native_FreChangeStep = _T("Native_FreChangeStep");
	g_sLangTxt_Native_FreChangeStep = _T("频率变化步长");
	g_sLangID_Native_FreFinal = _T("Native_FreFinal");
	g_sLangTxt_Native_FreFinal = _T("频率终值");

	g_sLangID_Native_IChangePhase = _T("Native_IChangePhase");
	g_sLangTxt_Native_IChangePhase = _T("电流变化相");
	g_sLangID_Native_SearchslipVal = _T("Native_SearchslipVal");
	g_sLangTxt_Native_SearchslipVal = _T("当前搜索滑差值(dfdt)");
	g_sLangID_Native_KeepTimeExp = _T("Native_KeepTimeExp");
	g_sLangTxt_Native_KeepTimeExp = _T("保持时间(表达式)");

	g_sLangID_Native_FreInitialValueExp = _T("Native_FreInitialValueExp");
	g_sLangTxt_Native_FreInitialValueExp = _T("频率变化始值(表达式)");
	g_sLangID_Native_FreFinalValueExp = _T("Native_FreFinalValueExp");
	g_sLangTxt_Native_FreFinalValueExp = _T("频率变化终值(表达式)");
	g_sLangID_Native_FreChangeStepExp = _T("Native_FreChangeStepExp");
	g_sLangTxt_Native_FreChangeStepExp = _T("频率变化步长(表达式)");
	g_sLangID_Native_SlipInitialValueExp = _T("Native_SlipInitialValueExp");
	g_sLangTxt_Native_SlipInitialValueExp = _T("滑差变化始值(表达式)");
	g_sLangID_Native_SlipFinalValueExp = _T("Native_SlipFinalValueExp");
	g_sLangTxt_Native_SlipFinalValueExp = _T("滑差变化终值(表达式)");
	g_sLangID_Native_SlipChangeStepExp = _T("Native_SlipChangeStepExp");
	g_sLangTxt_Native_SlipChangeStepExp = _T("滑差变化步长(表达式)");
	g_sLangID_Native_IInitialValueExp = _T("Native_IInitialValueExp");
	g_sLangTxt_Native_IInitialValueExp = _T("电流变化始值(表达式)");
	g_sLangID_Native_IFinalValueExp = _T("Native_IFinalValueExp");
	g_sLangTxt_Native_IFinalValueExp = _T("电流变化终值(表达式)");
	g_sLangID_Native_IChangeStepExp = _T("Native_IChangeStepExp");
	g_sLangTxt_Native_IChangeStepExp = _T("电流变化步长(表达式)");
	g_sLangID_Native_VInitialValueExp = _T("Native_VInitialValueExp");
	g_sLangTxt_Native_VInitialValueExp = _T("电压变化始值(表达式)");
	g_sLangID_Native_VFinalValueExp = _T("Native_VFinalValueExp");
	g_sLangTxt_Native_VFinalValueExp = _T("电压变化终值(表达式)");
	g_sLangID_Native_VChangeStepExp = _T("Native_VChangeStepExp");
	g_sLangTxt_Native_VChangeStepExp = _T("电压变化步长(表达式)");

	g_sLangID_Native_FreActValue = _T("Native_FreActValue");
	g_sLangTxt_Native_FreActValue = _T("频率动作值");
	g_sLangID_Native_LowCycleActDesc = _T("Native_LowCycleActDesc");
	g_sLangTxt_Native_LowCycleActDesc = _T("低周动作描述");
	g_sLangID_Native_SlipActValue = _T("Native_SlipActValue");
	g_sLangTxt_Native_SlipActValue = _T("滑差动作值");
	g_sLangID_Native_VBlockValue = _T("Native_VBlockValue");
	g_sLangTxt_Native_VBlockValue = _T("电压闭锁值");
	g_sLangID_Native_IBlockValue = _T("Native_IBlockValue");
	g_sLangTxt_Native_IBlockValue = _T("电流闭锁值");

	// 6
	g_sLangID_Native_VChangeRate_blockVal = _T("Native_VChangeRate_blockVal");
	g_sLangTxt_Native_VChangeRate_blockVal = _T("电压变化率闭锁值");
	g_sLangID_Native_LowVActionDesc = _T("Native_LowVActionDesc");
	g_sLangTxt_Native_LowVActionDesc = _T("低压动作描述");
	g_sLangID_Native_SearchslipVal2 = _T("Native_SearchslipVal2");
	g_sLangTxt_Native_SearchslipVal2 = _T("当前搜索滑差值(dvdt)");
	g_sLangID_Native_Uab1Amp = _T("Native_Uab1Amp");
	g_sLangTxt_Native_Uab1Amp = _T("Uab1幅值");
	g_sLangID_Native_Uab1Ph = _T("Native_Uab1Ph");
	g_sLangTxt_Native_Uab1Ph = _T("Uab1相位");
	g_sLangID_Native_Uab1Fre = _T("Native_Uab1Fre");
	g_sLangTxt_Native_Uab1Fre = _T("Uab1频率");
	g_sLangID_Native_3U0_1Amp = _T("Native_3U0_1Amp");
	g_sLangTxt_Native_3U0_1Amp = _T("3U0_1幅值");
	g_sLangID_Native_3U0_1Ph = _T("Native_3U0_1Ph");
	g_sLangTxt_Native_3U0_1Ph = _T("3U0_1相位");
	g_sLangID_Native_3U0_1Fre = _T("Native_3U0_1Fre");
	g_sLangTxt_Native_3U0_1Fre = _T("3U0_1频率");
	g_sLangID_Native_Uab2Amp = _T("Native_Uab2Amp");
	g_sLangTxt_Native_Uab2Amp = _T("Uab2幅值");
	g_sLangID_Native_Uab2Ph = _T("Native_Uab2Ph");
	g_sLangTxt_Native_Uab2Ph = _T("Uab2相位");
	g_sLangID_Native_Uab2Fre = _T("Native_Uab2Fre");
	g_sLangTxt_Native_Uab2Fre = _T("Uab2频率");
	g_sLangID_Native_3U0_2Amp = _T("Native_3U0_2Amp");
	g_sLangTxt_Native_3U0_2Amp = _T("3U0_2幅值");
	g_sLangID_Native_3U0_2Ph = _T("Native_3U0_2Ph");
	g_sLangTxt_Native_3U0_2Ph = _T("3U0_2相位");
	g_sLangID_Native_3U0_2Fre = _T("Native_3U0_2Fre");
	g_sLangTxt_Native_3U0_2Fre = _T("3U0_2频率");
	g_sLangID_Native_Ia1Fre = _T("Native_Ia1Fre");
	g_sLangTxt_Native_Ia1Fre = _T("Ia1频率");
	g_sLangID_Native_Ib1Fre = _T("Native_Ib1Fre");
	g_sLangTxt_Native_Ib1Fre = _T("Ib1频率");
	g_sLangID_Native_Ic1Fre = _T("Native_Ic1Fre");
	g_sLangTxt_Native_Ic1Fre = _T("Ic1频率");
	g_sLangID_Native_Ia2Fre = _T("Native_Ia2Fre");
	g_sLangTxt_Native_Ia2Fre = _T("Ia2频率");
	g_sLangID_Native_Ib2Fre = _T("Native_Ib2Fre");
	g_sLangTxt_Native_Ib2Fre = _T("Ib2频率");
	g_sLangID_Native_Ic2Fre = _T("Native_Ic2Fre");
	g_sLangTxt_Native_Ic2Fre = _T("Ic2频率");
	g_sLangID_Native_AuxiDCI = _T("Native_AuxiDCI");
	g_sLangTxt_Native_AuxiDCI = _T("辅助直流电流");
	g_sLangID_Native_AuxiDCV = _T("Native_AuxiDCV");
	g_sLangTxt_Native_AuxiDCV = _T("辅助直流电压");

	g_sLangID_Native_syspowerImp = _T("Native_syspowerImp");
	g_sLangTxt_Native_syspowerImp = _T("系统电源阻抗");
	g_sLangID_Native_syspowerImpangle = _T("Native_syspowerImpangle");
	g_sLangTxt_Native_syspowerImpangle = _T("系统电源阻抗角");
	g_sLangID_Native_syscomputModel012 = _T("Native_syscomputModel012");
	g_sLangTxt_Native_syscomputModel012 = _T("系统计算模型(0-电流不变 1-电压不变 2-系统阻抗不变)");
	g_sLangID_Native_fault_switchtime = _T("Native_fault_switchtime");
	g_sLangTxt_Native_fault_switchtime = _T("故障转换时间");
	g_sLangID_Native_switchErrtype = _T("Native_switchErrtype");
	g_sLangTxt_Native_switchErrtype = _T("转换故障类型");

	g_sLangID_Native_switchErr_shortImp = _T("Native_switchErr_shortImp");
	g_sLangTxt_Native_switchErr_shortImp = _T("转换故障短路阻抗");
	g_sLangID_Native_switchErr_shortImpAng = _T("Native_switchErr_shortImpAng");
	g_sLangTxt_Native_switchErr_shortImpAng = _T("转换故障短路阻抗角");
	g_sLangID_Native_switchErr_shortI = _T("Native_switchErr_shortI");
	g_sLangTxt_Native_switchErr_shortI = _T("转换故障短路电流");
	g_sLangID_Native_switchErr_shortV = _T("Native_switchErr_shortV");
	g_sLangTxt_Native_switchErr_shortV = _T("转换故障短路电压");
	g_sLangID_Native_switchErr_direction = _T("Native_switchErr_direction");
	g_sLangTxt_Native_switchErr_direction = _T("转换故障故障方向");
	g_sLangID_Native_testprocess = _T("Native_testprocess");
	g_sLangTxt_Native_testprocess = _T("试验过程");
	g_sLangID_Native_redundancy_mode = _T("Native_redundancy_mode");
	g_sLangTxt_Native_redundancy_mode = _T("重合方式");
	g_sLangID_Native_redundancy_duration = _T("Native_redundancy_duration");
	g_sLangTxt_Native_redundancy_duration = _T("重合持续时间");
	g_sLangID_Native_postswitch_duration = _T("Native_postswitch_duration");
	g_sLangTxt_Native_postswitch_duration = _T("后加速开关跳开后持续时间");

	// 9week ly
	g_sLangID_Native_change_startangle = _T("Native_change_startangle");
	g_sLangTxt_Native_change_startangle = _T("变化起始角度");
	g_sLangID_Native_change_endangle = _T("Native_change_endangle");
	g_sLangTxt_Native_change_endangle = _T("变化终止角度");
	g_sLangID_Native_impedanceAng_measured = _T("Native_impedanceAng_measured");
	g_sLangTxt_Native_impedanceAng_measured = _T("待测阻抗角度定值");
	g_sLangID_Native_search_way = _T("Native_search_way");
	g_sLangTxt_Native_search_way = _T("搜索方式");
	g_sLangID_Native_Zsearch_startAng = _T("Native_Zsearch_startAng");
	g_sLangTxt_Native_Zsearch_startAng = _T("Z搜索起点角度");
	g_sLangID_Native_Zsearch_startAct = _T("Native_Zsearch_startAct");
	g_sLangTxt_Native_Zsearch_startAct = _T("Z搜索起点动作");
	g_sLangID_Native_ZAng_currentVal = _T("Native_ZAng_currentVal");
	g_sLangTxt_Native_ZAng_currentVal = _T("Z当前值角度");
	g_sLangID_Native_Zsearch_endAng = _T("Native_Zsearch_endAng");
	g_sLangTxt_Native_Zsearch_endAng = _T("Z搜索终点角度");
	g_sLangID_Native_Zsearch_endAct = _T("Native_Zsearch_endAct");
	g_sLangTxt_Native_Zsearch_endAct = _T("Z搜索终点动作");
	g_sLangID_Native_action_impedance = _T("Native_action_impedance");
	g_sLangTxt_Native_action_impedance = _T("动作阻抗");
	g_sLangID_Native_action_impedanceAng = _T("Native_action_impedanceAng");
	g_sLangTxt_Native_action_impedanceAng = _T("动作阻抗角");
	g_sLangID_Native_Desc_impedance_Act = _T("Native_Desc_impedance_Act");
	g_sLangTxt_Native_Desc_impedance_Act = _T("阻抗动作描述");

	//
	g_sLangID_Native_impedance_setting = _T("Native_impedance_setting");
	g_sLangTxt_Native_impedance_setting = _T("阻抗定值");
	g_sLangID_Native_impedance_setExp = _T("Native_impedance_setExp");
	g_sLangTxt_Native_impedance_setExp = _T("阻抗定值(表达式)");

	//
	g_sLangID_Native_ZeroSeqCompExp = _T("Native_ZeroSeqCompExp");
	g_sLangTxt_Native_ZeroSeqCompExp = _T("零序补偿系数表达方式");
	g_sLangID_Native_ZeroSeqComp_RERL = _T("Native_ZeroSeqComp_RERL");
	g_sLangTxt_Native_ZeroSeqComp_RERL = _T("零序补偿系数RE/RL");
	g_sLangID_Native_ZeroSeqComp_XEXL = _T("Native_ZeroSeqComp_XEXL");
	g_sLangTxt_Native_ZeroSeqComp_XEXL = _T("零序补偿系数XE/XL");
	g_sLangID_Native_load_current = _T("Native_load_current");
	g_sLangTxt_Native_load_current = _T("负荷电流");
	g_sLangID_Native_loadpowerAng = _T("Native_loadpowerAng");
	g_sLangTxt_Native_loadpowerAng = _T("负荷功角");
	g_sLangID_Native_PT_installPos = _T("Native_PT_installPos");
	g_sLangTxt_Native_PT_installPos = _T("PT安装位置");
	g_sLangID_Native_closeAngmode01 = _T("Native_closeAngmode01");
	g_sLangTxt_Native_closeAngmode01 = _T("合闸角方式( 0-随机 1-定值)");
	g_sLangID_Native_closing_angle = _T("Native_closing_angle");
	g_sLangTxt_Native_closing_angle = _T("合闸角");
	g_sLangID_Native_Vz_outputDef = _T("Native_Vz_outputDef");
	g_sLangTxt_Native_Vz_outputDef = _T("Vz输出定义");
	g_sLangID_Native_Vz_referPhase = _T("Native_Vz_referPhase");
	g_sLangTxt_Native_Vz_referPhase = _T("Vz参考相");
	g_sLangID_Native_Vz_phase_angle = _T("Native_Vz_phase_angle");
	g_sLangTxt_Native_Vz_phase_angle = _T("Vz相角");
	g_sLangID_Native_reclose_timeset = _T("Native_reclose_timeset");
	g_sLangTxt_Native_reclose_timeset = _T("重合闸时间定值");
	g_sLangID_Native_PostAccelerat_TimeSet = _T("Native_PostAccelerat_TimeSet");
	g_sLangTxt_Native_PostAccelerat_TimeSet = _T("后加速时间定值");
	//

	g_sLangID_Native_auxiV_UxoutputMode = _T("Native_auxiV_UxoutputMode");
	g_sLangTxt_Native_auxiV_UxoutputMode = _T("辅助电压Ux输出方式");
	g_sLangID_Native_synchronous_VAmp = _T("Native_synchronous_VAmp");
	g_sLangTxt_Native_synchronous_VAmp = _T("同期电压幅值");
	g_sLangID_Native_synchronous_VPh = _T("Native_synchronous_VPh");
	g_sLangTxt_Native_synchronous_VPh = _T("同期电压相位");
	g_sLangID_Native_pressTestVal = _T("Native_pressTestVal");
	g_sLangTxt_Native_pressTestVal = _T("有压测试值");
	g_sLangID_Native_NOpressTestVal = _T("Native_NOpressTestVal");
	g_sLangTxt_Native_NOpressTestVal = _T("无压测试值");
	g_sLangID_Native_openflip_Control = _T("Native_openflip_Control");
	g_sLangTxt_Native_openflip_Control = _T("开出翻转控制方式");
	g_sLangID_Native_openflip_delay = _T("Native_openflip_delay");
	g_sLangTxt_Native_openflip_delay = _T("开出翻转延时");
	g_sLangID_Native_input_selection = _T("Native_input_selection");
	g_sLangTxt_Native_input_selection = _T("开入量选择");
	g_sLangID_Native_superimposed_ornot1 = _T("Native_superimpose_ornot1");
	g_sLangTxt_Native_superimposed_ornot1 = _T("是否叠加非周期分量");
	g_sLangID_Native_jumpctrl = _T("Native_jumpctrl");
	g_sLangTxt_Native_jumpctrl = _T("跳合信号控制");
	g_sLangID_Native_timectrl = _T("Native_timectrl");
	g_sLangTxt_Native_timectrl = _T("时间控制");
	g_sLangID_Native_totalweight = _T("Native_totalweight");
	g_sLangTxt_Native_totalweight = _T("综重（单重+三重）");
	g_sLangID_Native_tripleweight = _T("Native_tripleweight");
	g_sLangTxt_Native_tripleweight = _T("三重");
	g_sLangID_Native_norepeat = _T("Native_norepeat");
	g_sLangTxt_Native_norepeat = _T("不重合");
	g_sLangID_Native_Totransformer = _T("Native_Totransformer");
	g_sLangTxt_Native_Totransformer = _T("指向变压器");
	g_sLangID_Native_lagrange = _T("Native_lagrange");
	g_sLangTxt_Native_lagrange = _T("拉格朗日插值法");
	g_sLangID_Native_linear = _T("Native_linear");
	g_sLangTxt_Native_linear = _T("线性插值法");
	g_sLangID_Native_faultvoltype = _T("Native_faultvoltype");
	g_sLangTxt_Native_faultvoltype = _T("故障电压类型");

	g_sLangID_Native_Difsetting = _T("Native_Difsetting");
	g_sLangTxt_Native_Difsetting = _T("差动定值整定方式");
	g_sLangID_Native_DifCurChoose = _T("Native_DifCurChoose");
	g_sLangTxt_Native_DifCurChoose = _T("差动基准电流选择");
	g_sLangID_Native_harmonicnumber = _T("Native_harmonicnumber");
	g_sLangTxt_Native_harmonicnumber = _T("谐波次数选择");
	g_sLangID_Native_CuroutputPhase = _T("Native_CuroutputPhase");
	g_sLangTxt_Native_CuroutputPhase = _T("电流输出相");
	g_sLangID_Native_PhaseAshort = _T("Native_PhaseAshort");
	g_sLangTxt_Native_PhaseAshort = _T("A相短路");
	g_sLangID_Native_PhaseBshort = _T("Native_PhaseBshort");
	g_sLangTxt_Native_PhaseBshort = _T("B相短路");
	g_sLangID_Native_PhaseCshort = _T("Native_PhaseCshort");
	g_sLangTxt_Native_PhaseCshort = _T("C相短路");
	g_sLangID_Native_PhaseABCshort = _T("Native_PhaseABCshort");
	g_sLangTxt_Native_PhaseABCshort = _T("ABC相短路");

	// 第八周许
	g_sLangID_Native_ExceptionMsgSet = _T("Native_ExceptionMsgSet");
	g_sLangTxt_Native_ExceptionMsgSet = _T("异常报文设置");
	g_sLangID_Native_CharacteristicGraph = _T("Native_CharacteristicGraph");
	g_sLangTxt_Native_CharacteristicGraph = _T("特性图");
	g_sLangID_Native_OV1SetValue = _T("Native_OV1SetValue");
	g_sLangTxt_Native_OV1SetValue = _T("过压I段定值");
	g_sLangID_Native_OV2SetValue = _T("Native_OV2SetValue");
	g_sLangTxt_Native_OV2SetValue = _T("过压II段定值");
	g_sLangID_Native_OV3SetValue = _T("Native_OV3SetValue");
	g_sLangTxt_Native_OV3SetValue = _T("过压III段定值");
	g_sLangID_Native_OV4SetValue = _T("Native_OV4SetValue");
	g_sLangTxt_Native_OV4SetValue = _T("过压IV段定值");
	g_sLangID_Native_OV1Time = _T("Native_OV1Time");
	g_sLangTxt_Native_OV1Time = _T("过压I段时间");
	g_sLangID_Native_OV2Time = _T("Native_OV2Time");
	g_sLangTxt_Native_OV2Time = _T("过压II段时间");
	g_sLangID_Native_OV3Time = _T("Native_OV3Time");
	g_sLangTxt_Native_OV3Time = _T("过压III段时间");
	g_sLangID_Native_OV4Time = _T("Native_OV4Time");
	g_sLangTxt_Native_OV4Time = _T("过压IV段时间");
	g_sLangID_Native_SimBrkDel = _T("Native_SimBrkDel");
	g_sLangTxt_Native_SimBrkDel = _T("是否模拟断路器延时");
	g_sLangID_Native_BrkTripDel = _T("Native_BrkTripDel");
	g_sLangTxt_Native_BrkTripDel = _T("断路器跳闸延时");
	g_sLangID_Native_BrkClsDel = _T("Native_BrkClsDel");
	g_sLangTxt_Native_BrkClsDel = _T("断路器合闸延时");
	g_sLangID_Native_VoltType = _T("Native_VoltType");
	g_sLangTxt_Native_VoltType = _T("电压类型");
	g_sLangID_Native_ActionVoltExpr = _T("Native_ActionVoltExpr");
	g_sLangTxt_Native_ActionVoltExpr = _T("整定动作电压(表达式)");
	g_sLangID_Native_PhaseATime = _T("Native_PhaseATime");
	g_sLangTxt_Native_PhaseATime = _T("A相动作时间");
	g_sLangID_Native_PhaseBTime = _T("Native_PhaseBTime");
	g_sLangTxt_Native_PhaseBTime = _T("B相动作时间");
	g_sLangID_Native_PhaseCTime = _T("Native_PhaseCTime");
	g_sLangTxt_Native_PhaseCTime = _T("C相动作时间");
	g_sLangID_Native_RecloseTime = _T("Native_RecloseTime");
	g_sLangTxt_Native_RecloseTime = _T("重合闸动作时间");
	g_sLangID_Native_InputETime = _T("Native_InputETime");
	g_sLangTxt_Native_InputETime = _T("开入E动作时间");
	g_sLangID_Native_InputFTime = _T("Native_InputFTime");
	g_sLangTxt_Native_InputFTime = _T("开入F动作时间");
	g_sLangID_Native_InputGTime = _T("Native_InputGTime");
	g_sLangTxt_Native_InputGTime = _T("开入G动作时间");
	g_sLangID_Native_InputHTime = _T("Native_InputHTime");
	g_sLangTxt_Native_InputHTime = _T("开入H动作时间");
	g_sLangID_Native_InputADesc = _T("Native_InputADesc");
	g_sLangTxt_Native_InputADesc = _T("开入A动作描述");
	g_sLangID_Native_InputBDesc = _T("Native_InputBDesc");
	g_sLangTxt_Native_InputBDesc = _T("开入B动作描述");
	g_sLangID_Native_InputCDesc = _T("Native_InputCDesc");
	g_sLangTxt_Native_InputCDesc = _T("开入C动作描述");
	g_sLangID_Native_ReclActDesc = _T("Native_ReclActDesc");
	g_sLangTxt_Native_ReclActDesc = _T("重合闸动作描述");
	g_sLangID_Native_PostAccTime = _T("Native_PostAccTime");
	g_sLangTxt_Native_PostAccTime = _T("后加速动作时间");
	g_sLangID_Native_PostAccDesc = _T("Native_PostAccDesc");
	g_sLangTxt_Native_PostAccDesc = _T("后加速动作描述");
	g_sLangID_Native_ActShortCur = _T("Native_ActShortCur");
	g_sLangTxt_Native_ActShortCur = _T("实际短路电流");
	g_sLangID_Native_ActShortVol = _T("Native_ActShortVol");
	g_sLangTxt_Native_ActShortVol = _T("实际短路电压");
	g_sLangID_Native_OverVoltVal = _T("Native_OverVoltVal");
	g_sLangTxt_Native_OverVoltVal = _T("过压值");
	g_sLangID_Native_UaInitVal = _T("Native_UaInitVal");
	g_sLangTxt_Native_UaInitVal = _T("Ua初值");
	g_sLangID_Native_UbInitVal = _T("Native_UbInitVal");
	g_sLangTxt_Native_UbInitVal = _T("Ub初值");
	g_sLangID_Native_UcInitVal = _T("Native_UcInitVal");
	g_sLangTxt_Native_UcInitVal = _T("Uc初值");
	g_sLangID_Native_UzInitVal = _T("Native_UzInitVal");
	g_sLangTxt_Native_UzInitVal = _T("Uz初值");
	g_sLangID_Native_IaInitVal = _T("Native_IaInitVal");
	g_sLangTxt_Native_IaInitVal = _T("Ia初值");
	g_sLangID_Native_IbInitVal = _T("Native_IbInitVal");
	g_sLangTxt_Native_IbInitVal = _T("Ib初值");
	g_sLangID_Native_IcInitVal = _T("Native_IcInitVal");
	g_sLangTxt_Native_IcInitVal = _T("Ic初值");
	g_sLangID_Native_CurveSegments = _T("Native_CurveSegments");
	g_sLangTxt_Native_CurveSegments = _T("曲线段数");
	g_sLangID_Native_VarChnl = _T("Native_VarChnl");
	g_sLangTxt_Native_VarChnl = _T("递变通道");
	g_sLangID_Native_TimingCurve = _T("Native_TimingCurve");
	g_sLangTxt_Native_TimingCurve = _T("计时曲线");
	g_sLangID_Native_VarSel = _T("Native_VarSel");
	g_sLangTxt_Native_VarSel = _T("递变选择");
	g_sLangID_Native_TransType = _T("Native_TransType");
	g_sLangTxt_Native_TransType = _T("递变类型(0-斜率1-上升时间2-初值)");
	g_sLangID_Native_CurveSelect = _T("Native_CurveSelect");
	g_sLangTxt_Native_CurveSelect = _T("递变曲线选择");
	g_sLangID_Native_StartValue = _T("Native_StartValue");
	g_sLangTxt_Native_StartValue = _T("递变始值");
	g_sLangID_Native_EndValue = _T("Native_EndValue");
	g_sLangTxt_Native_EndValue = _T("递变终值");
	g_sLangID_Native_StepSize = _T("Native_StepSize");
	g_sLangTxt_Native_StepSize = _T("递变步长");
	g_sLangID_Native_Curve = _T("Native_Curve");
	g_sLangTxt_Native_Curve = _T("曲线");
	g_sLangID_Native_Slope = _T("Native_Slope");
	g_sLangTxt_Native_Slope = _T("斜率(A/ms)");
	g_sLangID_Native_OutputTimems = _T("Native_OutputTimems");
	g_sLangTxt_Native_OutputTimems = _T("输出时间(ms)");
	g_sLangID_Native_SearchStart = _T("Native_SearchStart");
	g_sLangTxt_Native_SearchStart = _T("搜索起点");
	g_sLangID_Native_CurrentValue = _T("Native_CurrentValue");
	g_sLangTxt_Native_CurrentValue = _T("当前值");
	g_sLangID_Native_SearchEnd = _T("Native_SearchEnd");
	g_sLangTxt_Native_SearchEnd = _T("搜索终点");
	g_sLangID_Native_SearchLen = _T("Native_SearchLen");
	g_sLangTxt_Native_SearchLen = _T("搜索区间长度");
	g_sLangID_Native_AutoSearch = _T("Native_AutoSearch");
	g_sLangTxt_Native_AutoSearch = _T("是否自动搜索");
	g_sLangID_Native_ComplexBrakeCurrent = _T("Native_ComplexBrakeCurrent");
	g_sLangTxt_Native_ComplexBrakeCurrent = _T("复式制动电流(Ir-Id)");
	g_sLangID_Native_DiffCurrentSetVal = _T("Native_DiffCurrentSetVal");
	g_sLangTxt_Native_DiffCurrentSetVal = _T("差动电流定值");
	g_sLangID_Native_DiffType = _T("Native_DiffType");
	g_sLangTxt_Native_DiffType = _T("差动类别(0-大差试验 1-小差试验)");
	g_sLangID_Native_UaAmplitude = _T("Native_UaAmplitude");
	g_sLangTxt_Native_UaAmplitude = _T("Ua幅值");
	g_sLangID_Native_UbAmplitude = _T("Native_UbAmplitude");
	g_sLangTxt_Native_UbAmplitude = _T("Ub幅值");
	g_sLangID_Native_UcAmplitude = _T("Native_UcAmplitude");
	g_sLangTxt_Native_UcAmplitude = _T("Uc幅值");
	g_sLangID_Native_UaPhase = _T("Native_UaPhase");
	g_sLangTxt_Native_UaPhase = _T("Ua相位");
	g_sLangID_Native_UbPhase = _T("Native_UbPhase");
	g_sLangTxt_Native_UbPhase = _T("Ub相位");
	g_sLangID_Native_UcPhase = _T("Native_UcPhase");
	g_sLangTxt_Native_UcPhase = _T("Uc相位");
	g_sLangID_Native_Gap1TARatio = _T("Native_Gap1TARatio");
	g_sLangTxt_Native_Gap1TARatio = _T("间隔1TA变比");
	g_sLangID_Native_Gap2TARatio = _T("Native_Gap2TARatio");
	g_sLangTxt_Native_Gap2TARatio = _T("间隔2TA变比");
	g_sLangID_Native_Gap3TARatio = _T("Native_Gap3TARatio");
	g_sLangTxt_Native_Gap3TARatio = _T("间隔3TA变比");
	g_sLangID_Native_MaxTARatio = _T("Native_MaxTARatio");
	g_sLangTxt_Native_MaxTARatio = _T("最大TA变比");
	g_sLangID_Native_DiffThreshCurrent = _T("Native_DiffThreshCurrent");
	g_sLangTxt_Native_DiffThreshCurrent = _T("差动门槛电流");
	g_sLangID_Native_HighCompRatioCoef = _T("Native_HighCompRatioCoef");
	g_sLangTxt_Native_HighCompRatioCoef = _T("复式比率系数高值");
	g_sLangID_Native_LowCompRatioCoef = _T("Native_LowCompRatioCoef");
	g_sLangTxt_Native_LowCompRatioCoef = _T("复式比率系数低值");
	g_sLangID_Native_DiffActionVal = _T("Native_DiffActionVal");
	g_sLangTxt_Native_DiffActionVal = _T("差动动作值");
	g_sLangID_Native_CurrSearchVal = _T("Native_CurrSearchVal");
	g_sLangTxt_Native_CurrSearchVal = _T("当前搜索值");
	g_sLangID_Native_DiffActionDesc = _T("Native_DiffActionDesc");
	g_sLangTxt_Native_DiffActionDesc = _T("差动动作描述");
	g_sLangID_Native_VoltLockElem = _T("Native_VoltLockElem");
	g_sLangTxt_Native_VoltLockElem = _T("电压闭锁元件");
	g_sLangID_Native_LockVoltValue = _T("Native_LockVoltValue");
	g_sLangTxt_Native_LockVoltValue = _T("闭锁电压值");
	g_sLangID_Native_BrkCoeffType = _T("Native_BrkCoeffType");
	g_sLangTxt_Native_BrkCoeffType = _T("比率制动系数类别(0-低值 1-高值)");
	g_sLangID_Native_DiffCurrentIds = _T("Native_DiffCurrentIds");
	g_sLangTxt_Native_DiffCurrentIds = _T("差动电流Id(表达式)");
	g_sLangID_Native_CompBrakeCurr = _T("Native_CompBrakeCurr");
	g_sLangTxt_Native_CompBrakeCurr = _T("复式制动电流(Ir-Id)(表达式)");
	g_sLangID_Native_IrBrakeEq = _T("Native_IrBrakeEq");
	g_sLangTxt_Native_IrBrakeEq = _T("Ir制动方程");
	g_sLangID_Native_FirstVoltNormOutput = _T("Native_FirstVoltNormOutput");
	g_sLangTxt_Native_FirstVoltNormOutput = _T("第一组电压常态输出值");
	g_sLangID_Native_SecondVoltNormOutput = _T("Native_SecondVoltNormOutput");
	g_sLangTxt_Native_SecondVoltNormOutput = _T("第二组电压常态输出值");
	g_sLangID_Native_VoltFaultState = _T("Native_VoltFaultState");
	g_sLangTxt_Native_VoltFaultState = _T("第一组电压故障态故障相输出值");
	g_sLangID_Native_VoltFaultState2 = _T("Native_VoltFaultState2");
	g_sLangTxt_Native_VoltFaultState2 = _T("第二组电压故障态故障相输出值");
	g_sLangID_Native_BalanceMode = _T("Native_BalanceMode");
	g_sLangTxt_Native_BalanceMode = _T("平衡系数设置方式");
	g_sLangID_Native_HVBalanceCoeff = _T("Native_HVBalanceCoeff");
	g_sLangTxt_Native_HVBalanceCoeff = _T("高压侧差动平衡系数设置值");
	g_sLangID_Native_MVBalanceCoeff = _T("Native_MVBalanceCoeff");
	g_sLangTxt_Native_MVBalanceCoeff = _T("中压侧差动平衡系数设置值");
	g_sLangID_Native_LVBalanceCoeff = _T("Native_LVBalanceCoeff");
	g_sLangTxt_Native_LVBalanceCoeff = _T("低压侧差动平衡系数设置值");
	g_sLangID_Native_HVCTRatio = _T("Native_HVCTRatio");
	g_sLangTxt_Native_HVCTRatio = _T("高压侧CT变比");
	g_sLangID_Native_MVCTRatio = _T("Native_MVCTRatio");
	g_sLangTxt_Native_MVCTRatio = _T("中压侧CT变比");
	g_sLangID_Native_LVCTRatio = _T("Native_LVCTRatio");
	g_sLangTxt_Native_LVCTRatio = _T("低压侧CT变比");
	g_sLangID_Native_TestCoil = _T("Native_TestCoil");
	g_sLangTxt_Native_TestCoil = _T("参与试验的绕组");
	g_sLangID_Native_ProtPhaseCorr = _T("Native_ProtPhaseCorr");
	g_sLangTxt_Native_ProtPhaseCorr = _T("保护内部相位校正方式");
	g_sLangID_Native_BaseCurrSet = _T("Native_BaseCurrSet");
	g_sLangTxt_Native_BaseCurrSet = _T("基准电流设定值");
	g_sLangID_Native_DiffQuickBreakCurr = _T("Native_DiffQuickBreakCurr");
	g_sLangTxt_Native_DiffQuickBreakCurr = _T("差动速断电流");
	g_sLangID_Native_RatioBrakeTurnPts = _T("Native_RatioBrakeTurnPts");
	g_sLangTxt_Native_RatioBrakeTurnPts = _T("比率制动拐点数");
	g_sLangID_Native_RatioBrakeTurn1Curr = _T("Native_RatioBrakeTurn1Curr");
	g_sLangTxt_Native_RatioBrakeTurn1Curr = _T("比率制动拐点1电流");
	g_sLangID_Native_RatioBrakeTurn2Curr = _T("Native_RatioBrakeTurn2Curr");
	g_sLangTxt_Native_RatioBrakeTurn2Curr = _T("比率制动拐点2电流");
	g_sLangID_Native_RatioBrakeTurn3Curr = _T("Native_RatioBrakeTurn3Curr");
	g_sLangTxt_Native_RatioBrakeTurn3Curr = _T("比率制动拐点3电流");
	g_sLangID_Native_HarmonicBrakeCoeff = _T("Native_HarmonicBrakeCoeff");
	g_sLangTxt_Native_HarmonicBrakeCoeff = _T("谐波制动系数定值");
	g_sLangID_Native_HarmonicBrakeDesc = _T("Native_HarmonicBrakeDesc");
	g_sLangTxt_Native_HarmonicBrakeDesc = _T("谐波制动系数描述");
	g_sLangID_Native_PhaseACurrent = _T("Native_PhaseACurrent");
	g_sLangTxt_Native_PhaseACurrent = _T("A相基波电流");
	g_sLangID_Native_PhaseBCurrent = _T("Native_PhaseBCurrent");
	g_sLangTxt_Native_PhaseBCurrent = _T("B相基波电流");
	g_sLangID_Native_PhaseCCurrent = _T("Native_PhaseCCurrent");
	g_sLangTxt_Native_PhaseCCurrent = _T("C相基波电流");
	g_sLangID_Native_PhaseAHarmCur = _T("Native_PhaseAHarmCur");
	g_sLangTxt_Native_PhaseAHarmCur = _T("A相谐波电流");
	g_sLangID_Native_BHarmonicCurrent = _T("Native_BHarmonicCurrent");
	g_sLangTxt_Native_BHarmonicCurrent = _T("B相谐波电流");
	g_sLangID_Native_CHarmonicCurrent = _T("Native_CHarmonicCurrent");
	g_sLangTxt_Native_CHarmonicCurrent = _T("C相谐波电流");
	g_sLangID_Native_FirstGroupVoltageOut = _T("Native_FirstGroupVoltageOut");
	g_sLangTxt_Native_FirstGroupVoltageOut = _T("第一组电压输出值");
	g_sLangID_Native_SecondGroupVoltageOut = _T("Native_SecondGroupVoltageOut");
	g_sLangTxt_Native_SecondGroupVoltageOut = _T("第二组电压输出值");
	g_sLangID_Native_HVCTConnectionMode = _T("Native_HVCTConnectionMode");
	g_sLangTxt_Native_HVCTConnectionMode = _T("高压侧CT接线方式");
	g_sLangID_Native_BalanceCoeffCalcMethod = _T("Native_BalanceCoeffCalcMethod");
	g_sLangTxt_Native_BalanceCoeffCalcMethod = _T("平衡系数计算方法");
	g_sLangID_Native_UnderTestValue = _T("Native_UnderTestValue");
	g_sLangTxt_Native_UnderTestValue = _T("待测定值");
	g_sLangID_Native_FaultImpedanceAngle = _T("Native_FaultImpedanceAngle");
	g_sLangTxt_Native_FaultImpedanceAngle = _T("故障阻抗角");
	g_sLangID_Native_PTLineSimulate = _T("Native_PTLineSimulate");
	g_sLangTxt_Native_PTLineSimulate = _T("是否模拟PT断线");
	g_sLangID_Native_PTLineSimPhase = _T("Native_PTLineSimPhase");
	g_sLangTxt_Native_PTLineSimPhase = _T("模拟PT断线相别");
	g_sLangID_Native_VarStartValue = _T("Native_VarStartValue");
	g_sLangTxt_Native_VarStartValue = _T("变化始值(表达式)");
	g_sLangID_Native_VarEndValue = _T("Native_VarEndValue");
	g_sLangTxt_Native_VarEndValue = _T("变化终值(表达式)");
	g_sLangID_Native_StepTime = _T("Native_StepTime");
	g_sLangTxt_Native_StepTime = _T("步长时间(表达式)");
	g_sLangID_Native_ShortVolt = _T("Native_ShortVolt");
	g_sLangTxt_Native_ShortVolt = _T("短路电压(表达式)");
	g_sLangID_Native_ShortCurr = _T("Native_ShortCurr");
	g_sLangTxt_Native_ShortCurr = _T("短路电流(表达式)");
	g_sLangID_Native_BoundaryAngle1 = _T("Native_BoundaryAngle1");
	g_sLangTxt_Native_BoundaryAngle1 = _T("边界角1(兼容)");
	g_sLangID_Native_BoundaryAngle2 = _T("Native_BoundaryAngle2");
	g_sLangTxt_Native_BoundaryAngle2 = _T("边界角2(兼容)");
	g_sLangID_Native_StepTimes = _T("Native_StepTimes");
	g_sLangTxt_Native_StepTimes = _T("步长时间");
	g_sLangID_Native_ShortCircuit = _T("Native_ShortCircuit");
	g_sLangTxt_Native_ShortCircuit = _T("短路电流");
	g_sLangID_Native_ImpedanceAngles = _T("Native_ImpedanceAngles");
	g_sLangTxt_Native_ImpedanceAngles = _T("阻抗角");
	g_sLangID_Native_TestReturnValue = _T("Native_TestReturnValue");
	g_sLangTxt_Native_TestReturnValue = _T("是否测试返回值");
	g_sLangID_Native_LowVoltagev = _T("Native_LowVoltagev");
	g_sLangTxt_Native_LowVoltagev = _T("低电压(V)");
	g_sLangID_Native_NegativeSeqVolt = _T("Native_NegativeSeqVolt");
	g_sLangTxt_Native_NegativeSeqVolt = _T("负序电压(V)");
	g_sLangID_Native_ActionCurrent = _T("Native_ActionCurrent");
	g_sLangTxt_Native_ActionCurrent = _T("动作电流(A)");
	g_sLangID_Native_DelayTimes = _T("Native_DelayTimes");
	g_sLangTxt_Native_DelayTimes = _T("延时时间(s)");
	g_sLangID_Native_ActionAreaSize = _T("Native_ActionAreaSize");
	g_sLangTxt_Native_ActionAreaSize = _T("动作区大小(°)");
	g_sLangID_Native_ImpedanceAnglexp = _T("Native_ImpedanceAnglexp");
	g_sLangTxt_Native_ImpedanceAnglexp = _T("阻抗角(表达式)");
	g_sLangID_Native_TestOutMode = _T("Native_TestOutMode");
	g_sLangTxt_Native_TestOutMode = _T("测试仪输出模式");
	g_sLangID_Native_RatedVoltVal = _T("Native_RatedVoltVal");
	g_sLangTxt_Native_RatedVoltVal = _T("额定电压值");
	g_sLangID_Native_RatedCurrVal = _T("Native_RatedCurrVal");
	g_sLangTxt_Native_RatedCurrVal = _T("额定电流值");
	g_sLangID_Native_FirstPTVal = _T("Native_FirstPTVal");
	g_sLangTxt_Native_FirstPTVal = _T("第%d组PT一次值");
	g_sLangID_Native_SecPTVal = _T("Native_SecPTVal");
	g_sLangTxt_Native_SecPTVal = _T("第%d组PT二次值");
	g_sLangID_Native_FirstCTVal = _T("Native_FirstCTVal");
	g_sLangTxt_Native_FirstCTVal = _T("第%d组CT一次值");
	g_sLangID_Native_SecCTVal = _T("Native_SecCTVal");
	g_sLangTxt_Native_SecCTVal = _T("第%d组CT二次值");
	g_sLangID_Native_MsgFormat = _T("Native_MsgFormat");
	g_sLangTxt_Native_MsgFormat = _T("报文输出格式");
	g_sLangID_Native_WeakSigOutSet = _T("Native_WeakSigOutSet");
	g_sLangTxt_Native_WeakSigOutSet = _T("弱信号输出设置");
	g_sLangID_Native_1588RecvOptPort = _T("Native_1588RecvOptPort");
	g_sLangTxt_Native_1588RecvOptPort = _T("1588接收光口");
	g_sLangID_Native_1588SyncMech = _T("Native_1588SyncMech");
	g_sLangTxt_Native_1588SyncMech = _T("1588同步机制");
	g_sLangID_Native_ParamSel = _T("Native_ParamSel");
	g_sLangTxt_Native_ParamSel = _T("参数设置选择(0-一次值,1-二次值)");
	g_sLangID_Native_MsgOutSel = _T("Native_MsgOutSel");
	g_sLangTxt_Native_MsgOutSel = _T("报文输出选择(0-一次值,1-二次值)");
	g_sLangID_Native_BCodeLogics = _T("Native_BCodeLogics");
	g_sLangTxt_Native_BCodeLogics = _T("B码逻辑(0-正逻辑,1-负逻辑)");
	g_sLangID_Native_FiberConn = _T("Native_FiberConn");
	g_sLangTxt_Native_FiberConn = _T("光纤连接方式(0-双回,1-单回)");
	g_sLangID_Native_GroupCurrMod = _T("Native_GroupCurrMod");
	g_sLangTxt_Native_GroupCurrMod = _T("组电流模块");
	g_sLangID_Native_CurrModPos = _T("Native_CurrModPos");
	g_sLangTxt_Native_CurrModPos = _T("电流模块位置");
	g_sLangID_Native_CurrModGearVal = _T("Native_CurrModGearVal");
	g_sLangTxt_Native_CurrModGearVal = _T("电流模块档位值");
	g_sLangID_Native_CurrChanMaxVolt = _T("Native_CurrChanMaxVolt");
	g_sLangTxt_Native_CurrChanMaxVolt = _T("电流通道最大端口电压");
	g_sLangID_Native_MergeCurrTerm = _T("Native_MergeCurrTerm");
	g_sLangTxt_Native_MergeCurrTerm = _T("合并电流端子");
	g_sLangID_Native_CurrModCount = _T("Native_CurrModCount");
	g_sLangTxt_Native_CurrModCount = _T("电流模块数量");
	g_sLangID_Native_WirelessNet = _T("Native_WirelessNet");
	g_sLangTxt_Native_WirelessNet = _T("无线网络");
	g_sLangID_Native_WiredNet = _T("Native_WiredNet");
	g_sLangTxt_Native_WiredNet = _T("有线网络");
	g_sLangID_Native_LcdBacklightTime = _T("Native_LcdBacklightTime");
	g_sLangTxt_Native_LcdBacklightTime = _T("Lcd背光时长");
	g_sLangID_Native_TouchSensitivity = _T("Native_TouchSensitivity");
	g_sLangTxt_Native_TouchSensitivity = _T("触摸灵敏度(ms)");
	g_sLangID_Native_CurrentActionError = _T("Native_CurrentActionError");
	g_sLangTxt_Native_CurrentActionError = _T("电流动作值绝对误差(A)");
	g_sLangID_Native_CurrentActionRelError = _T("Native_CurrentActionRelError");
	g_sLangTxt_Native_CurrentActionRelError = _T("电流动作值相对误差(%)");
	g_sLangID_Native_VoltageActionError = _T("Native_VoltageActionError");
	g_sLangTxt_Native_VoltageActionError = _T("电压动作值绝对误差(V)");
	g_sLangID_Native_VoltageActionRelError = _T("Native_VoltageActionRelError");
	g_sLangTxt_Native_VoltageActionRelError = _T("电压动作值相对误差(%)");
	g_sLangID_Native_ImpedanceActionError = _T("Native_ImpedanceActionError");
	g_sLangTxt_Native_ImpedanceActionError = _T("阻抗动作值绝对误差(Ω)");
	g_sLangID_Native_ImpedanceActionRelError = _T("Native_ImpedanceActionRelError");
	g_sLangTxt_Native_ImpedanceActionRelError = _T("阻抗动作值相对误差(%)");
	g_sLangID_Native_ActionTimeAbsError = _T("Native_ActionTimeAbsError");
	g_sLangTxt_Native_ActionTimeAbsError = _T("动作时间绝对误差(s)");
	g_sLangID_Native_ActionTimeRelError = _T("Native_ActionTimeRelError");
	g_sLangTxt_Native_ActionTimeRelError = _T("动作时间相对误差(%)");
	g_sLangID_Native_PhaseErrorValue = _T("Native_PhaseErrorValue");
	g_sLangTxt_Native_PhaseErrorValue = _T("相位误差值(°)");
	g_sLangID_Native_FreqErrorValue = _T("Native_FreqErrorValue");
	g_sLangTxt_Native_FreqErrorValue = _T("频率误差值(Hz)");
	g_sLangID_Native_VoltSlipErrorValue = _T("Native_VoltSlipErrorValue");
	g_sLangTxt_Native_VoltSlipErrorValue = _T("电压滑差误差值(V/s)");
	g_sLangID_Native_FreqSlipErrorValue = _T("Native_FreqSlipErrorValue");
	g_sLangTxt_Native_FreqSlipErrorValue = _T("频率滑差误差值(Hz/s)");
	g_sLangID_Native_DiffRatioBrakeAbsError = _T("Native_DiffRatioBrakeAbsError");
	g_sLangTxt_Native_DiffRatioBrakeAbsError = _T("差动比率制动系数绝对误差");
	g_sLangID_Native_DiffRatioBrakeRelError = _T("Native_DiffRatioBrakeRelError");
	g_sLangTxt_Native_DiffRatioBrakeRelError = _T("差动比率制动系数相对误差(%)");
	g_sLangID_Native_DiffHarmonicBrakeAbsError = _T("Native_DiffHarmonicBrakeAbsError");
	g_sLangTxt_Native_DiffHarmonicBrakeAbsError = _T("差动谐波制动系数绝对误差");
	g_sLangID_Native_DiffHarmonicBrakeRelError = _T("Native_DiffHarmonicBrakeRelError");
	g_sLangTxt_Native_DiffHarmonicBrakeRelError = _T("差动谐波制动系数相对误差(%)");
	g_sLangID_Native_AuxDcVoltageValue = _T("Native_AuxDcVoltageValue");
	g_sLangTxt_Native_AuxDcVoltageValue = _T("辅助直流电压值");
	g_sLangID_Native_AuxDcCurrentValue = _T("Native_AuxDcCurrentValue");
	g_sLangTxt_Native_AuxDcCurrentValue = _T("辅助直流电流值");
	g_sLangID_Native_VoltageRatioPrimary1 = _T("Native_VoltageRatioPrimary1");
	g_sLangTxt_Native_VoltageRatioPrimary1 = _T("电压变比一次值(第1组)");
	g_sLangID_Native_VoltageRatioPrimary2 = _T("Native_VoltageRatioPrimary2");
	g_sLangTxt_Native_VoltageRatioPrimary2 = _T("电压变比一次值(第2组)");
	g_sLangID_Native_VoltageRatioPrimary3 = _T("Native_VoltageRatioPrimary3");
	g_sLangTxt_Native_VoltageRatioPrimary3 = _T("电压变比一次值(第3组)");
	g_sLangID_Native_VoltageRatioPrimary4 = _T("Native_VoltageRatioPrimary4");
	g_sLangTxt_Native_VoltageRatioPrimary4 = _T("电压变比一次值(第4组)");
	g_sLangID_Native_VoltageRatioPrimary5 = _T("Native_VoltageRatioPrimary5");
	g_sLangTxt_Native_VoltageRatioPrimary5 = _T("电压变比一次值(第5组)");
	g_sLangID_Native_VoltageRatioPrimary6 = _T("Native_VoltageRatioPrimary6");
	g_sLangTxt_Native_VoltageRatioPrimary6 = _T("电压变比一次值(第6组)");
	g_sLangID_Native_VoltageRatioSecondary1 = _T("Native_VoltageRatioSecondary1");
	g_sLangTxt_Native_VoltageRatioSecondary1 = _T("电压变比二次值(第1组)");
	g_sLangID_Native_VoltageRatioSecondary2 = _T("Native_VoltageRatioSecondary2");
	g_sLangTxt_Native_VoltageRatioSecondary2 = _T("电压变比二次值(第2组)");
	g_sLangID_Native_VoltageRatioSecondary3 = _T("Native_VoltageRatioSecondary3");
	g_sLangTxt_Native_VoltageRatioSecondary3 = _T("电压变比二次值(第3组)");
	g_sLangID_Native_VoltageRatioSecondary4 = _T("Native_VoltageRatioSecondary4");
	g_sLangTxt_Native_VoltageRatioSecondary4 = _T("电压变比二次值(第4组)");
	g_sLangID_Native_VoltageRatioSecondary5 = _T("Native_VoltageRatioSecondary5");
	g_sLangTxt_Native_VoltageRatioSecondary5 = _T("电压变比二次值(第5组)");
	g_sLangID_Native_VoltageRatioSecondary6 = _T("Native_VoltageRatioSecondary6");
	g_sLangTxt_Native_VoltageRatioSecondary6 = _T("电压变比二次值(第6组)");
	g_sLangID_Native_CurrentRatioPrimary1 = _T("Native_CurrentRatioPrimary1");
	g_sLangTxt_Native_CurrentRatioPrimary1 = _T("电流变比一次值(第1组)");
	g_sLangID_Native_CurrentRatioPrimary2 = _T("Native_CurrentRatioPrimary2");
	g_sLangTxt_Native_CurrentRatioPrimary2 = _T("电流变比一次值(第2组)");
	g_sLangID_Native_CurrentRatioPrimary3 = _T("Native_CurrentRatioPrimary3");
	g_sLangTxt_Native_CurrentRatioPrimary3 = _T("电流变比一次值(第3组)");
	g_sLangID_Native_CurrentRatioPrimary4 = _T("Native_CurrentRatioPrimary4");
	g_sLangTxt_Native_CurrentRatioPrimary4 = _T("电流变比一次值(第4组)");
	g_sLangID_Native_CurrentRatioPrimary5 = _T("Native_CurrentRatioPrimary5");
	g_sLangTxt_Native_CurrentRatioPrimary5 = _T("电流变比一次值(第5组)");
	g_sLangID_Native_CurrentRatioPrimary6 = _T("Native_CurrentRatioPrimary6");
	g_sLangTxt_Native_CurrentRatioPrimary6 = _T("电流变比一次值(第6组)");
	g_sLangID_Native_CurrentRatioSecondary1 = _T("Native_CurrentRatioSecondary1");
	g_sLangTxt_Native_CurrentRatioSecondary1 = _T("电流变比二次值(第1组)");
	g_sLangID_Native_CurrentRatioSecondary2 = _T("Native_CurrentRatioSecondary2");
	g_sLangTxt_Native_CurrentRatioSecondary2 = _T("电流变比二次值(第2组)");
	g_sLangID_Native_CurrentRatioSecondary3 = _T("Native_CurrentRatioSecondary3");
	g_sLangTxt_Native_CurrentRatioSecondary3 = _T("电流变比二次值(第3组)");
	g_sLangID_Native_CurrentRatioSecondary4 = _T("Native_CurrentRatioSecondary4");
	g_sLangTxt_Native_CurrentRatioSecondary4 = _T("电流变比二次值(第4组)");
	g_sLangID_Native_CurrentRatioSecondary5 = _T("Native_CurrentRatioSecondary5");
	g_sLangTxt_Native_CurrentRatioSecondary5 = _T("电流变比二次值(第5组)");
	g_sLangID_Native_CurrentRatioSecondary6 = _T("Native_CurrentRatioSecondary6");
	g_sLangTxt_Native_CurrentRatioSecondary6 = _T("电流变比二次值(第6组)");
	g_sLangID_Native_OutputAnalog = _T("Native_OutputAnalog");
	g_sLangTxt_Native_OutputAnalog = _T("输出模拟量");
	g_sLangID_Native_OutputDigital = _T("Native_OutputDigital");
	g_sLangTxt_Native_OutputDigital = _T("输出数字量");
	g_sLangID_Native_OutputWeakSig = _T("Native_OutputWeakSig");
	g_sLangTxt_Native_OutputWeakSig = _T("输出弱信号");
	g_sLangID_Native_RatedLineVolt = _T("Native_RatedLineVolt");
	g_sLangTxt_Native_RatedLineVolt = _T("额定线电压值");
	g_sLangID_Native_RatedZeroVolt = _T("Native_RatedZeroVolt");
	g_sLangTxt_Native_RatedZeroVolt = _T("额定零序电压");
	g_sLangID_Native_RatedZeroCurr = _T("Native_RatedZeroCurr");
	g_sLangTxt_Native_RatedZeroCurr = _T("额定零序电流");
	g_sLangID_Native_StartOverloadDelay = _T("Native_StartOverloadDelay");
	g_sLangTxt_Native_StartOverloadDelay = _T("开始过载延时(s)");
	g_sLangID_Native_CheckTestEndHeartbeat = _T("Native_CheckTestEndHeartbeat");
	g_sLangTxt_Native_CheckTestEndHeartbeat = _T("检测测试端心跳");
	g_sLangID_Native_UseAnalogCapture = _T("Native_UseAnalogCapture");
	g_sLangTxt_Native_UseAnalogCapture = _T("使用模拟量采集");
	g_sLangID_Native_UseDigitalCapture = _T("Native_UseDigitalCapture");
	g_sLangTxt_Native_UseDigitalCapture = _T("使用数字量采集");
	g_sLangID_Native_UseSmallSignalCapture = _T("Native_UseSmallSignalCapture");
	g_sLangTxt_Native_UseSmallSignalCapture = _T("使用小信号采集");
	g_sLangID_Native_DigitalCaptureMsgType = _T("Native_DigitalCaptureMsgType");
	g_sLangTxt_Native_DigitalCaptureMsgType = _T("数字量采集报文类型");
	g_sLangID_Native_BCodeReceiveLogic = _T("Native_BCodeReceiveLogic");
	g_sLangTxt_Native_BCodeReceiveLogic = _T("B码接收逻辑(0-正逻辑,1-负逻辑)");
	g_sLangID_Native_ReportExtInQty = _T("Native_ReportExtInQty");
	g_sLangTxt_Native_ReportExtInQty = _T("报告需要的扩展开入数量(0-自动关联开关量扩展模块)");
	g_sLangID_Native_BaseReportTimeZone = _T("Native_BaseReportTimeZone");
	g_sLangTxt_Native_BaseReportTimeZone = _T("底层上报数据的时区");
	g_sLangID_Native_GPStoBCodeUserTZ = _T("Native_GPStoBCodeUserTZ");
	g_sLangTxt_Native_GPStoBCodeUserTZ = _T("GPS转B码时使用用户设置时区");
	g_sLangID_Native_MachineFanMode = _T("Native_MachineFanMode");
	g_sLangTxt_Native_MachineFanMode = _T("机器散热风扇模式(0-静音,1-正常)");
	g_sLangID_Native_AmplitudeGradual = _T("Native_AmplitudeGradual");
	g_sLangTxt_Native_AmplitudeGradual = _T("幅值递变标识");
	g_sLangID_Native_AmplitudeEndValue = _T("Native_AmplitudeEndValue");
	g_sLangTxt_Native_AmplitudeEndValue = _T("幅值递变终值");
	g_sLangID_Native_AmplitudeStep = _T("Native_AmplitudeStep");
	g_sLangTxt_Native_AmplitudeStep = _T("幅值递变步长");
	g_sLangID_Native_PhaseFlag = _T("Native_PhaseFlag");
	g_sLangTxt_Native_PhaseFlag = _T("相位递变标识");
	g_sLangID_Native_PhaseEndVal = _T("Native_PhaseEndVal");
	g_sLangTxt_Native_PhaseEndVal = _T("相位递变终值");
	g_sLangID_Native_PhaseStep = _T("Native_PhaseStep");
	g_sLangTxt_Native_PhaseStep = _T("相位递变步长");
	g_sLangID_Native_FreqFlag = _T("Native_FreqFlag");
	g_sLangTxt_Native_FreqFlag = _T("频率递变标识");
	g_sLangID_Native_FreqEnd = _T("Native_FreqEnd");
	g_sLangTxt_Native_FreqEnd = _T("频率递变终值");
	g_sLangID_Native_FreqStep = _T("Native_FreqStep");
	g_sLangTxt_Native_FreqStep = _T("频率递变步长");
	g_sLangID_Native_IsSelected = _T("Native_IsSelected");
	g_sLangTxt_Native_IsSelected = _T("是否选择");
	g_sLangID_Native_OpenState = _T("Native_OpenState");
	g_sLangTxt_Native_OpenState = _T("开出状态");
	g_sLangID_Native_DCOverlay = _T("Native_DCOverlay");
	g_sLangTxt_Native_DCOverlay = _T("是否叠加直流分量");
	g_sLangID_Native_DCDampTime = _T("Native_DCDampTime");
	g_sLangTxt_Native_DCDampTime = _T("直流分量的衰减时间常数");
	g_sLangID_Native_EnableEval = _T("Native_EnableEval");
	g_sLangTxt_Native_EnableEval = _T("使能评估");
	g_sLangID_Native_TimeStartState = _T("Native_TimeStartState");
	g_sLangTxt_Native_TimeStartState = _T("计时起点_状态");
	g_sLangID_Native_TimeEndState = _T("Native_TimeEndState");
	g_sLangTxt_Native_TimeEndState = _T("计时终点_状态");
	g_sLangID_Native_TimeStartInput = _T("Native_TimeStartInput");
	g_sLangTxt_Native_TimeStartInput = _T("计时起点_开入");
	g_sLangID_Native_TimeEndInput = _T("Native_TimeEndInput");
	g_sLangTxt_Native_TimeEndInput = _T("计时终点_开入");
	g_sLangID_Native_AbsErrorLimit = _T("Native_AbsErrorLimit");
	g_sLangTxt_Native_AbsErrorLimit = _T("绝对误差限");
	g_sLangID_Native_RelErrorLimit = _T("Native_RelErrorLimit");
	g_sLangTxt_Native_RelErrorLimit = _T("相对误差限");
	g_sLangID_Native_JudgeLogic = _T("Native_JudgeLogic");
	g_sLangTxt_Native_JudgeLogic = _T("判断逻辑");
	g_sLangID_Native_StepChangeID = _T("Native_StepChangeID");
	g_sLangTxt_Native_StepChangeID = _T("递变动作步数标识");
	g_sLangID_Native_CustomActTime = _T("Native_CustomActTime");
	g_sLangTxt_Native_CustomActTime = _T("自定义动作时间");
	g_sLangID_Native_AbsError = _T("Native_AbsError");
	g_sLangTxt_Native_AbsError = _T("自定义动作时间绝对误差");
	g_sLangID_Native_RelError = _T("Native_RelError");
	g_sLangTxt_Native_RelError = _T("自定义动作时间相对误差");
	g_sLangID_Native_CurrLoop = _T("Native_CurrLoop");
	g_sLangTxt_Native_CurrLoop = _T("当前循环的序号");
	g_sLangID_Native_TrigModes = _T("Native_TrigModes");
	g_sLangTxt_Native_TrigModes = _T("触发模式(0-立即运行,1-等待GPS)");
	g_sLangID_Native_HwSelect = _T("Native_HwSelect");
	g_sLangTxt_Native_HwSelect = _T("硬件选择(0-主板8个开出,1-扩展插件)");
	g_sLangID_Native_InAction = _T("Native_InAction");
	g_sLangTxt_Native_InAction = _T("开入动作(0-不记录,1-记录)");
	g_sLangID_Native_TotalTime = _T("Native_TotalTime");
	g_sLangTxt_Native_TotalTime = _T("实验运行总时长(s)");
	g_sLangID_Native_IsEnabled = _T("Native_IsEnabled");
	g_sLangTxt_Native_IsEnabled = _T("是否启用");
	g_sLangID_Native_PreState = _T("Native_PreState");
	g_sLangTxt_Native_PreState = _T("实验前状态值");
	g_sLangID_Native_InitState = _T("Native_InitState");
	g_sLangTxt_Native_InitState = _T("实验中初始状态值");
	g_sLangID_Native_PreCutDur = _T("Native_PreCutDur");
	g_sLangTxt_Native_PreCutDur = _T("实验前断开持续时间(ms)");
	g_sLangID_Native_CloseDur = _T("Native_CloseDur");
	g_sLangTxt_Native_CloseDur = _T("实验中闭合持续时间(ms)");
	g_sLangID_Native_BreakDur = _T("Native_BreakDur");
	g_sLangTxt_Native_BreakDur = _T("实验中断开持续时间(ms)");
	g_sLangID_Native_UzAmp = _T("Native_UzAmp");
	g_sLangTxt_Native_UzAmp = _T("Uz幅值");
	g_sLangID_Native_UzPhase = _T("Native_UzPhase");
	g_sLangTxt_Native_UzPhase = _T("Uz相位");
	g_sLangID_Native_UzFreq = _T("Native_UzFreq");
	g_sLangTxt_Native_UzFreq = _T("Uz频率");
	g_sLangID_Native_I0Amplitude = _T("Native_I0Amplitude");
	g_sLangTxt_Native_I0Amplitude = _T("I0幅值");
	g_sLangID_Native_I0Phase = _T("Native_I0Phase");
	g_sLangTxt_Native_I0Phase = _T("I0相位");
	g_sLangID_Native_I0Frequency = _T("Native_I0Frequency");
	g_sLangTxt_Native_I0Frequency = _T("I0频率");
	g_sLangID_Native_CurrentHighPowerMode = _T("Native_CurrentHighPowerMode");
	g_sLangTxt_Native_CurrentHighPowerMode = _T("电流启用高功率模式");
	g_sLangID_Native_EnableCustomOutput = _T("Native_EnableCustomOutput");
	g_sLangTxt_Native_EnableCustomOutput = _T("启用自定义输出");
	g_sLangID_Native_AbsoluteTime = _T("Native_AbsoluteTime");
	g_sLangTxt_Native_AbsoluteTime = _T("绝对时间");
	g_sLangID_Native_RelativeTime = _T("Native_RelativeTime");
	g_sLangTxt_Native_RelativeTime = _T("相对时间");
	// 9newly
	g_sLangID_Native_OverCurrentV = _T("Native_OverCurrentV");
	g_sLangTxt_Native_OverCurrentV = _T("过流V段定值");
	g_sLangID_Native_OverCurrentVTime = _T("Native_OverCurrentVTime");
	g_sLangTxt_Native_OverCurrentVTime = _T("过流V段时间");
	g_sLangID_Native_ShortZImpAngExp = _T("Native_ShortZImpAngExp");
	g_sLangTxt_Native_ShortZImpAngExp = _T("短路阻抗角(表达式)");

	//
	g_sLangID_Native_first_fault_type = _T("Native_first_fault_type");
	g_sLangTxt_Native_first_fault_type = _T("第一次故障类型");
	g_sLangID_Native_first_fault_current = _T("Native_first_fault_current");
	g_sLangTxt_Native_first_fault_current = _T("第一次故障电流");
	g_sLangID_Native_first_faultact_time = _T("Native_first_faultact_time");
	g_sLangTxt_Native_first_faultact_time = _T("第一次故障动作时间");
	g_sLangID_Native_first_fault_impedance = _T("Native_first_fault_impedance");
	g_sLangTxt_Native_first_fault_impedance = _T("第一次故障短路阻抗");
	g_sLangID_Native_first_fault_impedance_angle = _T("Native_first_fault_impedance_angle");
	g_sLangTxt_Native_first_fault_impedance_angle = _T("第一次故障短路阻抗角");

	g_sLangID_Native_second_fault_type = _T("Native_second_fault_type");
	g_sLangTxt_Native_second_fault_type = _T("第二次故障类型");
	g_sLangID_Native_second_fault_current = _T("Native_second_fault_current");
	g_sLangTxt_Native_second_fault_current = _T("第二次故障电流");
	g_sLangID_Native_second_faultact_time = _T("Native_second_faultact_time");
	g_sLangTxt_Native_second_faultact_time = _T("第二次故障动作时间");
	g_sLangID_Native_second_fault_impedance = _T("Native_second_fault_impedance");
	g_sLangTxt_Native_second_fault_impedance = _T("第二次故障短路阻抗");
	g_sLangID_Native_second_fault_impedance_angle = _T("Native_second_fault_impedance_angle");
	g_sLangTxt_Native_second_fault_impedance_angle = _T("第二次故障短路阻抗角");

	g_sLangID_Native_first_fault_impAmp = _T("Native_first_fault_impAmp");
	g_sLangTxt_Native_first_fault_impAmp = _T("第一次故障短路阻抗(表达式)");
	g_sLangID_Native_first_fault_impAngAmp = _T("Native_first_fault_impAngAmp");
	g_sLangTxt_Native_first_fault_impAngAmp = _T("第一次故障短路阻抗角(表达式)");
	g_sLangID_Native_second_fault_impAmp = _T("Native_second_fault_impAmp");
	g_sLangTxt_Native_second_fault_impAmp = _T("第二次故障短路阻抗(表达式)");
	g_sLangID_Native_second_fault_impAngAmp = _T("Native_second_fault_impAngAmp");
	g_sLangTxt_Native_second_fault_impAngAmp = _T("第二次故障短路阻抗角(表达式)");

	g_sLangID_Native_synchronous_VAmpExp = _T("Native_synchronous_VAmpExp");
	g_sLangTxt_Native_synchronous_VAmpExp = _T("同期电压幅值(表达式)");
	g_sLangID_Native_synchronous_VPhExp = _T("Native_synchronous_VPhExp");
	g_sLangTxt_Native_synchronous_VPhExp = _T("同期电压相位(表达式)");

	g_sLangID_Native_impedance_Set = _T("Native_impedance_Set");
	g_sLangTxt_Native_impedance_Set = _T("阻抗定值(定值)");
	g_sLangID_Native_ImpedanceAnglesSet = _T("Native_ImpedanceAnglesSet");
	g_sLangTxt_Native_ImpedanceAnglesSet = _T("阻抗角(定值)");
	g_sLangID_Native_Syn_closure_AngSet = _T("Native_Syn_closure_AngSet");
	g_sLangTxt_Native_Syn_closure_AngSet = _T("检同期合闸角(定值)");
	g_sLangID_Native_test_item_name = _T("Native_test_item_name");
	g_sLangTxt_Native_test_item_name = _T("测试项名称");

	//
	g_sLangID_Native_0seqISet = _T("ative_0seqISet");
	g_sLangTxt_Native_0seqISet = _T("零序电流定值");
	g_sLangID_Native_YN_autoTestMode = _T("Native_YN_autoTestMode");
	g_sLangTxt_Native_YN_autoTestMode = _T("是否自动测试模式");
	g_sLangID_Native_0SeqISet = _T("Native_0SeqISet");
	g_sLangTxt_Native_0SeqISet = _T("零序I段定值");
	g_sLangID_Native_0SeqIISet = _T("Native_0SeqIISet");
	g_sLangTxt_Native_0SeqIISet = _T("零序II段定值");
	g_sLangID_Native_0SeqIIISet = _T("Native_0SeqIIISet");
	g_sLangTxt_Native_0SeqIIISet = _T("零序III段定值");
	g_sLangID_Native_0SeqIVSet = _T("Native_0SeqIVSet");
	g_sLangTxt_Native_0SeqIVSet = _T("零序IV段定值");
	g_sLangID_Native_0SeqVSet = _T("Native_0SeqVSet");
	g_sLangTxt_Native_0SeqVSet = _T("零序V段定值");
	g_sLangID_Native_0SeqITime = _T("Native_0SeqITime");
	g_sLangTxt_Native_0SeqITime = _T("零序I段时间");
	g_sLangID_Native_0SeqIITime = _T("Native_0SeqIITime");
	g_sLangTxt_Native_0SeqIITime = _T("零序II段时间");
	g_sLangID_Native_0SeqIIITime = _T("Native_0SeqIIITime");
	g_sLangTxt_Native_0SeqIIITime = _T("零序III段时间");
	g_sLangID_Native_0SeqIVTime = _T("Native_0SeqIVTime");
	g_sLangTxt_Native_0SeqIVTime = _T("零序IV段时间");
	g_sLangID_Native_0SeqVTime = _T("Native_0SeqVTime");
	g_sLangTxt_Native_0SeqVTime = _T("零序V段时间");

	// 第八周马
	// tmt_adjust_sys_para_trans.cpp
	g_sLangID_Native_ACVoltPlugin = _T("Native_ACVoltPlugin");
	g_sLangTxt_Native_ACVoltPlugin = _T("交流电压插件");
	g_sLangID_Native_ACCurrPlugin = _T("Native_ACCurrPlugin");
	g_sLangTxt_Native_ACCurrPlugin = _T("交流电流插件");
	g_sLangID_Native_8x100MbpsDB = _T("Native_8x100MbpsDB");
	g_sLangTxt_Native_8x100MbpsDB = _T("8个百兆口数字板");
	g_sLangID_Native_6x100M2x1000MDB = _T("Native_6x100M2x1000MDB");
	g_sLangTxt_Native_6x100M2x1000MDB = _T("6个百兆口,2个千兆口数字板");
	g_sLangID_Native_4x100M4x1000MDB = _T("Native_4x100M4x1000MDB");
	g_sLangTxt_Native_4x100M4x1000MDB = _T("4个百兆口,4个千兆口数字板");
	g_sLangID_Native_DCCurrPlugin = _T("Native_DCCurrPlugin");
	g_sLangTxt_Native_DCCurrPlugin = _T("直流电流插件");
	g_sLangID_Native_DCVoltPlugin = _T("Native_DCVoltPlugin");
	g_sLangTxt_Native_DCVoltPlugin = _T("直流电压插件");
	g_sLangID_Native_DI_O_ExpBoard = _T("Native_DI_O_ExpBoard");
	g_sLangTxt_Native_DI_O_ExpBoard = _T("开关量扩展板");
	g_sLangID_Native_LSModPlugin = _T("Native_LSModPlugin");
	g_sLangTxt_Native_LSModPlugin = _T("小信号模块插件");
	g_sLangID_Native_MBLowSignal = _T("Native_MBLowSignal");
	g_sLangTxt_Native_MBLowSignal = _T("主板小信号");
	g_sLangID_Native_FSFT3Board = _T("Native_FSFT3Board");
	g_sLangTxt_Native_FSFT3Board = _T("柔直FT3板");
	g_sLangID_Native_UIHybridPlugin = _T("Native_UIHybridPlugin");
	g_sLangTxt_Native_UIHybridPlugin = _T("U、I混合插件");
	g_sLangID_Native_VoltAcqPlugin = _T("Native_VoltAcqPlugin");
	g_sLangTxt_Native_VoltAcqPlugin = _T("电压采集插件");
	g_sLangID_Native_CurrAcqPlugin = _T("Native_CurrAcqPlugin");
	g_sLangTxt_Native_CurrAcqPlugin = _T("电流采集插件");
	g_sLangID_Native_Stable2MCommPlugin = _T("Native_Stable2MCommPlugin");
	g_sLangTxt_Native_Stable2MCommPlugin = _T("稳控2M通讯插件");
	g_sLangID_Native_Acquisition = _T("Native_Acquisition");
	g_sLangTxt_Native_Acquisition = _T("采集");
	g_sLangID_Native_Undefined = _T("Native_Undefined");
	g_sLangTxt_Native_Undefined = _T("未定义");
	g_sLangID_Native_130VVoltageModule = _T("Native_130VVoltageModule");
	g_sLangTxt_Native_130VVoltageModule = _T("130伏电压模块");
	g_sLangID_Native_248VVoltageModule = _T("Native_248VVoltageModule");
	g_sLangTxt_Native_248VVoltageModule = _T("248伏电压模块");
	g_sLangID_Native_270VVMNoBoost = _T("Native_270VVMNoBoost");
	g_sLangTxt_Native_270VVMNoBoost = _T("270伏电压模块无升压");
	g_sLangID_Native_270VVModuleWBoost = _T("Native_270VVModuleWBoost");
	g_sLangTxt_Native_270VVModuleWBoost = _T("270伏电压模块有升压");
	g_sLangID_Native_300VVMNoBoost = _T("Native_300VVMNoBoost");
	g_sLangTxt_Native_300VVMNoBoost = _T("300伏电压模块无升压");
	g_sLangID_Native_300VVModuleWBoost = _T("Native_300VVModuleWBoost");
	g_sLangTxt_Native_300VVModuleWBoost = _T("300伏电压模块有升压");
	g_sLangID_Native_125ACModule = _T("Native_125ACModule");
	g_sLangTxt_Native_125ACModule = _T("12.5安电流模块");
	g_sLangID_Native_20ACModule = _T("Native_20ACModule");
	g_sLangTxt_Native_20ACModule = _T("20安电流模块");
	g_sLangID_Native_32ACModule = _T("Native_32ACModule");
	g_sLangTxt_Native_32ACModule = _T("32安电流模块");
	g_sLangID_Native_125V20AHM = _T("Native_125V20AHM");
	g_sLangTxt_Native_125V20AHM = _T("12.5伏20安混合模块");
	g_sLangID_Native_310V60AHM = _T("Native_310V60AHM");
	g_sLangTxt_Native_310V60AHM = _T("310伏60安混合模块");
	g_sLangID_Native_PFC6A = _T("Native_PFC6A");
	g_sLangTxt_Native_PFC6A = _T("PFC_6A 模块");
	g_sLangID_Native_P12DSM = _T("Native_P12DSM");
	g_sLangTxt_Native_P12DSM = _T("PIA12DS 模块");
	g_sLangID_Native_P48SM = _T("Native_P48SM");
	g_sLangTxt_Native_P48SM = _T("PIA48S 模块");
	g_sLangID_Native_EVTM = _T("Native_EVTM");
	g_sLangTxt_Native_EVTM = _T("EVTECT 模块");
	g_sLangID_Native_DCIPM = _T("Native_DCIPM");
	g_sLangTxt_Native_DCIPM = _T("直流增量保护模块");
	g_sLangID_Native_6C10VDCM = _T("Native_6C10VDCM");
	g_sLangTxt_Native_6C10VDCM = _T("6路10伏直流模块");
	g_sLangID_Native_6C20mADC = _T("Native_6C20mADC");
	g_sLangTxt_Native_6C20mADC = _T("6路20毫安直流模块");
	g_sLangID_Native_PN6U6IDCSSM = _T("Native_PN6U6IDCSSM");
	g_sLangTxt_Native_PN6U6IDCSSM = _T("PN6U6I直流小信号模块");
	g_sLangID_Native_OutputNotSupported = _T("Native_OutputNotSupported");
	g_sLangTxt_Native_OutputNotSupported = _T("不支持输出合并");
	g_sLangID_Native_6to1MergePossible = _T("Native_6to1MergePossible");
	g_sLangTxt_Native_6to1MergePossible = _T("6路可以合并为1路");
	g_sLangID_Native_6to3MergePossible = _T("Native_6to3MergePossible");
	g_sLangTxt_Native_6to3MergePossible = _T("6路可以合并为3路");
	g_sLangID_Native_6to3FixedMerge = _T("Native_6to3FixedMerge");
	g_sLangTxt_Native_6to3FixedMerge = _T("6路固定合并为3路");
	g_sLangID_Native_SeqComp = _T("Native_SeqComp");
	g_sLangTxt_Native_SeqComp = _T("序分量(S)");

	// adjust_sys_parameter
	g_sLangID_Native_AmpFactor = _T("Native_AmpFactor");
	g_sLangTxt_Native_AmpFactor = _T("幅值系数");
	g_sLangID_Native_NumGears = _T("Native_NumGears");
	g_sLangTxt_Native_NumGears = _T("档位数");
	g_sLangID_Native_HW1DCZeroDrift = _T("Native_HW1DCZeroDrift");
	g_sLangTxt_Native_HW1DCZeroDrift = _T("硬件1档直流零漂");
	g_sLangID_Native_HW2DCZeroDrift = _T("Native_HW2DCZeroDrift");
	g_sLangTxt_Native_HW2DCZeroDrift = _T("硬件2档直流零漂");
	g_sLangID_Native_HW3DCZeroDrift = _T("Native_HW3DCZeroDrift");
	g_sLangTxt_Native_HW3DCZeroDrift = _T("硬件3档直流零漂");
	g_sLangID_Native_LCNLCoeff = _T("Native_LCNLCoeff");
	g_sLangTxt_Native_LCNLCoeff = _T("大电流非线性系数");
	g_sLangID_Native_NthHarmonic = _T("Native_NthHarmonic");
	g_sLangTxt_Native_NthHarmonic = _T("%d次谐波");
	g_sLangID_Native_Temp = _T("Native_Temp");
	g_sLangTxt_Native_Temp = _T("温度");
	g_sLangID_Native_ChnN = _T("Native_ChnN");
	g_sLangTxt_Native_ChnN = _T("通道%d");
	g_sLangID_Native_GearID = _T("Native_GearID");
	g_sLangTxt_Native_GearID = _T("档位ID");
	g_sLangID_Native_GearVal = _T("Native_GearVal");
	g_sLangTxt_Native_GearVal = _T("档位值");
	g_sLangID_Native_HwGearCount = _T("Native_HwGearCount");
	g_sLangTxt_Native_HwGearCount = _T("硬件档位数");
	g_sLangID_Native_CalibCoeff = _T("Native_CalibCoeff");
	g_sLangTxt_Native_CalibCoeff = _T("校准系数");
	g_sLangID_Native_TempZoneCount = _T("Native_TempZoneCount");
	g_sLangTxt_Native_TempZoneCount = _T("温区数");
	g_sLangID_Native_HwChannel = _T("Native_HwChannel");
	g_sLangTxt_Native_HwChannel = _T("硬件通道");
	g_sLangID_Native_ChnID = _T("Native_ChnID");
	g_sLangTxt_Native_ChnID = _T("通道ID");
	g_sLangID_Native_ChnIndex = _T("Native_ChnIndex");
	g_sLangTxt_Native_ChnIndex = _T("通道索引");
	g_sLangID_Native_AssocSWRes = _T("Native_AssocSWRes");
	g_sLangTxt_Native_AssocSWRes = _T("关联的软件资源");
	g_sLangID_Native_ACMaxValue = _T("Native_ACMaxValue");
	g_sLangTxt_Native_ACMaxValue = _T("交流最大值");
	g_sLangID_Native_DCMaxValue = _T("Native_DCMaxValue");
	g_sLangTxt_Native_DCMaxValue = _T("直流最大值");
	g_sLangID_Native_ChAcqMapLoc = _T("Native_ChAcqMapLoc");
	g_sLangTxt_Native_ChAcqMapLoc = _T("通道采集映射位置");
	g_sLangID_Native_OpMode = _T("Native_OpMode");
	g_sLangTxt_Native_OpMode = _T("工作模式");
	g_sLangID_Native_ElecType = _T("Native_ElecType");
	g_sLangTxt_Native_ElecType = _T("电气类型");
	g_sLangID_Native_HwChDef = _T("Native_HwChDef");
	g_sLangTxt_Native_HwChDef = _T("硬件通道定义");
	g_sLangID_Native_ChDrivePos = _T("Native_ChDrivePos");
	g_sLangTxt_Native_ChDrivePos = _T("通道驱动位置");
	g_sLangID_Native_ChPos = _T("Native_ChPos");
	g_sLangTxt_Native_ChPos = _T("通道%d位置");
	g_sLangID_Native_ChMapDef = _T("Native_ChMapDef");
	g_sLangTxt_Native_ChMapDef = _T("通道映射定义");
	g_sLangID_Native_ModProps = _T("Native_ModProps");
	g_sLangTxt_Native_ModProps = _T("模块属性");
	g_sLangID_Native_LCOptPortCount = _T("Native_LCOptPortCount");
	g_sLangTxt_Native_LCOptPortCount = _T("LC光口数");
	g_sLangID_Native_STTxOptPortCount = _T("Native_STTxOptPortCount");
	g_sLangTxt_Native_STTxOptPortCount = _T("ST发送光口数");
	g_sLangID_Native_STRxOptPortCount = _T("Native_STRxOptPortCount");
	g_sLangTxt_Native_STRxOptPortCount = _T("ST接收光口数");
	g_sLangID_Native_HarmOrder = _T("Native_HarmOrder");
	g_sLangTxt_Native_HarmOrder = _T("谐波数");
	g_sLangID_Native_DCVoltChMax = _T("Native_DCVoltChMax");
	g_sLangTxt_Native_DCVoltChMax = _T("直流电压通道最大值");
	g_sLangID_Native_DCCurrChMax = _T("Native_DCCurrChMax");
	g_sLangTxt_Native_DCCurrChMax = _T("直流电流通道最大值");
	g_sLangID_Native_ChACOutMax = _T("Native_ChACOutMax");
	g_sLangTxt_Native_ChACOutMax = _T("通道出交流最大值");
	g_sLangID_Native_ChDCOutMax = _T("Native_ChDCOutMax");
	g_sLangTxt_Native_ChDCOutMax = _T("通道出直流最大值");
	g_sLangID_Native_FreqCompCoeff = _T("Native_FreqCompCoeff");
	g_sLangTxt_Native_FreqCompCoeff = _T("频率补偿系数");
	g_sLangID_Native_DigiHWPhaseDelay = _T("Native_DigiHWPhaseDelay");
	g_sLangTxt_Native_DigiHWPhaseDelay = _T("数字硬件相位延时");
	g_sLangID_Native_VoltCurrHWChar = _T("Native_VoltCurrHWChar");
	g_sLangTxt_Native_VoltCurrHWChar = _T("电压电流硬件特性");
	g_sLangID_Native_CurrChMergeMode = _T("Native_CurrChMergeMode");
	g_sLangTxt_Native_CurrChMergeMode = _T("电流通道合并模式");
	g_sLangID_Native_1stSetDigInCfg = _T("Native_1stSetDigInCfg");
	g_sLangTxt_Native_1stSetDigInCfg = _T("第一组开关量配为开入");
	g_sLangID_Native_2stSetDigInCfg = _T("Native_2stSetDigInCfg");
	g_sLangTxt_Native_2stSetDigInCfg = _T("第二组开关量配为开入");
	g_sLangID_Native_3stSetDigInCfg = _T("Native_3stSetDigInCfg");
	g_sLangTxt_Native_3stSetDigInCfg = _T("第三组开关量配为开入");
	g_sLangID_Native_4stSetDigInCfg = _T("Native_4stSetDigInCfg");
	g_sLangTxt_Native_4stSetDigInCfg = _T("第四组开关量配为开入");
	g_sLangID_Native_ModFPGAVer = _T("Native_ModFPGAVer");
	g_sLangTxt_Native_ModFPGAVer = _T("模块FPGA版本");
	g_sLangID_Native_ModAttrVer = _T("Native_ModAttrVer");
	g_sLangTxt_Native_ModAttrVer = _T("模块属性版本");
	g_sLangID_Native_IndepDCCurrChHWRange = _T("Native_IndepDCCurrChHWRange");
	g_sLangTxt_Native_IndepDCCurrChHWRange = _T("独立直流电流通道硬件档位");
	g_sLangID_Native_IndepDCVoltChHWRange = _T("Native_IndepDCVoltChHWRange");
	g_sLangTxt_Native_IndepDCVoltChHWRange = _T("独立直流电压通道硬件档位");
	g_sLangID_Native_ModChRange = _T("Native_ModChRange");
	g_sLangTxt_Native_ModChRange = _T("模块通道档位");
	g_sLangID_Native_TripRelayPickupDef = _T("Native_TripRelayPickupDef");
	g_sLangTxt_Native_TripRelayPickupDef = _T("开出量导通值定义");

	g_sLangID_Native_TripRelay1Pickup = _T("Native_TripRelay1Pickup");
	g_sLangTxt_Native_TripRelay1Pickup = _T("开出1导通值");
	g_sLangID_Native_TripRelay2Pickup = _T("Native_TripRelay2Pickup");
	g_sLangTxt_Native_TripRelay2Pickup = _T("开出2导通值");
	g_sLangID_Native_TripRelay3Pickup = _T("Native_TripRelay3Pickup");
	g_sLangTxt_Native_TripRelay3Pickup = _T("开出3导通值");
	g_sLangID_Native_TripRelay4Pickup = _T("Native_TripRelay4Pickup");
	g_sLangTxt_Native_TripRelay4Pickup = _T("开出4导通值");
	g_sLangID_Native_TripRelay5Pickup = _T("Native_TripRelay5Pickup");
	g_sLangTxt_Native_TripRelay5Pickup = _T("开出5导通值");
	g_sLangID_Native_TripRelay6Pickup = _T("Native_TripRelay6Pickup");
	g_sLangTxt_Native_TripRelay6Pickup = _T("开出6导通值");
	g_sLangID_Native_TripRelay7Pickup = _T("Native_TripRelay7Pickup");
	g_sLangTxt_Native_TripRelay7Pickup = _T("开出7导通值");
	g_sLangID_Native_TripRelay8Pickup = _T("Native_TripRelay8Pickup");
	g_sLangTxt_Native_TripRelay8Pickup = _T("开出8导通值");
	g_sLangID_Native_StateSeqCapacity = _T("Native_StateSeqCapacity");
	g_sLangTxt_Native_StateSeqCapacity = _T("状态序列容量(个)");
	g_sLangID_Native_MainBrdDInQty = _T("Native_MainBrdDInQty");
	g_sLangTxt_Native_MainBrdDInQty = _T("主板开入数量(个)");
	g_sLangID_Native_MainBrdDOutQty = _T("Native_MainBrdDOutQty");
	g_sLangTxt_Native_MainBrdDOutQty = _T("主板开出数量(个)");
	g_sLangID_Native_WSecMomentAnaPhAbsComp = _T("Native_WSecMomentAnaPhAbsComp");
	g_sLangTxt_Native_WSecMomentAnaPhAbsComp = _T("整秒时刻,模拟量绝对相位补偿(度)");
	g_sLangID_Native_CtrlAuthCheck = _T("Native_CtrlAuthCheck");
	g_sLangTxt_Native_CtrlAuthCheck = _T("启用控制权限判断(0-不启用，1-启用)");
	g_sLangID_Native_TestSrvName = _T("Native_TestSrvName");
	g_sLangTxt_Native_TestSrvName = _T("TestServer名称");
	g_sLangID_Native_TestSrvVersion = _T("Native_TestSrvVersion");
	g_sLangTxt_Native_TestSrvVersion = _T("TestServer版本");
	g_sLangID_Native_MainBrdVersion = _T("Native_MainBrdVersion");
	g_sLangTxt_Native_MainBrdVersion = _T("主板版本");
	g_sLangID_Native_DrvVersion = _T("Native_DrvVersion");
	g_sLangTxt_Native_DrvVersion = _T("驱动版本");
	g_sLangID_Native_DrvName = _T("Native_DrvName");
	g_sLangTxt_Native_DrvName = _T("驱动名称");
	g_sLangID_Native_MainBrdSTPortModeCfg = _T("Native_MainBrdSTPortModeCfg");
	g_sLangTxt_Native_MainBrdSTPortModeCfg = _T("主板ST口模式可设置");
	g_sLangID_Native_SysVerNumber = _T("Native_SysVerNumber");
	g_sLangTxt_Native_SysVerNumber = _T("系统版本号");

	// tmt_adjust_test
	g_sLangID_Native_CalibItem = _T("Native_CalibItem");
	g_sLangTxt_Native_CalibItem = _T("校准项目");
	g_sLangID_Native_Pt1Amp = _T("Native_Pt1Amp");
	g_sLangTxt_Native_Pt1Amp = _T("点1幅值");
	g_sLangID_Native_Pt2Amp = _T("Native_Pt2Amp");
	g_sLangTxt_Native_Pt2Amp = _T("点2幅值");

	// tmt_dig_replay_test
	g_sLangID_Native_SelCtrlBlock = _T("Native_SelCtrlBlock");
	g_sLangTxt_Native_SelCtrlBlock = _T("发送(选择该控制块)");
	g_sLangID_Native_CtrlBlkOutOptPortsCnt = _T("Native_CtrlBlkOutOptPortsCnt");
	g_sLangTxt_Native_CtrlBlkOutOptPortsCnt = _T("控制块输出光口数量");
	g_sLangID_Native_CtrlBlkAppID = _T("Native_CtrlBlkAppID");
	g_sLangTxt_Native_CtrlBlkAppID = _T("控制块AppID");
	g_sLangID_Native_CtrlBlkOutTotalFrames = _T("Native_CtrlBlkOutTotalFrames");
	g_sLangTxt_Native_CtrlBlkOutTotalFrames = _T("控制块输出总帧数");
	g_sLangID_Native_CtrlBlkOutStartFrmNum = _T("Native_CtrlBlkOutStartFrmNum");
	g_sLangTxt_Native_CtrlBlkOutStartFrmNum = _T("控制块输出起始帧号(本控制块内排序)");
	g_sLangID_Native_CtrlBlkOutEndFrmNum = _T("Native_CtrlBlkOutEndFrmNum");
	g_sLangTxt_Native_CtrlBlkOutEndFrmNum = _T("控制块输出结束帧号(本控制块内排序)");
	g_sLangID_Native_CtrlBlkDelayCompValue = _T("Native_CtrlBlkDelayCompValue");
	g_sLangTxt_Native_CtrlBlkDelayCompValue = _T("控制块延时补偿值(单位:us)");
	g_sLangID_Native_NumOfSVCBs = _T("Native_NumOfSVCBs");
	g_sLangTxt_Native_NumOfSVCBs = _T("采样值控制块数量");
	g_sLangID_Native_NumOfGCBs = _T("Native_NumOfGCBs");
	g_sLangTxt_Native_NumOfGCBs = _T("GOOSE控制块数量");
	g_sLangID_Native_SVReplayMode = _T("Native_SVReplayMode");
	g_sLangTxt_Native_SVReplayMode = _T("SV回放模式(0:按时间间隔,1:等间隔,2:自定义)");
	g_sLangID_Native_GOOSEReplayMode = _T("Native_GOOSEReplayMode");
	g_sLangTxt_Native_GOOSEReplayMode = _T("GOOSE回放模式(0:按时间间隔,1:等间隔)");
	g_sLangID_Native_SVEqReplayIntervalTime_us = _T("Native_SVEqReplayIntervalTime_us");
	g_sLangTxt_Native_SVEqReplayIntervalTime_us = _T("SV等间隔回放间隔时间(us)");
	g_sLangID_Native_GOOSEEqReplayIntervalTime_us = _T("Native_GOOSEEqReplayIntervalTime_us");
	g_sLangTxt_Native_GOOSEEqReplayIntervalTime_us = _T("GOOSE等间隔回放间隔时间(us)");
	g_sLangID_Native_CustomReplayJitter_us = _T("Native_CustomReplayJitter_us");
	g_sLangTxt_Native_CustomReplayJitter_us = _T("自定义回放抖动值(us)");
	g_sLangID_Native_LoopingFlag = _T("Native_LoopingFlag");
	g_sLangTxt_Native_LoopingFlag = _T("是否循环(0不循环,1循环)");
	g_sLangID_Native_ReplayIntervalType = _T("Native_ReplayIntervalType");
	g_sLangTxt_Native_ReplayIntervalType = _T("回放区间设置类型(0全部回放,1部分回放)");
	g_sLangID_Native_StartFrameNum = _T("Native_StartFrameNum");
	g_sLangTxt_Native_StartFrameNum = _T("输出起始帧号(全部控制块排序)");
	g_sLangID_Native_EndFrameNum = _T("Native_EndFrameNum");
	g_sLangTxt_Native_EndFrameNum = _T("输出结束帧号(全部控制块排序)");
	g_sLangID_Native_GPSTriggerTime_hr = _T("Native_GPSTriggerTime_hr");
	g_sLangTxt_Native_GPSTriggerTime_hr = _T("GPS触发时刻(时)");
	g_sLangID_Native_GPSTriggerTime_min = _T("Native_GPSTriggerTime_min");
	g_sLangTxt_Native_GPSTriggerTime_min = _T("GPS触发时刻(分)");
	g_sLangID_Native_GPSTriggerTime_sec = _T("Native_GPSTriggerTime_sec");
	g_sLangTxt_Native_GPSTriggerTime_sec = _T("GPS触发时刻(秒)");
	g_sLangID_Native_OutputDuration_sec = _T("Native_OutputDuration_sec");
	g_sLangTxt_Native_OutputDuration_sec = _T("输出时长(s)");
	g_sLangID_Native_InputSelection = _T("Native_InputSelection");
	g_sLangTxt_Native_InputSelection = _T("开入%c选择");

	// tmt_gradient_test
	g_sLangID_Native_FeedbackCoefSettingVal = _T("Native_FeedbackCoefSettingVal");
	g_sLangTxt_Native_FeedbackCoefSettingVal = _T("返回系数整定值");
	g_sLangID_Native_BoundaryAngle1SetVal = _T("Native_BoundaryAngle1SetVal");
	g_sLangTxt_Native_BoundaryAngle1SetVal = _T("边界角1整定值");
	g_sLangID_Native_BoundaryAngle2SetVal = _T("Native_BoundaryAngle2SetVal");
	g_sLangTxt_Native_BoundaryAngle2SetVal = _T("边界角2整定值");
	g_sLangID_Native_MaxSensitivityAngleSetVal = _T("Native_MaxSensitivityAngleSetVal");
	g_sLangTxt_Native_MaxSensitivityAngleSetVal = _T("最大灵敏角整定值");
	g_sLangID_Native_StepTimeSec = _T("Native_StepTimeSec");
	g_sLangTxt_Native_StepTimeSec = _T("步长时间(秒)");
	g_sLangID_Native_FSG2VoltageAmplitude = _T("Native_FSG2VoltageAmplitude");
	g_sLangTxt_Native_FSG2VoltageAmplitude = _T("故障态组2电压幅值");
	g_sLangID_Native_FSG2CurrentAmplitude = _T("Native_FSG2CurrentAmplitude");
	g_sLangTxt_Native_FSG2CurrentAmplitude = _T("故障态组2电流幅值");
	g_sLangID_Native_RatedVoltageAmplitude = _T("Native_RatedVoltageAmplitude");
	g_sLangTxt_Native_RatedVoltageAmplitude = _T("额定电压幅值");
	g_sLangID_Native_NomVoltPhaseSeq = _T("Native_NomVoltPhaseSeq");
	g_sLangTxt_Native_NomVoltPhaseSeq = _T("常态电压相序");
	g_sLangID_Native_NomCurrPhaseSeq = _T("Native_NomCurrPhaseSeq");
	g_sLangTxt_Native_NomCurrPhaseSeq = _T("常态电流相序");
	g_sLangID_Native_NomVoltAmplitude = _T("Native_NomVoltAmplitude");
	g_sLangTxt_Native_NomVoltAmplitude = _T("常态电压幅值");
	g_sLangID_Native_NomCurrAmplitude = _T("Native_NomCurrAmplitude");
	g_sLangTxt_Native_NomCurrAmplitude = _T("常态电流幅值");

	g_sLangID_Native_Ua1Amp = _T("Native_Ua1Amp");
	g_sLangTxt_Native_Ua1Amp = _T("Ua1幅值");
	g_sLangID_Native_Ua1Ph = _T("Native_Ua1Ph");
	g_sLangTxt_Native_Ua1Ph = _T("Ua1相位");
	g_sLangID_Native_Ua2Amp = _T("Native_Ua2Amp");
	g_sLangTxt_Native_Ua2Amp = _T("Ua2幅值");
	g_sLangID_Native_Ua2Ph = _T("Native_Ua2Ph");
	g_sLangTxt_Native_Ua2Ph = _T("Ua2相位");

	g_sLangID_Native_Ub1Amp = _T("Native_Ub1Amp");
	g_sLangTxt_Native_Ub1Amp = _T("Ub1幅值");
	g_sLangID_Native_Ub1Ph = _T("Native_Ub1Ph");
	g_sLangTxt_Native_Ub1Ph = _T("Ub1相位");
	g_sLangID_Native_Ub2Amp = _T("Native_Ub2Amp");
	g_sLangTxt_Native_Ub2Amp = _T("Ub2幅值");
	g_sLangID_Native_Ub2Ph = _T("Native_Ub2Ph");
	g_sLangTxt_Native_Ub2Ph = _T("Ub2相位");

	g_sLangID_Native_Uc1Amp = _T("Native_Uc1Amp");
	g_sLangTxt_Native_Uc1Amp = _T("Uc1幅值");
	g_sLangID_Native_Uc1Ph = _T("Native_Uc1Ph");
	g_sLangTxt_Native_Uc1Ph = _T("Uc1相位");
	g_sLangID_Native_Uc2Amp = _T("Native_Uc2Amp");
	g_sLangTxt_Native_Uc2Amp = _T("Uc2幅值");
	g_sLangID_Native_Uc2Ph = _T("Native_Uc2Ph");
	g_sLangTxt_Native_Uc2Ph = _T("Uc2相位");

	g_sLangID_Native_Ia1Amp = _T("Native_Ia1Amp");
	g_sLangTxt_Native_Ia1Amp = _T("Ia1幅值");
	g_sLangID_Native_Ia1Ph = _T("Native_Ia1Ph");
	g_sLangTxt_Native_Ia1Ph = _T("Ia1相位");
	g_sLangID_Native_Ia2Amp = _T("Native_Ia2Amp");
	g_sLangTxt_Native_Ia2Amp = _T("Ia2幅值");
	g_sLangID_Native_Ia2Ph = _T("Native_Ia2Ph");
	g_sLangTxt_Native_Ia2Ph = _T("Ia2相位");

	g_sLangID_Native_Ib1Amp = _T("Native_Ib1Amp");
	g_sLangTxt_Native_Ib1Amp = _T("Ib1幅值");
	g_sLangID_Native_Ib1Ph = _T("Native_Ib1Ph");
	g_sLangTxt_Native_Ib1Ph = _T("Ib1相位");
	g_sLangID_Native_Ib2Amp = _T("Native_Ib2Amp");
	g_sLangTxt_Native_Ib2Amp = _T("Ib2幅值");
	g_sLangID_Native_Ib2Ph = _T("Native_Ib2Ph");
	g_sLangTxt_Native_Ib2Ph = _T("Ib2相位");

	g_sLangID_Native_Ic1Amp = _T("Native_Ic1Amp");
	g_sLangTxt_Native_Ic1Amp = _T("Ic1幅值");
	g_sLangID_Native_Ic1Ph = _T("Native_Ic1Ph");
	g_sLangTxt_Native_Ic1Ph = _T("Ic1相位");
	g_sLangID_Native_Ic2Amp = _T("Native_Ic2Amp");
	g_sLangTxt_Native_Ic2Amp = _T("Ic2幅值");
	g_sLangID_Native_Ic2Ph = _T("Native_Ic2Ph");
	g_sLangTxt_Native_Ic2Ph = _T("Ic2相位");

	g_sLangID_Native_FreqPickAbsErr = _T("Native_FreqPickAbsErr");
	g_sLangTxt_Native_FreqPickAbsErr = _T("频率动作值绝对误差");
	g_sLangID_Native_FreqPickRelErr = _T("Native_FreqPickRelErr");
	g_sLangTxt_Native_FreqPickRelErr = _T("频率动作值相对误差");
	g_sLangID_Native_FreqPickErrDetectLogic = _T("Native_FreqPickErrDetectLogic");
	g_sLangTxt_Native_FreqPickErrDetectLogic = _T("频率动作值误差判断逻辑");
	g_sLangID_Native_MaxSensAngAbsErr = _T("Native_MaxSensAngAbsErr");
	g_sLangTxt_Native_MaxSensAngAbsErr = _T("最大灵敏角绝对误差");
	g_sLangID_Native_MaxSensAngRelErr = _T("Native_MaxSensAngRelErr");
	g_sLangTxt_Native_MaxSensAngRelErr = _T("最大灵敏角相对误差");
	g_sLangID_Native_MaxSensAngErrDetectLogic = _T("Native_MaxSensAngErrDetectLogic");
	g_sLangTxt_Native_MaxSensAngErrDetectLogic = _T("最大灵敏角误差判断逻辑");
	g_sLangID_Native_BndryAng1AbsErr = _T("Native_BndryAng1AbsErr");
	g_sLangTxt_Native_BndryAng1AbsErr = _T("边界角1绝对误差");
	g_sLangID_Native_BndryAng1RelErr = _T("Native_BndryAng1RelErr");
	g_sLangTxt_Native_BndryAng1RelErr = _T("边界角1相对误差");
	g_sLangID_Native_BndryAng1ErrDetectLogic = _T("Native_BndryAng1ErrDetectLogic");
	g_sLangTxt_Native_BndryAng1ErrDetectLogic = _T("边界角1误差判断逻辑");
	g_sLangID_Native_BndryAng2AbsErr = _T("Native_BndryAng2AbsErr");
	g_sLangTxt_Native_BndryAng2AbsErr = _T("边界角2绝对误差");
	g_sLangID_Native_BndryAng2RelErr = _T("Native_BndryAng2RelErr");
	g_sLangTxt_Native_BndryAng2RelErr = _T("边界角2相对误差");
	g_sLangID_Native_BndryAng2ErrDetectLogic = _T("Native_BndryAng2ErrDetectLogic");
	g_sLangTxt_Native_BndryAng2ErrDetectLogic = _T("边界角2误差判断逻辑");
	g_sLangID_Native_RetCoeffValid = _T("Native_RetCoeffValid");
	g_sLangTxt_Native_RetCoeffValid = _T("返回系数有效");
	g_sLangID_Native_AbsErrValid = _T("Native_AbsErrValid");
	g_sLangTxt_Native_AbsErrValid = _T("绝对误差有效");
	g_sLangID_Native_FreqTripValErr = _T("Native_FreqTripValErr");
	g_sLangTxt_Native_FreqTripValErr = _T("频率动作值误差");
	g_sLangID_Native_PhaseTripValErr = _T("Native_PhaseTripValErr");
	g_sLangTxt_Native_PhaseTripValErr = _T("相位动作值误差");
	g_sLangID_Native_RetCoeffError = _T("Native_RetCoeffError");
	g_sLangTxt_Native_RetCoeffError = _T("返回系数误差");
	g_sLangID_Native_MaxSensAngleErr = _T("Native_MaxSensAngleErr");
	g_sLangTxt_Native_MaxSensAngleErr = _T("最大灵敏角误差");
	g_sLangID_Native_BndryAngle1Err = _T("Native_BndryAngle1Err");
	g_sLangTxt_Native_BndryAngle1Err = _T("边界角1误差");
	g_sLangID_Native_BndryAngle2Err = _T("Native_BndryAngle2Err");
	g_sLangTxt_Native_BndryAngle2Err = _T("边界角2误差");

	// tmt_harm_test
	g_sLangID_Native_NthHarmPhase = _T("Native_NthHarmPhase");
	g_sLangTxt_Native_NthHarmPhase = _T("%d次谐波相位");
	g_sLangID_Native_NthHarmAmpl = _T("Native_NthHarmAmpl");
	g_sLangTxt_Native_NthHarmAmpl = _T("%d次谐波幅值");
	g_sLangID_Native_DCCompVaule = _T("Native_DCCompVaule");
	g_sLangTxt_Native_DCCompVaule = _T("直流分量");
	g_sLangID_Native_AutoVarConfig = _T("Native_AutoVarConfig");
	g_sLangTxt_Native_AutoVarConfig = _T("自动变化设置");
	g_sLangID_Native_AutoVarStatus = _T("Native_AutoVarStatus");
	g_sLangTxt_Native_AutoVarStatus = _T("是否自动变化");
	g_sLangID_Native_VarSelect = _T("Native_VarSelect");
	g_sLangTxt_Native_VarSelect = _T("变化量选择");
	g_sLangID_Native_VarTypeSelect = _T("Native_VarTypeSelect");
	g_sLangTxt_Native_VarTypeSelect = _T("变化类型选择");
	g_sLangID_Native_VarHarmonicNum = _T("Native_VarHarmonicNum");
	g_sLangTxt_Native_VarHarmonicNum = _T("变化谐波次数");

	// tmt_manu_test
	g_sLangID_Native_DCOutputMode = _T("Native_DCOutputMode");
	g_sLangTxt_Native_DCOutputMode = _T("是否以直流模式输出");
	g_sLangID_Native_HarmSuperposition = _T("Native_HarmSuperposition");
	g_sLangTxt_Native_HarmSuperposition = _T("谐波叠加");
	g_sLangID_Native_HarmSelection = _T("Native_HarmSelection");
	g_sLangTxt_Native_HarmSelection = _T("谐波选择");
	g_sLangID_Native_MrgUnit = _T("Native_MrgUnit");
	g_sLangTxt_Native_MrgUnit = _T("合并单元");
	g_sLangID_Native_AlgorithmSelection = _T("Native_AlgorithmSelection");
	g_sLangTxt_Native_AlgorithmSelection = _T("算法选择(0:插值法 1:同步法)");
	g_sLangID_Native_PPSConfiguration = _T("Native_PPSConfiguration");
	g_sLangTxt_Native_PPSConfiguration = _T("PPS设置(0:上升沿有效 1:下降沿有效 2:无PPS)");
	g_sLangID_Native_RatedV_Phase_ZeroDriftCalc = _T("Native_RatedV_Phase_ZeroDriftCalc");
	g_sLangTxt_Native_RatedV_Phase_ZeroDriftCalc = _T("额定相电压(零漂计算)");
	g_sLangID_Native_RatedI_Phase_ZeroDriftCalc = _T("Native_RatedI_Phase_ZeroDriftCalc");
	g_sLangTxt_Native_RatedI_Phase_ZeroDriftCalc = _T("额定相电流(零漂计算)");
	g_sLangID_Native_SyncDur_TAT = _T("Native_SyncDur_TAT");
	g_sLangTxt_Native_SyncDur_TAT = _T("守时精度测试时同步时长(单位:s)");
	g_sLangID_Native_DelayComp_NoPPS = _T("Native_DelayComp_NoPPS");
	g_sLangTxt_Native_DelayComp_NoPPS = _T("无PPS时延时补偿值(对时守时测试用,单位:μs)");
	g_sLangID_Native_CustomRepCnt_Use_MU = _T("Native_CustomRepCnt_Use_MU");
	g_sLangTxt_Native_CustomRepCnt_Use_MU = _T("是否使用自定义报告次数(合并单元)");
	g_sLangID_Native_CustomRepTestCnt_MU = _T("Native_CustomRepTestCnt_MU");
	g_sLangTxt_Native_CustomRepTestCnt_MU = _T("自定义报告测试次数(合并单元)");
	g_sLangID_Native_TestDurPerTest_MU_sec = _T("Native_TestDurPerTest_MU_sec");
	g_sLangTxt_Native_TestDurPerTest_MU_sec = _T("每次测试时间(合并单元,单位秒)");
	g_sLangID_Native_MUTimeTestResults = _T("Native_MUTimeTestResults");
	g_sLangTxt_Native_MUTimeTestResults = _T("MU时间测试结果");
	g_sLangID_Native_TestedDur = _T("Native_TestedDur");
	g_sLangTxt_Native_TestedDur = _T("已测试时长");
	g_sLangID_Native_MaxErrTime = _T("Native_MaxErrTime");
	g_sLangTxt_Native_MaxErrTime = _T("最大误差时间");
	g_sLangID_Native_MinErrTime = _T("Native_MinErrTime");
	g_sLangTxt_Native_MinErrTime = _T("最小误差时间");
	g_sLangID_Native_AvgErrTime = _T("Native_AvgErrTime");
	g_sLangTxt_Native_AvgErrTime = _T("平均误差时间");
	g_sLangID_Native_TimeAccTestResults = _T("Native_TimeAccTestResults");
	g_sLangTxt_Native_TimeAccTestResults = _T("时间精度测试结果");
	g_sLangID_Native_UaFreq = _T("Native_UaFreq");
	g_sLangTxt_Native_UaFreq = _T("Ua频率");
	g_sLangID_Native_UbFreq = _T("Native_UbFreq");
	g_sLangTxt_Native_UbFreq = _T("Ub频率");
	g_sLangID_Native_UcFreq = _T("Native_UcFreq");
	g_sLangTxt_Native_UcFreq = _T("Uc频率");

	g_sLangID_Native_UapAmp = _T("Native_UapAmp");
	g_sLangTxt_Native_UapAmp = _T("Uap幅值");
	g_sLangID_Native_UapPhase = _T("Native_UapPhase");
	g_sLangTxt_Native_UapPhase = _T("Uap相位");
	g_sLangID_Native_UapFreq = _T("Native_UapFreq");
	g_sLangTxt_Native_UapFreq = _T("Uap频率");

	g_sLangID_Native_UbpAmp = _T("Native_UbpAmp");
	g_sLangTxt_Native_UbpAmp = _T("Ubp幅值");
	g_sLangID_Native_UbpPhase = _T("Native_UbpPhase");
	g_sLangTxt_Native_UbpPhase = _T("Ubp相位");
	g_sLangID_Native_UbpFreq = _T("Native_UbpFreq");
	g_sLangTxt_Native_UbpFreq = _T("Ubp频率");

	g_sLangID_Native_UcpAmp = _T("Native_UcpAmp");
	g_sLangTxt_Native_UcpAmp = _T("Ucp幅值");
	g_sLangID_Native_UcpPhase = _T("Native_UcpPhase");
	g_sLangTxt_Native_UcpPhase = _T("Ucp相位");
	g_sLangID_Native_UcpFreq = _T("Native_UcpFreq");
	g_sLangTxt_Native_UcpFreq = _T("Ucp频率");

	g_sLangID_Native_IaAmp = _T("Native_IaAmp");
	g_sLangTxt_Native_IaAmp = _T("Ia幅值");
	g_sLangID_Native_IaPhase = _T("Native_IaPhase");
	g_sLangTxt_Native_IaPhase = _T("Ia相位");
	g_sLangID_Native_IaFreq = _T("Native_IaFreq");
	g_sLangTxt_Native_IaFreq = _T("Ia频率");

	g_sLangID_Native_IbAmp = _T("Native_IbAmp");
	g_sLangTxt_Native_IbAmp = _T("Ib幅值");
	g_sLangID_Native_IbPhase = _T("Native_IbPhase");
	g_sLangTxt_Native_IbPhase = _T("Ib相位");
	g_sLangID_Native_IbFreq = _T("Native_IbFreq");
	g_sLangTxt_Native_IbFreq = _T("Ib频率");

	g_sLangID_Native_IcAmp = _T("Native_IcAmp");
	g_sLangTxt_Native_IcAmp = _T("Ic幅值");
	g_sLangID_Native_IcPhase = _T("Native_IcPhase");
	g_sLangTxt_Native_IcPhase = _T("Ic相位");
	g_sLangID_Native_IcFreq = _T("Native_IcFreq");
	g_sLangTxt_Native_IcFreq = _T("Ic频率");

	g_sLangID_Native_IapAmp = _T("Native_IapAmp");
	g_sLangTxt_Native_IapAmp = _T("Iap幅值");
	g_sLangID_Native_IapPhase = _T("Native_IapPhase");
	g_sLangTxt_Native_IapPhase = _T("Iap相位");
	g_sLangID_Native_IapFreq = _T("Native_IapFreq");
	g_sLangTxt_Native_IapFreq = _T("Iap频率");

	g_sLangID_Native_IbpAmp = _T("Native_IbpAmp");
	g_sLangTxt_Native_IbpAmp = _T("Ibp幅值");
	g_sLangID_Native_IbpPhase = _T("Native_IbpPhase");
	g_sLangTxt_Native_IbpPhase = _T("Ibp相位");
	g_sLangID_Native_IbpFreq = _T("Native_IbpFreq");
	g_sLangTxt_Native_IbpFreq = _T("Ibp频率");

	g_sLangID_Native_IcpAmp = _T("Native_IcpAmp");
	g_sLangTxt_Native_IcpAmp = _T("Icp幅值");
	g_sLangID_Native_IcpPhase = _T("Native_IcpPhase");
	g_sLangTxt_Native_IcpPhase = _T("Icp相位");
	g_sLangID_Native_IcpFreq = _T("Native_IcpFreq");
	g_sLangTxt_Native_IcpFreq = _T("Icp频率");

	g_sLangID_Native_TestFuncCategory = _T("Native_TestFuncCategory");
	g_sLangTxt_Native_TestFuncCategory = _T("测试功能类别(0:普通手动试验1:MU精度测试2:MU零漂测试)");

	// tmt_pt_test
	g_sLangID_Native_PT1Impedance = _T("Native_PT1Impedance");
	g_sLangTxt_Native_PT1Impedance = _T("PT1阻值");
	g_sLangID_Native_PT2Impedance = _T("Native_PT2Impedance");
	g_sLangTxt_Native_PT2Impedance = _T("PT2阻值");

	// tmt_record
	g_sLangID_Native_RecvOptPort = _T("Native_RecvOptPort");
	g_sLangTxt_Native_RecvOptPort = _T("接收光口");
	g_sLangID_Native_TotalSubs = _T("Native_TotalSubs");
	g_sLangTxt_Native_TotalSubs = _T("订阅总数");

	// tmt_NEW
	g_sLangID_Native_UasAmp = _T("Native_UasAmp");
	g_sLangTxt_Native_UasAmp = _T("Uas幅值");
	g_sLangID_Native_UasPhase = _T("Native_UasPhase");
	g_sLangTxt_Native_UasPhase = _T("Uas相位");
	g_sLangID_Native_UasFreq = _T("Native_UasFreq");
	g_sLangTxt_Native_UasFreq = _T("Uas频率");

	g_sLangID_Native_UbsAmp = _T("Native_UbsAmp");
	g_sLangTxt_Native_UbsAmp = _T("Ubs幅值");
	g_sLangID_Native_UbsPhase = _T("Native_UbsPhase");
	g_sLangTxt_Native_UbsPhase = _T("Ubs相位");
	g_sLangID_Native_UbsFreq = _T("Native_UbsFreq");
	g_sLangTxt_Native_UbsFreq = _T("Ubs频率");

	g_sLangID_Native_UcsAmp = _T("Native_UcsAmp");
	g_sLangTxt_Native_UcsAmp = _T("Ucs幅值");
	g_sLangID_Native_UcsPhase = _T("Native_UcsPhase");
	g_sLangTxt_Native_UcsPhase = _T("Ucs相位");
	g_sLangID_Native_UcsFreq = _T("Native_UcsFreq");
	g_sLangTxt_Native_UcsFreq = _T("Ucs频率");

	g_sLangID_Native_UatAmp = _T("Native_UatAmp");
	g_sLangTxt_Native_UatAmp = _T("Uat幅值");
	g_sLangID_Native_UatPhase = _T("Native_UatPhase");
	g_sLangTxt_Native_UatPhase = _T("Uat相位");
	g_sLangID_Native_UatFreq = _T("Native_UatFreq");
	g_sLangTxt_Native_UatFreq = _T("Uat频率");

	g_sLangID_Native_UbtAmp = _T("Native_UbtAmp");
	g_sLangTxt_Native_UbtAmp = _T("Ubt幅值");
	g_sLangID_Native_UbtPhase = _T("Native_UbtPhase");
	g_sLangTxt_Native_UbtPhase = _T("Ubt相位");
	g_sLangID_Native_UbtFreq = _T("Native_UbtFreq");
	g_sLangTxt_Native_UbtFreq = _T("Ubt频率");

	g_sLangID_Native_UctAmp = _T("Native_UctAmp");
	g_sLangTxt_Native_UctAmp = _T("Uct幅值");
	g_sLangID_Native_UctPhase = _T("Native_UctPhase");
	g_sLangTxt_Native_UctPhase = _T("Uct相位");
	g_sLangID_Native_UctFreq = _T("Native_UctFreq");
	g_sLangTxt_Native_UctFreq = _T("Uct频率");

	g_sLangID_Native_IasAmp = _T("Native_IasAmp");
	g_sLangTxt_Native_IasAmp = _T("Ias幅值");
	g_sLangID_Native_IasPhase = _T("Native_IasPhase");
	g_sLangTxt_Native_IasPhase = _T("Ias相位");
	g_sLangID_Native_IasFreq = _T("Native_IasFreq");
	g_sLangTxt_Native_IasFreq = _T("Ias频率");

	g_sLangID_Native_IbsAmp = _T("Native_IbsAmp");
	g_sLangTxt_Native_IbsAmp = _T("Ibs幅值");
	g_sLangID_Native_IbsPhase = _T("Native_IbsPhase");
	g_sLangTxt_Native_IbsPhase = _T("Ibs相位");
	g_sLangID_Native_IbsFreq = _T("Native_IbsFreq");
	g_sLangTxt_Native_IbsFreq = _T("Ibs频率");

	g_sLangID_Native_IcsAmp = _T("Native_IcsAmp");
	g_sLangTxt_Native_IcsAmp = _T("Ics幅值");
	g_sLangID_Native_IcsPhase = _T("Native_IcsPhase");
	g_sLangTxt_Native_IcsPhase = _T("Ics相位");
	g_sLangID_Native_IcsFreq = _T("Native_IcsFreq");
	g_sLangTxt_Native_IcsFreq = _T("Ics频率");

	g_sLangID_Native_IatAmp = _T("Native_IatAmp");
	g_sLangTxt_Native_IatAmp = _T("Iat幅值");
	g_sLangID_Native_IatPhase = _T("Native_IatPhase");
	g_sLangTxt_Native_IatPhase = _T("Iat相位");
	g_sLangID_Native_IatFreq = _T("Native_IatFreq");
	g_sLangTxt_Native_IatFreq = _T("Iat频率");

	g_sLangID_Native_IbtAmp = _T("Native_IbtAmp");
	g_sLangTxt_Native_IbtAmp = _T("Ibt幅值");
	g_sLangID_Native_IbtPhase = _T("Native_IbtPhase");
	g_sLangTxt_Native_IbtPhase = _T("Ibt相位");
	g_sLangID_Native_IbtFreq = _T("Native_IbtFreq");
	g_sLangTxt_Native_IbtFreq = _T("Ibt频率");

	g_sLangID_Native_IctAmp = _T("Native_IctAmp");
	g_sLangTxt_Native_IctAmp = _T("Ict幅值");
	g_sLangID_Native_IctPhase = _T("Native_IctPhase");
	g_sLangTxt_Native_IctPhase = _T("Ict相位");
	g_sLangID_Native_IctFreq = _T("Native_IctFreq");
	g_sLangTxt_Native_IctFreq = _T("Ict频率");

	// tmt_replay_test
	g_sLangID_Native_ModReplace = _T("Native_ModReplace");
	g_sLangTxt_Native_ModReplace = _T("模块%d");
	g_sLangID_Native_TIC_A_Chn_Num = _T("Native_TIC_A_Chn_Num");
	g_sLangTxt_Native_TIC_A_Chn_Num = _T("测试仪通道%d_A通道序号");
	g_sLangID_Native_TIC_B_Chn_Num = _T("Native_TIC_B_Chn_Num");
	g_sLangTxt_Native_TIC_B_Chn_Num = _T("测试仪通道%d_B通道序号");
	g_sLangID_Native_TIC_TransfRatio = _T("Native_TIC_TransfRatio");
	g_sLangTxt_Native_TIC_TransfRatio = _T("测试仪通道%d_变比");
	g_sLangID_Native_SampFreq = _T("Native_SampFreq");
	g_sLangTxt_Native_SampFreq = _T("采样频率");
	g_sLangID_Native_PT_TxRatio_Primary = _T("Native_PT_TxRatio_Primary");
	g_sLangTxt_Native_PT_TxRatio_Primary = _T("PT变比一次值");
	g_sLangID_Native_PT_TxRatio_Secondary = _T("Native_PT_TxRatio_Secondary");
	g_sLangTxt_Native_PT_TxRatio_Secondary = _T("PT变比二次值");
	g_sLangID_Native_CT_TxRatio_Primary = _T("Native_CT_TxRatio_Primary");
	g_sLangTxt_Native_CT_TxRatio_Primary = _T("CT变比一次值");
	g_sLangID_Native_CT_TxRatio_Secondary = _T("Native_CT_TxRatio_Secondary");
	g_sLangTxt_Native_CT_TxRatio_Secondary = _T("CT变比二次值");
	g_sLangID_Native_NumOfModules = _T("Native_NumOfModules");
	g_sLangTxt_Native_NumOfModules = _T("模块数");
	g_sLangID_Native_WaveFileName = _T("Native_WaveFileName");
	g_sLangTxt_Native_WaveFileName = _T("录波文件名称");
	g_sLangID_Native_NumCycles = _T("Native_NumCycles");
	g_sLangTxt_Native_NumCycles = _T("周波数量");
	g_sLangID_Native_PostTrigMode = _T("Native_PostTrigMode");
	g_sLangTxt_Native_PostTrigMode = _T("触发后模式");
	g_sLangID_Native_ExpTrigTime = _T("Native_ExpTrigTime");
	g_sLangTxt_Native_ExpTrigTime = _T("实验触发时间");
	g_sLangID_Native_CycleIndex = _T("Native_CycleIndex");
	g_sLangTxt_Native_CycleIndex =	_T("全部循环次数");
	g_sLangID_Native_ManualControl = _T("Native_ManualControl");
	g_sLangTxt_Native_ManualControl =_T("手动控制");			 
	g_sLangID_Native_ReplayInterval = _T("Native_ReplayInterval");
	g_sLangTxt_Native_ReplayInterval	 =_T("时间间隔");

	g_sLangID_Native_ImpedanceEditBox = _T("Native_ImpedanceEditBox");
	g_sLangTxt_Native_ImpedanceEditBox = _T("阻抗特性编辑框");

	g_sLangID_Adjustment_Time = _T("Adjustment_Time");
	g_sLangTxt_Adjustment_Time = _T("整定动作时间");
	g_sLangID_Native_networkId = _T("Native_networkIdentifier");
	g_sLangTxt_Native_networkId = _T("网络标识");

	g_sLangID_Native_VolactValue = _T("Native_VolactValue");
	g_sLangTxt_Native_VolactValue = _T("电压动作值(%)");
	g_sLangID_Native_CuractValue = _T("Native_CuractValue");
	g_sLangTxt_Native_CuractValue = _T("电流动作值(%)");
	g_sLangID_Native_harmonicNotChecked = _T("Native_harmonicNotChecked");
	g_sLangTxt_Native_harmonicNotChecked = _T("指定通道的谐波未被勾选!");

	g_sLangID_Native_DCVmapping = _T("Native_DCVmapping");
	g_sLangTxt_Native_DCVmapping = _T("直流电压映射");
	g_sLangID_Native_DCImapping = _T("Native_DCImapping");
	g_sLangTxt_Native_DCImapping = _T("直流电流映射");
	g_sLangID_Native_ACVmapping = _T("Native_ACVmapping");
	g_sLangTxt_Native_ACVmapping = _T("交流电压映射");
	g_sLangID_Native_ACImapping = _T("Native_ACImapping");
	g_sLangTxt_Native_ACImapping = _T("交流电流映射");
	g_sLangID_Native_FailtoGetsclPath = _T("Native_FailtoGetsclPath");
	g_sLangTxt_Native_FailtoGetsclPath = _T("获取SCL文件路径失败(%s).");

	g_sLangID_Native_codesSetting = _T("Native_codesSetting");
	g_sLangTxt_Native_codesSetting = _T("码值设置");
	g_sLangID_Native_DCPart = _T("Native_DCPart");
	g_sLangTxt_Native_DCPart = _T("直流部分");
	g_sLangID_Native_ACPart = _T("Native_ACPart");
	g_sLangTxt_Native_ACPart = _T("交流部分");

	g_sLangID_Native_selected = _T("Native_selected");
	g_sLangTxt_Native_selected = _T("已选中");
	g_sLangID_Native_schematic = _T("Native_schematic");
	g_sLangTxt_Native_schematic = _T("示意图");
	g_sLangID_Native_codesValue = _T("Native_codesValue");
	g_sLangTxt_Native_codesValue = _T("码值");

	// ImportDvmFile
	g_sLangID_Native_modifyto = _T("Native_modifyto");
	g_sLangTxt_Native_modifyto = _T("修改为");
	g_sLangID_Native_function = _T("Native_function");
	g_sLangTxt_Native_function = _T("功能");
	g_sLangID_Native_completeconfig = _T("Native_completeconfig");
	g_sLangTxt_Native_completeconfig = _T("完成配置");
	g_sLangID_Native_nextitem = _T("Native_nextitem");
	g_sLangTxt_Native_nextitem = _T("下一项");
	g_sLangID_Native_previtem = _T("Native_previtem");
	g_sLangTxt_Native_previtem = _T("上一项");
	g_sLangID_Native_ttybzd = _T("Native_ttybzd");
	g_sLangTxt_Native_ttybzd = _T("_投退压板整定");
	g_sLangID_Native_FixedValueSet = _T("Native_FixedValueSet");
	g_sLangTxt_Native_FixedValueSet = _T("_修改定值整定");

	g_sLangID_Native_PYResnotFound = _T("Native_PYResnotFound");
	g_sLangTxt_Native_PYResnotFound = _T("没有找到中文拼音资源文件!");

	g_sLangID_Native_dataid = _T("Native_dataid");
	g_sLangTxt_Native_dataid = _T("数据ID");

	g_sLangID_Native_globalparams = _T("Native_globalparams");
	g_sLangTxt_Native_globalparams = _T("全局参数");
	g_sLangID_Native_reportdata = _T("Native_reportdata");
	g_sLangTxt_Native_reportdata = _T("报告数据");
	g_sLangID_Native_switchreport = _T("Native_switchreport");
	g_sLangTxt_Native_switchreport = _T("切换报告");

	g_sLangID_Native_reportdataname = _T("Native_reportdataname");
	g_sLangTxt_Native_reportdataname = _T("报告数据名称");
	g_sLangID_Native_paramone = _T("Native_paramone");
	g_sLangTxt_Native_paramone = _T("参数一");
	g_sLangID_Native_paramtwo = _T("Native_paramtwo");
	g_sLangTxt_Native_paramtwo = _T("参数二");

	g_sLangID_Native_baselineparams = _T("Native_baselineparams");
	g_sLangTxt_Native_baselineparams = _T("基准参数");
	g_sLangID_Native_errorresult = _T("Native_errorresult");
	g_sLangTxt_Native_errorresult = _T("误差结果");
	g_sLangID_Native_errorlimit = _T("Native_errorlimit");
	g_sLangTxt_Native_errorlimit = _T("误差限");

	g_sLangID_Native_notcalculated = _T("Native_notcalculated");
	g_sLangTxt_Native_notcalculated = _T("未计算");
	g_sLangID_Native_baseline_min = _T("Native_baseline_min");
	g_sLangTxt_Native_baseline_min = _T("基准-最小值");
	g_sLangID_Native_baseline_max = _T("Native_baseline_max");
	g_sLangTxt_Native_baseline_max = _T("基准-最大值");
	g_sLangID_Native_operationresult = _T("Native_operationresult");
	g_sLangTxt_Native_operationresult = _T("运算结果");

	// 第九周许
	// 10.30
	g_sLangID_Native_SelectParamFirst = _T("Native_SelectParamFirst");
	g_sLangTxt_Native_SelectParamFirst = _T("请先在左侧选中需要映射的参数，然后再进行映射……");
	g_sLangID_Native_NoValidMapData = _T("Native_NoValidMapData");
	g_sLangTxt_Native_NoValidMapData = _T("当前配置没找到有效的映射数据，配置无效！");
	g_sLangID_Native_DeviceModel = _T("Native_DeviceModel");
	g_sLangTxt_Native_DeviceModel = _T("在左侧表格选中需要映射的参数后，在右侧表格双击需要映射的模型数据");
	g_sLangID_Native_Dataset = _T("Native_Dataset");
	g_sLangTxt_Native_Dataset = _T("数据集：");
	g_sLangID_Native_AddNew = _T("Native_AddNew");
	g_sLangTxt_Native_AddNew = _T("新增");
	g_sLangID_Native_ClearMap = _T("Native_ClearMap");
	g_sLangTxt_Native_ClearMap = _T("清空所有映射");
	g_sLangID_Native_ClearSel = _T("Native_ClearSel");
	g_sLangTxt_Native_ClearSel = _T("清除选中映射");
	g_sLangID_Native_CustomName = _T("Native_CustomName");
	g_sLangTxt_Native_CustomName = _T("自定义名称");
	g_sLangID_Native_RealDevData = _T("Native_RealDevData");
	g_sLangTxt_Native_RealDevData = _T("实际装置的数据名称");
	g_sLangID_Native_DataInSet = _T("Native_DataInSet");
	g_sLangTxt_Native_DataInSet = _T("数据所在数据集");
	g_sLangID_Native_CurveName = _T("Native_CurveName");
	g_sLangTxt_Native_CurveName = _T("曲线名称");
	g_sLangID_Native_SingleTimeLimit = _T("Native_SingleTimeLimit");
	g_sLangTxt_Native_SingleTimeLimit = _T("1段定时限");
	g_sLangID_Native_DoubleTimeLimit = _T("Native_DoubleTimeLimit");
	g_sLangTxt_Native_DoubleTimeLimit = _T("2段定时限");
	g_sLangID_Native_TripleTimeLimit = _T("Native_TripleTimeLimit");
	g_sLangTxt_Native_TripleTimeLimit = _T("3段定时限");
	g_sLangID_Native_CurrentValueI = _T("Native_CurrentValueI");
	g_sLangTxt_Native_CurrentValueI = _T("电流值");
	g_sLangID_Native_ActionThres = _T("Native_ActionThres");
	g_sLangTxt_Native_ActionThres = _T("动作门槛");
	g_sLangID_Native_FeatCurveElem = _T("Native_FeatCurveElem");
	g_sLangTxt_Native_FeatCurveElem = _T("特性曲线元素");
	g_sLangID_Native_IEEECurveSet = _T("Native_IEEECurveSet");
	g_sLangTxt_Native_IEEECurveSet = _T("IEEE曲线元素设置");
	g_sLangID_Native_IACCurveSet = _T("Native_IACCurveSet");
	g_sLangTxt_Native_IACCurveSet = _T("IAC曲线元素设置");
	g_sLangID_Native_I2TCurveSet = _T("Native_I2TCurveSet");
	g_sLangTxt_Native_I2TCurveSet = _T("I2T曲线元素设置");
	g_sLangID_Native_IECCurveSet = _T("Native_IECCurveSet");
	g_sLangTxt_Native_IECCurveSet = _T("IEC曲线元素设置");
	g_sLangID_Native_Threshold = _T("Native_Threshold");
	g_sLangTxt_Native_Threshold = _T("门槛值");
	g_sLangID_Native_QuickBreak = _T("Native_QuickBreak");
	g_sLangTxt_Native_QuickBreak = _T("速断定值");
	g_sLangID_Native_FirstPart = _T("Native_FirstPart");
	g_sLangTxt_Native_FirstPart = _T("第一段");
	g_sLangID_Native_Inflection1 = _T("Inflection1");
	g_sLangTxt_Native_Inflection1 = _T("拐点1");
	g_sLangID_Native_SecondPart = _T("Native_SecondPart");
	g_sLangTxt_Native_SecondPart = _T("第二段");
	g_sLangID_Native_InflectionPoint2 = _T("Native_InflectionPoint2");
	g_sLangTxt_Native_InflectionPoint2 = _T("拐点2");
	g_sLangID_Native_TestCtrlProgDate = _T("Native_TestCtrlProgDate");
	g_sLangTxt_Native_TestCtrlProgDate = _T("当前测试控制程序生成日期(%s).");
	g_sLangID_Native_DebugOutput = _T("Native_DebugOutput");
	g_sLangTxt_Native_DebugOutput = _T("输出调试");
	//g_sLangID_Native_StartOutput = _T("Native_StartOutput");
	//g_sLangTxt_Native_StartOutput = _T("开始输出");
	g_sLangID_Native_StopOutput = _T("Native_StopOutput");
	g_sLangTxt_Native_StopOutput = _T("停止输出");
	
	//g_sLangID_Native_TestAnomalies = _T("Native_TestAnomalies");
	//g_sLangTxt_Native_TestAnomalies = _T("测试异常");

	//g_sLangID_Native_RelieveTestAnomalies = _T("Native_RelieveTestAnomalies");
	//g_sLangTxt_Native_RelieveTestAnomalies = _T("解除测试异常");

	//g_sLangID_Native_StateSwitch = _T("Native_StateSwitch");
	//g_sLangTxt_Native_StateSwitch = _T("状态切换");

	//g_sLangID_Native_SupDCSwitch = _T("Native_SupDCSwitch");
	//g_sLangTxt_Native_SupDCSwitch = _T("辅助直流切换");

	//g_sLangID_Native_BinDisPlace = _T("Native_BinDisPlace");
	//g_sLangTxt_Native_BinDisPlace = _T("开入变位");

	//g_sLangID_Native_BoutDisPlace = _T("Native_BinDisPlace");
	//g_sLangTxt_Native_BoutDisPlace = _T("开出变位");

	//g_sLangID_Native_ParaUpdata = _T("Native_ParaUpdata");
	//g_sLangTxt_Native_ParaUpdata = _T("参数更新");

	g_sLangID_Native_OpenFail = _T("Native_OpenFail");
	g_sLangTxt_Native_OpenFail = _T("打开文件(%s)失败.");
	g_sLangID_Native_Disconnect = _T("Native_Disconnect");
	g_sLangTxt_Native_Disconnect = _T("与测试仪断开连接，请检查网络链路是否连通，IP地址及端口配置是否正确；重新连接");
	g_sLangID_Native_StateGraph = _T("Native_StateGraph");
	g_sLangTxt_Native_StateGraph = _T("状态图");
	g_sLangID_Native_SoftResID = _T("Native_SoftResID");
	g_sLangTxt_Native_SoftResID = _T("软件资源标识");
	g_sLangID_Native_EnterNum = _T("Native_EnterNum");
	g_sLangTxt_Native_EnterNum = _T("请输入数值，不能为空！");
	g_sLangID_Native_SendByWave = _T("Native_SendByWave");
	g_sLangTxt_Native_SendByWave = _T("按周波发送");
	g_sLangID_Native_SendBySec = _T("Native_SendBySec");
	g_sLangTxt_Native_SendBySec = _T("按秒发送");
	g_sLangID_Native_StateNetID = _T("Native_StateNetID");
	g_sLangTxt_Native_StateNetID = _T("当前状态%d : 网络标识(0x%s)与原网络标识(0x%s)不一致");
	g_sLangID_Native_ExportWords = _T("Native_ExportWords");
	g_sLangTxt_Native_ExportWords = _T("导出Word报告");
	g_sLangID_Native_WordDoc = _T("Native_WordDoc");
	g_sLangTxt_Native_WordDoc = _T("Word报告文件 (*.doc)");
	g_sLangID_Native_ExportPath = _T("Native_ExportPath");
	g_sLangTxt_Native_ExportPath = _T("导出路径：");
	g_sLangID_Native_AbnCurr = _T("Native_AbnCurr");
	g_sLangTxt_Native_AbnCurr = _T("异常电流");

	// 第九周马
	g_sLangID_Native_UnzipError = _T("Native_UnzipError");
	g_sLangTxt_Native_UnzipError = _T("stt_rcd_unzip_file解压缩出错.");
	g_sLangID_Native_ExpPcapInterf = _T("Native_ExpPcapInterf");
	g_sLangTxt_Native_ExpPcapInterf = _T("导出Pcap文件界面");
	g_sLangID_Native_RawDataFile = _T("Native_RawDataFile");
	g_sLangTxt_Native_RawDataFile = _T("原始数据文件:");
	g_sLangID_Native_SelectOmit = _T("Native_SelectOmit");
	g_sLangTxt_Native_SelectOmit = _T("选择省略...");
	g_sLangID_Native_PcapFileN = _T("Native_PcapFileN");
	g_sLangTxt_Native_PcapFileN = _T("Pcap文件名:");
	g_sLangID_Native_StartConver = _T("Native_StartConver");
	g_sLangTxt_Native_StartConver = _T("开始转换");
	g_sLangID_Native_at02dCompFiles = _T("Native_at02dCompFiles");
	g_sLangTxt_Native_at02dCompFiles = _T("at02d压缩文件(*.at02dz);;at02d文件(*.at02d)");
	g_sLangID_Native_SelectRawFile = _T("Native_SelectRawFile");
	g_sLangTxt_Native_SelectRawFile = _T("请先选择原始数据文件.");
	g_sLangID_Native_SetOutFileName = _T("Native_SetOutFileName");
	g_sLangTxt_Native_SetOutFileName = _T("请先设置生成文件名称.");
	g_sLangID_Native_CurRawFileNotEx = _T("Native_CurRawFileNotEx");
	g_sLangTxt_Native_CurRawFileNotEx = _T("当前原始数据文件(%s)不存在.");
	g_sLangID_Native_PcapGenSuccess = _T("Native_PcapGenSuccess");
	g_sLangTxt_Native_PcapGenSuccess = _T("Pcap文件(%s)生成成功.");
	g_sLangID_Native_PcapGenFailed = _T("Native_PcapGenFailed");
	g_sLangTxt_Native_PcapGenFailed = _T("Pcap文件(%s)生成失败.");
	g_sLangID_Native_BaudRate = _T("Native_BaudRate");
	g_sLangTxt_Native_BaudRate = _T("波特率");
	g_sLangID_Native_MsgLength = _T("Native_MsgLength");
	g_sLangTxt_Native_MsgLength = _T("报文长度");
	g_sLangID_Native_UnkwnMsgType = _T("Native_UnkwnMsgType");
	g_sLangTxt_Native_UnkwnMsgType = _T("未知的报文类型(%u)");
	g_sLangID_Native_CurrPsdM0AssocAftRcvM = _T("Native_CurrPsdM0AssocAftRcvM");
	g_sLangTxt_Native_CurrPsdM0AssocAftRcvM = _T("当前解析的报文帧数为0,需收到报文后,才能关联.");
	g_sLangID_Native_RecTime = _T("Native_RecTime");
	g_sLangTxt_Native_RecTime = _T("录波时间");
	g_sLangID_Native_StopRecrd = _T("Native_StopRecrd");
	g_sLangTxt_Native_StopRecrd = _T("停止录波");
	g_sLangID_Native_ValdValue = _T("Native_ValdValue");
	g_sLangTxt_Native_ValdValue = _T("有效值");
	g_sLangID_Native_IncRate = _T("Native_IncRate");
	g_sLangTxt_Native_IncRate = _T("含有率");
	g_sLangID_Native_BarChar = _T("Native_BarChar");
	g_sLangTxt_Native_BarChar = _T("柱状图");
	g_sLangID_Native_RecWaveform = _T("Native_RecWaveform");
	g_sLangTxt_Native_RecWaveform = _T("录波");
	g_sLangID_Native_CurrWrtFileEmpty = _T("Native_CurrWrtFileEmpty");
	g_sLangTxt_Native_CurrWrtFileEmpty = _T("当前写文件路径为空.");
	g_sLangID_Native_SaveAs = _T("Native_SaveAs");
	g_sLangTxt_Native_SaveAs = _T("文件保存为");
	g_sLangID_Native_FileSavedSucc = _T("Native_FileSavedSucc");
	g_sLangTxt_Native_FileSavedSucc = _T("文件(%s)保存成功.");
	g_sLangID_Native_FileSaveFailed = _T("Native_FileSaveFailed");
	g_sLangTxt_Native_FileSaveFailed = _T("文件(%s)保存失败.");
	g_sLangID_Native_FileExist = _T("Native_FileExist");
	g_sLangTxt_Native_FileExist = _T("文件已存在,是否替换？");
	g_sLangID_Native_FileSave = _T("Native_FileSave");
	g_sLangTxt_Native_FileSave = _T("文件保存成功");
	
	g_sLangID_Native_Accept = _T("Native_Accept");
	g_sLangTxt_Native_Accept = _T("接收");
	g_sLangID_Native_SVMsgDispersView = _T("Native_SVMsgDispersView");
	g_sLangTxt_Native_SVMsgDispersView = _T("SV报文离散度视图");
	g_sLangID_Native_DCVoltAmp = _T("Native_DCVoltAmp");
	g_sLangTxt_Native_DCVoltAmp = _T("直流(V/A)");
	g_sLangID_Native_FundamentalVA = _T("Native_FundamentalVA");
	g_sLangTxt_Native_FundamentalVA = _T("基波(V/A)");
	g_sLangID_Native_LowLevelTmplFail = _T("Native_LowLevelTmplFail");
	g_sLangTxt_Native_LowLevelTmplFail = _T("底层测试模板生成失败.");
	g_sLangID_Native_StartTestSendFail = _T("Native_StartTestSendFail");
	g_sLangTxt_Native_StartTestSendFail = _T("开始测试命令下发失败.");
	g_sLangID_Native_StopTestSendFail = _T("Native_StopTestSendFail");
	g_sLangTxt_Native_StopTestSendFail = _T("停止测试命令下发失败.");
	g_sLangID_Native_StatusLDActTime = _T("Native_StatusLDActTime");
	g_sLangTxt_Native_StatusLDActTime = _T("状态%ld动作时间%.4lfs.");
	g_sLangID_Native_CloseFeatPromptSave = _T("Native_CloseFeatPromptSave");
	g_sLangTxt_Native_CloseFeatPromptSave = _T("?????????????? OnCmd_NewTest: 关闭打开的测试功能页面，并弹框提示是否保存修改 ???????????");
	g_sLangID_Native_InsData = _T("Native_InsData");
	g_sLangTxt_Native_InsData = _T("插入数据");
	g_sLangID_Native_ExecComm = _T("Native_ExecComm");
	g_sLangTxt_Native_ExecComm = _T("执行通信");
	g_sLangID_Native_DelSelData = _T("Native_DelSelData");
	g_sLangTxt_Native_DelSelData = _T("删除选中数据");
	g_sLangID_Native_SendChanges = _T("Native_SendChanges");
	g_sLangTxt_Native_SendChanges = _T("是否变化上送");
	g_sLangID_Native_CycleTm = _T("Native_CycleTm");
	g_sLangTxt_Native_CycleTm = _T("周期时间");
	g_sLangID_Native_ErrName = _T("Native_ErrName");
	g_sLangTxt_Native_ErrName = _T("误差名称");
	g_sLangID_Native_ErrValue = _T("Native_ErrValue");
	g_sLangTxt_Native_ErrValue = _T("误差值");
	g_sLangID_Native_TestCat = _T("Native_TestCat");
	g_sLangTxt_Native_TestCat = _T("测试分类");
	g_sLangID_Native_TitleLvl = _T("Native_TitleLvl");
	g_sLangTxt_Native_TitleLvl = _T("标题等级");
	g_sLangID_Native_ProjIdent = _T("Native_ProjIdent");
	g_sLangTxt_Native_ProjIdent = _T("项目标识");
	g_sLangID_Native_AsWordTitle = _T("Native_AsWordTitle");
	g_sLangTxt_Native_AsWordTitle = _T("作为Word标题");
	g_sLangID_Native_ModProjName = _T("Native_ModProjName");
	g_sLangTxt_Native_ModProjName = _T("修改项目名称");
	g_sLangID_Native_Wizard = _T("Native_Wizard");
	g_sLangTxt_Native_Wizard = _T("向导");
	g_sLangID_Native_PrevStep = _T("Native_PrevStep");
	g_sLangTxt_Native_PrevStep = _T("上一步");
	g_sLangID_Native_WebPageNotExst = _T("Native_WebPageNotExst");
	g_sLangTxt_Native_WebPageNotExst = _T("网页文件(%s)不存在.");
	g_sLangID_Native_IEDNotSel = _T("Native_IEDNotSel");
	g_sLangTxt_Native_IEDNotSel = _T("未选择IED");

	// Controls
	g_sLangID_Native_DevType = _T("Native_DevType");
	g_sLangTxt_Native_DevType = _T("设备类型");
	g_sLangID_Native_ProtoEngin = _T("Native_ProtoEngin");
	g_sLangTxt_Native_ProtoEngin = _T("规约引擎");
	g_sLangID_Native_DevIP = _T("Native_DevIP");
	g_sLangTxt_Native_DevIP = _T("装置IP");
	g_sLangID_Native_DevPort = _T("Native_DevPort");
	g_sLangTxt_Native_DevPort = _T("装置端口");
	g_sLangID_Native_ProtoTemp = _T("Native_ProtoTemp");
	g_sLangTxt_Native_ProtoTemp = _T("规约模板");
	g_sLangID_Native_SelSCDFile = _T("Native_SelSCDFile");
	g_sLangTxt_Native_SelSCDFile = _T("从SCD文件选择");
	g_sLangID_Native_AdvConfig = _T("Native_AdvConfig");
	g_sLangTxt_Native_AdvConfig = _T("高级配置");
	g_sLangID_Native_TimeSetUnit = _T("Native_TimeSetUnit");
	g_sLangTxt_Native_TimeSetUnit = _T("时间定值单位为ms");
	g_sLangID_Native_AddDevReset = _T("Native_AddDevReset");
	g_sLangTxt_Native_AddDevReset = _T("添加装置复归态");
	g_sLangID_Native_NewCat = _T("Native_NewCat");
	g_sLangTxt_Native_NewCat = _T("新分类");
	g_sLangID_Native_ProjSameExists = _T("Native_ProjSameExists");
	g_sLangTxt_Native_ProjSameExists = _T("存在相同名称的项目");
	g_sLangID_Native_ProjSameIDExists = _T("Native_ProjSameIDExists");
	g_sLangTxt_Native_ProjSameIDExists = _T("存在相同ID的项目");
	g_sLangID_Native_TestCntGt1AutoUpdtProjName = _T("Native_TestCntGt1AutoUpdtProjName");
	g_sLangTxt_Native_TestCntGt1AutoUpdtProjName = _T("测试次数 >1时，自动更新到项目名称");
	g_sLangID_Native_NameWordTitle = _T("Native_NameWordTitle");
	g_sLangTxt_Native_NameWordTitle = _T("名称作为word标题");
	g_sLangID_Native_PlsEntWiringInstruc = _T("Native_PlsEntWiringInstruc");
	g_sLangTxt_Native_PlsEntWiringInstruc = _T("请在此处输入接线提示信息……");
	g_sLangID_Native_NoMatchPresetInstrucPlsEntWiring = _T("Native_NoMatchPresetInstrucPlsEntWiring");
	g_sLangTxt_Native_NoMatchPresetInstrucPlsEntWiring = _T("未找到对应的预置提示信息，请在此处输入接线提示信息……");
	g_sLangID_Native_SelDesiredWiringInstruc = _T("Native_SelDesiredWiringInstruc");
	g_sLangTxt_Native_SelDesiredWiringInstruc = _T("选择需要的接线提示信息");
	g_sLangID_Native_DeletestrMsg = _T("Native_DeletestrMsg");
	g_sLangTxt_Native_DeletestrMsg = _T("确定要删除 [ ");
	g_sLangID_Native_DeletestrMsg2 = _T("Native_DeletestrMsg2");
	g_sLangTxt_Native_DeletestrMsg2 = _T(" ] 吗？");
	g_sLangID_Native_DeletestrMsg3 = _T("Native_DeletestrMsg3");
	g_sLangTxt_Native_DeletestrMsg3 = _T(" ] 吗？删除后无法恢复！");
	g_sLangID_Native_RestoreAfterTest = _T("Native_RestoreAfterTest");
	g_sLangTxt_Native_RestoreAfterTest = _T("测试后恢复");
	g_sLangID_Native_PrepBeforeTest = _T("Native_PrepBeforeTest");
	g_sLangTxt_Native_PrepBeforeTest = _T("测试前准备");
	g_sLangID_Native_CreateProjCat = _T("Native_CreateProjCat");
	g_sLangTxt_Native_CreateProjCat = _T("新建项目分类");
	g_sLangID_Native_CreatePrepBeforeTest = _T("Native_CreatePrepBeforeTest");
	g_sLangTxt_Native_CreatePrepBeforeTest = _T("新建测试前准备");
	g_sLangID_Native_CreateReplyAfterTest = _T("Native_CreateReplyAfterTest");
	g_sLangTxt_Native_CreateReplyAfterTest = _T("新建测试后恢复");
	g_sLangID_Native_DeleteCurrSelectedProj = _T("Native_DeleteCurrSelectedProj");
	g_sLangTxt_Native_DeleteCurrSelectedProj = _T("删除当前选中项目");
	g_sLangID_Native_EditCurrSelectedProj = _T("Native_EditCurrSelectedProj");
	g_sLangTxt_Native_EditCurrSelectedProj = _T("编辑当前选中项目");
	g_sLangID_Native_SaveCurrSelectedProj = _T("Native_SaveCurrSelectedProj");
	g_sLangTxt_Native_SaveCurrSelectedProj = _T("保存当前选中项目");
	g_sLangID_Native_AddFuncWizard = _T("Native_AddFuncWizard");
	g_sLangTxt_Native_AddFuncWizard = _T("添加功能向导");
	g_sLangID_Native_StartTestFromSelProj = _T("Native_StartTestFromSelProj");
	g_sLangTxt_Native_StartTestFromSelProj = _T("从当前选中项目开始测试");
	g_sLangID_Native_TestCurrSelProj = _T("Native_TestCurrSelProj");
	g_sLangTxt_Native_TestCurrSelProj = _T("测试当前选中项目");
	g_sLangID_Native_CreateCommCommand = _T("Native_CreateCommCommand");
	g_sLangTxt_Native_CreateCommCommand = _T("新建通讯命令");
	g_sLangID_Native_ConfirmDelProj = _T("Native_ConfirmDelProj");
	g_sLangTxt_Native_ConfirmDelProj = _T("确认删除项目");
	g_sLangID_Native_RenameCurrSelProj = _T("Native_RenameCurrSelProj");
	g_sLangTxt_Native_RenameCurrSelProj = _T("重命名当前选中项目");
	g_sLangID_Native_DeleteWiringInstr = _T("Native_DeleteWiringInstr");
	g_sLangTxt_Native_DeleteWiringInstr = _T("删除接线提示");
	g_sLangID_Native_AddPrePostCommCombo = _T("Native_AddPrePostCommCombo");
	g_sLangTxt_Native_AddPrePostCommCombo = _T("添加测试前、后通讯组合");
	g_sLangID_Native_CreateConfigProj = _T("Native_CreateConfigProj");
	g_sLangTxt_Native_CreateConfigProj = _T("新建配置项目");
	g_sLangID_Native_HWChanMapping = _T("Native_HWChanMapping");
	g_sLangTxt_Native_HWChanMapping = _T("硬件通道映射");
	g_sLangID_Native_IEC61850Config = _T("Native_IEC61850Config");
	g_sLangTxt_Native_IEC61850Config = _T("IEC61850配置");
	g_sLangID_Native_ConfirmDelWiringInstr = _T("Native_ConfirmDelWiringInstr");
	g_sLangTxt_Native_ConfirmDelWiringInstr = _T("确认删除接线提示");
	g_sLangID_Native_SaveProjInstrFailCommCmd = _T("Native_SaveProjInstrFailCommCmd");
	g_sLangTxt_Native_SaveProjInstrFailCommCmd = _T("保存项目指令，创建通讯命令失败！");
	g_sLangID_Native_SelProjNotExistRetryTest = _T("Native_SelProjNotExistRetryTest");
	g_sLangTxt_Native_SelProjNotExistRetryTest = _T("当前选中的项目，不存在！请重新选择项目后进行测试");
	g_sLangID_Native_NotSupportFeature = _T("Native_NotSupportFeature");
	g_sLangTxt_Native_NotSupportFeature = _T("该功能暂不支持……");
	g_sLangID_Native_AddSubitem = _T("Native_AddSubitem");
	g_sLangTxt_Native_AddSubitem = _T("添加至:子项");
	g_sLangID_Native_AddBeforeItem = _T("Native_AddBeforeItem");
	g_sLangTxt_Native_AddBeforeItem = _T("添加至:项之前");
	g_sLangID_Native_AddAfterItem = _T("Native_AddAfterItem");
	g_sLangTxt_Native_AddAfterItem = _T("添加至:项之后");
	g_sLangID_Native_ProjResults = _T("Native_ProjResults");
	g_sLangTxt_Native_ProjResults = _T("项目结果");
	g_sLangID_Native_AllRptData = _T("Native_AllRptData");
	g_sLangTxt_Native_AllRptData = _T("全部报告数据");
	g_sLangID_Native_RptDataDataset = _T("Native_RptDataDataset");
	g_sLangTxt_Native_RptDataDataset = _T("报告数据-数据集");
	g_sLangID_Native_TestConcl = _T("Native_TestConcl");
	g_sLangTxt_Native_TestConcl = _T("测试结论");
	g_sLangID_Native_ViewRpt = _T("Native_ViewRpt");
	g_sLangTxt_Native_ViewRpt = _T("查看报告");
	g_sLangID_Native_TestRun = _T("Native_TestRun");
	g_sLangTxt_Native_TestRun = _T("次测试");
	g_sLangID_Native_CalcResult = _T("Native_CalcResult");
	g_sLangTxt_Native_CalcResult = _T("次计算结果");
	g_sLangID_Native_gooseReceive = _T("Native_gooseReceive");
	g_sLangTxt_Native_gooseReceive = _T("GOOSE 接收");

	g_sLangID_Native_GroundDisSetV = _T("Native_GroundDisSetV");
	g_sLangTxt_Native_GroundDisSetV = _T("接地距离V定值"); // 接地距离定值（1-5段）
	g_sLangID_Native_GroundDisTimeI = _T("Native_GroundDisTimeI");
	g_sLangTxt_Native_GroundDisTimeI = _T("接地距离I段时间");
	g_sLangID_Native_GroundDisTimeII = _T("Native_GroundDisTimeII");
	g_sLangTxt_Native_GroundDisTimeII = _T("接地距离II段时间");
	g_sLangID_Native_GroundDisTimeIII = _T("Native_GroundDisTimeIII");
	g_sLangTxt_Native_GroundDisTimeIII = _T("接地距离III段时间");
	g_sLangID_Native_GroundDisTimeIV = _T("Native_GroundDisTimeIV");
	g_sLangTxt_Native_GroundDisTimeIV = _T("接地距离IV段时间");
	g_sLangID_Native_GroundDisTimeV = _T("Native_GroundDisTimeV");
	g_sLangTxt_Native_GroundDisTimeV = _T("接地距离V时间"); // 接地距离时间（1-5段）
	g_sLangID_Native_harmonicOrder = _T("Native_harmonicOrder");
	g_sLangTxt_Native_harmonicOrder = _T("谐波次数");

	g_sLangID_Native_AbnData = _T("Native_AbnData");
	g_sLangTxt_Native_AbnData = _T("异常数据");
	g_sLangID_Native_harmRepresent = _T("Native_harmRepresent");
	g_sLangTxt_Native_harmRepresent = _T("谐波表示方式");
	g_sLangID_Native_Identifier = _T("Native_Identifier");
	g_sLangTxt_Native_Identifier = _T("标识");
	g_sLangID_Native_InLogic = _T("Native_InLogic");
	g_sLangTxt_Native_InLogic = _T("开入逻辑");
	g_sLangID_Native_InputSet = _T("Native_InputSet");
	g_sLangTxt_Native_InputSet = _T("开入量设置");
	g_sLangID_Native_InstCurr = _T("Native_InstCurr");
	g_sLangTxt_Native_InstCurr = _T("速断电流");
	g_sLangID_Native_IsDC = _T("Native_IsDC");
	g_sLangTxt_Native_IsDC = _T("是否直流");

	g_sLangID_Native_AbnPointSet = _T("Native_AbnPointSet");
	g_sLangTxt_Native_AbnPointSet = _T("异常点设置");
	g_sLangID_Native_JitterTest = _T("Native_JitterTest");
	g_sLangTxt_Native_JitterTest = _T("抖动测试");
	g_sLangID_Native_JitterVal = _T("Native_JitterVal");
	g_sLangTxt_Native_JitterVal = _T("抖动值");

	g_sLangID_Native_AbnVolt = _T("Native_AbnVolt");
	g_sLangTxt_Native_AbnVolt = _T("异常电压");
	g_sLangID_Native_JumpVal = _T("Native_JumpVal");
	g_sLangTxt_Native_JumpVal = _T("跳变值");
	g_sLangID_Native_actionSetting = _T("Native_actionSetting");
	g_sLangTxt_Native_actionSetting = _T("动作定值");
	g_sLangID_Native_MaxTimeMalf = _T("Native_MaxTimeMalf");
	g_sLangTxt_Native_MaxTimeMalf = _T("最大故障时间");
	g_sLangID_Native_ModAllChan = _T("Native_ModAllChan");
	g_sLangTxt_Native_ModAllChan = _T("修改全部通道值");
	g_sLangID_Native_MsgSel = _T("Native_MsgSel");
	g_sLangTxt_Native_MsgSel = _T("报文选择");
	g_sLangID_Native_MsgSet = _T("Native_MsgSet");
	g_sLangTxt_Native_MsgSet = _T("报文设置");
	g_sLangID_Native_Multiple = _T("Native_Multiple");
	g_sLangTxt_Native_Multiple = _T("倍数");
	g_sLangID_Native_PreFaultVolt = _T("Native_PreFaultVolt");
	g_sLangTxt_Native_PreFaultVolt = _T("故障前电压");
	g_sLangID_Native_BCodeLogic= _T("Native_BCodeLogic");
	g_sLangTxt_Native_BCodeLogic = _T("B码逻辑") ;
	g_sLangID_Native_PreFaultCurr = _T("Native_PreFaultCurr");
	g_sLangTxt_Native_PreFaultCurr = _T("故障前电流");
	g_sLangID_Native_PhSetActValue = _T("Native_PhSetActValue");
	g_sLangTxt_Native_PhSetActValue = _T("相位整定动作值");
	g_sLangID_Native_Number = _T("Native_Number");
	g_sLangTxt_Native_Number = _T("第");
	g_sLangID_Native_BoundAngle1 = _T("Native_BoundAngle1");
	g_sLangTxt_Native_BoundAngle1 = _T("边界角1");
	g_sLangID_Native_BoundAngle2 = _T("Native_BoundAngle2");
	g_sLangTxt_Native_BoundAngle2 = _T("边界角2");
	g_sLangID_Native_ChannelSelect = _T("Native_ChannelSelect");
	g_sLangTxt_Native_ChannelSelect = _T("通道选择");
	g_sLangID_Native_PhaseDisSetI = _T("Native_PhaseDisSetI");
	g_sLangTxt_Native_PhaseDisSetI = _T("相间距离I段定值");
	g_sLangID_Native_PhaseDisSetII = _T("Native_PhaseDisSetII");
	g_sLangTxt_Native_PhaseDisSetII = _T("相间距离II段定值");
	g_sLangID_Native_PhaseDisSetIII = _T("Native_PhaseDisSetIII");
	g_sLangTxt_Native_PhaseDisSetIII = _T("相间距离III段定值");
	g_sLangID_Native_PhaseDisSetIV = _T("Native_PhaseDisSetIV");
	g_sLangTxt_Native_PhaseDisSetIV = _T("相间距离IV段定值");
	g_sLangID_Native_PhaseDisSetV = _T("Native_PhaseDisSetV");
	g_sLangTxt_Native_PhaseDisSetV = _T("相间距离V定值"); // 相间距离定值（1-5段）
	g_sLangID_Native_PhaseDisTimeI = _T("Native_PhaseDisTimeI");
	g_sLangTxt_Native_PhaseDisTimeI = _T("相间距离I段时间");
	g_sLangID_Native_PhaseDisTimeII = _T("Native_PhaseDisTimeII");
	g_sLangTxt_Native_PhaseDisTimeII = _T("相间距离II段时间");
	g_sLangID_Native_PhaseDisTimeIII = _T("Native_PhaseDisTimeIII");
	g_sLangTxt_Native_PhaseDisTimeIII = _T("相间距离III段时间");
	g_sLangID_Native_PhaseDisTimeIV = _T("Native_PhaseDisTimeIV");
	g_sLangTxt_Native_PhaseDisTimeIV = _T("相间距离IV段时间");
	g_sLangID_Native_PhaseDisTimeV = _T("Native_PhaseDisTimeV");
	g_sLangTxt_Native_PhaseDisTimeV = _T("相间距离V时间"); // 接地距离时间（1-5段）


	// 接地距离 电阻定值（1-5段）
	g_sLangID_Native_GroundResetI = _T("Native_GroundResetI");
	g_sLangTxt_Native_GroundResetI = _T("接地距离I段电阻定值");
	g_sLangID_Native_GroundResetII = _T(" Native_GroundResetII");
	g_sLangTxt_Native_GroundResetII = _T("接地距离II段电阻定值");
	g_sLangID_Native_GroundResetIII = _T("Native_GroundResetIII");
	g_sLangTxt_Native_GroundResetIII = _T("接地距离III段电阻定值");
	g_sLangID_Native_GroundResetIV = _T("Native_GroundResetIV");
	g_sLangTxt_Native_GroundResetIV = _T(" 接地距离IV段电阻定值");
	g_sLangID_Native_GroundResetV = _T("Native_GroundResetV");
	g_sLangTxt_Native_GroundResetV = _T("接地距离V段电阻定值"); 
	// 相间距离 电阻定值（1-5段）
	g_sLangID_Native_PhaseResetI = _T("Native_PhaseResetI");
	g_sLangTxt_Native_PhaseResetI = _T("相间距离I段电阻定值");
	g_sLangID_Native_PhaseResetII = _T(" Native_PhaseResetII");
	g_sLangTxt_Native_PhaseResetII = _T("相间距离II段电阻定值");
	g_sLangID_Native_PhaseResetIII = _T("Native_PhaseResetIII");
	g_sLangTxt_Native_PhaseResetIII = _T("相间距离III段电阻定值");
	g_sLangID_Native_PhaseResetIV = _T("Native_PhaseResetIV");
	g_sLangTxt_Native_PhaseResetIV = _T(" 相间距离IV段电阻定值");
	g_sLangID_Native_PhaseResetV = _T("Native_PhaseResetV");
	g_sLangTxt_Native_PhaseResetV = _T("相间距离V段电阻定值"); 
	// 接地距离电抗 （1-5段）
	g_sLangID_Native_GroundXesetI = _T(" Native_GroundXesetI");
	g_sLangTxt_Native_GroundXesetI = _T("接地距离I段电抗定值");
	g_sLangID_Native_GroundXesetII = _T("Native_GroundXesetII ");
	g_sLangTxt_Native_GroundXesetII = _T("接地距离II段电抗定值 ");
	g_sLangID_Native_GroundXesetIII = _T(" Native_GroundXesetIII");
	g_sLangTxt_Native_GroundXesetIII = _T("接地距离III段电抗定值");
	g_sLangID_Native_GroundXesetIV = _T("Native_GroundXesetIV ");
	g_sLangTxt_Native_GroundXesetIV = _T(" 接地距离IV段电抗定值");
	g_sLangID_Native_GroundXesetV = _T("Native_GroundXesetV ");
	g_sLangTxt_Native_GroundXesetV = _T("接地距离V段电抗定值");

	// 相间距离电抗 （1-5段）
	g_sLangID_Native_PhaseXesetI = _T(" Native_PhaseXesetI");
	g_sLangTxt_Native_PhaseXesetI = _T("相间距离I段电抗定值");
	g_sLangID_Native_PhaseXesetII = _T("Native_PhaseXesetII ");
	g_sLangTxt_Native_PhaseXesetII = _T("相间距离II段电抗定值 ");
	g_sLangID_Native_PhaseXesetIII = _T(" Native_PhaseXesetIII");
	g_sLangTxt_Native_PhaseXesetIII = _T("相间距离III段电抗定值");
	g_sLangID_Native_PhaseXesetIV = _T("Native_PhaseXesetIV ");
	g_sLangTxt_Native_PhaseXesetIV = _T(" 相间距离IV段电抗定值");
	g_sLangID_Native_PhaseXesetV = _T("Native_PhaseXesetV ");
	g_sLangTxt_Native_PhaseXesetV = _T("相间距离V段电抗定值");

	g_sLangID_Native_NatureMalf = _T("Native_NatureMalf");
	g_sLangTxt_Native_NatureMalf = _T("故障性质");
	g_sLangID_Native_Confm = _T("Native_Confm");
	g_sLangTxt_Native_Confm = _T("确认");
	g_sLangID_Native_OutTime = _T("Native_OutTime");
	g_sLangTxt_Native_OutTime = _T("输出时间");
	g_sLangID_Native_OutHoldTime = _T("Native_OutHoldTime");
	g_sLangTxt_Native_OutHoldTime = _T("开出量保持时间");
	g_sLangID_Native_CurSetActValue = _T("Native_CurSetActValue");
	g_sLangTxt_Native_CurSetActValue = _T("电流整定动作值");
	g_sLangID_Native_NetID = _T("Native_NetID");
	g_sLangTxt_Native_NetID = _T("网络标识   0x");
	g_sLangID_Native_DelayDev = _T("Native_DelayDev");
	g_sLangTxt_Native_DelayDev = _T("延时偏差");
	g_sLangID_Native_NormTime = _T("Native_NormTime");
	g_sLangTxt_Native_NormTime = _T("常态时间");
	g_sLangID_Native_oneToMany = _T("Native_oneToMany");
	g_sLangTxt_Native_oneToMany = _T("一个控制块对应多个线条");
	g_sLangID_Native_OpTimeSet = _T("Native_OpTimeSet");
	g_sLangTxt_Native_OpTimeSet = _T("动作时间定值");
	g_sLangID_Native_DelayTime = _T("Native_DelayTime");
	g_sLangTxt_Native_DelayTime = _T("延时时间");
	g_sLangID_Native_OrigMsgSet = _T("Native_OrigMsgSet");
	g_sLangTxt_Native_OrigMsgSet = _T("原始报文设置");
	g_sLangID_Native_DelayVar = _T("Native_DelayVar");
	g_sLangTxt_Native_DelayVar = _T("延时变化");
	g_sLangID_Native_OutputHoldTimeS = _T("Native_OutputHoldTimeS");
	g_sLangTxt_Native_OutputHoldTimeS = _T("开出保持时间");
	g_sLangID_Native_outputTimeLimit = _T("Native_outputTimeLimit");
	g_sLangTxt_Native_outputTimeLimit = _T("输出限时(s)");
	g_sLangID_Native_OverloadCurrChannel = _T("Native_OverloadCurrChannel");
	g_sLangTxt_Native_OverloadCurrChannel = _T("过负荷电流通道");
	g_sLangID_Native_delegate = _T("Native_delegate");
	g_sLangTxt_Native_delegate = _T("委托");

	g_sLangID_Native_phaseDifference = _T("Native_phaseDifference");
	g_sLangTxt_Native_phaseDifference = _T("相别");
	g_sLangID_Native_PreFaultTime = _T("Native_PreFaultTime");
	g_sLangTxt_Native_PreFaultTime = _T("故障前时间(s)");
	g_sLangID_Native_DestMAC = _T("Native_DestMAC");
	g_sLangTxt_Native_DestMAC = _T("目的MAC");
	g_sLangID_Native_DevSetMethod = _T("Native_DevSetMethod");
	g_sLangTxt_Native_DevSetMethod = _T("定值整定方式");
	g_sLangID_Native_DevTime = _T("Native_DevTime");
	g_sLangTxt_Native_DevTime = _T("偏差时间");
	g_sLangID_Native_DevVal = _T("Native_DevVal");
	g_sLangTxt_Native_DevVal = _T("偏差值");
	g_sLangID_Native_DiffSpdBrk = _T("Native_DiffSpdBrk");
	g_sLangTxt_Native_DiffSpdBrk = _T("差动速断");
	g_sLangID_Native_DurProtTrip = _T("Native_DurProtTrip");
	g_sLangTxt_Native_DurProtTrip = _T("保护动作后持续时间");
	g_sLangID_Native_error = _T("Native_error");
	g_sLangTxt_Native_error = _T("错误");
	g_sLangID_Native_ErrSeqTest = _T("Native_ErrSeqTest");
	g_sLangTxt_Native_ErrSeqTest = _T("错序测试");
	g_sLangID_Native_Fault = _T("Native_Fault");
	g_sLangTxt_Native_Fault = _T("故障");
	g_sLangID_Native_FaultChnl = _T("Native_FaultChnl");
	g_sLangTxt_Native_FaultChnl = _T("故障通道");
	g_sLangID_Native_FaultCurrValue = _T("Native_FaultCurrValue");
	g_sLangTxt_Native_FaultCurrValue = _T("故障电流");
	g_sLangID_Native_FaultTrigMethod = _T("Native_FaultTrigMethod");
	g_sLangTxt_Native_FaultTrigMethod = _T("故障触发方式");
	g_sLangID_Native_FaultVoltDef = _T("Native_FaultVoltDef");
	g_sLangTxt_Native_FaultVoltDef = _T("故障电压定义");
	g_sLangID_Native_FileName = _T("Native_FileName");
	g_sLangTxt_Native_FileName = _T("文件名称");
	g_sLangID_Native_FlipMoment = _T("Native_FlipMoment");
	g_sLangTxt_Native_FlipMoment = _T("翻转时刻");
	g_sLangID_Native_FrameDrop = _T("Native_FrameDrop");
	g_sLangTxt_Native_FrameDrop = _T("丢帧测试");
	g_sLangID_Native_FlyDot = _T("Native_FlyDot");
	g_sLangTxt_Native_FlyDot = _T("飞点测试");
	g_sLangID_Native_FreqSetActValue = _T("Native_FreqSetActValue");
	g_sLangTxt_Native_FreqSetActValue = _T("频率整定动作值");
	g_sLangID_Native_fundamentalFreq = _T("Native_fundamentalFreq");
	g_sLangTxt_Native_fundamentalFreq = _T("基波频率");
	g_sLangID_Native_YNInputStop = _T("Native_YNInputStop");
	g_sLangTxt_Native_YNInputStop = _T("是否开入停止");
	g_sLangID_Native_fundamentalAmp = _T("Native_fundamentalAmp");
	g_sLangTxt_Native_fundamentalAmp = _T("基波幅值");
	g_sLangID_Native_fundamentalPhase = _T("Native_fundamentalPhase");
	g_sLangTxt_Native_fundamentalPhase = _T("基波相位");
	g_sLangID_Native_PreFautTime = _T("Native_PreFautTime");
	g_sLangTxt_Native_PreFautTime = _T("故障前时间");
	g_sLangID_Native_ProjName = _T("Native_ProjName");
	g_sLangTxt_Native_ProjName = _T("项目名称");
	g_sLangID_Native_QltyExcp = _T("Native_QltyExcp");
	g_sLangTxt_Native_QltyExcp = _T("品质异常");
	g_sLangID_Native_GOOSEOrigMsg = _T("Native_GOOSEOrigMsg");
	g_sLangTxt_Native_GOOSEOrigMsg = _T("GOOSE原始报文");
	g_sLangID_Native_quote = _T("Native_quote");
	g_sLangTxt_Native_quote = _T("引用");
	g_sLangID_Native_RatioBrakeCoefficient = _T("Native_RatioBrakeCoefficient");
	g_sLangTxt_Native_RatioBrakeCoefficient = _T("比率制动系数");
	g_sLangID_Native_receive = _T("Native_receive");
	g_sLangTxt_Native_receive = _T("接收");
	g_sLangID_Native_ReturnTime = _T("Native_ReturnTime");
	g_sLangTxt_Native_ReturnTime = _T("返回时间");
	g_sLangID_Native_ReturnValue = _T("Native_ReturnValue");
	g_sLangTxt_Native_ReturnValue = _T("返回值");
	g_sLangID_Native_SampDelay = _T("Native_SampDelay");
	g_sLangTxt_Native_SampDelay = _T("采样延时");
	g_sLangID_Native_SamplingFrequency = _T("Native_SamplingFrequency");
	g_sLangTxt_Native_SamplingFrequency = _T("采样率");
	g_sLangID_Native_saveFailed = _T("Native_saveFailed");
	g_sLangTxt_Native_saveFailed = _T("保存失败！\n");
	g_sLangID_Native_SeqDev = _T("Native_SeqDev");
	g_sLangTxt_Native_SeqDev = _T("序号偏差");
	g_sLangID_Native_GPSTriggerHour = _T("Native_GPSTrHour");
	g_sLangTxt_Native_GPSTriggerHour = _T("GPS触发时刻（时）");
	g_sLangID_Native_GPSTriggerMinute = _T("Native_GPSTrMinute");
	g_sLangTxt_Native_GPSTriggerMinute = _T("GPS触发时刻（分）");
	g_sLangID_Native_GPSTriggerSecond = _T("Native_GPSTrSecond");
	g_sLangTxt_Native_GPSTriggerSecond = _T("GPS触发时刻（秒）");
	g_sLangID_Native_GradualTimeScale = _T("Native_GradTimeScale");
	g_sLangTxt_Native_GradualTimeScale = _T("递变时间分度(ms)");
	g_sLangID_Native_SetActVolt = _T("Native_SetActVolt");
	g_sLangTxt_Native_SetActVolt = _T("整定动作电压");
	g_sLangID_Native_SetPickCurr = _T("Native_SetPickCurr");
	g_sLangTxt_Native_SetPickCurr = _T("整定动作电流");
	g_sLangID_Native_ShiftCount = _T("Native_ShiftCount");
	g_sLangTxt_Native_ShiftCount = _T("变位次数");
	g_sLangID_Native_ShortCircuitV = _T("Native_ShortCircuitV");
	g_sLangTxt_Native_ShortCircuitV = _T("短路电压");
	g_sLangID_Native_GroundDisSetI = _T("Native_GroundDisSetI");
	g_sLangTxt_Native_GroundDisSetI = _T("接地距离I段定值");
	g_sLangID_Native_GroundDisSetII = _T("Native_GroundDisSetII");
	g_sLangTxt_Native_GroundDisSetII = _T("接地距离II段定值");
	g_sLangID_Native_GroundDisSetIII = _T("Native_GroundDisSetIII");
	g_sLangTxt_Native_GroundDisSetIII = _T("接地距离III段定值");
	g_sLangID_Native_GroundDisSetIV = _T("Native_GroundDisSetIV");
	g_sLangTxt_Native_GroundDisSetIV = _T("接地距离IV段定值");
	g_sLangID_Native_ShortZImp = _T("Native_ShortZImp");
	g_sLangTxt_Native_ShortZImp = _T("短路阻抗");
	g_sLangID_Native_ShortZImpAng = _T("Native_ShortZImpAng");
	g_sLangTxt_Native_ShortZImpAng = _T("短路阻抗角");
	g_sLangID_Native_smvReceive = _T("Native_smvReceive");
	g_sLangTxt_Native_smvReceive = _T("SMV 接收");
	g_sLangID_Native_SndFreq = _T("Native_SndFreq");
	g_sLangTxt_Native_SndFreq = _T("发送周波数");
	g_sLangID_Native_SndFreqPS = _T("Native_SndFreqPS");
	g_sLangTxt_Native_SndFreqPS = _T("每秒发送周波数");
	g_sLangID_Native_SndTimeS = _T("Native_SndTimeS");
	g_sLangTxt_Native_SndTimeS = _T("发送时间(s)");
	g_sLangID_Native_SrcMAC = _T("Native_SrcMAC");
	g_sLangTxt_Native_SrcMAC = _T("源MAC");
	g_sLangID_Native_StateD = _T("Native_StateD");
	g_sLangTxt_Native_StateD = _T("状态%d");
	g_sLangID_Native_subscriptionIndex = _T("Native_subscriptionIndex");
	g_sLangTxt_Native_subscriptionIndex = _T("订阅索引");
	g_sLangID_Native_subscriptionReference = _T("Native_subscriptionReference");
	g_sLangTxt_Native_subscriptionReference = _T("订阅引用");
	g_sLangID_Native_subscriptionDescription = _T("Native_subscriptionDescription");
	g_sLangTxt_Native_subscriptionDescription = _T("订阅描述");
	g_sLangID_Native_SVOrigMsg = _T("Native_SVOrigMsg");
	g_sLangTxt_Native_SVOrigMsg = _T("SV原始报文");
	g_sLangID_Native_SwitchVal = _T("Native_SwitchVal");
	g_sLangTxt_Native_SwitchVal = _T("开关量");
	g_sLangID_Native_test_process = _T("Native_test_process");
	g_sLangTxt_Native_test_process = _T("试验过程:");
	g_sLangID_Native_TestPrecision = _T("Native_TestPrecision");
	g_sLangTxt_Native_TestPrecision = _T("测试精度");
	g_sLangID_Native_TransConnForm = _T("Native_TransConnForm");
	g_sLangTxt_Native_TransConnForm = _T("变压器接线形式");
	g_sLangID_Native_TransientFault = _T("Native_TransientFault");
	g_sLangTxt_Native_TransientFault = _T("是否转换性故障");
	g_sLangID_Native_TrigHoldTime = _T("Native_TrigHoldTime");
	g_sLangTxt_Native_TrigHoldTime = _T("触发后保持时间");
	g_sLangID_Native_TrigMode = _T("Native_TrigMode");
	g_sLangTxt_Native_TrigMode = _T("触发方式");
	g_sLangID_Native_ValidBit = _T("Native_ValidBit");
	g_sLangTxt_Native_ValidBit = _T("有效[bit0-1]");
	g_sLangID_Native_VolSetActValue = _T("Native_VolSetActValue");
	g_sLangTxt_Native_VolSetActValue = _T("电压整定动作值");
	g_sLangID_Native_vTerminalConnectDia = _T("Native_vTerminalConnectDia");
	g_sLangTxt_Native_vTerminalConnectDia = _T("虚端子连接图");
	g_sLangID_Out1_Situation = _T("Out1_Situation");
	g_sLangTxt_Out1_Situation = _T("开出1状态");
	g_sLangID_Out2_Situation = _T("Out2_Situation");
	g_sLangTxt_Out2_Situation = _T("开出2状态");
	g_sLangID_Out3_Situation = _T("Out3_Situation");
	g_sLangTxt_Out3_Situation = _T("开出3状态");
	g_sLangID_without = _T("without");
	g_sLangTxt_without = _T("无");
	g_sLangID_Native_VoltSlip = _T("Native_VoltSlip");
	g_sLangTxt_Native_VoltSlip = _T("电压滑差");
	g_sLangID_Native_superimpose_ornot = _T("Native_superimposed_ornot");
	g_sLangTxt_Native_superimpose_ornot = _T("是否叠加非周期分量:");
	g_sLangID_Native_ShortCircuitVs = _T("Native_ShortCircuitVs");
	g_sLangTxt_Native_ShortCircuitVs = _T("短路电压(V):");

	g_sLangID_Native_FinalVoltChange = _T("Native_FinalVoltChange");
	g_sLangTxt_Native_FinalVoltChange = _T("电压变化终值");

	g_sLangID_Allow_FreqDifference = _T("Allow_FreqDifference");
	g_sLangTxt_Allow_FreqDifference = _T("允许频差");
	g_sLangID_LeadingAngle = _T("LeadingAngle");
	g_sLangTxt_LeadingAngle = _T("导前角");

	g_sLangID_LeadingTime = _T("LeadingTime");
	g_sLangTxt_LeadingTime = _T("导前时间");
	g_sLangID_Allow_VolDifference = _T("Allow_VolDifference");
	g_sLangTxt_Allow_VolDifference = _T("允许压差");
	g_sLangTxt_Vol_ReguPeriod = _T("调压周期");
	g_sLangID_Freq_ReguPeriod = _T("Freq_ReguPeriod");
	g_sLangTxt_Freq_ReguPeriod = _T("调频周期");
	g_sLangID_System_Rated_Voltage = _T("System_Rated_Voltage");
	g_sLangTxt_System_Rated_Voltage = _T("系统侧额定电压");
	g_sLangID_System_Rated_Frequency = _T("System_Rated_Frequency");
	g_sLangTxt_System_Rated_Frequency = _T("系统侧额定频率");
	g_sLangID_Grid_Rated_Voltage = _T("Grid_Rated_Voltage");
	g_sLangTxt_Grid_Rated_Voltage = _T("待并侧额定电压");
	g_sLangID_Freq_BoundValue = _T("Freq_BoundValue");
	g_sLangTxt_Freq_BoundValue = _T("频率边界值");
	g_sLangID_FreqDif = _T("FreqDif");
	g_sLangTxt_FreqDif = _T("频差");

	g_sLangID_Grid_FreqHZ = _T("Grid_FreqHZ");
	g_sLangTxt_Grid_FreqHZ = _T("待并侧频率（HZ）");
	g_sLangID_Native_InitVoltChange = _T("Native_InitVoltChange");
	g_sLangTxt_Native_InitVoltChange = _T("电压变化始值");
	g_sLangID_Native_LowVLockVal = _T("Native_LowVLockVal");
	g_sLangTxt_Native_LowVLockVal = _T("低压闭锁值");
	g_sLangID_Native_maxSyncTime = _T("Native_maxSyncTime");
	g_sLangTxt_Native_maxSyncTime = _T("最大同步时间:");
	g_sLangID_Native_LowVoltUnderloadTripSet = _T("Native_LowVoltUnderloadTripSet");
	g_sLangTxt_Native_LowVoltUnderloadTripSet = _T("低压减载动作值");
	g_sLangID_Native_VoltChangeStep = _T("Native_VoltChangeStep");
	g_sLangTxt_Native_VoltChangeStep = _T("电压变化步长");

	g_sLangID_Out4_Mode = _T("Out4_Mode");
	g_sLangTxt_Out4_Mode = _T("开出4输出方式");
	g_sLangID_Vol_BoundValue = _T("Vol_BoundValue");
	g_sLangTxt_Vol_BoundValue = _T("电压边界值");
	g_sLangID_Native_LockVoltDef = _T("Native_LockVoltDef");
	g_sLangTxt_Native_LockVoltDef = _T("闭锁电压定义");

	g_sLangID_Native_VoltSlipAct = _T("Native_VoltSlipAct");
	g_sLangTxt_Native_VoltSlipAct = _T("电压滑差动作值");
	g_sLangID_Native_LVLRActionVal = _T("Native_LVLRActionVal");
	g_sLangTxt_Native_LVLRActionVal = _T("低压减载动作值");
	g_sLangID_Native_LowVRateLock = _T("Native_LowVRateLock");
	g_sLangTxt_Native_LowVRateLock = _T("低压变化率闭锁值");
	g_sLangID_VolDif = _T("VolDif");
	g_sLangTxt_VolDif = _T("压差");
	g_sLangID_Native_FaultProp = _T("Native_FaultProp");
	g_sLangTxt_Native_FaultProp = _T("故障性质:");
	g_sLangID_Native_AngleDiffClockHrsTestWindings = _T("Native_AngleDiffClockHrsTestWindings");
	g_sLangTxt_Native_AngleDiffClockHrsTestWindings = _T("测试绕组之间角差(钟点数)");
	g_sLangID_Native_ControlCurrent = _T("Native_ControlCurrent");
	g_sLangTxt_Native_ControlCurrent = _T("制动电流");
	g_sLangID_Native_StartSegSlope = _T("Native_StartSegSlope");
	g_sLangTxt_Native_StartSegSlope = _T("启动段斜率");
	g_sLangID_Native_FundRatioBrkSlope1 = _T("Native_FundRatioBrkSlope1");
	g_sLangTxt_Native_FundRatioBrkSlope1 = _T("基波比率制动特性斜率1");
	g_sLangID_Native_FundRatioBrkSlope2 = _T("Native_FundRatioBrkSlope2");
	g_sLangTxt_Native_FundRatioBrkSlope2 = _T("基波比率制动特性斜率2");
	g_sLangID_Native_FundRatioBrkSlope3 = _T("Native_FundRatioBrkSlope3");
	g_sLangTxt_Native_FundRatioBrkSlope3 = _T("基波比率制动特性斜率3");
	g_sLangID_Native_SecHarBrkCoef = _T("Native_SecHarBrkCoef");
	g_sLangTxt_Native_SecHarBrkCoef = _T("二次谐波制动系数");
	g_sLangID_Native_ThiHarBrkCoef = _T("Native_ThiHarBrkCoef");
	g_sLangTxt_Native_ThiHarBrkCoef = _T("三次谐波制动系数");
	g_sLangID_Native_FivHarBrkCoef = _T("Native_FivHarBrkCoef");
	g_sLangTxt_Native_FivHarBrkCoef = _T("五次谐波制动系数");
	g_sLangID_Native_SearchMeth = _T("Native_SearchMeth");
	g_sLangTxt_Native_SearchMeth = _T("搜索方法");
	g_sLangID_Native_HighVoltSideRatedVolt = _T("Native_HighVoltSideRatedVolt");
	g_sLangTxt_Native_HighVoltSideRatedVolt = _T("高压侧额定电压");
	g_sLangID_Native_MedVoltSideRatedVolt = _T("Native_MedVoltSideRatedVolt");
	g_sLangTxt_Native_MedVoltSideRatedVolt = _T("中压侧额定电压");
	g_sLangID_Native_MedVoltWindingConnType = _T("Native_MedVoltWindingConnType");
	g_sLangTxt_Native_MedVoltWindingConnType = _T("中压侧绕组接线型式");
	g_sLangID_Native_LowVoltSideRatedVolt = _T("Native_LowVoltSideRatedVolt");
	g_sLangTxt_Native_LowVoltSideRatedVolt = _T("低压侧额定电压");
	g_sLangID_Native_HVSideCTPrimVal = _T("Native_HVSideCTPrimVal");
	g_sLangTxt_Native_HVSideCTPrimVal = _T("高压侧CT一次值");
	g_sLangID_Native_HVSide2CTPrimVal = _T("Native_HVSide2CTPrimVal");
	g_sLangTxt_Native_HVSide2CTPrimVal = _T("高压侧CT二次值");

	g_sLangID_Native_MVSideCTPrimVal = _T("Native_MVSideCTPrimVal");
	g_sLangTxt_Native_MVSideCTPrimVal = _T("中压侧CT一次值");
	g_sLangID_Native_MVSide2CTPrimVal = _T("Native_MVSide2CTPrimVal");
	g_sLangTxt_Native_MVSide2CTPrimVal = _T("中压侧CT二次值");

	g_sLangID_Native_LVSideCTPrimVal = _T("Native_LVSideCTPrimVal");
	g_sLangTxt_Native_LVSideCTPrimVal = _T("低压侧CT一次值");
	g_sLangID_Native_LVSide2CTPrimVal = _T("Native_LVSide2CTPrimVal");
	g_sLangTxt_Native_LVSide2CTPrimVal = _T("低压侧CT二次值");


	g_sLangID_Native_RefCurrentSel = _T("Native_RefCurrentSel");
	g_sLangTxt_Native_RefCurrentSel = _T("基准电流选择");
	g_sLangID_Native_ProportionalBrakingFactor = _T("Native_ProportionalBrakingFactor");
	g_sLangTxt_Native_ProportionalBrakingFactor = _T("比例制动系数");
	g_sLangID_Native_TransfRatedCapacity = _T("Native_TransfRatedCapacity");
	g_sLangTxt_Native_TransfRatedCapacity = _T("变压器额定容量");
	g_sLangID_lowfreqloadre_ActTime = _T("lowfreqloadre_ActTime");
	g_sLangTxt_lowfreqloadre_ActTime = _T("低周减载动作时间");


	g_sLangID_Native_VoltChangeAmt = _T("Native_VoltChangeAmt");
	g_sLangTxt_Native_VoltChangeAmt = _T("电压变化量");
	g_sLangID_Native_sliptripValue = _T("Native_sliptripValue");
	g_sLangTxt_Native_sliptripValue = _T("滑差闭锁值");
	g_sLangID_interlock_vol = _T("interlock_vol");
	g_sLangTxt_interlock_vol = _T("闭锁电压");
	g_sLangID_interlock_cur = _T("interlock_cur");
	g_sLangTxt_interlock_cur = _T("闭锁电流");
	g_sLangID_Native_OscilCount = _T("Native_OscilCount");
	g_sLangTxt_Native_OscilCount = _T("振荡次数");
	g_sLangID_Native_PreOscTime = _T("Native_PreOscTime");
	g_sLangTxt_Native_PreOscTime = _T("振荡前时间");
	g_sLangID_Native_SysImp = _T("Native_SysImp");
	g_sLangTxt_Native_SysImp = _T("系统侧阻抗");
	g_sLangID_Native_TransImp = _T("Native_TransImp");
	g_sLangTxt_Native_TransImp = _T("变压器阻抗");
	g_sLangID_Native_AccelSignalCont = _T("Native_AccelSignalCont");
	g_sLangTxt_Native_AccelSignalCont = _T("加速信号接点");
	g_sLangID_Native_DecelSignalCont = _T("Native_DecelSignalCont");
	g_sLangTxt_Native_DecelSignalCont = _T("减速信号接点");
	g_sLangID_Native_ActDirection = _T("Native_ActDirection");
	g_sLangTxt_Native_ActDirection = _T("动作方向");
	g_sLangID_Native_LowVoltageDef = _T("Native_LowVoltageDef");
	g_sLangTxt_Native_LowVoltageDef = _T("低电压定义");
	g_sLangID_Native_AngDef = _T("Native_AngDef");
	g_sLangTxt_Native_AngDef = _T("角度定义");
	g_sLangID_Native_ConnMethod = _T("Native_ConnMethod");
	g_sLangTxt_Native_ConnMethod = _T("接线方式");
	g_sLangID_Native_LeadAngle = _T("Native_LeadAngle");
	g_sLangTxt_Native_LeadAngle = _T("超前角度");
	g_sLangID_Native_LagAngle = _T("Native_LagAngle");
	g_sLangTxt_Native_LagAngle = _T("滞后角度");
	g_sLangID_Native_FreqChgZSetting = _T("Native_FreqChgZSetting");
	g_sLangTxt_Native_FreqChgZSetting = _T("工频变化量阻抗定值");
	g_sLangID_Native_CalcCoef = _T("Native_CalcCoef");
	g_sLangTxt_Native_CalcCoef = _T("计算系数");
	g_sLangID_Native_PosSeqSensAng = _T("Native_PosSeqSensAng");
	g_sLangTxt_Native_PosSeqSensAng = _T("正序灵敏角");
	g_sLangID_Native_GndDistOffset = _T("Native_GndDistOffset");
	g_sLangTxt_Native_GndDistOffset = _T("接地距离偏移角");
	g_sLangID_Native_PhaseDistOffset = _T("Native_PhaseDistOffset");
	g_sLangTxt_Native_PhaseDistOffset = _T("相间距离偏移角");
	g_sLangID_Native_BalCoeff = _T("Native_BalCoeff");
	g_sLangTxt_Native_BalCoeff = _T("平衡系数");
	g_sLangID_Native_2HarBrkCoef = _T("Native_2HarBrkCoef");
	g_sLangTxt_Native_2HarBrkCoef = _T("2次谐波制动系数");
	g_sLangID_Native_3HarBrkCoef = _T("Native_3HarBrkCoef");
	g_sLangTxt_Native_3HarBrkCoef = _T("3次谐波制动系数");
	g_sLangID_Native_5HarBrkCoef = _T("Native_5HarBrkCoef");
	g_sLangTxt_Native_5HarBrkCoef = _T("5次谐波制动系数");

	g_sLangID_Native_ConnectFail       = _T("Native_ConnectFail");
	g_sLangTxt_Native_ConnectFail      = _T("与当前测试仪建立连接失败(%s).");

	g_sLangID_Native_TestrDisconn = _T("Native_TestrDisconn");
	g_sLangTxt_Native_TestrDisconn = _T("测试仪连接中断，请先与测试仪建立连接。");
	g_sLangID_Native_UnBatteryInfor    = _T("Native_UnBatteryInfor");
	g_sLangTxt_Native_UnBatteryInfor   = _T("电池电量信息获取异常.");

	g_sLangID_Native_LoadingMacroTest = _T("Native_LoadingMacroTest");
	g_sLangTxt_Native_LoadingMacroTest = _T("正在加载测试功能界面，请稍侯...");
	g_sLangID_Native_LoadingBar = _T("Native_LoadingBar");
	g_sLangTxt_Native_LoadingBar = _T("功能加载进度条");

	g_sLangID_remotemeas                          =_T("remotemeas");
	g_sLangTxt_remotemeas                         =_T("遥测");
	g_sLangID_Internal = _T("RemoteCtrl_Internal");
	g_sLangTxt_Internal = _T("间隔");
	g_sLangID_Operation = _T("RemoteCtrl_Operation");
	g_sLangTxt_Operation = _T("操作");
	g_sLangID_Record = _T("RemoteCtrl_Record");
	g_sLangTxt_Record = _T("记录");
	g_sLangID_EventType = _T("RemoteCtrl_EventType");
	g_sLangTxt_EventType = _T("事件类型");
	g_sLangID_DeviceTime = _T("RemoteCtrl_DeviceTime");
	g_sLangTxt_DeviceTime = _T("装置时间");
	g_sLangID_PCTime = _T("RemoteCtrl_PCTime");
	g_sLangTxt_PCTime = _T("PC时间");
	g_sLangID_Native_TempSaveSucc = _T("Native_TempSaveSucc");
	g_sLangTxt_Native_TempSaveSucc = _T("模板保存成功");
	g_sLangID_Native_TempSaveFail = _T("Native_TempSaveFail");
	g_sLangTxt_Native_TempSaveFail = _T("模板保存失败");
	g_sLangID_Native_Success = _T("Native_Success");
	g_sLangTxt_Native_Success = _T("成功");
	g_sLangID_Native_Timeout = _T("Native_Timeout");
	g_sLangTxt_Native_Timeout = _T("超时");
	g_sLangID_Native_Fail = _T("Native_Fail");
	g_sLangTxt_Native_Fail = _T("失败");
	g_sLangID_Native_TempSave = _T("Native_TempSave");
	g_sLangTxt_Native_TempSave = _T("模板保存%s.");
	g_sLangID_Native_ExportWordReport = _T("Native_ExportWordReport");
	g_sLangTxt_Native_ExportWordReport = _T("导出Word报告%s.");
	g_sLangID_Native_ReportSave = _T("Native_ReportSave");
	g_sLangTxt_Native_ReportSave = _T("报告保存%s.");

	g_sLangID_Impedance_CalMode = _T("Impedance_CalMode");
	g_sLangTxt_Impedance_CalMode = _T("测试模型");
	g_sLangID_Impedance_Choose = _T("Impedance_Choose");
	g_sLangTxt_Impedance_Choose = _T("阻抗输入选择");
	g_sLangID_Impedance_ShortCurr = _T("Impedance_ShortCurr");
	g_sLangTxt_Impedance_ShortCurr = _T("短路电流(A)");
	g_sLangID_Impedance_Delayed = _T("Impedance_Delayed");
	g_sLangTxt_Impedance_Delayed = _T("触发后延时（s）");
	g_sLangID_Impedance_VarChoose = _T("Impedance_VarChoose");
	g_sLangTxt_Impedance_VarChoose = _T("变量选择");
	g_sLangID_Impedance_Mode = _T("Impedance_Mode");
	g_sLangTxt_Impedance_Mode = _T("模式");
	g_sLangID_Impedance_Time = _T("Impedance_Time");
	g_sLangTxt_Impedance_Time = _T("变化时间（s）");
	g_sLangID_Impedance_ChangeType = _T("Impedance_ChangeType");
	g_sLangTxt_Impedance_ChangeType = _T("变化方式");
	g_sLangID_Impedance_Auto = _T("Impedance_Auto");
	g_sLangTxt_Impedance_Auto = _T("自动递变");
	g_sLangID_Impedance_Mutation = _T("Impedance_Mutation");
	g_sLangTxt_Impedance_Mutation = _T("突变量启动");

 	g_sLangID_ExpSucc = _T("ExpSucc");                                                //sun
 	g_sLangTxt_ExpSucc = _T("导出成功");                                               //sun
 	g_sLangID_ExpFail = _T("ExpFail");                                                //sun
 	g_sLangTxt_ExpFail = _T("导出失败");                                               //sun
 	g_sLangID_ImpSucc = _T("ImpSucc");                                                //sun
 	g_sLangTxt_ImpSucc = _T("导入成功");                                               //sun
 	g_sLangID_ImpFail = _T("ImpFail");                                                //sun
 	g_sLangTxt_ImpFail = _T("导入失败");                                               //sun
																					  //sun
 	g_sLangID_RemainingMemorySize = _T("RemainingMemorySize");                        //sun
 	g_sLangTxt_RemainingMemorySize = _T("当前系统剩余内存大小%lu B.");                   //sun
 	g_sLangID_InsufficientSystemMemory = _T("InsufficientSystemMemory");              //sun
 	g_sLangTxt_InsufficientSystemMemory = _T("当前系统剩余内存不足");                    //sun
 	g_sLangID_ExistenceSCDFiles = _T("ExistenceSCDFiles");                            //sun
 	g_sLangTxt_ExistenceSCDFiles = _T("当前存在同名SCD文件，是否继续？");                  //sun
 	g_sLangID_NoExistenceSCLFiles = _T("NoExistenceSCLFiles");                        //sun
 	g_sLangTxt_NoExistenceSCLFiles = _T("当前文件(%s)没有扩展名不是SCL文件.");            //sun
																					  //sun
 	g_sLangID_AnalysisSCLFiles = _T("AnalysisSCLFiles");                              //sun
 	g_sLangTxt_AnalysisSCLFiles = _T("SCL解析");                                       //sun
 	g_sLangID_LoadSCLFiles = _T("LoadSCLFiles");                                      //sun
 	g_sLangTxt_LoadSCLFiles = _T("正在加载SCL文件...");                                 //sun
 	g_sLangID_LoadSCLFilesProgressBar = _T("LoadSCLFilesProgressBar");                //sun
 	g_sLangTxt_LoadSCLFilesProgressBar = _T("SCL加载进度条");                           //sun
																					  //sun
 	g_sLangID_SaveSCLFiles = _T("SaveSCLFiles");                                      //sun
 	g_sLangTxt_SaveSCLFiles = _T("正在保存SCL配置...");                                 //sun

	g_sLangID_Impedance_FunParas =_T("Impedance_FunParas");
	g_sLangTxt_Impedance_FunParas =_T("功能参数");
	g_sLangID_Impedance_Variable =_T("Impedance_Variable");
	g_sLangTxt_Impedance_Variable =_T("递变");
	g_sLangID_Impedance_ChangeStart =_T("Impedance_ChangeStart");
	g_sLangTxt_Impedance_ChangeStart =_T("变化始值(Ω)");
	g_sLangID_Impedance_ChangeEnd =_T("Impedance_ChangeEnd");
	g_sLangTxt_Impedance_ChangeEnd =_T("变化终值(Ω)");
	g_sLangID_Impedance_ChangStep =_T("Impedance_ChangStep");
	g_sLangTxt_Impedance_ChangStep =_T("变化步长(Ω)");
	g_sLangID_Impedance_NormalTime =_T("Impedance_NormalTime");
	g_sLangTxt_Impedance_NormalTime =_T("常态时间(s)");
	g_sLangID_Impedance_FailTime =_T("Impedance_FailTime");
	g_sLangTxt_Impedance_FailTime =_T("故障前时间(s)");
	g_sLangID_Impedance_ConstantCur =_T("Impedance_ConstantCur");
	g_sLangTxt_Impedance_ConstantCur =_T("定电流");
	g_sLangID_Impedance_ConstantVol=_T("Impedance_ConstantVol");
	g_sLangTxt_Impedance_ConstantVol =_T("定电压");
	g_sLangID_Impedance_FixedSystem =_T("Impedance_FixedSystem");
	g_sLangTxt_Impedance_FixedSystem =_T("固定系统侧阻抗");


	g_sLangID_Gradient_FailModes =_T("Gradient_FailModes");
	g_sLangTxt_Gradient_FailModes =_T("故障模式");
	g_sLangID_Gradient_Change =_T("Gradient_Change");
    g_sLangTxt_Gradient_Change =_T("变化量");
	g_sLangID_Gradient_ImpAngle =_T("Gradient_ImpAngle");
	g_sLangTxt_Gradient_ImpAngle =_T("阻抗角(°):");
	g_sLangID_Gradient_ChangeTime =_T("Gradient_ChangeTime");
	g_sLangTxt_Gradient_ChangeTime =_T("变化前时间(s):");
    g_sLangID_Gradient_FailBeforeTime =_T("Gradient_FailBeforeTime");
	g_sLangTxt_Gradient_FailBeforeTime =_T("故障前时间(s):");
	g_sLangID_Gradient_FailVol =_T("Gradient_FailVol");
	g_sLangTxt_Gradient_FailVol =_T("故障前电压(V):");
	g_sLangID_Gradient_FailCur =_T("Gradient_FailCur");
	g_sLangTxt_Gradient_FailCur =_T("故障前电流(A):");
	g_sLangID_Gradient_FailAngle =_T("Gradient_FailAngle");
	g_sLangTxt_Gradient_FailAngle =_T("故障前相角(°):");
	g_sLangID_Gradient_RampParas =_T("Gradient_RampParas");
	g_sLangTxt_Gradient_RampParas =_T("递变参数设置");
	//g_sLangID_Gradient_VarSet =_T("Gradient_VarSet");
	//g_sLangTxt_Gradient_VarSet =_T("变量设置");
	g_sLangID_Gradient_CommonParas =_T("Gradient_CommonParas");
	g_sLangTxt_Gradient_CommonParas =_T("通用参数");
	g_sLangID_Gradient_BinBout =_T("Gradient_BinBout");
	g_sLangTxt_Gradient_BinBout =_T("开入量");
	g_sLangID_Gradient_BoutNormal =_T("Gradient_BoutNormal");
	g_sLangTxt_Gradient_BoutNormal =_T("开出量正常态");
	g_sLangID_Gradient_BoutFaultState =_T("Gradient_BoutFaultState");
	g_sLangTxt_Gradient_BoutFaultState =_T("开出量故障态");


	g_sLangID_Gradient_Test1	=_T("Gradient_Test1");
	g_sLangTxt_Gradient_Test1	=_T("测试1");
	g_sLangID_Gradient_Test2 =_T("Gradient_Test2");
	g_sLangTxt_Gradient_Test2 =_T("测试2");
	g_sLangID_Gradient_Test3	=_T("Gradient_Test3");
	g_sLangTxt_Gradient_Test3	=_T("测试3");
	g_sLangID_Native_PhaseABshort	=_T("Native_PhaseABshort");
	g_sLangTxt_Native_PhaseABshort	=_T("AB相短路");
	g_sLangID_Native_PhaseBCshort	=_T("Native_PhaseBCshort");
	g_sLangTxt_Native_PhaseBCshort=_T("BC相短路");
	g_sLangID_Native_PhaseCAshort=_T("Native_PhaseCAshort");
	g_sLangTxt_Native_PhaseCAshort=_T("CA相短路");
	g_sLangID_Native_PhaseABshortCcur	=_T("Native_PhaseABshortCcur");
	g_sLangTxt_Native_PhaseABshortCcur	=_T("AB相短路，C相电流");
	g_sLangID_Native_PhaseBCshortAcur	=_T("Native_PhaseBCshortAcur");
	g_sLangTxt_Native_PhaseBCshortAcur	=_T("BC相短路，A相电流");
	g_sLangID_Native_PhaseCAshortBcur	=_T("Native_PhaseCAshortBcur");
	g_sLangTxt_Native_PhaseCAshortBcur	=_T("CA相短路，B相电流");
	g_sLangID_Native_PhaseABshortBcur	=_T("Native_PhaseABshortBcur");
	g_sLangTxt_Native_PhaseABshortBcur	=_T("AB相短路，B相电流");
	g_sLangID_Native_PhaseBCshortCcur	=_T("Native_PhaseBCshortCcur");
	g_sLangTxt_Native_PhaseBCshortCcur	=_T("BC相短路，C相电流");
	g_sLangID_Native_PhaseCAshortAcur	=_T("Native_PhaseCAshortAcur");
	g_sLangTxt_Native_PhaseCAshortAcur	=_T("CA相短路，A相电流");
	g_sLangID_Native_PosVol	=_T("Native_PosVol");
	g_sLangTxt_Native_PosVol	=_T("正序电压");
	g_sLangID_Native_NegVol	=_T("Native_NegVol");
	g_sLangTxt_Native_NegVol	=_T("负序电压");
	g_sLangID_Native_ZeroVol3U0	=_T("Native_ZeroVol3U0");
	g_sLangTxt_Native_ZeroVol3U0	=_T("零序电压（3U0）");
	g_sLangID_Native_PosVolU1	=_T("Native_PosVolU1");
	g_sLangTxt_Native_PosVolU1	=_T("正序(U1)");
	g_sLangID_Native_NegVolU2	=_T("Native_NegVolU2");
	g_sLangTxt_Native_NegVolU2	=_T("负序(U2)");
	g_sLangID_Native_Zero3U0 =_T("Native_Zero3U0");
	g_sLangTxt_Native_Zero3U0 =_T("零序(3U0)");

	g_sLangID_CBOperate_TimeAfterTrigger=_T("CBOperate_TimeAfterTrigger");
	g_sLangTxt_CBOperate_TimeAfterTrigger=_T("保护动作后持续时间(s)");
	g_sLangID_CBOperate_PTVPos=_T("CBOperate_PTVPos");
	g_sLangTxt_CBOperate_PTVPos=_T("TV安装位置");
	g_sLangID_CBOperate_CTPos=_T("g_sLangID_CBOperate_CTPos");
	g_sLangTxt_CBOperate_CTPos=_T("TA正极性");
	g_sLangID_CBOperate_AfterOpenTime=_T("CBOperate_AfterOpenTime");
	g_sLangTxt_CBOperate_AfterOpenTime=_T("开关跳开后持续时间(s)");
	g_sLangID_CBOperate_RecloseTime=_T("CBOperate_RecloseTime");
	g_sLangTxt_CBOperate_RecloseTime=_T("重合持续时间(s)");
	g_sLangID_CBOperate_AfterAccTime=_T("CBOperate_AfterAccTime");
	g_sLangTxt_CBOperate_AfterAccTime=_T("后加速开关跳开后持续时间(s)");
	g_sLangID_CBOperate_PTPos=_T("CBOperate_PTPos");
	g_sLangTxt_CBOperate_PTPos=_T("母线侧");
	g_sLangID_CBOperate_TPos=_T("CBOperate_TPos");
	g_sLangTxt_CBOperate_TPos=_T("线路侧");
	g_sLangID_CBOperate_CTPos1=_T("CBOperate_CTPos1");
	g_sLangTxt_CBOperate_CTPos1=_T("指向母线");
	g_sLangID_CBOperate_TPos1=_T("CBOperate_TPos1");
	g_sLangTxt_CBOperate_TPos1=_T("指向线路");
	g_sLangID_CBOperate_Overall=_T("CBOperate_Overall");
	g_sLangTxt_CBOperate_Overall=_T("综重");
	g_sLangID_CBOperate_Zs=_T("CBOperate_Zs");
	g_sLangTxt_CBOperate_Zs=_T("系统阻抗(Ω)");
	g_sLangID_CBOperate_ZsPh=_T("CBOperate_ZsPh");
	g_sLangTxt_CBOperate_ZsPh=_T("系统阻抗角(°)");
	g_sLangID_CBOperate_SimulateBreakerDelay=_T("CBOperate_SimulateBreakerDelay");
	g_sLangTxt_CBOperate_SimulateBreakerDelay=_T("断路器模拟");
	g_sLangID_CBOperate_BrkBreakTime=_T("CBOperate_BrkBreakTime");
	g_sLangTxt_CBOperate_BrkBreakTime=_T("分闸时间(ms)");
	g_sLangID_CBOperate_BrkCloseTime=_T("CBOperate_BrkCloseTime");
	g_sLangTxt_CBOperate_BrkCloseTime=_T("合闸时间(ms)");
	g_sLangID_CBOperate_FaultIncMode=_T("CBOperate_FaultIncMode");
	g_sLangTxt_CBOperate_FaultIncMode=_T("合闸角选择");
	g_sLangID_CBOperate_FaultAngle=_T("CBOperate_FaultAngle");
	g_sLangTxt_CBOperate_FaultAngle=_T("合闸角(°)");
	g_sLangID_CBOperate_BIPlusDC=_T("CBOperate_BIPlusDC");
	g_sLangTxt_CBOperate_BIPlusDC=_T("叠加非周期分量");
	g_sLangID_CBOperate_VzDefine=_T("CBOperate_VzDefine");
	g_sLangTxt_CBOperate_VzDefine=_T("抽取电压输出定义");
	g_sLangID_CBOperate_PsuVzRefPhase=_T("CBOperate_PsuVzRefPhase");
	g_sLangTxt_CBOperate_PsuVzRefPhase=_T("抽取电压参考相定义");
	g_sLangID_CBOperate_VzPh=_T("CBOperate_VzPh");
	g_sLangTxt_CBOperate_VzPh=_T("抽取电压相角");
	g_sLangID_CBOperate_NotSimulated=_T("CBOperate_NotSimulated");
	g_sLangTxt_CBOperate_NotSimulated=_T("不模拟");
	g_sLangID_CBOperate_Random=_T("CBOperate_Random");
	g_sLangTxt_CBOperate_Random=_T("随机");
	g_sLangID_CBOperate_FixedValue=_T("CBOperate_FixedValue");
	g_sLangTxt_CBOperate_FixedValue=_T("定值");
	g_sLangID_CBOperate_UabPhase=_T("CBOperate_UabPhase");
	g_sLangTxt_CBOperate_UabPhase=_T("Uab相位");
	g_sLangID_CBOperate_UbcPhase=_T("CBOperate_UbcPhase");
	g_sLangTxt_CBOperate_UbcPhase=_T("Ubc相位");
	g_sLangID_CBOperate_UcaPhase=_T("CBOperate_UcaPhase");
	g_sLangTxt_CBOperate_UcaPhase=_T("Uca相位");
	g_sLangID_CBOperate_SingleHop=_T("CBOperate_SingleHop");
	g_sLangTxt_CBOperate_SingleHop=_T("单跳");
	g_sLangID_CBOperate_TripleJump=_T("CBOperate_TripleJump");
	g_sLangTxt_CBOperate_TripleJump=_T("三跳");
	g_sLangID_CBOperate_Reclose=_T("CBOperate_Reclose");
	g_sLangTxt_CBOperate_Reclose=_T("重合");
	g_sLangID_CBOperate_BinBoutSelect=_T("CBOperate_BinBoutSelect");
	g_sLangTxt_CBOperate_BinBoutSelect=_T("开入选择");
	g_sLangID_CBOperate_BinABCD=_T("CBOperate_BinABCD");
	g_sLangTxt_CBOperate_BinABCD=_T("开入A-B-C-D");
	g_sLangID_CBOperate_BinEFGH=_T("CBOperate_BinEFGH");
	g_sLangTxt_CBOperate_BinEFGH=_T("开入E-F-G-H");
	g_sLangID_CBOperate_OutputSwitchMode=_T("CBOperate_OutputSwitchMode");
	g_sLangTxt_CBOperate_OutputSwitchMode=_T("开出翻转启动方式");
	g_sLangID_CBOperate_OutputDelayTime=_T("CBOperate_OutputDelayTime");
	g_sLangTxt_CBOperate_OutputDelayTime=_T("开出翻转时刻");
	g_sLangID_CBOperate_StartTime=_T("CBOperate_StartTime");
	g_sLangTxt_CBOperate_StartTime=_T("时间启动");
	g_sLangID_CBOperate_BinStart=_T("CBOperate_BinStart");
	g_sLangTxt_CBOperate_BinStart=_T("开入量启动");
	g_sLangID_CBOperate_AbsOrRelative=_T("CBOperate_AbsOrRelative");
	g_sLangTxt_CBOperate_AbsOrRelative=_T("绝对or相对");
	g_sLangID_CBOperate_AbsRelative=_T("CBOperate_AbsRelative");
	g_sLangTxt_CBOperate_AbsRelative=_T("绝对&相对");
	g_sLangID_CBOperate_CombError=_T("CBOperate_CombError");
	g_sLangTxt_CBOperate_CombError=_T("组合误差");
	g_sLangID_CBOperate_Instan=_T("CBOperate_Instan");
	g_sLangTxt_CBOperate_Instan=_T("瞬时");
	g_sLangID_CBOperate_Perpetual=_T("CBOperate_Perpetual");
	g_sLangTxt_CBOperate_Perpetual=_T("永久");
	g_sLangID_CBOperate_MaxFaultTime=_T("CBOperate_MaxFaultTime");
	g_sLangTxt_CBOperate_MaxFaultTime=_T("最大故障时间(S)");
	g_sLangID_CBOperate_FaultMoment=_T("CBOperate_FaultMoment");
	g_sLangTxt_CBOperate_FaultMoment=_T("故障触发时刻");
	g_sLangID_CBOperate_Hour=_T("CBOperate_Hour");
	g_sLangTxt_CBOperate_Hour=_T("时");
	g_sLangID_CBOperate_Minute=_T("CBOperate_Minute");
	g_sLangTxt_CBOperate_Minute=_T("分");
	g_sLangID_CBOperate_Second=_T("CBOperate_Second");
	g_sLangTxt_CBOperate_Second=_T("秒");
	g_sLangID_CBOperate_ImpRepre=_T("CBOperate_ImpRepre");
	g_sLangTxt_CBOperate_ImpRepre=_T("阻抗表示方式：");
	g_sLangID_CBOperate_AmpPhase=_T("CBOperate_AmpPhase");
	g_sLangTxt_CBOperate_AmpPhase=_T("幅值相位");
	g_sLangID_CBOperate_ConversionTime=_T("CBOperate_ConversionTime");
	g_sLangTxt_CBOperate_ConversionTime=_T("转换时间(S)");
	g_sLangID_CBOperate_Reverse=_T("CBOperate_Reverse");
	g_sLangTxt_CBOperate_Reverse=_T("反向");
	g_sLangID_CBOperate_Positive=_T("CBOperate_Positive");
	g_sLangTxt_CBOperate_Positive=_T("正向");
	g_sLangID_CBOperate_ConversionFail=_T("CBOperate_ConversionFail");
	g_sLangTxt_CBOperate_ConversionFail=_T("转换性故障");

	g_sLangID_CurrentHigh330   =_T("CurrentHigh330");//高功率电流
	g_sLangTxt_CurrentHigh330 =_T("高功率电流");
	g_sLangID_Native_CommandTimeout = _T("CommandTimeout");
	g_sLangTxt_Native_CommandTimeout = _T("%s命令：超时");



}

CString g_sLangID_Native_LangSetting;  //= _T("Native_LangSetting");
CString g_sLangTxt_Native_LangSetting; //= _T("语言设置");
CString g_sLangID_Native_CustomSetup;  //_T("Native_CustomSetup");
CString g_sLangTxt_Native_CustomSetup;  //_T("自定义设置");
// CString g_sLangID_Native_LangTip                 ;//= _T("Native_LangTip");
// CString g_sLangTxt_Native_LangTip                ;//= _T("提示");
CString g_sLangID_Native_LangTipContext;  //= _T("Native_LangTipContext");
CString g_sLangTxt_Native_LangTipContext; //= _T("语言设置重启后生效");

CString g_sLangID_Native_Amplitude;	 //= _T("Native_Amplitude");
CString g_sLangTxt_Native_Amplitude; //= _T("幅值");
CString g_sLangID_Native_Phase;		 //= _T("Native_Angle");
CString g_sLangTxt_Native_Phase;	 //= _T("相位");
CString g_sLangID_Native_Freq;		 //= _T("Native_Freq");
CString g_sLangTxt_Native_Freq;		 //= _T("频率");
// CString g_sLangID_Native_Unit ;//= _T("Native_Unit");
// CString g_sLangTxt_Native_Unit ;//= _T("单位");
CString g_sLangID_Native_Channel;	   //= _T("Native_Channel");
CString g_sLangTxt_Native_Channel;	   //= _T("通道");
CString g_sLangID_Native_DC;		   //= _T("Native_DC");
CString g_sLangTxt_Native_DC;		   //= _T("直流");
CString g_sLangID_Native_Fundamental;  //= _T("Native_Fundamental");
CString g_sLangTxt_Native_Fundamental; //= _T("基波");
CString g_sLangID_Native_Validity;	   //= _T("Native_Validity");
CString g_sLangTxt_Native_Validity;	   //= _T("有效性");
CString g_sLangID_Native_Overhaul;	   //= _T("Native_Overhaul");
CString g_sLangTxt_Native_Overhaul;	   //= _T("检修");
CString g_sLangID_Native_SelectTestFunction;
CString g_sLangTxt_Native_SelectTestFunction;
CString g_sLangID_Native_ReportHeadSet; // 报告头设置
CString g_sLangTxt_Native_ReportHeadSet;

CString g_sLangID_Native_ConnectingTester;	//= _T("Native_ConnectingTester");
CString g_sLangTxt_Native_ConnectingTester;	//= _T("正在连接测试仪......");
CString g_sLangID_Native_TesterConnectSucc;	//= _T("Native_TesterConnectSucc");
CString g_sLangTxt_Native_TesterConnectSucc;//= _T("测试仪连接成功");
CString g_sLangID_Native_TesterConnectfail;	//= _T("Native_TesterConnectfail");
CString g_sLangTxt_Native_TesterConnectfail;//= _T("连接测试仪失败，请检查网络链路是否连通，IP地址及端口配置是否正确；然后点击网络连接按钮重新连接");
CString g_sLangID_Native_LCSTSendportSTGigabit; //= _T("Native_LCSTSendportSTGigabit");
CString g_sLangTxt_Native_LCSTSendportSTGigabit; //= _T("当前设备共包含LC光口%ld个,ST发送口%ld个,ST接收口%ld个,千兆光口%ld个.");

CString g_sLangID_Harm_Set;		  //= _T("Harm_Set");
CString g_sLangTxt_Harm_Set;	  //= _T("谐波设置");
CString g_sLangID_Harm_Content;	  //= _T("Harm_Content");
CString g_sLangTxt_Harm_Content;  //= _T("谐波含有率");
CString g_sLangID_Harm_Enable;	  //= _T("Harm_Enable");
CString g_sLangTxt_Harm_Enable;	  //= _T("使能");
CString g_sLangID_Harm_UChannel;  //= _T("Harm_UChannel");
CString g_sLangTxt_Harm_UChannel; //= _T("电压通道");
CString g_sLangID_Harm_IChannel;  //= _T("Harm_IChannel");
CString g_sLangTxt_Harm_IChannel; //= _T("电流通道");

CString g_sLangID_Harm_UAllSelect; //= _T("Harm_UAllSelect");
CString g_sLangTxt_Harm_UAllSelect; //= _T("电压全选");
CString g_sLangID_Harm_IAllSelect; //= _T("Harm_IAllSelect");
CString g_sLangTxt_Harm_IAllSelect; //= _T("电流全选");
CString g_sLangID_Harm_UClear;	   //=("Harm_UClear");
CString g_sLangTxt_Harm_UClear;	   //=("电压清空");
CString g_sLangID_Harm_IClear;	   //=("Harm_IClear");
CString g_sLangTxt_Harm_IClear;		//=("电流清空");

CString g_sLangID_Harm_Reset;	  //= _T("Harm_Reset");
CString g_sLangTxt_Harm_Reset;	  //= _T("谐波清零");
CString g_sLangID_Harm_FundFreq;  //= _T("Harm_FundFreq");
CString g_sLangTxt_Harm_FundFreq; //= _T("基波频率");
CString g_sLangID_Harm_Times;	  //= _T("Harm_Times");
CString g_sLangTxt_Harm_Times;	  //= _T("次");
CString g_sLangID_Harm_InterHarm; // 间谐波
CString g_sLangTxt_Harm_InterHarm;

CString g_sLangID_Native_PhaseO;   //= _T("Native_PhaseO");
CString g_sLangTxt_Native_PhaseO;  //= _T("0相");
CString g_sLangID_Native_Relay;	   //= _T("Native_Relay");
CString g_sLangTxt_Native_Relay;   //= _T("保护");
CString g_sLangID_Native_Measure;  //= _T("Native_Measure");
CString g_sLangTxt_Native_Measure; //= _T("测量");
CString g_sLangID_Native_Current;  //= _T("Native_Current");
CString g_sLangTxt_Native_Current; //= _T("电流");
CString g_sLangID_Native_Voltage;  //= _T("Native_Voltage");
CString g_sLangTxt_Native_Voltage; //= _T("电压");

CString g_sLangID_Native_GndA;			//= _T("Native_GndA");
CString g_sLangTxt_Native_GndA;			//= _T("A相接地");
CString g_sLangID_Native_GndB;			//= _T("Native_GndB");
CString g_sLangTxt_Native_GndB;			//= _T("B相接地");
CString g_sLangID_Native_GndC;			//= _T("Native_GndC");
CString g_sLangTxt_Native_GndC;			//= _T("C相接地");
CString g_sLangID_Native_ShortAB;		//= _T("Native_ShortAB");
CString g_sLangTxt_Native_ShortAB;		//= _T("AB短路");
CString g_sLangID_Native_ShortBC;		//= _T("Native_ShortBC");
CString g_sLangTxt_Native_ShortBC;		//= _T("BC短路");
CString g_sLangID_Native_ShortCA;		//= _T("Native_ShortCA");
CString g_sLangTxt_Native_ShortCA;		//= _T("CA短路");
CString g_sLangID_Native_GndShortAB;	//= _T("Native_GndShortAB");
CString g_sLangTxt_Native_GndShortAB;	//= _T("AB接地短路");
CString g_sLangID_Native_GndShortBC;	//= _T("Native_GndShortBC");
CString g_sLangTxt_Native_GndShortBC;	//= _T("BC接地短路");
CString g_sLangID_Native_GndShortCA;	//= _T("Native_GndShortCA");
CString g_sLangTxt_Native_GndShortCA;	//= _T("CA接地短路");
CString g_sLangID_Native_ShortABC;		//= _T("Native_ShortABC");
CString g_sLangTxt_Native_ShortABC;		//= _T("三相短路");
CString g_sLangID_Native_SinglePhase;	//= _T("Native_SinglePhase");
CString g_sLangTxt_Native_SinglePhase;	//= _T("单相系统");
CString g_sLangID_Native_INotChange;	//= _T("Native_INotChange");
CString g_sLangTxt_Native_INotChange;	//= _T("电流不变");
CString g_sLangID_Native_UNotChange;	//= _T("Native_UNotChange");
CString g_sLangTxt_Native_UNotChange;	//= _T("电压不变");
CString g_sLangID_Native_ZNotChange;	//= _T("Native_ZNotChange");
CString g_sLangTxt_Native_ZNotChange;	//= _T("系统阻抗不变");
CString g_sLangID_Native_UZoomOut;		//= _T("Native_UZoomOut");
CString g_sLangTxt_Native_UZoomOut;		//= _T("电压放大");
CString g_sLangID_Native_UZoomIn;		//= _T("Native_UZoomIn");
CString g_sLangTxt_Native_UZoomIn;		//= _T("电压缩小");
CString g_sLangID_Native_IZoomOut;		//= _T("Native_IZoomOut");
CString g_sLangTxt_Native_IZoomOut;		//= _T("电流放大");
CString g_sLangID_Native_IZoomIn;		//= _T("Native_IZoomIn");
CString g_sLangTxt_Native_IZoomIn;		//= _T("电流缩小");
CString g_sLangID_Native_EDPhaseV;		//= _T("Native_EDPhaseV");
CString g_sLangTxt_Native_EDPhaseV;		//= _T("额定相电压");
CString g_sLangID_Native_EDCurrent;		//= _T("Native_EDCurrent");
CString g_sLangTxt_Native_EDCurrent;	//= _T("额定电流");
CString g_sLangID_Native_EqualAmp;		//= _T("Native_EqualAmp");
CString g_sLangTxt_Native_EqualAmp;		//= _T("等幅值");
CString g_sLangID_Native_EqualFreq;		//= _T("Native_EqualFreq");
CString g_sLangTxt_Native_EqualFreq;	//= _T("等频率");
CString g_sLangID_Native_PositiveSeq;	//= _T("Native_PositiveSeq");
CString g_sLangTxt_Native_PositiveSeq;	//= _T("正序");
CString g_sLangID_Native_NegativeSeq;	//= _T("Native_NegativeSeq");
CString g_sLangTxt_Native_NegativeSeq;	//= _T("负序");
CString g_sLangID_Native_ZeroSeq;		//= _T("Native_ZeroSeq");
CString g_sLangTxt_Native_ZeroSeq;		//= _T("零序");
CString g_sLangID_Native_Zero;			//= _T("Native_Zero");
CString g_sLangTxt_Native_Zero;			//= _T("零");
CString g_sLangID_Native_AllGroup;		//= _T("Native_AllGroup");
CString g_sLangTxt_Native_AllGroup;		//= _T("总组数:");
CString g_sLangID_Native_CurGroup;		//= _T("Native_CurGroup");
CString g_sLangTxt_Native_CurGroup;		//= _T("当前组:");
CString g_sLangID_Native_LastGroup;		//= _T("Native_LastGroup");
CString g_sLangTxt_Natve_LastGroup;		//= _T("上一组");
CString g_sLangID_Native_NextGroup;		//= _T("Native_NextGroup");
CString g_sLangTxt_Natve_NextGroup;		//= _T("下一组");
CString g_sLangID_Native_ExBinSet;		//= _T("Native_ExBinSet");
CString g_sLangTxt_Native_ExBinSet;		//= _T("扩展开入设置");
CString g_sLangID_Native_ExBoutSet;		//= _T("Native_ExBoutSet");
CString g_sLangTxt_Native_ExBoutSet;	//= _T("扩展开出设置");
CString g_sLangID_Native_GooseDataSet;	//= _T("Native_GooseDataSet");
CString g_sLangTxt_Native_GooseDataSet; //= _T("Goose数据发送");
CString g_sLangID_Native_GooseOutSet;		//= _T("Native_GooseOutSet");
CString g_sLangTxt_Native_GooseOutSet	;	//= _T("GOOSE OUT-->开入");
CString g_sLangID_Native_GooseInSet;	//= _T("Native_GooseInSet");
CString g_sLangTxt_Native_GooseInSet;	//= _T("开出-->GOOSE IN");
CString g_sLangID_Native_Bin;			//= _T("Native_Bin");
CString g_sLangTxt_Native_Bin;			//= _T("开入量");
CString g_sLangID_Native_Bout;			//= _T("Native_Bout");
CString g_sLangTxt_Native_Bout;			//= _T("开出量");

CString g_sLangID_Native_BinX;	 //= _T("Native_BinX");
CString g_sLangTxt_Native_BinX;	 //= _T("开入");
CString g_sLangID_Native_BoutX;	 //= _T("Native_BoutX");
CString g_sLangTxt_Native_BoutX; //= _T("开出");

CString g_sLangID_Native_BinEx;	  //= _T("Native_BinEx");
CString g_sLangTxt_Native_BinEx;  //= _T("扩展开入");
CString g_sLangID_Native_BoutEx;  //= _T("Native_BoutEx");
CString g_sLangTxt_Native_BoutEx; //= _T("扩展开出");

CString g_sLangID_Native_ActType;	  //= _T("Native_ActType");
CString g_sLangTxt_Native_ActType;	  //= _T("动作类型");
CString g_sLangID_Native_ActionTime;  //= _T("Native_ActionTime");
CString g_sLangTxt_Native_ActionTime; //= _T("动作时间(s)");
CString g_sLangID_Native_CurTypeIdx;  //= _T("Native_CurTypeIdx");
CString g_sLangTxt_Native_CurTypeIdx; //= _T("当前状态号");
CString g_sLangID_Native_Group;		  //= _T("Native_Group");
CString g_sLangTxt_Native_Group;	  //= _T("组");

CString g_sLangID_Native_Reverse;  //= _T("Native_Reverse");
CString g_sLangTxt_Native_Reverse; //= _T("取反");
CString g_sLangID_Native_Repair;   //= _T("Native_Repair");
CString g_sLangTxt_Native_Repair;  //= _T("置检修");
CString g_sLangID_Native_Revert;   //= _T("Native_Revert");
CString g_sLangTxt_Native_Revert;  //= _T("复归");
CString g_sLangID_Native_IEDName;  //= _T("Native_IEDName");
CString g_sLangTxt_Native_IEDName; //= _T("IED名称");
CString g_sLangID_Native_APPID;	   //= _T("Native_APPID");
CString g_sLangTxt_Native_APPID;   //= _T("应用标识(APPID)    0x");

CString g_sLangID_Native_Type;	//= _T("Native_Type");
CString g_sLangTxt_Native_Type; //= _T("类型:");
CString g_sLangID_Native_Switch;
CString g_sLangTxt_Native_Switch;
CString g_sLangID_Native_Action;	   //= _T("Native_Action");
CString g_sLangTxt_Native_Action;	   //= _T("动作值(V):");
CString g_sLangID_Native_ReturnVal;	   //= _T("Native_ReturnVal");
CString g_sLangTxt_Native_ReturnVal;   //= _T("返回值(V):");
CString g_sLangID_Native_ReturnCoeff;  //= _T("Native_ReturnCoeff");
CString g_sLangTxt_Native_ReturnCoeff; //= _T("返回系数");
CString g_sLangID_Native_LogicOr;	   //= _T("Native_LogicOr");
CString g_sLangTxt_Native_LogicOr;	   //= _T("逻辑或");
CString g_sLangID_Native_LogicAnd;	   //= _T("Native_LogicAnd");
CString g_sLangTxt_Native_LogicAnd;	   //= _T("逻辑与");

CString g_sLangID_Native_Enter;	 //= _T("Native_Enter");
CString g_sLangTxt_Native_Enter; //= _T("完成");

CString g_sLangID_Native_Caps;	 //= _T("Native_Caps");
CString g_sLangTxt_Native_Caps;	 //= _T("大小写");
CString g_sLangID_Native_Space;	 //= _T("Native_Space");
CString g_sLangTxt_Native_Space; //= _T("空格");

CString g_sLangID_Native_Maps;	//= _T("Native_Maps");
CString g_sLangTxt_Native_Maps; //= _T("映射");
CString g_sLangID_Native_Chs;	//= _T("Native_Chs");
CString g_sLangTxt_Native_Chs;	//= _T("中/英");
CString g_sLangID_Native_Eng;	//= _T("Native_Eng");
CString g_sLangTxt_Native_Eng;	//= _T("英/中");

CString g_sLangID_Native_FileFolder;  //= _T("Native_FileFolder");
CString g_sLangTxt_Native_FileFolder; //= _T("文件目录");
CString g_sLangID_Native_NoTimeSync;  //= _T("Native_NoTimeSync");
CString g_sLangTxt_Native_NoTimeSync; //= _T("未对时");
CString g_sLangID_Native_AllFreq;
CString g_sLangTxt_Native_AllFreq;

CString g_sLangID_Native_FileType;
CString g_sLangTxt_Native_FileType;

CString g_sLangID_Native_SCLPath;
CString g_sLangTxt_Native_SCLPath;
CString g_sLangID_Native_SCLFilter;
CString g_sLangTxt_Native_SCLFilter;
CString g_sLangID_Native_ResultJudge;
CString g_sLangTxt_Native_ResultJudge;
CString g_sLangID_Native_ResultDescript;
CString g_sLangTxt_Native_ResultDescript;
CString g_sLangID_Native_ResultTime;
CString g_sLangTxt_Native_ResultTime;
CString g_sLangID_Native_ResultAbsRsltCal1;
CString g_sLangTxt_Native_ResultAbsRsltCal1;
CString g_sLangID_Native_ResultAbsRsltCal2;
CString g_sLangTxt_Native_ResultAbsRsltCal2;
CString g_sLangID_Native_ResultRelRsltCal1;
CString g_sLangTxt_Native_ResultRelRsltCal1;
CString g_sLangID_Native_ResultRelRsltCal2;
CString g_sLangTxt_Native_ResultRelRsltCal2;
CString g_sLangID_Native_TimeSettingCoef;
CString g_sLangTxt_Native_TimeSettingCoef;

CString g_sLangID_Manual_IV;		   //= _T("Manual_IV");
CString g_sLangTxt_Manual_IV;		   //= _T("电流电压");
CString g_sLangID_Manual_OtherParam;   //= _T("Manual_OtherParam");
CString g_sLangTxt_Manual_OtherParam;  //= _T("其它参数设置");
CString g_sLangID_Manual_GlobalParam;  //= _T("Manual_GlobalParam");
CString g_sLangTxt_Manual_GlobalParam; //= _T("全局参数设置");
CString g_sLangID_Manual_Oscillogram;  //=_T("Manual_Oscillogram");
CString g_sLangTxt_Manual_Oscillogram; //=_T("波形图");

CString g_sLangID_Manual_FirGroup;	//=_T("Manual_FirGroup");第1组LCQ
CString g_sLangTxt_Manual_FirGroup; //=_T("第1组");

CString g_sLangID_Manual_Changing;	  //= _T("Manual_Changing");
CString g_sLangTxt_Manual_Changing;	  //= _T("递变");
CString g_sLangID_Manual_InitVal;	  //= _T("Manual_InitVal");
CString g_sLangTxt_Manual_InitVal;	  //= _T("始值(V):");
CString g_sLangID_Manual_ChangeType;  //= _T("Manual_ChangeType");
CString g_sLangTxt_Manual_ChangeType; //= _T("变化方式:");
CString g_sLangID_Manual_Channel;	  //= _T("Manual_Channel");
CString g_sLangTxt_Manual_Channel;	  //= _T("通道选择:");
CString g_sLangID_Manual_FinishVal;	  //= _T("Manual_FinishVal");
CString g_sLangTxt_Manual_FinishVal;  //= _T("终值(V):");
CString g_sLangID_Manual_Step;		  //= _T("Manual_Step");
CString g_sLangTxt_Manual_Step;		  //= _T("步长(V):");
CString g_sLangID_Manual_Timer;		  //= _T("Manual_Timer");
CString g_sLangTxt_Manual_Timer;	  //= _T("时间(s):");
CString g_sLangID_Manual_Old;		  //= _T("Manual_Old");
CString g_sLangTxt_Manual_Old;		  //= _T("老化");
CString g_sLangID_Manual_Auto;		  //= _T("Manual_Auto");
CString g_sLangTxt_Manual_Auto;		  //= _T("自动");

CString g_sLangID_Manual_Delayed;	  //= _T("Manual_Delayed");
CString g_sLangTxt_Manual_Delayed;	  //= _T("触发后延时(s):");
CString g_sLangID_Manual_OutSetting;  //= _T("Manual_OutSetting");
CString g_sLangTxt_Manual_OutSetting; //= _T("开出设置");
CString g_sLangID_Manual_Out1;		  //= _T("Manual_Out1");
CString g_sLangTxt_Manual_Out1;		  //= _T("开出1");
CString g_sLangID_Manual_Out2;		  //= _T("Manual_Out2");
CString g_sLangTxt_Manual_Out2;		  //= _T("开出2");
CString g_sLangID_Manual_Out3;		  //= _T("Manual_Out3");
CString g_sLangTxt_Manual_Out3;		  //= _T("开出3");
CString g_sLangID_Manual_Out4;		  //= _T("Manual_Out4");
CString g_sLangTxt_Manual_Out4;		  //= _T("开出4");
CString g_sLangID_Manual_Out5;		  //= _T("Manual_Out5");
CString g_sLangTxt_Manual_Out5;		  //= _T("开出5");
CString g_sLangID_Manual_Out6;		  //= _T("Manual_Out6");
CString g_sLangTxt_Manual_Out6;		  //= _T("开出6");
CString g_sLangID_Manual_Out7;		  //= _T("Manual_Out7");
CString g_sLangTxt_Manual_Out7;		  //= _T("开出7");
CString g_sLangID_Manual_Out8;		  //= _T("Manual_Out8");
CString g_sLangTxt_Manual_Out8;		  //= _T("开出8");
CString g_sLangID_Manual_InSetting;	  //= _T("Manual_InSetting");
CString g_sLangTxt_Manual_InSetting;  //= _T("开入设置");
CString g_sLangID_Manual_InA;		  //= _T("Manual_InA");
CString g_sLangTxt_Manual_InA;		  //= _T("开入A");
CString g_sLangID_Manual_InB;		  //= _T("Manual_InB");
CString g_sLangTxt_Manual_InB;		  //= _T("开入B");
CString g_sLangID_Manual_InC;		  //= _T("Manual_InC");
CString g_sLangTxt_Manual_InC;		  //= _T("开入C");
CString g_sLangID_Manual_InD;		  //= _T("Manual_InD");
CString g_sLangTxt_Manual_InD;		  //= _T("开入D");
CString g_sLangID_Manual_InE;		  //= _T("Manual_InE");
CString g_sLangTxt_Manual_InE;		  //= _T("开入E");
CString g_sLangID_Manual_InF;		  //= _T("Manual_InF");
CString g_sLangTxt_Manual_InF;		  //= _T("开入F");
CString g_sLangID_Manual_InG;		  //= _T("Manual_InG");
CString g_sLangTxt_Manual_InG;		  //= _T("开入G");
CString g_sLangID_Manual_InH;		  //= _T("Manual_InH");
CString g_sLangTxt_Manual_InH;		  //= _T("开入H");
CString g_sLangID_Manual_Lock;		  //= _T("Manual_Lock");
CString g_sLangTxt_Manual_Lock;		  //= _T("锁");
CString g_sLangID_Manual_UnLock;	  //= _T("Manual_UnLock");
CString g_sLangTxt_Manual_UnLock;	  //= _T("解锁");
CString g_sLangID_Manual_ActionTime;  //= _T("Manual_ActionTime");
CString g_sLangTxt_Manual_ActionTime; //= _T("动作时间(s):");
CString g_sLangID_Manual_ReturnTime;  //= _T("Manual_ReturnTime");
CString g_sLangTxt_Manual_ReturnTime; //= _T("返回时间(s):");
CString g_sLangID_Manual_S_E;		  //= _T("Manual_S_E");
CString g_sLangTxt_Manual_S_E;		  //= _T("始-终");
CString g_sLangID_Manual_S_E_S;		  //= _T("Manual_S_E_S");
CString g_sLangTxt_Manual_S_E_S;	  //= _T("始-终-始");

CString g_sLangID_Manual_Harm;
CString g_sLangTxt_Manual_Harm;
CString g_sLangID_Manual_TestMethod;
CString g_sLangTxt_Manual_TestMethod;
CString g_sLangID_Manual_MeasType;
CString g_sLangTxt_Manual_MeasType;
CString g_sLangID_Manual_BCode;
CString g_sLangTxt_Manual_BCode;
CString g_sLangID_Manual_TestReport;
CString g_sLangTxt_Manual_TestReport;
CString g_sLangID_Manual_TestTime;
CString g_sLangTxt_Manual_TestTime;
CString g_sLangID_Manual_PositiveLogic;
CString g_sLangTxt_Manual_PositiveLogic;
CString g_sLangID_Manual_NegativeLogic;
CString g_sLangTxt_Manual_NegativeLogic;

CString g_sLangID_Manual_SyncSet;			 //=_T("Manual_SyncSet");
CString g_sLangTxt_Manual_SyncSet;			 //=_T("同步设置");
CString g_sLangID_Manual_SecSyncStatus;		 //=_T("Manual_SecSyncStatus");
CString g_sLangTxt_Manual_SecSyncStatus;	 //=_T("秒同步状态");
CString g_sLangID_Manual_OpenSecSync;		 //=_T("Manual_OpenSecSync");
CString g_sLangTxt_Manual_OpenSecSync;		 //=_T("开启秒同步");
CString g_sLangID_Manual_CloseSecSync;		 //=_T("Manual_CloseSecSync");
CString g_sLangTxt_Manual_CloseSecSync;		 //=_T("关闭秒同步");
CString g_sLangID_Manual_IEC1588Sync;		 //=_T("Manual_IEC1588Sync");
CString g_sLangTxt_Manual_IEC1588Sync;		 //=_T("IEC1588同步机制");
CString g_sLangID_Manual_PeerDelay;			 //=_T("Manual_PeerDelay");
CString g_sLangTxt_Manual_PeerDelay;		 //=_T("对等延时");
CString g_sLangID_Manual_DelayRequestReply;	 //=_T("Manual_PeerDelay");
CString g_sLangTxt_Manual_DelayRequestReply; //=_T("延时请求-响应");

CString g_sLangID_Manual_Refresh;
CString g_sLangTxt_Manual_Refresh;

CString g_sLangID_IEC_WeakSet;			 //= _T("IEC_WeakSet");
CString g_sLangTxt_IEC_WeakSet;			 //= _T("弱信号设置");
CString g_sLangID_ErrorSet;				 //= _T("sErrorSet");
CString g_sLangTxt_ErrorSet;			 //= _T("误差值设置");
CString g_sLangID_CurAbsError;			 //= _T("sCurAbsError");
CString g_sLangTxt_CurAbsError;			 //= _T("电流动作值绝对误差(A):");
CString g_sLangID_CurRelError;			 //= _T("sCurRelError");
CString g_sLangTxt_CurRelError;			 //= _T("电流动作值相对误差(%):");
CString g_sLangID_VolAbsError;			 //= _T("sVolAbsError");
CString g_sLangTxt_VolAbsError;			 //= _T("电压动作值绝对误差(V):");
CString g_sLangID_VolRelError;			 //= _T("sVolRelError");
CString g_sLangTxt_VolRelError;			 //= _T("电压动作值相对误差(%):");
CString g_sLangID_ImpAbsError;			 //= _T("sImpAbsError");
CString g_sLangTxt_ImpAbsError;			 //= _T("阻抗动作值绝对误差(Ω):");
CString g_sLangID_ImpRelError;			 //= _T("sImpRelError");
CString g_sLangTxt_ImpRelError;			 //= _T("阻抗动作值相对误差(%):");
CString g_sLangID_TimeAbsError;			 //= _T("sTimeAbsError");
CString g_sLangTxt_TimeAbsError;		 //= _T("动作时间绝对误差(%):");
CString g_sLangID_TimeRelError;			 //= _T("sTimeRelError");
CString g_sLangTxt_TimeRelError;		 //= _T("动作时间相对误差(%):");
CString g_sLangID_AngError;				 //= _T("sAngError");
CString g_sLangTxt_AngError;			 //= _T("相位误差值(°):");
CString g_sLangID_FreqError;			 //= _T("sFreqError");
CString g_sLangTxt_FreqError;			 //= _T("频率误差值(Hz):");
CString g_sLangID_DvDtError;			 //= _T("sDvDtError");
CString g_sLangTxt_DvDtError;			 //= _T("电压滑差误差值(V/s):");
CString g_sLangID_DfDtError;			 //= _T("sDfDtError");
CString g_sLangTxt_DfDtError;			 //= _T("频率滑差误差值(Hz/s):");
CString g_sLangID_DiffRateCoefAbsError;	 //= _T("sDiffRateCoefAbsError");
CString g_sLangTxt_DiffRateCoefAbsError; //= _T("差动比率制动系数绝对误差:");
CString g_sLangID_DiffRateCoefRelError;	 //= _T("sDiffRateCoefRelError");
CString g_sLangTxt_DiffRateCoefRelError; //= _T("差动比率制动系数相对误差:");
CString g_sLangID_DiffHarmCoefAbsError;	 //= _T("sDiffHarmCoefAbsError");
CString g_sLangTxt_DiffHarmCoefAbsError; //= _T("差动谐波制动系数绝对误差:");
CString g_sLangID_DiffHarmCoefRelError;	 //= _T("sDiffHarmCoefRelError");
CString g_sLangTxt_DiffHarmCoefRelError; //= _T("差动谐波制动系数相对误差:");

CString g_sLangID_State_TrigerSetup;		 //= _T("State_TrigerSetup");
CString g_sLangTxt_State_TrigerSetup;		 //= _T("触发设置");
CString g_sLangID_State_TrigerCondition;	 //= _T("State_TrigerCondition");
CString g_sLangTxt_State_TrigerCondition;	 //= _T("触发条件");
CString g_sLangID_State_OutTime;			 //= _T("State_OutTime");
CString g_sLangTxt_State_OutTime;			 //= _T("输出时间(s)");
CString g_sLangID_State_TrigerTime;			 //= _T("State_TrigerTime");
CString g_sLangTxt_State_TrigerTime;		 //= _T("触发时刻");
CString g_sLangID_State_Hour;				 //= _T("State_Hour");
CString g_sLangTxt_State_Hour;				 //= _T("时");
CString g_sLangID_State_Minute;				 //= _T("State_Minute");
CString g_sLangTxt_State_Minute;			 //= _T("分");
CString g_sLangID_State_Second;				 //= _T("State_Second");
CString g_sLangTxt_State_Second;			 //= _T("秒");
CString g_sLangID_State_TrigerHoldTime;		 //= _T("State_TrigerHoldTime");
CString g_sLangTxt_State_TrigerHoldTime;	 //= _T("触发后保持时间(s)");
CString g_sLangID_State_HoldTime;			 //= _T("State_HoldTime");
CString g_sLangTxt_State_HoldTime;			 //= _T("保持时间(s):");
CString g_sLangID_State_ShortCalc;			 //= _T("State_ShortCalc");
CString g_sLangTxt_State_ShortCalc;			 //= _T("短路计算");
CString g_sLangID_State_GradientSet;		 //= _T("State_GradientSet");
CString g_sLangTxt_State_GradientSet;		 //= _T("递变设置");
CString g_sLangID_State_PasteStateBf;		 //= _T("State_PasteStateBf");
CString g_sLangTxt_State_PasteStateBf;		 //= _T("粘贴状态—前");
CString g_sLangID_State_InsertStateBf;		 //= _T("State_InsertStateBf");
CString g_sLangTxt_State_InsertStateBf;		 //= _T("插入状态—前");
CString g_sLangID_State_InsertStateAf;		 //= _T("State_InsertStateAf");
CString g_sLangTxt_State_InsertStateAf;		 //= _T("插入状态—后");
CString g_sLangID_State_PasteStateAf;		 //= _T("State_PasteStateAf");
CString g_sLangTxt_State_PasteStateAf;		 //= _T("粘贴状态—后");
CString g_sLangID_State_CopyCurState;		 //= _T("State_CopyCurState");
CString g_sLangTxt_State_CopyCurState;		 //= _T("拷贝当前状态");
CString g_sLangID_State_DeleteCurState;		 //= _T("State_DeleteCurState");
CString g_sLangTxt_State_DeleteCurState;	 //= _T("删除当前状态");
CString g_sLangID_State_UISet;				 //= _T("State_UISet");
CString g_sLangTxt_State_UISet;				 //= _T("电压电流设置");
CString g_sLangID_State_StateParaSet;		 //= _T("State_StateParaSet");
CString g_sLangTxt_State_StateParaSet;		 //= _T("状态参数设置");
CString g_sLangID_State_JudgeCondition;		 //=_T("State_JudgeCondition");
CString g_sLangTxt_State_JudgeCondition;	 //=_T("开入翻转参考状态");
CString g_sLangID_State_DCOffSet;			 //=_T("State_DCOffSet");
CString g_sLangTxt_State_DCOffSet;			 //=_T("叠加衰减直流分量");
CString g_sLangID_State_Tou;				 //=_T("State_Tou");
CString g_sLangTxt_State_Tou;				 //=_T("衰减时间常数");
CString g_sLangID_State_StackByState;		 //=_T("State_StackByState");
CString g_sLangTxt_State_StackByState;		 //=_T("按状态叠加");
CString g_sLangID_State_RepeatTimes;		 //=_T("State_RepeatTimes");
CString g_sLangTxt_State_RepeatTimes;		 //=_T("循环次数");
CString g_sLangID_State_ChGroup;			 //=_T("State_ChGroup");
CString g_sLangTxt_State_ChGroup;			 //=_T("组号:");
//chenling 20240204 异常报文选择APPID
CString g_sLangID_Abnormal_APPID;
CString g_sLangTxt_Abnormal_APPID;
CString g_sLangID_State_FaultType;			 //=_T("State_FaultType");
CString g_sLangTxt_State_FaultType;			 //=_T("故障类型:");
CString g_sLangID_State_CalcMode;			 //=_T("State_CalcMode");
CString g_sLangTxt_State_CalcMode;			 //=_T("计算模型:");
CString g_sLangID_State_ShortI;				 //=_T("State_ShortI");
CString g_sLangTxt_State_ShortI;			 //=_T("短路电流(A):");
CString g_sLangID_State_ShortU;				 //=_T("State_ShortU");
CString g_sLangTxt_State_ShortU;			 //=_T("短路电压(V):");
CString g_sLangID_State_ZeroCoeff;			 //=_T("State_ZeroCoeff");
CString g_sLangTxt_State_ZeroCoeff;			 //=_T("零序补偿系数");
CString g_sLangID_State_CalcType;			 //=_T("State_CalcType");
CString g_sLangTxt_State_CalcType;			 //=_T("计算方式:");
CString g_sLangID_State_Amp;				 //=_T("State_Amp");
CString g_sLangTxt_State_Amp;				 //=_T("幅值:");
CString g_sLangID_State_Angle;				 //=_T("State_Angle");
CString g_sLangTxt_State_Angle;				 //=_T("相角:");
CString g_sLangID_LoadI;					 //=_T("State_LoadI");
CString g_sLangTxt_LoadI;					 //=_T("负荷电流(A):");
CString g_sLangID_State_LoadAngle;			 //=_T("State_LoadAngle");
CString g_sLangTxt_State_LoadAngle;			 //=_T("负荷功角(°):");
CString g_sLangID_State_Trigger_Time;		 //= _T("State_Trigger_Time");
CString g_sLangTxt_State_Trigger_Time;		 //= _T("时间触发");
CString g_sLangID_State_Trigger_TimeAndBin;	 //= _T("State_Trigger_TimeAndBin");
CString g_sLangTxt_State_Trigger_TimeAndBin; //= _T("时间或开入量翻转");
CString g_sLangID_State_Trigger_Bin;		 //= _T("State_Trigger_Bin");
CString g_sLangTxt_State_Trigger_Bin;		 //= _T("开入量触发");
CString g_sLangID_State_Trigger_Manu;		 //= _T("State_Trigger_Manu");
CString g_sLangTxt_State_Trigger_Manu;		 //= _T("手动触发");
CString g_sLangID_State_Trigger_GPSB;		 //= _T("State_Trigger_GPSB");
CString g_sLangTxt_State_Trigger_GPSB;		 //= _T("GPS/B码触发");
CString g_sLangID_State_LinearChange;		 //=  _T("State_LinearChange");
CString g_sLangTxt_State_LinearChange;		 //= _T("线性变化");
CString g_sLangID_State_StepChange;			 //= _T("State_StepChange");
CString g_sLangTxt_State_StepChange;		 //= _T("阶梯变化");
CString g_sLangID_State_StepTime;			 //= _T("State_StepTime");
CString g_sLangTxt_State_StepTime;			 //= _T("步长时间(s)");
CString g_sLangID_State_BeginVal;			 //= _T("State_BeginVal");
CString g_sLangTxt_State_BeginVal;			 //= _T("始值");
CString g_sLangID_State_EndVal;				 //= _T("State_EndVal");
CString g_sLangTxt_State_EndVal;			 //= _T("终值");
CString g_sLangID_State_AmpGradient;		 //= _T("State_AmpGradient");
CString g_sLangTxt_State_AmpGradient;		 //= _T("幅值递变");
CString g_sLangID_State_FreqGradient;		 //= _T("State_FreqGradient");
CString g_sLangTxt_State_FreqGradient;		 //= _T("频率递变");
CString g_sLangID_State_LastState;			 //=	_T("State_LastState");
CString g_sLangTxt_State_LastState;			 //= _T("上一个状态");
CString g_sLangID_State_FirstState;			 //= _T("State_FirstState");
CString g_sLangTxt_State_FirstState;		 //= _T("第一个状态");
CString g_sLangID_State_No;					 //= _T("State_No");  //sun
CString g_sLangTxt_State_No;				 //= _T("否");        //sun
CString g_sLangID_State_Yes;				 //= _T("State_Yes"); //sun
CString g_sLangTxt_State_Yes;				 //= _T("是");        //sun
CString g_sLangID_State_HarmCount;			 //= _T("State_HarmCount");
CString g_sLangTxt_State_HarmCount;			 //= _T("次谐波");

CString g_sLangID_State_NoActioned;	 //= _T("State_NoActioned");//LCQ
CString g_sLangTxt_State_NoActioned; //= _T("未动作");

CString g_sLangID_State_ActionValue;  //= _T("State_ActionValue");//LCQ
CString g_sLangTxt_State_ActionValue; // = _T("动作值");

CString g_sLangID_State_Error;	//= _T("State_Error");//LCQ
CString g_sLangTxt_State_Error; // = _T("误差");

CString g_sLangID_State_CurlfailedItems;  //= _T("State_CurlfailedItems");  //LCQ
CString g_sLangTxt_State_CurlfailedItems; //= _T("特性曲线查找失败(strCharaID=%s;strIndex=%s),无法更新项目列表.");

CString g_sLangID_State_Sysgenerated;  //= _T("State_Sysgenerated");  //LCQ
CString g_sLangTxt_State_Sysgenerated; //= _T("系统生成");

CString g_sLangID_State_StatusEdition;	//= _T("State_StatusEdition");//LCQ
CString g_sLangTxt_State_StatusEdition; //= _T("状态编辑");

CString g_sLangID_State_HarmonicAmpInc;	 //= _T("State_HarmonicAmpInc");//LCQ
CString g_sLangTxt_State_HarmonicAmpInc; //= _T("谐波按幅值递变");

CString g_sLangID_State_HarmonicAmpPer;	 //= _T("State_HarmonicAmpPer");//LCQ
CString g_sLangTxt_State_HarmonicAmpPer; //= _T("谐波按百分比递变");

CString g_sLangID_State_PreviosState;  //= _T("State_PreviosState");//LCQ
CString g_sLangTxt_State_PreviosState; //= _T("上一状态");

CString g_sLangID_State_NextState;	//= _T("State_NextState");//LCQ
CString g_sLangTxt_State_NextState; //= _T("下一状态");

CString g_sLangID_Gradient_Npchannelgroupset; //= _T("Gradient_Npchannelgroupset;"); //LCQ
CString g_sLangTxt_Gradient_Npchannelgroupset;
; //= _T("非递变通道分组设置");

CString g_sLangID_Gradient_Groupset;  //= _T("Gradient_Groupset"); //LCQ
CString g_sLangTxt_Gradient_Groupset; //= _T("分组设置");

CString g_sLangID_State_12Oclock;  //= _T("State_12Oclock");//LCQ
CString g_sLangTxt_State_12Oclock; //= _T("十二点");

CString g_sLangID_State_Test;  //= _T("State_Test");//LCQ
CString g_sLangTxt_State_Test; // = _T("测试");

CString g_sLangID_State_Description;  // = _T("State_Description");//LCQ
CString g_sLangTxt_State_Description; // = _T("描述");

CString g_sLangID_State_FGBlueNetworkcar;  // = _T("State_FGBlueNetworkcar");//LCQ
CString g_sLangTxt_State_FGBlueNetworkcar; // = _T("4G、蓝牙、网卡使能");

CString g_sLangID_State_CharCurEdgeElements;  //= _T("State_CharacteristicCurveEdgeElements");//LCQ
CString g_sLangTxt_State_CharCurEdgeElements; //= _T("特性曲线边元素");

CString g_sLangID_State_Bluetooth;	// = _T("State_Bluetooth");//LCQ
CString g_sLangTxt_State_Bluetooth; //   = _T("蓝牙");

CString g_sLangID_State_Wirelesscard;  // = _T("State_Wirelesscard");//LCQ
CString g_sLangTxt_State_Wirelesscard; //   = _T("无线网卡");

CString g_sLangID_State_NativeNetworkcard;	//   = _T("State_NativeNetworkcard");//LCQ
CString g_sLangTxt_State_NativeNetworkcard; //    = _T("本机网卡");

CString g_sLangID_State_MinBacklighttime;  // = _T("State_MinBacklighttime");//LCQ
CString g_sLangTxt_State_MinBacklighttime; //  = _T("背光时间(分钟)");

CString g_sLangID_State_MinScreenBright;	//  = _T("State_MinScreenBright");//LCQ
CString g_sLangTxt_State_MinScreenBright; //  = _T("(屏幕亮度)");

CString g_sLangID_State_NoteFivemeansBrightest;	//  = _T("State_NoteFivemeansBrightest");//LCQ
CString g_sLangTxt_State_NoteFivemeansBrightest; //  = _T("(备注:5代表最亮)");

CString g_sLangID_State_NoteZeromeansAlwayson;	//  = _T("State_NoteZeromeansAlwayson");//LCQ
CString g_sLangTxt_State_NoteZeromeansAlwayson; //  = _T("(备注:0代表常亮)");

CString g_sLangID_State_FanMode;	//  = _T("State_FanMode");
CString g_sLangTxt_State_FanMode; //  = _T("机器散热风扇模式");

CString g_sLangID_State_Normal;	//  = _T("State_Normal");
CString g_sLangTxt_State_Normal; //  = _T("正常");

CString g_sLangID_State_Mute;	//  = _T("State_Mute");
CString g_sLangTxt_State_Mute; //  = _T("静音");

CString g_sLangID_State_Timezonesetting;  // = _T("State_Timezonesetting");//LCQ
CString g_sLangTxt_State_Timezonesetting; // = _T("时区设置");

CString g_sLangID_State_Othersettings;	// = _T("State_Othersettings");//LCQ
CString g_sLangTxt_State_Othersettings; // = _T("其它设置");

CString g_sLangID_State_Statusname;	 //  = _T("State_Statusname");//LCQ
CString g_sLangTxt_State_Statusname; // = _T("状态名");

CString g_sLangID_State_Datavalue;	// = _T("State_Datavalue");//LCQ
CString g_sLangTxt_State_Datavalue; // = _T("数据值");

CString g_sLangID_State_AuxiliaryDCSettings;  // = _T("State_AuxiliaryDCSettings");//LCQ
CString g_sLangTxt_State_AuxiliaryDCSettings; //   = _T("辅助直流设置");

CString g_sLangID_State_Others;	 //= _T("State_Others");//LCQ
CString g_sLangTxt_State_Others; // = _T("其它");

CString g_sLangID_State_Voltagevalue;  // = _T("State_Datavalue");//LCQ
CString g_sLangTxt_State_Voltagevalue; //   = _T("电压值(V):");

CString g_sLangID_Gradient_Pleaselaterithasstarted;	 // = _T("Gradient_Pleaselaterithasstarted");//LCQ
CString g_sLangTxt_Gradient_Pleaselaterithasstarted; //   = _T("请稍后,已开始");

CString g_sLangID_State_Scanlinesegments;  //= _T("State_Scanlinesegments");//LCQ
CString g_sLangTxt_State_Scanlinesegments; //  = _T("扫描线段");

CString g_sLangID_State_Testpoints;	 //= _T("State_Testpoints");//LCQ
CString g_sLangTxt_State_Testpoints; // = _T("测试点");

CString g_sLangID_State_Iecurrent;	//= _T("State_Iecurrent");//LCQ
CString g_sLangTxt_State_Iecurrent; // = _T("电流(Ie)");

CString g_sLangID_State_Acurrent;  // = _T("State_Acurrent");//LCQ
CString g_sLangTxt_State_Acurrent; // = _T("电流(A)");

CString g_sLangID_State_Interpolation;	//= _T("State_Interpolation");//LCQ
CString g_sLangTxt_State_Interpolation; //  = _T("插值法");

CString g_sLangID_State_Synchronousmethod;	// = _T("State_Synchronousmethod");//LCQ
CString g_sLangTxt_State_Synchronousmethod; //   = _T("同步法");

CString g_sLangID_State_TestLogic;	//= _T("State_TestLogic");//LCQ
CString g_sLangTxt_State_TestLogic; // = _T("测试逻辑");

CString g_sLangID_State_Risingedgeeffective;  //= _T("State_Risingedgeeffective");//LCQ
CString g_sLangTxt_State_Risingedgeeffective; // = _T("上升沿有效");

CString g_sLangID_State_Downedgeeffective;	// = _T("State_Downedgeeffective");//LCQ
CString g_sLangTxt_State_Downedgeeffective; // = _T("下降沿有效");

CString g_sLangID_State_NOPPS;	//= _T("State_NOPPS");//LCQ
CString g_sLangTxt_State_NOPPS; //= _T("无PPS");

CString g_sLangID_State_PPSsettings;  // = _T("State_PPSsettings");//LCQ
CString g_sLangTxt_State_PPSsettings; // = _T("PPS设置");

CString g_sLangID_State_UsNoPPSdelaycompensation;  //= _T("State_UsNoPPSdelaycompensation");//LCQ
CString g_sLangTxt_State_UsNoPPSdelaycompensation; //  = _T("无PPS延时补偿(μs)");

CString g_sLangID_State_SSyncduration;	// = _T("State_SSyncduration");//LCQ
CString g_sLangTxt_State_SSyncduration; //  = _T("同步时长(s):");

CString g_sLangID_State_UsCurrenterror;	 //= _T("State_UsCurrenterror");//LCQ
CString g_sLangTxt_State_UsCurrenterror; // = _T("当前误差(μs):");

CString g_sLangID_State_UsMaximumerror;	 //= _T("State_UsMaximumerror");//LCQ
CString g_sLangTxt_State_UsMaximumerror; //  = _T("最大误差(μs):");

CString g_sLangID_State_UsMinimumerror;	 // = _T("State_UsMinimumerror");//LCQ
CString g_sLangTxt_State_UsMinimumerror; //  = _T("最小误差(μs):");

CString g_sLangID_State_Remark;	 //= _T("State_Remark");//LCQ
CString g_sLangTxt_State_Remark; // = _T("备注");

CString g_sLangID_State_SPunctuality;  //= _T("State_SPunctuality");//LCQ
CString g_sLangTxt_State_SPunctuality; // = _T("守时时长(s):");

CString g_sLangID_State_IlleInputCharac;  //= _T("State_IlleInputCharac");//LCQ
CString g_sLangTxt_State_IlleInputCharac; // = _T("输入值含有非法字符");

CString g_sLangID_State_Dropframes;	 //= _T("State_Dropframes");//LCQ
CString g_sLangTxt_State_Dropframes; //  = _T("丢帧");

CString g_sLangID_State_Flypoint;  // = _T("State_Flypoint");//LCQ
CString g_sLangTxt_State_Flypoint; // = _T("飞点");

CString g_sLangID_State_Dithering;	//= _T("State_Dithering");//LCQ
CString g_sLangTxt_State_Dithering; //  = _T("抖动");

CString g_sLangID_State_OutofOrder;	 // = _T("State_OutofOrder");//LCQ
CString g_sLangTxt_State_OutofOrder; // = _T("错序");

CString g_sLangID_State_VoltageandCurrent;	//= _T("State_VoltageandCurrent");//LCQ
CString g_sLangTxt_State_VoltageandCurrent; // = _T("电压电流");

CString g_sLangID_Gradient_CreateFolder;  //= _T("Gradient_CreateFolder");//LCQ
CString g_sLangTxt_Gradient_CreateFolder; // = _T("创建文件夹");

CString g_sLangID_Gradient_FolderCreationFailed;  // = _T("Gradient_FolderCreationFailed");//LCQ
CString g_sLangTxt_Gradient_FolderCreationFailed; //  = _T("文件夹创建失败！");

CString g_sLangID_State_StateSequencefile; // 状态序列模板文件LCQ
CString g_sLangTxt_State_StateSequencefile;

CString g_sLangID_State_SVexceptionSimulation; // SV异常模拟 LCQ
CString g_sLangTxt_State_SVexceptionSimulation;

CString g_sLangID_State_NumnotExceed; // 状态数目不能超过%d LCQ
CString g_sLangTxt_State_NumnotExceed;

CString g_sLangID_State_TheCurrentLoop; // 当前循环 LCQ
CString g_sLangTxt_State_TheCurrentLoop;

CString g_sLangID_State_Enter; // 进入LCQ
CString g_sLangTxt_State_Enter;

CString g_sLangID_State_IncreExperfile;	 //= _T("State_IncreExperfile");//LCQ
CString g_sLangTxt_State_IncreExperfile; //= _T("递变试验模板文件");

CString g_sLangID_State_HarContent;	 //= _T("State_HarContent");//LCQ
CString g_sLangTxt_State_HarContent; //= _T("谐波含量");

CString g_sLangID_State_DifferentCur;  //= _T("State_DifferentCur");//LCQ
CString g_sLangTxt_State_DifferentCur; //= _T("差动电流");

CString g_sLangID_State_BrakingCur;	 //= _T("State_BrakingCur");//LCQ
CString g_sLangTxt_State_BrakingCur; //= _T("制动电流");

CString g_sLangID_State_VoltageRat;	 //= _T("State_VoltageRat");//LCQ
CString g_sLangTxt_State_VoltageRat; //= _T("电压比值");

CString g_sLangID_State_ZImpValue;	//= _T("State_ZImpValue");//LCQ
CString g_sLangTxt_State_ZImpValue; //= _T("阻抗值(Z)");

CString g_sLangID_State_DAngle;	 //= _T("State_Error");//LCQ
CString g_sLangTxt_State_DAngle; //= _T("角度(°)");

CString g_sLangID_State_CurrentRat;	 //= _T("State_CurrentRat");//LCQ
CString g_sLangTxt_State_CurrentRat; //= _T("电流比值");

CString g_sLangID_State_POpenCFile; // 请打开COMTRADE波形文件 lcq 3.15
CString g_sLangTxt_State_POpenCFile;

CString g_sLangID_State_HarmonicBrakingcoefficient; // 谐波制动系数 lcq 3.15
CString g_sLangTxt_State_HarmonicBrakingcoefficient;

CString g_sLangID_State_Harmonicbraking; // 谐波制动 lcq 3.15
CString g_sLangTxt_State_Harmonicbraking;

CString g_sLangID_State_Magnify;  // = _T("State_Magnify");//LCQ
CString g_sLangTxt_State_Magnify; // = _T("放大");

CString g_sLangID_State_Shrink;	 //= _T("State_Shrink");//LCQ
CString g_sLangTxt_State_Shrink; //= _T("缩小");

CString g_sLangID_IECConfig_Screen;	 //= _T("IECConfig_Screen");
CString g_sLangTxt_IECConfig_Screen; //= _T("筛选");

CString g_sLangID_State_Reposition;	 //= _T("State_Reposition");//LCQ
CString g_sLangTxt_State_Reposition; //     = _T("复位");

CString g_sLangID_Gradient_AddExperiment;  //= _T("Gradient_AddExperiment");//LCQ
CString g_sLangTxt_Gradient_AddExperiment; // = _T("添加试验");

CString g_sLangID_State_FThreeStraight;	 //= _T("State_FThreeStraight");//LCQ
CString g_sLangTxt_State_FThreeStraight; // = _T("柔直(FT3)");

CString g_sLangID_State_SinglephaseImpedance;  // = _T("State_SinglephaseImpedance");//LCQ
CString g_sLangTxt_State_SinglephaseImpedance; // = _T("单相阻抗");

CString g_sLangID_State_Coincidence;  //= _T("State_Coincidence");//LCQ
CString g_sLangTxt_State_Coincidence; //= _T("重  合");

CString g_sLangID_State_RearAcceleration;  //= _T("State_RearAcceleration");//LCQ
CString g_sLangTxt_State_RearAcceleration; // = _T("后 加 速");

CString g_sLangID_State_UTC_TwelveWIntDLine;  //= _T("State_UTC_TwelveWIntDLine");//LCQ
CString g_sLangTxt_State_UTC_TwelveWIntDLine; // = _T("(UTC-12:00)国际日期变更线西");

CString g_sLangID_State_UTC_State_UTC_ElevenCUTime;	 //= _T("State_UTC_ElevenCUTime");//LCQ
CString g_sLangTxt_State_UTC_State_UTC_ElevenCUTime; // = _T("(UTC-11:00)协调世界时-11")");

CString g_sLangID_State_UTC_TenAleutianIslands;	 //= _T("State_UTC_TenAleutianIslands");//LCQ
CString g_sLangTxt_State_UTC_TenAleutianIslands; // = _T("(UTC-10:00)阿留申群岛");

CString g_sLangID_State_UTC_NineAlaska;	 //= _T("State_UTC_NineAlaska");//LCQ
CString g_sLangTxt_State_UTC_NineAlaska; //= _T("(UTC-9:00)阿拉斯加");

CString g_sLangID_State_UTC_EUCPacificTime;	 //= _T("State_UTC_EUCPacificTime");//LCQ
CString g_sLangTxt_State_UTC_EUCPacificTime; // = _T("(UTC-8:00)太平洋时间(美国和加拿大)");

CString g_sLangID_State_State_UTC_SevenCLM;	 // = _T("State_UTC_SevenCLM");//LCQ
CString g_sLangTxt_State_State_UTC_SevenCLM; // = _T("(UTC-7:00)奇瓦瓦,拉巴斯,马萨特兰");

CString g_sLangID_State_UTC_SixCentralAmerica;	// = _T("State_UTC_SixCentralAmerica");//LCQ
CString g_sLangTxt_State_UTC_SixCentralAmerica; // = _T("(UTC-6:00)中美洲");

CString g_sLangID_State_UTC_FiveUCEasternTime;	// = _T("State_UTC_FiveUCEasternTime");//LCQ
CString g_sLangTxt_State_UTC_FiveUCEasternTime; //  = _T("(UTC-5:00)东部时间(美国和加拿大)");

CString g_sLangID_State_UTC_FourCanadaAtlanticTime;	 //= _T("State_UTC_FourCanadaAtlanticTime");//LCQ
CString g_sLangTxt_State_UTC_FourCanadaAtlanticTime; // = _T("(UTC-4:00)大西洋时间(加拿大)");

CString g_sLangID_State_UTC_ThreeGreenland;	 //= _T("State_UTC_ThreeGreenland");//LCQ
CString g_sLangTxt_State_UTC_ThreeGreenland; //= _T("(UTC-3:00)格陵兰");

CString g_sLangID_State_UTC_TwoCooUniversalTime;  //= _T("State_UTC_TwoCooUniversalTime");//LCQ
CString g_sLangTxt_State_UTC_TwoCooUniversalTime; // = _T("(UTC-2:00)协调世界时-2");

CString g_sLangID_State_UTC_OneCapIslandsAzores;  //= _T("State_UTC_OneCapIslandsAzores");//LCQ
CString g_sLangTxt_State_UTC_OneCapIslandsAzores; // = _T("(UTC-1:00)佛得角群岛,亚速尔群岛");

CString g_sLangID_State_UTC_DubEdinhLisLon;	 //= _T("State_UTC_DubEdinhLisLon");//LCQ
CString g_sLangTxt_State_UTC_DubEdinhLisLon; //= _T("(UTC)都柏林,爱丁堡,里斯本,伦敦");

CString g_sLangID_State_UTC_POneBCMPWAfrica;  //= _T("State_UTC_POneBCMPWAfrica");//LCQ
CString g_sLangTxt_State_UTC_POneBCMPWAfrica; // = _T("(UTC+1:00)布鲁塞尔,哥本哈根,马德里,巴黎,中非西部");

CString g_sLangID_State_UTC_PTwoCAJerusalem;  //= _T("State_UTC_PTwoCAJerusalem");//LCQ
CString g_sLangTxt_State_UTC_PTwoCAJerusalem; //= _T("(UTC+2:00)开罗,雅典,耶路撒冷");

CString g_sLangID_State_UTC_PThreeBKMPeterby;  // = _T("State_UTC_PThreeBKMPeterby");//LCQ
CString g_sLangTxt_State_UTC_PThreeBKMPeterby; // = _T("(UTC+3:00)巴格达,科威特,莫斯科,圣彼得比");

CString g_sLangID_State_UTC_PFourAbuDhabiBaku;	//= _T("State_UTC_PFourAbuDhabiBaku");//LCQ
CString g_sLangTxt_State_UTC_PFourAbuDhabiBaku; //= _T("(UTC+4:00)阿布扎比,巴库");

CString g_sLangID_State_UTC_PFiveIslamabadKarachi;	//= _T("State_UTC_PFiveIslamabadKarachi");//LCQ
CString g_sLangTxt_State_UTC_PFiveIslamabadKarachi; // = _T("(UTC+5:00)伊斯兰堡,卡拉奇");

CString g_sLangID_State_UTC_PSixAstana;	 //= _T("State_UTC_PSixAstana");//LCQ
CString g_sLangTxt_State_UTC_PSixAstana; //= _T("(UTC+6:00)阿斯塔纳");

CString g_sLangID_State_UTC_PSevenBHJakarta;  //= _T("State_UTC_PSevenBHJakarta");//LCQ
CString g_sLangTxt_State_UTC_PSevenBHJakarta; //= _T("(UTC+7:00)曼谷,河内,雅加达");

CString g_sLangID_State_UTC_PEightBCHUrumqi;  //= _T("State_UTC_PEightBCHUrumqi");//LCQ
CString g_sLangTxt_State_UTC_PEightBCHUrumqi; // = _T("(UTC+8:00)北京,重庆,香港,乌鲁木齐");

CString g_sLangID_State_UTC_PNineTSPyongyang;  //= _T("State_UTC_PNineTSPyongyang");//LCQ
CString g_sLangTxt_State_UTC_PNineTSPyongyang; // = _T("(UTC+9:00)东京,首尔,平壤");

CString g_sLangID_State_UTC_PTenCMSydney;  // = _T("State_UTC_PTenCMSydney");//LCQ
CString g_sLangTxt_State_UTC_PTenCMSydney; // = _T("(UTC+10:00)堪培拉,墨尔本,悉尼");

CString g_sLangID_State_UTC_PSINCaledonia;	//= _T("State_UTC_PSINCaledonia");//LCQ
CString g_sLangTxt_State_UTC_PSINCaledonia; //  = _T("(UTC+11:00)所罗门群岛,新喀里多尼亚");

CString g_sLangID_State_UTC_PTwelveFiji;  //= _T("State_UTC_PTwelveFiji");//LCQ
CString g_sLangTxt_State_UTC_PTwelveFiji; // = _T("(UTC+12:00)斐济");

CString g_sLangID_Gradient_CurbanksatleastTwo;	//= _T("Gradient_CurbanksatleastTwo");//LCQ
CString g_sLangTxt_Gradient_CurbanksatleastTwo; // = _T("当前电流组数为(%ld),至少需要2组电流才能进行差流计算.");

CString g_sLangID_Gradient_CurselinNotFound;  //= _T("Gradient_CurselinNotFound");//LCQ
CString g_sLangTxt_Gradient_CurselinNotFound; // = _T("当前选择的递变通道(Index=%d)未查找到.");

CString g_sLangID_Gradient_CurinDCincrement;  //= _T("Gradient_CurinDCincrement");//LCQ
CString g_sLangTxt_Gradient_CurinDCincrement; //= _T("当前为直流输出模式,不可切换为频率递变.");

CString g_sLangID_Gradient_NoteThepthanoneus;  //= _T("Gradient_NoteThepthanoneus");//LCQ
CString g_sLangTxt_Gradient_NoteThepthanoneus; //  = _T("备注:规程要求测试时间1分钟，最大对时误差不大于1μs.");

CString g_sLangID_Gradient_NoteThepthanfourus;	//= _T("Gradient_NoteThepthanfourus");//LCQ
CString g_sLangTxt_Gradient_NoteThepthanfourus; // = _T("备注:规程要求测试时间10分钟，最大守时误差不大于4μs.");

CString g_sLangID_Gradient_InPPSfreemodevaluecontrolblock;	//= _T("Gradient_InPPSfreemodevaluecontrolblock");
CString g_sLangTxt_Gradient_InPPSfreemodevaluecontrolblock; //  = _T("无PPS模式下,需要先进行报文探测,选择对应采样值控制块.");//LCQ

CString g_sLangID_Gradient_GOOSEreleaseDataStatusIsempty;  //= _T("Gradient_GOOSEreleaseDataStatusIsempty");
CString g_sLangTxt_Gradient_GOOSEreleaseDataStatusIsempty; //= _T("当前状态(%d)的GOOSE发布数据为空(出现异常).");//LCQ

CString g_sLangID_Gradient_MaintainatLeastOneState;	 //= _T("Gradient_MaintainatLeastOneState");//LCQ
CString g_sLangTxt_Gradient_MaintainatLeastOneState; //= _T("至少保留一个状态.");

CString g_sLangID_Gradient_Intotalcheckarow;  //= _T("Gradient_Intotalcheckarow");//LCQ
CString g_sLangTxt_Gradient_Intotalcheckarow; //= _T("总计只能选择%d次谐波，假如想选择当前次谐波，需要取消勾选一行.");

CString g_sLangID_Gradient_TheUsedfordebuggingNOexist;	//= _T("Gradient_TheUsedfordebuggingNOexist");//LCQ
CString g_sLangTxt_Gradient_TheUsedfordebuggingNOexist; //= _T("调试使用的配置文件(%s)不存在.");

CString g_sLangID_Gradient_FailedTestParameterfile;	 //= _T("Gradient_FailedTestParameterfile");//LCQ
CString g_sLangTxt_Gradient_FailedTestParameterfile; // = _T("解析功能测试参数文件【%s】失败");

CString g_sLangID_Gradient_MissingDefaultMappings;	//= _T("Gradient_MissingDefaultMappings");//LCQ
CString g_sLangTxt_Gradient_MissingDefaultMappings; //= _T("缺少硬件资源文件,无法创建缺省通道映射.");

CString g_sLangID_Gradient_FailDefaultPath;	 //= _T("Gradient_FailDefaultPath");//LCQ
CString g_sLangTxt_Gradient_FailDefaultPath; // = _T("创建通道映射缺省路径失败.");

CString g_sLangID_Gradient_ExportfileSucceeded;	 //= _T("Gradient_ExportfileSucceeded");//LCQ
CString g_sLangTxt_Gradient_ExportfileSucceeded; // = _T("导出通道映射文件[%s]成功");

CString g_sLangID_Gradient_Failedtofile;  //= _T("Gradient_Failedtofile");//LCQ
CString g_sLangTxt_Gradient_Failedtofile; //= _T("导出通道映射文件[%s]失败");

CString g_sLangID_Gradient_TheTesterfileFailedtoload;  //= _T("Gradient_TheTesterfileFailedtoload");//LCQ
CString g_sLangTxt_Gradient_TheTesterfileFailedtoload; //= _T("测试仪硬件信息文件加载失败.");

CString g_sLangID_State_HardwareInformationSettings;  //= _T("State_HardwareInformationSettings");//LCQ
CString g_sLangTxt_State_HardwareInformationSettings; //= _T("硬件信息设置");

CString g_sLangID_Gradient_UnknownCommand;	//= _T("Gradient_UnknownCommand");//LCQ
CString g_sLangTxt_Gradient_UnknownCommand; //= _T("未知的网页报告执行命令(%s).");

CString g_sLangID_State_InVolOutofRange;  //= _T("State_InVolOutofRange");//LCQ
CString g_sLangTxt_State_InVolOutofRange; // = _T("输入的电压超出范围");

CString g_sLangID_State_InCurOutofrange;  // = _T("State_TheInputCurrentisOutofrange");//LCQ
CString g_sLangTxt_State_InCurOutofrange; // = _T("输入的电流超出范围");

CString g_sLangID_State_TheOnepercentHarmonic;	//= _T("State_TheOnepercentHarmonic");//LCQ
CString g_sLangTxt_State_TheOnepercentHarmonic; //= _T("%1次谐波");

CString g_sLangID_State_HarmonicTestTemplatefile;  //= _T("State_HarmonicTestTemplatefile");//LCQ
CString g_sLangTxt_State_HarmonicTestTemplatefile; //= _T("谐波测试模板文件");

CString g_sLangID_State_TBuildDate;	 //= _T("State_TBuildDate");//LCQ
CString g_sLangTxt_State_TBuildDate; // = _T("TestCtrlCntrLinux生成日期");

CString g_sLangID_State_Genexperfile;  //= _T("State_Genexperfile");//LCQ
CString g_sLangTxt_State_Genexperfile; //  = _T("通用试验模板文件");

CString g_sLangID_State_Gooseexfile;  //= _T("State_Gooseexceptionsimulationtemplatefile");//LCQ
CString g_sLangTxt_State_Gooseexfile; //  = _T("Goose异常模拟模板文件");

CString g_sLangID_State_GOOSEmessageparameters;	 //= _T("State_GOOSEmessageparameters");//LCQ
CString g_sLangTxt_State_GOOSEmessageparameters; // = _T("GOOSE报文参数");

CString g_sLangID_State_VersionInformation;	 //= _T("State_VersionInformation");//LCQ
CString g_sLangTxt_State_VersionInformation; // = _T("版本信息");

CString g_sLangID_State_ApplianceProperties;  //= _T("State_ApplianceProperties");//LCQ
CString g_sLangTxt_State_ApplianceProperties; // = _T("装置属性");

CString g_sLangID_State_AppNumber;	//= _T("State_AppNumber");//LCQ
CString g_sLangTxt_State_AppNumber; //= _T("编号:");

CString g_sLangID_State_ModuleManagement;  //= _T("State_RearAcceleration");//LCQ
CString g_sLangTxt_State_ModuleManagement; // = _T("模块管理");

CString g_sLangID_State_TheEdgeElementType; //"边元素类型"
CString g_sLangTxt_State_TheEdgeElementType;

CString g_sLangID_State_ErrorBandLength;  // = _T("State_ErrorBandLength");//LCQ
CString g_sLangTxt_State_ErrorBandLength; // = _T("误差带长度");

CString g_sLangID_State_EdgeTestPoints;	 //= _T("State_EdgeTestPoints");//LCQ
CString g_sLangTxt_State_EdgeTestPoints; // = _T("边测试点数");

CString g_sLangID_Gradient_Functionalfiledtexist;  //= _T("Gradient_Functionalfiledtexist");//LCQ
CString g_sLangTxt_Gradient_Functionalfiledtexist; // = _T("功能测试参数文件【%s】不存在");

CString g_sLangID_Gradient_Inverse;	 //= _T("Gradient_Inverse");//LCQ
CString g_sLangTxt_Gradient_Inverse; //= _T("反选");

CString g_sLangID_State_UTC_SevenCLM;
CString g_sLangTxt_State_UTC_SevenCLM;

CString g_sLangID_State_UTC_ElevenCUTime;
CString g_sLangTxt_State_UTC_ElevenCUTime;

CString g_sLangID_State_EnterTheValueoutofRange;
CString g_sLangTxt_State_EnterTheValueoutofRange;

CString g_sLangID_State_LowVoltageprotection; // 低压保护
CString g_sLangTxt_State_LowVoltageprotection;

CString g_sLangID_State_Overvoltageprotection; // 过压保护
CString g_sLangTxt_State_Overvoltageprotection;

CString g_sLangID_State_startingPointR; // 起始点-R
CString g_sLangTxt_State_startingPointR;
// 起始点-X
CString g_sLangID_State_startingPointX;
CString g_sLangTxt_State_EdgeTestPointX;
// 终止点-R
CString g_sLangID_State_EndPointR;
CString g_sLangTxt_State_EndPointR;
// 终止点-X
CString g_sLangID_State_EndPointX;
CString g_sLangTxt_State_EndPointX;
// 方向
CString g_sLangID_State_Direction;
CString g_sLangTxt_State_Direction;
// 正向到达
CString g_sLangID_State_PositiveArrival;
CString g_sLangTxt_State_PositiveArrival;
// 角度
CString g_sLangID_State_ANgle;
CString g_sLangTxt_State_ANgle;
// 偏移
CString g_sLangID_State_Offset;
CString g_sLangTxt_State_Offset;
// 宽度
CString g_sLangID_State_Width;
CString g_sLangTxt_State_Width;
// x-圆心
CString g_sLangID_State_CenterX;
CString g_sLangTxt_State_CenterX;
// y-圆心
CString g_sLangID_State_CenterY;
CString g_sLangTxt_State_CenterY;
// 半径
CString g_sLangID_State_Radius;
CString g_sLangTxt_State_Radius;
// 起始角度
CString g_sLangID_State_StartingAngle;
CString g_sLangTxt_State_StartingAngle;
// 终止角度
CString g_sLangID_State_TerminationAngle;
CString g_sLangTxt_State_TerminationAngle;
// 时钟方向
CString g_sLangID_State_ClockDirection;
CString g_sLangTxt_State_ClockDirection;

CString g_sLangID_State_IEEECurset;	 //= _T("State_IEEECurset");//LCQ
CString g_sLangTxt_State_IEEECurset; // = _T("IEEE曲线参数设置");

CString g_sLangID_State_IACCurSet;	// = _T("State_IACCurSet");//LCQ
CString g_sLangTxt_State_IACCurSet; // = _T("IAC曲线参数设置");

CString g_sLangID_State_I2TCurSet;	// = _T("State_I2TCurSet");//LCQ
CString g_sLangTxt_State_I2TCurSet; // = _T("I2T曲线参数设置");

CString g_sLangID_State_IECCurSet;	//= _T("State_IECCurveParameterSettings");//LCQ
CString g_sLangTxt_State_IECCurSet; // = _T("IEC曲线参数设置");

CString g_sLangID_State_VolLimitSet;  // = _T("State_VolLimitSet");//LCQ
CString g_sLangTxt_State_VolLimitSet; //  = _T("电压反时限参数设置");

CString g_sLangID_State_Harmonicwave;  //= _T("State_Harmonicwave");//LCQ
CString g_sLangTxt_State_Harmonicwave; // = _T("谐波");

CString g_sLangID_Gradient_VActionValue;  //= _T("Gradient_VActionValue");//LCQ
CString g_sLangTxt_Gradient_VActionValue; //= _T("电压动作值(V)");

CString g_sLangID_Gradient_CActionValue;  //= _T("Gradient_CActionValue");//LCQ
CString g_sLangTxt_Gradient_CActionValue; //= _T("电流动作值(A)");

CString g_sLangID_Gradient_ReCoefficient;  //= _T("Gradient_ReCoefficient");//LCQ
CString g_sLangTxt_Gradient_ReCoefficient; //= _T("返回系数");

CString g_sLangID_Gradient_FirBoundAngle;  //= _T("Gradient_FirBoundAngle");//LCQ
CString g_sLangTxt_Gradient_FirBoundAngle; //= _T("边界角1(°)");

CString g_sLangID_Gradient_SecBoundAngle;  //= _T("Gradient_SecBoundAngle");//LCQ
CString g_sLangTxt_Gradient_SecBoundAngle; //= _T("边界角2(°)");

CString g_sLangID_Gradient_MaxSenAngle;	 //= _T("Gradient_MaxSenAngle");//LCQ
CString g_sLangTxt_Gradient_MaxSenAngle; //= _T("最大灵敏角(°)");

CString g_sLangID_Gradient_FreAction;  //= _T("Gradient_FreAction");//LCQ
CString g_sLangTxt_Gradient_FreAction; //= _T("动作频率(Hz)");

CString g_sLangID_Gradient_PhaseAValue;	 //= _T("Gradient_PhaseAValue");//LCQ
CString g_sLangTxt_Gradient_PhaseAValue; //= _T("相位动作值(°)");

CString g_sLangID_Gradient_ImpAValue;	 //= _T("Gradient_ImpeAValue");
CString g_sLangTxt_Gradient_ImpAValue; //= _T("阻抗动作值(Ω)");

CString g_sLangID_Gradient_TestTeach; // 测试教学 lcq
CString g_sLangTxt_Gradient_TestTeach;

CString g_sLangID_Gradient_ReportHeader;  //= _T("Gradient_ReportHeader");//LCQ;
CString g_sLangTxt_Gradient_ReportHeader; //= _T("报告头信息");

CString g_sLangID_Gradient_TestTempSusCom;	// = _T("Gradient_TestTempSusCom");//LCQ;
CString g_sLangTxt_Gradient_TestTempSusCom; //  = _T("下发保存测试模板(%s%s)命令成功.");

CString g_sLangID_Gradient_TestTempDefCom;	//  = _T("Gradient_TestTempDefCom");//LCQ;
CString g_sLangTxt_Gradient_TestTempDefCom; //  = _T("下发保存测试模板(%s%s)命令失败.");

CString g_sLangID_Gradient_SavePageSus;	 // = _T("Gradient_SavePageSus");//LCQ;
CString g_sLangTxt_Gradient_SavePageSus; // = _T("保存网页模板文件(%s%s)成功.");

CString g_sLangID_Gradient_TestRecordSus;  // = _T("Gradient_TestRecordSus");//LCQ;
CString g_sLangTxt_Gradient_TestRecordSus; //  = _T("下发保存测试记录(%s%s)命令成功.");

CString g_sLangID_Gradient_TestRecordFai;  //  = _T("Gradient_TestRecordFai");//LCQ;
CString g_sLangTxt_Gradient_TestRecordFai; //  = _T("下发保存测试记录(%s%s)命令失败.");

CString g_sLangID_Gradient_SaveReportSus;  //  = _T("Gradient_SaveReportSus");//LCQ;
CString g_sLangTxt_Gradient_SaveReportSus; //  = _T("保存报告文件(%s%s)成功.");

CString g_sLangID_Gradient_SameeXist;  //= _T("Gradient_SameeXist");//LCQ;
CString g_sLangTxt_Gradient_SameeXist; // = _T("路径(%s)下存在同名的文件,请修改文件名.");

CString g_sLangID_Gradient_ModuleType;	//= _T("Gradient_ModuleType");//LCQ;
CString g_sLangTxt_Gradient_ModuleType; //= _T("模块类型");

CString g_sLangID_Gradient_LocNumber;  // = _T("Gradient_LocNumber");//LCQ;
CString g_sLangTxt_Gradient_LocNumber; // = _T("位置号");

CString g_sLangID_Gradient_ModuleVersion;  //  = _T("Gradient_ModuleVersion");//LCQ;
CString g_sLangTxt_Gradient_ModuleVersion; // = _T("模块版本");

CString g_sLangID_Gradient_ManufactDate;  // = _T("Gradient_ManufactDate");//LCQ;
CString g_sLangTxt_Gradient_ManufactDate; // = _T("生产日期");

//
// CString g_sLangID_Gradient_InstrumentName;         //= _T("Gradient_InstrumentName");//LCQ;
// CString g_sLangTxt_Gradient_InstrumentName;        //= _T("仪器名称");
//
// CString g_sLangID_Gradient_BoardVersion;         //= _T("Gradient_BoardVersion");//LCQ;
// CString g_sLangTxt_Gradient_BoardVersion;        //= _T("主板版本");
//
// CString g_sLangID_Gradient_DriverVersion;         //= _T("Gradient_DriverVersion");//LCQ;
// CString g_sLangTxt_Gradient_DriverVersion;        //= _T("驱动版本");
//
// CString g_sLangID_Gradient_TestSVersion;         //= _T("Gradient_TestSVersion");//LCQ;
// CString g_sLangTxt_Gradient_TestSVersion;       // = _T("TestServer版本");
//
// CString g_sLangID_Gradient_LinuxBDate;        // = _T("Gradient_LinuxBDate");//LCQ;
// CString g_sLangTxt_Gradient_LinuxBDate;       // = _T("Linux生成日期");
//
// CString g_sLangID_Gradient_MboardsNumIn;        // = _T("Gradient_MboardsNumIn");//LCQ;
// CString g_sLangTxt_Gradient_MboardsNumIn;       // = _T("主板开入数量（个）");
//
// CString g_sLangID_Gradient_MboardsNumOut;        // = _T("Gradient_MboardsNumOut");//LCQ;
// CString g_sLangTxt_Gradient_MboardsNumOut;       // = _T("主板开出数量（个）");
//
// CString g_sLangID_Gradient_AAcompensation;       //  = _T("Gradient_AAcompensation");//LCQ;
// CString g_sLangTxt_Gradient_AAcompensation;       // = _T("模拟量绝对相位补偿(度)");
//
// CString g_sLangID_Gradient_SsCapacity;        // = _T("Gradient_SsCapacity");//LCQ;
// CString g_sLangTxt_Gradient_SsCapacity;       // = _T("状态序列容量");
//
// CString g_sLangID_Gradient_TestSName;        // = _T("Gradient_TestSName");//LCQ;
// CString g_sLangTxt_Gradient_TestSName;       // = _T("TestServer名称");
//
// CString g_sLangID_Gradient_DriverName;         //= _T("Gradient_DriverName");//LCQ;
// CString g_sLangTxt_Gradient_DriverName;       // = _T("驱动名称");
//
// CString g_sLangID_Gradient_ModLocation;         //= _T("Gradient_ModLocation");//LCQ;
// CString g_sLangTxt_Gradient_ModLocation;        //= _T("模块位置");
//
// CString g_sLangID_Gradient_HarmonicsNum;        // = _T("Gradient_HarmonicsNum");//LCQ;
// CString g_sLangTxt_Gradient_HarmonicsNum;       // = _T("谐波数");
//
// CString g_sLangID_Gradient_DCVolChaMax;        // = _T("Gradient_DCVolChaMax");//LCQ;
// CString g_sLangTxt_Gradient_DCVolChaMax;       // = _T("直流电压通道最大值");
//
// CString g_sLangID_Gradient_DCCurChaMax;       //  = _T("Gradient_DCCurChaMax");//LCQ;
// CString g_sLangTxt_Gradient_DCCurChaMax;       // = _T("直流电流通道最大值");
//
// CString g_sLangID_Gradient_ACChanMax;        // = _T("Gradient_ACChanMax");//LCQ;
// CString g_sLangTxt_Gradient_ACChanMax;       // = _T("通道出交流最大值");
//
// CString g_sLangID_Gradient_DCChanMax;        // = _T("Gradient_DCChanMax");//LCQ;
// CString g_sLangTxt_Gradient_DCChanMax;       // = _T("通道出直流最大值");
//
// CString g_sLangID_Gradient_FreComFactor;       // = _T("Gradient_FreComFactor");//LCQ;
// CString g_sLangTxt_Gradient_FreComFactor;      //  = _T("频率补偿系数");
//
// CString g_sLangID_Gradient_DigDeLHardware;      //   = _T("Gradient_DigDeLHardware");//LCQ;
// CString g_sLangTxt_Gradient_DigDeLHardware;      //  = _T("数字硬件相位延时");
//
// CString g_sLangID_Gradient_VCHardware;        // = _T("Gradient_VCHardware");//LCQ;
// CString g_sLangTxt_Gradient_VCHardware;       // = _T("电压电流硬件特性");
//
// CString g_sLangID_Gradient_CCcoalescing ;        //= _T("Gradient_CCcoalescing");//LCQ;
// CString g_sLangTxt_Gradient_CCcoalescing;       // = _T("电流通道合并模式");

// CString g_sLangID_Gradient_FirSwitchoPen;        // = _T("Gradient_FirSwitchoPen");//LCQ;
// CString g_sLangTxt_Gradient_FirSwitchoPen;       // = _T("第一组开关量配为开入");
//
// CString g_sLangID_Gradient_SecSwitchoPen;       //  = _T("Gradient_SecSwitchoPen");//LCQ;
// CString g_sLangTxt_Gradient_SecSwitchoPen;       // = _T("第二组开关量配为开入");
//
// CString g_sLangID_Gradient_ThirSwitchoPen;        // = _T("Gradient_ThirSwitchoPen");//LCQ;
// CString g_sLangTxt_Gradient_ThirSwitchoPen;       // = _T("第三组开关量配为开入");
//
// CString g_sLangID_Gradient_FourSwitchoPen;        // = _T("Gradient_FourSwitchoPen");//LCQ;
// CString g_sLangTxt_Gradient_FourSwitchoPen;      //  = _T("第四组开关量配为开入");
//
// CString g_sLangID_Gradient_FPGAVersion;        // = _T("Gradient_FPGAVersion");//LCQ;
// CString g_sLangTxt_Gradient_FPGAVersion;       // = _T("模块FPGA版本");
//
// CString g_sLangID_Gradient_ModproVersion;         //= _T("Gradient_ModproVersion");//LCQ;
// CString g_sLangTxt_Gradient_ModproVersion;        //= _T("模块属性版本");

// CString g_sLangID_Gradient_BodianEleCor;         //= _T("Gradient_BodianEleCor");//LCQ;
// CString g_sLangTxt_Gradient_BodianEleCor;        //= _T("北京博电新力电气股份有限公司");
//
// CString g_sLangID_Gradient_SCDfile;         //= _T("Gradient_SCDfile");//LCQ;
// CString g_sLangTxt_Gradient_SCDfile;        //= _T("SCD文件");
//
// CString g_sLangID_Gradient_TemplateFile;        // = _T("Gradient_TemplateFile");//LCQ;
// CString g_sLangTxt_Gradient_TemplateFile;        //= _T("模板文件");
//
// CString g_sLangID_Gradient_ScreenFolder;       //  = _T("Gradient_ScreenFolder");//LCQ;
// CString g_sLangTxt_Gradient_ScreenFolder;       // = _T("截屏文件夹");
//
// CString g_sLangID_Gradient_SaveCast;        // = _T("Gradient_SaveCast");//LCQ;
// CString g_sLangTxt_Gradient_SaveCast;       // = _T("保存截屏图片");
//
// CString g_sLangID_Gradient_OtherTypeFile;        // = _T("Gradient_OtherTypeFile");//LCQ;
// CString g_sLangTxt_Gradient_OtherTypeFile;       // = _T("其他类型文件");

CString g_sLangID_Gradient_LocalNICIP;	// = _T("Gradient_LocalNICIP");//LCQ;
CString g_sLangTxt_Gradient_LocalNICIP; //  = _T("本地网卡IP");

CString g_sLangID_Gradient_PrimaryIP;  // = _T("Gradient_PrimaryIP");//LCQ;
CString g_sLangTxt_Gradient_PrimaryIP; // = _T("主IP地址");

CString g_sLangID_Gradient_CurGSetting;	 //= _T("Gradient_CurGSetting");//LCQ;
CString g_sLangTxt_Gradient_CurGSetting; //= _T("电流档位设置:");

CString g_sLangID_Gradient_HighCurPort;	 //= _T("Gradient_HighCurPort");//LCQ;
CString g_sLangTxt_Gradient_HighCurPort; //= _T("大电流输出端口:");

CString g_sLangID_Gradient_FirstFile;  //= _T("Gradient_FirstFile");//LCQ;
CString g_sLangTxt_Gradient_FirstFile; //= _T("1档(0.2Ω/10A)");

CString g_sLangID_Gradient_SecondFile;	//= _T("Gradient_SecondFile");//LCQ;
CString g_sLangTxt_Gradient_SecondFile; //= _T("2档(0.3Ω/10A)");

CString g_sLangID_Gradient_ThirdFile;  //= _T("Gradient_ThirdFile");//LCQ;
CString g_sLangTxt_Gradient_ThirdFile; //= _T("3档(0.7Ω/10A)");

//"1档(0.3Ω/10A)" lcq
CString g_sLangID_Currentlevel1;
CString g_sLangTxt_Currentlevel1;
//"2档(0.7Ω/10A)" lcq
CString g_sLangID_Currentlevel2;
CString g_sLangTxt_Currentlevel2;
//"3档(1.5Ω/10A)" lcq
CString g_sLangID_Currentlevel3;
CString g_sLangTxt_Currentlevel3;

CString g_sLangID_Gradient_ShotScreenSus;  // = _T("Gradient_ShotScreenSus");//LCQ;
CString g_sLangTxt_Gradient_ShotScreenSus; // = _T("截屏成功.");

CString g_sLangID_Gradient_IECConfiguration;  //= _T("Gradient_IECConfiguration");//LCQ;
CString g_sLangTxt_Gradient_IECConfiguration; //= _T("IEC配置");

CString g_sLangID_Gradient_MessageType; //"报文类型"
CString g_sLangTxt_Gradient_MessageType;

CString g_sLangID_Gradient_SCLPars; // SCL解析界面 SCL parsing interface
CString g_sLangTxt_Gradient_SCLPars;

CString g_sLangID_Gradient_VoltageSet;	//= _T("Gradient_VoltageSet");//LCQ;
CString g_sLangTxt_Gradient_VoltageSet; // = _T("电压设置");

CString g_sLangID_Gradient_CurrentSet;	// = _T("Gradient_CurrentSet");//LCQ;
CString g_sLangTxt_Gradient_CurrentSet; //= _T("电流设置");

CString g_sLangID_Gradient_FailedGfp; //"获取文件路径失败(%s)."
CString g_sLangTxt_Gradient_FailedGfp;

CString g_sLangID_Gradient_FailedTof; //"打开文件失败(%s)."
CString g_sLangTxt_Gradient_FailedTof;

CString g_sLangID_Gradient_FailedCwf; //"[%s]创建写文件失败."
CString g_sLangTxt_Gradient_FailedCwf;

CString g_sLangID_Gradient_FileIsize; //"文件[%s]大小为(%ld)."
CString g_sLangTxt_Gradient_FileIsize;

CString g_sLangID_Gradient_FailedTRlfile; //"读取指定长度的大文件内容失败."
CString g_sLangTxt_Gradient_FailedTRlfile;

CString g_sLangID_Gradient_FileNoexist; //"文件不存在(%s)."
CString g_sLangTxt_Gradient_FileNoexist;

CString g_sLangID_Gradient_FreAValue; // 频率动作值(Hz)
CString g_sLangTxt_Gradient_FreAValue;

CString g_sLangID_Gradient_ReleasedFTT; //"FT3发布"
CString g_sLangTxt_Gradient_ReleasedFTT;

CString g_sLangID_Gradient_CurSmvErr; //"当前SMVFT3通道映射出错(%s)."
CString g_sLangTxt_Gradient_CurSmvErr;

CString g_sLangID_Gradient_ExIEDdescrip; //"外部IED描述"
CString g_sLangTxt_Gradient_ExIEDdescrip;

CString g_sLangID_Gradient_ParseLFile; //"解析文件("
CString g_sLangTxt_Gradient_ParseLFile;

CString g_sLangID_Gradient_SCLNoSel; //")不存在,无法进行SCL选择切换."
CString g_sLangTxt_Gradient_SCLNoSel;

CString g_sLangID_Gradient_NoParObjRisk; //"当前表格数据链表无父对象,删除当前行数据失败,存在内存泄漏风险."
CString g_sLangTxt_Gradient_NoParObjRisk;

CString g_sLangID_Gradient_FailType; //"故障类型"
CString g_sLangTxt_Gradient_FailType;

CString g_sLangID_Gradient_FailDirect; //"故障方向"
CString g_sLangTxt_Gradient_FailDirect;

CString g_sLangID_Gradient_FailTime; //"故障时间"
CString g_sLangTxt_Gradient_FailTime;

CString g_sLangID_Gradient_Slope; //"斜率"
CString g_sLangTxt_Gradient_Slope;

CString g_sLangID_Gradient_StartTs; //"启动门槛"  "Threshold for starting"
CString g_sLangTxt_Gradient_StartTs;

CString g_sLangID_Gradient_StartCur; //"启动电流"
CString g_sLangTxt_Gradient_StartCur;

CString g_sLangID_Gradient_Inflectp; // 拐点 point of inflection
CString g_sLangTxt_Gradient_Inflectp;

CString g_sLangID_Gradient_DiffFlowEx; //"差流极值" "Differential Flow Extremum"
CString g_sLangTxt_Gradient_DiffFlowEx;

CString g_sLangID_Gradient_AddCusp; //"添加自定义点" Add Custom Point
CString g_sLangTxt_Gradient_AddCusp;

CString g_sLangID_Gradient_Emptycusp; // 清空自定义点 "Empty Custom Points"
CString g_sLangTxt_Gradient_Emptycusp;

CString g_sLangID_Gradient_NoLessCor; //"差流极值设置不能小于拐点电流对应差流值."
CString g_sLangTxt_Gradient_NoLessCor;

CString g_sLangID_Gradient_RatioDiff; // 比率差动
CString g_sLangTxt_Gradient_RatioDiff;

CString g_sLangID_Gradient_Custestp; //"自定义测试点"
CString g_sLangTxt_Gradient_Custestp;

CString g_sLangID_Gradient_Impedance; // 阻抗表达方式
CString g_sLangTxt_Gradient_Impedance;

CString g_sLangID_Gradient_SelectCur; // 请先选择需要删除的特性曲线
CString g_sLangTxt_Gradient_SelectCur;

CString g_sLangID_Gradient_CurveEditing; //"曲线编辑" Curve Editing
CString g_sLangTxt_Gradient_CurveEditing;

CString g_sLangID_Gradient_InsertElement; //"插入元素"
CString g_sLangTxt_Gradient_InsertElement;

CString g_sLangID_Gradient_ModifyElement; //"修改元素"
CString g_sLangTxt_Gradient_ModifyElement;

CString g_sLangID_Gradient_DeleteElement; //"删除元素"
CString g_sLangTxt_Gradient_DeleteElement;

CString g_sLangID_Gradient_PInitial; //"+:初始"
CString g_sLangTxt_Gradient_PInitial;

CString g_sLangID_Gradient_PSelected; //"+:选中"
CString g_sLangTxt_Gradient_PSelected;

CString g_sLangID_Gradient_EndTrial; //"+:试验结束"
CString g_sLangTxt_Gradient_EndTrial;

CString g_sLangID_Gradient_UnUpdateGraph; //"特性曲线查找失败(strCharaID=%s;strIndex=%s),无法更新曲线图"
CString g_sLangTxt_Gradient_UnUpdateGraph;

CString g_sLangID_Gradient_YNWirBlancer;  //= _T("Gradient_YNWirBlancer");  //LCQ
CString g_sLangTxt_Gradient_YNWirBlancer; // = _T("Y/V接线平衡变压器");

CString g_sLangID_Gradient_YNoCorners;	// = _T("Gradient_YNoCorners");  //LCQ
CString g_sLangTxt_Gradient_YNoCorners; // = _T("Y/△-11接线(无转角)");

CString g_sLangID_Gradient_Sphase;	//= _T("Gradient_Sphase");  //LCQ
CString g_sLangTxt_Gradient_Sphase; //= _T("单相变压器");

CString g_sLangID_Gradient_YDSCornect;	//= _T("Gradient_YDSCornect");  //LCQ
CString g_sLangTxt_Gradient_YDSCornect; //= _T("Y/△/△接线");

CString g_sLangID_Gradient_ImpedanceMB;	 //= _T("Gradient_ImpedanceMB");  //LCQ
CString g_sLangTxt_Gradient_ImpedanceMB; //= _T("Y/A 接线阻抗匹配平衡变压器");

CString g_sLangID_Gradient_ThrVWirceTF;	 // = _T("Gradient_ThrVWirceTF");  //LCQ
CString g_sLangTxt_Gradient_ThrVWirceTF; // = _T("三相V/V接线变压器");

CString g_sLangID_Gradient_SecThrVWirceTF;	//= _T("Gradient_SecThrVWirceTF");  //LCQ
CString g_sLangTxt_Gradient_SecThrVWirceTF; //= _T("三相V/V接线变压器2");

CString g_sLangID_Gradient_YSideCorner;	 // = _T("Gradient_YSideCorner");  //LCQ
CString g_sLangTxt_Gradient_YSideCorner; //= _T("Y/△-11接线(Y侧转角)");

CString g_sLangID_Gradient_VThrPhase;  //= _T("Gradient_VThrPhase");  //LCQ
CString g_sLangTxt_Gradient_VThrPhase; //= _T("三相V/V");

CString g_sLangID_Gradient_IRCurrent;  //= _T("Gradient_IRCurrent");  //LCQ
CString g_sLangTxt_Gradient_IRCurrent; //= _T("基准电流(Ie)");

CString g_sLangID_Gradient_ARCurrent;  //= _T("Gradient_ARCurrent");  //LCQ
CString g_sLangTxt_Gradient_ARCurrent; //= _T("基准电流(A)");

CString g_sLangID_Gradient_ActionTime;	//= _T("Gradient_ActionTime ");  //LCQ
CString g_sLangTxt_Gradient_ActionTime; //= _T("动作时间");

CString g_sLangID_Gradient_JumpA; //" 跳  A "
CString g_sLangTxt_Gradient_JumpA;

CString g_sLangID_Gradient_JumpB; //" 跳  B "
CString g_sLangTxt_Gradient_JumpB;

CString g_sLangID_Gradient_JumpC; //" 跳  C "
CString g_sLangTxt_Gradient_JumpC;

CString g_sLangID_Gradient_Jjump; // 跳
CString g_sLangTxt_Gradient_Jjump;

CString g_sLangID_Gradient_CurPhaseErr; //"当前相位值越限出错(%f)."
CString g_sLangTxt_Gradient_CurPhaseErr;

CString g_sLangID_Gradient_Setting; //"设置"
CString g_sLangTxt_Gradient_Setting;

CString g_sLangID_Gradient_FT3CurChanErr; //"当前FT3通道映射出错(%s)."
CString g_sLangTxt_Gradient_FT3CurChanErr;

CString g_sLangID_Gradient_OpticalPower; //"光功率" "Optical Power"
CString g_sLangTxt_Gradient_OpticalPower;

CString g_sLangID_Gradient_POpticalPort; //"光口%d"
CString g_sLangTxt_Gradient_POpticalPort;

CString g_sLangID_Gradient_FOpticalPower; //"光功率(-dbm)"
CString g_sLangTxt_Gradient_FOpticalPower;

CString g_sLangID_Gradient_FmFileName; //"文件名称："
CString g_sLangTxt_Gradient_FmFileName;

CString g_sLangID_Gradient_DirectoryFile; //"文件目录：""File directory:"
CString g_sLangTxt_Gradient_DirectoryFile;

CString g_sLangID_Gradient_SecondaryIPSet; //"辅助IP设置" "Secondary IP Settings"
CString g_sLangTxt_Gradient_SecondaryIPSet;

CString g_sLangID_Gradient_IPInputInvalid; //"IP输入不合法" "IP input is invalid"
CString g_sLangTxt_Gradient_IPInputInvalid;

CString g_sLangID_Gradient_VAOnceValue; //"一次值(V/A)"
CString g_sLangTxt_Gradient_VAOnceValue;

CString g_sLangID_Gradient_VATwiceValue; //"二次值(V/A)"
CString g_sLangTxt_Gradient_VATwiceValue;

CString g_sLangID_Gradient_SameThreep; //"三相相同" The three phases are the same
CString g_sLangTxt_Gradient_SameThreep;

CString g_sLangID_Gradient_AllSamep; //"全部相同"
CString g_sLangTxt_Gradient_AllSamep;

CString g_sLangID_Gradient_DPhase; //"相位(°)"
CString g_sLangTxt_Gradient_DPhase;

CString g_sLangID_Gradient_FRelCurempty; //"当前状态(%d)的FT3发布数据为空(出现异常)."
CString g_sLangTxt_Gradient_FRelCurempty;

CString g_sLangID_Gradient_EmptyCurTI; //"当前测试项为空."
CString g_sLangTxt_Gradient_EmptyCurTI;

CString g_sLangID_Gradient_ClosePerTBF; //"请先关闭网页界面,才能执行工具栏按钮功能."
CString g_sLangTxt_Gradient_ClosePerTBF;

CString g_sLangID_Gradient_WaitSASD; //"等待测试服务停止后关闭."
CString g_sLangTxt_Gradient_WaitSASD;

CString g_sLangID_Gradient_INUnSavescreen; //"保存截屏(%s)(isNull)失败."
CString g_sLangTxt_Gradient_INUnSavescreen;

CString g_sLangID_Gradient_UnSavescreen; //"保存截屏(%s)(save)失败."
CString g_sLangTxt_Gradient_UnSavescreen;

CString g_sLangID_Gradient_Savescreen;
CString g_sLangTxt_Gradient_Savescreen; // 保存截屏(%s)成功.

CString g_sLangID_Gradient_Selectleg; //"请在测试项目树形控件中选择合法的项目分类"
CString g_sLangTxt_Gradient_Selectleg;

CString g_sLangID_Gradient_CLoseMMChanges;
CString g_sLangTxt_Gradient_CLoseMMChanges; //"?????????????? OnCmd_NewTest: 关闭打开的测试功能页面，并弹框提示是否保存修改 ???????????"

CString g_sLangID_Gradient_TemplateErr;
CString g_sLangTxt_Gradient_TemplateErr; //"模板错误！找不到rootnode节点对应的功能界面【%s】"

CString g_sLangID_Gradient_SaveTemplateAs;
CString g_sLangTxt_Gradient_SaveTemplateAs; //"模板另存为"

///////////////////////////////////////////////////////////////////////////////////
CString g_sLangID_Gradient_OpenfileFail; //"打开文件失败"
CString g_sLangTxt_Gradient_OpenfileFail;

CString g_sLangID_Gradient_SendComplete; //"发送完成"
CString g_sLangTxt_Gradient_SendComplete;

CString g_sLangID_Gradient_RecvChannel; //"接收通道设置"
CString g_sLangTxt_Gradient_RecvChannel;

CString g_sLangID_Gradient_RatioPCT; //"PT/CT变比"
CString g_sLangTxt_Gradient_RatioPCT;

CString g_sLangID_Gradient_ControlB; //"请选择控制块"
CString g_sLangTxt_Gradient_ControlB;

CString g_sLangID_Gradient_RecvChannnel; //"接收通道"
CString g_sLangTxt_Gradient_RecvChannnel;

CString g_sLangID_Gradient_ResTimeErr; //"响应时间误差"
CString g_sLangTxt_Gradient_ResTimeErr;

CString g_sLangID_Gradient_MessResTime; //"报文响应时间"
CString g_sLangTxt_Gradient_MessResTime;

CString g_sLangID_Gradient_ChaDelay; // 通道延时
CString g_sLangTxt_Gradient_ChaDelay;

CString g_sLangID_Gradient_MergeUint; //"合并单元测试功能ID()在配置文件中未查找到."
CString g_sLangTxt_Gradient_MergeUint;

CString g_sLangID_Gradient_NAbnormalRes; //"当前选择测试功能异常(%s),导致m_pSttIecRcdFuncInterface==NULL."
CString g_sLangTxt_Gradient_NAbnormalRes;

CString g_sLangID_Gradient_TestDuration; //"测试时长(s):"
CString g_sLangTxt_Gradient_TestDuration;

CString g_sLangID_Gradient_TheCurDelay;
CString g_sLangTxt_Gradient_TheCurDelay; //"当前延时数据为空,清空时间精度结果失败."

CString g_sLangID_Gradient_EmptyRes; //"清空时间精度结果成功."
CString g_sLangTxt_Gradient_EmptyRes;

CString g_sLangID_Gradient_DiffRatio; //"比差(%)"
CString g_sLangTxt_Gradient_DiffRatio;

CString g_sLangID_Gradient_CurNullFa; //"当前数据集为空,清空误差统计结果失败."
CString g_sLangTxt_Gradient_CurNullFa;

CString g_sLangID_Gradient_ZeroDrift; //"零漂"
CString g_sLangTxt_Gradient_ZeroDrift;

CString g_sLangID_Gradient_ValueOutP; //"输出值"
CString g_sLangTxt_Gradient_ValueOutP;

CString g_sLangID_Gradient_PhaseOutP; //"输出相位"
CString g_sLangTxt_Gradient_PhaseOutP;

CString g_sLangID_Gradient_MeasurAmp; //"实测幅值"
CString g_sLangTxt_Gradient_MeasurAmp;

CString g_sLangID_Gradient_ChanDelay; //"通道延时"
CString g_sLangTxt_Gradient_ChanDelay;

CString g_sLangID_Gradient_CompError; //"复合误差" "Composite error"
CString g_sLangTxt_Gradient_CompError;

CString g_sLangID_Gradient_MeaPhase; //"实测相位" Measured phase
CString g_sLangTxt_Gradient_MeaPhase;

CString g_sLangID_Gradient_FrequencyDiff; //"频差" "Frequency difference"
CString g_sLangTxt_Gradient_FrequencyDiff;

CString g_sLangID_Gradient_DetectMessageI; //"报文探测界面" Message Detection Interface
CString g_sLangTxt_Gradient_DetectMessageI;

CString g_sLangID_Gradient_Unrecorded; //"未录波"
CString g_sLangTxt_Gradient_Unrecorded;

CString g_sLangID_Gradient_Appscribed; //"GOOSE控制块(AppID=0X%04X),已添加订阅到光口%ld,无需重复添加."
CString g_sLangTxt_Gradient_Appscribed;

CString g_sLangID_Gradient_SEcontrolSus; //"GOOSE控制块(AppID=0X%04X),添加订阅到光口%ld成功."
CString g_sLangTxt_Gradient_SEcontrolSus;

CString g_sLangID_Gradient_AppscribedFa; //"GOOSE控制块(AppID=0X%04X),已添加发布到光口%ld,无需重复添加."
CString g_sLangTxt_Gradient_AppscribedFa;

CString g_sLangID_Gradient_AppFascribedFa; //"GOOSE控制块(AppID=0X%04X),添加发布到光口%ld成功."
CString g_sLangTxt_Gradient_AppFascribedFa;

CString g_sLangID_Gradient_ModifyTip; //"修改接线提示"
CString g_sLangTxt_Gradient_ModifyTip;

CString g_sLangID_Gradient_WiringTip; // 接线提示
CString g_sLangTxt_Gradient_WiringTip;

CString g_sLangID_Gradient_WirPrompt; // 新建接线提示
CString g_sLangTxt_Gradient_WirPrompt;

CString g_sLangID_Gradient_EnterTips; //"请在此处输入接线提示信息……"
CString g_sLangTxt_Gradient_EnterTips;

CString g_sLangID_Gradient_ClickCTest; //"请按照接线提示信息，完成接线后，点击“完成接线”按钮，继续测试……"
CString g_sLangTxt_Gradient_ClickCTest;

CString g_sLangID_Gradient_CompleteWir; //"完成接线"
CString g_sLangTxt_Gradient_CompleteWir;

CString g_sLangID_Gradient_WirpromptExit; //"存在相同名称的接线提示"
CString g_sLangTxt_Gradient_WirpromptExit;

CString g_sLangID_Gradient_WEditNoChange; //"接线提示信息编辑，未检测到内容发生变化……"
CString g_sLangTxt_Gradient_WEditNoChange;

CString g_sLangID_Gradient_WrongWayrun; //"错误的运行方式！"
CString g_sLangTxt_Gradient_WrongWayrun;

CString g_sLangID_State_Difflowcalculation;
CString g_sLangTxt_State_Difflowcalculation;
CString g_sLangID_State_DiffCurrentA;
CString g_sLangTxt_State_DiffCurrentA;
CString g_sLangID_State_BrakCurrentA;
CString g_sLangTxt_State_BrakCurrentA;
CString g_sLangID_State_Bequation;
CString g_sLangTxt_State_Bequation;
CString g_sLangID_State_CTpolarity;
CString g_sLangTxt_State_CTpolarity;
CString g_sLangID_State_Hsbalancefactor;
CString g_sLangTxt_State_Hsbalancefactor;
CString g_sLangID_State_Lsbalancefactor;
CString g_sLangTxt_State_Lsbalancefactor;
CString g_sLangID_State_Hswindwirtype;
CString g_sLangTxt_State_Hswindwirtype;
CString g_sLangID_State_Lswindwirtype;
CString g_sLangTxt_State_Lswindwirtype;
CString g_sLangID_State_HbdiffAngularwind;
CString g_sLangTxt_State_HbdiffAngularwind;
CString g_sLangID_State_Bfactorcalculation;
CString g_sLangTxt_State_Bfactorcalculation;
CString g_sLangID_State_Oclock;
CString g_sLangTxt_State_Oclock;
CString g_sLangID_State_Correctionselection;
CString g_sLangTxt_State_Correctionselection;
CString g_sLangID_State_Testphase;
CString g_sLangTxt_State_Testphase;
CString g_sLangID_State_FirHVoltageSide;
CString g_sLangTxt_State_FirHVoltageSide;
CString g_sLangID_State_SecHVoltageSide;
CString g_sLangTxt_State_SecHVoltageSide;
CString g_sLangID_State_BFtransformer;
CString g_sLangTxt_State_BFtransformer;
CString g_sLangID_State_OFtransformer;
CString g_sLangTxt_State_OFtransformer;
CString g_sLangID_State_NotconWindconnection;
CString g_sLangTxt_State_NotconWindconnection;
CString g_sLangID_State_ConWindconnection;
CString g_sLangTxt_State_ConWindconnection;
CString g_sLangID_State_Triangulationcorrection;
CString g_sLangTxt_State_Triangulationcorrection;

CString g_sLangID_State_Trans1; // 一侧指向变压器
CString g_sLangTxt_State_Trans1;
CString g_sLangID_State_Trans2;
CString g_sLangTxt_State_Trans2;
CString g_sLangID_State_Winding; // 考虑绕组接线型式
CString g_sLangTxt_State_Winding;

CString g_sLangID_State_NoAdjust; // 无校正
CString g_sLangTxt_State_NoAdjust;

CString g_sLangID_State_YAdjust;
CString g_sLangTxt_State_YAdjust;

CString g_sLangID_State_SettingValue; // 整定值
CString g_sLangTxt_State_SettingValue;

CString g_sLangID_State_Estimate; // 整定及结果评估
CString g_sLangTxt_State_Estimate;
CString g_sLangID_State_InState; // 进入状态
CString g_sLangTxt_State_InState;

// 整定及结果评估 表格

CString g_sLangID_StateEstimate_Start; // 计时起点
CString g_sLangTxt_StateEstimate_State;
CString g_sLangID_StateEstimate_End; // 计时终点
CString g_sLangTxt_StateEstimate_End;
CString g_sLangID_StateEstimate_ErrorType; // 误差类型
CString g_sLangTxt_StateEstimate_ErrorType;
CString g_sLangID_StateEstimate_RelError; // 相对误差
CString g_sLangTxt_StateEstimate_RelError;
CString g_sLangID_StateEstimate_AbsError; // 绝对误差
CString g_sLangTxt_StateEstimate_AbsError;
CString g_sLangID_StateEstimate_SettingValue; // 整定值(s)
CString g_sLangTxt_StateEstimate_SettingValue;
CString g_sLangID_StateEstimate_BinTrigger; // 开入触发
CString g_sLangTxt_StateEstimate_BinTrigger;

CString g_sLangID_StateEstimate_CombinationError; // 组合误差
CString g_sLangTxt_StateEstimate_CombinationError;

CString g_sLangID_StateEstimate_ResultEstimate; // 结果评估
CString g_sLangTxt_StateEstimate_ResultEstimate;

/////

CString g_sLangID_Gradient_VarType;			  //= _T("Gradient_VarType");
CString g_sLangTxt_Gradient_VarType;		  //= _T("变量类型");
CString g_sLangID_Gradient_Phase;			  //= _T("Gradient_Phase");
CString g_sLangTxt_Gradient_Phase;			  //= _T("相位差");
CString g_sLangID_Gradient_VarSet;			  //= _T("Gradient_VarSet");
CString g_sLangTxt_Gradient_VarSet;			  //= _T("变量设置");
CString g_sLangID_Gradient_ChangingSet;		  //= _T("Gradient_ChangingSet");
CString g_sLangTxt_Gradient_ChangingSet;	  //= _T("递变参数设置");
CString g_sLangID_Gradient_UnChangingSet;	  //= _T("Gradient_UnChangingSet");
CString g_sLangTxt_Gradient_UnChangingSet;	  //= _T("非递变通道设置");
CString g_sLangID_Gradient_OtherSet;		  //= _T("Gradient_OtherSet");
CString g_sLangTxt_Gradient_OtherSet;		  //= _T("其他参数");
CString g_sLangID_Gradient_TestResult;		  //= _T("Gradient_TestResult");
CString g_sLangTxt_Gradient_TestResult;		  //= _T("测试结果");
CString g_sLangID_Gradient_Init;			  //= _T("Gradient_Init");
CString g_sLangTxt_Gradient_Init;			  //= _T("变化始值");
CString g_sLangID_Gradient_Finish;			  //= _T("Gradient_Finish");
CString g_sLangTxt_Gradient_Finish;			  //= _T("变化终值");
CString g_sLangID_Gradient_Step;			  //= _T("Gradient_Step");
CString g_sLangTxt_Gradient_Step;			  //= _T("变化步长");
CString g_sLangID_Gradient_Time;			  //= _T("Gradient_Time");
CString g_sLangTxt_Gradient_Time;			  //= _T("故障时间");
CString g_sLangID_Gradient_Direction;		  //= _T("Gradient_Direction");
CString g_sLangTxt_Gradient_Direction;		  //= _T("递变方向");
CString g_sLangID_Gradient_MaxAngle;		  //= _T("Gradient_MaxAngle");
CString g_sLangTxt_Gradient_MaxAngle;		  //= _T("最大灵敏角");
CString g_sLangID_Gradient_Clockwise;		  //= _T("Gradient_Clockwise");
CString g_sLangTxt_Gradient_Clockwise;		  //= _T("顺时针");
CString g_sLangID_Gradient_Anticlockwise;	  //= _T("Gradient_Anticlockwise");
CString g_sLangTxt_Gradient_Anticlockwise;	  //= _T("逆时针");
CString g_sLangID_Gradient_AllFreq;			  //= _T("Gradient_AllFreq");
CString g_sLangTxt_Gradient_AllFreq;		  //= _T("全部频率");
CString g_sLangID_Gradient_TimeBeforeChange;  //= _T("Gradient_TimeBeforeChange");
CString g_sLangTxt_Gradient_TimeBeforeChange; //= _T("变化前时间");
CString g_sLangID_Gradient_TimeBeforeFail;	  //= _T("Gradient_TimeBeforeFail");
CString g_sLangTxt_Gradient_TimeBeforeFail;	  //= _T("脉冲递变复归时间");
CString g_sLangID_Gradient_CurBeforeChange;	  //= _T("Gradient_CurBeforeChange");
CString g_sLangTxt_Gradient_CurBeforeChange;  //= _T("变化前电流");
CString g_sLangID_Gradient_Normal;			  //= _T("Gradient_Normal");
CString g_sLangTxt_Gradient_Normal;			  //= _T("正常态");
CString g_sLangID_Gradient_Failure;			  //= _T("Gradient_Failure");
CString g_sLangTxt_Gradient_Failure;		  //= _T("故障态");
CString g_sLangID_Gradient_ParaSet;			  //= _T("Gradient_ParaSet");
CString g_sLangTxt_Gradient_ParaSet;		  //= _T("参数设置");
CString g_sLangID_Gradient_BoutSet;			  // 开出量设置
CString g_sLangTxt_Gradient_BoutSet;
CString g_sLangID_Gradient_BoutSets; // 更多开出量设置
CString g_sLangTxt_Gradient_BoutSets;
CString g_sLangID_Report_TestChoose;	  //= _T("Report_TestChoose");
CString g_sLangTxt_Report_TestChoose;	  //= _T("内容选择");
CString g_sLangID_Report_TestObjInf;	  //= _T("Report_TestObjInf");
CString g_sLangTxt_Report_TestObjInf;	  //= _T("测试对象信息");
CString g_sLangID_Report_SubInformation;  //= _T("Report_SubInformation");
CString g_sLangTxt_Report_SubInformation; //= _T("变电站信息");
CString g_sLangID_Report_SubName;		  //= _T("Report_SubName");
CString g_sLangTxt_Report_SubName;		  //= _T("变电站名称");
CString g_sLangID_Report_SubAddr;		  //= _T("Report_SubAddr");
CString g_sLangTxt_Report_SubAddr;		  //= _T("变电站地址");
CString g_sLangID_Report_LoopName;		  //= _T("Report_LoopName");
CString g_sLangTxt_Report_LoopName;		  //= _T("回路名称");
CString g_sLangID_Report_LoopAddr;		  //= _T("Report_LoopAddr");
CString g_sLangTxt_Report_LoopAddr;		  //= _T("回路地址");
CString g_sLangID_Report_Tester;		  //= _T("Report_Tester");
CString g_sLangTxt_Report_Tester;		  //= _T("测试人员");
CString g_sLangID_Report_ReportTitle;	  //= _T("Report_ReportTitle");
CString g_sLangTxt_Report_ReportTitle;	  //= _T("报告标题");
CString g_sLangID_Report_DeviceInfor;	  //= _T("Report_DeviceInfor");
CString g_sLangTxt_Report_DeviceInfor;	  //= _T("装置信息");
CString g_sLangID_Report_DeviceName;	  //= _T("Report_DeviceName");
CString g_sLangTxt_Report_DeviceName;	  //= _T("装置名称");
CString g_sLangID_Report_DeviceModel;	  //= _T("Report_DeviceModel");
CString g_sLangTxt_Report_DeviceModel;	  //= _T("装置型号");
CString g_sLangID_Report_DeviceAddr;	  //= _T("Report_DeviceAddr");
CString g_sLangTxt_Report_DeviceAddr;	  //= _T("装置地址");
CString g_sLangID_Report_DeviceFactory;	  //= _T("Report_DeviceFactory");
CString g_sLangTxt_Report_DeviceFactory;  //= _T("生产厂家");

CString g_sLangID_Report_SettingsNO;	 //= _T("Report_SettingsNO");
CString g_sLangTxt_Report_SettingsNO;	 //= _T("定制单编号");
CString g_sLangID_Report_AdditionalInf;	 //= _T("Report_AdditionalInf");
CString g_sLangTxt_Report_AdditionalInf; //= _T("附加信息");
CString g_sLangID_Report_RatedValue;	 //= _T("Report_RatedValue");
CString g_sLangTxt_Report_RatedValue;	 //= _T("额定值");

CString g_sLangID_Report_DUTs;			 //= _T("Report_DUTs");
CString g_sLangTxt_Report_DUTs;			 //= _T("被测装置");
CString g_sLangID_Report_Title;			 //= _T("Report_Title");
CString g_sLangTxt_Report_Title;		 //= _T("报告内容与格式");
CString g_sLangID_Report_Vnom;			 //= _T("Report_Vnom");
CString g_sLangTxt_Report_Vnom;			 //= _T("额定电压");
CString g_sLangID_Report_Vdc;			 //= _T("Report_Vdc");
CString g_sLangTxt_Report_Vdc;			 //= _T("辅助直流");
CString g_sLangID_Report_SureTime;		 //= _T("Report_SureTime");
CString g_sLangTxt_Report_SureTime;		 //= _T("开入防抖时间");
CString g_sLangID_Report_AntiShakeTime;	 //= _T("Report_AntiShakeTime");
CString g_sLangTxt_Report_AntiShakeTime; //= _T("防抖时间");

CString g_sLangID_Report_Vprim;			 //= _T("Report_Vprim");
CString g_sLangTxt_Report_Vprim;		 //= _T("一次侧电压");
CString g_sLangID_Report_Fnom;			 //= _T("Report_Fnom");
CString g_sLangTxt_Report_Fnom;			 //= _T("额定频率");
CString g_sLangID_Report_Iprim;			 //= _T("Report_Iprim");
CString g_sLangTxt_Report_Iprim;		 //= _T("一次侧电流");
CString g_sLangID_Report_TestAppInfor;	 //= _T("Report_TestAppInfor");
CString g_sLangTxt_Report_TestAppInfor;	 //= _T("测试设备信息");
CString g_sLangID_Report_AppModel;		 //= _T("Report_AppModel");
CString g_sLangTxt_Report_AppModel;		 //= _T("型号");
CString g_sLangID_Report_Imax;			 //= _T("Report_Imax");
CString g_sLangTxt_Report_Imax;			 //= _T("电流最大值");
CString g_sLangID_Report_AppSN;			 //= _T("Report_AppSN");
CString g_sLangTxt_Report_AppSN;		 //= _T("序列号");
CString g_sLangID_Report_TestStartTime;	 //= _T("Report_TestStartTime");
CString g_sLangTxt_Report_TestStartTime; //= _T("测试开始时间");
CString g_sLangID_Report_ComPortType;	 //= _T("Report_ComPortType");
CString g_sLangTxt_Report_ComPortType;	 //= _T("通讯口类型");
CString g_sLangID_Report_TestEndTime;	 //= _T("Report_TestEndTime");
CString g_sLangTxt_Report_TestEndTime;	 //= _T("测试终止时间");
CString g_sLangID_Report_Vmax;			 //= _T("Report_Vmax");
CString g_sLangTxt_Report_Vmax;			 //= _T("电压最大值");

CString g_sLangID_ChMaps_AnalogCh;		//= _T("ChMaps_AnalogCh");
CString g_sLangTxt_ChMaps_AnalogCh;		//= _T("模拟量通道");
CString g_sLangID_ChMaps_DigitalCh;		//= _T("ChMaps_DigitalCh");
CString g_sLangTxt_ChMaps_DigitalCh;	//= _T("数字量通道");
CString g_sLangID_ChMaps_WeekCh;		//= _T("ChMaps_WeekCh");
CString g_sLangTxt_ChMaps_WeekCh;		//= _T("弱信号通道");
CString g_sLangID_ChMaps_Analog;		//= _T("ChMaps_Analog");
CString g_sLangTxt_ChMaps_Analog;		//= _T("模拟");
CString g_sLangID_ChMaps_Digital;		//= _T("ChMaps_Digital");
CString g_sLangTxt_ChMaps_Digital;		//= _T("数字");
CString g_sLangID_ChMaps_Week;			//= _T("ChMaps_Week");
CString g_sLangTxt_ChMaps_Week;			//= _T("弱信号");
CString g_sLangID_ChMaps_Title;			//= _T("ChMaps_Title");
CString g_sLangTxt_ChMaps_Title;		//= _T("通道映射设置");
CString g_sLangID_ChMaps_OutputSel;		//= _T("ChMaps_OutputSel");
CString g_sLangTxt_ChMaps_OutputSel;	//= _T("输出类型选择");
CString g_sLangID_ChMaps_DigitalType;	//= _T("ChMaps_DigitalType");
CString g_sLangTxt_ChMaps_DigitalType;	//= _T("数字报文类型");
CString g_sLangID_ChMaps_DefautMaps;	//= _T("ChMaps_DefautMaps");
CString g_sLangTxt_ChMaps_DefautMaps;	//= _T("设置缺省映射");
CString g_sLangID_ChMaps_ImportChMaps;	//= _T("ChMaps_ImportChMaps");
CString g_sLangTxt_ChMaps_ImportChMaps; //= _T("导入通道映射");
CString g_sLangID_ChMaps_ExportChMaps;	//= _T("ChMaps_ExportChMaps");
CString g_sLangTxt_ChMaps_ExportChMaps; //= _T("导出通道映射");
CString g_sLangID_ChMaps_LockMaps;	//= _T("ChMaps_ExportChMaps");
CString g_sLangTxt_ChMaps_LockMaps; //= _T("导出通道映射");

CString g_sLangID_ChMaps_MeasSel;
CString g_sLangTxt_ChMaps_MeasSel;
CString g_sLangID_ChMaps_DigitalMeasType;
CString g_sLangTxt_ChMaps_DigitalMeasType;

CString g_sLangID_IEC_SysParasSet;		 //= _T("IEC_SysParasSet");
CString g_sLangTxt_IEC_SysParasSet;		 //= _T("系统参数设置");
CString g_sLangID_IEC_SysParasConfig;	 //= _T("IEC_SysParasConfig");
CString g_sLangTxt_IEC_SysParasConfig;	 //= _T("系统参数配置");
CString g_sLangID_IEC_IEC_WeakSet;		 //= _T("IEC_IEC_WeakSet");
CString g_sLangTxt_IEC_IEC_WeakSet;		 //= _T("弱信号设置");
CString g_sLangID_IEC_Message;			 //= _T("IEC_Message");
CString g_sLangTxt_IEC_Message;			 //= _T("IEC61850-9-2报文");
CString g_sLangID_IEC_Publish;			 //= _T("IEC_Publish");
CString g_sLangTxt_IEC_Publish;			 //= _T("GOOSE发布");
CString g_sLangID_IEC_Subscription;		 //= _T("IEC_Subscription");
CString g_sLangTxt_IEC_Subscription;	 //= _T("GOOSE订阅");
CString g_sLangID_IEC_OpenConfig;		 //= _T("IEC_OpenConfig");
CString g_sLangTxt_IEC_OpenConfig;		 //= _T("打开配置");
CString g_sLangID_IEC_OpenConfigFile;	 //= _T("IEC_OpenConfigFile");
CString g_sLangTxt_IEC_OpenConfigFile;	 //= _T("打开配置文件");
CString g_sLangID_IEC_ConfigSaveAs;		 //= _T("IEC_ConfigSaveAs");
CString g_sLangTxt_IEC_ConfigSaveAs;	 //= _T("配置另存");
CString g_sLangID_IEC_ConfigFileSaveAs;	 //= _T("IEC_ConfigFileSaveAs");
CString g_sLangTxt_IEC_ConfigFileSaveAs; //= _T("配置文件另存为");
CString g_sLangID_IEC_ImportSCL;		 //= _T("IEC_ImportSCL");
CString g_sLangTxt_IEC_ImportSCL;		 //= _T("导入SCL");
CString g_sLangID_IEC_ImportSCLFile;	 //= _T("IEC_ImportSCLFile");
CString g_sLangTxt_IEC_ImportSCLFile;	 //= _T("导入SCL文件");
CString g_sLangID_IEC_SaveDatas;		 //= _T("IEC_SaveDatas");
CString g_sLangTxt_IEC_SaveDatas;		 //= _T("保存数据");

CString g_sLangID_IEC_DeleteAllButFirst;  //= _T("IEC_DeleteAllButFirst");
CString g_sLangTxt_IEC_DeleteAllButFirst; //= _T("删除N-1");

CString g_sLangID_IEC_ChEdit;				  //= _T("IEC_ChEdit");
CString g_sLangTxt_IEC_ChEdit;				  //= _T("通道编辑");
CString g_sLangID_IEC_T1Times;				  //= _T("IEC_T1Times");
CString g_sLangTxt_IEC_T1Times;				  //= _T("T1时间(ms)");
CString g_sLangID_IEC_T0Times;				  //= _T("IEC_T0Times");
CString g_sLangTxt_IEC_T0Times;				  //= _T("T0时间(ms)");
CString g_sLangID_IEC_TimeQuality;			  //= _T("IEC_TimeQuality");
CString g_sLangTxt_IEC_TimeQuality;			  //= _T("时间品质");
CString g_sLangID_IEC_GroupDelay;			  //= _T("IEC_GroupDelay");
CString g_sLangTxt_IEC_GroupDelay;			  //= _T("组间延时(ms)");
CString g_sLangID_IEC_Details;				  //= _T("IEC_Details");
CString g_sLangTxt_IEC_Details;				  //= _T("详细设置");
CString g_sLangID_IEC_SetRecordParas;		  //= _T("IEC_SetRecordParas");
CString g_sLangTxt_IEC_SetRecordParas;		  //= _T("报文参数设置");
CString g_sLangID_IEC_SmpByteNum;			  //= _T("IEC_SmpByteNum");
CString g_sLangTxt_IEC_SmpByteNum;			  //= _T("采样位宽");
CString g_sLangID_IEC_SmpCntType;			  //= _T("IEC_SmpCntType");
CString g_sLangTxt_IEC_SmpCntType;			  //= _T("采样方式");
CString g_sLangID_IEC_SamplingRate;			  //= _T("IEC_SamplingRate");
CString g_sLangTxt_IEC_SamplingRate;		  //= _T("采样率：");
CString g_sLangID_IEC_BaudRate;				  //= _T("IEC_BaudRate");
CString g_sLangTxt_IEC_BaudRate;			  //= _T("波特率：");
CString g_sLangID_IEC_RatedDelay;			  //= _T("IEC_RatedDelay");
CString g_sLangTxt_IEC_RatedDelay;			  //= _T("额定延时");
CString g_sLangID_IEC_DcVolCodeValue;		  //= _T("IEC_DcVolCodeValue");
CString g_sLangTxt_IEC_DcVolCodeValue;		  //= _T("直流电压码值");
CString g_sLangID_IEC_AcVolCodeValue;		  //= _T("IEC_AcVolCodeValue");
CString g_sLangTxt_IEC_AcVolCodeValue;		  //= _T("交流电压码值");
CString g_sLangID_IEC_DcCurCodeValue;		  //= _T("IEC_DcCurCodeValue");
CString g_sLangTxt_IEC_DcCurCodeValue;		  //= _T("直流电流码值");
CString g_sLangID_IEC_PrimtRatedVol;		  //= _T("IEC_PrimtRatedVol");
CString g_sLangTxt_IEC_PrimtRatedVol;		  //= _T("一次额定电压");
CString g_sLangID_IEC_PrimtRatedCur;		  //= _T("IEC_PrimtRatedCur");
CString g_sLangTxt_IEC_PrimtRatedCur;		  // = _T("一次额定电流");
CString g_sLangID_IEC_DcNeutralVolCodeValue;  //= _T("IEC_DcNeutralVolCodeValue");
CString g_sLangTxt_IEC_DcNeutralVolCodeValue; //= _T("中性母线电压码值");
CString g_sLangID_IEC_AcProtCurCodeValue;	  //= _T("IEC_AcProtCurCodeValue");
CString g_sLangTxt_IEC_AcProtCurCodeValue;	  //= _T("交流保护电流码值");
CString g_sLangID_IEC_AcMeasCurCodeValue;	  //= _T("IEC_AcMeasCurCodeValue");
CString g_sLangTxt_IEC_AcMeasCurCodeValue;	  //= _T("交流测量电流码值");

CString g_sLangID_IEC_FT3PublishParameterSet;  //= _T("IEC_FT3PublishParameterSet");
CString g_sLangTxt_IEC_FT3PublishParameterSet; //= _T("FT3发布参数设置");
CString g_sLangID_IEC_FT3MapParameterSet;	   //= _T("IEC_FT3MapParameterSet");
CString g_sLangTxt_IEC_FT3MapParameterSet;	   //= _T("FT3映射参数设置");
CString g_sLangID_IEC_KeepSendAfterStop;	   //= _T("IEC_KeepSendAfterStop");
CString g_sLangTxt_IEC_KeepSendAfterStop;	   //= _T("停止后保持发送");
CString g_sLangID_IEC_StopSending;			   //= _T("IEC_StopSending");
CString g_sLangTxt_IEC_StopSending;			   //= _T("停止后终止发送");

CString g_sLangID_IEC_PacketSendingMode;  //= _T("IEC_PacketSendingMode");
CString g_sLangTxt_IEC_PacketSendingMode; //= _T("报文发送方式：");
CString g_sLangID_IEC_PTRatio;			  //= _T("IEC_PTRatio");
CString g_sLangTxt_IEC_PTRatio;			  //= _T("PT变比：");
CString g_sLangID_IEC_CTRatio;			  //= _T("IEC_CTRatio");
CString g_sLangTxt_IEC_CTRatio;			  //= _T("CT变比：");
CString g_sLangID_IEC_SMVCh;			  //= _T("IEC_SMVCh");
CString g_sLangTxt_IEC_SMVCh;			  //= _T("SMV通道");
CString g_sLangID_IEC_ChDescription;	  //= _T("IEC_ChDescription");
CString g_sLangTxt_IEC_ChDescription;	  //= _T("通道描述");
CString g_sLangID_IEC_ChType;			  //= _T("IEC_ChType");
CString g_sLangTxt_IEC_ChType;			  //= _T("通道类型");
CString g_sLangID_IEC_ChByteLen;		  //= _T("IEC_ChByteLen");
CString g_sLangTxt_IEC_ChByteLen;		  //= _T("字节长度");
CString g_sLangID_IEC_DIMap;			  //= _T("IEC_DIMap");
CString g_sLangTxt_IEC_DIMap;			  //= _T("开入映射");
CString g_sLangID_IEC_SetRepair;		  //= _T("IEC_SetRepair");
CString g_sLangTxt_IEC_SetRepair;		  //= _T("投检修");
CString g_sLangID_IEC_UnSetRepair;		  //= _T("IEC_UnSetRepair");
CString g_sLangTxt_IEC_UnSetRepair;		  //= _T("不投检修");
CString g_sLangID_IEC_IMap;				  //= _T("IEC_IMap");
CString g_sLangTxt_IEC_IMap;			  //= _T("电流映射:");
CString g_sLangID_IEC_UMap;				  //= _T("IEC_UMap");
CString g_sLangTxt_IEC_UMap;			  //= _T("电压映射:");
CString g_sLangID_IEC_SetInitValue;		  //= _T("IEC_SetInitValue");
CString g_sLangTxt_IEC_SetInitValue;	  //= _T("初值设置");
CString g_sLangID_IEC_Choose;			  //= _T("IEC_Choose");
CString g_sLangTxt_IEC_Choose;			  //= _T("选择:");
CString g_sLangID_IEC_Target;			  //= _T("IEC_Target");
CString g_sLangTxt_IEC_Target;			  //= _T("目标MAC地址");
CString g_sLangID_IEC_Entrance;			  //= _T("IEC_Entrance");
CString g_sLangTxt_IEC_Entrance;		  //= _T("输入口选择");

CString g_sLangID_IEC_ChannelNumber;   //= _T("IEC_ChannelNumber");
CString g_sLangTxt_IEC_ChannelNumber;  //= _T("通道数");
CString g_sLangID_IEC_Version;		   //= _T("IEC_Version");
CString g_sLangTxt_IEC_Version;		   //= _T("版本号");
CString g_sLangID_IEC_Test;			   //= _T("IEC_Test");
CString g_sLangTxt_IEC_Test;		   //= _T("测试(Test)");
CString g_sLangID_IEC_LifeTime;		   //= _T("IEC_LifeTime");
CString g_sLangTxt_IEC_LifeTime;	   //= _T("允许生存时间(ms)");
CString g_sLangID_IEC_UnParse;		   //= _T("IEC_ParseGoCB_GoID_Dataset");
CString g_sLangTxt_IEC_UnParse;		   //= _T("解析GoCB,GoID,Dataset");
CString g_sLangID_IEC_ChMaps;		   //= _T("IEC_ChMaps");
CString g_sLangTxt_IEC_ChMaps;		   //= _T("通道映射");
CString g_sLangID_IEC_InitValue;	   //= _T("IEC_InitValue");
CString g_sLangTxt_IEC_InitValue;	   //= _T("初始值");
CString g_sLangID_IEC_InputMap;		   //= _T("IEC_InputMap");
CString g_sLangTxt_IEC_InputMap;	   //= _T("开入量映射");
CString g_sLangID_IEC_Source;		   //= _T("IEC_Source");
CString g_sLangTxt_IEC_Source;		   //= _T("源MAC地址");
CString g_sLangID_IEC_Intrance;		   //= _T("IEC_Intrance");
CString g_sLangTxt_IEC_Intrance;	   //= _T("输出口选择");
CString g_sLangID_IEC_DescExternal;	   //= _T("IEC_DescExternal");
CString g_sLangTxt_IEC_DescExternal;   //= _T("外部通道描述");
CString g_sLangID_IEC_Quality;		   //= _T("IEC_Quality");
CString g_sLangTxt_IEC_Quality;		   //= _T("品质");
CString g_sLangID_IEC_Delay;		   //= _T("IEC_Delay");
CString g_sLangTxt_IEC_Delay;		   //= _T("采样延时(μs)");
CString g_sLangID_IEC_StartDelay;	   //= _T("IEC_StartDelay");
CString g_sLangTxt_IEC_StartDelay;	   //= _T("开始过载延时(s):");
CString g_sLangID_IEC_Synchronously;   //= _T("IEC_Synchronously");
CString g_sLangTxt_IEC_Synchronously;  //= _T("同步方式");
CString g_sLangID_IEC_ScaleFactor;	   //= _T("IEC_ScaleFactor");
CString g_sLangTxt_IEC_ScaleFactor;	   //= _T("比例因子");
CString g_sLangID_IEC_SetScaleFactor;  //= _T("IEC_SetScaleFactor");
CString g_sLangTxt_IEC_SetScaleFactor; //= _T("比例因子设置");
CString g_sLangID_IEC_FMByte;		   //= _T("IEC_FMByte");
CString g_sLangTxt_IEC_FMByte;		   //= _T("百兆口");
CString g_sLangID_IEC_GMByte;		   //= _T("IEC_GMByte");
CString g_sLangTxt_IEC_GMByte;		   //= _T("千兆口");
CString g_sLangID_IEC_LCFI;			   //= _T("IEC_LCFI");
CString g_sLangTxt_IEC_LCFI;		   //= _T("LC光口");
CString g_sLangID_IEC_IRIGB;		   //= _T("IEC_IRIGB");
CString g_sLangTxt_IEC_IRIGB;		   //= _T("B码");
CString g_sLangID_IEC_STFI;			   //= _T("IEC_STFI");
CString g_sLangTxt_IEC_STFI;		   //= _T("ST光口");
CString g_sLangID_IEC_AccuratyLevel;   //= _T("IEC_AccuratyLevel");
CString g_sLangTxt_IEC_AccuratyLevel;  //= _T("准确级");

CString g_sLangID_IEC_IEC61850;
CString g_sLangTxt_IEC_IEC61850;

CString g_sLangID_IEC_PTOnce;
CString g_sLangTxt_IEC_PTOnce;
CString g_sLangID_IEC_PTSecond;
CString g_sLangTxt_IEC_PTSecond;
CString g_sLangID_IEC_CTOnce;
CString g_sLangTxt_IEC_CTOnce;
CString g_sLangID_IEC_CTSecond;
CString g_sLangTxt_IEC_CTSecond;
CString g_sLangTxt_IEC_OPDES;
CString g_sLangID_IEC_OPDES;
CString g_sLangID_IEC_Protectcurrent;
CString g_sLangTxt_IEC_Protectcurrent;
CString g_sLangTxt_IEC_Measurcurrent;
CString g_sLangID_IEC_Measurcurrent;

CString g_sLangID_IEC_IEDselect;
CString g_sLangTxt_IEC_IEDselect;

CString g_sLangID_IEC_Msg_OverWriteCtrl;
CString g_sLangTxt_IEC_Msg_OverWriteCtrl;

CString g_sLangID_IEC_FI;		 //= _T("IEC_FI");
CString g_sLangTxt_IEC_FI;		 //= _T("光口");
CString g_sLangID_IEC_FIChoose;	 //= _T("IEC_FIChoose");
CString g_sLangTxt_IEC_FIChoose; //= _T("光口选择");

CString g_sLangID_IEC_Opticalport;
CString g_sLangTxt_IEC_Opticalport;
CString g_sLangID_IEC_MACAddr;			//= _T("IEC_MACAddr");
CString g_sLangTxt_IEC_MACAddr;			//= _T("MAC地址");
CString g_sLangID_IEC_DataSetText;		//= _T("IEC_DataSetText");
CString g_sLangTxt_IEC_DataSetText;		//= _T("数据集描述");
CString g_sLangID_IEC_GOOSEIndex;		//= _T("IEC_GOOSEIndex");
CString g_sLangTxt_IEC_GOOSEIndex;		//= _T("GOOSE控制块索引");
CString g_sLangID_IEC_VlanPri;			//= _T("IEC_VlanPri");
CString g_sLangTxt_IEC_VlanPri;			//= _T("Vlan优先级");
CString g_sLangID_IEC_ConfigVersion;	//= _T("IEC_ConfigVersion");
CString g_sLangTxt_IEC_ConfigVersion;	//= _T("配置版本");
CString g_sLangID_IEC_ChAllNumber;		//= _T("IEC_ChAllNumber");
CString g_sLangTxt_IEC_ChAllNumber;		//= _T("总通道数");
CString g_sLangID_IEC_SubChNumber;		//= _T("IEC_SubChNumber");
CString g_sLangTxt_IEC_SubChNumber;		//= _T("订阅通道数");
CString g_sLangID_IEC_SubIED;			//= _T("IEC_SubIED");
CString g_sLangTxt_IEC_SubIED;			//= _T("订阅IED");
CString g_sLangID_IEC_ASDU;				//= _T("IEC_ASDU");
CString g_sLangTxt_IEC_ASDU;			//= _T("ASDU数");
CString g_sLangID_IEC_Find;				//= _T("IEC_Find");
CString g_sLangTxt_IEC_Find;			//= _T("查找");
CString g_sLangID_IEC_SMVPublish;		//= _T("IEC_SMVPublish");
CString g_sLangTxt_IEC_SMVPublish;		//= _T("SMV发布");
CString g_sLangID_IEC_SMVSubscription;	//= _T("IEC_SMVSubscription");
CString g_sLangTxt_IEC_SMVSubscription; //= _T("SMV订阅");
CString g_sLangID_IEC_Configure;		//= _T("IEC_Configure");
CString g_sLangTxt_IEC_Configure;		//= _T("一键配置");
CString g_sLangID_IEC_CancelConfigure;		//= _T("IEC_Configure");
CString g_sLangTxt_IEC_CancelConfigure;		//= _T("取消一键配置");
CString g_sLangID_IEC_IEDList;		   //= _T("IEC_IEDList");
CString g_sLangTxt_IEC_IEDList;		   //= _T("IED列表");
CString g_sLangID_IEC_QualityParaSet;  //= _T("IEC_QualityParaSet");
CString g_sLangTxt_IEC_QualityParaSet; //= _T("品质参数设置");
CString g_sLangID_IEC_Validity;		   //= _T("IEC_Validity");
CString g_sLangTxt_IEC_Validity;	   //= _T("有效[bit0-bit1]");
CString g_sLangID_IEC_Overflow;		   //= _T("IEC_Overflow");
CString g_sLangTxt_IEC_Overflow;	   //= _T("溢出[bit2]");
CString g_sLangID_IEC_OutOfRange;	   //= _T("IEC_OutOfRange");
CString g_sLangTxt_IEC_OutOfRange;	   //= _T("超值域[bit3]");
CString g_sLangID_IEC_BadReference;	   //= _T("IEC_BadReference");
CString g_sLangTxt_IEC_BadReference;   //= _T("坏基准值[bit4]");
CString g_sLangID_IEC_Oscillatory;	   //= _T("IEC_Oscillatory");
CString g_sLangTxt_IEC_Oscillatory;	   //= _T("抖动[bit5]");
CString g_sLangID_IEC_Failure;		   //= _T("IEC_Failure");
CString g_sLangTxt_IEC_Failure;		   //= _T("故障[bit6]");
CString g_sLangID_IEC_OldData;		   //= _T("IEC_OldData");
CString g_sLangTxt_IEC_OldData;		   //= _T("旧数据[bit7]");
CString g_sLangID_IEC_Inconsistent;	   //= _T("IEC_Inconsistent");
CString g_sLangTxt_IEC_Inconsistent;   //= _T("不一致[bit8]");
CString g_sLangID_IEC_Inaccurate;	   //= _T("IEC_Inaccurate");
CString g_sLangTxt_IEC_Inaccurate;	   //= _T("不精确[bit9]");
CString g_sLangID_Channel_Source;	   //= _T("Channel_Source");
CString g_sLangTxt_Channel_Source;	   //= _T("源[bit10]");
CString g_sLangID_Channel_Test;		   //= _T("Channel_Test");
CString g_sLangTxt_Channel_Test;	   //= _T("测试[bit11]");
CString g_sLangID_IEC_Opb;			   //= _T("IEC_Opb");
CString g_sLangTxt_IEC_Opb;			   //= _T("操作员闭锁[bit12]");
CString g_sLangID_IEC_ModifyAllChs;	   //= _T("IEC_ModifyAllChs");
CString g_sLangTxt_IEC_ModifyAllChs;   //= _T("修改全部通道");
CString g_sLangID_IEC_DirectSet;	   //= _T("IEC_DirectSet");
CString g_sLangTxt_IEC_DirectSet;	   //= _T("直接设置");
CString g_sLangID_IEC_good;			   //= _T("IEC_good");
CString g_sLangTxt_IEC_good;		   //= _T("00:好");
CString g_sLangID_IEC_invalid;		   //= _T("IEC_invalid");
CString g_sLangTxt_IEC_invalid;		   //= _T("01:无效");
CString g_sLangID_IEC_reserved;		   //= _T("IEC_reserved");
CString g_sLangTxt_IEC_reserved;	   //= _T("10:保留");
CString g_sLangID_IEC_questionable;	   //= _T("IEC_questionable");
CString g_sLangTxt_IEC_questionable;   //= _T("11:可疑");
CString g_sLangID_IEC_nooverflow;	   //= _T("IEC_nooverflow");
CString g_sLangTxt_IEC_nooverflow;	   //= _T("0:无溢出");
CString g_sLangID_IEC_overflow;		   //= _T("IEC_overflow");
CString g_sLangTxt_IEC_overflow;	   //= _T("1:溢出");
CString g_sLangID_IEC_normal;		   //= _T("IEC_normal");
CString g_sLangTxt_IEC_normal;		   //= _T("0:正常");
CString g_sLangID_IEC_outofrange;	   //= _T("IEC_outofrange");
CString g_sLangTxt_IEC_outofrange;	   //= _T("1:超值域");
CString g_sLangID_IEC_badreference;	   //= _T("IEC_badreference");
CString g_sLangTxt_IEC_badreference;   //= _T("1:坏基准值");
CString g_sLangID_IEC_noOscillatory;   //= _T("IEC_noOscillatory");
CString g_sLangTxt_IEC_noOscillatory;  //= _T("0:无抖动");
CString g_sLangID_IEC_oscillatory;	   //= _T("IEC_oscillatory");
CString g_sLangTxt_IEC_oscillatory;	   //= _T("1:有抖动");
CString g_sLangID_IEC_nofailure;	   //= _T("IEC_nofailure");
CString g_sLangTxt_IEC_nofailure;	   //= _T("0:无故障");
CString g_sLangID_IEC_failure;		   //= _T("IEC_failure");
CString g_sLangTxt_IEC_failure;		   //= _T("1:有故障");
CString g_sLangID_IEC_noovertime;	   //= _T("IEC_noovertime");
CString g_sLangTxt_IEC_noovertime;	   //= _T("0:无超时");
CString g_sLangID_IEC_overtime;		   //= _T("IEC_overtime");
CString g_sLangTxt_IEC_overtime;	   //= _T("1:数据超时");
CString g_sLangID_IEC_noinconsistent;  //= _T("IEC_noinconsistent");
CString g_sLangTxt_IEC_noinconsistent; //= _T("0:一致");
CString g_sLangID_IEC_inconsistent;	   //= _T("IEC_inconsistent");
CString g_sLangTxt_IEC_inconsistent;   //= _T("1:不一致");
CString g_sLangID_IEC_accurate;		   //= _T("IEC_accurate");
CString g_sLangTxt_IEC_accurate;	   //= _T("0:精确");
CString g_sLangID_IEC_inaccurate;	   //= _T("IEC_inaccurate");
CString g_sLangTxt_IEC_inaccurate;	   //= _T("1:不精确");
CString g_sLangID_IEC_process;		   //= _T("IEC_process");
CString g_sLangTxt_IEC_process;		   //= _T("0:过程");
CString g_sLangID_IEC_substituted;	   //= _T("IEC_substituted");
CString g_sLangTxt_IEC_substituted;	   //= _T("1:被取代");
CString g_sLangID_IEC_run;			   //= _T("IEC_run");
CString g_sLangTxt_IEC_run;			   //= _T("0:运行");
CString g_sLangID_IEC_test;			   //= _T("IEC_test");
CString g_sLangTxt_IEC_test;		   //= _T("1:测试");
CString g_sLangID_IEC_nolock;		   //= _T("IEC_nolock");
CString g_sLangTxt_IEC_nolock;		   //= _T("0:不闭锁");
CString g_sLangID_IEC_lock;			   //= _T("IEC_lock");
CString g_sLangTxt_IEC_lock;		   //= _T("1:闭锁");
CString g_sLangID_IEC_Sendratio;
CString g_sLangTxt_IEC_Sendratio;
CString g_sLangID_IEC_Receiveratio;
CString g_sLangTxt_IEC_Receiveratio;

CString g_sLangID_IEC_ImportIecfg;	   //= _T("IEC_ImportIecfg");
CString g_sLangTxt_IEC_ImportIecfg;	   //= _T("导入配置");
CString g_sLangID_IEC_Detect;		   //= _T("IEC_Detect");
CString g_sLangTxt_IEC_Detect;		   //= _T("开始探测");
CString g_sLangID_IEC_DetectStop;	   //= _T("IEC_DetectStop");
CString g_sLangTxt_IEC_DetectStop;	   //= _T("停止探测");
CString g_sLangID_IEC_Clear;		   //= _T("IEC_Clear");
CString g_sLangTxt_IEC_Clear;		   //= _T("清空列表");
CString g_sLangID_IEC_BeginRecord;	   //= _T("IEC_BeginRecord");
CString g_sLangTxt_IEC_BeginRecord;	   //= _T("进入监视");
CString g_sLangID_IEC_UseSmv;		   //= _T("IEC_UseSmv");
CString g_sLangTxt_IEC_UseSmv;		   //= _T("显示Smv");
CString g_sLangID_IEC_UseGoose;		   //= _T("IEC_UseGoose");
CString g_sLangTxt_IEC_UseGoose;	   //= _T("显示Goose");
CString g_sLangID_IEC_SmvFirstIsTime;  //= _T("IEC_SmvFirstIsTime");
CString g_sLangTxt_IEC_SmvFirstIsTime; //= _T("SMV第1通道为延时");
CString g_sLangID_IEC_WriteDetectPkg;  //= _T("IEC_WriteDetectPkg");
CString g_sLangTxt_IEC_WriteDetectPkg; //= _T("模拟探测");
CString g_sLangID_IEC_WriteRcvPkg;	   //= _T("IEC_WriteRcvPkg");
CString g_sLangTxt_IEC_WriteRcvPkg;	   //= _T("模拟接受报文");
CString g_sLangID_IEC_AutoWrite;	   //= _T("IEC_AutoWrite");
CString g_sLangTxt_IEC_AutoWrite;	   //= _T("自动模拟");
CString g_sLangID_IEC_SendLength_2;	   //= _T("IEC_SendLength_2");
CString g_sLangTxt_IEC_SendLength_2;   //= _T("总长度");

CString g_sLangID_IEC_SendLength;  //= _T("IEC_SendLength");
CString g_sLangTxt_IEC_SendLength; //= _T("发送长度");
CString g_sLangID_IEC_Writegen;	   //= _T("IEC_Writegen");
CString g_sLangTxt_IEC_Writegen;   //= _T("模拟发生器");

CString g_sLangID_IEC_PacketSending;  //= _T("IEC_PacketSending");
CString g_sLangTxt_IEC_PacketSending; //= _T("报文输出");
CString g_sLangID_IEC_OnceValue;	  //= _T("IEC_OnceValue");
CString g_sLangTxt_IEC_OnceValue;	  //= _T("一次值");
CString g_sLangID_IEC_TwiceValue;	  //= _T("IEC_TwiceValue");
CString g_sLangTxt_IEC_TwiceValue;	  //= _T("二次值");
CString g_sLangID_IEC_Coeff;		  //= _T("IEC_Coeff");
CString g_sLangTxt_IEC_Coeff;		  //= _T("系数");
CString g_sLangID_IEC_FileSaveAs;	  //= _T("IEC_FileSaveAs");
CString g_sLangTxt_IEC_FileSaveAs;	  //= _T("文件另存为");

CString g_sLangID_GOOSE_Single;	 //= _T("GOOSE_Single");
CString g_sLangTxt_GOOSE_Single; //= _T("单点");
CString g_sLangID_GOOSE_Double;	 //= _T("GOOSE_Double");
CString g_sLangTxt_GOOSE_Double; //= _T("双点");

CString g_sLangID_GOOSE_Float;	//= _T("GOOSE_Float");
CString g_sLangTxt_GOOSE_Float; //= _T("浮点");

CString g_sLangID_Goose_SwitchTime;	   //= _T("Goose_SwitchTime");
CString g_sLangTxt_Goose_SwitchTime;   //= _T("切换时间");
CString g_sLangID_Goose_Value;		   //= _T("Goose_Value");
CString g_sLangTxt_Goose_Value;		   //= _T("值");
CString g_sLangID_Goose_RelativeTime;  //= _T("Goose_RelativeTime");
CString g_sLangTxt_Goose_RelativeTime; //= _T("相对时间/us");

CString g_sLangID_CharLib_ZoomIndex;   //=_T("CharLib_ZoomIndex");
CString g_sLangTxt_CharLib_ZoomIndex;  //=	_T("段号");
CString g_sLangID_CharLib_FaultPhase;  //=	_T("CharLib_FaultPhase");
CString g_sLangTxt_CharLib_FaultPhase; //=_T("故障相");
CString g_sLangID_CharLib_AddChar;	   // 特性曲线添加
CString g_sLangTxt_CharLib_AddChar;
CString g_sLangID_CharLib_StartCurr; // 启动段
CString g_sLangTxt_CharLib_StartCurr;
CString g_sLangID_CharLib_Ratiobraking; // 比率制动
CString g_sLangTxt_CharLib_Ratiobraking;
CString g_sLangID_CharLib_Paragraph; // 段
CString g_sLangTxt_CharLib_Paragraph;
CString g_sLangID_CharLib_Tripping; // 速断
CString g_sLangTxt_CharLib_Tripping;
CString g_sLangID_CharLib_TestPointsGrid; // 测试点列表
CString g_sLangTxt_CharLib_TestPointsGrid;

CString g_sLangID_Smv_SelCb;		 //= _T("Smv_SelCb");
CString g_sLangTxt_Smv_SelCb;		 //= _T("选择控制块");
CString g_sLangID_Smv_SelFunc;		 //= _T("Smv_SelFunc");
CString g_sLangTxt_Smv_SelFunc;		 //= _T("选择功能");
CString g_sLangID_Smv_PrevPage;		 //= _T("Smv_PrevPage");
CString g_sLangTxt_Smv_PrevPage;	 //= _T("上一页");
CString g_sLangID_Smv_NextPage;		 //= _T("Smv_NextPage");
CString g_sLangTxt_Smv_NextPage;	 //= _T("下一页");
CString g_sLangID_Smv_SysSet;		 //= _T("Smv_SysSet");
CString g_sLangTxt_Smv_SysSet;		 //= _T("系统设置");
CString g_sLangID_Smv_ChName;		 //=_T("Smv_ChName");
CString g_sLangTxt_Smv_ChName;		 //= _T("通道名");
CString g_sLangID_Smv_Item;			 //= _T("Smv_Item");
CString g_sLangTxt_Smv_Item;		 //=_T("项目");
CString g_sLangID_Smv_Number;		 //= _T("Smv_Number");
CString g_sLangTxt_Smv_Number;		 //=  _T("数目");
CString g_sLangID_Smv_PkgValue;		 //=  _T("Smv_PkgValue");
CString g_sLangTxt_Smv_PkgValue;	 //= _T("报文值");
CString g_sLangID_Smv_Category;		 //= _T("Smv_Category");
CString g_sLangTxt_Smv_Category;	 //= _T("类别");
CString g_sLangID_Smv_Rates;		 //=  _T("Smv_Rates");
CString g_sLangTxt_Smv_Rates;		 //=  _T("变比设置");
CString g_sLangID_Smv_ShowOneValue;	 //= _T("Smv_ShowOneValue");
CString g_sLangTxt_Smv_ShowOneValue; //= _T("显示一次值");
CString g_sLangID_Smv_ShowTwoValue;	 //= _T("Smv_ShowTwoValue");
CString g_sLangTxt_Smv_ShowTwoValue; //=  _T("显示二次值");

CString g_sLangID_Native_EffectiveVol;	 //= _T("Native_EffectiveVol");
CString g_sLangTxt_Native_EffectiveVol;	 //=  _T("电压有效值");
CString g_sLangID_Native_EffectiveCurr;	 //=  _T("Native_EffectiveCurr");
CString g_sLangTxt_Native_EffectiveCurr; //= _T("电流有效值");
CString g_sLangID_Native_Power;			 //= _T("Native_Power");
CString g_sLangTxt_Native_Power;		 //=  _T("有功功率(W)");
CString g_sLangID_Native_ReactivePow;	 //= _T("Native_ReactivePow");
CString g_sLangTxt_Native_ReactivePow;	 //=  _T("无功功率(Var)");
CString g_sLangID_Native_ApparentPow;	 //= _T("Native_ApparentPow");
CString g_sLangTxt_Native_ApparentPow;	 //= _T("视在功率(VA)");
CString g_sLangID_Native_PowFactor;		 //= _T("Native_PowFactor");
CString g_sLangTxt_Native_PowFactor;	 //=  _T("功率因数");
CString g_sLangID_Native_TotalPow;		 //=  _T("Native_TotalPow");
CString g_sLangTxt_Native_TotalPow;		 //= _T("总功率");
CString g_sLangID_Native_Clear;			 //=  _T("Native_Clear");
CString g_sLangTxt_Native_Clear;		 //=  _T("清空");

CString g_sLangID_Samples;
CString g_sLangTxt_Samples;
CString g_sLangID_Momentaryvalue;
CString g_sLangTxt_Momentaryvalue;
CString g_sLangID_notrigger;
CString g_sLangTxt_notrigger;
CString g_sLangID_Cyclicwave;
CString g_sLangTxt_Cyclicwave;
CString g_sLangID_GPS;
CString g_sLangTxt_GPS;
CString g_sLangID_Timere;
CString g_sLangTxt_Timere;
CString g_sLangID_Switchtrigger;
CString g_sLangTxt_Switchtrigger;
CString g_sLangID_Faultcurve;
CString g_sLangTxt_Faultcurve;
CString g_sLangID_Display;
CString g_sLangTxt_Display;
CString g_sLangID_AChannel;
CString g_sLangTxt_AChannel;
CString g_sLangID_BChannel;
CString g_sLangTxt_BChannel;
CString g_sLangID_Open_Record;
CString g_sLangTxt_Open_Record;
CString g_sLangID_Instant;
CString g_sLangTxt_Instant;
CString g_sLangID_PT;
CString g_sLangTxt_PT;
CString g_sLangID_CT;
CString g_sLangTxt_CT;
CString g_sLangID_Module1;
CString g_sLangTxt_Module1;
CString g_sLangID_Outputpower;
CString g_sLangTxt_Outputpower;
CString g_sLangID_Currentmodule;
CString g_sLangTxt_Currentmodule;
CString g_sLangID_CurrModuleSelect;
CString g_sLangTxt_CurrModuleSelect;
CString g_sLangID_Currentgear;
CString g_sLangTxt_Currentgear;
CString g_sLangID_Maximumport;
CString g_sLangTxt_Maximumport;
CString g_sLangID_Combinedcurrent;
CString g_sLangTxt_Combinedcurrent;
CString g_sLangID_Highcurrent;
CString g_sLangTxt_Highcurrent;
CString g_sLangID_Onegear;
CString g_sLangTxt_Onegear;
CString g_sLangID_Twogear;
CString g_sLangTxt_Twogear;
CString g_sLangID_Threegear;
CString g_sLangTxt_Threegear;
CString g_sLangID_else;
CString g_sLangTxt_else;
CString g_sLangID_Onlyselect;
CString g_sLangTxt_Onlyselect;
CString g_sLangID_Clickratio;
CString g_sLangTxt_Clickratio;
CString g_sLangID_Clickmonitor;
CString g_sLangTxt_Clickmonitor;
CString g_sLangID_Selecttable;
CString g_sLangTxt_Selecttable;
CString g_sLangID_Reporttest;
CString g_sLangTxt_Reporttest;
CString g_sLangID_starttest;
CString g_sLangTxt_starttest;
CString g_sLangID_General;
CString g_sLangTxt_General;
CString g_sLangID_TestHelp;
CString g_sLangTxt_TestHelp;
CString g_sLangID_Currentfailed;
CString g_sLangTxt_Currentfailed;
CString g_sLangID_Succeeded;
CString g_sLangTxt_Succeeded;
CString g_sLangID_delay;
CString g_sLangTxt_delay;
CString g_sLangID_Measured;
CString g_sLangTxt_Measured;
CString g_sLangID_error;
CString g_sLangTxt_error;
CString g_sLangID_The;
CString g_sLangTxt_The;
CString g_sLangID_current;
CString g_sLangTxt_current;
CString g_sLangID_Node;
CString g_sLangTxt_Node;
CString g_sLangID_Items;
CString g_sLangTxt_Items;
CString g_sLangID_exist;
CString g_sLangTxt_exist;
CString g_sLangID_menu;
CString g_sLangTxt_menu;
CString g_sLangID_return;
CString g_sLangTxt_return;
CString g_sLangID_USBFile;
CString g_sLangTxt_USBFile;
CString g_sLangID_RepalceFile;
CString g_sLangTxt_RepalceFile;
CString g_sLangID_import;
CString g_sLangTxt_import;
CString g_sLangID_export;
CString g_sLangTxt_export;
CString g_sLangID_Importflie;
CString g_sLangTxt_Importflie;
CString g_sLangID_Win;
CString g_sLangTxt_Win;
CString g_sLangID_Lose;
CString g_sLangTxt_Lose;
CString g_sLangID_block;
CString g_sLangTxt_block;
CString g_sLangID_Controlblock;
CString g_sLangTxt_Controlblock;
CString g_sLangID_leastone;
CString g_sLangTxt_leastone;
CString g_sLangID_copyblock;
CString g_sLangTxt_copyblock;
CString g_sLangID_viewchannel;
CString g_sLangTxt_viewchannel;
CString g_sLangID_dataobject;
CString g_sLangTxt_dataobject;
CString g_sLangID_channelType;
CString g_sLangTxt_channelType;
CString g_sLangID_parameterport;
CString g_sLangTxt_parameterport;
CString g_sLangID_SMV92map;
CString g_sLangTxt_SMV92map;
CString g_sLangID_samplepublish;
CString g_sLangTxt_samplepublish;
CString g_sLangID_USB;
CString g_sLangTxt_USB;
CString g_sLangID_exportbar;
CString g_sLangTxt_exportbar;
CString g_sLangID_Fileguid;
CString g_sLangTxt_Fileguid;
CString g_sLangID_devicedesc;
CString g_sLangTxt_devicedesc;
CString g_sLangID_unittype;
CString g_sLangTxt_unittype;
CString g_sLangID_changelist;
CString g_sLangTxt_changelist;
CString g_sLangID_overwitten;
CString g_sLangTxt_overwitten;
CString g_sLangID_componenttest;
CString g_sLangTxt_componenttest;
CString g_sLangID_sequence;
CString g_sLangTxt_sequence;
CString g_sLangID_componentlinevolttest;
CString g_sLangTxt_componentlinevolttest;
CString g_sLangID_linevolt;
CString g_sLangTxt_linevolt;
CString g_sLangID_steplength;
CString g_sLangTxt_steplength;
//CString g_sLangID_Frequency;    //移动到基类CXLanguageResourceBase  2024-1-4 shaolei
//CString g_sLangTxt_Frequency;
CString g_sLangID_selectchannel;
CString g_sLangTxt_selectchannel;
CString g_sLangID_currenttime;
CString g_sLangTxt_currenttime;
CString g_sLangID_channelname;
CString g_sLangTxt_channelname;
CString g_sLangID_errorclass;
CString g_sLangTxt_errorclass;
CString g_sLangID_numbertest;
CString g_sLangTxt_numbertest;
CString g_sLangID_realtime;
CString g_sLangTxt_realtime;
CString g_sLangID_emptydata;
CString g_sLangTxt_emptydata;
CString g_sLangID_ratioerror;
CString g_sLangTxt_ratioerror;
CString g_sLangID_ratioerror2;
CString g_sLangTxt_ratioerror2;
CString g_sLangID_angle;
CString g_sLangTxt_angle;
CString g_sLangID_Compound;
CString g_sLangTxt_Compound;
CString g_sLangID_statistic;
CString g_sLangTxt_statistic;
CString g_sLangID_outputvalue;
CString g_sLangTxt_outputvalue;
CString g_sLangID_Outputphase;
CString g_sLangTxt_Outputphase;
CString g_sLangID_Measureampl;
CString g_sLangTxt_Measureampl;
CString g_sLangID_Measuredphase;
CString g_sLangTxt_Measuredphase;
CString g_sLangID_zerodrift;
CString g_sLangTxt_zerodrift;
CString g_sLangID_posttrigger;
CString g_sLangTxt_posttrigger;
CString g_sLangID_Switchimmed;
CString g_sLangTxt_Switchimmed;
CString g_sLangID_loopwaveform;
CString g_sLangTxt_loopwaveform;
CString g_sLangID_faultreplay;
CString g_sLangTxt_faultreplay;
CString g_sLangID_downloaddata;
CString g_sLangTxt_downloaddata;
CString g_sLangID_ReplayStarttest;
CString g_sLangTxt_ReplayStarttest;
CString g_sLangID_playback;
CString g_sLangTxt_playback;
CString g_sLangID_outputvoltage;
CString g_sLangTxt_outputvoltage;
CString g_sLangID_outputcurrent;
CString g_sLangTxt_outputcurrent;
CString g_sLangID_deliverybar;
CString g_sLangTxt_deliverybar;
CString g_sLangID_cfgFile;
CString g_sLangTxt_cfgFile;
CString g_sLangID_parsebar;
CString g_sLangTxt_parsebar;
CString g_sLangID_recordfile;
CString g_sLangTxt_recordfile;
CString g_sLangID_hardwarefile;
CString g_sLangTxt_hardwarefile;
CString g_sLangID_channelphase;
CString g_sLangTxt_channelphase;
CString g_sLangID_tablechannel;
CString g_sLangTxt_tablechannel;
CString g_sLangID_faulttype;
CString g_sLangTxt_faulttype;
CString g_sLangID_rangenumber;
CString g_sLangTxt_rangenumber;
CString g_sLangID_maxblocks;
CString g_sLangTxt_maxblocks;
CString g_sLangID_valuesubscrip;
CString g_sLangTxt_valuesubscrip;
CString g_sLangID_emptyIed;
CString g_sLangTxt_emptyIed;
CString g_sLangID_emptyIEC;
CString g_sLangTxt_emptyIEC;
CString g_sLangID_addedblock;
CString g_sLangTxt_addedblock;
CString g_sLangID_configurationfile;
CString g_sLangTxt_configurationfile;
CString g_sLangID_warning; //sun
 CString g_sLangTxt_warning; //sun
CString g_sLangID_NullIEC;
CString g_sLangTxt_NullIEC;
CString g_sLangID_IECpath;
CString g_sLangTxt_IECpath;
CString g_sLangID_IECdocument;
CString g_sLangTxt_IECdocument;
CString g_sLangID_zero;
CString g_sLangTxt_zero;
CString g_sLangID_step;
CString g_sLangTxt_step;
CString g_sLangID_datapath;
CString g_sLangTxt_datapath;
CString g_sLangID_guide;
CString g_sLangTxt_guide;
CString g_sLangID_wizard;
CString g_sLangTxt_wizard;
CString g_sLangID_period;
CString g_sLangTxt_period;
CString g_sLangID_quality;
CString g_sLangTxt_quality;
CString g_sLangID_mutate;
CString g_sLangTxt_mutate;
CString g_sLangID_leadtime;
CString g_sLangTxt_leadtime;
CString g_sLangID_change;
CString g_sLangTxt_change;
CString g_sLangID_instrument;
CString g_sLangTxt_instrument;
CString g_sLangID_instrumentnumber;
CString g_sLangTxt_instrumentnumber;
CString g_sLangID_testip;
CString g_sLangTxt_testip;
CString g_sLangID_IPaddress;
CString g_sLangTxt_IPaddress;
CString g_sLangID_correctlyform;
CString g_sLangTxt_correctlyform;
CString g_sLangID_assistantIP;
CString g_sLangTxt_assistantIP;
CString g_sLangID_validentry;
CString g_sLangTxt_validentry;
CString g_sLangID_listIP;
CString g_sLangTxt_listIP;
CString g_sLangID_cardIP;
CString g_sLangTxt_cardIP;
CString g_sLangID_scan;
CString g_sLangTxt_scan;
CString g_sLangID_query;
CString g_sLangTxt_query;
CString g_sLangID_running;
CString g_sLangTxt_running;
CString g_sLangID_nullIP;
CString g_sLangTxt_nullIP;
CString g_sLangID_automatic;
CString g_sLangTxt_automatic;
CString g_sLangID_networkcards;
CString g_sLangTxt_networkcards;
CString g_sLangID_validIP;
CString g_sLangTxt_validIP;
CString g_sLangID_cardlookup;
CString g_sLangTxt_cardlookup;
CString g_sLangID_modifyIP;
CString g_sLangTxt_modifyIP;
CString g_sLangID_stopscan;
CString g_sLangTxt_stopscan;

// SOE

CString g_sLangID_SOE_state;
CString g_sLangTxt_SOE_state;
CString g_sLangID_SOE_ChangeBeforTimes;
CString g_sLangTxt_SOE_ChangeBeforTimes;
CString g_sLangID_SOE_ShuttingTimes;
CString g_sLangTxt_SOE_ShuttingTimes;
CString g_sLangID_SOE_DisconTimes;
CString g_sLangTxt_SOE_DisconTimes;
CString g_sLangID_SOE_Count;
CString g_sLangTxt_SOE_Count;
CString g_sLangID_SOE_SustainTimes;
CString g_sLangTxt_SOE_SustainTimes;
CString g_sLangID_SOE_Break;
CString g_sLangTxt_SOE_Break;
CString g_sLangID_SOE_Shutting;
CString g_sLangTxt_SOE_Shutting;

CString g_sLangID_SOE_ImmediateExperiment;
CString g_sLangTxt_SOE_ImmediateExperiment;
CString g_sLangID_SOE_PulseWidth;
CString g_sLangTxt_SOE_PulseWidth;
CString g_sLangID_SOE_Resolution;
CString g_sLangTxt_SOE_Resolution;
CString g_sLangID_SOE_SelectAll;
CString g_sLangTxt_SOE_SelectAll;
CString g_sLangID_SOE_CancelAll;
CString g_sLangTxt_SOE_CancelAll;
CString g_sLangID_SOE_InitialAll;
CString g_sLangTxt_SOE_InitialAll;
CString g_sLangID_SOE_InitialDivideAll;
CString g_sLangTxt_SOE_InitialDivideAll;

CString g_sLangID_SOE_TemplateFile;
CString g_sLangTxt_SOE_TemplateFile;

CString g_sLangID_FileMngr_FolderName;
CString g_sLangTxt_FileMngr_FolderName;
CString g_sLangID_FileMngr_FolderIllustrate;
CString g_sLangTxt_FileMngr_FolderIllustrate;
CString g_sLangID_FileMngr_Date;
CString g_sLangTxt_FileMngr_Date;
CString g_sLangID_FileMngr_File;
CString g_sLangTxt_FileMngr_File;
CString g_sLangID_FileMngr_Used;
CString g_sLangTxt_FileMngr_Used;
CString g_sLangID_FileMngr_Available;
CString g_sLangTxt_FileMngr_Available;

CString g_sLangID_Native_Toolbar;
CString g_sLangTxt_Native_Toolbar;
CString g_sLangID_Native_BtnRemove;
CString g_sLangTxt_Native_BtnRemove;
CString g_sLangID_Native_BtnEndInsert;
CString g_sLangTxt_Native_BtnEndInsert;
CString g_sLangID_Native_BtnInsertAfter;
CString g_sLangTxt_Native_BtnInsertAfter;
CString g_sLangID_Native_BtnInsertBefore;
CString g_sLangTxt_Native_BtnInsertBefore;

CString g_sLangID_Native_BtnConfigDevice;
CString g_sLangTxt_Native_BtnConfigDevice;
CString g_sLangID_Native_BtnConnectDevice;
CString g_sLangTxt_Native_BtnConnectDevice;
CString g_sLangID_Native_BtnEnumDevice;
CString g_sLangTxt_Native_BtnEnumDevice;
CString g_sLangID_Native_BtnReadDataset;
CString g_sLangTxt_Native_BtnReadDataset;
CString g_sLangID_Native_BtnWriteDataset;
CString g_sLangTxt_Native_BtnWriteDataset;
CString g_sLangID_Native_BtnReadZone;
CString g_sLangTxt_Native_BtnReadZone;
CString g_sLangID_Native_BtnWriteZone;
CString g_sLangTxt_Native_BtnWriteZone;
CString g_sLangID_Native_BtnReset;
CString g_sLangTxt_Native_BtnReset;
CString g_sLangID_Native_BtnStartRpt;
CString g_sLangTxt_Native_BtnStartRpt;
CString g_sLangID_Native_BtnStopReport;
CString g_sLangTxt_Native_BtnStopReportr;
CString g_sLangID_Native_BtnAddDevice;
CString g_sLangTxt_Native_BtnAddDevice;
CString g_sLangID_Native_BtnEnumLDevice;
CString g_sLangTxt_Native_BtnEnumLDevice;
CString g_sLangID_Native_BtnEnumDataset;
CString g_sLangTxt_Native_BtnEnumDataset;
CString g_sLangID_Native_BtnOpenDvmFile;
CString g_sLangTxt_Native_BtnOpenDvmFile;
CString g_sLangID_Native_BtnSaveDvmFile;
CString g_sLangTxt_Native_BtnSaveDvmFile;

CString g_sLangID_Native_Upgradation;
CString g_sLangTxt_Native_Upgradation;
CString g_sLangID_Native_UpdateSoftware;
CString g_sLangTxt_Native_UpdateSoftware;
CString g_sLangID_Native_OnlineUpgrade;
CString g_sLangTxt_Native_OnlineUpgrade;
CString g_sLangID_Native_UpgradeProgressBar;
CString g_sLangTxt_Native_UpgradeProgressBar;
CString g_sLangID_Native_NetworkConnectionFailed;
CString g_sLangTxt_Native_NetworkConnectionFailed;
CString g_sLangID_Native_VersionUpdateFailed;
CString g_sLangTxt_Native_VersionUpdateFailed;
CString g_sLangID_Native_CommandFailed;
CString g_sLangTxt_Native_CommandFailed;
CString g_sLangID_Native_LowBatteryLevel;
CString g_sLangTxt_Native_LowBatteryLevel;
CString g_sLangID_Native_IecDetection;
CString g_sLangTxt_Native_IecDetection;
CString g_sLangID_Native_UnrecognizedUSB;
CString g_sLangTxt_Native_UnrecognizedUSB;
CString g_sLangID_Native_ChargingUpgrade;
CString g_sLangTxt_Native_ChargingUpgrade;
CString g_sLangID_Native_OfflineUpgrade;
CString g_sLangTxt_Native_OfflineUpgrade;
CString g_sLangID_Native_PreparationUpgrade;
CString g_sLangTxt_Native_PreparationUpgrade;
CString g_sLangID_Native_LookupFailed;
CString g_sLangTxt_Native_LookupFailed;
CString g_sLangID_Native_LiveUpdate;
CString g_sLangTxt_Native_LiveUpdate;
CString g_sLangID_Native_ExcludingReportData;
CString g_sLangTxt_Native_ExcludingReportData;
CString g_sLangID_Native_ReportDataEmpty;
CString g_sLangTxt_Native_ReportDataEmpty;

CString g_sLangID_Native_VolSetTypeLN;
CString g_sLangTxt_Native_VolSetTypeLN;
CString g_sLangID_Native_VolSetTypeLL;
CString g_sLangTxt_Native_VolSetTypeLL;
CString g_sLangID_Native_VolSetTypeSE;
CString g_sLangTxt_Native_VolSetTypeSE;
CString g_sLangID_Native_CurSetTypeLN;
CString g_sLangTxt_Native_CurSetTypeLN;
CString g_sLangID_Native_CurSetTypeSE;
CString g_sLangTxt_Native_CurSetTypeSE;

CString g_sLangID_Native_SyStempoints;
CString g_sLangTxt_Native_SyStempoints;
CString g_sLangID_Native_Custompoints;
CString g_sLangTxt_Native_Custompoints;
CString g_sLangID_Native_Iecurrent;
CString g_sLangTxt_Native_Iecurrent;
CString g_sLangID_Native_Acurrent;
CString g_sLangTxt_Native_Acurrent;
CString g_sLangID_Native_Faultcurrent;
CString g_sLangTxt_Native_Faultcurrent;

CString g_sLangID_IEC_FiberInSet;
CString g_sLangTxt_IEC_FiberInSet;
CString g_sLangID_IEC_FiberOutSet;
CString g_sLangTxt_IEC_FiberOutSet;

// 第七周许
// xwd 10.16
CString g_sLangID_Native_SetOrigMsg;				   // = _T("Native_SetOrigMsg")
CString g_sLangTxt_Native_SetOrigMsg;				   // = _T("设置原始报文")
CString g_sLangID_Native_DestMacAddr;				   // = _T("Native_DestMacAddr")
CString g_sLangTxt_Native_DestMacAddr;				   // = _T("目的Mac地址")
CString g_sLangID_Native_Netid;						   // = _T("Native_Netid")
CString g_sLangTxt_Native_Netid;					   // = _T("网络标识")
CString g_sLangID_Native_FlyPntVolt;				   // = _T("Native_FlyPntVolt")
CString g_sLangTxt_Native_FlyPntVolt;				   // = _T("飞点电压值")
CString g_sLangID_Native_FlyPntCurr;				   // = _T("Native_FlyPntCurr")
CString g_sLangTxt_Native_FlyPntCurr;				   // = _T("飞点电流值")
CString g_sLangID_Native_FlyPntVoltUaEn;			   // = _T("Native_FlyPntVoltUaEn")
CString g_sLangTxt_Native_FlyPntVoltUaEn;			   // = _T("飞点电压Ua使能")
CString g_sLangID_Native_FlyPntVoltUbEn;			   // = _T("Native_FlyPntVoltUbEn")
CString g_sLangTxt_Native_FlyPntVoltUbEn;			   // = _T("飞点电压Ub使能")
CString g_sLangID_Native_FlyPntVoltUcEn;			   // = _T("Native_FlyPntVoltUcEn")
CString g_sLangTxt_Native_FlyPntVoltUcEn;			   // = _T("飞点电压Uc使能")
CString g_sLangID_Native_FlyPntCurrIaEn;			   // = _T("Native_FlyPntCurrIaEn")
CString g_sLangTxt_Native_FlyPntCurrIaEn;			   // = _T("飞点电流Ia使能")
CString g_sLangID_Native_FlyPntCurrIbEn;			   // = _T("Native_FlyPntCurrIbEn")
CString g_sLangTxt_Native_FlyPntCurrIbEn;			   // = _T("飞点电流Ib使能")
CString g_sLangID_Native_FlyPntCurrIcEn;			   // = _T("Native_FlyPntCurrIcEn")
CString g_sLangTxt_Native_FlyPntCurrIcEn;			   // = _T("飞点电流Ic使能")
CString g_sLangID_Native_JitterValns;				   // = _T("Native_JitterVal")
CString g_sLangTxt_Native_JitterValns;				   // = _T("抖动值(单位ns)")
CString g_sLangID_Native_Valid;						   // = _T("Native_Valid")
CString g_sLangTxt_Native_Valid;					   // = _T("有效")
CString g_sLangID_Native_Overflow;					   // = _T("Native_Overflow")
CString g_sLangTxt_Native_Overflow;					   // = _T("溢出")
CString g_sLangID_Native_OutOfRanges;				   // = _T("Native_OutOfRange")
CString g_sLangTxt_Native_OutOfRanges;				   // = _T("超值域")
CString g_sLangID_Native_BadBaseVal;				   // = _T("Native_BadBaseVal")
CString g_sLangTxt_Native_BadBaseVal;				   // = _T("坏基准值")
CString g_sLangID_Native_OldData;					   // = _T("Native_OldData")
CString g_sLangTxt_Native_OldData;					   // = _T("旧数据")
CString g_sLangID_Native_Inconsistent;				   // = _T("Native_Inconsistent")
CString g_sLangTxt_Native_Inconsistent;				   // = _T("不一致")
CString g_sLangID_Native_Inaccurate;				   // = _T("Native_Inaccurate")
CString g_sLangTxt_Native_Inaccurate;				   // = _T("不精确")
CString g_sLangID_Native_Source;					   // = _T("Native_Source")
CString g_sLangTxt_Native_Source;					   // = _T("源")
CString g_sLangID_Native_OpLock;					   // = _T("Native_OpLock")
CString g_sLangTxt_Native_OpLock;					   // = _T("操作员闭锁")
CString g_sLangID_Native_AbnPointSel;				   // = _T("Native_AbnPointSel")
CString g_sLangTxt_Native_AbnPointSel;				   // = _T("异常点选择")
CString g_sLangID_Native_AbnPoint;					   // = _T("Native_AbnPoint")
CString g_sLangTxt_Native_AbnPoint;					   // = _T("异常点")
CString g_sLangID_Native_SMVAbnParam;				   // = _T("Native_SMVAbnParam")
CString g_sLangTxt_Native_SMVAbnParam;				   // = _T("SMV异常参数")
CString g_sLangID_Native_SVAbnType;					   // = _T("Native_SVAbnType")
CString g_sLangTxt_Native_SVAbnType;				   // = _T("SV异常类型")
CString g_sLangID_Native_SVMsgGrpNum;				   // = _T("Native_SVMsgGrpNum")
CString g_sLangTxt_Native_SVMsgGrpNum;				   // = _T("SV报文组号(从0开始编号)")
CString g_sLangID_Native_SendFreq;					   // = _T("Native_SendFreq")
CString g_sLangTxt_Native_SendFreq;					   // = _T("发送周波数(周波模式)")
CString g_sLangID_Native_SendFreqPerSec;			   // = _T("Native_SendFreqPerSec")
CString g_sLangTxt_Native_SendFreqPerSec;			   // = _T("每秒发送周波数(秒模式)")
CString g_sLangID_Native_AbnormDataSendTimeMode;	   // = _T("Native_AbnormDataSendTimeMode")
CString g_sLangTxt_Native_AbnormDataSendTimeMode;	   // = _T("异常数据发送时间模式(0-周波;1-秒)")
CString g_sLangID_Native_SVSendTimeSecMode;			   // = _T("Native_SVSendTimeSecMode")
CString g_sLangTxt_Native_SVSendTimeSecMode;		   // = _T("SV发送时间(秒模式)")
CString g_sLangID_Native_GOOSEAbnormParam;			   // = _T("Native_GOOSEAbnormParam")
CString g_sLangTxt_Native_GOOSEAbnormParam;			   // = _T("GOOSE异常参数")
CString g_sLangID_Native_AbnormGroupSeq;			   // = _T("Native_AbnormGroupSeq")
CString g_sLangTxt_Native_AbnormGroupSeq;			   // = _T("异常组序号（从0计数）")
CString g_sLangID_Native_SrcMACSelect;				   // = _T("Native_SrcMACSelect")
CString g_sLangTxt_Native_SrcMACSelect;				   // = _T("源MAC(选择)")
CString g_sLangID_Native_DestMACSelect;				   // = _T("Native_DestMACSelect")
CString g_sLangTxt_Native_DestMACSelect;			   // = _T("目标MAC(选择)")
CString g_sLangID_Native_GocbRefSelect;				   // = _T("Native_GocbRefSelect")
CString g_sLangTxt_Native_GocbRefSelect;			   // = _T("GocbRef(选择)")
CString g_sLangID_Native_GoIDSelect;				   // = _T("Native_GoIDSelect")
CString g_sLangTxt_Native_GoIDSelect;				   // = _T("GoID(选择)")
CString g_sLangID_Native_DataSetSelect;				   // = _T("Native_DataSetSelect")
CString g_sLangTxt_Native_DataSetSelect;			   // = _T("DataSet(选择)")
CString g_sLangID_Native_DestMACs;					   // = _T("Native_DestMACs")
CString g_sLangTxt_Native_DestMACs;					   // = _T("目标MAC")
CString g_sLangID_Native_AppIDSelect;				   // = _T("Native_AppIDSelect")
CString g_sLangTxt_Native_AppIDSelect;				   // = _T("AppID(选择)")
CString g_sLangID_Native_StSelect;					   // = _T("Native_StSelect")
CString g_sLangTxt_Native_StSelect;					   // = _T("St(选择)")
CString g_sLangID_Native_StValue;					   // = _T("Native_StValue")
CString g_sLangTxt_Native_StValue;					   // = _T("St值")
CString g_sLangID_Native_SqSelect;					   // = _T("Native_SqSelect")
CString g_sLangTxt_Native_SqSelect;					   // = _T("Sq(选择)")
CString g_sLangID_Native_SqValue;					   // = _T("Native_SqValue")
CString g_sLangTxt_Native_SqValue;					   // = _T("Sq值")
CString g_sLangID_Native_AllowLiveTSelect;			   // = _T("Native_AllowLiveTSelect")
CString g_sLangTxt_Native_AllowLiveTSelect;			   // = _T("允许生存时间(选择)")
CString g_sLangID_Native_AllowLiveT;				   // = _T("Native_AllowLiveT")
CString g_sLangTxt_Native_AllowLiveT;				   // = _T("允许生存时间")
CString g_sLangID_Native_DelegateSelect;			   // = _T("Native_DelegateSelect")
CString g_sLangTxt_Native_DelegateSelect;			   // = _T("委托(选择)")
CString g_sLangID_Native_TestMarkSelect;			   // = _T("Native_TestMarkSelect")
CString g_sLangTxt_Native_TestMarkSelect;			   // = _T("测试标记(选择)")
CString g_sLangID_Native_Delegate;					   // = _T("Native_Delegate")
CString g_sLangTxt_Native_Delegate;					   // = _T("委托")
CString g_sLangID_Native_TestMark;					   // = _T("Native_TestMark")
CString g_sLangTxt_Native_TestMark;					   // = _T("测试标记")
CString g_sLangID_Native_VlanIDSelect;				   // = _T("Native_VlanIDSelect")
CString g_sLangTxt_Native_VlanIDSelect;				   // = _T("VlanID(选择)")
CString g_sLangID_Native_VlanIDValue;				   // = _T("Native_VlanIDValue")
CString g_sLangTxt_Native_VlanIDValue;				   // = _T("VlanID值")
CString g_sLangID_Native_NetIDSelect;				   // = _T("Native_NetIDSelect")
CString g_sLangTxt_Native_NetIDSelect;				   // = _T("网络标识(选择)")
CString g_sLangID_Native_NetIDValue;				   // = _T("Native_NetIDValue")
CString g_sLangTxt_Native_NetIDValue;				   // = _T("网络标识值")
CString g_sLangID_Native_ConfigVerSelect;			   // = _T("Native_ConfigVerSelect")
CString g_sLangTxt_Native_ConfigVerSelect;			   // = _T("配置版本(选择)")
CString g_sLangID_Native_ConfigVerValue;			   // = _T("Native_ConfigVerValue")
CString g_sLangTxt_Native_ConfigVerValue;			   // = _T("配置版本值")
CString g_sLangID_Native_NormalOpen1State;			   // = _T("Native_NormalOpen1State")
CString g_sLangTxt_Native_NormalOpen1State;			   // = _T("常态开出1状态")
CString g_sLangID_Native_NormalOpen2State;			   // = _T("Native_NormalOpen2State")
CString g_sLangTxt_Native_NormalOpen2State;			   // = _T("常态开出2状态")
CString g_sLangID_Native_NormalOpen3State;			   // = _T("Native_NormalOpen3State")
CString g_sLangTxt_Native_NormalOpen3State;			   // = _T("常态开出3状态")
CString g_sLangID_Native_NormalOpen4State;			   // = _T("Native_NormalOpen4State")
CString g_sLangTxt_Native_NormalOpen4State;			   // = _T("常态开出4状态")
CString g_sLangID_Native_NormalOpen5State;			   // = _T("Native_NormalOpen5State")
CString g_sLangTxt_Native_NormalOpen5State;			   // = _T("常态开出5状态")
CString g_sLangID_Native_NormalOpen6State;			   // = _T("Native_NormalOpen6State")
CString g_sLangTxt_Native_NormalOpen6State;			   // = _T("常态开出6状态")
CString g_sLangID_Native_NormalOpen7State;			   // = _T("Native_NormalOpen7State")
CString g_sLangTxt_Native_NormalOpen7State;			   // = _T("常态开出7状态")
CString g_sLangID_Native_NormalOpen8State;			   // = _T("Native_NormalOpen8State")
CString g_sLangTxt_Native_NormalOpen8State;			   // = _T("常态开出8状态")
CString g_sLangID_Native_FaultOpen1State;			   // = _T("Native_FaultOpen1State")
CString g_sLangTxt_Native_FaultOpen1State;			   // = _T("故障态开出1状态")
CString g_sLangID_Native_FaultOpen2State;			   // = _T("Native_FaultOpen2State")
CString g_sLangTxt_Native_FaultOpen2State;			   // = _T("故障态开出2状态")
CString g_sLangID_Native_FaultOpen3State;			   // = _T("Native_FaultOpen3State")
CString g_sLangTxt_Native_FaultOpen3State;			   // = _T("故障态开出3状态")
CString g_sLangID_Native_FaultOpen4State;			   // = _T("Native_FaultOpen4State")
CString g_sLangTxt_Native_FaultOpen4State;			   // = _T("故障态开出4状态")
CString g_sLangID_Native_FaultOpen5State;			   // = _T("Native_FaultOpen5State")
CString g_sLangTxt_Native_FaultOpen5State;			   // = _T("故障态开出5状态")
CString g_sLangID_Native_FaultOpen6State;			   // = _T("Native_FaultOpen6State")
CString g_sLangTxt_Native_FaultOpen6State;			   // = _T("故障态开出6状态")
CString g_sLangID_Native_FaultOpen7State;			   // = _T("Native_FaultOpen7State")
CString g_sLangTxt_Native_FaultOpen7State;			   // = _T("故障态开出7状态")
CString g_sLangID_Native_FaultOpen8State;			   // = _T("Native_FaultOpen8State")
CString g_sLangTxt_Native_FaultOpen8State;			   // = _T("故障态开出8状态")
CString g_sLangID_Native_HotOverloadTimeConst;		   // = _T("Native_HotOTC")
CString g_sLangTxt_Native_HotOverloadTimeConst;		   // = _T("热过负荷时间常数")
CString g_sLangID_Native_HotOverloadBaseCurrent;	   // = _T("Native_HotOBC")
CString g_sLangTxt_Native_HotOverloadBaseCurrent;	   // = _T("热过负荷基数电流")
CString g_sLangID_Native_HotOverloadActionValue;	   // = _T("Native_HotOAV")
CString g_sLangTxt_Native_HotOverloadActionValue;	   // = _T("热过负荷动作定值")
CString g_sLangID_Native_OverloadCurrent;			   // = _T("Native_OverloadC")
CString g_sLangTxt_Native_OverloadCurrent;			   // = _T("过负荷电流")
CString g_sLangID_Native_FaultTimeMargin;			   // = _T("Native_FaultTM")
CString g_sLangTxt_Native_FaultTimeMargin;			   // = _T("故障时间裕度")
CString g_sLangID_Native_CurrentChangeStartValue;	   // = _T("Native_CurrChngStartV")
CString g_sLangTxt_Native_CurrentChangeStartValue;	   // = _T("电流变化始值")
CString g_sLangID_Native_CurrentChangeEndValue;		   // = _T("Native_CurrChngEndV")
CString g_sLangTxt_Native_CurrentChangeEndValue;	   // = _T("电流变化终值")
CString g_sLangID_Native_CurrentChangeStep;			   // = _T("Native_CurrChngStep")
CString g_sLangTxt_Native_CurrentChangeStep;		   // = _T("电流变化步长")
CString g_sLangID_Native_HotOverloadTime;			   // = _T("Native_HotOTConst")
CString g_sLangTxt_Native_HotOverloadTime;			   // = _T("热过负荷时间常数(表达式)")
CString g_sLangID_Native_HotOverloadBaseCurr;		   // = _T("Native_HotOBaseCurr")
CString g_sLangTxt_Native_HotOverloadBaseCurr;		   // = _T("热过负荷基数电流(表达式)")
CString g_sLangID_Native_HotOverloadActionValues;	   // = _T("Native_HotOActionVals")
CString g_sLangTxt_Native_HotOverloadActionValues;	   // = _T("热过负荷动作定值(表达式)")
CString g_sLangID_Native_ActionDesc;				   // = _T("Native_ActionDesc")
CString g_sLangTxt_Native_ActionDesc;				   // = _T("动作描述")
CString g_sLangID_Native_FaultPreVoltageAmp;		   // = _T("Native_FltPreVAmp")
CString g_sLangTxt_Native_FaultPreVoltageAmp;		   // = _T("故障前电压幅值")
CString g_sLangID_Native_FaultPreCurrentAmp;		   // = _T("Native_FltPreCAmp")
CString g_sLangTxt_Native_FaultPreCurrentAmp;		   // = _T("故障前电流幅值")
CString g_sLangID_Native_FaultPreVoltageCurrentPhase;  // = _T("Native_FltPreVCP")
CString g_sLangTxt_Native_FaultPreVoltageCurrentPhase; // = _T("故障前电压电流相角(U-I)")
CString g_sLangID_Native_FaultPreVoltageSeq;		   // = _T("Native_FltPreVSeq")
CString g_sLangTxt_Native_FaultPreVoltageSeq;		   // = _T("故障前电压相序")
CString g_sLangID_Native_FaultPreCurrentSeq;		   // = _T("Native_FltPreCSeq")
CString g_sLangTxt_Native_FaultPreCurrentSeq;		   // = _T("故障前电流相序")
CString g_sLangID_Native_FaultVoltage;				   // = _T("Native_FltVoltage")
CString g_sLangTxt_Native_FaultVoltage;				   // = _T("故障电压")
CString g_sLangID_Native_FaultVoltageCurrentPhase;	   // = _T("Native_FltVCP")
CString g_sLangTxt_Native_FaultVoltageCurrentPhase;	   // = _T("故障态电压电流相角(U-I)")
CString g_sLangID_Native_ShortCircuitVoltageType;	   // = _T("Native_SCVT")
CString g_sLangTxt_Native_ShortCircuitVoltageType;	   // = _T("短路电压类别")
CString g_sLangID_Native_ReferenceValue;			   // = _T("Native_RefVal")
CString g_sLangTxt_Native_ReferenceValue;			   // = _T("基准值")
CString g_sLangID_Native_CTPolarityPositive;		   // = _T("Native_CTPP")
CString g_sLangTxt_Native_CTPolarityPositive;		   // = _T("CT正极性")
CString g_sLangID_Native_PreFaultVCPAExpr;			   // = _T("Native_PFVCPAE")
CString g_sLangTxt_Native_PreFaultVCPAExpr;			   // = _T("故障前电压电流相角(表达式)")
CString g_sLangID_Native_ActionTimeSetValueExpr;	   // = _T("Native_ATSE")
CString g_sLangTxt_Native_ActionTimeSetValueExpr;	   // = _T("动作时间定值(表达式)")
CString g_sLangID_Native_FaultVoltageExpr;			   // = _T("Native_FVE")
CString g_sLangTxt_Native_FaultVoltageExpr;			   // = _T("故障电压(表达式)")
CString g_sLangID_Native_FaultCurr;					   // = _T("Native_FaultCurr")
CString g_sLangTxt_Native_FaultCurr;				   // = _T("故障电流(表达式)")
CString g_sLangID_Native_FaultAngExp;				   // = _T("Native_FaultAngExp")
CString g_sLangTxt_Native_FaultAngExp;				   // = _T("故障态电压电流相角(表达式)")
CString g_sLangID_Native_CharCurveParam;			   // = _T("Native_CharCurveParam")
CString g_sLangTxt_Native_CharCurveParam;			   // = _T("特性曲线参数(Vp)")
CString g_sLangID_Native_VoltFreqRatio;				   // = _T("Native_VoltFreqRatio")
CString g_sLangTxt_Native_VoltFreqRatio;			   // = _T("电压频率比")
CString g_sLangID_Native_ChangeMode;				   // = _T("Native_ChangeMode")
CString g_sLangTxt_Native_ChangeMode;				   // = _T("变化方式 0-频率不变,增电压  1-电压不变,降频率")
CString g_sLangID_Native_CollectModPos;				   // = _T("Native_CollectModPos")
CString g_sLangTxt_Native_CollectModPos;			   // = _T("采集模块位置")
CString g_sLangID_Native_CollectGear;				   // = _T("Native_CollectGear")
CString g_sLangTxt_Native_CollectGear;				   // = _T("采集档位")
CString g_sLangID_Native_ModPos;					   // = _T("Native_ModPos")
CString g_sLangTxt_Native_ModPos;					   // = _T("模块位置")
CString g_sLangID_Native_TempZone;					   // = _T("Native_TempZone")
CString g_sLangTxt_Native_TempZone;					   // = _T("温区")
CString g_sLangID_Native_MeterError;				   // = _T("Native_MeterError")
CString g_sLangTxt_Native_MeterError;				   // = _T("表计误差")
CString g_sLangID_Native_RefFreq;					   // = _T("Native_RefFreq")
CString g_sLangTxt_Native_RefFreq;					   // = _T("参考频率")
CString g_sLangID_Native_Point1RefAmp;				   // = _T("Native_Point1RefAmp")
CString g_sLangTxt_Native_Point1RefAmp;				   // = _T("点1参考幅值")
CString g_sLangID_Native_Point2RefAmp;				   // = _T("Native_Point2RefAmp")
CString g_sLangTxt_Native_Point2RefAmp;				   // = _T("点2参考幅值")
CString g_sLangID_Native_Point1MeasAmp;				   // = _T("Native_Point1MeasAmp")
CString g_sLangTxt_Native_Point1MeasAmp;			   // = _T("点1测量幅值")
CString g_sLangID_Native_Point2MeasAmp;				   // = _T("Native_Point2MeasAmp")
CString g_sLangTxt_Native_Point2MeasAmp;			   // = _T("点2测量幅值")
CString g_sLangID_Native_OutputAmp;					   // = _T("Native_OutputAmp")
CString g_sLangTxt_Native_OutputAmp;				   // = _T("输出幅值")
CString g_sLangID_Native_PhaseMeasVal;				   // = _T("Native_PhaseMeasVal")
CString g_sLangTxt_Native_PhaseMeasVal;				   // = _T("相位测量值")
CString g_sLangID_Native_MeasFreq;					   // = _T("Native_MeasFreq")
CString g_sLangTxt_Native_MeasFreq;					   // = _T("测量频率")
CString g_sLangID_Native_ChannelHardGear;			   // = _T("Native_ChannelHardGear")
CString g_sLangTxt_Native_ChannelHardGear;			   // = _T("通道硬件档位")
CString g_sLangID_Native_ZeroDriftMeas;				   // = _T("Native_ZeroDriftMeas")
CString g_sLangTxt_Native_ZeroDriftMeas;			   // = _T("零漂测量值")
CString g_sLangID_Native_Channel1ID;				   // = _T("Native_Channel1ID")
CString g_sLangTxt_Native_Channel1ID;				   // = _T("通道1编号")
CString g_sLangID_Native_Channel1Amp;				   // = _T("Native_Channel1Amp")
CString g_sLangTxt_Native_Channel1Amp;				   // = _T("通道1幅值")
CString g_sLangID_Native_Channel1Phase;				   // = _T("Native_Channel1Phase")
CString g_sLangTxt_Native_Channel1Phase;			   // = _T("通道1相位")
CString g_sLangID_Native_Channel1Freq;				   // = _T("Native_Channel1Freq")
CString g_sLangTxt_Native_Channel1Freq;				   // = _T("通道1频率")
CString g_sLangID_Native_Channel2Num;				   // = _T("Native_Channel2Num")
CString g_sLangTxt_Native_Channel2Num;				   // = _T("通道2编号")
CString g_sLangID_Native_Channel2Amp;				   // = _T("Native_Channel2Amp")
CString g_sLangTxt_Native_Channel2Amp;				   // = _T("通道2幅值")
CString g_sLangID_Native_Channel2Phase;				   // = _T("Native_Channel2Phase")
CString g_sLangTxt_Native_Channel2Phase;			   // = _T("通道2相位")
CString g_sLangID_Native_Channel2Freq;				   // = _T("Native_Channel2Freq")
CString g_sLangTxt_Native_Channel2Freq;				   // = _T("通道2频率")
CString g_sLangID_Native_Channel3Num;				   // = _T("Native_Channel3Num")
CString g_sLangTxt_Native_Channel3Num;				   // = _T("通道3编号")
CString g_sLangID_Native_Channel3Amp;				   // = _T("Native_Channel3Amp")
CString g_sLangTxt_Native_Channel3Amp;				   // = _T("通道3幅值")
CString g_sLangID_Native_Channel3Phase;				   // = _T("Native_Channel3Phase")
CString g_sLangTxt_Native_Channel3Phase;			   // = _T("通道3相位")
CString g_sLangID_Native_Channel3Freq;				   // = _T("Channel3Freq")
CString g_sLangTxt_Native_Channel3Freq;				   // = _T("通道3频率")
CString g_sLangID_Native_IsHighCurrentCalib;		   // = _T("IsHighCurrentCalib")
CString g_sLangTxt_Native_IsHighCurrentCalib;		   // = _T("是否大电流校准")
CString g_sLangID_Native_Channel1AmpCoeff;			   // = _T("Channel1AmpCoeff")
CString g_sLangTxt_Native_Channel1AmpCoeff;			   // = _T("通道1幅值系数")
CString g_sLangID_Native_Channel1ZeroOffset;		   // = _T("Channel1ZeroOffset")
CString g_sLangTxt_Native_Channel1ZeroOffset;		   // = _T("通道1零漂")
CString g_sLangID_Native_Channel2AmpCoeff;			   // = _T("Channel2AmpCoeff")
CString g_sLangTxt_Native_Channel2AmpCoeff;			   // = _T("通道2幅值系数")
CString g_sLangID_Native_Channel2ZeroOffset;		   // = _T("Channel2ZeroOffset")
CString g_sLangTxt_Native_Channel2ZeroOffset;		   // = _T("通道2零漂")
CString g_sLangID_Native_Channel3AmpCoeff;			   // = _T("Channel3AmpCoeff")
CString g_sLangTxt_Native_Channel3AmpCoeff;			   // = _T("通道3幅值系数")
CString g_sLangID_Native_Channel3ZeroOffset;		   // = _T("Channel3ZeroOffset")
CString g_sLangTxt_Native_Channel3ZeroOffset;		   // = _T("通道3零漂")
CString g_sLangID_Native_WaveformSelection;			   // = _T("WaveformSelection")
CString g_sLangTxt_Native_WaveformSelection;		   // = _T("波形选择")
CString g_sLangID_Native_Gear;						   // = _T("Native_Gear")
CString g_sLangTxt_Native_Gear;						   // = _T("档位")
CString g_sLangID_Native_ModuleNo2;					   // = _T("Native_ModuleNo2")
CString g_sLangTxt_Native_ModuleNo2;				   // = _T("模块编号2")
CString g_sLangID_Native_TempZone2;					   // = _T("Native_TempZone2")
CString g_sLangTxt_Native_TempZone2;				   // = _T("温区2")
CString g_sLangID_Native_ChannelNo2;				   // = _T("Native_ChannelNo2")
CString g_sLangTxt_Native_ChannelNo2;				   // = _T("通道编号2")
CString g_sLangID_Native_Gear2;						   // = _T("Native_Gear2")
CString g_sLangTxt_Native_Gear2;					   // = _T("档位2")
CString g_sLangID_Native_OutputChannel;				   // = _T("Native_OutputChannel")
CString g_sLangTxt_Native_OutputChannel;			   // = _T("输出通道")
CString g_sLangID_Native_HardwareGear;				   // = _T("Native_HardwareGear")
CString g_sLangTxt_Native_HardwareGear;				   // = _T("硬件档位")
CString g_sLangID_Native_ModuleNumber;				   // = _T("Native_ModuleNumber")
CString g_sLangTxt_Native_ModuleNumber;				   // = _T("模块编号")
CString g_sLangID_Native_SwitchMode;				   // = _T("Native_SwitchMode")
CString g_sLangTxt_Native_SwitchMode;				   // = _T("切换模式")
CString g_sLangID_Native_Output1ConductValue;		   // = _T("Native_Output1ConductValue")
CString g_sLangTxt_Native_Output1ConductValue;		   // = _T("开出1导通值")
CString g_sLangID_Native_Output2ConductValue;		   // = _T("Native_Output2ConductValue")
CString g_sLangTxt_Native_Output2ConductValue;		   // = _T("开出2导通值")
CString g_sLangID_Native_Output3ConductValue;		   // = _T("Native_Output3ConductValue")
CString g_sLangTxt_Native_Output3ConductValue;		   // = _T("开出3导通值")
CString g_sLangID_Native_Output4ConductValue;		   // = _T("Native_Output4ConductValue")
CString g_sLangTxt_Native_Output4ConductValue;		   // = _T("开出4导通值")
CString g_sLangID_Native_Output5ConductValue;		   // = _T("Native_Output5ConductValue")
CString g_sLangTxt_Native_Output5ConductValue;		   // = _T("开出5导通值")
CString g_sLangID_Native_Output6ConductValue;		   // = _T("Native_Output6ConductValue")
CString g_sLangTxt_Native_Output6ConductValue;		   // = _T("开出6导通值")
CString g_sLangID_Native_Output7ConductValue;		   // = _T("Native_Output7ConductValue")
CString g_sLangTxt_Native_Output7ConductValue;		   // = _T("开出7导通值")
CString g_sLangID_Native_Output8ConductValue;		   // = _T("Native_Output8ConductValue")
CString g_sLangTxt_Native_Output8ConductValue;		   // = _T("开出8导通值")
CString g_sLangID_Native_RegAddrHex;				   // = _T("Native_RegAddrHex")
CString g_sLangTxt_Native_RegAddrHex;				   // = _T("寄存器地址(16进制)")
CString g_sLangID_Native_RegValHex;					   // = _T("Native_RegValHex")
CString g_sLangTxt_Native_RegValHex;				   // = _T("寄存器值(16进制)")
CString g_sLangID_Native_Results;					   // = _T("Native_Results")
CString g_sLangTxt_Native_Results;					   // = _T("结果")
CString g_sLangID_Native_FlipDelay;					   // = _T("Native_FlipDelay")
CString g_sLangTxt_Native_FlipDelay;				   // = _T("开出翻转延时")
CString g_sLangID_Native_InFlipCond;				   // = _T("Native_InFlipCond")
CString g_sLangTxt_Native_InFlipCond;				   // = _T("开入量翻转判别条件")
CString g_sLangID_Native_IsSeqStateSeq;				   // = _T("Native_IsSeqStateSeq")
CString g_sLangTxt_Native_IsSeqStateSeq;			   // = _T("是否为顺序状态序列")
CString g_sLangID_Native_RepeatCount;				   // = _T("Native_RepeatCount")
CString g_sLangTxt_Native_RepeatCount;				   // = _T("重复次数")
CString g_sLangID_Native_StateNum;					   // = _T("Native_StateNum")
CString g_sLangTxt_Native_StateNum;					   // = _T("状态数")
CString g_sLangID_Native_InputExpand;				   // = _T("Native_InputExpand")
CString g_sLangTxt_Native_InputExpand;				   // = _T("开入扩展")
CString g_sLangID_Native_NActionTime;				   // = _T("Native_NActionTime")
CString g_sLangTxt_Native_NActionTime;				   // = _T("次动作时间")
CString g_sLangID_Native_LoopNum;					   // = _T("Native_LoopNum")
CString g_sLangTxt_Native_LoopNum;					   // = _T("循环序号")
CString g_sLangID_Native_StateNums;					   // = _T("Native_StateNums")
CString g_sLangTxt_Native_StateNums;				   // = _T("状态序号")
CString g_sLangID_Native_OverCurrentI;				   // = _T("Native_OverCurrentI")
CString g_sLangTxt_Native_OverCurrentI;				   // = _T("过流I段定值")
CString g_sLangID_Native_OverCurrentII;				   // = _T("Native_OverCurrentII")
CString g_sLangTxt_Native_OverCurrentII;			   // = _T("过流II段定值")
CString g_sLangID_Native_OverCurrentIII;			   // = _T("Native_OverCurrentIII")
CString g_sLangTxt_Native_OverCurrentIII;			   // = _T("过流III段定值")
CString g_sLangID_Native_OverCurrentIV;				   // = _T("Native_OverCurrentIV")
CString g_sLangTxt_Native_OverCurrentIV;			   // = _T("过流IV段定值")
CString g_sLangID_Native_OverCurrentITime;			   // = _T("Native_OverCurrentITime")
CString g_sLangTxt_Native_OverCurrentITime;			   // = _T("过流I段时间")
CString g_sLangID_Native_OverCurrentIITime;			   // = _T("Native_OverCurrentIITime")
CString g_sLangTxt_Native_OverCurrentIITime;		   // = _T("过流II段时间")
CString g_sLangID_Native_OverCurrentIIITime;		   // = _T("Native_OverCurrentIIITime")
CString g_sLangTxt_Native_OverCurrentIIITime;		   // = _T("过流III段时间")
CString g_sLangID_Native_OverCurrentIVTime;			   // = _T("Native_OverCurrentIVTime")
CString g_sLangTxt_Native_OverCurrentIVTime;		   // = _T("过流IV段时间")
CString g_sLangID_Native_Grouping;					   // = _T("Native_Grouping")
CString g_sLangTxt_Native_Grouping;					   // = _T("分组")
CString g_sLangID_Native_SetActCurExp;				   // = _T("Native_SetActCurExp")
CString g_sLangTxt_Native_SetActCurExp;				   // = _T("整定动作电流(表达式)")
CString g_sLangID_Native_OverCurrentValue;			   // = _T("Native_OverCurrentValue")
CString g_sLangTxt_Native_OverCurrentValue;			   // = _T("过流值")
// 第八周吕
CString g_sLangID_Native_volDefinition1;
CString g_sLangTxt_Native_volDefinition1; // 电压定义
CString g_sLangID_Native_refphase;
CString g_sLangTxt_Native_refphase; // 参考相

CString g_sLangID_Native_transfConnection;
CString g_sLangTxt_Native_transfConnection; // 变压器接线方式
CString g_sLangID_Native_maxSyncTime1;
CString g_sLangTxt_Native_maxSyncTime1; // 最大同步时间
CString g_sLangID_Native_breaker4HoldTime;
CString g_sLangTxt_Native_breaker4HoldTime; // 开出4保持时间
CString g_sLangID_Native_Grid_Vol;
CString g_sLangTxt_Native_Grid_Vol; // 待并侧电压
CString g_sLangID_Native_Grid_Freq;
CString g_sLangTxt_Native_Grid_Freq; // 待并侧频率
CString g_sLangID_Native_syncSignal;
CString g_sLangTxt_Native_syncSignal; // 同期信号
CString g_sLangID_Native_boostSignal;
CString g_sLangTxt_Native_boostSignal; // 增压信号
CString g_sLangID_Native_boostFreqSignal;
CString g_sLangTxt_Native_boostFreqSignal; // 增频信号
CString g_sLangID_Native_reducePresSignal;
CString g_sLangTxt_Native_reducePresSignal; // 减压信号
CString g_sLangID_Native_reduceFreqSignal;
CString g_sLangTxt_Native_reduceFreqSignal; // 减频信号
CString g_sLangID_Native_OutPut;
CString g_sLangTxt_Native_OutPut; // 开出%d
CString g_sLangID_Native_GvolChangeStep;
CString g_sLangTxt_Native_GvolChangeStep; // 待并侧电压变化步长
CString g_sLangID_Native_GridVol_Exp;
CString g_sLangTxt_Native_GridVol_Exp; // 待并侧电压(表达式)
CString g_sLangID_Native_GridFreq_Exp;
CString g_sLangTxt_Native_GridFreq_Exp; // 待并侧频率(表达式)
CString g_sLangID_Native_GvolChangeStepExp;
CString g_sLangTxt_Native_GvolChangeStepExp; // 待并侧电压变化步长(表达式)
CString g_sLangID_Native_GfreqChangeStep;
CString g_sLangTxt_Native_GfreqChangeStep; // 待并侧频率变化步长
CString g_sLangID_Native_GfreqChangeStepExp;
CString g_sLangTxt_Native_GfreqChangeStepExp; // 待并侧频率变化步长(表达式)
CString g_sLangID_Native_FreqSlip;
CString g_sLangTxt_Native_FreqSlip; // 频率滑差
CString g_sLangID_Native_VoltSlip_Exp;
CString g_sLangTxt_Native_VoltSlip_Exp; // 电压滑差(表达式)
CString g_sLangID_Native_FreqSlip_Exp;
CString g_sLangTxt_Native_FreqSlip_Exp; // 频率滑差(表达式)
CString g_sLangID_Native_RegulatePulseWidth;
CString g_sLangTxt_Native_RegulatePulseWidth; // 调压脉宽
CString g_sLangID_Native_FrequencyPulseWidth;
CString g_sLangTxt_Native_FrequencyPulseWidth; // 调频脉宽

CString g_sLangID_Native_AngleStartPar1;
CString g_sLangTxt_Native_AngleStartPar1; // 功角始值
CString g_sLangID_Native_AngleEndPar1;
CString g_sLangTxt_Native_AngleEndPar1; // 功角终值
CString g_sLangID_Native_OscilPeriod1;
CString g_sLangTxt_Native_OscilPeriod1; // 振荡周期
CString g_sLangID_Native_TripAccessPoint;
CString g_sLangTxt_Native_TripAccessPoint; // 跳闸接入点
CString g_sLangID_Native_ReOscillat_ornot;
CString g_sLangTxt_Native_ReOscillat_ornot; // 是否往复振荡
CString g_sLangID_Native_SpeedChange;
CString g_sLangTxt_Native_SpeedChange; // 速度变化选择
CString g_sLangID_Native_ImpedanceChange_ornot;
CString g_sLangTxt_Native_ImpedanceChange_ornot; // 是否变阻抗
CString g_sLangID_Native_ImpedanceRateChange;
CString g_sLangTxt_Native_ImpedanceRateChange; // 阻抗变化率

CString g_sLangID_Native_zeroseq_comp_calculat1;
CString g_sLangTxt_Native_zeroseq_comp_calculat1; // 零序补偿系数计算方式
CString g_sLangID_Native_ZeroSeqComp1;
CString g_sLangTxt_Native_ZeroSeqComp1; // 零序补偿系数(|K0|$KR$|Z0/Z1|)
CString g_sLangID_Native_ZeroSeqComp2;
CString g_sLangTxt_Native_ZeroSeqComp2; // 零序补偿系数(Phi(K0)$KX$Phi(Z0/Z1))

CString g_sLangID_Native_SysImpedAngle;
CString g_sLangTxt_Native_SysImpedAngle; // 系统侧阻抗角
CString g_sLangID_Native_TransImpedAngle;
CString g_sLangTxt_Native_TransImpedAngle; // 变压器阻抗角
CString g_sLangID_Native_GeneTransImped;
CString g_sLangTxt_Native_GeneTransImped; // 发电机暂态阻抗

CString g_sLangID_Out4_Situation;
CString g_sLangTxt_Out4_Situation; // 开出4状态
CString g_sLangID_Out5_Situation;
CString g_sLangTxt_Out5_Situation; // 开出5状态
CString g_sLangID_Out6_Situation;
CString g_sLangTxt_Out6_Situation; // 开出6状态
CString g_sLangID_Out7_Situation;
CString g_sLangTxt_Out7_Situation; // 开出7状态
CString g_sLangID_Out8_Situation;
CString g_sLangTxt_Out8_Situation; // 开出8状态
CString g_sLangID_Native_ProtRelayTime1;
CString g_sLangTxt_Native_ProtRelayTime1; // 保护出口时间
CString g_sLangID_Native_AccelSigOutTime1;
CString g_sLangTxt_Native_AccelSigOutTime1; // 加速信号出口时间
CString g_sLangID_Native_DecelSigOutTime1;
CString g_sLangTxt_Native_DecelSigOutTime1; // 减速信号出口时间

CString g_sLangID_Native_VariablePhaseChange;
CString g_sLangTxt_Native_VariablePhaseChange; // 递变相别
CString g_sLangID_Native_PreTestTimeS;
CString g_sLangTxt_Native_PreTestTimeS; // 测试前时间(秒)
CString g_sLangID_Native_FaultPreTimeS;
CString g_sLangTxt_Native_FaultPreTimeS; // 故障前时间(秒)
CString g_sLangID_Native_FaultPreUIPhaseAngle;
CString g_sLangTxt_Native_FaultPreUIPhaseAngle; // 故障前电压电流相角(U-I)
CString g_sLangID_Native_VariableMode0123;
CString g_sLangTxt_Native_VariableMode0123; // 递变模式(0-单机模式1-电压递变 2-电流递变 3-单机分组模式)
CString g_sLangID_Native_TestReturnCoefficient;
CString g_sLangTxt_Native_TestReturnCoefficient; // 测试返回系数
CString g_sLangID_Native_TestChannelType;
CString g_sLangTxt_Native_TestChannelType; // 测试通道类型
CString g_sLangID_Native_VariableType;
CString g_sLangTxt_Native_VariableType; // 递变类型

CString g_sLangID_Native_PhaseShiftDir01;
CString g_sLangTxt_Native_PhaseShiftDir01; // 相位递变方向(0:逆时针 1:顺时针)
CString g_sLangID_Native_IBeforeChange;
CString g_sLangTxt_Native_IBeforeChange; // 变化前电流幅值
CString g_sLangID_Native_FaultGroup1VAmp;
CString g_sLangTxt_Native_FaultGroup1VAmp; // 故障态组1电压幅值
CString g_sLangID_Native_FaultGroup1IAmp;
CString g_sLangTxt_Native_FaultGroup1IAmp; // 故障态组1电流幅值
CString g_sLangID_Native_FaultGroupIPhaseDiff;
CString g_sLangTxt_Native_FaultGroupIPhaseDiff; // 故障态两组电流角差
CString g_sLangID_Native_FaultGroupFreq;
CString g_sLangTxt_Native_FaultGroupFreq; // 故障态频率

CString g_sLangID_Native_VActionValueAbsErr;
CString g_sLangTxt_Native_VActionValueAbsErr; // 电压动作值绝对误差
CString g_sLangID_Native_VActionValueRelErr;
CString g_sLangTxt_Native_VActionValueRelErr; // 电压动作值相对误差
CString g_sLangID_Native_VActionValueErrLogic;
CString g_sLangTxt_Native_VActionValueErrLogic; // 电压动作值误差判断逻辑
CString g_sLangID_Native_IActionValueAbsErr;
CString g_sLangTxt_Native_IActionValueAbsErr; // 电流动作值绝对误差
CString g_sLangID_Native_IActionValueRelErr;
CString g_sLangTxt_Native_IActionValueRelErr; // 电流动作值相对误差
CString g_sLangID_Native_IActionValueErrLogic;
CString g_sLangTxt_Native_IActionValueErrLogic; // 电流动作值误差判断逻辑
CString g_sLangID_Native_CoefficientAbsErr;
CString g_sLangTxt_Native_CoefficientAbsErr; // 返回系数绝对误差
CString g_sLangID_Native_CoefficientRelErr;
CString g_sLangTxt_Native_CoefficientRelErr; // 返回系数相对误差
CString g_sLangID_Native_CoefficientErrLogic;
CString g_sLangTxt_Native_CoefficientErrLogic; // 返回系数误差判断逻辑

CString g_sLangID_Native_relativeErr;
CString g_sLangTxt_Native_relativeErr; // 相对误差有效
CString g_sLangID_Native_criteria_logic;
CString g_sLangTxt_Native_criteria_logic; // 判据逻辑
CString g_sLangID_Native_VActionValueErr;
CString g_sLangTxt_Native_VActionValueErr; // 电压动作值误差
CString g_sLangID_Native_IActionValueErr;
CString g_sLangTxt_Native_IActionValueErr; // 电流动作值误差
CString g_sLangID_Native_input1_ActionVal;
CString g_sLangTxt_Native_input1_ActionVal; // 开入1动作值
CString g_sLangID_Native_input2_ActionVal;
CString g_sLangTxt_Native_input2_ActionVal; // 开入2动作值
CString g_sLangID_Native_input3_ActionVal;
CString g_sLangTxt_Native_input3_ActionVal; // 开入3动作值
CString g_sLangID_Native_input4_ActionVal;
CString g_sLangTxt_Native_input4_ActionVal; // 开入4动作值
CString g_sLangID_Native_input5_ActionVal;
CString g_sLangTxt_Native_input5_ActionVal; // 开入5动作值
CString g_sLangID_Native_input6_ActionVal;
CString g_sLangTxt_Native_input6_ActionVal; // 开入6动作值
CString g_sLangID_Native_input7_ActionVal;
CString g_sLangTxt_Native_input7_ActionVal; // 开入7动作值
CString g_sLangID_Native_input8_ActionVal;
CString g_sLangTxt_Native_input8_ActionVal; // 开入8动作值

// 4
CString g_sLangID_Native_YNaging_test;
CString g_sLangTxt_Native_YNaging_test; // 是否老化试验
CString g_sLangID_Native_varchannel_select;
CString g_sLangTxt_Native_varchannel_select; // 递变通道选择
CString g_sLangID_Native_vartype_select;
CString g_sLangTxt_Native_vartype_select; // 递变类型选择
CString g_sLangID_Native_change_mode;
CString g_sLangTxt_Native_change_mode; // 变化模式
CString g_sLangID_Native_step_time;
CString g_sLangTxt_Native_step_time; // 每步时间
CString g_sLangID_Native_trigger_delay;
CString g_sLangTxt_Native_trigger_delay; // 触发延时
CString g_sLangID_Native_YN_locked;
CString g_sLangTxt_Native_YN_locked; // 是否锁定
CString g_sLangID_Native_YN_autoevo;
CString g_sLangTxt_Native_YN_autoevo; // 是否自动递变
CString g_sLangID_Native_max_outputtime;
CString g_sLangTxt_Native_max_outputtime; // 最长输出时间(s)
CString g_sLangID_Native_acttuning_time;
CString g_sLangTxt_Native_acttuning_time; // 动作整定时间
CString g_sLangID_Native_ActTimeValueAbsErr;
CString g_sLangTxt_Native_ActTimeValueAbsErr; // 动作时间值绝对误差
CString g_sLangID_Native_ActTimeValueRelErr;
CString g_sLangTxt_Native_ActTimeValueRelErr; // 动作时间值相对误差
CString g_sLangID_Native_ActTimeValueErrLogic;
CString g_sLangTxt_Native_ActTimeValueErrLogic; // 动作时间误差判断逻辑
CString g_sLangID_Native_PhaseActValueAbsErr;
CString g_sLangTxt_Native_PhaseActValueAbsErr; // 相位动作值绝对误差
CString g_sLangID_Native_PhaseActValueRelErr;
CString g_sLangTxt_Native_PhaseActValueRelErr; // 相位动作值相对误差
CString g_sLangID_Native_PhaseActValueErrLogic;
CString g_sLangTxt_Native_PhaseActValueErrLogic; // 相位动作值误差判断逻辑
CString g_sLangID_Native_action_mark;
CString g_sLangTxt_Native_action_mark; // 动作标记
CString g_sLangID_Native_result_status;
CString g_sLangTxt_Native_result_status; // 结果状态
CString g_sLangID_Native_extend;
CString g_sLangTxt_Native_extend; // 扩展%d

// 5
CString g_sLangID_Native_KeepTime;
CString g_sLangTxt_Native_KeepTime; // 保持时间
CString g_sLangID_Native_SteadyTime;
CString g_sLangTxt_Native_SteadyTime; // 稳态时间
CString g_sLangID_Native_LowFreActValue;
CString g_sLangTxt_Native_LowFreActValue; // 低频动作值

CString g_sLangID_Native_InputASelect;
CString g_sLangTxt_Native_InputASelect; // 开入A-J选择
CString g_sLangID_Native_InputBSelect;
CString g_sLangTxt_Native_InputBSelect;
CString g_sLangID_Native_InputCSelect;
CString g_sLangTxt_Native_InputCSelect;
CString g_sLangID_Native_InputDSelect;
CString g_sLangTxt_Native_InputDSelect;
CString g_sLangID_Native_InputESelect;
CString g_sLangTxt_Native_InputESelect;
CString g_sLangID_Native_InputFSelect;
CString g_sLangTxt_Native_InputFSelect;
CString g_sLangID_Native_InputGSelect;
CString g_sLangTxt_Native_InputGSelect;
CString g_sLangID_Native_InputHSelect;
CString g_sLangTxt_Native_InputHSelect;
CString g_sLangID_Native_InputISelect;
CString g_sLangTxt_Native_InputISelect;
CString g_sLangID_Native_InputJSelect;
CString g_sLangTxt_Native_InputJSelect;

CString g_sLangID_Native_FreInitialValue;
CString g_sLangTxt_Native_FreInitialValue; // 频率变化始值
CString g_sLangID_Native_FreFinalValue;
CString g_sLangTxt_Native_FreFinalValue; // 频率变化终值
CString g_sLangID_Native_FreChangeStep;
CString g_sLangTxt_Native_FreChangeStep; // 频率变化步长
CString g_sLangID_Native_FreFinal;
CString g_sLangTxt_Native_FreFinal; // 频率终值
CString g_sLangID_Native_IChangePhase;
CString g_sLangTxt_Native_IChangePhase; // 电流变化相
CString g_sLangID_Native_SearchslipVal;
CString g_sLangTxt_Native_SearchslipVal; // 当前搜索滑差值(dfdt)
CString g_sLangID_Native_KeepTimeExp;
CString g_sLangTxt_Native_KeepTimeExp; // 保持时间(表达式)
CString g_sLangID_Native_FreInitialValueExp;
CString g_sLangTxt_Native_FreInitialValueExp; // 频率变化始值(表达式)
CString g_sLangID_Native_FreFinalValueExp;
CString g_sLangTxt_Native_FreFinalValueExp; // 频率变化终值(表达式)
CString g_sLangID_Native_FreChangeStepExp;
CString g_sLangTxt_Native_FreChangeStepExp; // 频率变化步长(表达式)
CString g_sLangID_Native_SlipInitialValueExp;
CString g_sLangTxt_Native_SlipInitialValueExp; // 滑差变化始值(表达式)
CString g_sLangID_Native_SlipFinalValueExp;
CString g_sLangTxt_Native_SlipFinalValueExp; // 滑差变化终值(表达式)
CString g_sLangID_Native_SlipChangeStepExp;
CString g_sLangTxt_Native_SlipChangeStepExp; // 滑差变化步长(表达式)
CString g_sLangID_Native_IInitialValueExp;
CString g_sLangTxt_Native_IInitialValueExp; // 电流变化始值(表达式)
CString g_sLangID_Native_IFinalValueExp;
CString g_sLangTxt_Native_IFinalValueExp; // 电流变化终值(表达式)
CString g_sLangID_Native_IChangeStepExp;
CString g_sLangTxt_Native_IChangeStepExp; // 电流变化步长(表达式)
CString g_sLangID_Native_VInitialValueExp;
CString g_sLangTxt_Native_VInitialValueExp; // 电压变化始值(表达式)
CString g_sLangID_Native_VFinalValueExp;
CString g_sLangTxt_Native_VFinalValueExp; // 电压变化终值(表达式)
CString g_sLangID_Native_VChangeStepExp;
CString g_sLangTxt_Native_VChangeStepExp; // 电压变化步长(表达式)

CString g_sLangID_Native_FreActValue;
CString g_sLangTxt_Native_FreActValue; // 频率动作值
CString g_sLangID_Native_LowCycleActDesc;
CString g_sLangTxt_Native_LowCycleActDesc; // 低周动作描述
CString g_sLangID_Native_SlipActValue;
CString g_sLangTxt_Native_SlipActValue; // 滑差动作值
CString g_sLangID_Native_VBlockValue;
CString g_sLangTxt_Native_VBlockValue; // 电压闭锁值
CString g_sLangID_Native_IBlockValue;
CString g_sLangTxt_Native_IBlockValue; // 电流闭锁值

CString g_sLangID_Native_VChangeRate_blockVal;
CString g_sLangTxt_Native_VChangeRate_blockVal; // 电压变化率闭锁值
CString g_sLangID_Native_SearchslipVal2;
CString g_sLangTxt_Native_SearchslipVal2; // 当前搜索滑差值(dvdt)
CString g_sLangID_Native_LowVActionDesc;
CString g_sLangTxt_Native_LowVActionDesc; // 低压动作描述

CString g_sLangID_Native_Uab1Amp;
CString g_sLangTxt_Native_Uab1Amp; // Uab1幅值
CString g_sLangID_Native_Uab1Ph;
CString g_sLangTxt_Native_Uab1Ph; // Uab1相位
CString g_sLangID_Native_Uab1Fre;
CString g_sLangTxt_Native_Uab1Fre; // Uab1频率
CString g_sLangID_Native_3U0_1Amp;
CString g_sLangTxt_Native_3U0_1Amp; // 3U0_1幅值
CString g_sLangID_Native_3U0_1Ph;
CString g_sLangTxt_Native_3U0_1Ph; // 3U0_1相位
CString g_sLangID_Native_3U0_1Fre;
CString g_sLangTxt_Native_3U0_1Fre; // 3U0_1频率
CString g_sLangID_Native_Uab2Amp;
CString g_sLangTxt_Native_Uab2Amp; // Uab2幅值
CString g_sLangID_Native_Uab2Ph;
CString g_sLangTxt_Native_Uab2Ph; // Uab2相位
CString g_sLangID_Native_Uab2Fre;
CString g_sLangTxt_Native_Uab2Fre; // Uab2频率
CString g_sLangID_Native_3U0_2Amp;
CString g_sLangTxt_Native_3U0_2Amp; // 3U0_2幅值
CString g_sLangID_Native_3U0_2Ph;
CString g_sLangTxt_Native_3U0_2Ph; // 3U0_2相位
CString g_sLangID_Native_3U0_2Fre;
CString g_sLangTxt_Native_3U0_2Fre; // 3U0_2频率
CString g_sLangID_Native_Ia1Fre;
CString g_sLangTxt_Native_Ia1Fre; // Ia1频率
CString g_sLangID_Native_Ib1Fre;
CString g_sLangTxt_Native_Ib1Fre; // Ib1频率
CString g_sLangID_Native_Ic1Fre;
CString g_sLangTxt_Native_Ic1Fre; // Ic1频率
CString g_sLangID_Native_Ia2Fre;
CString g_sLangTxt_Native_Ia2Fre; // Ia2频率
CString g_sLangID_Native_Ib2Fre;
CString g_sLangTxt_Native_Ib2Fre; // Ib2频率
CString g_sLangID_Native_Ic2Fre;
CString g_sLangTxt_Native_Ic2Fre; // Ic2频率
CString g_sLangID_Native_AuxiDCI;
CString g_sLangTxt_Native_AuxiDCI; // 辅助直流电流
CString g_sLangID_Native_AuxiDCV;
CString g_sLangTxt_Native_AuxiDCV; // 辅助直流电压

CString g_sLangID_Native_syspowerImp;
CString g_sLangTxt_Native_syspowerImp; // 系统电源阻抗
CString g_sLangID_Native_syspowerImpangle;
CString g_sLangTxt_Native_syspowerImpangle; // 系统电源阻抗角
CString g_sLangID_Native_syscomputModel012;
CString g_sLangTxt_Native_syscomputModel012; // 系统计算模型(0-电流不变 1-电压不变 2-系统阻抗不变)
CString g_sLangID_Native_fault_switchtime;
CString g_sLangTxt_Native_fault_switchtime; // 故障转换时间
CString g_sLangID_Native_switchErrtype;
CString g_sLangTxt_Native_switchErrtype; // 转换故障类型
CString g_sLangID_Native_switchErr_shortImp;
CString g_sLangTxt_Native_switchErr_shortImp; // 转换故障短路阻抗
CString g_sLangID_Native_switchErr_shortImpAng;
CString g_sLangTxt_Native_switchErr_shortImpAng; // 转换故障短路阻抗角
CString g_sLangID_Native_switchErr_shortI;
CString g_sLangTxt_Native_switchErr_shortI; // 转换故障短路电流
CString g_sLangID_Native_switchErr_shortV;
CString g_sLangTxt_Native_switchErr_shortV; // 转换故障短路电压
CString g_sLangID_Native_switchErr_direction;
CString g_sLangTxt_Native_switchErr_direction; // 转换故障故障方向
CString g_sLangID_Native_testprocess;
CString g_sLangTxt_Native_testprocess; // 试验过程
CString g_sLangID_Native_redundancy_mode;
CString g_sLangTxt_Native_redundancy_mode; // 重合方式
CString g_sLangID_Native_redundancy_duration;
CString g_sLangTxt_Native_redundancy_duration; // 重合持续时间
CString g_sLangID_Native_postswitch_duration;
CString g_sLangTxt_Native_postswitch_duration; // 后加速开关跳开后持续时间

// 9week ly
CString g_sLangID_Native_change_startangle;
CString g_sLangTxt_Native_change_startangle; // 变化起始角度
CString g_sLangID_Native_change_endangle;
CString g_sLangTxt_Native_change_endangle; // 变化终止角度
CString g_sLangID_Native_impedanceAng_measured;
CString g_sLangTxt_Native_impedanceAng_measured; // 待测阻抗角度定值
CString g_sLangID_Native_search_way;
CString g_sLangTxt_Native_search_way; // 搜索方式
CString g_sLangID_Native_Zsearch_startAng;
CString g_sLangTxt_Native_Zsearch_startAng; // Z搜索起点角度
CString g_sLangID_Native_Zsearch_startAct;
CString g_sLangTxt_Native_Zsearch_startAct; // Z搜索起点动作
CString g_sLangID_Native_ZAng_currentVal;
CString g_sLangTxt_Native_ZAng_currentVal; // Z当前值角度
CString g_sLangID_Native_Zsearch_endAng;
CString g_sLangTxt_Native_Zsearch_endAng; // Z搜索终点角度
CString g_sLangID_Native_Zsearch_endAct;
CString g_sLangTxt_Native_Zsearch_endAct; // Z搜索终点动作
CString g_sLangID_Native_action_impedance;
CString g_sLangTxt_Native_action_impedance; // 动作阻抗
CString g_sLangID_Native_action_impedanceAng;
CString g_sLangTxt_Native_action_impedanceAng; // 动作阻抗角
CString g_sLangID_Native_Desc_impedance_Act;
CString g_sLangTxt_Native_Desc_impedance_Act; // 阻抗动作描述

//
CString g_sLangID_Native_impedance_setting;
CString g_sLangTxt_Native_impedance_setting; // 阻抗定值
CString g_sLangID_Native_impedance_setExp;
CString g_sLangTxt_Native_impedance_setExp; // 阻抗定值(表达式)

//
CString g_sLangID_Native_ZeroSeqCompExp;
CString g_sLangTxt_Native_ZeroSeqCompExp; // 零序补偿系数表达方式
CString g_sLangID_Native_ZeroSeqComp_RERL;
CString g_sLangTxt_Native_ZeroSeqComp_RERL; // 零序补偿系数RE/RL
CString g_sLangID_Native_ZeroSeqComp_XEXL;
CString g_sLangTxt_Native_ZeroSeqComp_XEXL; // 零序补偿系数XE/XL
CString g_sLangID_Native_load_current;
CString g_sLangTxt_Native_load_current; // 负荷电流
CString g_sLangID_Native_loadpowerAng;
CString g_sLangTxt_Native_loadpowerAng; // 负荷功角
CString g_sLangID_Native_PT_installPos;
CString g_sLangTxt_Native_PT_installPos; // PT安装位置
CString g_sLangID_Native_closeAngmode01;
CString g_sLangTxt_Native_closeAngmode01; // 合闸角方式( 0-随机 1-定值)
CString g_sLangID_Native_closing_angle;
CString g_sLangTxt_Native_closing_angle; // 合闸角
CString g_sLangID_Native_Vz_outputDef;
CString g_sLangTxt_Native_Vz_outputDef; // Vz输出定义
CString g_sLangID_Native_Vz_referPhase;
CString g_sLangTxt_Native_Vz_referPhase; // Vz参考相
CString g_sLangID_Native_Vz_phase_angle;
CString g_sLangTxt_Native_Vz_phase_angle; // Vz相角
CString g_sLangID_Native_reclose_timeset;
CString g_sLangTxt_Native_reclose_timeset; // 重合闸时间定值
CString g_sLangID_Native_PostAccelerat_TimeSet;
CString g_sLangTxt_Native_PostAccelerat_TimeSet; // 后加速时间定值

CString g_sLangID_Native_auxiV_UxoutputMode;
CString g_sLangTxt_Native_auxiV_UxoutputMode; // 辅助电压Ux输出方式
CString g_sLangID_Native_synchronous_VAmp;
CString g_sLangTxt_Native_synchronous_VAmp; // 同期电压幅值(检同期方式有效)
CString g_sLangID_Native_synchronous_VPh;
CString g_sLangTxt_Native_synchronous_VPh; // 同期电压相位(检同期方式有效)
CString g_sLangID_Native_pressTestVal;
CString g_sLangTxt_Native_pressTestVal; // 有压测试值
CString g_sLangID_Native_NOpressTestVal;
CString g_sLangTxt_Native_NOpressTestVal; // 无压测试值
CString g_sLangID_Native_openflip_Control;
CString g_sLangTxt_Native_openflip_Control; // 开出翻转控制方式
CString g_sLangID_Native_openflip_delay;
CString g_sLangTxt_Native_openflip_delay; // 开出翻转延时
CString g_sLangID_Native_input_selection;
CString g_sLangTxt_Native_input_selection; // 开入量选择
CString g_sLangID_Native_superimposed_ornot1;
CString g_sLangTxt_Native_superimposed_ornot1; // 是否叠加非周期分量
CString g_sLangID_Native_jumpctrl;
CString g_sLangTxt_Native_jumpctrl; // 跳合信号控制
CString g_sLangID_Native_timectrl;
CString g_sLangTxt_Native_timectrl; // 时间控制
CString g_sLangID_Native_totalweight;
CString g_sLangTxt_Native_totalweight; // 综重（单重+三重）
CString g_sLangID_Native_tripleweight;
CString g_sLangTxt_Native_tripleweight; // 三重
CString g_sLangID_Native_norepeat;
CString g_sLangTxt_Native_norepeat; // 不重合
CString g_sLangID_Native_Totransformer;
CString g_sLangTxt_Native_Totransformer; // 指向变压器
CString g_sLangID_Native_lagrange;
CString g_sLangTxt_Native_lagrange; // 拉格朗日插值法
CString g_sLangID_Native_linear;
CString g_sLangTxt_Native_linear; // 线性插值法
CString g_sLangID_Native_faultvoltype;
CString g_sLangTxt_Native_faultvoltype; // 故障电压类型

CString g_sLangID_Native_Difsetting;
CString g_sLangTxt_Native_Difsetting; // 差动定值整定方式
CString g_sLangID_Native_DifCurChoose;
CString g_sLangTxt_Native_DifCurChoose; // 差动基准电流选择
CString g_sLangID_Native_harmonicnumber;
CString g_sLangTxt_Native_harmonicnumber; // 谐波次数选择//谐波次数选择
CString g_sLangID_Native_CuroutputPhase;
CString g_sLangTxt_Native_CuroutputPhase; // 电流输出相//电流输出相
CString g_sLangID_Native_PhaseAshort;
CString g_sLangTxt_Native_PhaseAshort; // A相短路
CString g_sLangID_Native_PhaseBshort;
CString g_sLangTxt_Native_PhaseBshort; // B相短路
CString g_sLangID_Native_PhaseCshort;
CString g_sLangTxt_Native_PhaseCshort; // C相短路
CString g_sLangID_Native_PhaseABCshort;
CString g_sLangTxt_Native_PhaseABCshort; // ABC相短路

// 第八周许
CString g_sLangID_Native_ExceptionMsgSet;			 // = _T("Native_ExceptionMsgSet")
CString g_sLangTxt_Native_ExceptionMsgSet;			 // = _T("异常报文设置")
CString g_sLangID_Native_CharacteristicGraph;		 // = _T("Native_CharacteristicGraph")
CString g_sLangTxt_Native_CharacteristicGraph;		 // = _T("特性图")
CString g_sLangID_Native_OV1SetValue;				 // = _T("Native_OV1SetValue")
CString g_sLangTxt_Native_OV1SetValue;				 // = _T("过压I段定值")
CString g_sLangID_Native_OV2SetValue;				 // = _T("Native_OV2SetValue")
CString g_sLangTxt_Native_OV2SetValue;				 // = _T("过压II段定值")
CString g_sLangID_Native_OV3SetValue;				 // = _T("Native_OV3SetValue")
CString g_sLangTxt_Native_OV3SetValue;				 // = _T("过压III段定值")
CString g_sLangID_Native_OV4SetValue;				 // = _T("Native_OV4SetValue")
CString g_sLangTxt_Native_OV4SetValue;				 // = _T("过压IV段定值")
CString g_sLangID_Native_OV1Time;					 // = _T("Native_OV1Time")
CString g_sLangTxt_Native_OV1Time;					 // = _T("过压I段时间")
CString g_sLangID_Native_OV2Time;					 // = _T("Native_OV2Time")
CString g_sLangTxt_Native_OV2Time;					 // = _T("过压II段时间")
CString g_sLangID_Native_OV3Time;					 // = _T("Native_OV3Time")
CString g_sLangTxt_Native_OV3Time;					 // = _T("过压III段时间")
CString g_sLangID_Native_OV4Time;					 // = _T("Native_OV4Time")
CString g_sLangTxt_Native_OV4Time;					 // = _T("过压IV段时间")
CString g_sLangID_Native_SimBrkDel;					 // = _T("SimBrkDel")
CString g_sLangTxt_Native_SimBrkDel;				 // = _T("是否模拟断路器延时")
CString g_sLangID_Native_BrkTripDel;				 // = _T("BrkTripDel")
CString g_sLangTxt_Native_BrkTripDel;				 // = _T("断路器跳闸延时")
CString g_sLangID_Native_BrkClsDel;					 // = _T("BrkClsDel")
CString g_sLangTxt_Native_BrkClsDel;				 // = _T("断路器合闸延时")
CString g_sLangID_Native_VoltType;					 // = _T("VoltType")
CString g_sLangTxt_Native_VoltType;					 // = _T("电压类型")
CString g_sLangID_Native_ActionVoltExpr;			 // = _T("Native_ActionVoltExpr")
CString g_sLangTxt_Native_ActionVoltExpr;			 // = _T("整定动作电压(表达式)")
CString g_sLangID_Native_PhaseATime;				 // = _T("Native_PhaseATime")
CString g_sLangTxt_Native_PhaseATime;				 // = _T("A相动作时间")
CString g_sLangID_Native_PhaseBTime;				 // = _T("Native_PhaseBTime")
CString g_sLangTxt_Native_PhaseBTime;				 // = _T("B相动作时间")
CString g_sLangID_Native_PhaseCTime;				 // = _T("Native_PhaseCTime")
CString g_sLangTxt_Native_PhaseCTime;				 // = _T("C相动作时间")
CString g_sLangID_Native_RecloseTime;				 // = _T("Native_RecloseTime")
CString g_sLangTxt_Native_RecloseTime;				 // = _T("重合闸动作时间")
CString g_sLangID_Native_InputETime;				 // = _T("Native_InputETime")
CString g_sLangTxt_Native_InputETime;				 // = _T("开入E动作时间")
CString g_sLangID_Native_InputFTime;				 // = _T("Native_InputFTime")
CString g_sLangTxt_Native_InputFTime;				 // = _T("开入F动作时间")
CString g_sLangID_Native_InputGTime;				 // = _T("Native_InputGTime")
CString g_sLangTxt_Native_InputGTime;				 // = _T("开入G动作时间")
CString g_sLangID_Native_InputHTime;				 // = _T("Native_InputHTime")
CString g_sLangTxt_Native_InputHTime;				 // = _T("开入H动作时间")
CString g_sLangID_Native_InputADesc;				 // = _T("Native_InputADesc")
CString g_sLangTxt_Native_InputADesc;				 // = _T("开入A动作描述")
CString g_sLangID_Native_InputBDesc;				 // = _T("Native_InputBDesc")
CString g_sLangTxt_Native_InputBDesc;				 // = _T("开入B动作描述")
CString g_sLangID_Native_InputCDesc;				 // = _T("Native_InputCDesc")
CString g_sLangTxt_Native_InputCDesc;				 // = _T("开入C动作描述")
CString g_sLangID_Native_ReclActDesc;				 // = _T("Native_ReclActDesc")
CString g_sLangTxt_Native_ReclActDesc;				 // = _T("重合闸动作描述")
CString g_sLangID_Native_PostAccTime;				 // = _T("Native_PostAccTime")
CString g_sLangTxt_Native_PostAccTime;				 // = _T("后加速动作时间")
CString g_sLangID_Native_PostAccDesc;				 // = _T("Native_PostAccDesc")
CString g_sLangTxt_Native_PostAccDesc;				 // = _T("后加速动作描述")
CString g_sLangID_Native_ActShortCur;				 // = _T("Native_ActShortCur")
CString g_sLangTxt_Native_ActShortCur;				 // = _T("实际短路电流")
CString g_sLangID_Native_ActShortVol;				 // = _T("Native_ActShortVol")
CString g_sLangTxt_Native_ActShortVol;				 // = _T("实际短路电压")
CString g_sLangID_Native_OverVoltVal;				 // = _T("Native_OverVoltVal")
CString g_sLangTxt_Native_OverVoltVal;				 // = _T("过压值")
CString g_sLangID_Native_UaInitVal;					 // = _T("Native_UaInitVal")
CString g_sLangTxt_Native_UaInitVal;				 // = _T("Ua初值")
CString g_sLangID_Native_UbInitVal;					 // = _T("Native_UbInitVal")
CString g_sLangTxt_Native_UbInitVal;				 // = _T("Ub初值")
CString g_sLangID_Native_UcInitVal;					 // = _T("Native_UcInitVal")
CString g_sLangTxt_Native_UcInitVal;				 // = _T("Uc初值")
CString g_sLangID_Native_UzInitVal;					 // = _T("Native_UzInitVal")
CString g_sLangTxt_Native_UzInitVal;				 // = _T("Uz初值")
CString g_sLangID_Native_IaInitVal;					 // = _T("Native_IaInitVal")
CString g_sLangTxt_Native_IaInitVal;				 // = _T("Ia初值")
CString g_sLangID_Native_IbInitVal;					 // = _T("Native_IbInitVal")
CString g_sLangTxt_Native_IbInitVal;				 // = _T("Ib初值")
CString g_sLangID_Native_IcInitVal;					 // = _T("Native_IcInitVal")
CString g_sLangTxt_Native_IcInitVal;				 // = _T("Ic初值")
CString g_sLangID_Native_CurveSegments;				 // = _T("Native_CurveSegments")
CString g_sLangTxt_Native_CurveSegments;			 // = _T("曲线段数")
CString g_sLangID_Native_VarChnl;					 // = _T("Native_VarChnl")
CString g_sLangTxt_Native_VarChnl;					 // = _T("递变通道")
CString g_sLangID_Native_TimingCurve;				 // = _T("Native_TimingCurve")
CString g_sLangTxt_Native_TimingCurve;				 // = _T("计时曲线")
CString g_sLangID_Native_VarSel;					 // = _T("Native_VarSel")
CString g_sLangTxt_Native_VarSel;					 // = _T("递变选择")
CString g_sLangID_Native_TransType;					 // = _T("Native_TransType")
CString g_sLangTxt_Native_TransType;				 // = _T("递变类型(0-斜率1-上升时间2-初值)")
CString g_sLangID_Native_CurveSelect;				 // = _T("Native_CurveSelect")
CString g_sLangTxt_Native_CurveSelect;				 // = _T("递变曲线选择")
CString g_sLangID_Native_StartValue;				 // = _T("Native_StartValue")
CString g_sLangTxt_Native_StartValue;				 // = _T("递变始值")
CString g_sLangID_Native_EndValue;					 // = _T("Native_EndValue")
CString g_sLangTxt_Native_EndValue;					 // = _T("递变终值")
CString g_sLangID_Native_StepSize;					 // = _T("Native_StepSize")
CString g_sLangTxt_Native_StepSize;					 // = _T("递变步长")
CString g_sLangID_Native_Curve;						 // = _T("Native_Curve")
CString g_sLangTxt_Native_Curve;					 // = _T("曲线")
CString g_sLangID_Native_Slope;						 // = _T("Native_Slope")
CString g_sLangTxt_Native_Slope;					 // = _T("斜率(A/ms)")
CString g_sLangID_Native_OutputTimems;				 // = _T("Native_OutputTimems")
CString g_sLangTxt_Native_OutputTimems;				 // = _T("输出时间(ms)")
CString g_sLangID_Native_SearchStart;				 // = _T("Native_SearchStart")
CString g_sLangTxt_Native_SearchStart;				 // = _T("搜索起点")
CString g_sLangID_Native_CurrentValue;				 // = _T("Native_CurrentValue")
CString g_sLangTxt_Native_CurrentValue;				 // = _T("当前值")
CString g_sLangID_Native_SearchEnd;					 // = _T("Native_SearchEnd")
CString g_sLangTxt_Native_SearchEnd;				 // = _T("搜索终点")
CString g_sLangID_Native_SearchLen;					 // = _T("Native_SearchLen")
CString g_sLangTxt_Native_SearchLen;				 // = _T("搜索区间长度")
CString g_sLangID_Native_AutoSearch;				 // = _T("Native_AutoSearch")
CString g_sLangTxt_Native_AutoSearch;				 // = _T("是否自动搜索")
CString g_sLangID_Native_ComplexBrakeCurrent;		 // = _T("Native_ComplexBrakeCurrent")
CString g_sLangTxt_Native_ComplexBrakeCurrent;		 // = _T("复式制动电流(Ir-Id)")
CString g_sLangID_Native_DiffCurrentSetVal;			 // = _T("Native_DiffCurrentSetVal")
CString g_sLangTxt_Native_DiffCurrentSetVal;		 // = _T("差动电流定值")
CString g_sLangID_Native_DiffType;					 // = _T("Native_DiffType")
CString g_sLangTxt_Native_DiffType;					 // = _T("差动类别(0-大差试验 1-小差试验)")
CString g_sLangID_Native_UaAmplitude;				 // = _T("Native_UaAmplitude")
CString g_sLangTxt_Native_UaAmplitude;				 // = _T("Ua幅值")
CString g_sLangID_Native_UbAmplitude;				 // = _T("Native_UbAmplitude")
CString g_sLangTxt_Native_UbAmplitude;				 // = _T("Ub幅值")
CString g_sLangID_Native_UcAmplitude;				 // = _T("Native_UcAmplitude")
CString g_sLangTxt_Native_UcAmplitude;				 // = _T("Uc幅值")
CString g_sLangID_Native_UaPhase;					 // = _T("Native_UaPhase")
CString g_sLangTxt_Native_UaPhase;					 // = _T("Ua相位")
CString g_sLangID_Native_UbPhase;					 // = _T("Native_UbPhase")
CString g_sLangTxt_Native_UbPhase;					 // = _T("Ub相位")
CString g_sLangID_Native_UcPhase;					 // = _T("Native_UcPhase")
CString g_sLangTxt_Native_UcPhase;					 // = _T("Uc相位")
CString g_sLangID_Native_Gap1TARatio;				 // = _T("Native_Gap1TARatio")
CString g_sLangTxt_Native_Gap1TARatio;				 // = _T("间隔1TA变比")
CString g_sLangID_Native_Gap2TARatio;				 // = _T("Native_Gap2TARatio")
CString g_sLangTxt_Native_Gap2TARatio;				 // = _T("间隔2TA变比")
CString g_sLangID_Native_Gap3TARatio;				 // = _T("Native_Gap3TARatio")
CString g_sLangTxt_Native_Gap3TARatio;				 // = _T("间隔3TA变比")
CString g_sLangID_Native_MaxTARatio;				 // = _T("Native_MaxTARatio")
CString g_sLangTxt_Native_MaxTARatio;				 // = _T("最大TA变比")
CString g_sLangID_Native_DiffThreshCurrent;			 // = _T("Native_DiffThreshCurrent")
CString g_sLangTxt_Native_DiffThreshCurrent;		 // = _T("差动门槛电流")
CString g_sLangID_Native_HighCompRatioCoef;			 // = _T("Native_HighCompRatioCoef")
CString g_sLangTxt_Native_HighCompRatioCoef;		 // = _T("复式比率系数高值")
CString g_sLangID_Native_LowCompRatioCoef;			 // = _T("Native_LowCompRatioCoef")
CString g_sLangTxt_Native_LowCompRatioCoef;			 // = _T("复式比率系数低值")
CString g_sLangID_Native_DiffActionVal;				 // = _T("Native_DiffActionVal")
CString g_sLangTxt_Native_DiffActionVal;			 // = _T("差动动作值")
CString g_sLangID_Native_CurrSearchVal;				 // = _T("Native_CurrSearchVal")
CString g_sLangTxt_Native_CurrSearchVal;			 // = _T("当前搜索值")
CString g_sLangID_Native_DiffActionDesc;			 // = _T("Native_DiffActionDesc")
CString g_sLangTxt_Native_DiffActionDesc;			 // = _T("差动动作描述")
CString g_sLangID_Native_VoltLockElem;				 // = _T("Native_VoltLockElem")
CString g_sLangTxt_Native_VoltLockElem;				 // = _T("电压闭锁元件")
CString g_sLangID_Native_LockVoltValue;				 // = _T("Native_LockVoltValue")
CString g_sLangTxt_Native_LockVoltValue;			 // = _T("闭锁电压值")
CString g_sLangID_Native_BrkCoeffType;				 // = _T("Native_BrkCoeffType")
CString g_sLangTxt_Native_BrkCoeffType;				 // = _T("比率制动系数类别(0-低值 1-高值)")
CString g_sLangID_Native_DiffCurrentIds;			 // = _T("Native_DiffCurrentIds")
CString g_sLangTxt_Native_DiffCurrentIds;			 // = _T("差动电流Id(表达式)")
CString g_sLangID_Native_CompBrakeCurr;				 // = _T("Native_CompBrakeCurr")
CString g_sLangTxt_Native_CompBrakeCurr;			 // = _T("复式制动电流(Ir-Id)(表达式)")
CString g_sLangID_Native_IrBrakeEq;					 // = _T("Native_IrBrakeEq")
CString g_sLangTxt_Native_IrBrakeEq;				 // = _T("Ir制动方程")
CString g_sLangID_Native_FirstVoltNormOutput;		 // = _T("Native_FirstVoltNormOutput")
CString g_sLangTxt_Native_FirstVoltNormOutput;		 // = _T("第一组电压常态输出值")
CString g_sLangID_Native_SecondVoltNormOutput;		 // = _T("Native_SecondVoltNormOutput")
CString g_sLangTxt_Native_SecondVoltNormOutput;		 // = _T("第二组电压常态输出值")
CString g_sLangID_Native_VoltFaultState;			 // = _T("Native_VoltFaultState")
CString g_sLangTxt_Native_VoltFaultState;			 // = _T("第一组电压故障态故障相输出值")
CString g_sLangID_Native_VoltFaultState2;			 // = _T("VoltFaultState2")
CString g_sLangTxt_Native_VoltFaultState2;			 // = _T("第二组电压故障态故障相输出值")
CString g_sLangID_Native_BalanceMode;				 // = _T("Native_BalanceMode")
CString g_sLangTxt_Native_BalanceMode;				 // = _T("平衡系数设置方式")
CString g_sLangID_Native_HVBalanceCoeff;			 // = _T("Native_HVBalanceCoeff")
CString g_sLangTxt_Native_HVBalanceCoeff;			 // = _T("高压侧差动平衡系数设置值")
CString g_sLangID_Native_MVBalanceCoeff;			 // = _T("Native_MVBalanceCoeff")
CString g_sLangTxt_Native_MVBalanceCoeff;			 // = _T("中压侧差动平衡系数设置值")
CString g_sLangID_Native_LVBalanceCoeff;			 // = _T("Native_LVBalanceCoeff")
CString g_sLangTxt_Native_LVBalanceCoeff;			 // = _T("低压侧差动平衡系数设置值")
CString g_sLangID_Native_HVCTRatio;					 // = _T("Native_HVCTRatio")
CString g_sLangTxt_Native_HVCTRatio;				 // = _T("高压侧CT变比")
CString g_sLangID_Native_MVCTRatio;					 // = _T("Native_MVCTRatio")
CString g_sLangTxt_Native_MVCTRatio;				 // = _T("中压侧CT变比")
CString g_sLangID_Native_LVCTRatio;					 // = _T("Native_LVCTRatio")
CString g_sLangTxt_Native_LVCTRatio;				 // = _T("低压侧CT变比")
CString g_sLangID_Native_TestCoil;					 // = _T("Native_TestCoil")
CString g_sLangTxt_Native_TestCoil;					 // = _T("参与试验的绕组")
CString g_sLangID_Native_ProtPhaseCorr;				 // = _T("Native_ProtPhaseCorr")
CString g_sLangTxt_Native_ProtPhaseCorr;			 // = _T("保护内部相位校正方式")
CString g_sLangID_Native_BaseCurrSet;				 // = _T("Native_BaseCurrSet")
CString g_sLangTxt_Native_BaseCurrSet;				 // = _T("基准电流设定值")
CString g_sLangID_Native_DiffQuickBreakCurr;		 // = _T("Native_DiffQuickBreakCurr")
CString g_sLangTxt_Native_DiffQuickBreakCurr;		 // = _T("差动速断电流")
CString g_sLangID_Native_RatioBrakeTurnPts;			 // = _T("Native_RatioBrakeTurnPts")
CString g_sLangTxt_Native_RatioBrakeTurnPts;		 // = _T("比率制动拐点数")
CString g_sLangID_Native_RatioBrakeTurn1Curr;		 // = _T("Native_RatioBrakeTurn1Curr")
CString g_sLangTxt_Native_RatioBrakeTurn1Curr;		 // = _T("比率制动拐点1电流")
CString g_sLangID_Native_RatioBrakeTurn2Curr;		 // = _T("Native_RatioBrakeTurn2Curr")
CString g_sLangTxt_Native_RatioBrakeTurn2Curr;		 // = _T("比率制动拐点2电流")
CString g_sLangID_Native_RatioBrakeTurn3Curr;		 // = _T("Native_RatioBrakeTurn3Curr")
CString g_sLangTxt_Native_RatioBrakeTurn3Curr;		 // = _T("比率制动拐点3电流")
CString g_sLangID_Native_HarmonicBrakeCoeff;		 // = _T("Native_HarmonicBrakeCoeff")
CString g_sLangTxt_Native_HarmonicBrakeCoeff;		 // = _T("谐波制动系数定值")
CString g_sLangID_Native_HarmonicBrakeDesc;			 // = _T("Native_HarmonicBrakeDesc")
CString g_sLangTxt_Native_HarmonicBrakeDesc;		 // = _T("谐波制动系数描述")
CString g_sLangID_Native_PhaseACurrent;				 // = _T("Native_PhaseACurrent")
CString g_sLangTxt_Native_PhaseACurrent;			 // = _T("A相基波电流")
CString g_sLangID_Native_PhaseBCurrent;				 // = _T("Native_PhaseBCurrent")
CString g_sLangTxt_Native_PhaseBCurrent;			 // = _T("B相基波电流")
CString g_sLangID_Native_PhaseCCurrent;				 // = _T("Native_PhaseCCurrent")
CString g_sLangTxt_Native_PhaseCCurrent;			 // = _T("C相基波电流")
CString g_sLangID_Native_PhaseAHarmCur;				 // = _T("Native_PhaseAHarmCur")
CString g_sLangTxt_Native_PhaseAHarmCur;			 // = _T("A相谐波电流")
CString g_sLangID_Native_BHarmonicCurrent;			 // = _T("Native_BHarmonicCurrent")
CString g_sLangTxt_Native_BHarmonicCurrent;			 // = _T("B相谐波电流")
CString g_sLangID_Native_CHarmonicCurrent;			 // = _T("Native_CHarmonicCurrent")
CString g_sLangTxt_Native_CHarmonicCurrent;			 // = _T("C相谐波电流")
CString g_sLangID_Native_FirstGroupVoltageOut;		 // = _T("Native_FirstGroupVoltageOut")
CString g_sLangTxt_Native_FirstGroupVoltageOut;		 // = _T("第一组电压输出值")
CString g_sLangID_Native_HVCTConnectionMode;		 // = _T("Native_HVCTConnectionMode")
CString g_sLangTxt_Native_HVCTConnectionMode;		 // = _T("高压侧CT接线方式")
CString g_sLangID_Native_BalanceCoeffCalcMethod;	 // = _T("Native_BalanceCoeffCalcMethod")
CString g_sLangTxt_Native_BalanceCoeffCalcMethod;	 // = _T("平衡系数计算方法")
CString g_sLangID_Native_UnderTestValue;			 // = _T("Native_UnderTestValue")
CString g_sLangTxt_Native_UnderTestValue;			 // = _T("待测定值")
CString g_sLangID_Native_FaultImpedanceAngle;		 // = _T("Native_FaultImpedanceAngle")
CString g_sLangTxt_Native_FaultImpedanceAngle;		 // = _T("故障阻抗角")
CString g_sLangID_Native_PTLineSimulate;			 // = _T("Native_PTLineSimulate")
CString g_sLangTxt_Native_PTLineSimulate;			 // = _T("是否模拟PT断线")
CString g_sLangID_Native_PTLineSimPhase;			 // = _T("Native_PTLineSimPhase")
CString g_sLangTxt_Native_PTLineSimPhase;			 // = _T("模拟PT断线相别")
CString g_sLangID_Native_VarStartValue;				 // = _T("Native_VarStartValue")
CString g_sLangTxt_Native_VarStartValue;			 // = _T("变化始值(表达式)")
CString g_sLangID_Native_VarEndValue;				 // = _T("Native_VarEndValue")
CString g_sLangTxt_Native_VarEndValue;				 // = _T("变化终值(表达式)")
CString g_sLangID_Native_StepTime;					 // = _T("Native_StepTime")
CString g_sLangTxt_Native_StepTime;					 // = _T("步长时间(表达式)")
CString g_sLangID_Native_ShortVolt;					 // = _T("Native_ShortVolt")
CString g_sLangTxt_Native_ShortVolt;				 // = _T("短路电压(表达式)")
CString g_sLangID_Native_ShortCurr;					 // = _T("Native_ShortCurr")
CString g_sLangTxt_Native_ShortCurr;				 // = _T("短路电流(表达式)")
CString g_sLangID_Native_BoundaryAngle1;			 // = _T("Native_BoundaryAngle1")
CString g_sLangTxt_Native_BoundaryAngle1;			 // = _T("边界角1(兼容)")
CString g_sLangID_Native_BoundaryAngle2;			 // = _T("Native_BoundaryAngle2")
CString g_sLangTxt_Native_BoundaryAngle2;			 // = _T("边界角2(兼容)")
CString g_sLangID_Native_StepTimes;					 // = _T("Native_StepTimes")
CString g_sLangTxt_Native_StepTimes;				 // = _T("步长时间")
CString g_sLangID_Native_ShortCircuit;				 // = _T("Native_ShortCircuit")
CString g_sLangTxt_Native_ShortCircuit;				 // = _T("短路电流")
CString g_sLangID_Native_ImpedanceAngles;			 // = _T("Native_ImpedanceAngles")
CString g_sLangTxt_Native_ImpedanceAngles;			 // = _T("阻抗角")
CString g_sLangID_Native_TestReturnValue;			 // = _T("Native_TestReturnValue")
CString g_sLangTxt_Native_TestReturnValue;			 // = _T("是否测试返回值")
CString g_sLangID_Native_LowVoltagev;				 // = _T("Native_LowVoltagev")
CString g_sLangTxt_Native_LowVoltagev;				 // = _T("低电压(V)")
CString g_sLangID_Native_NegativeSeqVolt;			 // = _T("Native_NegativeSeqVolt")
CString g_sLangTxt_Native_NegativeSeqVolt;			 // = _T("负序电压(V)")
CString g_sLangID_Native_ActionCurrent;				 // = _T("Native_ActionCurrent")
CString g_sLangTxt_Native_ActionCurrent;			 // = _T("动作电流(A)")
CString g_sLangID_Native_DelayTimes;				 // = _T("Native_DelayTimes")
CString g_sLangTxt_Native_DelayTimes;				 // = _T("延时时间(s)")
CString g_sLangID_Native_ActionAreaSize;			 // = _T("Native_ActionAreaSize")
CString g_sLangTxt_Native_ActionAreaSize;			 // = _T("动作区大小(°)")
CString g_sLangID_Native_ImpedanceAnglexp;			 // = _T("Native_ImpedanceAnglexp")
CString g_sLangTxt_Native_ImpedanceAnglexp;			 // = _T("阻抗角(表达式)")
CString g_sLangID_Native_TestOutMode;				 // = _T("Native_TestOutMode")
CString g_sLangTxt_Native_TestOutMode;				 // = _T("测试仪输出模式")
CString g_sLangID_Native_RatedVoltVal;				 // = _T("Native_RatedVoltVal")
CString g_sLangTxt_Native_RatedVoltVal;				 // = _T("额定电压值")
CString g_sLangID_Native_RatedCurrVal;				 // = _T("Native_RatedCurrVal")
CString g_sLangTxt_Native_RatedCurrVal;				 // = _T("额定电流值")
CString g_sLangID_Native_FirstPTVal;				 // = _T("Native_FirstPTVal")
CString g_sLangTxt_Native_FirstPTVal;				 // = _T("第%d组PT一次值")
CString g_sLangID_Native_SecPTVal;					 // = _T("Native_SecPTVal")
CString g_sLangTxt_Native_SecPTVal;					 // = _T("第%d组PT二次值")
CString g_sLangID_Native_FirstCTVal;				 // = _T("Native_FirstCTVal")
CString g_sLangTxt_Native_FirstCTVal;				 // = _T("第%d组CT一次值")
CString g_sLangID_Native_SecCTVal;					 // = _T("Native_SecCTVal")
CString g_sLangTxt_Native_SecCTVal;					 // = _T("第%d组CT二次值")
CString g_sLangID_Native_MsgFormat;					 // = _T("Native_MsgFormat")
CString g_sLangTxt_Native_MsgFormat;				 // = _T("报文输出格式")
CString g_sLangID_Native_WeakSigOutSet;				 // = _T("Native_WeakSigOutSet")
CString g_sLangTxt_Native_WeakSigOutSet;			 // = _T("弱信号输出设置")
CString g_sLangID_Native_1588RecvOptPort;			 // = _T("Native_1588RecvOptPort")
CString g_sLangTxt_Native_1588RecvOptPort;			 // = _T("1588接收光口")
CString g_sLangID_Native_1588SyncMech;				 // = _T("Native_1588SyncMech")
CString g_sLangTxt_Native_1588SyncMech;				 // = _T("1588同步机制")
CString g_sLangID_Native_ParamSel;					 // = _T("Native_ParamSel")
CString g_sLangTxt_Native_ParamSel;					 // = _T("参数设置选择(0-一次值,1-二次值)")
CString g_sLangID_Native_MsgOutSel;					 // = _T("Native_MsgOutSel")
CString g_sLangTxt_Native_MsgOutSel;				 // = _T("报文输出选择(0-一次值,1-二次值)")
CString g_sLangID_Native_BCodeLogics;				 // = _T("Native_BCodeLogics")
CString g_sLangTxt_Native_BCodeLogics;				 // = _T("B码逻辑(0-正逻辑,1-负逻辑)")
CString g_sLangID_Native_FiberConn;					 // = _T("Native_FiberConn")
CString g_sLangTxt_Native_FiberConn;				 // = _T("光纤连接方式(0-双回,1-单回)")
CString g_sLangID_Native_GroupCurrMod;				 // = _T("Native_GroupCurrMod")
CString g_sLangTxt_Native_GroupCurrMod;				 // = _T("组电流模块")
CString g_sLangID_Native_CurrModPos;				 // = _T("Native_CurrModPos")
CString g_sLangTxt_Native_CurrModPos;				 // = _T("电流模块位置")
CString g_sLangID_Native_CurrModGearVal;			 // = _T("Native_CurrModGearVal")
CString g_sLangTxt_Native_CurrModGearVal;			 // = _T("电流模块档位值")
CString g_sLangID_Native_CurrChanMaxVolt;			 // = _T("Native_CurrChanMaxVolt")
CString g_sLangTxt_Native_CurrChanMaxVolt;			 // = _T("电流通道最大端口电压")
CString g_sLangID_Native_MergeCurrTerm;				 // = _T("Native_MergeCurrTerm")
CString g_sLangTxt_Native_MergeCurrTerm;			 // = _T("合并电流端子")
CString g_sLangID_Native_CurrModCount;				 // = _T("Native_CurrModCount")
CString g_sLangTxt_Native_CurrModCount;				 // = _T("电流模块数量")
CString g_sLangID_Native_WirelessNet;				 // = _T("Native_WirelessNet")
CString g_sLangTxt_Native_WirelessNet;				 // = _T("无线网络")
CString g_sLangID_Native_WiredNet;					 // = _T("Native_WiredNet")
CString g_sLangTxt_Native_WiredNet;					 // = _T("有线网络")
CString g_sLangID_Native_LcdBacklightTime;			 // = _T("Native_LcdBacklightTime")
CString g_sLangTxt_Native_LcdBacklightTime;			 // = _T("Lcd背光时长")
CString g_sLangID_Native_TouchSensitivity;			 // = _T("Native_TouchSensitivity")
CString g_sLangTxt_Native_TouchSensitivity;			 // = _T("触摸灵敏度(ms)")
CString g_sLangID_Native_CurrentActionError;		 // = _T("Native_CurrentActionError")
CString g_sLangTxt_Native_CurrentActionError;		 // = _T("电流动作值绝对误差(A)")
CString g_sLangID_Native_CurrentActionRelError;		 // = _T("Native_CurrentActionRelError")
CString g_sLangTxt_Native_CurrentActionRelError;	 // = _T("电流动作值相对误差(%)")
CString g_sLangID_Native_VoltageActionError;		 // = _T("Native_VoltageActionError")
CString g_sLangTxt_Native_VoltageActionError;		 // = _T("电压动作值绝对误差(V)")
CString g_sLangID_Native_VoltageActionRelError;		 // = _T("Native_VoltageActionRelError")
CString g_sLangTxt_Native_VoltageActionRelError;	 // = _T("电压动作值相对误差(%)")
CString g_sLangID_Native_ImpedanceActionError;		 // = _T("Native_ImpedanceActionError")
CString g_sLangTxt_Native_ImpedanceActionError;		 // = _T("阻抗动作值绝对误差(Ω)")
CString g_sLangID_Native_ImpedanceActionRelError;	 // = _T("Native_ImpedanceActionRelError")
CString g_sLangTxt_Native_ImpedanceActionRelError;	 // = _T("阻抗动作值相对误差(%)")
CString g_sLangID_Native_ActionTimeAbsError;		 // = _T("Native_ActionTimeAbsError")
CString g_sLangTxt_Native_ActionTimeAbsError;		 // = _T("动作时间绝对误差(s)")
CString g_sLangID_Native_ActionTimeRelError;		 // = _T("Native_ActionTimeRelError")
CString g_sLangTxt_Native_ActionTimeRelError;		 // = _T("动作时间相对误差(%)")
CString g_sLangID_Native_PhaseErrorValue;			 // = _T("Native_PhaseErrorValue")
CString g_sLangTxt_Native_PhaseErrorValue;			 // = _T("相位误差值(°)")
CString g_sLangID_Native_FreqErrorValue;			 // = _T("Native_FreqErrorValue")
CString g_sLangTxt_Native_FreqErrorValue;			 // = _T("频率误差值(Hz)")
CString g_sLangID_Native_VoltSlipErrorValue;		 // = _T("Native_VoltSlipErrorValue")
CString g_sLangTxt_Native_VoltSlipErrorValue;		 // = _T("电压滑差误差值(V/s)")
CString g_sLangID_Native_FreqSlipErrorValue;		 // = _T("Native_FreqSlipErrorValue")
CString g_sLangTxt_Native_FreqSlipErrorValue;		 // = _T("频率滑差误差值(Hz/s)")
CString g_sLangID_Native_DiffRatioBrakeAbsError;	 // = _T("Native_DiffRatioBrakeAbsError")
CString g_sLangTxt_Native_DiffRatioBrakeAbsError;	 // = _T("差动比率制动系数绝对误差")
CString g_sLangID_Native_DiffRatioBrakeRelError;	 // = _T("Native_DiffRatioBrakeRelError")
CString g_sLangTxt_Native_DiffRatioBrakeRelError;	 // = _T("差动比率制动系数相对误差(%)")
CString g_sLangID_Native_DiffHarmonicBrakeAbsError;	 // = _T("Native_DiffHarmonicBrakeAbsError")
CString g_sLangTxt_Native_DiffHarmonicBrakeAbsError; // = _T("差动谐波制动系数绝对误差")
CString g_sLangID_Native_DiffHarmonicBrakeRelError;	 // = _T("Native_DiffHarmonicBrakeRelError")
CString g_sLangTxt_Native_DiffHarmonicBrakeRelError; // = _T("差动谐波制动系数相对误差(%)")
CString g_sLangID_Native_AuxDcVoltageValue;			 // = _T("Native_AuxDcVoltageValue")
CString g_sLangTxt_Native_AuxDcVoltageValue;		 // = _T("辅助直流电压值")
CString g_sLangID_Native_AuxDcCurrentValue;			 // = _T("Native_AuxDcCurrentValue")
CString g_sLangTxt_Native_AuxDcCurrentValue;		 // = _T("辅助直流电流值")
CString g_sLangID_Native_VoltageRatioPrimary1;		 // = _T("Native_VoltageRatioPrimary1")
CString g_sLangTxt_Native_VoltageRatioPrimary1;		 // = _T("电压变比一次值(第1组)")
CString g_sLangID_Native_VoltageRatioPrimary2;		 // = _T("Native_VoltageRatioPrimary2")
CString g_sLangTxt_Native_VoltageRatioPrimary2;		 // = _T("电压变比一次值(第2组)")
CString g_sLangID_Native_VoltageRatioPrimary3;		 // = _T("Native_VoltageRatioPrimary3")
CString g_sLangTxt_Native_VoltageRatioPrimary3;		 // = _T("电压变比一次值(第3组)")
CString g_sLangID_Native_VoltageRatioPrimary4;		 // = _T("Native_VoltageRatioPrimary4")
CString g_sLangTxt_Native_VoltageRatioPrimary4;		 // = _T("电压变比一次值(第4组)")
CString g_sLangID_Native_VoltageRatioPrimary5;		 // = _T("Native_VoltageRatioPrimary5")
CString g_sLangTxt_Native_VoltageRatioPrimary5;		 // = _T("电压变比一次值(第5组)")
CString g_sLangID_Native_VoltageRatioPrimary6;		 // = _T("Native_VoltageRatioPrimary6")
CString g_sLangTxt_Native_VoltageRatioPrimary6;		 // = _T("电压变比一次值(第6组)")
CString g_sLangID_Native_VoltageRatioSecondary1;	 // = _T("Native_VoltageRatioSecondary1")
CString g_sLangTxt_Native_VoltageRatioSecondary1;	 // = _T("电压变比二次值(第1组)")
CString g_sLangID_Native_VoltageRatioSecondary2;	 // = _T("Native_VoltageRatioSecondary2")
CString g_sLangTxt_Native_VoltageRatioSecondary2;	 // = _T("电压变比二次值(第2组)")
CString g_sLangID_Native_VoltageRatioSecondary3;	 // = _T("Native_VoltageRatioSecondary3")
CString g_sLangTxt_Native_VoltageRatioSecondary3;	 // = _T("电压变比二次值(第3组)")
CString g_sLangID_Native_VoltageRatioSecondary4;	 // = _T("Native_VoltageRatioSecondary4")
CString g_sLangTxt_Native_VoltageRatioSecondary4;	 // = _T("电压变比二次值(第4组)")
CString g_sLangID_Native_VoltageRatioSecondary5;	 // = _T("Native_VoltageRatioSecondary5")
CString g_sLangTxt_Native_VoltageRatioSecondary5;	 // = _T("电压变比二次值(第5组)")
CString g_sLangID_Native_VoltageRatioSecondary6;	 // = _T("Native_VoltageRatioSecondary6")
CString g_sLangTxt_Native_VoltageRatioSecondary6;	 // = _T("电压变比二次值(第6组)")
CString g_sLangID_Native_CurrentRatioPrimary1;		 // = _T("Native_CurrentRatioPrimary1")
CString g_sLangTxt_Native_CurrentRatioPrimary1;		 // = _T("电流变比一次值(第1组)")
CString g_sLangID_Native_CurrentRatioPrimary2;		 // = _T("Native_CurrentRatioPrimary2")
CString g_sLangTxt_Native_CurrentRatioPrimary2;		 // = _T("电流变比一次值(第2组)")
CString g_sLangID_Native_CurrentRatioPrimary3;		 // = _T("Native_CurrentRatioPrimary3")
CString g_sLangTxt_Native_CurrentRatioPrimary3;		 // = _T("电流变比一次值(第3组)")
CString g_sLangID_Native_CurrentRatioPrimary4;		 // = _T("Native_CurrentRatioPrimary4")
CString g_sLangTxt_Native_CurrentRatioPrimary4;		 // = _T("电流变比一次值(第4组)")
CString g_sLangID_Native_CurrentRatioPrimary5;		 // = _T("Native_CurrentRatioPrimary5")
CString g_sLangTxt_Native_CurrentRatioPrimary5;		 // = _T("电流变比一次值(第5组)")
CString g_sLangID_Native_SecondGroupVoltageOut;		 //= _T("Native_SecondGroupVoltageOut");
CString g_sLangTxt_Native_SecondGroupVoltageOut;	 //= _T("第二组电压输出值");
CString g_sLangID_Native_CurrentRatioPrimary6;		 // = _T("Native_CurrentRatioPrimary6")
CString g_sLangTxt_Native_CurrentRatioPrimary6;		 // = _T("电流变比一次值(第6组)")
CString g_sLangID_Native_CurrentRatioSecondary1;	 // = _T("Native_CurrentRatioSecondary1")
CString g_sLangTxt_Native_CurrentRatioSecondary1;	 // = _T("电流变比二次值(第1组)")
CString g_sLangID_Native_CurrentRatioSecondary2;	 // = _T("Native_CurrentRatioSecondary2")
CString g_sLangTxt_Native_CurrentRatioSecondary2;	 // = _T("电流变比二次值(第2组)")
CString g_sLangID_Native_CurrentRatioSecondary3;	 // = _T("Native_CurrentRatioSecondary3")
CString g_sLangTxt_Native_CurrentRatioSecondary3;	 // = _T("电流变比二次值(第3组)")
CString g_sLangID_Native_CurrentRatioSecondary4;	 // = _T("Native_CurrentRatioSecondary4")
CString g_sLangTxt_Native_CurrentRatioSecondary4;	 // = _T("电流变比二次值(第4组)")
CString g_sLangID_Native_CurrentRatioSecondary5;	 // = _T("Native_CurrentRatioSecondary5")
CString g_sLangTxt_Native_CurrentRatioSecondary5;	 // = _T("电流变比二次值(第5组)")
CString g_sLangID_Native_CurrentRatioSecondary6;	 // = _T("Native_CurrentRatioSecondary6")
CString g_sLangTxt_Native_CurrentRatioSecondary6;	 // = _T("电流变比二次值(第6组)")
CString g_sLangID_Native_OutputAnalog;				 // = _T("Native_OutputAnalog")
CString g_sLangTxt_Native_OutputAnalog;				 // = _T("输出模拟量")
CString g_sLangID_Native_OutputDigital;				 // = _T("Native_OutputDigital")
CString g_sLangTxt_Native_OutputDigital;			 // = _T("输出数字量")
CString g_sLangID_Native_OutputWeakSig;				 // = _T("Native_OutputWeakSig")
CString g_sLangTxt_Native_OutputWeakSig;			 // = _T("输出弱信号")
CString g_sLangID_Native_RatedLineVolt;				 // = _T("Native_RatedLineVolt")
CString g_sLangTxt_Native_RatedLineVolt;			 // = _T("额定线电压值")
CString g_sLangID_Native_RatedZeroVolt;				 // = _T("Native_RatedZeroVolt")
CString g_sLangTxt_Native_RatedZeroVolt;			 // = _T("额定零序电压")
CString g_sLangID_Native_RatedZeroCurr;				 // = _T("Native_RatedZeroCurr")
CString g_sLangTxt_Native_RatedZeroCurr;			 // = _T("额定零序电流")
CString g_sLangID_Native_StartOverloadDelay;		 // = _T("Native_StartOverloadDelay")
CString g_sLangTxt_Native_StartOverloadDelay;		 // = _T("开始过载延时(s)")
CString g_sLangID_Native_CheckTestEndHeartbeat;		 // = _T("Native_CheckTestEndHeartbeat")
CString g_sLangTxt_Native_CheckTestEndHeartbeat;	 // = _T("检测测试端心跳")
CString g_sLangID_Native_UseAnalogCapture;			 // = _T("Native_UseAnalogCapture")
CString g_sLangTxt_Native_UseAnalogCapture;			 // = _T("使用模拟量采集")
CString g_sLangID_Native_UseDigitalCapture;			 // = _T("Native_UseDigitalCapture")
CString g_sLangTxt_Native_UseDigitalCapture;		 // = _T("使用数字量采集")
CString g_sLangID_Native_UseSmallSignalCapture;		 // = _T("Native_UseSmallSignalCapture")
CString g_sLangTxt_Native_UseSmallSignalCapture;	 // = _T("使用小信号采集")
CString g_sLangID_Native_DigitalCaptureMsgType;		 // = _T("Native_DigitalCaptureMsgType")
CString g_sLangTxt_Native_DigitalCaptureMsgType;	 // = _T("数字量采集报文类型")
CString g_sLangID_Native_BCodeReceiveLogic;			 // = _T("Native_BCodeReceiveLogic")
CString g_sLangTxt_Native_BCodeReceiveLogic;		 // = _T("B码接收逻辑(0-正逻辑,1-负逻辑)")
CString g_sLangID_Native_ReportExtInQty;			 // = _T("Native_ReportExtInQty")
CString g_sLangTxt_Native_ReportExtInQty;			 // = _T("报告需要的扩展开入数量(0-自动关联开关量扩展模块)")
CString g_sLangID_Native_BaseReportTimeZone;		 // = _T("Native_BaseReportTimeZone")
CString g_sLangTxt_Native_BaseReportTimeZone;		 // = _T("底层上报数据的时区")
CString g_sLangID_Native_GPStoBCodeUserTZ;			 // = _T("Native_GPStoBCodeUserTZ")
CString g_sLangTxt_Native_GPStoBCodeUserTZ;			 // = _T("GPS转B码时使用用户设置时区")
CString g_sLangID_Native_MachineFanMode;			 // = _T("Native_MachineFanMode")
CString g_sLangTxt_Native_MachineFanMode;			 // = _T("机器散热风扇模式(0-静音,1-正常)")
CString g_sLangID_Native_AmplitudeGradual;			 // = _T("Native_AmplitudeGradual")
CString g_sLangTxt_Native_AmplitudeGradual;			 // = _T("幅值递变标识")
CString g_sLangID_Native_AmplitudeEndValue;			 // = _T("Native_AmplitudeEndValue")
CString g_sLangTxt_Native_AmplitudeEndValue;		 // = _T("幅值递变终值")
CString g_sLangID_Native_AmplitudeStep;				 // = _T("Native_AmplitudeStep")
CString g_sLangTxt_Native_AmplitudeStep;			 // = _T("幅值递变步长")
CString g_sLangID_Native_PhaseFlag;					 // = _T("Native_PhaseFlag")
CString g_sLangTxt_Native_PhaseFlag;				 // = _T("相位递变标识")
CString g_sLangID_Native_PhaseEndVal;				 // = _T("Native_PhaseEndVal")
CString g_sLangTxt_Native_PhaseEndVal;				 // = _T("相位递变终值")
CString g_sLangID_Native_PhaseStep;					 // = _T("Native_PhaseStep")
CString g_sLangTxt_Native_PhaseStep;				 // = _T("相位递变步长")
CString g_sLangID_Native_FreqFlag;					 // = _T("Native_FreqFlag")
CString g_sLangTxt_Native_FreqFlag;					 // = _T("频率递变标识")
CString g_sLangID_Native_FreqEnd;					 // = _T("Native_FreqEnd")
CString g_sLangTxt_Native_FreqEnd;					 // = _T("频率递变终值")
CString g_sLangID_Native_FreqStep;					 // = _T("Native_FreqStep")
CString g_sLangTxt_Native_FreqStep;					 // = _T("频率递变步长")
CString g_sLangID_Native_IsSelected;				 // = _T("Native_IsSelected")
CString g_sLangTxt_Native_IsSelected;				 // = _T("是否选择")
CString g_sLangID_Native_OpenState;					 // = _T("Native_OpenState")
CString g_sLangTxt_Native_OpenState;				 // = _T("开出状态")
CString g_sLangID_Native_DCOverlay;					 // = _T("Native_DCOverlay")
CString g_sLangTxt_Native_DCOverlay;				 // = _T("是否叠加直流分量")
CString g_sLangID_Native_DCDampTime;				 // = _T("Native_DCDampTime")
CString g_sLangTxt_Native_DCDampTime;				 // = _T("直流分量的衰减时间常数")
CString g_sLangID_Native_EnableEval;				 // = _T("Native_EnableEval")
CString g_sLangTxt_Native_EnableEval;				 // = _T("使能评估")
CString g_sLangID_Native_TimeStartState;			 // = _T("Native_TimeStartState")
CString g_sLangTxt_Native_TimeStartState;			 // = _T("计时起点_状态")
CString g_sLangID_Native_TimeEndState;				 // = _T("Native_TimeEndState")
CString g_sLangTxt_Native_TimeEndState;				 // = _T("计时终点_状态")
CString g_sLangID_Native_TimeStartInput;			 // = _T("Native_TimeStartInput")
CString g_sLangTxt_Native_TimeStartInput;			 // = _T("计时起点_开入")
CString g_sLangID_Native_TimeEndInput;				 // = _T("Native_TimeEndInput")
CString g_sLangTxt_Native_TimeEndInput;				 // = _T("计时终点_开入")
CString g_sLangID_Native_AbsErrorLimit;				 // = _T("Native_AbsErrorLimit")
CString g_sLangTxt_Native_AbsErrorLimit;			 // = _T("绝对误差限")
CString g_sLangID_Native_RelErrorLimit;				 // = _T("Native_RelErrorLimit")
CString g_sLangTxt_Native_RelErrorLimit;			 // = _T("相对误差限")
CString g_sLangID_Native_JudgeLogic;				 // = _T("Native_JudgeLogic")
CString g_sLangTxt_Native_JudgeLogic;				 // = _T("判断逻辑")
CString g_sLangID_Native_StepChangeID;				 // = _T("Native_StepChangeID")
CString g_sLangTxt_Native_StepChangeID;				 // = _T("递变动作步数标识")
CString g_sLangID_Native_CustomActTime;				 // = _T("Native_CustomActTime")
CString g_sLangTxt_Native_CustomActTime;			 // = _T("自定义动作时间")
CString g_sLangID_Native_AbsError;					 // = _T("Native_AbsError")
CString g_sLangTxt_Native_AbsError;					 // = _T("自定义动作时间绝对误差")
CString g_sLangID_Native_RelError;					 // = _T("Native_RelError")
CString g_sLangTxt_Native_RelError;					 // = _T("自定义动作时间相对误差")
CString g_sLangID_Native_CurrLoop;					 // = _T("Native_CurrLoop")
CString g_sLangTxt_Native_CurrLoop;					 // = _T("当前循环的序号")
CString g_sLangID_Native_TrigModes;					 // = _T("Native_TrigModes")
CString g_sLangTxt_Native_TrigModes;				 // = _T("触发模式(0-立即运行,1-等待GPS)")
CString g_sLangID_Native_HwSelect;					 // = _T("Native_HwSelect")
CString g_sLangTxt_Native_HwSelect;					 // = _T("硬件选择(0-主板8个开出,1-扩展插件)")
CString g_sLangID_Native_InAction;					 // = _T("Native_InAction")
CString g_sLangTxt_Native_InAction;					 // = _T("开入动作(0-不记录,1-记录)")
CString g_sLangID_Native_TotalTime;					 // = _T("Native_TotalTime")
CString g_sLangTxt_Native_TotalTime;				 // = _T("实验运行总时长(s)")
CString g_sLangID_Native_IsEnabled;					 // = _T("Native_IsEnabled")
CString g_sLangTxt_Native_IsEnabled;				 // = _T("是否启用")
CString g_sLangID_Native_PreState;					 // = _T("Native_PreState")
CString g_sLangTxt_Native_PreState;					 // = _T("实验前状态值")
CString g_sLangID_Native_InitState;					 // = _T("Native_InitState")
CString g_sLangTxt_Native_InitState;				 // = _T("实验中初始状态值")
CString g_sLangID_Native_PreCutDur;					 // = _T("Native_PreCutDur")
CString g_sLangTxt_Native_PreCutDur;				 // = _T("实验前断开持续时间(ms)")
CString g_sLangID_Native_CloseDur;					 // = _T("Native_CloseDur")
CString g_sLangTxt_Native_CloseDur;					 // = _T("实验中闭合持续时间(ms)")
CString g_sLangID_Native_BreakDur;					 // = _T("Native_BreakDur")
CString g_sLangTxt_Native_BreakDur;					 // = _T("实验中断开持续时间(ms)")
CString g_sLangID_Native_UzAmp;						 // = _T("Native_UzAmp")
CString g_sLangTxt_Native_UzAmp;					 // = _T("Uz幅值")
CString g_sLangID_Native_UzPhase;					 // = _T("Native_UzPhase")
CString g_sLangTxt_Native_UzPhase;					 // = _T("Uz相位")
CString g_sLangID_Native_UzFreq;					 // = _T("Native_UzFreq")
CString g_sLangTxt_Native_UzFreq;					 // = _T("Uz频率")
CString g_sLangID_Native_I0Amplitude;				 // = _T("Native_I0Amplitude")
CString g_sLangTxt_Native_I0Amplitude;				 // = _T("I0幅值")
CString g_sLangID_Native_I0Phase;					 // = _T("Native_I0Phase")
CString g_sLangTxt_Native_I0Phase;					 // = _T("I0相位")
CString g_sLangID_Native_I0Frequency;				 // = _T("Native_I0Frequency")
CString g_sLangTxt_Native_I0Frequency;				 // = _T("I0频率")
CString g_sLangID_Native_CurrentHighPowerMode;		 // = _T("Native_CurrentHighPowerMode")
CString g_sLangTxt_Native_CurrentHighPowerMode;		 // = _T("电流启用高功率模式")
CString g_sLangID_Native_EnableCustomOutput;		 // = _T("Native_EnableCustomOutput")
CString g_sLangTxt_Native_EnableCustomOutput;		 // = _T("启用自定义输出")
CString g_sLangID_Native_AbsoluteTime;				 // = _T("Native_AbsoluteTime")
CString g_sLangTxt_Native_AbsoluteTime;				 // = _T("绝对时间")
CString g_sLangID_Native_RelativeTime;				 // = _T("Native_RelativeTime")
CString g_sLangTxt_Native_RelativeTime;				 // = _T("相对时间")
CString g_sLangID_Native_ErrUaAmp;
CString g_sLangTxt_Native_ErrUaAmp; // 故障Ua幅值
CString g_sLangID_Native_ErrUbAmp;
CString g_sLangTxt_Native_ErrUbAmp; // 故障Ub幅值
CString g_sLangID_Native_ErrUcAmp;
CString g_sLangTxt_Native_ErrUcAmp; // 故障Uc幅值
CString g_sLangID_Native_ErrUzAmp;
CString g_sLangTxt_Native_ErrUzAmp; // 故障Uz幅值
CString g_sLangID_Native_ErrUaPh;
CString g_sLangTxt_Native_ErrUaPh; // 故障Ua相位
CString g_sLangID_Native_ErrUbPh;
CString g_sLangTxt_Native_ErrUbPh; // 故障Ub相位
CString g_sLangID_Native_ErrUcPh;
CString g_sLangTxt_Native_ErrUcPh; // 故障Uc相位
CString g_sLangID_Native_ErrUzPh;
CString g_sLangTxt_Native_ErrUzPh; // 故障Uz相位
CString g_sLangID_Native_OverCurrentV;
CString g_sLangTxt_Native_OverCurrentV; // 过流V段定值
CString g_sLangID_Native_OverCurrentVTime;
CString g_sLangTxt_Native_OverCurrentVTime; // 过流V段时间
CString g_sLangID_Native_ShortZImpAngExp;
CString g_sLangTxt_Native_ShortZImpAngExp; // 短路阻抗角(表达式)

CString g_sLangID_Native_first_fault_type;
CString g_sLangTxt_Native_first_fault_type; // 第一次故障类型
CString g_sLangID_Native_first_fault_current;
CString g_sLangTxt_Native_first_fault_current; // 第一次故障电流
CString g_sLangID_Native_first_faultact_time;
CString g_sLangTxt_Native_first_faultact_time; // 第一次故障动作时间
CString g_sLangID_Native_first_fault_impedance;
CString g_sLangTxt_Native_first_fault_impedance; // 第一次故障短路阻抗
CString g_sLangID_Native_first_fault_impedance_angle;
CString g_sLangTxt_Native_first_fault_impedance_angle; // 第一次故障短路阻抗角
CString g_sLangID_Native_second_fault_type;
CString g_sLangTxt_Native_second_fault_type; // 第二次故障类型
CString g_sLangID_Native_second_fault_current;
CString g_sLangTxt_Native_second_fault_current; // 第二次故障电流
CString g_sLangID_Native_second_faultact_time;
CString g_sLangTxt_Native_second_faultact_time; // 第二次故障动作时间
CString g_sLangID_Native_second_fault_impedance;
CString g_sLangTxt_Native_second_fault_impedance; // 第二次故障短路阻抗
CString g_sLangID_Native_second_fault_impedance_angle;
CString g_sLangTxt_Native_second_fault_impedance_angle; // 第二次故障短路阻抗角
CString g_sLangID_Native_first_fault_impAmp;
CString g_sLangTxt_Native_first_fault_impAmp; // 第一次故障短路阻抗(表达式)
CString g_sLangID_Native_first_fault_impAngAmp;
CString g_sLangTxt_Native_first_fault_impAngAmp; // 第一次故障短路阻抗角(表达式)
CString g_sLangID_Native_second_fault_impAmp;
CString g_sLangTxt_Native_second_fault_impAmp; // 第二次故障短路阻抗(表达式)
CString g_sLangID_Native_second_fault_impAngAmp;
CString g_sLangTxt_Native_second_fault_impAngAmp; // 第二次故障短路阻抗角(表达式)
CString g_sLangID_Native_synchronous_VAmpExp;
CString g_sLangTxt_Native_synchronous_VAmpExp; // 同期电压幅值(表达式)
CString g_sLangID_Native_synchronous_VPhExp;
CString g_sLangTxt_Native_synchronous_VPhExp; // 同期电压相位(表达式)
CString g_sLangID_Native_impedance_Set;
CString g_sLangTxt_Native_impedance_Set; // 阻抗定值(定值)
CString g_sLangID_Native_ImpedanceAnglesSet;
CString g_sLangTxt_Native_ImpedanceAnglesSet; // 阻抗角(定值)
CString g_sLangID_Native_Syn_closure_AngSet;
CString g_sLangTxt_Native_Syn_closure_AngSet; // 检同期合闸角(定值)
CString g_sLangID_Native_test_item_name;
CString g_sLangTxt_Native_test_item_name; // 测试项名称

//
CString g_sLangID_Native_0seqISet;
CString g_sLangTxt_Native_0seqISet; // 零序电流定值
CString g_sLangID_Native_YN_autoTestMode;
CString g_sLangTxt_Native_YN_autoTestMode; // 是否自动测试模式
CString g_sLangID_Native_0SeqISet;
CString g_sLangTxt_Native_0SeqISet; // 零序I-V段定值
CString g_sLangID_Native_0SeqIISet;
CString g_sLangTxt_Native_0SeqIISet;
CString g_sLangID_Native_0SeqIIISet;
CString g_sLangTxt_Native_0SeqIIISet;
CString g_sLangID_Native_0SeqIVSet;
CString g_sLangTxt_Native_0SeqIVSet;
CString g_sLangID_Native_0SeqVSet;
CString g_sLangTxt_Native_0SeqVSet;
CString g_sLangID_Native_0SeqITime;
CString g_sLangTxt_Native_0SeqITime; // 零序I-V段时间
CString g_sLangID_Native_0SeqIITime;
CString g_sLangTxt_Native_0SeqIITime;
CString g_sLangID_Native_0SeqIIITime;
CString g_sLangTxt_Native_0SeqIIITime;
CString g_sLangID_Native_0SeqIVTime;
CString g_sLangTxt_Native_0SeqIVTime;
CString g_sLangID_Native_0SeqVTime;
CString g_sLangTxt_Native_0SeqVTime;

// 第八周马
CString g_sLangID_Native_SeqComp;
CString g_sLangTxt_Native_SeqComp;
// tmt_adjust_sys_para_trans.cpp
/*_T("交流电压插件")*/
CString g_sLangID_Native_ACVoltPlugin;
CString g_sLangTxt_Native_ACVoltPlugin;
/*_T("交流电流插件")*/
CString g_sLangID_Native_ACCurrPlugin;
CString g_sLangTxt_Native_ACCurrPlugin;
/*_T("8个百兆口数字板")*/
CString g_sLangID_Native_8x100MbpsDB;
CString g_sLangTxt_Native_8x100MbpsDB;
/*_T("6个百兆口,2个千兆口数字板")*/
CString g_sLangID_Native_6x100M2x1000MDB;
CString g_sLangTxt_Native_6x100M2x1000MDB;
/*_T("4个百兆口,4个千兆口数字板")*/
CString g_sLangID_Native_4x100M4x1000MDB;
CString g_sLangTxt_Native_4x100M4x1000MDB;
/*_T("直流电流插件")*/
CString g_sLangID_Native_DCCurrPlugin;
CString g_sLangTxt_Native_DCCurrPlugin;
/*_T("直流电压插件")*/
CString g_sLangID_Native_DCVoltPlugin;
CString g_sLangTxt_Native_DCVoltPlugin;
/*_T("开关量扩展板")*/
CString g_sLangID_Native_DI_O_ExpBoard;
CString g_sLangTxt_Native_DI_O_ExpBoard;
/*_T("小信号模块插件")*/
CString g_sLangID_Native_LSModPlugin;
CString g_sLangTxt_Native_LSModPlugin;
/*_T("主板小信号")*/
CString g_sLangID_Native_MBLowSignal;
CString g_sLangTxt_Native_MBLowSignal;
/*_T("柔直FT3板")*/
CString g_sLangID_Native_FSFT3Board;
CString g_sLangTxt_Native_FSFT3Board;
/*_T("U、I混合插件")*/
CString g_sLangID_Native_UIHybridPlugin;
CString g_sLangTxt_Native_UIHybridPlugin;
/*_T("电压采集插件")*/
CString g_sLangID_Native_VoltAcqPlugin;
CString g_sLangTxt_Native_VoltAcqPlugin;
/*_T("电流采集插件")*/
CString g_sLangID_Native_CurrAcqPlugin;
CString g_sLangTxt_Native_CurrAcqPlugin;
/*_T("稳控2M通讯插件")*/
CString g_sLangID_Native_Stable2MCommPlugin;
CString g_sLangTxt_Native_Stable2MCommPlugin;
/*_T("采集")*/
CString g_sLangID_Native_Acquisition;
CString g_sLangTxt_Native_Acquisition;
/*_T("未定义")*/
CString g_sLangID_Native_Undefined;
CString g_sLangTxt_Native_Undefined;
/*_T("130伏电压模块")*/
CString g_sLangID_Native_130VVoltageModule;
CString g_sLangTxt_Native_130VVoltageModule;
/*_T("2480伏电压模块")*/
CString g_sLangID_Native_248VVoltageModule;
CString g_sLangTxt_Native_248VVoltageModule;
/*_T("270伏电压模块无升压")*/
CString g_sLangID_Native_270VVMNoBoost;
CString g_sLangTxt_Native_270VVMNoBoost;
/*_T("270伏电压模块有升压")*/
CString g_sLangID_Native_270VVModuleWBoost;
CString g_sLangTxt_Native_270VVModuleWBoost;
/*_T("300伏电压模块无升压")*/
CString g_sLangID_Native_300VVMNoBoost;
CString g_sLangTxt_Native_300VVMNoBoost;
/*_T("300伏电压模块有升压")*/
CString g_sLangID_Native_300VVModuleWBoost;
CString g_sLangTxt_Native_300VVModuleWBoost;
/*_T("12.5安电流模块")*/
CString g_sLangID_Native_125ACModule;
CString g_sLangTxt_Native_125ACModule;
/*_T("20安电流模块")*/
CString g_sLangID_Native_20ACModule;
CString g_sLangTxt_Native_20ACModule;
/*_T("32安电流模块")*/
CString g_sLangID_Native_32ACModule;
CString g_sLangTxt_Native_32ACModule;
/*_T("130伏20安混合模块")*/
CString g_sLangID_Native_125V20AHM;
CString g_sLangTxt_Native_125V20AHM;
/*_T("310伏60安混合模块")*/
CString g_sLangID_Native_310V60AHM;
CString g_sLangTxt_Native_310V60AHM;
/*_T("PFC_6A 模块")*/
CString g_sLangID_Native_PFC6A;
CString g_sLangTxt_Native_PFC6A;
/*_T("PIA12DS 模块")*/
CString g_sLangID_Native_P12DSM;
CString g_sLangTxt_Native_P12DSM;
/*_T("PIA48S 模块")*/
CString g_sLangID_Native_P48SM;
CString g_sLangTxt_Native_P48SM;
/*_T("EVTECT 模块")*/
CString g_sLangID_Native_EVTM;
CString g_sLangTxt_Native_EVTM;
/*_T("直流增量保护模块")*/
CString g_sLangID_Native_DCIPM;
CString g_sLangTxt_Native_DCIPM;
/*_T("6路10伏直流模块")*/
CString g_sLangID_Native_6C10VDCM;
CString g_sLangTxt_Native_6C10VDCM;
/*_T("6路20毫安直流模块")*/
CString g_sLangID_Native_6C20mADC;
CString g_sLangTxt_Native_6C20mADC;
/*_T("PN6U6I直流小信号模块")*/
CString g_sLangID_Native_PN6U6IDCSSM;
CString g_sLangTxt_Native_PN6U6IDCSSM;
/*_T("不支持输出合并")*/
CString g_sLangID_Native_OutputNotSupported;
CString g_sLangTxt_Native_OutputNotSupported;
/*_T("6路可以合并为1路")*/
CString g_sLangID_Native_6to1MergePossible;
CString g_sLangTxt_Native_6to1MergePossible;
/*_T("6路可以合并为3路")*/
CString g_sLangID_Native_6to3MergePossible;
CString g_sLangTxt_Native_6to3MergePossible;
/*_T("6路固定合并为3路")*/
CString g_sLangID_Native_6to3FixedMerge;
CString g_sLangTxt_Native_6to3FixedMerge;

// adjust_sys_parameter
/*"幅值系数"*/
CString g_sLangID_Native_AmpFactor;
CString g_sLangTxt_Native_AmpFactor;
/*"档位数"*/
CString g_sLangID_Native_NumGears;
CString g_sLangTxt_Native_NumGears;
/*"硬件1档直流零漂"*/
CString g_sLangID_Native_HW1DCZeroDrift;
CString g_sLangTxt_Native_HW1DCZeroDrift;
/*"硬件2档直流零漂"*/
CString g_sLangID_Native_HW2DCZeroDrift;
CString g_sLangTxt_Native_HW2DCZeroDrift;
/*"硬件3档直流零漂"*/
CString g_sLangID_Native_HW3DCZeroDrift;
CString g_sLangTxt_Native_HW3DCZeroDrift;
/*"大电流非线性系数"*/
CString g_sLangID_Native_LCNLCoeff;
CString g_sLangTxt_Native_LCNLCoeff;
/*"%d次谐波"*/
CString g_sLangID_Native_NthHarmonic;
CString g_sLangTxt_Native_NthHarmonic;
/*"温度"*/
CString g_sLangID_Native_Temp;
CString g_sLangTxt_Native_Temp;
/*"通道%d"*/
CString g_sLangID_Native_ChnN;
CString g_sLangTxt_Native_ChnN;
/*"档位ID"*/
CString g_sLangID_Native_GearID;
CString g_sLangTxt_Native_GearID;
/*"档位值"*/
CString g_sLangID_Native_GearVal;
CString g_sLangTxt_Native_GearVal;
/*"硬件档位数"*/
CString g_sLangID_Native_HwGearCount;
CString g_sLangTxt_Native_HwGearCount;
/*"校准系数"*/
CString g_sLangID_Native_CalibCoeff;
CString g_sLangTxt_Native_CalibCoeff;
/*"温区数"*/
CString g_sLangID_Native_TempZoneCount;
CString g_sLangTxt_Native_TempZoneCount;
/*"硬件通道"*/
CString g_sLangID_Native_HwChannel;
CString g_sLangTxt_Native_HwChannel;
/*"通道ID"*/
CString g_sLangID_Native_ChnID;
CString g_sLangTxt_Native_ChnID;
/*"通道索引"*/
CString g_sLangID_Native_ChnIndex;
CString g_sLangTxt_Native_ChnIndex;
/*"关联的软件资源"*/
CString g_sLangID_Native_AssocSWRes;
CString g_sLangTxt_Native_AssocSWRes;
/*"交流最大值"*/
CString g_sLangID_Native_ACMaxValue;
CString g_sLangTxt_Native_ACMaxValue;
/*"直流最大值"*/
CString g_sLangID_Native_DCMaxValue;
CString g_sLangTxt_Native_DCMaxValue;
/*"通道采集映射位置"*/
CString g_sLangID_Native_ChAcqMapLoc;
CString g_sLangTxt_Native_ChAcqMapLoc;
/*"工作模式"*/
CString g_sLangID_Native_OpMode;
CString g_sLangTxt_Native_OpMode;
/*"电气类型"*/
CString g_sLangID_Native_ElecType;
CString g_sLangTxt_Native_ElecType;
/*"硬件通道定义"*/
CString g_sLangID_Native_HwChDef;
CString g_sLangTxt_Native_HwChDef;
/*"通道驱动位置"*/
CString g_sLangID_Native_ChDrivePos;
CString g_sLangTxt_Native_ChDrivePos;
/*_T("通道%d位置")*/
CString g_sLangID_Native_ChPos;
CString g_sLangTxt_Native_ChPos;
/*"通道映射定义"*/
CString g_sLangID_Native_ChMapDef;
CString g_sLangTxt_Native_ChMapDef;
/*"模块属性"*/
CString g_sLangID_Native_ModProps;
CString g_sLangTxt_Native_ModProps;
/*"LC光口数"*/
CString g_sLangID_Native_LCOptPortCount;
CString g_sLangTxt_Native_LCOptPortCount;
/*"ST发送光口数"*/
CString g_sLangID_Native_STTxOptPortCount;
CString g_sLangTxt_Native_STTxOptPortCount;
/*"ST接收光口数"*/
CString g_sLangID_Native_STRxOptPortCount;
CString g_sLangTxt_Native_STRxOptPortCount;
/*"谐波数"*/
CString g_sLangID_Native_HarmOrder;
CString g_sLangTxt_Native_HarmOrder;
/*"直流电压通道最大值"*/
CString g_sLangID_Native_DCVoltChMax;
CString g_sLangTxt_Native_DCVoltChMax;
/*"直流电流通道最大值"*/
CString g_sLangID_Native_DCCurrChMax;
CString g_sLangTxt_Native_DCCurrChMax;
/*"通道出交流最大值"*/
CString g_sLangID_Native_ChACOutMax;
CString g_sLangTxt_Native_ChACOutMax;
/*"通道出直流最大值"*/
CString g_sLangID_Native_ChDCOutMax;
CString g_sLangTxt_Native_ChDCOutMax;
/*"频率补偿系数"*/
CString g_sLangID_Native_FreqCompCoeff;
CString g_sLangTxt_Native_FreqCompCoeff;
/*"数字硬件相位延时"*/
CString g_sLangID_Native_DigiHWPhaseDelay;
CString g_sLangTxt_Native_DigiHWPhaseDelay;
/*"电压电流硬件特性"*/
CString g_sLangID_Native_VoltCurrHWChar;
CString g_sLangTxt_Native_VoltCurrHWChar;
/*"电流通道合并模式"*/
CString g_sLangID_Native_CurrChMergeMode;
CString g_sLangTxt_Native_CurrChMergeMode;
/*"第一组开关量配为开入"*/
CString g_sLangID_Native_1stSetDigInCfg;
CString g_sLangTxt_Native_1stSetDigInCfg;
/*"第二组开关量配为开入"*/
CString g_sLangID_Native_2stSetDigInCfg;
CString g_sLangTxt_Native_2stSetDigInCfg;
/*"第三组开关量配为开入"*/
CString g_sLangID_Native_3stSetDigInCfg;
CString g_sLangTxt_Native_3stSetDigInCfg;
/*"第四组开关量配为开入"*/
CString g_sLangID_Native_4stSetDigInCfg;
CString g_sLangTxt_Native_4stSetDigInCfg;
/*"模块FPGA版本"*/
CString g_sLangID_Native_ModFPGAVer;
CString g_sLangTxt_Native_ModFPGAVer;
/*"模块属性版本"*/
CString g_sLangID_Native_ModAttrVer;
CString g_sLangTxt_Native_ModAttrVer;
/*"独立直流电流通道硬件档位"*/
CString g_sLangID_Native_IndepDCCurrChHWRange;
CString g_sLangTxt_Native_IndepDCCurrChHWRange;
/*"独立直流电压通道硬件档位"*/
CString g_sLangID_Native_IndepDCVoltChHWRange;
CString g_sLangTxt_Native_IndepDCVoltChHWRange;
/*"模块通道档位"*/
CString g_sLangID_Native_ModChRange;
CString g_sLangTxt_Native_ModChRange;
/*"开出量导通值定义"*/
CString g_sLangID_Native_TripRelayPickupDef;
CString g_sLangTxt_Native_TripRelayPickupDef;
/*"开出1导通值"*/
CString g_sLangID_Native_TripRelay1Pickup;
CString g_sLangTxt_Native_TripRelay1Pickup;
/*"开出2导通值"*/
CString g_sLangID_Native_TripRelay2Pickup;
CString g_sLangTxt_Native_TripRelay2Pickup;
/*"开出3导通值"*/
CString g_sLangID_Native_TripRelay3Pickup;
CString g_sLangTxt_Native_TripRelay3Pickup;
/*"开出4导通值"*/
CString g_sLangID_Native_TripRelay4Pickup;
CString g_sLangTxt_Native_TripRelay4Pickup;
/*"开出5导通值"*/
CString g_sLangID_Native_TripRelay5Pickup;
CString g_sLangTxt_Native_TripRelay5Pickup;
/*"开出6导通值"*/
CString g_sLangID_Native_TripRelay6Pickup;
CString g_sLangTxt_Native_TripRelay6Pickup;
/*"开出7导通值"*/
CString g_sLangID_Native_TripRelay7Pickup;
CString g_sLangTxt_Native_TripRelay7Pickup;
/*"开出8导通值"*/
CString g_sLangID_Native_TripRelay8Pickup;
CString g_sLangTxt_Native_TripRelay8Pickup;
/*"状态序列容量(个)"*/
CString g_sLangID_Native_StateSeqCapacity;
CString g_sLangTxt_Native_StateSeqCapacity;
/*"主板开入数量(个)"*/
CString g_sLangID_Native_MainBrdDInQty;
CString g_sLangTxt_Native_MainBrdDInQty;
/*"主板开出数量(个)"*/
CString g_sLangID_Native_MainBrdDOutQty;
CString g_sLangTxt_Native_MainBrdDOutQty;
/*"整秒时刻,模拟量绝对相位补偿(度)"*/
CString g_sLangID_Native_WSecMomentAnaPhAbsComp;
CString g_sLangTxt_Native_WSecMomentAnaPhAbsComp;
/*"启用控制权限判断(0-不启用，1-启用)"*/
CString g_sLangID_Native_CtrlAuthCheck;
CString g_sLangTxt_Native_CtrlAuthCheck;
/*"TestServer名称"*/
CString g_sLangID_Native_TestSrvName;
CString g_sLangTxt_Native_TestSrvName;
/*"TestServer版本"*/
CString g_sLangID_Native_TestSrvVersion;
CString g_sLangTxt_Native_TestSrvVersion;
/*"主板版本"*/
CString g_sLangID_Native_MainBrdVersion;
CString g_sLangTxt_Native_MainBrdVersion;
/*"驱动版本"*/
CString g_sLangID_Native_DrvVersion;
CString g_sLangTxt_Native_DrvVersion;
/*"驱动名称"*/
CString g_sLangID_Native_DrvName;
CString g_sLangTxt_Native_DrvName;
/*"主板ST口模式可设置"*/
CString g_sLangID_Native_MainBrdSTPortModeCfg;
CString g_sLangTxt_Native_MainBrdSTPortModeCfg;
/*"系统版本号"*/
CString g_sLangID_Native_SysVerNumber;
CString g_sLangTxt_Native_SysVerNumber;

// tmt_adjust_test
/*"校准项目"*/
CString g_sLangID_Native_CalibItem;
CString g_sLangTxt_Native_CalibItem;
/*"点1幅值"*/
CString g_sLangID_Native_Pt1Amp;
CString g_sLangTxt_Native_Pt1Amp;
/*"点2幅值"*/
CString g_sLangID_Native_Pt2Amp;
CString g_sLangTxt_Native_Pt2Amp;

// tmt_dig_replay_test
/*"发送(选择该控制块)"*/
CString g_sLangID_Native_SelCtrlBlock;
CString g_sLangTxt_Native_SelCtrlBlock;
/*"控制块输出光口数量"*/
CString g_sLangID_Native_CtrlBlkOutOptPortsCnt;
CString g_sLangTxt_Native_CtrlBlkOutOptPortsCnt;
/*"控制块AppID"*/
CString g_sLangID_Native_CtrlBlkAppID;
CString g_sLangTxt_Native_CtrlBlkAppID;
/*"控制块输出总帧数"*/
CString g_sLangID_Native_CtrlBlkOutTotalFrames;
CString g_sLangTxt_Native_CtrlBlkOutTotalFrames;
/*"控制块输出起始帧号(本控制块内排序)"*/
CString g_sLangID_Native_CtrlBlkOutStartFrmNum;
CString g_sLangTxt_Native_CtrlBlkOutStartFrmNum;
/*"控制块输出结束帧号(本控制块内排序)"*/
CString g_sLangID_Native_CtrlBlkOutEndFrmNum;
CString g_sLangTxt_Native_CtrlBlkOutEndFrmNum;
/*"控制块延时补偿值(单位:us)"*/
CString g_sLangID_Native_CtrlBlkDelayCompValue;
CString g_sLangTxt_Native_CtrlBlkDelayCompValue;
/*"采样值控制块数量"*/
CString g_sLangID_Native_NumOfSVCBs;
CString g_sLangTxt_Native_NumOfSVCBs;
/*"GOOSE控制块数量"*/
CString g_sLangID_Native_NumOfGCBs;
CString g_sLangTxt_Native_NumOfGCBs;
/*"SV回放模式(0:按时间间隔,1:等间隔,2:自定义)"*/
CString g_sLangID_Native_SVReplayMode;
CString g_sLangTxt_Native_SVReplayMode;
/*"GOOSE回放模式(0:按时间间隔,1:等间隔)"*/
CString g_sLangID_Native_GOOSEReplayMode;
CString g_sLangTxt_Native_GOOSEReplayMode;
/*"SV等间隔回放间隔时间(us)"*/
CString g_sLangID_Native_SVEqReplayIntervalTime_us;
CString g_sLangTxt_Native_SVEqReplayIntervalTime_us;
/*"GOOSE等间隔回放间隔时间(us)"*/
CString g_sLangID_Native_GOOSEEqReplayIntervalTime_us;
CString g_sLangTxt_Native_GOOSEEqReplayIntervalTime_us;
/*"自定义回放抖动值(us)"*/
CString g_sLangID_Native_CustomReplayJitter_us;
CString g_sLangTxt_Native_CustomReplayJitter_us;
/*"是否循环(0不循环,1循环)"*/
CString g_sLangID_Native_LoopingFlag;
CString g_sLangTxt_Native_LoopingFlag;
/*"回放区间设置类型(0全部回放,1部分回放)"*/
CString g_sLangID_Native_ReplayIntervalType;
CString g_sLangTxt_Native_ReplayIntervalType;
/*"输出起始帧号(全部控制块排序)"*/
CString g_sLangID_Native_StartFrameNum;
CString g_sLangTxt_Native_StartFrameNum;
/*"输出结束帧号(全部控制块排序)"*/
CString g_sLangID_Native_EndFrameNum;
CString g_sLangTxt_Native_EndFrameNum;
/*"GPS触发时刻(时)"*/
CString g_sLangID_Native_GPSTriggerTime_hr;
CString g_sLangTxt_Native_GPSTriggerTime_hr;
/*"GPS触发时刻(分)"*/
CString g_sLangID_Native_GPSTriggerTime_min;
CString g_sLangTxt_Native_GPSTriggerTime_min;
/*"GPS触发时刻(秒)"*/
CString g_sLangID_Native_GPSTriggerTime_sec;
CString g_sLangTxt_Native_GPSTriggerTime_sec;
/*"输出时长(s)"*/
CString g_sLangID_Native_OutputDuration_sec;
CString g_sLangTxt_Native_OutputDuration_sec;
/*"开入%c选择"*/
CString g_sLangID_Native_InputSelection;
CString g_sLangTxt_Native_InputSelection;

// tmt_gradient_test
/*"返回系数整定值"*/
CString g_sLangID_Native_FeedbackCoefSettingVal;
CString g_sLangTxt_Native_FeedbackCoefSettingVal;
/*"边界角1整定值"*/
CString g_sLangID_Native_BoundaryAngle1SetVal;
CString g_sLangTxt_Native_BoundaryAngle1SetVal;
/*"边界角2整定值"*/
CString g_sLangID_Native_BoundaryAngle2SetVal;
CString g_sLangTxt_Native_BoundaryAngle2SetVal;
/*"最大灵敏角整定值"*/
CString g_sLangID_Native_MaxSensitivityAngleSetVal;
CString g_sLangTxt_Native_MaxSensitivityAngleSetVal;
/*"步长时间(秒)"*/
CString g_sLangID_Native_StepTimeSec;
CString g_sLangTxt_Native_StepTimeSec;
/*"故障态组2电压幅值"*/
CString g_sLangID_Native_FSG2VoltageAmplitude;
CString g_sLangTxt_Native_FSG2VoltageAmplitude;
/*"故障态组2电流幅值"*/
CString g_sLangID_Native_FSG2CurrentAmplitude;
CString g_sLangTxt_Native_FSG2CurrentAmplitude;
/*"额定电压幅值"*/
CString g_sLangID_Native_RatedVoltageAmplitude;
CString g_sLangTxt_Native_RatedVoltageAmplitude;
/*"常态电压相序"*/
CString g_sLangID_Native_NomVoltPhaseSeq;
CString g_sLangTxt_Native_NomVoltPhaseSeq;
/*"常态电流相序"*/
CString g_sLangID_Native_NomCurrPhaseSeq;
CString g_sLangTxt_Native_NomCurrPhaseSeq;
/*"常态电压幅值"*/
CString g_sLangID_Native_NomVoltAmplitude;
CString g_sLangTxt_Native_NomVoltAmplitude;
/*"常态电流幅值"*/
CString g_sLangID_Native_NomCurrAmplitude;
CString g_sLangTxt_Native_NomCurrAmplitude;

/*"Ua1幅值"*/
CString g_sLangID_Native_Ua1Amp;
CString g_sLangTxt_Native_Ua1Amp;
/*"Ua1相位"*/
CString g_sLangID_Native_Ua1Ph;
CString g_sLangTxt_Native_Ua1Ph;
/*"Ua2幅值"*/
CString g_sLangID_Native_Ua2Amp;
CString g_sLangTxt_Native_Ua2Amp;
/*"Ua2相位"*/
CString g_sLangID_Native_Ua2Ph;
CString g_sLangTxt_Native_Ua2Ph;

/*"Ub1幅值"*/
CString g_sLangID_Native_Ub1Amp;
CString g_sLangTxt_Native_Ub1Amp;
/*"Ub1相位"*/
CString g_sLangID_Native_Ub1Ph;
CString g_sLangTxt_Native_Ub1Ph;
/*"Ub2幅值"*/
CString g_sLangID_Native_Ub2Amp;
CString g_sLangTxt_Native_Ub2Amp;
/*"Ub2相位"*/
CString g_sLangID_Native_Ub2Ph;
CString g_sLangTxt_Native_Ub2Ph;

/*"Uc1幅值"*/
CString g_sLangID_Native_Uc1Amp;
CString g_sLangTxt_Native_Uc1Amp;
/*"Uc1相位"*/
CString g_sLangID_Native_Uc1Ph;
CString g_sLangTxt_Native_Uc1Ph;
/*"Uc2幅值"*/
CString g_sLangID_Native_Uc2Amp;
CString g_sLangTxt_Native_Uc2Amp;
/*"Uc2相位"*/
CString g_sLangID_Native_Uc2Ph;
CString g_sLangTxt_Native_Uc2Ph;

/*"Ia1幅值"*/
CString g_sLangID_Native_Ia1Amp;
CString g_sLangTxt_Native_Ia1Amp;
/*"Ia1相位"*/
CString g_sLangID_Native_Ia1Ph;
CString g_sLangTxt_Native_Ia1Ph;
/*"Ia2幅值"*/
CString g_sLangID_Native_Ia2Amp;
CString g_sLangTxt_Native_Ia2Amp;
/*"Ia2相位"*/
CString g_sLangID_Native_Ia2Ph;
CString g_sLangTxt_Native_Ia2Ph;

/*"Ib1幅值"*/
CString g_sLangID_Native_Ib1Amp;
CString g_sLangTxt_Native_Ib1Amp;
/*"Ib1相位"*/
CString g_sLangID_Native_Ib1Ph;
CString g_sLangTxt_Native_Ib1Ph;
/*"Ib2幅值"*/
CString g_sLangID_Native_Ib2Amp;
CString g_sLangTxt_Native_Ib2Amp;
/*"Ib2相位"*/
CString g_sLangID_Native_Ib2Ph;
CString g_sLangTxt_Native_Ib2Ph;

/*"Ic1幅值"*/
CString g_sLangID_Native_Ic1Amp;
CString g_sLangTxt_Native_Ic1Amp;
/*"Ic1相位"*/
CString g_sLangID_Native_Ic1Ph;
CString g_sLangTxt_Native_Ic1Ph;
/*"Ic2幅值"*/
CString g_sLangID_Native_Ic2Amp;
CString g_sLangTxt_Native_Ic2Amp;
/*"Ic2相位"*/
CString g_sLangID_Native_Ic2Ph;
CString g_sLangTxt_Native_Ic2Ph;

/*"频率动作值绝对误差"*/
CString g_sLangID_Native_FreqPickAbsErr;
CString g_sLangTxt_Native_FreqPickAbsErr;
/*"频率动作值相对误差"*/
CString g_sLangID_Native_FreqPickRelErr;
CString g_sLangTxt_Native_FreqPickRelErr;
/*"频率动作值误差判断逻辑"*/
CString g_sLangID_Native_FreqPickErrDetectLogic;
CString g_sLangTxt_Native_FreqPickErrDetectLogic;
/*"最大灵敏角绝对误差"*/
CString g_sLangID_Native_MaxSensAngAbsErr;
CString g_sLangTxt_Native_MaxSensAngAbsErr;
/*"最大灵敏角相对误差"*/
CString g_sLangID_Native_MaxSensAngRelErr;
CString g_sLangTxt_Native_MaxSensAngRelErr;
/*"最大灵敏角误差判断逻辑"*/
CString g_sLangID_Native_MaxSensAngErrDetectLogic;
CString g_sLangTxt_Native_MaxSensAngErrDetectLogic;
/*"边界角1绝对误差"*/
CString g_sLangID_Native_BndryAng1AbsErr;
CString g_sLangTxt_Native_BndryAng1AbsErr;
/*"边界角1相对误差"*/
CString g_sLangID_Native_BndryAng1RelErr;
CString g_sLangTxt_Native_BndryAng1RelErr;
/*"边界角1误差判断逻辑"*/
CString g_sLangID_Native_BndryAng1ErrDetectLogic;
CString g_sLangTxt_Native_BndryAng1ErrDetectLogic;
/*"边界角2绝对误差"*/
CString g_sLangID_Native_BndryAng2AbsErr;
CString g_sLangTxt_Native_BndryAng2AbsErr;
/*"边界角2相对误差"*/
CString g_sLangID_Native_BndryAng2RelErr;
CString g_sLangTxt_Native_BndryAng2RelErr;
/*"边界角2误差判断逻辑"*/
CString g_sLangID_Native_BndryAng2ErrDetectLogic;
CString g_sLangTxt_Native_BndryAng2ErrDetectLogic;
/*"返回系数有效"*/
CString g_sLangID_Native_RetCoeffValid;
CString g_sLangTxt_Native_RetCoeffValid;
/*"绝对误差有效"*/
CString g_sLangID_Native_AbsErrValid;
CString g_sLangTxt_Native_AbsErrValid;
/*"频率动作值误差"*/
CString g_sLangID_Native_FreqTripValErr;
CString g_sLangTxt_Native_FreqTripValErr;
/*"相位动作值误差"*/
CString g_sLangID_Native_PhaseTripValErr;
CString g_sLangTxt_Native_PhaseTripValErr;
/*"返回系数误差"*/
CString g_sLangID_Native_RetCoeffError;
CString g_sLangTxt_Native_RetCoeffError;
/*"最大灵敏角误差"*/
CString g_sLangID_Native_MaxSensAngleErr;
CString g_sLangTxt_Native_MaxSensAngleErr;
/*"边界角1误差"*/
CString g_sLangID_Native_BndryAngle1Err;
CString g_sLangTxt_Native_BndryAngle1Err;
/*"边界角2误差"*/
CString g_sLangID_Native_BndryAngle2Err;
CString g_sLangTxt_Native_BndryAngle2Err;

// tmt_harm_test
/*"%d次谐波相位"*/
CString g_sLangID_Native_NthHarmPhase;
CString g_sLangTxt_Native_NthHarmPhase;
/*"%d次谐波幅值"*/
CString g_sLangID_Native_NthHarmAmpl;
CString g_sLangTxt_Native_NthHarmAmpl;
/*"直流分量"*/
CString g_sLangID_Native_DCCompVaule;
CString g_sLangTxt_Native_DCCompVaule;
/*"自动变化设置"*/
CString g_sLangID_Native_AutoVarConfig;
CString g_sLangTxt_Native_AutoVarConfig;
/*"是否自动变化"*/
CString g_sLangID_Native_AutoVarStatus;
CString g_sLangTxt_Native_AutoVarStatus;
/*"变化量选择"*/
CString g_sLangID_Native_VarSelect;
CString g_sLangTxt_Native_VarSelect;
/*"变化类型选择"*/
CString g_sLangID_Native_VarTypeSelect;
CString g_sLangTxt_Native_VarTypeSelect;
/*"变化谐波次数"*/
CString g_sLangID_Native_VarHarmonicNum;
CString g_sLangTxt_Native_VarHarmonicNum;

// tmt_manu_test
/*"是否以直流模式输出"*/
CString g_sLangID_Native_DCOutputMode;
CString g_sLangTxt_Native_DCOutputMode;
/*"谐波叠加"*/
CString g_sLangID_Native_HarmSuperposition;
CString g_sLangTxt_Native_HarmSuperposition;
/*"谐波选择"*/
CString g_sLangID_Native_HarmSelection;
CString g_sLangTxt_Native_HarmSelection;
/*"合并单元"*/
CString g_sLangID_Native_MrgUnit;
CString g_sLangTxt_Native_MrgUnit;
/*"算法选择(0:插值法  1:同步法)"*/
CString g_sLangID_Native_AlgorithmSelection;
CString g_sLangTxt_Native_AlgorithmSelection;
/*"PPS设置(0:上升沿有效  1:下降沿有效 2:无PPS)"*/
CString g_sLangID_Native_PPSConfiguration;
CString g_sLangTxt_Native_PPSConfiguration;
/*"额定相电压(零漂计算)"*/
CString g_sLangID_Native_RatedV_Phase_ZeroDriftCalc;
CString g_sLangTxt_Native_RatedV_Phase_ZeroDriftCalc;
/*"额定相电流(零漂计算)"*/
CString g_sLangID_Native_RatedI_Phase_ZeroDriftCalc;
CString g_sLangTxt_Native_RatedI_Phase_ZeroDriftCalc;
/*"守时精度测试时同步时长(单位:s)"*/
CString g_sLangID_Native_SyncDur_TAT;
CString g_sLangTxt_Native_SyncDur_TAT;
/*"无PPS时延时补偿值(对时守时测试用,单位:μs)"*/
CString g_sLangID_Native_DelayComp_NoPPS;
CString g_sLangTxt_Native_DelayComp_NoPPS;
/*"是否使用自定义报告次数(合并单元)"*/
CString g_sLangID_Native_CustomRepCnt_Use_MU;
CString g_sLangTxt_Native_CustomRepCnt_Use_MU;
/*"自定义报告测试次数(合并单元)"*/
CString g_sLangID_Native_CustomRepTestCnt_MU;
CString g_sLangTxt_Native_CustomRepTestCnt_MU;
/*"每次测试时间(合并单元,单位秒)"*/
CString g_sLangID_Native_TestDurPerTest_MU_sec;
CString g_sLangTxt_Native_TestDurPerTest_MU_sec;
/*"MU时间测试结果"*/
CString g_sLangID_Native_MUTimeTestResults;
CString g_sLangTxt_Native_MUTimeTestResults;
/*"已测试时长"*/
CString g_sLangID_Native_TestedDur;
CString g_sLangTxt_Native_TestedDur;
/*"最大误差时间"*/
CString g_sLangID_Native_MaxErrTime;
CString g_sLangTxt_Native_MaxErrTime;
/*"最小误差时间"*/
CString g_sLangID_Native_MinErrTime;
CString g_sLangTxt_Native_MinErrTime;
/*"平均误差时间"*/
CString g_sLangID_Native_AvgErrTime;
CString g_sLangTxt_Native_AvgErrTime;
/*"时间精度测试结果"*/
CString g_sLangID_Native_TimeAccTestResults;
CString g_sLangTxt_Native_TimeAccTestResults;
/*"Ua频率"*/
CString g_sLangID_Native_UaFreq;
CString g_sLangTxt_Native_UaFreq;
/*"Ub频率"*/
CString g_sLangID_Native_UbFreq;
CString g_sLangTxt_Native_UbFreq;
/*"Uc频率"*/
CString g_sLangID_Native_UcFreq;
CString g_sLangTxt_Native_UcFreq;

/*"Uap幅值"*/
CString g_sLangID_Native_UapAmp;
CString g_sLangTxt_Native_UapAmp;
/*"Uap相位"*/
CString g_sLangID_Native_UapPhase;
CString g_sLangTxt_Native_UapPhase;
/*"Uap频率"*/
CString g_sLangID_Native_UapFreq;
CString g_sLangTxt_Native_UapFreq;

/*"Ubp幅值"*/
CString g_sLangID_Native_UbpAmp;
CString g_sLangTxt_Native_UbpAmp;
/*"Ubp相位"*/
CString g_sLangID_Native_UbpPhase;
CString g_sLangTxt_Native_UbpPhase;
/*"Ubp频率"*/
CString g_sLangID_Native_UbpFreq;
CString g_sLangTxt_Native_UbpFreq;

/*"Ucp幅值"*/
CString g_sLangID_Native_UcpAmp;
CString g_sLangTxt_Native_UcpAmp;
/*"Ucp相位"*/
CString g_sLangID_Native_UcpPhase;
CString g_sLangTxt_Native_UcpPhase;
/*"Ucp频率"*/
CString g_sLangID_Native_UcpFreq;
CString g_sLangTxt_Native_UcpFreq;

/*"Ia幅值"*/
CString g_sLangID_Native_IaAmp;
CString g_sLangTxt_Native_IaAmp;
/*"Ia相位"*/
CString g_sLangID_Native_IaPhase;
CString g_sLangTxt_Native_IaPhase;
/*"Ia频率"*/
CString g_sLangID_Native_IaFreq;
CString g_sLangTxt_Native_IaFreq;

/*"Ib幅值"*/
CString g_sLangID_Native_IbAmp;
CString g_sLangTxt_Native_IbAmp;
/*"Ib相位"*/
CString g_sLangID_Native_IbPhase;
CString g_sLangTxt_Native_IbPhase;
/*"Ib频率"*/
CString g_sLangID_Native_IbFreq;
CString g_sLangTxt_Native_IbFreq;

/*"Ic幅值"*/
CString g_sLangID_Native_IcAmp;
CString g_sLangTxt_Native_IcAmp;
/*"Ic相位"*/
CString g_sLangID_Native_IcPhase;
CString g_sLangTxt_Native_IcPhase;
/*"Ic频率"*/
CString g_sLangID_Native_IcFreq;
CString g_sLangTxt_Native_IcFreq;

/*"Iap幅值"*/
CString g_sLangID_Native_IapAmp;
CString g_sLangTxt_Native_IapAmp;
/*"Iap相位"*/
CString g_sLangID_Native_IapPhase;
CString g_sLangTxt_Native_IapPhase;
/*"Iap频率"*/
CString g_sLangID_Native_IapFreq;
CString g_sLangTxt_Native_IapFreq;

/*"Ibp幅值"*/
CString g_sLangID_Native_IbpAmp;
CString g_sLangTxt_Native_IbpAmp;
/*"Ibp相位"*/
CString g_sLangID_Native_IbpPhase;
CString g_sLangTxt_Native_IbpPhase;
/*"Ibp频率"*/
CString g_sLangID_Native_IbpFreq;
CString g_sLangTxt_Native_IbpFreq;

/*"Icp幅值"*/
CString g_sLangID_Native_IcpAmp;
CString g_sLangTxt_Native_IcpAmp;
/*"Icp相位"*/
CString g_sLangID_Native_IcpPhase;
CString g_sLangTxt_Native_IcpPhase;
/*"Icp频率"*/
CString g_sLangID_Native_IcpFreq;
CString g_sLangTxt_Native_IcpFreq;

/*"测试功能类别(0:普通手动试验1:MU精度测试2:MU零漂测试)"*/
CString g_sLangID_Native_TestFuncCategory;
CString g_sLangTxt_Native_TestFuncCategory;

// tmt_pt_test
/*"PT1阻值"*/
CString g_sLangID_Native_PT1Impedance;
CString g_sLangTxt_Native_PT1Impedance;
/*"PT2阻值"*/
CString g_sLangID_Native_PT2Impedance;
CString g_sLangTxt_Native_PT2Impedance;

// tmt_record
/*"接收光口"*/
CString g_sLangID_Native_RecvOptPort;
CString g_sLangTxt_Native_RecvOptPort;
/*"订阅总数"*/
CString g_sLangID_Native_TotalSubs;
CString g_sLangTxt_Native_TotalSubs;

// tmt_NEW
/*"Uas幅值"*/
CString g_sLangID_Native_UasAmp;
CString g_sLangTxt_Native_UasAmp;
/*"Uas相位"*/
CString g_sLangID_Native_UasPhase;
CString g_sLangTxt_Native_UasPhase;
/*"Uas频率"*/
CString g_sLangID_Native_UasFreq;
CString g_sLangTxt_Native_UasFreq;

/*"Ubs幅值"*/
CString g_sLangID_Native_UbsAmp;
CString g_sLangTxt_Native_UbsAmp;
/*"Ubs相位"*/
CString g_sLangID_Native_UbsPhase;
CString g_sLangTxt_Native_UbsPhase;
/*"Ubs频率"*/
CString g_sLangID_Native_UbsFreq;
CString g_sLangTxt_Native_UbsFreq;

/*"Ucs幅值"*/
CString g_sLangID_Native_UcsAmp;
CString g_sLangTxt_Native_UcsAmp;
/*"Ucs相位"*/
CString g_sLangID_Native_UcsPhase;
CString g_sLangTxt_Native_UcsPhase;
/*"Ucs频率"*/
CString g_sLangID_Native_UcsFreq;
CString g_sLangTxt_Native_UcsFreq;

/*"Uat幅值"*/
CString g_sLangID_Native_UatAmp;
CString g_sLangTxt_Native_UatAmp;
/*"Uat相位"*/
CString g_sLangID_Native_UatPhase;
CString g_sLangTxt_Native_UatPhase;
/*"Uat频率"*/
CString g_sLangID_Native_UatFreq;
CString g_sLangTxt_Native_UatFreq;

/*"Ubt幅值"*/
CString g_sLangID_Native_UbtAmp;
CString g_sLangTxt_Native_UbtAmp;
/*"Ubt相位"*/
CString g_sLangID_Native_UbtPhase;
CString g_sLangTxt_Native_UbtPhase;
/*"Ubt频率"*/
CString g_sLangID_Native_UbtFreq;
CString g_sLangTxt_Native_UbtFreq;

/*"Uct幅值"*/
CString g_sLangID_Native_UctAmp;
CString g_sLangTxt_Native_UctAmp;
/*"Uct相位"*/
CString g_sLangID_Native_UctPhase;
CString g_sLangTxt_Native_UctPhase;
/*"Uct频率"*/
CString g_sLangID_Native_UctFreq;
CString g_sLangTxt_Native_UctFreq;

/*"Ias幅值"*/
CString g_sLangID_Native_IasAmp;
CString g_sLangTxt_Native_IasAmp;
/*"Ias相位"*/
CString g_sLangID_Native_IasPhase;
CString g_sLangTxt_Native_IasPhase;
/*"Ias频率"*/
CString g_sLangID_Native_IasFreq;
CString g_sLangTxt_Native_IasFreq;

/*"Ibs幅值"*/
CString g_sLangID_Native_IbsAmp;
CString g_sLangTxt_Native_IbsAmp;
/*"Ibs相位"*/
CString g_sLangID_Native_IbsPhase;
CString g_sLangTxt_Native_IbsPhase;
/*"Ibs频率"*/
CString g_sLangID_Native_IbsFreq;
CString g_sLangTxt_Native_IbsFreq;

/*"Ics幅值"*/
CString g_sLangID_Native_IcsAmp;
CString g_sLangTxt_Native_IcsAmp;
/*"Ics相位"*/
CString g_sLangID_Native_IcsPhase;
CString g_sLangTxt_Native_IcsPhase;
/*"Ics频率"*/
CString g_sLangID_Native_IcsFreq;
CString g_sLangTxt_Native_IcsFreq;

/*"Iat幅值"*/
CString g_sLangID_Native_IatAmp;
CString g_sLangTxt_Native_IatAmp;
/*"Iat相位"*/
CString g_sLangID_Native_IatPhase;
CString g_sLangTxt_Native_IatPhase;
/*"Iat频率"*/
CString g_sLangID_Native_IatFreq;
CString g_sLangTxt_Native_IatFreq;

/*"Ibt幅值"*/
CString g_sLangID_Native_IbtAmp;
CString g_sLangTxt_Native_IbtAmp;
/*"Ibt相位"*/
CString g_sLangID_Native_IbtPhase;
CString g_sLangTxt_Native_IbtPhase;
/*"Ibt频率"*/
CString g_sLangID_Native_IbtFreq;
CString g_sLangTxt_Native_IbtFreq;

/*"Ict幅值"*/
CString g_sLangID_Native_IctAmp;
CString g_sLangTxt_Native_IctAmp;
/*"Ict相位"*/
CString g_sLangID_Native_IctPhase;
CString g_sLangTxt_Native_IctPhase;
/*"Ict频率"*/
CString g_sLangID_Native_IctFreq;
CString g_sLangTxt_Native_IctFreq;

// tmt_replay_test
/*"模块%d"*/
CString g_sLangID_Native_ModReplace;
CString g_sLangTxt_Native_ModReplace;
/*"测试仪通道%d_A通道序号"*/
CString g_sLangID_Native_TIC_A_Chn_Num;
CString g_sLangTxt_Native_TIC_A_Chn_Num;
/*"测试仪通道%d_B通道序号"*/
CString g_sLangID_Native_TIC_B_Chn_Num;
CString g_sLangTxt_Native_TIC_B_Chn_Num;
/*"测试仪通道%d_变比"*/
CString g_sLangID_Native_TIC_TransfRatio;
CString g_sLangTxt_Native_TIC_TransfRatio;
/*"采样频率"*/
CString g_sLangID_Native_SampFreq;
CString g_sLangTxt_Native_SampFreq;
/*"PT变比一次值"*/
CString g_sLangID_Native_PT_TxRatio_Primary;
CString g_sLangTxt_Native_PT_TxRatio_Primary;
/*"PT变比二次值"*/
CString g_sLangID_Native_PT_TxRatio_Secondary;
CString g_sLangTxt_Native_PT_TxRatio_Secondary;
/*"CT变比一次值"*/
CString g_sLangID_Native_CT_TxRatio_Primary;
CString g_sLangTxt_Native_CT_TxRatio_Primary;
/*"CT变比二次值"*/
CString g_sLangID_Native_CT_TxRatio_Secondary;
CString g_sLangTxt_Native_CT_TxRatio_Secondary;
/*"模块数"*/
CString g_sLangID_Native_NumOfModules;
CString g_sLangTxt_Native_NumOfModules;
/*"录波文件名称"*/
CString g_sLangID_Native_WaveFileName;
CString g_sLangTxt_Native_WaveFileName;
/*"周波数"*/
CString g_sLangID_Native_NumCycles;
CString g_sLangTxt_Native_NumCycles;
/*"触发后模式"*/
CString g_sLangID_Native_PostTrigMode;
CString g_sLangTxt_Native_PostTrigMode;
/*"实验触发时间"*/
CString g_sLangID_Native_ExpTrigTime;
CString g_sLangTxt_Native_ExpTrigTime;
/*"全部循环次数"*/
CString g_sLangID_Native_CycleIndex;
CString g_sLangTxt_Native_CycleIndex;
/*"手动控制"*/
CString g_sLangID_Native_ManualControl;
CString g_sLangTxt_Native_ManualControl;	 
/*"时间间隔"*/
CString g_sLangID_Native_ReplayInterval;
CString g_sLangTxt_Native_ReplayInterval;

CString g_sLangID_Native_ImpedanceEditBox;	// = _T("Native_ImpedanceEditBox")
CString g_sLangTxt_Native_ImpedanceEditBox; // = _T("阻抗特性编辑框")

// 第九周吕
// CString g_sLangID_Native_jumpctrl;
// CString g_sLangTxt_Native_jumpctrl;//跳合信号控制
// CString g_sLangID_Native_timectrl;
// CString g_sLangTxt_Native_timectrl;//时间控制
// CString g_sLangID_Native_totalweight;
// CString g_sLangTxt_Native_totalweight;//综重（单重+三重）
// CString g_sLangID_Native_tripleweight;
// CString g_sLangTxt_Native_tripleweight;//三重
// CString g_sLangID_Native_norepeat;
// CString g_sLangTxt_Native_norepeat;//不重合
// CString g_sLangID_Native_Totransformer;
// CString g_sLangTxt_Native_Totransformer;//指向变压器
// CString g_sLangID_Native_lagrange;
// CString g_sLangTxt_Native_lagrange;//拉格朗日插值法
// CString g_sLangID_Native_linear;
// CString g_sLangTxt_Native_linear;//线性插值法
// CString g_sLangID_Native_faultvoltype;
// CString g_sLangTxt_Native_faultvoltype;//故障电压类型
//
// CString g_sLangID_Native_Difsetting;
// CString g_sLangTxt_Native_Difsetting;//差动定值整定方式
// CString g_sLangID_Native_DifCurChoose;
// CString g_sLangTxt_Native_DifCurChoose;//差动基准电流选择
// CString g_sLangID_Native_harmonicnumber;
// CString g_sLangTxt_Native_harmonicnumber;//谐波次数选择//谐波次数选择
// CString g_sLangID_Native_CuroutputPhase;
// CString g_sLangTxt_Native_CuroutputPhase;//电流输出相//电流输出相
// CString g_sLangID_Native_PhaseAshort;
// CString g_sLangTxt_Native_PhaseAshort;//A相短路
// CString g_sLangID_Native_PhaseBshort;
// CString g_sLangTxt_Native_PhaseBshort;//B相短路
// CString g_sLangID_Native_PhaseCshort;
// CString g_sLangTxt_Native_PhaseCshort;//C相短路
// CString g_sLangID_Native_PhaseABCshort;
// CString g_sLangTxt_Native_PhaseABCshort;//ABC相短路

// UI
// Harm
CString g_sLangID_Native_VolactValue;
CString g_sLangTxt_Native_VolactValue; // 电压动作值(%)
CString g_sLangID_Native_CuractValue;
CString g_sLangTxt_Native_CuractValue; // 电流动作值(%)
CString g_sLangID_Native_harmonicNotChecked;
CString g_sLangTxt_Native_harmonicNotChecked; // 指定通道的谐波未被勾选!

// IEC61850Config
CString g_sLangID_Native_DCVmapping;
CString g_sLangTxt_Native_DCVmapping; // 直流电压映射
CString g_sLangID_Native_DCImapping;
CString g_sLangTxt_Native_DCImapping; // 直流电流映射
CString g_sLangID_Native_ACVmapping;
CString g_sLangTxt_Native_ACVmapping; // 交流电压映射
CString g_sLangID_Native_ACImapping;
CString g_sLangTxt_Native_ACImapping; // 交流电流映射
CString g_sLangID_Native_FailtoGetsclPath;
CString g_sLangTxt_Native_FailtoGetsclPath; // 获取SCL文件路径失败(%s).
CString g_sLangID_Native_codesSetting;
CString g_sLangTxt_Native_codesSetting; // 码值设置
CString g_sLangID_Native_DCPart;
CString g_sLangTxt_Native_DCPart; // 直流部分
CString g_sLangID_Native_ACPart;
CString g_sLangTxt_Native_ACPart; // 交流部分

CString g_sLangID_Native_selected;
CString g_sLangTxt_Native_selected; // 已选中
CString g_sLangID_Native_schematic;
CString g_sLangTxt_Native_schematic; // 示意图
CString g_sLangID_Native_codesValue;
CString g_sLangTxt_Native_codesValue; // 码值

// ImportDvmFile
CString g_sLangID_Native_modifyto;
CString g_sLangTxt_Native_modifyto; // 修改为
CString g_sLangID_Native_function;
CString g_sLangTxt_Native_function; // 功能
CString g_sLangID_Native_completeconfig;
CString g_sLangTxt_Native_completeconfig; // 完成配置
CString g_sLangID_Native_nextitem;
CString g_sLangTxt_Native_nextitem; // 上一项
CString g_sLangID_Native_previtem;
CString g_sLangTxt_Native_previtem; // 上一项
CString g_sLangID_Native_ttybzd;
CString g_sLangTxt_Native_ttybzd; //_投退压板整定
CString g_sLangID_Native_FixedValueSet;
CString g_sLangTxt_Native_FixedValueSet; //_修改定值整定

// KeyBoard
CString g_sLangID_Native_PYResnotFound;
CString g_sLangTxt_Native_PYResnotFound; // 没有找到中文拼音资源文件!

//
CString g_sLangID_Native_dataid;
CString g_sLangTxt_Native_dataid; // 数据ID
CString g_sLangID_Native_paramselect;
CString g_sLangTxt_Native_paramselect; // 参数选择

CString g_sLangID_Native_globalparams;
CString g_sLangTxt_Native_globalparams; // 全局参数
CString g_sLangID_Native_reportdata;
CString g_sLangTxt_Native_reportdata; // 报告数据
CString g_sLangID_Native_switchreport;
CString g_sLangTxt_Native_switchreport; // 切换报告

CString g_sLangID_Native_reportdataname;
CString g_sLangTxt_Native_reportdataname; // 报告数据名称
CString g_sLangID_Native_paramone;
CString g_sLangTxt_Native_paramone; // 参数一
CString g_sLangID_Native_paramtwo;
CString g_sLangTxt_Native_paramtwo; // 参数二
CString g_sLangID_Native_baselineparams;
CString g_sLangTxt_Native_baselineparams; // 基准参数
CString g_sLangID_Native_errorresult;
CString g_sLangTxt_Native_errorresult; // 误差结果
CString g_sLangID_Native_errorlimit;
CString g_sLangTxt_Native_errorlimit; // 误差限
CString g_sLangID_Native_notcalculated;
CString g_sLangTxt_Native_notcalculated; // 未计算
CString g_sLangID_Native_baseline_min;
CString g_sLangTxt_Native_baseline_min; // 基准-最小值
CString g_sLangID_Native_baseline_max;
CString g_sLangTxt_Native_baseline_max; // 基准-最大值
CString g_sLangID_Native_operationresult;
CString g_sLangTxt_Native_operationresult; // 运算结果

// 第九周许
// 10.30
CString g_sLangID_Native_SelectParamFirst;	// = _T("Native_SelectParamFirst")
CString g_sLangTxt_Native_SelectParamFirst; // = _T("请先在左侧选中需要映射的参数，然后再进行映射……")
CString g_sLangID_Native_NoValidMapData;	// = _T("Native_NoValidMapData")
CString g_sLangTxt_Native_NoValidMapData;	// = _T("当前配置没找到有效的映射数据，配置无效！")
CString g_sLangID_Native_DeviceModel;		// = _T("Native_DeviceModel")
CString g_sLangTxt_Native_DeviceModel;		// = _T("装置模型：（先在左侧表格，选中需要映射的参数，然后双击映射）")
CString g_sLangID_Native_Dataset;			// = _T("Native_Dataset")
CString g_sLangTxt_Native_Dataset;			// = _T("数据集：")
CString g_sLangID_Native_AddNew;			// = _T("Native_AddNew")
CString g_sLangTxt_Native_AddNew;			// = _T("新增")
CString g_sLangID_Native_ClearMap;			// = _T("Native_ClearMap")
CString g_sLangTxt_Native_ClearMap;			// = _T("清空所有映射")
CString g_sLangID_Native_ClearSel;			// = _T("Native_ClearSel")
CString g_sLangTxt_Native_ClearSel;			// = _T("清除选中映射")
CString g_sLangID_Native_CustomName;		// = _T("Native_CustomName")
CString g_sLangTxt_Native_CustomName;		// = _T("自定义名称")
CString g_sLangID_Native_RealDevData;		// = _T("Native_RealDevData")
CString g_sLangTxt_Native_RealDevData;		// = _T("实际装置的数据名称")
CString g_sLangID_Native_DataInSet;			// = _T("Native_DataInSet")
CString g_sLangTxt_Native_DataInSet;		// = _T("数据所在数据集")
CString g_sLangID_Native_CurveName;			// = _T("Native_CurveName")
CString g_sLangTxt_Native_CurveName;		// = _T("曲线名称")
CString g_sLangID_Native_SingleTimeLimit;	// = _T("Native_SingleTimeLimit")
CString g_sLangTxt_Native_SingleTimeLimit;	// = _T("1段定时限")
CString g_sLangID_Native_DoubleTimeLimit;	// = _T("Native_DoubleTimeLimit")
CString g_sLangTxt_Native_DoubleTimeLimit;	// = _T("2段定时限")
CString g_sLangID_Native_TripleTimeLimit;	// = _T("Native_TripleTimeLimit")
CString g_sLangTxt_Native_TripleTimeLimit;	// = _T("3段定时限")
CString g_sLangID_Native_CurrentValueI;		// = _T("Native_CurrentValueI")
CString g_sLangTxt_Native_CurrentValueI;	// = _T("电流值")
CString g_sLangID_Native_ActionThres;		// = _T("Native_ActionThres")
CString g_sLangTxt_Native_ActionThres;		// = _T("动作门槛")
CString g_sLangID_Native_FeatCurveElem;		// = _T("Native_FeatCurveElem")
CString g_sLangTxt_Native_FeatCurveElem;	// = _T("特性曲线元素")
CString g_sLangID_Native_IEEECurveSet;		// = _T("Native_IEEECurveSet")
CString g_sLangTxt_Native_IEEECurveSet;		// = _T("IEEE曲线元素设置")
CString g_sLangID_Native_IACCurveSet;		// = _T("Native_IACCurveSet")
CString g_sLangTxt_Native_IACCurveSet;		// = _T("IAC曲线元素设置")
CString g_sLangID_Native_I2TCurveSet;		// = _T("Native_I2TCurveSet")
CString g_sLangTxt_Native_I2TCurveSet;		// = _T("I2T曲线元素设置")
CString g_sLangID_Native_IECCurveSet;		// = _T("Native_IECCurveSet")
CString g_sLangTxt_Native_IECCurveSet;		// = _T("IEC曲线元素设置")
CString g_sLangID_Native_Threshold;			// = _T("Native_Threshold")
CString g_sLangTxt_Native_Threshold;		// = _T("门槛值")
CString g_sLangID_Native_QuickBreak;		// = _T("Native_QuickBreak")
CString g_sLangTxt_Native_QuickBreak;		// = _T("速断定值")
CString g_sLangID_Native_FirstPart;			// = _T("Native_FirstPart")
CString g_sLangTxt_Native_FirstPart;		// = _T("第一段")
CString g_sLangID_Native_Inflection1;		// = _T("Inflection1")
CString g_sLangTxt_Native_Inflection1;		// = _T("拐点1")
CString g_sLangID_Native_SecondPart;		//=_T("Native_SecondPart");
CString g_sLangTxt_Native_SecondPart;		//=_T("第二段");
CString g_sLangID_Native_InflectionPoint2;	// = _T("Native_InflectionPoint2")
CString g_sLangTxt_Native_InflectionPoint2; // = _T("拐点2")
CString g_sLangID_Native_TestCtrlProgDate;	// = _T("Native_TestCtrlProgDate")
CString g_sLangTxt_Native_TestCtrlProgDate; // = _T("当前测试控制程序生成日期(%s).")
CString g_sLangID_Native_DebugOutput;		// = _T("Native_DebugOutput")
CString g_sLangTxt_Native_DebugOutput;		// = _T("输出调试")
//CString g_sLangID_Native_StartOutput;		// = _T("Native_StartOutput")
//CString g_sLangTxt_Native_StartOutput;		// = _T("开始输出")
CString g_sLangID_Native_StopOutput;		// = _T("Native_StopOutput")
CString g_sLangTxt_Native_StopOutput;		// = _T("停止输出")
//CString g_sLangID_Native_TestAnomalies;     //= _T("Native_TestAnomalies");
//CString g_sLangTxt_Native_TestAnomalies;    //= _T("测试异常");
//CString g_sLangID_Native_RelieveTestAnomalies; //= _T("Native_RelieveTestAnomalies")
//CString g_sLangTxt_Native_RelieveTestAnomalies; //= _T("解除测试异常")
//CString g_sLangID_Native_StateSwitch;        //= _T("Native_StateSwitch");
//CString g_sLangTxt_Native_StateSwitch;       //= _T("状态切换");
//CString g_sLangID_Native_SupDCSwitch;        //= _T("Native_SupDCSwitch");
//CString g_sLangTxt_Native_SupDCSwitch;       //= _T("辅助直流切换");
//CString g_sLangID_Native_BinDisPlace;        // = _T("Native_BinDisPlace");
//CString g_sLangTxt_Native_BinDisPlace;       //= _T("开入变位");
//CString g_sLangID_Native_BoutDisPlace;       //= _T("Native_BinDisPlace");
//CString g_sLangTxt_Native_BoutDisPlace;      //= _T("开出变位");
//CString g_sLangID_Native_ParaUpdata;         //= _T("Native_ParaUpdata");
//CString g_sLangTxt_Native_ParaUpdata;        //= _T("参数更新");
CString g_sLangID_Native_OpenFail;			// = _T("Native_OpenFail")
CString g_sLangTxt_Native_OpenFail;			// = _T("打开文件(%s)失败.")
CString g_sLangID_Native_Disconnect;		// = _T("Native_Disconnect")
CString g_sLangTxt_Native_Disconnect;		// = _T("与测试仪断开连接，请检查网络链路是否连通，IP地址及端口配置是否正确；重新连接")
CString g_sLangID_Native_StateGraph;		// = _T("Native_StateGraph")
CString g_sLangTxt_Native_StateGraph;		// = _T("状态图")
CString g_sLangID_Native_SoftResID;			// = _T("Native_SoftResID")
CString g_sLangTxt_Native_SoftResID;		// = _T("软件资源标识")
CString g_sLangID_Native_EnterNum;			// = _T("Native_EnterNum")
CString g_sLangTxt_Native_EnterNum;			// = _T("请输入数值，不能为空！")
CString g_sLangID_Native_SendByWave;		// = _T("Native_SendByWave")
CString g_sLangTxt_Native_SendByWave;		// = _T("按周波发送")
CString g_sLangID_Native_SendBySec;			// = _T("Native_SendBySec")
CString g_sLangTxt_Native_SendBySec;		// = _T("按秒发送")
CString g_sLangID_Native_StateNetID;		// = _T("Native_StateNetID")
CString g_sLangTxt_Native_StateNetID;		// = _T("当前状态%d : 网络标识(0x%s)与原网络标识(0x%s)不一致")
CString g_sLangID_Native_ExportWords;		// = _T("Native_ExportWords")
CString g_sLangTxt_Native_ExportWords;		// = _T("导出Word报告")
CString g_sLangID_Native_WordDoc;			// = _T("Native_WordDoc")
CString g_sLangTxt_Native_WordDoc;			// = _T("Word报告文件 (*.doc)")
CString g_sLangID_Native_ExportPath;		// = _T("Native_ExportPath")
CString g_sLangTxt_Native_ExportPath;		// = _T("导出路径：")

// 第九周马
/*_T("stt_rcd_unzip_file解压缩出错.")*/
CString g_sLangID_Native_UnzipError;
CString g_sLangTxt_Native_UnzipError;
/*_T("导出Pcap文件界面")*/
CString g_sLangID_Native_ExpPcapInterf;
CString g_sLangTxt_Native_ExpPcapInterf;
/*_T("原始数据文件:")*/
CString g_sLangID_Native_RawDataFile;
CString g_sLangTxt_Native_RawDataFile;
/*_T("选择...")*/
CString g_sLangID_Native_SelectOmit;
CString g_sLangTxt_Native_SelectOmit;
/*_T("Pcap文件名:")*/
CString g_sLangID_Native_PcapFileN;
CString g_sLangTxt_Native_PcapFileN;
/*_T("开始转换")*/
CString g_sLangID_Native_StartConver;
CString g_sLangTxt_Native_StartConver;
/*_T("at02d压缩文件(*.at02dz);;at02d文件(*.at02d)")*/
CString g_sLangID_Native_at02dCompFiles;
CString g_sLangTxt_Native_at02dCompFiles;
/*_T("请先选择原始数据文件.")*/
CString g_sLangID_Native_SelectRawFile;
CString g_sLangTxt_Native_SelectRawFile;
/*_T("请先设置生成文件名称.")*/
CString g_sLangID_Native_SetOutFileName;
CString g_sLangTxt_Native_SetOutFileName;
/*_T("当前原始数据文件(%s)不存在.")*/
CString g_sLangID_Native_CurRawFileNotEx;
CString g_sLangTxt_Native_CurRawFileNotEx;
/*_T("Pcap文件(%s)生成成功.")*/
CString g_sLangID_Native_PcapGenSuccess;
CString g_sLangTxt_Native_PcapGenSuccess;
/*_T("Pcap文件(%s)生成失败.")*/
CString g_sLangID_Native_PcapGenFailed;
CString g_sLangTxt_Native_PcapGenFailed;
/*"波特率"*/
CString g_sLangID_Native_BaudRate;
CString g_sLangTxt_Native_BaudRate;
/*"报文长度"*/
CString g_sLangID_Native_MsgLength;
CString g_sLangTxt_Native_MsgLength;
/*_T("未知的报文类型(%u).")*/
CString g_sLangID_Native_UnkwnMsgType;
CString g_sLangTxt_Native_UnkwnMsgType;
/*_T("当前解析的报文帧数为0,需收到报文后,才能关联.")*/
CString g_sLangID_Native_CurrPsdM0AssocAftRcvM;
CString g_sLangTxt_Native_CurrPsdM0AssocAftRcvM;
/*("录波时间")*/
CString g_sLangID_Native_RecTime;
CString g_sLangTxt_Native_RecTime;
/*_T("停止录波")*/
CString g_sLangID_Native_StopRecrd;
CString g_sLangTxt_Native_StopRecrd;
/*_T("有效值")*/
CString g_sLangID_Native_ValdValue;
CString g_sLangTxt_Native_ValdValue;
/*_T("含有率")*/
CString g_sLangID_Native_IncRate;
CString g_sLangTxt_Native_IncRate;
/*_T("柱状图")*/
CString g_sLangID_Native_BarChar;
CString g_sLangTxt_Native_BarChar;
/*_T("录波")*/
CString g_sLangID_Native_RecWaveform;
CString g_sLangTxt_Native_RecWaveform;
/*_T("当前写文件路径为空.")*/
CString g_sLangID_Native_CurrWrtFileEmpty;
CString g_sLangTxt_Native_CurrWrtFileEmpty;
/*_T("文件保存为")*/
CString g_sLangID_Native_SaveAs;
CString g_sLangTxt_Native_SaveAs;
/*_T("文件(%s)保存成功.")*/
CString g_sLangID_Native_FileSavedSucc;
CString g_sLangTxt_Native_FileSavedSucc;
/*文件已存在，是否替换？*/
CString g_sLangID_Native_FileExist;
CString g_sLangTxt_Native_FileExist;
/*文件保存成功*/
CString g_sLangID_Native_FileSave;
CString g_sLangTxt_Native_FileSave;
/*接收*/
CString g_sLangID_Native_Accept;
CString g_sLangTxt_Native_Accept;
/*_T("文件(%s)保存失败.")*/
CString g_sLangID_Native_FileSaveFailed;
CString g_sLangTxt_Native_FileSaveFailed;
/*_T("SV报文离散度视图")*/
CString g_sLangID_Native_SVMsgDispersView;
CString g_sLangTxt_Native_SVMsgDispersView;
/*_T("直流(V/A)")*/
CString g_sLangID_Native_DCVoltAmp;
CString g_sLangTxt_Native_DCVoltAmp;
/*_T("基波(V/A)")*/
CString g_sLangID_Native_FundamentalVA;
CString g_sLangTxt_Native_FundamentalVA;
/*_T("底层测试模板生成失败.")*/
CString g_sLangID_Native_LowLevelTmplFail;
CString g_sLangTxt_Native_LowLevelTmplFail;
/*_T("开始测试命令下发失败.")*/
CString g_sLangID_Native_StartTestSendFail;
CString g_sLangTxt_Native_StartTestSendFail;
/*_T("停止测试命令下发失败.")*/
CString g_sLangID_Native_StopTestSendFail;
CString g_sLangTxt_Native_StopTestSendFail;
/*_T("状态%ld动作时间%.4lfs.")*/
CString g_sLangID_Native_StatusLDActTime;
CString g_sLangTxt_Native_StatusLDActTime;
/*_T("?????????????? OnCmd_NewTest: 关闭打开的测试功能页面，并弹框提示是否保存修改 ???????????")*/
CString g_sLangID_Native_CloseFeatPromptSave;
CString g_sLangTxt_Native_CloseFeatPromptSave;
// 插入数据
CString g_sLangID_Native_InsData;
CString g_sLangTxt_Native_InsData;
// 执行通信
CString g_sLangID_Native_ExecComm;
CString g_sLangTxt_Native_ExecComm;
// 删除选中数据
CString g_sLangID_Native_DelSelData;
CString g_sLangTxt_Native_DelSelData;
/*"是否变化上送"*/
CString g_sLangID_Native_SendChanges;
CString g_sLangTxt_Native_SendChanges;
// 周期时间
CString g_sLangID_Native_CycleTm;
CString g_sLangTxt_Native_CycleTm;
// 误差名称
CString g_sLangID_Native_ErrName;
CString g_sLangTxt_Native_ErrName;
// 误差值
CString g_sLangID_Native_ErrValue;
CString g_sLangTxt_Native_ErrValue;
// 测试分类
CString g_sLangID_Native_TestCat;
CString g_sLangTxt_Native_TestCat;
// 标题等级
CString g_sLangID_Native_TitleLvl;
CString g_sLangTxt_Native_TitleLvl;
// 项目标识
CString g_sLangID_Native_ProjIdent;
CString g_sLangTxt_Native_ProjIdent;
// 作为Word标题
CString g_sLangID_Native_AsWordTitle;
CString g_sLangTxt_Native_AsWordTitle;
// 修改项目名称
CString g_sLangID_Native_ModProjName;
CString g_sLangTxt_Native_ModProjName;
// 向导
CString g_sLangID_Native_Wizard;
CString g_sLangTxt_Native_Wizard;
// 上一步
CString g_sLangID_Native_PrevStep;
CString g_sLangTxt_Native_PrevStep;
/*_T("网页文件(%s)不存在.")*/
CString g_sLangID_Native_WebPageNotExst;
CString g_sLangTxt_Native_WebPageNotExst;
/*_T("未选择IED")*/
CString g_sLangID_Native_IEDNotSel;
CString g_sLangTxt_Native_IEDNotSel;

// Controls
// 设备类型
CString g_sLangID_Native_DevType;
CString g_sLangTxt_Native_DevType;
// 规约引擎
CString g_sLangID_Native_ProtoEngin;
CString g_sLangTxt_Native_ProtoEngin;
// 装置IP
CString g_sLangID_Native_DevIP;
CString g_sLangTxt_Native_DevIP;
// 装置端口
CString g_sLangID_Native_DevPort;
CString g_sLangTxt_Native_DevPort;
// 规约模板
CString g_sLangID_Native_ProtoTemp;
CString g_sLangTxt_Native_ProtoTemp;
// 从SCD文件选择
CString g_sLangID_Native_SelSCDFile;
CString g_sLangTxt_Native_SelSCDFile;
// 高级配置
CString g_sLangID_Native_AdvConfig;
CString g_sLangTxt_Native_AdvConfig;
// 时间定值单位为ms
CString g_sLangID_Native_TimeSetUnit;
CString g_sLangTxt_Native_TimeSetUnit;
// 添加装置复归态
CString g_sLangID_Native_AddDevReset;
CString g_sLangTxt_Native_AddDevReset;
/*"新分类"*/
CString g_sLangID_Native_NewCat;
CString g_sLangTxt_Native_NewCat;
/*"存在相同名称的项目"*/
CString g_sLangID_Native_ProjSameExists;
CString g_sLangTxt_Native_ProjSameExists;
/*"存在相同ID的项目"*/
CString g_sLangID_Native_ProjSameIDExists;
CString g_sLangTxt_Native_ProjSameIDExists;
// 测试次数 >1时，自动更新到项目名称
CString g_sLangID_Native_TestCntGt1AutoUpdtProjName;
CString g_sLangTxt_Native_TestCntGt1AutoUpdtProjName;
// 名称作为word标题
CString g_sLangID_Native_NameWordTitle;
CString g_sLangTxt_Native_NameWordTitle;
/*_T("请在此处输入接线提示信息……")*/
CString g_sLangID_Native_PlsEntWiringInstruc;
CString g_sLangTxt_Native_PlsEntWiringInstruc;
/*_T("未找到对应的预置提示信息，请在此处输入接线提示信息……")*/
CString g_sLangID_Native_NoMatchPresetInstrucPlsEntWiring;
CString g_sLangTxt_Native_NoMatchPresetInstrucPlsEntWiring;
// 选择需要的接线提示信息
CString g_sLangID_Native_SelDesiredWiringInstruc;
CString g_sLangTxt_Native_SelDesiredWiringInstruc;
/*"确实要删除 ["*/
CString g_sLangID_Native_DeletestrMsg;
CString g_sLangTxt_Native_DeletestrMsg;
/*"] 吗？"*/
CString g_sLangID_Native_DeletestrMsg2;
CString g_sLangTxt_Native_DeletestrMsg2;
/*_T(" ] 吗？删除后无法恢复！")*/
CString g_sLangID_Native_DeletestrMsg3;
CString g_sLangTxt_Native_DeletestrMsg3;
/*"测试后恢复"*/
CString g_sLangID_Native_RestoreAfterTest;
CString g_sLangTxt_Native_RestoreAfterTest;
/*"测试前准备"*/
CString g_sLangID_Native_PrepBeforeTest;
CString g_sLangTxt_Native_PrepBeforeTest;
/*tr("新建项目分类")*/
CString g_sLangID_Native_CreateProjCat;
CString g_sLangTxt_Native_CreateProjCat;
/*tr("新建测试前准备")*/
CString g_sLangID_Native_CreatePrepBeforeTest;
CString g_sLangTxt_Native_CreatePrepBeforeTest;
/*tr("新建测试后恢复")*/
CString g_sLangID_Native_CreateReplyAfterTest;
CString g_sLangTxt_Native_CreateReplyAfterTest;
/*tr("删除当前选中项目")*/
CString g_sLangID_Native_DeleteCurrSelectedProj;
CString g_sLangTxt_Native_DeleteCurrSelectedProj;
/*tr("编辑当前选中项目")*/
CString g_sLangID_Native_EditCurrSelectedProj;
CString g_sLangTxt_Native_EditCurrSelectedProj;
/*tr("保存当前选中项目")*/
CString g_sLangID_Native_SaveCurrSelectedProj;
CString g_sLangTxt_Native_SaveCurrSelectedProj;
/*tr("添加功能向导")*/
CString g_sLangID_Native_AddFuncWizard;
CString g_sLangTxt_Native_AddFuncWizard;
/*tr("从当前选中项目开始测试")*/
CString g_sLangID_Native_StartTestFromSelProj;
CString g_sLangTxt_Native_StartTestFromSelProj;
/*tr("测试当前选中项目")*/
CString g_sLangID_Native_TestCurrSelProj;
CString g_sLangTxt_Native_TestCurrSelProj;
/*"新建通讯命令"*/
CString g_sLangID_Native_CreateCommCommand;
CString g_sLangTxt_Native_CreateCommCommand;
/*_T("确认删除项目")*/
CString g_sLangID_Native_ConfirmDelProj;
CString g_sLangTxt_Native_ConfirmDelProj;
/*_T("重命名当前选中项目")*/
CString g_sLangID_Native_RenameCurrSelProj;
CString g_sLangTxt_Native_RenameCurrSelProj;
/*_T("删除接线提示")*/
CString g_sLangID_Native_DeleteWiringInstr;
CString g_sLangTxt_Native_DeleteWiringInstr;
/*_T("添加测试前、后通讯组合")*/
CString g_sLangID_Native_AddPrePostCommCombo;
CString g_sLangTxt_Native_AddPrePostCommCombo;
/*_T("新建配置项目")*/
CString g_sLangID_Native_CreateConfigProj;
CString g_sLangTxt_Native_CreateConfigProj;
/*_T("硬件通道映射")*/
CString g_sLangID_Native_HWChanMapping;
CString g_sLangTxt_Native_HWChanMapping;
/*_T("IEC61850配置")*/
CString g_sLangID_Native_IEC61850Config;
CString g_sLangTxt_Native_IEC61850Config;
/*_T("确认删除接线提示")*/
CString g_sLangID_Native_ConfirmDelWiringInstr;
CString g_sLangTxt_Native_ConfirmDelWiringInstr;
/*_T("保存项目指令，创建通讯命令失败！")*/
CString g_sLangID_Native_SaveProjInstrFailCommCmd;
CString g_sLangTxt_Native_SaveProjInstrFailCommCmd;
/*_T("当前选中的项目，不存在！请重新选择项目后进行测试")*/
CString g_sLangID_Native_SelProjNotExistRetryTest;
CString g_sLangTxt_Native_SelProjNotExistRetryTest;
/*_T("该功能暂不支持……")*/
CString g_sLangID_Native_NotSupportFeature;
CString g_sLangTxt_Native_NotSupportFeature;
// 添加至:子项
CString g_sLangID_Native_AddSubitem;
CString g_sLangTxt_Native_AddSubitem;
// 添加至:项之前
CString g_sLangID_Native_AddBeforeItem;
CString g_sLangTxt_Native_AddBeforeItem;
// 添加至:项之后
CString g_sLangID_Native_AddAfterItem;
CString g_sLangTxt_Native_AddAfterItem;
/*_T("项目结果")*/
CString g_sLangID_Native_ProjResults;
CString g_sLangTxt_Native_ProjResults;
/*_T("全部报告数据")*/
CString g_sLangID_Native_AllRptData;
CString g_sLangTxt_Native_AllRptData;
/*_T("报告数据-数据集")*/
CString g_sLangID_Native_RptDataDataset;
CString g_sLangTxt_Native_RptDataDataset;
/*_T("测试结论")*/
CString g_sLangID_Native_TestConcl;
CString g_sLangTxt_Native_TestConcl;
/*_T("查看报告")*/
CString g_sLangID_Native_ViewRpt;
CString g_sLangTxt_Native_ViewRpt;
/*_T("次测试")*/
CString g_sLangID_Native_TestRun;
CString g_sLangTxt_Native_TestRun;
/*_T("次计算结果")*/
CString g_sLangID_Native_CalcResult;
CString g_sLangTxt_Native_CalcResult;

CString g_sLangID_Native_GroundDisSetV;
CString g_sLangTxt_Native_GroundDisSetV; // 接地距离定值（1-5段）GroundDisSet

CString g_sLangID_Adjustment_Time;	//= _T("Adjustment_Time");
CString g_sLangTxt_Adjustment_Time; //=  _T("整定动作时间");
CString g_sLangID_Native_GroundDisTimeI;
CString g_sLangTxt_Native_GroundDisTimeI;
CString g_sLangID_Native_GroundDisTimeII;
CString g_sLangTxt_Native_GroundDisTimeII;
CString g_sLangID_Native_GroundDisTimeIII;
CString g_sLangTxt_Native_GroundDisTimeIII;
CString g_sLangID_Native_GroundDisTimeIV;
CString g_sLangTxt_Native_GroundDisTimeIV;
CString g_sLangID_Native_GroundDisTimeV;
CString g_sLangTxt_Native_GroundDisTimeV; // 接地距离时间（1-5段）GroundDisTime
CString g_sLangID_Native_AbnCurr;		  // = _T("Native_AbnCurr")
CString g_sLangTxt_Native_AbnCurr;		  // = _T("异常电流")
CString g_sLangID_Native_harmonicOrder;
CString g_sLangTxt_Native_harmonicOrder; // 谐波次数

CString g_sLangID_Native_AbnData;  // = _T("Native_AbnData")
CString g_sLangTxt_Native_AbnData; // = _T("异常数据")

CString g_sLangID_Native_harmRepresent;
CString g_sLangTxt_Native_harmRepresent; // 谐波表示方式
CString g_sLangID_Native_Identifier;	 // = _T("Native_Identifier")
CString g_sLangTxt_Native_Identifier;	 // = _T("标识")
CString g_sLangID_Native_InLogic;		 // = _T("Native_InLogic")
CString g_sLangTxt_Native_InLogic;		 // = _T("开入逻辑")
CString g_sLangID_Native_InputSet;		 // = _T("Native_InputSet")
CString g_sLangTxt_Native_InputSet;		 // = _T("开入量设置")
/*QObject::tr("速断电流")*/
CString g_sLangID_Native_InstCurr;
CString g_sLangTxt_Native_InstCurr;
CString g_sLangID_Native_IsDC;	// = _T("Native_IsDC")
CString g_sLangTxt_Native_IsDC; // = _T("是否直流")

CString g_sLangID_Native_AbnPointSet;  // = _T("Native_AbnPointSet")
CString g_sLangTxt_Native_AbnPointSet; // = _T("异常点设置")
CString g_sLangID_Native_JitterTest;   // = _T("Native_JitterTest")
CString g_sLangTxt_Native_JitterTest;  // = _T("抖动测试")
CString g_sLangID_Native_JitterVal;	   // = _T("Native_JitterVal")
CString g_sLangTxt_Native_JitterVal;   // = _T("抖动值")

CString g_sLangID_Native_AbnVolt;	   // = _T("Native_AbnVolt")
CString g_sLangTxt_Native_AbnVolt;	   // = _T("异常电压")
CString g_sLangID_Native_JumpVal;	   // = _T("Native_JumpVal")
CString g_sLangTxt_Native_JumpVal;	   // = _T("跳变值")
CString g_sLangID_Native_MaxTimeMalf;  //=_T("Native_MaxTimeMalf");
CString g_sLangTxt_Native_MaxTimeMalf; //=_T("最大故障时间");

CString g_sLangID_Native_actionSetting;
CString g_sLangTxt_Native_actionSetting; // 动作定值
CString g_sLangID_Native_ModAllChan;	 // = _T("Native_ModAllChan")
CString g_sLangTxt_Native_ModAllChan;	 // = _T("修改全部通道值")
CString g_sLangID_Native_MsgSel;		 // = _T("Native_MsgSel")
CString g_sLangTxt_Native_MsgSel;		 // = _T("报文选择")
CString g_sLangID_Native_MsgSet;		 // = _T("Native_MsgSet")
CString g_sLangTxt_Native_MsgSet;		 // = _T("报文设置")
CString g_sLangID_Native_Multiple;		 // = _T("Native_Multiple")
CString g_sLangTxt_Native_Multiple;		 // = _T("倍数")
/*tr("故障前电压")*/
CString g_sLangID_Native_PreFaultVolt;
CString g_sLangTxt_Native_PreFaultVolt;
CString g_sLangID_Native_BCodeLogic;  // = _T("Native_BCodeLogic")
CString g_sLangTxt_Native_BCodeLogic; // = _T("B码逻辑")
CString g_sLangID_Native_PhSetActValue;
CString g_sLangTxt_Native_PhSetActValue; // 相位整定动作值
/*tr("故障前电流")*/
CString g_sLangID_Native_PreFaultCurr;
CString g_sLangTxt_Native_PreFaultCurr;
CString g_sLangID_Native_Number;  // = _T("Native_Number")
CString g_sLangTxt_Native_Number; // = _T("第")
/*tr("边界角1")*/
CString g_sLangID_Native_BoundAngle1;
CString g_sLangTxt_Native_BoundAngle1;
/*tr("边界角2")*/
CString g_sLangID_Native_BoundAngle2;
CString g_sLangTxt_Native_BoundAngle2;
CString g_sLangID_Native_ChannelSelect;	 //=_T("Native_ChannelSelect");
CString g_sLangTxt_Native_ChannelSelect; //=_T("通道选择");
CString g_sLangID_Native_PhaseDisSetI;
CString g_sLangTxt_Native_PhaseDisSetI;
CString g_sLangID_Native_PhaseDisSetII;
CString g_sLangTxt_Native_PhaseDisSetII;
CString g_sLangID_Native_PhaseDisSetIII;
CString g_sLangTxt_Native_PhaseDisSetIII;
CString g_sLangID_Native_PhaseDisSetIV;
CString g_sLangTxt_Native_PhaseDisSetIV;
CString g_sLangID_Native_PhaseDisSetV;
CString g_sLangTxt_Native_PhaseDisSetV; // 相间距离定值（1-5段）
CString g_sLangID_Native_PhaseDisTimeI;
CString g_sLangTxt_Native_PhaseDisTimeI;
CString g_sLangID_Native_PhaseDisTimeII;
CString g_sLangTxt_Native_PhaseDisTimeII;
CString g_sLangID_Native_PhaseDisTimeIII;
CString g_sLangTxt_Native_PhaseDisTimeIII;
CString g_sLangID_Native_PhaseDisTimeIV;
CString g_sLangTxt_Native_PhaseDisTimeIV;
CString g_sLangID_Native_PhaseDisTimeV;
CString g_sLangTxt_Native_PhaseDisTimeV; // 相间距离时间（1-5段）
CString g_sLangID_Native_NatureMalf;	 //=_T("Native_NatureMalf");
CString g_sLangTxt_Native_NatureMalf;	 //=_T("故障性质");

// 接地距离 电阻定值（1-5段）
CString g_sLangID_Native_GroundResetI;
CString g_sLangTxt_Native_GroundResetI;
CString g_sLangID_Native_GroundResetII;
CString g_sLangTxt_Native_GroundResetII;
CString g_sLangID_Native_GroundResetIII;
CString g_sLangTxt_Native_GroundResetIII;
CString g_sLangID_Native_GroundResetIV;
CString g_sLangTxt_Native_GroundResetIV;
CString g_sLangID_Native_GroundResetV;
CString g_sLangTxt_Native_GroundResetV; 

 // 接地距离电抗 （1-5段）
CString g_sLangID_Native_GroundXesetI;
CString g_sLangTxt_Native_GroundXesetI;
CString g_sLangID_Native_GroundXesetII;
CString g_sLangTxt_Native_GroundXesetII;
CString g_sLangID_Native_GroundXesetIII;
CString g_sLangTxt_Native_GroundXesetIII;
CString g_sLangID_Native_GroundXesetIV;
CString g_sLangTxt_Native_GroundXesetIV;
CString g_sLangID_Native_GroundXesetV;
CString g_sLangTxt_Native_GroundXesetV;

// 相间距离 电阻定值（1-5段）
CString g_sLangID_Native_PhaseResetI;
CString g_sLangTxt_Native_PhaseResetI;
CString g_sLangID_Native_PhaseResetII;
CString g_sLangTxt_Native_PhaseResetII;
CString g_sLangID_Native_PhaseResetIII;
CString g_sLangTxt_Native_PhaseResetIII;
CString g_sLangID_Native_PhaseResetIV;
CString g_sLangTxt_Native_PhaseResetIV;
CString g_sLangID_Native_PhaseResetV;
CString g_sLangTxt_Native_PhaseResetV; 

 // 相间距离电抗 （1-5段）
CString g_sLangID_Native_PhaseXesetI;
CString g_sLangTxt_Native_PhaseXesetI;
CString g_sLangID_Native_PhaseXesetII;
CString g_sLangTxt_Native_PhaseXesetII;
CString g_sLangID_Native_PhaseXesetIII;
CString g_sLangTxt_Native_PhaseXesetIII;
CString g_sLangID_Native_PhaseXesetIV;
CString g_sLangTxt_Native_PhaseXesetIV;
CString g_sLangID_Native_PhaseXesetV;
CString g_sLangTxt_Native_PhaseXesetV;

// 确认
CString g_sLangID_Native_Confm;
CString g_sLangTxt_Native_Confm;
CString g_sLangID_Native_OutTime;	   // = _T("Native_OutTime")
CString g_sLangTxt_Native_OutTime;	   // = _T("输出时间")
CString g_sLangID_Native_OutHoldTime;  // = _T("Native_OutHoldTime")
CString g_sLangTxt_Native_OutHoldTime; // = _T("开出量保持时间")
CString g_sLangID_Native_NetID;		   // = _T("Native_NetID")
CString g_sLangTxt_Native_NetID;	   // = _T("网络标识   0x")
CString g_sLangID_Native_CurSetActValue;
CString g_sLangTxt_Native_CurSetActValue; // 电流整定动作值
CString g_sLangID_Native_networkId;
CString g_sLangTxt_Native_networkId; // 网络标识
// 常态时间
CString g_sLangID_Native_NormTime;
CString g_sLangTxt_Native_NormTime;
CString g_sLangID_Native_DelayDev;	// = _T("Native_DelayDev")
CString g_sLangTxt_Native_DelayDev; // = _T("延时偏差")
CString g_sLangID_Native_oneToMany;
CString g_sLangTxt_Native_oneToMany; // 一个控制块对应多个线条
// 动作时间定值
CString g_sLangID_Native_OpTimeSet;
CString g_sLangTxt_Native_OpTimeSet;
CString g_sLangID_Native_DelayTime;		   //=_T("Native_DelayTime");
CString g_sLangTxt_Native_DelayTime;	   //=_T("延时时间");
CString g_sLangID_Native_OrigMsgSet;	   // = _T("Native_OrigMsgSet")
CString g_sLangTxt_Native_OrigMsgSet;	   // = _T("原始报文设置")
CString g_sLangID_Native_OutputHoldTimeS;  // = _T("Native_OutputHoldTimeS")
CString g_sLangTxt_Native_OutputHoldTimeS; // = _T("开出保持时间")
CString g_sLangID_Native_DelayVar;		   // = _T("Native_DelayVar")
CString g_sLangTxt_Native_DelayVar;		   // = _T("延时变化")
CString g_sLangID_Native_outputTimeLimit;
CString g_sLangTxt_Native_outputTimeLimit; // 输出限时(s)
/*"过负荷电流通道"*/
CString g_sLangID_Native_OverloadCurrChannel;
CString g_sLangTxt_Native_OverloadCurrChannel;
CString g_sLangID_Native_delegate;
CString g_sLangTxt_Native_delegate; // 委托
CString g_sLangID_Native_phaseDifference;
CString g_sLangTxt_Native_phaseDifference; // 相别
CString g_sLangID_Native_PreFaultTime;
CString g_sLangTxt_Native_PreFaultTime; // 故障前时间(s)
CString g_sLangID_Native_DestMAC;		// = _T("Native_DestMAC")
CString g_sLangTxt_Native_DestMAC;		// = _T("目的MAC")
/*_T("定值整定方式")*/
CString g_sLangID_Native_DevSetMethod;
CString g_sLangTxt_Native_DevSetMethod;
CString g_sLangID_Native_DevTime;  // = _T("Native_DevTime")
CString g_sLangTxt_Native_DevTime; // = _T("偏差时间")
CString g_sLangID_Native_DevVal;   // = _T("Native_DevVal")
CString g_sLangTxt_Native_DevVal;  // = _T("偏差值")
/*"差动速断"*/
CString g_sLangID_Native_DiffSpdBrk;
CString g_sLangTxt_Native_DiffSpdBrk;
// 保护动作后持续时间
CString g_sLangID_Native_DurProtTrip;
CString g_sLangTxt_Native_DurProtTrip;
CString g_sLangID_Native_error;
CString g_sLangTxt_Native_error;	  // 错误
CString g_sLangID_Native_ErrSeqTest;  // = _T("Native_ErrSeqTest")
CString g_sLangTxt_Native_ErrSeqTest; // = _T("错序测试")
CString g_sLangID_Native_Fault;		  // = _T("Native_Fault")
CString g_sLangTxt_Native_Fault;	  // = _T("故障")
// 故障通道
CString g_sLangID_Native_FaultChnl;
CString g_sLangTxt_Native_FaultChnl;
/*故障电流*/
CString g_sLangID_Native_FaultCurrValue;
CString g_sLangTxt_Native_FaultCurrValue;
// 故障触发方式
CString g_sLangID_Native_FaultTrigMethod;
CString g_sLangTxt_Native_FaultTrigMethod;
// 故障电压定义
CString g_sLangID_Native_FaultVoltDef;
CString g_sLangTxt_Native_FaultVoltDef;
// 文件名称
CString g_sLangID_Native_FileName;
CString g_sLangTxt_Native_FileName;
CString g_sLangID_Native_FlipMoment;  // = _T("Native_FlipMoment")
CString g_sLangTxt_Native_FlipMoment; // = _T("翻转时刻")
CString g_sLangID_Native_FrameDrop;	  // = _T("Native_FrameDrop")
CString g_sLangTxt_Native_FrameDrop;  // = _T("丢帧测试")
CString g_sLangID_Native_FlyDot;	  // = _T("Native_FlyDot")
CString g_sLangTxt_Native_FlyDot;	  // = _T("飞点测试")
CString g_sLangID_Native_FreqSetActValue;
CString g_sLangTxt_Native_FreqSetActValue; // 频率整定动作值
CString g_sLangID_Native_fundamentalFreq;
CString g_sLangTxt_Native_fundamentalFreq; // 基波频率
CString g_sLangID_Native_fundamentalAmp;
CString g_sLangTxt_Native_fundamentalAmp; // 基波幅值
CString g_sLangID_Native_fundamentalPhase;
CString g_sLangTxt_Native_fundamentalPhase; // 基波相位
CString g_sLangID_Native_GOOSEOrigMsg;
CString g_sLangTxt_Native_GOOSEOrigMsg; // GOOSE原始报文
CString g_sLangID_Native_gooseReceive;
CString g_sLangTxt_Native_gooseReceive;		// GOOSE 接收
CString g_sLangID_Native_GPSTriggerHour;	// = _T("Native_GPSTrHour")
CString g_sLangTxt_Native_GPSTriggerHour;	// = _T("GPS触发时刻（时）")
CString g_sLangID_Native_GPSTriggerMinute;	// = _T("Native_GPSTrMinute")
CString g_sLangTxt_Native_GPSTriggerMinute; // = _T("GPS触发时刻（分）")
CString g_sLangID_Native_GPSTriggerSecond;	// = _T("Native_GPSTrSecond")
CString g_sLangTxt_Native_GPSTriggerSecond; // = _T("GPS触发时刻（秒）")
CString g_sLangID_Native_GradualTimeScale;	// = _T("Native_GradTimeScale")
CString g_sLangTxt_Native_GradualTimeScale; // = _T("递变时间分度(ms)")
CString g_sLangID_Native_GroundDisSetI;
CString g_sLangTxt_Native_GroundDisSetI;
CString g_sLangID_Native_GroundDisSetII;
CString g_sLangTxt_Native_GroundDisSetII;
CString g_sLangID_Native_GroundDisSetIII;
CString g_sLangTxt_Native_GroundDisSetIII;
CString g_sLangID_Native_GroundDisSetIV;
CString g_sLangTxt_Native_GroundDisSetIV;

/*tr("故障时间(S)")*/
CString g_sLangID_Native_PreFautTime;
CString g_sLangTxt_Native_PreFautTime;
/*"项目名称"*/
CString g_sLangID_Native_ProjName;
CString g_sLangTxt_Native_ProjName;
// 品质异常
CString g_sLangID_Native_QltyExcp;
CString g_sLangTxt_Native_QltyExcp;
CString g_sLangID_Native_quote;
CString g_sLangTxt_Native_quote; // 引用
CString g_sLangID_Native_RatioBrakeCoefficient;
CString g_sLangTxt_Native_RatioBrakeCoefficient; // 比率制动系数
CString g_sLangID_Native_receive;
CString g_sLangTxt_Native_receive; // 接收
// 返回时间
CString g_sLangID_Native_ReturnTime;
CString g_sLangTxt_Native_ReturnTime;
// 返回值
CString g_sLangID_Native_ReturnValue;
CString g_sLangTxt_Native_ReturnValue;
// 采样延时
CString g_sLangID_Native_SampDelay;
CString g_sLangTxt_Native_SampDelay;
// 采样率
CString g_sLangID_Native_SamplingFrequency;
CString g_sLangTxt_Native_SamplingFrequency;
CString g_sLangID_Native_saveFailed;
CString g_sLangTxt_Native_saveFailed; // 保存失败！\n
// 序号偏差
CString g_sLangID_Native_SeqDev;
CString g_sLangTxt_Native_SeqDev;
CString g_sLangID_Native_SetActVolt;
CString g_sLangTxt_Native_SetActVolt;
// 整定动作电流
CString g_sLangID_Native_SetPickCurr;
CString g_sLangTxt_Native_SetPickCurr;
// 变位次数
CString g_sLangID_Native_ShiftCount;
CString g_sLangTxt_Native_ShiftCount;
// 短路电压
CString g_sLangID_Native_ShortCircuitV;
CString g_sLangTxt_Native_ShortCircuitV;
// 短路阻抗角
CString g_sLangID_Native_ShortZImpAng;
CString g_sLangTxt_Native_ShortZImpAng;
/*短路阻抗*/
CString g_sLangID_Native_ShortZImp;
CString g_sLangTxt_Native_ShortZImp;
CString g_sLangID_Native_smvReceive;
CString g_sLangTxt_Native_smvReceive; // SMV 接收
// 发送周波数
CString g_sLangID_Native_SndFreq;
CString g_sLangTxt_Native_SndFreq;
// 每秒发送周波数
CString g_sLangID_Native_SndFreqPS;
CString g_sLangTxt_Native_SndFreqPS;
// 发送时间(s)
CString g_sLangID_Native_SndTimeS;
CString g_sLangTxt_Native_SndTimeS;
// 源MAC
CString g_sLangID_Native_SrcMAC;
CString g_sLangTxt_Native_SrcMAC;
// 状态%d
CString g_sLangID_Native_StateD;
CString g_sLangTxt_Native_StateD;
CString g_sLangID_Native_subscriptionDescription;
CString g_sLangTxt_Native_subscriptionDescription; // 订阅描述
CString g_sLangID_Native_subscriptionIndex;
CString g_sLangTxt_Native_subscriptionIndex; // 订阅索引
CString g_sLangID_Native_subscriptionReference;
CString g_sLangTxt_Native_subscriptionReference; // 订阅引用
CString g_sLangID_Native_superimpose_ornot;
CString g_sLangTxt_Native_superimpose_ornot; // 是否叠加非周期分量:
// SV原始报文
CString g_sLangID_Native_SVOrigMsg;
CString g_sLangTxt_Native_SVOrigMsg;
// 开关量
CString g_sLangID_Native_SwitchVal;
CString g_sLangTxt_Native_SwitchVal;
CString g_sLangID_Native_test_process;
CString g_sLangTxt_Native_test_process; // 试验过程:
// 测试精度
CString g_sLangID_Native_TestPrecision;
CString g_sLangTxt_Native_TestPrecision;
// 变压器接线形式
CString g_sLangID_Native_TransConnForm;
CString g_sLangTxt_Native_TransConnForm;
// 是否转换性故障
CString g_sLangID_Native_TransientFault;
CString g_sLangTxt_Native_TransientFault;
// 触发后保持时间
CString g_sLangID_Native_TrigHoldTime;
CString g_sLangTxt_Native_TrigHoldTime;
// 触发方式
CString g_sLangID_Native_TrigMode;
CString g_sLangTxt_Native_TrigMode;
// 有效[bit0-1]
CString g_sLangID_Native_ValidBit;
CString g_sLangTxt_Native_ValidBit;
CString g_sLangID_Native_VolSetActValue;
CString g_sLangTxt_Native_VolSetActValue; // 电压整定动作值
CString g_sLangID_Native_vTerminalConnectDia;
CString g_sLangTxt_Native_vTerminalConnectDia; // 虚端子连接图
CString g_sLangID_Native_YNInputStop;
CString g_sLangTxt_Native_YNInputStop; // 是否开入停止
CString g_sLangID_Out1_Situation;
CString g_sLangTxt_Out1_Situation; // 开出1状态
CString g_sLangID_Out2_Situation;
CString g_sLangTxt_Out2_Situation; // 开出2状态
CString g_sLangID_Out3_Situation;
CString g_sLangTxt_Out3_Situation; // 开出3状态
CString g_sLangID_without;
CString g_sLangTxt_without; // 无
// 电压滑差
CString g_sLangID_Native_VoltSlip;
CString g_sLangTxt_Native_VoltSlip;
CString g_sLangID_Native_ShortCircuitVs;  // = _T("Native_ShortCircuitVs")
CString g_sLangTxt_Native_ShortCircuitVs; // = _T("短路电压(V):")

// 电压变化终值
CString g_sLangID_Native_FinalVoltChange;
CString g_sLangTxt_Native_FinalVoltChange;
CString g_sLangID_Allow_FreqDifference;
CString g_sLangTxt_Allow_FreqDifference;
CString g_sLangID_LeadingAngle;
CString g_sLangTxt_LeadingAngle;
CString g_sLangID_LeadingTime;
CString g_sLangTxt_LeadingTime;
CString g_sLangID_Allow_VolDifference;
CString g_sLangTxt_Allow_VolDifference;
CString g_sLangID_Vol_ReguPeriod;
CString g_sLangTxt_Vol_ReguPeriod;
CString g_sLangID_Freq_ReguPeriod;
CString g_sLangTxt_Freq_ReguPeriod;

CString g_sLangID_System_Rated_Voltage;
CString g_sLangTxt_System_Rated_Voltage;
CString g_sLangID_System_Rated_Frequency;
CString g_sLangTxt_System_Rated_Frequency;
CString g_sLangID_Grid_Rated_Voltage;
CString g_sLangTxt_Grid_Rated_Voltage;

CString g_sLangID_Freq_BoundValue;
CString g_sLangTxt_Freq_BoundValue; // 频率边界值
CString g_sLangID_FreqDif;
CString g_sLangTxt_FreqDif; // 频差

// 电压变化始值
CString g_sLangID_Native_InitVoltChange;
CString g_sLangTxt_Native_InitVoltChange;
CString g_sLangID_Grid_FreqHZ;
CString g_sLangTxt_Grid_FreqHZ;
/*_T("低压闭锁值")*/
CString g_sLangID_Native_LowVLockVal;
CString g_sLangTxt_Native_LowVLockVal;

// 低压减载动作值
CString g_sLangID_Native_LowVoltUnderloadTripSet;
CString g_sLangTxt_Native_LowVoltUnderloadTripSet;

CString g_sLangID_Native_maxSyncTime;
CString g_sLangTxt_Native_maxSyncTime; // 最大同步时间：

CString g_sLangID_Out4_Mode;
CString g_sLangTxt_Out4_Mode; // 开出4输出方式
// 电压变化步长
CString g_sLangID_Native_VoltChangeStep;
CString g_sLangTxt_Native_VoltChangeStep;
CString g_sLangID_Vol_BoundValue;
CString g_sLangTxt_Vol_BoundValue; // 电压边界值

/*QString::tr("电压滑差动作值")*/
CString g_sLangID_Native_VoltSlipAct;
CString g_sLangTxt_Native_VoltSlipAct;
/*_T("闭锁电压定义")*/
CString g_sLangID_Native_LockVoltDef;
CString g_sLangTxt_Native_LockVoltDef;
/*_T("低压变化率闭锁值")*/
CString g_sLangID_Native_LowVRateLock;
CString g_sLangTxt_Native_LowVRateLock;
/*QString::tr("低压减载动作值")*/
CString g_sLangID_Native_LVLRActionVal;
CString g_sLangTxt_Native_LVLRActionVal;
CString g_sLangID_VolDif;
CString g_sLangTxt_VolDif; // 压差
CString g_sLangID_Native_FaultProp;					 // = _T("Native_FaultProp")
CString g_sLangTxt_Native_FaultProp;				 // = _T("故障性质:")
CString g_sLangID_Native_ControlCurrent;			 // = _T("Native_ControlCurrent")
CString g_sLangTxt_Native_ControlCurrent;			 // = _T("制动电流")
/*tr("测试绕组之间角差(钟点数)")*/
CString g_sLangID_Native_AngleDiffClockHrsTestWindings;
CString g_sLangTxt_Native_AngleDiffClockHrsTestWindings;

/*_T("启动段斜率")*/
CString g_sLangID_Native_StartSegSlope;
CString g_sLangTxt_Native_StartSegSlope;
/*_T("基波比率制动特性斜率1")*/
CString g_sLangID_Native_FundRatioBrkSlope1;
CString g_sLangTxt_Native_FundRatioBrkSlope1;
/*_T("基波比率制动特性斜率2")*/
CString g_sLangID_Native_FundRatioBrkSlope2;
CString g_sLangTxt_Native_FundRatioBrkSlope2;
/*_T("基波比率制动特性斜率3")*/
CString g_sLangID_Native_FundRatioBrkSlope3;
CString g_sLangTxt_Native_FundRatioBrkSlope3;
/*_T("二次谐波制动系数")*/
CString g_sLangID_Native_SecHarBrkCoef;
CString g_sLangTxt_Native_SecHarBrkCoef;
/*_T("三次谐波制动系数")*/
CString g_sLangID_Native_ThiHarBrkCoef;
CString g_sLangTxt_Native_ThiHarBrkCoef;
/*_T("五次谐波制动系数")*/
CString g_sLangID_Native_FivHarBrkCoef;
CString g_sLangTxt_Native_FivHarBrkCoef;
/*tr("高压侧额定电压(kV)")*/
CString g_sLangID_Native_HighVoltSideRatedVolt;
CString g_sLangTxt_Native_HighVoltSideRatedVolt;
/*tr("中压侧额定电压(kV)")*/
CString g_sLangID_Native_MedVoltSideRatedVolt;
CString g_sLangTxt_Native_MedVoltSideRatedVolt;
CString g_sLangID_Native_SearchMeth;			// = _T("Native_SearchMeth")
CString g_sLangTxt_Native_SearchMeth;			// = _T("搜索方法")
/*tr("中压侧绕组接线型式")*/
CString g_sLangID_Native_MedVoltWindingConnType;
CString g_sLangTxt_Native_MedVoltWindingConnType;
/*tr("低压侧额定电压(kV)")*/
CString g_sLangID_Native_LowVoltSideRatedVolt;
CString g_sLangTxt_Native_LowVoltSideRatedVolt;
/*"高压侧CT一次值(A)"*/
CString g_sLangID_Native_HVSideCTPrimVal;
CString g_sLangTxt_Native_HVSideCTPrimVal;
/*"高压侧CT二次值(A)"*/
CString g_sLangID_Native_HVSide2CTPrimVal;
CString g_sLangTxt_Native_HVSide2CTPrimVal;

/*"中压侧CT一次值(A)"*/
CString g_sLangID_Native_MVSideCTPrimVal;
CString g_sLangTxt_Native_MVSideCTPrimVal;
/*"中压侧CT二次值(A)"*/
CString g_sLangID_Native_MVSide2CTPrimVal;
CString g_sLangTxt_Native_MVSide2CTPrimVal;
/*"低压侧CT一次值(A)"*/
CString g_sLangID_Native_LVSideCTPrimVal;
CString g_sLangTxt_Native_LVSideCTPrimVal;
/*"低压侧CT二次值(A)"*/
CString g_sLangID_Native_LVSide2CTPrimVal;
CString g_sLangTxt_Native_LVSide2CTPrimVal;
CString g_sLangID_Native_ProportionalBrakingFactor;	 // = _T("Native_ProportionalBrakingFactor")
CString g_sLangTxt_Native_ProportionalBrakingFactor; // = _T("比例制动系数")
/*_T("基准电流选择")*/
CString g_sLangID_Native_RefCurrentSel;
CString g_sLangTxt_Native_RefCurrentSel;
/*tr("变压器额定容量(MVA)")*/
CString g_sLangID_Native_TransfRatedCapacity;
CString g_sLangTxt_Native_TransfRatedCapacity;
CString g_sLangID_interlock_vol;
CString g_sLangTxt_interlock_vol; // 闭锁电压
CString g_sLangID_interlock_cur;
CString g_sLangTxt_interlock_cur; // 闭锁电流
CString g_sLangID_lowfreqloadre_ActTime;
CString g_sLangTxt_lowfreqloadre_ActTime; // 低周减载动作时间

CString g_sLangID_Native_sliptripValue;
CString g_sLangTxt_Native_sliptripValue; // 滑差闭锁值
// 电压变化量
CString g_sLangID_Native_VoltChangeAmt;
CString g_sLangTxt_Native_VoltChangeAmt;

// 加速信号接点
CString g_sLangID_Native_AccelSignalCont;
CString g_sLangTxt_Native_AccelSignalCont;
// 减速信号接点
CString g_sLangID_Native_DecelSignalCont;
CString g_sLangTxt_Native_DecelSignalCont;
// 振荡前时间
CString g_sLangID_Native_PreOscTime;
CString g_sLangTxt_Native_PreOscTime;
// 系统侧阻抗
CString g_sLangID_Native_SysImp;
CString g_sLangTxt_Native_SysImp;
// 变压器阻抗
CString g_sLangID_Native_TransImp;
CString g_sLangTxt_Native_TransImp;

/*_T("振荡次数")*/
CString g_sLangID_Native_OscilCount;
CString g_sLangTxt_Native_OscilCount;

// 角度定义
CString g_sLangID_Native_AngDef;
CString g_sLangTxt_Native_AngDef;
// 接线方式
CString g_sLangID_Native_ConnMethod;
CString g_sLangTxt_Native_ConnMethod;
CString g_sLangID_Native_ActDirection;		 //=_T("Native_ActDirection");
CString g_sLangTxt_Native_ActDirection;		 //=_T("动作方向");
CString g_sLangID_Native_LowVoltageDef;		 //=_T("Native_LowVoltageDef");
CString g_sLangTxt_Native_LowVoltageDef;	 //=_T("低电压定义");
/*_T("超前角度")*/
CString g_sLangID_Native_LeadAngle;
CString g_sLangTxt_Native_LeadAngle;
/*_T("滞后角度")*/
CString g_sLangID_Native_LagAngle;
CString g_sLangTxt_Native_LagAngle;
// 计算系数
CString g_sLangID_Native_CalcCoef;
CString g_sLangTxt_Native_CalcCoef;
/*_T("工频变化量阻抗定值")*/
CString g_sLangID_Native_FreqChgZSetting;
CString g_sLangTxt_Native_FreqChgZSetting;
/*_T("正序灵敏角")*/
CString g_sLangID_Native_PosSeqSensAng;
CString g_sLangTxt_Native_PosSeqSensAng;
/*_T("接地距离偏移角")*/
CString g_sLangID_Native_GndDistOffset;
CString g_sLangTxt_Native_GndDistOffset;
/*_T("相间距离偏移角")*/
CString g_sLangID_Native_PhaseDistOffset;
CString g_sLangTxt_Native_PhaseDistOffset;
/*QObject::tr("2次谐波制动系数")*/
CString g_sLangID_Native_2HarBrkCoef;
CString g_sLangTxt_Native_2HarBrkCoef;
/*QObject::tr("3次谐波制动系数")*/
CString g_sLangID_Native_3HarBrkCoef;
CString g_sLangTxt_Native_3HarBrkCoef;
/*QObject::tr("5次谐波制动系数")*/
CString g_sLangID_Native_5HarBrkCoef;
CString g_sLangTxt_Native_5HarBrkCoef;
CString g_sLangID_Native_BalCoeff;				// = _T("Native_BalCoeff")
CString g_sLangTxt_Native_BalCoeff;				// = _T("平衡系数")

CString g_sLangID_Native_ConnectFail;        // = _T("Native_ConnectFail")
CString g_sLangTxt_Native_ConnectFail;       // = _T("与当前测试仪建立连接失败(%s).")

CString g_sLangID_Native_TestrDisconn;				  // = _T("Native_TestrDisconn")
CString g_sLangTxt_Native_TestrDisconn;				  // = _T("测试仪连接中断，请先与测试仪建立连接。")

CString g_sLangID_Native_UnBatteryInfor;				  // = _T("Native_UnBatteryInfor")
CString g_sLangTxt_Native_UnBatteryInfor;				  // = _T("电池电量信息获取异常.")

CString g_sLangID_Native_LoadingMacroTest;
CString g_sLangTxt_Native_LoadingMacroTest;
CString g_sLangID_Native_LoadingBar;
CString g_sLangTxt_Native_LoadingBar;

CString g_sLangID_remotemeas;
CString g_sLangTxt_remotemeas;
CString g_sLangID_Internal;
CString g_sLangTxt_Internal;
CString g_sLangID_Operation;
CString g_sLangTxt_Operation;
CString g_sLangID_Record;
CString g_sLangTxt_Record;
CString g_sLangID_EventType;
CString g_sLangTxt_EventType;
CString g_sLangID_DeviceTime;
CString g_sLangTxt_DeviceTime;
CString g_sLangID_PCTime;
CString g_sLangTxt_PCTime;
CString g_sLangID_Native_TempSaveSucc;
CString g_sLangTxt_Native_TempSaveSucc;
CString g_sLangID_Native_TempSaveFail;
CString g_sLangTxt_Native_TempSaveFail;
CString g_sLangID_Native_Success;
CString g_sLangTxt_Native_Success;
CString g_sLangID_Native_Timeout;
CString g_sLangTxt_Native_Timeout;
CString g_sLangID_Native_Fail;
CString g_sLangTxt_Native_Fail;
CString g_sLangID_Native_TempSave;
CString g_sLangTxt_Native_TempSave;
CString g_sLangID_Native_ExportWordReport;
CString g_sLangTxt_Native_ExportWordReport;
CString g_sLangID_Native_ReportSave;
CString g_sLangTxt_Native_ReportSave;

CString g_sLangID_Impedance_CalMode;			 //=_T("Impedance_CalMode");
CString g_sLangTxt_Impedance_CalMode;			 //=_T("测试模型:");
CString g_sLangID_Impedance_Choose;			 //=_T("Impedance_Choose");
CString g_sLangTxt_Impedance_Choose;			 //=_T("阻抗输入选择:");
CString g_sLangID_Impedance_ShortCurr;			 //=_T("Impedance_ShortCurr");
CString g_sLangTxt_Impedance_ShortCurr;			 //=_T("短路电流(A)");
CString g_sLangID_Impedance_Delayed;			 //=_T("Impedance_Delayed");
CString g_sLangTxt_Impedance_Delayed;			 //=_T("触发后延时(s)");
CString g_sLangID_Impedance_VarChoose;			 //=_T("Impedance_VarChoose");
CString g_sLangTxt_Impedance_VarChoose;			 //=_T("变量选择");
CString g_sLangID_Impedance_Mode;			 //=_T("Impedance_Mode");
CString g_sLangTxt_Impedance_Mode;			 //=_T("模式");
CString g_sLangID_Impedance_Time;			 //=_T("Impedance_Time");
CString g_sLangTxt_Impedance_Time;			 //=_T("变化时间");
CString g_sLangID_Impedance_ChangeType;			 //=_T("Impedance_ChangeType");
CString g_sLangTxt_Impedance_ChangeType;			 //=_T("变化方式");
CString g_sLangID_Impedance_Auto;			 //=_T("Impedance_Auto");
CString g_sLangTxt_Impedance_Auto;			 //=_T("自动递变");
CString g_sLangID_Impedance_Mutation;			 //=_T("Impedance_Mutation");
CString g_sLangTxt_Impedance_Mutation;			 //=_T("突变量启动");
 CString g_sLangID_ExpSucc;                          //sun
 CString g_sLangTxt_ExpSucc;                         //sun
 CString g_sLangID_ExpFail;                          //sun
 CString g_sLangTxt_ExpFail;                         //sun
 CString g_sLangID_ImpSucc;                          //sun
 CString g_sLangTxt_ImpSucc;                         //sun
 CString g_sLangID_ImpFail;                          //sun
 CString g_sLangTxt_ImpFail;                         //sun
 CString g_sLangID_RemainingMemorySize;              //sun
 CString g_sLangTxt_RemainingMemorySize;             //sun
 CString g_sLangID_InsufficientSystemMemory;         //sun
 CString g_sLangTxt_InsufficientSystemMemory;        //sun
 CString g_sLangID_ExistenceSCDFiles;                //sun
 CString g_sLangTxt_ExistenceSCDFiles;               //sun
 CString g_sLangID_NoExistenceSCLFiles;              //sun
 CString g_sLangTxt_NoExistenceSCLFiles;             //sun
 CString g_sLangID_AnalysisSCLFiles;                 //sun
 CString g_sLangTxt_AnalysisSCLFiles;                //sun
 CString g_sLangID_LoadSCLFiles;                     //sun
 CString g_sLangTxt_LoadSCLFiles;                    //sun
 CString g_sLangID_LoadSCLFilesProgressBar;          //sun
 CString g_sLangTxt_LoadSCLFilesProgressBar;         //sun
 CString g_sLangID_SaveSCLFiles;                     //sun
 CString g_sLangTxt_SaveSCLFiles;                    //sun

CString g_sLangID_Impedance_FunParas;			 //=_T("Impedance_FunParas");
CString g_sLangTxt_Impedance_FunParas;			 //=_T("功能参数");
CString g_sLangID_Impedance_Variable;			 //=_T("Impedance_Variable");
CString g_sLangTxt_Impedance_Variable;			 //=_T("递变");
CString g_sLangID_Impedance_ChangeStart;			 //=_T("Impedance_ChangeStart");
CString g_sLangTxt_Impedance_ChangeStart;			 //=_T("变化始值(Ω)");
CString g_sLangID_Impedance_ChangeEnd;			 //=_T("Impedance_ChangeEnd");
CString g_sLangTxt_Impedance_ChangeEnd;			 //=_T("变化终值(Ω)");
CString g_sLangID_Impedance_ChangStep;			 //=_T("Impedance_ChangStep");
CString g_sLangTxt_Impedance_ChangStep;			 //=_T("变化步长(Ω)");
CString g_sLangID_Impedance_NormalTime;			 //=_T("Impedance_NormalTime");
CString g_sLangTxt_Impedance_NormalTime;			 //=_T("常态时间(s)");
CString g_sLangID_Impedance_FailTime;			 //=_T("Impedance_FailTime");
CString g_sLangTxt_Impedance_FailTime;			 //=_T("故障前时间(s)");
CString g_sLangID_Impedance_ConstantCur;			 //=_T("Impedance_ConstantCur");
CString g_sLangTxt_Impedance_ConstantCur;			 //=_T("定电流");
CString g_sLangID_Impedance_ConstantVol;			 //=_T("Impedance_ConstantVol");
CString g_sLangTxt_Impedance_ConstantVol;			 //=_T("定电压");
CString g_sLangID_Impedance_FixedSystem;			 //=_T("Impedance_FixedSystem");
CString g_sLangTxt_Impedance_FixedSystem;			 //=_T("固定系统侧阻抗");

CString g_sLangID_Gradient_FailModes;			 //=_T("Gradient_FailModes");
CString g_sLangTxt_Gradient_FailModes;			 //=_T("故障模式");
CString g_sLangID_Gradient_Change;			 //=_T("Gradient_Change");
CString g_sLangTxt_Gradient_Change;			 //=_T("变化量");
CString g_sLangID_Gradient_ImpAngle;			 //=_T("Gradient_ImpAngle");
CString g_sLangTxt_Gradient_ImpAngle;			 //=_T("阻抗角(°):");
CString g_sLangID_Gradient_ChangeTime;			 //=_T("Gradient_ChangeTime");
CString g_sLangTxt_Gradient_ChangeTime;			 //=_T("变化前时间(s):");
CString g_sLangID_Gradient_FailBeforeTime;			 //=_T("Gradient_FailBeforeTime");
CString g_sLangTxt_Gradient_FailBeforeTime;			 //=_T("故障前时间(s):");
CString g_sLangID_Gradient_FailVol;			 //=_T("Gradient_FailVol");
CString g_sLangTxt_Gradient_FailVol;			 //=_T("故障前电压(V):");
CString g_sLangID_Gradient_FailCur;			 //=_T("Gradient_FailCur");
CString g_sLangTxt_Gradient_FailCur;			 //=_T("故障前电流(A):");
CString g_sLangID_Gradient_FailAngle;			 //=_T("Gradient_FailAngle");
CString g_sLangTxt_Gradient_FailAngle;			 //=_T("故障前相角(°):");
CString g_sLangID_Gradient_RampParas;			 //=_T("Gradient_RampParas");
CString g_sLangTxt_Gradient_RampParas;			 //=_T("递变参数设置");
//CString g_sLangID_Gradient_VarSet;			 //=_T("Gradient_VarSet");
//CString g_sLangTxt_Gradient_VarSet;			 //=_T("变量设置");
CString g_sLangID_Gradient_CommonParas;			 //=_T("Gradient_CommonParas");
CString g_sLangTxt_Gradient_CommonParas;			 //=_T("通用参数");
CString g_sLangID_Gradient_BinBout;			 //=_T("Gradient_BinBout");
CString g_sLangTxt_Gradient_BinBout;			 //=_T("开入量");
CString g_sLangID_Gradient_BoutNormal;			 //=_T("Gradient_BoutNormal");
CString g_sLangTxt_Gradient_BoutNormal;			 //=_T("开出量正常态");
CString g_sLangID_Gradient_BoutFaultState;			 //=_T("Gradient_BoutFaultState");
CString g_sLangTxt_Gradient_BoutFaultState;			 //=_T("开出量故障态");
CString g_sLangID_Gradient_Test1;			 //=_T("Gradient_Test1");
CString g_sLangTxt_Gradient_Test1;			 //=_T("测试1");
CString g_sLangID_Gradient_Test2;			 //=_T("Gradient_Test2");
CString g_sLangTxt_Gradient_Test2;			 //=_T("测试2");
CString g_sLangID_Gradient_Test3;			 //=_T("Gradient_Test3");
CString g_sLangTxt_Gradient_Test3;			 //=_T("测试3");

CString g_sLangID_Native_PhaseABshort;			 //=_T("Native_PhaseABshort");
CString g_sLangTxt_Native_PhaseABshort;			 //=_T("AB相短路");
CString g_sLangID_Native_PhaseBCshort;			 //=_T("Native_PhaseBCshort");
CString g_sLangTxt_Native_PhaseBCshort;			 //=_T("BC相短路");
CString g_sLangID_Native_PhaseCAshort;			 //=_T("Native_PhaseCAshort");
CString g_sLangTxt_Native_PhaseCAshort;			 //=_T("CA相短路");
CString g_sLangID_Native_PhaseABshortCcur;			 //=_T("Native_PhaseABshortCcur");
CString g_sLangTxt_Native_PhaseABshortCcur;			 //=_T("AB相短路，C相电流");
CString g_sLangID_Native_PhaseBCshortAcur;			 //=_T("Native_PhaseBCshortAcur");
CString g_sLangTxt_Native_PhaseBCshortAcur;			 //=_T("BC相短路，A相电流");
CString g_sLangID_Native_PhaseCAshortBcur;			 //=_T("Native_PhaseCAshortBcur");
CString g_sLangTxt_Native_PhaseCAshortBcur;			 //=_T("CA相短路，B相电流");
CString g_sLangID_Native_PhaseABshortBcur;			 //=_T("Native_PhaseABshortBcur");
CString g_sLangTxt_Native_PhaseABshortBcur;			 //=_T("AB相短路，B相电流");
CString g_sLangID_Native_PhaseBCshortCcur;			 //=_T("Native_PhaseBCshortCcur");
CString g_sLangTxt_Native_PhaseBCshortCcur;			 //=_T("BC相短路，C相电流");
CString g_sLangID_Native_PhaseCAshortAcur;			 //=_T("Native_PhaseCAshortAcur");
CString g_sLangTxt_Native_PhaseCAshortAcur;			 //=_T("CA相短路，A相电流");
CString g_sLangID_Native_PosVol;			 //=_T("Native_PosVol");
CString g_sLangTxt_Native_PosVol;			 //=_T("正序电压");
CString g_sLangID_Native_NegVol;			 //=_T("Native_NegVol");
CString g_sLangTxt_Native_NegVol;			 //=_T("负序电压");
CString g_sLangID_Native_ZeroVol3U0;			 //=_T("Native_ZeroVol3U0");
CString g_sLangTxt_Native_ZeroVol3U0;			 //=_T("零序电压（3U0）");
CString g_sLangID_Native_PosVolU1;			 //=_T("Native_PosVolU1");
CString g_sLangTxt_Native_PosVolU1;			 //=_T("正序(U1)");
CString g_sLangID_Native_NegVolU2;			 //=_T("Native_NegVolU2");
CString g_sLangTxt_Native_NegVolU2;			 //=_T("负序(U2)");
CString g_sLangID_Native_Zero3U0;			 //=_T("Native_Zero3U0");
CString g_sLangTxt_Native_Zero3U0;			 //=_T("零序(3U0)");

CString g_sLangID_CBOperate_TimeAfterTrigger;			 //=_T("CBOperate_TimeAfterTrigger");
CString g_sLangTxt_CBOperate_TimeAfterTrigger;			 //=_T("保护动作后持续时间(s)");
CString g_sLangID_CBOperate_PTVPos;			 //=_T("CBOperate_PTVPos");
CString g_sLangTxt_CBOperate_PTVPos;			 //=_T("TV安装位置");
CString g_sLangID_CBOperate_CTPos;			 //=_T("CBOperate_CTPos");
CString g_sLangTxt_CBOperate_CTPos;			 //=_T("TA正极性");
CString g_sLangID_CBOperate_AfterOpenTime;			 //=_T("CBOperate_AfterOpenTime");
CString g_sLangTxt_CBOperate_AfterOpenTime;			 //=_T("开关跳开后持续时间(s)");
CString g_sLangID_CBOperate_RecloseTime;			 //=_T("CBOperate_RecloseTime");
CString g_sLangTxt_CBOperate_RecloseTime;			 //=_T("重合持续时间(s)");
CString g_sLangID_CBOperate_AfterAccTime;			 //=_T("CBOperate_AfterAccTime");
CString g_sLangTxt_CBOperate_AfterAccTime;			 //=_T("后加速开关跳开后持续时间(s)");
CString g_sLangID_CBOperate_PTPos;			 //=_T("CBOperate_PTPos");
CString g_sLangTxt_CBOperate_PTPos;			 //=_T("母线侧");
CString g_sLangID_CBOperate_TPos;			 //=_T("CBOperate_TPos");
CString g_sLangTxt_CBOperate_TPos;			 //=_T("线路侧");
CString g_sLangID_CBOperate_CTPos1;			 //=_T("CBOperate_CTPos1");
CString g_sLangTxt_CBOperate_CTPos1;			 //=_T("指向母线");
CString g_sLangID_CBOperate_TPos1;			 //=_T("CBOperate_TPos1");
CString g_sLangTxt_CBOperate_TPos1;			 //=_T("指向线路");
CString g_sLangID_CBOperate_Overall;			 //=_T("CBOperate_Overall");
CString g_sLangTxt_CBOperate_Overall;			 //=_T("综重");
CString g_sLangID_CBOperate_Zs;			 //=_T("CBOperate_Zs");
CString g_sLangTxt_CBOperate_Zs;			 //=_T("系统阻抗(Ω)");
CString g_sLangID_CBOperate_ZsPh;			 //=_T("CBOperate_ZsPh");
CString g_sLangTxt_CBOperate_ZsPh;			 //=_T("系统阻抗角(°)");
CString g_sLangID_CBOperate_SimulateBreakerDelay;			 //=_T("CBOperate_SimulateBreakerDelay");
CString g_sLangTxt_CBOperate_SimulateBreakerDelay;			 //=_T("断路器模拟");
CString g_sLangID_CBOperate_BrkBreakTime;			 //=_T("CBOperate_BrkBreakTime");
CString g_sLangTxt_CBOperate_BrkBreakTime;			 //=_T("分闸时间(ms)");
CString g_sLangID_CBOperate_BrkCloseTime;			 //=_T("CBOperate_BrkCloseTime");
CString g_sLangTxt_CBOperate_BrkCloseTime;			 //=_T("合闸时间(ms)");
CString g_sLangID_CBOperate_FaultIncMode;			 //=_T("CBOperate_FaultIncMode");
CString g_sLangTxt_CBOperate_FaultIncMode;			 //=_T("合闸角选择");
CString g_sLangID_CBOperate_FaultAngle;			 //=_T("CBOperate_FaultAngle");
CString g_sLangTxt_CBOperate_FaultAngle;			 //=_T("合闸角(°)");
CString g_sLangID_CBOperate_BIPlusDC;			 //=_T("CBOperate_BIPlusDC");
CString g_sLangTxt_CBOperate_BIPlusDC;			 //=_T("叠加非周期分量");
CString g_sLangID_CBOperate_VzDefine;			 //=_T("CBOperate_VzDefine");
CString g_sLangTxt_CBOperate_VzDefine;			 //=_T("抽取电压输出定义");
CString g_sLangID_CBOperate_PsuVzRefPhase;			 //=_T("CBOperate_PsuVzRefPhase");
CString g_sLangTxt_CBOperate_PsuVzRefPhase;			 //=_T("抽取电压参考相定义");
CString g_sLangID_CBOperate_VzPh;			 //=_T("CBOperate_VzPh");
CString g_sLangTxt_CBOperate_VzPh;			 //=_T("抽取电压相角");
CString g_sLangID_CBOperate_NotSimulated;			 //=_T("CBOperate_NotSimulated");
CString g_sLangTxt_CBOperate_NotSimulated;			 //=_T("不模拟");
CString g_sLangID_CBOperate_Random;			 //=_T("CBOperate_Random");
CString g_sLangTxt_CBOperate_Random;			 //=_T("随机");
CString g_sLangID_CBOperate_FixedValue;			 //=_T("CBOperate_FixedValue");
CString g_sLangTxt_CBOperate_FixedValue;			 //=_T("定值");
CString g_sLangID_CBOperate_UabPhase;			 //=_T("CBOperate_UabPhase");
CString g_sLangTxt_CBOperate_UabPhase;			 //=_T("Uab相位");
CString g_sLangID_CBOperate_UbcPhase;			 //=_T("CBOperate_UbcPhase");
CString g_sLangTxt_CBOperate_UbcPhase;			 //=_T("Ubc相位");
CString g_sLangID_CBOperate_UcaPhase;			 //=_T("CBOperate_UcaPhase");
CString g_sLangTxt_CBOperate_UcaPhase;			 //=_T("Uca相位");
CString g_sLangID_CBOperate_SingleHop;			 //=_T("CBOperate_SingleHop");
CString g_sLangTxt_CBOperate_SingleHop;			 //=_T("单跳");
CString g_sLangID_CBOperate_TripleJump;			 //=_T("CBOperate_TripleJump");
CString g_sLangTxt_CBOperate_TripleJump;			 //=_T("三跳");
CString g_sLangID_CBOperate_Reclose;			 //=_T("CBOperate_Reclose");
CString g_sLangTxt_CBOperate_Reclose;			 //=_T("重合");
CString g_sLangID_CBOperate_BinBoutSelect;			 //=_T("CBOperate_BinBoutSelect");
CString g_sLangTxt_CBOperate_BinBoutSelect;			 //=_T("开入选择");
CString g_sLangID_CBOperate_BinABCD;			 //=_T("CBOperate_BinABCD");
CString g_sLangTxt_CBOperate_BinABCD;			 //=_T("开入A-B-C-D");
CString g_sLangID_CBOperate_BinEFGH;			 //=_T("CBOperate_BinEFGH");
CString g_sLangTxt_CBOperate_BinEFGH;			 //=_T("开入E-F-G-H");
CString g_sLangID_CBOperate_OutputSwitchMode;			 //=_T("CBOperate_OutputSwitchMode");
CString g_sLangTxt_CBOperate_OutputSwitchMode;			 //=_T("开出翻转启动方式");
CString g_sLangID_CBOperate_OutputDelayTime;			 //=_T("CBOperate_OutputDelayTime");
CString g_sLangTxt_CBOperate_OutputDelayTime;			 //=_T("开出翻转时刻");
CString g_sLangID_CBOperate_StartTime;			 //=_T("CBOperate_StartTime");
CString g_sLangTxt_CBOperate_StartTime;			 //=_T("时间启动");
CString g_sLangID_CBOperate_BinStart;			 //=_T("CBOperate_BinStart");
CString g_sLangTxt_CBOperate_BinStart;			 //=_T("开入量启动");
CString g_sLangID_CBOperate_AbsOrRelative;			 //=_T("CBOperate_AbsOrRelative");
CString g_sLangTxt_CBOperate_AbsOrRelative;			 //=_T("绝对or相对");
CString g_sLangID_CBOperate_AbsRelative;			 //=_T("CBOperate_AbsRelative");
CString g_sLangTxt_CBOperate_AbsRelative;			 //=_T("绝对&相对");
CString g_sLangID_CBOperate_CombError;			 //=_T("CBOperate_CombError");
CString g_sLangTxt_CBOperate_CombError;			 //=_T("组合误差");
CString g_sLangID_CBOperate_Instan;			 //=_T("CBOperate_Instan");
CString g_sLangTxt_CBOperate_Instan;			 //=_T("瞬时");
CString g_sLangID_CBOperate_Perpetual;			 //=_T("CBOperate_Perpetual");
CString g_sLangTxt_CBOperate_Perpetual;			 //=_T("永久");
CString g_sLangID_CBOperate_MaxFaultTime;			 //=_T("CBOperate_MaxFaultTime");
CString g_sLangTxt_CBOperate_MaxFaultTime;			 //=_T("最大故障时间(S)");
CString g_sLangID_CBOperate_FaultMoment;			 //=_T("CBOperate_FaultMoment");
CString g_sLangTxt_CBOperate_FaultMoment;			 //=_T("故障触发时刻");
CString g_sLangID_CBOperate_Hour;			 //=_T("CBOperate_Hour");
CString g_sLangTxt_CBOperate_Hour;			 //=_T("时");
CString g_sLangID_CBOperate_Minute;			 //=_T("CBOperate_Minute");
CString g_sLangTxt_CBOperate_Minute;			 //=_T("分");
CString g_sLangID_CBOperate_Second;			 //=_T("CBOperate_Second");
CString g_sLangTxt_CBOperate_Second;			 //=_T("秒");
CString g_sLangID_CBOperate_ImpRepre;			 //=_T("CBOperate_ImpRepre");
CString g_sLangTxt_CBOperate_ImpRepre;			 //=_T("阻抗表示方式：");
CString g_sLangID_CBOperate_AmpPhase;			 //=_T("CBOperate_AmpPhase");
CString g_sLangTxt_CBOperate_AmpPhase;			 //=_T("幅值相位");
CString g_sLangID_CBOperate_ConversionTime;			 //=_T("CBOperate_ConversionTime");
CString g_sLangTxt_CBOperate_ConversionTime;			 //=_T("转换时间(S)");
CString g_sLangID_CBOperate_Reverse;			 //=_T("CBOperate_Reverse");
CString g_sLangTxt_CBOperate_Reverse;			 //=_T("反向");
CString g_sLangID_CBOperate_Positive;			 //=_T("CBOperate_Positive");
CString g_sLangTxt_CBOperate_Positive;			 //=_T("正向");
CString g_sLangID_CBOperate_ConversionFail;			 //=_T("CBOperate_ConversionFail");
CString g_sLangTxt_CBOperate_ConversionFail;			 //=_T("转换性故障");
CString g_sLangID_CurrentHigh330;//高功率电流
CString g_sLangTxt_CurrentHigh330;
CString g_sLangID_Native_CommandTimeout;
CString g_sLangTxt_Native_CommandTimeout;











