#include "tp_qt_maps/OffscreenContext.h"

#include <QOffscreenSurface>
#include <QOpenGLContext>

namespace tp_qt_maps
{

//##################################################################################################
struct OffscreenContext::Private
{
  QOffscreenSurface surf;
  QOpenGLContext ctx;
};
//##################################################################################################
OffscreenContext::OffscreenContext():
  d(new Private)
{
  d->surf.create();
  d->ctx.create();
  d->ctx.makeCurrent(&d->surf);
}

//##################################################################################################
OffscreenContext::~OffscreenContext()
{
  delete d;
}

}
