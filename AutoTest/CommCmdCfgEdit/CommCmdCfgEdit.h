
// CommCmdCfgEdit.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCommCmdCfgEditApp:
// �йش����ʵ�֣������ CommCmdCfgEdit.cpp
//

class CCommCmdCfgEditApp : public CWinAppEx
{
public:
	CCommCmdCfgEditApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCommCmdCfgEditApp theApp;