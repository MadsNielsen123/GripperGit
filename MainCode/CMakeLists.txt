cmake_minimum_required(VERSION 3.14)

project(MainCode LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find pigpio library
find_library(PIGPIO_LIBRARY NAMES pigpio)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

add_executable(MainCode
  main.cpp
  DCMotor.h DCMotor.cpp
  URTCP.cpp URTCP.h
)
target_link_libraries(MainCode Qt${QT_VERSION_MAJOR}::Core)
# Link pigpio library
target_link_libraries(MainCode
    Qt${QT_VERSION_MAJOR}::Core
    ${PIGPIO_LIBRARY}
)

target_include_directories(MainCode PRIVATE ${PIGPIO_INCLUDE_DIRS})
