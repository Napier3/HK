#include "HKWgtCmdExecTool.h"
#include "../Ctrls/HKWgtLinux.h"
#include "../../../../Module/API/GlobalConfigApi.h"
#include "../../../../Module/System/TickCount32.h"
#include "../../LiveUpdate/SttLiveUpdateShell.h"
#include "../../../../61850/Module/SCL/SclFileMngr/XSclFileMngr.h"
#include "../../UI/SCL/QSttSelSclFileWidget.h"
#include <QTableWidget>
#include <QProcess>
#include <QStyleOption>
#include <QMessageBox>
#include <QDesktopServices>
#include <QString>
#include <QStringList>
#include "../SttMainArgvDef.h"
#include "../../../../Module/OSInterface/QT/XMessageBox.h"


HKWgtCmdExecTool* g_pHKWgtCmdExecTool = nullptr;
QMainWindow *g_pSttWgtCmdMainWindow = nullptr;
QSharedMemory g_oTestMacroSM(STT_UPDATE_TESTMACRO_SM_ID);//切换测试模块共享内存

double g_dStartupDelayTime = 3.0f;//开机后等待自动测试启动需要的延时时间

HKWgtCmdExecTool::HKWgtCmdExecTool()
{
	if (!g_oTestMacroSM.attach()) 
	{
		if (!g_oTestMacroSM.create(STT_UPDATE_TESTMACRO_SM_SIZE)) 
		{
            CXMessageBox::information(nullptr,_T("提示"),_T("创建共享内存段失败!"),QMessageBox::Yes);
		}
	}
    g_pHKWgtCmdExecTool = this;
	m_nType = LINUX;
}

HKWgtCmdExecTool::~HKWgtCmdExecTool()
{
	// 在析构函数中分离共享内存
	if(g_oTestMacroSM.isAttached())
		g_oTestMacroSM.detach();
}

CString HKWgtCmdExecTool::GetCmdParasString_WaitingTime()
{
	double dHasWaitingTime = m_oStartTickCount.GetTickCountLong(FALSE);
	dHasWaitingTime /= 1000;
	CString strText;
	strText = ARGV_CMD_PARA_ID_waiting_time;

	//延时最大等待时间,不超过10s；如果当前程序已经打开超过10s,则不再需要等待
	if ((dHasWaitingTime>g_dStartupDelayTime)||(dHasWaitingTime<=0))
	{
		strText += _T("=0;");
		return strText;
	}

	long nNeedWaitTime = (g_dStartupDelayTime - dHasWaitingTime)*1000;//转换为ms
	strText.AppendFormat(_T("=%ld;"),nNeedWaitTime);
	return strText;
}

void HKWgtCmdExecTool::ExecCmd(const CString& strType, const CString& strID, const CString& strSrcData, const CString &strArgv)
{
	{
		if(strType == "cmd")
		{
			OnCmd(strID);
		}
		else if(strType == ARGV_CMD_ID_MACROTEST)
		{
			OnMacroTest(strID, strArgv);
		}
		else if (strType == ARGV_CMD_ID_OPENFILE)
		{
			OnOpenFile(strSrcData, strArgv);
		}
		else if (strType == ARGV_CMD_ID_OPENDIALOG)
		{
			OnOpenDialog(strID, strArgv);
		}
        else if (strType == ARGV_CMD_ID_OPENMACROEXE)
		{
			OnMacroExe(strID, strArgv);
		}
	}
}

void HKWgtCmdExecTool::ExecCmd(const CString& strType, QStringList strings)
{
    g_pHKWgtCmdExecTool->m_oThread.m_strPath = _P_GetBinPath();

    if (g_pHKWgtCmdExecTool->m_nType == WINDOWS)
	{
        g_pHKWgtCmdExecTool->m_oThread.m_strExe = "TestCtrlCntrWin.exe";
	} 
    g_pHKWgtCmdExecTool->m_oThread.m_listCmd.clear();
    g_pHKWgtCmdExecTool->m_oThread.m_listCmd << strType << strings;
    g_pHKWgtCmdExecTool->m_oThread.start();
}

void HKWgtCmdExecTool::OnOpenFile( const CString& strDataSrc , const CString &strArgv)
{
	if(strDataSrc.GetLength() <= 1)
	{
		return;
	}

    QTableWidget* pWgt = m_gHKWgtLinux->findChild<QTableWidget*>(strDataSrc);
	QTableWidgetItem* pItem = pWgt->itemAt(pWgt->currentRow(), 0);

    if (pItem == nullptr)
	{
		return;
	}
	CString strFileName = pItem->text();
}

//macrotest macro_id=XXXX;iec=1/0;meas_svr=1/0;
void HKWgtCmdExecTool::OnMacroTest( const CString& strID , const CString &strArgv)
{
    g_pHKWgtCmdExecTool->m_oThread.m_strPath = _P_GetBinPath();
    if (g_pHKWgtCmdExecTool->m_nType == WINDOWS)
	{
        g_pHKWgtCmdExecTool->m_oThread.m_strExe = "TestCtrlCntrWin.exe";
	} 
	else
	{
        g_pHKWgtCmdExecTool->m_oThread.m_strExe = "TestCtrlCntrLinux";
	}
    g_pHKWgtCmdExecTool->m_oThread.m_listCmd.clear();
    g_pHKWgtCmdExecTool->m_oThread.m_listCmd << ARGV_CMD_ID_MACROTEST;

	CString strParas,strSsclPath;
	strParas.Format(_T("%s=%s;"), ARGV_CMD_PARA_ID_MACROID, strID.GetString());
	strSsclPath = g_oXSclFileMngr.GetCurrSelSsclFilePah();
	strParas.AppendFormat(_T("%s="),ARGV_CMD_PARA_ID_sscl_path);
	strParas += strSsclPath;
	strParas += _T(";");
    strParas += g_pHKWgtCmdExecTool->GetCmdParasString_WaitingTime();
	strParas += strArgv;
    g_pHKWgtCmdExecTool->m_oThread.m_listCmd << strParas;
    g_pHKWgtCmdExecTool->m_oThread.start();
	CTickCount32 time;
    while(!g_pHKWgtCmdExecTool->m_oThread.isFinished())
	{
		time.DoEvents(10);
	}

    if (g_pSttSelSclFileWidget != nullptr)
	{
		g_oXSclFileMngr.OpenSclFileMngrCfg();
		g_pSttSelSclFileWidget->InitDatas();
	}
}

void HKWgtCmdExecTool::OnMacroExe( const CString& strID , const CString &strArgv)
{
    g_pHKWgtCmdExecTool->m_oThread.m_strPath = _P_GetBinPath();
    g_pHKWgtCmdExecTool->m_oThread.m_strExe = strID;
    g_pHKWgtCmdExecTool->m_oThread.m_listCmd.clear();
    g_pHKWgtCmdExecTool->m_oThread.m_listCmd << strArgv;

	CString strParas,strSsclPath;
    g_pHKWgtCmdExecTool->m_oThread.start();
	CTickCount32 time;
    while(!g_pHKWgtCmdExecTool->m_oThread.isFinished())
	{
		time.DoEvents(10);
	}
	ReadSharedData();//进程结束读取数据
}

void HKWgtCmdExecTool::OnOpenDialog( const CString& strID , const CString &strArgv)
{
    g_pHKWgtCmdExecTool->m_oThread.m_strPath = _P_GetBinPath();

    if (g_pHKWgtCmdExecTool->m_nType == WINDOWS)
	{
        g_pHKWgtCmdExecTool->m_oThread.m_strExe = "TestCtrlCntrWin.exe";
	} 
	else
	{
        g_pHKWgtCmdExecTool->m_oThread.m_strExe = "TestCtrlCntrLinux";
	}
    g_pHKWgtCmdExecTool->m_oThread.m_listCmd.clear();
    g_pHKWgtCmdExecTool->m_oThread.m_listCmd << ARGV_CMD_ID_OPENDIALOG;

	BOOL bUpdateScl = FALSE;
    CString strParas,strSsclPath;
	strParas.Format(_T("%s=%s;"), ARGV_CMD_PARA_ID_DIALOGID, strID.GetString());

	if (strID == _T("IecCapDialog"))
	{
		strSsclPath = g_oXSclFileMngr.GetCurrSelSsclFilePah();
		strParas.AppendFormat(_T("%s="),ARGV_CMD_PARA_ID_sscl_path);
		strParas += strSsclPath;
		strParas += _T(";");	
		bUpdateScl = TRUE;
	}

    strParas += g_pHKWgtCmdExecTool->GetCmdParasString_WaitingTime();
	strParas += strArgv;
    g_pHKWgtCmdExecTool->m_oThread.m_listCmd << strParas;
    g_pHKWgtCmdExecTool->m_oThread.start();

	CTickCount32 time;
    while(!g_pHKWgtCmdExecTool->m_oThread.isFinished())
	{
		time.DoEvents(10);
	}

    if ((g_pSttSelSclFileWidget != nullptr)&&bUpdateScl)
	{
		g_oXSclFileMngr.OpenSclFileMngrCfg();
		g_pSttSelSclFileWidget->InitDatas();
	}
}

void HKWgtCmdExecTool::OnCmd( const CString& strID )
{
	if (TOOL_TEST_SET == strID)
	{
		theLiveUpdate.Init();
		theLiveUpdate.LocalUpdate();
	}
	else if (TOOL_TEST_APP_UPDATE == strID)
	{
		theLiveUpdate.Init();
		theLiveUpdate.TestAppUpdate();
	}
	else if (TOOL_TEST_TESTER_UPDATE == strID)
	{
	}
	else if (TOOL_TEST_SUPPORT == strID)
	{
	}
	else if (TOOL_TEST_POWERSET == strID)
	{
	}
	else if (TOOL_TEST_VERSION == strID)
	{
	}
	else
	{
		QMessageBox::information(NULL, QObject::tr("提示"), QObject::tr("此功能需获取相关权限后方可使用,可咨询测试仪生成厂家了解功能授权详情."));
	}
}

void HKWgtCmdExecTool::ReadSharedData()
{
    CString strTplID, strParaFilePath;
	char *TestMacroSM_addr = static_cast<char *>(g_oTestMacroSM.data());
    if (TestMacroSM_addr != nullptr)
	{
        QString strRevData = QString::fromLocal8Bit(TestMacroSM_addr, STT_UPDATE_TESTMACRO_SM_SIZE);
		QStringList parts = strRevData.split(";");
		if (parts.size() >= 2) 
		{
			strTplID = parts.at(0);
			strParaFilePath = parts.at(1);
			if(g_oTestMacroSM.create(sizeof(STT_UPDATE_TESTMACRO_SM_ID)))
			{
				char *fszTestMacroData = static_cast<char *>(g_oTestMacroSM.data());
                if (fszTestMacroData != nullptr)
				{
					memset(fszTestMacroData, 0, g_oTestMacroSM.size());
				}
			}
			if(!(strTplID.IsEmpty()) && IsFileExist(strParaFilePath))
			{
				CString strExeID,  strType,  strArgv;
				UpdateExecCmd(strParaFilePath, strTplID);
			}
		} 
	} 
	return;
}

void HKWgtCmdExecTool::UpdateExecCmd( const CString &strTmpFile, const CString &strTplID )
{
	CString strEXE ,strExePath;
	CString strAbnormalType;
    g_pHKWgtCmdExecTool->m_oThread.m_listCmd.clear();

    if(strTplID == SMVABNTEST_TPL_ID)//sv异常模拟
    {
		CString strSVExe = _T("StateTest");
		strAbnormalType.Format(_T("%s=%s;"), STATE_ABNORMAL_TYPE, "1");
        g_pHKWgtCmdExecTool->m_oThread.m_listCmd << strAbnormalType;
		strEXE =  strSVExe  + _T(".exe");//StateTest.exe	
    }
	else
    {
		strEXE =  strTplID  + _T(".exe");//ReplayTest.exe
	}
	strExePath = _P_GetBinPath() + strEXE;

    if(IsFileExist(strExePath))
    {
        g_pHKWgtCmdExecTool->m_oThread.m_strPath = _P_GetBinPath();
        g_pHKWgtCmdExecTool->m_oThread.m_strExe = strEXE;
        CString strParas;
        QString strQPara = QString("%1=%2;").arg(ARGV_CMD_PARA_ID_TmpPath).arg(strTmpFile);//2024-01-03 wuxinyi 解决中文路径乱码问题
        strParas.Format(strQPara);
        g_pHKWgtCmdExecTool->m_oThread.m_listCmd << strParas;
        g_pHKWgtCmdExecTool->m_oThread.start();

        CTickCount32 time;
        while(!g_pHKWgtCmdExecTool->m_oThread.isFinished())
        {
           time.DoEvents(10);
        }
        ReadSharedData();//进程结束读取数据
    }
	else
	{
		CString strTip = _T("");
        strTip.Format( _T("找不到该【%s】文件路径！"), strExePath.GetString());
        CXMessageBox::information(nullptr, _T("提示"), strTip);
	}
	return;
}

