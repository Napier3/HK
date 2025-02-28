#pragma once
#include <QMessageBox>

class CXMessageBox : public QMessageBox
{
public:
	static int information(QWidget *parent, const QString &title,
		const QString &text, StandardButtons buttons = Ok,
		StandardButton defaultButton = NoButton)
	{
		QMessageBox messageBox(NoIcon, title, text, buttons, parent);
		messageBox.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
		return messageBox.exec();
	}
};
