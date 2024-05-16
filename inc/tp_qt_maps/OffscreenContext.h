#ifndef tp_qt_maps_OffscreenContext_h
#define tp_qt_maps_OffscreenContext_h

// Don't bring in tp_qt_maps/Globals.h because is causes GLEW warnings.
#include "tp_utils/Globals.h"

namespace tp_qt_maps
{

//##################################################################################################
class OffscreenContext
{
  TP_NONCOPYABLE(OffscreenContext);
  TP_DQ;
public:
  //################################################################################################
  OffscreenContext();

  //################################################################################################
  ~OffscreenContext();
};

}
#endif
