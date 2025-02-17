// CharElementInvIEEEDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CharLibDev.h"
#include "CharElementInvIEEEDlg.h"


// CCharElementInvIEEEDlg �Ի���

IMPLEMENT_DYNAMIC(CCharElementInvIEEEDlg, CDialog)

CCharElementInvIEEEDlg::CCharElementInvIEEEDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCharElementInvIEEEDlg::IDD, pParent)
	, m_strTP(_T(""))
	, m_strA(_T(""))
	, m_strB(_T(""))
	, m_strP(_T(""))
	, m_strQ(_T(""))
	, m_strK1(_T(""))
	, m_strK2(_T(""))
{

}

CCharElementInvIEEEDlg::~CCharElementInvIEEEDlg()
{
}

void CCharElementInvIEEEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_IEEE_TP, m_strTP);
	DDX_Text(pDX, IDC_IEEE_A, m_strA);
	DDX_Text(pDX, IDC_IEEE_B, m_strB);
	DDX_Text(pDX, IDC_IEEE_P, m_strP);
	DDX_Text(pDX, IDC_IEEE_Q, m_strQ);
	DDX_Text(pDX, IDC_IEEE_K1, m_strK1);
	DDX_Text(pDX, IDC_IEEE_K2, m_strK2);
}


BEGIN_MESSAGE_MAP(CCharElementInvIEEEDlg, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CCharElementInvIEEEDlg ��Ϣ�������
BOOL CCharElementInvIEEEDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	if( m_bmp.m_hObject != NULL )//�ж�
		m_bmp.DeleteObject();
	/////////����ͼƬ
	HBITMAP hbmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), 
		_T("res/IEEE.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION|LR_LOADFROMFILE);
	if( hbmp == NULL ) 
	{
		return FALSE;
	}
	///////////////////////�öϳ�������ȡ�ü��ص�BMP����Ϣ////////////////////////
	m_bmp.Attach( hbmp );
	DIBSECTION ds;
	BITMAPINFOHEADER &bminfo = ds.dsBmih; 
	m_bmp.GetObject( sizeof(ds), &ds );
	int cx=bminfo.biWidth;  //�õ�ͼ����
	int cy=bminfo.biHeight; //�õ�ͼ��߶�
	/////////////////// ////////////////////////////////
	/////////////�õ���ͼ��Ŀ�Ⱥ͸߶Ⱥ�,���ǾͿ��Զ�ͼ���С������Ӧ,�������ؼ��Ĵ�С,����������ʾһ��ͼƬ///////////////////////////
	CRect rect;
	GetDlgItem(IDC_IEEE_PIC)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	GetDlgItem(IDC_IEEE_PIC)->MoveWindow(rect.left,rect.top,cx,cy,true);//������С
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CCharElementInvIEEEDlg::CreateDlg(CWnd *pParent)
{	
	Create(IDD, pParent);
	m_pDialog = this;
}

void CCharElementInvIEEEDlg::ShowData()
{
	CCharElementIEEE * pCharData= (CCharElementIEEE *) m_pCharElementBase;

	m_strTP = pCharData->m_strTp;
	m_strA = pCharData->m_strA;
	m_strB = pCharData->m_strB;
	m_strP = pCharData->m_strP;
	m_strQ = pCharData->m_strQ;
	m_strK1 = pCharData->m_strK1;
	m_strK2 = pCharData->m_strK2;

	UpdateData(FALSE);
}

void CCharElementInvIEEEDlg::GetData()
{
	CCharElementIEEE * pCharData= (CCharElementIEEE *) m_pCharElementBase;

	UpdateData(TRUE);

	pCharData->m_strTp = m_strTP;
	pCharData->m_strA = m_strA;
	pCharData->m_strB = m_strB;
	pCharData->m_strP = m_strP;
	pCharData->m_strQ = m_strQ;
	pCharData->m_strK1 = m_strK1;
	pCharData->m_strK2 = m_strK2;
}

BOOL CCharElementInvIEEEDlg::IsEnable()
{
	if (m_strTP.IsEmpty())
	{
		return FALSE;
	}

	if (m_strA.IsEmpty())
	{
		return FALSE;
	}

	if (m_strB.IsEmpty())
	{
		return FALSE;
	}

	if (m_strP.IsEmpty())
	{
		return FALSE;
	}

	if (m_strQ.IsEmpty())
	{
		return FALSE;
	}

	if (m_strK1.IsEmpty())
	{
		return FALSE;
	}

	if (m_strK2.IsEmpty())
	{
		return FALSE;
	}

	return TRUE;
}

void CCharElementInvIEEEDlg::OnPaint() 
{
	//////////////�������������ѡһ�ֻ��ǲ�ͬЧ��(ֻ��һ�ִ���)///////////
	//CPaintDC dc(this);      //���ô˾�,�õ����ǶԻ����DC,ͼƬ���������ڶԻ�����.
	CPaintDC dc(GetDlgItem(IDC_IEEE_PIC)); //�ô˾�,�õ�picture�ؼ���DC,ͼ�񽫱������ڿؼ���  
	//  CDC dc;
	//  dc.m_hDC=::GetDC(NULL);  //���ô�����,�õ�������Ļ��DC,ͼƬ������������Ļ��///////////////////////////////////////////////////////
	CRect rcclient;
	GetDlgItem(IDC_IEEE_PIC)->GetClientRect(&rcclient);
	CDC memdc;
	memdc.CreateCompatibleDC(&dc);  
	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(&dc, rcclient.Width(), rcclient.Height());
	memdc.SelectObject( &bitmap );
	CWnd::DefWindowProc(WM_PAINT, (WPARAM)memdc.m_hDC , 0);
	CDC maskdc;
	maskdc.CreateCompatibleDC(&dc);
	CBitmap maskbitmap;
	maskbitmap.CreateBitmap(rcclient.Width(), rcclient.Height(), 1, 1, NULL);
	maskdc.SelectObject( &maskbitmap );
	maskdc.BitBlt( 0, 0, rcclient.Width(), rcclient.Height(), &memdc, 
		rcclient.left, rcclient.top, SRCCOPY);
	CBrush brush;
	brush.CreatePatternBrush(&m_bmp);
	dc.FillRect(rcclient, &brush);  
	dc.BitBlt(rcclient.left, rcclient.top, rcclient.Width(), rcclient.Height(), 
		&memdc, rcclient.left, rcclient.top,SRCPAINT);
	brush.DeleteObject();
	// Do not call CDialog::OnPaint() for painting messages
}
