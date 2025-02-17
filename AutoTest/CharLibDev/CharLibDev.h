// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// ("Fluent UI")����ʾ������Ϊ�ο������ṩ�� 
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://msdn.microsoft.com/officeui��
//
// ��Ȩ���� (C) Microsoft Corporation
// ��������Ȩ����

// CharLibDev.h : CharLibDev Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������
#include "..\Module\Characteristic\CharacteristicLib.h"
#include "XLanguageResourceAts_CharLibDev.h"
#include "..\..\Module\XLanguage\XLangWndAdjust.h"

// CCharLibDevApp:
// �йش����ʵ�֣������ CharLibDev.cpp
//

#include "..\..\Module\DocFrameMngr\DocFrameMngr.h"

class CCharLibDevApp : public CWinAppEx
{
public:
	CCharLibDevApp();

	CCharacteristicLib m_oCharacteristicLib;

	CMultiDocTemplate* m_pDocTemplate;

	void OpenCharTemplate(CCharacteristic *pCharTemp);
	void CloseCharTempFrame(CMDIChildWndEx *pFrame);
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

extern CCharLibDevApp theApp;
