#ifndef CSTTTESTMNGR_H
#define CSTTTESTMNGR_H

#include <QObject>
#include <QTimer>
#include "QUdpSocket"
#include "../../Module/SttSocket/Multicast/SttMulticastServerSocket.h"
#include "../../Module/API/NetworkInterface.h"
#include "../../Module/API/GlobalConfigApi.h"
#include "../../Module/SttGlobalDef.h"
#include "QList"
#include "QStringList"
//"SttTestMngr.ini"
/***
[boot]
TestServer=SttTestServer_PTU200L
TestMainCore=SttTestMainCore

[App]
SttApp=SttTestServer_PTU200L
SttApp=SttTestMainCore
SttApp=PUDA ²©µçµ×²ã
SttApp=SttLiveUpdate

[Driver]
SttDriver=SttDriver_466
SttDriver=SttDriver_PTU
SttDriver=SttDriver_PID200
 ***/
class CSttTestMngr : public QObject,public CLogBase
{
	Q_OBJECT
public:
	static CSttTestMngr *Create();
	static void Release();

	CSttTestMngr(void);
	virtual ~CSttTestMngr(void);

	static int g_nTestMngrRef;
	static CSttTestMngr *g_pTestMngr;

public:
    CSttMulticastServerSocket *m_pMulticastServerSocket;
	void MulticastInit();
	BOOL StartProcess(CString strApp);
	void GetConfigInfo();
	void GetRunningProcess(CString strPsData,CStringArray &strAppArray);
	void GetIniCfg(CStringArray &arrayBoot,CStringArray &arraySttApp,CStringArray &arrayDriver);

	CString m_strBootTestServer;
	QList<CString> m_listSttDriver;
	QList<CString> m_listSttApp;
    QTimer *m_pTimer;
    QStringList m_oMntList;
	BOOL m_bThreadRun;
	void *m_shm;// = NULL;
	int m_nShareMemoryId;// = -1;
	long m_nShmkey;// = 1234;

public slots:
    void OnTimer();
public:
	virtual void LogString(long nLevel, const CString &strMsg);
    virtual void LogString(long nLevel, const char *strMsg);
};

inline BOOL callcmd(const char *cmd, std::string &result)
{
	int MAX_CMD_BUF_LEN = 1024;
	FILE *fp = popen(cmd,"r");
	if(fp == NULL)
	{
		return FALSE;
	}

	char buffer[MAX_CMD_BUF_LEN];
	memset(buffer,0,MAX_CMD_BUF_LEN);
	result = "";
	while(TRUE)
	{
		char *res = fgets(buffer, sizeof(buffer), fp);

		if(res == NULL)
		{
			break;
		}

		result += std::string(buffer);
	}

	pclose(fp);

	return TRUE;
}

inline BOOL callcmd(std::string cmd, std::string &result)
{
	return callcmd(cmd.c_str(),result);
}

inline BOOL callcmd(CString cmd, std::string &result)
{
	return callcmd(cmd.GetString(),result);
}

#endif // CSTTTESTMNGR_H
