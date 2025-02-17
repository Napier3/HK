#pragma once

#include "../../../Module/BaseClass/ExBaseList.h"
#include "SttWgtBase.h"

class QSttWgtBaseList : public QSttWgtBase, public CTLinkList <QSttWgtBase>
{
public:
        QSttWgtBaseList(QWidget* pParent = nullptr);
        ~QSttWgtBaseList() override;

};
