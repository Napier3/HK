#pragma once
#include "afxwin.h"

#include "..\..\Module\BaseClass\ExBaseListComboBox.h"
#include "CharElementLineDlg.h"
#include "CharElementLinedDlg.h"
#include "CharElementLinerDlg.h"
#include "CharElementArcDlg.h"
#include "CharElementArcpDlg.h"
#include "CharElementMhoDlg.h"
#include "CharElementLensDlg.h"
#include "CharElementInvI2TDlg.h"
#include "CharElementInvIACDlg.h"
#include "CharElementInvIECDlg.h"
#include "CharElementInvIEEEDlg.h"
#include "CharElementInvOwnDefDlg.h"
#include "..\..\Module\Xlanguage\Xlanguagetextwnd.h"
#include "..\..\Module\XLanguage\XLanguageButton.h"

// CDlgCharElement �Ի���

class CDlgCharElement : public CDialog
{
	DECLARE_DYNAMIC(CDlgCharElement)

protected:
	void ShowElementDlg(const CString &strClassID);
	CCharElmentBaseDlg* CreateCharElementDlg(const CString &strClassID); 

	CCharElementMngrDlg m_oCharElementMngrDlg;
	CCharElmentBaseDlg *m_pElementDlgCurr;
	CRect m_rcCharElemDlg;

public:
	CDlgCharElement(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgCharElement();
	CCharElement *m_pCharElementEdit;  //��ǰ�༭��Ԫ��
	CCharElement *m_pCharElementSrcSel;  //��ǰѡ�е�Ԫ��
	CCharElement *m_pPrevCharElement;  //��ǰѡ�е�Ԫ��

	void xlang_InitAndAdjust();

// �Ի�������
	enum { IDD = IDD_DIALOG_CHAR_ELEMENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CExBaseListComboBox m_cmbElementType;
	CStatic m_wndFrmElement;
	afx_msg void OnCbnSelchangeCmbElementtype();
	virtual BOOL OnInitDialog();
protected:
	virtual void OnOK();
public:
	CString m_strErrLength;
	long m_nTestPoints;

	CXLanguageTextWnd m_wndEdgeElementType;
	CXLanguageTextWnd m_wndErrorBandLength;
	CXLanguageTextWnd m_wndEdgTestPoints;
	CXLanguageButton m_btnOK;
	CXLanguageButton m_btnCancel;
	CEdit m_edtErrorBandLength;
	CEdit m_edtEdgTestPoints;

};
