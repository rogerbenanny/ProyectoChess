cmake_minimum_required(VERSION 3.5)

project(ChessTO LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)


file(GLOB files "*.h" "*.cpp")

add_executable(AjedrezTO ${files} main.cpp imagenes.qrc)
target_link_libraries(AjedrezTO PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
