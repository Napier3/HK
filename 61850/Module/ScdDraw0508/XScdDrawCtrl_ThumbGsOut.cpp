//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawCtrl_ThumbGsOut.cpp  CXScdDrawCtrl_ThumbGsOut


#include "stdafx.h"
#include "XScdDrawCtrl_ThumbGsOut.h"

CXScdDrawCtrl_ThumbGsOut::CXScdDrawCtrl_ThumbGsOut()
{
	//初始化属性

	//初始化成员变量
	m_strName = _T("GSOUT");
}

CXScdDrawCtrl_ThumbGsOut::~CXScdDrawCtrl_ThumbGsOut()
{
}

void CXScdDrawCtrl_ThumbGsOut::Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
{
	CXScdDrawCtrl_ThumbBase::Draw(pDC, fZoomRatio, ptOffset);
}

