#include "HKMainApplication.h"

HKMainApplication::HKMainApplication(int argc, char *argv[]):QApplication(argc,argv){}

HKMainApplication::~HKMainApplication(){}

void HKMainApplication::InitApplication(CXLanguageResourceBase *pLanguage)
{
   QTextCodec *codec = QTextCodec::codecForName("GBK");
   QTextCodec::setCodecForLocale(codec);
   HKMainApplicationBase::InitHKMainApp(pLanguage);
}

void HKMainApplication::ExitApplication()
{
    HKMainApplicationBase::ExitHKMainApp();
}
