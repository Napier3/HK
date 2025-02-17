#include "StdAfx.h"
#include "WordRptFill.h"
#include "../../TctrlCntrBaseApp.h"
#include "..\..\..\Module\API\GlobalApi.h"

CWordRptFill::CWordRptFill(void)
{
	m_pGuideBook = NULL;
	m_oDoc = NULL;
	m_hWordWnd = NULL;
	m_bAttachReportMap = FALSE;
	m_pReortMap = new CReportMap();
}

CWordRptFill::~CWordRptFill(void)
{
	
}

void CWordRptFill::FreeReportMap()
{
	if (m_bAttachReportMap)
	{
		m_pReortMap = NULL;
		m_bAttachReportMap = FALSE;
	}	
	else
	{
		if (m_pReortMap != NULL)
		{
			delete m_pReortMap;
			m_pReortMap = NULL;
		}
	}
}

void CWordRptFill::AttachReportMap(CReportMap* pReportMap)
{
	FreeReportMap();
	
	m_pReortMap = pReportMap;
	m_bAttachReportMap = TRUE;
}

//////////////////////////////////////////////////////////////////////////
//
//重载父类成员虚函数
//
//////////////////////////////////////////////////////////////////////////
void CWordRptFill::CreateWordApp()
{
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();

	if (pApp->GetCntrConfig()->m_nDebugWithoutReport)
	{
		return;
	}

	COleVariant covTrue((long)TRUE),covFalse((long)FALSE),covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	COleVariant vTemplate(m_strReportTemplFile);			
	COleVariant vRptFile(m_strReportFile);			
	BOOL bWordCreate = TRUE;

	pApp->GetWordApp();
}

long CWordRptFill::New(CString strReportMapFile, CString strReportTemplFile, CString strReportFile)
{
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();

	if (pApp->GetCntrConfig()->m_nDebugWithoutReport)
	{
		return FALSE;
	}

	m_strReportMapFile = strReportMapFile;
	m_strReportTemplFile = strReportTemplFile;
	m_strReportFile = strReportFile;

	if(!m_strReportMapFile.IsEmpty())
	{
		m_pReortMap->Open(m_strReportMapFile);
	}

	COleVariant covTrue((long)TRUE),covFalse((long)FALSE),covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	COleVariant vTemplate(m_strReportTemplFile);			
	COleVariant vRptFile(m_strReportFile);			
	BOOL bWordCreate = TRUE;

	pApp->GetWordApp();

	if (  pApp->m_WordApp == NULL)
	{
		return 0;
	}

	MSWord::Documents docs;

	try
	{
		//如果打开了报告文档，则保存并关闭文档
		docs =   pApp->m_WordApp.GetDocuments();

		//打开报告文档
		if (!Open(m_strReportFile))
		{
			try
			{
				//如果打开失败，则打开测试模板，并且填写试验报告
				if (AddNewReport(m_strReportTemplFile))
				{
					pApp->SetDocViewSettings();
				}
			}
			catch (...)
			{
			}
		}

		AdjustWordWindow();
	}
	catch(...)
	{
	}

	return TRUE;
}

long CWordRptFill::Open(const CString  &strReportFile)
{
	CreateWordApp();

	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();

	if (pApp->GetCntrConfig()->m_nDebugWithoutReport)
	{
		return FALSE;
	}

	m_strReportFile = strReportFile;
	CFileFind find;

	if (!find.FindFile(strReportFile))
	{
		return FALSE;
	}

	if ( pApp->m_WordApp == NULL)
	{
		return FALSE;
	}

	m_strReportFile = strReportFile;

	MSWord::Documents docs = NULL;
	docs =  pApp->m_WordApp.GetDocuments();

	if (docs == NULL)
	{
		return FALSE;
	}

	COleVariant vRptFile(strReportFile);			
	COleVariant covTrue((long)TRUE),covFalse((long)FALSE),covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

	BOOL bTrue = TRUE;
	try
	{
		//打开试验报告文件
		m_oDoc = docs.Open(&vRptFile,covOptional,covFalse,covTrue,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional,covTrue);
		pApp->SetDocViewSettings();
	}
	catch (...)
	{
		bTrue = FALSE;
	}

	AdjustWordWindow();

	return bTrue;
}

long CWordRptFill::Save()
{
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();
	if (pApp->GetCntrConfig()->m_nDebugWithoutReport)
	{
		return FALSE;
	}

	if( pApp->m_WordApp == NULL)
		return FALSE;

	if(m_oDoc == NULL)
		return FALSE;

	m_oDoc.Save();

	return TRUE;
}

long CWordRptFill::SaveAs(CString  strRptFile)
{
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();
	
	if (pApp->GetCntrConfig()->m_nDebugWithoutReport)
	{
		return FALSE;
	}

	if( pApp->m_WordApp == NULL || m_oDoc == NULL)
		return FALSE;

	COleVariant covTrue((long)TRUE),covFalse((long)FALSE),covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	COleVariant vRptFile(m_strReportFile);
	m_oDoc.SaveAs(vRptFile,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional);

	return TRUE;
}

long CWordRptFill::Close(long nSave)
{
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();
	
	if (pApp->GetCntrConfig()->m_nDebugWithoutReport)
	{
		return FALSE;
	}

	if( pApp->m_WordApp == NULL || m_oDoc == NULL)
	{
		return TRUE;
	}

	CloseWordDocWindow();
	pApp->CloseWordApplication();

	return TRUE;
}

//获取试验报告处理程序的主窗口
//用于调整试验报告界面与主程序界面的布局
void CWordRptFill::SetParentWnd(CWnd* pParentWnd)
{
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();
	if (pApp->GetCntrConfig()->m_nDebugWithoutReport)
	{
		return;
	}

	m_pParentWnd = pParentWnd;
}

CWnd* CWordRptFill::GetReportMainWnd()
{
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();
	if (pApp->GetCntrConfig()->m_nDebugWithoutReport)
	{
		return NULL;
	}

	return NULL;
}

void CWordRptFill::AdjustReportWindowOnSize()
{
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();
	if (pApp->GetCntrConfig()->m_nDebugWithoutReport)
	{
		return;
	}

	AdjustWordWindowOnSize();
}

//是否包含需要填写的报告数据的位置
long CWordRptFill::HasReportNeedFill(const CGbItemBase* pItem)
{
	return 0;
}

//设置报告数据，填写报告
long CWordRptFill::FillReport(CReport* pReport)
{
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();
	if (pApp->GetCntrConfig()->m_nDebugWithoutReport)
	{
		return FALSE;
	}

	CRptItem *pItem = Match(pReport);

	if (pItem == NULL)
	{
		return -1;
	}

	POS pos = pItem->GetHeadPosition();
	CExBaseObject *p = NULL;
	UINT nCladdID = 0;

	while (pos != NULL)
	{
		p = pItem->GetNext(pos);
		long nClassID = p->GetClassID();

		switch(nClassID)
		{
		case RPTCLASSID_RPTDATA:
			FillReport((CRptData*)p, pReport);
			break;
		case RPTCLASSID_RPTDATAS:
			FillReport((CRptDatas*)p, pReport);
			break;
		default:
			break;
		}
	}
	return 0;
}

//在报告中定位
long CWordRptFill::LocateReport(CGbItemBase* pItemBase)
{
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();
	if (pApp->GetCntrConfig()->m_nDebugWithoutReport)
	{
		return FALSE;
	}

	CRptItem *pItem = Match(pItemBase);

	if (pItem == NULL)
	{
		return -1;
	}

	POS pos = pItem->GetHeadPosition();
	CExBaseObject *p = NULL;
	UINT nCladdID = 0;

	if (pos != NULL)
	{
		p = pItem->GetAt(pos);
		long nClassID = p->GetClassID();

		switch(nClassID)
		{
		case RPTCLASSID_RPTDATA:
			LocateReport((CRptData*)p);
			break;
		case RPTCLASSID_RPTDATAS:
			LocateReport((CRptDatas*)p);
			break;
		default:
			break;
		}
	}

	return 0;
}

void CWordRptFill::PrintReport()
{
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();

	if( pApp->m_WordApp == NULL || m_oDoc == NULL)
	{
		return;
	}

	try
	{
		COleVariant covTrue((short)TRUE),covFalse((short)FALSE),covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);	
		m_oDoc.PrintOut(covFalse,
			covOptional,//Append.
			covOptional,//Range.
			covOptional,//OutputFileName.
			covOptional,//From.
			covOptional,//To.
			covOptional,//Item.
			covOptional,//Copies.
			covOptional,//Pages.
			covOptional,//PageType.
			covOptional,//PrintToFile.
			covOptional,//Collate.
			covOptional,//ActivePrinterMacGX.
			covOptional,//ManualDuplexPrint.
			covOptional,//PrintZoomColumnNewwithWord2002
			covOptional,//PrintZoomRowditto
			covOptional,//PrintZoomPaperWidthditto
			covOptional);//PrintZoomPaperHeightditto	
	}
	catch (...)
	{
	}
}

void CWordRptFill::ZoomReport(long nPercentage)
{
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();

	if( pApp->m_WordApp == NULL || m_oDoc == NULL)
	{
		return;
	}

	try
	{
		MSWord::Window wnd;
		MSWord::View vw;
		wnd =  pApp->m_WordApp.GetActiveWindow();
		vw = wnd.GetView();
		MSWord::Zoom zm;
		zm = vw.GetZoom();
		zm.SetPercentage(nPercentage);
	}
	catch (...) 
	{
	}	
}

long CWordRptFill::GetZoomReport()
{
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();
	long nPercentage = 100;

	if( pApp->m_WordApp == NULL || m_oDoc == NULL)
	{
		return nPercentage;
	}

	try
	{
		MSWord::Window wnd;
		MSWord::View vw;
		wnd = pApp->m_WordApp.GetActiveWindow();
		vw = wnd.GetView();
		MSWord::Zoom zm;
		zm = vw.GetZoom();
		nPercentage = zm.GetPercentage();
	}
	catch (...) 
	{
	}

	return nPercentage;
}

//调整报告
long CWordRptFill::AdjustReport()
{
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();

	if( pApp->m_WordApp == NULL || m_oDoc == NULL)
	{
		return -1;
	}

	AdjustReport_FillEmpty();

	AdjustReport_Area();
	return 0;
}

long CWordRptFill::AdjustReport_FillEmpty()
{
	POS pos = m_pReortMap->GetHeadPosition();
	CExBaseObject *p = NULL;
	CString strReplace;

	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();
	CTCtrlCntrConfig *pConfig = pApp->GetCntrConfig();

	AdjustReport_FillEmpty(pConfig->m_strReplaceForEmptyCell, (CExBaseList*)m_pReortMap);

	return 0;
}

long CWordRptFill::AdjustReport_FillEmpty(const CString &strReplace, CExBaseObject *pObj)
{
	UINT nClassID = pObj->GetClassID();
	ASSERT (nClassID == RPTCLASSID_RPTBKMK);

	if (nClassID != RPTCLASSID_RPTBKMK)
	{
		return 0;
	}

	CRptBkmk *pBkmk = (CRptBkmk*)pObj;
	AdjustReport_FillEmpty(strReplace, pBkmk);

	return 0;
}


long CWordRptFill::AdjustReport_FillEmpty(const CString &strReplace, CExBaseList *pList)
{
	POS pos = pList->GetHeadPosition();
	CExBaseObject *p = NULL;
	UINT nClassID = 0;

	while (pos != NULL)
	{
		p = (CExBaseObject*)pList->GetNext(pos);
		nClassID = p->GetClassID();

		if (nClassID == RPTCLASSID_RPTAREA)
		{
			continue;
		}

		if (nClassID == RPTCLASSID_RPTDATA)
		{
			AdjustReport_FillEmpty(strReplace, (CRptData*)p);
			continue;
		}

		if (p->IsBaseList())
		{
			AdjustReport_FillEmpty(strReplace, (CExBaseList*)p);
		}
		else
		{
			AdjustReport_FillEmpty(strReplace, p);
		}
	}

	return 0;
}

long CWordRptFill::AdjustReport_FillEmpty(const CString &strReplace, CRptData *pData)
{
	if (pData->m_nDataFill > 0)
	{
		return 0;
	}

	POS pos = pData->GetHeadPosition();
	CRptBkmk *pBkmk = NULL;

	while (pos != NULL)
	{
		pBkmk = (CRptBkmk*)pData->GetNext(pos);
		AdjustReport_FillEmpty(strReplace, pBkmk);
	}

	return 1;
}


long CWordRptFill::AdjustReport_FillEmpty(const CString &strReplace, CRptBkmk *pBkmk)
{
	UINT nClassID = pBkmk->GetClassID();
	ASSERT (nClassID == RPTCLASSID_RPTBKMK);

	if (nClassID != RPTCLASSID_RPTBKMK)
	{
		return 0;
	}

	FillReport(strReplace, pBkmk);

	return 0;
}


//调整报告的区域位置
long CWordRptFill::AdjustReport_Area()
{
	AdjustReport_Area((CExBaseList*)m_pGuideBook);

	return 0;
}

long CWordRptFill::AdjustReport_Area(CExBaseList *pList)
{
	POS pos = pList->GetHeadPosition();
	CBaseObject *p = NULL;
	UINT nClassID = 0;

	while (pos != NULL)
	{
		p = pList->GetNext(pos);
		nClassID = p->GetClassID();

		if ( Gb_IsGbItemClassID(nClassID))
		{
			AdjustReport_DelArea((CGbItemBase*)p);
		}
		else if (Gb_IsItemsBaseClassID(nClassID))
		{
			AdjustReport_Area((CItems*)p);
		}
	}

	return 0;
}

long CWordRptFill::AdjustReport_Area(CItems *pItems)
{
	AdjustReport_Area( (CExBaseList*)pItems);

	//调整本项目的区域
	AdjustReport_DelArea( (CGbItemBase*)pItems);

	return 0;
}

long  CWordRptFill::AdjustReport_DelArea(CGbItemBase *pItem)
{
	if (pItem->m_nSelect > 0)
	{
		return 0;
	}

	CRptItem *pRptItem = MatchItem(pItem);

	if (pRptItem == NULL)
	{
		return 0;
	}

	AdjustReport_DelArea(pRptItem->m_pArea);

	return 0;
}

long CWordRptFill::AdjustReport_DelArea(CRptArea *pArea)
{
	if (pArea == NULL)
	{
		return 0;
	}

	if (pArea->GetCount() != 2)
	{
		return 0;
	}

	ASSERT (pArea->m_pBkmkBegin != NULL && pArea->m_pBkmkEnd != NULL);
	long nPosBegin1 = 0, nPosEnd1 = 0;
	long nPosBegin2 = 0, nPosEnd2 = 0;
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();

	GetBkmkPos(pArea->m_pBkmkBegin, nPosBegin1, nPosEnd1);
	GetBkmkPos(pArea->m_pBkmkEnd, nPosBegin2, nPosEnd2);

	if (nPosBegin1 == -1 || nPosEnd2 == -1)
	{
		return 0;
	}

	try
	{
		MSWord::Selection oSelection;
		MSWord::Bookmarks bookmarks;
		MSWord::Bookmark bookmark;

		oSelection =  pApp->m_WordApp.GetSelection();
		bookmarks = m_oDoc.GetBookmarks();
		oSelection.SetStart(nPosBegin1);
		oSelection.SetEnd(nPosEnd2);
		oSelection.Select();
		oSelection.Cut();

		DeleteBkmk(bookmarks, pArea->m_pBkmkBegin->m_strID);
		DeleteBkmk(bookmarks, pArea->m_pBkmkEnd->m_strID);
	}
	catch(...)
	{
	}

	return 0;
}

void CWordRptFill::DeleteBkmk(MSWord::Bookmarks bookmarks, const CString &strBkmk)
{
	try
	{
		if (bookmarks.Exists(strBkmk))
		{
			COleVariant vIndex(strBkmk);
			MSWord::Bookmark  bookmark = bookmarks.Item(&vIndex);
			bookmark.Delete();
		}
	}
	catch (...)
	{
	}
}

long CWordRptFill::GetBkmkPos(CRptBkmk *pBkmk, long &nBeginPos, long &nEndPos)
{
	nBeginPos = -1;
	nEndPos = -1;
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();

	try
	{
		MSWord::Selection oSelection;
		MSWord::Bookmarks bookmarks;
		MSWord::Bookmark bookmark;

		oSelection =  pApp->m_WordApp.GetSelection();
		bookmarks = m_oDoc.GetBookmarks();

		if(!pBkmk->m_strID.IsEmpty() && bookmarks.Exists(pBkmk->m_strID))
		{
			COleVariant vIndex(pBkmk->m_strID);
			bookmark = bookmarks.Item(&vIndex);
			nBeginPos = bookmark.GetStart();
			nEndPos = bookmark.GetEnd();
		}
	}
	catch(...)
	{
	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////
//
//成员函数
//
//////////////////////////////////////////////////////////////////////////
CRptItem* CWordRptFill::Match(CReport *pReport)
{
	stack<CGbItemBase*> m_stackItem;

	//清空堆栈
	m_stackItem.empty();
	CGbItemBase* pTemp = (CGbItemBase*)pReport->GetParent()->GetParent();

	while(pTemp)
	{
		m_stackItem.push(pTemp);
		pTemp = (CGbItemBase*)pTemp->GetParent();

		if(pTemp == m_pGuideBook)
		{
			break;
		}
	}

	//压栈完成，开始匹配
	CGbItemBase* pItem = m_stackItem.top();
	if(pItem == NULL)
	{
		return NULL;
	}

	m_stackItem.pop();
	CExBaseList* pRptItem = (CExBaseList*)m_pReortMap->FindByID(pItem->GetID());
	CRptItem *pItemMatch = NULL;

	if (pRptItem == NULL)
	{
		return NULL;
	}

	while(TRUE)
	{
		if (m_stackItem.empty())
		{
			break;
		}

		//匹配数据
			pItem = m_stackItem.top();
		pRptItem = (CExBaseList*)pRptItem->FindByID(pItem->GetID());

		if (pRptItem == NULL)
		{
			break;
		}

		m_stackItem.pop();

		if(m_stackItem.empty())
		{
			if(pRptItem->GetClassID() == RPTCLASSID_RPTITEM)
			{
				pItemMatch = (CRptItem*)pRptItem; //找到对应报告项
			}
		}
	}

	return pItemMatch;
}

CRptItem* CWordRptFill::Match(CGbItemBase* pItemBase)
{
	stack<CGbItemBase*> m_stackItem;

	ASSERT(pItemBase != NULL);
	//清空堆栈
	m_stackItem.empty();
	CGbItemBase* pTemp = pItemBase;//(CGbItemBase*)pReport->GetParent()->GetParent();

	while(pTemp)
	{
		m_stackItem.push(pTemp);
		pTemp = (CGbItemBase*)pTemp->GetParent();

		if(pTemp == m_pGuideBook)
		{
			break;
		}
	}

	//压栈完成，开始匹配
	CGbItemBase* pItem = m_stackItem.top();
	if(!pItem)
		return NULL;

	m_stackItem.pop();
	CExBaseList* pRptItem = (CExBaseList*)m_pReortMap->FindByID(pItem->GetID());

	while(pRptItem)
	{
		if(pRptItem->GetClassID() == RPTCLASSID_RPTITEM)
			return (CRptItem*)pRptItem; //找到对应报告项

		if(!m_stackItem.empty())
			pItem = m_stackItem.top();
		else
			return NULL;

		m_stackItem.pop();
		pRptItem = (CExBaseList*)pRptItem->FindByID(pItem->GetID());
	}

	return NULL;
}

CRptItem* CWordRptFill::MatchItem(CGbItemBase* pItemBase)
{
	CExBaseList oList;
	oList.AddHead(pItemBase);
	CExBaseObject *pParent = (CExBaseObject*)pItemBase->GetParent();

	while (pParent != m_pGuideBook && pParent != NULL)
	{
		oList.AddHead(pParent);
		pParent = (CExBaseObject*)pParent->GetParent();
	}
	
	CExBaseList *pRptMapList = m_pReortMap;
	POS pos = oList.GetHeadPosition();
	CRptItem *pRptItemFind = NULL;
	CExBaseObject *p = NULL;

	while (pos != NULL)
	{
		p = (CExBaseObject*)oList.GetNext(pos);
		pRptMapList = (CExBaseList*)pRptMapList->FindByID(p->m_strID);

		if (pRptMapList == NULL)
		{
			break;
		}
	}

	if (pos == NULL)
	{//如果遍历到最后一个节点，表示全部查找到
		pRptItemFind = (CRptItem*)pRptMapList;
	}

	oList.RemoveAll();
	return pRptItemFind;
}

BOOL CWordRptFill::IsRptDataSingleMode(CRptData *pData, CReport *pReport, SystemTool::ITagPtr &oTag)
{
	CGbItemBase* pItem = (CGbItemBase*)pReport->GetParent()->GetParent();

	ASSERT (pItem != NULL);

	if (pItem->GetClassID() != GBCLASSID_COMMCMD)
	{
		return TRUE;
	}

	//@@@@@@@@@@@@@@@@@@@@@@@
	CCommCmd *pCommCmd = (CCommCmd*)pItem;
	oTag = pCommCmd->FindRptTag(_bstr_t(pData->m_strID));

	if (oTag == NULL)
	{
		return TRUE;
	}

	_bstr_t bstrDataType = oTag->GetDataType();

	if (bstrDataType == g_bstrCommCmdDataExModeID[COMMCMD_DATAEX_MODE_COL] 
		|| bstrDataType == g_bstrCommCmdDataExModeID[COMMCMD_DATAEX_MODE_ROW] )
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

void CWordRptFill::FillReport(CRptData *pData, CReport *pReport)
{
	SystemTool::ITagPtr oTag;

	pData->m_nDataFill++;

	if (IsRptDataSingleMode(pData, pReport, oTag))
	{
		FillReportSingle(pData, pReport);
	}
	else
	{
		FillReportGroup(pData, pReport, oTag);
	}
}

void CWordRptFill::FillReportGroup(CRptData *pData, CReport *pReport, SystemTool::ITagPtr oTag)
{
	_bstr_t bstrDataType = oTag->GetDataType();

	if (bstrDataType == g_bstrCommCmdDataExModeID[COMMCMD_DATAEX_MODE_COL] )
	{
		FillReportGroupColMode(pData, pReport, oTag);
	}
	else if (bstrDataType == g_bstrCommCmdDataExModeID[COMMCMD_DATAEX_MODE_ROW] )
	{
		FillReportGroupRowMode(pData, pReport, oTag);
	}
}


//根据pReport获得Item对象，如果Item对象为通讯命令对象
//且通讯命令对象中能够找到pData数据
//如果pData数据对应的Tag对象的DataTyoe为“col-mode”
//则获取报告数据的m_oRprDataEx
//获取pItem的m_oRptTags中的“Count”Tag，
//获取表格，逐行填写
long Gb_RptFill_GetReportGroupDataCount(CCommCmd *pCommCmd, CReport *pReport)
{
	//SystemTool::ITagPtr oCountTag = pCommCmd->FindRptTagDataType(g_bstrRptDataTypeEx_Count);
	//SystemTool::ITagPtr oCountTag = pCommCmd->FindRptTag(g_bstrRptDataTypeEx_Count);
	long nCount = 0;

// 	if (oCountTag != NULL)
// 	{//如果没有定义数据的数量
// 		nCount = _wtol(oCountTag->GetValue());
// 	}
// 	else
	{
		if (pReport->m_oRptDataEx != NULL)
		{
			nCount = pReport->m_oRptDataEx->GetCount();
		}
	}

	return nCount;
}

/*
Sub Test()
'
' Test Macro
' 宏在 2010-12-23 由 LJQ 创建
'
	Dim nIndex As Long
	Dim oTable As Table
	Dim oCell As Cell
	Dim oRow As Row
	Dim oRng As Range
	Dim oBkmk As Bookmark
	Dim oBkmks As Bookmarks
	Dim oCols As Columns
	Dim oCol As Column


	nIndex = 1

	Set oBkmks = ActiveDocument.Bookmarks
	Set oBkmk = oBkmks.Item(1)
	oBkmk.Select
	Set oCols = oBkmk.Range.Columns
	Set oCol = oCols.Item(1)

	Dim count As Long

	Dim oCells As Cells

	Set oCells = oCol.Cells
	count = oCells.count

	For nIndex = 1 To count
		Set oCell = oCells.Item(nIndex)
		oCell.Select
		Set oRng = oCell.Range
		oRng.Text = "123456789"
	Next nIndex

End Sub

*/

MSWord::Cells CWordRptFill::GetCells(CRptBkmk *pBkmk, BOOL bRowMode)
{
	if (pBkmk->m_strID.IsEmpty())
	{
		return NULL;
	}

	MSWord::Cells oCells = NULL;
	MSWord::Bookmarks oBkmks = NULL;
	MSWord::Bookmark oBkmk = NULL;

	try
	{
		oBkmks = m_oDoc.GetBookmarks();

		if (oBkmks.Exists(pBkmk->m_strID))
		{
			COleVariant vIndex(pBkmk->m_strID);
			oBkmk = oBkmks.Item(&vIndex);
			oBkmk.Select();
			MSWord::Range oRange = oBkmk.GetRange();

			if (bRowMode)
			{
				MSWord::Columns oCols = NULL;
				MSWord::Column oCol = NULL;
				oCols = oRange.GetColumns();
				oCol = oCols.Item(1);
				oCells = oCol.GetCells();
			}
			else
			{
				MSWord::Rows oRows = NULL;
				MSWord::Row oRow = NULL;
				oRows = oRange.GetColumns();
				oRow = oRows.Item(1);
				oCells = oRow.GetCells();
			}
		}
	}
	catch(...)
	{

	}

	return oCells;
}

void CWordRptFill::FillReportGroupColMode(CRptData *pData, CReport *pReport, SystemTool::ITagPtr oTagDataDef)
{
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();

	if( pApp->m_WordApp == NULL || m_oDoc == NULL || pData->GetCount() == 0)
	{
		return;
	}

	//@@@@@@@@@@@@@@@@@@@@@@@
	//获取pItem的m_oRptTags中的“Count”Tag，
	CCommCmd *pCommCmd = (CCommCmd*)pReport->GetParent()->GetParent();
	long nDataCount = Gb_RptFill_GetReportGroupDataCount(pCommCmd, pReport);
	long nIndex = 0;
	_bstr_t bstrRptExTagID = oTagDataDef->GetValue();

	if (nDataCount <= 0)
	{
		return;
	}

	CRptBkmk *pBkmk = (CRptBkmk*)pData->GetHead();
	MSWord::Cells oCells = NULL;
	MSWord::Cell oCell = NULL;

	oCells = GetCells(pBkmk, FALSE);

	if (oCells == NULL)
	{
		return;
	}

	try
	{
		//扩展报告数据
		SystemTool::ITagsMngrPtr oDatas;
		SystemTool::ITagsPtr oData;
		SystemTool::ITagPtr oValue;
		oDatas = pReport->m_oRptDataEx;
		_bstr_t bstrDataExTagID = oTagDataDef->GetValue();//@@@@@@@
		_bstr_t strValue;
		long nCountTemp = oDatas->GetCount();

		//?????????????????????????????????????????????????????
		//从第二行开始
		for (nIndex=2; nIndex<=nDataCount; nIndex++)
		{
			if (nCountTemp <= nIndex - 2)
			{
				break;
			}

			oData = oDatas->GetItem(nIndex-2);

			if (oData == NULL)
			{
				break;
			}

			oCell = oCells.Item(nIndex);
			oValue = oData->FindByID(bstrDataExTagID);

			if (oValue != NULL)
			{
				strValue = oValue->GetValue();
			}
			else
			{
				strValue = L"****";
			}

			FillReportCell(strValue, oCell);
		}
	}
	catch(...)
	{
	}
}

void CWordRptFill::FillReportGroupRowMode(CRptData *pData, CReport *pReport, SystemTool::ITagPtr oTagDataDef)
{

}

void CWordRptFill::FillReportCell(const _bstr_t &strValue, MSWord::Cell oCell)
{
	oCell.Select();
	MSWord::Range oRange = oCell.GetRange();
	oRange.SetText(strValue);
}

void CWordRptFill::ChopValueString(CRptData *pData, CString &strValue)
{
	if (pData->m_nPrecision > 0)
	{
		if (strValue.GetLength() > 0)
		{
// 			int nChar = strValue.GetAt(0);
// 			
// 			if ('0' < nChar && nChar <= '9')
// 			{
// 				CString strFormat;
// 				strFormat.Format(L"%%.%df", pData->m_nPrecision);
// 				CString strTemp;
// 				strTemp.Format(strFormat, strValue);
// 			}
//			ChopFloatString(strValue, 0);
		CString strFormat;
		strFormat.Format(L"%%.%df", pData->m_nPrecision);
				double dValue = _wtof(strValue);
				strValue.Format(strFormat, dValue);
		}
	}
	else
	{
		ChopFloatString(strValue, -1);
	}
	}

void CWordRptFill::FillReportSingle(CRptData *pData, CReport *pReport)
{
	SystemTool::IValuesPtr oValues = pReport->GetValues();
	SystemTool::IValuePtr oValue = oValues->FindByID((_bstr_t)pData->m_strID);
	POS pos = pData->GetHeadPosition();
	CRptBkmk *pBkmk = NULL;

	if (oValue == NULL)
	{
		return;
	}

	CString strValue = (CString)(char*)oValue->GetValue();
	ChopValueString(pData, strValue);

	while (pos != NULL)
	{
		pBkmk = (CRptBkmk*)pData->GetNext(pos);
		FillReport(strValue, pBkmk);
	}
}

void CWordRptFill::FillReport(CRptDatas *pDatas, CReport *pReport)
{
	POS pos = pDatas->GetHeadPosition();
	CRptData *pData;
	while(pos != NULL)
	{
		pData = (CRptData*)pDatas->GetNext(pos);
		FillReport(pData,pReport);
	}
}

void CWordRptFill::FillReport(const CString &strValue, CRptBkmk *pBkmk)
{
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();

	if( pApp->m_WordApp == NULL || m_oDoc == NULL)
	{
		return;
	}
	
	try
	{
		MSWord::Selection sel;
		MSWord::Bookmarks bookmarks;
		MSWord::Bookmark bookmark;

		MSWord::Range  range = NULL;
		MSWord::Paragraphs  paragraphs = NULL;
		MSWord::Paragraph paragraph = NULL;
		MSWord::Range rangeParagraph = NULL;
		long lRangeStart = 0;
		long lRangeEnd = 0;
		long lRangeStart2 = 0;
		long lRangeEnd2 = 0;
		long lEndTemp = 0;

		sel =  pApp->m_WordApp.GetSelection();

		bookmarks = m_oDoc.GetBookmarks();
		if(!pBkmk->m_strID.IsEmpty() && bookmarks.Exists(pBkmk->m_strID))
		{
			COleVariant vIndex(pBkmk->m_strID);
			bookmark = bookmarks.Item(&vIndex);
			bookmark.Select();

			range = bookmark.GetRange();
			paragraphs = range.GetParagraphs();
			paragraph = paragraphs.GetFirst();
			rangeParagraph = paragraph.GetRange();
			lRangeStart2 = rangeParagraph.GetStart();
			lRangeEnd2 = rangeParagraph.GetEnd();
			lEndTemp = lRangeEnd2 - 1;
			if (lRangeStart2 <= lEndTemp)
				lRangeEnd2 = lEndTemp;

			sel.SetStart(lRangeStart2);
			sel.SetEnd(lRangeEnd2);

			sel.SetText(_bstr_t(strValue));
		}
	}
	catch(...)
	{
	}
}

BOOL CWordRptFill::CloseWordDocWindow()
{
	COleVariant covTrue((long)TRUE);
	COleVariant covFalse((long)FALSE);
	COleVariant covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

	try
	{
		CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();
		pApp->RestoreDocViewSettings();

		if (m_oDoc != NULL)
		{
			m_oDoc.Close(covFalse,covOptional,covOptional);
			m_oDoc = NULL;
		}
	}
	catch (...) 
	{
		TRACE("CloseWordDocWindow:Error");
	}

	return TRUE;
}
void CWordRptFill::AdjustWordWindow()
{
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();

	CWnd *pWnd = NULL;
	//获取Word文档的窗口
	try
	{
		if (m_oDoc != NULL)
		{
			CString strName = m_oDoc.GetName();
			CString strWordName =  pApp->m_WordApp.GetName();
			CString strWordCaption =  pApp->m_WordApp.GetCaption();
			MSWord::Window docWnd = m_oDoc.GetActiveWindow();
			if (docWnd != NULL)
			{
				CString strWndCaption = docWnd.GetCaption();
				CString strWndTitle;
				strWndTitle.Format(L"%s - %s",strWndCaption,strWordCaption);
				pWnd=CWnd::FindWindow(NULL,strWndTitle);
			}
		}
	}
	catch(...)
	{
	}

	ASSERT(pApp->GetCntrConfig() != NULL);

	if (pWnd == NULL)
	{
		if (::IsWindow(m_hWordWnd))
		{
			pWnd = CWnd::FromHandle(m_hWordWnd);
		}
	}
	
	if (pWnd != NULL)
	{
		CRect rectWin;
		pWnd->GetWindowRect(rectWin);
		::SetParent(pWnd->GetSafeHwnd(),m_pParentWnd->GetSafeHwnd());

		if (TRUE/*pApp->GetCntrConfig()->m_nHideAllCmdbars == 1*/)
		{
			if (FALSE/*CanUnLockReport()*/)
			{
			}
			else
			{
				//注释掉下面一行，可以在word中输入
				pWnd->ModifyStyle(0,WS_CHILD);
			}
			pWnd->ModifyStyle(WS_BORDER | WS_DLGFRAME | WS_EX_WINDOWEDGE,0);
			pWnd->ModifyStyle(WS_SIZEBOX,0);
			pWnd->SetMenu(NULL);

			// need to adjust the client edge style as max/restore happens
			DWORD dwStyle = ::GetWindowLong(m_pParentWnd->GetSafeHwnd(), GWL_EXSTYLE);
			DWORD dwNewStyle = dwStyle;
			dwNewStyle |= WS_EX_CLIENTEDGE;

			if (dwStyle != dwNewStyle)
			{
				// SetWindowPos will not move invalid bits
				::RedrawWindow(m_pParentWnd->GetSafeHwnd(), NULL, NULL,
					RDW_INVALIDATE | RDW_ALLCHILDREN);

				// remove/add WS_EX_CLIENTEDGE to MDI client area
				::SetWindowLong(m_pParentWnd->GetSafeHwnd(), GWL_EXSTYLE, dwNewStyle);
				::SetWindowPos(m_pParentWnd->GetSafeHwnd(), NULL, 0, 0, 0, 0,
					SWP_FRAMECHANGED | SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE |
					SWP_NOZORDER | SWP_NOCOPYBITS);
				pWnd->ShowWindow(SW_SHOWMAXIMIZED);
				
				// return new client area
				::GetClientRect(m_pParentWnd->GetSafeHwnd(), &rectWin);
				pWnd->MoveWindow(rectWin);
				pWnd->SetFocus();
				m_hWordWnd = pWnd->m_hWnd;
			}

			::GetClientRect(m_pParentWnd->GetSafeHwnd(), &rectWin);
			pWnd->MoveWindow(rectWin);
			pWnd->SetFocus();
			pWnd->ShowWindow(SW_SHOWMAXIMIZED);			
		}
		else
		{
			pWnd->ModifyStyle(WS_SYSMENU,0);
			pWnd->ModifyStyle(WS_SIZEBOX,0);
			::GetClientRect(m_pParentWnd->GetSafeHwnd(), &rectWin);
			pWnd->MoveWindow(rectWin);
			pWnd->SetFocus();
		}

		m_hWordWnd = pWnd->m_hWnd;

		if ( pApp->m_WordApp != NULL)
		{
			try
			{
				 pApp->m_WordApp.SetVisible(TRUE);
				 pApp->m_WordApp.SetDisplayStatusBar(TRUE);
			}
			catch (...)
			{
			}
		}
	}
	else
	{
		try
		{
			pApp->m_WordApp.SetVisible(FALSE);
			pApp->m_WordApp.SetDisplayStatusBar(TRUE);
		}
		catch (...)
		{
		}
	}
}

void CWordRptFill::AdjustWordWindowOnSize()
{
	CWnd *pWnd = NULL;

	if (::IsWindow(m_hWordWnd))
	{
		pWnd = CWnd::FromHandle(m_hWordWnd);
	}

	if (pWnd != NULL)
	{
		CRect rectWin;
		::GetClientRect(m_pParentWnd->GetSafeHwnd(), &rectWin);
		pWnd->MoveWindow(rectWin);
		pWnd->SetFocus();
	}	
}

BOOL CWordRptFill::AddNewReport(const CString &strRptTmplFile)
{
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();

	COleVariant covTrue((long)TRUE),covFalse((long)FALSE),covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	COleVariant FileFormat((long)0);
	COleVariant Password(L"");
	COleVariant WritePassword(L"");
	
	CString strWordRptFile;
	COleVariant TmplFile(strRptTmplFile);

	CFileFind find;
	if (!find.FindFile(strRptTmplFile))
	{
		return FALSE;
	}

	BOOL bTrue = TRUE;
	MSWord::Documents docs =  pApp->m_WordApp.GetDocuments();

	try
	{
		m_oDoc = docs.Add(&TmplFile,&covFalse,&FileFormat,&covTrue);
	}
	catch (...)
	{
		bTrue = FALSE;
	}

	return bTrue;
}

long CWordRptFill::LocateReport(CRptDatas *pDatas)
{
	POS pos = pDatas->GetHeadPosition();
	CRptData *pData;
	if(pos != NULL)
	{
		pData = (CRptData*)pDatas->GetAt(pos);
		LocateReport(pData);
	}
	return 0;
}

long CWordRptFill::LocateReport(CRptData *pData)
{
	POS pos = pData->GetHeadPosition();
	CRptBkmk *pRptBkmk;
	if(pos != NULL)
	{
		pRptBkmk = (CRptBkmk*)pData->GetAt(pos);
		LocateReport(pRptBkmk);
	}
	return 0;
}

long CWordRptFill::LocateReport(CRptBkmk *pBkmk)
{
	CTCtrlCntrBaseApp* pApp = (CTCtrlCntrBaseApp*)AfxGetApp();

	if( pApp->m_WordApp == NULL || m_oDoc == NULL)
	{
		return -1;
	}
	
	try
	{
		MSWord::Selection sel;
		MSWord::Bookmarks bookmarks;
		MSWord::Bookmark bookmark;

		sel =  pApp->m_WordApp.GetSelection();

		bookmarks = m_oDoc.GetBookmarks();
		if(!pBkmk->m_strID.IsEmpty() && bookmarks.Exists(pBkmk->m_strID))
		{
			COleVariant vIndex(pBkmk->m_strID);
			bookmark = bookmarks.Item(&vIndex);
			bookmark.Select();
		}
	}
	catch(...)
	{
	}
	return 0;
}