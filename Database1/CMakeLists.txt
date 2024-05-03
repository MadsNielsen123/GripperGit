cmake_minimum_required(VERSION 3.5)

project(Database1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt5Sql REQUIRED)

add_executable(Database1 main.cpp Db.h Db.cpp)
target_link_libraries(Database1 Qt5::Core Qt5::Sql)
