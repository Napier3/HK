//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawCtrlBase.cpp  CXScdDrawCtrlBase


#include "stdafx.h"
#include "XScdDrawCtrlBase.h"

CXScdDrawCtrlBase::CXScdDrawCtrlBase()
{
	//初始化属性

	//初始化成员变量
	m_pGridCtrlTitle = NULL;
	m_pGridCtrlChs = NULL;
	m_bShowChs = TRUE;
	m_pActiveGrid = NULL;
	m_pXScdDrawLine_Ctrl = NULL;
}

CXScdDrawCtrlBase::~CXScdDrawCtrlBase()
{
	if (m_pGridCtrlTitle != NULL)
	{
		delete m_pGridCtrlTitle;
		m_pGridCtrlTitle = NULL;
	}

	if (m_pGridCtrlChs != NULL)
	{
		delete m_pGridCtrlChs;
		m_pGridCtrlChs = NULL;
	}

	if (m_pXScdDrawLine_Ctrl != NULL)
	{
		delete m_pXScdDrawLine_Ctrl;
		m_pXScdDrawLine_Ctrl = NULL;
	}
}

void CXScdDrawCtrlBase::AttachViewWindow(CXDrawBaseInterface_ViewWindow *pViewWindow)
{
	ASSERT (m_pGridCtrlTitle != NULL);
	ASSERT (m_pGridCtrlChs != NULL);

	m_pGridCtrlTitle->AttachViewWindow(pViewWindow);
	m_pGridCtrlChs->AttachViewWindow(pViewWindow);
}

void CXScdDrawCtrlBase::Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
{
	//ASSERT (m_pGridCtrlTitle != NULL && m_pGridCtrlChs != NULL);
	if (m_pGridCtrlTitle!=NULL||m_pGridCtrlChs!=NULL)
	{
		ASSERT (m_pGridCtrlTitle != NULL && m_pGridCtrlChs != NULL);
		m_pGridCtrlTitle->OnDraw(pDC);

		if (m_bShowChs)
		{
			m_pGridCtrlChs->OnDraw(pDC);
		}
		else
		{

		}
	}

	POS pos = GetHeadPosition();
	CXScdDrawLineBase *pLine = NULL;

	while (pos != NULL)
	{
		pLine = (CXScdDrawLineBase *)GetNext(pos);
		pLine->m_nShow = m_bShowChs;
	}

	if (m_pXScdDrawLine_Ctrl != NULL)
	{
		m_pXScdDrawLine_Ctrl->m_nShow = !m_bShowChs;
	}
}

void CXScdDrawCtrlBase::Pick(const CPoint &point, CExBaseList &oList)
{
	if (IsPointInRect(point))
	{
		oList.AddTail(this);
		return;
	}

	CXDrawElements::Pick(point, oList);
}

DWORD CXScdDrawCtrlBase::XCreateElement(CExBaseObject *pData, CWnd *pParentWnd)
{
	m_pXDrawDataRef = pData;

	XCreateElement_Title(pData, pParentWnd);
	XCreateElement_Chs(pData, pParentWnd);

	m_pGridCtrlTitle->m_pCtrlChsGrid = m_pGridCtrlChs;
	m_pGridCtrlChs->m_pCtrlTitleGrid = m_pGridCtrlTitle;

	ReSetTiTleChsWidth();

	CSize sz;
	CalLayout(sz);

	return XCREATE_SUCC;
}

CSize CXScdDrawCtrlBase::CalLayout(CSize &szDraw)
{
	if (m_bShowChs)
	{
		m_nWidth = max(m_pGridCtrlTitle->GetVirtualWidth(), m_pGridCtrlChs->GetVirtualWidth());
		m_nHeight = m_pGridCtrlTitle->GetVirtualHeight() + m_pGridCtrlChs->GetVirtualHeight();
	}
	else
	{
		m_nWidth = m_pGridCtrlTitle->GetVirtualWidth();
		m_nHeight = m_pGridCtrlTitle->GetVirtualHeight();
	}

	CSize sz(m_nWidth, m_nHeight);

	return sz;
}

CSize CXScdDrawCtrlBase::Layout(CPoint &ptTopLeft)
{
	CPoint pt = ptTopLeft;
	m_ptTopLeft = ptTopLeft;
	m_pGridCtrlTitle->SetPosTopLeft(pt);

	if (m_bShowChs)
	{
		pt.y += m_pGridCtrlTitle->GetVirtualHeight();
		m_pGridCtrlChs->SetPosTopLeft(pt);

		//调整通道之间的连线@@@
	}
	else
	{
		//调整控制块之间的连线@@@
	}

	LayoutLines();
	LayoutCtrlLine();

	CSize sz(m_nWidth, m_nHeight);
	return sz;
}

void CXScdDrawCtrlBase::LayoutLines()
{
	if (GetCount() == 0)
	{
		return;
	}

	CXScdDrawLineBase *pLine = (CXScdDrawLineBase*)GetHead();
	CXScdDrawCtrlBase *pBeginCtrl = (CXScdDrawCtrlBase*)pLine->m_pBeginElement;
	POS pos = GetHeadPosition();
	CRect rcCell;
	long nBeginIndex = 0;
	long nEndIndex   = 0;
	CXScdDrawCtrl_CfgGridChsBase *pBeginGridChs = pBeginCtrl->m_pGridCtrlChs;
	CXScdDrawCtrl_CfgGridChsBase *pEndGridChs = m_pGridCtrlChs;
	CExBaseList *pBeginChs = pBeginGridChs->GetGridData();
	CExBaseList *pEndChs   = m_pGridCtrlChs->GetGridData();

    // nBeginIndex=0;
	while (pos != NULL)
	{
		pLine = (CXScdDrawLineBase *)GetNext(pos);
	    //nBeginIndex = pBeginChs->FindIndex(pLine->m_pBeginObj);
		nEndIndex   = pEndChs->FindIndex(pLine->m_pEndObj);

        CExBaseObject *pBeginObj=pLine->m_pBeginObj;
		if (CXScdDrawConstGlobal::OnlyShowUsedGsOutChs())
		{		

			//CExBaseObject *pBeginObj=pLine->m_pBeginObj;
			if (CFGCLASSID_CIECCFG92CH==pBeginObj->GetClassID())
			{
				CIecCfg92Ch *p92Ch = (CIecCfg92Ch*)pBeginObj;
				nBeginIndex=p92Ch->m_nIndexExternal;
			}
			else if(CFGCLASSID_CIECCFGGOUTCH==pBeginObj->GetClassID())
			{
				CIecCfgGoutCh *pGsOutCh=( CIecCfgGoutCh *)pBeginObj;
				nBeginIndex=pGsOutCh->m_nIndexExternal;
			}
			
		}
		else
		{
			nBeginIndex = pBeginChs->FindIndex(pBeginObj);
		}


		if (nBeginIndex == -1 || nEndIndex == -1)
		{
			continue;
		}


		LayoutLine(pBeginGridChs, pEndGridChs, nBeginIndex, nEndIndex, 2, pLine);
		
	}
}

void CXScdDrawCtrlBase::LayoutCtrlLine()
{
	if (m_pXScdDrawLine_Ctrl == NULL)
	{
		return;
	}

	CXScdDrawCtrlBase *pBeginCtrl = (CXScdDrawCtrlBase*)m_pXScdDrawLine_Ctrl->m_pBeginElement;

	if (m_pXScdDrawLine_Ctrl != NULL)
	{
		LayoutLine(pBeginCtrl->m_pGridCtrlTitle, m_pGridCtrlTitle, 0, 0,3, m_pXScdDrawLine_Ctrl);
	}
}

void CXScdDrawCtrlBase::LayoutLine(CXScdDrawCtrl_CfgGridBase *pBeginGridChs, CXScdDrawCtrl_CfgGridBase *pEndGridChs
								   , long nBeginIndex, long nEndIndex,long nEndColIndex, CXScdDrawLineBase *pLine)
{
	CRect rcCell;
/*
      /
     /
   |/_
*/
	if (pBeginGridChs->GetPosTopLeft().x > pEndGridChs->GetPosTopLeft().x)
	{

		pBeginGridChs->GetCellRect(nBeginIndex, 0, &rcCell);
		pLine->m_ptBegin.x = rcCell.left;
		pLine->m_ptBegin.y = (rcCell.top + rcCell.bottom) / 2;

		pEndGridChs->GetCellRect(nEndIndex, nEndColIndex, &rcCell);
		pLine->m_ptEnd.x = rcCell.right;
		pLine->m_ptEnd.y = (rcCell.top + rcCell.bottom) / 2;
	}
	else
/*   _
      /|
     /
    /
*/
	{
		pBeginGridChs->GetCellRect(nBeginIndex, nEndColIndex, &rcCell);
		pLine->m_ptBegin.x = rcCell.right;
		pLine->m_ptBegin.y = (rcCell.top + rcCell.bottom) / 2;

		pEndGridChs->GetCellRect(nEndIndex, 0, &rcCell);
		pLine->m_ptEnd.x = rcCell.left;
		pLine->m_ptEnd.y = (rcCell.top + rcCell.bottom) / 2;
	}
}

void CXScdDrawCtrlBase::InitLineBeginElement(CXDrawElement *pElement)
{
	POS pos = GetHeadPosition();
	CXScdDrawLineBase *pLine = NULL;

	while (pos != NULL) 
	{
		pLine = (CXScdDrawLineBase*)GetNext(pos);
		pLine->m_pBeginElement = pElement;
	}
}

void CXScdDrawCtrlBase::InitLineEndElement(CXDrawElement *pElement)
{
	POS pos = GetHeadPosition();
	CXScdDrawLineBase *pLine = NULL;

	while (pos != NULL)
	{
		pLine = (CXScdDrawLineBase*)GetNext(pos);
		pLine->m_pEndElement = pElement;
	}
}

CXScdDrawLine_Ctrl* CXScdDrawCtrlBase::AddXScdDrawLineCtrl(CXDrawElement *pBeginElement, CXDrawElement *pEndElement, CExBaseObject *pBeginObj, CExBaseObject *pEndObj)
{
	m_pXScdDrawLine_Ctrl = new CXScdDrawLine_Ctrl();

	m_pXScdDrawLine_Ctrl->m_pBeginObj = pBeginObj;
	m_pXScdDrawLine_Ctrl->m_pEndObj   = pEndObj;
	m_pXScdDrawLine_Ctrl->m_pBeginElement = pBeginElement;
	m_pXScdDrawLine_Ctrl->m_pEndElement   = pEndElement;

	return m_pXScdDrawLine_Ctrl;
}

void CXScdDrawCtrlBase::GetAllLines(CXDrawElements &oScdLines)
{
	oScdLines.Append(this);
	oScdLines.AddTail(m_pXScdDrawLine_Ctrl);
}

DWORD CXScdDrawCtrlBase::XCreateElement_Title(CExBaseObject *pData, CWnd *pParentWnd)
{
	return XCREATE_SUCC;
}

DWORD CXScdDrawCtrlBase::XCreateElement_Chs(CExBaseObject *pData, CWnd *pParentWnd)
{
	return XCREATE_SUCC;
}

void CXScdDrawCtrlBase::ReSetTiTleChsWidth()
{
	//生成完标题和通道后重新调增两者的宽度，令其保持一致
	if (m_pGridCtrlChs->GetVirtualWidth()>m_pGridCtrlTitle->GetVirtualWidth())
	{
		long p1=m_pGridCtrlChs->GetVirtualWidth()-TlTLE_COL_WIDTH_SEL;
		//m_pGridCtrlTitle->SetColumnWidth(1,p1/3);
		//m_pGridCtrlTitle->SetColumnWidth(2,p1/3);
		//m_pGridCtrlTitle->SetColumnWidth(3,p1-2*p1/3+1);
		m_pGridCtrlTitle->SetColumnWidth(1,p1/4);
		m_pGridCtrlTitle->SetColumnWidth(2,p1/4);
		m_pGridCtrlTitle->SetColumnWidth(3,p1/4);
		m_pGridCtrlTitle->SetColumnWidth(4,p1-3*p1/4+1);
	}
	else
	{
		long p2=m_pGridCtrlTitle->GetVirtualWidth()-TlTLE_COL_WIDTH_SEL;

		//if (p2/2>m_pGridCtrlChs->GetColumnWidth(1)&&p2/2>m_pGridCtrlChs->GetColumnWidth(2))
		//{
		//	m_pGridCtrlChs->SetColumnWidth(1,p2/2);	
		//	m_pGridCtrlChs->SetColumnWidth(2,p2-p2/2);	
		//}
		//else
		//{
		//	long p3=p2-m_pGridCtrlChs->GetColumnWidth(1);
		//	m_pGridCtrlChs->SetColumnWidth(2,p3);	
		//}
		m_pGridCtrlChs->SetColumnWidth(2,CHANNEL_COL_WIDTH);
		m_pGridCtrlChs->SetColumnWidth(1,p2-CHANNEL_COL_WIDTH);
	}

}

//////////////////////////////////////////////////////////////////////////

LRESULT CXScdDrawCtrlBase::UI_OnSetFont(WPARAM hFont, LPARAM lParam)
{
	if (m_pActiveGrid != NULL)
	{
		return m_pActiveGrid->OnSetFont(hFont, lParam);
	}

	return 0;
}

LRESULT CXScdDrawCtrlBase::UI_OnGetFont(WPARAM hFont, LPARAM lParam)
{
	if (m_pActiveGrid != NULL)
	{
		return m_pActiveGrid->OnGetFont(hFont, lParam);
	}

	return 0;
}

void CXScdDrawCtrlBase::UI_OnLButtonUp(UINT nFlags, CPoint point)
{
	if (m_pGridCtrlTitle != NULL)
	{
		if (m_pGridCtrlTitle->IsPointInRect(point) && m_pGridCtrlTitle == m_pActiveGrid)
		{
			m_pGridCtrlTitle->OnLButtonUp(nFlags, point);
			return;
		}
	}

	if (m_pGridCtrlChs != NULL)
	{
		if (m_pGridCtrlChs->IsPointInRect(point) && m_pGridCtrlChs == m_pActiveGrid)
		{
			m_pGridCtrlChs->OnLButtonUp(nFlags, point);
			return;
		}
	}
}

void CXScdDrawCtrlBase::UI_OnLButtonDown(UINT nFlags, CPoint point)
{
	if (m_pGridCtrlTitle != NULL)
	{
		if (m_pGridCtrlTitle->IsPointInRect(point))
		{
			if (m_pActiveGrid != m_pGridCtrlTitle && m_pActiveGrid != NULL)
			{
				m_pActiveGrid->KillFoucusEditWnd();
			}

			m_pGridCtrlTitle->OnLButtonDown(nFlags, point);
			m_pActiveGrid = m_pGridCtrlTitle;
			return;
		}
	}

	if (m_pGridCtrlChs != NULL)
	{
		if (m_pGridCtrlChs->IsPointInRect(point))
		{
			if (m_pActiveGrid != m_pGridCtrlChs && m_pActiveGrid != NULL)
			{
				m_pActiveGrid->KillFoucusEditWnd();
			}

			m_pGridCtrlChs->OnLButtonDown(nFlags, point);
			m_pActiveGrid = m_pGridCtrlChs;
			return;
		}
	}
}

void CXScdDrawCtrlBase::UI_OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_pActiveGrid == NULL)
	{
		return;
	}

	if (m_pGridCtrlTitle == m_pActiveGrid)
	{
		if (m_pGridCtrlTitle->IsPointInRect(point))
		{
			m_pGridCtrlTitle->OnMouseMove(nFlags, point);
			return;
		}
	}

	if (m_pGridCtrlChs == m_pActiveGrid)
	{
		if (m_pGridCtrlChs->IsPointInRect(point))
		{
			m_pGridCtrlChs->OnMouseMove(nFlags, point);
			return;
		}
	}
}

void CXScdDrawCtrlBase::UI_OnTimer(UINT nIDEvent)
{
	if (m_pActiveGrid != NULL)
	{
		m_pActiveGrid->OnTimer(nIDEvent);
	}
}


BOOL CXScdDrawCtrlBase::UI_OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (m_pActiveGrid != NULL)
	{
		m_pActiveGrid->OnKeyDown(nChar, nRepCnt, nFlags);
	}


	return TRUE;
}

BOOL CXScdDrawCtrlBase::UI_OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (m_pActiveGrid != NULL)
	{
		m_pActiveGrid->OnChar(nChar, nRepCnt, nFlags);
	}

	return TRUE;
}

void CXScdDrawCtrlBase::UI_OnLButtonDblClk(UINT nFlags, CPoint point)
{
	if (m_pGridCtrlTitle != NULL)
	{
		if (m_pGridCtrlTitle->IsPointInRect(point))
		{
			m_pGridCtrlTitle->OnLButtonDblClk(nFlags, point);
			m_pActiveGrid = m_pGridCtrlTitle;
			return;
		}
	}

	if (m_pGridCtrlChs != NULL)
	{
		if (m_pGridCtrlChs->IsPointInRect(point))
		{
			m_pGridCtrlChs->OnLButtonDblClk(nFlags, point);
			m_pActiveGrid = m_pGridCtrlChs;
			return;
		}
	}
}

void CXScdDrawCtrlBase::UI_OnRButtonDblClk(UINT nFlags, CPoint point)
{
	if (m_pGridCtrlTitle != NULL)
	{
		if (m_pGridCtrlTitle->IsPointInRect(point))
		{
			m_pGridCtrlTitle->OnRButtonDblClk(nFlags, point);
			return;
		}
	}

	if (m_pGridCtrlChs != NULL)
	{
		if (m_pGridCtrlChs->IsPointInRect(point))
		{
			m_pGridCtrlChs->OnRButtonDblClk(nFlags, point);
			return;
		}
	}

	m_pActiveGrid = NULL;
}


void CXScdDrawCtrlBase::UI_OnCaptureChanged(CWnd *pWnd)
{
	if (m_pActiveGrid != NULL)
	{
		m_pActiveGrid->OnCaptureChanged(pWnd);
	}
}


void CXScdDrawCtrlBase::UI_OnRButtonUp(UINT nFlags, CPoint point)
{
	if (m_pGridCtrlTitle != NULL)
	{
		if (m_pGridCtrlTitle->IsPointInRect(point))
		{
			m_pGridCtrlTitle->OnRButtonUp(nFlags, point);
			return;
		}
	}

	if (m_pGridCtrlChs != NULL)
	{
		if (m_pGridCtrlChs->IsPointInRect(point))
		{
			m_pGridCtrlChs->OnRButtonUp(nFlags, point);
			return;
		}
	}
}

void CXScdDrawCtrlBase::UI_OnKillFocus(CWnd* pNewWnd)
{
	if (m_pActiveGrid != NULL)
	{
		m_pActiveGrid->OnKillFocus(pNewWnd);
		m_pActiveGrid = NULL;
	}
}

void CXScdDrawCtrlBase::UI_OnRButtonDown(UINT nFlags, CPoint point)
{
	if (m_pGridCtrlTitle != NULL)
	{
		if (m_pGridCtrlTitle->IsPointInRect(point))
		{
			m_pGridCtrlTitle->OnRButtonDown(nFlags, point);
			m_pActiveGrid = m_pGridCtrlTitle;
			return;
		}
	}

	if (m_pGridCtrlChs != NULL)
	{
		if (m_pGridCtrlChs->IsPointInRect(point))
		{
			m_pGridCtrlChs->OnRButtonDown(nFlags, point);
			m_pActiveGrid = m_pGridCtrlChs;
			return;
		}
	}

	m_pActiveGrid = NULL;
}


void CXScdDrawCtrlBase::UI_KillFocus()
{
	if (m_pActiveGrid != NULL)
	{
		m_pActiveGrid->KillFoucusEditWnd();
		m_pActiveGrid = NULL;
	}
}
