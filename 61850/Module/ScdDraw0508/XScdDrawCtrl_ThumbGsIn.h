//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawCtrl_ThumbGsIn.h  CXScdDrawCtrl_ThumbGsIn

#pragma once

#include "XScdDrawCtrl_ThumbBase.h"

class CXScdDrawCtrl_ThumbGsIn : public CXScdDrawCtrl_ThumbBase
{
public:
	CXScdDrawCtrl_ThumbGsIn();
	virtual ~CXScdDrawCtrl_ThumbGsIn();
public:
	
	

	//重载函数
public:
	virtual void Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset);
	virtual void CreateCtrlLines();

	//私有成员变量
private:

	//私有成员变量访问方法
public:

	//绘图相关函数定义
public:

};