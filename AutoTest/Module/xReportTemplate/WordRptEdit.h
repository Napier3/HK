#pragma once
#include "rpteditinterface.h"
#include "../../../Module/Office/mso9.h"
#include "RptItems.h"

class CWordRptEdit :	public CRptEditInterface
{
public:
	CWordRptEdit(void);
	~CWordRptEdit(void);

public:
	//attribute
	DWORD		m_dwMaxBkmkIndex;
	CExBaseList m_listErrorBkmk;

	//Word ±‰¡ø
	MSWord::_Application	m_WordApp;
	MSWord::_Document		m_doc;
	CWnd *					m_pWordWnd;
	HWND					m_hWordWnd;
	BOOL					m_bHasWord;

	//Word Mathods
	BOOL CreateWordApplication();
	BOOL OpenWordReportFile(const CString &strRptFile);
	BOOL OpenReportTemplate(const CString &strRptFile);


	//Member Functions
	void InitAllBookmarks();
	BOOL FindFile(const CString& strFileName);
	void Free();

	void InitBkmkMaxindex();
	void SetMaxIndexInList(CExBaseList* pList);
	void HideCommandBar(MSO9::_CommandBars cmdBars );
	CExBaseObject * ReLocateBkmk();
	//void RestoreDocViewSettings();

public:
	//Interface
	void ExitWord();
	long Open(const CString &strGuideBookFile);
	virtual long LocateBkmk(const CString &  strBkmk);
	virtual long LocateBkmk(CRptData *pData, LONG nIndex);
	virtual long DeleteBkmk(const CString &  strBkmk);
	virtual long DeleteBkmk(CExBaseObject *pObj);
	virtual CExBaseObject* AddBkmk(CRptData *pData);
	virtual CExBaseObject* AddArea(CExBaseList *pRptArea);

	virtual long Save();
	virtual long Close(BOOL bSave);

	void SetWordWndFocus();
	BOOL CanAddArea();

private:
	CRptBkmk* InsertNewBkmk(DWORD &dwBkmkIndex, CExBaseList *pRptArea, MSWord::Bookmarks wordBookmarks, MSWord::Selection wordSelection, long nPos);
};
