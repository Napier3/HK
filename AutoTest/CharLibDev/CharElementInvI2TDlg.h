#pragma once

#include "CharElmentBaseDlg.h"

// CCharElementInvI2TDlg �Ի���

class CCharElementInvI2TDlg : public CDialog , public CCharElmentBaseDlg
{
	DECLARE_DYNAMIC(CCharElementInvI2TDlg)

public:
	CCharElementInvI2TDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCharElementInvI2TDlg();

	virtual void CreateDlg(CWnd *pParent) ; 
	virtual void GetData(); 
	virtual void ShowData(); 	
	virtual BOOL IsEnable();

// �Ի�������
	enum { IDD = IDD_DIALOG_INV_I2T };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strTp;
	CString m_strA;
};
