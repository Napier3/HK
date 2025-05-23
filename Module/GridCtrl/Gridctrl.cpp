// GridCtrl.cpp : implementation file

#include "stdafx.h"
#include "GridCtrl.h"
#include "GridEdit.h"
#include "GridComboBox.h"
#include "GridHexEdit.h"
//#include "GridBinaryEdit.h"
#include "GridMacEdit.h"

#include "..\API\StringApi.h"
#include "..\API\GloblaDrawFunctions.h"

// OLE stuff for clipboard operations
#include <afxadv.h>            // For CSharedFile
#include <afxole.h>            // For COleDataSource
#include <afxconv.h>           // For LPTSTR -> LPSTR macros


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define HEADER_HEIGHT       2    // For printing
#define FOOTER_HEIGHT       2
#define LEFT_MARGIN         4
#define RIGHT_MARGIN        4
#define TOP_MARGIN          1
#define BOTTOM_MARGIN       1 
#define GAP                 1

#define IDC_INPLACE_EDIT            8    // ID of inplace edit controls
///////////////////////////////////////////////////////////////////////////////////
//添加		2001年8月27日
#define IDC_INPLACE_COMBOBOX		9	 // ID of inplace combobox controls..
//添加		2001年8月27日
////////////////////////////////////////////////////////////////////////////////////


// Get the number of lines to scroll with each mouse wheel notch
// Why doesn't windows give us this function???
UINT GetMouseScrollLines()
{
	int nScrollLines = 3;            // reasonable default
	HKEY hKey;

	if (RegOpenKeyEx(HKEY_CURRENT_USER,  _T("Control Panel\\Desktop"),
		0, KEY_QUERY_VALUE, &hKey) == ERROR_SUCCESS)
	{
		TCHAR szData[128];
		DWORD dwKeyDataType;
		DWORD dwDataBufSize = sizeof(szData);

		if (RegQueryValueEx(hKey, _T("WheelScrollLines"), NULL, &dwKeyDataType,
			(LPBYTE) &szData, &dwDataBufSize) == ERROR_SUCCESS)
		{
			nScrollLines = _tcstoul(szData, NULL, 10);
		}
		RegCloseKey(hKey);
	}

	return nScrollLines;
}

//////////////////////////////////////////////////////////////////////////
// CGridCell
//////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CXGridCtrlBase
//////////////////////////////////////////////////////////////////////////////
//						//添加		2001年8月27日
CFont* CXGridCtrlBase::msg_OnGetFont(WPARAM hFont, LPARAM lParam)
{
	return CFont::FromHandle((HFONT)OnGetFont(hFont, lParam));
}

void CXGridCtrlBase::msg_OnEndInPlaceEdit(NMHDR* pNMHDR, LRESULT* pResult)
{
	OnEndInPlaceEdit(pNMHDR, pResult);
}

void CXGridCtrlBase::msg_OnEndPointEdit(NMHDR* pNMHDR, LRESULT* pResult)
{
	OnEndPointEdit(pNMHDR, pResult);
}

void CXGridCtrlBase::msg_OnEndInplaceComboBoxEdit(NMHDR* pNMHDR, LRESULT* pResult)
{
	OnEndInplaceComboBoxEdit(pNMHDR, pResult);
}


LRESULT CXGridCtrlBase::msg_OnFillComboBox(WPARAM nColumn, LPARAM pListBox)
{
	return OnFillComboBox(nColumn, pListBox);
}

LRESULT CXGridCtrlBase::msg_OnFillList(WPARAM nColumn, LPARAM pListBox)
{
	OnFillList(nColumn, pListBox);
	return 0;
}

LRESULT CXGridCtrlBase::msg_OnFillTree(WPARAM nColumn, LPARAM pListBox)
{
	OnFillTree(nColumn, pListBox);
	return 0;
}

LRESULT CXGridCtrlBase::msg_OnFillTimeCtrl(WPARAM nColumn, LPARAM pListBox)
{
	OnFillTimeCtrl(nColumn, pListBox);
	return 0;
}

void CXGridCtrlBase::CreateTitleTip()
{
	
}

GRIDEDIT_FORMAT CXGridCtrlBase::GetEditFormat(int nRow, int nCol)
{
	return GEFM_NONE;
}

void CXGridCtrlBase::FillComboBoxItems(int nRow, int nCol, LPARAM lParam)
{

}
void CXGridCtrlBase::FillListItems(int nCol, LPARAM cltList)
{
	// do nothing for now
}
void CXGridCtrlBase::FillTreeItems(int nCol, LPARAM cltList)
{
	// do nothing for now
}
void CXGridCtrlBase::FillTimeCtrlItems(int nCol, LPARAM cltList)
{
	// do nothing for now
}

////添加		2001年8月27日
//////////////////////////////////////////////////////////////////////////







CXGridCtrlBase::CXGridCtrlBase(int nRows, int nCols, int nFixedRows, int nFixedCols)
{
	//2021-6-3  lijunqing 
	m_crHighLight = ::GetSysColor(COLOR_HIGHLIGHT);
	m_crHighLightText = ::GetSysColor(COLOR_HIGHLIGHTTEXT);
	m_cr3DHighLight = ::GetSysColor(COLOR_3DHIGHLIGHT);
	m_cr3DDKShadow = ::GetSysColor(COLOR_3DDKSHADOW);

	m_pViewWindowPos = NULL;
	RegisterWindowClass();

	m_posTopLeft.x = 0;
	m_posTopLeft.y = 0;
	m_pGridRefWnd = NULL;

	// Initialize OLE libraries
	m_bMustUninitOLE = FALSE;


	// Store the system colours in case they change. The gridctrl uses
	// these colours, and in OnSysColorChange we can check to see if 
	// the gridctrl colours have been changed from the system colours.
	// If they have, then leave them, otherwise change them to reflect
	// the new system colours.
	m_crWindowText       = ::GetSysColor(COLOR_WINDOWTEXT);
	m_crWindowColour     = ::GetSysColor(COLOR_WINDOW);
	m_cr3DFace           = ::GetSysColor(COLOR_3DFACE);
	m_crShadow           = ::GetSysColor(COLOR_3DSHADOW);
	m_crGridColour       = RGB(0,0,0);

	m_nRows              = 0;
	m_nCols              = 0;
	m_nFixedRows         = 0;
	m_nFixedCols         = 0;

	m_nDefCellWidth      = 10;        // These will get changed to something meaningful
	m_nDefCellHeight     = 20;        //    when the window is created or subclassed

	m_nVScrollMax        = 0;         // Scroll position
	m_nHScrollMax        = 0;
	m_nMargin            = 4;         // cell padding
	m_nRowsPerWheelNotch = GetMouseScrollLines(); // Get the number of lines
	// per mouse wheel notch to scroll

	m_MouseMode          = MOUSE_NOTHING;
	m_nGridLines         = GVL_BOTH;
	m_bEditable          = TRUE;
	m_bListMode          = FALSE;
	m_bAllowDraw         = TRUE;      // allow draw updates
	m_bEnableSelection   = TRUE;
	m_bAllowRowResize    = TRUE;
	m_bAllowColumnResize = TRUE;
	m_bSortOnClick       = FALSE;      // Sort on header row click if in list mode
	m_bHandleTabKey      = TRUE;
	m_bDoubleBuffer      = TRUE;      // Use double buffering to avoid flicker?
	m_bTitleTips         = TRUE;      // show cell title tips

	m_bAscending         = TRUE;      // sorting stuff
	m_SortColumn         = -1;

	m_nTimerID           = 0;         // For drag-selection
	m_nTimerInterval     = 25;        // (in milliseconds)
	m_nResizeCaptureRange = 3;        // When resizing columns/row, the cursor has to be 
	// within +/-3 pixels of the dividing line for 
	// resizing to be possible
	m_pImageList         = NULL;      
	m_bAllowDragAndDrop  = FALSE;     // for drag and drop

	// Initially use the system message font for the GridCtrl font
	//     NONCLIENTMETRICS ncm;
	//     ncm.cbSize = sizeof(NONCLIENTMETRICS);
	//     VERIFY(SystemParametersInfo(SPI_GETNONCLIENTMETRICS, sizeof(NONCLIENTMETRICS), &ncm, 0));    
	//     memcpy(&m_Logfont, &(ncm.lfMessageFont), sizeof(LOGFONT));
	m_Logfont = InitLogFont();
	m_Logfont.lfHeight = 14;

#ifdef UNICODE
	wcscpy(m_Logfont.lfFaceName, _T("Tohoma"));
#else
	strcpy(m_Logfont.lfFaceName, "Tahoma");
#endif

	m_Font.DeleteObject();
	m_Font.CreateFontIndirect(&m_Logfont);

	// Set up the initial grid size
	SetRowCount(nRows);
	SetColumnCount(nCols);
	SetFixedRowCount(nFixedRows);
	SetFixedColumnCount(nFixedCols);

	// Set the colours
	SetTextColor(m_crWindowText);
	SetTextBkColor(m_crWindowColour);
	SetBkColor(m_crShadow);
	SetFixedTextColor(m_crWindowText);
	SetFixedBkColor(m_cr3DFace);
	SetUseRButtonDownForSel(FALSE);

	// set initial selection range (ie. none)
	m_SelectedCellMap.RemoveAll();
	m_PrevSelectedCellMap.RemoveAll();

	m_bDrawSelCellFrame = FALSE;
	///////////////
	m_crGridColour = RGB(0,0,0);
	ptGridOrigin.x = 0;
	ptGridOrigin.y = 0;
	m_bModified = TRUE;
	m_LeftClickDownPoint.x = 0;
	m_LeftClickDownPoint.y = 0;
	m_LastMousePoint.x = 0;
	m_LastMousePoint.y = 0;
	m_nPageHeight = 10;
	m_bUseVKDelete = TRUE;

	m_pInplaceEditWnd = NULL;
	m_bInplaceEdit_VKReturn = FALSE;
	m_dwInplaceEditEndTick = 0;

	m_bUseKeyMsg		= TRUE;
	m_bIsReadOnly = FALSE;
}

CXGridCtrlBase::~CXGridCtrlBase()
{
	DeleteAllItems(FALSE);

	//DestroyWindow();

	m_Font.DeleteObject();

	// Uninitialize OLE support
	if (m_bMustUninitOLE)
		::OleUninitialize();
}

// Register the window class if it has not already been registered.
// BOOL CXGridCtrlBase::RegisterWindowClass()
// {
//     WNDCLASS wndcls;
//     HINSTANCE hInst = AfxGetResourceHandle();
// 
//     if (!(::GetClassInfo(hInst, GRIDCTRL_CLASSNAME, &wndcls)))
//     {
//         // otherwise we need to register a new class
//         wndcls.style            = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
//         wndcls.lpfnWndProc      = ::DefWindowProc;
//         wndcls.cbClsExtra       = wndcls.cbWndExtra = 0;
//         wndcls.hInstance        = hInst;
//         wndcls.hIcon            = NULL;
//         wndcls.hCursor          = NULL;
//         wndcls.hbrBackground    = (HBRUSH) (COLOR_3DFACE + 1);
//         wndcls.lpszMenuName     = NULL;
//         wndcls.lpszClassName    = GRIDCTRL_CLASSNAME;
// 
//         if (!AfxRegisterClass(&wndcls)) {
//             AfxThrowResourceException();
//             return FALSE;
//         }
//     }
// 
//     return TRUE;
// }

BOOL CXGridCtrlBase::RegisterWindowClass(HINSTANCE hInstance)  
{  
	WNDCLASS wndcls;  
	// 	HINSTANCE hInst2 = AfxGetInstanceHandle();
	HINSTANCE hInst1 = AfxGetResourceHandle();  
	HINSTANCE hInst = hInstance ? hInstance : hInst1;  
	//HINSTANCE hInst = AfxGetResourceHandle();  
	//HINSTANCE hInst = AfxGetResourceHandle();

	if (!(::GetClassInfo(hInst, GRIDCTRL_CLASSNAME, &wndcls)))  
	{  
		// otherwise we need to register a new class  
		wndcls.style            = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;  
		wndcls.lpfnWndProc      = ::DefWindowProc;  
		wndcls.cbClsExtra       = wndcls.cbWndExtra = 0;  
		wndcls.hInstance        = hInst;  
		wndcls.hIcon            = NULL;  
#ifndef _WIN32_WCE_NO_CURSOR  
		wndcls.hCursor          = AfxGetApp()->LoadStandardCursor(IDC_ARROW);  
#else  
		wndcls.hCursor          = 0;  
#endif  
		wndcls.hbrBackground    = (HBRUSH) (COLOR_3DFACE + 1);  
		wndcls.lpszMenuName     = NULL;  
		wndcls.lpszClassName    = GRIDCTRL_CLASSNAME;  

		if (!AfxRegisterClass(&wndcls))  
		{  
			AfxThrowResourceException();  
			return FALSE;  
		}  
	}  

	return TRUE;  
}  

BOOL CXGridCtrlBase::Create(CWnd* pParentWnd, CPoint ptTopLeft)
{
	m_pGridRefWnd = pParentWnd;
	m_posTopLeft = ptTopLeft;
	ASSERT (m_pGridRefWnd != NULL);
	int i = 0;

	for (i = 0; i < m_nRows; i++)
	{
		SetRowHeight(i, m_nDefCellHeight);
	}

	for (i = 0; i < m_nCols; i++) 
	{
		SetColumnWidth(i, m_nDefCellWidth);
	}

	ResetScrollBars();

	return TRUE;
}

void CXGridCtrlBase::SetGridLines(int nWhichLines) 
{
	ASSERT (m_pGridRefWnd != NULL);

	m_nGridLines = nWhichLines; 

	if (::IsWindow(m_pGridRefWnd->GetSafeHwnd()))
	{
		m_pGridRefWnd->Invalidate();
	}
}

void CXGridCtrlBase::FreeInplaceEditWnd()
{
	ASSERT (m_pGridRefWnd != NULL);
	if (m_pInplaceEditWnd == NULL)
	{
		return;
	}

	m_pGridRefWnd->SetFocus();
}

LRESULT CXGridCtrlBase::SendMessageToParent(int nRow, int nCol, int nMessage)
{
	ASSERT (m_pGridRefWnd != NULL);

	if (!IsWindow(m_pGridRefWnd->m_hWnd))
		return 0;

	NM_GRIDVIEW nmgv;
	nmgv.iRow         = nRow;
	nmgv.iColumn      = nCol;
	nmgv.hdr.hwndFrom = m_pGridRefWnd->m_hWnd;
	nmgv.hdr.idFrom   = m_pGridRefWnd->GetDlgCtrlID();
	nmgv.hdr.code     = nMessage;

	CWnd *pOwner = m_pGridRefWnd->GetOwner();

	if (pOwner)
	{
		if (IsWindow(pOwner->m_hWnd)) 
		{
			return pOwner->SendMessage(WM_NOTIFY, nmgv.hdr.idFrom, (LPARAM)&nmgv);
		}
		else
		{
			return 0;
		}
	}
	else
		return 0;
}

/////////////////////////////////////////////////////////////////////////////
// CXGridCtrlBase message handlers

// Custom background erasure. This gets called from within the OnDraw function,
// since we will (most likely) be using a memory DC to stop flicker. If we just
// erase the background normally through OnEraseBkgnd, and didn't fill the memDC's
// selected bitmap with colour, then all sorts of vis problems would occur
void CXGridCtrlBase::EraseBkgnd(CDC* pDC) 
{
	CRect  VisRect, clipRect, rect;
	CBrush FixedBack(GetFixedBkColor()),
		TextBack(GetTextBkColor()),
		Back(GetBkColor());

	if (GetGridClipRect(pDC, clipRect) == ERROR) return;
	GetVisibleNonFixedCellRange(VisRect);

	// Draw Fixed columns background
	int nFixedColumnWidth = GetFixedColumnWidth() + m_posTopLeft.x;
	if (clipRect.left < nFixedColumnWidth && clipRect.top < VisRect.bottom)
	{
		pDC->FillRect(CRect(clipRect.left, clipRect.top, nFixedColumnWidth, VisRect.bottom),
			&FixedBack);
		//TRACE("\ncolumns background(%d, %d, %d, %d)", ClipRect.left, ClipRect.top, nFixedColumnWidth, VisRect.bottom);
	}

	// Draw Fixed rows background
	int nFixedRowHeight = GetFixedRowHeight()  + m_posTopLeft.y;
	if (clipRect.top < nFixedRowHeight && 
		clipRect.right > nFixedColumnWidth && clipRect.left < VisRect.right)
	{
		pDC->FillRect(CRect(nFixedColumnWidth-1, clipRect.top, VisRect.right, nFixedRowHeight),
			&FixedBack);
		//TRACE("\nFixed rows background(%d, %d, %d, %d)", nFixedColumnWidth-1, ClipRect.top, VisRect.right, nFixedRowHeight);
	}

	// Draw non-fixed cell background
	if (rect.IntersectRect(VisRect, clipRect)) 
	{
		CRect CellRect(max(nFixedColumnWidth, rect.left), max(nFixedRowHeight, rect.top),
			rect.right, rect.bottom);
		pDC->FillRect(CellRect, &TextBack);
		//TRACE("\ncell background(%d, %d, %d, %d)", CellRect.left, ClipRect.top, CellRect.right, CellRect.bottom);
	}

	// Draw right hand side of window outside grid
	if (VisRect.right < clipRect.right) 
	{
		pDC->FillRect(CRect(VisRect.right, clipRect.top, clipRect.right, clipRect.bottom),
			&Back);
		//TRACE("\noutside grid(%d, %d, %d, %d)", VisRect.right, ClipRect.top, ClipRect.right, ClipRect.bottom);
	}

	// Draw bottom of window below grid
	if (VisRect.bottom < clipRect.bottom && clipRect.left < VisRect.right) 
	{
		pDC->FillRect(CRect(clipRect.left, VisRect.bottom, VisRect.right, clipRect.bottom),
			&Back);
		//TRACE("\nbelow grid(%d, %d, %d, %d)", ClipRect.left, VisRect.bottom, VisRect.right, ClipRect.bottom);
	}
}



// For drag-selection. Scrolls hidden cells into view
// TODO: decrease timer interval over time to speed up selection over time


BOOL CXGridCtrlBase::GetNextCell(CCellID &next, BOOL &bChangeLine)
{
	BOOL bTrue = FALSE;

	while (TRUE)
	{
		if (next.col < (GetColumnCount() - 1)) 
		{
			next.col++;
		}
		else if (next.col == (GetColumnCount() - 1) && 
			next.row < (GetRowCount() - 1) )
		{
			next.row++; 
			next.col = m_nFixedCols; 
			bChangeLine = TRUE;
		}
		else
		{
			break;
		}

		CGridCell *pCell = GetCell(next.row, next.col);

		if (pCell == NULL)
		{
			break;
		}

		if (pCell->m_pMergeTo == NULL || pCell->m_pMergeTo == pCell)
		{
			bTrue = TRUE;
			break;
		}
	}

	return bTrue;
}

BOOL CXGridCtrlBase::GetPrevCell(CCellID &next, BOOL &bChangeLine)
{
	BOOL bTrue = FALSE;

	while (TRUE)
	{
		if (next.col > m_nFixedCols) 
		{
			next.col--;
		}
		else if (next.col == m_nFixedCols && next.row > m_nFixedRows) 
		{
			next.row--; 
			next.col = GetColumnCount() - 1; 
			bChangeLine = TRUE;
		}
		else
		{
			break;
		}

		CGridCell *pCell = GetCell(next.row, next.col);

		if (pCell == NULL)
		{
			break;
		}

		if (pCell->m_pMergeTo == NULL || pCell->m_pMergeTo == pCell)
		{
			bTrue = TRUE;
			break;
		}
	}

	return bTrue;
}

BOOL CXGridCtrlBase::GetUpCell(CCellID &next)
{
	BOOL bTrue = FALSE;
	CCellID oCurr = next;

	while (TRUE)
	{
		if (next.row > m_nFixedRows)           
			next.row--; 

		CGridCell *pCell = GetCell(next.row, next.col);

		if (pCell == NULL)
		{
			break;
		}

		if (AdjustCell(oCurr, next, bTrue))
		{
			break;
		}
	}

	return bTrue;
}

BOOL CXGridCtrlBase::GetDownCell(CCellID &next)
{
	BOOL bTrue = FALSE;
	CCellID oCurr = next;

	while (TRUE)
	{
		if (next.row < (GetRowCount() - 1))
			next.row++; 

		CGridCell *pCell = GetCell(next.row, next.col);

		if (pCell == NULL)
		{
			break;
		}

		if (AdjustCell(oCurr, next, bTrue))
		{
			break;
		}

		if (next.row == m_nRows -1)
		{
			break;
		}
	}

	return bTrue;
}

BOOL CXGridCtrlBase::GetLeftCell(CCellID &next)
{
	BOOL bTrue = FALSE;
	CCellID oCurr = next;

	while (TRUE)
	{
		if (next.col > m_nFixedCols)           
		{
			next.col--;  
		}
		else
		{
			break;
		}

		CGridCell *pCell = GetCell(next.row, next.col);

		if (pCell == NULL)
		{
			break;
		}

		if (AdjustCell(oCurr, next, bTrue))
		{
			break;
		}
	}

	return bTrue;
}

BOOL CXGridCtrlBase::GetRightCell(CCellID &next)
{
	BOOL bTrue = FALSE;
	CCellID oCurr = next;

	while (TRUE)
	{
		if (next.col < (GetColumnCount() - 1)) 
			next.col++; 

		CGridCell *pCell = GetCell(next.row, next.col);

		if (pCell == NULL)
		{
			break;
		}

		if (AdjustCell(oCurr, next, bTrue))
		{
			break;
		}

		if (next.col == m_nCols -1)
		{
			break;
		}
	}

	return bTrue;
}

BOOL CXGridCtrlBase::AdjustCell(const CCellID &oCurr, CCellID &next, BOOL &bTrue)
{
	CGridCell *pCell = GetCell(next.row, next.col);

	if (pCell->m_pMergeTo == NULL)
	{
		bTrue = TRUE;
	}
	else
	{
		if (pCell->m_pMergeTo == pCell)
		{
			bTrue = TRUE;
		}
		else
		{
			CCellID oCellID;
			pCell->m_pMergeTo->GetCellID(oCellID.row, oCellID.col);

			if (oCellID == oCurr)
			{
				bTrue = FALSE;
			}
			else
			{
				next = oCellID;
				bTrue = TRUE;
			}
		}
	}

	return bTrue;
}

BOOL CXGridCtrlBase::OnCellKeyDelete(const CCellID &idCell)
{
	return FALSE;
}

UINT CXGridCtrlBase::GetGridClipRect(CDC* pDC, CRect &rcClip)
{
	GetGridClientRect(rcClip);
	rcClip.right++;
	rcClip.bottom++;
	rcClip.left--;
	rcClip.top--;

	return SIMPLEREGION;
}

void CXGridCtrlBase::GetGridClientRect(CRect &rcClient)
{
	rcClient.top = m_posTopLeft.y;
	rcClient.left = m_posTopLeft.x;
	rcClient.right = rcClient.left + GetVirtualWidth();
	rcClient.bottom = rcClient.top + GetVirtualHeight();
	//m_posTopLeft
	ASSERT(m_pGridRefWnd != NULL);

	//m_pGridRefWnd->GetClientRect(&rcClient);
}

void CXGridCtrlBase::GetGridClientRect(CRect &rcClient) const 
{
	rcClient.top = m_posTopLeft.x;
	rcClient.left = m_posTopLeft.y;
	rcClient.right = rcClient.left + GetVirtualWidth();
	rcClient.bottom = rcClient.top + GetVirtualHeight();
}


// CXGridCtrlBase cellrange functions
CCellID CXGridCtrlBase::GetTopleftNonFixedCell() const
{
// 	int nVertScroll = m_pGridRefWnd->GetScrollPos(SB_VERT), 
// 		nHorzScroll = m_pGridRefWnd->GetScrollPos(SB_HORZ);
// 
// 	int nColumn = m_nFixedCols, nRight = 0;
// 	while (nRight < nHorzScroll && nColumn < (GetColumnCount()-1))
// 		nRight += GetColumnWidth(nColumn++);
// 
// 	int nRow = m_nFixedRows, nTop = 0;
// 	while (nTop < nVertScroll && nRow < (GetRowCount()-1))
// 		nTop += GetRowHeight(nRow++);
// 
// 	//TRACE("TopLeft cell is row %d, col %d\n",nRow, nColumn);
// 	return CCellID(nRow, nColumn);
	return CCellID(m_nFixedRows, m_nFixedCols);
}

// This gets even partially visible cells
CGridCellRange CXGridCtrlBase::GetVisibleNonFixedCellRange(LPRECT pRect /*=NULL*/) const
{
	CRect rect;
	int i = 0;

	GetGridClientRect(rect);

	CCellID idTopLeft = GetTopleftNonFixedCell();

	// calc bottom
	int bottom = GetFixedRowHeight();
	for (i = idTopLeft.row; i < GetRowCount(); i++)
	{
		bottom += GetRowHeight(i);
// 		if (bottom >= rect.bottom)
// 		{
// 			bottom = rect.bottom;
// 			break;
// 		}
	}                                
	int maxVisibleRow = GetRowCount() - 1;//min(i, GetRowCount() - 1);

	// calc right
	int right = GetFixedColumnWidth();
	for (i = idTopLeft.col; i < GetColumnCount(); i++)
	{
		right += GetColumnWidth(i);
// 		if (right >= rect.right) {
// 			right = rect.right;
// 			break;
// 		}
	}
	int maxVisibleCol = GetColumnCount() - 1;//min(i, GetColumnCount() - 1);
	
	if (pRect) 
	{
		pRect->left = pRect->top = 0;
		pRect->right = right;
		pRect->bottom = bottom;
	
		pRect->left   += m_posTopLeft.x;
		pRect->right  += m_posTopLeft.x;
		pRect->top    += m_posTopLeft.y;
		pRect->bottom += m_posTopLeft.y;
	}


	return CGridCellRange(idTopLeft.row, idTopLeft.col, maxVisibleRow, maxVisibleCol);
}

// used by ResetScrollBars() - This gets only fully visible cells
CGridCellRange CXGridCtrlBase::GetUnobstructedNonFixedCellRange() const
{
// 	CRect rect;
// 	GetGridClientRect(rect);

	CCellID idTopLeft = GetTopleftNonFixedCell();

// 	int i = 0;
// 
// 	// calc bottom
// 	int bottom = GetFixedRowHeight();
// 	for (i = idTopLeft.row; i < GetRowCount(); i++)
// 	{
// 		bottom += GetRowHeight(i);
// 		if (bottom >= rect.bottom) break;
// 	}
	int maxVisibleRow = GetRowCount() - 1;//min(i, GetRowCount() - 1);
// 	if (maxVisibleRow > 0 && bottom > rect.bottom) maxVisibleRow--;

	// calc right
// 	int right = GetFixedColumnWidth();
// 	for (i = idTopLeft.col; i < GetColumnCount(); i++)
// 	{
// 		right += GetColumnWidth(i);
// 		if (right >= rect.right) break;
// 	}
	int maxVisibleCol = GetColumnCount() - 1;//min(i, GetColumnCount() - 1);
// 	if (maxVisibleCol > 0 && right > rect.right) maxVisibleCol--;


	return CGridCellRange(idTopLeft.row, idTopLeft.col, maxVisibleRow, maxVisibleCol);
}

void CXGridCtrlBase::InvalidateGrid(BOOL b)
{
	if (m_pGridRefWnd != NULL)
	{
		m_pGridRefWnd->Invalidate(b);
	}
}

CWnd* CXGridCtrlBase::GetParentWnd()
{
	if (m_pGridRefWnd != NULL)
	{
		return m_pGridRefWnd->GetParent();
	}
	else
	{
		return NULL;
	}
}

void CXGridCtrlBase::AttachViewWindow(CXDrawBaseInterface_ViewWindow *pViewWindow)
{
	m_pViewWindowPos = pViewWindow;
}

/////////////////////////////////////////////////////////////////////////////
// CXGridCtrlBase implementation functions

void CXGridCtrlBase::OnDraw(CDC* pDC)
{
	CRect rect;
	int row,col;

	CRect clipRect;
	if (GetGridClipRect(pDC, clipRect) == ERROR) return;

	EraseBkgnd(pDC);            // OnEraseBkgnd does nothing, so erase bkgnd here.
	// This necessary since we may be using a Memory DC.

	DrawGridLines(pDC);

	int nFixedRowHeight = GetFixedRowHeight();
	int nFixedColWidth  = GetFixedColumnWidth();

	CCellID idTopLeft = GetTopleftNonFixedCell();
	int minVisibleRow = idTopLeft.row,
		minVisibleCol = idTopLeft.col;

	CRect VisRect;
	CGridCellRange VisCellRange = GetVisibleNonFixedCellRange(VisRect);
	int maxVisibleRow = VisCellRange.GetMaxRow(),
		maxVisibleCol = VisCellRange.GetMaxCol();

	// draw rest of non-fixed cells
	rect.bottom = nFixedRowHeight-1 + m_posTopLeft.y;
	CGridCells oCells;

	//TRACE("Draw Cells\n\n");
	for (row = minVisibleRow; row <= maxVisibleRow; row++)
	{
		rect.top = rect.bottom+1;
		rect.bottom = rect.top + GetRowHeight(row)-1;

		// rect.bottom = bottom pixel of previous row
		if (rect.top > clipRect.bottom) break;                // Gone past cliprect
		if (rect.bottom < clipRect.top) continue;             // Reached cliprect yet?

		rect.right = nFixedColWidth-1 + m_posTopLeft.x;
		for (col = minVisibleCol; col <= maxVisibleCol; col++)
		{
			rect.left = rect.right+1;
			rect.right = rect.left + GetColumnWidth(col)-1;

			if (rect.left > clipRect.right) break;        // gone past cliprect
			if (rect.right < clipRect.left) continue;     // Reached cliprect yet?

			DrawCell(oCells, pDC, row, col, rect);
		}
	}

	oCells.RemoveAll();

	// draw top-left cells 0..m_nFixedRows-1, 0..m_nFixedCols-1
	rect.bottom = -1 + m_posTopLeft.y;

	for (row = 0; row < m_nFixedRows; row++)
	{
		rect.top = rect.bottom+1;
		rect.bottom = rect.top + GetRowHeight(row)-1;
		rect.right = m_posTopLeft.x - 1;

		for (col = 0; col < m_nFixedCols; col++)
		{
			rect.left = rect.right+1;
			rect.right = rect.left + GetColumnWidth(col)-1;
			//CGridCell *pCell = GetCell(row, col);
			//pCell->DrawFixedCell(pDC, rect, this, row, col, TRUE);
			DrawFixedCell(oCells, pDC, row, col, rect, TRUE, TRUE);
		}
	}

	// draw fixed column cells:  m_nFixedRows..n, 0..m_nFixedCols-1
	rect.bottom = nFixedRowHeight-1;
	for (row = minVisibleRow; row <= maxVisibleRow; row++)
	{
		rect.top = rect.bottom+1;
		rect.bottom = rect.top + GetRowHeight(row)-1;

		// rect.bottom = bottom pixel of previous row
		if (rect.top > clipRect.bottom) break;                // Gone past cliprect
		if (rect.bottom < clipRect.top) continue;             // Reached cliprect yet?

		rect.right = -1;
		for (col = 0; col < m_nFixedCols; col++)
		{
			rect.left = rect.right+1;
			rect.right = rect.left + GetColumnWidth(col)-1;

			if (rect.left > clipRect.right) break;            // gone past cliprect
			if (rect.right < clipRect.left) continue;         // Reached cliprect yet?

			//CGridCell *pCell = GetCell(row, col);
			//pCell->DrawFixedCell(pDC, rect, this, row, col, TRUE);
			DrawFixedCell(oCells, pDC, row, col, rect, TRUE, TRUE);
		}
	}

	// draw fixed row cells  0..m_nFixedRows, m_nFixedCols..n
	rect.bottom = m_posTopLeft.y-1;
	for (row = 0; row < m_nFixedRows; row++)
	{
		rect.top = rect.bottom+1;
		rect.bottom = rect.top + GetRowHeight(row)-1;

		// rect.bottom = bottom pixel of previous row
		if (rect.top > clipRect.bottom) break;                // Gone past cliprect
		if (rect.bottom < clipRect.top) continue;             // Reached cliprect yet?

		rect.right = m_posTopLeft.x + nFixedColWidth-1;

		for (col = minVisibleCol; col <= maxVisibleCol; col++)
		{                                       
			rect.left = rect.right+1;
			rect.right = rect.left + GetColumnWidth(col)-1;

			if (rect.left > clipRect.right) break;        // gone past cliprect
			if (rect.right < clipRect.left) continue;     // Reached cliprect yet?

			//CGridCell *pCell = GetCell(row, col);
			//pCell->DrawFixedCell(pDC, rect, this, row, col, TRUE);
			DrawFixedCell(oCells, pDC, row, col, rect, TRUE, TRUE);
		}
	}
#ifdef USE_MEMDC                        // Use a memDC for flicker free update
}
#else                                   // Use normal DC - this helps in debugging
}
#endif

BOOL CXGridCtrlBase::DrawCell(CGridCells &oCells, CDC *pDC, int nRow, int nCol, CRect rect, BOOL bCalMerge, BOOL bEraseBk)
{
	CGridCell *pCell = GetCell(nRow, nCol);

	if (pCell->IsMergeCell())
	{
		if (oCells.FindIndex(pCell->m_pMergeTo) >= 0)
		{
		}
		else
		{
			CRect rcCell = rect;
			oCells.Add(pCell->m_pMergeTo);
			AdjustCellDrawRect(nRow, nCol, rcCell);
			pCell->m_pMergeTo->DrawCell(pDC, rcCell, this);
		}
	}
	else
	{
		pCell->DrawCell(pDC, rect, this);
	}

	return TRUE;
}

BOOL CXGridCtrlBase::DrawFixedCell(CGridCells &oCells, CDC *pDC, int nRow, int nCol, CRect rect, BOOL bCalMerge, BOOL bEraseBk)
{
	CGridCell *pCell = GetCell(nRow, nCol);

	if (pCell->IsMergeCell())
	{
		if (oCells.FindIndex(pCell->m_pMergeTo) >= 0)
		{
		}
		else
		{
			CRect rcCell = rect;
			oCells.Add(pCell->m_pMergeTo);
			AdjustCellDrawRect(nRow, nCol, rcCell);
			pCell->m_pMergeTo->DrawFixedCell(pDC, rcCell, this, nRow, nCol, bCalMerge, bEraseBk);
		}
	}
	else
	{
		pCell->DrawFixedCell(pDC, rect, this, nRow, nCol, bCalMerge, bEraseBk);
	}

	return TRUE;
}

//
//void CXGridCtrlBase::OnDraw(CDC* pDC)
//{
//    CRect rect;
//    int row,col;
//
//    CRect clipRect;
//    if (GetGridClipRect(pDC, clipRect) == ERROR) return;
//
//    EraseBkgnd(pDC);            // OnEraseBkgnd does nothing, so erase bkgnd here.
//                                // This necessary since we may be using a Memory DC.
//
//	DrawGridLines(pDC);
//	
//    int nFixedRowHeight = GetFixedRowHeight();
//    int nFixedColWidth  = GetFixedColumnWidth();
//
//    CCellID idTopLeft = GetTopleftNonFixedCell();
//    int minVisibleRow = idTopLeft.row,
//        minVisibleCol = idTopLeft.col;
//
//    CRect VisRect;
//    CGridCellRange VisCellRange = GetVisibleNonFixedCellRange(VisRect);
//    int maxVisibleRow = VisCellRange.GetMaxRow(),
//        maxVisibleCol = VisCellRange.GetMaxCol();
//
//    // draw top-left cells 0..m_nFixedRows-1, 0..m_nFixedCols-1
//    rect.bottom = -1;
//    for (row = 0; row < m_nFixedRows; row++)
//    {
//        rect.top = rect.bottom+1;
//        rect.bottom = rect.top + GetRowHeight(row)-1;
//        rect.right = -1;
//        for (col = 0; col < m_nFixedCols; col++)
//        {
//            rect.left = rect.right+1;
//            rect.right = rect.left + GetColumnWidth(col)-1;
//			CGridCell *pCell = GetCell(row, col);
//            pCell->DrawFixedCell(pDC, rect, this, row, col);
//        }
//    }
//     
//    // draw fixed column cells:  m_nFixedRows..n, 0..m_nFixedCols-1
//    rect.bottom = nFixedRowHeight-1;
//    for (row = minVisibleRow; row <= maxVisibleRow; row++)
//    {
//        rect.top = rect.bottom+1;
//        rect.bottom = rect.top + GetRowHeight(row)-1;
//
//        // rect.bottom = bottom pixel of previous row
//        if (rect.top > clipRect.bottom) break;                // Gone past cliprect
//        if (rect.bottom < clipRect.top) continue;             // Reached cliprect yet?
//
//        rect.right = -1;
//        for (col = 0; col < m_nFixedCols; col++)
//        {
//            rect.left = rect.right+1;
//            rect.right = rect.left + GetColumnWidth(col)-1;
//
//            if (rect.left > clipRect.right) break;            // gone past cliprect
//            if (rect.right < clipRect.left) continue;         // Reached cliprect yet?
//
//            CGridCell *pCell = GetCell(row, col);
//            pCell->DrawFixedCell(pDC, rect, this, row, col);
//        }
//    }
//    
//    // draw fixed row cells  0..m_nFixedRows, m_nFixedCols..n
//    rect.bottom = -1;
//    for (row = 0; row < m_nFixedRows; row++)
//    {
//        rect.top = rect.bottom+1;
//        rect.bottom = rect.top + GetRowHeight(row)-1;
//
//        // rect.bottom = bottom pixel of previous row
//        if (rect.top > clipRect.bottom) break;                // Gone past cliprect
//        if (rect.bottom < clipRect.top) continue;             // Reached cliprect yet?
//
//        rect.right = nFixedColWidth-1;
//        for (col = minVisibleCol; col <= maxVisibleCol; col++)
//        {                                       
//            rect.left = rect.right+1;
//            rect.right = rect.left + GetColumnWidth(col)-1;
//
//            if (rect.left > clipRect.right) break;        // gone past cliprect
//            if (rect.right < clipRect.left) continue;     // Reached cliprect yet?
//
//			CGridCell *pCell = GetCell(row, col);
//            pCell->DrawFixedCell(pDC, rect, this, row, col);
//        }
//    }
//    
//    // draw rest of non-fixed cells
//    rect.bottom = nFixedRowHeight-1;
//	CGridCells oCells;
//
//	TRACE("Draw Cells\n\n");
//    for (row = minVisibleRow; row <= maxVisibleRow; row++)
//    {
//        rect.top = rect.bottom+1;
//        rect.bottom = rect.top + GetRowHeight(row)-1;
//
//        // rect.bottom = bottom pixel of previous row
//        if (rect.top > clipRect.bottom) break;                // Gone past cliprect
//        if (rect.bottom < clipRect.top) continue;             // Reached cliprect yet?
//
//        rect.right = nFixedColWidth-1;
//        for (col = minVisibleCol; col <= maxVisibleCol; col++)
//        {
//            rect.left = rect.right+1;
//            rect.right = rect.left + GetColumnWidth(col)-1;
//			
//            if (rect.left > clipRect.right) break;        // gone past cliprect
//            if (rect.right < clipRect.left) continue;     // Reached cliprect yet?
//
//			CGridCell *pCell = GetCell(row, col);
//
//			if (pCell->IsMergeCell())
//			{
//				if (oCells.FindIndex(pCell->m_pMergeTo) >= 0)
//				{
//				}
//				else
//				{
//					//draw mergecell
//					CRect rcCell = rect;
//					oCells.Add(pCell->m_pMergeTo);
//					AdjustCellDrawRect(row, col, rcCell);
//					TRACE("#Cell(%d, %d):(%d, %d, %d, %d)\n", row, col, rcCell.left, rcCell.top, rcCell.right, rcCell.bottom);
//					pCell->m_pMergeTo->DrawCell(pDC, rcCell, this);
//				}
//			}
//			else
//			{
//				TRACE("Cell(%d, %d):(%d, %d, %d, %d)\n", row, col, rect.left, rect.top, rect.right, rect.bottom);
//				pCell->DrawCell(pDC, rect, this);
//			}
//        }
//
//		TRACE("\n");
//    }
//
//	oCells.RemoveAll();
//	
//#ifdef USE_MEMDC                        // Use a memDC for flicker free update
//}
//#else                                   // Use normal DC - this helps in debugging
//}
//#endif

void CXGridCtrlBase::AdjustCellDrawRect(int nRow, int nCol, CRect &rect)
{
	CGridCell *pCell = GetCell(nRow, nCol);
	int nMergeToRow = 0;
	int nMergeToCol = 0;
	pCell->m_pMergeTo->GetCellID(nMergeToRow, nMergeToCol);
	int nIndex = 0;

	int nHeight = GetRowHeight(nMergeToRow);
	for (nIndex=nMergeToRow; nIndex<nRow; nIndex++)
	{
		rect.top -= GetRowHeight(nIndex);
	}
	rect.bottom = rect.top + nHeight - 1;

	int nWidth = GetColumnWidth(nMergeToCol);
	for (nIndex=nMergeToCol; nIndex<nCol; nIndex++)
	{
		rect.left -= GetColumnWidth(nIndex);
	}
	rect.right = rect.left + nWidth - 1;
}

void CXGridCtrlBase::DrawGridLines(CDC *pDC)
{
	int nFixedRowHeight = GetFixedRowHeight() + m_posTopLeft.y;
	int nFixedColWidth  = GetFixedColumnWidth() + m_posTopLeft.x;

	CCellID idTopLeft = GetTopleftNonFixedCell();
	int minVisibleRow = idTopLeft.row,
		minVisibleCol = idTopLeft.col;

	CRect VisRect;
	CGridCellRange VisCellRange = GetVisibleNonFixedCellRange(VisRect);
	int maxVisibleRow = VisCellRange.GetMaxRow(),
		maxVisibleCol = VisCellRange.GetMaxCol();

	CPen pen;

	try 
	{
		pen.CreatePen(PS_SOLID, 0, m_crGridColour);
	}
	catch (CResourceException *e)
	{
		e->Delete();
		return;
	}
	pDC->SelectObject(&pen);

	int row = 0;
	int col = 0;

	// draw vertical lines (drawn at ends of cells)
	if (m_nGridLines == GVL_BOTH || m_nGridLines == GVL_VERT) 
	{
		int x = nFixedColWidth;

		for (col = minVisibleCol; col <= maxVisibleCol; col++) 
		{
			x += GetColumnWidth(col);
			pDC->MoveTo(x-1, nFixedRowHeight);
			pDC->LineTo(x-1, VisRect.bottom);   
		}
	}

	// draw horizontal lines (drawn at bottom of each cell)
	if (m_nGridLines == GVL_BOTH || m_nGridLines == GVL_HORZ) 
	{
		int y = nFixedRowHeight;

		for (row = minVisibleRow; row <= maxVisibleRow; row++)
		{
			y += GetRowHeight(row);
			pDC->MoveTo(nFixedColWidth, y-1);    
			pDC->LineTo(VisRect.right,  y-1);
		}
	}

	pDC->SelectStockObject(NULL_PEN);
}

////////////////////////////////////////////////////////////////////////////////////////
// CXGridCtrlBase Cell selection stuff

BOOL CXGridCtrlBase::IsValid(int nRow, int nCol) const
{
	return (nRow >= 0 && nRow < m_nRows && nCol >= 0 && nCol < m_nCols);
}

BOOL CXGridCtrlBase::IsValid(const CCellID& cell) const
{
	return IsValid(cell.row, cell.col);
}

BOOL CXGridCtrlBase::IsValid(const CGridCellRange& range) const
{
	return (range.GetMinRow() >= 0 && range.GetMinCol() >= 0 && 
		range.GetMaxRow() >= 0 && range.GetMaxCol() >= 0 &&
		range.GetMaxRow() < m_nRows && range.GetMaxCol() < m_nCols &&
		range.GetMinRow() <= range.GetMaxRow() && range.GetMinCol() <= range.GetMaxCol());
}

// Enables/Disables redraw for certain operations like columns auto-sizing etc,
// but not for user caused things such as selection changes.
void CXGridCtrlBase::SetRedraw(BOOL bAllowDraw, BOOL bResetScrollBars /* = FALSE */)
{
	ASSERT (m_pGridRefWnd != NULL);

	if (bAllowDraw && !m_bAllowDraw)
	{
		m_pGridRefWnd->Invalidate();
	}

	m_bAllowDraw = bAllowDraw;

	if (bResetScrollBars)
	{
		ResetScrollBars();
	}
}

// Forces a redraw of a cell immediately (using a direct DC construction, 
// or the supplied dc)
BOOL CXGridCtrlBase::RedrawCell(const CCellID& cell, CDC* pDC /* = NULL */)
{
	return RedrawCell(cell.row, cell.col, pDC);
}

BOOL CXGridCtrlBase::RedrawCell(int nRow, int nCol, CDC* pDC /* = NULL */)
{
	ASSERT (m_pGridRefWnd != NULL);
	BOOL bResult = TRUE;
	BOOL bMustReleaseDC = FALSE;

	if (!m_bAllowDraw || !IsCellVisible(CCellID(nRow, nCol))) return FALSE;

	CRect rect;
	if (!GetCellRect(nRow, nCol, rect)) return FALSE;

	if (m_pViewWindowPos != NULL)
	{
		m_pViewWindowPos->ViewToWindow(rect);
	}

	if (!pDC) 
	{
		pDC = m_pGridRefWnd->GetDC();
		if (pDC) bMustReleaseDC = TRUE;
	}

	CGridCells oCells;

	if (pDC)
	{
		// Redraw cells directly
		if (nRow < m_nFixedRows || nCol < m_nFixedCols)
		{
			bResult = DrawFixedCell(oCells, pDC, nRow, nCol, rect, TRUE, TRUE);
		}
		else
		{
			bResult = DrawCell(oCells, pDC, nRow, nCol, rect, TRUE, TRUE);
		}

		// Since we have erased the background, we will need to redraw the gridlines
		CPen pen;
		try 
		{
			pen.CreatePen(PS_SOLID, 0, m_crGridColour);
		} 
		catch (...) 
		{
		}

		CPen* pOldPen = (CPen*) pDC->SelectObject(&pen);
		//        if (m_nGridLines == GVL_BOTH || m_nGridLines == GVL_HORZ) 
		//        {
		//            pDC->MoveTo(rect.left,    rect.bottom);
		//            pDC->LineTo(rect.right+1, rect.bottom);
		//        }
		//        if (m_nGridLines == GVL_BOTH || m_nGridLines == GVL_VERT) 
		//        {
		//            pDC->MoveTo(rect.right, rect.top);
		//            pDC->LineTo(rect.right, rect.bottom+1);    
		//        }
		pDC->SelectObject(pOldPen);

	} 
	else
	{
		m_pGridRefWnd->InvalidateRect(rect, TRUE);     // Could not get a DC - invalidate it anyway
		// and hope that OnPaint manages to get one
	}

	if (bMustReleaseDC) 
	{
		m_pGridRefWnd->ReleaseDC(pDC);
	}

	return bResult;
}

// redraw a complete row
BOOL CXGridCtrlBase::RedrawRow(int row)
{
	ASSERT(m_pGridRefWnd != NULL);
	BOOL bResult = TRUE;

	CDC* pDC = m_pGridRefWnd->GetDC();

	for (int col = 0; col < GetColumnCount(); col++)
	{
		bResult = RedrawCell(row, col, pDC) && bResult;
	}

	if (pDC)
	{
		m_pGridRefWnd->ReleaseDC(pDC);
	}

	return bResult;
}

// redraw a complete column
BOOL CXGridCtrlBase::RedrawColumn(int col)
{
	ASSERT(m_pGridRefWnd != NULL);
	BOOL bResult = TRUE;

	CDC* pDC = m_pGridRefWnd->GetDC();

	for (int row = 0; row < GetRowCount(); row++)
	{
		bResult = RedrawCell(row, col, pDC) && bResult;
	}

	if (pDC)
	{
		m_pGridRefWnd->ReleaseDC(pDC);
	}

	return bResult;
}


// Sets the currently selected cell, returning the previous current cell
CCellID CXGridCtrlBase::SetFocusCell(int nRow, int nCol)
{
	return SetFocusCell(CCellID(nRow, nCol));
}

CCellID CXGridCtrlBase::SetFocusCell(CCellID cell)
{
	if (cell == m_idCurrentCell) 
		return m_idCurrentCell;

	CCellID idPrev = m_idCurrentCell;
	m_idCurrentCell = cell;

	if (IsValid(idPrev)) 
	{
		SendMessageToParent(idPrev.row, idPrev.col, GVN_SELCHANGING); 

		BOOL bCtrlDown = FALSE;
		SHORT nKeyState = GetKeyState(VK_CONTROL);

		bCtrlDown = ( (nKeyState & 0xFF00) > 0);

		if (!bCtrlDown)
		{
			SetItemState(idPrev.row, idPrev.col, 
				GetItemState(idPrev.row, idPrev.col) & ~GVIS_FOCUSED & ~GVIS_SELECTED);
		}
		else
		{
			SetItemState(idPrev.row, idPrev.col, 
				GetItemState(idPrev.row, idPrev.col) & ~GVIS_FOCUSED);
		}

		RedrawCell(idPrev);

		if (idPrev.col != m_idCurrentCell.col)
			for (int row = 0; row < m_nFixedRows; row++)
				RedrawCell(row, idPrev.col);
		if (idPrev.row != m_idCurrentCell.row)
			for (int col = 0; col < m_nFixedCols; col++) 
				RedrawCell(idPrev.row, col);
	}

	if (IsValid(m_idCurrentCell)) 
	{
		SetItemState(m_idCurrentCell.row, m_idCurrentCell.col, 
			GetItemState(m_idCurrentCell.row, m_idCurrentCell.col) | GVIS_FOCUSED);

		RedrawCell(m_idCurrentCell);

		if (idPrev.col != m_idCurrentCell.col)
			for (int row = 0; row < m_nFixedRows; row++) 
				RedrawCell(row, m_idCurrentCell.col);
		if (idPrev.row != m_idCurrentCell.row)
			for (int col = 0; col < m_nFixedCols; col++) 
				RedrawCell(m_idCurrentCell.row, col);

		SendMessageToParent(m_idCurrentCell.row, m_idCurrentCell.col, GVN_SELCHANGED); 
	}

	return idPrev;
}

void CXGridCtrlBase::ClearSelect()
{
	POSITION pos = m_SelectedCellMap.GetStartPosition();
	CCellID cell;
	DWORD key = 0;

	while (pos != NULL)
	{
		m_SelectedCellMap.GetNextAssoc(pos, key, cell);
		SetItemState(cell.row ,cell.col, 0);
	}

	m_SelectedCellMap.RemoveAll();

	pos = m_PrevSelectedCellMap.GetStartPosition();
	while (pos != NULL)
	{
		m_PrevSelectedCellMap.GetNextAssoc(pos, key, cell);
		SetItemState(cell.row ,cell.col, 0);
	}

	m_PrevSelectedCellMap.RemoveAll();
}

BOOL CXGridCtrlBase::KillFocusCell()
{
	return TRUE;
}

// Sets the range of currently selected cells
void CXGridCtrlBase::SetSelectedRange(const CGridCellRange& Range, 
									  BOOL bForceRepaint /* = FALSE */)
{
	SetSelectedRange(Range.GetMinRow(), Range.GetMinCol(), Range.GetMaxRow(), Range.GetMaxCol(),
		bForceRepaint);
}

void CXGridCtrlBase::SetSelectedRange(int nMinRow, int nMinCol, int nMaxRow, int nMaxCol,
									  BOOL bForceRepaint /* = FALSE */)
{
	if (!m_bEnableSelection) return;

	CDC* pDC = NULL;
	if (bForceRepaint) pDC = m_pGridRefWnd->GetDC();

	POSITION pos = NULL;

	// Unselect all previously selected cells
	for (pos = m_SelectedCellMap.GetStartPosition(); pos != NULL; )
	{
		DWORD key;
		CCellID cell;
		m_SelectedCellMap.GetNextAssoc(pos, key, (CCellID&)cell);

		// Reset the selection flag on the cell
		if (IsValid(cell)) 
		{
			SetItemState(cell.row, cell.col, 
				GetItemState(cell.row, cell.col) & ~GVIS_SELECTED);

			// If this is to be reselected, continue on past the redraw
			if (nMinRow <= cell.row && cell.row <= nMaxRow &&
				nMinCol <= cell.col && cell.col <= nMaxCol)
				continue;

			if (bForceRepaint && pDC)                    // Redraw NOW
				RedrawCell(cell.row, cell.col, pDC);
			else
				InvalidateCellRect(cell);                // Redraw at leisure
		}
	}

	// if any previous selected cells are to be retained (eg Ctrl is being held down)
	// then copy them to the newly created list, and mark all these cells as
	// selected
	for (pos = m_PrevSelectedCellMap.GetStartPosition(); pos != NULL; )
	{
		DWORD key;
		CCellID cell;
		m_PrevSelectedCellMap.GetNextAssoc(pos, key, (CCellID&)cell);

		if (!IsValid(cell)) continue;

		int nState = GetItemState(cell.row, cell.col);

		// Set state as Selected. This will add the cell to m_SelectedCells[]
		SetItemState(cell.row, cell.col, nState | GVIS_SELECTED);

		// Redraw (immediately or at leisure)
		if (bForceRepaint && pDC)
			RedrawCell(cell.row, cell.col, pDC);
		else
			InvalidateCellRect(cell);
	}

	// Now select all cells in the cell range specified. If the cell has already
	// been marked as selected (above) then ignore it.
	if (nMinRow >= 0 && nMinCol >= 0 && nMaxRow >= 0 && nMaxCol >= 0 &&
		nMaxRow < m_nRows && nMaxCol < m_nCols &&
		nMinRow <= nMaxRow && nMinCol <= nMaxCol)
	{
		for (int row = nMinRow; row <= nMaxRow; row++)
			for (int col = nMinCol; col <= nMaxCol; col++) 
			{
				int nState = GetItemState(row, col);
				if (nState & GVIS_SELECTED) {
					continue;    // Already selected - ignore
				}

				// Add to list of selected cells
				CCellID cell(row, col);

				// Set state as Selected. This will add the cell to m_SelectedCells[]
				SetItemState(row, col, nState | GVIS_SELECTED);

				// Redraw (immediately or at leisure)
				if (bForceRepaint && pDC)
					RedrawCell(row, col, pDC);
				else
					InvalidateCellRect(cell);
			}
	}
	//    TRACE(_T("%d cells selected.\n"), m_SelectedCellMap.GetCount());

	if (pDC != NULL) m_pGridRefWnd->ReleaseDC(pDC);
} 

BOOL CXGridCtrlBase::IsPointInRect(const CPoint &point)
{
	long nWidth = GetVirtualWidth();
	long nHeight = GetVirtualHeight();

	return ((m_posTopLeft.x <= point.x && point.x <= nWidth + m_posTopLeft.x) 
		&&  (m_posTopLeft.y <= point.y && point.y <= nHeight + m_posTopLeft.y));

// 	if (m_pViewWindowPos == NULL)
// 	{
// 		return ((m_posTopLeft.x <= point.x && point.x <= nWidth + m_posTopLeft.x) 
// 			&&  (m_posTopLeft.y <= point.y && point.y <= nHeight + m_posTopLeft.y));
// 	}
// 	else
// 	{
// 		CPoint pt = point;
// 		m_pViewWindowPos->WindowToView(pt);
// 
// 		return ((m_posTopLeft.x <= pt.x && pt.x <= nWidth + m_posTopLeft.x) 
// 			&&  (m_posTopLeft.y <= pt.y && pt.y <= nHeight + m_posTopLeft.y));
// 	}
}

// selects all cells
void CXGridCtrlBase::SelectAllCells()
{
	if (!m_bEnableSelection) return;
	m_SelectionStartCell.row = m_nFixedRows;
	m_SelectionStartCell.col = m_nFixedCols;

	SetSelectedRange(m_nFixedRows, m_nFixedCols, GetRowCount()-1, GetColumnCount()-1);
}

// selects columns
void CXGridCtrlBase::SelectColumns(CCellID currentCell)
{
	if (!m_bEnableSelection) return;

	//if (currentCell.col == m_idCurrentCell.col) return;
	if (currentCell.col < m_nFixedCols) return;
	if (!IsValid(currentCell)) return;

	SetSelectedRange(GetFixedRowCount(), min(m_SelectionStartCell.col, currentCell.col), 
		GetRowCount()-1,    max(m_SelectionStartCell.col, currentCell.col)); 
}

// selects rows
void CXGridCtrlBase::SelectRows(CCellID currentCell)
{  
	if (!m_bEnableSelection) return;

	//if (currentCell.row; == m_idCurrentCell.row) return;
	if (currentCell.row < m_nFixedRows) return;
	if (!IsValid(currentCell)) return;

	SetSelectedRange(min(m_SelectionStartCell.row, currentCell.row), GetFixedColumnCount(), 
		max(m_SelectionStartCell.row, currentCell.row), GetColumnCount()-1); 
}

// selects cells
void CXGridCtrlBase::SelectCells(CCellID currentCell)
{
	if (!m_bEnableSelection) return;

	int row = currentCell.row;
	int col = currentCell.col;
	if (row < m_nFixedRows || col < m_nFixedCols) return;
	if (!IsValid(currentCell)) return;

	// Prevent unnecessary redraws
	//if (currentCell == m_LeftClickDownCell)  return;
	//else if (currentCell == m_idCurrentCell) return;

	SetSelectedRange(min(m_SelectionStartCell.row, row), min(m_SelectionStartCell.col, col), 
		max(m_SelectionStartCell.row, row), max(m_SelectionStartCell.col, col)); 
}

void CXGridCtrlBase::OnSelecting(const CCellID& currentCell)
{
	if (!m_bEnableSelection) return;

	switch(m_MouseMode)
	{
	case MOUSE_SELECT_ALL:     SelectAllCells();               break;
	case MOUSE_SELECT_COL:     SelectColumns(currentCell);     break;
	case MOUSE_SELECT_ROW:     SelectRows(currentCell);        break;
	case MOUSE_SELECT_CELLS:   SelectCells(currentCell);       break;
	}
}

////////////////////////////////////////////////////////////////////////////////////////
// Clipboard functions

void CXGridCtrlBase::CutSelectedText()
{
	if (!IsEditable())
		return;

	// Clear contents of selected cells.
	for (POSITION pos = m_SelectedCellMap.GetStartPosition(); pos != NULL; )
	{
		DWORD key;
		CCellID cell;
		m_SelectedCellMap.GetNextAssoc(pos, key, (CCellID&)cell);

		if (!IsCellEditable(cell))
			continue;

		CGridCell* pCell = GetCell(cell.row, cell.col);
		if (pCell)
		{
			EmptyCell(pCell, cell.row, cell.col);
			SetModified(TRUE);
		}
	}
	m_pGridRefWnd->Invalidate();
}

COleDataSource* CXGridCtrlBase::CopyTextFromGrid()
{
	USES_CONVERSION;

	CGridCellRange Selection = GetSelectedCellRange();
	if (!IsValid(Selection)) return NULL;

	// Write to shared file (REMEBER: CF_TEXT is ANSI, not UNICODE, so we need to convert)
	CSharedFile sf(GMEM_MOVEABLE|GMEM_DDESHARE|GMEM_ZEROINIT);

	// Get a tab delimited string to copy to cache
	CString str;
	CGridCell *pCell;
	for (int row = Selection.GetMinRow(); row <= Selection.GetMaxRow(); row++) 
	{
		str.Empty();
		for (int col = Selection.GetMinCol(); col <= Selection.GetMaxCol(); col++)
		{
			pCell = GetCell(row,col);
			if (pCell && (pCell->state  & GVIS_SELECTED))
			{
				if (pCell->szText.IsEmpty())
					str += _T(" ");
				else 
					str += pCell->szText;
			}
			if (col != Selection.GetMaxCol()) 
				str += _T("\t");
		}
		if (row != Selection.GetMaxRow()) 
			str += _T("\n");

		sf.Write(T2A(str.GetBuffer(1)), str.GetLength());
		str.ReleaseBuffer();
	}

	char c = '\0';
	sf.Write(&c, 1);

	DWORD dwLen = sf.GetLength();
	HGLOBAL hMem = sf.Detach();
	if (!hMem) 
		return NULL;

	hMem = ::GlobalReAlloc(hMem, dwLen, GMEM_MOVEABLE|GMEM_DDESHARE|GMEM_ZEROINIT);
	if (!hMem) 
		return NULL;

	// Cache data
	COleDataSource* pSource = new COleDataSource();
	pSource->CacheGlobalData(CF_TEXT, hMem);

	return pSource;
}

BOOL CXGridCtrlBase::PasteTextToGrid(CCellID cell, COleDataObject* pDataObject)
{
	//     if (!IsValid(cell) || !IsCellEditable(cell) || !pDataObject->IsDataAvailable(CF_TEXT))
	//         return FALSE;
	// 
	//     // Get the text from the COleDataObject
	//     HGLOBAL hmem = pDataObject->GetGlobalData(CF_TEXT);
	//     CMemFile sf((BYTE*) ::GlobalLock(hmem), ::GlobalSize(hmem));
	// 
	//     // CF_TEXT is ANSI text, so we need to allocate a char* buffer
	//     // to hold this.
	//     LPSTR szBuffer = new char[::GlobalSize(hmem)];
	//     if (!szBuffer)
	//         return FALSE;
	// 
	//     sf.Read(szBuffer, ::GlobalSize(hmem));
	//     ::GlobalUnlock(hmem);
	// 
	//     // Now store in generic TCHAR form so we no longer have to deal with
	//     // ANSI/UNICODE problems
	//     CString strText = szBuffer;
	//     delete szBuffer;
	// 
	//     // Parse text data and set in cells...
	//     strText.LockBuffer();
	//     CString strLine = strText;
	//     int nLine = 0;
	// 
	//     // Find the end of the first line
	//     int nIndex;
	//     do {
	//         int nColumn = 0;
	//         nIndex = strLine.Find(_T("\n"));
	// 
	//         // Store the remaining chars after the newline
	//         CString strNext = (nIndex < 0)? _T("")  : strLine.Mid(nIndex+1);
	// 
	//         // Remove all chars after the newline
	//         if (nIndex >= 0) 
	//             strLine = strLine.Left(nIndex);
	// 
	//         // Make blank entries a "space"
	//         if (strLine.IsEmpty() && nIndex >= 0)
	//             strLine = _T(" ");
	// 
	//         LPTSTR szLine = strLine.GetBuffer(1);
	// 
	//         // Break the current line into tokens (tab or comma delimited)
	//         LPTSTR pszCellText = _tcstok(szLine, _T("\t,\n"));
	//         while (pszCellText != NULL)
	//         {
	//             CCellID TargetCell(cell.row + nLine, cell.col + nColumn);
	//             if (IsValid(TargetCell))
	//             {
	//                 CString strCellText = pszCellText;
	//                 strCellText.TrimLeft();  strCellText.TrimRight();
	// 
	//                 SetItemText(TargetCell.row, TargetCell.col, strCellText);
	//                 SetModified(TRUE);
	// 
	//                 // Make sure cell is not selected to avoid data loss
	//                 SetItemState(TargetCell.row, TargetCell.col,
	//                              GetItemState(TargetCell.row, TargetCell.col) & ~GVIS_SELECTED);
	//             }
	// 
	//             pszCellText = _tcstok(NULL, _T("\t,\n"));
	//             nColumn++;
	//         }
	// 
	//         strLine.ReleaseBuffer();
	//         strLine = strNext;
	//         nLine++;
	// 
	//     } while (nIndex >= 0);
	// 
	//     strText.UnlockBuffer();
	//     Invalidate();

	return TRUE;
}

void CXGridCtrlBase::OnBeginDrag()
{        
	if (!m_bAllowDragAndDrop) return;

	COleDataSource* pSource = CopyTextFromGrid();
	if (pSource) 
	{    
		SendMessageToParent(GetSelectedCellRange().GetTopLeft().row,
			GetSelectedCellRange().GetTopLeft().col,
			GVN_BEGINDRAG);

		m_MouseMode = MOUSE_DRAGGING;
		DROPEFFECT dropEffect = pSource->DoDragDrop(DROPEFFECT_COPY|DROPEFFECT_MOVE);

		if (dropEffect & DROPEFFECT_MOVE)
			CutSelectedText();

		if (pSource) 
			delete pSource;    // Did not pass source to clipboard, so must delete
	}    
}

DROPEFFECT CXGridCtrlBase::OnDragOver(COleDataObject* pDataObject, DWORD dwKeyState, 
									  CPoint point)
{
	// Any text data available for us?
	if (!m_bAllowDragAndDrop || !IsEditable() || !pDataObject->IsDataAvailable(CF_TEXT))
		return DROPEFFECT_NONE;

	// Find which cell we are over and drop-highlight it
	CCellID cell = GetCellFromPt(point, FALSE);

	// If not valid, set the previously drop-highlighted cell as no longer drop-highlighted
	if (!IsValid(cell))
	{
		OnDragLeave();
		m_LastDragOverCell = CCellID(-1,-1);
		return DROPEFFECT_NONE;
	}

	if (!IsCellEditable(cell))
		return DROPEFFECT_NONE;

	// Have we moved over a different cell than last time?
	if (cell != m_LastDragOverCell) 
	{
		// Set the previously drop-highlighted cell as no longer drop-highlighted
		if (IsValid(m_LastDragOverCell)) {
			UINT nState = GetItemState(m_LastDragOverCell.row, m_LastDragOverCell.col);
			SetItemState(m_LastDragOverCell.row, m_LastDragOverCell.col,
				nState & ~GVIS_DROPHILITED);
			RedrawCell(m_LastDragOverCell);
		}

		m_LastDragOverCell = cell;

		// Set the new cell as drop-highlighted
		if (IsValid(m_LastDragOverCell)) {
			UINT nState = GetItemState(m_LastDragOverCell.row, m_LastDragOverCell.col);
			SetItemState(m_LastDragOverCell.row, m_LastDragOverCell.col,
				nState | GVIS_DROPHILITED);
			RedrawCell(m_LastDragOverCell);
		}
	}

	// Return an appropraite value of DROPEFFECT so mouse cursor is set properly
	if (dwKeyState & MK_CONTROL)
		return DROPEFFECT_COPY;
	else
		return DROPEFFECT_MOVE;
}

DROPEFFECT CXGridCtrlBase::OnDragEnter(COleDataObject* pDataObject, DWORD dwKeyState, 
									   CPoint point)
{
	// Any text data available for us?
	if (!m_bAllowDragAndDrop || !pDataObject->IsDataAvailable(CF_TEXT))
		return DROPEFFECT_NONE;

	// Find which cell we are over and drop-highlight it
	m_LastDragOverCell = GetCellFromPt(point, FALSE);
	if (!IsValid(m_LastDragOverCell))
		return DROPEFFECT_NONE;

	if (!IsCellEditable(m_LastDragOverCell))
		return DROPEFFECT_NONE;

	if (IsValid(m_LastDragOverCell)) 
	{
		UINT nState = GetItemState(m_LastDragOverCell.row, m_LastDragOverCell.col);
		SetItemState(m_LastDragOverCell.row, m_LastDragOverCell.col,
			nState | GVIS_DROPHILITED);
		RedrawCell(m_LastDragOverCell);
	}

	// Return an appropraite value of DROPEFFECT so mouse cursor is set properly
	if (dwKeyState & MK_CONTROL)
		return DROPEFFECT_COPY;
	else
		return DROPEFFECT_MOVE;
}

void CXGridCtrlBase::OnDragLeave()
{
	// Set the previously drop-highlighted cell as no longer drop-highlighted
	if (IsValid(m_LastDragOverCell)) {
		UINT nState = GetItemState(m_LastDragOverCell.row, m_LastDragOverCell.col);
		SetItemState(m_LastDragOverCell.row, m_LastDragOverCell.col,
			nState & ~GVIS_DROPHILITED);
		RedrawCell(m_LastDragOverCell);
	}
}

BOOL CXGridCtrlBase::OnDrop(COleDataObject* pDataObject, DROPEFFECT /*dropEffect*/, 
							CPoint /* point */) 
{
	BOOL bResult = FALSE;

	if (!m_bAllowDragAndDrop || !IsCellEditable(m_LastDragOverCell))
		return bResult;

	m_MouseMode = MOUSE_NOTHING;
	OnDragLeave();

	return PasteTextToGrid(m_LastDragOverCell, pDataObject);
}


////////////////////////////////////////////////////////////////////////////////////////
// hittest-like functions

// Get cell from point
CCellID CXGridCtrlBase::GetCellFromPt(CPoint point, BOOL bAllowFixedCellCheck /*=TRUE*/) const
{  
// 	if (m_pViewWindowPos != NULL)
// 	{
// 		m_pViewWindowPos->WindowToView(point);
// 	}

	CCellID idTopLeft = GetTopleftNonFixedCell();
	CCellID cellID; // return value

	// calculate column index
	int fixedColWidth = GetFixedColumnWidth() + m_posTopLeft.x;
	int col = 0;
	int row = 0;

	if (point.x < 0 || (!bAllowFixedCellCheck && point.x < fixedColWidth)) // not in window
	{
		cellID.col = -1;
	}
	else if (point.x < fixedColWidth) // in fixed col
	{
		int xpos = m_posTopLeft.x;

		for (col = 0; col < m_nFixedCols; col++)
		{
			xpos += GetColumnWidth(col);
			if (xpos > point.x) break;
		}

		cellID.col = col;
	}
	else    // in non-fixed col
	{
		int xpos = fixedColWidth;
		for (col = idTopLeft.col; col < GetColumnCount(); col++)
		{
			xpos += GetColumnWidth(col);
			if (xpos > point.x) break;
		}

		if (col >= GetColumnCount())
			cellID.col = -1;
		else
			cellID.col = col;
	}

	// calculate row index
	int fixedRowHeight = GetFixedRowHeight() + m_posTopLeft.y;
	if (point.y < 0 || (!bAllowFixedCellCheck && point.y < fixedRowHeight)) // not in window
	{
		cellID.row = -1;
	}
	else if (point.y < fixedRowHeight) // in fixed col
	{
		int ypos = m_posTopLeft.y;

		for (row = 0; row < m_nFixedRows; row++)
		{
			ypos += GetRowHeight(row);
			if (ypos > point.y) break;
		}

		cellID.row = row;
	}
	else
	{
		int ypos = fixedRowHeight;
		for (row = idTopLeft.row; row < GetRowCount(); row++)
		{
			ypos += GetRowHeight(row);
			if (ypos > point.y) break;
		}

		if (row >= GetRowCount())
			cellID.row = -1;
		else
			cellID.row = row;
	}

	CGridCell *pCell = GetCell(cellID.row, cellID.col);

	if (pCell != NULL)
	{
		if (pCell->m_pMergeTo != NULL)
		{
			pCell->m_pMergeTo->GetCellID(cellID.row, cellID.col);
		}
	}

	return cellID;
}


// Returns the minimum bounding range of the current selection
// If no selection, then the returned CGridCellRange will be invalid
CGridCellRange CXGridCtrlBase::GetSelectedCellRange() const
{
	CGridCellRange Selection(GetRowCount(), GetColumnCount(), -1,-1);

	for (POSITION pos = m_SelectedCellMap.GetStartPosition(); pos != NULL; )
	{
		DWORD key;
		CCellID cell;
		m_SelectedCellMap.GetNextAssoc(pos, key, (CCellID&)cell);

		Selection.SetMinRow( min(Selection.GetMinRow(), cell.row) );
		Selection.SetMinCol( min(Selection.GetMinCol(), cell.col) );
		Selection.SetMaxRow( max(Selection.GetMaxRow(), cell.row) );
		Selection.SetMaxCol( max(Selection.GetMaxCol(), cell.col) );
	}

	return Selection;
}

// Returns ALL the cells in the grid
CGridCellRange CXGridCtrlBase::GetCellRange() const
{
	return CGridCellRange(0, 0, GetRowCount() - 1, GetColumnCount() - 1);
}

void CXGridCtrlBase::ResetSelectedRange()
{
	SetSelectedRange(-1,-1,-1,-1);
	SetFocusCell(-1,-1);
}

// Get/Set scroll position using 32 bit functions
int CXGridCtrlBase::GetScrollPos32(int nBar, BOOL bGetTrackPos /* = FALSE */)
{
	SCROLLINFO si;
	si.cbSize = sizeof(SCROLLINFO);

	if (bGetTrackPos)
	{
		if (m_pGridRefWnd->GetScrollInfo(nBar, &si, SIF_TRACKPOS))
			return si.nTrackPos;
	}
	else 
	{
		if (m_pGridRefWnd->GetScrollInfo(nBar, &si, SIF_POS))
			return si.nPos;
	}

	return 0;
}

BOOL CXGridCtrlBase::SetScrollPos32(int nBar, int nPos, BOOL bRedraw /* = TRUE */)
{
	SCROLLINFO si;
	si.cbSize = sizeof(SCROLLINFO);
	si.fMask  = SIF_POS;
	si.nPos   = nPos;
	return m_pGridRefWnd->SetScrollInfo(nBar, &si, bRedraw);
}

void CXGridCtrlBase::ResetScrollBars()
{
	return;
// 	if (!m_bAllowDraw || !::IsWindow(m_pGridRefWnd->GetSafeHwnd())) 
// 		return;
// 
// 	CRect rect;
// 	GetGridClientRect(rect);
// 	rect.left  += GetFixedColumnWidth();
// 	rect.top   += GetFixedRowHeight();
// 	if (rect.left >= rect.right || rect.top >= rect.bottom) return;
// 
// 	CRect VisibleRect(GetFixedColumnWidth(), GetFixedRowHeight(), rect.right, rect.bottom);
// 	CRect VirtualRect(GetFixedColumnWidth(), GetFixedRowHeight(), GetVirtualWidth(), GetVirtualHeight());
// 
// 	CGridCellRange visibleCells = GetUnobstructedNonFixedCellRange();
// 	//if (!IsValid(visibleCells)) return;
// 
// 	SCROLLINFO si;
// 	si.cbSize = sizeof(SCROLLINFO);
// 	si.fMask  = SIF_PAGE;
// 	si.nPage  = VisibleRect.Width();    m_pGridRefWnd->SetScrollInfo(SB_HORZ, &si, FALSE); 
// 	si.nPage  = VisibleRect.Height();   m_pGridRefWnd->SetScrollInfo(SB_VERT, &si, FALSE); 
// 
// 	if (VisibleRect.Height() < VirtualRect.Height())
// 		m_nVScrollMax = VirtualRect.Height()-1; //+ GetRowHeight(visibleCells.GetTopLeft().row);
// 	else
// 		m_nVScrollMax = 0;
// 
// 	if (VisibleRect.Width() < VirtualRect.Width())
// 		m_nHScrollMax = VirtualRect.Width()-1; //+ GetColumnWidth(visibleCells.GetTopLeft().col);
// 	else
// 		m_nHScrollMax = 0;
// 
// 	ASSERT(m_nVScrollMax < INT_MAX && m_nHScrollMax < INT_MAX); // This should be fine :)
// 	m_pGridRefWnd->SetScrollRange(SB_VERT, 0, m_nVScrollMax, TRUE);
// 	m_pGridRefWnd->SetScrollRange(SB_HORZ, 0, m_nHScrollMax, TRUE);
}

void CXGridCtrlBase::GetScrollMax(long &nHScrollMax, long &nVScrollMax)
{
	/*
	CRect rect;
	GetClientRect(rect);
	rect.left  += GetFixedColumnWidth();
	rect.top   += GetFixedRowHeight();
	CRect VisibleRect(GetFixedColumnWidth(), GetFixedRowHeight(), rect.right, rect.bottom);
	nVScrollMax = VisibleRect.Height();
	nHScrollMax = VisibleRect.Width();
	*/

	CRect VirtualRect(GetFixedColumnWidth(), GetFixedRowHeight(), GetVirtualWidth(), GetVirtualHeight());
	nVScrollMax = VirtualRect.Height() + 6;
	nHScrollMax = VirtualRect.Width() + 6;

}

////////////////////////////////////////////////////////////////////////////////////
// Row/Column position functions

// returns the top left point of the cell. Returns FALSE if cell not visible.
BOOL CXGridCtrlBase::GetCellOrigin(int nRow, int nCol, LPPOINT p) const
{
	int i;

	if (!IsValid(nRow, nCol)) return FALSE;

	CCellID idTopLeft;
	if (nCol >= m_nFixedCols || nRow >= m_nFixedRows)
		idTopLeft = GetTopleftNonFixedCell();

	if ((nRow >= m_nFixedRows && nRow < idTopLeft.row) ||
		(nCol>= m_nFixedCols && nCol < idTopLeft.col))
		return FALSE;

	p->x = m_posTopLeft.x;
	if (nCol < m_nFixedCols)                      // is a fixed column
		for (i = 0; i < nCol; i++)
			p->x += GetColumnWidth(i);
	else {                                        // is a scrollable data column
		for (i = 0; i < m_nFixedCols; i++)
			p->x += GetColumnWidth(i);
		for (i = idTopLeft.col; i < nCol; i++)
			p->x += GetColumnWidth(i);
	}

	p->y =  m_posTopLeft.y;
	if (nRow < m_nFixedRows)                      // is a fixed row
		for (i = 0; i < nRow; i++)
			p->y += GetRowHeight(i);
	else {                                        // is a scrollable data row
		for (i = 0; i < m_nFixedRows; i++)
			p->y += GetRowHeight(i);
		for (i = idTopLeft.row; i < nRow; i++)
			p->y += GetRowHeight(i);
	}

	return TRUE;
}

BOOL CXGridCtrlBase::GetCellOrigin(const CCellID& cell, LPPOINT p) const
{
	return GetCellOrigin(cell.row, cell.col, p);
}

// Returns the bounding box of the cell
BOOL CXGridCtrlBase::GetCellRect(const CCellID& cell, LPRECT pRect) const
{
	return GetCellRect(cell.row, cell.col, pRect);
}

BOOL CXGridCtrlBase::GetCellRect(int nRow, int nCol, LPRECT pRect) const
{    
	CPoint CellOrigin;
	if (!GetCellOrigin(nRow, nCol, &CellOrigin)) return FALSE;

	pRect->left   = CellOrigin.x;
	pRect->top    = CellOrigin.y;
	pRect->right  = CellOrigin.x + GetColumnWidth(nCol)-1;
	pRect->bottom = CellOrigin.y + GetRowHeight(nRow)-1;

	CGridCell *pCell = GetCell(nRow, nCol);

	if (pCell != NULL)
	{
		*pRect = pCell->GetMergeCellRect(*pRect);
	}

	//TRACE("Row %d, col %d: L %d, T %d, W %d, H %d:  %d,%d - %d,%d\n",
	//      nRow,nCol, CellOrigin.x, CellOrigin.y, GetColumnWidth(nCol), GetRowHeight(nRow),
	//      pRect->left, pRect->top, pRect->right, pRect->bottom);

	return TRUE;
}

// Returns the bounding box of a range of cells
BOOL CXGridCtrlBase::GetCellRangeRect(const CGridCellRange& cellRange, LPRECT lpRect) const
{
	CPoint MinOrigin,MaxOrigin;

	if (!GetCellOrigin(cellRange.GetMinRow(), cellRange.GetMinCol(), &MinOrigin)) 
		return FALSE;
	if (!GetCellOrigin(cellRange.GetMaxRow(), cellRange.GetMaxCol(), &MaxOrigin)) 
		return FALSE;

	lpRect->left   = MinOrigin.x;
	lpRect->top    = MinOrigin.y;
	lpRect->right  = MaxOrigin.x + GetColumnWidth(cellRange.GetMaxCol()-1);
	lpRect->bottom = MaxOrigin.y + GetRowHeight(cellRange.GetMaxRow()-1);

	return TRUE;
}

////////////////////////////////////////////////////////////////////////////////////
// Row/Column count functions

BOOL CXGridCtrlBase::SetFixedRowCount(int nFixedRows)
{
	ASSERT(nFixedRows >= 0);

	if (nFixedRows > GetRowCount()) 
		if (!SetRowCount(nFixedRows)) return FALSE;

	if (m_idCurrentCell.row < nFixedRows)
		SetFocusCell(-1,-1);

	m_nFixedRows = nFixedRows;

	if (m_pGridRefWnd->GetSafeHwnd() && m_bAllowDraw)
		m_pGridRefWnd->Invalidate();

	return TRUE;
}

BOOL CXGridCtrlBase::SetFixedColumnCount(int nFixedCols)
{
	ASSERT(nFixedCols >= 0);
	if (nFixedCols > GetColumnCount())
		if (!SetColumnCount(nFixedCols)) return FALSE;

	if (m_idCurrentCell.col < nFixedCols)
		SetFocusCell(-1,-1);

	m_nFixedCols = nFixedCols;

	if (m_pGridRefWnd->GetSafeHwnd() && m_bAllowDraw)
		m_pGridRefWnd->Invalidate();

	return TRUE;
}

BOOL CXGridCtrlBase::SetRowCount(int nRows, BOOL bResetScrollBars)
{
	ASSERT(nRows >= 0);
	if (nRows == GetRowCount()) return TRUE;

	if (nRows < m_nFixedRows) 
		m_nFixedRows = nRows;

	if (m_idCurrentCell.row >= nRows)
		SetFocusCell(-1,-1);

	int addedRows = nRows - GetRowCount();

	// If we are about to lose rows, then we need to delete the GridCell objects 
	// in each column within each row
	if (addedRows < 0) 
	{
		for (int row = nRows; row < m_nRows; row++)
		{
			// Delete rows
			CGridRow* pRow = m_RowData[row];

			if (pRow != NULL)
			{
				pRow->DeleteAllCells();
				delete pRow;
			}
		}
	}

	// Change the number of rows.
	m_nRows = nRows;
	m_RowData.SetSize(m_nRows);
	m_oColumns.SetRowCount(m_nRows);

	// If we have just added rows, we need to construct new elements for each cell
	// and set the default row height
	if (addedRows > 0) 
	{
		// initialize row heights and data
		int startRow = nRows - addedRows;
		for (int row = startRow; row < GetRowCount(); row++) 
		{
			CGridRow* pRow = new CGridRow(this);
			m_RowData.SetAt(row, pRow);
			pRow->m_nRowHeight = m_nDefCellHeight;
			pRow->SetSize(m_nCols);

			if (pRow != NULL)
			{
				for (int col = 0; col < m_nCols; col++)
				{
					CGridColumn *pCol = m_oColumns.GetAt(col);
					CGridCell *pCell = CreateCell(row, col);
					pRow->SetAt(col, pCell);
					pCol->SetAt(row, pCell);
				}
			}
		}

		UpdateRowsColsIndex();
	}
	//else
	//    ResetSelectedRange();

	if (m_pGridRefWnd->GetSafeHwnd() && m_bAllowDraw)
	{
		if (bResetScrollBars)
		{
			ResetScrollBars();
		}

		m_pGridRefWnd->Invalidate();
	}

	return TRUE;
}

BOOL CXGridCtrlBase::SetColumnCount(int nCols)
{
	ASSERT(nCols >= 0);

	if (nCols == GetColumnCount()) return TRUE;

	if (nCols < m_nFixedCols) 
		m_nFixedCols = nCols;

	if (m_idCurrentCell.col >= nCols)
		SetFocusCell(-1,-1);

	CGridColumn *pColumn = NULL;		
	int addedCols = nCols - GetColumnCount();

	// If we are about to lose columns, then we need to delete the GridCell objects 
	// within each column
	if (addedCols < 0) 
	{
		for (int row = 0; row < m_nRows; row++)
		{
			for (int col = nCols; col < GetColumnCount(); col++)
			{
				CGridCell* pCell = GetCell(row, col);

				if (pCell)
				{
					EmptyCell(pCell, row, col);

					delete pCell;
				}
			}
		}

		//delete column
		for (int col = GetColumnCount()-1; col >= nCols; col--)
		{
			pColumn = m_oColumns.GetAt(col);
			delete pColumn;
		}
	}

	// Change the number of columns.
	m_nCols = nCols;
	m_oColumns.SetSize(m_nCols);

	// Change the number of columns in each row.
	for (int i = 0; i < m_nRows; i++)
	{
		if (m_RowData[i]) m_RowData[i]->SetSize(nCols);
	}

	int row = 0, col = 0;
	// If we have just added columns, we need to construct new elements for each cell
	// and set the default column width
	if (addedCols > 0)
	{
		// initialized column widths
		int startCol = nCols - addedCols;
		for (col = startCol; col < m_nCols; col++)
		{
			pColumn = new CGridColumn(this);
			pColumn->m_nWidth = m_nDefCellWidth;
			m_oColumns.SetAt(col, pColumn);
			pColumn->SetSize(m_nRows);
		}

		// initialise column data
		for (row = 0; row < m_nRows; row++)
		{
			for (col = startCol; col < m_nCols; col++)
			{
				pColumn = m_oColumns.GetAt(col);
				CGridRow* pRow = m_RowData[row];

				if (pRow) 	
				{
					CGridCell* pCell = CreateCell(row,col);
					pRow->SetAt(col, pCell);
					pColumn->SetAt(row, pCell);
				}
			}
		}
	}

	UpdateRowsColsIndex();

	if (m_pGridRefWnd->GetSafeHwnd() && m_bAllowDraw)
	{
		ResetScrollBars();
		m_pGridRefWnd->Invalidate();
	}

	return TRUE;
}

// Insert a column at a given position, or add to end of columns (if nColumn = -1)
int CXGridCtrlBase::InsertColumn(LPCTSTR strHeading, 
								 UINT nFormat /* = DT_CENTER|DT_VCENTER|DT_SINGLELINE */,
								 int nColumn  /* = -1 */,
								 int nType	 /* = GVET_NOEDIT 李俊庆添加		2001年8月27日*/)
{
	// If the insertion is for a specific column, check it's within range.
	if (nColumn >= 0 && nColumn > GetColumnCount())
		return -1;

	ResetSelectedRange();

	// Gotta be able to at least _see_ some of the column.
	if (m_nRows < 1)
		SetRowCount(1);    

	if (nColumn < 0)
	{
		nColumn = m_nCols;
		CGridColumn *pColumn = new CGridColumn(this);
		m_oColumns.Add(pColumn);
		//pColumn->SetSize(m_nRows);

		for (int row = 0; row < m_nRows; row++) 
		{
			CGridRow* pRow = m_RowData[row];
			if (!pRow)
				return -1;

			CGridCell *pCell = CreateCell(row, nColumn);
			pCell->nDataType = nType;
			pRow->Add(pCell);
		}
	} 
	else
	{
		CGridColumn *pColumn = new CGridColumn(this);
		m_oColumns.InsertAt(nColumn, pColumn);
		pColumn->SetSize(m_nRows);

		for (int row = 0; row < m_nRows; row++) 
		{
			CGridRow* pRow = m_RowData[row];
			if (!pRow) return -1;

			CGridCell *pCell = CreateCell(row, nColumn);
			pCell->nDataType = nType;
			pRow->InsertAt(nColumn, pCell);
		}
	}

	m_nCols++;

	// Initialise column data
	SetItemText(0, nColumn, strHeading);

	for (int row = 0; row < m_nRows; row++) 
	{
		SetItemFormat(row, nColumn, nFormat);
	}

	// initialized column width
	SetColumnWidth(nColumn, GetTextExtent(strHeading).cx);

	if (m_idCurrentCell.col != -1 && nColumn < m_idCurrentCell.col)
		m_idCurrentCell.col++;

	UpdateRowsColsIndex();
	ResetScrollBars();

	return nColumn;
}

// Insert a row at a given position, or add to end of rows (if nRow = -1)
int CXGridCtrlBase::InsertRow(LPCTSTR strHeading, int nRow /* = -1 */)
{
	// If the insertion is for a specific row, check it's within range.
	if (nRow >= 0 && nRow >= m_nRows)
		return -1;

	ResetSelectedRange();

	// Gotta be able to at least _see_ some of the row.
	if (m_nCols < 1) 
		SetColumnCount(1);    

	// Adding a row to the bottom
	if (nRow < 0) 
	{
		nRow = m_nRows;
		m_RowData.Add(new CGridRow(this));
	} 
	else 
	{
		m_RowData.InsertAt(nRow, new CGridRow(this));
	}

	m_nRows++;	
	m_oColumns.SetRowCount(m_nRows);
	m_RowData[nRow]->SetSize(m_nCols);
	UpdateRowsColsIndex();	

	// Initialise cell data
	CGridRow* pRow = m_RowData[nRow];
	if (!pRow) return -1;
	CGridCell *pCell = NULL;

	for (int col = 0; col < m_nCols; col++)
	{
		pCell = CreateCell(nRow, col);
		pRow->SetAt(col, pCell);
	}

	// Set row title
	SetItemText(nRow, 0, strHeading);

	// initialized row height
	SetRowHeight(nRow, GetTextExtent(strHeading).cy );

	if (m_idCurrentCell.row != -1 && nRow < m_idCurrentCell.row)
		m_idCurrentCell.row++;


	ResetScrollBars();

	return nRow;
}

// Creates a new grid cell and performs any necessary initialisation
CGridCell* CXGridCtrlBase::CreateCell(int nRow, int nCol)
{
	CGridCell* pCell = new CGridCell(nRow, nCol);

	if (!pCell)
	{
		return NULL;
	}

	CGridColumn *pCol = m_oColumns[nCol];
	pCell->m_pRow = m_RowData[nRow];

	if (pCol != NULL)
	{
		if (pCol->GetSize() > nRow)
		{
			pCol->SetAt(nRow, pCell);
		}
		else
		{
			pCol->Add(pCell);
		}
	}

	pCell->m_pColumn = pCol;

	// Make format same as cell above
	if (nRow > 0 && nCol > 0 && nCol < m_nCols)
	{
		pCell->nFormat = GetItemFormat(nRow-1, nCol);
	}

	// Make font default grid font
	memcpy(&(pCell->lfFont), &m_Logfont, sizeof(LOGFONT));
	pCell->dwValue = 0;

	return pCell;
}

// Performs any cell cleanup necessary to maintain grid integrity
void CXGridCtrlBase::EmptyCell(CGridCell* pCell, int nRow, int nCol)
{
	// Set the cells state to 0. If the cell is selected, this
	// will remove the cell from the selected list.
	SetItemState(nRow, nCol, 0);

	// Empty strings
	pCell->szText.Empty();
}

BOOL CXGridCtrlBase::DeleteColumn(int nColumn)
{
	if (nColumn < 0 || nColumn >= GetColumnCount())
		return FALSE;

	ResetSelectedRange();
	CGridColumn *pColumn = m_oColumns.GetAt(nColumn);
	m_oColumns.RemoveAt(nColumn);
	delete pColumn;

	for (int row = 0; row < GetRowCount(); row++) 
	{
		CGridRow* pRow = m_RowData[row];
		if (!pRow) return FALSE;

		CGridCell* pCell = pRow->GetAt(nColumn);

		if (pCell) 
		{
			EmptyCell(pCell, row, nColumn);
			delete pCell;
		}

		pRow->RemoveAt(nColumn);
	}

	m_nCols--;

	if (nColumn < m_nFixedCols) 
		m_nFixedCols--;

	if (nColumn == m_idCurrentCell.col)
	{
		m_idCurrentCell.row = m_idCurrentCell.col = -1;
	}
	else if (nColumn < m_idCurrentCell.col)
	{
		m_idCurrentCell.col--;
	}
	else
	{
	}

	UpdateRowsColsIndex();
	ResetScrollBars();
	m_pGridRefWnd->Invalidate(FALSE);

	return FALSE;
}

BOOL CXGridCtrlBase::DeleteRow(int nRow)
{
	if ( nRow < 0 || nRow >= GetRowCount())
		return FALSE;

	CGridRow* pRow = m_RowData[nRow];
	if (!pRow) return FALSE;

	ResetSelectedRange();

	delete pRow;
	m_RowData.RemoveAt(nRow);
	UpdateRowsColsIndex();

	m_nRows--;
	m_oColumns.SetRowCount(m_nRows);
	if (nRow < m_nFixedRows) m_nFixedRows--;

	if (nRow == m_idCurrentCell.row)
		m_idCurrentCell.row = m_idCurrentCell.col = -1;
	else if (nRow < m_idCurrentCell.row)
		m_idCurrentCell.row--;

	ResetScrollBars();

	return TRUE;
}

// Handy function that removes all non-fixed rows
BOOL CXGridCtrlBase::DeleteNonFixedRows()
{
	int nFixed = GetFixedRowCount();
	int nCount = GetRowCount();

	// Delete all data rows
	for (int nRow = nCount-1; nRow >= nFixed; nRow--) 
		DeleteRow(nRow);

	return TRUE;
}

// Removes all rows, columns and data from the grid.
BOOL CXGridCtrlBase::DeleteAllItems(BOOL bResetScrollBars)
{
	ResetSelectedRange();

	// Delete all cells in the grid
	for (int row = 0; row < m_nRows; row++) 
	{
		CGridRow* pRow = m_RowData[row];
		//        if (!pRow) continue;
		//        for (int col = 0; col < m_nCols; col++)
		//        {
		//            CGridCell* pCell = pRow->GetAt(col);
		//            if (pCell) {
		//                EmptyCell(pCell, row, col);  // TODO - this is a bit of a performance hit.
		//                delete pCell;                // better to call m_SelectedCells.RemoveAll()
		//            }                                // instead. This is safer for changes though.
		//        }
		//pRow->DeleteAllCells();
		delete pRow;
	}

	// Remove all rows
	m_RowData.RemoveAll();
	m_oColumns.DeleteAll();

	m_idCurrentCell.row = m_idCurrentCell.col = -1;
	m_nRows = m_nFixedRows = m_nCols = m_nFixedCols = 0;

	if (bResetScrollBars)
	{
		ResetScrollBars();
	}

	return TRUE;
}

BOOL CXGridCtrlBase::ChangeRowPosition(long nRow1, long nRow2)
{
	if ((nRow1 < 0 || nRow1 >= m_nRows) || (nRow2 < 0 || nRow2 >= m_nRows)) 
	{
		return FALSE;
	}

	CGridRow* pRow1 = m_RowData[nRow1];
	CGridRow* pRow2 = m_RowData[nRow2];

	if (pRow1 == NULL || pRow1 == NULL)
	{
		return FALSE;
	}

	m_RowData.SetAt(nRow2, pRow1);
	m_RowData.SetAt(nRow1, pRow2);

	pRow1->m_nRow = nRow2;
	pRow2->m_nRow = nRow1;

	m_pGridRefWnd->Invalidate(FALSE);

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CXGridCtrlBase data functions

// Set CListCtrl::GetNextItem for details
CCellID CXGridCtrlBase::GetNextItem(CCellID& cell, int nFlags) const
{
	if ((nFlags & GVNI_BELOW) && (nFlags & GVNI_TORIGHT))
	{
		int row = cell.row;
		if (row <= 0) row = GetFixedRowCount();
		for (; row < GetRowCount(); row++)
		{
			int col = cell.col + 1;
			if (col <= 0) col = GetFixedColumnCount();
			for (; col < GetColumnCount(); col++) 
			{
				int nState = GetItemState(row, col);
				if (nFlags & GVNI_DROPHILITED && nState & GVIS_DROPHILITED) 
					return CCellID(row, col);
				if (nFlags & GVNI_FOCUSED && nState & GVIS_FOCUSED)     
					return CCellID(row, col);
				if (nFlags & GVNI_SELECTED && nState & GVIS_SELECTED)   
					return CCellID(row, col);
				if (nFlags & GVNI_READONLY && nState & GVIS_READONLY)   
					return CCellID(row, col);    
			}
		}
	}
	if (nFlags & GVNI_ABOVE) 
	{
		for (int row = cell.row-1; row >= GetFixedRowCount(); row--) 
		{
			int nState = GetItemState(row, cell.col);
			if (nFlags & GVNI_DROPHILITED && nState & GVIS_DROPHILITED) return CCellID(row, cell.col);
			if (nFlags & GVNI_FOCUSED && nState & GVIS_FOCUSED)     return CCellID(row, cell.col);
			if (nFlags & GVNI_SELECTED && nState & GVIS_SELECTED)   return CCellID(row, cell.col);
			if (nFlags & GVNI_READONLY && nState & GVIS_READONLY)   return CCellID(row, cell.col);
		}
	}
	else if (nFlags & GVNI_BELOW)
	{
		for (int row = cell.row+1; row < GetRowCount(); row++) 
		{
			int nState = GetItemState(row, cell.col);
			if (nFlags & GVNI_DROPHILITED && nState & GVIS_DROPHILITED) return CCellID(row, cell.col);
			if (nFlags & GVNI_FOCUSED && nState & GVIS_FOCUSED)     return CCellID(row, cell.col);
			if (nFlags & GVNI_SELECTED && nState & GVIS_SELECTED)   return CCellID(row, cell.col);
			if (nFlags & GVNI_READONLY && nState & GVIS_READONLY)   return CCellID(row, cell.col);
		}
	} 
	else if (nFlags & GVNI_TOLEFT)
	{
		for (int col = cell.col-1; col >= GetFixedColumnCount(); col--) 
		{
			int nState = GetItemState(cell.row, col);
			if (nFlags & GVNI_DROPHILITED && nState & GVIS_DROPHILITED) return CCellID(cell.row, col);
			if (nFlags & GVNI_FOCUSED && nState & GVIS_FOCUSED)     return CCellID(cell.row, col);
			if (nFlags & GVNI_SELECTED && nState & GVIS_SELECTED)   return CCellID(cell.row, col);
			if (nFlags & GVNI_READONLY && nState & GVIS_READONLY)   return CCellID(cell.row, col);
		}
	}
	else if (nFlags & GVNI_TORIGHT) 
	{
		for (int col = cell.col+1; col < GetColumnCount(); col++) 
		{
			int nState = GetItemState(cell.row, col);
			if (nFlags & GVNI_DROPHILITED && nState & GVIS_DROPHILITED) return CCellID(cell.row, col);
			if (nFlags & GVNI_FOCUSED && nState & GVIS_FOCUSED)     return CCellID(cell.row, col);
			if (nFlags & GVNI_SELECTED && nState & GVIS_SELECTED)   return CCellID(cell.row, col);
			if (nFlags & GVNI_READONLY && nState & GVIS_READONLY)   return CCellID(cell.row, col);
		}
	}

	return CCellID(-1, -1);
}

// Sorts on a given column using the cell text
BOOL CXGridCtrlBase::SortTextItems(int nCol, BOOL bAscending)
{
	ResetSelectedRange();
	SetFocusCell(-1,-1);
	return SortTextItems(nCol, bAscending, GetFixedRowCount(),-1);
}

// recursive sort implementation
BOOL CXGridCtrlBase::SortTextItems(int nCol, BOOL bAscending, int low, int high)
{
	if (nCol >= GetColumnCount()) return FALSE;

	if (high == -1) high = GetRowCount() - 1;

	int lo = low;
	int hi = high;

	if( hi <= lo ) return FALSE;

	CString midItem = GetItemText( (lo+hi)/2, nCol );

	// loop through the list until indices cross
	while( lo <= hi )
	{
		// Find the first element that is greater than or equal to the partition 
		// element starting from the left Index.
		if( bAscending )
			while (lo < high  && GetItemText(lo, nCol) < midItem)
				++lo;
		else
			while (lo < high && GetItemText(lo, nCol) > midItem)
				++lo;

		// Find an element that is smaller than or equal to  the partition 
		// element starting from the right Index.
		if( bAscending )
			while (hi > low && GetItemText(hi, nCol) > midItem)
				--hi;
		else
			while (hi > low && GetItemText(hi, nCol) < midItem)
				--hi;

		// If the indexes have not crossed, swap if the items are not equal
		if (lo <= hi)
		{
			// swap only if the items are not equal
			if (GetItemText(lo, nCol) != GetItemText(hi, nCol))
			{
				for (int col = 0; col < GetColumnCount(); col++)
				{
					CGridCell *pCell = GetCell(lo, col);
					SetCell(lo, col, GetCell(hi, col));
					SetCell(hi, col, pCell);
				}

				CGridRow *pRowLO = m_RowData[lo];
				CGridRow *pRowHI = m_RowData[hi];
				UINT nRowHeight = pRowLO->m_nRowHeight;
				pRowLO->m_nRowHeight = pRowHI->m_nRowHeight;
				pRowHI->m_nRowHeight = nRowHeight;
			}

			++lo;
			--hi;
		}
	}

	// If the right index has not reached the left side of array
	// must now sort the left partition.
	if( low < hi )
		SortTextItems(nCol, bAscending, low, hi);

	// If the left index has not reached the right side of array
	// must now sort the right partition.
	if( lo < high )
		SortTextItems(nCol, bAscending, lo, high);

	return TRUE;
}

// Sorts on a given column using the supplied compare function (see CListCtrl::SortItems)
BOOL CXGridCtrlBase::SortItems(PFNLVCOMPARE pfnCompare, int nCol, BOOL bAscending, 
							   LPARAM data /* = 0 */)
{
	ResetSelectedRange();
	SetFocusCell(-1,-1);
	return SortItems(pfnCompare, nCol, bAscending, data, GetFixedRowCount(), -1);
}

// recursive sort implementation
BOOL CXGridCtrlBase::SortItems(PFNLVCOMPARE pfnCompare, int nCol, BOOL bAscending, LPARAM data,
							   int low, int high)
{
	if (nCol >= GetColumnCount()) return FALSE;

	if (high == -1) high = GetRowCount() - 1;

	int lo = low;
	int hi = high;

	if( hi <= lo ) return FALSE;

	LPARAM midItem = GetItemData( (lo+hi)/2, nCol );

	// loop through the list until indices cross
	while( lo <= hi )
	{
		// Find the first element that is greater than or equal to the partition 
		// element starting from the left Index.
		if( bAscending )
			while (lo < high  && pfnCompare(GetItemData(lo, nCol), midItem, data) < 0)
				++lo;
		else
			while (lo < high && pfnCompare(GetItemData(lo, nCol), midItem, data) > 0)
				++lo;

		// Find an element that is smaller than or equal to  the partition 
		// element starting from the right Index.
		if( bAscending )
			while (hi > low && pfnCompare(GetItemData(hi, nCol), midItem, data) > 0)
				--hi;
		else
			while (hi > low && pfnCompare(GetItemData(hi, nCol), midItem, data) < 0)
				--hi;

		// If the indexes have not crossed, swap if the items are not equal
		if (lo <= hi)
		{
			// swap only if the items are not equal
			if (pfnCompare(GetItemData(lo, nCol), GetItemData(hi, nCol), data) != 0)
			{
				for (int col = 0; col < GetColumnCount(); col++)
				{
					CGridCell *pCell = GetCell(lo, col);
					SetCell(lo, col, GetCell(hi, col));
					SetCell(hi, col, pCell);
				}

				CGridRow *pRowLO = m_RowData[lo];
				CGridRow *pRowHI = m_RowData[hi];
				UINT nRowHeight = pRowLO->m_nRowHeight;
				pRowLO->m_nRowHeight = pRowHI->m_nRowHeight;
				pRowHI->m_nRowHeight = nRowHeight;
			}

			++lo;
			--hi;
		}
	}

	// If the right index has not reached the left side of array
	// must now sort the left partition.
	if( low < hi )
		SortItems(pfnCompare, nCol, bAscending, data, low, hi);

	// If the left index has not reached the right side of array
	// must now sort the right partition.
	if( lo < high )
		SortItems(pfnCompare, nCol, bAscending, data, lo, high);

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//grid merge functions
CGridCellRange CXGridCtrlBase::GetSelectedCellRange()
{
	CGridCellRange Selection(GetRowCount(), GetColumnCount(), -1,-1);

	for (POSITION pos = m_SelectedCellMap.GetStartPosition(); pos != NULL; )
	{
		DWORD key;
		CCellID cell;
		m_SelectedCellMap.GetNextAssoc(pos, key, (CCellID&)cell);

		Selection.SetMinRow( min(Selection.GetMinRow(), cell.row) );
		Selection.SetMinCol( min(Selection.GetMinCol(), cell.col) );
		Selection.SetMaxRow( max(Selection.GetMaxRow(), cell.row) );
		Selection.SetMaxCol( max(Selection.GetMaxCol(), cell.col) );
	}

	Selection.SetGridCtrl(this);

	return Selection;
}

// Returns ALL the cells in the grid
CGridCellRange CXGridCtrlBase::GetCellRange()
{
	CGridCellRange oRange(0, 0, GetRowCount() - 1, GetColumnCount() - 1);
	oRange.SetGridCtrl(this);
	return oRange;
}

void CXGridCtrlBase::Merge(const CGridCellRange &oRange)
{

}

void CXGridCtrlBase::Merge(long nRowMin, long nColMin, long nRowMax, long nColMax)
{
	CGridCellRange oRange = GetSelectedCellRange();
	oRange.Set(nRowMin, nColMin, nRowMax, nColMax);
	oRange.Merge(TRUE);
}
//
//CGridCellRange CXGridCtrlBase::GetCellRange()
//{
//	CGridCellRange oCellRange = GetSelectedCellRange();
//	oCellRange.SetGridCtrl(this);
//	return oCellRange;
//}

/////////////////////////////////////////////////////////////////////////////
// CXGridCtrlBase data functions

BOOL CXGridCtrlBase::SetItem(const GV_ITEM* pItem)
{
	if (!pItem) return FALSE;
	CGridCell* pCell = GetCell(pItem->row, pItem->col);
	if (!pCell) return FALSE;


	if (pItem->mask & GVIF_TEXT)   pCell->szText  = pItem->szText;

	if (pItem->mask & GVIF_PARAM)  pCell->lParam  = pItem->lParam;

	if (pItem->mask & GVIF_IMAGE)  pCell->iImage  = pItem->iImage;

	if (pItem->mask & GVIF_STATE)  pCell->state   = pItem->state;

	if (pItem->mask & GVIF_FORMAT) pCell->nFormat = pItem->nFormat;

	if (pItem->mask & GVIF_BKCLR)  pCell->crBkClr = pItem->crBkClr;

	if (pItem->mask & GVIF_FGCLR)  pCell->crFgClr = pItem->crFgClr;

	if (pItem->mask & GVIF_FONT)  
		memcpy(&(pCell->lfFont), &(pItem->lfFont), sizeof(LOGFONT));

	if (pItem->mask & GVIF_DATATYPE)   
		pCell->nDataType = pItem->nDataType;

	if (pItem->mask & GVIF_VALUE)   
		pCell->dwValue = pItem->dwValue;

	if (pItem->mask & GVIF_FUNC)   
		pCell->pEditFunc = pItem->pEditFunc;

	if (pItem->mask & GVIF_MAXLEN)   
		pCell->iMaxLen = pItem->iMaxLen;
	if (pItem->mask & GVIF_STRBLOCKS)   
		pCell->m_pStrCmpBlocks = pItem->pStrCmpBlocks;


	return TRUE;
}

BOOL CXGridCtrlBase::GetItem(GV_ITEM* pItem)
{
	if (!pItem) return FALSE;
	CGridCell* pCell = GetCell(pItem->row, pItem->col);
	if (!pCell) return FALSE;

	if (pItem->mask & GVIF_TEXT)   
		pItem->szText  = GetItemText(pItem->row, pItem->col);
	if (pItem->mask & GVIF_PARAM)  
		pItem->lParam  = pCell->lParam;
	if (pItem->mask & GVIF_IMAGE)  pItem->iImage  = pCell->iImage;
	if (pItem->mask & GVIF_STATE)  pItem->state   = pCell->state;
	if (pItem->mask & GVIF_FORMAT) pItem->nFormat = pCell->nFormat;
	if (pItem->mask & GVIF_BKCLR)  pItem->crBkClr = pCell->crBkClr;
	if (pItem->mask & GVIF_FGCLR)  pItem->crFgClr = pCell->crFgClr;
	if (pItem->mask & GVIF_FONT)   memcpy(&(pItem->lfFont), &(pCell->lfFont), sizeof(LOGFONT));
	if (pItem->mask & GVIF_VALUE)  pItem->dwValue = pCell->dwValue;
	if (pItem->mask & GVIF_FUNC)   pItem->pEditFunc = pCell->pEditFunc;
	if (pItem->mask & GVIF_MAXLEN)   pItem->iMaxLen = pCell->iMaxLen;

	return TRUE;
}

BOOL CXGridCtrlBase::SetItemText(int nRow, int nCol, LPCTSTR str)
{
	CGridCell* pCell = GetCell(nRow, nCol);
	if (!pCell) return FALSE;

	pCell->szText = str;
	return TRUE;
}

BOOL CXGridCtrlBase::SetItemMaxLen(int nRow, int nCol, int iLen)
{
	CGridCell* pCell = GetCell(nRow, nCol);
	if (!pCell) return FALSE;

	pCell->iMaxLen = iLen;
	return TRUE;
}

int CXGridCtrlBase::GetItemMaxLen(int nRow, int nCol)
{
	CGridCell* pCell = GetCell(nRow, nCol);
	if (!pCell) return 0;

	return pCell->iMaxLen;
}

BOOL   CXGridCtrlBase::SetItemValue(int nRow, int nCol, DWORD dwValue)
{
	CGridCell* pCell = GetCell(nRow, nCol);
	if (!pCell) return FALSE;

	pCell->dwValue = dwValue;
	return TRUE;
}

DWORD CXGridCtrlBase::GetItemValue(int nRow, int nCol) const
{
	CGridCell* pCell = GetCell(nRow, nCol);
	if (!pCell) return (LPARAM) 0;

	return pCell->dwValue;
}

BOOL CXGridCtrlBase::SetItemData(int nRow, int nCol, LPARAM lParam)
{
	CGridCell* pCell = GetCell(nRow, nCol);
	if (!pCell) return FALSE;

	pCell->lParam = lParam;
	return TRUE;
}

LPARAM CXGridCtrlBase::GetItemData(int nRow, int nCol) const
{    
	CGridCell* pCell = GetCell(nRow, nCol);
	if (!pCell) return (LPARAM) 0;

	return pCell->lParam;
}

BOOL CXGridCtrlBase::SetItemImage(int nRow, int nCol, int iImage)
{
	CGridCell* pCell = GetCell(nRow, nCol);
	if (!pCell) return FALSE;

	pCell->iImage = iImage;
	return TRUE;
}

int CXGridCtrlBase::GetItemImage(int nRow, int nCol) const
{
	CGridCell* pCell = GetCell(nRow, nCol);
	ASSERT(pCell);
	if (!pCell) return -1;

	return pCell->iImage;
}

BOOL CXGridCtrlBase::SetItemState(int nRow, int nCol, UINT state)
{
	CGridCell* pCell = GetCell(nRow, nCol);
	ASSERT(pCell);
	if (!pCell) return FALSE;

	// If the cell is being unselected, remove it from the selected list
	if ((pCell->state & GVIS_SELECTED) && !(state & GVIS_SELECTED))
	{
		CCellID cell;
		DWORD key = MAKELONG(nRow, nCol);

		if (m_SelectedCellMap.Lookup(key, (CCellID&)cell))
			m_SelectedCellMap.RemoveKey(key);
	}

	// If cell is being selected, add it to the list of selected cells
	else if (!(pCell->state & GVIS_SELECTED) && (state & GVIS_SELECTED))
	{
		CCellID cell(nRow, nCol);
		m_SelectedCellMap.SetAt(MAKELONG(nRow, nCol), cell);
	}

	// Set the cell's state
	pCell->state = state;

	return TRUE;
}


BOOL CXGridCtrlBase::SetItemState(CGridCell *pCell, UINT state)
{
	ASSERT(pCell);
	if (!pCell) return FALSE;

	int nRow = 0;
	int nCol = 0;
	pCell->GetRowCol(nRow, nCol);

	// If the cell is being unselected, remove it from the selected list
	if ((pCell->state & GVIS_SELECTED) && !(state & GVIS_SELECTED))
	{
		CCellID cell;
		DWORD key = MAKELONG(nRow, nCol);

		if (m_SelectedCellMap.Lookup(key, (CCellID&)cell))
			m_SelectedCellMap.RemoveKey(key);
	}

	// If cell is being selected, add it to the list of selected cells
	else if (!(pCell->state & GVIS_SELECTED) && (state & GVIS_SELECTED))
	{
		CCellID cell(nRow, nCol);
		m_SelectedCellMap.SetAt(MAKELONG(nRow, nCol), cell);
	}

	// Set the cell's state
	pCell->state = state;

	return TRUE;
}

UINT CXGridCtrlBase::GetItemState(int nRow, int nCol) const
{
	CGridCell* pCell = GetCell(nRow, nCol);
	ASSERT(pCell);
	if (!pCell) return 0;

	return pCell->state;
}

BOOL CXGridCtrlBase::SetItemFormat(int nRow, int nCol, UINT nFormat)
{
	CGridCell* pCell = GetCell(nRow, nCol);
	ASSERT(pCell);
	if (!pCell) return FALSE;

	pCell->nFormat = nFormat;
	return TRUE;
}

UINT CXGridCtrlBase::GetItemFormat(int nRow, int nCol) const
{
	CGridCell* pCell = GetCell(nRow, nCol);
	ASSERT(pCell);
	if (!pCell) return 0;

	return pCell->nFormat;
}

BOOL CXGridCtrlBase::SetItemBkColour(int nRow, int nCol, COLORREF cr /* = CLR_DEFAULT */)
{
	CGridCell* pCell = GetCell(nRow, nCol);
	ASSERT(pCell);
	if (!pCell) return FALSE;

	pCell->crBkClr = cr;
	return TRUE;
}

COLORREF CXGridCtrlBase::GetItemBkColour(int nRow, int nCol) const
{
	CGridCell* pCell = GetCell(nRow, nCol);
	ASSERT(pCell);
	if (!pCell) return 0;

	return pCell->crBkClr;
}

BOOL CXGridCtrlBase::SetItemFgColour(int nRow, int nCol, COLORREF cr /* = CLR_DEFAULT */)
{
	CGridCell* pCell = GetCell(nRow, nCol);
	ASSERT(pCell);
	if (!pCell) return FALSE;

	pCell->crFgClr = cr;
	return TRUE;
}

COLORREF CXGridCtrlBase::GetItemFgColour(int nRow, int nCol) const
{
	CGridCell* pCell = GetCell(nRow, nCol);
	ASSERT(pCell);
	if (!pCell) return 0;

	return pCell->crFgClr;
}

BOOL CXGridCtrlBase::SetItemFont(int nRow, int nCol, LOGFONT* lf)
{
	CGridCell* pCell = GetCell(nRow, nCol);
	ASSERT(pCell);
	if (!pCell) return FALSE;

	memcpy(&(pCell->lfFont), lf, sizeof(LOGFONT));
	return TRUE;
}

BOOL CXGridCtrlBase::SetItemFontBold(int nRow, int nCol, BOOL bBold)
{
	CGridCell* pCell = GetCell(nRow, nCol);
	ASSERT(pCell);
	if (!pCell) return FALSE;

	if (bBold)
	{
		pCell->lfFont.lfWeight = 600;
	}
	else
	{
		pCell->lfFont.lfWeight = 400;
	}

	return TRUE;
}


LOGFONT* CXGridCtrlBase::GetItemFont(int nRow, int nCol) const
{
	CGridCell* pCell = GetCell(nRow, nCol);
	ASSERT(pCell);
	if (!pCell) return NULL;

	return &pCell->lfFont;
}

////////////////////////////////////////////////////////////////////////////////////
// Row/Column size functions

long CXGridCtrlBase::GetVirtualWidth() const
{
	long lVirtualWidth = 0;
	int iColCount = GetColumnCount();
	for (int i = 0; i < iColCount; i++)
	{
		lVirtualWidth += GetColumnWidth(i);
	}

	return lVirtualWidth;
}

long CXGridCtrlBase::GetVirtualHeight() const
{
	long lVirtualHeight = 0;
	int iRowCount = GetRowCount();
	for (int i = 0; i < iRowCount; i++)
	{
		lVirtualHeight += GetRowHeight(i);
	}

	return lVirtualHeight;
}
BOOL CXGridCtrlBase::SetColumnType(int nCol, int nType)
{
	ASSERT(nCol >= 0 && nCol < m_nCols && nType >= 0);
	if (nCol < 0 || nCol >= m_nCols || nType < 0) return FALSE;

	CGridColumn *pCol = m_oColumns[nCol];
	ASSERT (pCol != NULL);

	if (pCol != NULL)
	{
		pCol->SetColumnType(nType);
	}

	return TRUE;
}

int CXGridCtrlBase::GetColumnType(int nCol) const
{
	ASSERT(nCol >= 0 && nCol < m_nCols);
	if (nCol < 0 || nCol >= m_nCols) return -1;

	return -1;
}

int CXGridCtrlBase::GetRowHeight(int nRow) const
{
	ASSERT(nRow >= 0 && nRow < m_nRows);
	if (nRow < 0 || nRow >= m_nRows) return -1;

	return m_RowData.GetRowHeight(nRow);
}

int CXGridCtrlBase::GetColumnWidth(int nCol) const
{
	ASSERT(nCol >= 0 && nCol < m_nCols);
	if (nCol < 0 || nCol >= m_nCols) return -1;

	CGridColumn *pCol = m_oColumns[nCol];

	if (pCol == NULL)
	{
		return -1;
	}

	return pCol->m_nWidth;
}

BOOL CXGridCtrlBase::SetRowHeight(int nRow, int height)
{
	ASSERT(nRow >= 0 && nRow < m_nRows && height >= 0);
	if (nRow < 0 || nRow >= m_nRows || height < 0) return FALSE;

	m_RowData.SetRowHeight(nRow, height);
	return TRUE;
}

BOOL CXGridCtrlBase::SetColumnWidth(int nCol, int width)
{
	ASSERT(nCol >= 0 && nCol < m_nCols && width >= 0);
	if (nCol < 0 || nCol >= m_nCols || width < 0)
	{
		return FALSE;
	}

	CGridColumn *pCol = m_oColumns[nCol];

	if (pCol == NULL)
	{
		return FALSE;
	}

	pCol->m_nWidth = width;

	return TRUE;
}

int CXGridCtrlBase::GetFixedRowHeight() const
{
	int nHeight = 0;
	for (int i = 0; i < m_nFixedRows; i++)
		nHeight += GetRowHeight(i);

	return nHeight;
}

int CXGridCtrlBase::GetFixedColumnWidth() const
{
	int nWidth = 0;
	for (int i = 0; i < m_nFixedCols; i++)
		nWidth += GetColumnWidth(i);

	return nWidth;
}

BOOL CXGridCtrlBase::AutoSizeColumn(int nCol, BOOL bResetScrollBars)
{
	ASSERT(nCol >= 0 && nCol < m_nCols);
	if (nCol < 0 || nCol >= m_nCols) return FALSE;

	CSize size;
	CDC* pDC = m_pGridRefWnd->GetDC();
	if (!pDC) return FALSE;

	int nWidth = 0;
	int nNumRows = GetRowCount();
	for (int nRow = 0; nRow < nNumRows; nRow++)
	{
		size = GetCellExtent(nRow, nCol, pDC);
		if (size.cx > nWidth) nWidth = size.cx;
	}

	SetColumnWidth(nCol, nWidth);

	m_pGridRefWnd->ReleaseDC(pDC);

	if (bResetScrollBars)
	{
		ResetScrollBars();
	}

	return TRUE;
}

BOOL CXGridCtrlBase::AutoSizeRow(int nRow)
{
	ASSERT(nRow >= 0 && nRow < m_nRows);
	if (nRow < 0 || nRow >= m_nRows) return FALSE;

	CSize size;
	CDC* pDC = m_pGridRefWnd->GetDC();
	if (!pDC) return FALSE;

	int nHeight = 0;
	int nNumColumns = GetColumnCount();
	for (int nCol = 0; nCol < nNumColumns; nCol++)
	{  
		size = GetCellExtent(nRow, nCol, pDC);
		if (size.cy > nHeight) nHeight = size.cy;
	}  

	SetRowHeight(nRow, nHeight);

	m_pGridRefWnd->ReleaseDC(pDC);
	ResetScrollBars();

	return TRUE;
}

void CXGridCtrlBase::AutoSizeColumns()
{
	int nNumColumns = GetColumnCount();
	for (int nCol = 0; nCol < nNumColumns; nCol++)
		AutoSizeColumn(nCol);
}

void CXGridCtrlBase::AutoSizeRows()
{
	int nNumRows = GetRowCount();
	for (int nRow = 0; nRow < nNumRows; nRow++)
		AutoSizeRow(nRow);
}

// sizes all rows and columns
// faster than calling both AutoSizeColumns() and AutoSizeRows()
void CXGridCtrlBase::AutoSize(BOOL bSizeVert, BOOL bSizeHorz)
{
	CDC* pDC = m_pGridRefWnd->GetDC();
	if (!pDC) return;

	int nNumColumns = GetColumnCount();
	int nNumRows = GetRowCount();
	int nRow = 0;

	// initialize row heights to zero
	if (bSizeVert)
	{
		for (nRow = 0; nRow < nNumRows; nRow++)
		{
			SetRowHeight(nRow, 0);
		}
	}

	CSize size;
	int nCol = 0;
	CGridColumn *pCol = NULL;

	for (nCol = 0; nCol < nNumColumns; nCol++)
	{
		pCol = m_oColumns[nCol];

		for (nRow = 0; nRow < nNumRows; nRow++)
		{
			size = GetCellExtent(nRow, nCol, pDC);

			if (size.cx > pCol->m_nWidth) 
			{
				if (bSizeHorz)
				{
					pCol->m_nWidth = size.cx;
				}
			}

			CGridRow *pRow = m_RowData[nRow];

			if (size.cy > pRow->m_nRowHeight) 
			{
				if (bSizeVert)
				{
					pRow->m_nRowHeight = size.cy;
				}
			}
		}
	}

	m_pGridRefWnd->ReleaseDC(pDC);

	if (m_bAllowDraw) 
	{
		ResetScrollBars();
		m_pGridRefWnd->Invalidate();
	}
}

void CXGridCtrlBase::ExpandColumnsToFit()
{
	if (GetColumnCount() <= 0) return;

	CRect rect;
	GetGridClientRect(rect);

	long virtualWidth = GetVirtualWidth();
	int nDifference = rect.Width() - (int) virtualWidth;
	int nColumnAdjustment = nDifference / GetColumnCount();
	int i = 0;

	for (i = 0; i < GetColumnCount(); i++)
	{
		SetColumnWidth(i, nColumnAdjustment);
	}

	if (nDifference > 0)
	{
		int leftOver = nDifference % GetColumnCount();

		for (i = 0; i < leftOver; i++)
		{
			SetColumnWidth(i, GetColumnWidth(i)+1);
		}
	} 
	else 
	{
		int leftOver = (-nDifference) % GetColumnCount();
		for (i = 0; i < leftOver; i++)
		{
			SetColumnWidth(i, GetColumnWidth(i)-1);
		}
	}

	if (m_bAllowDraw) 
		m_pGridRefWnd->Invalidate();
}

void CXGridCtrlBase::ExpandColumnsToFitEx()
{
	if (GetColumnCount() <= 0) return;

	CRect rect;
	GetGridClientRect(rect);

	long virtualWidth = GetVirtualWidth();
	int nDifference = rect.Width() - (int) virtualWidth;
	int nColumnAdjustment = nDifference / (GetColumnCount()-1);//编号列不收缩
	int i = 0;

	for (i = 1; i < GetColumnCount(); i++)
	{
		if(GetColumnWidth(i)+nColumnAdjustment > 0)
		{
			SetColumnWidth(i, GetColumnWidth(i)+nColumnAdjustment);
		}	
	}

	if (m_bAllowDraw) 
		m_pGridRefWnd->Invalidate();
}

void CXGridCtrlBase::ExpandRowsToFit()
{
	if (GetRowCount() <= 0) return;

	CRect rect;
	GetGridClientRect(rect);

	long virtualHeight = GetVirtualHeight();
	int nDifference = rect.Height() - (int) virtualHeight;
	int nRowAdjustment = nDifference / GetRowCount();
	int i = 0;

	for (i = 0; i < GetRowCount(); i++)
	{
		SetRowHeight(i, GetRowHeight(i)+nRowAdjustment);
	}

	if (nDifference > 0)
	{
		int leftOver = nDifference % GetRowCount();
		for (i = 0; i < leftOver; i++)
		{
			SetRowHeight(i, GetRowHeight(i)+1);			
		}
	} 
	else 
	{
		int leftOver = (-nDifference) % GetRowCount();
		for (i = 0; i < leftOver; i++)
		{
			SetRowHeight(i, GetRowHeight(i)-1);

		}
	}

	if (m_bAllowDraw) 
		m_pGridRefWnd->Invalidate();
}

void CXGridCtrlBase::ExpandToFit()
{
	ExpandColumnsToFit();   // This will remove any existing horz scrollbar
	ExpandRowsToFit();      // This will remove any existing vert scrollbar
	ExpandColumnsToFit();   // Just in case the first adjustment was with a vert
	// scrollbar in place
}

/////////////////////////////////////////////////////////////////////////////////////
// GridCtrl cell visibility tests and invalidation/redraw functions

// EnsureVisible supplied by Roelf Werkman
void CXGridCtrlBase::EnsureVisible(int nRow, int nCol)
{
	if (nRow < 0 || nCol < 0)
	{
		return;
	}

	CGridCellRange VisibleCells = GetVisibleNonFixedCellRange();

	int right = nCol - VisibleCells.GetMaxCol();
	int left  = VisibleCells.GetMinCol() - nCol;
	int down  = nRow - VisibleCells.GetMaxRow();
	int up    = VisibleCells.GetMinRow() - nRow;

	if (!::IsWindow(m_pGridRefWnd->GetSafeHwnd())) 
	{
		return;
	}

	while (right > 0)
	{
		m_pGridRefWnd->SendMessage(WM_HSCROLL, SB_LINERIGHT, 0);
		right--;
	}
	while (left > 0)
	{
		m_pGridRefWnd->SendMessage(WM_HSCROLL, SB_LINELEFT, 0);
		left--;
	}
	while (down > 0)
	{
		m_pGridRefWnd->SendMessage(WM_VSCROLL, SB_LINEDOWN, 0);
		down--;
	}
	while (up > 0)
	{
		m_pGridRefWnd->SendMessage(WM_VSCROLL, SB_LINEUP, 0);
		up--;
	}

	// Move one more if we only see a snall bit of the cell
	CRect rectCell, rectWindow;
	GetCellRect(nRow, nCol, rectCell);
	GetGridClientRect(rectWindow);
	if (rectCell.right > rectWindow.right)
		m_pGridRefWnd->SendMessage(WM_HSCROLL, SB_LINERIGHT, 0);
	if (rectCell.bottom > rectWindow.bottom)
		m_pGridRefWnd->SendMessage(WM_VSCROLL, SB_LINEDOWN, 0);
}

void CXGridCtrlBase::SetTopRow(int nRow)
{
	if (nRow < 0 )
	{
		return;
	}

	CGridCellRange VisibleCells = GetVisibleNonFixedCellRange();

	int down  = nRow - VisibleCells.GetMinRow();
	int up    = VisibleCells.GetMinRow() - nRow;

	if (!::IsWindow(m_pGridRefWnd->GetSafeHwnd())) 
	{
		return;
	}

	while (down > 0)
	{
		m_pGridRefWnd->SendMessage(WM_VSCROLL, SB_LINEDOWN, 0);
		down--;
	}
	while (up > 0)
	{
		m_pGridRefWnd->SendMessage(WM_VSCROLL, SB_LINEUP, 0);
		up--;
	}

	// Move one more if we only see a snall bit of the cell
	CRect rectCell, rectWindow;
	GetCellRect(nRow, 0, rectCell);
	GetGridClientRect(rectWindow);
	if (rectCell.right > rectWindow.right)
		m_pGridRefWnd->SendMessage(WM_HSCROLL, SB_LINERIGHT, 0);
	if (rectCell.bottom > rectWindow.bottom)
		m_pGridRefWnd->SendMessage(WM_VSCROLL, SB_LINEDOWN, 0);
}

int CXGridCtrlBase::GetTopRow()
{
	CGridCellRange VisibleCells = GetVisibleNonFixedCellRange();
	return VisibleCells.GetMinRow();
}

BOOL CXGridCtrlBase::IsCellEditable(CCellID &cell) const
{
	return IsCellEditable(cell.row, cell.col); 
}

BOOL CXGridCtrlBase::IsCellEditable(int nRow, int nCol) const
{
	unsigned int uiState=GetItemState(nRow, nCol);
	uiState &= GVIS_READONLY;

	BOOL b=IsEditable() && (uiState != GVIS_READONLY);
	return b;
}

BOOL CXGridCtrlBase::IsCellVisible(CCellID cell) const
{  
	CGridCell *pCell = GetCell(cell.row, cell.col);

	if (pCell == NULL)
	{
		return FALSE;
	}

	if (pCell->m_pMergeTo == NULL)
	{
		return IsCellVisible(cell.row, cell.col);
	}
	else
	{
		CGridCellRange oCellRange;
		pCell->m_pMergeTo->GetCellRange(oCellRange);
		return IsCellRangeVisible(oCellRange);		
	}
}

BOOL CXGridCtrlBase::IsCellVisible(int nRow, int nCol) const
{  
	if (!IsWindow(m_pGridRefWnd->m_hWnd))
		return FALSE;

	CGridCell *pCell = GetCell(nRow, nCol);
	int x,y;

	CCellID TopLeft;
	if (nCol >= GetFixedColumnCount() || nRow >= GetFixedRowCount())
	{
		TopLeft = GetTopleftNonFixedCell();
		if (nCol >= GetFixedColumnCount() && nCol < TopLeft.col) return FALSE;
		if (nRow >= GetFixedRowCount() && nRow < TopLeft.row) return FALSE;
	}

	CRect rect;
	GetGridClientRect(rect);
	if (nCol < GetFixedColumnCount())
	{
		x = 0;
		for (int i = 0; i <= nCol; i++) 
		{
			if (x >= rect.right) return FALSE;
			x += GetColumnWidth(i);    
		}
	} 
	else 
	{
		x = GetFixedColumnWidth();
		for (int i = TopLeft.col; i <= nCol; i++) 
		{
			if (x >= rect.right) return FALSE;
			x += GetColumnWidth(i);    
		}
	}

	if (nRow < GetFixedRowCount())
	{
		y = 0;
		for (int i = 0; i <= nRow; i++) 
		{
			if (y >= rect.bottom) return FALSE;
			y += GetRowHeight(i);    
		}
	} 
	else 
	{
		if (nRow < TopLeft.row) return FALSE;
		y = GetFixedRowHeight();
		for (int i = TopLeft.row; i <= nRow; i++) 
		{
			if (y >= rect.bottom) return FALSE;
			y += GetRowHeight(i);    
		}
	}

	return TRUE;
}

BOOL CXGridCtrlBase::IsCellRangeVisible(const CGridCellRange &oCellRange) const
{
	int nRow = 0;
	int nCol = 0;
	BOOL bVisible = FALSE;

	for (nRow=oCellRange.m_nMinRow; nRow <= oCellRange.m_nMaxRow; nRow++)
	{
		for (nCol = oCellRange.m_nMinCol; nCol <= oCellRange.m_nMaxCol; nCol++)
		{
			if (IsCellVisible(nRow, nCol))
			{
				bVisible = TRUE;
				break;
			}
		}
	}

	return bVisible;
}

BOOL CXGridCtrlBase::InvalidateCellRect(const CCellID& cell)
{
	if (!::IsWindow(m_pGridRefWnd->GetSafeHwnd()) || !m_bAllowDraw)
		return FALSE;

	ASSERT(IsValid(cell));

	if (!IsCellVisible(cell)) return FALSE;

	CRect rect;
	if (!GetCellRect(cell, rect)) return FALSE;

	rect.right++; rect.bottom++;

	if (m_pViewWindowPos != NULL)
	{
		m_pViewWindowPos->ViewToWindow(rect);
	}

	CGridCell *pCell = GetCell(cell.row, cell.col);

	if (pCell != NULL)
	{
		if (pCell->m_pMergeTo == NULL)
		{
			m_pGridRefWnd->InvalidateRect(rect, TRUE);
		}
		else
		{
			if (pCell->m_pMergeTo == pCell)
			{
				m_pGridRefWnd->InvalidateRect(rect, TRUE);
			}
		}
	}

	return TRUE;
}

BOOL CXGridCtrlBase::InvalidateCellRect(const CGridCellRange& cellRange)
{
	ASSERT(IsValid(cellRange));
	if (!::IsWindow(m_pGridRefWnd->GetSafeHwnd()) || !m_bAllowDraw) return FALSE;

	CGridCellRange visibleCellRange = GetVisibleNonFixedCellRange().Intersect(cellRange);

	CRect rect;
	if (!GetCellRangeRect(visibleCellRange, rect)) return FALSE;

	rect.right++; rect.bottom++;

	if (m_pViewWindowPos != NULL)
	{
		m_pViewWindowPos->ViewToWindow(rect);
	}

	m_pGridRefWnd->InvalidateRect(rect, TRUE);

	return TRUE;
}



void  CXGridCtrlBase::OnEditCellLBDblClk(int nRow, int nCol, UINT nChar)
{
	OnEditCell(nRow, nCol, nChar);
}

void  CXGridCtrlBase::OnEditCellRBDblClk(int nRow, int nCol, UINT nChar)
{

}

void CXGridCtrlBase::KillFoucusEditWnd()
{
	m_pGridRefWnd->SetFocus();        // Auto-destroy any InPlaceEdit's
	SetSelectedRange(-1, -1, -1, -1);
	SetFocusCell(-1, -1);
}

/////////////////////////////////////////////////////////////////////////////
// CXGridCtrlBase printing 

void CXGridCtrlBase::Print() 
{
	CDC dc;
	CPrintDialog printDlg(FALSE);

	if (printDlg.DoModal() != IDOK)             // Get printer settings from user
		return;

	dc.Attach(printDlg.GetPrinterDC());         // attach a printer DC
	dc.m_bPrinting = TRUE;

	CString strTitle;
	strTitle.LoadString(AFX_IDS_APP_TITLE);

	DOCINFO di;                                 // Initialise print doc details
	::ZeroMemory (&di, sizeof (DOCINFO));
	di.cbSize = sizeof (DOCINFO);
	di.lpszDocName = strTitle;

	BOOL bPrintingOK = dc.StartDoc(&di);        // Begin a new print job

	CPrintInfo Info;
	Info.m_rectDraw.SetRect(0,0, dc.GetDeviceCaps(HORZRES), dc.GetDeviceCaps(VERTRES));

	OnBeginPrinting(&dc, &Info);                // Initialise printing
	for (UINT page = Info.GetMinPage(); page <= Info.GetMaxPage() && bPrintingOK; page++)
	{
		dc.StartPage();                         // begin new page
		Info.m_nCurPage = page;
		OnPrint(&dc, &Info);                    // Print page
		bPrintingOK = (dc.EndPage() > 0);       // end page
	}
	OnEndPrinting(&dc, &Info);                  // Clean up after printing

	if (bPrintingOK)
		dc.EndDoc();                            // end a print job
	else
		dc.AbortDoc();                          // abort job.

	dc.Detach();                                // detach the printer DC
}


void CXGridCtrlBase::OnBeginPrinting(CDC *pDC, CPrintInfo *pInfo)
{
	// OnBeginPrinting() is called after the user has committed to
	// printing by OK'ing the Print dialog, and after the framework
	// has created a CDC object for the printer or the preview view.

	// This is the right opportunity to set up the page range.
	// Given the CDC object, we can determine how many rows will
	// fit on a page, so we can in turn determine how many printed
	// pages represent the entire document.

	ASSERT(pDC && pInfo);
	if (!pDC || !pInfo) return;

	int nMaxRowCount = GetRowCount() - GetFixedRowCount();
	if (!nMaxRowCount) return;

	// Get a DC for the current window (will be a screen DC for print previewing)
	CDC *pCurrentDC = m_pGridRefWnd->GetDC();        // will have dimensions of the client area
	if (!pCurrentDC) return;

	CSize PaperPixelsPerInch(pDC->GetDeviceCaps(LOGPIXELSX), pDC->GetDeviceCaps(LOGPIXELSY));
	CSize ScreenPixelsPerInch(pCurrentDC->GetDeviceCaps(LOGPIXELSX), pCurrentDC->GetDeviceCaps(LOGPIXELSY));

	// Create the printer font
	int nFontSize = -9;
	CString strFontName = _T("Times New Roman");
	m_PrinterFont.CreateFont(nFontSize, 0,0,0, FW_NORMAL, 0,0,0, DEFAULT_CHARSET,
		OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, strFontName);

	CFont *pOldFont = pDC->SelectObject(&m_PrinterFont);

	// Get the average character width (in GridCtrl units) and hence the margins
	m_CharSize = pDC->GetTextExtent(_T("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSATUVWXYZ"),52);
	m_CharSize.cx /= 52;
	int nMargins = (LEFT_MARGIN+RIGHT_MARGIN)*m_CharSize.cx;

	// Get the page sizes (physical and logical)
	m_PaperSize = CSize(pDC->GetDeviceCaps(HORZRES), pDC->GetDeviceCaps(VERTRES));
	m_LogicalPageSize.cx = GetVirtualWidth()+nMargins;
	m_LogicalPageSize.cy = MulDiv(m_LogicalPageSize.cx, m_PaperSize.cy, m_PaperSize.cx);

	m_nPageHeight = m_LogicalPageSize.cy - GetFixedRowHeight()
		- (HEADER_HEIGHT+FOOTER_HEIGHT + 2*GAP)*m_CharSize.cy;

	// Get the number of pages. Assumes no row is bigger than the page size.
	int nTotalRowHeight = 0;
	int nNumPages = 1;
	for (int row = GetFixedRowCount(); row < GetRowCount(); row++)
	{
		nTotalRowHeight += GetRowHeight(row);
		if (nTotalRowHeight > m_nPageHeight) {
			nNumPages++;
			nTotalRowHeight = GetRowHeight(row);
		}
	}

	// Set up the print info
	pInfo->SetMaxPage(nNumPages);
	pInfo->m_nCurPage = 1;                        // start printing at page# 1

	m_pGridRefWnd->ReleaseDC(pCurrentDC);
	pDC->SelectObject(pOldFont);
}

void CXGridCtrlBase::OnPrint(CDC *pDC, CPrintInfo *pInfo)
{
	if (!pDC || !pInfo) return;

	//CRect rcPage(pInfo->m_rectDraw);
	CFont *pOldFont = pDC->SelectObject(&m_PrinterFont);

	// Set the page map mode to use GridCtrl units, and setup margin
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(m_LogicalPageSize);
	pDC->SetViewportExt(m_PaperSize);
	pDC->SetWindowOrg(-LEFT_MARGIN*m_CharSize.cx, 0);

	// Header
	pInfo->m_rectDraw.top    = 0;
	pInfo->m_rectDraw.left   = 0;
	pInfo->m_rectDraw.right  = m_LogicalPageSize.cx - (LEFT_MARGIN+RIGHT_MARGIN)*m_CharSize.cx;
	pInfo->m_rectDraw.bottom = HEADER_HEIGHT*m_CharSize.cy;
	PrintHeader(pDC, pInfo);
	pDC->OffsetWindowOrg(0, -HEADER_HEIGHT*m_CharSize.cy);

	// Gap between header and column headings
	pDC->OffsetWindowOrg(0, -GAP*m_CharSize.cy);

	// Print the column headings
	pInfo->m_rectDraw.bottom = GetFixedRowHeight(); 
	PrintColumnHeadings(pDC, pInfo);
	pDC->OffsetWindowOrg(0, -GetFixedRowHeight()); 

	// We need to find out which row to start printing for this page.
	int nTotalRowHeight = 0;
	UINT nNumPages = 1;
	int nCurrPrintRow = GetFixedRowCount();

	while (nCurrPrintRow < GetRowCount() && nNumPages < pInfo->m_nCurPage)
	{
		nTotalRowHeight += GetRowHeight(nCurrPrintRow);
		if (nTotalRowHeight > m_nPageHeight) {
			nNumPages++;
			if (nNumPages == pInfo->m_nCurPage) break;
			nTotalRowHeight = GetRowHeight(nCurrPrintRow);
		}
		nCurrPrintRow++;
	}
	if (nCurrPrintRow >= GetRowCount()) return;

	// Draw as many rows as will fit on the printed page.
	// Clip the printed page so that there is no partially shown
	// row at the bottom of the page (the same row which will be fully
	// shown at the top of the next page).

	BOOL bFirstPrintedRow = TRUE;
	CRect rect;
	rect.bottom = -1;
	while (nCurrPrintRow < GetRowCount())
	{
		rect.top = rect.bottom+1;
		rect.bottom = rect.top + GetRowHeight(nCurrPrintRow) - 1;

		if (rect.bottom > m_nPageHeight) break;            // Gone past end of page

		rect.right = -1;
		for (int col = 0; col < GetColumnCount(); col++)
		{
			rect.left = rect.right+1;
			rect.right = rect.left + GetColumnWidth(col) - 1;

			CGridCell *pCell = GetCell(nCurrPrintRow, col);
			pCell->DrawCell(pDC, rect, this, TRUE, TRUE);

			if (m_nGridLines == GVL_BOTH || m_nGridLines == GVL_HORZ) 
			{
				int Overlap = (col == 0)? 0:1;
				pDC->MoveTo(rect.left-Overlap, rect.bottom);
				pDC->LineTo(rect.right, rect.bottom);
				if (nCurrPrintRow == 0) {
					pDC->MoveTo(rect.left-Overlap, rect.top);
					pDC->LineTo(rect.right, rect.top);
				}
			}
			if (m_nGridLines == GVL_BOTH || m_nGridLines == GVL_VERT) 
			{
				int Overlap = (bFirstPrintedRow)? 0:1;
				pDC->MoveTo(rect.right, rect.top-Overlap);
				pDC->LineTo(rect.right, rect.bottom);    
				if (col == 0) {
					pDC->MoveTo(rect.left, rect.top-Overlap);
					pDC->LineTo(rect.left, rect.bottom);    
				}
			}

		}
		nCurrPrintRow++;
		bFirstPrintedRow = FALSE;
	}

	// Footer
	pInfo->m_rectDraw.bottom = FOOTER_HEIGHT*m_CharSize.cy;
	pDC->SetWindowOrg(-LEFT_MARGIN*m_CharSize.cx, -m_LogicalPageSize.cy + FOOTER_HEIGHT*m_CharSize.cy);
	PrintFooter(pDC, pInfo);

	// SetWindowOrg back for next page
	pDC->SetWindowOrg(0,0);

	pDC->SelectObject(pOldFont);
}

void CXGridCtrlBase::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	m_PrinterFont.DeleteObject();
}


/////////////////////////////////////////////////////////////////////////////
// CXGridCtrlBase printing overridables - for Doc/View print/print preview framework

void CXGridCtrlBase::PrintColumnHeadings(CDC *pDC, CPrintInfo* /*pInfo*/)
{
	CFont *pOldFont = pDC->SelectObject(&m_PrinterFont);

	CRect rect;
	rect.bottom = -1;
	for (int row = 0; row < GetFixedRowCount(); row++)
	{
		rect.top = rect.bottom+1;
		rect.bottom = rect.top + GetRowHeight(row) - 1;

		rect.right = -1;
		for (int col = 0; col < GetColumnCount(); col++)
		{
			rect.left = rect.right+1;
			rect.right = rect.left + GetColumnWidth(col) - 1;

			CGridCell *pCell = GetCell(row, col);
			pCell->DrawFixedCell(pDC, rect, this, row, col);

			if (m_nGridLines == GVL_BOTH || m_nGridLines == GVL_HORZ) 
			{
				int Overlap = (col == 0)? 0:1;
				pDC->MoveTo(rect.left-Overlap, rect.bottom);
				pDC->LineTo(rect.right, rect.bottom);
				if (row == 0) {
					pDC->MoveTo(rect.left-Overlap, rect.top);
					pDC->LineTo(rect.right, rect.top);
				}
			}
			if (m_nGridLines == GVL_BOTH || m_nGridLines == GVL_VERT) 
			{
				int Overlap = (row == 0)? 0:1;
				pDC->MoveTo(rect.right, rect.top-Overlap);
				pDC->LineTo(rect.right, rect.bottom);    
				if (col == 0) {
					pDC->MoveTo(rect.left, rect.top-Overlap);
					pDC->LineTo(rect.left, rect.bottom);    
				}
			}

		}
	}

	pDC->SelectObject(pOldFont);
}

void CXGridCtrlBase::PrintHeader(CDC *pDC, CPrintInfo *pInfo)
{
	CRect   rc(pInfo->m_rectDraw);
	CString strHeaderString;
	CFont   BoldFont;
	LOGFONT lf;

	//create bold font for header and footer
	VERIFY(m_PrinterFont.GetLogFont(&lf));
	lf.lfWeight = FW_BOLD;
	VERIFY(BoldFont.CreateFontIndirect(&lf));

	CFont *pNormalFont = pDC->SelectObject(&BoldFont);
	int nPrevBkMode = pDC->SetBkMode(TRANSPARENT);

	// print App title on top right margin
	strHeaderString.LoadString(AFX_IDS_APP_TITLE);
	pDC->DrawText(strHeaderString, &rc, DT_RIGHT | DT_SINGLELINE | DT_NOPREFIX | DT_VCENTER);

	// print parent window title in the centre (Gert Rijs)
	CWnd *pParentWnd = m_pGridRefWnd->GetParent();
	while (pParentWnd)
	{
		pParentWnd->GetWindowText(strHeaderString);
		if (strHeaderString.GetLength())  // can happen if it is a CView, CChildFrm has the title
			break;
		pParentWnd = pParentWnd->GetParent();
	}
	pDC->DrawText(strHeaderString, &rc, DT_CENTER | DT_SINGLELINE | DT_NOPREFIX | DT_VCENTER);


	pDC->SetBkMode(nPrevBkMode);
	pDC->SelectObject(pNormalFont);
	BoldFont.DeleteObject();

	pDC->SelectStockObject(BLACK_PEN);
	pDC->MoveTo(rc.left, rc.bottom);
	pDC->LineTo(rc.right, rc.bottom);
}

//print footer with a line and date, and page number
void CXGridCtrlBase::PrintFooter(CDC *pDC, CPrintInfo *pInfo)
{
	CRect rc(pInfo->m_rectDraw);
	CFont BoldFont;
	LOGFONT lf;

	//draw line
	pDC->MoveTo(rc.left, rc.top);
	pDC->LineTo(rc.right, rc.top);

	//create bold font for header and footer
	m_PrinterFont.GetLogFont(&lf);
	lf.lfWeight = FW_BOLD;
	BoldFont.CreateFontIndirect(&lf);

	CFont *pNormalFont = pDC->SelectObject(&BoldFont);
	int nPrevBkMode = pDC->SetBkMode(TRANSPARENT);

	// draw page number
	CString   sTemp ;
	rc.OffsetRect(0, m_CharSize.cy/2);
	sTemp.Format(_T("Page %d of %d"), pInfo->m_nCurPage, pInfo->GetMaxPage());
	pDC->DrawText(sTemp,-1,rc, DT_LEFT | DT_SINGLELINE | DT_NOPREFIX | DT_NOCLIP | DT_VCENTER);

	CTime t = CTime::GetCurrentTime();
	sTemp = t.Format(_T("%c"));
	pDC->DrawText(sTemp,-1,rc, DT_RIGHT | DT_SINGLELINE | DT_NOPREFIX | DT_NOCLIP | DT_VCENTER);

	pDC->SetBkMode(nPrevBkMode);
	pDC->SelectObject(pNormalFont);
	BoldFont.DeleteObject();
}


/////////////////////////////////////////////////////////////////////////////
// CXGridCtrlBase persistance

BOOL CXGridCtrlBase::Save(LPCTSTR filename)
{
	CStdioFile File;
	CFileException ex;
	int i = 0;

	if (!File.Open(filename, CFile::modeWrite | CFile::modeCreate| CFile::typeText, &ex)) {
		ex.ReportError();
		return FALSE;
	}

	try {

		int nNumColumns = GetColumnCount();
		for (i = 0; i < nNumColumns; i++) {
			File.WriteString(GetItemText(0,i));
			File.WriteString((i==(nNumColumns-1))? _T("\n"):_T(","));
		}

		for (i = 0; i < GetRowCount(); i++) {
			for (int j = 0; j < nNumColumns; j++) {
				File.WriteString(GetItemText(i,j));
				File.WriteString((j==(nNumColumns-1))? _T("\n"):_T(","));
			}
		}

		File.Close();
	}

	catch (CFileException* e) 
	{
		m_pGridRefWnd->MessageBox(_T("Unable to save grid list"));
		e->Delete();
		return FALSE;
	}

	return TRUE;
}

BOOL CXGridCtrlBase::Load(LPCTSTR filename)
{
	TCHAR *token, *end;
	TCHAR buffer[1024];
	CStdioFile File;
	CFileException ex;

	if (!File.Open(filename, CFile::modeRead | CFile::typeText)) {
		ex.ReportError();
		return FALSE;
	}

	DeleteAllItems();

	try {

		// Read Header off file
		File.ReadString(buffer, 1024);

		// Get first token
		for (token=buffer, end=buffer; 
			*end && (*end != _T(',')) && (*end != _T('\n')); end++);
			if ((*end == _T('\0')) && (token == end)) token = NULL;
		*end = _T('\0');

		while (token) 
		{
			InsertColumn(token);

			// Get next token
			for (token=++end; *end && (*end != _T(',')) && (*end != _T('\n'));
				end++);
				if ((*end == _T('\0')) && (token == end)) token = NULL;
			*end = _T('\0');
		}

		// Read in rest of data
		int nItem = 0;
		while (File.ReadString(buffer, 1024)) {

			// Get first token
			for (token=buffer, end=buffer; 
				*end && (*end != _T(',')) && (*end != _T('\n')); end++);
				if ((*end == _T('\0')) && (token == end)) token = NULL;
			*end = _T('\0');

			int nSubItem = 0;
			while (token) {

				if (!nSubItem)
					InsertRow(token);
				else
					SetItemText(nItem, nSubItem, token);

				// Get next token
				for (token=++end; *end && (*end != _T(',')) && (*end != _T('\n'));
					end++);
					if ((*end == _T('\0')) && (token == end)) token = NULL;
				*end = _T('\0');

				nSubItem++;
			}
			nItem++;
		}

		AutoSizeColumns();
		File.Close();
	}

	catch (CFileException* e) 
	{
		m_pGridRefWnd->MessageBox(_T("Unable to load grid data"));
		e->Delete();
		return FALSE;
	}
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CXGridCtrlBase overrideables

// This is no longer needed since I've changed to OLE drag and drop - but it's
// still cool code. :)
CImageList* CXGridCtrlBase::CreateDragImage(CPoint *pHotSpot)
{
	CDC* pDC = m_pGridRefWnd->GetDC();
	if (!pDC) return NULL;

	CRect rect;
	CCellID cell = GetFocusCell();
	if (!GetCellRect(cell.row, cell.col, rect)) return NULL;

	// Translate coordinate system
	rect.BottomRight() = CPoint(rect.Width(), rect.Height());
	rect.TopLeft()     = CPoint(0,0);
	*pHotSpot = rect.BottomRight(); 

	// Create a new imagelist (the caller of this function has responsibility
	// for deleting this list)
	CImageList* pList = new CImageList;
	if (!pList || !pList->Create(rect.Width(), rect.Height(), ILC_MASK, 1,1))
	{    
		if (pList) delete pList;
		return NULL;
	}

	// Create mem DC and bitmap
	CDC MemDC;
	CBitmap bm;
	MemDC.CreateCompatibleDC(pDC);
	bm.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	CBitmap* pOldBitmap = MemDC.SelectObject(&bm);
	MemDC.SetWindowOrg(0,0);

	// Draw cell onto bitmap in memDC
	CGridCell *pCell = GetCell(cell.row, cell.col);
	pCell->DrawCell(pDC, rect, this, TRUE);

	// Clean up
	MemDC.SelectObject(pOldBitmap);
	m_pGridRefWnd->ReleaseDC(pDC);

	// Add the bitmap we just drew to the image list.
	pList->Add(&bm, GetTextBkColor());
	bm.DeleteObject();

	return pList;
}

void CXGridCtrlBase::OnFixedRowClick(CCellID& cell)
{
	if (!IsValid(cell)) 
		return;

	if (m_bListMode)
	{
		if (!m_bSortOnClick) 
			return;

		CWaitCursor waiter;
		if (cell.col == m_SortColumn)
			m_bAscending = !m_bAscending;
		else 
		{
			m_bAscending = TRUE;
			m_SortColumn = cell.col;
		}
		SortTextItems(m_SortColumn, m_bAscending);
		m_pGridRefWnd->Invalidate();
	} 
	else if (cell.col < GetFixedColumnCount()) 
	{
		m_MouseMode = MOUSE_SELECT_ALL;
		OnSelecting(cell);
	} 
	else 
	{
		m_MouseMode = MOUSE_SELECT_COL;
		OnSelecting(cell);
	}
}

void CXGridCtrlBase::OnFixedColumnClick(CCellID& cell)
{
	if (!IsValid(cell))
		return;

	//    if (m_bListMode && (GetItemState(cell.row, m_nFixedCols) & GVNI_SELECTED))
	//    {
	//        OnEditCell(cell.row, cell.col, VK_LBUTTON);
	//        return;
	//    }

	if (cell.row < GetFixedRowCount()) 
	{
		m_MouseMode = MOUSE_SELECT_ALL;
		OnSelecting(cell);
	}
	else 
	{
		m_MouseMode = MOUSE_SELECT_ROW;
		OnSelecting(cell);
	}
}

// Gets the extent of the text pointed to by str (no CDC needed)
// By default this uses the selected font (which is a bigger font)
CSize CXGridCtrlBase::GetTextExtent(LPCTSTR str, BOOL bUseSelectedFont /* = TRUE */)
{
	CDC* pDC = m_pGridRefWnd->GetDC();
	if (!pDC) return CSize(0,0);

	CFont *pOldFont, font;

	if (bUseSelectedFont)
	{
		LOGFONT lf;
		memcpy(&lf, &m_Logfont, sizeof(LOGFONT));
		lf.lfWeight = SELECTED_CELL_FONT_WEIGHT;

		font.CreateFontIndirect(&lf);

		pOldFont = pDC->SelectObject(&font);
	}
	else
		pOldFont = pDC->SelectObject(&m_Font);

	CSize size = pDC->GetTextExtent(str);
	pDC->SelectObject(pOldFont);
	m_pGridRefWnd->ReleaseDC(pDC);

	return size + CSize(2*m_nMargin, 2*m_nMargin);
}

CSize CXGridCtrlBase::GetCellExtent(int nRow, int nCol, CDC* pDC)
{
	if (nRow < 0 || nRow >= m_nRows || nCol < 0 || nCol >= m_nCols)
	{
		return 0;
	}

	CSize size;
	CGridCell* pCell = GetCell(nRow, nCol);

	if (pCell->nDataType == GVET_COMBO_CHECKBOX)
	{
		size.cx = pCell->nFormat * 16 + 4*m_nMargin;
		size.cy = 16;
		return size;
	}

	LOGFONT *pLF = GetItemFont(nRow, nCol);

	// use selected font since it's thicker   
	LOGFONT lf;
	memcpy(&lf, pLF, sizeof(LOGFONT));

	if (nRow < m_nFixedRows || nCol < m_nFixedCols)
		lf.lfWeight = SELECTED_CELL_FONT_WEIGHT;

	CFont font;
	font.CreateFontIndirect(&lf);

	CFont* pOldFont = pDC->SelectObject(&font);
	CString *pStringRef = GetItemTextRef(nRow, nCol);

	if (pStringRef != NULL)
	{
		size = pDC->GetTextExtent(*pStringRef);
	}

	pDC->SelectObject(pOldFont);

	size += CSize(4*m_nMargin, 2*m_nMargin);

	CSize ImageSize(0,0);
	if (m_pImageList) {
		int nImage = GetItemImage(nRow, nCol);
		if (nImage >= 0) {
			IMAGEINFO Info;
			if (m_pImageList->GetImageInfo(nImage, &Info))
				ImageSize = CSize(Info.rcImage.right-Info.rcImage.left+1, 
				Info.rcImage.bottom-Info.rcImage.top+1);
		}
	}

	return CSize(size.cx + ImageSize.cx, max(size.cy, ImageSize.cy));
}

BOOL CXGridCtrlBase::IsReadOnly(CGridCell *pCell)
{
	if (m_bIsReadOnly)
	{
		return m_bIsReadOnly;
	}

	return pCell->IsReadOnly();
}

void CXGridCtrlBase::OnEditCell(int nRow, int nCol, UINT nChar)
{
	//TRACE("\nOnEditCell(%d, %d)", nRow, nCol);
	EnsureVisible(nRow, nCol);

	CCellID cell(nRow, nCol);
	if (!IsValid(cell) || !IsCellEditable(nRow, nCol) || !IsCellVisible(CCellID(nRow, nCol))) 
		return;

	CRect rect;
	if (!GetCellRect(cell, rect)) return;
	// if it is column with GVET_NOEDIT style, Do not edit

	if (m_pViewWindowPos != NULL)
	{
		m_pViewWindowPos->ViewToWindow(rect);
	}

	CGridCell *pCell = GetCell(nRow, nCol);
	int nType = pCell->nDataType & 0xFFFF0000;
	if (  nType == GVET_NOEDIT ) return;

	SendMessageToParent(nRow, nCol, GVN_BEGINLABELEDIT);

	GV_ITEM Item;
	Item.mask = GVIF_TEXT | GVIF_FORMAT;
	Item.row = nRow;
	Item.col = nCol;
	if (!GetItem(&Item)) return;

	pCell = GetCell(nRow, nCol);
	if (IsReadOnly(pCell))
	{
		return;
	}

	DWORD dwStyle = ES_LEFT;
	if (Item.nFormat & DT_RIGHT) 
	{
		dwStyle = ES_RIGHT;
	}
	else if (Item.nFormat & DT_CENTER) 
	{
		dwStyle = ES_CENTER;
	}
	else
	{
	}

	CWnd *pWnd = NULL;

	// InPlaceEdit auto-deletes itself
	switch (nType)
	{
	case GVET_EDITBOX:
		{
			GRIDEDIT_FORMAT nFormat = GetEditFormat(nRow, nCol);
			m_pInplaceEditWnd = new CGridEdit(m_pGridRefWnd, rect, dwStyle, IDC_INPLACE_EDIT, nRow, nCol, Item.szText, nChar, nFormat, this);
			m_bInplaceEdit_VKReturn = TRUE;
		}
		return;
	case GVET_HEXEDIT:
		{
			int nMaxLen = GetItemMaxLen(nRow, nCol);
			CGridHexEdit *pCGridHexEdit = new CGridHexEdit(m_pGridRefWnd, rect, dwStyle, IDC_INPLACE_EDIT
				, nRow, nCol, Item.szText, nChar, nMaxLen, this);
			m_pInplaceEditWnd = pCGridHexEdit;
			m_bInplaceEdit_VKReturn = TRUE;
		}
		return;
	case GVET_BINARYEDIT:
		{
			int nMaxLen = GetItemMaxLen(nRow, nCol);
			CGridBinaryEdit *pCGridHexEdit = new CGridBinaryEdit(m_pGridRefWnd, rect, dwStyle, IDC_INPLACE_EDIT
				, nRow, nCol, Item.szText, nChar, nMaxLen, this);
			m_pInplaceEditWnd = pCGridHexEdit;
			m_bInplaceEdit_VKReturn = TRUE;
		}
		return;
	case GVET_MACEDIT:
		{
			CGridMacEdit *pCGridMacEdit = new CGridMacEdit(m_pGridRefWnd, rect, dwStyle, IDC_INPLACE_EDIT
				, nRow, nCol, Item.szText, nChar, this);
			m_pInplaceEditWnd = pCGridMacEdit;
			m_bInplaceEdit_VKReturn = TRUE;
		}
		return;
		//		case GVET_LISTBOX:
		//			//new CInPlaceList(this, rect, dwStyle, nRow, nCol, Item.szText, nChar);
		//			return;
		////		case GVET_TREECTRL:
		////			new CInPalaceTreeCtrl(this, rect, dwStyle, nRow, nCol, Item.szText, nChar);
		////			return;
		////		case GVET_DATECTRL:
		////			new CInPlaceTimeCtrl(this, rect, dwStyle, nRow, nCol, Item.szText, nChar);
		////			return;
	case GVET_COMBOBOX:
		//new CInPlaceComboBox(this, rect, dwStyle, IDC_INPLACE_COMBOBOX, nRow, nCol, Item.szText, nChar);
		m_pInplaceEditWnd = new CGridComboBox(m_pGridRefWnd, rect,
			CBS_DROPDOWN,          // Uncomment for dropdown style
			IDC_INPLACE_COMBOBOX,                   // ID of control being created
			nRow, nCol, 
			Item.szText
			, nChar, *(GetItemFont(nRow, nCol)), this);

		return;
	case GVET_COMBOBOXDROPLIST:
		//new CInPlaceComboBox(this, rect, dwStyle, IDC_INPLACE_COMBOBOX, nRow, nCol, Item.szText, nChar);
		m_pInplaceEditWnd = new CGridComboBox(m_pGridRefWnd, rect,
			CBS_DROPDOWN,          // Uncomment for dropdown style
			IDC_INPLACE_COMBOBOX,                   // ID of control being created
			nRow, nCol, 
			Item.szText
			, nChar, *(GetItemFont(nRow, nCol)), this);

		return;
	case GVET_CHECKBOX:
		{
			if ((nChar == CHECHBOX_EDIT_KEYVALUE) || (nChar == VK_LBUTTON)) //只有按下指定键（当前为空格键）才会编辑响应 Add 2010.4.2
			{
				CGridCell *pCell = GetCell(nRow, nCol);

				if(pCell->dwValue ==0 )
				{
					pCell->dwValue = 1;
				}
				else
				{
					pCell->dwValue = 0;
				}

				TRACE(_T(" %d\n"),pCell->dwValue);
				OnEndEditCell(nRow, nCol, pCell->dwValue);
				RedrawCell(nRow,nCol);
			}
		}
		return;
		//		case GVET_POINTEDIT:
		//			if(Item.szText.GetLength()<=2)return;
		//			new CPointEdit(this, rect, dwStyle, IDC_IPPOINTEDIT, nRow, nCol, Item.szText, nChar);
		//			return;
	case GVET_COMBO_CHECKBOX:
		{
			if ((nChar == CHECHBOX_EDIT_KEYVALUE) || (nChar == VK_LBUTTON)) //只有按下指定键（当前为空格键）才会编辑响应 Add 2010.10.20
			{
				CGridCell *pCell = GetCell(nRow, nCol);

				int nCount = pCell->nFormat;
				CRect rect;
				CPoint ptCenter, ptHit;
				int nIndex = 0;
				int nFlag = 0x1;

				GetCellRect(nRow, nCol, &rect);
				rect.left += m_nMargin;
				::GetCursorPos(&ptHit);
				m_pGridRefWnd->ScreenToClient(&ptHit);
				nIndex = (ptHit.x - rect.left) / 16;

				if (nIndex >= 0 && nIndex < nCount)
				{
					rect.left += nIndex * 16;
					rect.right = rect.left + 14;
					ptCenter = rect.CenterPoint();
					nFlag = nFlag << nIndex;
					if (ptCenter.x - 7 < ptHit.x && ptHit.x < ptCenter.x + 7
						&& ptCenter.y - 6 < ptHit.y && ptHit.y < ptCenter.y + 6)
					{
						pCell->dwValue = pCell->dwValue ^ nFlag;
						OnEndEditCell(nRow, nCol, pCell->dwValue);
						RedrawCell(nRow,nCol);
					}			
				}						
			}
		}
		break;

		// 		case GVET_HEXEDIT:
		// 			{
		// 				GRIDEDIT_FORMAT nFormat = GetEditFormat(nRow, nCol);
		// 				m_pInplaceEditWnd = new CGridEdit(this, rect, dwStyle, IDC_INPLACE_EDIT, nRow, nCol, Item.szText, nChar, nFormat);
		// 				m_bInplaceEdit_VKReturn = TRUE;
		// 			}
		// 			return;

	}
}
//
//void CXGridCtrlBase::CreateInPlaceEditControl(CRect& rect, DWORD dwStyle, UINT nID,
//                                         int nRow, int nCol,
//                                         LPCTSTR szText, int nChar)
//{
//    // InPlaceEdit auto-deletes itself
//    new CInPlaceEdit(this, rect, dwStyle, nID, nRow, nCol, szText, nChar);
//}

BOOL CXGridCtrlBase::EndEditCell(int nRow, int nCol, DWORD dwItemData)
{
	CGridCell* pCell = GetCell(nRow, nCol);

	if (pCell == NULL)
	{
		return FALSE;
	}

	if (pCell->pEditFunc == NULL)
	{
		return FALSE;
	}

	pCell->pEditFunc(nRow, nCol, pCell, this);

	return TRUE;
}

void CXGridCtrlBase::OnEndEditCell(int nRow, int nCol, CString str, DWORD dwValue, DWORD dwItemData)
{
	CGridCell* pCell = GetCell(nRow, nCol);
	if (pCell != NULL)
	{
		pCell->szText = str;
		pCell->dwValue = dwValue;
	}

	if (!EndEditCell(nRow, nCol, dwItemData))
	{
		long lValue=0;
		lValue+=nCol;
		lValue+=nRow<<16;
		CWnd* pWnd =  m_pGridRefWnd->GetParent();
		if (pWnd != NULL)
		{
			if (::IsWindow(pWnd->GetSafeHwnd())) 
			{
				pWnd->SendMessage(WM_GRID_END_EDIT,0,(LPARAM)lValue);
			}		
		}
	}
	else
	{
	}	
}

void CXGridCtrlBase::OnEndEditCell(int nRow, int nCol, DWORD dwValue, DWORD dwItemData)
{
	CGridCell* pCell = GetCell(nRow, nCol);

	if (pCell != NULL)
	{
		pCell->dwValue = dwValue;
	}

	if (!EndEditCell(nRow, nCol, dwItemData))
	{
		long lValue=0;
		lValue+=nCol;
		lValue+=nRow<<16;
		CWnd* pWnd =  m_pGridRefWnd->GetParent();
		if (pWnd != NULL)
		{
			if (::IsWindow(pWnd->GetSafeHwnd())) 
			{
				pWnd->SendMessage(WM_GRID_END_EDIT,0,(LPARAM)lValue);
			}
		}
	}
	else
	{
	}	
}


CString CXGridCtrlBase::GetItemText(int nRow, int nCol)
{
	if (nRow < 0 || nRow >= m_nRows || nCol < 0 || nCol >= m_nCols) return CString(_T(""));

	CGridCell* pCell = GetCell(nRow, nCol);
	ASSERT(pCell);
	if (!pCell) return CString(_T(""));

	return pCell->szText;
}

CString* CXGridCtrlBase::GetItemTextRef(int nRow, int nCol)
{
	if (nRow < 0 || nRow >= m_nRows || nCol < 0 || nCol >= m_nCols)
	{
		return NULL;
	}

	CGridCell* pCell = GetCell(nRow, nCol);
	ASSERT(pCell);
	if (!pCell) return NULL;

	if (pCell->m_pStrCmpBlocks != NULL)
	{
		return pCell->m_pStrCmpBlocks->m_pStringRef;
	}
	else
	{
		return &pCell->szText;
	}
}

BOOL CXGridCtrlBase::OnCellRButtonUp(const CCellID &idCell)
{
	return FALSE;
}

BOOL CXGridCtrlBase::OnCellRButtonUpEx(UINT nFlags, CPoint point)
{
	return FALSE;
}

void CXGridCtrlBase::OnEndInPlaceEdit(NMHDR* pNMHDR, LRESULT* pResult) 
{    
	GV_DISPINFO *pgvDispInfo = (GV_DISPINFO *)pNMHDR;
	GV_ITEM     *pgvItem = &pgvDispInfo->item;


	// In case OnEndInPlaceEdit called as window is being destroyed
	if (!IsWindow(m_pGridRefWnd->GetSafeHwnd()))
		return;

	// Only set as modified if (a) it actually was, and (b) ESC was not hit.
	if (pgvItem->lParam != VK_ESCAPE &&
		GetItemText(pgvItem->row, pgvItem->col) != pgvItem->szText)
	{
		SetModified(TRUE);
	}

	CGridCell *pCell = GetCell(pgvItem->row, pgvItem->col);

	if  (pCell == NULL)
	{
		return;
	}

	OnEndEditCell(pgvItem->row, pgvItem->col, pgvItem->szText, pCell->dwValue);
	InvalidateCellRect(CCellID(pgvItem->row, pgvItem->col));

	SendMessageToParent(pgvItem->row, pgvItem->col, GVN_ENDLABELEDIT);
	SetFocusCell(pgvItem->row, pgvItem->col);
	m_idCurrentCell.row = pgvItem->row;
	m_idCurrentCell.col = pgvItem->col;

	switch (pgvItem->lParam) 
	{
	case VK_DOWN: 
	case VK_UP:   
	case VK_RIGHT:
	case VK_LEFT:  
	case VK_NEXT:  
	case VK_PRIOR: 
	case VK_HOME:  
	case VK_END:    OnKeyDown(pgvItem->lParam, 0, 0);
		OnEditCell(m_idCurrentCell.row, m_idCurrentCell.col, pgvItem->lParam);
	}

	*pResult = 0;
	m_pInplaceEditWnd = NULL;
	m_dwInplaceEditEndTick = ::GetTickCount();
}
void CXGridCtrlBase::OnEndPointEdit(NMHDR* pNMHDR, LRESULT* pResult) 
{    
	GV_DISPINFO *pgvDispInfo = (GV_DISPINFO *)pNMHDR;
	GV_ITEM     *pgvItem = &pgvDispInfo->item;

	// In case OnEndInPlaceEdit called as window is being destroyed
	if (!IsWindow(m_pGridRefWnd->GetSafeHwnd()))
		return;

	// Only set as modified if (a) it actually was, and (b) ESC was not hit.
	if (pgvItem->lParam != VK_ESCAPE &&
		GetItemText(pgvItem->row, pgvItem->col) != pgvItem->szText)
	{
		SetModified(TRUE);
	}

	OnEndEditCell(pgvItem->row, pgvItem->col, pgvItem->szText);
	InvalidateCellRect(CCellID(pgvItem->row, pgvItem->col));

	SendMessageToParent(pgvItem->row, pgvItem->col, GVN_ENDLABELEDIT);
	SetFocusCell(pgvItem->row, pgvItem->col);
	m_idCurrentCell.row = pgvItem->row;
	m_idCurrentCell.col = pgvItem->col;

	switch (pgvItem->lParam) 
	{
	case VK_DOWN: 
	case VK_UP:   
	case VK_RIGHT:
	case VK_LEFT:  
	case VK_NEXT:  
	case VK_PRIOR: 
	case VK_HOME:  
	case VK_END:    OnKeyDown(pgvItem->lParam, 0, 0);
		OnEditCell(m_idCurrentCell.row, m_idCurrentCell.col, pgvItem->lParam);
	}

	*pResult = 0;
}
void CXGridCtrlBase::OnEndInplaceComboBoxEdit(NMHDR* pNMHDR, LRESULT* pResult) 
{    
	GV_DISPINFO *pgvDispInfo = (GV_DISPINFO *)pNMHDR;
	GV_ITEM     *pgvItem = &pgvDispInfo->item;

	// In case OnEndInPlaceEdit called as window is being destroyed
	if (!IsWindow(m_pGridRefWnd->GetSafeHwnd()))
		return;

	// Only set as modified if (a) it actually was, and (b) ESC was not hit.
	if (pgvItem->lParam != VK_ESCAPE &&
		GetItemText(pgvItem->row, pgvItem->col) != pgvItem->szText)
	{
		SetModified(TRUE);
	}

	OnEndEditCell(pgvItem->row, pgvItem->col, pgvItem->szText, pgvItem->dwValue);
	InvalidateCellRect(CCellID(pgvItem->row, pgvItem->col));

	SendMessageToParent(pgvItem->row, pgvItem->col, GVN_ENDLABELEDIT);
	SetFocusCell(pgvItem->row, pgvItem->col);
	m_idCurrentCell.row = pgvItem->row;
	m_idCurrentCell.col = pgvItem->col;

	switch (pgvItem->lParam) 
	{
	case VK_DOWN: 
	case VK_UP:   
	case VK_RIGHT:
	case VK_LEFT:  
	case VK_NEXT:  
	case VK_PRIOR: 
	case VK_HOME:  
	case VK_END:    OnKeyDown(pgvItem->lParam, 0, 0);
		OnEditCell(m_idCurrentCell.row, m_idCurrentCell.col, pgvItem->lParam);
	}

	*pResult = 0;
}

LRESULT CXGridCtrlBase::OnFillComboBox(WPARAM wParam, LPARAM lParam)
{
	int nRow = wParam >> 16;
	int nCol = wParam & 0x00FFFF;
	FillComboBoxItems(nRow, nCol, lParam);
	return 0;
}

LRESULT CXGridCtrlBase::OnFillList(WPARAM nColumn, LPARAM pListBox)
{
	FillListItems(nColumn, pListBox);
	return 0;
}

LRESULT CXGridCtrlBase::OnFillTree(WPARAM nColumn, LPARAM pListBox)
{
	FillTreeItems(nColumn, pListBox);
	return 0;
}
LRESULT CXGridCtrlBase::OnFillTimeCtrl(WPARAM nColumn, LPARAM pListBox)
{
	FillTimeCtrlItems(nColumn, pListBox);
	return 0;
}


BOOL CXGridCtrlBase::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->wParam == VK_RETURN)
	{
		if (!m_bInplaceEdit_VKReturn && WM_KEYUP == pMsg->message)
		{
			if (IsValid(m_idCurrentCell))
			{
				if (::GetTickCount() - m_dwInplaceEditEndTick > 400)
				{
					OnEditCell(m_idCurrentCell.row, m_idCurrentCell.col, VK_SPACE);
				}
			}
		}
		else
		{
			m_bInplaceEdit_VKReturn = FALSE;
		}
	}

	return 0;
}


void CXGridCtrlBase::OnRButtonDown(UINT nFlags, CPoint point)
{
	if (m_bUseRButtonDownForSel)
	{
		OnLButtonDown(nFlags, point);
	}

	//CWnd::OnRButtonDown(nFlags, point);
}

//////////////////////////////////////////////////////////////////////////

// Handle horz scrollbar notifications
void CXGridCtrlBase::OnHScroll(UINT nSBCode, UINT /*nPos*/, CScrollBar* /*pScrollBar*/)
{
	if (m_pGridRefWnd->GetFocus()->GetSafeHwnd() != m_pGridRefWnd->GetSafeHwnd()) 
		m_pGridRefWnd->SetFocus();  // Auto-destroy any InPlaceEdit's

	int scrollPos = GetScrollPos32(SB_HORZ);

	CCellID idTopLeft = GetTopleftNonFixedCell();

	CRect rect;
	GetGridClientRect(rect);

	switch (nSBCode)
	{
	case SB_LINERIGHT:
		if (scrollPos < m_nHScrollMax)
		{
			int xScroll = GetColumnWidth(idTopLeft.col);
			SetScrollPos32(SB_HORZ, scrollPos + xScroll);
			if (GetScrollPos32(SB_HORZ) == scrollPos) break;          // didn't work

			rect.left = GetFixedColumnWidth() + xScroll;
			m_pGridRefWnd->ScrollWindow(-xScroll, 0, rect);
			rect.left = rect.right - xScroll;
			m_pGridRefWnd->InvalidateRect(rect);
		}
		break;

	case SB_LINELEFT:
		if (scrollPos > 0 && idTopLeft.col > GetFixedColumnCount())
		{
			int xScroll = GetColumnWidth(idTopLeft.col-1);
			SetScrollPos32(SB_HORZ, max(0,scrollPos - xScroll));
			rect.left = GetFixedColumnWidth();
			m_pGridRefWnd->ScrollWindow(xScroll, 0, rect);
			rect.right = rect.left + xScroll;
			m_pGridRefWnd->InvalidateRect(rect);
		}
		break;

	case SB_PAGERIGHT:
		if (scrollPos < m_nHScrollMax)
		{
			rect.left = GetFixedColumnWidth();
			int offset = rect.Width();
			int pos = min(m_nHScrollMax, scrollPos + offset);
			SetScrollPos32(SB_HORZ, pos);
			rect.left = GetFixedColumnWidth();
			m_pGridRefWnd->InvalidateRect(rect);
		}
		break;

	case SB_PAGELEFT:
		if (scrollPos > 0)
		{
			rect.left = GetFixedColumnWidth();
			int offset = -rect.Width();
			int pos = max(0, scrollPos + offset);
			SetScrollPos32(SB_HORZ, pos);
			rect.left = GetFixedColumnWidth();
			m_pGridRefWnd->InvalidateRect(rect);
		}
		break;

	case SB_THUMBPOSITION:
	case SB_THUMBTRACK:
		{
			SetScrollPos32(SB_HORZ, GetScrollPos32(SB_HORZ, TRUE));
			rect.left = GetFixedColumnWidth();
			m_pGridRefWnd->InvalidateRect(rect);
			//TRACE("\nHor(%d, %d, %d, %d)", rect.left, rect.top, rect.right, rect.bottom);
		}
		break;

	case SB_LEFT:
		if (scrollPos > 0)
		{
			SetScrollPos32(SB_HORZ, 0);
			m_pGridRefWnd->Invalidate();
		}
		break;

	case SB_RIGHT:
		if (scrollPos < m_nHScrollMax)
		{
			SetScrollPos32(SB_HORZ, m_nHScrollMax);
			m_pGridRefWnd->Invalidate();
		}
		break;


	default: break;
	}
}

// Handle vert scrollbar notifications
void CXGridCtrlBase::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (m_pGridRefWnd->GetFocus()->GetSafeHwnd() != m_pGridRefWnd->GetSafeHwnd()) 
		m_pGridRefWnd->SetFocus();        // Auto-destroy any InPlaceEdit's

	// Get the scroll position ourselves to ensure we get a 32 bit value
	int scrollPos = GetScrollPos32(SB_VERT);

	CCellID idTopLeft = GetTopleftNonFixedCell();

	CRect rect;
	GetGridClientRect(rect);

	switch (nSBCode)
	{
	case SB_LINEDOWN:
		if (scrollPos < m_nVScrollMax)
		{
			int yScroll = GetRowHeight(idTopLeft.row);
			SetScrollPos32(SB_VERT, scrollPos + yScroll);
			if (GetScrollPos32(SB_VERT) == scrollPos) break;          // didn't work

			rect.top = GetFixedRowHeight() + yScroll;
			m_pGridRefWnd->ScrollWindow( 0, -yScroll, rect);
			rect.top = rect.bottom - yScroll;
			m_pGridRefWnd->InvalidateRect(rect);
		}
		break;

	case SB_LINEUP:
		if (scrollPos > 0 && idTopLeft.row > GetFixedRowCount())
		{
			int yScroll = GetRowHeight(idTopLeft.row-1);
			SetScrollPos32(SB_VERT, max(0, scrollPos - yScroll));
			rect.top = GetFixedRowHeight();
			m_pGridRefWnd->ScrollWindow(0, yScroll, rect);
			rect.bottom = rect.top + yScroll;
			m_pGridRefWnd->InvalidateRect(rect);
		}
		break;

	case SB_PAGEDOWN:
		if (scrollPos < m_nVScrollMax)
		{
			rect.top = GetFixedRowHeight();
			scrollPos = min(m_nVScrollMax, scrollPos + rect.Height());
			SetScrollPos32(SB_VERT, scrollPos);
			rect.top = GetFixedRowHeight();
			m_pGridRefWnd->InvalidateRect(rect);
		}
		break;

	case SB_PAGEUP:
		if (scrollPos > 0)
		{
			rect.top = GetFixedRowHeight();
			int offset = -rect.Height();
			int pos = max(0, scrollPos + offset);
			SetScrollPos32(SB_VERT, pos);
			rect.top = GetFixedRowHeight();
			m_pGridRefWnd->InvalidateRect(rect);
		}
		break;

	case SB_THUMBPOSITION:
	case SB_THUMBTRACK:
		{
			SetScrollPos32(SB_VERT, GetScrollPos32(SB_VERT, TRUE));
			rect.top = GetFixedRowHeight();
			m_pGridRefWnd->InvalidateRect(rect);
			//TRACE("\nRect(%d, %d, %d, %d)", rect.left, rect.top, rect.right, rect.bottom);
		}
		break;

	case SB_TOP:
		if (scrollPos > 0)
		{
			SetScrollPos32(SB_VERT, 0);
			m_pGridRefWnd->Invalidate();
		}
		break;

	case SB_BOTTOM:
		if (scrollPos < m_nVScrollMax)
		{
			SetScrollPos32(SB_VERT, m_nVScrollMax);
			m_pGridRefWnd->Invalidate();
		}

	default: break;
	}

	AfterOnVScroll(nSBCode, nPos, pScrollBar);
}

UINT CXGridCtrlBase::OnGetDlgCode() 
{
	UINT nCode = DLGC_WANTARROWS | DLGC_WANTCHARS;

	if (m_bHandleTabKey && !IsCTRLpressed()) 
		nCode |= DLGC_WANTTAB;

	return nCode;
}


void CXGridCtrlBase::OnLButtonUp(UINT nFlags, CPoint point)
{
	ClipCursor(NULL);

	if (m_pGridRefWnd->GetCapture()->GetSafeHwnd() == m_pGridRefWnd->GetSafeHwnd())
	{
		ReleaseCapture();
		m_pGridRefWnd->KillTimer(m_nTimerID);
		m_nTimerID = 0;
	}

	// m_MouseMode == MOUSE_PREPARE_EDIT only if user clicked down on current cell
	// and then didn't move mouse before clicking up (releasing button)
	if (m_MouseMode == MOUSE_PREPARE_EDIT)    
	{
		OnEditCell(m_idCurrentCell.row, m_idCurrentCell.col, VK_LBUTTON);
	}
	// m_MouseMode == MOUSE_PREPARE_DRAG only if user clicked down on a selected cell
	// and then didn't move mouse before clicking up (releasing button)
	else if (m_MouseMode == MOUSE_PREPARE_DRAG) 
	{
		ResetSelectedRange();
	}
	else if (m_MouseMode == MOUSE_SIZING_COL)
	{
		CRect rect;
		GetGridClientRect(rect);
		CRect invertedRect(m_LastMousePoint.x, rect.top, m_LastMousePoint.x + 2, rect.bottom);

		CDC* pDC = m_pGridRefWnd->GetDC();

		if (pDC) 
		{
			pDC->InvertRect(&invertedRect);
			m_pGridRefWnd->ReleaseDC(pDC);
		}

		if (m_LeftClickDownPoint != point) 
		{   
			CPoint start;
			if (!GetCellOrigin(m_LeftClickDownCell, &start)) return;
			SetColumnWidth(m_LeftClickDownCell.col, point.x - start.x);
			CWnd* pOwner = m_pGridRefWnd->GetOwner();

			if(pOwner != NULL)
			{
				if (::IsWindow(pOwner->GetSafeHwnd())) 
				{
					pOwner->SendMessage(WM_USER+1002,(WPARAM)m_LeftClickDownCell.col,(LPARAM)(point.x - start.x));
				}

			}	

			ResetScrollBars();
			m_pGridRefWnd->Invalidate();
		}
	}
	else if (m_MouseMode == MOUSE_SIZING_ROW)
	{
		CRect rect;
		GetGridClientRect(rect);
		CRect invertedRect(rect.left, m_LastMousePoint.y, rect.right, m_LastMousePoint.y + 2);

		CDC* pDC = m_pGridRefWnd->GetDC();
		if (pDC) 
		{
			pDC->InvertRect(&invertedRect);
			m_pGridRefWnd->ReleaseDC(pDC);
		}

		if (m_LeftClickDownPoint != point) 
		{
			CPoint start;
			if (!GetCellOrigin(m_LeftClickDownCell, &start)) return;

			SetRowHeight(m_LeftClickDownCell.row, point.y - start.y);
			ResetScrollBars();
			m_pGridRefWnd->Invalidate();
		}
	} 
	else
	{
		CCellID oCellID;
		oCellID = GetCellFromPt(point);

		if (m_LeftClickDownCell == oCellID)
		{
			OnEditCell(oCellID.row, oCellID.col, VK_LBUTTON);
		}
		//m_MouseMode = MOUSE_PREPARE_EDIT;		
	}

	m_MouseMode = MOUSE_NOTHING;
	SetCursor(::LoadCursor(NULL, IDC_ARROW));

	if (!IsValid(m_LeftClickDownCell)) return;

	CWnd *pOwner = m_pGridRefWnd->GetOwner();
	if (pOwner)
	{
		if (IsWindow(pOwner->m_hWnd))
		{
			pOwner->PostMessage(WM_COMMAND, MAKELONG(m_pGridRefWnd->GetDlgCtrlID(), BN_CLICKED), 
				(LPARAM) m_pGridRefWnd->GetSafeHwnd());
		}
	}

	{
		CCellID oCellID;
		oCellID = GetCellFromPt(point);
		//WPARAM wParam = (oCellID.row << 16) + oCellID.col;
		m_pGridRefWnd->GetParent()->PostMessage(WM_USER + 1003, (oCellID.row << 16) + oCellID.col, (LPARAM)m_pGridRefWnd->GetDlgCtrlID());
	}
}

void CXGridCtrlBase::OnLButtonDown(UINT nFlags, CPoint point)
{
// 	if (m_pViewWindowPos != NULL)
// 	{
// 		m_pViewWindowPos->WindowToView(point);
// 	}

	HWND hOldFocusWnd = ::GetFocus();

	m_LeftClickDownPoint = point;
	m_LeftClickDownCell = GetCellFromPt(point);
	if (!IsValid(m_LeftClickDownCell)) return;

	m_SelectionStartCell = (nFlags & MK_SHIFT)? m_idCurrentCell : m_LeftClickDownCell;

	m_pGridRefWnd->SetFocus();        // Auto-destroy any InPlaceEdit's

	// If the user clicks on the current cell, then prepare to edit it.
	// (If the user moves the mouse, then dragging occurs)
	if (m_LeftClickDownCell == m_idCurrentCell)
	{
		//m_MouseMode = MOUSE_PREPARE_EDIT;
		return;
	} 
	else 
	{
		SetFocusCell(-1,-1);
		SetFocusCell(max(m_LeftClickDownCell.row, m_nFixedRows),
			max(m_LeftClickDownCell.col, m_nFixedCols));
	}

	// If the user clicks on a selected cell, then prepare to drag it.
	// (If the user moves the mouse, then dragging occurs)
	if (m_bAllowDragAndDrop && hOldFocusWnd == m_pGridRefWnd->GetSafeHwnd() && 
		GetItemState(m_LeftClickDownCell.row, m_LeftClickDownCell.col) & GVNI_SELECTED)
	{
		m_MouseMode = MOUSE_PREPARE_DRAG;
		return;
	}

	m_pGridRefWnd->SetCapture();

	if (m_MouseMode == MOUSE_OVER_COL_DIVIDE) // sizing column
	{
		m_MouseMode = MOUSE_SIZING_COL;
		CPoint start;
		if (!GetCellOrigin(0, m_LeftClickDownCell.col, &start)) return;

		CRect rect;
		GetGridClientRect(rect);
		CRect invertedRect(point.x, rect.top, point.x + 2, rect.bottom);

		CDC* pDC = m_pGridRefWnd->GetDC();
		if (pDC) 
		{
			pDC->InvertRect(&invertedRect);
			m_pGridRefWnd->ReleaseDC(pDC);
		}

		if (point.x - start.x <= m_nResizeCaptureRange)        // clicked right of border
			if (!GetCellOrigin(0, --m_LeftClickDownCell.col, &start)) return;

		rect.left = start.x;
		m_pGridRefWnd->ClientToScreen(rect);
		ClipCursor(rect);
	}
	else if (m_MouseMode == MOUSE_OVER_ROW_DIVIDE) // sizing row
	{
		m_MouseMode = MOUSE_SIZING_ROW;
		CPoint start;
		if (!GetCellOrigin(m_LeftClickDownCell, &start)) return;

		CRect rect;
		GetGridClientRect(rect);
		CRect invertedRect(rect.left, point.y, rect.right, point.y + 2);

		CDC* pDC = m_pGridRefWnd->GetDC();

		if (pDC) 
		{
			pDC->InvertRect(&invertedRect);
			m_pGridRefWnd->ReleaseDC(pDC);
		}

		if (point.y - start.y <= m_nResizeCaptureRange)            // clicked below border
			if (!GetCellOrigin(--m_LeftClickDownCell.row, 0, &start)) return;

		rect.top = start.y;
		m_pGridRefWnd->ClientToScreen(rect);
		ClipCursor(rect);
	}
	else // not sizing or editing -- selecting
	{    
		// If Ctrl pressed, save the current cell selection. This will get added
		// to the new cell selection at the end of the cell selection process
		m_PrevSelectedCellMap.RemoveAll();
		if (nFlags & MK_CONTROL) 
		{
			for (POSITION pos = m_SelectedCellMap.GetStartPosition(); pos != NULL; )
			{
				DWORD key;
				CCellID cell;
				m_SelectedCellMap.GetNextAssoc(pos, key, (CCellID&)cell);
				m_PrevSelectedCellMap.SetAt(key, cell);
			}
		}

		if (m_LeftClickDownCell.row < GetFixedRowCount())
			OnFixedRowClick(m_LeftClickDownCell);
		else if (m_LeftClickDownCell.col < GetFixedColumnCount())
			OnFixedColumnClick(m_LeftClickDownCell);
		else
		{
			m_MouseMode = m_bListMode? MOUSE_SELECT_ROW : MOUSE_SELECT_CELLS;
			OnSelecting(m_LeftClickDownCell);
		}

		m_nTimerID = m_pGridRefWnd->SetTimer(WM_LBUTTONDOWN, m_nTimerInterval, 0);
	}   
	m_LastMousePoint = point;
}

void CXGridCtrlBase::OnMouseMove(UINT nFlags, CPoint point)
{
	CRect rect;
	GetGridClientRect(rect);

	// If outside client area, return (unless we are drag n dropping)
	if (m_MouseMode != MOUSE_DRAGGING && !rect.PtInRect(point))
		return;

	// If the left mouse button is up, then test to see if row/column sizing is imminent
	if (!(nFlags & MK_LBUTTON))
	{
		if (point.y < GetFixedRowHeight() && m_bAllowColumnResize)
		{
			CCellID idCurrentCell = GetCellFromPt(point);
			CPoint start;
			if (!GetCellOrigin(idCurrentCell, &start)) return;

			int endx = start.x + GetColumnWidth(idCurrentCell.col);

			if ((point.x - start.x <= m_nResizeCaptureRange && idCurrentCell.col != 0) || 
				endx - point.x <= m_nResizeCaptureRange)
			{
				if (m_MouseMode != MOUSE_OVER_COL_DIVIDE)
					SetCursor(::LoadCursor(NULL, IDC_SIZEWE));
				m_MouseMode = MOUSE_OVER_COL_DIVIDE;
			}
			else 
			{
				if (m_MouseMode != MOUSE_NOTHING)
					SetCursor(::LoadCursor(NULL, IDC_ARROW));
				m_MouseMode = MOUSE_NOTHING;
			}
		}
		else if (point.x < GetFixedColumnWidth() && m_bAllowRowResize)
		{
			CCellID idCurrentCell = GetCellFromPt(point);
			CPoint start;
			if (!GetCellOrigin(idCurrentCell, &start)) return;

			int endy = start.y + GetRowHeight(idCurrentCell.row);

			if ((point.y - start.y <= m_nResizeCaptureRange && idCurrentCell.row != 0) || 
				endy - point.y <= m_nResizeCaptureRange)
			{
				if (m_MouseMode != MOUSE_OVER_ROW_DIVIDE)
					SetCursor(::LoadCursor(NULL, IDC_SIZENS));
				m_MouseMode = MOUSE_OVER_ROW_DIVIDE;
			}
			else
			{
				if (m_MouseMode != MOUSE_NOTHING)
					SetCursor(::LoadCursor(NULL, IDC_ARROW));
				m_MouseMode = MOUSE_NOTHING;
			}
		}
		else
		{
			if (m_MouseMode != MOUSE_NOTHING)
				SetCursor(::LoadCursor(NULL, IDC_ARROW));
			m_MouseMode = MOUSE_NOTHING;
		}

		m_LastMousePoint = point;
		return;
	}

	if (!IsValid(m_LeftClickDownCell))
	{
		m_LastMousePoint = point;
		return;
	}

	// If the left mouse button is down, the process appropriately
	if (nFlags & MK_LBUTTON) 
	{
		switch(m_MouseMode)
		{
		case MOUSE_SELECT_ALL:        break;

		case MOUSE_SELECT_COL:
		case MOUSE_SELECT_ROW:    
		case MOUSE_SELECT_CELLS:  
			{
				CCellID idCurrentCell = GetCellFromPt(point);
				if (!IsValid(idCurrentCell)) return;
				OnSelecting(idCurrentCell);
				//SetFocusCell(max(idCurrentCell.row, m_nFixedRows),
				//             max(idCurrentCell.col, m_nFixedCols));
				if (idCurrentCell.row >= m_nFixedRows &&
					idCurrentCell.col >= m_nFixedCols)
					SetFocusCell(idCurrentCell);
				break;
			}

		case MOUSE_SIZING_COL:       
			{
				CDC* pDC = m_pGridRefWnd->GetDC();
				if (!pDC) break;

				CRect oldInvertedRect(m_LastMousePoint.x, rect.top, 
					m_LastMousePoint.x + 2, rect.bottom);
				pDC->InvertRect(&oldInvertedRect);
				CRect newInvertedRect(point.x, rect.top, 
					point.x + 2, rect.bottom);
				pDC->InvertRect(&newInvertedRect);
				m_pGridRefWnd->ReleaseDC(pDC);
			}
			break;

		case MOUSE_SIZING_ROW:       
			{
				CDC* pDC = m_pGridRefWnd->GetDC();
				if (!pDC) break;

				CRect oldInvertedRect(rect.left, m_LastMousePoint.y, 
					rect.right, m_LastMousePoint.y + 2);
				pDC->InvertRect(&oldInvertedRect);
				CRect newInvertedRect(rect.left, point.y, 
					rect.right, point.y + 2);
				pDC->InvertRect(&newInvertedRect);
				m_pGridRefWnd->ReleaseDC(pDC);
			}
			break;

		case MOUSE_PREPARE_DRAG:    OnBeginDrag();    break;
		}    
	}

	m_LastMousePoint = point;
}

void CXGridCtrlBase::OnTimer(UINT nIDEvent)
{
	ASSERT(nIDEvent == WM_LBUTTONDOWN);
	if (nIDEvent != WM_LBUTTONDOWN) return;

	if (::IsWindow(m_pGridRefWnd->GetSafeHwnd()))
	{
		return;
	}

	CPoint pt, origPt;

	if (!GetCursorPos(&origPt)) return;

	m_pGridRefWnd->ScreenToClient(&origPt);

	CRect rect;
	GetGridClientRect(rect);

	int nFixedRowHeight = GetFixedRowHeight();
	int nFixedColWidth = GetFixedColumnWidth();

	pt = origPt;
	if (pt.y > rect.bottom)
	{
		//SendMessage(WM_VSCROLL, SB_LINEDOWN, 0);
		m_pGridRefWnd->SendMessage(WM_KEYDOWN, VK_DOWN, 0);

		if (pt.x < rect.left)  pt.x = rect.left;
		if (pt.x > rect.right) pt.x = rect.right;
		pt.y = rect.bottom;
		OnSelecting(GetCellFromPt(pt));
	}
	else if (pt.y < nFixedRowHeight)
	{
		//SendMessage(WM_VSCROLL, SB_LINEUP, 0);
		m_pGridRefWnd->SendMessage(WM_KEYDOWN, VK_UP, 0);

		if (pt.x < rect.left)  pt.x = rect.left;
		if (pt.x > rect.right) pt.x = rect.right;
		pt.y = nFixedRowHeight + 1;
		OnSelecting(GetCellFromPt(pt));
	}

	pt = origPt;
	if (pt.x > rect.right)
	{
		// SendMessage(WM_HSCROLL, SB_LINERIGHT, 0);
		m_pGridRefWnd->SendMessage(WM_KEYDOWN, VK_RIGHT, 0);

		if (pt.y < rect.top)    pt.y = rect.top;
		if (pt.y > rect.bottom) pt.y = rect.bottom;
		pt.x = rect.right;
		OnSelecting(GetCellFromPt(pt));
	} 
	else if (pt.x < nFixedColWidth)
	{
		//SendMessage(WM_HSCROLL, SB_LINELEFT, 0);
		m_pGridRefWnd->SendMessage(WM_KEYDOWN, VK_LEFT, 0);

		if (pt.y < rect.top)    pt.y = rect.top;
		if (pt.y > rect.bottom) pt.y = rect.bottom;
		pt.x = nFixedColWidth + 1;
		OnSelecting(GetCellFromPt(pt));
	}

}


BOOL CXGridCtrlBase::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if (!m_bUseKeyMsg)
	{
		return FALSE;
	}

	if (!m_oKeysMngr.CanUseKey(nChar))
	{
		return FALSE;
	}

	if (!IsValid(m_idCurrentCell)) 
	{
		return FALSE;
	}

	CCellID next = m_idCurrentCell;
	BOOL bChangeLine = FALSE;

	// 	if (IsCTRLpressed())
	// 	{
	// 		switch (nChar)
	// 		{
	// 		case 'A': OnEditSelectAll();  break;
	// 		case 'X': OnEditCut();        break;
	// 		case 'C': OnEditCopy();       break;
	// 		case 'V': OnEditPaste();      break;
	// 		}
	// 	}

	switch (nChar)
	{
	case VK_DELETE: 
		if (OnCellKeyDelete(m_idCurrentCell))
		{
			break;
		}

		if (m_bUseVKDelete && IsCellEditable(m_idCurrentCell.row, m_idCurrentCell.col))
		{
			SetItemText(m_idCurrentCell.row, m_idCurrentCell.col, _T(""));
			RedrawCell(m_idCurrentCell);
			SetModified(TRUE);
			long lValue=0;
			lValue+=m_idCurrentCell.col;
			lValue+=m_idCurrentCell.row<<16;

			CWnd* pWnd = m_pGridRefWnd->GetParent();
			if (pWnd != NULL)
			{
				if (::IsWindow(pWnd->GetSafeHwnd()))
				{
					pWnd->SendMessage(WM_GRID_END_EDIT,0,(LPARAM)lValue);
				}			
			}
		}
		break;

	case VK_TAB:    
		if (IsSHIFTpressed())
		{
			if (GetPrevCell(next, bChangeLine))
			{
			}
			else
			{
				//CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
				return FALSE;
			}
		}
		else
		{
			if (GetNextCell(next, bChangeLine))
			{
			}
			else
			{
				//CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
				return FALSE;
			}
		} 
		break;

	case VK_DOWN:   
		GetDownCell(next);
		break;            

	case VK_UP:   
		GetUpCell(next);
		break;

	case VK_RIGHT:  
		GetRightCell(next);
		break;

	case VK_LEFT:   
		GetLeftCell(next);
		break;

	case VK_NEXT:   
		{
			CCellID idOldTopLeft = GetTopleftNonFixedCell();

			if (::IsWindow(m_pGridRefWnd->GetSafeHwnd()))
			{
				m_pGridRefWnd->SendMessage(WM_VSCROLL, SB_PAGEDOWN, 0);
			}

			CCellID idNewTopLeft = GetTopleftNonFixedCell();

			int increment = idNewTopLeft.row - idOldTopLeft.row;
			if (increment) {
				next.row += increment;
				if (next.row > (GetRowCount() - 1)) 
					next.row = GetRowCount() - 1;
			}
			else
				next.row = GetRowCount() - 1;
			break;
		}

	case VK_PRIOR:  
		{
			CCellID idOldTopLeft = GetTopleftNonFixedCell();

			if (::IsWindow(m_pGridRefWnd->GetSafeHwnd()))
			{
				m_pGridRefWnd->SendMessage(WM_VSCROLL, SB_PAGEUP, 0);
			}

			CCellID idNewTopLeft = GetTopleftNonFixedCell();

			int increment = idNewTopLeft.row - idOldTopLeft.row;
			if (increment) 
			{
				next.row += increment;
				if (next.row < m_nFixedRows) 
					next.row = m_nFixedRows;
			} else
				next.row = m_nFixedRows;
			break;
		}

	case VK_HOME:   
		{
			if (::IsWindow(m_pGridRefWnd->GetSafeHwnd()))
			{
				m_pGridRefWnd->SendMessage(WM_VSCROLL, SB_TOP, 0);
			}

			next.row = m_nFixedRows;
		}
		break;

	case VK_END:    
		{
			if (::IsWindow(m_pGridRefWnd->GetSafeHwnd()))
			{
				m_pGridRefWnd->SendMessage(WM_VSCROLL, SB_BOTTOM, 0);
			}

			next.row = GetRowCount() - 1;
		}
		break;

	default:
		return FALSE;
		break;
	}

	if (next != m_idCurrentCell) 
	{
		// While moving with the Cursorkeys the current ROW/CELL will get selected
		// OR Selection will get expanded when SHIFT is pressed
		// Cut n paste from OnLButtonDown - Franco Bez 
		// Added check for NULL mouse mode - Chris Maunder.
		if (m_MouseMode == MOUSE_NOTHING)
		{
			m_PrevSelectedCellMap.RemoveAll();
			m_MouseMode = m_bListMode? MOUSE_SELECT_ROW : MOUSE_SELECT_CELLS;
			if (!IsSHIFTpressed() || nChar == VK_TAB)
				m_SelectionStartCell = next;
			OnSelecting(next);
			m_MouseMode = MOUSE_NOTHING;
		}

		SetFocusCell(next);

		if (!IsCellVisible(next))
		{   
			EnsureVisible(next); // Make sure cell is visible

			if (!::IsWindow(m_pGridRefWnd->GetSafeHwnd())) 
			{
				return FALSE;
			}

			switch (nChar) 
			{
			case VK_RIGHT:  
				m_pGridRefWnd->SendMessage(WM_HSCROLL, SB_LINERIGHT, 0); 
				break;

			case VK_LEFT:   
				m_pGridRefWnd->SendMessage(WM_HSCROLL, SB_LINELEFT, 0);  
				break;

			case VK_DOWN:   
				m_pGridRefWnd->SendMessage(WM_VSCROLL, SB_LINEDOWN, 0);  
				break;

			case VK_UP:     
				m_pGridRefWnd->SendMessage(WM_VSCROLL, SB_LINEUP, 0);    
				break;                

			case VK_TAB:    
				if (IsSHIFTpressed())
				{
					if (bChangeLine) 
					{
						m_pGridRefWnd->SendMessage(WM_VSCROLL, SB_LINEUP, 0);
						SetScrollPos32(SB_HORZ, m_nHScrollMax);
						break;
					}
					else 
						m_pGridRefWnd->SendMessage(WM_HSCROLL, SB_LINELEFT, 0);
				}
				else
				{
					if (bChangeLine) 
					{
						m_pGridRefWnd->SendMessage(WM_VSCROLL, SB_LINEDOWN, 0);
						SetScrollPos32(SB_HORZ, 0);
						break;
					}
					else 
						m_pGridRefWnd->SendMessage(WM_HSCROLL, SB_LINERIGHT, 0);
				}
				break;

			}

			m_pGridRefWnd->Invalidate();
		}
	}

	return TRUE;
}

// Instant editing of cells when keys are pressed
BOOL CXGridCtrlBase::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if (!m_oKeysMngr.CanUseKey(nChar))
	{
		//CWnd::OnChar(nChar, nRepCnt, nFlags);
		return FALSE;
	}

	if (m_bUseKeyMsg)
	{
		if (!IsCTRLpressed() && m_MouseMode == MOUSE_NOTHING)
		{
			if (!m_bHandleTabKey || (m_bHandleTabKey && nChar != VK_TAB))
			{
				OnEditCell(m_idCurrentCell.row, m_idCurrentCell.col, nChar);
			}
		}
	} 
	else
	{
	}

	//CWnd::OnChar(nChar, nRepCnt, nFlags);
	return TRUE;
}

void CXGridCtrlBase::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	if (m_MouseMode == MOUSE_OVER_COL_DIVIDE) 
	{
		CCellID cell = GetCellFromPt(point);
		ASSERT(IsValid(cell));

		CPoint start;
		if (!GetCellOrigin(0, cell.col, &start)) return;

		if (point.x - start.x <= m_nResizeCaptureRange)     // Clicked right of border
			cell.col--;

		AutoSizeColumn(cell.col);
		m_pGridRefWnd->Invalidate();
	} 
	else if (m_MouseMode == MOUSE_OVER_ROW_DIVIDE)
	{
		CCellID cell = GetCellFromPt(point);
		ASSERT(IsValid(cell));

		CPoint start;
		if (!GetCellOrigin(0, cell.col, &start)) return;

		if (point.y - start.y <= m_nResizeCaptureRange)     // Clicked below border
			cell.row--;

		AutoSizeRow(cell.row);
		m_pGridRefWnd->Invalidate();
	}
	else if (m_MouseMode == MOUSE_NOTHING)
	{
		if (m_LeftClickDownCell.row >= m_nFixedRows && 
			IsValid(m_LeftClickDownCell) &&
			m_LeftClickDownCell.col >= m_nFixedCols)
		{
			OnEditCellLBDblClk(m_idCurrentCell.row, m_idCurrentCell.col, VK_LBUTTON);
			SendMessageToParent(m_idCurrentCell.row, m_idCurrentCell.col, GVN_GRIDDBCLICK);
		}
		else if (m_bListMode)
		{
			CCellID cell = GetCellFromPt(point);
			if (!IsValid(cell)) return;
			if (cell.row >= m_nFixedRows && cell.col < GetFixedColumnCount())
				OnEditCellLBDblClk(cell.row, cell.col, VK_LBUTTON);
			SendMessageToParent(cell.row, cell.col, GVN_GRIDDBCLICK);
		}

	}

	//CWnd::OnLButtonDblClk(nFlags, point);
}


void CXGridCtrlBase::OnRButtonDblClk(UINT nFlags, CPoint point) 
{
	if (m_MouseMode == MOUSE_OVER_COL_DIVIDE) 
	{

	} 
	else if (m_MouseMode == MOUSE_OVER_ROW_DIVIDE)
	{

	}
	else if (m_MouseMode == MOUSE_NOTHING)
	{
		CCellID oCurrCell = GetCellFromPt(point);

		if (oCurrCell == m_LeftClickDownCell)
		{
			if (m_LeftClickDownCell.row >= m_nFixedRows && 
				IsValid(m_LeftClickDownCell) &&
				m_LeftClickDownCell.col >= m_nFixedCols)
			{
				OnEditCellRBDblClk(m_idCurrentCell.row, m_idCurrentCell.col, VK_RBUTTON);
				SendMessageToParent(m_idCurrentCell.row, m_idCurrentCell.col, GVN_GRIDDBCLICKR);
			}
			else if (m_bListMode)
			{
				CCellID cell = GetCellFromPt(point);
				if (!IsValid(cell)) return;
				if (cell.row >= m_nFixedRows && cell.col < GetFixedColumnCount())
					OnEditCellRBDblClk(cell.row, cell.col, VK_LBUTTON);
				SendMessageToParent(cell.row, cell.col, GVN_GRIDDBCLICKR);
			}
		}
	}

	//CWnd::OnRButtonDblClk(nFlags, point);
}


BOOL CXGridCtrlBase::OnEraseBkgnd(CDC* /*pDC*/) 
{
	return TRUE;    // Don't erase the background.
}


BOOL CXGridCtrlBase::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if (nHitTest == HTCLIENT)
	{
		switch (m_MouseMode) 
		{
		case MOUSE_OVER_COL_DIVIDE: SetCursor(::LoadCursor(NULL, IDC_SIZEWE)); break;
		case MOUSE_OVER_ROW_DIVIDE: SetCursor(::LoadCursor(NULL, IDC_SIZENS)); break;
		case MOUSE_DRAGGING:        break;
		default:                    SetCursor(::LoadCursor(NULL, IDC_ARROW));
		}
		return TRUE;
	}

	return FALSE;//CWnd::OnSetCursor(pWnd, nHitTest, message);
}


// If system colours change, then redo colours
void CXGridCtrlBase::OnSysColorChange() 
{
	//CWnd::OnSysColorChange();

	if (GetTextColor() == m_crWindowText)                   // Still using system colours
		SetTextColor(::GetSysColor(COLOR_WINDOWTEXT));      // set to new system colour
	if (GetTextBkColor() == m_crWindowColour)
		SetTextBkColor(::GetSysColor(COLOR_WINDOW));
	if (GetBkColor() == m_crShadow)
		SetBkColor(::GetSysColor(COLOR_3DSHADOW));
	if (GetFixedTextColor() == m_crWindowText)
		SetFixedTextColor(::GetSysColor(COLOR_WINDOWTEXT));
	if (GetFixedBkColor() == m_cr3DFace)
		SetFixedBkColor(::GetSysColor(COLOR_3DFACE));

	m_crWindowText   = ::GetSysColor(COLOR_WINDOWTEXT);
	m_crWindowColour = ::GetSysColor(COLOR_WINDOW);
	m_cr3DFace       = ::GetSysColor(COLOR_3DFACE);
	m_crShadow       = ::GetSysColor(COLOR_3DSHADOW);
}


// If we are drag-selecting cells, or drag and dropping, stop now
void CXGridCtrlBase::OnCaptureChanged(CWnd *pWnd) 
{
	if (pWnd->GetSafeHwnd() == m_pGridRefWnd->GetSafeHwnd())
	{
		return;
	}

	// kill timer if active
	if (m_nTimerID != 0)
	{
		m_pGridRefWnd->KillTimer(m_nTimerID);
		m_nTimerID = 0;
	}

	// Kill drag and drop if active
	if (m_MouseMode == MOUSE_DRAGGING)
	{
		m_MouseMode = MOUSE_NOTHING;
	}
}


void CXGridCtrlBase::OnRButtonUp(UINT nFlags, CPoint point) 
{
	if (OnCellRButtonUpEx(nFlags, point))
	{
		return ;
	}

	// TODO: Add your message handler code here and/or call default
	CCellID rightClickDownCell = GetCellFromPt(point);

	if (OnCellRButtonUp(rightClickDownCell))
	{
		return;
	}

	RB_MOUSEPOS rbMouse;
	rbMouse.iActCellCol	=m_idCurrentCell.col;
	rbMouse.iActCellRow	=m_idCurrentCell.row;
	rbMouse.iMouseCol	=rightClickDownCell.col;
	rbMouse.iMouseRow	=rightClickDownCell.row;
	rbMouse.ptMousePos	=point;
	rbMouse.ulHWnd		=(unsigned long)m_pGridRefWnd->m_hWnd;

	unsigned long l=(unsigned long)m_pGridRefWnd->m_hWnd;
	CWnd *pWnd = m_pGridRefWnd->GetOwner();

	if (pWnd != NULL)
	{
		if (::IsWindow(pWnd->GetSafeHwnd()))
		{
			pWnd->SendMessage(WM_USER+1001,(WPARAM)l,(LPARAM)&rbMouse);
		}
	}

}


void CXGridCtrlBase::OnKillFocus(CWnd* pNewWnd) 
{
	//CWnd::OnKillFocus(pNewWnd);
	KillFocusCell();
}

#if _MFC_VER >= 0x0421
// If system settings change, then redo colours
void CXGridCtrlBase::OnSettingChange(UINT uFlags, LPCTSTR lpszSection) 
{
	if (GetTextColor() == m_crWindowText)                   // Still using system colours
		SetTextColor(::GetSysColor(COLOR_WINDOWTEXT));      // set to new system colour
	if (GetTextBkColor() == m_crWindowColour)
		SetTextBkColor(::GetSysColor(COLOR_WINDOW));
	if (GetBkColor() == m_crShadow)
		SetBkColor(::GetSysColor(COLOR_3DSHADOW));
	if (GetFixedTextColor() == m_crWindowText)
		SetFixedTextColor(::GetSysColor(COLOR_WINDOWTEXT));
	if (GetFixedBkColor() == m_cr3DFace)
		SetFixedBkColor(::GetSysColor(COLOR_3DFACE));

	m_crWindowText   = ::GetSysColor(COLOR_WINDOWTEXT);
	m_crWindowColour = ::GetSysColor(COLOR_WINDOW);
	m_cr3DFace       = ::GetSysColor(COLOR_3DFACE);
	m_crShadow       = ::GetSysColor(COLOR_3DSHADOW);

	m_nRowsPerWheelNotch = GetMouseScrollLines(); // Get the number of lines
}

#endif

#if _MFC_VER >= 0x0421
BOOL CXGridCtrlBase::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// A m_nRowsPerWheelNotch value less than 0 indicates that the mouse
	// wheel scrolls whole pages, not just lines.
	if (!::IsWindow(m_pGridRefWnd->GetSafeHwnd()))
	{
		return TRUE;
	}

	if (m_nRowsPerWheelNotch == -1)
	{
		int nPagesScrolled = zDelta / 120;

		if (nPagesScrolled > 0)
			for (int i = 0; i < nPagesScrolled; i++)
				m_pGridRefWnd->PostMessage(WM_VSCROLL, SB_PAGEUP, 0);
		else
			for (int i = 0; i > nPagesScrolled; i--)
				m_pGridRefWnd->PostMessage(WM_VSCROLL, SB_PAGEDOWN, 0);
	}
	else
	{
		int nRowsScrolled = m_nRowsPerWheelNotch * zDelta / 120;

		if (nRowsScrolled > 0)
			for (int i = 0; i < nRowsScrolled; i++)
				m_pGridRefWnd->PostMessage(WM_VSCROLL, SB_LINEUP, 0);
		else
			for (int i = 0; i > nRowsScrolled; i--)
				m_pGridRefWnd->PostMessage(WM_VSCROLL, SB_LINEDOWN, 0);
	}

	AfterOnMouseWheel(nFlags, zDelta, pt);

	return TRUE;
}
#endif



LRESULT CXGridCtrlBase::OnSetFont(WPARAM hFont, LPARAM /*lParam */)
{
	if (m_pGridRefWnd == NULL)
	{
		return 0;
	}

	// Get the logical font
	LOGFONT lf;
	if (!GetObject((HFONT) hFont, sizeof(LOGFONT), &lf))
		return 0;

	// Store font as the global default
	memcpy(&m_Logfont, &lf, sizeof(LOGFONT));

	// reset all cells' fonts
	for (int row = 0; row < GetRowCount(); row++)
		for (int col = 0; col < GetColumnCount(); col++)
			SetItemFont(row, col, &lf);

	// Get the font size and hence the default cell size
	CDC* pDC = m_pGridRefWnd->GetDC();

	if (pDC) 
	{
		m_Font.DeleteObject();
		m_Font.CreateFontIndirect(&m_Logfont);
		CFont* pOldFont = pDC->SelectObject(&m_Font);

		TEXTMETRIC tm;
		pDC->GetTextMetrics(&tm);

		m_nMargin = pDC->GetTextExtent(_T(" "),1).cx;
		pDC->SelectObject(pOldFont);
		m_pGridRefWnd->ReleaseDC(pDC);

		m_nDefCellHeight = tm.tmHeight+tm.tmExternalLeading + 2*m_nMargin;
		m_nDefCellWidth  = tm.tmAveCharWidth*12 + 2*m_nMargin;
	}

	if (::IsWindow(m_pGridRefWnd->GetSafeHwnd())) 
		m_pGridRefWnd->Invalidate();

	return 0;
}

LRESULT CXGridCtrlBase::OnGetFont(WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	return (LRESULT) (HFONT) m_Font;
}


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CGridCtrl, CWnd)

void AFXAPI DDX_GridControl(CDataExchange* pDX, int nIDC, CGridCtrl& rControl)
{
	if (rControl.GetSafeHwnd() == NULL)    // not subclassed yet
	{
		ASSERT(!pDX->m_bSaveAndValidate);

		HWND hWndCtrl = pDX->PrepareCtrl(nIDC);

		if (!rControl.SubclassWindow(hWndCtrl))
		{
			ASSERT(FALSE);      // possibly trying to subclass twice?
			AfxThrowNotSupportedException();
		}
#ifndef _AFX_NO_OCC_SUPPORT
		else
		{
			// If the control has reparented itself (e.g., invisible control),
			// make sure that the CWnd gets properly wired to its control site.
			if (pDX->m_pDlgWnd->GetSafeHwnd() != ::GetParent(rControl.GetSafeHwnd()))
				rControl.AttachControlSite(pDX->m_pDlgWnd);
		}
#endif //!_AFX_NO_OCC_SUPPORT

	}
}



CGridCtrl::CGridCtrl(int nRows, int nCols, int nFixedRows, int nFixedCols)
: CXGridCtrlBase(nRows, nCols, nFixedRows, nFixedCols)
{
	m_pGridRefWnd = this;
}

CGridCtrl::~CGridCtrl()
{

}

UINT CGridCtrl::GetGridClipRect(CDC* pDC, CRect &rcClip)
{
	return pDC->GetClipBox(&rcClip);
}

void CGridCtrl::GetGridClientRect(CRect &rcClient)
{
	ASSERT(m_pGridRefWnd != NULL);
	GetClientRect(&rcClient);
}

void CGridCtrl::GetGridClientRect(CRect &rcClient) const
{
	ASSERT(m_pGridRefWnd != NULL);
	GetClientRect(&rcClient);
}

// CXGridCtrlBase cellrange functions
CCellID CGridCtrl::GetTopleftNonFixedCell() const
{
	int nVertScroll = m_pGridRefWnd->GetScrollPos(SB_VERT), 
		nHorzScroll = m_pGridRefWnd->GetScrollPos(SB_HORZ);

	int nColumn = m_nFixedCols, nRight = 0;
	while (nRight < nHorzScroll && nColumn < (GetColumnCount()-1))
		nRight += GetColumnWidth(nColumn++);

	int nRow = m_nFixedRows, nTop = 0;
	while (nTop < nVertScroll && nRow < (GetRowCount()-1))
		nTop += GetRowHeight(nRow++);

	//TRACE("TopLeft cell is row %d, col %d\n",nRow, nColumn);
	return CCellID(nRow, nColumn);
}

// This gets even partially visible cells
CGridCellRange CGridCtrl::GetVisibleNonFixedCellRange(LPRECT pRect /*=NULL*/) const
{
	CRect rect;
	int i = 0;

	GetGridClientRect(rect);

	CCellID idTopLeft = GetTopleftNonFixedCell();

	// calc bottom
	int bottom = GetFixedRowHeight();
	for (i = idTopLeft.row; i < GetRowCount(); i++)
	{
		bottom += GetRowHeight(i);
		if (bottom >= rect.bottom) {
			bottom = rect.bottom;
			break;
		}
	}                                
	int maxVisibleRow = min(i, GetRowCount() - 1);

	// calc right
	int right = GetFixedColumnWidth();
	for (i = idTopLeft.col; i < GetColumnCount(); i++)
	{
		right += GetColumnWidth(i);
		if (right >= rect.right) {
			right = rect.right;
			break;
		}
	}
	int maxVisibleCol = min(i, GetColumnCount() - 1);
	if (pRect) {
		pRect->left = pRect->top = 0;
		pRect->right = right;
		pRect->bottom = bottom;
	}

	return CGridCellRange(idTopLeft.row, idTopLeft.col, maxVisibleRow, maxVisibleCol);
}

// used by ResetScrollBars() - This gets only fully visible cells
CGridCellRange CGridCtrl::GetUnobstructedNonFixedCellRange() const
{
	CRect rect;
	GetGridClientRect(rect);

	CCellID idTopLeft = GetTopleftNonFixedCell();

	int i = 0;

	// calc bottom
	int bottom = GetFixedRowHeight();
	for (i = idTopLeft.row; i < GetRowCount(); i++)
	{
		bottom += GetRowHeight(i);
		if (bottom >= rect.bottom) break;
	}
	int maxVisibleRow = min(i, GetRowCount() - 1);
	if (maxVisibleRow > 0 && bottom > rect.bottom) maxVisibleRow--;

	// calc right
	int right = GetFixedColumnWidth();
	for (i = idTopLeft.col; i < GetColumnCount(); i++)
	{
		right += GetColumnWidth(i);
		if (right >= rect.right) break;
	}
	int maxVisibleCol = min(i, GetColumnCount() - 1);
	if (maxVisibleCol > 0 && right > rect.right) maxVisibleCol--;


	return CGridCellRange(idTopLeft.row, idTopLeft.col, maxVisibleRow, maxVisibleCol);
}

BEGIN_MESSAGE_MAP(CGridCtrl, CWnd)
	//{{AFX_MSG_MAP(CXGridCtrlBase)
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_SIZE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_WM_GETDLGCODE()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_ERASEBKGND()
	ON_WM_SETCURSOR()
	ON_WM_SYSCOLORCHANGE()
	ON_WM_CAPTURECHANGED()
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_SELECT_ALL, OnUpdateEditSelectAll)
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_COMMAND(ID_EDIT_SELECT_ALL, OnEditSelectAll)
	ON_WM_KILLFOCUS()
	//}}AFX_MSG_MAP
#if _MFC_VER >= 0x0421
	ON_WM_MOUSEWHEEL()
	ON_WM_SETTINGCHANGE()
#endif
	ON_MESSAGE(WM_SETFONT, OnSetFont)
	ON_MESSAGE(WM_GETFONT, OnGetFont)
	ON_NOTIFY(GVN_ENDLABELEDIT, IDC_INPLACE_EDIT, OnEndInPlaceEdit)
	ON_NOTIFY(GVN_ENDCOMBOBOXEDIT, IDC_INPLACE_COMBOBOX, OnEndInplaceComboBoxEdit)	
	//////////////////////////////////////////////////
	ON_MESSAGE(IPCMBM_FILL, OnFillComboBox)
	//ON_MESSAGE(IPTM_FILL, OnFillTree)
	//ON_MESSAGE(IPDM_FILL, OnFillTimeCtrl)

	/////////////////////////////////////////////////
	//	   ON_NOTIFY(NM_KILLFOCUS, IDC_INPLACE_EDIT, OnEndInPlaceEdit)

	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()



BOOL CGridCtrl::Create(const RECT& rect, CWnd* pParentWnd, UINT nID, DWORD dwStyle)
{
	ASSERT(pParentWnd->GetSafeHwnd());

	if (!CWnd::Create(GRIDCTRL_CLASSNAME, NULL, dwStyle, rect, pParentWnd, nID)) 
		return FALSE;

	CXGridCtrlBase::Create(this);

	return TRUE;
}

BOOL CGridCtrl::SubclassWindow(HWND hWnd) 
{    
	if (!CWnd::SubclassWindow(hWnd)) return FALSE;

	return TRUE;
}


void CGridCtrl::PreSubclassWindow() 
{    
	CWnd::PreSubclassWindow();

	HFONT hFont = ::CreateFontIndirect(&m_Logfont);
	OnSetFont((LPARAM)hFont, 0);
	DeleteObject(hFont);

	ResetScrollBars();   
}

void CGridCtrl::OnPaint() 
{
	CPaintDC dc(this);      // device context for painting

	if (m_bDoubleBuffer)    // Use a memory DC to remove flicker
	{
		CXGridCtrlBaseMemDC MemDC(&dc);
		OnDraw(&MemDC);
	}
	else                    // Draw raw - this helps in debugging vis problems.
		OnDraw(&dc);
}


// Handle horz scrollbar notifications
void CGridCtrl::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CXGridCtrlBase::OnHScroll(nSBCode, nPos, pScrollBar);
}

// Handle vert scrollbar notifications
void CGridCtrl::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CXGridCtrlBase::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CGridCtrl::OnSize(UINT nType, int cx, int cy) 
{
	//    if (::IsWindow(GetSafeHwnd()) && GetFocus()->GetSafeHwnd() != GetSafeHwnd()) 
	SetFocus();        // Auto-destroy any InPlaceEdit's

	CWnd::OnSize(nType, cx, cy);
	ResetScrollBars();    
}

void CGridCtrl::OnLButtonUp(UINT nFlags, CPoint point)
{
	CWnd::OnLButtonUp(nFlags, point);

	CXGridCtrlBase::OnLButtonUp(nFlags, point);
}

void CGridCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	CXGridCtrlBase::OnLButtonDown(nFlags, point);
}

void CGridCtrl::OnMouseMove(UINT nFlags, CPoint point)
{
	CXGridCtrlBase::OnMouseMove(nFlags, point);
}

void CGridCtrl::OnTimer(UINT nIDEvent)
{
	CXGridCtrlBase::OnTimer(nIDEvent);
}


UINT CGridCtrl::OnGetDlgCode() 
{
	return CXGridCtrlBase::OnGetDlgCode();
}


// move about with keyboard
void CGridCtrl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if (CXGridCtrlBase::OnKeyDown(nChar, nRepCnt, nFlags))
	{

	}

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}

// Instant editing of cells when keys are pressed
void CGridCtrl::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if (CXGridCtrlBase::OnChar(nChar, nRepCnt, nFlags))
	{
		return;
	}

	CWnd::OnChar(nChar, nRepCnt, nFlags);
}

void CGridCtrl::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	CXGridCtrlBase::OnLButtonDblClk(nFlags, point);

	CWnd::OnLButtonDblClk(nFlags, point);
}


void CGridCtrl::OnRButtonDblClk(UINT nFlags, CPoint point) 
{
	CXGridCtrlBase::OnRButtonDblClk(nFlags, point);

	CWnd::OnRButtonDblClk(nFlags, point);
}


BOOL CGridCtrl::OnEraseBkgnd(CDC* /*pDC*/) 
{
	return TRUE;    // Don't erase the background.
}


BOOL CGridCtrl::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if (CXGridCtrlBase::OnSetCursor(pWnd, nHitTest, message))
	{
		return TRUE;
	}

	return CWnd::OnSetCursor(pWnd, nHitTest, message);
}


// If system colours change, then redo colours
void CGridCtrl::OnSysColorChange() 
{
	CWnd::OnSysColorChange();

	CXGridCtrlBase::OnSysColorChange();
}


// If we are drag-selecting cells, or drag and dropping, stop now
void CGridCtrl::OnCaptureChanged(CWnd *pWnd) 
{
	CXGridCtrlBase::OnCaptureChanged(pWnd);
}

void CGridCtrl::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	CGridCellRange Selection = GetSelectedCellRange();
	pCmdUI->Enable(Selection.Count() && IsValid(Selection));
}

void CGridCtrl::OnUpdateEditCut(CCmdUI* pCmdUI) 
{
	CGridCellRange Selection = GetSelectedCellRange();
	pCmdUI->Enable(IsEditable() && Selection.Count() && IsValid(Selection));
}

void CGridCtrl::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
	CCellID cell = GetFocusCell();

	BOOL bCanPaste = IsValid(cell) && IsCellEditable(cell) &&
		::IsClipboardFormatAvailable(CF_TEXT);

	pCmdUI->Enable(bCanPaste);
}

void CGridCtrl::OnUpdateEditSelectAll(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_bEnableSelection);
}


void CGridCtrl::OnRButtonUp(UINT nFlags, CPoint point) 
{
	CXGridCtrlBase::OnRButtonUp(nFlags, point);

	CWnd::OnRButtonUp(nFlags, point);
}


void CGridCtrl::OnKillFocus(CWnd* pNewWnd) 
{
	CWnd::OnKillFocus(pNewWnd);

	CXGridCtrlBase::OnKillFocus(pNewWnd);
}


#if _MFC_VER >= 0x0421
// If system settings change, then redo colours
void CGridCtrl::OnSettingChange(UINT uFlags, LPCTSTR lpszSection) 
{
	CWnd::OnSettingChange(uFlags, lpszSection);

	CXGridCtrlBase::OnSettingChange(uFlags, lpszSection);
}
#endif

/////////////////////////////////////////////////////////////////////////////
// CXGridCtrlBase Mouse stuff

// Handles mouse wheel notifications
// Note - if this doesn't work for win95 then use OnRegisteredMouseWheel instead
#if _MFC_VER >= 0x0421
BOOL CGridCtrl::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	CXGridCtrlBase::OnMouseWheel(nFlags, zDelta, pt);

	return CWnd::OnMouseWheel(nFlags, zDelta, pt);
}
#endif


////////////////////////////////////////////////////////////////////////////////////
// Grid attribute functions

LRESULT CGridCtrl::OnSetFont(WPARAM hFont, LPARAM lParam)
{
	LRESULT result = Default();

	CXGridCtrlBase::OnSetFont(hFont, lParam);
	return result;
}

LRESULT CGridCtrl::OnGetFont(WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	return (LRESULT) (HFONT) m_Font;
}


// Callback from any CInPlaceEdits that ended. This just calls OnEndEditCell,
// refreshes the edited cell and moves onto next cell if the return character
// from the edit says we should.
void CGridCtrl::OnEndInPlaceEdit(NMHDR* pNMHDR, LRESULT* pResult) 
{    
	CXGridCtrlBase::OnEndInPlaceEdit(pNMHDR, pResult);
}
void CGridCtrl::OnEndPointEdit(NMHDR* pNMHDR, LRESULT* pResult) 
{    
	CXGridCtrlBase::OnEndPointEdit(pNMHDR, pResult);
}
void CGridCtrl::OnEndInplaceComboBoxEdit(NMHDR* pNMHDR, LRESULT* pResult) 
{    
	CXGridCtrlBase::OnEndInplaceComboBoxEdit(pNMHDR, pResult);
}

LRESULT CGridCtrl::OnFillComboBox(WPARAM wParam, LPARAM lParam)
{
	CXGridCtrlBase::OnFillComboBox(wParam, lParam);
	return Default();
}

LRESULT CGridCtrl::OnFillList(WPARAM nColumn, LPARAM pListBox)
{
	CXGridCtrlBase::OnFillList(nColumn, pListBox);
	return Default();
}

LRESULT CGridCtrl::OnFillTree(WPARAM nColumn, LPARAM pListBox)
{
	CXGridCtrlBase::OnFillTree(nColumn, pListBox);
	return Default();
}
LRESULT CGridCtrl::OnFillTimeCtrl(WPARAM nColumn, LPARAM pListBox)
{
	CXGridCtrlBase::OnFillTimeCtrl(nColumn, pListBox);
	return Default();
}

BOOL CGridCtrl::PreTranslateMessage(MSG* pMsg) 
{
	CXGridCtrlBase::PreTranslateMessage(pMsg);

	return CWnd::PreTranslateMessage(pMsg);
}

void CGridCtrl::OnRButtonDown(UINT nFlags, CPoint point)
{
	if (m_bUseRButtonDownForSel)
	{
		OnLButtonDown(nFlags, point);
		m_MouseMode = MOUSE_NOTHING;
	}

	//CWnd::OnRButtonDown(nFlags, point);
}


void CGridCtrl::OnEditCut()
{
	if (!IsEditable())
		return;

	COleDataSource* pSource = CopyTextFromGrid();
	if (!pSource) return;

	pSource->SetClipboard();
	CutSelectedText();
}

void CGridCtrl::OnEditCopy()
{
	COleDataSource* pSource = CopyTextFromGrid();
	if (!pSource) return;

	pSource->SetClipboard();
}

void CGridCtrl::OnEditPaste()
{
	if (!IsEditable())
		return;

	// Get the Focus cell, or if none, get the topleft (non-fixed) cell
	CCellID cell = GetFocusCell();  
	if (!IsValid(cell)) cell = GetTopleftNonFixedCell();  
	if (!IsValid(cell)) return;

	// Attach a COleDataObject to the clipboard and paste the data to the grid
	COleDataObject obj;
	if (obj.AttachClipboard()) 
		PasteTextToGrid(cell, &obj);
}

void CGridCtrl::OnEditSelectAll() 
{
	SelectAllCells();
}


void CGridCtrl::ResetScrollBars()
{
	if (!m_bAllowDraw || !::IsWindow(m_pGridRefWnd->GetSafeHwnd())) 
		return;

	CRect rect;
	GetGridClientRect(rect);
	rect.left  += GetFixedColumnWidth();
	rect.top   += GetFixedRowHeight();
	if (rect.left >= rect.right || rect.top >= rect.bottom) return;

	CRect VisibleRect(GetFixedColumnWidth(), GetFixedRowHeight(), rect.right, rect.bottom);
	CRect VirtualRect(GetFixedColumnWidth(), GetFixedRowHeight(), GetVirtualWidth(), GetVirtualHeight());

	CGridCellRange visibleCells = GetUnobstructedNonFixedCellRange();
	//if (!IsValid(visibleCells)) return;

	SCROLLINFO si;
	si.cbSize = sizeof(SCROLLINFO);
	si.fMask  = SIF_PAGE;
	si.nPage  = VisibleRect.Width();    m_pGridRefWnd->SetScrollInfo(SB_HORZ, &si, FALSE); 
	si.nPage  = VisibleRect.Height();   m_pGridRefWnd->SetScrollInfo(SB_VERT, &si, FALSE); 

	if (VisibleRect.Height() < VirtualRect.Height())
		m_nVScrollMax = VirtualRect.Height()-1; //+ GetRowHeight(visibleCells.GetTopLeft().row);
	else
		m_nVScrollMax = 0;

	if (VisibleRect.Width() < VirtualRect.Width())
		m_nHScrollMax = VirtualRect.Width()-1; //+ GetColumnWidth(visibleCells.GetTopLeft().col);
	else
		m_nHScrollMax = 0;

	ASSERT(m_nVScrollMax < INT_MAX && m_nHScrollMax < INT_MAX); // This should be fine :)
	SetScrollRange(SB_VERT, 0, m_nVScrollMax, TRUE);
	SetScrollRange(SB_HORZ, 0, m_nHScrollMax, TRUE);
}
