
// GbChar.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGbCharApp:
// �йش����ʵ�֣������ GbChar.cpp
//

class CGbCharApp : public CWinAppEx
{
public:
	CGbCharApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGbCharApp theApp;