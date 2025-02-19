/*
 *Shandong HuanKe copyright 2025
 *Author: Eric
*/
#pragma once

#include <QThread>
#include <QStringList>
#include "../../../../Module/OSInterface/QT/CString_QT.h"

class HKWgtCmdThread : public QThread
{
public:
    HKWgtCmdThread();
    ~HKWgtCmdThread() override;

    QString m_strPath{};
    QStringList m_listCmd{};
    CString m_strExe{};

	static void start_exe(const CString &strExe, const CString &strArguments);
	static void startDetached_exe(const CString &strExe, const CString &strArguments);
public:
    void run() override;

};
