#ifndef tdp_maps_QImageTexture_h
#define tdp_maps_QImageTexture_h

#include "tdp_maps/Globals.h"

#include "tp_maps/Font.h"

class QFont;

namespace tdp_maps
{

//##################################################################################################
class TDP_MAPS_SHARED_EXPORT QFontFont : public tp_maps::Font
{
public:
  //################################################################################################
  QFontFont(const QFont& font);

  //################################################################################################
  ~QFontFont() override;

  //################################################################################################
  void prepareGlyph(char16_t character, const std::function<void(const tp_maps::Glyph&)>& addGlyph) const override;

private:
  struct Private;
  Private* d;
  friend struct Private;
};

}

#endif
