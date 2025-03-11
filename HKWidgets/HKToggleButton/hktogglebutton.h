#ifndef HKTOGGLEBUTTON_H
#define HKTOGGLEBUTTON_H

#include <QAbstractButton>
#include <QColor>
#include <QWidget>

class HKToggleButton : public QAbstractButton
{
    Q_OBJECT

    // Exposed as properties so you can set them in Designer (via "Promote to ...") or in code
    Q_PROPERTY(QColor onColor  READ onColor  WRITE setOnColor)
    Q_PROPERTY(QColor offColor READ offColor WRITE setOffColor)
    Q_PROPERTY(QString onText  READ onText   WRITE setOnText)
    Q_PROPERTY(QString offText READ offText  WRITE setOffText)

public:
    explicit HKToggleButton(QWidget *parent = nullptr);

    // Getters / setters for colors
    QColor onColor() const;
    void setOnColor(const QColor &color);

    QColor offColor() const;
    void setOffColor(const QColor &color);

    // Getters / setters for labels
    QString onText() const;
    void setOnText(const QString &text);

    QString offText() const;
    void setOffText(const QString &text);

    // Size suggestion
    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    // Internal state
    QColor m_onColor;
    QColor m_offColor;
    QString m_onText;
    QString m_offText;
};

#endif // HKTOGGLEBUTTON_H
