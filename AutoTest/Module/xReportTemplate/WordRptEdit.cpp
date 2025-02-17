#include "StdAfx.h"
#include "WordRptEdit.h"
//#include "RptMapFile.h"
#include "ReportMap.h"
#include "RptBkmk.h"
#include "RptData.h"
#include "../../../Module/Office/mso9.h"

CWordRptEdit::CWordRptEdit(void):m_doc(NULL),m_WordApp(NULL)
{
	m_dwMaxBkmkIndex = 0;
}

CWordRptEdit::~CWordRptEdit(void)
{

	Free();
}

void CWordRptEdit::Free()
{	
}

long CWordRptEdit::Open(const CString &strGuideBookFile)
{
	if (m_bHasModified)
	{
		long nResult = AfxMessageBox(L"�ļ����޸ģ��Ƿ񱣴棿", MB_YESNOCANCEL);
		if (nResult == IDNO  )
		{
			m_bSave = FALSE;
		}
		else if (nResult == IDYES)
		{
			m_bSave = TRUE;
		}
		else
		{
			return 0;
		}
	}

	ExitWord();

	ASSERT (m_pGuideBook != NULL);
	m_pGuideBook->OpenXMLFile(strGuideBookFile);

	CString strPathTitle;
	int nPos = strGuideBookFile.ReverseFind('.');
	ASSERT (nPos > 0);
	strPathTitle = strGuideBookFile.Left(nPos);

	//mapfile����
	m_strReportMapFile.Format(L"%s.mpxml", strPathTitle);

	if (FindFile(m_strReportMapFile))
	{
		ASSERT(m_pReportMap!=NULL);

		//�޸�ֻ������
		CFileStatus rStatus;
		CFile::GetStatus(m_strReportMapFile,rStatus);//����ļ�����������
		rStatus.m_attribute=rStatus.m_attribute & 0x3E;   //����ļ�Ϊֻ���ģ���ֻ������ȥ��
		//--------------------------------------------
		CFile::SetStatus(m_strReportMapFile, rStatus );//�����ļ�����������

		m_pReportMap->Open(m_strReportMapFile);
		InitBkmkMaxindex();
	}

	//Doc�ļ�����
	m_strReportTemplateFile = strPathTitle;
	m_strReportTemplateFile += L".doc";

	//��Word�ĵ�
	if (!CreateWordApplication())
	{
		AfxMessageBox(L"��Wordʧ��");
		return FALSE;
	}
	//if (OpenReportTemplate(m_strReportTemplateFile))
	//{
	//	AdjustWordWindow();
	//}

	return TRUE;
}

BOOL CWordRptEdit::FindFile(const CString& strFileName)
{
	//�����ļ��Ƿ����
	CFileFind find;
	BOOL bRet = find.FindFile(strFileName);
	find.Close();
	return bRet;
}

long CWordRptEdit::LocateBkmk(const CString &  strBkmk)
{
	BOOL bFind = FALSE;
	MSWord::Bookmarks wordBookmarks;
	MSWord::Bookmark wordBookmark;

	try
	{
		if(m_doc == NULL)
			return FALSE;
		wordBookmarks = m_doc.GetBookmarks();		
		bFind = wordBookmarks.Exists(strBkmk);
		if (bFind)
		{
			COleVariant index(strBkmk);
			wordBookmark = wordBookmarks.Item(&index);
			wordBookmark.Select();
		}
	}
	catch (...)
	{
	}
	return 0;
}

long CWordRptEdit::LocateBkmk(CRptData *pData, LONG nIndex)
{
	CRptBkmk* pBkmk = (CRptBkmk*)pData->GetAt(nIndex);
	LocateBkmk(pBkmk->m_strID);
	return 0;
}

CExBaseObject * CWordRptEdit::ReLocateBkmk()
{
	CRptBkmk* pBkmk = NULL;

	try
	{
		// ������ǩ
		if(m_doc == NULL)
			return FALSE;
		COleVariant vOpt(DISP_E_PARAMNOTFOUND, VT_ERROR);
		MSWord::Bookmarks wordBookmarks = m_doc.GetBookmarks();
		MSWord::Bookmark wordBookmark;
		MSWord::Selection wordSelection = m_WordApp.GetSelection();
		MSWord::Range wordSelectionRange = wordSelection.GetRange();

		long nStart = wordSelectionRange.GetStart();
		long nID = wordSelectionRange.GetBookmarkID();
		if(nID != 0)
		{
			//�����Ƿ��ж�Ӧ��ǩ
			long nCount = wordBookmarks.GetCount();
			for (long nIndex=1; nIndex<nCount+1; nIndex++)
			{
				COleVariant index(nIndex);
				wordBookmark = wordBookmarks.Item(&index);
				long nTemp = wordBookmark.GetStart();

				if (nStart == nTemp)//�ҵ���λ�õ���ǩ
				{
					CString Name = wordBookmark.GetName();

					pBkmk = (CRptBkmk*)m_pReportMap->FindBkmk(Name);
					break;
				}
			}
		}
	}
	catch (...)
	{
	}

	return pBkmk;
}

long CWordRptEdit::DeleteBkmk(const CString &  strBkmk)
{	
	CString str = strBkmk;
	COleVariant index(str);
	MSWord::Bookmarks wordBookmarks = m_doc.GetBookmarks();
	MSWord::Bookmark wordBookmark;

	try
	{
		//ɾ��Map�ṹbkmk
		CExBaseObject* pBkmk = m_pReportMap->FindBkmk(strBkmk);
		ASSERT(pBkmk != NULL);

		CExBaseList* pParent = (CExBaseList*)pBkmk->GetParent();
		ASSERT(pParent != NULL);

		pParent->Delete(pBkmk);

		if (wordBookmarks.Exists(str))
		{
			wordBookmark = wordBookmarks.Item(&index);
			wordBookmark.Delete();
		}
	}
	catch(...)
	{
		TRACE0("Fail to Delete BookMark");
	}	

	m_bHasModified = TRUE;
	return 1;
}

long CWordRptEdit::DeleteBkmk(CExBaseObject *pObj)
{
	return CRptEditInterface::DeleteBkmk(pObj);
}


CExBaseObject* CWordRptEdit::AddBkmk(CRptData *pData)
{
	if(m_doc == NULL)
	{
		return FALSE;
	}

	CRptBkmk* pBkmk = NULL;

	try
	{
		// ������ǩ
		COleVariant vOpt(DISP_E_PARAMNOTFOUND, VT_ERROR);
		MSWord::Bookmarks wordBookmarks = m_doc.GetBookmarks();
		MSWord::Bookmark wordBookmark;
		MSWord::Selection wordSelection = m_WordApp.GetSelection();
		MSWord::Range wordSelectionRange = wordSelection.GetRange();

		long nStart = wordSelectionRange.GetStart();
		long nID = wordSelectionRange.GetBookmarkID();
		if(nID != 0)
		{
			//�����Ƿ��ж�Ӧ��ǩ
			long nCount = wordBookmarks.GetCount();
			for (long nIndex=1; nIndex<nCount+1; nIndex++)
			{
				COleVariant index(nIndex);
				wordBookmark = wordBookmarks.Item(&index);
				long nTemp = wordBookmark.GetStart();

				if (nStart == nTemp)//�ҵ���λ�õ���ǩ
				{
					CString Name = wordBookmark.GetName();

					if (m_pReportMap->FindBkmk(Name)!=NULL)//����Ч��ǩ
					{
						int nResult = MessageBoxW(NULL,L"��ǰλ���б�ǩ��ȷ���滻",L"��ʾ",MB_YESNO);

						if(nResult == IDNO)
						{
							return NULL;
						}
						else//�滻��ǩ
						{
							long nCount = wordBookmarks.GetCount();
							for (long nIndex=1; nIndex<nCount+1; nIndex++)
							{
								COleVariant index(nIndex);
								wordBookmark = wordBookmarks.Item(&index);
								long nTemp = wordBookmark.GetStart();
								if (nStart == nTemp)
								{
									CString Name = wordBookmark.GetName();
									//���Ҫ�������ǩ������Data��ͬ�򷵻�
									if (pData->FindByID(Name) != NULL)
									{
										return NULL;
									}
									DeleteBkmk(Name);
									break;
								}
							}			
						}
					}
					else
					{
						wordBookmark.Delete();
					}
					
					break;
				}
			}
		}

		CString strBkmk;
		strBkmk.Format(L"Bkmk_%d",m_dwMaxBkmkIndex++);
		wordBookmarks.Add(strBkmk, vOpt);
		pBkmk = (CRptBkmk*)pData->AddNew2(strBkmk);

	}
	catch (...)
	{
	}
	
	m_bHasModified = TRUE;

	return pBkmk;
}

BOOL CWordRptEdit::CanAddArea()
{
	if(m_doc == NULL)
	{
		return FALSE;
	}

	BOOL bCanAdd = TRUE;

	try
	{
		// ������ǩ
		COleVariant vOpt(DISP_E_PARAMNOTFOUND, VT_ERROR);
		MSWord::Bookmarks wordBookmarks = m_doc.GetBookmarks();
		MSWord::Bookmark wordBookmark;
		MSWord::Selection wordSelection = m_WordApp.GetSelection();
		MSWord::Range wordSelectionRange = wordSelection.GetRange();

		long nStart = wordSelectionRange.GetStart();
		long nEnd = wordSelectionRange.GetEnd();

		if (nEnd <= nStart+1)
		{
			bCanAdd = FALSE;
		}
	}
	catch(...)
	{
		bCanAdd = FALSE;
	}

	return bCanAdd;
}

CExBaseObject* CWordRptEdit::AddArea(CExBaseList *pRptArea)
{
	if(m_doc == NULL)
	{
		return FALSE;
	}

	CRptBkmk* pBkmk = NULL;

	try
	{
		// ������ǩ
		COleVariant vOpt(DISP_E_PARAMNOTFOUND, VT_ERROR);
		MSWord::Bookmarks wordBookmarks = m_doc.GetBookmarks();
		MSWord::Bookmark wordBookmark;
		MSWord::Selection wordSelection = m_WordApp.GetSelection();
		MSWord::Range wordSelectionRange = wordSelection.GetRange();

		long nStart = wordSelectionRange.GetStart();
		long nEnd = wordSelectionRange.GetEnd();
		long nID = wordSelectionRange.GetBookmarkID();

		CRptArea *pArea = (CRptArea*)pRptArea;
		pArea->m_pBkmkBegin = InsertNewBkmk(m_dwMaxBkmkIndex, pRptArea, wordBookmarks, wordSelection, nStart);
		pArea->m_pBkmkEnd = InsertNewBkmk(m_dwMaxBkmkIndex, pRptArea, wordBookmarks, wordSelection, nEnd);
	}
	catch (...)
	{
	}
	
	m_bHasModified = TRUE;

	return pBkmk;
}

CRptBkmk* CWordRptEdit::InsertNewBkmk(DWORD &dwBkmkIndex, CExBaseList *pRptArea, MSWord::Bookmarks wordBookmarks, MSWord::Selection wordSelection, long nPos)
{
	CRptBkmk *pBkmk = new CRptBkmk();
	pBkmk->m_strID.Format(L"Bkmk_%d", dwBkmkIndex);
	dwBkmkIndex++;
	pRptArea->AddTail(pBkmk);
	pBkmk->SetParent(pRptArea);

	COleVariant vOpt(DISP_E_PARAMNOTFOUND, VT_ERROR);
	wordSelection.SetStart(nPos);
	wordSelection.SetEnd(nPos);
	wordSelection.Select();
	wordBookmarks.Add(pBkmk->m_strID, vOpt);

	return pBkmk;
}

//Ŀǰ��ʹ�����ַ�ʽ��������word����Ϊ���ַ�ʽ�µ�word�Ѵ�ʱ�ᵯ��**�Ѵ򿪶Ի���
BOOL CWordRptEdit::CreateWordApplication()
{
	//��������
	COleVariant covTrue((long)TRUE),covFalse((long)FALSE),covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	try
	{

		if (!m_WordApp.CreateDispatch(L"Word.Application"))
		{
			AfxMessageBox(L"û�а�װWord");
			return FALSE;
		}

		m_WordApp.SetVisible(FALSE);  //This shows the application.
	}
	catch (...)
	{
	}

	if(!OpenWordReportFile(m_strReportTemplateFile))
	{
		AfxMessageBox(L"���ĵ�ʧ�ܣ�");
		try
		{
		}
		catch (...)
		{
		}
	}
	else
	{
		MSWord::Window wnd = m_WordApp.GetActiveWindow();
		MSWord::View v = wnd.GetView();
		v.SetShowBookmarks(TRUE);
	}

	return TRUE;
}

BOOL CWordRptEdit::OpenWordReportFile(const CString &strRptFile)
{
	if (m_WordApp == NULL)
	{
		return FALSE;
	}

	MSWord::Documents docs(m_WordApp.GetDocuments());

	if (docs == NULL)
	{
		return FALSE;
	}

	COleVariant vRptFile(strRptFile);			
	COleVariant covTrue((long)TRUE),covFalse((long)FALSE),covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

	BOOL bTrue = TRUE;
	if (FindFile(m_strReportTemplateFile))
	{

		try
		{
			//�����鱨���ļ�
			m_doc = docs.Open(&vRptFile,covOptional,covFalse,covTrue,covOptional,covOptional,
				covOptional,covOptional,covOptional,covOptional,covOptional,covTrue);
		}
		catch (...)
		{
			bTrue = FALSE;
		}
	}
	else
	{
		try
		{
			CComVariant Template(_T("")); 
			CComVariant NewTemplate(false),DocumentType(0),Visible;
			m_doc = docs.Add(&Template,&NewTemplate,&DocumentType,&Visible);
		}
		catch(...)
		{
			bTrue = FALSE;
		}
	}

	MSO9::_CommandBars cmdbars;
	cmdbars = m_WordApp.GetCommandBars();
	//HideCommandBar(cmdbars);
	return bTrue;
}

void  CWordRptEdit::HideCommandBar(MSO9::_CommandBars cmdBars )
{
	try
	{
		long nCount = cmdBars.GetCount();
		long nIndex = 1;
		for(nIndex=1;nIndex<=nCount;nIndex++)
		{
			MSO9::CommandBar cmdbar = cmdBars.GetItem(COleVariant(nIndex));

			if (cmdbar.GetEnabled() && cmdbar.GetVisible())
			{
				cmdbar.SetEnabled(FALSE);
			}
		}
	}
	catch (...)
	{

	}
}

long CWordRptEdit::Save()
{
	//Map�ļ�����
	if (!m_bHasModified)
	{
		return 0;
	}

	if (m_pReportMap == NULL)
	{
		return 0;
	}
	m_pReportMap->Save(m_strReportMapFile);

	//Doc�ļ�����
	COleVariant vOpt(DISP_E_PARAMNOTFOUND, VT_ERROR);  	

	m_doc.SaveAs(COleVariant(m_strReportTemplateFile), vOpt, vOpt, vOpt,
		vOpt, vOpt, vOpt, vOpt, vOpt, vOpt, vOpt);

	m_bHasModified = FALSE;

	return 0;
}

long CWordRptEdit::Close(BOOL bSave)
{
	if (bSave)//nSave ��Ϊ0�˳�����
	{
		Save();
	}
	return 0;
}

void CWordRptEdit::ExitWord()
{	
	COleVariant vTrue((short)TRUE), vFalse((short)FALSE),
		vOpt((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

	if (m_doc!=NULL)
	{
		Close(m_bSave);

		try
		{
			if (m_doc != NULL)
			{
				m_doc.Close(vFalse,vOpt,vOpt);
			}

			m_doc = NULL;
		}
		catch (...)
		{
			m_doc = NULL;

			TRACE(L"Close word doc error...");
		}
	}

	try
	{
		m_doc = NULL;

		if (m_WordApp != NULL)
		{
			m_WordApp.Quit(vFalse,vOpt,vOpt);
			m_WordApp = NULL;
		}
		m_WordApp = NULL;
	}
	catch (...) 
	{
	}

}

void CWordRptEdit::SetWordWndFocus()
{
	CWnd *pWnd = NULL;
	if (::IsWindow(m_hWordWnd))
	{
		pWnd = CWnd::FromHandle(m_hWordWnd);
		if (pWnd != NULL)
		{
			BOOL b = pWnd->SetForegroundWindow();
			pWnd->SetFocus();
		}
	}
}

//����RptMap�������Index��
void CWordRptEdit::InitBkmkMaxindex()
{
	if (m_pReportMap == NULL)
	{
		return;
	}

	SetMaxIndexInList(m_pReportMap);
	m_dwMaxBkmkIndex ++;
}

void CWordRptEdit::SetMaxIndexInList(CExBaseList* pList)
{
	DWORD nIndex = 0;
	int nCount = pList->GetCount();
	CExBaseObject* pObj = NULL;

	for (int i=0; i<nCount; i++)
	{
		pObj = pList->GetAt(i);

		if (pObj->GetClassID()&CLASSID_EXLISTCLASS)
		{
			SetMaxIndexInList((CExBaseList*)pObj);
		}
		else
		{
			nIndex = ((CRptBkmk*)pObj)->m_dwIndex;
			if (nIndex > m_dwMaxBkmkIndex)
			{
				m_dwMaxBkmkIndex = nIndex;
			}
		}
	}

}

//BOOL CWordRptEdit::OpenReportTemplate(const CString &strRptFile)
//{
//	CMainFrame* pFrm = (CMainFrame*)AfxGetMainWnd();
//	pFrm->BeginWaitCursor();
//	// ���Word����ģ��
//	CReportTemplateEditCntrItem* pItem = NULL;
//	try
//	{
//		CReportTemplateDevView* pView = (CReportTemplateDevView*)pFrm->GetActiveView();
//		CReportTemplateDevDoc* pDoc = (CReportTemplateDevDoc*)pFrm->GetActiveDocument();
//		ASSERT_VALID(pDoc);
//
//		pItem = new CReportTemplateEditCntrItem(pDoc);
//		ASSERT_VALID(pItem);
//
//		CLSID clsid;
//		if(FAILED(::CLSIDFromProgID(L"Word.document",&clsid)))
//			AfxThrowMemoryException();
//
//		if(!pItem->CreateFromFile(strRptFile/*, clsid*/))
//			//	AfxThrowMemoryException();
//		{
//			if(!pItem->CreateNewItem(clsid))
//				AfxThrowMemoryException();
//
//			ASSERT_VALID(pItem);		
//			pItem->DoVerb(OLEIVERB_SHOW, pView);
//			m_pSelection = pItem;   
//			pDoc->UpdateAllViews(NULL);
//
//			LPDISPATCH lpDisp;
//			lpDisp = pItem->GetIDispatch();
//			m_doc.AttachDispatch(lpDisp);	
//
//			COleVariant vRptFile(strRptFile);			
//			COleVariant covTrue((short)TRUE),covFalse((short)FALSE),covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
//			m_doc.SaveAs(vRptFile,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional);
//
//			m_WordApp = m_doc.GetApplication();
//			//GetAllBookMarks();			
//		}
//		else
//		{
//			ASSERT_VALID(pItem);		
//			pItem->DoVerb(OLEIVERB_SHOW, pView);
//			m_pSelection = pItem;   
//			pDoc->UpdateAllViews(NULL);
//
//			LPDISPATCH lpDisp;
//			lpDisp = pItem->GetIDispatch();
//			m_doc.AttachDispatch(lpDisp);	
//
//			m_WordApp = m_doc.GetApplication();
//			//GetAllBookMarks();
//
//			try
//			{				
//				MSWord::Window wnd = m_WordApp.GetActiveWindow();
//				MSWord::View v = wnd.GetView();
//				m_bHasWord = TRUE;
//				v.SetShowBookmarks(TRUE);
//			}
//			catch (...)
//			{
//				m_bHasWord = FALSE;
//			}
//		}
//	}
//	catch (...) 
//	{
//		if (pItem != NULL)
//		{
//			ASSERT_VALID(pItem);
//			pItem->Delete();
//		}
//		return FALSE;
//	}
//
//	pFrm->EndWaitCursor();
//	return TRUE;
//}
