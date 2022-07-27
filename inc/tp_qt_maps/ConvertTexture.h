#ifndef tp_qt_maps_ConvertTexture_h
#define tp_qt_maps_ConvertTexture_h

#include "tp_qt_maps/Globals.h"

#include "tp_image_utils/ColorMap.h"

class QImage;
class QIcon;
class QPixmap;

namespace tp_qt_maps
{

//##################################################################################################
tp_image_utils::ColorMap TP_QT_MAPS_SHARED_EXPORT convertTexture(const QImage& image);

//##################################################################################################
QImage TP_QT_MAPS_SHARED_EXPORT convertTexture(const tp_image_utils::ColorMap& image);

//##################################################################################################
QPixmap TP_QT_MAPS_SHARED_EXPORT loadPixmapFromResource(const std::string& path);

//##################################################################################################
QIcon TP_QT_MAPS_SHARED_EXPORT loadIconFromResource(const std::string& path);

//##################################################################################################
QIcon TP_QT_MAPS_SHARED_EXPORT loadIconFromResource(const std::string& normal, const std::string& down);

}
#endif
