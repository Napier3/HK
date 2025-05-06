#ifndef HKMAIN_H
#define HKMAIN_H

#include <QMainWindow>

namespace Ui {
class HKMain;
}

class HKMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit HKMain(QWidget *parent = nullptr);
    ~HKMain();

private:
    Ui::HKMain *ui;
};

#endif // HKMAIN_H
