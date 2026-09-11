cmake_minimum_required(VERSION 3.20)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    project(cpp_playground_variables LANGUAGES CXX)
endif()

include("${CMAKE_CURRENT_LIST_DIR}/../cmake/CppPlayground.cmake")

cpp_playground_add_executable(
    var_declaration_vs_definition
    SOURCES
        var_declaration_vs_definition.cpp
        external_definition.cpp
)

cpp_playground_add_executables(
    EXCLUDE
        external_definition
        var_declaration_vs_definition
        var_define_near_use
        var_init_vs_assign
)

cpp_playground_add_child_directories()
