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
    panoramic_image_widget.cpp \
    stb_image.c \
    image.cpp

HEADERS  += mainwindow.h \
    panoramic_image_widget.h \
    stb_image.h \
    image.h

FORMS    += mainwindow.ui

LIBS +=-lglut -lGL -lGLU
