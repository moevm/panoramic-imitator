#-------------------------------------------------
#
# Project created by QtCreator 2016-12-09T08:54:42
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Panoramic-video-shoting-simulator
TEMPLATE = app


SOURCES += src/main.cpp\
    src/stb_image.c \
    src/Image.cpp \
    src/PanoramicImage.cpp \
    src/protobuf/panoramic-imitator-message.pb.cc \
    src/pbdata.cpp \
    src/image_window.cpp \
    src/panoramic_image_window.cpp \
    src/mainwindow.cpp \
    src/ImageLabel.cpp

HEADERS  += \
    inc/stb_image.h \
    inc/Image.h \
    inc/PanoramicImage.h \
    inc/protobuf/panoramic-imitator-message.pb.h \
    inc/data_structures.h \
    inc/pbdata.h \
    inc/image_window.h \
    inc/panoramic_image_window.h \
    inc/mainwindow.h \
    inc/ImageLabel.h

FORMS    += \
    ui/image_window.ui \
    ui/panoramic_image_window.ui \
    ui/mainwindow.ui

LIBS +=-lglut -lGL -lGLU \
     -lprotobuf

RESOURCES += \
resources.qrc
