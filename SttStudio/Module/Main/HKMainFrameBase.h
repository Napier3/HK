/*
 *Shandong HuanKe copyright 2025
 *Author: Eric
*/
#pragma once
#include "../../../Module/Log/LogPrint.h"
#include "Module/HKWgtCmdExecTool.h"
#include "SttXuiData/SttXMainConfigGlobal.h"
#include "SttXuiData/SttXuiDataMainConfig.h"

#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

class HKMainFrameBase : public QMainWindow, public CLogBase
{
    Q_OBJECT
protected:
    HKWgtCmdExecTool m_oCmdTool;
public:
    explicit HKMainFrameBase(QWidget *parent = nullptr, CString strConfigFile = "");
    ~HKMainFrameBase();

    void InitResource();
    void ReleaseResource();
    void InitUI(CString strConfigFile = "");
    void CreateCloseHidingBtns();
    void CreateCloseBtns();
public:
    QFont m_gFont;
    CSttXuiDataMainConfig* m_pMainConfig;
public slots:
	void slot_CloseApp();
	void slot_HideApp();
};

extern HKMainFrameBase *g_HKMainFrame;
extern double g_dUIShowCoef; //Ëõ·Å±ÈÀý
