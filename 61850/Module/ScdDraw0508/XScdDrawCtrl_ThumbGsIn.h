//���Դ������ClassGenerator����
//��Ȩ���� LiJunqing  lijunqing1224@126.com
//��������Ȩ��

//XScdDrawCtrl_ThumbGsIn.h  CXScdDrawCtrl_ThumbGsIn

#pragma once

#include "XScdDrawCtrl_ThumbBase.h"

class CXScdDrawCtrl_ThumbGsIn : public CXScdDrawCtrl_ThumbBase
{
public:
	CXScdDrawCtrl_ThumbGsIn();
	virtual ~CXScdDrawCtrl_ThumbGsIn();
public:
	
	

	//���غ���
public:
	virtual void Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset);
	virtual void CreateCtrlLines();

	//˽�г�Ա����
private:

	//˽�г�Ա�������ʷ���
public:

	//��ͼ��غ�������
public:

};