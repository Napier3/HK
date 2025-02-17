#pragma once

#include "CharElmentBaseDlg.h"

#include "..\Module\Characteristic\CharElementLine.h"
#include "..\..\Module\BaseClass\ExBaseListComboBox.h"

// CCharElementLineDlg �Ի���

class CCharElementLineDlg : public CDialog , public CCharElmentBaseDlg
{
	DECLARE_DYNAMIC(CCharElementLineDlg)

public:
	CCharElementLineDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCharElementLineDlg();

	virtual void CreateDlg(CWnd *pParent) ; 
	virtual void GetData(); 
	virtual void ShowData(); 	
	virtual BOOL IsEnable();

// �Ի�������
	enum { IDD = IDD_DIALOG_LINE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strXb;
	CString m_strYb;
	CString m_strAngle;
	CExBaseListComboBox m_cmbDir;
};
