// XscdViewMain.cpp : 实现文件
//

#include "stdafx.h"
#include "XscdViewMain.h"


// CXscdViewMain

IMPLEMENT_DYNCREATE(CXscdViewMain, CScrollView)

CXscdViewMain::CXscdViewMain()
{
	m_pIecCfgDatasMngr = NULL;
}

CXscdViewMain::~CXscdViewMain()
{
}

void CXscdViewMain::ViewToWindow(CPoint &point)
{
	CPoint pt = GetScrollPosition();
	point -= pt;
}

void CXscdViewMain::WindowToView(CPoint &point)
{
	CPoint pt = GetScrollPosition();
	point += pt;
}

void CXscdViewMain::ViewToWindow(CRect &rect)
{
	CPoint pt = GetScrollPosition();
	rect.OffsetRect(-pt.x, -pt.y);
}

void CXscdViewMain::WindowToView(CRect &rect)
{
	CPoint pt = GetScrollPosition();
	rect.OffsetRect(pt.x, pt.y);
}

BEGIN_MESSAGE_MAP(CXscdViewMain, CScrollView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_WM_VSCROLL()

	ON_MESSAGE(WM_SETFONT, OnSetFont)
	ON_MESSAGE(WM_GETFONT, OnGetFont)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()

	ON_MESSAGE(WM_XSCDDRAW_DATACHANGED, OnXScdDrawChanged)
END_MESSAGE_MAP()


// CXscdViewMain 绘图
void CXscdViewMain::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}


BOOL CXscdViewMain::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CXscdViewMain::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CXscdViewMain::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CXscdViewMain::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	
	if (m_oMemDC->IsSizeChanged())
	{
		CRect rc(0, 0, m_oXScdDrawViewCfg.m_nWidth, m_oXScdDrawViewCfg.m_nHeight);
		m_oMemDC->Create(pDC, rc);
		CDC *pMemDC = m_oMemDC->GetDC();
		m_oMemDC->FillSolidRect(RGB(255, 255, 255));

		if (m_pIecCfgDatasMngr != NULL)
		{
			m_oXScdDrawViewCfg.Draw(pMemDC, 1, CPoint(0, 0));
		}
	}
	
	
	m_oMemDC->Draw(pDC);
	m_oXScdDrawViewCfg.DrawActiveElement(pDC, 1, CPoint(0, 0));
}

BOOL CXscdViewMain::OnEraseBkgnd(CDC* pDC)
{
	return CScrollView::OnEraseBkgnd(pDC);
}


// CXscdViewMain 诊断

#ifdef _DEBUG
void CXscdViewMain::AssertValid() const
{
	CScrollView::AssertValid();
}

#ifndef _WIN32_WCE
void CXscdViewMain::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif
#endif //_DEBUG


// CXscdViewMain 消息处理程序

int CXscdViewMain::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;

	return 0;
}

void CXscdViewMain::OnSize(UINT nType, int cx, int cy)
{
	CScrollView::OnSize(nType, cx, cy);


}

void CXscdViewMain::PostNcDestroy()
{

	CScrollView::PostNcDestroy();
}

void CXscdViewMain::OnDestroy()
{
	
	CScrollView::OnDestroy();
}

void CXscdViewMain::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	m_pIecCfgDatasMngr = NULL;
	CIecCfgFile *pIecfgFile = (CIecCfgFile*)lHint;

	if (pIecfgFile == NULL)
	{
		return;
	}

	m_pIecCfgDatasMngr = pIecfgFile->m_pIecCfgDatasMngr;
	m_oXScdDrawViewCfg.XCreateElement(m_pIecCfgDatasMngr, this);
	m_oXScdDrawViewCfg.AttachViewWindow(this);
	
	CSize sizeTotal;
	
	sizeTotal.cx = m_oXScdDrawViewCfg.m_nWidth;
	sizeTotal.cy = m_oXScdDrawViewCfg.m_nHeight;

	SetScrollSizes(MM_TEXT, sizeTotal); 
	m_oMemDC->SetSizeChanged();
	SetFont(g_pGlobalFont11);
}


void CXscdViewMain::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CRect rc;
	GetClientRect(rc);

	SCROLLINFO scrollInfo; 
	GetScrollInfo(SB_VERT,   &scrollInfo,   SIF_ALL); 
	switch   (nSBCode) 
	{ 
	case   SB_LINEUP: 
		scrollInfo.nPos -= 1; 
		if   (scrollInfo.nPos   <   scrollInfo.nMin) 
		{ 
			scrollInfo.nPos =   scrollInfo.nMin; 
			break; 
		} 
		SetScrollInfo(SB_VERT,   &scrollInfo,   SIF_ALL); 
		ScrollWindow(0,   1); 
		break; 
	case   SB_LINEDOWN: 
		scrollInfo.nPos += 1; 
		if   (scrollInfo.nPos + rc.Height()   >   scrollInfo.nMax) 
		{ 
			scrollInfo.nPos =   scrollInfo.nMax; 
			break; 
		} 
		SetScrollInfo(SB_VERT,   &scrollInfo,   SIF_ALL); 
		ScrollWindow(0,   -1); 
		break; 
	case   SB_TOP   : 
		ScrollWindow((scrollInfo.nPos   -   scrollInfo.nMin),   0); 
		scrollInfo.nPos =   scrollInfo.nMin; 
		SetScrollInfo(SB_VERT,   &scrollInfo,   SIF_ALL); 
		break; 
	case   SB_BOTTOM: 
		ScrollWindow(-(scrollInfo.nMax   -   scrollInfo.nPos),   0); 
		scrollInfo.nPos =   scrollInfo.nMax; 
		SetScrollInfo(SB_VERT,   &scrollInfo,   SIF_ALL); 
		break; 
	case   SB_PAGEUP: 
		scrollInfo.nPos -= 5; 
		if   (scrollInfo.nPos   <   scrollInfo.nMin) 
		{ 
			scrollInfo.nPos =   scrollInfo.nMin; 
			break; 
		} 
		SetScrollInfo(SB_VERT,&scrollInfo,SIF_ALL); 
		ScrollWindow(0,   5); 
		break; 
	case   SB_PAGEDOWN: 
		scrollInfo.nPos += 5; 
		if   (scrollInfo.nPos   >   scrollInfo.nMax) 
		{ 
			scrollInfo.nPos =   scrollInfo.nMax; 
			break; 
		} 
		SetScrollInfo(SB_VERT,   &scrollInfo,   SIF_ALL); 
		ScrollWindow(0,   -5); 
		break; 
	case   SB_ENDSCROLL: 
		break; 
	case   SB_THUMBPOSITION: 
		break; 
	case   SB_THUMBTRACK: 
		ScrollWindow(0,   (scrollInfo.nPos   -   nPos)); 
		scrollInfo.nPos =   nPos; 
		SetScrollInfo(SB_VERT,   &scrollInfo,   SIF_ALL); 
		break; 
	} 

	CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CXscdViewMain::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	SetFont(g_pGlobalFont14);
}

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

void CXscdViewMain::OnLButtonUp(UINT nFlags, CPoint point)
{
	CScrollView::OnLButtonUp(nFlags, point);

	CPoint pt = GetScrollPosition();
	point += pt;
	m_oXScdDrawViewCfg.UI_OnLButtonUp(nFlags, point);
}

void CXscdViewMain::OnLButtonDown(UINT nFlags, CPoint point)
{
	CPoint pt = GetScrollPosition();
	point += pt;

	m_oXScdDrawViewCfg.UI_OnLButtonDown(nFlags, point);
}

void CXscdViewMain::OnMouseMove(UINT nFlags, CPoint point)
{
	CPoint pt = GetScrollPosition();
	point += pt;

	m_oXScdDrawViewCfg.UI_OnMouseMove(nFlags, point);
}

void CXscdViewMain::OnTimer(UINT nIDEvent)
{
	m_oXScdDrawViewCfg.UI_OnTimer(nIDEvent);
}

void CXscdViewMain::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if (m_oXScdDrawViewCfg.UI_OnKeyDown(nChar, nRepCnt, nFlags))
	{

	}

	CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
}

// Instant editing of cells when keys are pressed
void CXscdViewMain::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if (m_oXScdDrawViewCfg.UI_OnChar(nChar, nRepCnt, nFlags))
	{
		return;
	}

	CScrollView::OnChar(nChar, nRepCnt, nFlags);
}

void CXscdViewMain::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	m_oXScdDrawViewCfg.UI_OnLButtonDblClk(nFlags, point);

	CScrollView::OnLButtonDblClk(nFlags, point);
}


void CXscdViewMain::OnRButtonDblClk(UINT nFlags, CPoint point) 
{
	m_oXScdDrawViewCfg.UI_OnRButtonDblClk(nFlags, point);

	CScrollView::OnRButtonDblClk(nFlags, point);
}


void CXscdViewMain::OnKillFocus(CWnd* pNewWnd) 
{
	CScrollView::OnKillFocus(pNewWnd);

	m_oXScdDrawViewCfg.UI_OnKillFocus(pNewWnd);
}

void CXscdViewMain::OnRButtonDown(UINT nFlags, CPoint point)
{
	m_oXScdDrawViewCfg.UI_OnRButtonDown(nFlags, point);

	//CScrollView::OnRButtonDown(nFlags, point);
}

void CXscdViewMain::OnRButtonUp(UINT nFlags, CPoint point)
{
	m_oXScdDrawViewCfg.UI_OnRButtonUp(nFlags, point);
}


LRESULT CXscdViewMain::OnSetFont(WPARAM hFont, LPARAM lParam)
{
	LRESULT result = Default();

	m_oXScdDrawViewCfg.UI_OnSetFont(hFont, lParam);
	return result;
}

LRESULT CXscdViewMain::OnGetFont(WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	return (LRESULT) (HFONT) m_oXScdDrawViewCfg.UI_OnGetFont(0, 0);//m_Font;
}

LRESULT CXscdViewMain::OnXScdDrawChanged(WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	if (m_pIecCfgDatasMngr != NULL)
	{
		CDC *pMemDC = m_oMemDC->GetDC();
		m_oMemDC->FillSolidRect(RGB(255, 255, 255));
		m_oXScdDrawViewCfg.Draw(pMemDC, 1, CPoint(0, 0));
	}

	return 0;
}
