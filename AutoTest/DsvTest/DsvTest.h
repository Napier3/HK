
// DsvTest.h : DsvTest 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号

#include "..\..\Module\DataMngr\DatasetValid\DsvScript.h"

// CDsvTestApp:
// 有关此类的实现，请参阅 DsvTest.cpp
//

class CDsvTestFormView;

class CDsvTestApp : public CWinAppEx
{
public:
	CDsvTestApp();

	CDsvScript m_oDsvScript;
	CDvmDataset m_oDataSet;
	CDvmDataset m_oSoeForDsv;

	CDsvTestFormView *m_pDsvTestFormView;

	void InitDsvScript();

// 重写
public:
	virtual BOOL InitInstance();

// 实现
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CDsvTestApp theApp;
