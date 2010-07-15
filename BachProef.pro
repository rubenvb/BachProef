#-------------------------------------------------
#
# Project created by QtCreator 2010-07-05T15:17:25
#
#-------------------------------------------------

TARGET = BachProef
TEMPLATE = app
CONFIG   += console warn_on
#CONFIG -= qt
#DEFINES -= QT_LARGEFILE_SUPPORT UNICODE

# platform specificities
*g++: QMAKE_CXXFLAGS += -Wextra -std=gnu++0x -ftree-vectorize
win32-msvc*:DEFINES += _USE_MATH_DEFINES

SOURCES += \
    Main.cpp \
    Cubature/Cubature.c

HEADERS += \
    Cubature/Cubature.h \
    StructureFunction.h \
    StructureFunctionPlots.h

OTHER_FILES += \
    thesis/thesis.tex
