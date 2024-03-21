cmake_minimum_required(VERSION 3.14)

project(GPIOTest1 LANGUAGES CXX)

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

add_executable(GPIOTest1
  main.cpp
  DCMotor.h
  DCMotor.cpp
)
target_link_libraries(GPIOTest1 Qt${QT_VERSION_MAJOR}::Core)

# Link pigpio library
target_link_libraries(GPIOTest1 
    Qt${QT_VERSION_MAJOR}::Core
    ${PIGPIO_LIBRARY}
)
