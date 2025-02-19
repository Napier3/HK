/*
 *Shandong HuanKe copyright 2025
 *Author: Eric
*/
#pragma once

#include <QToolButton>
#include "../Module/HKWgtBase.h"

class HKButton : public HKWgtBase, public QToolButton
{
public:
    HKButton(QWidget* pParent = nullptr);
    ~HKButton() override;

public:
    void InitUIOwn(CExBaseObject *pSttXuiData) override;
    void OnClick();
    void CalcGeometry(long& nX, long nCy, long nInset);//����ƫ��

private: 
    void mousePressEvent(QMouseEvent *e) override;

};
