#ifndef tp_qt_maps_Globals_h
#define tp_qt_maps_Globals_h

#include "tp_utils/StringID.h"

#include "tp_maps/Globals.h"

#include <QIcon>

#if defined(TP_QT_MAPS_LIBRARY)
#  define TP_QT_MAPS_SHARED_EXPORT TP_EXPORT
#else
#  define TP_QT_MAPS_SHARED_EXPORT TP_IMPORT
#endif

//##################################################################################################
//! Utils for using tp_maps in Qt
/*!
\see tp_qt_maps_widget
\see tp_qt_maps_window
*/
namespace tp_qt_maps
{

//##################################################################################################
tp_maps::OpenGLProfile getOpenGLProfile();

//##################################################################################################
QPixmap loadPixmapFromResource(const std::string& path);

//##################################################################################################
QIcon loadIconFromResource(const std::string& path);

//##################################################################################################
QIcon loadIconFromResource(const std::string& normal, const std::string& down);

}

#endif
