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
    SF/SFMassless.cpp \
    SF/SFMassive.cpp \
    StrongCoupling.cpp \
    Plots.cpp \
    UGD/UGDMassless.cpp \
    ET/ETMassless.cpp \
    ALGLIB/ialglib.cpp \
    ALGLIB/elliptic.cpp \
    ALGLIB/ap.cpp \
    ALGLIB/bessel.cpp

HEADERS += \
    Cubature/Cubature.h \
    Plots.h \
    StructureFunction.h \
    SF/SFMassless.h \
    SF/SFMassive.h \
    StrongCoupling.h \
    UnintegratedGluonDensity.h \
    Quarks.h \
    UGD/UGDMassless.h \
    TransverseEnergyFlow.h \
    ET/ETMassless.h \
    ALGLIB/ialglib.h \
    ALGLIB/elliptic.h \
    ALGLIB/apvt.h \
    ALGLIB/ap.h \
    ALGLIB/bessel.h

OTHER_FILES += \
    thesis/thesis.tex \
    README.txt \
    StructureFunction.nb \
    SFMassive.nb \
    SFMassless.nb \
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
