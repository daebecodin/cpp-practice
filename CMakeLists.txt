cmake_minimum_required(VERSION 3.20)
project(cpp_practice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
add_compile_options(-Wall -Wextra -Wpedantic)

# Precompiled headers
add_library(pch INTERFACE)
target_precompile_headers(pch INTERFACE include/pch.h)

file(GLOB_RECURSE HEADER_FILES "include/*.h")
add_custom_target(headers SOURCES ${HEADER_FILES})

add_subdirectory(primer)
add_subdirectory(projects)
add_subdirectory(playground)
