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

    //获取等待延时字符串
	CString GetCmdParasString_WaitingTime();

    HKWgtCmdThread m_oThread;
	long m_nType;

	//在Linux下记录软件已打开运行的时间,如刚打开,进入测试控制中心,需要等待时间长一些
	CTickCount32 m_oStartTickCount;

public:
	static void ExecCmd(const CString& strType, const CString& strID, const CString& strSrcData, const CString &strArgv);
	static void ExecCmd(const CString& strType, QStringList strings);
	static void UpdateExecCmd( const CString &strTmpFile, const CString &strTplID);//通过共享内存或传入参数，调用新的exe  

private:
	static void OnOpenFile(const CString& strDataSrc, const CString &strArgv);
	static void OnMacroTest(const CString& strID, const CString &strArgv);
	static void OnOpenDialog(const CString& strID, const CString &strArgv);//zhouhj  在linux程序中弹出对话框
	static void OnCmd(const CString& strID);
	static void OnMacroExe(const CString& strID, const CString &strArgv);
	static void ReadSharedData();//读取共享内存数据
};

extern HKWgtCmdExecTool* g_pHKWgtCmdExecTool;
extern QMainWindow *g_pSttWgtCmdMainWindow;
extern QSharedMemory g_oTestMacroSM;//切换测试模块共享内存
extern double g_dStartupDelayTime;//开机后等待自动测试启动需要的延时时间
