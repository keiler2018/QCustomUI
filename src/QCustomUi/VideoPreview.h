#pragma once

#include "qcustomui_global.h"

#include <QGraphicsView>
#include <QGraphicsPixmapItem>

class CrossHairItem : public QGraphicsItem
{
public:
    CrossHairItem(qreal size = 20, qreal circleRadius = 4) : m_size(size), m_circleRadius(circleRadius) {}

    QRectF boundingRect() const override
    {
        // 确保十字线和圆圈都在此范围内
        qreal half = m_size / 2;
        return QRectF(-half - m_circleRadius, -half - m_circleRadius, m_size + m_circleRadius * 2, m_size + m_circleRadius * 2);
    }

    void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override
    {
        painter->setRenderHint(QPainter::Antialiasing, true);
        QPen pen(Qt::red, 1); // 可自定义颜色和粗细
        painter->setPen(pen);

        // 画十字线
        painter->drawLine(QPointF(-m_size / 2, 0), QPointF(m_size / 2, 0)); // 横
        painter->drawLine(QPointF(0, -m_size / 2), QPointF(0, m_size / 2)); // 竖

        // 画中心小圆圈
        painter->setBrush(Qt::NoBrush);
        painter->drawEllipse(QPointF(0, 0), m_circleRadius, m_circleRadius);
    }

private:
    qreal m_size;
    qreal m_circleRadius;
};

class QCUSTOMUI_EXPORT VideoPreview :  public QGraphicsView
{
    Q_OBJECT
    Q_PROPERTY(bool showCrosshair READ isShowCrosshair WRITE setShowCrosshair)
public:
    explicit VideoPreview(QWidget* parent = nullptr);
    ~VideoPreview();

    void updatePixmap(const QPixmap& pixmap);
    
    /*!
     \brief      是否显示十字线
    */
    bool isShowCrosshair() const;
    void setShowCrosshair(bool show);

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    struct Impl;
    std::unique_ptr<Impl> m_impl;
};
