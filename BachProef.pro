#-------------------------------------------------
#
# Project created by QtCreator 2010-07-05T15:17:25
#
#-------------------------------------------------

TARGET = BachProef
TEMPLATE = app
CONFIG += console warn_on sse sse2 mmx
CONFIG -= qt
DEFINES -= QT_LARGEFILE_SUPPORT UNICODE

# platform specificities
*g++: QMAKE_CXXFLAGS += -Wextra -std=gnu++0x
win32-msvc*:DEFINES += _USE_MATH_DEFINES

DEPENDPATH += .
INCLUDEPATH += .

SOURCES += \
    Main.cpp \
    Cubature/Cubature.c \
    StructureFunction/Massless.cpp \
    StructureFunction/Massive.cpp \
    StructureFunction/CouplingConstant.cpp \
    Plots.cpp

HEADERS += \
    Cubature/Cubature.h \
    Plots.h \
    StructureFunction.h \
    StructureFunction/Massless.h \
    StructureFunction/Massive.h \
    StructureFunction/CouplingConstant.h

OTHER_FILES += \
    thesis/thesis.tex \
    README.txt \
    StructureFunction.nb \
    Massive.nb \
    thesis/Afbeeldingen/placeholder.eps \
    thesis/Afbeeldingen/UA.eps \
    plotFL.m \
    plotF2.m
