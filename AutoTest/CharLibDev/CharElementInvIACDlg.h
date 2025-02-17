#pragma once

#include "CharElmentBaseDlg.h"

// CCharElementInvIACDlg �Ի���

class CCharElementInvIACDlg : public CDialog , public CCharElmentBaseDlg
{
	DECLARE_DYNAMIC(CCharElementInvIACDlg)

public:
	CCharElementInvIACDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCharElementInvIACDlg();

	virtual BOOL OnInitDialog();
	virtual void CreateDlg(CWnd *pParent) ; 
	virtual void GetData(); 
	virtual void ShowData(); 	
	virtual BOOL IsEnable();

// �Ի�������
	enum { IDD = IDD_DIALOG_INV_IAC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnPaint();

	DECLARE_MESSAGE_MAP()

public:
	CString m_strTp;
	CString m_strA;
	CString m_strB;
	CString m_strC;
	CString m_strD;
	CString m_strE;
	CString m_strBeta;

	CBitmap  m_bmp;
};
