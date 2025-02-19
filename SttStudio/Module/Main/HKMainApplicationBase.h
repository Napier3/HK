/*
 *Shandong HuanKe copyright 2025
 *Author: Eric
*/
#pragma once

#include "../../../Module/XLanguage/XLanguageMngr.h"
#include "../../../Module/DataMngr/DataMngrGlobal.h"

class HKMainApplicationBase
{
public:
    HKMainApplicationBase();
    virtual ~HKMainApplicationBase();
    virtual void InitHKMainApp(CXLanguageResourceBase *pLanguage = nullptr);
    virtual void ExitHKMainApp();
public:
    void OnCmd_StartHKMain();
    void OnCmd_StopHKMain();
};

extern HKMainApplicationBase *g_HKMainApp;
