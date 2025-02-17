//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawIed.cpp  CXScdDrawIed


#include "stdafx.h"
#include "XScdDrawLineBase.h"
extern 	int g_VerticalLocate_GooseBus;
extern int g_VerticalLocate_SmvBus;

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
	pLineToBus=NULL;
	pBusToLine=NULL;

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
	// 	if (abs(m_pBeginElement->m_ptTopLeft.y-m_pEndElement->m_ptTopLeft.y)<100)
	// 	{
	// 		return;
	// 	}



	if (m_nShow == 0)
	{
		return;
	}


	//if (m_ptBegin.y>500||m_ptEnd.y>500)
	//{
	//	if (m_ptBegin.y<m_ptEnd.y)
	//	{
	//		m_ptBegin.y+=62;
	//	}
	//	else
	//	{
	//		m_ptEnd.y+=62;
	//	}
	//}
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
	if((m_ptBegin.y<m_ptEnd.y)||((m_ptBegin.y==m_ptEnd.y)&&(m_ptBegin.y>300)))
	{
		//ptArrow1.x=-(int)(fAss*sin((fAngle+75.0f)*fAg));		
		//ptArrow2.x=-(int)(fAss*sin((75.0f-fAngle)*fAg));
		ptArrow1.y=m_ptEnd.y-10;
		ptArrow1.x=m_ptEnd.x-3;

		ptArrow2.y=m_ptEnd.y-10;
		ptArrow2.x=m_ptEnd.x+3;
	}
	else
	{
		/*	ptArrow1.x=-(int)(fAss*sin((fAngle+75.0f)*fAg));		
		ptArrow2.x=-(int)(fAss*sin((75.0f-fAngle)*fAg));*/
		ptArrow1.y=m_ptEnd.y+10;
		ptArrow1.x=m_ptEnd.x-3;

		ptArrow2.y=m_ptEnd.y+10;
		ptArrow2.x=m_ptEnd.x+3;
	}


	//ptArrow1.y=-(int)(fAss*cos((fAngle+75.0f)*fAg));
	//ptArrow2.y=(int)(fAss*cos((75.0f-fAngle)*fAg));

	//ptArrow1 = m_ptEnd+ptArrow1;
	//ptArrow2 = m_ptEnd+ptArrow2;
	//////////绘制矢量直线
	pen.CreatePen(uiLineStyle,iLineWidth,crVector);
	pOldPen=pDC->SelectObject(&pen);

	CPoint m_ptMiddle,m_ptMiddle1,m_ptMiddle2;
	if (m_ptBegin.y==m_ptEnd.y)
	{
		if (m_ptBegin.y<300)
		{
			m_ptMiddle1.y=m_ptBegin.y+XSCDDRAW_IED_BORDER_GAP*2;	
			m_ptMiddle2.y=m_ptEnd.y+XSCDDRAW_IED_BORDER_GAP*2;	
		}
		else
		{
			m_ptMiddle1.y=m_ptBegin.y-XSCDDRAW_IED_BORDER_GAP*2;	
			m_ptMiddle2.y=m_ptEnd.y-XSCDDRAW_IED_BORDER_GAP*2;	
		}

			m_ptMiddle1.x=m_ptBegin.x;
			m_ptMiddle2.x=m_ptEnd.x;

			pDC->MoveTo(m_ptBegin);		pDC->LineTo(m_ptMiddle1);
			pDC->MoveTo(m_ptMiddle1);      pDC->LineTo(m_ptMiddle2);
			pDC->MoveTo(m_ptMiddle2);      pDC->LineTo(m_ptEnd);
	}
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





CXScdDrawLine_ToBus::CXScdDrawLine_ToBus()
{

}

CXScdDrawLine_ToBus::~CXScdDrawLine_ToBus()
{

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

	COLORREF crVector = RGB(0, 0, 0);
	if (abs(m_ptBegin.y-g_VerticalLocate_GooseBus)<10||abs(m_ptEnd.y-g_VerticalLocate_GooseBus)<10)
	{
	    crVector = RGB(0,0, 0);
	}
	else if (abs(m_ptBegin.y-g_VerticalLocate_SmvBus)<10||abs(m_ptEnd.y-g_VerticalLocate_SmvBus)<10)
	{
		    crVector = RGB(255, 0, 0);
	}
  

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
	pen.CreatePen(uiLineStyle,iLineWidth,crVector);
	pOldPen=pDC->SelectObject(&pen);	

	pDC->MoveTo(m_ptBegin);		     pDC->LineTo(m_ptEnd);
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










CXScdDrawLine_GooseBus::CXScdDrawLine_GooseBus()
{

}

CXScdDrawLine_GooseBus::~CXScdDrawLine_GooseBus()
{

}

void CXScdDrawLine_GooseBus::Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
{
		
	CPen pen,*pOldPen;

	UINT uiLineStyle = PS_SOLID;
	UINT iLineWidth = 10;
	COLORREF crVector = RGB(0,0, 0);

	pen.CreatePen(uiLineStyle,iLineWidth,crVector);
	pOldPen=pDC->SelectObject(&pen);	

			pDC->MoveTo(m_ptBegin);	    pDC->LineTo(m_ptEnd);
			pDC->SelectObject(pOldPen);
			pen.DeleteObject();

}

CXScdDrawLine_SvBus::CXScdDrawLine_SvBus()
{

}

CXScdDrawLine_SvBus::~CXScdDrawLine_SvBus()
{

}

void CXScdDrawLine_SvBus::Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
{


	CPen pen,*pOldPen;

	UINT uiLineStyle = PS_SOLID;
	UINT iLineWidth = 10;
	COLORREF crVector = RGB(255, 0, 0);

	pen.CreatePen(uiLineStyle,iLineWidth,crVector);
	pOldPen=pDC->SelectObject(&pen);	

	pDC->MoveTo(m_ptBegin);	    pDC->LineTo(m_ptEnd);
	pDC->SelectObject(pOldPen);
	pen.DeleteObject();

}
