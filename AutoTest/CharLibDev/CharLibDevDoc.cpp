// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// ("Fluent UI")����ʾ������Ϊ�ο������ṩ�� 
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://msdn.microsoft.com/officeui��
//
// ��Ȩ���� (C) Microsoft Corporation
// ��������Ȩ����

// CharLibDevDoc.cpp : CCharLibDevDoc ���ʵ��
//

#include "stdafx.h"
#include "CharLibDev.h"

#include "CharLibDevDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCharLibDevDoc

IMPLEMENT_DYNCREATE(CCharLibDevDoc, CDocument)

BEGIN_MESSAGE_MAP(CCharLibDevDoc, CDocument)
END_MESSAGE_MAP()


// CCharLibDevDoc ����/����

CCharLibDevDoc::CCharLibDevDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CCharLibDevDoc::~CCharLibDevDoc()
{
}

BOOL CCharLibDevDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CCharLibDevDoc ���л�

void CCharLibDevDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CCharLibDevDoc ���

#ifdef _DEBUG
void CCharLibDevDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCharLibDevDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CCharLibDevDoc ����
