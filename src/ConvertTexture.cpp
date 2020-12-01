#include "tp_qt_maps/ConvertTexture.h"

#include <QImage>

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
  for(size_t y=0; y<image.height(); y++)
  {
    for(size_t x=0; x<image.width(); x++)
    {
      auto c = image.pixel(x, y);
      img.setPixel(int(x), int(y), QColor(c.r, c.g, c.b, c.a).rgba());
    }
  }

  return img;
}

}
