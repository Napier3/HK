#pragma once

#include <QWidget>
#include "../Module/SttWgtBaseList.h"
#include "../SttXuiData/SttXuiDataBtnsGroup.h"
#include "../SttXuiData/SttXuiDataTestBtnsGroup.h"

class QSttWgtButtonGroup : public QSttWgtBaseList, public QWidget
{
public:
        QSttWgtButtonGroup(QWidget* pParent = nullptr);
        ~QSttWgtButtonGroup() override;

private:
	void InitTestBtnsGroup(CExBaseObject *pSttXuiData);
	void InitBtnsGroup(CExBaseObject *pSttXuiData);
	virtual void InitTestBtnsGroupChildren(CExBaseObject *pSttXuiData);
        virtual void InitBtnsGroupChildren(CExBaseObject *pSttXuiData);

public:
        void InitUIOwn(CExBaseObject *pSttXuiData) override;
        void InitUIChildren(CExBaseObject *pSttXuiData) override;

};
