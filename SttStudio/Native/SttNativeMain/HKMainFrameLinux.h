/*
 *Shandong HuanKe copyright 2025
 *Author: Eric
*/
#pragma once
#include "../../Module/Main/HKMainFrameBase.h"
#include "../../Module/TestClient/SttMacroTestInterface.h"
#include <QToolButton>

class HKMainFrameLinux : public HKMainFrameBase, CTestEventBaseInterface
{
    Q_OBJECT
public:
    explicit HKMainFrameLinux(QWidget *parent = nullptr);
    ~HKMainFrameLinux() override;
    void InitBatteryBtn();
    void UpdateBatteryState(int nState);
    long OnRtData(CSttParas *pParas) override;
    long OnDisConnect() override;
public:
    QToolButton m_oBatteryBtn{};//用于电池电量显示
    bool m_bConnected{};//是否联机
    long m_nBatCapValue{};
    long m_nPowerAC{};
    CString m_strCurrStyleString{};
    CString m_strBatCapString{};//用于更新电池电量
    QTimer m_oTimerForConnect{};//用于处理可能存在联机冲突
    int m_nConnectCnt{};//尝试联机十次
    long m_nTesterVerIdx{}; //实时数据VerIdx值 更新鼠标光标显示
private:
    bool m_bLeftPressed{};
    QPoint m_ptStart{};
signals:
	void sig_UpdateBatteryState();
public slots:
	void slot_UpdateBatteryState();
	void slot_SttConnect();
};
