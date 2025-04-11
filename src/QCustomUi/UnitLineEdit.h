#pragma once

#include "qcustomui_global.h"

#include <QLineEdit>
#include <QPainter>
#include <QDoubleValidator>

class QCUSTOMUI_EXPORT UnitLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit UnitLineEdit(QWidget* parent = nullptr,const QString& unit = "") : QLineEdit(parent), unitText(unit)
    {
        // 设置验证器限制输入为双精度数
        setValidator(new QDoubleValidator(this)); 
    }

protected:
    void paintEvent(QPaintEvent* event) override
    {
        QLineEdit::paintEvent(event);

        QPainter painter(this);
        QFontMetrics fm(font());
        int textWidth = fm.horizontalAdvance(text());

        int unitX = width() - fm.horizontalAdvance(unitText) - 6; // Padding from right
        int y     = (height() + fm.ascent() - fm.descent()) / 2;

        painter.setPen(QColor(150, 150, 150)); // Gray color
        painter.drawText(unitX, y, unitText);
    }

private:
    QString unitText;
};
