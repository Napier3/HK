//���Դ������ClassGenerator����
//��Ȩ���� LiJunqing  lijunqing1224@126.com
//��������Ȩ��

//XScdDrawCtrl_ThumbSvOut.h  CXScdDrawCtrl_ThumbSvOut

#pragma once

#include "XScdDrawCtrl_ThumbBase.h"
//#include "XScdDrawIedThumbnail.h"
class CXScdDrawCtrl_ThumbSvOut : public CXScdDrawCtrl_ThumbBase
{
public:
	CXScdDrawCtrl_ThumbSvOut();
	virtual ~CXScdDrawCtrl_ThumbSvOut();

	//���غ���
public:
	//CXScdDrawIedThumbnail *m_pRefDrawIedThumbnail ;

	virtual void Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset);

	//˽�г�Ա����
private:

	//˽�г�Ա�������ʷ���
public:

	//��ͼ��غ�������
public:

};