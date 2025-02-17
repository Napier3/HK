#pragma once

#include "..\Module\XrioRead\XrioTextFileToAtsCharTool.h"
#include "afxcmn.h"
#include "afxwin.h"

// CDlgImportCharFromRioFile �Ի���

class CDlgImportCharFromRioFile : public CDialog
{
	DECLARE_DYNAMIC(CDlgImportCharFromRioFile)

public:
	CDlgImportCharFromRioFile(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgImportCharFromRioFile();

	CXrioTextFile m_oXrioTextFile;
	CCharacteristic *m_pCharacteristic;
	void EnableOK();
	CXrioGroup* GetSelGroup();

// �Ի�������
	enum { IDD = IDD_DIALOG_IMPORT_FROM_RIO_FILE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonBrowse();
	CTreeCtrl m_treeXrio;
protected:
	virtual void OnOK();
	virtual void OnCancel();
public:
	CButton m_btnOK;
	CString m_strXrioFile;
	afx_msg void OnTvnSelchangedTreeRioFile(NMHDR *pNMHDR, LRESULT *pResult);
};
