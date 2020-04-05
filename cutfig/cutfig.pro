#-------------------------------------------------
#
# Project created by QtCreator 2020-03-03T00:42:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cutfig
TEMPLATE = app
CXXFLAGS += -std=c++1z -stdlib=libc++
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        cutfig.cpp \
    arrangement.cpp \
    stencil.cpp \
    occupancy.cpp \
    rectangle.cpp

HEADERS += \
        cutfig.h \
    tools.h \
    arrangement.h \
    rectangle.h \
    figure.h \
    point.h \
    istencil.h \
    stencil.h \
    ioccupancy.h \
    occupancy.h

FORMS += \
        cutfig.ui
