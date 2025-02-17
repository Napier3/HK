#pragma once

#include "..\IecCfgTool\IecCfgFile.h"
#include "XScdDrawViewCfg.h"
#include "..\..\..\Module\BaseClass\MemBufferDC.H"
// CXscdViewMain 视图

class CXscdViewMain : public CScrollView , public CXDrawBaseInterface_ViewWindow
{
protected:
	DECLARE_DYNCREATE(CXscdViewMain)

//////////////////////////////////////////////////////////////////////////
//CXDrawBaseInterface_ViewWindow
public:
	virtual void ViewToWindow(CPoint &point);
	virtual void WindowToView(CPoint &point);

	virtual void ViewToWindow(CRect &rect);
	virtual void WindowToView(CRect &rect);

protected:
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
	CXScdDrawViewCfg m_oXScdDrawViewCfg;
	CIecCfgDatasMngr *m_pIecCfgDatasMngr;

	CMemBufferDC m_oMemDC;

protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

public:
	CXscdViewMain();           // 动态创建所使用的受保护的构造函数
	virtual ~CXscdViewMain();
	void SetRefDoc(CDocument *pDoc)	{	m_pDocument = pDoc;	}

public:
	virtual void OnDraw(CDC* pDC);      // 重写以绘制该视图
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
protected:
	afx_msg void OnFilePrintPreview();
	virtual void PostNcDestroy();
public:
	//afx_msg void OnPaint();
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual void OnInitialUpdate();

	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);

	afx_msg LRESULT OnSetFont(WPARAM hFont, LPARAM lParam);
	afx_msg LRESULT OnGetFont(WPARAM hFont, LPARAM lParam);
	afx_msg LRESULT OnXScdDrawChanged(WPARAM hFont, LPARAM lParam);

};


