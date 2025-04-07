#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QList>

#include "../../UI/SoftKeyboard/SoftKeyBoard.h"

namespace Ui {
class HKMainWindow;
}

// Enum class for the EXTRA tabs only (3̬..8̬).
enum class ExtraTabPage {
    ThreeState = 3,
    FourState,
    FiveState,
    SixState,
    SevenState,
    EightState
};


struct TabInfo {
    QWidget      *widget = nullptr; // pointer to the actual tab widget
    QString       title;            // tab label text
    ExtraTabPage  page;             // which 'page' (3̬..8̬) this tab is
};

class HKMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HKMainWindow(QWidget *parent = nullptr);
    ~HKMainWindow();

    void InitUI();
    void InitSignalConnection();
    void CreateTabCornerWidget();

private slots:
    void InsertOneTab();
    void InitComboBox();
    void RemoveOneTab();
    void SwitchParameters(bool checked);
    void AttachKeyboard();

private:
    Ui::HKMainWindow *ui;

    QPushButton *m_plusButton  = nullptr;
    QPushButton *m_minusButton = nullptr;

    // Keep the list of "extra" tabs (3̬..8̬)
    QList<TabInfo> m_extraTabInfos;

    int m_insertedCount = 0;
};
