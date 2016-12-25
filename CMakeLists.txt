cmake_minimum_required(VERSION 3.7.1)
project (Panoramic-video-shoting-simulator)

set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_AUTOMOC ON)

find_package (Qt5Widgets)

set (HEADERS stb_image.h Image.h PanoramicImage.h protobuf/panoramic-imitator-message.pb.h data_structures.h pbdata.h image_window.h panoramic_image_window.h mainwindow.h ImageLabel.h)

set (SRC_LIST stb_image.c Image.cpp PanoramicImage.cpp protobuf/panoramic-imitator-message.pb.cc pbdata.cpp image_window.cpp panoramic_image_window.cpp mainwindow.cpp ImageLabel.cpp)

set (UI image_window.ui panoramic_image_window.ui mainwindow.ui)

set (RESOURCES resources.qrc)

add_executable (${Panoramic-video-shoting-simulator} ${SRC_LIST} ${HEADERS} ${UI} ${RESOURCES})

target_link_libraries (Panoramic-video-shoting-simulator Qt5::Widgets)