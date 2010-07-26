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
LIBS += -lgsl

SOURCES += \
    Main.cpp \
    Cubature/Cubature.c \
    StructureFunction/SFMassless.cpp \
    StructureFunction/SFMassive.cpp \
    StrongCoupling.cpp \
    Plots.cpp \
    UnintegratedGluonDensity/UGDMassless.cpp

HEADERS += \
    Cubature/Cubature.h \
    Plots.h \
    StructureFunction.h \
    StructureFunction/SFMassless.h \
    StructureFunction/SFMassive.h \
    StrongCoupling.h \
    UnintegratedGluonDensity.h \
    Quarks.h \
    UnintegratedGluonDensity/UGDMassless.h

OTHER_FILES += \
    thesis/thesis.tex \
    README.txt \
    StructureFunction.nb \
    Massive.nb \
    thesis/Afbeeldingen/placeholder.eps \
    thesis/Afbeeldingen/UA.eps \
    plotFL.m \
    plotF2.m \
    UnintegratedGluonDensity.nb \
    thesis/Afbeeldingen/QED.eps \
    thesis/Afbeeldingen/NC.eps \
    thesis/Afbeeldingen/GluonLoop.eps \
    thesis/Afbeeldingen/DIS.eps \
    thesis/Afbeeldingen/CC.eps
