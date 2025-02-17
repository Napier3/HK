
// DsvTestView.cpp : CDsvTestView ���ʵ��
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDsvTestView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDsvTestView ����/����

CDsvTestView::CDsvTestView()
{
	// TODO: �ڴ˴���ӹ������

}

CDsvTestView::~CDsvTestView()
{
}

BOOL CDsvTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDsvTestView ����

void CDsvTestView::OnDraw(CDC* /*pDC*/)
{
	CDsvTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CDsvTestView ��ӡ


void CDsvTestView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CDsvTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDsvTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDsvTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CDsvTestView ���

#ifdef _DEBUG
void CDsvTestView::AssertValid() const
{
	CView::AssertValid();
}

void CDsvTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDsvTestDoc* CDsvTestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDsvTestDoc)));
	return (CDsvTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CDsvTestView ��Ϣ�������
