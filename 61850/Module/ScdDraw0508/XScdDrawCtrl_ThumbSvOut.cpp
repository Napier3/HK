//���Դ������ClassGenerator����
//��Ȩ���� LiJunqing  lijunqing1224@126.com
//��������Ȩ��

//XScdDrawCtrl_ThumbSvOut.cpp  CXScdDrawCtrl_ThumbSvOut


#include "stdafx.h"
#include "XScdDrawCtrl_ThumbSvOut.h"

CXScdDrawCtrl_ThumbSvOut::CXScdDrawCtrl_ThumbSvOut()
{
	//��ʼ������

	//��ʼ����Ա����
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

