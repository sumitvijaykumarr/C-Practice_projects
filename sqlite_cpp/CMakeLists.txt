cmake_minimum_required(VERSION 3.10)
project(SQLiteCppDemo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(SQLite3 REQUIRED)
find_package(SQLiteCpp REQUIRED)

add_executable(demo main.cpp)
target_link_libraries(demo PRIVATE SQLiteCpp SQLite::SQLite3)


