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
    stb_image.c \
    Image.cpp \
    PanoramicImage.cpp \
    protobuf/panoramic-imitator-message.pb.cc \
    pbdata.cpp \
    image_window.cpp \
    panoramic_image_window.cpp

HEADERS  += \
    stb_image.h \
    Image.h \
    PanoramicImage.h \
    protobuf/panoramic-imitator-message.pb.h \
    data_structures.h \
    pbdata.h \
    image_window.h \
    panoramic_image_window.h

FORMS    += \
    image_window.ui \
    panoramic_image_window.ui

LIBS +=-lglut -lGL -lGLU \
     -lprotobuf
