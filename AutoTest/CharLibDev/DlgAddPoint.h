#pragma once
#include "afxwin.h"
#include "resource.h"
#include "../Module/Characteristic/CharElementTestPoint.h"

// CDlgAddPoint �Ի���

class CDlgAddPoint : public CDialog
{
	DECLARE_DYNAMIC(CDlgAddPoint)

public:
	CDlgAddPoint(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgAddPoint();

// �Ի�������
	enum { IDD = IDD_IOWNDEF_ADDPOINT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
protected:
	virtual void OnOK();
public:
	CString m_strX;
	CString m_strY;
	CCharElementTestPoint *m_pPoint;
};
