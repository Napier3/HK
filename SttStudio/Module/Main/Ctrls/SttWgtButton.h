#pragma once

#include <QToolButton>
#include "../Module/SttWgtBase.h"

class QSttWgtButton : public QSttWgtBase, public QToolButton
{
public:
    QSttWgtButton(QWidget* pParent = nullptr);
    ~QSttWgtButton() override;

public:
    void InitUIOwn(CExBaseObject *pSttXuiData) override;
	void OnClick();
	void CalcGeometry(long& nX, long nCy, long nInset);//¼ÆËãÆ«ÒÆ

private: 
    void mousePressEvent(QMouseEvent *e) override;

};
