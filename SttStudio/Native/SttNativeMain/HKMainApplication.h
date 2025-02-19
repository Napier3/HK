/*
 *Shandong HuanKe copyright 2025
 *Author: Eric
*/
#pragma once

#include <QApplication>
#include <QTextCodec>
#include <QSharedMemory>
#include "../../Module/Main/HKMainApplicationBase.h"

class HKMainApplication : public QApplication, public HKMainApplicationBase
{
    Q_OBJECT
public:
  HKMainApplication(int argc, char *argv[]);
  ~HKMainApplication() override;

public:
   void InitApplication(CXLanguageResourceBase *pLanguage);
   void ExitApplication();
};
