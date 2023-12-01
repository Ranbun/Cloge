#include "PreViewImageItem.h"

namespace CM
{
    PreViewImageItem::PreViewImageItem(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
    {
        m_margin = {30,30,213,30};
    }

    void PreViewImageItem::updatePixmapSize()
    {
#if _DEBUG
        auto ph = m_pixmap.height();
        auto pw = m_pixmap.width();
#endif

        const auto currentScene = scene();
        if(!currentScene) return;
        const auto &  sceneRect = currentScene->sceneRect();

        CM::Size sceneRectSize{(int)sceneRect.width(),(int)sceneRect.height(),0};

#if  0
        auto w = (int)(sceneRectSize.x * 0.6);
        if(w < sceneRect.width() - 200)
        {
            w = sceneRect.width() - 200;
        }
        auto h = static_cast<int>(static_cast<float>(m_pixmap.height()) / static_cast<float>(m_pixmap.width()) * w);

        if(m_pixmap.isNull()) return ;

        setPixmap(m_pixmap.scaled(w,h,Qt::KeepAspectRatio, Qt::SmoothTransformation));
#endif

        auto newWidth = sceneRectSize.x - m_margin.leftMargin - m_margin.rightMargin;
        auto newHeight = static_cast<int>(static_cast<float>(m_pixmap.height()) / static_cast<float>(m_pixmap.width()) * static_cast<float>(newWidth));

        if(m_pixmap.isNull()) return ;

        setPixmap(m_pixmap.scaled(newWidth,newHeight,Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    void PreViewImageItem::resetPixmap(const QPixmap &previewPixmap)
    {
        m_pixmap = previewPixmap;
        if(m_pixmap.isNull())
        {
            throw std::runtime_error("Pixmap is Null!");
        }

        update();
    }

    void PreViewImageItem::update()
    {
        updatePixmapSize();
        updatePos();
    }

    void PreViewImageItem::updatePos()
    {
        const auto currentScene = scene();
        if(!currentScene) return;
        const auto &  sceneRect = currentScene->sceneRect();

#if  0
        const auto & rect = boundingRect();
        const auto imageY = sceneRect.height() / 2 - rect.height() / 2;
        constexpr auto imageX = 0;
        setPos(imageX, imageY);
#endif
        auto posX = m_margin.leftMargin;
        auto posY = m_margin.topMargin;
        setPos(posX, posY);
    }
} // CM
