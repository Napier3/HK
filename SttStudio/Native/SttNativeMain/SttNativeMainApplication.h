#pragma once

#include <QApplication>
#include <QTextCodec>
#include <QSharedMemory>
#include "../../Module/Main/SttXMainAppBase.h"

class CSttNativeMainApplication : public QApplication, public CSttXMainAppBase
{
    Q_OBJECT
public:
#ifdef _PSX_OS_CENTOS_
   CSttNativeMainApplication(Display *pDisplay);
#else
  CSttNativeMainApplication(int argc, char *argv[]);
#endif
  virtual ~CSttNativeMainApplication();

public:
   void InitSttMainApp(CXLanguageResourceBase *pLanguage);
   void ExitSttMainApp();
};
