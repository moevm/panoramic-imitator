#-------------------------------------------------
#
# Project created by QtCreator 2016-11-27T06:10:13
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Panoramic-video-shoting-simulator
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc

SOURCES += main.cpp \
    image.cpp \
    panoramic_image.cpp

HEADERS += \
    image.h \
    panoramic_image.h
