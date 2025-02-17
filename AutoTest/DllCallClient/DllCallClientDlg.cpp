
// DllCallClientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DllCallClient.h"
#include "DllCallClientDlg.h"

#include "..\..\..\Module\API\PEApi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CDllCallClientDlg �Ի���




CDllCallClientDlg::CDllCallClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDllCallClientDlg::IDD, pParent)
	, m_strParaData(_T(""))
	, m_strResultFile(_T(""))
	, m_strDllFile(_T(""))
	, m_strDllPath(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pDllCall = new CDllCall();
}

void CDllCallClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PARATYPE, m_cmbParaType);
	DDX_Text(pDX, IDC_PARADATA, m_strParaData);
	DDX_Control(pDX, IDC_PARADATA, m_edtParaData);
	DDX_Text(pDX, IDC_RESULTFILE, m_strResultFile);
	DDX_Text(pDX, IDC_DLLFILE, m_strDllFile);
	DDX_Text(pDX, IDC_DLL_PATH, m_strDllPath);
	DDX_Control(pDX, IDC_CMB_DLLFUNC, m_cmbDllFunc);
	DDX_Control(pDX, IDC_RESULTFILE, m_edtResultFile);
	DDX_Control(pDX, IDC_STATIC_PARATITLE, m_stcParaDataTitle);

	DDX_Control(pDX, IDC_BTN_CALL, m_btnDllCall);
}

BEGIN_MESSAGE_MAP(CDllCallClientDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_PARATYPE, &CDllCallClientDlg::OnCbnSelchangeParatype)
	ON_BN_CLICKED(IDC_BTN_BROWSE_RESULT_FILE, &CDllCallClientDlg::OnBnClickedBtnBrowseResultFile)
	ON_BN_CLICKED(IDC_BTN_BROWSE_PARA_FILE, &CDllCallClientDlg::OnBnClickedBtnBrowseParaFile)
	ON_EN_CHANGE(IDC_DLLFILE, &CDllCallClientDlg::OnEnChangeDllfile)
	ON_EN_CHANGE(IDC_RESULTFILE, &CDllCallClientDlg::OnEnChangeResultfile)
	ON_EN_CHANGE(IDC_PARADATA, &CDllCallClientDlg::OnEnChangeParadata)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_CALL, &CDllCallClientDlg::OnBnClickedBtnCall)
	ON_CBN_SELCHANGE(IDC_CMB_DLLFUNC, &CDllCallClientDlg::OnCbnSelchangeCmbDllfunc)
	ON_CBN_EDITCHANGE(IDC_CMB_DLLFUNC, &CDllCallClientDlg::OnCbnEditchangeCmbDllfunc)
	ON_CBN_CLOSEUP(IDC_CMB_DLLFUNC, &CDllCallClientDlg::OnCbnCloseupCmbDllfunc)
END_MESSAGE_MAP()


// CDllCallClientDlg ��Ϣ�������

BOOL CDllCallClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_cmbParaType.SetAddEmptyString(FALSE);
	m_cmbParaType.ShowBaseList(CGbParaTypeMngr::GetSafetyDllCallParaType());
	EnableAllButtons();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDllCallClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDllCallClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDllCallClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// CDllCallClientDlg ��Ϣ�������
void CDllCallClientDlg::EnableAllButtons()
{
	BOOL bEnableUI = TRUE;

	bEnableUI = TRUE;
	
	m_cmbDllFunc.EnableWindow(bEnableUI);
	m_cmbParaType.EnableWindow(bEnableUI);
	m_edtParaData.EnableWindow(bEnableUI);
	m_edtResultFile.EnableWindow(bEnableUI);

	UpdateParaWnds(FALSE);
}

void CDllCallClientDlg::EnableDllCallButton()
{
	BOOL bTrue = m_pDllCall->IsDllPathValid();

	if (bTrue)
	{
		if (m_pDllCall->IsParaTypeFile())
		{
			bTrue = m_pDllCall->IsParaFilePathValid();
		}
	}

	if (bTrue)
	{
		bTrue = (m_pDllCall->m_strFuncName.GetLength() > 0);
	}
	
	m_btnDllCall.EnableWindow(bTrue);
}

void CDllCallClientDlg::UpdateDlg()
{
	m_bGBModified = FALSE;

	if (m_pDllCall == NULL)
	{
		return;
	}

	CDllCall *pDllCall = m_pDllCall;
	UpdateByDllfile();

	m_cmbParaType.SetCurrSelByID(pDllCall->m_strParaType);
	m_strParaData = pDllCall->m_strParaData;
	m_strResultFile = pDllCall->m_strResultFile;
	m_strDllFile = pDllCall->m_strID;
	m_cmbDllFunc.SetWindowText(pDllCall->m_strFuncName);
	m_cmbParaType.SetCurrSelByID(pDllCall->m_strParaType);

	UpdateData(FALSE);
}

BOOL CDllCallClientDlg::CreateEx(CWnd* pParent,CExBaseObject* pNode)
{
	BOOL bRet = FALSE;
	bRet = Create(IDD,pParent);

	return bRet;
}

BOOL CDllCallClientDlg::Save()
{
	if (!m_bGBModified)
	{
		return TRUE;
	}

	UpdateData(TRUE);
	m_bGBModified = TRUE;

	CDllCall *pDllCall = m_pDllCall;
	m_cmbParaType.GetSelectID(pDllCall->m_strParaType );
	pDllCall->m_strParaData = m_strParaData;
	pDllCall->m_strResultFile = m_strResultFile;
	pDllCall->m_strID = m_strDllFile;
	m_cmbDllFunc.GetWindowText(pDllCall->m_strFuncName);

	return TRUE;
}


void CDllCallClientDlg::OnCbnSelchangeParatype()
{
	m_bGBModified = TRUE;
	CDllCall *pDllCall = m_pDllCall;
	m_cmbParaType.GetSelectID(pDllCall->m_strParaType );

	UpdateParaWnds(TRUE);
}


void CDllCallClientDlg::OnBnClickedBtnBrowseResultFile()
{

}

void CDllCallClientDlg::OnBnClickedBtnBrowseParaFile()
{

}

void CDllCallClientDlg::OnEnChangeDllfile()
{
	m_bGBModified = TRUE;
	CDllCall *pDllCall = m_pDllCall;

	UpdateData(TRUE);
	pDllCall->m_strID = m_strDllFile;

	UpdateByDllfile();
}

void CDllCallClientDlg::UpdateByDllfile()
{
	CString strDllFilePath;
	CDllCall *pDllCall = m_pDllCall;

	if (!ValidateDllFile(strDllFilePath))
	{
		m_cmbDllFunc.ResetContent();
		EnableAllButtons();
		return;
	}

	CStringArray astrFuncs;
	PE_GetDLLFileExports(strDllFilePath, astrFuncs);

	long nCount = astrFuncs.GetSize();
	long nIndex = 0;

	for (nIndex=0; nIndex<nCount; nIndex++)
	{
		m_cmbDllFunc.AddString(astrFuncs.GetAt(nIndex));
	}

	EnableAllButtons();
}

BOOL CDllCallClientDlg::ValidateDllFile(CString &strDllFilePath)
{
	CDllCall *pDllCall = m_pDllCall;

	BOOL bTrue = pDllCall->IsDllPathValid(strDllFilePath);

	if (bTrue)
	{
		m_strDllPath = strDllFilePath;
	}
	else
	{
		if (pDllCall->m_strID.GetLength() == 0)
		{
			m_strDllPath.Empty();
		}
		else
		{
			m_strDllPath.Format(_T("�����·��:%s"), strDllFilePath);
		}
	}

	UpdateData(FALSE);

	return bTrue;
}


BOOL CDllCallClientDlg::ValidateParaFile(CString &strParaFilePath)
{
	CDllCall *pDllCall = m_pDllCall;

	BOOL bTrue = pDllCall->IsParaFilePathValid(strParaFilePath);

	if (bTrue)
	{
		m_strDllPath = strParaFilePath;
	}
	else
	{
		if (pDllCall->m_strID.GetLength() == 0)
		{
			m_strDllPath.Empty();
		}
		else
		{
			m_strDllPath.Format(_T("�����·��:%s"), strParaFilePath);
		}
	}

	UpdateData(FALSE);

	return bTrue;
}


void CDllCallClientDlg::OnEnChangeResultfile()
{

}

void CDllCallClientDlg::OnEnChangeParadata()
{
	CString strParaFilePath;
	CDllCall *pDllCall = m_pDllCall;

	m_bGBModified = TRUE;
	UpdateData(TRUE);
	pDllCall->m_strParaData = m_strParaData;

	UpdateParaWnds(TRUE);
}


void CDllCallClientDlg::UpdateParaWnds(BOOL bUpdatePath)
{
	CDllCall *pDllCall = m_pDllCall;

	if (pDllCall->IsParaTypeFile())
	{
		m_stcParaDataTitle.SetWindowText(_T("�����ļ�"));
		m_edtParaData.EnableWindow(TRUE);

		CString strParaFilePath;
		BOOL bTrue = pDllCall->IsParaFilePathValid(strParaFilePath);

		if (bUpdatePath)
		{
			if (bTrue)
			{
				m_strDllPath = strParaFilePath;
			}
			else
			{
				m_strDllPath.Format(_T("�����·��:%s"), strParaFilePath);
			}
		}
	}
	else if (pDllCall->IsParaTypeText())
	{
		m_stcParaDataTitle.SetWindowText(_T("�����ı�"));
		m_edtParaData.EnableWindow(TRUE);

		if (bUpdatePath)
		{
			m_strDllPath.Empty();
		}
	}
	else
	{
		m_stcParaDataTitle.SetWindowText(_T(""));
		m_edtParaData.EnableWindow(FALSE);

		if (bUpdatePath)
		{
			m_strDllPath.Empty();
		}
	}

	UpdateData(FALSE);

	EnableDllCallButton();
}

void CDllCallClientDlg::OnOK()
{

	//CDialog::OnOK();
}

void CDllCallClientDlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���
	delete m_pDllCall;

	CDialog::OnCancel();
}

void CDllCallClientDlg::OnBnClickedBtnCall()
{
	if (!m_oDllCallInterface.CallDllFunc(m_pDllCall))
	{
		CString strMsg;
		strMsg.Format(_T("����%s::%s(\"%s\", \"%s\") ����")
			, m_pDllCall->m_strID, m_pDllCall->m_strFuncName
			, m_pDllCall->m_strParaType, m_pDllCall->m_strParaData);

		MessageBox(strMsg);
	}
}

void CDllCallClientDlg::OnCbnSelchangeCmbDllfunc()
{
	long nCurrSel = m_cmbDllFunc.GetCurSel();

	if (nCurrSel == CB_ERR)
	{
		m_pDllCall->m_strFuncName.Empty();
	}
	else
	{
		m_cmbDllFunc.GetLBText(nCurrSel, m_pDllCall->m_strFuncName);
	}

	EnableDllCallButton();
}

void CDllCallClientDlg::OnCbnEditchangeCmbDllfunc()
{
	//UpdateData(TRUE);
	m_cmbDllFunc.GetWindowText(m_pDllCall->m_strFuncName);
	EnableDllCallButton();
}

void CDllCallClientDlg::OnCbnCloseupCmbDllfunc()
{
	//OnCbnEditchangeCmbDllfunc();
}
