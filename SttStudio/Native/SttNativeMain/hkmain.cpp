#include "hkmain.h"
#include "ui_hkmain.h"

HKMain::HKMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HKMain)
{
    ui->setupUi(this);
}

HKMain::~HKMain()
{
    delete ui;
}
