cmake_minimum_required(VERSION 3.17)
project(DMHelper)

set(CMAKE_CXX_STANDARD 20)

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

add_executable(DMHelper Source/Entry.cpp Source/Core/Application.cpp Source/Core/Application.h Source/GUI/MainWindow.cpp Source/GUI/MainWindow.h Source/GUI/Widgets/GLWidget.cpp Source/GUI/Widgets/GLWidget.h)

include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${QT_QTOPENGL_INCLUDE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/Vendor/json/include)

message(STATUS "Adding sqlite3 include directories.")
include_directories(${PROJECT_SOURCE_DIR}/Vendor/sqlite3/include)
include_directories(${PROJECT_SOURCE_DIR}/Vendor/spdlog/include)

target_link_libraries(DMHelper Qt6::Core)
target_link_libraries(DMHelper Qt6::Widgets)
target_link_libraries(DMHelper Qt6::Quick)
target_link_libraries(DMHelper Qt6::OpenGL)
target_link_libraries(DMHelper Qt6::OpenGLWidgets)
target_link_libraries(DMHelper ${OPENGL_LIBRARIES})

IF (APPLE)
    message(STATUS "Apple Detected: Linking with GLUT")
    target_link_libraries(DMHelper ${GLUT_LIBRARY})
    message(STATUS "Apple Detected: Linking with sqlite3")

    IF (NOT EXISTS "${PROJECT_SOURCE_DIR}/Vendor/sqlite3/lib/macOS/libsqlite3.a")
        message(SEND_ERROR "libsqlite3.a does not exist, please generate it and then reload.")
    ENDIF()

    IF (NOT EXISTS "${PROJECT_SOURCE_DIR}/Vendor/spdlog/lib/macOS/libspdlog.a")
        message(SEND_ERROR "libspdlog.a does not exist, please generate it and then reload.")
    ENDIF()

    target_link_libraries(DMHelper ${PROJECT_SOURCE_DIR}/Vendor/sqlite3/lib/macOS/libsqlite3.a)
    target_link_libraries(DMHelper ${PROJECT_SOURCE_DIR}/Vendor/spdlog/lib/macOS/libspdlog.a)
ELSEIF(WIN32)
    message("Windows Detected: Linking with sqlite3")

    IF (NOT EXISTS "${PROJECT_SOURCE_DIR}/Vendor/sqlite3/lib/win_x64/sqlite3.lib")
        message(SEND_ERROR "sqlite3 library does not exist, please run the build script for it located in ${PROJECT_SOURCE_DIR}/Vendor/sqlite3.")
    ENDIF()

    IF (NOT EXISTS "${PROJECT_SOURCE_DIR}/Vendor/spdlog/lib/win_x64/spdlogd.lib")
        message(SEND_ERROR "spdlogd library does not exist.")
    ENDIF()

    target_link_libraries(DMHelper ${PROJECT_SOURCE_DIR}/Vendor/sqlite3/lib/win_x64/sqlite3.lib)
    target_link_libraries(DMHelper ${PROJECT_SOURCE_DIR}/Vendor/spdlog/lib/win_x64/spdlogd.lib)
ENDIF()