#-------------------------------------------------
#
# Project created by QtCreator 2010-07-05T15:17:25
#
#-------------------------------------------------

TARGET = BachProef
TEMPLATE = app
CONFIG   += console warn_on
CONFIG -= qt
DEFINES -= QT_LARGEFILE_SUPPORT UNICODE

# platform specificities
*g++: QMAKE_CXXFLAGS += -Wextra
win32-msvc*:DEFINES += _USE_MATH_DEFINES
win32:INCLUDEPATH += %DEV%/x64/Qwt/src

SOURCES += \
    Main.cpp \
    Cubature/Cubature.c

HEADERS += \
    Cubature/Cubature.h \
    StructureFunction.h

OTHER_FILES += \
    thesis/thesis.tex
