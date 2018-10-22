#ifndef tdp_maps_ConvertTexture_h
#define tdp_maps_ConvertTexture_h

#include "tdp_maps/Globals.h"

#include "tp_maps/textures/BasicTexture.h"

class QImage;

namespace tdp_maps
{

//##################################################################################################
tp_maps::TextureData TDP_MAPS_SHARED_EXPORT convertTexture(const QImage& image);

}
#endif
