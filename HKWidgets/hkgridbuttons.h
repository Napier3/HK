#pragma once

#include <QWidget>
#include <QColor>

namespace Ui {
class HKGridButtons;
}

class QPushButton;

class HKGridButtons : public QWidget
{
    Q_OBJECT

public:
    enum class ButtonID {
        TopLeft,
        Top,
        TopRight,
        Left,
        Right,
        BottomLeft,
        Bottom,
        BottomRight
    };

    explicit HKGridButtons(QWidget *parent = nullptr);
    ~HKGridButtons() override;

    void setButtonVisible(ButtonID id, bool visible);
    void setButtonText(ButtonID id, const QString &text);
    void setMiddleWidget(QWidget *widget);
    void setButtonColor(ButtonID id, const QColor &color);

signals:
    void buttonClicked(ButtonID id);

private slots:
    void handleButtonClick();

private:
    Ui::HKGridButtons *ui;

    QPushButton* buttonPtr(ButtonID id) const;
    ButtonID buttonIDFromSender(QObject *sender) const;
    void setupButtonConnections();
};


//How to use it in main ui class:
/*
HKGridButtons *m_hkGridButtons = nullptr;
private slots:
void onGridButtonClicked(HKGridButtons::ButtonID id);

HKGridButtons *gridBtns = new HKGridButtons(this);
gridBtns->setButtonVisible(HKGridButtons::ButtonID::TopLeft, false);
gridBtns->setButtonText(HKGridButtons::ButtonID::Top, "Go");
gridBtns->setButtonColor(HKGridButtons::ButtonID::Top, Qt::green);

   // Insert the HKGridButtons into your layout
   ui->verticalLayout->addWidget(m_hkGridButtons);

   // Connect the signal
   connect(m_hkGridButtons, &HKGridButtons::buttonClicked, this, &MainUIObject::onGridButtonClicked);
   void UI1::onGridButtonClicked(HKGridButtons::ButtonID id)
   {
       switch (id) {
       case HKGridButtons::ButtonID::Top:
           func1();
           break;
       case HKGridButtons::ButtonID::Left:
           func1();
           break;
       default:
           break;
       }
   }

   or lamda:
connect(gridBtns, &HKGridButtons::buttonClicked,
        this, [&](HKGridButtons::ButtonID id){
    // handle button click
    if (id == HKGridButtons::ButtonID::Top) {
        // do something
    }
});
*/
