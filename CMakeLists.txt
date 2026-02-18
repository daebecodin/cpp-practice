cmake_minimum_required(VERSION 3.20)
project(cpp_practice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
add_compile_options(-Wall -Wextra -Wpedantic)

add_subdirectory(primer)
add_subdirectory(projects)
