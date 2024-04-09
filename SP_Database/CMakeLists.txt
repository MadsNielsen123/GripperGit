cmake_minimum_required(VERSION 3.14)

project(SP_DATABASE LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)
find_package(Qt5Sql REQUIRED)


add_executable(SP_DATABASE
  main.cpp
  db.h
  db.cpp

)
target_link_libraries(SP_DATABASE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(SP_DATABASE  Qt5::Core Qt5::Sql)
