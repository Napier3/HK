#pragma once

#include "CharElmentBaseDlg.h"

// CCharElementInvIECDlg �Ի���

class CCharElementInvIECDlg : public CDialog , public CCharElmentBaseDlg
{
	DECLARE_DYNAMIC(CCharElementInvIECDlg)

public:
	CCharElementInvIECDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCharElementInvIECDlg();

	virtual void CreateDlg(CWnd *pParent) ; 
	virtual void GetData(); 
	virtual void ShowData(); 	
	virtual BOOL IsEnable();

// �Ի�������
	enum { IDD = IDD_DIALOG_INV_IEC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strTp;
	CString m_strK;
	CString m_strAlpha;
};
