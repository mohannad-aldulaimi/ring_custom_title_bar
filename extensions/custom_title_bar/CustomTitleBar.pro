#------------------------------------------------------------
#
# RingQt Project - A project file to support QtCore only
#
#------------------------------------------------------------
QT += core gui widgets

TARGET = CustomTitleBar
TEMPLATE = lib

DEFINES -= UNICODE

SOURCES += main_ring.cpp 
HEADERS += main.hpp 

INCLUDEPATH += ../../language/include

win32 {
	LIBS += ../../lib/ring.lib
}

CONFIG += warn_off
CONFIG += release