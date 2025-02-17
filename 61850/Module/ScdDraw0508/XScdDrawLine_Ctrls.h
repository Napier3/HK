//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawIed.h  CXScdDrawIed

#pragma once

#include "XScdDrawLineBase.h"



class CXScdDrawLine_Ctrls : public CXScdDrawLine_Vert
{
public:
	CXScdDrawLine_Ctrls();
	virtual ~CXScdDrawLine_Ctrls();

public:


	

//重载函数
public:
public:
	virtual void Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset);
	virtual UINT GetClassID() {    return XSCDDRAW_LINE_CTRLS;   }
	virtual void InitLinePos();
	virtual void InitToBusLinePos();

};

