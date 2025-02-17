
// DsvTest.cpp : ����Ӧ�ó��������Ϊ��
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
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// ��׼��ӡ��������
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
END_MESSAGE_MAP()


// CDsvTestApp ����

CDsvTestApp::CDsvTestApp()
{

	m_bHiColorIcons = TRUE;

	SYSTEMTIME tm;
	::GetLocalTime(&tm);

	SYSTEMTIME tm2;
	::GetSystemTime(&tm2);

	m_pDsvTestFormView = NULL;
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CDsvTestApp ����

CDsvTestApp theApp;


// CDsvTestApp ��ʼ��

BOOL CDsvTestApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	_P_InitSystemPath();
	CDataMngrXmlRWKeys::Create();
	InitDsvScript();

	AfxEnableControlContainer();
	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_P_GetCompany());
	LoadStdProfileSettings(4);  // ���ر�׼ INI �ļ�ѡ��(���� MRU)

	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// ע��Ӧ�ó�����ĵ�ģ�塣�ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CDsvTestDoc),
		RUNTIME_CLASS(CMainFrame),       // �� SDI ��ܴ���
		RUNTIME_CLASS(CDsvTestFormView));
// 	RUNTIME_CLASS(CDsvTestView));

	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);



	// ������׼������DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	// ��������������ָ����������
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// �������к�׺ʱ�ŵ��� DragAcceptFiles
	//  �� SDI Ӧ�ó����У���Ӧ�� ProcessShellCommand ֮����


	return TRUE;
}



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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

// �������жԻ����Ӧ�ó�������
void CDsvTestApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CDsvTestApp �Զ������/���淽��

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

// CDsvTestApp ��Ϣ�������




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
