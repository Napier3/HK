
// DsvTest.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "DsvTest.h"
#include "MainFrm.h"

#include "DsvTestDoc.h"
#include "DsvTestView.h"
#include "DsvTestFormView.h"

#include "..\..\Module\DataMngr\DataMngrGlobal.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDsvTestApp

BEGIN_MESSAGE_MAP(CDsvTestApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CDsvTestApp::OnAppAbout)
	// 基于文件的标准文档命令
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// 标准打印设置命令
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
END_MESSAGE_MAP()


// CDsvTestApp 构造

CDsvTestApp::CDsvTestApp()
{

	m_bHiColorIcons = TRUE;

	SYSTEMTIME tm;
	::GetLocalTime(&tm);

	SYSTEMTIME tm2;
	::GetSystemTime(&tm2);

	m_pDsvTestFormView = NULL;
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

// 唯一的一个 CDsvTestApp 对象

CDsvTestApp theApp;


// CDsvTestApp 初始化

BOOL CDsvTestApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	// 初始化 OLE 库
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	_P_InitSystemPath();
	CDataMngrXmlRWKeys::Create();
	InitDsvScript();

	AfxEnableControlContainer();
	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_P_GetCompany());
	LoadStdProfileSettings(4);  // 加载标准 INI 文件选项(包括 MRU)

	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// 注册应用程序的文档模板。文档模板
	// 将用作文档、框架窗口和视图之间的连接
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CDsvTestDoc),
		RUNTIME_CLASS(CMainFrame),       // 主 SDI 框架窗口
		RUNTIME_CLASS(CDsvTestFormView));
// 	RUNTIME_CLASS(CDsvTestView));

	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);



	// 分析标准外壳命令、DDE、打开文件操作的命令行
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	// 调度在命令行中指定的命令。如果
	// 用 /RegServer、/Register、/Unregserver 或 /Unregister 启动应用程序，则返回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// 唯一的一个窗口已初始化，因此显示它并对其进行更新
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// 仅当具有后缀时才调用 DragAcceptFiles
	//  在 SDI 应用程序中，这应在 ProcessShellCommand 之后发生


	return TRUE;
}



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// 用于运行对话框的应用程序命令
void CDsvTestApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CDsvTestApp 自定义加载/保存方法

void CDsvTestApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	bNameValid = strName.LoadString(IDS_EXPLORER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CDsvTestApp::LoadCustomState()
{
}

void CDsvTestApp::SaveCustomState()
{
}

// CDsvTestApp 消息处理程序




int CDsvTestApp::ExitInstance()
{
	CDataMngrXmlRWKeys::Release();

	return CWinAppEx::ExitInstance();
}

void CDsvTestApp::InitDsvScript()
{
	if (m_oSoeForDsv.GetCount() > 0)
	{
		return;
	}

	CString strFile;
	strFile = _P_GetLibraryPath();
	strFile += _T("dsv-test\\DsvScript-only-soe.xml");
	m_oDsvScript.OpenXmlFile(strFile, CDataMngrXmlRWKeys::CDsvScriptKey(), CDataMngrXmlRWKeys::g_pXmlKeys);

	strFile = _P_GetLibraryPath();
	strFile += _T("dsv-test\\LLN0$dsTripInfo.xml");
	m_oDataSet.OpenXmlFile(strFile, CDataMngrXmlRWKeys::CDvmDatasetKey(), CDataMngrXmlRWKeys::g_pXmlKeys);

	strFile = _P_GetLibraryPath();
	strFile += _T("dsv-test\\LLN0$dsTripInfo_SOE.xml");
	m_oSoeForDsv.OpenXmlFile(strFile, CDataMngrXmlRWKeys::CDvmDatasetKey(), CDataMngrXmlRWKeys::g_pXmlKeys);

}
