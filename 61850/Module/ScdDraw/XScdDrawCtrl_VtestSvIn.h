//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawCtrl_VtestSvIn.h  CXScdDrawCtrl_VtestSvIn

#pragma once

#include "XScdDrawCtrlBase.h"
#include "XScdDrawCtrl_GridBase.h"


//////////////////////////////////////////////////////////////////////////
class CXScdDrawCtrl_VtestGridTitleSvIn : public CXScdDrawCtrl_VtestGridTitleBase
{
public:
	CXScdDrawCtrl_VtestGridTitleSvIn();
	virtual ~CXScdDrawCtrl_VtestGridTitleSvIn();

	//重载函数
public:
	virtual void ShowTitle(CExBaseObject *pData);

	//私有成员变量
private:

	//私有成员变量访问方法
public:

	//绘图相关函数定义
public:


};

//////////////////////////////////////////////////////////////////////////
class CXScdDrawCtrl_VtestGridChsSvIn : public CXScdDrawCtrl_VtestGridChsBase
{
public:
	CXScdDrawCtrl_VtestGridChsSvIn();
	virtual ~CXScdDrawCtrl_VtestGridChsSvIn();

	CIecVtestDataBase *m_pIecfgData;

//重载函数
public:
	virtual void ShowData(CExBaseObject *pData, int& nRow, BOOL bInsertRow=TRUE);

	//私有成员变量
private:

	//私有成员变量访问方法
public:

	//绘图相关函数定义
public:

};

//////////////////////////////////////////////////////////////////////////
//CXScdDrawCtrl_VtestSvIn
class CXScdDrawCtrl_VtestSvIn : public CXScdDrawCtrlBase
{
public:
	CXScdDrawCtrl_VtestSvIn();
	virtual ~CXScdDrawCtrl_VtestSvIn();

//重载函数
public:
 	virtual UINT GetClassID() {    return XSCDDRAW_CTRL_CFG_SVIN;   }

//私有成员变量
private:

//私有成员变量访问方法
public:

//绘图相关函数定义
public:
	virtual void Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset);

protected:
	virtual DWORD XCreateElement_Title(CExBaseObject *pData, CWnd *pParentWnd);
	virtual DWORD XCreateElement_Chs(CExBaseObject *pData, CWnd *pParentWnd);

};

