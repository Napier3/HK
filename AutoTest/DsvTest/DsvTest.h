
// DsvTest.h : DsvTest Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������

#include "..\..\Module\DataMngr\DatasetValid\DsvScript.h"

// CDsvTestApp:
// �йش����ʵ�֣������ DsvTest.cpp
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

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
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
