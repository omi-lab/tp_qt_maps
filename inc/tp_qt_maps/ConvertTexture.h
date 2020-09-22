#ifndef tp_qt_maps_ConvertTexture_h
#define tp_qt_maps_ConvertTexture_h

#include "tp_qt_maps/Globals.h"

#include "tp_image_utils/ColorMap.h"

class QImage;

namespace tp_qt_maps
{

//##################################################################################################
tp_image_utils::ColorMap TP_QT_MAPS_SHARED_EXPORT convertTexture(const QImage& image);

}
#endif
