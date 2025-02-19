/*
 *Shandong HuanKe copyright 2025
 *Author: Eric
*/
#pragma once

#include <QTabWidget>
#include "../Module/HKWgtBaseList.h"

class HkTabWidget : public HKWgtBaseList, public QTabWidget
{
public:
    HkTabWidget(QWidget* pParent = nullptr);
    ~HkTabWidget() override;

public:
    void InitUIOwn(CExBaseObject *pSttXuiData) override;
    void InitUIChildren(CExBaseObject *pSttXuiData) override;
};

class HkTabPage : public HKWgtBase, public QWidget
{
public:
    HkTabPage(QWidget* pParent = nullptr);
    ~HkTabPage() override;

public:
    void InitUIOwn(CExBaseObject *pSttXuiData) override;
    void InitUIChildren(CExBaseObject *pSttXuiData) override;
	void AddWidgetChild(QWidget *pChildWidget);
};
