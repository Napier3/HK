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

// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "CharLibDev.h"

#include "MainFrm.h"
#include "CharEditDlg.h"
#include "DlgImportCharFromRioFile.h"
#include "..\..\Module\XLanguage\XLangRibbonCtrls.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWndEx)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND(ID_WINDOW_MANAGER, &CMainFrame::OnWindowManager)
	ON_COMMAND_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_OFF_2007_AQUA, &CMainFrame::OnApplicationLook)
	ON_UPDATE_COMMAND_UI_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_OFF_2007_AQUA, &CMainFrame::OnUpdateApplicationLook)
	ON_COMMAND(ID_CHAROPTR_NEWCHAR, &CMainFrame::OnCharoptrNewchar)
	ON_COMMAND(ID_CHAROPTR_SAVE, &CMainFrame::OnCharoptrSave)
	ON_UPDATE_COMMAND_UI(ID_CHAROPTR_SAVE, &CMainFrame::OnUpdateCharoptrSave)
	ON_COMMAND(ID_CHAROPTR_SAVEAS, &CMainFrame::OnCharoptrSaveas)
	ON_UPDATE_COMMAND_UI(ID_CHAROPTR_SAVEAS, &CMainFrame::OnUpdateCharoptrSaveas)
	ON_COMMAND(ID_CHAROPTR_DELETE, &CMainFrame::OnCharoptrDelete)
	ON_UPDATE_COMMAND_UI(ID_CHAROPTR_DELETE, &CMainFrame::OnUpdateCharoptrDelete)
	ON_COMMAND(ID_CHAROPTR_EXPORT, &CMainFrame::OnCharoptrExport)
	ON_UPDATE_COMMAND_UI(ID_CHAROPTR_EXPORT, &CMainFrame::OnUpdateCharoptrExport)
	ON_COMMAND(ID_VIEW_CHARPANE, &CMainFrame::OnViewCharpane)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CHARPANE, &CMainFrame::OnUpdateViewCharpane)
	ON_COMMAND(ID_VIEW_OUTPUTWND, &CMainFrame::OnViewOutputwnd)
	ON_UPDATE_COMMAND_UI(ID_VIEW_OUTPUTWND, &CMainFrame::OnUpdateViewOutputwnd)
	ON_WM_CLOSE()
	ON_COMMAND(ID_CHAROPTR_IMPORTFROMRIOFILE, &CMainFrame::OnCharoptrImportfromriofile)
END_MESSAGE_MAP()

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
	theApp.m_nAppLook = theApp.GetInt(_T("ApplicationLook"), ID_VIEW_APPLOOK_VS_2005);
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	BOOL bNameValid;
	// ���ڳ־�ֵ�����Ӿ�����������ʽ
	OnApplicationLook(theApp.m_nAppLook);

	CMDITabInfo mdiTabParams;
	mdiTabParams.m_style = CMFCTabCtrl::STYLE_3D_ONENOTE; // ����������ʽ...
	mdiTabParams.m_bActiveTabCloseButton = TRUE;      // ����Ϊ FALSE �Ὣ�رհ�ť������ѡ�������Ҳ�
	mdiTabParams.m_bTabIcons = FALSE;    // ����Ϊ TRUE ���� MDI ѡ��������ĵ�ͼ��
	mdiTabParams.m_bAutoColor = TRUE;    // ����Ϊ FALSE ������ MDI ѡ����Զ���ɫ
	mdiTabParams.m_bDocumentMenu = TRUE; // ��ѡ�������ұ�Ե�����ĵ��˵�
	EnableMDITabbedGroups(TRUE, mdiTabParams);

	m_wndRibbonBar.Create(this);
	InitializeRibbon();

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}

	CString strTitlePane1;
	CString strTitlePane2;
	bNameValid = strTitlePane1.LoadString(IDS_STATUS_PANE1);
	ASSERT(bNameValid);
	bNameValid = strTitlePane2.LoadString(IDS_STATUS_PANE2);
	ASSERT(bNameValid);
	m_wndStatusBar.AddElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE1, strTitlePane1, TRUE), strTitlePane1);
	m_wndStatusBar.AddExtendedElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE2, strTitlePane2, TRUE), strTitlePane2);

	// ���� Visual Studio 2005 ��ʽͣ��������Ϊ
	CDockingManager::SetDockingMode(DT_SMART);
	// ���� Visual Studio 2005 ��ʽͣ�������Զ�������Ϊ
	EnableAutoHidePanes(CBRS_ALIGN_ANY);

	// ���ز˵���ͼ��(�����κα�׼��������):
	CMFCToolBar::AddToolBarForImageCollection(IDR_MENU_IMAGES, theApp.m_bHiColorIcons ? IDB_MENU_IMAGES_24 : 0);

	// ����ͣ������
	if (!CreateDockingWindows())
	{
		TRACE0("δ�ܴ���ͣ������\n");
		return -1;
	}

	m_wndCharLibView.EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndCharLibView);
	m_wndOutput.EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndOutput);


	// ������ǿ�Ĵ��ڹ���Ի���
	EnableWindowsDialog(ID_WINDOW_MANAGER, IDS_WINDOWS_MANAGER, TRUE);

	m_wndCharLibView.ShowCharLib();
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWndEx::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

void CMainFrame::InitializeRibbon()
{
	BOOL bNameValid;

	CString strTemp;
	bNameValid = strTemp.LoadString(IDS_RIBBON_FILE);
	ASSERT(bNameValid);

	// �������ͼ��:
	m_PanelImages.SetImageSize(CSize(16, 16));
	m_PanelImages.Load(IDB_BUTTONS);

	// ��ʼ����ť:
	m_MainButton.SetImage(IDB_MAIN);
	m_MainButton.SetText(_T("\nf"));
	m_MainButton.SetToolTipText(CXLanguageResourceAts_CharLibDev::g_sLangTxt_File1);

	m_wndRibbonBar.SetApplicationButton(&m_MainButton, CSize (45, 45));
	CMFCRibbonMainPanel* pMainPanel = m_wndRibbonBar.AddMainCategory(strTemp, IDB_FILESMALL, IDB_FILELARGE);

	bNameValid = strTemp.LoadString(IDS_RIBBON_NEW);
	ASSERT(bNameValid);
	pMainPanel->Add(new CXLangRibbonButton(ID_FILE_NEW, CXLanguageResourceAts_CharLibDev::g_sLangTxt_NewFileCreat/*strTemp*/,CXLanguageResourceAts_CharLibDev::g_sLangTxt_NewFileCreatTip, 0, 0));
	bNameValid = strTemp.LoadString(IDS_RIBBON_OPEN);
	ASSERT(bNameValid);
	pMainPanel->Add(new CXLangRibbonButton(ID_FILE_OPEN, CXLanguageResourceAts_CharLibDev::g_sLangTxt_Open0/*strTemp*/,CXLanguageResourceAts_CharLibDev::g_sLangTxt_Open0Tip, 1, 1));
	bNameValid = strTemp.LoadString(IDS_RIBBON_SAVE);
	ASSERT(bNameValid);
	pMainPanel->Add(new CXLangRibbonButton(ID_FILE_SAVE, CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveS/*strTemp*/,CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveSTip, 2, 2));
	bNameValid = strTemp.LoadString(IDS_RIBBON_SAVEAS);
	ASSERT(bNameValid);
	pMainPanel->Add(new CXLangRibbonButton(ID_FILE_SAVE_AS,CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveAsA /*strTemp*/,CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveAsATip, 3, 3));

	bNameValid = strTemp.LoadString(IDS_RIBBON_PRINT);
	ASSERT(bNameValid);
	CMFCRibbonButton* pBtnPrint = new CMFCRibbonButton(ID_FILE_PRINT, CXLanguageResourceAts_CharLibDev::g_sLangTxt_Print1/*strTemp*/, 6, 6);
	pBtnPrint->SetKeys(_T("p"), _T("w"));
	bNameValid = strTemp.LoadString(IDS_RIBBON_PRINT_LABEL);
	ASSERT(bNameValid);
	pBtnPrint->AddSubItem(new CMFCRibbonLabel(CXLanguageResourceAts_CharLibDev::g_sLangTxt_RePrintDoc/*strTemp*/));
	bNameValid = strTemp.LoadString(IDS_RIBBON_PRINT_QUICK);
	ASSERT(bNameValid);
	pBtnPrint->AddSubItem(new CMFCRibbonButton(ID_FILE_PRINT_DIRECT, CXLanguageResourceAts_CharLibDev::g_sLangTxt_PrintQuick/*strTemp*/, 7, 7, TRUE));
	bNameValid = strTemp.LoadString(IDS_RIBBON_PRINT_PREVIEW);
	ASSERT(bNameValid);
	pBtnPrint->AddSubItem(new CMFCRibbonButton(ID_FILE_PRINT_PREVIEW, CXLanguageResourceAts_CharLibDev::g_sLangTxt_PrintPre/*strTemp*/, 8, 8, TRUE));
	bNameValid = strTemp.LoadString(IDS_RIBBON_PRINT_SETUP);
	ASSERT(bNameValid);
	pBtnPrint->AddSubItem(new CMFCRibbonButton(ID_FILE_PRINT_SETUP, CXLanguageResourceAts_CharLibDev::g_sLangTxt_PrintSet/*strTemp*/, 11, 11, TRUE));
	pMainPanel->Add(pBtnPrint);
	pMainPanel->Add(new CMFCRibbonSeparator(TRUE));

	bNameValid = strTemp.LoadString(IDS_RIBBON_CLOSE);
	ASSERT(bNameValid);
	pMainPanel->Add(new CMFCRibbonButton(ID_FILE_CLOSE, CXLanguageResourceAts_CharLibDev::g_sLangTxt_FileClose1/*strTemp*/, 9, 9));

	bNameValid = strTemp.LoadString(IDS_RIBBON_RECENT_DOCS);
	ASSERT(bNameValid);
	pMainPanel->AddRecentFilesList(CXLanguageResourceAts_CharLibDev::g_sLangTxt_CurrentUseDoc/*strTemp*/);

	bNameValid = strTemp.LoadString(IDS_RIBBON_EXIT);
	ASSERT(bNameValid);
	pMainPanel->AddToBottom(new CXLangRibbonMainPanelButton(ID_APP_EXIT, CXLanguageResourceAts_CharLibDev::g_sLangTxt_Exit1/*strTemp*/,CXLanguageResourceAts_CharLibDev::g_sLangTxt_Exit1Tip, 15));

	CMFCRibbonCategory* pCategoryHome = m_wndRibbonBar.AddCategory(CXLanguageResourceAts_CharLibDev::g_sLangTxt_CharCurveOprt/*_T("�������߲���")*/, IDB_WRITESMALL, IDB_WRITELARGE);

	CMFCRibbonPanel* pPane = pCategoryHome->AddPanel(CXLanguageResourceAts_CharLibDev::g_sLangTxt_CurveOprt/*_T("���߲���")*/, m_PanelImages.ExtractIcon(27));
	CMFCRibbonButton* pBtn = NULL;
	
	pBtn = new CXLangRibbonButton(ID_CHAROPTR_NEWCHAR, CXLanguageResourceAts_CharLibDev::g_sLangTxt_NewCurve/*_T("�½�����")*/,CXLanguageResourceAts_CharLibDev::g_sLangTxt_NewCurveTip, 0, 0);
	pPane->Add(pBtn);
	pBtn = new CXLangRibbonButton(ID_CHAROPTR_IMPORTFROMRIOFILE, CXLanguageResourceAts_CharLibDev::g_sLangTxt_ImportCurve, CXLanguageResourceAts_CharLibDev::g_sLangTxt_ImportCurveTip, 8, 8);
	pPane->Add(pBtn);
	pBtn = new CXLangRibbonButton(ID_CHAROPTR_SAVE, CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveCurve/*_T("��������")*/,CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveCurveTip, 1, 1);
	pPane->Add(pBtn);
	pBtn = new CXLangRibbonButton(ID_CHAROPTR_SAVEAS,  CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveAsCurve/*_T("�������Ϊ")*/,CXLanguageResourceAts_CharLibDev::g_sLangTxt_SaveAsCurveTip, 2, 2);
	pPane->Add(pBtn);
	pBtn = new CXLangRibbonButton(ID_CHAROPTR_DELETE, CXLanguageResourceAts_CharLibDev::g_sLangTxt_DeleteCurve/*_T("ɾ������")*/,CXLanguageResourceAts_CharLibDev::g_sLangTxt_DeleteCurveTip, 3, 3);
	pPane->Add(pBtn);
	pBtn = new CXLangRibbonButton(ID_CHAROPTR_EXPORT, CXLanguageResourceAts_CharLibDev::g_sLangTxt_ExportCurve/*_T("��������")*/,CXLanguageResourceAts_CharLibDev::g_sLangTxt_ExportCurveTip, 4, 4);
	pPane->Add(pBtn);
	pBtn = new CXLangRibbonButton(ID_CHAROPTR_EDIT,  CXLanguageResourceAts_CharLibDev::g_sLangTxt_ModifyCurve/*_T("�޸�����")*/,CXLanguageResourceAts_CharLibDev::g_sLangTxt_ModifyCurveTip, 7, 7);
	pPane->Add(pBtn);

	pPane = pCategoryHome->AddPanel(CXLanguageResourceAts_CharLibDev::g_sLangTxt_View/*_T("��ͼ")*/, m_PanelImages.ExtractIcon(27));
	pBtn = new CXLangRibbonCheckBox(ID_VIEW_CHARPANE, CXLanguageResourceAts_CharLibDev::g_sLangTxt_CurveBar/*_T("������")*/,CXLanguageResourceAts_CharLibDev::g_sLangTxt_CurveBarTip);
	pPane->Add(pBtn);
	pBtn = new CXLangRibbonCheckBox(ID_VIEW_OUTPUTWND, CXLanguageResourceAts_CharLibDev::g_sLangTxt_OutputBar1/*_T("�����")*/,CXLanguageResourceAts_CharLibDev::g_sLangTxt_OutputBar1Tip);
	pPane->Add(pBtn);

	pPane = pCategoryHome->AddPanel(CXLanguageResourceAts_CharLibDev::g_sLangTxt_HelpAbout /*_T("����")*/, m_PanelImages.ExtractIcon(27));
	pBtn = new CXLangRibbonButton(ID_APP_ABOUT,CXLanguageResourceAts_CharLibDev::g_sLangTxt_About1 /* _T("����")*/,CXLanguageResourceAts_CharLibDev::g_sLangTxt_About1Tip, 5, 5);
	pPane->Add(pBtn);
	pBtn = new CXLangRibbonButton(ID_APP_EXIT, CXLanguageResourceAts_CharLibDev::g_sLangTxt_Exit1/*_T("�˳�")*/,CXLanguageResourceAts_CharLibDev::g_sLangTxt_Exit1Tip, 6, 6);
	pPane->Add(pBtn);

	// ��Ԫ����ӵ�ѡ��Ҳ�:
	bNameValid = strTemp.LoadString(IDS_RIBBON_STYLE);
	ASSERT(bNameValid);
	CMFCRibbonButton* pVisualStyleButton = new CMFCRibbonButton(-1, CXLanguageResourceAts_CharLibDev::g_sLangTxt_Style/*strTemp*/, -1, -1);

	pVisualStyleButton->SetMenu(IDR_THEME_MENU, FALSE /* ��Ĭ������*/, TRUE /* �Ҷ���*/);

	bNameValid = strTemp.LoadString(IDS_RIBBON_STYLE_TIP);
	ASSERT(bNameValid);
	pVisualStyleButton->SetToolTipText(CXLanguageResourceAts_CharLibDev::g_sLangTxt_StyleTip1);
	bNameValid = strTemp.LoadString(IDS_RIBBON_STYLE_DESC);
	ASSERT(bNameValid);
	pVisualStyleButton->SetDescription(CXLanguageResourceAts_CharLibDev::g_sLangTxt_StyleTip2/*strTemp*/);
	m_wndRibbonBar.AddToTabs(pVisualStyleButton);

	// ��ӿ��ٷ��ʹ���������:
	CList<UINT, UINT> lstQATCmds;

	lstQATCmds.AddTail(ID_FILE_NEW);
	lstQATCmds.AddTail(ID_FILE_OPEN);
	lstQATCmds.AddTail(ID_FILE_SAVE);
	lstQATCmds.AddTail(ID_FILE_PRINT_DIRECT);

	m_wndRibbonBar.SetQuickAccessCommands(lstQATCmds);

	m_wndRibbonBar.AddToTabs(new CXLangRibbonButton(ID_APP_ABOUT, CXLanguageResourceAts_CharLibDev::g_sLangTxt_About1/*_T("\na")*/,CXLanguageResourceAts_CharLibDev::g_sLangTxt_About1Tip, m_PanelImages.ExtractIcon (0)));
}

BOOL CMainFrame::CreateDockingWindows()
{
	BOOL bNameValid;

	// ��������ͼ
	CString strCharLibView;
	bNameValid = strCharLibView.LoadString(IDS_CLASS_VIEW);
	ASSERT(bNameValid);
	if (!m_wndCharLibView.Create(CXLanguageResourceAts_CharLibDev::g_sLangTxt_ClassView/*strCharLibView*/, this, CRect(0, 0, 200, 200), TRUE, ID_VIEW_CLASSVIEW, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI))
	{
		TRACE0("δ�ܴ���������ͼ������\n");
		return FALSE; // δ�ܴ���
	}

	// �����������
	CString strOutputWnd;
	bNameValid = strOutputWnd.LoadString(IDS_OUTPUT_WND);
	ASSERT(bNameValid);
	if (!m_wndOutput.Create(CXLanguageResourceAts_CharLibDev::g_sLangTxt_OutPut/*strOutputWnd*/, this, CRect(0, 0, 100, 100), TRUE, ID_VIEW_OUTPUTWND, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_BOTTOM | CBRS_FLOAT_MULTI))
	{
		TRACE0("δ�ܴ����������\n");
		return FALSE; // δ�ܴ���
	}

	SetDockingWindowIcons(theApp.m_bHiColorIcons);
	return TRUE;
}

void CMainFrame::SetDockingWindowIcons(BOOL bHiColorIcons)
{
	HICON hCharLibViewIcon = (HICON) ::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(bHiColorIcons ? IDI_CLASS_VIEW_HC : IDI_CLASS_VIEW), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), 0);
	m_wndCharLibView.SetIcon(hCharLibViewIcon, FALSE);

	HICON hOutputBarIcon = (HICON) ::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(bHiColorIcons ? IDI_OUTPUT_WND_HC : IDI_OUTPUT_WND), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), 0);
	m_wndOutput.SetIcon(hOutputBarIcon, FALSE);

	UpdateMDITabbedBarsIcons();
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������

void CMainFrame::OnWindowManager()
{
	ShowWindowsDialog();
}

void CMainFrame::OnApplicationLook(UINT id)
{
	CWaitCursor wait;

	theApp.m_nAppLook = id;

	switch (theApp.m_nAppLook)
	{
	case ID_VIEW_APPLOOK_WIN_2000:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManager));
		break;

	case ID_VIEW_APPLOOK_OFF_XP:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOfficeXP));
		break;

	case ID_VIEW_APPLOOK_WIN_XP:
		CMFCVisualManagerWindows::m_b3DTabsXPTheme = TRUE;
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
		break;

	case ID_VIEW_APPLOOK_OFF_2003:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2003));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	case ID_VIEW_APPLOOK_VS_2005:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2005));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	default:
		switch (theApp.m_nAppLook)
		{
		case ID_VIEW_APPLOOK_OFF_2007_BLUE:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_LunaBlue);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_BLACK:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_ObsidianBlack);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_SILVER:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Silver);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_AQUA:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Aqua);
			break;
		}

		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));
		CDockingManager::SetDockingMode(DT_SMART);
	}

	RedrawWindow(NULL, NULL, RDW_ALLCHILDREN | RDW_INVALIDATE | RDW_UPDATENOW | RDW_FRAME | RDW_ERASE);

	theApp.WriteInt(_T("ApplicationLook"), theApp.m_nAppLook);
}

void CMainFrame::OnUpdateApplicationLook(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(theApp.m_nAppLook == pCmdUI->m_nID);
}

void CMainFrame::OnCharoptrNewchar()
{
	CCharEditDlg dlg;
	dlg.m_strTitle = CXLanguageResourceAts_CharLibDev::g_sLangTxt_ModifyCharCurve/*_T("�޸���������")*/;
	CCharacteristic *pCharTemp = new CCharacteristic();
	CCharacterFolder *pCurrFolder = m_wndCharLibView.GetCurrSelFolder();
	dlg.m_pCurrFolder = (CCharacterFolder *)pCurrFolder;
	pCharTemp->InitAfterRead();
	dlg.m_pCharTemp = pCharTemp;

	if (dlg.DoModal() == IDOK)
	{
		pCharTemp->m_strName = dlg.m_strName;
		pCharTemp->m_strID   = dlg.m_strID;
		pCharTemp->m_strAxis = dlg.m_strAxis;
		pCharTemp->m_strTestLineMode = dlg.m_strTestLineMode;
		pCharTemp->m_strXMin = dlg.m_strXMin;
		pCharTemp->m_strXMax = dlg.m_strXMax;
		pCharTemp->m_strYMin = dlg.m_strYMin;
		pCharTemp->m_strYMax = dlg.m_strYMax;

		pCurrFolder->AddNewChild(pCharTemp);
		m_wndCharLibView.InsertCharTemp(pCharTemp);
		theApp.OpenCharTemplate(pCharTemp);
	}
	else
	{
		delete pCharTemp;
	}
}

void CMainFrame::OnCharoptrSave()
{
	theApp.m_oCharacteristicLib.SaveCharLibFile(_T(""));
	char_dev_SetModifiedFlag(&theApp.m_oCharacteristicLib, FALSE);
}

void CMainFrame::OnUpdateCharoptrSave(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
}

void CMainFrame::OnCharoptrSaveas()
{
	// TODO: �ڴ���������������
}

void CMainFrame::OnUpdateCharoptrSaveas(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
}

void CMainFrame::OnCharoptrDelete()
{
	// TODO: �ڴ���������������
}

void CMainFrame::OnUpdateCharoptrDelete(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
}

void CMainFrame::OnCharoptrExport()
{
	// TODO: �ڴ���������������
}

void CMainFrame::OnUpdateCharoptrExport(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
}

void CMainFrame::OnViewCharpane()
{
	if (m_wndCharLibView.IsVisible())
	{
		m_wndCharLibView.ShowPane(FALSE, FALSE, FALSE);
	}
	else
	{
		m_wndCharLibView.ShowPane(TRUE, FALSE, TRUE);
	}
}

void CMainFrame::OnUpdateViewCharpane(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_wndCharLibView.IsVisible());
}

void CMainFrame::OnViewOutputwnd()
{
	if (m_wndOutput.IsVisible())
	{
		m_wndOutput.ShowPane(FALSE, FALSE, FALSE);
	}
	else
	{
		m_wndOutput.ShowPane(TRUE, FALSE, TRUE);
	}
}

void CMainFrame::OnUpdateViewOutputwnd(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_wndOutput.IsVisible());
}

void CMainFrame::UpdateCharTemp(CCharacteristic *pCharTemp)
{
	m_wndCharLibView.UpdateCharTemp(pCharTemp);
}
void CMainFrame::OnClose()
{
	if (!char_dev_GetModifiedFlag(&theApp.m_oCharacteristicLib))
	{
		CMDIFrameWndEx::OnClose();
		return;
	}

	int nRet = MessageBox(CXLanguageResourceAts_CharLibDev::g_sLangTxt_CharCurveSave/*_T("�������߿��Ѿ����޸ģ��Ƿ񱣴��޸ģ�")*/,CXLanguageResourceAts_CharLibDev::g_sLangTxt_Message1/*_T("��ʾ")*/,MB_YESNOCANCEL|MB_ICONQUESTION);

	switch(nRet)
	{
	case IDYES:
		theApp.m_oCharacteristicLib.SaveCharLibFile(_T(""));
		break;
	case IDNO:
		break;
	case IDCANCEL:
		return;
	}

	CMDIFrameWndEx::OnClose();
}

void CMainFrame::OnCharoptrImportfromriofile()
{
	CDlgImportCharFromRioFile dlgImport;

	if (dlgImport.DoModal() != IDOK)
	{
		return;
	}

	CCharEditDlg dlgEdit;
	dlgEdit.m_strTitle = CXLanguageResourceAts_CharLibDev::g_sLangTxt_ModifyCharCurve/*_T("�޸���������")*/;
	CCharacteristic *pCharTemp = dlgImport.m_pCharacteristic;
	CCharacterFolder *pCurrFolder = m_wndCharLibView.GetCurrSelFolder();
	dlgEdit.m_pCurrFolder = (CCharacterFolder *)pCurrFolder;
	pCharTemp->InitAfterRead();
	dlgEdit.m_pCharTemp = pCharTemp;

	dlgEdit.DoModal();
	
	pCharTemp->m_strName = dlgEdit.m_strName;
	pCharTemp->m_strID   = dlgEdit.m_strID;
	pCharTemp->m_strAxis = dlgEdit.m_strAxis;
	pCharTemp->m_strTestLineMode = dlgEdit.m_strTestLineMode;
	pCharTemp->m_strXMin = dlgEdit.m_strXMin;
	pCharTemp->m_strXMax = dlgEdit.m_strXMax;
	pCharTemp->m_strYMin = dlgEdit.m_strYMin;
	pCharTemp->m_strYMax = dlgEdit.m_strYMax;

	pCurrFolder->AddNewChild(pCharTemp);
	m_wndCharLibView.InsertCharTemp(pCharTemp);
	theApp.OpenCharTemplate(pCharTemp);
}
