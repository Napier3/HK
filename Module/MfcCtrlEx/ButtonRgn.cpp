#include "stdafx.h"
#include "ButtonRgn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CButtonRgn

// Mask for control's type
//#define BS_TYPEMASK SS_TYPEMASK

CButtonRgn::CButtonRgn()
{
	m_bIsPressed		= FALSE;
	m_bIsFocused		= FALSE;
	m_bIsDisabled		= FALSE;
	m_bMouseOnButton	= FALSE;

	FreeResources(FALSE);

	// Default type is "flat" button
	m_bIsFlat = TRUE;
	// Button will be tracked also if when the window is inactive (like Internet Explorer)
	m_bAlwaysTrack = TRUE;
  
	// By default draw border in "flat" button 
	m_bDrawBorder = TRUE; 
  
	// By default icon is aligned horizontally
	m_byAlign = ST_ALIGN_HORIZ; 
	m_nBitmapsPos = ST_BITMAP_POS_TOP;
  
	// By default, for "flat" button, don't draw the focus rect
	m_bDrawFlatFocus = FALSE;

	// By default the button is not the default button
	m_bIsDefault = FALSE;
	// Invalid value, since type still unknown
	m_nTypeStyle = BS_TYPEMASK;

	// By default the button is not a checkbox
	m_bIsCheckBox = FALSE;
	m_nCheck = 0;

	// Set default colors
	SetDefaultColors(FALSE);

	// No tooltip created
	m_ToolTip.m_hWnd = NULL;

	// Do not draw as a transparent button
	m_bDrawTransparent = FALSE;
	m_pbmpOldBk = NULL;

	// No URL defined
	SetURL(NULL);

	// No cursor defined
	m_hCursor = NULL;

	// No associated menu
#ifndef	BTNST_USE_BCMENU
	m_hMenu = NULL;
#endif
	m_hParentWndMenu = NULL;
	m_bMenuDisplayed = FALSE;

	m_bShowDisabledBitmap = TRUE;
	m_crTextColor = 0xFFFFFFFF;
} // End of CButtonRgn

CButtonRgn::~CButtonRgn()
{
	// Restore old bitmap (if any)
	if (m_dcBk.m_hDC && m_pbmpOldBk)
	{
		m_dcBk.SelectObject(m_pbmpOldBk);
	} // if

	FreeResources();

	// Destroy the cursor (if any)
	if (m_hCursor) ::DestroyCursor(m_hCursor);

	// Destroy the menu (if any)
	if (m_hMenu)	::DestroyMenu(m_hMenu);
} // End of ~CButtonRgn

BEGIN_MESSAGE_MAP(CButtonRgn, CButton)
    //{{AFX_MSG_MAP(CButtonRgn)
	ON_WM_SETCURSOR()
	ON_WM_KILLFOCUS()
	ON_WM_MOUSEMOVE()
	ON_WM_SYSCOLORCHANGE()
	ON_CONTROL_REFLECT_EX(BN_CLICKED, OnClicked)
	ON_WM_ACTIVATE()
	ON_WM_ENABLE()
	ON_WM_CANCELMODE()
	ON_WM_GETDLGCODE()
	ON_WM_CTLCOLOR_REFLECT()
	//}}AFX_MSG_MAP

	ON_MESSAGE(BM_SETSTYLE, OnSetStyle)
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_MESSAGE(BM_SETCHECK, OnSetCheck)
	ON_MESSAGE(BM_GETCHECK, OnGetCheck)
END_MESSAGE_MAP()

void CButtonRgn::FreeResources(BOOL bCheckForNULL)
{
	if (bCheckForNULL)
	{
		// Destroy icons
		// Note: the following two lines MUST be here! even if
		// BoundChecker says they are unnecessary!
		if (m_csIcons[0].hIcon)	::DestroyIcon(m_csIcons[0].hIcon);
		if (m_csIcons[1].hIcon)	::DestroyIcon(m_csIcons[1].hIcon);

		// Destroy bitmaps
		if (m_csBitmaps[0].hBitmap)	::DeleteObject(m_csBitmaps[0].hBitmap);
		if (m_csBitmaps[1].hBitmap)	::DeleteObject(m_csBitmaps[1].hBitmap);

		// Destroy mask bitmaps
		if (m_csBitmaps[0].hMask)	::DeleteObject(m_csBitmaps[0].hMask);
		if (m_csBitmaps[1].hMask)	::DeleteObject(m_csBitmaps[1].hMask);
	} // if

	::ZeroMemory(&m_csIcons, sizeof(m_csIcons));
	::ZeroMemory(&m_csBitmaps, sizeof(m_csBitmaps));
} // End of FreeResources

void CButtonRgn::PreSubclassWindow() 
{
	UINT nBS;

	nBS = GetButtonStyle();

	// Set initial control type
	m_nTypeStyle = nBS & BS_TYPEMASK;

	// Check if this is a checkbox
	if (nBS & BS_CHECKBOX) m_bIsCheckBox = TRUE;

	// Set initial default state flag
	if (m_nTypeStyle == BS_DEFPUSHBUTTON)
	{
		// Set default state for a default button
		m_bIsDefault = TRUE;

		// Adjust style for default button
		m_nTypeStyle = BS_PUSHBUTTON;
	} // If

	// You should not set the Owner Draw before this call
	// (don't use the resource editor "Owner Draw" or
	// ModifyStyle(0, BS_OWNERDRAW) before calling PreSubclassWindow() )
	ASSERT(m_nTypeStyle != BS_OWNERDRAW);

	// Switch to owner-draw
	ModifyStyle(BS_TYPEMASK, BS_OWNERDRAW, SWP_FRAMECHANGED);

	CButton::PreSubclassWindow();
} // End of PreSubclassWindow

UINT CButtonRgn::OnGetDlgCode() 
{
	UINT nCode = CButton::OnGetDlgCode();

	// Tell the system if we want default state handling
	// (losing default state always allowed)
	nCode |= (m_bIsDefault ? DLGC_DEFPUSHBUTTON : DLGC_UNDEFPUSHBUTTON);

	return nCode;
} // End of OnGetDlgCode

BOOL CButtonRgn::PreTranslateMessage(MSG* pMsg) 
{
	InitToolTip();
	m_ToolTip.RelayEvent(pMsg);
	
	return CButton::PreTranslateMessage(pMsg);
} // End of PreTranslateMessage

LRESULT CButtonRgn::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	if (message == WM_LBUTTONDBLCLK)
	{
		message = WM_LBUTTONDOWN;
	} // if
	/*
	switch (message)
	{
		case WM_LBUTTONDBLCLK:
			message = WM_LBUTTONDOWN;
			break;
		case WM_MOVE:
			CRect rect;

			GetClientRect(&rect);
			if (::IsWindow(m_ToolTip.m_hWnd))
			{
				if (m_ToolTip.GetToolCount() != 0)
					m_ToolTip.SetToolRect(this, 1, &rect);
			} // if
			break;
	} // switch
	*/
	return CButton::DefWindowProc(message, wParam, lParam);
} // End of DefWindowProc

HBRUSH CButtonRgn::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	return (HBRUSH)::GetStockObject(NULL_BRUSH); 
} // End of CtlColor

void CButtonRgn::OnSysColorChange() 
{
	CButton::OnSysColorChange();

	m_dcBk.DeleteDC();
	m_bmpBk.DeleteObject();	
} // End of OnSysColorChange

LRESULT CButtonRgn::OnSetStyle(WPARAM wParam, LPARAM lParam)
{
	UINT nNewType = (wParam & BS_TYPEMASK);

	// Update default state flag
	if (nNewType == BS_DEFPUSHBUTTON)
	{
		m_bIsDefault = TRUE;
	} // if
	else if (nNewType == BS_PUSHBUTTON)
	{
		// Losing default state always allowed
		m_bIsDefault = FALSE;
	} // if

	// Can't change control type after owner-draw is set.
	// Let the system process changes to other style bits
	// and redrawing, while keeping owner-draw style
	return DefWindowProc(BM_SETSTYLE,
		(wParam & ~BS_TYPEMASK) | BS_OWNERDRAW, lParam);
} // End of OnSetStyle

LRESULT CButtonRgn::OnSetCheck(WPARAM wParam, LPARAM lParam)
{
	ASSERT(m_bIsCheckBox);

	switch (wParam)
	{
		case BST_CHECKED:
		case BST_INDETERMINATE:	// Indeterminate state is handled like checked state
			SetCheck(1);
			break;
		default:
			SetCheck(0);
			break;
	} // switch

	return 0;
} // End of OnSetCheck

LRESULT CButtonRgn::OnGetCheck(WPARAM wParam, LPARAM lParam)
{
	ASSERT(m_bIsCheckBox);
	return GetCheck();
} // End of OnGetCheck


void CButtonRgn::OnEnable(BOOL bEnable) 
{
	CButton::OnEnable(bEnable);
	
	if (bEnable == FALSE)	
	{
		CWnd*	pWnd = GetParent()->GetNextDlgTabItem(this);
		if (pWnd)
			pWnd->SetFocus();
		else
			GetParent()->SetFocus();

		CancelHover();
	} // if
} // End of OnEnable

void CButtonRgn::OnKillFocus(CWnd * pNewWnd)
{
	CButton::OnKillFocus(pNewWnd);
	CancelHover();
} // End of OnKillFocus

void CButtonRgn::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
	CButton::OnActivate(nState, pWndOther, bMinimized);
	if (nState == WA_INACTIVE)	CancelHover();
} // End of OnActivate

void CButtonRgn::OnCancelMode() 
{
	CButton::OnCancelMode();
	CancelHover();
} // End of OnCancelMode

BOOL CButtonRgn::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// If a cursor was specified then use it!
	if (m_hCursor != NULL)
	{
		::SetCursor(m_hCursor);
		return TRUE;
	} // if

	return CButton::OnSetCursor(pWnd, nHitTest, message);
} // End of OnSetCursor

void CButtonRgn::CancelHover()
{
	// Only for flat buttons
	if (m_bIsFlat)
	{
		if (m_bMouseOnButton)
		{
			m_bMouseOnButton = FALSE;
			Invalidate();
		} // if
	} // if
} // End of CancelHover

void CButtonRgn::OnMouseMove(UINT nFlags, CPoint point)
{
	CWnd*				wndUnderMouse = NULL;
	CWnd*				wndActive = this;
	TRACKMOUSEEVENT		csTME;

	CButton::OnMouseMove(nFlags, point);

	ClientToScreen(&point);
	wndUnderMouse = WindowFromPoint(point);

	// If the mouse enter the button with the left button pressed then do nothing
	if (nFlags & MK_LBUTTON && m_bMouseOnButton == FALSE) return;

	// If our button is not flat then do nothing
	if (m_bIsFlat == FALSE) return;

	if (m_bAlwaysTrack == FALSE)	wndActive = GetActiveWindow();

	if (wndUnderMouse && wndUnderMouse->m_hWnd == m_hWnd && wndActive)
	{
		if (!m_bMouseOnButton)
		{
			m_bMouseOnButton = TRUE;

			Invalidate();

			csTME.cbSize = sizeof(csTME);
			csTME.dwFlags = TME_LEAVE;
			csTME.hwndTrack = m_hWnd;
			::_TrackMouseEvent(&csTME);
		} // if
	} else CancelHover();
} // End of OnMouseMove

// Handler for WM_MOUSELEAVE
LRESULT CButtonRgn::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
	CancelHover();
	return 0;
} // End of OnMouseLeave

BOOL CButtonRgn::OnClicked() 
{	
	SetFocus();

	if (m_bIsCheckBox)
	{
		m_nCheck = !m_nCheck;
		Invalidate();
	} // if
	else
	{
		// Handle the menu (if any)
		if (m_hMenu)
		{
			CRect	rWnd;
			GetWindowRect(rWnd);

			m_bMenuDisplayed = TRUE;
			Invalidate();

			HMENU hSubMenu = ::GetSubMenu(m_hMenu, 0);
			//DWORD dwRetValue = ::TrackPopupMenuEx(hSubMenu, TPM_LEFTALIGN | TPM_LEFTBUTTON, rWnd.left, rWnd.bottom, m_hParentWndMenu, NULL);
			DWORD dwRetValue = ::TrackPopupMenuEx(hSubMenu, TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_RIGHTBUTTON | TPM_NONOTIFY | TPM_RETURNCMD, rWnd.left, rWnd.bottom, m_hParentWndMenu, NULL);

			m_bMenuDisplayed = FALSE;
			Invalidate();

			if (dwRetValue)
				::PostMessage(m_hParentWndMenu, WM_COMMAND, MAKEWPARAM(dwRetValue, 0), (LPARAM)NULL);
		} // if
		else
		{
			// Handle the URL (if any)
			if (_tcslen(m_szURL) > 0)
			{
				SHELLEXECUTEINFO	csSEI;

				memset(&csSEI, 0, sizeof(csSEI));
				csSEI.cbSize = sizeof(SHELLEXECUTEINFO);
				csSEI.fMask = SEE_MASK_FLAG_NO_UI;
				csSEI.lpVerb = _T("open");
				csSEI.lpFile = m_szURL;
				csSEI.nShow = SW_SHOWMAXIMIZED;
				::ShellExecuteEx(&csSEI);
			} // if
		} // else
	} // else

	return FALSE;
} // End of OnClicked

void CButtonRgn::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{
	CDC*	pDC = CDC::FromHandle(lpDIS->hDC);
	CPen*	pOldPen;

/*	CRect rectClient;
	GetClientRect(&rectClient);
	CRgn	rgnRound;
	CRgn rgnTemp1,rgnTemp2;
	int iWidth = rectClient.Width()-4;
	int iHeight = rectClient.Height()-5;

	POINT	ptLeader[8];
	ptLeader[0].x = 2;
	ptLeader[0].y = 0;
	ptLeader[1].x = iWidth + 2;
	ptLeader[1].y = 0;
	ptLeader[2].x = iWidth + 4;
	ptLeader[2].y = 2;
	ptLeader[3].x = iWidth + 4;
	ptLeader[3].y = iHeight + 2;
	ptLeader[4].x = iWidth + 2;
	ptLeader[4].y = iHeight + 5;
	ptLeader[5].x = 2;
	ptLeader[5].y = iHeight + 5;
	ptLeader[6].x = 0;
	ptLeader[6].y = iHeight + 2;
	ptLeader[7].x = 0;
	ptLeader[7].y = 2;

	rgnRound.CreatePolygonRgn(ptLeader, 8, ALTERNATE);
*/
/*	rgnRound.CreateRectRgn(0,0,0,0);
	rgnTemp1.CreateRectRgn(2,0,iWidth,0);
	rgnTemp2.CreateRectRgn(1,1,iWidth+1,1);
	rgnRound.CombineRgn(&rgnTemp1,&rgnTemp2,RGN_AND);
	rgnTemp1.DeleteObject();
	rgnTemp1.CreateRectRgn(0,2,iWidth+2,iHeight+2);
	rgnTemp2.CopyRgn(&rgnRound);
	rgnRound.CombineRgn(&rgnTemp1,&rgnTemp2,RGN_AND);

	rgnTemp1.DeleteObject();
	rgnTemp1.CreateRectRgn(1,iHeight+3,iWidth+1,iHeight+3);
	rgnTemp2.CopyRgn(&rgnRound);
	rgnRound.CombineRgn(&rgnTemp1,&rgnTemp2,RGN_AND);
	rgnTemp1.DeleteObject();
	rgnTemp1.CreateRectRgn(2,iHeight+4,iWidth,iHeight+4);
	rgnTemp2.CopyRgn(&rgnRound);
	rgnRound.CombineRgn(&rgnTemp1,&rgnTemp2,RGN_AND);
*/
/*	HRGN hRegion =  ::CreateRectRgn(0, 0, rectClient.Width()+2, rectClient.Height()+2);
	rgnRound.CreateRoundRectRgn(0, 0, rectClient.Width(), rectClient.Height(), 2, 2);
	CombineRgn(hRegion, rgnRound.operator HRGN(), rgnRound.operator HRGN(), RGN_OR);
//	::SetWindowRgn(m_hWnd,hRegion, TRUE);
//	SetWindowRgn(rgnRound,FALSE);
*/
/*	CBrush	WindowBrush;
	CBrush	FrameBrush;
	//��������
	FrameBrush.CreateSolidBrush(RGB(192,192,192));
	WindowBrush.CreateSolidBrush(RGB(255,255,204));

//	CRgn	*pRegion;
//	pRegion = CRgn::FromHandle(hRegion);
	pDC->FillRgn(&rgnRound, &WindowBrush);
	pDC->FrameRgn(&rgnRound, &FrameBrush, 1, 1);

	CString strText = "";
	GetWindowText(strText);
	pDC->SetBkMode( TRANSPARENT );
	rectClient.top += 2;
	pDC->DrawText(strText, &rectClient, DT_CENTER);
	//CmDrawTextRect(&dc,m_szText,RGB(0,0,0),rc,RGB(255,255,255),m_lfLogFont,TRANSPARENT,DT_TOP | DT_LEFT | DT_WORDBREAK,0);
	return;
*/	// Checkbox?
	if (m_bIsCheckBox)
	{
		m_bIsPressed  =  (lpDIS->itemState & ODS_SELECTED) || (m_nCheck != 0);
	} // if
	else	// Normal button OR other button style ...
	{
		m_bIsPressed = (lpDIS->itemState & ODS_SELECTED);

		// If there is a menu and it's displayed, draw the button as pressed
		if (
			m_hMenu 
			&& m_bMenuDisplayed)	m_bIsPressed = TRUE;
	} // else

	m_bIsFocused  = (lpDIS->itemState & ODS_FOCUS);
	m_bIsDisabled = (lpDIS->itemState & ODS_DISABLED);

	CRect itemRect = lpDIS->rcItem;

	pDC->SetBkMode(TRANSPARENT);

	if (m_bIsFlat == FALSE)
	{
		if (m_bIsFocused || m_bIsDefault)
		{
			CBrush br(RGB(0,0,0));  
			pDC->FrameRect(&itemRect, &br);
			itemRect.DeflateRect(1, 1);
		} // if
	} // if

	// Prepare draw... paint button background

	// Draw transparent?
	if (m_bDrawTransparent)
		PaintBk(pDC);
	else
		OnDrawBackground(pDC, &itemRect);

	// Draw pressed button
	if (m_bIsPressed)
	{
		if (m_bIsFlat)
		{
			if (m_bDrawBorder)
				OnDrawBorder(pDC, &itemRect);
		}
		else    
		{
			CBrush brBtnShadow(GetSysColor(COLOR_BTNSHADOW));
			pDC->FrameRect(&itemRect, &brBtnShadow);
		}
	}
	else // ...else draw non pressed button
	{
		CPen penBtnHiLight(PS_SOLID, 0, GetSysColor(COLOR_BTNHILIGHT)); // White
		CPen pen3DLight(PS_SOLID, 0, GetSysColor(COLOR_3DLIGHT));       // Light gray
		CPen penBtnShadow(PS_SOLID, 0, GetSysColor(COLOR_BTNSHADOW));   // Dark gray
		CPen pen3DDKShadow(PS_SOLID, 0, GetSysColor(COLOR_3DDKSHADOW)); // Black

		if (m_bIsFlat)
		{
			if (m_bDrawBorder)
				OnDrawBorder(pDC, &itemRect);
		}
		else
		{
			// Draw top-left borders
			// White line
			pOldPen = pDC->SelectObject(&penBtnHiLight);
			pDC->MoveTo(itemRect.left, itemRect.bottom-1);
			pDC->LineTo(itemRect.left, itemRect.top);
			pDC->LineTo(itemRect.right, itemRect.top);
			// Light gray line
			pDC->SelectObject(pen3DLight);
			pDC->MoveTo(itemRect.left+1, itemRect.bottom-1);
			pDC->LineTo(itemRect.left+1, itemRect.top+1);
			pDC->LineTo(itemRect.right, itemRect.top+1);
			// Draw bottom-right borders
			// Black line
			pDC->SelectObject(pen3DDKShadow);
			pDC->MoveTo(itemRect.left, itemRect.bottom-1);
			pDC->LineTo(itemRect.right-1, itemRect.bottom-1);
			pDC->LineTo(itemRect.right-1, itemRect.top-1);
			// Dark gray line
			pDC->SelectObject(penBtnShadow);
			pDC->MoveTo(itemRect.left+1, itemRect.bottom-2);
			pDC->LineTo(itemRect.right-2, itemRect.bottom-2);
			pDC->LineTo(itemRect.right-2, itemRect.top);
			//
			pDC->SelectObject(pOldPen);
		} // else
	} // else

	// Read the button's title
	CString sTitle;
	GetWindowText(sTitle);

	CRect captionRect = lpDIS->rcItem;

	// Draw the icon
	if (m_csIcons[0].hIcon)
	{
		DrawTheIcon(pDC, !sTitle.IsEmpty(), &lpDIS->rcItem, &captionRect, m_bIsPressed, m_bIsDisabled);
	} // if

	if (m_csBitmaps[0].hBitmap)
	{
		pDC->SetBkColor(RGB(255,255,255));
		DrawTheBitmap(pDC, !sTitle.IsEmpty(), &lpDIS->rcItem, &captionRect, m_bIsPressed, m_bIsDisabled);
	} // if

	// Write the button title (if any)
	if (sTitle.IsEmpty() == FALSE)
	{
		// Draw the button's title
		// If button is pressed then "press" title also
		if (m_bIsPressed && m_bIsCheckBox == FALSE)
			captionRect.OffsetRect(1, 1);
    
		// ONLY FOR DEBUG 
		//CBrush brBtnShadow(RGB(255, 0, 0));
		//pDC->FrameRect(&captionRect, &brBtnShadow);

		// Center text
		CRect centerRect = captionRect;
		pDC->DrawText(sTitle, -1, captionRect, DT_WORDBREAK | DT_CENTER | DT_CALCRECT);
		captionRect.OffsetRect((centerRect.Width() - captionRect.Width())/2, (centerRect.Height() - captionRect.Height())/2);
		/* RFU
		captionRect.OffsetRect(0, (centerRect.Height() - captionRect.Height())/2);
		captionRect.OffsetRect((centerRect.Width() - captionRect.Width())-4, (centerRect.Height() - captionRect.Height())/2);
		*/

		pDC->SetBkMode(TRANSPARENT);
		/*
		pDC->DrawState(captionRect.TopLeft(), captionRect.Size(), (LPCTSTR)sTitle, (bIsDisabled ? DSS_DISABLED : DSS_NORMAL), 
						TRUE, 0, (CBrush*)NULL);
		*/
		if (m_bIsDisabled)
		{
			captionRect.OffsetRect(1, 1);
			pDC->SetTextColor(::GetSysColor(COLOR_3DHILIGHT));
			pDC->DrawText(sTitle, -1, captionRect, DT_WORDBREAK | DT_CENTER);
			captionRect.OffsetRect(-1, -1);
			pDC->SetTextColor(::GetSysColor(COLOR_3DSHADOW));
			pDC->DrawText(sTitle, -1, captionRect, DT_WORDBREAK | DT_CENTER);
		} // if
		else
		{
			if (m_bMouseOnButton || m_bIsPressed) 
			{
				pDC->SetTextColor(GetTextColor(m_crColors[BTNST_COLOR_FG_IN]));
				pDC->SetBkColor(m_crColors[BTNST_COLOR_BK_IN]);
			} // if
			else 
			{
				pDC->SetTextColor(GetTextColor(m_crColors[BTNST_COLOR_FG_OUT]));
				pDC->SetBkColor(m_crColors[BTNST_COLOR_BK_OUT]);
			} // else
			pDC->DrawText(sTitle, -1, captionRect, DT_WORDBREAK | DT_CENTER);
		} // if
	} // if

	if (m_bIsFlat == FALSE || (m_bIsFlat && m_bDrawFlatFocus))
	{
		// Draw the focus rect
		if (m_bIsFocused)
		{
			CRect focusRect = itemRect;
			focusRect.DeflateRect(3, 3);
			pDC->DrawFocusRect(&focusRect);
		} // if
	} // if
} // End of DrawItem

void CButtonRgn::PaintBk(CDC* pDC)
{
	CClientDC clDC(GetParent());
	CRect rect;
	CRect rect1;

	GetClientRect(rect);

	GetWindowRect(rect1);
	GetParent()->ScreenToClient(rect1);

	if (m_dcBk.m_hDC == NULL)
	{
		m_dcBk.CreateCompatibleDC(&clDC);
		m_bmpBk.CreateCompatibleBitmap(&clDC, rect.Width(), rect.Height());
		m_pbmpOldBk = m_dcBk.SelectObject(&m_bmpBk);
		m_dcBk.BitBlt(0, 0, rect.Width(), rect.Height(), &clDC, rect1.left, rect1.top, SRCCOPY);
	} // if

	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &m_dcBk, 0, 0, SRCCOPY);
} // End of PaintBk

HBITMAP CButtonRgn::CreateBitmapMask(HBITMAP hSourceBitmap, DWORD dwWidth, DWORD dwHeight, COLORREF crTransColor)
{
	HBITMAP		hMask		= NULL;
	HDC			hdcSrc		= NULL;
	HDC			hdcDest		= NULL;
	HBITMAP		hbmSrcT		= NULL;
	HBITMAP		hbmDestT	= NULL;
	COLORREF	crSaveBk;
	COLORREF	crSaveDestText;

	hMask = ::CreateBitmap(dwWidth, dwHeight, 1, 1, NULL);
	if (hMask == NULL)	return NULL;

	hdcSrc	= ::CreateCompatibleDC(NULL);
	hdcDest	= ::CreateCompatibleDC(NULL);

	hbmSrcT = (HBITMAP)::SelectObject(hdcSrc, hSourceBitmap);
	hbmDestT = (HBITMAP)::SelectObject(hdcDest, hMask);

	crSaveBk = ::SetBkColor(hdcSrc, crTransColor);

	::BitBlt(hdcDest, 0, 0, dwWidth, dwHeight, hdcSrc, 0, 0, SRCCOPY);

	crSaveDestText = ::SetTextColor(hdcSrc, RGB(255, 255, 255));
	::SetBkColor(hdcSrc,RGB(0, 0, 0));

	::BitBlt(hdcSrc, 0, 0, dwWidth, dwHeight, hdcDest, 0, 0, SRCAND);

	SetTextColor(hdcDest, crSaveDestText);

	::SetBkColor(hdcSrc, crSaveBk);
	::SelectObject(hdcSrc, hbmSrcT);
	::SelectObject(hdcDest, hbmDestT);

	::DeleteDC(hdcSrc);
	::DeleteDC(hdcDest);

	return hMask;
} // End of CreateBitmapMask

//
// Parameters:
//		[IN]	bHasTitle
//				TRUE if the button has a text
//		[IN]	rpItem
//				A pointer to a RECT structure indicating the allowed paint area
//		[IN/OUT]rpTitle
//				A pointer to a CRect object indicating the paint area reserved for the
//				text. This structure will be modified if necessary.
//		[IN]	bIsPressed
//				TRUE if the button is currently pressed
//		[IN]	dwWidth
//				Width of the image (icon or bitmap)
//		[IN]	dwHeight
//				Height of the image (icon or bitmap)
//		[OUT]	rpImage
//				A pointer to a CRect object that will receive the area available to the image
//
void CButtonRgn::PrepareImageRect(BOOL bHasTitle, RECT* rpItem, CRect* rpTitle, BOOL bIsPressed, DWORD dwWidth, DWORD dwHeight, CRect* rpImage)
{
	CRect rBtn;

	rpImage->CopyRect(rpItem);

	switch (m_byAlign)
	{
		case ST_ALIGN_HORIZ:
			PrepareImageRect_Horz(bHasTitle, rpItem, rpTitle, bIsPressed, dwWidth, dwHeight, rpImage);
			break;

		case ST_ALIGN_HORIZ_RIGHT:
			GetClientRect(&rBtn);
			if (bHasTitle == FALSE)
			{
				// Center image horizontally
				rpImage->left += ((rpImage->Width() - (long)dwWidth)/2);
			}
			else
			{
				// Image must be placed just inside the focus rect
				rpTitle->right = rpTitle->Width() - dwWidth - 3;
				rpTitle->left = 3;
				rpImage->left = rBtn.right - dwWidth - 3;
				// Center image vertically
				rpImage->top += ((rpImage->Height() - (long)dwHeight)/2);
			}
			break;
		
		case ST_ALIGN_VERT:
			PrepareImageRect_Vert(bHasTitle, rpItem, rpTitle, bIsPressed, dwWidth, dwHeight, rpImage);
			break;
	}
    
	// If button is pressed then press image also
	if (bIsPressed && m_bIsCheckBox == FALSE)
		rpImage->OffsetRect(1, 1);
} // End of PrepareImageRect

void CButtonRgn::PrepareImageRect_Horz(BOOL bHasTitle, RECT* rpItem, CRect* rpTitle, BOOL bIsPressed, DWORD dwWidth, DWORD dwHeight, CRect* rpImage)
{
	CRect rBtn;
	rpImage->CopyRect(rpItem);

	if (bHasTitle == FALSE)
	{
		// Center image horizontally
		rpImage->left += ((rpImage->Width() - (long)dwWidth)/2);
	}
	else
	{
		// Image must be placed just inside the focus rect

		switch (m_nBitmapsPos)
		{
		case ST_BITMAP_POS_LEFT:
			rpImage->left += 3;  
			rpTitle->left += dwWidth + 3;
			// Center image vertically
			rpImage->top += ((rpImage->Height() - (long)dwHeight)/2);
			break;
		case ST_BITMAP_POS_TOP:
			rpImage->top += 3;
			rpImage->bottom = rpImage->top + dwHeight ;
			rpImage->left =  rpItem->left + (rpItem->right-rpItem->left - dwWidth)/2;
			rpImage->right = rpImage->left + dwWidth;
			rpTitle->left += rpItem->left + 3;
			rpTitle->top += dwHeight;
			break;
		}
	}

	// If button is pressed then press image also
	if (bIsPressed && m_bIsCheckBox == FALSE)
		rpImage->OffsetRect(1, 1);
} // End of PrepareImageRect

void CButtonRgn::PrepareImageRect_Vert(BOOL bHasTitle, RECT* rpItem, CRect* rpTitle, BOOL bIsPressed, DWORD dwWidth, DWORD dwHeight, CRect* rpImage)
{
	CRect rBtn;

	rpImage->CopyRect(rpItem);

	switch (m_byAlign)
	{
	case ST_ALIGN_HORIZ:
		PrepareImageRect_Horz(bHasTitle, rpItem, rpTitle, bIsPressed, dwWidth, dwHeight, rpImage);
		break;

	case ST_ALIGN_HORIZ_RIGHT:
		GetClientRect(&rBtn);
		if (bHasTitle == FALSE)
		{
			// Center image horizontally
			rpImage->left += ((rpImage->Width() - (long)dwWidth)/2);
		}
		else
		{
			// Image must be placed just inside the focus rect
			rpTitle->right = rpTitle->Width() - dwWidth - 3;
			rpTitle->left = 3;
			rpImage->left = rBtn.right - dwWidth - 3;
			// Center image vertically
			rpImage->top += ((rpImage->Height() - (long)dwHeight)/2);
		}
		break;

	case ST_ALIGN_VERT:
		PrepareImageRect_Vert(bHasTitle, rpItem, rpTitle, bIsPressed, dwWidth, dwHeight, rpImage);
		break;
	}

	// If button is pressed then press image also
	if (bIsPressed && m_bIsCheckBox == FALSE)
		rpImage->OffsetRect(1, 1);
} // End of PrepareImageRect

void CButtonRgn::DrawTheIcon(CDC* pDC, BOOL bHasTitle, RECT* rpItem, CRect* rpTitle, BOOL bIsPressed, BOOL bIsDisabled)
{
	BYTE		byIndex		= 0;

	// Select the icon to use
	if ((m_bIsCheckBox && bIsPressed) || (!m_bIsCheckBox && (bIsPressed || m_bMouseOnButton)))
		byIndex = 0;
	else
		byIndex = (m_csIcons[1].hIcon == NULL ? 0 : 1);

	CRect	rImage;
	PrepareImageRect(bHasTitle, rpItem, rpTitle, bIsPressed, m_csIcons[byIndex].dwWidth, m_csIcons[byIndex].dwHeight, &rImage);

	// Ole'!
	pDC->DrawState(	rImage.TopLeft(),
					rImage.Size(), 
					m_csIcons[byIndex].hIcon,
					(bIsDisabled ? DSS_DISABLED : DSS_NORMAL), 
					(CBrush*)NULL);
} // End of DrawTheIcon

void CButtonRgn::DrawTheBitmap(CDC* pDC, BOOL bHasTitle, RECT* rItem, CRect *rCaption, BOOL bIsPressed, BOOL bIsDisabled)
{
	HDC			hdcBmpMem	= NULL;
	HBITMAP		hbmOldBmp	= NULL;
	HDC			hdcMem		= NULL;
	HBITMAP		hbmT		= NULL;

	BYTE		byIndex		= 0;

	// Select the bitmap to use
	if ((m_bIsCheckBox && bIsPressed) || (!m_bIsCheckBox && (bIsPressed || m_bMouseOnButton)))
		byIndex = 0;
	else
		byIndex = (m_csBitmaps[1].hBitmap == NULL ? 0 : 1);

	CRect	rImage;
	PrepareImageRect(bHasTitle, rItem, rCaption, bIsPressed, m_csBitmaps[byIndex].dwWidth, m_csBitmaps[byIndex].dwHeight, &rImage);

	hdcBmpMem = ::CreateCompatibleDC(pDC->m_hDC);

	hbmOldBmp = (HBITMAP)::SelectObject(hdcBmpMem, m_csBitmaps[byIndex].hBitmap);

	hdcMem = ::CreateCompatibleDC(NULL);

	hbmT = (HBITMAP)::SelectObject(hdcMem, m_csBitmaps[byIndex].hMask);

	if (bIsDisabled && m_bShowDisabledBitmap)
	{
		HDC		hDC = NULL;
		HBITMAP	hBitmap = NULL;

		hDC = ::CreateCompatibleDC(pDC->m_hDC);
		hBitmap = ::CreateCompatibleBitmap(pDC->m_hDC, m_csBitmaps[byIndex].dwWidth, m_csBitmaps[byIndex].dwHeight);
		HBITMAP	hOldBmp2 = (HBITMAP)::SelectObject(hDC, hBitmap);

		RECT	rRect;
		rRect.left = 0;
		rRect.top = 0;
		rRect.right = rImage.right + 1;
		rRect.bottom = rImage.bottom + 1;
		::FillRect(hDC, &rRect, (HBRUSH)RGB(255, 255, 255));

		COLORREF crOldColor = ::SetBkColor(hDC, RGB(255,255,255));

		::BitBlt(hDC, 0, 0, m_csBitmaps[byIndex].dwWidth, m_csBitmaps[byIndex].dwHeight, hdcMem, 0, 0, SRCAND);
		::BitBlt(hDC, 0, 0, m_csBitmaps[byIndex].dwWidth, m_csBitmaps[byIndex].dwHeight, hdcBmpMem, 0, 0, SRCPAINT);

		::SetBkColor(hDC, crOldColor);
		::SelectObject(hDC, hOldBmp2);
		::DeleteDC(hDC);

		pDC->DrawState(	CPoint(rImage.left/*+1*/, rImage.top), 
						CSize(m_csBitmaps[byIndex].dwWidth, m_csBitmaps[byIndex].dwHeight), 
						hBitmap, DST_BITMAP | DSS_DISABLED);

		::DeleteObject(hBitmap);
	} // if
	else
	{
		::BitBlt(pDC->m_hDC, rImage.left, rImage.top, m_csBitmaps[byIndex].dwWidth, m_csBitmaps[byIndex].dwHeight, hdcMem, 0, 0, SRCAND);

		::BitBlt(pDC->m_hDC, rImage.left, rImage.top, m_csBitmaps[byIndex].dwWidth, m_csBitmaps[byIndex].dwHeight, hdcBmpMem, 0, 0, SRCPAINT);
	} // else

	::SelectObject(hdcMem, hbmT);
	::DeleteDC(hdcMem);

	::SelectObject(hdcBmpMem, hbmOldBmp);
	::DeleteDC(hdcBmpMem);
} // End of DrawTheBitmap

// This function creates a grayscale icon starting from a given icon.
// The resulting icon will have the same size of the original one.
//
// Parameters:
//		[IN]	hIcon
//				Handle to the original icon.
//
// Return value:
//		If the function succeeds, the return value is the handle to the newly created
//		grayscale icon.
//		If the function fails, the return value is NULL.
//
HICON CButtonRgn::CreateGrayscaleIcon(HICON hIcon)
{
	HICON		hGrayIcon = NULL;
	HDC			hMainDC = NULL, hMemDC1 = NULL, hMemDC2 = NULL;
	BITMAP		bmp;
	HBITMAP		hOldBmp1 = NULL, hOldBmp2 = NULL;
	ICONINFO	csII, csGrayII;
	BOOL		bRetValue = FALSE;

	bRetValue = ::GetIconInfo(hIcon, &csII);
	if (bRetValue == FALSE)	return NULL;

	hMainDC = ::GetDC(m_hWnd);
	hMemDC1 = ::CreateCompatibleDC(hMainDC);
	hMemDC2 = ::CreateCompatibleDC(hMainDC);
	if (hMainDC == NULL || hMemDC1 == NULL || hMemDC2 == NULL)	return NULL;
  
	if (::GetObject(csII.hbmColor, sizeof(BITMAP), &bmp))
	{
		csGrayII.hbmColor = ::CreateBitmap(csII.xHotspot*2, csII.yHotspot*2, bmp.bmPlanes, bmp.bmBitsPixel, NULL);
		if (csGrayII.hbmColor)
		{
			hOldBmp1 = (HBITMAP)::SelectObject(hMemDC1, csII.hbmColor);
			hOldBmp2 = (HBITMAP)::SelectObject(hMemDC2, csGrayII.hbmColor);

			::BitBlt(hMemDC2, 0, 0, csII.xHotspot*2, csII.yHotspot*2, hMemDC1, 0, 0, SRCCOPY);

			DWORD		dwLoopY = 0, dwLoopX = 0;
			COLORREF	crPixel = 0;
			BYTE		byNewPixel = 0;

			for (dwLoopY = 0; dwLoopY < csII.yHotspot*2; dwLoopY++)
			{
				for (dwLoopX = 0; dwLoopX < csII.xHotspot*2; dwLoopX++)
				{
					crPixel = ::GetPixel(hMemDC2, dwLoopX, dwLoopY);

					byNewPixel = (BYTE)((GetRValue(crPixel) * 0.299) + (GetGValue(crPixel) * 0.587) + (GetBValue(crPixel) * 0.114));
					if (crPixel)	::SetPixel(hMemDC2, dwLoopX, dwLoopY, RGB(byNewPixel, byNewPixel, byNewPixel));
				} // for
			} // for

			::SelectObject(hMemDC1, hOldBmp1);
			::SelectObject(hMemDC2, hOldBmp2);

			csGrayII.hbmMask = csII.hbmMask;

			csGrayII.fIcon = TRUE;
			hGrayIcon = ::CreateIconIndirect(&csGrayII);
		} // if

		::DeleteObject(csGrayII.hbmColor);
		//::DeleteObject(csGrayII.hbmMask);
	} // if

	::DeleteObject(csII.hbmColor);
	::DeleteObject(csII.hbmMask);
	::DeleteDC(hMemDC1);
	::DeleteDC(hMemDC2);
	::ReleaseDC(m_hWnd, hMainDC);

	return hGrayIcon;
} // End of CreateGrayscaleIcon

// This function assigns icons to the button.
// Any previous icon or bitmap will be removed.
//
// Parameters:
//		[IN]	nIconIn
//				ID number of the icon resource to show when the mouse is over the button.
//				Pass NULL to remove any icon from the button.
//		[IN]	nIconOut
//				ID number of the icon resource to show when the mouse is outside the button.
//				Can be NULL.
//
// Return value:
//		BTNST_OK
//			Function executed successfully.
//		BTNST_INVALIDRESOURCE
//			Failed loading the specified resource.
//
DWORD CButtonRgn::SetIcon(int nIconIn, int nIconOut)
{
	HICON		hIconIn			= NULL;
	HICON		hIconOut		= NULL;
	HINSTANCE	hInstResource	= NULL;

	// Find correct resource handle
	hInstResource = AfxFindResourceHandle(MAKEINTRESOURCE(nIconIn), RT_GROUP_ICON);

	// Set icon when the mouse is IN the button
	hIconIn = (HICON)::LoadImage(hInstResource, MAKEINTRESOURCE(nIconIn), IMAGE_ICON, 0, 0, 0);

  	// Set icon when the mouse is OUT the button
	if (nIconOut)
	{
		if (nIconOut == (int)BTNST_AUTO_GRAY)
			hIconOut = BTNST_AUTO_GRAY;
		else
			hIconOut = (HICON)::LoadImage(hInstResource, MAKEINTRESOURCE(nIconOut), IMAGE_ICON, 0, 0, 0);
	} // if

	return SetIcon(hIconIn, hIconOut);
} // End of SetIcon

// This function assigns icons to the button.
// Any previous icon or bitmap will be removed.
//
// Parameters:
//		[IN]	hIconIn
//				Handle fo the icon to show when the mouse is over the button.
//				Pass NULL to remove any icon from the button.
//		[IN]	hIconOut
//				Handle to the icon to show when the mouse is outside the button.
//				Can be NULL.
//
// Return value:
//		BTNST_OK
//			Function executed successfully.
//		BTNST_INVALIDRESOURCE
//			Failed loading the specified resource.
//
DWORD CButtonRgn::SetIcon(HICON hIconIn, HICON hIconOut)
{
	BOOL		bRetValue;
	ICONINFO	ii;

	// Free any loaded resource
	FreeResources();

	if (hIconIn)
	{
		// Icon when mouse over button?
		m_csIcons[0].hIcon = hIconIn;
		// Get icon dimension
		::ZeroMemory(&ii, sizeof(ICONINFO));
		bRetValue = ::GetIconInfo(hIconIn, &ii);
		if (bRetValue == FALSE)
		{
			FreeResources();
			return BTNST_INVALIDRESOURCE;
		} // if

		m_csIcons[0].dwWidth	= (DWORD)(ii.xHotspot * 2);
		m_csIcons[0].dwHeight	= (DWORD)(ii.yHotspot * 2);
		::DeleteObject(ii.hbmMask);
		::DeleteObject(ii.hbmColor);

		// Icon when mouse outside button?
		if (hIconOut)
		{
			if (hIconOut == BTNST_AUTO_GRAY)
			{
				hIconOut = CreateGrayscaleIcon(hIconIn);
			} // if

			m_csIcons[1].hIcon = hIconOut;
			// Get icon dimension
			::ZeroMemory(&ii, sizeof(ICONINFO));
			bRetValue = ::GetIconInfo(hIconOut, &ii);
			if (bRetValue == FALSE)
			{
				FreeResources();
				return BTNST_INVALIDRESOURCE;
			} // if

			m_csIcons[1].dwWidth	= (DWORD)(ii.xHotspot * 2);
			m_csIcons[1].dwHeight	= (DWORD)(ii.yHotspot * 2);
			::DeleteObject(ii.hbmMask);
			::DeleteObject(ii.hbmColor);
		} // if
	} // if

	Invalidate();

	return BTNST_OK;
} // End of SetIcon

// This function assigns bitmaps to the button.
// Any previous icon or bitmap will be removed.
//
// Parameters:
//		[IN]	nBitmapIn
//				ID number of the bitmap resource to show when the mouse is over the button.
//				Pass NULL to remove any bitmap from the button.
//		[IN]	crTransColorIn
//				Color (inside nBitmapIn) to be used as transparent color.
//		[IN]	nBitmapOut
//				ID number of the bitmap resource to show when the mouse is outside the button.
//				Can be NULL.
//		[IN]	crTransColorOut
//				Color (inside nBitmapOut) to be used as transparent color.
//
// Return value:
//		BTNST_OK
//			Function executed successfully.
//		BTNST_INVALIDRESOURCE
//			Failed loading the specified resource.
//		BTNST_FAILEDMASK
//			Failed creating mask bitmap.
//
DWORD CButtonRgn::SetBitmaps(int nBitmapIn, COLORREF crTransColorIn, int nBitmapOut, COLORREF crTransColorOut)
{
	HBITMAP		hBitmapIn		= NULL;
	HBITMAP		hBitmapOut		= NULL;
	HINSTANCE	hInstResource	= NULL;
	
	// Find correct resource handle
	hInstResource = AfxFindResourceHandle(MAKEINTRESOURCE(nBitmapIn), RT_BITMAP);

	// Load bitmap In
	hBitmapIn = (HBITMAP)::LoadImage(hInstResource, MAKEINTRESOURCE(nBitmapIn), IMAGE_BITMAP, 0, 0, 0);

	// Load bitmap Out
	if (nBitmapOut)
		hBitmapOut = (HBITMAP)::LoadImage(hInstResource, MAKEINTRESOURCE(nBitmapOut), IMAGE_BITMAP, 0, 0, 0);

	return SetBitmaps(hBitmapIn, crTransColorIn, hBitmapOut, crTransColorOut);
} // End of SetBitmaps

// This function assigns bitmaps to the button.
// Any previous icon or bitmap will be removed.
//
// Parameters:
//		[IN]	hBitmapIn
//				Handle fo the bitmap to show when the mouse is over the button.
//				Pass NULL to remove any bitmap from the button.
//		[IN]	crTransColorIn
//				Color (inside hBitmapIn) to be used as transparent color.
//		[IN]	hBitmapOut
//				Handle to the bitmap to show when the mouse is outside the button.
//				Can be NULL.
//		[IN]	crTransColorOut
//				Color (inside hBitmapOut) to be used as transparent color.
//
// Return value:
//		BTNST_OK
//			Function executed successfully.
//		BTNST_INVALIDRESOURCE
//			Failed loading the specified resource.
//		BTNST_FAILEDMASK
//			Failed creating mask bitmap.
//
DWORD CButtonRgn::SetBitmaps(HBITMAP hBitmapIn, COLORREF crTransColorIn, HBITMAP hBitmapOut, COLORREF crTransColorOut)
{
	int		nRetValue;
	BITMAP	csBitmapSize;

	// Free any loaded resource
	FreeResources();

	if (hBitmapIn)
	{
		m_csBitmaps[0].hBitmap = hBitmapIn;
		m_csBitmaps[0].crTransparent = crTransColorIn;
		// Get bitmap size
		nRetValue = ::GetObject(hBitmapIn, sizeof(csBitmapSize), &csBitmapSize);
		if (nRetValue == 0)
		{
			FreeResources();
			return BTNST_INVALIDRESOURCE;
		} // if
		m_csBitmaps[0].dwWidth = (DWORD)csBitmapSize.bmWidth;
		m_csBitmaps[0].dwHeight = (DWORD)csBitmapSize.bmHeight;

		// Create mask for bitmap In
		m_csBitmaps[0].hMask = CreateBitmapMask(hBitmapIn, m_csBitmaps[0].dwWidth, m_csBitmaps[0].dwHeight, crTransColorIn);
		if (m_csBitmaps[0].hMask == NULL)
		{
			FreeResources();
			return BTNST_FAILEDMASK;
		} // if

		if (hBitmapOut)
		{
			m_csBitmaps[1].hBitmap = hBitmapOut;
			m_csBitmaps[1].crTransparent = crTransColorOut;
			// Get bitmap size
			nRetValue = ::GetObject(hBitmapOut, sizeof(csBitmapSize), &csBitmapSize);
			if (nRetValue == 0)
			{
				FreeResources();
				return BTNST_INVALIDRESOURCE;
			} // if
			m_csBitmaps[1].dwWidth = (DWORD)csBitmapSize.bmWidth;
			m_csBitmaps[1].dwHeight = (DWORD)csBitmapSize.bmHeight;

			// Create mask for bitmap Out
			m_csBitmaps[1].hMask = CreateBitmapMask(hBitmapOut, m_csBitmaps[1].dwWidth, m_csBitmaps[1].dwHeight, crTransColorOut);
			if (m_csBitmaps[1].hMask == NULL)
			{
				FreeResources();
				return BTNST_FAILEDMASK;
			} // if
		} // if
	} // if

	Invalidate();

	return BTNST_OK;
} // End of SetBitmaps

// This functions sets the button to have a standard or flat style.
//
// Parameters:
//		[IN]	bFlat
//				If TRUE the button will have a flat style, else
//				will have a standard style.
//				By default, CButtonRgn buttons are flat.
//		[IN]	bRepaint
//				If TRUE the control will be repainted.
//
// Return value:
//		BTNST_OK
//			Function executed successfully.
//
DWORD CButtonRgn::SetFlat(BOOL bFlat, BOOL bRepaint)
{
	m_bIsFlat = bFlat;
	if (bRepaint)	Invalidate();

	return BTNST_OK;
} // End of SetFlat

// This function sets the alignment type between icon/bitmap and text.
//
// Parameters:
//		[IN]	byAlign
//				Alignment type. Can be one of the following values:
//				ST_ALIGN_HORIZ			Icon/bitmap on the left, text on the right
//				ST_ALIGN_VERT			Icon/bitmap on the top, text on the bottom
//				ST_ALIGN_HORIZ_RIGHT	Icon/bitmap on the right, text on the left
//				By default, CButtonRgn buttons have ST_ALIGN_HORIZ alignment.
//		[IN]	bRepaint
//				If TRUE the control will be repainted.
//
// Return value:
//		BTNST_OK
//			Function executed successfully.
//		BTNST_INVALIDALIGN
//			Alignment type not supported.
//
DWORD CButtonRgn::SetAlign(BYTE byAlign, BOOL bRepaint)
{
	switch (byAlign)
	{    
		case ST_ALIGN_HORIZ:
		case ST_ALIGN_HORIZ_RIGHT:
		case ST_ALIGN_VERT:
			m_byAlign = byAlign;
			if (bRepaint)	Invalidate();
			return BTNST_OK;
			break;
	} // switch

	return BTNST_INVALIDALIGN;
} // End of SetAlign

// This function sets the state of the checkbox.
// If the button is not a checkbox, this function has no meaning.
//
// Parameters:
//		[IN]	nCheck
//				1 to check the checkbox.
//				0 to un-check the checkbox.
//		[IN]	bRepaint
//				If TRUE the control will be repainted.
//
// Return value:
//		BTNST_OK
//			Function executed successfully.
//
DWORD CButtonRgn::SetCheck(int nCheck, BOOL bRepaint)
{
	if (m_bIsCheckBox)
	{
		if (nCheck == 0) m_nCheck = 0;
		else m_nCheck = 1;

		if (bRepaint) Invalidate();
	} // if

	return BTNST_OK;
} // End of SetCheck

// This function returns the current state of the checkbox.
// If the button is not a checkbox, this function has no meaning.
//
// Return value:
//		The current state of the checkbox.
//			1 if checked.
//			0 if not checked or the button is not a checkbox.
//
int CButtonRgn::GetCheck()
{
	return m_nCheck;
} // End of GetCheck


void CButtonRgn::SetBtnTextColor(COLORREF rcText)	
{
	m_crTextColor = rcText;
	Invalidate();
}

COLORREF CButtonRgn::GetTextColor(COLORREF rcText)
{
	if (m_crTextColor == 0xFFFFFFFF)
	{
		return rcText;
	}
	else
	{
		return m_crTextColor;
	}
}

// This function sets all colors to a default value.
//
// Parameters:
//		[IN]	bRepaint
//				If TRUE the control will be repainted.
//
// Return value:
//		BTNST_OK
//			Function executed successfully.
//
DWORD CButtonRgn::SetDefaultColors(BOOL bRepaint)
{
	m_crColors[BTNST_COLOR_BK_IN]		= ::GetSysColor(COLOR_BTNFACE);
	m_crColors[BTNST_COLOR_FG_IN]		= ::GetSysColor(COLOR_BTNTEXT);
	m_crColors[BTNST_COLOR_BK_OUT]		= ::GetSysColor(COLOR_BTNFACE);
	m_crColors[BTNST_COLOR_FG_OUT]		= ::GetSysColor(COLOR_BTNTEXT);
	m_crColors[BTNST_COLOR_BK_FOCUS]	= ::GetSysColor(COLOR_BTNFACE);
	m_crColors[BTNST_COLOR_FG_FOCUS]	= ::GetSysColor(COLOR_BTNTEXT);

	if (bRepaint)	Invalidate();

	return BTNST_OK;
} // End of SetDefaultColors

// This function sets the color to use for a particular state.
//
// Parameters:
//		[IN]	byColorIndex
//				Index of the color to set. Can be one of the following values:
//				BTNST_COLOR_BK_IN		Background color when mouse is over the button
//				BTNST_COLOR_FG_IN		Text color when mouse is over the button
//				BTNST_COLOR_BK_OUT		Background color when mouse is outside the button
//				BTNST_COLOR_FG_OUT		Text color when mouse is outside the button
//				BTNST_COLOR_BK_FOCUS	Background color when the button is focused
//				BTNST_COLOR_FG_FOCUS	Text color when the button is focused
//		[IN]	crColor
//				New color.
//		[IN]	bRepaint
//				If TRUE the control will be repainted.
//
// Return value:
//		BTNST_OK
//			Function executed successfully.
//		BTNST_INVALIDINDEX
//			Invalid color index.
//
DWORD CButtonRgn::SetColor(BYTE byColorIndex, COLORREF crColor, BOOL bRepaint)
{
	if (byColorIndex >= BTNST_MAX_COLORS)	return BTNST_INVALIDINDEX;

	// Set new color
	m_crColors[byColorIndex] = crColor;

	if (bRepaint)	Invalidate();

	return BTNST_OK;
} // End of SetColor

// This functions returns the color used for a particular state.
//
// Parameters:
//		[IN]	byColorIndex
//				Index of the color to get.
//				See SetColor for the list of available colors.
//		[OUT]	crpColor
//				A pointer to a COLORREF that will receive the color.
//
// Return value:
//		BTNST_OK
//			Function executed successfully.
//		BTNST_INVALIDINDEX
//			Invalid color index.
//
DWORD CButtonRgn::GetColor(BYTE byColorIndex, COLORREF* crpColor)
{
	if (byColorIndex >= BTNST_MAX_COLORS)	return BTNST_INVALIDINDEX;

	// Get color
	*crpColor = m_crColors[byColorIndex];

	return BTNST_OK;
} // End of GetColor

// This function applies an offset to the RGB components of the specified color.
// This function can be seen as an easy way to make a color darker or lighter than
// its default value.
//
// Parameters:
//		[IN]	byColorIndex
//				Index of the color to set.
//				See SetColor for the list of available colors.
//		[IN]	shOffsetColor
//				A short value indicating the offset to apply to the color.
//				This value must be between -255 and 255.
//		[IN]	bRepaint
//				If TRUE the control will be repainted.
//
// Return value:
//		BTNST_OK
//			Function executed successfully.
//		BTNST_INVALIDINDEX
//			Invalid color index.
//		BTNST_BADPARAM
//			The specified offset is out of range.
//
DWORD CButtonRgn::OffsetColor(BYTE byColorIndex, short shOffset, BOOL bRepaint)
{
	BYTE	byRed = 0;
	BYTE	byGreen = 0;
	BYTE	byBlue = 0;
	short	shOffsetR = shOffset;
	short	shOffsetG = shOffset;
	short	shOffsetB = shOffset;

	if (byColorIndex >= BTNST_MAX_COLORS)	return BTNST_INVALIDINDEX;
	if (shOffset < -255 || shOffset > 255)	return BTNST_BADPARAM;

	// Get RGB components of specified color
	byRed = GetRValue(m_crColors[byColorIndex]);
	byGreen = GetGValue(m_crColors[byColorIndex]);
	byBlue = GetBValue(m_crColors[byColorIndex]);

	// Calculate max. allowed real offset
	if (shOffset > 0)
	{
		if (byRed + shOffset > 255)		shOffsetR = 255 - byRed;
		if (byGreen + shOffset > 255)	shOffsetG = 255 - byGreen;
		if (byBlue + shOffset > 255)	shOffsetB = 255 - byBlue;

		shOffset = min(min(shOffsetR, shOffsetG), shOffsetB);
	} // if
	else
	{
		if (byRed + shOffset < 0)		shOffsetR = -byRed;
		if (byGreen + shOffset < 0)		shOffsetG = -byGreen;
		if (byBlue + shOffset < 0)		shOffsetB = -byBlue;

		shOffset = max(max(shOffsetR, shOffsetG), shOffsetB);
	} // else

	// Set new color
	m_crColors[byColorIndex] = RGB(byRed + shOffset, byGreen + shOffset, byBlue + shOffset);

	if (bRepaint)	Invalidate();

	return BTNST_OK;
} // End of OffsetColor

// This function sets the hilight logic for the button.
// Applies only to flat buttons.
//
// Parameters:
//		[IN]	bAlwaysTrack
//				If TRUE the button will be hilighted even if the window that owns it, is
//				not the active window.
//				If FALSE the button will be hilighted only if the window that owns it,
//				is the active window.
//
// Return value:
//		BTNST_OK
//			Function executed successfully.
//
DWORD CButtonRgn::SetAlwaysTrack(BOOL bAlwaysTrack)
{
	m_bAlwaysTrack = bAlwaysTrack;
	return BTNST_OK;
} // End of SetAlwaysTrack

// This function sets the cursor to be used when the mouse is over the button.
//
// Parameters:
//		[IN]	nCursorId
//				ID number of the cursor resource.
//				Pass NULL to remove a previously loaded cursor.
//		[IN]	bRepaint
//				If TRUE the control will be repainted.
//
// Return value:
//		BTNST_OK
//			Function executed successfully.
//		BTNST_INVALIDRESOURCE
//			Failed loading the specified resource.
//
DWORD CButtonRgn::SetBtnCursor(int nCursorId, BOOL bRepaint)
{
	HINSTANCE	hInstResource = NULL;
	// Destroy any previous cursor
	if (m_hCursor)
	{
		::DestroyCursor(m_hCursor);
		m_hCursor = NULL;
	} // if

	// Load cursor
	if (nCursorId)
	{
		hInstResource = AfxFindResourceHandle(MAKEINTRESOURCE(nCursorId), RT_GROUP_CURSOR);
		// Load cursor resource
		m_hCursor = (HCURSOR)::LoadImage(hInstResource, MAKEINTRESOURCE(nCursorId), IMAGE_CURSOR, 0, 0, 0);
		// Repaint the button
		if (bRepaint) Invalidate();
		// If something wrong
		if (m_hCursor == NULL) return BTNST_INVALIDRESOURCE;
	} // if

	return BTNST_OK;
} // End of SetBtnCursor

// This function sets if the button border must be drawn.
// Applies only to flat buttons.
//
// Parameters:
//		[IN]	bDrawBorder
//				If TRUE the border will be drawn.
//		[IN]	bRepaint
//				If TRUE the control will be repainted.
//
// Return value:
//		BTNST_OK
//			Function executed successfully.
//
DWORD CButtonRgn::DrawBorder(BOOL bDrawBorder, BOOL bRepaint)
{
	m_bDrawBorder = bDrawBorder;
	// Repaint the button
	if (bRepaint) Invalidate();

	return BTNST_OK;
} // End of DrawBorder

// This function sets if the focus rectangle must be drawn for flat buttons.
//
// Parameters:
//		[IN]	bDrawFlatFocus
//				If TRUE the focus rectangle will be drawn also for flat buttons.
//		[IN]	bRepaint
//				If TRUE the control will be repainted.
//
// Return value:
//		BTNST_OK
//			Function executed successfully.
//
DWORD CButtonRgn::DrawFlatFocus(BOOL bDrawFlatFocus, BOOL bRepaint)
{
	m_bDrawFlatFocus = bDrawFlatFocus;
	// Repaint the button
	if (bRepaint) Invalidate();

	return BTNST_OK;
} // End of DrawFlatFocus

void CButtonRgn::InitToolTip()
{
	if (m_ToolTip.m_hWnd == NULL)
	{
		// Create ToolTip control
		m_ToolTip.Create(this);
		// Create inactive
		m_ToolTip.Activate(FALSE);
		// Enable multiline
		m_ToolTip.SendMessage(TTM_SETMAXTIPWIDTH, 0, 400);
	} // if
} // End of InitToolTip

// This function sets the text to show in the button tooltip.
//
// Parameters:
//		[IN]	nText
//				ID number of the string resource containing the text to show.
//		[IN]	bActivate
//				If TRUE the tooltip will be created active.
//
void CButtonRgn::SetTooltipText(int nText, BOOL bActivate)
{
	CString sText;

	// Load string resource
	sText.LoadString(nText);
	// If string resource is not empty
	if (sText.IsEmpty() == FALSE) SetTooltipText((LPCTSTR)sText, bActivate);
} // End of SetTooltipText

// This function sets the text to show in the button tooltip.
//
// Parameters:
//		[IN]	lpszText
//				Pointer to a null-terminated string containing the text to show.
//		[IN]	bActivate
//				If TRUE the tooltip will be created active.
//
void CButtonRgn::SetTooltipText(LPCTSTR lpszText, BOOL bActivate)
{
	// We cannot accept NULL pointer
	if (lpszText == NULL) return;

	// Initialize ToolTip
	InitToolTip();

	// If there is no tooltip defined then add it
	if (m_ToolTip.GetToolCount() == 0)
	{
		CRect rectBtn; 
		GetClientRect(rectBtn);
		m_ToolTip.AddTool(this, lpszText, rectBtn, 1);
	} // if

	// Set text for tooltip
	m_ToolTip.UpdateTipText(lpszText, this, 1);
	m_ToolTip.Activate(bActivate);
} // End of SetTooltipText

// This function enables or disables the button tooltip.
//
// Parameters:
//		[IN]	bActivate
//				If TRUE the tooltip will be activated.
//
void CButtonRgn::ActivateTooltip(BOOL bActivate)
{
	// If there is no tooltip then do nothing
	if (m_ToolTip.GetToolCount() == 0) return;

	// Activate tooltip
	m_ToolTip.Activate(bActivate);
} // End of EnableTooltip

// This function returns if the button is the default button.
//
// Return value:
//		TRUE
//			The button is the default button.
//		FALSE
//			The button is not the default button.
//
BOOL CButtonRgn::GetDefault()
{
	return m_bIsDefault;
} // End of GetDefault

// This function enables the transparent mode.
// Note: this operation is not reversible.
// DrawTransparent should be called just after the button is created.
// Do not use trasparent buttons until you really need it (you have a bitmapped
// background) since each transparent button makes a copy in memory of its background.
// This may bring unnecessary memory use and execution overload.
//
// Parameters:
//		[IN]	bRepaint
//				If TRUE the control will be repainted.
//
void CButtonRgn::DrawTransparent(BOOL bRepaint)
{
	m_bDrawTransparent = TRUE;

	// Restore old bitmap (if any)
	if (m_dcBk.m_hDC != NULL && m_pbmpOldBk != NULL)
	{
		m_dcBk.SelectObject(m_pbmpOldBk);
	} // if

	m_bmpBk.DeleteObject();
	m_dcBk.DeleteDC();

	// Repaint the button
	if (bRepaint) Invalidate();
} // End of DrawTransparent

// This function sets the URL that will be opened when the button is clicked.
//
// Parameters:
//		[IN]	lpszURL
//				Pointer to a null-terminated string that contains the URL.
//				Pass NULL to removed any previously specified URL.
//
// Return value:
//		BTNST_OK
//			Function executed successfully.
//
DWORD CButtonRgn::SetURL(LPCTSTR lpszURL)
{
	// Remove any existing URL
	memset(m_szURL, 0, sizeof(m_szURL));

	if (lpszURL)
	{
		// Store the URL
		_tcsncpy(m_szURL, lpszURL, _MAX_PATH);
	} // if

	return BTNST_OK;
} // End of SetURL

// This function is called every time the button background needs to be painted.
// If the button is in transparent mode this function will NOT be called.
// This is a virtual function that can be rewritten in CButtonRgn-derived classes
// to produce a whole range of buttons not available by default.
//
// Parameters:
//		[IN]	pDC
//				Pointer to a CDC object that indicates the device context.
//		[IN]	pRect
//				Pointer to a CRect object that indicates the bounds of the
//				area to be painted.
//
// Return value:
//		BTNST_OK
//			Function executed successfully.
//
DWORD CButtonRgn::OnDrawBackground(CDC* pDC, LPCRECT pRect)
{
	COLORREF	crColor;

	if (m_bMouseOnButton || m_bIsPressed)
		crColor = m_crColors[BTNST_COLOR_BK_IN];
	else
	{
		if (m_bIsFocused)
			crColor = m_crColors[BTNST_COLOR_BK_FOCUS];
		else
			crColor = m_crColors[BTNST_COLOR_BK_OUT];
	} // else

	CBrush		brBackground(crColor);

	pDC->FillRect(pRect, &brBackground);

	return BTNST_OK;
} // End of OnDrawBackground

// This function is called every time the button border needs to be painted.
// If the button is in standard (not flat) mode this function will NOT be called.
// This is a virtual function that can be rewritten in CButtonRgn-derived classes
// to produce a whole range of buttons not available by default.
//
// Parameters:
//		[IN]	pDC
//				Pointer to a CDC object that indicates the device context.
//		[IN]	pRect
//				Pointer to a CRect object that indicates the bounds of the
//				area to be painted.
//
// Return value:
//		BTNST_OK
//			Function executed successfully.
//
DWORD CButtonRgn::OnDrawBorder(CDC* pDC, LPCRECT pRect)
{
	CBrush br(RGB(128,128,128));  
	CBrush br3(RGB(192,192,192));  
	CBrush br2(RGB(240,240,240));  

	if (m_bIsPressed)
	{
		pDC->Draw3dRect(pRect, ::GetSysColor(COLOR_BTNSHADOW), ::GetSysColor(COLOR_BTNHILIGHT));
		//pDC->FrameRect(pRect, &br);
	}
	else
	{
		//pDC->Draw3dRect(pRect, ::GetSysColor(COLOR_BTNHILIGHT), ::GetSysColor(COLOR_BTNSHADOW));
		if(m_bMouseOnButton)
			pDC->FrameRect(pRect, &br2);
		else
			pDC->FrameRect(pRect, &br3);
	}
	return BTNST_OK;
} // End of OnDrawBorder

#undef BS_TYPEMASK
