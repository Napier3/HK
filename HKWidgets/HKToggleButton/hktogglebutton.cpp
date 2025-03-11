#include "hktogglebutton.h"
#include <QPainter>
#include <QMouseEvent>

HKToggleButton::HKToggleButton(QWidget *parent)
    : QAbstractButton(parent)
    , m_onColor(Qt::green)
    , m_offColor(Qt::red)
    , m_onText(QStringLiteral("ON"))
    , m_offText(QStringLiteral("OFF"))
{
    // Allow toggling (checked <-> unchecked)
    setCheckable(true);

    // Initial state
    setChecked(true);

    // Optional: change cursor to indicate interactivity
    setCursor(Qt::PointingHandCursor);
}

// --- Color Getters/Setters ---
QColor HKToggleButton::onColor() const
{
    return m_onColor;
}

void HKToggleButton::setOnColor(const QColor &color)
{
    m_onColor = color;
    update();  // trigger repaint
}

QColor HKToggleButton::offColor() const
{
    return m_offColor;
}

void HKToggleButton::setOffColor(const QColor &color)
{
    m_offColor = color;
    update();
}

// --- Text Getters/Setters ---
QString HKToggleButton::onText() const
{
    return m_onText;
}

void HKToggleButton::setOnText(const QString &text)
{
    m_onText = text;
    update();
}

QString HKToggleButton::offText() const
{
    return m_offText;
}

void HKToggleButton::setOffText(const QString &text)
{
    m_offText = text;
    update();
}

// --- Size Hint ---
QSize HKToggleButton::sizeHint() const
{
    // Adjust these to suit the look you want
    return QSize(80, 36);
}

// --- Paint Event ---
void HKToggleButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Background rectangle
    QRectF rect(0, 0, width(), height());
    qreal radius = rect.height() / 2.0;

    // Draw background
    painter.setPen(Qt::NoPen);
    painter.setBrush(isChecked() ? m_onColor : m_offColor);
    painter.drawRoundedRect(rect, radius, radius);

    // Draw the toggle circle
    qreal circleDiameter = height() - 4;  // 2 px margin top/bottom
    qreal circleRadius   = circleDiameter / 2.0;
    qreal circleX        = isChecked()
                           ? width() - circleDiameter - 2
                           : 2;
    qreal circleY = 2;

    painter.setBrush(Qt::white);
    painter.drawEllipse(QPointF(circleX + circleRadius, circleY + circleRadius),
                        circleRadius, circleRadius);

    // Draw the text
    painter.setPen(Qt::white);
    QString textToDraw = isChecked() ? m_onText : m_offText;
    QFontMetrics fm(painter.font());
    int textWidth  = fm.horizontalAdvance(textToDraw);
    int textHeight = fm.height();

    // Position text to avoid overlapping the circle
    // Feel free to adjust these positions as desired
    int textX = isChecked() ? 8 : (width() - textWidth - 8);
    int textY = (height() + textHeight) / 2 - fm.descent();
    painter.drawText(textX, textY, textToDraw);
}

// --- Mouse Release Event ---
void HKToggleButton::mouseReleaseEvent(QMouseEvent *event)
{
    // If the click/tap is within our rectangle, toggle the state
    if (rect().contains(event->pos())) {
        // Manually toggle (since we are not calling the base implementation)
        setChecked(!isChecked());

        // Emit signals
        emit clicked(isChecked());
        emit toggled(isChecked());
    }

    // We do NOT call QAbstractButton::mouseReleaseEvent(event) here
    // because that might toggle again (leading to double toggles).
    // If you'd rather let QAbstractButton handle toggling automatically,
    // remove this override entirely.
}
