//���Դ������ClassGenerator����
//��Ȩ���� LiJunqing  lijunqing1224@126.com
//��������Ȩ��

//XScdDrawIed.cpp  CXScdDrawIed


#include "stdafx.h"
#include "XScdDrawIedCfg.h"

CXScdDrawIedBase::CXScdDrawIedBase()
{
	//��ʼ������

	//��ʼ����Ա����
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
