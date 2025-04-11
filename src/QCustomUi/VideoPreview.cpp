#include "VideoPreview.h"

#include <QMouseEvent>
#include <QtOpenGLWidgets/QOpenGLWidget>

struct VideoPreview::Impl
{
    QGraphicsScene* scene { nullptr };
    QGraphicsPixmapItem* pixmapItem { nullptr };
    CrossHairItem* crossHairItem { nullptr };
    bool showCrosshair{false};
};


VideoPreview::VideoPreview(QWidget* parent /*= nullptr*/) : QGraphicsView(parent), m_impl(std::make_unique<Impl>()) {
    setMouseTracking(true);
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    m_impl->scene = new QGraphicsScene(this);
    m_impl->scene->setBackgroundBrush(Qt::black);
    this->setScene(m_impl->scene);

    // 图片
    m_impl->pixmapItem = new QGraphicsPixmapItem();
    m_impl->pixmapItem->setPos(0, 0);
    m_impl->pixmapItem->setZValue(-1000);
    m_impl->pixmapItem->setFlag(QGraphicsItem::ItemIsSelectable, false);
    m_impl->pixmapItem->setFlag(QGraphicsItem::ItemIsMovable, false);
    m_impl->pixmapItem->setFlag(QGraphicsItem::ItemIsFocusable, false);
    m_impl->scene->addItem(m_impl->pixmapItem);

    //十字线
    m_impl->crossHairItem = new CrossHairItem();
    m_impl->scene->addItem(m_impl->crossHairItem);
    m_impl->crossHairItem->setPos(m_impl->scene->sceneRect().center());
    if (m_impl->showCrosshair)
    {
        m_impl->crossHairItem->setVisible(true);
    }
    else
    {
        m_impl->crossHairItem->setVisible(false);
    }
}

VideoPreview::~VideoPreview() {}

void VideoPreview::resizeEvent(QResizeEvent* event)
{
    if (m_impl->scene)
    {
        m_impl->scene->setSceneRect(QRect(QPoint(0, 0), event->size()));
        m_impl->crossHairItem->setPos(m_impl->scene->sceneRect().center());
    }
    QGraphicsView::resizeEvent(event);
}

void VideoPreview::updatePixmap(const QPixmap& pixmap) {
    qreal scaleX = static_cast<qreal>(this->size().width()) / pixmap.width();
    qreal scaleY = static_cast<qreal>(this->size().height()) / pixmap.height();

    // 计算缩放后的图像大小
    QSize scaledSize(pixmap.width() * scaleX, pixmap.height() * scaleY);
    QPixmap scaledPixmap = pixmap.scaled(scaledSize, Qt::KeepAspectRatio, Qt::FastTransformation);

   m_impl->pixmapItem->setPixmap(scaledPixmap);
   m_impl->pixmapItem->setPos(sceneRect().width() / 2 - scaledPixmap.width() / 2, 0);
}

bool VideoPreview::isShowCrosshair() const { return m_impl->showCrosshair; }

void VideoPreview::setShowCrosshair(bool show) {
    m_impl->showCrosshair = show;

    if (m_impl->showCrosshair)
    {
        m_impl->crossHairItem->setVisible(true);
    }
    else
    {
        m_impl->crossHairItem->setVisible(false);
    }
}
