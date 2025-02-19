#include "XLangResource_SttNativeMain.h"
#include "HKMainFrameLinux.h"
#include "HKMainApplication.h"
#include "../../../Module/API/GlobalConfigApi.h"
#include "../../../Module/XLanguage/XLanguageMngr.h"
#include "../../../Module/API/StringConvertApi.h"
#include <QDebug>
#include <QTextCodec>
#include <QSharedMemory>
#include <QMessageBox>
#include <QMainWindow>
#include <QApplication>

#ifdef USE_Custom_CDateTime
#include "../../../Module/OSInterface/QT/CDateTime_QT.h"
#endif

int main(int argc, char *argv[])
{
    QSharedMemory *shareMem = new QSharedMemory(QString("HKMain"));

    volatile short i = 2;
    while (i--)
    {
        if(shareMem->attach(QSharedMemory::ReadOnly))
        {
            shareMem->detach();
        }
    }
    if(!shareMem->create(1))
    {
        qDebug() << "Error: HKMain is exist !";
        return 0;
    }
#ifdef USE_Custom_CDateTime
    CDateTime::CreateClientDataTime();
#endif
    HKMainApplication oHKMainApplication(argc,argv);
    oHKMainApplication.InitApplication(new CXLangResource_SttNativeMain());
    HKMainFrameLinux oHKMainFrameLinux;
    g_pHKWgtCmdExecTool->m_oStartTickCount.Enter();
    oHKMainFrameLinux.show();
    oHKMainApplication.exec();

    if(shareMem->isAttached())
    {
        shareMem->detach();
    }
    delete shareMem;
#ifdef USE_Custom_CDateTime
    CDateTime::ReleaseClientDataTime();
#endif
    return 0;
}
