// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// ("Fluent UI")����ʾ������Ϊ�ο������ṩ�� 
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://msdn.microsoft.com/officeui��
//
// ��Ȩ���� (C) Microsoft Corporation
// ��������Ȩ����

// CharLibDev.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "CharLibDev.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "CharLibDevDoc.h"
#include "CharLibDevView.h"
#include "afxcmn.h"
#include "..\..\Module\XMinidmp\XMinidmp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////////
BOOL CharVar_CalScriptValue(CCharInterfaceVariable *pCharVar)
{
	return FALSE;
}

CExBaseObject* CharVar_GetScriptValObj(CCharInterfaceVariable *pCharVar)
{
	return NULL;
}

CString* CharVar_CalScriptValue(CExBaseObject *pData)
{
	return &pData->m_strID;
}

void CharVar_CalScriptValue(CExBaseObject *pData, CString &strValue)
{

}


// CCharLibDevApp

BEGIN_MESSAGE_MAP(CCharLibDevApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CCharLibDevApp::OnAppAbout)
	// �����ļ��ı�׼�ĵ�����
	//ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	//ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
END_MESSAGE_MAP()


// CCharLibDevApp ����

CCharLibDevApp::CCharLibDevApp()
{
	m_bHiColorIcons = TRUE;
	m_pDocTemplate = NULL;

}

// Ψһ��һ�� CCharLibDevApp ����

CCharLibDevApp theApp;


// CCharLibDevApp ��ʼ��

BOOL CCharLibDevApp::InitInstance()
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
	AfxEnableControlContainer();

	_P_InitSystemPath();
	RunCrashHandler();

	CXLanguageXmlRWKeys::Create();
	CXLanguageMngr::Create(new CXLanguageResourceAts_CharLibDev(),TRUE);

	CCharacteristicXmlRWKeys::Create();
	CDataMngrXmlRWKeys::Create();
	m_oCharacteristicLib.OpenCharLibFile(_T(""));
	char_dev_SetModifiedFlag(&m_oCharacteristicLib, FALSE);

	CCharacteristicLib::CreateGlobalCharAreaSrc();
	CDocFrameMngr::Create();
	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_P_GetCompany());
	LoadStdProfileSettings(0);  // ���ر�׼ INI �ļ�ѡ��

	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// ע��Ӧ�ó�����ĵ�ģ�塣�ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_CharLibDevTYPE,
		RUNTIME_CLASS(CCharLibDevDoc),
		RUNTIME_CLASS(CChildFrame), // �Զ��� MDI �ӿ��
		RUNTIME_CLASS(CCharLibDevView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);
	m_pDocTemplate = pDocTemplate;

	// ������ MDI ��ܴ���
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;
	// �������к�׺ʱ�ŵ��� DragAcceptFiles
	//  �� MDI Ӧ�ó����У���Ӧ������ m_pMainWnd ֮����������


	// ������׼������DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	cmdInfo.m_nShellCommand = cmdInfo.CCommandLineInfo::FileNothing;

	// ��������������ָ����������
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// �������ѳ�ʼ���������ʾ����������и���
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

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
public:
	virtual BOOL OnInitDialog();
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
void CCharLibDevApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CCharLibDevApp �Զ������/���淽��

void CCharLibDevApp::PreLoadState()
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

void CCharLibDevApp::LoadCustomState()
{
}

void CCharLibDevApp::SaveCustomState()
{
}

// CCharLibDevApp ��Ϣ�������




int CCharLibDevApp::ExitInstance()
{
	CCharacteristicXmlRWKeys::Release();
	CCharacteristicLib::ReleaseGlobalCharAreaSrc();

	CXLanguageXmlRWKeys::Release();
	CDataMngrXmlRWKeys::Release();
	CXLanguageMngr::Release();
	CDocFrameMngr::Release();

	return CWinAppEx::ExitInstance();
}

void CCharLibDevApp::OpenCharTemplate(CCharacteristic *pCharTemp)
{
	if (pCharTemp == NULL)
	{
		return;
	}

	CMDIChildWndEx *pFrame = CDocFrameMngr::FindDocFrame(pCharTemp);

	if (pFrame != NULL)
	{
		pFrame->ActivateFrame();
		return;
	}

	CLogPrint::LogFormatString(XLOGLEVEL_TRACE, _T("Open Characteristic[%s]"), pCharTemp->m_strName);
	CView *pView = NULL;
	CDocument *pDoc = docfrm_OpenDocTemplateEx(pCharTemp, m_pDocTemplate, &pView, &pFrame);
	pDoc->UpdateAllViews(NULL, (LPARAM)pCharTemp, NULL);
	pDoc->SetTitle(pCharTemp->m_strName);
	((CChildFrame*)pFrame)->m_pCurrCharTemp = pCharTemp;
}

void CCharLibDevApp::CloseCharTempFrame(CMDIChildWndEx *pFrame)
{
	CDocFrameMngr::CloseFrame(pFrame);
}


BOOL CAboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
