cmake_minimum_required(VERSION 3.17)
project(DMHelper)

set(CMAKE_CXX_STANDARD 20)

add_definitions(-DGL_SILENCE_DEPRECATION)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "/Users/jaredchester/Qt/6.0.2/clang_64/lib/cmake")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6Quick REQUIRED)
find_package(Qt6OpenGL REQUIRED)
find_package(Qt6OpenGLWidgets REQUIRED)

add_executable(DMHelper main.cpp Source/Application.cpp Source/Application.h Source/MainWindow.cpp Source/MainWindow.h)

include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${QT_QTOPENGL_INCLUDE_DIR})

target_link_libraries(DMHelper Qt6::Core)
target_link_libraries(DMHelper Qt6::Widgets)
target_link_libraries(DMHelper Qt6::Quick)
target_link_libraries(DMHelper Qt6::OpenGL)
target_link_libraries(DMHelper Qt6::OpenGLWidgets)
target_link_libraries(DMHelper ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})