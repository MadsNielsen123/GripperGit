cmake_minimum_required(VERSION 3.14)

project(InterruptTest LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_library(PIGPIO_LIBRARY NAMES pigpio)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(InterruptTest
  main.cpp
)
target_link_libraries(InterruptTest Qt${QT_VERSION_MAJOR}::Core)

# Link pigpio library
target_link_libraries(InterruptTest
    Qt${QT_VERSION_MAJOR}::Core
    ${PIGPIO_LIBRARY}
)



install(TARGETS InterruptTest
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

target_include_directories(InterruptTest PRIVATE ${PIGPIO_INCLUDE_DIRS})
