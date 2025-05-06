#include "SttTestMngr.h"
#include "QHostAddress"
#include "QAbstractSocket"
#include "QNetworkInterface"
#include "QDir"
#include "QCoreApplication"
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include "qdebug.h"
#include "../../Module/API/NetworkInterface.h"
#include "../../Module/OSInterface/QT/CDateTime_QT.h"
#include "../../Module/SttTestBase/SttMacroXmlKeys.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "fstream"

#define USBPATH  "/mnt/Stt/Usb/"

int CSttTestMngr::g_nTestMngrRef = 0;
CSttTestMngr *CSttTestMngr::g_pTestMngr = NULL;

CSttTestMngr *CSttTestMngr::Create()
{
	g_nTestMngrRef++;

	if(g_nTestMngrRef == 1)
	{
		g_pTestMngr = new CSttTestMngr;
	}

	return g_pTestMngr;
}

void CSttTestMngr::Release()
{
	g_nTestMngrRef--;

	if(g_nTestMngrRef == 0)
	{
		delete g_pTestMngr;
		g_pTestMngr = NULL;
	}
}


void *XDateTimeThread(LPVOID pParam)
{
	CSttTestMngr *pSttTestMngr = (CSttTestMngr*)pParam;
	CDateTime oDateTime;
	oDateTime.ServerInit();
	long nSecond, nNSecond, nZone;
	int fd = open("/dev/mem", O_RDWR| O_SYNC, 0655);
	char *pBase = (char*)mmap(0, 8192, PROT_READ, MAP_SHARED, fd, 0x70000000);
    char *pUtcH = pBase + 4;   //0x7000_0004 ——UTC TIME高32位（s）
    char *pUtcL = pBase + 12;  //0x7000_000C ——UTC TIME低32位（ns）
    char *pSysTickH = pBase + 4144;   //驱动未使用
    char *pSysTickL = pBase + 4148;   //驱动未使用

    while(pSttTestMngr->m_bThreadRun)   //dead loop    testmngr退出后，停止
	{
        memcpy(&nSecond,pUtcH,4);   //read reg 0x7000_0004
        memcpy(&nNSecond,pUtcL,4);  //read reg 0x7000_000C
        oDateTime.GetDateZone(nZone);   //从共享内存中读数据（datezone时间日期的时区信息） m_shm + 12
		nSecond += nZone*3600;
        oDateTime.SetDateTime(nSecond,nNSecond); //将时间信息写入共享内存  m_shm + 4   m_shm + 8

		memcpy(&nSecond,pSysTickH,4);
		memcpy(&nNSecond,pSysTickL,4);
        oDateTime.SetSystemTick(nSecond,nNSecond);  //将时间信息写入共享内存

		usleep(400);
	}

	munmap(pBase, 8192);
	pthread_exit(0);
}

CSttTestMngr::CSttTestMngr()
{
	m_shm = NULL;
	m_nShmkey = 2024;
        //shmget得到一个共享内存标识符或创建一个共享内存对象
        //多进程读写即一个进程写共享内存，一个或多个进程读共享内存。下面的例子实现的是一个进程写共享内存，一个进程读共享内存。
        //下面程序实现了创建共享内存，并写入消息。
        //用于Linux进程通信共享内存。共享内存函数由shmget、shmat、shmdt、shmctl四个函数组成。
	m_nShareMemoryId = shmget((key_t)m_nShmkey, 4, 0666 | IPC_CREAT);

	if(m_nShareMemoryId == -1)
	{
		CLogPrint::LogString(XLOGLEVEL_ERROR, _T("Requset ShareMemoryId Fail"));
	}

    m_shm = shmat(m_nShareMemoryId, (void *)0, 0);  //shmat(把共享内存区对象映射到调用进程的地址空间)

	if(m_shm == (void *) -1)
	{
		CLogPrint::LogString(XLOGLEVEL_ERROR, _T("Requset ShareMemoryAddr Fail"));
	}
	else
	{
		long nVersion = 0;
		nVersion += 24<<16;
		nVersion += 12<<8;
		nVersion += 6;
        memcpy(m_shm, &nVersion, 4);//24.12.06     将verison信息“写入”共享内存。
	}

	CLogPrint::Create(this);
	//等待FPGA初始化完成,尤其是PI1000的数字模块
	struct timeval timeout = {2,0};
    select(0,NULL,NULL,NULL,&timeout);  //Qt数据库模型中的select函数是用于查询数据库中数据的重要函数。
	MulticastInit();
	GetConfigInfo();

	if(!m_listSttDriver.isEmpty())
	{
		CString strCmd, strPath;
		QFile file;

		foreach(CString strdata, m_listSttDriver)
		{
			strPath.Format(_T("%s%s"), _P_GetBinPath(), strdata.GetString());
			file.setFileName(strPath);

			if(file.exists())
			{
				strCmd.Format(_T("insmod %s"), strPath.GetString());
				system(strCmd.toUtf8());
			}
		}
	}

	if(!m_strBootTestServer.isEmpty())
	{
		//优先选择SttTestServer，后选择SttTestServer_*
		CString strPath = _P_GetBinPath() + QString("SttTestServer");
		QFile oTestServer(strPath);
		if(oTestServer.exists())
		{
			long nIndex = m_strBootTestServer.indexOf("_");
			if(nIndex > 0)
			{
				CString strServer = m_strBootTestServer;
				strServer = strServer.remove(0, nIndex + 1);
				CString strCmd;
				strCmd.Format(_T("%s %s &"), strPath.GetString(), strServer.GetString());
				system(strCmd.toUtf8());
			}
		}
		else
		{
			StartProcess(m_strBootTestServer);
		}
	}

	QDir UsbPath(USBPATH);

	if(UsbPath.exists())
	{
        QString strCmd = QString("rm -rf %1").arg(USBPATH);   //删除USB目录下的所有内容  %1替换为USBPATH
		system(strCmd.toUtf8());
	}
       //Linux系统操作中，为了提高磁盘读写效率，就需要使用到sync命令
       //sync命令是Linux系统中的一个基础命令,用于将内存中的数据写入磁盘,确保文件系统的完整性。
       //sync命令用于数据同步,sync命令是在关闭Linux系统时使用的。
	system("sync");
	m_oMntList.clear();
	m_pTimer = new QTimer;
	connect(m_pTimer, SIGNAL(timeout()), this, SLOT(OnTimer()));
    m_pTimer->start(2000);  //启动定时器，定时间隔2000ms
	m_bThreadRun = TRUE;
	pthread_t nthreadid;
	pthread_create(&nthreadid, NULL, XDateTimeThread, (LPVOID)this);

	CMacroXmlKeys::Create();
}

CSttTestMngr::~CSttTestMngr()
{
	CMacroXmlKeys::Release();

	m_bThreadRun = FALSE;
	delete m_pMulticastServerSocket;
	m_pMulticastServerSocket = NULL;
	Sleep(10);
}

void CSttTestMngr::GetConfigInfo()
{
	m_strBootTestServer = "";
	m_listSttApp.clear();
	m_listSttDriver.clear();
	CString strLabel, strVal;
	int nLabelType = 0; //1=boot 2=STT 3=Driver
	QFile fileini(_P_GetBinPath() + QString("SttTestMngr.ini"));

	if(fileini.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QString strData;

		while(!fileini.atEnd())
		{
			strData = fileini.readLine();

			if(strData.contains("[boot]"))
			{
				nLabelType = 1;
			}
			else if(strData.contains("[App]"))
			{
				nLabelType = 2;
			}
			else if(strData.contains("[Driver]"))
			{
				nLabelType = 3;
			}
			else if(strData.contains("="))
			{
				strLabel = strData.split("=")[0].replace(" ", "");
				strVal = strData.split("=")[1].replace(" ", "");
				strVal = strVal.left(strVal.length() - 1);

				if(strLabel.isEmpty() || strVal.isEmpty())
				{
					continue;
				}

				switch(nLabelType)
				{
					case 1:
					{
						if(strLabel == "TestServer")
						{
							m_strBootTestServer = strVal;
						}
					}
					break;

					case 2:
					{
						m_listSttApp.append(strVal);
					}
					break;

					case 3:
					{
						m_listSttDriver.append(strVal);
					}
					break;
				}
			}
			else
			{
				break;
			}
		}

		fileini.close();
	}
}

BOOL CSttTestMngr::StartProcess(CString strApp)
{
	QFile fileApp(_P_GetBinPath() + strApp);

	if(!fileApp.exists())
	{
		return FALSE;
	}

	CString strCmd;
	strCmd.Format(_T("pkill -9 %s"), strApp.GetString());
	system(strCmd.toUtf8());
	strCmd.Format(_T("%s%s &"), _P_GetBinPath(), strApp.GetString());
	system(strCmd.toUtf8());

	return TRUE;
}

void CSttTestMngr::GetRunningProcess(CString strPsData, CStringArray &strAppArray)
{
	foreach(CString data, m_listSttApp)
	{
		if(strPsData.contains(data))
		{
			strAppArray.Add(data);
		}
		else
		{
			if(strPsData.contains("SttTestServer") && data.contains("SttTestServer"))
			{
				strAppArray.Add(data);
			}
		}
	}
}

void CSttTestMngr::GetIniCfg(CStringArray &arrayBoot, CStringArray &arraySttApp, CStringArray &arrayDriver)
{
	if(!m_strBootTestServer.isEmpty())
	{
		arrayBoot.Add(m_strBootTestServer);
	}

	foreach(CString data, m_listSttApp)
	{
		arraySttApp.Add(data);
	}

	foreach(CString data, m_listSttDriver)
	{
		arrayDriver.Add(data);
	}
}

void stt_find_device_info(CString strData, CString &strSN, CString &strModel)
{
	int nPosBegin = strData.Find("\"SN\"");
	nPosBegin = strData.Find(" value", nPosBegin);
	nPosBegin = strData.Find("\"", nPosBegin);
	int nPosEnd = strData.Find("\"", nPosBegin + 1);
	strSN = strData.Mid(nPosBegin + 1, nPosEnd - nPosBegin - 1);
	nPosBegin = strData.Find("\"Model\"");
	nPosBegin = strData.Find(" value=", nPosBegin);
	nPosBegin = strData.Find("\"", nPosBegin);
	nPosEnd = strData.Find("\"", nPosBegin + 1);
	strModel = strData.Mid(nPosBegin + 1, nPosEnd - nPosBegin - 1);
}

void CSttTestMngr::MulticastInit()
{
	CString strIP, strMask;
	stt_file_get_deviceip(strIP, strMask);
	m_pMulticastServerSocket = new CSttMulticastServerSocket;
	m_pMulticastServerSocket->Create(STT_Multicast_IP, STT_Multicast_Port, strIP);
	m_pMulticastServerSocket->SetLocalNetInfo(strIP, strMask);
	CString strSN, strModel;
	strSN = _T("PSL001");
	strModel = _T("PSL001");
	QFile fileXml(_P_GetConfigPath() + CString("DeviceSystemParas.xml"));

	if(fileXml.exists())
	{
		if(fileXml.open(QIODevice::Text | QIODevice::ReadOnly))
		{
			char pszBuf[1000];
			fileXml.read(pszBuf, 1000);
			fileXml.close();
			pszBuf[999] = '\0';
			CString strData(pszBuf);
			stt_find_device_info(strData, strSN, strModel);
			CString strMac = QString("%1").arg(strSN,12,'0');
			strMac = strMac.insert(10,":");
			strMac = strMac.insert(8,":");
			strMac = strMac.insert(6,":");
			strMac = strMac.insert(4,":");
			strMac = strMac.insert(2,":");
			system("ifconfig eth0 down");
			CString strCmd = QString("ifconfig eth0 hw ether %1").arg(strMac);
			system(strCmd.toUtf8());
			system("ifconfig eth0 up");
		}
	}

	m_pMulticastServerSocket->SetDeviceInfo(strSN, strModel);
}

void CSttTestMngr::LogString(long nLevel, const CString &strMsg)
{
	QTime tm = QTime::currentTime();
	CString str;
	str.Format(("%d:%d:%d.%d:"),
			   tm.hour(), tm.minute(), tm.second(),
			   tm.msec());
#ifdef _PSX_QT_LINUX_
	qDebug() << str << strMsg;
#endif

	if(nLevel != XLOGLEVEL_DEBUG)
	{
		return;
	}
}

void CSttTestMngr::LogString(long nLevel, const char *strMsg)
{
	LogString(nLevel, CString(strMsg));
}

typedef struct
{
	QString strFile;
	int bfsType;//0-NTFS,1-FAT32,2-Unknow
}DiskInfo;

void CSttTestMngr::OnTimer()    //U盘处理
{
	QDir UsbPath(USBPATH);

	if(UsbPath.exists())
	{
		QList<DiskInfo> DiskInfoList;

		std::string line;
		BOOL bRet = callcmd("fdisk -l",line);
		if(!bRet)
		{
			return;
		}

		CString strData = CString::fromStdString(line);
		long nFindPos = 0;

		while(TRUE)
		{
			int nLineBegin = strData.indexOf('\n',nFindPos);
			if(nLineBegin >= 0)
			{
				int nLineEnd = strData.indexOf('\n',nLineBegin + 1);
				if(nLineEnd < 0)
				{
					break;
				}

				CString strLineData = strData.mid(nLineBegin + 1,nLineEnd - 1 - nLineBegin);
				if(strLineData.indexOf("/dev/sd") != 0)
				{
					nFindPos += nLineEnd - nLineBegin;
					continue;
				}

				int nPathEnd = strLineData.indexOf(" ");

				if(strLineData.contains("NTFS"))
				{
					DiskInfo oDiskInfo;
					oDiskInfo.strFile = strLineData.left(nPathEnd);
					oDiskInfo.bfsType = 0;
					DiskInfoList.append(oDiskInfo);
				}
				else if(strLineData.contains("FAT32"))
				{
					DiskInfo oDiskInfo;
					oDiskInfo.strFile = strLineData.left(nPathEnd);
					oDiskInfo.bfsType = 1;
					DiskInfoList.append(oDiskInfo);
				}
				else if(strLineData.contains("Unknown"))
				{
					DiskInfo oDiskInfo;
					oDiskInfo.strFile = strLineData.left(nPathEnd);
					oDiskInfo.bfsType = 2;
					DiskInfoList.append(oDiskInfo);
				}

				nFindPos +=nLineEnd - nLineBegin;
			}
			else
			{
				break;
			}
		}

		for(int i = 0; i < DiskInfoList.count(); i++)
		{
			DiskInfo oDiskInfo = DiskInfoList.at(i);
			if(oDiskInfo.bfsType == 2)
			{
				DiskInfoList.clear();
				DiskInfoList.append(oDiskInfo);
				break;
			}
		}

		if(DiskInfoList.count() == 0)
		{
			QDir oDir(USBPATH);
			oDir.setFilter(QDir::Dirs);
			QFileInfoList oFileList = oDir.entryInfoList();
			QString strFileName;
			BOOL bHasSubFiles = FALSE;

			for(int i = 0; i < m_oMntList.count(); i++)
			{
				QString strCmd = QString("umount %1").arg(m_oMntList.at(i));
				system(strCmd.toUtf8());
			}

			for(int i = 0; i < oFileList.count(); i++)
			{
				strFileName = oFileList.at(i).fileName();
				strFileName = strFileName.replace(".", "");

				if(strFileName.length() > 0)
				{
					bHasSubFiles = TRUE;
					break;
				}
			}

			if(bHasSubFiles)
			{
				QString strCmd = QString("rm -rf %1").arg(USBPATH);
				system(strCmd.toUtf8());
				system("sync");
			}

			m_oMntList.clear();
		}
		else
		{
			for(int i = 0; i < DiskInfoList.count(); i++)
			{
				DiskInfo oDiskInfo = DiskInfoList.at(i);
				QString strSda = oDiskInfo.strFile;
				QString strMntPath = USBPATH + QString::number(i+1);
				QDir mntfile(strMntPath);

				if(!mntfile.exists())
				{
					mntfile.mkdir(strMntPath);
					system("sync");
				}

				if(!m_oMntList.contains(strMntPath))
				{
					//可支持FAT32、NTFS格式的U盘
					QString strCmd;

					switch(oDiskInfo.bfsType)
					{
					case 0:
					{
						strCmd = QString("/mnt/ntfs-3g %1 %2").arg(strSda).arg(strMntPath);
						system(strCmd.toUtf8());
					}
						break;
					case 1:
					{
						strCmd = QString("mount -o utf8 %1 %2").arg(strSda).arg(strMntPath);
						system(strCmd.toUtf8());
					}
						break;
					case 2:
					{
						strCmd = QString("mount -o utf8 %1 %2").arg(strSda).arg(strMntPath);
						bRet = callcmd(strCmd.toUtf8(),line);
						if(bRet)
						{
							strData = CString::fromStdString(line);

							if(strData.contains("failed"))
							{
								strCmd = QString("/mnt/ntfs-3g %1 %2").arg(strSda).arg(strMntPath);
								system(strCmd.toUtf8());
							}
						}
					}
						break;
					}

					system(strCmd.toUtf8());
					m_oMntList.append(strMntPath);
				}
			}
		}
	}
	else
	{
		UsbPath.mkdir(USBPATH);
		system("sync");
	}
}
