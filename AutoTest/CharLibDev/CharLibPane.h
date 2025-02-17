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

#pragma once
#include "..\..\Module\XLanguage\XLangToolBar.h"
#include "..\Module\Characteristic\CharLibTreeCtrl.h"

class CClassToolBar : public CXLangToolBar
{
	virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler)
	{
		CMFCToolBar::OnUpdateCmdUI((CFrameWnd*) GetOwner(), bDisableIfNoHndler);
	}

	virtual BOOL AllowShowOnList() const { return FALSE; }
};

#define IDC_CHARLIB_REECTRL    6932
class CCharLibPane : public CDockablePane
{
public:
	CCharLibPane();
	virtual ~CCharLibPane();

	void AdjustLayout();
	void OnChangeVisualStyle();

	void ShowCharLib();
	void InsertCharTemp(CCharacteristic *pCharTemp);
	void UpdateCharTemp(CCharacteristic *pCharTemp);
	CCharacterFolder* GetCurrSelFolder();

protected:
	CClassToolBar m_wndToolBar;
	CCharLibTreeCtrl m_wndCharLibView;
	CImageList m_CharLibViewImages;
	UINT m_nCurrSort;

// ��д
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnClassAddMemberFunction();
	afx_msg void OnClassAddMemberVariable();
	afx_msg void OnClassDefinition();
	afx_msg void OnClassProperties();
	afx_msg void OnNewFolder();
	afx_msg void OnEditFolder();
	afx_msg void OnUpdateEditFolder(CCmdUI* pCmdUI);
	afx_msg void OnDeleteFolder();
	afx_msg void OnUpdateDeleteFolder(CCmdUI* pCmdUI);
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg LRESULT OnChangeActiveTab(WPARAM, LPARAM);
	afx_msg void OnSort(UINT id);
	afx_msg void OnUpdateSort(CCmdUI* pCmdUI);
	afx_msg void OnNMDblclkCharLibTree(NMHDR *pNMHDR, LRESULT *pResult);

	DECLARE_MESSAGE_MAP()
};

