#pragma once

#include"SttMacroTestMsgRcvInterface.h"


class CSttMacroTestMsgRcvInterface_Win : public CSttMacroTestMsgRcvInterface
{
public:
	CSttMacroTestMsgRcvInterface_Win();
	virtual ~CSttMacroTestMsgRcvInterface_Win();
	
public:
    virtual void PostTestWndMsg(WPARAM wParam, LPARAM lParam)
    {
    	if (!::IsWindow(((HWND)m_hMsgWnd)))
			{
			return;
			}

		::PostMessage((HWND)m_hMsgWnd, m_nMsgID, wParam, lParam);
    }



protected:
	DECLARE_MESSAGE_MAP()

};

