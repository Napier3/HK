#include "HKMainFrameBase.h"
#include "Ctrls/HKWgtLinux.h"
#include "../../../Module/API/GlobalConfigApi.h"
#include "Module/HKWgtFactory.h"
#include "../../../Module/XLanguage/XLanguageMngr.h"
#include <QScreen>
#include <QDesktopWidget>
#include <QApplication>
#include <QDebug>

HKMainFrameBase *g_HKMainFrame = nullptr;
long g_nComBoxItemHeight = 50;
long g_nComBoxVertScrollWidth = 30;
long g_nTableVertScrollWidth = 30;
long g_nTableHorizontalScrollHeight = 30;
QFont *g_pSttGlobalFont = nullptr;

HKMainFrameBase::HKMainFrameBase(QWidget *parent, CString strConfigFile)
: QMainWindow(parent)
{
    m_pMainConfig = nullptr;
    g_HKMainFrame = this;
    g_pSttWgtCmdMainWindow = this;
	m_gFont = font();
	g_pSttGlobalFont = &m_gFont;
	InitResource();
	InitUI(strConfigFile);
}

HKMainFrameBase::~HKMainFrameBase()
{
    g_pSttWgtCmdMainWindow = nullptr;
	ReleaseResource();
}

void HKMainFrameBase::InitResource()
{
	CLogPrint::Create(this);
	CSttXMainConfigXmlRWKeys::Create();
}

void HKMainFrameBase::ReleaseResource()
{
	CSttXMainConfigXmlRWKeys::Release();
    CLogPrint::SetLog(nullptr);
	CLogPrint::Release();
}

void HKMainFrameBase::InitUI(CString strConfigFile)
{
	QSize size(1024, 768);
	resize(1024,768);
	setMaximumSize(size);
    setMinimumSize(size);
	setWindowFlags(Qt::FramelessWindowHint);

	CString strFile = _P_GetConfigPath();
	if(strConfigFile.GetLength())
	{
		strFile += strConfigFile;
	}
	else
	{
		strFile += "SttXMainConfig.xml";
	}

	m_pMainConfig = new CSttXuiDataMainConfig();
	if(!m_pMainConfig->OpenXmlFile(strFile, CSttXMainConfigXmlRWKeys::g_pXmlKeys))
	{
		return;
	}

	g_dStartupDelayTime =  m_pMainConfig->m_dStartupDelayTime;

	if(strConfigFile.GetLength())
	{
		xlang_TranslateByResourceFileEx(m_pMainConfig, strConfigFile);
	}
	else
	{
		xlang_TranslateByResourceFileEx(m_pMainConfig, _T("SttXMainConfig.xml"));
	}

	if(m_pMainConfig->m_nCx && m_pMainConfig->m_nCy)
	{
		QSize sizeNew(m_pMainConfig->m_nCx * g_dUIShowCoef, m_pMainConfig->m_nCy* g_dUIShowCoef);
		setMaximumSize(sizeNew);
        setMinimumSize(sizeNew);
	}

    HKWgtLinux* p = new HKWgtLinux();
	p->InitUI(strFile, m_pMainConfig);
	setCentralWidget(p);
}

void HKMainFrameBase::CreateCloseHidingBtns()
{
	//创建最小化以及关闭按钮
	QRect rc = geometry();
	QSize szBtn = QSize(36, 24);
	long nX = rc.right() - szBtn.width();
	QPushButton* pBtn = new QPushButton(this);
	pBtn->setText(QString::fromLocal8Bit("×"));//dingxy 20240729 解决乱码问题
	pBtn->setGeometry(nX, 0, szBtn.width(), szBtn.height());
	pBtn->setStyleSheet("QPushButton{border:0px solid white; color: white; background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #058a93, stop: 0.4 #06a1ac, stop: 0.5 #06a1ac, stop: 1.0 #058a93);}"
		"QPushButton:hover{border:1px solid white;background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ff0000, stop: 0.4 #ff8080, stop: 0.5 #ff8080, stop: 1.0 #ff0000);}");
	connect(pBtn, SIGNAL(clicked()), this, SLOT(slot_CloseApp()));
	nX = nX - szBtn.width();
	pBtn = new QPushButton(this);
	pBtn->setText(QString::fromLocal8Bit("—"));
	pBtn->setStyleSheet("QPushButton{border:0px solid white; color: white; background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #058a93, stop: 0.4 #06a1ac, stop: 0.5 #06a1ac, stop: 1.0 #058a93);}"
		"QPushButton:hover{border:1px solid white;background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #4d4dff, stop: 0.4 #9a9aff, stop: 0.5 #9a9aff, stop: 1.0 #4d4dff);}");
	pBtn->setGeometry(nX, 0, szBtn.width(), szBtn.height());
	connect(pBtn, SIGNAL(clicked()), this, SLOT(slot_HideApp()));
}

void HKMainFrameBase::CreateCloseBtns()
{
    //创建关闭按钮
    QRect rc = geometry();
    QSize szBtn = QSize(36, 24);
    long nX = rc.right() - szBtn.width();
    QPushButton* pBtn = new QPushButton(this);
    //pBtn->setText("×");
    pBtn->setText(QString::fromLocal8Bit("×"));//dingxy 20240729 解决乱码问题
    pBtn->setGeometry(nX, 0, szBtn.width(), szBtn.height());
    pBtn->setStyleSheet("QPushButton{border:0px solid white; color: white; background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #058a93, stop: 0.4 #06a1ac, stop: 0.5 #06a1ac, stop: 1.0 #058a93);}"
        "QPushButton:hover{border:1px solid white;background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ff0000, stop: 0.4 #ff8080, stop: 0.5 #ff8080, stop: 1.0 #ff0000);}");
    connect(pBtn, SIGNAL(clicked()), this, SLOT(slot_CloseApp()));
}

void HKMainFrameBase::slot_CloseApp()
{
	close();
}

void HKMainFrameBase::slot_HideApp()
{
	showMinimized();
}
