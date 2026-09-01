cmake_minimum_required(VERSION 3.20)
project(cpp_practice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)
add_compile_options(-Wall -Wextra -Wpedantic)

# Precompiled headers
add_library(pch INTERFACE)
target_precompile_headers(pch INTERFACE include/pch.h)

file(GLOB_RECURSE HEADER_FILES "include/*.h")
add_custom_target(headers SOURCES ${HEADER_FILES})

function(add_child_directories)
    file(GLOB child_cmake_files
        CONFIGURE_DEPENDS
        RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}/*/CMakeLists.txt"
    )

    foreach(child_cmake_file IN LISTS child_cmake_files)
        get_filename_component(child_directory "${child_cmake_file}" DIRECTORY)
        add_subdirectory("${child_directory}")
    endforeach()
endfunction()

add_child_directories()
