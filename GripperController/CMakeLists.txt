cmake_minimum_required(VERSION 3.14)

project(GripperController LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find pigpio library
find_library(PIGPIO_LIBRARY NAMES pigpio)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(GripperController
  main.cpp
  DCMotor.h DCMotor.cpp
  GripperController.h GripperController.cpp
)
target_link_libraries(GripperController Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS GripperController
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

# Link pigpio library
target_link_libraries(GripperController
    Qt${QT_VERSION_MAJOR}::Core
    ${PIGPIO_LIBRARY}
)

target_include_directories(GripperController PRIVATE ${PIGPIO_INCLUDE_DIRS})
