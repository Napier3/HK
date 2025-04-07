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
    case ExtraTabPage::ThreeState:  return QString::fromLocal8Bit("3态");
    case ExtraTabPage::FourState:   return QString::fromLocal8Bit("4态");
    case ExtraTabPage::FiveState:   return QString::fromLocal8Bit("5态");
    case ExtraTabPage::SixState:    return QString::fromLocal8Bit("6态");
    case ExtraTabPage::SevenState:  return QString::fromLocal8Bit("7态");
    case ExtraTabPage::EightState:  return QString::fromLocal8Bit("8态");
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
    if (!g_pSoftKeyBoard)
    {
            g_pSoftKeyBoard = new QSoftKeyBoard();
    }
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
    InitComboBox();
    AttachKeyboard();
}

void HKMainWindow::InitSignalConnection()
{
    connect(ui->m_currentToggle, &HKToggleButton::toggled, this, &HKMainWindow::SwitchParameters);
}

void HKMainWindow::InitComboBox()
{
    ui->m_comboTrigger->addItem(QString::fromLocal8Bit("手动"));
    ui->m_comboTrigger->addItem(QString::fromLocal8Bit("时间"));
    ui->m_comboTrigger->addItem(QString::fromLocal8Bit("开入量"));
    ui->m_comboStep1->addItem(QString::fromLocal8Bit("幅值"));
    ui->m_comboStep1->addItem(QString::fromLocal8Bit("相位"));
    ui->m_comboStep1->addItem(QString::fromLocal8Bit("频率"));
    ui->m_comboStep2->addItem(QString::fromLocal8Bit("幅值"));
    ui->m_comboStep2->addItem(QString::fromLocal8Bit("相位"));
    ui->m_comboStep2->addItem(QString::fromLocal8Bit("频率"));
    ui->m_comboVariable1->addItem(QString::fromLocal8Bit("1UA"));
    ui->m_comboVariable1->addItem(QString::fromLocal8Bit("1UB"));
    ui->m_comboVariable1->addItem(QString::fromLocal8Bit("1UC"));
    ui->m_comboVariable1->addItem(QString::fromLocal8Bit("1UA,B"));
    ui->m_comboVariable1->addItem(QString::fromLocal8Bit("1UB,C"));
    ui->m_comboVariable1->addItem(QString::fromLocal8Bit("1UA,C"));
    ui->m_comboVariable1->addItem(QString::fromLocal8Bit("1UABC"));
    ui->m_comboVariable1->addItem(QString::fromLocal8Bit("1IA"));
    ui->m_comboVariable1->addItem(QString::fromLocal8Bit("1IB"));
    ui->m_comboVariable1->addItem(QString::fromLocal8Bit("1IC"));
    ui->m_comboVariable1->addItem(QString::fromLocal8Bit("1IABC"));
    ui->m_comboVariable1->addItem(QString::fromLocal8Bit("1负序电压"));
    ui->m_comboVariable1->addItem(QString::fromLocal8Bit("1阻抗三项"));
    ui->m_comboVariable1->addItem(QString::fromLocal8Bit("Udc"));
    ui->m_comboVariable2->addItem(QString::fromLocal8Bit("通道一"));
    ui->m_comboVariable2->addItem(QString::fromLocal8Bit("通道二"));
    ui->m_comboVariable2->addItem(QString::fromLocal8Bit("通道三"));
    ui->m_comboVariable2->addItem(QString::fromLocal8Bit("通道四"));
    ui->m_comboVariable3->addItem(QString::fromLocal8Bit("1UA"));
    ui->m_comboVariable3->addItem(QString::fromLocal8Bit("1UB"));
    ui->m_comboVariable3->addItem(QString::fromLocal8Bit("1UC"));
    ui->m_comboVariable3->addItem(QString::fromLocal8Bit("1UA,B"));
    ui->m_comboVariable3->addItem(QString::fromLocal8Bit("1UB,C"));
    ui->m_comboVariable3->addItem(QString::fromLocal8Bit("1UA,C"));
    ui->m_comboVariable3->addItem(QString::fromLocal8Bit("1UABC"));
    ui->m_comboVariable3->addItem(QString::fromLocal8Bit("1IA"));
    ui->m_comboVariable3->addItem(QString::fromLocal8Bit("1IB"));
    ui->m_comboVariable3->addItem(QString::fromLocal8Bit("1IC"));
    ui->m_comboVariable3->addItem(QString::fromLocal8Bit("1IABC"));
    ui->m_comboVariable3->addItem(QString::fromLocal8Bit("1负序电压"));
    ui->m_comboVariable3->addItem(QString::fromLocal8Bit("1阻抗三项"));
    ui->m_comboVariable3->addItem(QString::fromLocal8Bit("Udc"));
    ui->m_comboVariable4->addItem(QString::fromLocal8Bit("通道一"));
    ui->m_comboVariable4->addItem(QString::fromLocal8Bit("通道二"));
    ui->m_comboVariable4->addItem(QString::fromLocal8Bit("通道三"));
    ui->m_comboVariable4->addItem(QString::fromLocal8Bit("通道四"));
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

    // 2. Prepare the EXTRA tabs (3态..8态) but do NOT insert them yet
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

// Remove exactly ONE tab (the last one in the list, if it’s currently inserted)
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

void HKMainWindow::AttachKeyboard()
{
    QList<QSpinBox*> spinList = this->findChildren<QSpinBox*>();
    for (QSpinBox *spin : spinList)
    {
        // You already set "NoButtons" in .ui (spin->setButtonSymbols(QAbstractSpinBox::NoButtons))
        // Make sure spin has focus policy so that the user can click it
        spin->setFocusPolicy(Qt::StrongFocus);
        // Ensure the internal line-edit is actually created
        spin->setAttribute(Qt::WA_InputMethodEnabled, true);

        // 1) Get the internal QLineEdit
        if (QLineEdit *spinLineEdit = spin->findChild<QLineEdit*>())
        {
            // 2) Attach the soft keyboard to that line-edit
            QSoftKeyBoard::AttachObj(spinLineEdit, Keyboard::ONLYNUMBER);
        }
    }
}
