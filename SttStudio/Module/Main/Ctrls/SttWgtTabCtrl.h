#pragma once

#include <QTabWidget>
#include "../Module/SttWgtBaseList.h"

class QSttWgtTabCtrl : public QSttWgtBaseList, public QTabWidget
{
public:
    QSttWgtTabCtrl(QWidget* pParent = nullptr);
    ~QSttWgtTabCtrl() override;

public:
    void InitUIOwn(CExBaseObject *pSttXuiData) override;
    void InitUIChildren(CExBaseObject *pSttXuiData) override;
};

class QSttWgtTab : public QSttWgtBase, public QWidget
{
public:
    QSttWgtTab(QWidget* pParent = nullptr);
    ~QSttWgtTab() override;

public:
    void InitUIOwn(CExBaseObject *pSttXuiData) override;
    void InitUIChildren(CExBaseObject *pSttXuiData) override;
	void AddWidgetChild(QWidget *pChildWidget);
};
