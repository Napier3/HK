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
    QToolButton m_oBatteryBtn{};//���ڵ�ص�����ʾ
    bool m_bConnected{};//�Ƿ�����
    long m_nBatCapValue{};
    long m_nPowerAC{};
    CString m_strCurrStyleString{};
    CString m_strBatCapString{};//���ڸ��µ�ص���
    QTimer m_oTimerForConnect{};//���ڴ�����ܴ���������ͻ
    int m_nConnectCnt{};//��������ʮ��
    long m_nTesterVerIdx{}; //ʵʱ����VerIdxֵ �����������ʾ
private:
    bool m_bLeftPressed{};
    QPoint m_ptStart{};
signals:
	void sig_UpdateBatteryState();
public slots:
	void slot_UpdateBatteryState();
	void slot_SttConnect();
};
