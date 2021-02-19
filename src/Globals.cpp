#include "tp_qt_maps/Globals.h"
#include "tp_qt_maps/ConvertTexture.h"

#include "tp_image_utils/LoadImages.h"

#include "tp_utils/DebugUtils.h"

#include <QOffscreenSurface>
#include <QOpenGLContext>
#include <QGLFunctions>

namespace tp_qt_maps
{

//##################################################################################################
tp_maps::OpenGLProfile getOpenGLProfile()
{
  QOffscreenSurface surf;
  surf.create();

  QOpenGLContext ctx;
  ctx.create();
  ctx.makeCurrent(&surf);

  //3.0 Mesa 19.1.8
  QString version(reinterpret_cast<const char*>(ctx.functions()->glGetString(GL_VERSION)));

  //tpWarning() << "OpenGL Version: " << version.toStdString();

  //3.0
  {
    QStringList parts=version.split(" ", Qt::SkipEmptyParts);
    if(parts.isEmpty())
      return TP_DEFAULT_PROFILE;
    version = parts.first();
  }

  int major=3;
  int minor=0;
  {
    QStringList parts=version.split(".", Qt::SkipEmptyParts);
    if(parts.isEmpty())
      return TP_DEFAULT_PROFILE;

    major = parts.first().toInt();
    if(parts.size()>1)
      minor = parts.at(1).toInt();
  }

  //Implement ES
  //if(major==1 && minor==0) return tp_maps::OpenGLProfile::VERSION_100_ES;
  //if(major==1 && minor==0) return tp_maps::OpenGLProfile::VERSION_300_ES;
  //if(major==1 && minor==0) return tp_maps::OpenGLProfile::VERSION_310_ES;
  //if(major==1 && minor==0) return tp_maps::OpenGLProfile::VERSION_320_ES;

  if(major==2 && minor==0) return tp_maps::OpenGLProfile::VERSION_110; //2.0
  if(major==2 && minor==1) return tp_maps::OpenGLProfile::VERSION_120; //2.1
  if(major==3 && minor==0) return tp_maps::OpenGLProfile::VERSION_130; //3.0
  if(major==3 && minor==1) return tp_maps::OpenGLProfile::VERSION_140; //3.1
  if(major==3 && minor==2) return tp_maps::OpenGLProfile::VERSION_150; //3.2
  if(major==3 && minor==3) return tp_maps::OpenGLProfile::VERSION_330; //3.3
  if(major==4 && minor==0) return tp_maps::OpenGLProfile::VERSION_400; //4.0
  if(major==4 && minor==1) return tp_maps::OpenGLProfile::VERSION_410; //4.1
  if(major==4 && minor==2) return tp_maps::OpenGLProfile::VERSION_420; //4.2
  if(major==4 && minor==3) return tp_maps::OpenGLProfile::VERSION_430; //4.3
  if(major==4 && minor==4) return tp_maps::OpenGLProfile::VERSION_440; //4.4
  if(major==4 && minor==5) return tp_maps::OpenGLProfile::VERSION_450; //4.5
  if(major==4 && minor==6) return tp_maps::OpenGLProfile::VERSION_460; //4.6

  return TP_DEFAULT_PROFILE;
}

//##################################################################################################
QPixmap loadPixmapFromResource(const std::string& path)
{
  return QPixmap::fromImage(convertTexture(tp_image_utils::loadImageFromResource(path)));
}

//##################################################################################################
QIcon loadIconFromResource(const std::string& path)
{
  return loadIconFromResource(path, path);
}

//##################################################################################################
QIcon loadIconFromResource(const std::string& normal, const std::string& down)
{
  QIcon icon(loadPixmapFromResource(normal));  
  icon.addPixmap(loadPixmapFromResource(down), QIcon::Normal, QIcon::On);
  return icon;
}
}
