//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawCtrl_ThumbBase.cpp  XScdDrawCtrl_ThumbBase


#include "stdafx.h"
#include "XScdDrawCtrl_ThumbBase.h"

CXScdDrawCtrl_ThumbBase::CXScdDrawCtrl_ThumbBase()
{
	m_pSclCtrls=NULL;     
}

CXScdDrawCtrl_ThumbBase::~CXScdDrawCtrl_ThumbBase()
{
	RemoveAll();
}

void CXScdDrawCtrl_ThumbBase::Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
{
	CFont *pFont;
	pFont=pDC->SelectObject(g_pGlobalFont12);
	pDC->SetTextColor(RGB(0,0,0));


	CRect rc(m_ptTopLeft.x, m_ptTopLeft.y, m_ptTopLeft.x + m_nWidth, m_ptTopLeft.y + m_nHeight);
	pDC->Rectangle(rc);
	CmDrawTextRect(pDC, m_strName, RGB(0, 0, 0), rc, RGB(192,192,192),   g_lfGlobalFont12, TRANSPARENT, DT_VCENTER|DT_WORDBREAK|DT_CENTER, 0);

	pDC->SelectObject(pFont);
}


DWORD CXScdDrawCtrl_ThumbBase::XCreateElement(CExBaseObject *pData, CWnd *pParentWnd)
{
	m_pXDrawDataRef = pData;

	CreateCtrlLines();

	CSize sz;
	CalLayout(sz);

	return XCREATE_SUCC;
}

CSize CXScdDrawCtrl_ThumbBase::CalLayout(CSize &szDraw)
{
	m_nWidth = XSCDDRAW_THUMBNAIL_CTRL_WIDTH;
	m_nHeight = XSCDDRAW_THUMBNAIL_IED_HEIGHT_CTRLS;

	CSize sz(m_nWidth, m_nHeight);

	return sz;
}

CSize CXScdDrawCtrl_ThumbBase::Layout(CPoint &ptTopLeft)
{
	m_ptTopLeft = ptTopLeft;

	CSize sz(m_nWidth, m_nHeight);
	return sz;
}

CXScdDrawLineBase* CXScdDrawCtrl_ThumbBase::FindLineByBeginRef(CExBaseObject *pBeginRef)
{
	POS pos = GetHeadPosition();
	CXScdDrawLineBase *p = NULL, *pFind = NULL;

	while (pos != NULL)
	{
		p = (CXScdDrawLineBase *)GetNext(pos);

		if (p->m_pBeginObj == pBeginRef)
		{
			pFind = p;
			break;
		}
	}

	return pFind;
}

void CXScdDrawCtrl_ThumbBase::GetAllLines(CXDrawElements &oScdLines)
{
	oScdLines.Append(this);
}

void CXScdDrawCtrl_ThumbBase::GetAllKindsLines(CXDrawElements &oScdLines,CXDrawElements &oScdToBusLines)
{
	POS pos=GetHeadPosition();
	CXScdDrawLineBase *pXScdDrawLineBase=NULL;
	while (pos!=NULL)
	{
		pXScdDrawLineBase=(CXScdDrawLineBase*)GetNext(pos);
		if (pXScdDrawLineBase->GetClassID()==XSCDDRAW_LINE_CTRL)
		{
			//oScdLines.AddTail(pXScdDrawLineBase);
           
			
		}
		else if(pXScdDrawLineBase->GetClassID()==XSCDDRAW_LINE_TOBUS)
		{
            oScdToBusLines.AddTail(pXScdDrawLineBase);
		}

	}

}
