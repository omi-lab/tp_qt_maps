#include "tp_qt_maps/Globals.h"
#include "tp_qt_maps/OffscreenContext.h"

#include "tp_maps/subsystems/open_gl/OpenGL.h"

#include <QStringList>

namespace tp_qt_maps
{

//##################################################################################################
tp_maps::ShaderProfile getShaderProfile()
{
  // Kludge to silence some thread sanitizer warnings.
#ifdef TP_SANITIZE_THREAD
  return TP_DEFAULT_PROFILE;
#endif

  OffscreenContext offscreenContext;

  //3.0 Mesa 19.1.8
  //OpenGL ES 3.2 NVIDIA 510.68.02
  QString version(reinterpret_cast<const char*>(glGetString(GL_VERSION)));
  bool es=false;

  //3.0
  {
    QStringList parts=version.split(" ", Qt::SkipEmptyParts);
    if(parts.isEmpty())
      return TP_DEFAULT_PROFILE;

    if(parts.size()>=3 && parts.at(0) == "OpenGL" && parts.at(1) == "ES")
    {
      es = true;
      version = parts.at(2);
    }
    else
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

  if(es)
  {
    if(major==1 && minor==0) return tp_maps::ShaderProfile::GLSL_100_ES;
    if(major==3 && minor==0) return tp_maps::ShaderProfile::GLSL_300_ES;
    if(major==3 && minor==1) return tp_maps::ShaderProfile::GLSL_310_ES;
    if(major==3 && minor==2) return tp_maps::ShaderProfile::GLSL_320_ES;
  }

  if(major==2 && minor==0) return tp_maps::ShaderProfile::GLSL_110; //2.0
  if(major==2 && minor==1) return tp_maps::ShaderProfile::GLSL_120; //2.1
  if(major==3 && minor==0) return tp_maps::ShaderProfile::GLSL_130; //3.0
  if(major==3 && minor==1) return tp_maps::ShaderProfile::GLSL_140; //3.1
  if(major==3 && minor==2) return tp_maps::ShaderProfile::GLSL_150; //3.2
  if(major==3 && minor==3) return tp_maps::ShaderProfile::GLSL_330; //3.3
  if(major==4 && minor==0) return tp_maps::ShaderProfile::GLSL_400; //4.0
  if(major==4 && minor==1) return tp_maps::ShaderProfile::GLSL_410; //4.1
  if(major==4 && minor==2) return tp_maps::ShaderProfile::GLSL_420; //4.2
  if(major==4 && minor==3) return tp_maps::ShaderProfile::GLSL_430; //4.3
  if(major==4 && minor==4) return tp_maps::ShaderProfile::GLSL_440; //4.4
  if(major==4 && minor==5) return tp_maps::ShaderProfile::GLSL_450; //4.5
  if(major==4 && minor==6) return tp_maps::ShaderProfile::GLSL_460; //4.6

  return TP_DEFAULT_PROFILE;
}

}
