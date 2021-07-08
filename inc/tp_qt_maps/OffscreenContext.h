#ifndef tp_qt_maps_OffscreenContext_h
#define tp_qt_maps_OffscreenContext_h

#include "tp_qt_maps/Globals.h"

namespace tp_qt_maps
{

//##################################################################################################
class OffscreenContext
{
  TP_NONCOPYABLE(OffscreenContext);
public:
  //################################################################################################
  OffscreenContext();

  //################################################################################################
  ~OffscreenContext();

private:
  struct Private;
  Private* d;
};

}
#endif
