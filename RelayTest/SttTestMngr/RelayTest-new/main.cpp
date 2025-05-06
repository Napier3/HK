#include <QCoreApplication>
#include "SttTestMngr.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	CString strPath = qApp->applicationDirPath();
	long nIndex =  strPath.ReverseFind('/');
	strPath = strPath.left(nIndex);
	_P_SetSystemPath(strPath.GetString());	

	CSttTestMngr::Create();
	int nRet=a.exec();
	CSttTestMngr::Release();

	return nRet;
}

