// DsvTestFormView.cpp : 实现文件
//

#include "stdafx.h"
#include "DsvTest.h"
#include "DsvTestFormView.h"


// CDsvTestFormView

IMPLEMENT_DYNCREATE(CDsvTestFormView, CFormView)

CDsvTestFormView::CDsvTestFormView()
	: CFormView(CDsvTestFormView::IDD)
	, m_strMore(_T(""))
	, m_strMiss(_T(""))
	, m_strAll(_T(""))
	, m_strMatch(_T(""))
{
	theApp.m_pDsvTestFormView = this;
}

CDsvTestFormView::~CDsvTestFormView()
{
}

void CDsvTestFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GRID_DSVELEMENT, m_gridDsvElement);
	DDX_Control(pDX, IDC_GRID_DSVELEMATTR, m_gridDsvElemAttr);
	DDX_Text(pDX, IDC_EDIT_MORE, m_strMore);
	DDX_Text(pDX, IDC_EDIT_MISS, m_strMiss);
	DDX_Text(pDX, IDC_EDIT_ALL, m_strAll);
	DDX_Text(pDX, IDC_EDIT_MATCH, m_strMatch);
}

BEGIN_MESSAGE_MAP(CDsvTestFormView, CFormView)
END_MESSAGE_MAP()


// CDsvTestFormView 诊断

#ifdef _DEBUG
void CDsvTestFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDsvTestFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDsvTestFormView 消息处理程序

void CDsvTestFormView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	m_gridDsvElement.InitGrid();
	m_gridDsvElemAttr.InitGrid();

	m_gridDsvElement.ShowDatas(&theApp.m_oDsvScript);
	m_gridDsvElement.SetDsvScriptAttrEditGrid(&m_gridDsvElemAttr);
}

void CDsvTestFormView::ShowDsvResult()
{
	theApp.m_oDsvScript.GetDsv_All(m_strAll, 1);
	theApp.m_oDsvScript.GetDsv_All_More(m_strMore, 1);
	theApp.m_oDsvScript.GetDsv_All_Miss(m_strMiss, 1);
	theApp.m_oDsvScript.GetDsv_All_Match(m_strMatch, 1);

	UpdateData(FALSE);
}

