
// DsvTestDoc.cpp : CDsvTestDoc 类的实现
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


// CDsvTestDoc 构造/析构

CDsvTestDoc::CDsvTestDoc()
{
	// TODO: 在此添加一次性构造代码

}

CDsvTestDoc::~CDsvTestDoc()
{
}

BOOL CDsvTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CDsvTestDoc 序列化

void CDsvTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CDsvTestDoc 诊断

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


// CDsvTestDoc 命令
