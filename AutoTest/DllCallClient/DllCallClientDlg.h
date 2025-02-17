
// DllCallClientDlg.h : 头文件
//

#pragma once

#include "..\Module\GuideBook\DllCall.h"
#include "..\..\Module\BaseClass\ExBaseListComboBox.h"
#include "..\Module\DllCallInterface\DllCallInterface.h"
#include "afxwin.h"

// CDllCallClientDlg 对话框
class CDllCallClientDlg : public CDialog
{
public:
	CDllCall *m_pDllCall;
	CDllCallInterface m_oDllCallInterface;

	void EnableDllCallButton();
	void UpdateDlg();
	BOOL CreateEx(CWnd* pParent,CExBaseObject* pNode);
	BOOL Save();

	BOOL m_bGBModified;
	void EnableAllButtons();
	void UpdateParaWnds(BOOL bUpdatePath);
	BOOL ValidateDllFile(CString &strDllFilePath);
	void 	UpdateByDllfile();
	BOOL ValidateParaFile(CString &strParaFilePath);

// 构造
public:
	CDllCallClientDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DLLCALLCLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	CExBaseListComboBox m_cmbParaType;
	CString m_strParaData;
	CEdit m_edtParaData;
	afx_msg void OnCbnSelchangeParatype();
	afx_msg void OnBnClickedBtnBrowseResultFile();
	afx_msg void OnBnClickedBtnBrowseParaFile();
	CString m_strResultFile;
	CString m_strDllFile;
	afx_msg void OnEnChangeDllfile();
	CString m_strDllPath;
	CComboBox m_cmbDllFunc;
	CEdit m_edtResultFile;
	afx_msg void OnEnChangeResultfile();
	afx_msg void OnEnChangeParadata();
	CStatic m_stcParaDataTitle;

	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
	virtual void OnCancel();
public:
	afx_msg void OnBnClickedBtnCall();
	CButton m_btnDllCall;
	afx_msg void OnCbnSelchangeCmbDllfunc();
	afx_msg void OnCbnEditchangeCmbDllfunc();
	afx_msg void OnCbnCloseupCmbDllfunc();
};
