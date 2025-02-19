/*
 *Shandong HuanKe copyright 2025
 *Author: Eric
*/
#pragma once

#include <QWidget>
#include "../Module/HKWgtBaseList.h"
#include "../SttXuiData/SttXuiDataBtnsGroup.h"
#include "../SttXuiData/SttXuiDataTestBtnsGroup.h"

class HKButtonGroup : public HKWgtBaseList, public QWidget
{
public:
    HKButtonGroup(QWidget* pParent = nullptr);
    ~HKButtonGroup() override;

private:
	void InitTestBtnsGroup(CExBaseObject *pSttXuiData);
	void InitBtnsGroup(CExBaseObject *pSttXuiData);
	virtual void InitTestBtnsGroupChildren(CExBaseObject *pSttXuiData);
    virtual void InitBtnsGroupChildren(CExBaseObject *pSttXuiData);

public:
    void InitUIOwn(CExBaseObject *pSttXuiData) override;
    void InitUIChildren(CExBaseObject *pSttXuiData) override;
};
