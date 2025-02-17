#pragma once

#include "CharElmentBaseDlg.h"
#include "InvOwnDefGrid.h"
#include "../Module/Characteristic/CharElementTestPoint.h"
#include "afxwin.h"

// CCharElementInvOwnDefDlg �Ի���

class CCharElementInvOwnDefDlg : public CDialog , public CCharElmentBaseDlg, public CExBaseListGridOptrInterface
{
	DECLARE_DYNAMIC(CCharElementInvOwnDefDlg)

public:
	CCharElementInvOwnDefDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCharElementInvOwnDefDlg();

	virtual void CreateDlg(CWnd *pParent) ; 
	virtual void GetData(); 
	virtual void ShowData(); 	
	virtual BOOL IsEnable();

// �Ի�������
	enum { IDD = IDD_DIALOG_INV_OWNDEF };

public:
	CInvOwnDefGrid m_gridInvOwnDef;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnDataSelChanged(CXGridCtrlBase *pGridCtrl, int nRow, int nCol);
	virtual void OnDataEditChanged(CXGridCtrlBase *pGridCtrl, int nRow, int nCol);

public:
	virtual BOOL OnInitDialog();
	void EnableButtons();

	DECLARE_MESSAGE_MAP()
public:
	CString m_strXMAX;
	CString m_strTMAX;
	CCharElementTestPoints m_oPoints; //���Ե㼯��

	CButton m_btnInvOwnDefDel;
	CButton m_btnInvOwnDefDelAll;
	CButton m_btnInvOwnDefAddPrev;
	CButton m_btnInvOwnDefAddAfter;

public:
	afx_msg void OnBnClickedInvowndefAddpoint();
	afx_msg void OnBnClickedInvowndefDelpoint();
	afx_msg void OnBnClickedInvowndefDelallpoint();
	afx_msg void OnBnClickedInvowndefAddpointhead();
	afx_msg void OnBnClickedInvowndefAddpointprev();
	afx_msg void OnBnClickedInvowndefAddpointafter();
};
