
// DsvTestDoc.h : CDsvTestDoc ��Ľӿ�
//


#pragma once


class CDsvTestDoc : public CDocument
{
protected: // �������л�����
	CDsvTestDoc();
	DECLARE_DYNCREATE(CDsvTestDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CDsvTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


