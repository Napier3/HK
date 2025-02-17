//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawCtrl_ThumbSvOut.cpp  CXScdDrawCtrl_ThumbSvOut


#include "stdafx.h"
#include "XScdDrawCtrl_ThumbSvOut.h"

CXScdDrawCtrl_ThumbSvOut::CXScdDrawCtrl_ThumbSvOut()
{
	//初始化属性

	//初始化成员变量
	//m_pRefDrawIedThumbnail=NULL ;
	m_strName = _T("SVOUT");
}

CXScdDrawCtrl_ThumbSvOut::~CXScdDrawCtrl_ThumbSvOut()
{
}

void CXScdDrawCtrl_ThumbSvOut::Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
{
	CXScdDrawCtrl_ThumbBase::Draw(pDC, fZoomRatio, ptOffset);
}

