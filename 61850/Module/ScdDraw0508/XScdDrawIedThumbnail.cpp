//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawIed.cpp  CXScdDrawIed


#include "stdafx.h"
#include "XScdDrawIedThumbnail.h"

CXScdDrawIedThumbnail::CXScdDrawIedThumbnail()
{
	//初始化属性
	m_pCloseIedThumb=NULL;
	m_pRefIed=NULL;
	m_b_ProtMeas_MuCtrl=0;
	nCountRefIeds=0;
	m_pRefIedsThumbGroups=new CExBaseList();
	m_pRefLines=new CExBaseList();

	//初始化成员变量
}

CXScdDrawIedThumbnail::~CXScdDrawIedThumbnail()
{
}

void CXScdDrawIedThumbnail::RightRemovd(int nRange)
{
	POS pos=GetHeadPosition();
	CXDrawElement *pXDrawElement = NULL;
	while (pos!=NULL)
	{
		pXDrawElement=(CXDrawElement*)GetNext(pos);
        pXDrawElement->m_ptTopLeft.x+=nRange;

	}
	

}

void CXScdDrawIedThumbnail::LeftRemovd(int nRange)
{
	POS pos=GetHeadPosition();
	CXDrawElement *pXDrawElement = NULL;
	while (pos!=NULL)
	{
		pXDrawElement=(CXDrawElement*)GetNext(pos);
		pXDrawElement->m_ptTopLeft.x-=nRange;

	}


}


int CXScdDrawIedThumbnail::GetAllLinesLength()
 {
	// CExBaseList *pRefIedsThumbGroup=m_pRefIedsThumbGroups;
	 CExBaseList *pRefLines=m_pRefLines;
	 POS pos=pRefLines->GetHeadPosition();
	 
	 CXScdDrawLineBase *pLine=NULL;
	 //CXScdDrawIedThumbnail *pXScdDrawIedThumbnail =NULL;
	 int Length_AllLine=0;
	 while (pos!=NULL)
	 {
		// pXScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)pRefIedsThumbGroup->GetNext(pos);
		// pRefLines=GetLinesBetweenIedsThumbnail(pXScdDrawIedThumbnail);
   

			pLine=(CXScdDrawLineBase*)pRefLines->GetNext(pos);
			if (pLine->m_pBeginElement->m_ptTopLeft.x==0||pLine->m_pEndElement->m_ptTopLeft.x==0)
			{
				continue;
			}
           Length_AllLine+=abs(pLine->m_pBeginElement->m_ptTopLeft.x-pLine->m_pEndElement->m_ptTopLeft.x);
		
	 }
    return Length_AllLine;
}

CExBaseList *CXScdDrawIedThumbnail::GetLinesBetweenIedsThumbnail(CXScdDrawIedThumbnail *pXScdDrawIedThumbnail)
{
	CExBaseList *pAllLines=m_pRefLines;
	CExBaseList *pRefLines=new CExBaseList();
	CXDrawElement *pBeginElement=NULL;
	CXDrawElement *pEndElement=NULL;
	CXScdDrawIedThumbnail *pDrawIedThumbnail_Begin=NULL;
	CXScdDrawIedThumbnail *pDrawIedThumbnail_End=NULL;
	CXScdDrawLineBase *pLine = NULL;
	POS pos=pAllLines->GetHeadPosition();
	while (pos!=NULL)
	{
		pLine=(CXScdDrawLineBase*)pAllLines->GetNext(pos);
		if (pLine==NULL)
		{
			continue;
		}
		pBeginElement=pLine->m_pBeginElement;
		pEndElement=pLine->m_pEndElement;
		pDrawIedThumbnail_Begin=(CXScdDrawIedThumbnail *)pBeginElement->GetParent();
		pDrawIedThumbnail_End=(CXScdDrawIedThumbnail *)pEndElement->GetParent();
		if (pDrawIedThumbnail_Begin==pXScdDrawIedThumbnail||pDrawIedThumbnail_End==pXScdDrawIedThumbnail)
		{
			pRefLines->AddNewChild(pLine);
		}

	}
	return pRefLines;

}

void CXScdDrawIedThumbnail::Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
{
	if (m_ptTopLeft.x==0&&m_ptTopLeft.y==0)
	{
		return;
	}
	CFont *pFont;
	CBrush brush1;
	pFont=pDC->SelectObject(g_pGlobalFont12);
	UINT nOldTextColor = pDC->SetTextColor(RGB(0,0,0));
	UINT nOldBkColor = pDC->SetBkColor(RGB(150,200,156));
	brush1.CreateSolidBrush(RGB(192,192,192));
	CBrush *pOldBrush1 = pDC->SelectObject(&brush1);

	CPoint ptTopLeft = m_ptTopLeft;
	CRect rc_Ied(ptTopLeft.x, ptTopLeft.y, (ptTopLeft.x+m_nWidth), ptTopLeft.y+m_nHeight);
	rc_Ied.DeflateRect(1,1,1,1);
	CPen pen1(PS_SOLID, 1, RGB(0, 0, 255));//重新定义IED正文的画笔和画刷
	CPen *pOldPen1 = pDC->SelectObject(&pen1);
	pDC->Rectangle(rc_Ied);

	CPoint ptTopLeft_ID;
	ptTopLeft_ID.x=ptTopLeft.x;
	ptTopLeft_ID.y = ptTopLeft.y + XSCDDRAW_THUMBNAIL_IED_HEIGHT_TYPE - 1;

	if (m_b_ProtMeas_MuCtrl==IEDTHUMBNAILTYPE_MUCTRL||m_b_ProtMeas_MuCtrl==IEDTHUMBNAILTYPE_PROCMEAS2)
	{
		ptTopLeft.y += m_nHeight - XSCDDRAW_THUMBNAIL_IED_HEIGHT_TYPE;	
		ptTopLeft_ID.y= ptTopLeft.y - XSCDDRAW_THUMBNAIL_IED_HEIGHT_ID + 1;
	}

	CRect rc_IedName(ptTopLeft.x, ptTopLeft.y, ptTopLeft.x+m_nWidth, ptTopLeft.y + XSCDDRAW_THUMBNAIL_IED_HEIGHT_TYPE);//定义IED的名字和ID的背景区域
	CRect rc_IedID(ptTopLeft_ID.x,ptTopLeft_ID.y, (ptTopLeft_ID.x+m_nWidth/2), (ptTopLeft_ID.y+XSCDDRAW_THUMBNAIL_IED_HEIGHT_ID));
	CRect rc_IP = rc_IedID;
	rc_IP.left  = rc_IedID.right;
	rc_IP.right = ptTopLeft_ID.x + m_nWidth;

	rc_IedName.DeflateRect(1,1,1,1);
	rc_IedID.DeflateRect(1,1,1,1);
	rc_IP.DeflateRect(1,1,1,1);

	pDC->Rectangle(rc_IedName);
	pDC->Rectangle(rc_IedID);
	pDC->Rectangle(rc_IP);
	CRect rc_IedName_Text;

	rc_IedName_Text = CRect(ptTopLeft.x, ptTopLeft.y, ptTopLeft.x+m_nWidth, ptTopLeft.y+XSCDDRAW_THUMBNAIL_IED_HEIGHT_TYPE);
	CRect rc_IedID_Text(ptTopLeft_ID.x, ptTopLeft_ID.y, ptTopLeft_ID.x+m_nWidth/2, ptTopLeft_ID.y+XSCDDRAW_THUMBNAIL_IED_HEIGHT_ID);
	CRect rc_IP_Text = rc_IP;
	rc_IP_Text.DeflateRect(1, 0, 1, 0);

	CmDrawTextRect(pDC, m_strName, RGB(0, 0, 0), rc_IedName_Text, RGB(192,192,192), g_lfGlobalFont12, TRANSPARENT, DT_VCENTER|DT_WORDBREAK|DT_CENTER, 0);
	CmDrawTextRect(pDC, m_strID,   RGB(0, 0, 0), rc_IedID_Text, RGB(192,192,192),   g_lfGlobalFont12, TRANSPARENT, DT_VCENTER|DT_WORDBREAK|DT_CENTER, 0);
	//CmDrawTextRect(pDC, m_pRefIed->m_strIP,   RGB(0, 0, 0), rc_IP_Text, RGB(192,192,192),   g_lfGlobalFont12, TRANSPARENT, DT_VCENTER|DT_WORDBREAK|DT_CENTER, 0);
	CString p_strCountRefIeds;
	p_strCountRefIeds.Format(_T("%d"),nCountRefIeds);
		CmDrawTextRect(pDC, p_strCountRefIeds,   RGB(0, 0, 0), rc_IP_Text, RGB(192,192,192),   g_lfGlobalFont12, TRANSPARENT, DT_VCENTER|DT_WORDBREAK|DT_CENTER, 0);
	
	CXDrawElements::Draw(pDC, fZoomRatio, ptOffset);

	pDC->SelectObject(pOldPen1);
	pDC->SelectObject(pOldBrush1);
	pDC->SetTextColor(nOldTextColor);
	pDC->SetBkColor(nOldBkColor);
}

void CXScdDrawIedThumbnail::XCreateCtrl(CSclIed *pIedData, CWnd *pParentWnd)
{
	CSclIed *pTempIed=pIedData;
	POS pos=pTempIed->GetHeadPosition();
	CExBaseObject *pIedCtrl=NULL;
	UINT nClassID = 0;

	while (pos!=NULL)
	{
		pIedCtrl=pTempIed->GetNext(pos);
		nClassID = pIedCtrl->GetClassID();
	
		if (nClassID==SCLIECCLASSID_CTRLS_GS_IN)
		{
			CSclCtrlsGsIn *pSclCtrlsGsIn=(CSclCtrlsGsIn*)pIedCtrl;
			CXScdDrawCtrl_ThumbGsIn *pNew=new CXScdDrawCtrl_ThumbGsIn();
          pNew->m_pSclCtrls=pIedCtrl;
			AddNewChild(pNew);
			pNew->XCreateElement(pSclCtrlsGsIn,pParentWnd);
		}
		else if(nClassID==SCLIECCLASSID_CTRLS_GS_OUT)
		{
			CSclCtrlsGsOut *pSclCtrlsGsOut=(CSclCtrlsGsOut*)pIedCtrl;
			CXScdDrawCtrl_ThumbGsOut *pNew=new CXScdDrawCtrl_ThumbGsOut();
			pNew->m_pSclCtrls=pIedCtrl;
			AddNewChild(pNew);
			pNew->XCreateElement(pSclCtrlsGsOut,pParentWnd);
		}
		else if(nClassID==SCLIECCLASSID_CTRLS_SMV_IN)
		{
			CSclCtrlsSmvIn *pSclCtrlsSmvIn=(CSclCtrlsSmvIn*)pIedCtrl;
			CXScdDrawCtrl_ThumbSvIn *pNew=new CXScdDrawCtrl_ThumbSvIn();
			pNew->m_pSclCtrls=pIedCtrl;
			AddNewChild(pNew);
			pNew->XCreateElement(pSclCtrlsSmvIn,pParentWnd);
		}
		else if(nClassID==SCLIECCLASSID_CTRLS_SMV_OUT)
		{
			CSclCtrlsSmvOut *pSclCtrlsSmvOut=(CSclCtrlsSmvOut*)pIedCtrl;
			CXScdDrawCtrl_ThumbSvOut *pNew=new CXScdDrawCtrl_ThumbSvOut();
			pNew->m_pSclCtrls=pIedCtrl;
			AddNewChild(pNew);
			pNew->XCreateElement(pSclCtrlsSmvOut,pParentWnd);			
		}
		 
	}
}
//
//void CXScdDrawIedThumbnail::GetCount_RefIed(CSclIed *pIedData)
//{
//	CSclIed *pTempIed=pIedData;
//	POS pos=pTempIed->GetHeadPosition();
//	CExBaseObject *pIedCtrl=NULL;
//	UINT nClassID = 0;
//
//	while (pos!=NULL)
//	{
//		pIedCtrl=pTempIed->GetNext(pos);
//		nClassID = pIedCtrl->GetClassID();
//
//		if (nClassID==SCLIECCLASSID_CTRLS_GS_IN)
//		{
//			CSclCtrlsGsIn *pSclCtrlsGsIn=(CSclCtrlsGsIn*)pIedCtrl;
//			//CXScdDrawCtrl_ThumbGsIn *pNew=new CXScdDrawCtrl_ThumbGsIn();
//			//AddNewChild(pNew);
//			//pNew->XCreateElement(pSclCtrlsGsIn,pParentWnd);
//		}
//		else if(nClassID==SCLIECCLASSID_CTRLS_GS_OUT)
//		{
//			CSclCtrlsGsOut *pSclCtrlsGsOut=(CSclCtrlsGsOut*)pIedCtrl;
//			//CXScdDrawCtrl_ThumbGsOut *pNew=new CXScdDrawCtrl_ThumbGsOut();
//			//AddNewChild(pNew);
//			//pNew->XCreateElement(pSclCtrlsGsOut,pParentWnd);
//		}
//		else if(nClassID==SCLIECCLASSID_CTRLS_SMV_IN)
//		{
//			CSclCtrlsSmvIn *pSclCtrlsSmvIn=(CSclCtrlsSmvIn*)pIedCtrl;
//			//CXScdDrawCtrl_ThumbSvIn *pNew=new CXScdDrawCtrl_ThumbSvIn();
//			//AddNewChild(pNew);
//			//pNew->XCreateElement(pSclCtrlsSmvIn,pParentWnd);
//		}
//		else if(nClassID==SCLIECCLASSID_CTRLS_SMV_OUT)
//		{
//			CSclCtrlsSmvOut *pSclCtrlsSmvOut=(CSclCtrlsSmvOut*)pIedCtrl;
//			//CXScdDrawCtrl_ThumbSvOut *pNew=new CXScdDrawCtrl_ThumbSvOut();
//			//AddNewChild(pNew);
//			//pNew->XCreateElement(pSclCtrlsSmvOut,pParentWnd);
//		}
//	}
//}


void CXScdDrawIedThumbnail::GetAllLines(CXDrawElements &oScdLines)
{
	CXScdDrawCtrl_ThumbBase *p = NULL;
	POS pos = GetHeadPosition();

	while (pos != NULL)
	{
		p = (CXScdDrawCtrl_ThumbBase *)GetNext(pos);
		p->GetAllLines(oScdLines);
	}
}

void CXScdDrawIedThumbnail::GetAllKindsLines(CXDrawElements &oScdLines,CXDrawElements &oScdToBusLines)
{

	CXScdDrawCtrl_ThumbBase *p = NULL;
	POS pos = GetHeadPosition();

	while (pos != NULL)
	{
		p = (CXScdDrawCtrl_ThumbBase *)GetNext(pos);
		p->GetAllKindsLines(oScdLines,oScdToBusLines);
	}

}



CSize CXScdDrawIedThumbnail::CalLayout(CSize &szDraw)
{
	POS pos = GetHeadPosition();
	CXDrawElement *p = NULL;
	CSize szElement, szIed(0,200);
	long nCount = GetCount();

	while (pos != NULL)
	{
		p = (CXDrawElement *)GetNext(pos);
		szElement = p->CalLayout(szElement);
		szIed.cx += szElement.cx;	
	}

	if (nCount > 0)
	{
		szIed.cx += (nCount + 1) * XSCDDRAW_ELEMENT_MARGIN;
	}

	//标题：
	szIed.cx = max(XSCDDRAW_THUMBNAIL_IED_WIDTH , szIed.cx);
	szIed.cy = XSCDDRAW_THUMBNAIL_IED_HEIGHT;
	szIed.cy += XSCDDRAW_ELEMENT_MARGIN;

	m_nHeight = szIed.cy;
	m_nWidth  = szIed.cx;

	szDraw = szIed;
	return szDraw;
}


CSize CXScdDrawIedThumbnail::Layout(CPoint &ptTopLeft)
{
	POS pos = GetHeadPosition();
	CXScdDrawCtrlBase *pCtrlBase = NULL;
	CPoint pt;
	CSize szCtrl;
	m_ptTopLeft = ptTopLeft;

	pt.x = ptTopLeft.x+XSCDDRAW_ELEMENT_MARGIN;

	//保护、测控
	if(m_b_ProtMeas_MuCtrl==IEDTHUMBNAILTYPE_MUCTRL||m_b_ProtMeas_MuCtrl==IEDTHUMBNAILTYPE_PROCMEAS2)
	{
		pt.y = ptTopLeft.y + XSCDDRAW_ELEMENT_MARGIN;
	}
	else
	{//合并单元、智能终端
		pt.y = ptTopLeft.y + XSCDDRAW_THUMBNAIL_IED_HEIGHT_TYPE+XSCDDRAW_THUMBNAIL_IED_HEIGHT_ID;
	}

	//CTRLS
	while (pos != NULL)
	{
		pCtrlBase = (CXScdDrawCtrlBase *)GetNext(pos);
		szCtrl = pCtrlBase->Layout(pt);
		pt.x += szCtrl.cx + XSCDDRAW_ELEMENT_MARGIN;
	}

	CSize sz(m_nWidth, m_nHeight);
	return sz;
}

