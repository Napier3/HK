#include "hkgridbuttons.h"
#include "ui_hkgridbuttons.h"

#include <QPushButton>
#include <QLayoutItem>
#include <QVBoxLayout> // or QHBoxLayout if you like

HKGridButtons::HKGridButtons(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HKGridButtons)
{
    ui->setupUi(this);
    setupButtonConnections();
}

HKGridButtons::~HKGridButtons()
{
    delete ui;
}

void HKGridButtons::setupButtonConnections()
{
    connect(ui->m_pushButtonTopLeft,    &QPushButton::clicked,
            this, &HKGridButtons::handleButtonClick);
    connect(ui->m_pushButtonTop,        &QPushButton::clicked,
            this, &HKGridButtons::handleButtonClick);
    connect(ui->m_pushButtonTopRight,   &QPushButton::clicked,
            this, &HKGridButtons::handleButtonClick);
    connect(ui->m_pushButtonLeft,       &QPushButton::clicked,
            this, &HKGridButtons::handleButtonClick);
    connect(ui->m_pushButtonRight,      &QPushButton::clicked,
            this, &HKGridButtons::handleButtonClick);
    connect(ui->m_pushButtonBottomLeft, &QPushButton::clicked,
            this, &HKGridButtons::handleButtonClick);
    connect(ui->m_pushButtonBottom,     &QPushButton::clicked,
            this, &HKGridButtons::handleButtonClick);
    connect(ui->m_pushButtonBottomRight,&QPushButton::clicked,
            this, &HKGridButtons::handleButtonClick);
}

void HKGridButtons::handleButtonClick()
{
    ButtonID id = buttonIDFromSender(sender());
    emit buttonClicked(id);
}

HKGridButtons::ButtonID HKGridButtons::buttonIDFromSender(QObject *sender) const
{
    if      (sender == ui->m_pushButtonTopLeft)    return ButtonID::TopLeft;
    else if (sender == ui->m_pushButtonTop)        return ButtonID::Top;
    else if (sender == ui->m_pushButtonTopRight)   return ButtonID::TopRight;
    else if (sender == ui->m_pushButtonLeft)       return ButtonID::Left;
    else if (sender == ui->m_pushButtonRight)      return ButtonID::Right;
    else if (sender == ui->m_pushButtonBottomLeft) return ButtonID::BottomLeft;
    else if (sender == ui->m_pushButtonBottom)     return ButtonID::Bottom;
    else if (sender == ui->m_pushButtonBottomRight)return ButtonID::BottomRight;

    // fallback
    return ButtonID::Top;
}

QPushButton* HKGridButtons::buttonPtr(ButtonID id) const
{
    switch (id)
    {
    case ButtonID::TopLeft:     return ui->m_pushButtonTopLeft;
    case ButtonID::Top:         return ui->m_pushButtonTop;
    case ButtonID::TopRight:    return ui->m_pushButtonTopRight;
    case ButtonID::Left:        return ui->m_pushButtonLeft;
    case ButtonID::Right:       return ui->m_pushButtonRight;
    case ButtonID::BottomLeft:  return ui->m_pushButtonBottomLeft;
    case ButtonID::Bottom:      return ui->m_pushButtonBottom;
    case ButtonID::BottomRight: return ui->m_pushButtonBottomRight;
    }
    return nullptr; // not reached, but safe fallback
}

void HKGridButtons::setButtonVisible(ButtonID id, bool visible)
{
    if (auto btn = buttonPtr(id))
    {
        btn->setVisible(visible);
    }
}

void HKGridButtons::setButtonText(ButtonID id, const QString &text)
{
    if (auto btn = buttonPtr(id))
    {
        btn->setText(text);
    }
}

void HKGridButtons::setMiddleWidget(QWidget *widget)
{
    QLayoutItem *childItem = nullptr;
    while ((childItem = ui->m_centerLayout->takeAt(0)) != nullptr)
    {
        if (auto oldWidget = childItem->widget()) {
            oldWidget->deleteLater();
        }
        delete childItem;
    }

    if (widget) {
        ui->m_centerLayout->addWidget(widget);
    }
}

void HKGridButtons::setButtonColor(ButtonID id, const QColor &color)
{
    if (auto btn = buttonPtr(id)) {
        const QString style = QString("background-color: %1;")
                              .arg(color.name(QColor::HexRgb));
        btn->setStyleSheet(style);
    }
}

