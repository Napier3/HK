#pragma once

#include <QLabel>
#include "../Module/SttWgtBaseList.h"

class QSttWgtText : public QSttWgtBaseList, public QLabel
{
public:
    QSttWgtText(QWidget* pParent = nullptr);
    ~QSttWgtText() override;

private:
	void SetWgtStyle(QSttWgtStyle* pStyle);

public:
    void InitUIOwn(CExBaseObject *pSttXuiData) override;

};
