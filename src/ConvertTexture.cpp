#include "tdp_maps/ConvertTexture.h"

#include <QImage>

namespace tdp_maps
{

//##################################################################################################
tp_maps::TextureData convertTexture(const QImage& image)
{
  tp_maps::TextureData textureData;

  QImage img = image.mirrored(false, true);
  img = img.convertToFormat(QImage::Format_ARGB32);

  textureData.w = size_t(img.width());
  textureData.h = size_t(img.height());

  auto newData = new TPPixel[size_t(textureData.w * textureData.h)];
  textureData.data = newData;
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

}
