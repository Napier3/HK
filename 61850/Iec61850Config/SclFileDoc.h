#pragma once

// CSclFileDoc �ĵ�

class CSclFileDoc : public CDocument
{
	DECLARE_DYNCREATE(CSclFileDoc)

public:
	CSclFileDoc();
	virtual ~CSclFileDoc();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // Ϊ�ĵ� I/O ��д
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()
};
