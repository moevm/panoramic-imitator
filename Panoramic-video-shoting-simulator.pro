#-------------------------------------------------
#
# Project created by QtCreator 2016-12-09T08:54:42
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Panoramic-video-shoting-simulator
TEMPLATE = app



LIBS +=-lglut -lGL -lGLU \
     -lprotobuf

RESOURCES += \
resources.qrc

HEADERS += \
    src/protobuf/panoramic-imitator-message.pb.h \
    inc/data_structures.h \
    inc/Image.h \
    inc/ImageLabel.h \
    inc/mainwindow.h \
    inc/PanoramicImage.h \
    inc/pbdata.h \
    inc/stb_image.h

SOURCES += \
    src/protobuf/panoramic-imitator-message.pb.cc \
    src/Image.cpp \
    src/ImageLabel.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/PanoramicImage.cpp \
    src/pbdata.cpp \
    src/stb_image.c

FORMS += \
    src/mainwindow.ui
