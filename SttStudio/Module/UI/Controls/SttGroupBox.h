#ifndef QSTTGROPBOX_H
#define QSTTGROPBOX_H

#include <QGroupBox>

class QSttGroupBox : public QGroupBox
{
	Q_OBJECT

public:
        QSttGroupBox(QWidget *parent = nullptr);
        QSttGroupBox(const QString &text,QWidget *parent = nullptr);
	~QSttGroupBox();

public:
	void InitStyleSheet();

protected slots:
	
};

extern QFont *g_pSttGlobalFont;

#endif // QSTTGROPBOX_H
