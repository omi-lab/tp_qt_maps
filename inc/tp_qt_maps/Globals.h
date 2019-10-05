#ifndef tp_qt_maps_Globals_h
#define tp_qt_maps_Globals_h

#include "tp_utils/StringID.h"

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

}

#endif
