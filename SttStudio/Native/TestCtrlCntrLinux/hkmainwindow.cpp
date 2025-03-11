#include "hkmainwindow.h"
#include "ui_hkmainwindow.h"

#include <QTabWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

// Helper: map each ExtraTabPage to a display text
static QString tabTitle(ExtraTabPage page)
{
    switch (page) {
    case ExtraTabPage::ThreeState:  return QStringLiteral("3̬");
    case ExtraTabPage::FourState:   return QStringLiteral("4̬");
    case ExtraTabPage::FiveState:   return QStringLiteral("5̬");
    case ExtraTabPage::SixState:    return QStringLiteral("6̬");
    case ExtraTabPage::SevenState:  return QStringLiteral("7̬");
    case ExtraTabPage::EightState:  return QStringLiteral("8̬");
    }
    return QStringLiteral("Unknown");
}

// Create a QWidget with a label inside, just for demo
static QWidget* createPageWidget(const QString &labelText, QWidget *parent = nullptr)
{
    QWidget *page = new QWidget(parent);
    QVBoxLayout *layout = new QVBoxLayout(page);
    layout->setContentsMargins(20, 20, 20, 20);
    layout->addWidget(new QLabel(labelText, page));
    page->setLayout(layout);
    return page;
}

HKMainWindow::HKMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HKMainWindow)
{
    ui->setupUi(this);
    InitUI();
    InitSignalConnection();
    connect(ui->m_buttonClose, &QPushButton::clicked, this, &QMainWindow::close);
}

HKMainWindow::~HKMainWindow()
{
    delete ui;
}

void HKMainWindow::InitUI()
{
    // Example usage of your custom toggle
    ui->m_currentToggle->setOnText("3I");
    ui->m_currentToggle->setOffText("6I");
    SwitchParameters(true);
    CreateTabCornerWidget();
}

void HKMainWindow::InitSignalConnection()
{
    connect(ui->m_currentToggle, &HKToggleButton::toggled, this, &HKMainWindow::SwitchParameters);
}

void HKMainWindow::CreateTabCornerWidget()
{
    // 1. Create corner widget with plus/minus in top-right of the tab widget
    QWidget *cornerWidget = new QWidget(this);
    QHBoxLayout *cornerLayout = new QHBoxLayout(cornerWidget);
    cornerLayout->setContentsMargins(0, 0, 0, 0);

    m_plusButton  = new QPushButton(QStringLiteral("+"), cornerWidget);
    m_minusButton = new QPushButton(QStringLiteral("-"), cornerWidget);

    cornerLayout->addWidget(m_plusButton);
    cornerLayout->addWidget(m_minusButton);
    cornerWidget->setLayout(cornerLayout);

    // Attach corner widget to the top-right corner of our tab widget
    ui->m_stateTab->setCornerWidget(cornerWidget, Qt::TopRightCorner);

    // Connect signals to our slots
    connect(m_plusButton,  &QPushButton::clicked, this, &HKMainWindow::InsertOneTab);
    connect(m_minusButton, &QPushButton::clicked, this, &HKMainWindow::RemoveOneTab);

    // 2. Prepare the EXTRA tabs (3̬..8̬) but do NOT insert them yet
    m_extraTabInfos.append({nullptr, tabTitle(ExtraTabPage::ThreeState),  ExtraTabPage::ThreeState});
    m_extraTabInfos.append({nullptr, tabTitle(ExtraTabPage::FourState),   ExtraTabPage::FourState});
    m_extraTabInfos.append({nullptr, tabTitle(ExtraTabPage::FiveState),   ExtraTabPage::FiveState});
    m_extraTabInfos.append({nullptr, tabTitle(ExtraTabPage::SixState),    ExtraTabPage::SixState});
    m_extraTabInfos.append({nullptr, tabTitle(ExtraTabPage::SevenState),  ExtraTabPage::SevenState});
    m_extraTabInfos.append({nullptr, tabTitle(ExtraTabPage::EightState),  ExtraTabPage::EightState});
}

void HKMainWindow::InsertOneTab()
{
    // If we've already inserted all the extra tabs, do nothing
    if (m_insertedCount >= m_extraTabInfos.size()) {
        return;
    }

    // The next tab to insert is at index = m_insertedCount
    TabInfo &info = m_extraTabInfos[m_insertedCount];
    if (!info.widget) {
        // create the widget if not already created
        info.widget = createPageWidget(info.title, this);
    }

    // We want the first extra tab to appear at index=2 in the tab widget
    // next at index=3, etc., so the formula is (2 + m_insertedCount).
    int insertPosition = 2 + m_insertedCount;

    // Insert the tab
    ui->m_stateTab->insertTab(insertPosition, info.widget, info.title);

    // We have inserted one more
    m_insertedCount++;
}

// Remove exactly ONE tab (the last one in the list, if it��s currently inserted)
void HKMainWindow::RemoveOneTab()
{
    // If no extra tabs are inserted, do nothing
    if (m_insertedCount <= 0) {
        return;
    }

    // The last inserted tab is at index (m_insertedCount - 1)
    m_insertedCount--; // we will remove that one
    TabInfo &info = m_extraTabInfos[m_insertedCount];

    // Make sure it exists and is in the tab widget
    if (info.widget) {
        int idx = ui->m_stateTab->indexOf(info.widget);
        if (idx != -1) {
            ui->m_stateTab->removeTab(idx);
        }
    }
}

void HKMainWindow::SwitchParameters(bool checked)
{
    if (checked)
    {
        ui->m_parameterStack->setCurrentIndex(0);
        ui->m_parameterLabels->setCurrentIndex(0);
    }else
    {
        ui->m_parameterStack->setCurrentIndex(1);
        ui->m_parameterLabels->setCurrentIndex(1);
    }
    ui->m_labelCurAmplitude->setHidden(checked);
    ui->m_labelCurPhase->setHidden(checked);
    ui->m_labelCurFrequency->setHidden(checked);
}
