cmake_minimum_required(VERSION 3.5)

project(Database LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt5Sql REQUIRED)

add_executable(Database main.cpp db.h db.cpp)
target_link_libraries(Database Qt5::Core Qt5::Sql)
