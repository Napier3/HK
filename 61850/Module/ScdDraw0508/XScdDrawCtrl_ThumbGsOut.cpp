//���Դ������ClassGenerator����
//��Ȩ���� LiJunqing  lijunqing1224@126.com
//��������Ȩ��

//XScdDrawCtrl_ThumbGsOut.cpp  CXScdDrawCtrl_ThumbGsOut


#include "stdafx.h"
#include "XScdDrawCtrl_ThumbGsOut.h"

CXScdDrawCtrl_ThumbGsOut::CXScdDrawCtrl_ThumbGsOut()
{
	//��ʼ������

	//��ʼ����Ա����
	m_strName = _T("GSOUT");
}

CXScdDrawCtrl_ThumbGsOut::~CXScdDrawCtrl_ThumbGsOut()
{
}

void CXScdDrawCtrl_ThumbGsOut::Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
{
	CXScdDrawCtrl_ThumbBase::Draw(pDC, fZoomRatio, ptOffset);
}

