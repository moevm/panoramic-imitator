#-------------------------------------------------
#
# Project created by QtCreator 2016-12-09T08:54:42
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Panoramic-video-shoting-simulator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    stb_image.c \
    Image.cpp \
    PanoramicImageWidget.cpp \
    protobuf/panoramic-imitator-message.pb.cc \
    getpbdata.cpp

HEADERS  += mainwindow.h \
    stb_image.h \
    Image.h \
    PanoramicImageWidget.h \
    protobuf/panoramic-imitator-message.pb.h \
    getpbdata.h \
    data_structures.h

FORMS    += mainwindow.ui

LIBS +=-lglut -lGL -lGLU \
     -lprotobuf
