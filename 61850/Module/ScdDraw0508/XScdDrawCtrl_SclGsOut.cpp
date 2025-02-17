//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawCtrl_SclGsOut.cpp  CXScdDrawCtrl_SclGsOut


#include "stdafx.h"
#include "XScdDrawCtrl_SclGsOut.h"


//////////////////////////////////////////////////////////////////////////
//CXScdDrawCtrl_SclGridTitleGsOut
CXScdDrawCtrl_SclGridTitleGsOut::CXScdDrawCtrl_SclGridTitleGsOut()
{

}

CXScdDrawCtrl_SclGridTitleGsOut::~CXScdDrawCtrl_SclGridTitleGsOut()
{

}

void CXScdDrawCtrl_SclGridTitleGsOut::ShowTitle(CExBaseObject *pData)
{
	UINT nClassID = pData->GetClassID();
	// 	ASSERT (nClassID == CFGCLASSID_CIECCFG92CH);

	CIecCfgGoutData *pGoutData=(CIecCfgGoutData *)pData;
	//CIecCfg92Data *p92Data = (CIecCfg92Data*)pData;
	Show_Check(pData, 0, 0, &pGoutData->m_nUseFlag);
	Show_StaticString(pData, 0, 1, _T("GSOUT"));
	Show_Hex(pData, 0, 2, &pGoutData->m_dwAppID, 2);

	Show_Fiber(pData, 0, 3, &pGoutData->m_nFiberIndex);

}

//////////////////////////////////////////////////////////////////////////
//CXScdDrawCtrl_SclGridChsGsOut
CXScdDrawCtrl_SclGridChsGsOut::CXScdDrawCtrl_SclGridChsGsOut()
{

}

CXScdDrawCtrl_SclGridChsGsOut::~CXScdDrawCtrl_SclGridChsGsOut()
{

}


void CXScdDrawCtrl_SclGridChsGsOut::ShowData(CExBaseObject *pData, int& nRow, BOOL bInsertRow)
{
	UINT nClassID = pData->GetClassID();
// 	ASSERT (nClassID == CFGCLASSID_CIECCFG92CH);

	CIecCfg92Ch *p92Ch = (CIecCfg92Ch*)pData;

	if (CXScdDrawConstGlobal::OnlyShowUsedGsOutChs())
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
	if (CXScdDrawConstGlobal::OnlyShowUsedGsOutChs())
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
//CXScdDrawCtrl_SclGsOut
CXScdDrawCtrl_SclGsOut::CXScdDrawCtrl_SclGsOut()
{
	//初始化属性

	//初始化成员变量
}

CXScdDrawCtrl_SclGsOut::~CXScdDrawCtrl_SclGsOut()
{
}

void CXScdDrawCtrl_SclGsOut::Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
{
	CXScdDrawCtrlBase::Draw(pDC, fZoomRatio, ptOffset);
}


DWORD CXScdDrawCtrl_SclGsOut::XCreateElement_Title(CExBaseObject *pData, CWnd *pParentWnd)
{
	ASSERT (m_pGridCtrlTitle == NULL);
	m_pGridCtrlTitle = new CXScdDrawCtrl_SclGridTitleGsOut();
	m_pGridCtrlTitle->Create(pParentWnd);
	m_pGridCtrlTitle->InitGrid();
	m_pGridCtrlTitle->ShowDatas((CExBaseList*)pData);

	return XCREATE_SUCC;
}

DWORD CXScdDrawCtrl_SclGsOut::XCreateElement_Chs(CExBaseObject *pData, CWnd *pParentWnd)
{
	ASSERT (m_pGridCtrlChs == NULL);
	m_pGridCtrlChs = new CXScdDrawCtrl_SclGridChsGsOut();
	m_pGridCtrlChs->Create(pParentWnd);
	m_pGridCtrlChs->InitGrid();

	CIecCfgDataBase *pIecCfgData = (CIecCfgDataBase*)pData;
	m_pGridCtrlChs->ShowDatas(pIecCfgData->m_pCfgChs);

	return XCREATE_SUCC;
}

