#ifndef CMARK_PICTUREMANAGER_H_
#define CMARK_PICTUREMANAGER_H_


#include <future>

#include <Base/FixMap.hpp>
#include <Base/ImagePack.h>


namespace CM
{
    namespace Tools
    {
        class ResourcesTools;
    }

    class PictureManager
    {
        friend class Tools::ResourcesTools;

    public:
        PictureManager() = default;

        static void insert(const std::pair<size_t, std::shared_ptr<QPixmap>>& d);

        static void insert(size_t key, const std::shared_ptr<QPixmap>& value);

        static std::shared_ptr<QPixmap> getImage(size_t key);

        static void remove(size_t index);

        /**
         * @brief load image from QByteArray
         * @param pack params pack
         * @param synchronization bool 是否同步
         */
        static void loadImage(const ImagePack &pack, bool synchronization = true);

        static FixMap<size_t, std::shared_ptr<QPixmap>> & images(){return m_Maps;}

    private:
        static void destroy();

    private:
        static FixMap<size_t, std::shared_ptr<QPixmap>> m_Maps;
    };
}

#endif