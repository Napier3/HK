/*
 *Shandong HuanKe copyright 2025
 *Author: Eric
*/
#pragma once

#include "HKWgtBase.h"
#include "../SttXuiData/SttXuiDataBase.h"

class HKWgtFactory : public CExBaseList
{
public:
    HKWgtFactory();
    virtual ~HKWgtFactory();

    static HKWgtFactory *Create();
	static void Release();

public:
    static HKWgtBase* CreateHKWgt(CSttXuiDataBase *pSttXuiData, QWidget* pParent);
};

extern HKWgtFactory* g_pHKWgtFactory;
extern long g_nHKWgtFactoryRef;
