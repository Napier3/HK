#include "stdafx.h"  
#include "DynDialogEx.h"  

#ifdef _DEBUG  
#define new DEBUG_NEW  
#undef THIS_FILE  
static char THIS_FILE[] = __FILE__; 
#endif  

/////////////////////////////////////////////////////////////////////////////  
// CDynDialogEx dialog  


CDynDialogEx::CDynDialogEx(CWnd* pParent /*=NULL*/, BOOL bVisible) 
: CDialog() 
{ 
	//{{AFX_DATA_INIT(CDynDialogEx)  
	// NOTE: the ClassWizard will add member initialization here  
	//}}AFX_DATA_INIT  

	if (bVisible)
	{
		m_DialogTemplate.style= WS_CAPTION | WS_SYSMENU | WS_VISIBLE | DS_SETFONT; 
	}
	else
	{
		m_DialogTemplate.style= WS_CAPTION | WS_SYSMENU | DS_SETFONT; 
	}

	m_DialogTemplate.dwExtendedStyle = WS_EX_DLGMODALFRAME; 
	m_DialogTemplate.x= 0; 
	m_DialogTemplate.y= 0; 
	m_DialogTemplate.cx = 0; // 4 horizontal units are the width of one character  
	m_DialogTemplate.cy = 0; // 8 vertical units are the height of one character  
	m_DialogTemplate.cdit = 0;// nr of dialog items in the dialog  

	m_pParentWnd= pParent; 
	m_strCaption= _T(""); 
	m_pFont = NULL; 
	m_wFontSize = 0; 
	m_nCurRow = FIRSTROW1; 
	m_bAddSystemButtons = FALSE; 

	m_bIsFontCreated = FALSE; 
	m_bModelessDlg = FALSE; 
	m_bHasInitDialog = FALSE;

	LOGFONT LogFont; 
	memset(&LogFont, 0x00, sizeof(LogFont)); 
#ifdef _UNICODE
	wcscpy(LogFont.lfFaceName, _T("MS Sans Serif")); 
#else
	strcpy(LogFont.lfFaceName, _T("MS Sans Serif")); 
#endif
	LogFont.lfHeight = 9; 

	m_pFont = new CFont; 
	m_pFont->CreateFontIndirect(&LogFont); 
	m_bIsFontCreated = TRUE;
} 

CDynDialogEx::~CDynDialogEx() 
{ 
	CDynDialogItemEx *pDynDialogItemEx = NULL;

	for (int i = m_arrDlgItemPtr.GetSize() - 1; i >= 0; i--)
	{ 
		pDynDialogItemEx = m_arrDlgItemPtr[i]; 

		if (pDynDialogItemEx != NULL)
		{ 
			delete pDynDialogItemEx; 
			pDynDialogItemEx = NULL; 
		} 
	} 

	if (m_bIsFontCreated) 
	{ 
		delete m_pFont; 
	} 
} 

CWnd *CDynDialogEx::GetParent() 
{ 
	return m_pParentWnd; 
} 

void CDynDialogEx::AddStyles(DWORD dwStyles) 
{ 
	m_DialogTemplate.style |= dwStyles; 
} 

void CDynDialogEx::RemoveStyles(DWORD dwStyles) 
{ 
	m_DialogTemplate.style &= (~dwStyles); 
} 

void CDynDialogEx::DoDataExchange(CDataExchange* pDX) 
{ 
	CDialog::DoDataExchange(pDX); 
	//{{AFX_DATA_MAP(CDynDialogEx)  
	// NOTE: the ClassWizard will add DDX and DDV calls here  
	//}}AFX_DATA_MAP  

	CDynDialogItemEx *pDynDialogItemEx = NULL; 

	for (int i = m_arrDlgItemPtr.GetSize() - 1; i >= 0; i--) 
	{ 
		pDynDialogItemEx = m_arrDlgItemPtr[i]; 

		if (pDynDialogItemEx != NULL) 
		{ 
			pDynDialogItemEx->DoDataExchange(pDX); 
		} 
	} 
} 

BEGIN_MESSAGE_MAP(CDynDialogEx, CDialog) 
	//{{AFX_MSG_MAP(CDynDialogEx)  
	ON_WM_CREATE() 
	//}}AFX_MSG_MAP  
	ON_MESSAGE(WM_HELP, OnHelpMsg) 
	ON_WM_MEASUREITEM() // TMB! 06-12-2001 Adjusted.. was wrongly an ON_MESSAGE()!!  
	ON_WM_DRAWITEM()// TMB! 06-12-2001 Adjusted.. was wrongly an ON_MESSAGE()!!  
END_MESSAGE_MAP() 

/////////////////////////////////////////////////////////////////////////////  
// CDynDialogEx message handlers  

int CDynDialogEx::OnCreate(LPCREATESTRUCT lpCreateStruct)
{ 
	if (CDialog::OnCreate(lpCreateStruct) == -1) 
		return -1; 

	SetFont(m_pFont); 

	//Create all the controls on the dialog  
	CDynDialogItemEx *pDynDialogItemEx = NULL; 

	for (int i = 0; i < m_arrDlgItemPtr.GetSize(); i++)
	{ 
		pDynDialogItemEx = m_arrDlgItemPtr[i]; 

		if (pDynDialogItemEx != NULL)
		{ 
			if (!pDynDialogItemEx->IsDlgItemSubclassed())
			{ 
				if (!pDynDialogItemEx->CreateEx(this))
				{ 
					AfxMessageBox(_T("Failed to create DlgItem.")); 
				} 
				else if (pDynDialogItemEx->GetSafeHwnd() != NULL) 
				{ 
					pDynDialogItemEx->SetFont(m_pFont, FALSE); 
				} 
			} 
		} 
	} 

	return 0; 
} 

BOOL CDynDialogEx::OnInitDialog()
{ 
	//Reposition all the controls on the dialog...  
	CDynDialogItemEx *pDynDialogItemEx = NULL; 

	for (int i = 0; i < m_arrDlgItemPtr.GetSize(); i++) 
	{ 
		pDynDialogItemEx = m_arrDlgItemPtr[i]; 

		if (pDynDialogItemEx != NULL)
		{ 
			if (!pDynDialogItemEx->IsDlgItemSubclassed() && !pDynDialogItemEx->SetWindowPos(this)) 
			{ 
				CString strMessage; 
				strMessage.Format(_T("Failed SetWindowPos for control %s."), pDynDialogItemEx->GetClassName()); 
				AfxMessageBox(strMessage); 
			} 
		} 
	} 

	CDialog::OnInitDialog(); 

	CenterWindow(); 
	m_bHasInitDialog = TRUE;

	return TRUE;// return TRUE unless you set the focus to a control  
	// EXCEPTION: OCX Property Pages should return FALSE  
} 

int CDynDialogEx::DoModal()
{ 
	//Do we need OK and Cancel buttons    
	if (m_bAddSystemButtons) 
	{ 
		AddSystemButtons(); 
	} 

	//  
	// Get font info from mainwindow of the application  
	//  
	CFont* pParentFont = m_pFont; 
	if (pParentFont == NULL && m_pParentWnd != NULL) 
	{ 
		pParentFont = m_pParentWnd->GetFont(); 
	} 

	if (pParentFont == NULL && AfxGetApp()->m_pActiveWnd != NULL) 
	{ 
		pParentFont = AfxGetApp()->m_pActiveWnd->GetFont(); 
	} 

	LOGFONT LogFont; 
	memset(&LogFont, 0x00, sizeof(LogFont)); 

	if (pParentFont != NULL) 
	{ 
		pParentFont->GetLogFont(&LogFont); 
	} 
	else
	{ 
		// Can do better     
#ifdef _UNICODE
		wcscpy(LogFont.lfFaceName, _T("MS Sans Serif")); 
#else
		strcpy(LogFont.lfFaceName, _T("MS Sans Serif")); 
#endif

		LogFont.lfHeight = 8; 
	} 

	//Prework for setting font in dialog...  
	int cWC = 0;
#ifdef _UNICODE
	cWC = wcslen(LogFont.lfFaceName);// MultiByteToWideChar(CP_ACP, 0, LogFont.lfFaceName, -1, NULL, 0); 
#else
	BSTR bstrFaceName;
	CString strTemp;
	strTemp = LogFont.lfFaceName;
	bstrFaceName = strTemp.AllocSysString();
	cWC = wcslen(bstrFaceName);// MultiByteToWideChar(CP_ACP, 0, LogFont.lfFaceName, -1, NULL, 0); 
#endif

	int nFontNameLen = cWC+1; 
	// Copy the string  
	//MultiByteToWideChar(CP_ACP, 0, LogFont.lfFaceName, -1, (LPWSTR) szFontName, cWC); 
	
	WCHAR *szFontName = new WCHAR[nFontNameLen]; 
#ifdef _UNICODE
	wcscpy(szFontName, LogFont.lfFaceName);
#else
	wcscpy(szFontName, bstrFaceName);
	::SysFreeString(bstrFaceName);
#endif

	szFontName[cWC] = 0; 

	nFontNameLen = nFontNameLen * sizeof(WCHAR); 

	if (m_wFontSize == 0) 
	{ 
		m_wFontSize = (unsigned short)LogFont.lfHeight; 
	} 

	//Prework for setting caption in dialog...  
#ifdef _UNICODE
	cWC = m_strCaption.GetLength();//MultiByteToWideChar(CP_ACP, 0, m_strCaption, -1, NULL, 0); 
#else
	BSTR bstrCaption;
	bstrCaption = m_strCaption.AllocSysString();
	cWC = wcslen(bstrCaption);
#endif

	int szBoxLen = cWC + 1; 
	// Copy the string  
	//MultiByteToWideChar(CP_ACP, 0, m_strCaption, -1, (LPWSTR) szBoxCaption, cWC); 
	WCHAR *szBoxCaption = new WCHAR[szBoxLen]; 

#ifdef _UNICODE
	wcscpy(szBoxCaption, m_strCaption);
#else
	wcscpy(szBoxCaption, bstrCaption);
	::SysFreeString(bstrCaption);
#endif

	szBoxCaption[cWC] = 0; 

	szBoxLen = szBoxLen * sizeof(WCHAR); 

	int iRet = -1; 
	//Here 's the stuff to build the dialog template in memory  
	//without the controls being in the template  
	//(Our first try, was this same template with some additional code  
	//for each control placed on it, that's why this class is cold Ex :)  
	//This gave some problems on WIN9x systems, where EDIT boxes  
	//were not shown with 3D-look, but as flat controls)  
	int nBufferSize =sizeof(DLGTEMPLATE) + (2 * sizeof(WORD)) /*menu and class*/ + szBoxLen /*size of caption*/ 
		+ sizeof(WORD) /*fontsize*/ + nFontNameLen /*size of fontname*/; 

	//Are there any subclassed controls...  
	if (m_DialogTemplate.cdit > 0) 
	{ 
		nBufferSize = (nBufferSize + 3) & ~3;// adjust size to make first control DWORD aligned  

		CDynDialogItemEx *pDynDialogItemEx = NULL; 

		for (int i = 0; i < m_arrDlgItemPtr.GetSize(); i++) 
		{ 
			pDynDialogItemEx = m_arrDlgItemPtr[i]; 

			if (pDynDialogItemEx != NULL) 
			{ 
				if (pDynDialogItemEx->IsDlgItemSubclassed()) 
				{ 
					int nItemLength = sizeof(DLGITEMTEMPLATE) + 3 * sizeof(WORD); 
#ifdef _UNICODE
					nItemLength += (pDynDialogItemEx->GetCaptionLength() + 1) * sizeof(WCHAR); 
#else
					nItemLength += (pDynDialogItemEx->GetCaptionLength() + 1) * sizeof(CHAR); 
#endif
					if (i != m_DialogTemplate.cdit - 1)
					{ // the last control does not need extra bytes  
						nItemLength = (nItemLength + 3) & ~3;// take into account gap so next control is DWORD aligned  
					} 

					nBufferSize += nItemLength; 
				} 
			} 
		} 
	} 

	HLOCAL hLocal = LocalAlloc(LHND, nBufferSize); 

	if (hLocal != NULL)
	{ 
		BYTE* pBuffer = (BYTE*)LocalLock(hLocal); 
		if (pBuffer == NULL)
		{ 
			LocalFree(hLocal); 
			AfxMessageBox(_T("CDynDialogEx::DoModal() : LocalLock Failed")); 
		} 

		BYTE *pdest = pBuffer; 
		// transfer DLGTEMPLATE structure to the buffer  
		memcpy(pdest, &m_DialogTemplate, sizeof(DLGTEMPLATE));// DLGTemplate  
		pdest += sizeof(DLGTEMPLATE); 
		*(WORD*)pdest = 0;// no menu -- WORD to say it is 0 bytes  
		pdest += sizeof(WORD);// Increment  
		*(WORD*)(pdest + 1) = 0;// use default window class -- WORD to say it is 0 bytes  
		pdest += sizeof(WORD);// Increment  
		memcpy(pdest, szBoxCaption, szBoxLen);// Caption  
		pdest += szBoxLen; 

		*(WORD*)pdest = m_wFontSize;// font size  
		pdest += sizeof(WORD); 
		memcpy(pdest, szFontName, nFontNameLen);// font name  
		pdest += nFontNameLen; 

		// will now transfer the information for each one of subclassed controls...  
		if (m_DialogTemplate.cdit > 0) 
		{ 
			CDynDialogItemEx *pDynDialogItemEx = NULL; 

			for (int i = 0; i < m_arrDlgItemPtr.GetSize(); i++)
			{ 
				pDynDialogItemEx = m_arrDlgItemPtr[i]; 
				if (pDynDialogItemEx != NULL)
				{ 
					if (pDynDialogItemEx->IsDlgItemSubclassed())
					{ 
						pdest = pDynDialogItemEx->FillBufferWithItemTemplate(pdest); 
					} 
				} 
			} 
		} 

		ASSERT(pdest - pBuffer == nBufferSize); // just make sure we did not overrun the heap  

		//Next lines to make sure that MFC makes no ASSERTION when PREVIOUS/NEXT is pressed:)  
		if (m_lpDialogTemplate != NULL) 
		{ 
			m_lpDialogTemplate = NULL; 
		} 

		//These are the MFC functions, which do the job...  
		if (m_bModelessDlg) 
		{ 
			iRet = CreateIndirect((LPDLGTEMPLATE)pBuffer, m_pParentWnd); 
		} 
		else 
		{ 
			InitModalIndirect((LPDLGTEMPLATE)pBuffer, m_pParentWnd); 
			iRet = CDialog::DoModal(); 
		} 

		LocalUnlock(hLocal); 
		LocalFree(hLocal); 

		delete [] szBoxCaption; 
		delete [] szFontName; 
		return iRet; 
	} 
	else 
	{ 
		AfxMessageBox(_T("CDynDialogEx::DoModal() : LocalAllock Failed")); 
		return -1; 
	} 
} 

void CDynDialogEx::SetFont(CFont *pFont) 
{ 
	if (m_bIsFontCreated)
	{
		if (m_pFont != NULL)
		{
			delete m_pFont;
			m_pFont = NULL;
		}

		m_bIsFontCreated = FALSE;
	}

	m_pFont = pFont; 
} 

CFont *CDynDialogEx::GetFont() 
{ 
	return m_pFont; 
} 

void CDynDialogEx::SetFontSize(WORD wSize) 
{ 
	m_wFontSize = wSize; 
} 

WORD CDynDialogEx::GetFontSize() 
{ 
	return m_wFontSize; 
} 

void CDynDialogEx::SetUseSystemButtons(BOOL bUse /*= TRUE*/) 
{ 
	m_bAddSystemButtons = bUse; 
} 

void CDynDialogEx::GetDlgRect(LPRECT lpRect) 
{ 
	ASSERT(lpRect); 
	lpRect->left = m_DialogTemplate.x; 
	lpRect->top= m_DialogTemplate.y; 
	lpRect->right= lpRect->left + m_DialogTemplate.cx; 
	lpRect->bottom = lpRect->top + m_DialogTemplate.cy; 
} 

void CDynDialogEx::SetDlgRect(LPRECT lpRect) 
{ 
	ASSERT(lpRect); 
	//#pragma warning(disable : 4244)  
	m_DialogTemplate.cx = (short)(lpRect->right- lpRect->left); 
	m_DialogTemplate.cy = (short)(lpRect->bottom - lpRect->top); 
	m_DialogTemplate.x= (short)(lpRect->left); 
	m_DialogTemplate.y= (short)(lpRect->top); 
	//#pragma warning(default : 4244)  
} 

void CDynDialogEx::SetDlgRectangle(LPRECT pRect) 
{ 
	RECT rect; 

	GetDlgRect(&rect); 

	if (rect.left > pRect->left) 
	{ 
		rect.left = pRect->left; 
	} 

	if (rect.right < pRect->right)
	{ 
		rect.right = pRect->right + 5; 
	} 

	if (rect.top > pRect->top)
	{ 
		rect.top = pRect->top; 
	} 

	if (rect.bottom < pRect->bottom) 
	{ 
		rect.bottom = pRect->bottom + 5; 
	} 

	SetDlgRect(&rect); 
} 

UINT CDynDialogEx::AddDlgControl(DLGITEMTEMPLATECONTROLS TypeControl, 
								 const CString & lpszCaption, 
								 DWORD dwStyle, 
								 DWORD dwExtendedStyle, 
								 LPRECT pRect /*= NULL*/, 
								 void *pData /*= NULL*/, 
								 UINT nID /*= 0*/) 
{ 
	UINT nRet = 0; 
	//In case no rectangle given create our own...  
	CRect Rect(FIXEDCOL1, m_nCurRow, FIXEDCOL2, m_nCurRow + ROWSTEPSIZE); 

	//if no rectangle given use our own...  
	if (pRect == NULL)
	{ 
		pRect = &Rect; 
	} 
	//else {  
	//m_nCurRow = max(m_nCurRow, pRect->bottom) - m_nCurRow;  
	//}  

	m_nCurRow += (ROWSTEPSIZE); 

	//Update dialogtemplate boundaries  
	SetDlgRectangle(pRect); 

	//Create control and add to array of controls  
	CDynDialogItemEx *pDynDialogItemEx = new CDynDialogItemEx;

	if (pDynDialogItemEx != NULL) 
	{ 
		nRet = pDynDialogItemEx->InitDialogItem(TypeControl, dwStyle, dwExtendedStyle, pRect, lpszCaption, nID, FALSE, pData); 
		m_arrDlgItemPtr.Add(pDynDialogItemEx); 
	} 

	//Return ID of Control we created.  
	return nRet; 
} 

UINT CDynDialogEx::AddDlgControl(const CString & lpszClassName, 
								 const CString & lpszCaption, 
								 DWORD dwStyle, 
								 DWORD dwExtendedStyle, 
								 LPRECT pRect /*= NULL*/, 
								 void *pData /*= NULL*/, 
								 UINT nID /*= 0*/) 
{ 
	UINT nRet = 0; 
	//In case no rectangle given create our own...  
	CRect Rect(FIXEDCOL1, m_nCurRow, FIXEDCOL2, m_nCurRow + ROWSTEPSIZE); 

	//if no rectangle given use our own...  
	if (pRect == NULL) 
	{ 
		pRect = &Rect; 
		Rect.right += INPUTCOL; 
	} 
	//else {  
	//m_nCurRow = max(m_nCurRow, pRect->bottom) - m_nCurRow;  
	//}  

	m_nCurRow += (ROWSTEPSIZE); 

	//Update dialogtemplate boundaries  
	SetDlgRectangle(pRect); 

	//Create control and add to array of controls  
	CDynDialogItemEx *pDynDialogItemEx = new CDynDialogItemEx; 

	if (pDynDialogItemEx != NULL) 
	{ 
		nRet = pDynDialogItemEx->InitDialogItem(lpszClassName, dwStyle, dwExtendedStyle, pRect, lpszCaption, nID, FALSE, pData); 
		m_arrDlgItemPtr.Add(pDynDialogItemEx); 
	} 

	//Return ID of Control we created.  
	return nRet; 
} 

UINT CDynDialogEx::AddSubclassedDlgControl(const CString & lpszClassName, 
										   const CString & lpszCaption, 
										   DWORD dwStyle, 
										   DWORD dwExtendedStyle, 
										   LPRECT pRect /*= NULL*/, 
										   UINT nID /*= 0*/) 
{ 
	UINT nRet = 0; 
	//In case no rectangle given create our own...  
	CRect Rect(FIXEDCOL1, m_nCurRow, FIXEDCOL2, m_nCurRow + ROWSTEPSIZE); 

	//if no rectangle given use our own...  
	if (pRect == NULL)
	{ 
		pRect = &Rect; 
		Rect.right += INPUTCOL; 
	} 
	//else {  
	//m_nCurRow = max(m_nCurRow, pRect->bottom) - m_nCurRow;  
	//}  

	m_nCurRow += (ROWSTEPSIZE); 

	//Update dialogtemplate boundaries  
	SetDlgRectangle(pRect); 

	//Create control and add to array of controls  
	CDynDialogItemEx *pDynDialogItemEx = new CDynDialogItemEx; 

	if (pDynDialogItemEx != NULL) 
	{ 
		nRet = pDynDialogItemEx->InitDialogItem(lpszClassName, dwStyle, dwExtendedStyle, pRect, lpszCaption, nID, TRUE); 
		m_arrDlgItemPtr.Add(pDynDialogItemEx); 
		m_DialogTemplate.cdit++; 
	} 

	//Return ID of Control we created.  
	return nRet; 
} 

void CDynDialogEx::AddSystemButtons() 
{ 
	m_nCurRow += 6; // Leave some room!  
	CRect rect(FIXEDCOL1, m_nCurRow, FIXEDCOL2 - 60, m_nCurRow + (long)(ROWSTEPSIZE * 1.2)); 

	AddDlgControl(BUTTON, _T("OK"), STYLE_BUTTON, EXSTYLE_BUTTON, &rect, NULL, IDOK); 

	// This has to be revised later.  
	rect.left+= 55; 
	rect.right += 55; 
	AddDlgControl(BUTTON, _T("Annuleren"), STYLE_BUTTON, EXSTYLE_BUTTON, &rect, NULL, IDCANCEL); 

} 

void CDynDialogEx::SetWindowTitle(const CString & lpszCaption) 
{ 
	m_strCaption = lpszCaption; 
} 

void CDynDialogEx::SetUseModeless(BOOL bModelessDlg /*= TRUE*/) 
{ 
	m_bModelessDlg = bModelessDlg; 
} 

void CDynDialogEx::OnCancel() 
{ 
	if (m_bModelessDlg) 
	{ 
		DestroyWindow(); 
	} 
	else 
	{ 
		CDialog::OnCancel(); 
	} 
} 

void CDynDialogEx::OnOK() 
{ 
	if (m_bModelessDlg)
	{ 
		DestroyWindow(); 
	} 
	else 
	{ 
		CDialog::OnOK(); 
	} 
} 

BOOL CDynDialogEx::OnCommand(WPARAM wParam, LPARAM lParam)
{ 
	//wParam  
	//The low-order word of wParam identifies the command ID of the menu item, control, or accelerator.  
	//The high-order word of wParam specifies the notification message if the message is from a control.  
	//If the message is from an accelerator, the high-order word is 1.  
	//If the message is from a menu, the high-order word is 0.  

	//lParam  
	//Identifies the control that sends the message if the message is from a control. Otherwise, lParam is 0.  

// 	WORD wControlID = LOWORD(wParam); 
// 	WORD wMessageID = HIWORD(wParam); 
// 
// 	if (wControlID != 0)
// 	{ 
// 		switch (wControlID)
// 		{ 
// 		case IDOK: 
// 			OnOK(); 
// 			return TRUE; 
// 			break; 
// 		case IDCANCEL: 
// 			OnCancel(); 
// 			return TRUE; 
// 			break; 
// 		default: 
// 			//if we have a parent send the message to the parent, so we can handle the message over there.  
// 			if (m_pParentWnd != NULL)
// 			{ 
// 				::SendMessage(m_pParentWnd->GetSafeHwnd(), WM_COMMAND, wParam, lParam); 
// 			} 
// 			break; 
// 		} 
// 	} 

	return CDialog::OnCommand(wParam, lParam); 
} 

// Hellup!  
afx_msg LRESULT CDynDialogEx::OnHelpMsg(WPARAM wParam, LPARAM lParam) 
{ 
	//lParam<<-- Contains: (LPHELPINFO)lParam  
	// >> typedefstructtagHELPINFO { 
	// UINT cbSize; 
	// intiContextType 
	// intiCtrlId; 
	// HANDLE hItemHandle; 
	// DWORDdwContextId; 
	// POINTMousePos; 
	// } HELPINFO, FAR *LPHELPINFO;  

	//  
	// User pressed F1 in dialog, call the OnHelp() function, this can be overridden...  
	//  
	OnHelp(); 
	return TRUE; 
} 

// Default implementation of the OnHelp()  
// This one is to be overridden by a caller ;)  
void CDynDialogEx::OnHelp() 
{ 
	CDialog::OnHelp(); 
}