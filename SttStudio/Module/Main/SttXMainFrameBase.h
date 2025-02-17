#pragma once

#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include "../../../Module/Log/LogPrint.h"
#include "Module/SttWgtCmdExecTool.h"
#include "SttXuiData/SttXMainConfigGlobal.h"
#include "SttXuiData/SttXuiDataMainConfig.h"

class QSttXMainFrameBase : public QMainWindow, public CLogBase
{
    Q_OBJECT

protected:
	QSttWgtCmdExecTool m_oCmdTool;//用于响应挂载cmd
public:
    explicit QSttXMainFrameBase(QWidget *parent = nullptr, CString strConfigFile = "");
    ~QSttXMainFrameBase();

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

extern QSttXMainFrameBase *g_theSttXMainFrame;
extern double g_dUIShowCoef; // 界面显示缩放比例
