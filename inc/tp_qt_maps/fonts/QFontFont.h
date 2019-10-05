#ifndef tp_qt_maps_QImageTexture_h
#define tp_qt_maps_QImageTexture_h

#include "tp_qt_maps/Globals.h"

#include "tp_maps/Font.h"

class QFont;

namespace tp_qt_maps
{

//##################################################################################################
class TP_QT_MAPS_SHARED_EXPORT QFontFont : public tp_maps::Font
{
public:
  //################################################################################################
  QFontFont(const QFont& font);

  //################################################################################################
  ~QFontFont() override;

  //################################################################################################
  void prepareGlyph(char16_t character, const std::function<void(const tp_maps::Glyph&)>& addGlyph) const override;

  //################################################################################################
  float lineHeight() const override;

private:
  struct Private;
  Private* d;
  friend struct Private;
};

}

#endif
