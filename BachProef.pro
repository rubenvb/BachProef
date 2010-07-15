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
*g++: QMAKE_CXXFLAGS += -Wextra
win32-msvc*:DEFINES += _USE_MATH_DEFINES

#for my pc only
win32:QWT_DIR = M:/Development/x64/Qwt
win32:INCLUDEPATH += $$QWT_DIR/src
win32:DEPENDPATH += $$QWT_DIR/src"
win32:LIBS += -L$$QWT_DIR/lib

#qwt
LIBS += -lqwt5

SOURCES += \
    Main.cpp \
    Cubature/Cubature.c \
    Plot.cpp

HEADERS += \
    Cubature/Cubature.h \
    StructureFunction.h \
    Plot.h

OTHER_FILES += \
    thesis/thesis.tex
