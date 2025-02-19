/*
 *Shandong HuanKe copyright 2025
 *Author: Eric
*/
#pragma once

#include <QLabel>
#include "../Module/HKWgtBaseList.h"

class HKWgtText : public HKWgtBaseList, public QLabel
{
public:
    HKWgtText(QWidget* pParent = nullptr);
    ~HKWgtText() override;

private:
    void SetWgtStyle(HKWgtStyle* pStyle);

public:
    void InitUIOwn(CExBaseObject *pSttXuiData) override;

};
