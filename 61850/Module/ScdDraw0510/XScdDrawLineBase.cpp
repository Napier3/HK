//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawIed.cpp  CXScdDrawIed


#include "stdafx.h"
#include "XScdDrawLineBase.h"


CXScdDrawLineBase::CXScdDrawLineBase()
{
	//初始化属性

	//初始化成员变量
	m_pBeginObj      = NULL;
	m_pEndObj        = NULL;
	m_pBeginElement  = NULL;
	m_pEndElement    = NULL;
	m_ptBegin.x = 0;
	m_ptBegin.y = 0;
	m_ptEnd.x   = 0;
	m_ptBegin.y = 0;
}

CXScdDrawLineBase::~CXScdDrawLineBase()
{

}

BOOL CXScdDrawLineBase::CopyOwn(CBaseObject* pDest)
{
	if(this == pDest)
	{
		return TRUE;
	}

	CXScdDrawLineBase *p = (CXScdDrawLineBase*)pDest;

	CXDrawElement::CopyOwn(pDest);

	p->m_pBeginObj = m_pBeginObj;
	p->m_pEndObj = m_pEndObj;
	p->m_pBeginElement = m_pBeginElement;
	p->m_pEndElement = m_pEndElement;
	p->m_ptBegin = m_ptBegin;
	p->m_ptEnd = m_ptEnd;

	return TRUE;
}

CBaseObject* CXScdDrawLineBase::Clone()
{
	CXScdDrawLineBase *p = new CXScdDrawLineBase();
	Copy(p);
	return p;
}

void CXScdDrawLineBase::Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
{
	if (m_nShow == 0)
	{
		return;
	}

	int iArrowLen = 10;
	CPen pen,*pOldPen;
	CPoint ptArrow1=m_ptEnd;
	CPoint ptArrow2=m_ptEnd;
	//double dCal = m_ptBegin.y - m_ptEnd.y;
	//dCal = dCal / (m_ptEnd.x - m_ptBegin.x);
	//double fAngle = atan(dCal) * 180 / 3.141592654;;//+180;
	UINT uiLineStyle = PS_SOLID;
	UINT iLineWidth = 1;
	COLORREF crVector = RGB(0, 0, 0);


	//if(CFGCLASSID_CIECCFGGOUTCH==m_pBeginObj->GetClassID())
	//{

	//////////////计算矢量图的箭头
	/*	float	fAss=(float)iArrowLen;
	float	fAg=(float)(3.141592654 / 180.0);*/
	if(m_ptBegin.x<m_ptEnd.x)
	{
		//ptArrow1.x=-(int)(fAss*sin((fAngle+75.0f)*fAg));		
		//ptArrow2.x=-(int)(fAss*sin((75.0f-fAngle)*fAg));
		ptArrow1.x=m_ptEnd.x-10;
		ptArrow1.y=m_ptEnd.y-3;

		ptArrow2.x=m_ptEnd.x-10;
		ptArrow2.y=m_ptEnd.y+3;
	}
	else
	{
		/*	ptArrow1.x=-(int)(fAss*sin((fAngle+75.0f)*fAg));		
		ptArrow2.x=-(int)(fAss*sin((75.0f-fAngle)*fAg));*/
		ptArrow1.x=m_ptEnd.x+10;
		ptArrow1.y=m_ptEnd.y-3;

		ptArrow2.x=m_ptEnd.x+10;
		ptArrow2.y=m_ptEnd.y+3;
	}


	//ptArrow1.y=-(int)(fAss*cos((fAngle+75.0f)*fAg));
	//ptArrow2.y=(int)(fAss*cos((75.0f-fAngle)*fAg));

	//ptArrow1 = m_ptEnd+ptArrow1;
	//ptArrow2 = m_ptEnd+ptArrow2;
	//////////绘制矢量直线
	pen.CreatePen(uiLineStyle,iLineWidth,crVector);
	pOldPen=pDC->SelectObject(&pen);

	CPoint m_ptMiddle;

	if(m_ptBegin.x<m_ptEnd.x)
	{
		m_ptMiddle.x=m_ptEnd.x-XSCDDRAW_IED_BORDER_GAP;
	}
	else
	{
		m_ptMiddle.x=m_ptEnd.x+XSCDDRAW_IED_BORDER_GAP;		
	}


	m_ptMiddle.y=m_ptEnd.y;

	pDC->MoveTo(m_ptBegin);		pDC->LineTo(m_ptMiddle);
	pDC->MoveTo(m_ptMiddle);      pDC->LineTo(m_ptEnd);


	pDC->SelectObject(pOldPen);
	pen.DeleteObject();
	//////////绘制矢量箭头
	pen.CreatePen(PS_SOLID,iLineWidth,crVector);
	pOldPen=pDC->SelectObject(&pen);
	CBrush brush,*pOldBrush;
	brush.CreateSolidBrush(crVector);
	pOldBrush=pDC->SelectObject(&brush);

	if(iLineWidth==1)
	{
		CPoint ptArrow[3];
		ptArrow[0]=m_ptEnd;ptArrow[1]=ptArrow1;ptArrow[2]=ptArrow2;
		pDC->Polygon(ptArrow,3);
	}
	else
	{
		pDC->MoveTo(ptArrow1);pDC->LineTo(m_ptEnd);
		pDC->MoveTo(ptArrow2);pDC->LineTo(m_ptEnd);
	}
	pDC->SelectObject(pOldBrush);
	brush.DeleteObject();
	pDC->SelectObject(pOldPen);
	pen.DeleteObject();
	//	

	//}

}

void CXScdDrawLineBase::InitLinePos()
{

}

void CXScdDrawLineBase::InitToBusLinePos()
{

}
//////////////////////////////////////////////////////////////////////////
//
CXScdDrawLine_Vert::CXScdDrawLine_Vert()
{
// 	m_pLineToBus=NULL;
// 	m_pBusToLine=NULL;

}

CXScdDrawLine_Vert::~CXScdDrawLine_Vert()
{

}

void CXScdDrawLine_Vert::Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
{
	if (m_ptBegin.x==0||m_ptBegin.y==0)
	{
		return ;
	}
	if (m_ptEnd.x==0||m_ptEnd.y==0)
	{
		return ;
	}
	if (m_nShow == 0)
	{
		return;
	}

	int iArrowLen = 10;
	CPen pen,*pOldPen;
	CPoint ptArrow1=m_ptEnd;
	CPoint ptArrow2=m_ptEnd;
	UINT uiLineStyle = PS_SOLID;
	UINT iLineWidth = 1;
	COLORREF crVector = RGB(0, 0, 0);
	
	//////////////计算垂直方向矢量图的箭头

	if((m_ptBegin.y<m_ptEnd.y)||((m_ptBegin.y==m_ptEnd.y)&&(m_ptBegin.y>300)))
	{
		ptArrow1.y=m_ptEnd.y-10;
		ptArrow1.x=m_ptEnd.x-3;

		ptArrow2.y=m_ptEnd.y-10;
		ptArrow2.x=m_ptEnd.x+3;
	}
	else
	{

		ptArrow1.y=m_ptEnd.y+10;
		ptArrow1.x=m_ptEnd.x-3;

		ptArrow2.y=m_ptEnd.y+10;
		ptArrow2.x=m_ptEnd.x+3;
	}


	//////////绘制矢量直线
	pen.CreatePen(uiLineStyle,iLineWidth,crVector);
	pOldPen=pDC->SelectObject(&pen);


	/////////////////////////////////////////////////////////////////////////////////////////////////////在同一条水平线上的情况///////////////////////////////////////////////////////
	CPoint m_ptMiddle,m_ptMiddle1,m_ptMiddle2;

	if (m_ptBegin.y==m_ptEnd.y)
	{
		pDC->SelectObject(pOldPen);
		pen.DeleteObject();
	
		if (abs(pt_MainIedTurn.x-m_ptBegin.x)<100)		
		{
			m_ptMiddle1=pt_MainIedTurn;
			m_ptMiddle2.y=m_ptMiddle1.y;
			if (m_ptBegin.x>m_ptEnd.x)
			{		
				
				m_ptMiddle2.x=m_ptEnd.x+(pt_MainIedTurn.y-m_ptEnd.y);
				
			}
			else
			{
				m_ptMiddle2.x=m_ptEnd.x-(pt_MainIedTurn.y-m_ptEnd.y);
			
			}

			crVector = RGB(3,163,7);
			pen.CreatePen(uiLineStyle,iLineWidth,crVector);
			pOldPen=pDC->SelectObject(&pen);
			pDC->MoveTo(m_ptBegin);		pDC->LineTo(m_ptMiddle1);
			pDC->MoveTo(m_ptMiddle1);      pDC->LineTo(m_ptMiddle2);
			pDC->MoveTo(m_ptMiddle2);      pDC->LineTo(m_ptEnd);
		}
		else if(abs(pt_MainIedTurn.x-m_ptEnd.x)<100)
		{
			m_ptMiddle2=pt_MainIedTurn;
			m_ptMiddle1.y=m_ptMiddle2.y;
			if (m_ptBegin.x<m_ptEnd.x)
			{

			m_ptMiddle1.x=m_ptBegin.x+(pt_MainIedTurn.y-m_ptBegin.y);
			}
			else
			{
			m_ptMiddle1.x=m_ptBegin.x-(pt_MainIedTurn.y-m_ptBegin.y);
			}

			crVector = RGB(0,0, 255);
			pen.CreatePen(uiLineStyle,iLineWidth,crVector);
			pOldPen=pDC->SelectObject(&pen);
			pDC->MoveTo(m_ptBegin);		pDC->LineTo(m_ptMiddle1);
			pDC->MoveTo(m_ptMiddle1);      pDC->LineTo(m_ptMiddle2);
			pDC->MoveTo(m_ptMiddle2);      pDC->LineTo(m_ptEnd);

		}	
                                                         	//////////////重新计算矢量图的箭头，斜箭头////////////////////////////////////////////////////////
	       double dCal = m_ptMiddle2.y - m_ptEnd.y;
	       dCal = dCal / (m_ptEnd.x - m_ptMiddle2.x);
	      double fAngle = atan(dCal) * 180 / 3.141592654;;//+180;		  
		  float	fAss=(float)iArrowLen;
	      float	fAg=(float)(3.141592654 / 180.0);
	      if((m_ptMiddle2.x<m_ptEnd.x))
	      {
	     	ptArrow1.x=-(int)(fAss*sin((fAngle+75.0f)*fAg));		
	     	ptArrow2.x=-(int)(fAss*sin((75.0f-fAngle)*fAg)); 
			ptArrow1.y=-(int)(fAss*cos((fAngle+75.0f)*fAg));
			ptArrow2.y=(int)(fAss*cos((75.0f-fAngle)*fAg));
	      }
	     else
      	{
			ptArrow1.x=(int)(fAss*sin((fAngle+75.0f)*fAg));		
		     ptArrow2.x=(int)(fAss*sin((75.0f-fAngle)*fAg));
			 ptArrow1.y=(int)(fAss*cos((fAngle+75.0f)*fAg));
			 ptArrow2.y=-(int)(fAss*cos((75.0f-fAngle)*fAg));
		}

		ptArrow1 = m_ptEnd+ptArrow1;
		ptArrow2 = m_ptEnd+ptArrow2;
		
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////不在同一条水平线上的情况/////////////////////////////////////////////////////////////
	else
	{

		if(m_ptBegin.y<m_ptEnd.y)
		{
			m_ptMiddle.y=m_ptEnd.y-XSCDDRAW_IED_BORDER_GAP;
		}
		else
		{
			m_ptMiddle.y=m_ptEnd.y+XSCDDRAW_IED_BORDER_GAP;		
		}

		m_ptMiddle.x=m_ptEnd.x;

		pDC->MoveTo(m_ptBegin);		pDC->LineTo(m_ptMiddle);
		pDC->MoveTo(m_ptMiddle);      pDC->LineTo(m_ptEnd);
	}


	pDC->SelectObject(pOldPen);
	pen.DeleteObject();

	//////////绘制矢量箭头
	pen.CreatePen(PS_SOLID,iLineWidth,crVector);
	pOldPen=pDC->SelectObject(&pen);
	CBrush brush,*pOldBrush;
	brush.CreateSolidBrush(crVector);
	pOldBrush=pDC->SelectObject(&brush);

	if(iLineWidth==1)
	{
		CPoint ptArrow[3];
		ptArrow[0]=m_ptEnd;ptArrow[1]=ptArrow1;ptArrow[2]=ptArrow2;
		pDC->Polygon(ptArrow,3);
	}
	else
	{
		pDC->MoveTo(ptArrow1);pDC->LineTo(m_ptEnd);
		pDC->MoveTo(ptArrow2);pDC->LineTo(m_ptEnd);
	}
	pDC->SelectObject(pOldBrush);
	brush.DeleteObject();
	pDC->SelectObject(pOldPen);
	pen.DeleteObject();
}

//
//void CXScdDrawLine_Vert::Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
//{
//	if (m_ptBegin.x==0||m_ptBegin.y==0)
//	{
//		return ;
//	}
//	if (m_ptEnd.x==0||m_ptEnd.y==0)
//	{
//		return ;
//	}
//	// 	if (abs(m_pBeginElement->m_ptTopLeft.y-m_pEndElement->m_ptTopLeft.y)<100)
//	// 	{
//	// 		return;
//	// 	}
//
//
//
//	if (m_nShow == 0)
//	{
//		return;
//	}
//
//
//	//if (m_ptBegin.y>500||m_ptEnd.y>500)
//	//{
//	//	if (m_ptBegin.y<m_ptEnd.y)
//	//	{
//	//		m_ptBegin.y+=62;
//	//	}
//	//	else
//	//	{
//	//		m_ptEnd.y+=62;
//	//	}
//	//}
//	int iArrowLen = 10;
//	CPen pen,*pOldPen;
//	CPoint ptArrow1=m_ptEnd;
//	CPoint ptArrow2=m_ptEnd;
//	//double dCal = m_ptBegin.y - m_ptEnd.y;
//	//dCal = dCal / (m_ptEnd.x - m_ptBegin.x);
//	//double fAngle = atan(dCal) * 180 / 3.141592654;;//+180;
//	UINT uiLineStyle = PS_SOLID;
//	UINT iLineWidth = 1;
//	COLORREF crVector = RGB(0, 0, 0);
//
//
//	//if(CFGCLASSID_CIECCFGGOUTCH==m_pBeginObj->GetClassID())
//	//{
//
//	//////////////计算矢量图的箭头
//	/*	float	fAss=(float)iArrowLen;
//	float	fAg=(float)(3.141592654 / 180.0);*/
//	if((m_ptBegin.y<m_ptEnd.y)||((m_ptBegin.y==m_ptEnd.y)&&(m_ptBegin.y>300)))
//	{
//		//ptArrow1.x=-(int)(fAss*sin((fAngle+75.0f)*fAg));		
//		//ptArrow2.x=-(int)(fAss*sin((75.0f-fAngle)*fAg));
//		ptArrow1.y=m_ptEnd.y-10;
//		ptArrow1.x=m_ptEnd.x-3;
//
//		ptArrow2.y=m_ptEnd.y-10;
//		ptArrow2.x=m_ptEnd.x+3;
//	}
//	else
//	{
//		/*	ptArrow1.x=-(int)(fAss*sin((fAngle+75.0f)*fAg));		
//		ptArrow2.x=-(int)(fAss*sin((75.0f-fAngle)*fAg));*/
//		ptArrow1.y=m_ptEnd.y+10;
//		ptArrow1.x=m_ptEnd.x-3;
//
//		ptArrow2.y=m_ptEnd.y+10;
//		ptArrow2.x=m_ptEnd.x+3;
//	}
//
//
//	//ptArrow1.y=-(int)(fAss*cos((fAngle+75.0f)*fAg));
//	//ptArrow2.y=(int)(fAss*cos((75.0f-fAngle)*fAg));
//
//	//ptArrow1 = m_ptEnd+ptArrow1;
//	//ptArrow2 = m_ptEnd+ptArrow2;
//	//////////绘制矢量直线
//	pen.CreatePen(uiLineStyle,iLineWidth,crVector);
//	pOldPen=pDC->SelectObject(&pen);
//
//	/////////////////////////////////////////////////////////////////////////////////////////////////////在一条水平线上
//	CPoint m_ptMiddle,m_ptMiddle1,m_ptMiddle2;
//
//	if (m_ptBegin.y==m_ptEnd.y)
//	{
//		pDC->SelectObject(pOldPen);
//		pen.DeleteObject();
//		//if (m_ptBegin.y<300)
//		//{
//		//	m_ptMiddle1.y=m_ptBegin.y+XSCDDRAW_IED_BORDER_GAP*2;	
//		//	m_ptMiddle2.y=m_ptEnd.y+XSCDDRAW_IED_BORDER_GAP*2;	
//		//}
//		//else
//		//{
//		//	m_ptMiddle1.y=m_ptBegin.y-XSCDDRAW_IED_BORDER_GAP*2;	
//		//	m_ptMiddle2.y=m_ptEnd.y-XSCDDRAW_IED_BORDER_GAP*2;	
//		//}
//
//		//m_ptMiddle1.x=m_ptBegin.x;
//		//m_ptMiddle2.x=m_ptEnd.x;
//
//		//pDC->MoveTo(m_ptBegin);		pDC->LineTo(m_ptMiddle1);
//		//pDC->MoveTo(m_ptMiddle1);      pDC->LineTo(m_ptMiddle2);
//		//pDC->MoveTo(m_ptMiddle2);      pDC->LineTo(m_ptEnd);
//
//		//if (m_ptBegin.y<300)
//		//{
//		//	m_ptMiddle1.y=m_ptBegin.y+XSCDDRAW_IED_BORDER_GAP*2;	
//		//	m_ptMiddle2.y=m_ptEnd.y+XSCDDRAW_IED_BORDER_GAP*2;	
//		//}
//		//else
//		//{
//		//	m_ptMiddle1.y=m_ptBegin.y-XSCDDRAW_IED_BORDER_GAP*2;	
//		//	m_ptMiddle2.y=m_ptEnd.y-XSCDDRAW_IED_BORDER_GAP*2;	
//		//}
//
//		//m_ptMiddle1.x=m_ptBegin.x;
//		//m_ptMiddle2.x=m_ptEnd.x;
//
//		//pDC->MoveTo(m_ptBegin);		pDC->LineTo(m_ptMiddle1);
//		//pDC->MoveTo(m_ptMiddle1);      pDC->LineTo(m_ptMiddle2);
//		//pDC->MoveTo(m_ptMiddle2);      pDC->LineTo(m_ptEnd);
//		int width1=Yaxis_Turn-m_ptEnd.y;
//		if (((m_ptBegin.x>m_ptEnd.x)&&(Label_LeftOrRight==0))||((m_ptBegin.x<m_ptEnd.x)&&(Label_LeftOrRight==1)))
//		{
//
//			if (Label_LeftOrRight==0)
//			{
//				m_ptMiddle1.x=m_ptBegin.x-width1;			
//			}
//			else
//			{
//				m_ptMiddle1.x=m_ptBegin.x+width1;
//			}
//				m_ptMiddle2.x=m_ptEnd.x;
//				m_ptMiddle1.y=Yaxis_Turn;
//				m_ptMiddle2.y=Yaxis_Turn;
//
//				
//                crVector = RGB(60,240,120);
//				 pen.CreatePen(uiLineStyle,iLineWidth,crVector);
//				 pOldPen=pDC->SelectObject(&pen);
//				pDC->MoveTo(m_ptBegin);		pDC->LineTo(m_ptMiddle1);
//				pDC->MoveTo(m_ptMiddle1);      pDC->LineTo(m_ptMiddle2);
//				pDC->MoveTo(m_ptMiddle2);      pDC->LineTo(m_ptEnd);
//		}
//		else
//		{
//			if (Label_LeftOrRight==0)
//			{
//				m_ptMiddle1.x=m_ptBegin.x+width1;
//			}
//			else
//			{
//				m_ptMiddle1.x=m_ptBegin.x-width1;
//
//			}
//			
//			m_ptMiddle2.x=m_ptEnd.x;
//			m_ptMiddle1.y=Yaxis_Turn;
//			m_ptMiddle2.y=Yaxis_Turn;
//
//			crVector = RGB(0,0, 255);
//			pen.CreatePen(uiLineStyle,iLineWidth,crVector);
//			pOldPen=pDC->SelectObject(&pen);
//			pDC->MoveTo(m_ptBegin);		pDC->LineTo(m_ptMiddle1);
//			pDC->MoveTo(m_ptMiddle1);      pDC->LineTo(m_ptMiddle2);
//			pDC->MoveTo(m_ptMiddle2);      pDC->LineTo(m_ptEnd);
//		}
//	}
//	else
//	{
//
//		if(m_ptBegin.y<m_ptEnd.y)
//		{
//			m_ptMiddle.y=m_ptEnd.y-XSCDDRAW_IED_BORDER_GAP;
//		}
//		else
//		{
//			m_ptMiddle.y=m_ptEnd.y+XSCDDRAW_IED_BORDER_GAP;		
//		}
//
//		m_ptMiddle.x=m_ptEnd.x;
//
//		pDC->MoveTo(m_ptBegin);		pDC->LineTo(m_ptMiddle);
//		pDC->MoveTo(m_ptMiddle);      pDC->LineTo(m_ptEnd);
//	}
//
//
//	pDC->SelectObject(pOldPen);
//	pen.DeleteObject();
//	//////////绘制矢量箭头
//	pen.CreatePen(PS_SOLID,iLineWidth,crVector);
//	pOldPen=pDC->SelectObject(&pen);
//	CBrush brush,*pOldBrush;
//	brush.CreateSolidBrush(crVector);
//	pOldBrush=pDC->SelectObject(&brush);
//
//	if(iLineWidth==1)
//	{
//		CPoint ptArrow[3];
//		ptArrow[0]=m_ptEnd;ptArrow[1]=ptArrow1;ptArrow[2]=ptArrow2;
//		pDC->Polygon(ptArrow,3);
//	}
//	else
//	{
//		pDC->MoveTo(ptArrow1);pDC->LineTo(m_ptEnd);
//		pDC->MoveTo(ptArrow2);pDC->LineTo(m_ptEnd);
//	}
//	pDC->SelectObject(pOldBrush);
//	brush.DeleteObject();
//	pDC->SelectObject(pOldPen);
//	pen.DeleteObject();
//}

CBaseObject* CXScdDrawLine_Vert::Clone()
{
	CXScdDrawLine_Vert *p = new CXScdDrawLine_Vert();
	Copy(p);
	return p;
}


CXScdDrawLine_ToBus::CXScdDrawLine_ToBus()
{

}

CXScdDrawLine_ToBus::~CXScdDrawLine_ToBus()
{
	RemoveAll();
}

void CXScdDrawLine_ToBus::Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
{
	if (m_ptBegin.x==0||m_ptBegin.y==0)
	{
		return ;
	}
	if (m_ptEnd.x==0||m_ptEnd.y==0)
	{
		return ;
	}

	if (m_nShow == 0)
	{
		return;
	}

	int iArrowLen = 10;
	CPen pen,*pOldPen;
	CPoint ptArrow1=m_ptEnd;
	CPoint ptArrow2=m_ptEnd;

	UINT uiLineStyle = PS_SOLID;
	UINT iLineWidth = 1;

	//////////////计算矢量图的箭头

	if((m_ptBegin.y<m_ptEnd.y))
	{
	
		ptArrow1.y=m_ptEnd.y-10;
		ptArrow1.x=m_ptEnd.x-3;

		ptArrow2.y=m_ptEnd.y-10;
		ptArrow2.x=m_ptEnd.x+3;
	}
	else
	{	
		ptArrow1.y=m_ptEnd.y+10;
		ptArrow1.x=m_ptEnd.x-3;

		ptArrow2.y=m_ptEnd.y+10;
		ptArrow2.x=m_ptEnd.x+3;
	}



	//////////绘制矢量直线
	pen.CreatePen(uiLineStyle,iLineWidth,m_crForeColor);
	pOldPen=pDC->SelectObject(&pen);	

	pDC->MoveTo(m_ptBegin);		     pDC->LineTo(m_ptEnd);
	pDC->SelectObject(pOldPen);
	pen.DeleteObject();


	//////////绘制矢量箭头
	pen.CreatePen(PS_SOLID,iLineWidth,m_crForeColor);
	pOldPen=pDC->SelectObject(&pen);
	CBrush brush,*pOldBrush;
	brush.CreateSolidBrush(m_crForeColor);
	pOldBrush=pDC->SelectObject(&brush);

	if(iLineWidth==1)
	{
		CPoint ptArrow[3];
		ptArrow[0]=m_ptEnd;ptArrow[1]=ptArrow1;ptArrow[2]=ptArrow2;
		pDC->Polygon(ptArrow,3);
	}
	else
	{
		pDC->MoveTo(ptArrow1);pDC->LineTo(m_ptEnd);
		pDC->MoveTo(ptArrow2);pDC->LineTo(m_ptEnd);
	}
	pDC->SelectObject(pOldBrush);
	brush.DeleteObject();
	pDC->SelectObject(pOldPen);
	pen.DeleteObject();
}


void CXScdDrawLine_ToBus::InitLinePos()
{
	//起始点  小于   终点
	if (m_pBeginElement->m_ptTopLeft.y < m_pEndElement->m_ptTopLeft.y)
	{
		//起始点是bus【top】，终点是Ctrl【bottom】
		if (m_pBeginObj == NULL)
		{
			m_ptBegin = m_pBeginElement->m_ptTopLeft;
			m_ptEnd = m_pEndElement->GetTopCenter();
			m_ptBegin.x = m_ptEnd.x;
		}
		else
		{//起始点是Ctrl【top】，终点是bus【bottom】
			m_ptBegin = m_pBeginElement->GetBottomCenter();
			m_ptEnd = m_pEndElement->m_ptTopLeft;
			m_ptEnd.x = m_ptBegin.x;
		}
	}
	else//起始点  大于   终点
	{
		//起始点是bus【bottom】，终点是Ctrl【top】
		if (m_pBeginObj == NULL)
		{
			m_ptBegin = m_pBeginElement->m_ptTopLeft;
			m_ptEnd = m_pEndElement->GetBottomCenter();
			m_ptBegin.x = m_ptEnd.x;
		}
		else
		{//起始点是Ctrl【bottom】，终点是bus【top】
			m_ptBegin = m_pBeginElement->GetTopCenter();
			m_ptEnd = m_pEndElement->m_ptTopLeft;
			m_ptEnd.x = m_ptBegin.x;
		}
	}	
}

//////////////////////////////////////////////////////////////////////////
//CXScdDrawLine_Bus
CXScdDrawLine_Bus::CXScdDrawLine_Bus()
{
	m_crForeColor = RGB(0, 0, 0);
}

CXScdDrawLine_Bus::~CXScdDrawLine_Bus()
{

}

void CXScdDrawLine_Bus::Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
{
	CPen pen,*pOldPen;

	UINT uiLineStyle = PS_SOLID;
	UINT iLineWidth = 5;

	pen.CreatePen(uiLineStyle,iLineWidth,m_crForeColor);
	pOldPen=pDC->SelectObject(&pen);	

			pDC->MoveTo(m_ptBegin);	    pDC->LineTo(m_ptEnd);
			pDC->SelectObject(pOldPen);
			pen.DeleteObject();

	CRect rc(m_ptBegin.x, m_ptBegin.y-3, m_ptBegin.x + 60, m_ptBegin.y - 16);
	CmDrawTextRect(pDC, m_strName, m_crForeColor, rc, RGB(192,192,192),   g_lfGlobalFont14, TRANSPARENT, DT_VCENTER|DT_WORDBREAK|DT_CENTER, 0);
}

//////////////////////////////////////////////////////////////////////////
//CXScdDrawLine_GooseBus
CXScdDrawLine_GooseBus::CXScdDrawLine_GooseBus()
{
	m_crForeColor = RGB(34, 177, 76);
	m_strName  = _T("GOOSE");
}

CXScdDrawLine_GooseBus::~CXScdDrawLine_GooseBus()
{

}

//////////////////////////////////////////////////////////////////////////
//CXScdDrawLine_SvBus
CXScdDrawLine_SvBus::CXScdDrawLine_SvBus()
{
	m_crForeColor = RGB(185, 122, 87);
	m_strName  = _T("SV");
}

CXScdDrawLine_SvBus::~CXScdDrawLine_SvBus()
{

}
