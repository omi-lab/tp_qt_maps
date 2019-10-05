TARGET = tp_qt_maps
TEMPLATE = lib

DEFINES += tp_qt_MAPS_LIBRARY

#SOURCES += src/Globals.cpp
HEADERS += inc/tp_qt_maps/Globals.h

SOURCES += src/ConvertTexture.cpp
HEADERS += inc/tp_qt_maps/ConvertTexture.h

SOURCES += src/textures/QImageTexture.cpp
HEADERS += inc/tp_qt_maps/textures/QImageTexture.h

SOURCES += src/fonts/QFontFont.cpp
HEADERS += inc/tp_qt_maps/fonts/QFontFont.h
