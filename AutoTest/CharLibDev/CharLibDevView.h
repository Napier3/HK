// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// ("Fluent UI")����ʾ������Ϊ�ο������ṩ�� 
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://msdn.microsoft.com/officeui��
//
// ��Ȩ���� (C) Microsoft Corporation
// ��������Ȩ����

// CharLibDevView.h : CCharLibDevView ��Ľӿ�
//


#pragma once

#include "..\Module\Characteristic\CharacterDrawWnd.h"
#include "..\module\characteristic\characterdrawwnd.h"
#include "..\Module\Characteristic\GridCharInterface.h"
#include "..\module\characteristic\gridcharelement.h"
#include "..\module\characteristic\gridcharmacrotest.h"
#include "..\Module\Characteristic\GridCharTestLine.h"
#include "..\..\module\xlanguage\xlanguagetextwnd.h"
#include "..\..\Module\XLanguage\XLanguageButton.h"
class CCharLibDevView : public CFormView, public CExBaseListGridOptrInterface
{
protected: // �������л�����
	CCharLibDevView();
	DECLARE_DYNCREATE(CCharLibDevView)

	CRect m_rcCtrls[12];
	void InitCtrlsPos();
	void AdjustCtrlsPos(long cx, long cy);

	void EnableCharInterfaceButtons();
	void EnableCharElementButtons();

	BOOL OnEditCellLBDblClk_CharElement(int nRow, int nCol, UINT nChar);
	void ShowCharElementTestLines();

	enum{ IDD = IDD_CHARLIBDEV_FORM };
public:
	virtual void OnDataSelChanged(CXGridCtrlBase *pGridCtrl, int nRow, int nCol);
	virtual BOOL OnEditCellLBDblClk(CXGridCtrlBase *pGridCtrl, int nRow, int nCol, UINT nChar);
	virtual void OnDataEditChanged(CXGridCtrlBase *pGridCtrl, int nRow, int nCol);

	void xlang_InitAndAdjust(); 

// ����
public:
	CCharLibDevDoc* GetDocument() const;
	//2020-3-13  lijq  ȥ��CCharacteristicTmplate
	//CCharacteristicTmplate *m_pCharacteristicTmplate;
	CCharacteristic *m_pCharacteristic;
	void ShowCharacteristicTmplate();

	//����
	CCharInterface *m_pCharInterface;
	CCharacterArea *m_pCharacterArea;


// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CCharLibDevView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CCharacterDrawWnd m_stcCharDraw;
	CGridCharInterface m_gridCharInterface;
	CGridCharElementDev m_gridCharElement;
	CGridCharTestLine m_gridCharElementTestLine;
	CXLanguageButton m_btnNewVariable;
	CXLanguageButton m_btnDeleteVariable;
	CXLanguageButton m_btnNewElement;
	CXLanguageButton m_btnDeleteElement;
	CXLanguageButton m_btnMoveUp;
	CXLanguageButton m_btnMoveDown;
	afx_msg void OnBnClickedBtnNewVariable();
	afx_msg void OnBnClickedBtnDeleteVariable();
	afx_msg void OnBnClickedBtnNewElement();
	afx_msg void OnBnClickedBtnDelete();
	afx_msg void OnBnClickedBtnMoveup();
	afx_msg void OnBnClickedBtnMoveDown();
	afx_msg void OnSize(UINT nType, int cx, int cy);
protected:
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};

#ifndef _DEBUG  // CharLibDevView.cpp �еĵ��԰汾
inline CCharLibDevDoc* CCharLibDevView::GetDocument() const
   { return reinterpret_cast<CCharLibDevDoc*>(m_pDocument); }
#endif

