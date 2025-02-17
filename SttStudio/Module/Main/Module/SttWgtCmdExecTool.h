#pragma once

#include "../../../Module/BaseClass/ExBaseList.h"
#include "../../../Module/System/TickCount32.h"

#include "SttWgtCmdThread.h"
#include <QMainWindow>
#include <QSharedMemory>

class QSttWgtCmdExecTool
{
public:
	enum
	{
		LINUX,
		WINDOWS
	};

	QSttWgtCmdExecTool();
	virtual ~QSttWgtCmdExecTool();

	//zhouhj 2023.10.18 ��ȡ�ȴ���ʱ�ַ���
	CString GetCmdParasString_WaitingTime();

	QSttWgtCmdThread m_oThread;
	long m_nType;

	//zhouhj 2023.10.18
	//��Linux�¼�¼����Ѵ����е�ʱ��,��մ�,������Կ�������,��Ҫ�ȴ�ʱ�䳤һЩ
	CTickCount32 m_oStartTickCount;

public:
	static void ExecCmd(const CString& strType, const CString& strID, const CString& strSrcData, const CString &strArgv);
	static void ExecCmd(const CString& strType, QStringList strings);
	static void UpdateExecCmd( const CString &strTmpFile, const CString &strTplID);//ͨ�������ڴ��������������µ�exe  

private:
	//330
	static void OnOpenFile(const CString& strDataSrc, const CString &strArgv);
	static void OnMacroTest(const CString& strID, const CString &strArgv);
	static void OnOpenDialog(const CString& strID, const CString &strArgv);//zhouhj  ��linux�����е����Ի���
	static void OnCmd(const CString& strID);
	static void OnMacroExe(const CString& strID, const CString &strArgv);
	static void ReadSharedData();//��ȡ�����ڴ�����
};

extern QSttWgtCmdExecTool* g_pQSttWgtCmdExecTool;
extern QMainWindow *g_pSttWgtCmdMainWindow;
extern QSharedMemory g_oTestMacroSM;//2023-12-26 wuxinyi �л�����ģ�鹲���ڴ�
extern double g_dStartupDelayTime;//������ȴ��Զ�����������Ҫ����ʱʱ��
