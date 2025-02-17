//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawCtrl__CfgGridChs.cpp  CXScdDrawCtrl__CfgGridChs


#include "stdafx.h"
#include "XScdDrawCtrl_CfgGrid.h"

//////////////////////////////////////////////////////////////////////////
//CXScdDrawCtrl_CfgGridBase
CXScdDrawCtrl_CfgGridBase::CXScdDrawCtrl_CfgGridBase()
{

}

CXScdDrawCtrl_CfgGridBase::~CXScdDrawCtrl_CfgGridBase()
{

}

void CXScdDrawCtrl_CfgGridBase::SetMidifiedFlag(CExBaseObject *pData, BOOL bModified)
{
	CExBaseListXGridCtrlBase::SetMidifiedFlag(pData, bModified);

	if ((m_pGridRefWnd != NULL) && bModified)
	{
		m_pGridRefWnd->PostMessage(WM_XSCDDRAW_DATACHANGED, (WPARAM)pData, 0);
	}
}

CDataType* CXScdDrawCtrl_CfgGridBase::FindDataType(const CString &strDataType)
{
	CDataType *pDataType = CCfgDataMngrConstGlobal::FindIecRtdDataType(strDataType);

	return pDataType;
}


void  CXScdDrawCtrl_CfgGridBase::ShowCfgCh_AppCh(CExBaseObject *pData, const int& nRow, const int& nCol, CString *pstrAppCh,const CString &strDataType, BOOL bSetColor)
{
	CIecCfgDataSmvChBase *pSmvCh = (CIecCfgDataSmvChBase*)pData;

	if (iecfg_IsCurrSmvChType(pSmvCh->m_strChType))
	{
		Show_DataType_Val(pData, nRow, nCol, iecfg_SmvAppChDataType_I, pstrAppCh, EndEditCell_AppCh);
	}
	else if (iecfg_IsVolSmvChType(pSmvCh->m_strChType))
	{
		Show_DataType_Val(pData, nRow, nCol, iecfg_SmvAppChDataType_U, pstrAppCh, EndEditCell_AppCh);
	}
	else if (iecfg_IsUTCTimeSmvChType(pSmvCh->m_strChType))
	{
		// 		Show_String(pData, nRow, nCol, pstrAppCh);
		Show_DataType_Val(pData, nRow, nCol, iecfg_SmvAppChDataType_T, pstrAppCh, EndEditCell_AppCh);
	}
	else
	{
		Show_DataType_Val(pData, nRow, nCol, iecfg_SmvAppChDataType_U, pstrAppCh, EndEditCell_AppCh);
	}
}


void CXScdDrawCtrl_CfgGridBase::EndEditCell_AppCh (int nRow, int nCol,CGridCell *pCell, CXGridCtrlBase *pGrid)
{
	EndEditCell_DataType_Val(nRow, nCol, pCell, pGrid);
}


//////////////////////////////////////////////////////////////////////////
//CXScdDrawCtrl_CfgGridTitleBase
CXScdDrawCtrl_CfgGridTitleBase::CXScdDrawCtrl_CfgGridTitleBase()
{
	m_nAdjustBeginCol = -1;
	//初始化属性

	//初始化成员变量
}

CXScdDrawCtrl_CfgGridTitleBase::~CXScdDrawCtrl_CfgGridTitleBase()
{
}


void CXScdDrawCtrl_CfgGridTitleBase::InitGrid()
{
	SetListMode(FALSE);
	SetRowCount(1);
	SetColumnCount(4);
	SetFixedRowCount(0);
	SetFixedColumnCount(0);
	InitGridTitle();
}

void CXScdDrawCtrl_CfgGridTitleBase::InitGridTitle()
{
	SetColumnWidth(0, TlTLE_COL_WIDTH_SEL);
	SetColumnWidth(1, TlTLE_COL_WIDTH_CTRLTYPE);
	SetColumnWidth(2,TlTLE_COL_WIDTH_APPID);
	SetColumnWidth(3, TlTLE_COL_WIDTH_FIBER);
}

void CXScdDrawCtrl_CfgGridTitleBase::ShowDatas(CExBaseList *pDatas)
{
	ClearSelect();
	CTLinkList <_ExBaseCellData> listVCellData;
	BackListCellData(listVCellData);
	m_pCurrData = NULL;
	m_pDatas = pDatas;
	SetRowCount(1);

	if (pDatas == NULL)
	{
		return;
	}

	
	COLORREF clr = RGB(34,161,34);
	SelectRow(0);
	SetTextBkColor(clr);

	ShowTitle(pDatas);
	SetRowHeight(0, EXBASEGRID_ROWHEIGHT);
	ResetScrollBars();
	InvalidateGrid(FALSE);
}

void CXScdDrawCtrl_CfgGridTitleBase::ShowData(CExBaseObject *pData, int& nRow, BOOL bInsertRow)
{

}

void  CXScdDrawCtrl_CfgGridTitleBase::Show_Fiber(CExBaseObject *pData, const int& nRow, const int& nCol, long *pnFiber, GRID_CELL_EDIT_FUNC pFunc)
{
	CIecCfgDataBase *pIecCfgData = (CIecCfgDataBase*)pData;
	CString strDataType =_T("AppFiberPort");

	if (pFunc != NULL)
	{
		Show_DataType_Val(pData, nRow, nCol, strDataType, pnFiber, pFunc);
	}
	else
	{
		Show_DataType_Val(pData, nRow, nCol, strDataType, pnFiber,NULL);
	}
}


//////////////////////////////////////////////////////////////////////////
//CXScdDrawCtrl_CfgGridChsBase
CXScdDrawCtrl_CfgGridChsBase::CXScdDrawCtrl_CfgGridChsBase()
{
	m_nAdjustBeginCol = 0;
	//初始化属性

	//初始化成员变量
}

CXScdDrawCtrl_CfgGridChsBase::~CXScdDrawCtrl_CfgGridChsBase()
{

}


void CXScdDrawCtrl_CfgGridChsBase::InitGrid()
{
	SetListMode(FALSE);
	SetRowCount(1);
	SetColumnCount(3);
	SetFixedRowCount(0);
	SetFixedColumnCount(0);
	InitGridTitle();
}

void CXScdDrawCtrl_CfgGridChsBase::InitGridTitle()
{
	SetColumnWidth(0,TlTLE_COL_WIDTH_SEL);

}


void CXScdDrawCtrl_CfgGridChsBase::ShowDatas(CExBaseList *pDatas)
{
	ClearSelect();
	CTLinkList <_ExBaseCellData> listVCellData;
	BackListCellData(listVCellData);
	m_pCurrData = NULL;

	if (pDatas == NULL)
	{
		SetRowCount(1);
		return;
	}

	m_pDatas = pDatas;
	CExBaseObject *pObj = NULL;	
	POS pos = pDatas->GetHeadPosition();
	int nRowIndex = 0;
	long nCalRows = pDatas->GetCount();
	SetRowCount(nCalRows);

	while (pos != NULL)
	{
		pObj = pDatas->GetNext(pos);
		ShowData(pObj, nRowIndex, FALSE);
	}

	SetRowCount(nRowIndex);

	for (nRowIndex=1; nRowIndex<m_nRows; nRowIndex++)
	{
		SetRowHeight(nRowIndex, EXBASEGRID_ROWHEIGHT);
	}

	AdjustAllCols();
	ResetScrollBars();
	InvalidateGrid(FALSE);
}

void CXScdDrawCtrl_CfgGridChsBase::ShowData(CExBaseObject *pData, int& nRow, BOOL bInsertRow)
{
	
}

// 
// void  CXScdDrawCtrl_CfgGridChsBase::Show_Fiber(CExBaseObject *pData, const int& nRow, const int& nCol, long *pnFiber, GRID_CELL_EDIT_FUNC pFunc)
// {
// 	CIecCfgDataBase *pIecCfgData = (CIecCfgDataBase*)pData;
// 	CString strDataType = GetAppPortDataType();
// 
// 	if (pFunc != NULL)
// 	{
// 		Show_DataType_Val(pData, nRow, nCol, strDataType, pnFiber, pFunc);
// 	}
// 	else
// 	{
// 		Show_DataType_Val(pData, nRow, nCol, strDataType, pnFiber, EndEditCell_Fiber);
// 	}
// }
// 
// void CXScdDrawCtrl_CfgGridChsBase::EndEditCell_Fiber (int nRow, int nCol,CGridCell *pCell, CXGridCtrlBase *pGrid)
// {
// 	PEXBASECELLDATA pVellData = (_ExBaseCellData*)pCell->lParam;
// 	ASSERT (pVellData != NULL);
// 	CIecCfgDataGridBase *pIecCfgDataGrid = (CIecCfgDataGridBase*)pGrid;
// 
// 	CIecCfgDataBase *pIecCfgData = (CIecCfgDataBase*)pVellData->pObj;
// 	long nFiberIndex = pIecCfgData->m_nFiberIndex;
// 	EndEditCell_DataType_Val(nRow, nCol, pCell, pGrid);
// 
// 	if (nFiberIndex == pIecCfgData->m_nFiberIndex)
// 	{
// 		return;
// 	}
// 
// 	if (pIecCfgDataGrid->ValidateIecCfgDatFiberIndex(pIecCfgData))
// 	{
// 		return;
// 	}
// 
// 	pIecCfgData->m_nFiberIndex = nFiberIndex;
// 	pIecCfgDataGrid->FreeExBaseCellData(nRow, nCol);
// 	pIecCfgDataGrid->Show_Fiber(pIecCfgData, nRow, nCol, &pIecCfgData->m_nFiberIndex);
// }