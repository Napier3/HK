
// DsvTestView.cpp : CDsvTestView 类的实现
//

#include "stdafx.h"
#include "DsvTest.h"

#include "DsvTestDoc.h"
#include "DsvTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDsvTestView

IMPLEMENT_DYNCREATE(CDsvTestView, CView)

BEGIN_MESSAGE_MAP(CDsvTestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDsvTestView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDsvTestView 构造/析构

CDsvTestView::CDsvTestView()
{
	// TODO: 在此处添加构造代码

}

CDsvTestView::~CDsvTestView()
{
}

BOOL CDsvTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDsvTestView 绘制

void CDsvTestView::OnDraw(CDC* /*pDC*/)
{
	CDsvTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDsvTestView 打印


void CDsvTestView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CDsvTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDsvTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDsvTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CDsvTestView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDsvTestView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CDsvTestView 诊断

#ifdef _DEBUG
void CDsvTestView::AssertValid() const
{
	CView::AssertValid();
}

void CDsvTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDsvTestDoc* CDsvTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDsvTestDoc)));
	return (CDsvTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CDsvTestView 消息处理程序
