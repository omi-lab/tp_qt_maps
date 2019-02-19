#ifndef tdp_maps_Globals_h
#define tdp_maps_Globals_h

#include "tp_utils/StringID.h"

#if defined(TDP_MAPS_LIBRARY)
#  define TDP_MAPS_SHARED_EXPORT TP_EXPORT
#else
#  define TDP_MAPS_SHARED_EXPORT TP_IMPORT
#endif

//##################################################################################################
//! Utils for using tp_maps in Qt
/*!
\see tdp_maps_widget
\see tdp_maps_window
*/
namespace tdp_maps
{

}

#endif
