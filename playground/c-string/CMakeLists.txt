cmake_minimum_required(VERSION 3.20)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    project(cpp_playground_c_string LANGUAGES CXX)
endif()

include("${CMAKE_CURRENT_LIST_DIR}/../cmake/CppPlayground.cmake")

cpp_playground_add_executables()
cpp_playground_add_child_directories()
