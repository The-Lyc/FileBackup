cmake_minimum_required(VERSION 3.22.1)

project(test)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES 
    ../src/copy.cpp
    copy_test.cpp)

add_executable(cpt ${SOURCES})

target_include_directories(cpt PRIVATE /home/lyc/cpp_ws/file_backup/include)

set_target_properties(cpt PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)