
// DllCallClient.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDllCallClientApp:
// �йش����ʵ�֣������ DllCallClient.cpp
//

class CDllCallClientApp : public CWinAppEx
{
public:
	CDllCallClientApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CDllCallClientApp theApp;