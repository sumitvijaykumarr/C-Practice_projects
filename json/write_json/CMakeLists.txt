cmake_minimum_required(VERSION 3.10)
project(JsonExample CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source file(s)
add_executable(json_app json_creation.cpp)

# Tell CMake where to find RapidJSON headers (if installed system-wide, this works automatically)
find_path(RAPIDJSON_INCLUDE_DIR rapidjson/document.h)

if (RAPIDJSON_INCLUDE_DIR)
    message(STATUS "Found RapidJSON in: ${RAPIDJSON_INCLUDE_DIR}")
    target_include_directories(json_app PRIVATE ${RAPIDJSON_INCLUDE_DIR})
else()
    message(WARNING "RapidJSON not found system-wide. Please install it or set RAPIDJSON_INCLUDE_DIR manually.")
endif()
