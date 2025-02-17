#pragma once
#include "afxwin.h"
#include "CharElmentBaseDlg.h"

#include "..\Module\Characteristic\CharElementLiner.h"
#include "..\..\Module\BaseClass\ExBaseListComboBox.h"

// CCharElementLinerDlg �Ի���

class CCharElementLinerDlg : public CDialog , public CCharElmentBaseDlg
{
	DECLARE_DYNAMIC(CCharElementLinerDlg)

public:
	CCharElementLinerDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCharElementLinerDlg();

	virtual void CreateDlg(CWnd *pParent) ; 
	virtual void GetData(); 
	virtual void ShowData(); 	
	virtual BOOL IsEnable();

// �Ի�������
	enum { IDD = IDD_DIALOG_LINER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strXb;
	CString m_strYb;
	CString m_strAngle;
	CExBaseListComboBox m_cmbDir;
};
