//���Դ������ClassGenerator����
//��Ȩ���� LiJunqing  lijunqing1224@126.com
//��������Ȩ��

//XScdDrawIed.h  CXScdDrawIed

#pragma once

#include "XScdDrawGlobal.h"



class CXScdDrawIedBase : public CXDrawElements
{
public:
	CXScdDrawIedBase();
	virtual ~CXScdDrawIedBase();

//���غ���
public:
 	virtual void AttachViewWindow(CXDrawBaseInterface_ViewWindow *pViewWindow);
};

