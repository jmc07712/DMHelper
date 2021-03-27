cmake_minimum_required(VERSION 3.17)
project(DMHelper)

set(CMAKE_CXX_STANDARD 14)

add_definitions(-DGL_SILENCE_DEPRECATION)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

IF (WIN32)
    message("Windows Detected: Setting PREFIX_PATH accordingly")
    set(CMAKE_PREFIX_PATH "C:\\Qt\\6.0.2\\msvc2019_64\\lib\\cmake")
ELSEIF(APPLE)
    message("Apple Detected: Setting PREFIX_PATH accordingly")
    set(CMAKE_PREFIX_PATH "/Users/jaredchester/Qt/6.0.2/clang_64/lib/cmake")
ENDIF()

IF(APPLE)
    message("Apple Detected: Adding GLUT package")
    find_package(GLUT REQUIRED)
ENDIF()

find_package(OpenGL REQUIRED)
find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6Quick REQUIRED)
find_package(Qt6OpenGL REQUIRED)
find_package(Qt6OpenGLWidgets REQUIRED)

add_executable(DMHelper Source/main.cpp Source/Application.cpp Source/Application.h Source/MainWindow.cpp Source/MainWindow.h)

include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${QT_QTOPENGL_INCLUDE_DIR})

target_link_libraries(DMHelper Qt6::Core)
target_link_libraries(DMHelper Qt6::Widgets)
target_link_libraries(DMHelper Qt6::Quick)
target_link_libraries(DMHelper Qt6::OpenGL)
target_link_libraries(DMHelper Qt6::OpenGLWidgets)
target_link_libraries(DMHelper ${OPENGL_LIBRARIES})

if (APPLE)
    message("Apple Detected: Linking with GLUT")
    target_link_libraries(DMHelper ${GLUT_LIBRARY})
ENDIF()