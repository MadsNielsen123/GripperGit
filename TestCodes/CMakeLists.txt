cmake_minimum_required(VERSION 3.14)

project(Testcode LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find pigpio library
find_library(PIGPIO_LIBRARY NAMES pigpio)
find_package(Qt5Sql REQUIRED)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

add_executable(Testcode
  main.cpp
  DCMotor.h DCMotor.cpp
  GripperController.h GripperController.cpp
  server.h server.cpp
  Db.h Db.cpp
)
target_link_libraries(Testcode Qt${QT_VERSION_MAJOR}::Core)
# Link pigpio library
target_link_libraries(Testcode
    Qt${QT_VERSION_MAJOR}::Core
    ${PIGPIO_LIBRARY}
)

target_include_directories(Testcode PRIVATE ${PIGPIO_INCLUDE_DIRS})
target_link_libraries(Testcode Qt5::Core Qt5::Sql)
