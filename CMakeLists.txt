cmake_minimum_required(VERSION 3.22.1)

project(file_backup)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/main.cpp 
    src/search.cpp)

add_executable(bp ${SOURCES})

target_include_directories(bp PRIVATE include)

set_target_properties(bp PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
