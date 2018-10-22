TARGET = tdp_maps
TEMPLATE = lib

DEFINES += TDP_MAPS_LIBRARY

#SOURCES += src/Globals.cpp
HEADERS += inc/tdp_maps/Globals.h

SOURCES += src/ConvertTexture.cpp
HEADERS += inc/tdp_maps/ConvertTexture.h

SOURCES += src/textures/QImageTexture.cpp
HEADERS += inc/tdp_maps/textures/QImageTexture.h

SOURCES += src/fonts/QFontFont.cpp
HEADERS += inc/tdp_maps/fonts/QFontFont.h
