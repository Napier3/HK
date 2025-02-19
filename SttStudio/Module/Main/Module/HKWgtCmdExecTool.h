/*
 *Shandong HuanKe copyright 2025
 *Author: Eric
*/
#pragma once

#include "../../../Module/BaseClass/ExBaseList.h"
#include "../../../Module/System/TickCount32.h"

#include "HKWgtCmdThread.h"
#include <QMainWindow>
#include <QSharedMemory>

class HKWgtCmdExecTool
{
public:
	enum
	{
		LINUX,
		WINDOWS
	};

    HKWgtCmdExecTool();
    virtual ~HKWgtCmdExecTool();

    //��ȡ�ȴ���ʱ�ַ���
	CString GetCmdParasString_WaitingTime();

    HKWgtCmdThread m_oThread;
	long m_nType;

	//��Linux�¼�¼����Ѵ����е�ʱ��,��մ�,������Կ�������,��Ҫ�ȴ�ʱ�䳤һЩ
	CTickCount32 m_oStartTickCount;

public:
	static void ExecCmd(const CString& strType, const CString& strID, const CString& strSrcData, const CString &strArgv);
	static void ExecCmd(const CString& strType, QStringList strings);
	static void UpdateExecCmd( const CString &strTmpFile, const CString &strTplID);//ͨ�������ڴ��������������µ�exe  

private:
	static void OnOpenFile(const CString& strDataSrc, const CString &strArgv);
	static void OnMacroTest(const CString& strID, const CString &strArgv);
	static void OnOpenDialog(const CString& strID, const CString &strArgv);//zhouhj  ��linux�����е����Ի���
	static void OnCmd(const CString& strID);
	static void OnMacroExe(const CString& strID, const CString &strArgv);
	static void ReadSharedData();//��ȡ�����ڴ�����
};

extern HKWgtCmdExecTool* g_pHKWgtCmdExecTool;
extern QMainWindow *g_pSttWgtCmdMainWindow;
extern QSharedMemory g_oTestMacroSM;//�л�����ģ�鹲���ڴ�
extern double g_dStartupDelayTime;//������ȴ��Զ�����������Ҫ����ʱʱ��
