#ifndef tp_qt_maps_OffscreenContext_h
#define tp_qt_maps_OffscreenContext_h

namespace tp_qt_maps
{

//##################################################################################################
class OffscreenContext
{
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
