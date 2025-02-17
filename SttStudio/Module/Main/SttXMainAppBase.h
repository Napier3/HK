#pragma once

#include "../../../Module/XLanguage/XLanguageMngr.h"
#include "../../../Module/DataMngr/DataMngrGlobal.h"

class CSttXMainAppBase
{
public:
    CSttXMainAppBase();
    virtual ~CSttXMainAppBase();
    virtual void InitSttXMainApp(CXLanguageResourceBase *pLanguage = nullptr);
    virtual void ExitSttXMainApp();
public:
	void OnCmd_StartSttXMain();
	void OnCmd_StopSttXMain();
};

extern CSttXMainAppBase *g_pTheSttXMainApp;
