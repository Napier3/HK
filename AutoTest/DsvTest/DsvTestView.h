
// DsvTestView.h : CDsvTestView 类的接口
//


#pragma once


class CDsvTestView : public CView
{
protected: // 仅从序列化创建
	CDsvTestView();
	DECLARE_DYNCREATE(CDsvTestView)

// 属性
public:
	CDsvTestDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDsvTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // DsvTestView.cpp 中的调试版本
inline CDsvTestDoc* CDsvTestView::GetDocument() const
   { return reinterpret_cast<CDsvTestDoc*>(m_pDocument); }
#endif

