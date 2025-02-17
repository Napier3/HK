//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawCtrl_SclSvOut.cpp  CXScdDrawCtrl_SclSvOut


#include "stdafx.h"
#include "XScdDrawCtrl_SclSvOut.h"

//////////////////////////////////////////////////////////////////////////
//CXScdDrawCtrl_SclGridTitleSvOut
CXScdDrawCtrl_SclGridTitleSvOut::CXScdDrawCtrl_SclGridTitleSvOut()
{

}

CXScdDrawCtrl_SclGridTitleSvOut::~CXScdDrawCtrl_SclGridTitleSvOut()
{

}

void CXScdDrawCtrl_SclGridTitleSvOut::ShowTitle(CExBaseObject *pData)
{
	CIecCfg92Data *p92Data = (CIecCfg92Data*)pData;
	Show_Check(pData, 0, 0, &p92Data->m_nUseFlag);
	Show_StaticString(pData, 0, 1, _T("SVOUT"));
	Show_Hex(pData, 0, 2, &p92Data->m_dwAppID, 2);
	Show_Fiber(pData, 0, 3,    &p92Data->m_nFiberIndex);




}

//////////////////////////////////////////////////////////////////////////
//CXScdDrawCtrl_SclGridChsSvOut
CXScdDrawCtrl_SclGridChsSvOut::CXScdDrawCtrl_SclGridChsSvOut()
{

}

CXScdDrawCtrl_SclGridChsSvOut::~CXScdDrawCtrl_SclGridChsSvOut()
{

}


void CXScdDrawCtrl_SclGridChsSvOut::ShowData(CExBaseObject *pData, int& nRow, BOOL bInsertRow)
{
	UINT nClassID = pData->GetClassID();
	ASSERT (nClassID == CFGCLASSID_CIECCFG92CH);

	CIecCfg92Ch *p92Ch = (CIecCfg92Ch*)pData;

	if (CXScdDrawConstGlobal::OnlyShowUsedSvOutChs())
	{
		if (p92Ch->m_nIndexExternal == -1)
		{
			return;
		}
	}

	Show_Index(pData, nRow, 0);
	Show_String(pData, nRow, 1, &p92Ch->m_strName, EndEditCell_String_NameAndID );
	ShowCfgCh_AppCh(pData, nRow, 2, &p92Ch->m_strAppChID, iecfg_SmvAppChDataType);

	//编号改变
	if (CXScdDrawConstGlobal::OnlyShowUsedSvOutChs())
	{
		if (p92Ch->m_nIndexExternal != 65535)
		{
			CString strIndex;
			long nIndex=m_pDatas->FindIndex(pData);
			strIndex.Format(_T("%d / %d"), p92Ch->m_nIndexExternal+1, nIndex+1);
			SetItemText(nRow, 0, strIndex);
		}
	}

	nRow++;
}

//////////////////////////////////////////////////////////////////////////
//CXScdDrawCtrl_SclSvOut
CXScdDrawCtrl_SclSvOut::CXScdDrawCtrl_SclSvOut()
{
	//初始化属性

	//初始化成员变量
}

CXScdDrawCtrl_SclSvOut::~CXScdDrawCtrl_SclSvOut()
{
}

void CXScdDrawCtrl_SclSvOut::Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
{
	CXScdDrawCtrlBase::Draw(pDC, fZoomRatio, ptOffset);
}


// DWORD CXScdDrawCtrl_SclSvOut::XCreateElement(CExBaseObject *pData, CWnd *pParentWnd)
// {
// 	UINT nClassID = pData->GetClassID();
// 
// 	if (nClassID != CFGCLASSID_CIECCFG92DATA || nClassID != CFGCLASSID_CIECCFG91DATA || nClassID != CFGCLASSID_CIECCFG6044DATA)
// 	{
// 		return XCREATE_FAIL;
// 	}
// 
// 	return XCREATE_SUCC;
// }


DWORD CXScdDrawCtrl_SclSvOut::XCreateElement_Title(CExBaseObject *pData, CWnd *pParentWnd)
{
	ASSERT (m_pGridCtrlTitle == NULL);
	m_pGridCtrlTitle = new CXScdDrawCtrl_SclGridTitleSvOut();
	m_pGridCtrlTitle->Create(pParentWnd);
	m_pGridCtrlTitle->InitGrid();
	m_pGridCtrlTitle->ShowDatas((CExBaseList*)pData);

	return XCREATE_SUCC;
}

DWORD CXScdDrawCtrl_SclSvOut::XCreateElement_Chs(CExBaseObject *pData, CWnd *pParentWnd)
{
	ASSERT (m_pGridCtrlChs == NULL);
	m_pGridCtrlChs = new CXScdDrawCtrl_SclGridChsSvOut();
	m_pGridCtrlChs->Create(pParentWnd);
	m_pGridCtrlChs->InitGrid();

	CIecCfgDataBase *pIecCfgData = (CIecCfgDataBase*)pData;
	m_pGridCtrlChs->ShowDatas(pIecCfgData->m_pCfgChs);

	return XCREATE_SUCC;
}

