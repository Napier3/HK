/*
 *Shandong HuanKe copyright 2025
 *Author: Eric
*/
#pragma once

#include "../../../Module/BaseClass/ExBaseList.h"
#include "HKWgtBase.h"

class HKWgtBaseList : public HKWgtBase, public CTLinkList <HKWgtBase>
{
public:
        HKWgtBaseList(QWidget* pParent = nullptr);
        ~HKWgtBaseList() override;
};
