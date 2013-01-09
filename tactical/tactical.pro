DEPENDPATH	= .
VPATH	= ../include ../main
AUTHOR	= Rene Kjellerup
TEMPLATE	= lib
TARGET = tactical
EMAIL	= rk (dot) katana (dot) steel (at) gmail (dot) com
QT	= gui core xml
LANGUAGE	= C++
INCLUDEPATH	= . ../include
CONFIG	+= debug_and_release plugin
LICENSE	= GPL

win32:QMAKE_EXTRA_TARGETS = dll_clean

CONFIG(debug, debug|release) {
    DESTDIR = ../plugins
    OBJECTS_DIR = ../debug
    unix:OBJECTS_DIR = ../plug_debug
    RCC_DIR = debug
    win32:dll_clean.commands = -@echo [File] - Cleaning dll build enviroment && del ..\debug\tab_dll_res.o
} else {
    OBJECTS_DIR = ../release
    unix:OBJECTS_DIR = ../plug_release
    DESTDIR = ../install
    RCC_DIR = release
    win32:dll_clean.commands = -@echo [File] - Cleaning dll build enviroment && del ..\release\tab_dll_res.o
}
win32:PRE_TARGETDEPS = dll_clean

win32:RC_FILE += tab_dll.rc

SOURCES	= tactical.cc 

#FORMS	= tactical.ui

HEADERS	= system.h \
	  tactical.h 

