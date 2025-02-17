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

// ChildFrm.cpp : CChildFrame ���ʵ��
//

#include "stdafx.h"
#include "CharLibDev.h"

#include "ChildFrm.h"
#include "CharEditDlg.h"
#include "MainFrm.h"
#include "XLanguageResourceAts_CharLibDev.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWndEx)
	ON_WM_CLOSE()
	ON_COMMAND(ID_CHAROPTR_EDIT, &CChildFrame::OnCharoptrEdit)
	ON_UPDATE_COMMAND_UI(ID_CHAROPTR_EDIT, &CChildFrame::OnUpdateCharoptrEdit)
END_MESSAGE_MAP()

// CChildFrame ����/����

CChildFrame::CChildFrame()
{
	m_pCurrCharTemp = NULL;
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ��������ʽ
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// CChildFrame ���

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// CChildFrame ��Ϣ�������

void CChildFrame::OnClose()
{
	theApp.CloseCharTempFrame(this);

	CMDIChildWndEx::OnClose();
}

void CChildFrame::OnCharoptrEdit()
{
	CCharEditDlg dlg;
	dlg.m_strTitle = CXLanguageResourceAts_CharLibDev::g_sLangTxt_NewCharCurve/*_T("�½���������")*/;
	dlg.m_pCharTemp = m_pCurrCharTemp;
	dlg.m_pCurrFolder = (CCharacterFolder *)m_pCurrCharTemp->GetParent();

	if (dlg.DoModal() == IDOK)
	{
		CMainFrame *pMainFrame = (CMainFrame*)theApp.m_pMainWnd;
		m_pCurrCharTemp->m_strName = dlg.m_strName;
		m_pCurrCharTemp->m_strID   = dlg.m_strID;
		m_pCurrCharTemp->m_strAxis = dlg.m_strAxis;
		m_pCurrCharTemp->m_strTestLineMode = dlg.m_strTestLineMode;
		m_pCurrCharTemp->m_strXMin = dlg.m_strXMin;
		m_pCurrCharTemp->m_strXMax = dlg.m_strXMax;
		m_pCurrCharTemp->m_strYMin = dlg.m_strYMin;
		m_pCurrCharTemp->m_strYMax = dlg.m_strYMax;

		pMainFrame->UpdateCharTemp(m_pCurrCharTemp);
		CView *pView = GetActiveView();
		CDocument *pDoc = pView->GetDocument();
		pDoc->SetTitle(m_pCurrCharTemp->m_strName);
	}
	
}

void CChildFrame::OnUpdateCharoptrEdit(CCmdUI *pCmdUI)
{
	
}
