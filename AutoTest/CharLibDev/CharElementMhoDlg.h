#pragma once
#include "afxwin.h"
#include "CharElmentBaseDlg.h"

#include "..\Module\Characteristic\CharElementMho.h"

// CCharElementMhoDlg �Ի���

class CCharElementMhoDlg : public CDialog , public CCharElmentBaseDlg
{
	DECLARE_DYNAMIC(CCharElementMhoDlg)

public:
	CCharElementMhoDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCharElementMhoDlg();

	virtual void CreateDlg(CWnd *pParent) ; 
	virtual void GetData(); 
	virtual void ShowData(); 	
	virtual BOOL IsEnable();

// �Ի�������
	enum { IDD = IDD_DIALOG_MHO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strForwardReach;
	CString m_strAngle;
	CString m_strOffset;
};
