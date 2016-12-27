cmake_minimum_required(VERSION 3.0.2)
project(Panoramic-video-shoting-simulator)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC TRUE)
set(CMAKE_AUTOUIC TRUE)

find_package(Qt5Widgets REQUIRED)

find_package(Qt5OpenGL)
find_package(OpenGL REQUIRED)
find_package(Protobuf REQUIRED)
find_package(GLUT REQUIRED)

set(PROTO_SRC ${PROTO_SRC} ${PROJECT_SOURCE_DIR}/src-gen)

set (HEADERS
    inc/stb_image.h 
    inc/Image.h 
    inc/PanoramicImage.h 
    inc/data_structures.h 
    inc/pbdata.h 
    inc/mainwindow.h 
    inc/ImageLabel.h)

set (SRC
    src/stb_image.c 
    src/Image.cpp 
    src/PanoramicImage.cpp 
    src/pbdata.cpp 
    src/mainwindow.cpp 
    src/ImageLabel.cpp
    src/mainwindow.ui
    src/main.cpp)

set(RESOURCES resources.qrc)

qt5_add_resources(UI_RESOURCES resources.qrc)

file(GLOB ProtoFiles "${CMAKE_CURRENT_SOURCE_DIR}/panoramic-imitator-message.proto")
PROTOBUF_GENERATE_CPP(ProtoSources ProtoHeaders ${ProtoFiles})

include_directories(${OPENGL_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} ${SRC} ${HEADERS} ${RESOURCES} ${ProtoSources} ${ProtoHeaders} ${UI_RESOURCES})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::OpenGL ${OPENGL_LIBRARIES} ${PROTOBUF_LIBRARY} ${GLUT_LIBRARIES})
