DEPENDPATH	= .
VPATH	= ../include
AUTHOR	= Rene Kjellerup
TEMPLATE	= app
EMAIL	= rk (dot) katana (dot) steel (at) keenan (dot) dk
QT	= core gui xml
INCLUDEPATH	= . ../include
TARGET	= shuttle_sim
win32:RC_FILE	+= shuttle_sim.rc
LICENSE	= GPL
#RESOURCES	= shuttle_sim.qrc
CONFIG += debug_and_release warn_off
#unix:QMAKE_CXXFLAGS += -fPIC
CONFIG(debug, debug|release) {
    OBJECTS_DIR = ../debug
    DESTDIR = ../
    CONFIG += console
} else {
    OBJECTS_DIR = ../release
    DESTDIR = ../install
}

SOURCES	= main.cc \
	  disp.cc

#FORMS	= disp.ui

HEADERS	= disp.h \
	  system.h \
	  utils.h


