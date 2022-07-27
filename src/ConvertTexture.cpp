#include "tp_qt_maps/ConvertTexture.h"

#include "tp_image_utils/LoadImages.h"

#include <QImage>
#include <QIcon>

namespace tp_qt_maps
{

//##################################################################################################
tp_image_utils::ColorMap convertTexture(const QImage& image)
{
  QImage img = image.mirrored(false, true);
  img = img.convertToFormat(QImage::Format_ARGB32);

  tp_image_utils::ColorMap textureData(size_t(img.width()), size_t(img.height()));

  auto newData = textureData.data();
  {
    const uchar* p = img.bits();
    const uchar* pMax = p + (img.bytesPerLine() * img.height());
    TPPixel* dst = newData;
    for(; p<pMax; p+=4, dst++)
    {
      dst->r = p[2];
      dst->g = p[1];
      dst->b = p[0];
      dst->a = p[3];
    }
  }

  return textureData;
}

//##################################################################################################
QImage convertTexture(const tp_image_utils::ColorMap& image)
{
  QImage img(int(image.width()), int(image.height()), QImage::Format_ARGB32);

  const TPPixel* src = image.constData();
  const TPPixel* srcMax = src + image.size();
  uchar* dst = img.bits();
  for(; src<srcMax; src++, dst+=4)
  {
    uint32_t rgba =
        (src->a << 24) +
        (src->r << 16) +
        (src->g <<  8) +
        (src->b);

    memcpy(dst, &rgba, 4);
  }

  return img;
}

//##################################################################################################
QPixmap loadPixmapFromResource(const std::string& path)
{
  return QPixmap::fromImage(convertTexture(tp_image_utils::loadImageFromResource(path)));
}

//##################################################################################################
QIcon loadIconFromResource(const std::string& path)
{
  return loadIconFromResource(path, path);
}

//##################################################################################################
QIcon loadIconFromResource(const std::string& normal, const std::string& down)
{
  QIcon icon(loadPixmapFromResource(normal));
  icon.addPixmap(loadPixmapFromResource(down), QIcon::Normal, QIcon::On);
  return icon;
}

}
