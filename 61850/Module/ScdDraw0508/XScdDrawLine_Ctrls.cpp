//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawIed.cpp  CXScdDrawIed


#include "stdafx.h"
#include "XScdDrawLine_Ctrls.h"

extern int g_VerticalLocate_Bus;

CXScdDrawLine_Ctrls::CXScdDrawLine_Ctrls()
{
	//初始化属性


	//初始化成员变量
	
}

CXScdDrawLine_Ctrls::~CXScdDrawLine_Ctrls()
{
	
}


void CXScdDrawLine_Ctrls::Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
 {
	CXScdDrawLine_Vert::Draw(pDC, fZoomRatio, ptOffset);
}


void CXScdDrawLine_Ctrls::InitLinePos()
{
	ASSERT ((m_pBeginElement != NULL) && (m_pEndElement != NULL) );

	if (m_pBeginElement == NULL || m_pEndElement == NULL)
	{
		return;
	}

	
	m_ptBegin.x = m_pBeginElement->m_ptTopLeft.x + m_pBeginElement->m_nWidth / 2;
	m_ptEnd.x   = m_pEndElement->m_ptTopLeft.x + m_pEndElement->m_nWidth / 2;
	
	if (m_pBeginElement->m_ptTopLeft.y > m_pEndElement->m_ptTopLeft.y)
	{
		m_ptBegin.y = m_pBeginElement->m_ptTopLeft.y;
		m_ptEnd.y   = m_pEndElement->m_ptTopLeft.y + m_pEndElement->m_nHeight;

		pLineToBus->m_ptBegin=m_ptBegin;
		pLineToBus->m_ptEnd.x=m_ptBegin.x;
		pLineToBus->m_ptEnd.y=g_VerticalLocate_Bus+5;

		pBusToLine->m_ptEnd=m_ptEnd;
		pBusToLine->m_ptBegin.x=m_ptEnd.x;
		pBusToLine->m_ptBegin.y=g_VerticalLocate_Bus-5;
	}
	else if( (m_pBeginElement->m_ptTopLeft.y < m_pEndElement->m_ptTopLeft.y))
	{
		m_ptBegin.y = m_pBeginElement->m_ptTopLeft.y + m_pEndElement->m_nHeight;
		m_ptEnd.y   = m_pEndElement->m_ptTopLeft.y;

		pLineToBus->m_ptBegin=m_ptBegin;
		pLineToBus->m_ptEnd.x=m_ptBegin.x;
		pLineToBus->m_ptEnd.y=g_VerticalLocate_Bus-5;

		pBusToLine->m_ptEnd=m_ptEnd;
		pBusToLine->m_ptBegin.x=m_ptEnd.x;
		pBusToLine->m_ptBegin.y=g_VerticalLocate_Bus+5;
	}
	else if( (m_pBeginElement->m_ptTopLeft.y==m_pEndElement->m_ptTopLeft.y))//如果开始和结束的纵坐标相同，则在一条水平线上有上下之分
	{
		//m_ptBegin.y = m_pBeginElement->m_ptTopLeft.y ;
		//m_ptEnd.y   = m_pEndElement->m_ptTopLeft.y;
        return;
	}
	//else
	//{

	//}


}


void CXScdDrawLine_Ctrls::InitToBusLinePos()
{
	ASSERT ((m_pBeginElement != NULL) && (m_pEndElement != NULL) );
    if((m_pBeginElement==NULL)&&(m_pEndElement!=NULL))
	{
		m_ptEnd.x   = m_pEndElement->m_ptTopLeft.x + m_pEndElement->m_nWidth / 2;
		m_ptEnd.y= m_pEndElement->m_ptTopLeft.y;
		m_ptBegin.x=m_ptEnd.x;
		m_ptBegin.y=g_VerticalLocate_Bus;
	}
	else  if((m_pEndElement==NULL)&&(m_pBeginElement!=NULL))
	{
		m_ptBegin.x   = m_pBeginElement->m_ptTopLeft.x + m_pBeginElement->m_nWidth / 2;
		m_ptBegin.y= m_pBeginElement->m_ptTopLeft.y;
		m_ptEnd.x=m_ptBegin.x;
		m_ptEnd.y=g_VerticalLocate_Bus;
	}



}



