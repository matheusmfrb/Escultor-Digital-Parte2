TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Sculptor.cpp \
        cutbox.cpp \
        cutellipsoid.cpp \
        cutsphere.cpp \
        cutvoxel.cpp \
        figurageometrica.cpp \
        main.cpp \
        putbox.cpp \
        putellipsoid.cpp \
        putsphere.cpp \
        putvoxel.cpp

HEADERS += \
    Sculptor.h \
    Voxel.h \
    cutbox.h \
    cutellipsoid.h \
    cutsphere.h \
    cutvoxel.h \
    figurageometrica.h \
    putbox.h \
    putellipsoid.h \
    putsphere.h \
    putvoxel.h
