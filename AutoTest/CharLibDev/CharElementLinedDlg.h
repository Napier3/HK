#pragma once
#include "afxwin.h"
#include "CharElmentBaseDlg.h"

#include "..\Module\Characteristic\CharElementLined.h"
#include "..\..\Module\BaseClass\ExBaseListComboBox.h"

// CCharElementLinedDlg �Ի���

class CCharElementLinedDlg : public CDialog , public CCharElmentBaseDlg
{
	DECLARE_DYNAMIC(CCharElementLinedDlg)

public:
	CCharElementLinedDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCharElementLinedDlg();

	virtual void CreateDlg(CWnd *pParent) ; 
	virtual void GetData(); 
	virtual void ShowData(); 	
	virtual BOOL IsEnable();

// �Ի�������
	enum { IDD = IDD_DIALOG_LINED };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strXb;
	CString m_strYb;
	CString m_strXe;
	CString m_strYe;
	CExBaseListComboBox m_cmbDir;
};
