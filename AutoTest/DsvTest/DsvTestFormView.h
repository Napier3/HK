#pragma once


#include "..\..\Module\DataMngr\DatasetValid\DsvScriptEditGrid.h"

// CDsvTestFormView ������ͼ

class CDsvTestFormView : public CFormView
{
	DECLARE_DYNCREATE(CDsvTestFormView)

public:
	void ShowDsvResult();

protected:
	CDsvTestFormView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CDsvTestFormView();

	CDsvScriptEditGrid m_gridDsvElement;
	CDsvScriptAttrEditGrid m_gridDsvElemAttr;

public:
	enum { IDD = IDD_VIEW_DSVTEST };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	CString m_strMore;
	CString m_strMiss;
	CString m_strAll;
	CString m_strMatch;
};


