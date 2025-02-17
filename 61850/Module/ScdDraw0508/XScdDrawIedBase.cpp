//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawIed.cpp  CXScdDrawIed


#include "stdafx.h"
#include "XScdDrawIedCfg.h"

CXScdDrawIedBase::CXScdDrawIedBase()
{
	//初始化属性

	//初始化成员变量
}

CXScdDrawIedBase::~CXScdDrawIedBase()
{
}

void CXScdDrawIedBase::AttachViewWindow(CXDrawBaseInterface_ViewWindow *pViewWindow)
{
	POS pos = GetHeadPosition();
	CXScdDrawCtrlBase *pCtrlBase = NULL;

	while (pos != NULL)
	{
		pCtrlBase = (CXScdDrawCtrlBase *)GetNext(pos);
		pCtrlBase->AttachViewWindow(pViewWindow);
	}
}
