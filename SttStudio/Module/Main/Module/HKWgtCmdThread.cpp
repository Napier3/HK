#include "HKWgtCmdThread.h"
#include <QProcess>
#include "../../../../Module/API/FileApi.h"
#include "../../../../Module/API/GlobalConfigApi.h"

HKWgtCmdThread::HKWgtCmdThread(){}

HKWgtCmdThread::~HKWgtCmdThread(){}

void HKWgtCmdThread::start_exe(const CString &strExe, const CString &strArguments)
{
	QStringList strList;
	strList << strArguments;

	QProcess process;
	process.start(strExe, strList);
}

void HKWgtCmdThread::startDetached_exe(const CString &strExe, const CString &strArguments)
{
	QStringList strList;
	strList << strArguments;

	QProcess process;
	bool bRet = process.startDetached(strExe, strList);

	if (!bRet)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_ERROR,_T("µ÷ÓÃ³ÌÐò(%s)Ê§°Ü(strArguments=%s).")
			,strExe.GetString(),strArguments.GetString());
	}
}

void HKWgtCmdThread::run()
{
	QProcess process;
	QString strCmd = m_strPath;
	strCmd += m_strExe;

	if (!IsFileExist(strCmd))
	{
		CString strRootPah;
		strRootPah = _P_GetInstallPath();
		strCmd = strRootPah;
		strCmd += _T("Stt/Bin/");
		strCmd += m_strExe;

		if (!IsFileExist(strCmd))
		{
			strCmd = strRootPah;
			strCmd += _T("Test_Win/Bin/");
			strCmd += m_strExe;

			if (!IsFileExist(strCmd))
			{
				strCmd = strRootPah;
				strCmd += _T("SttStudio/Test_Win/Bin/");
				strCmd += m_strExe;
			}
		}
	}
	process.execute(strCmd, m_listCmd);
}
