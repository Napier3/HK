
// DsvTestDoc.cpp : CDsvTestDoc ���ʵ��
//

#include "stdafx.h"
#include "DsvTest.h"

#include "DsvTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDsvTestDoc

IMPLEMENT_DYNCREATE(CDsvTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CDsvTestDoc, CDocument)
END_MESSAGE_MAP()


// CDsvTestDoc ����/����

CDsvTestDoc::CDsvTestDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CDsvTestDoc::~CDsvTestDoc()
{
}

BOOL CDsvTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CDsvTestDoc ���л�

void CDsvTestDoc::Serialize(CArchive& ar)
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


// CDsvTestDoc ���

#ifdef _DEBUG
void CDsvTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDsvTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDsvTestDoc ����
