//���Դ������ClassGenerator����
//��Ȩ���� LiJunqing  lijunqing1224@126.com
//��������Ȩ��

//XScdDrawIed.h  CXScdDrawIed

#pragma once

#include "XScdDrawLineBase.h"



class CXScdDrawLine_Ctrls : public CXScdDrawLine_Vert
{
public:
	CXScdDrawLine_Ctrls();
	virtual ~CXScdDrawLine_Ctrls();

public:


	

//���غ���
public:
public:
	virtual void Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset);
	virtual UINT GetClassID() {    return XSCDDRAW_LINE_CTRLS;   }
	virtual void InitLinePos();
	virtual void InitToBusLinePos();

};

