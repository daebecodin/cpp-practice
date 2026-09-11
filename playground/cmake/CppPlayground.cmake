include_guard(GLOBAL)

set(
    CPP_PLAYGROUND_CXX_STANDARD
    20
    CACHE STRING
    "C++ language standard used by playground targets"
)

set(CMAKE_CXX_STANDARD "${CPP_PLAYGROUND_CXX_STANDARD}")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

get_filename_component(
    CPP_PLAYGROUND_ROOT
    "${CMAKE_CURRENT_LIST_DIR}/../.."
    ABSOLUTE
)

if(NOT TARGET cpp_playground_pch)
    add_library(cpp_playground_pch INTERFACE)
    target_compile_options(
        cpp_playground_pch
        INTERFACE
            "$<$<COMPILE_LANG_AND_ID:CXX,AppleClang,Clang,GNU>:-Wall;-Wextra;-Wpedantic>"
    )
    target_include_directories(
        cpp_playground_pch
        INTERFACE "${CPP_PLAYGROUND_ROOT}/include"
    )
    target_precompile_headers(
        cpp_playground_pch
        INTERFACE "${CPP_PLAYGROUND_ROOT}/include/pch.h"
    )
endif()

function(cpp_playground_add_executable target_name)
    cmake_parse_arguments(ARG "" "" "SOURCES" ${ARGN})

    if(NOT ARG_SOURCES)
        message(FATAL_ERROR "${target_name} requires at least one source file")
    endif()

    add_executable("${target_name}" ${ARG_SOURCES})
    target_link_libraries("${target_name}" PRIVATE cpp_playground_pch)
endfunction()
function(cpp_playground_add_executables)
    cmake_parse_arguments(ARG "" "" "EXCLUDE" ${ARGN})

    file(GLOB source_files CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

    foreach(source_file IN LISTS source_files)
        get_filename_component(executable_name "${source_file}" NAME_WLE)
        list(FIND ARG_EXCLUDE "${executable_name}" excluded_index)

        if(excluded_index EQUAL -1)
            cpp_playground_add_executable(
                "${executable_name}"
                SOURCES "${source_file}"
            )
        endif()
    endforeach()
endfunction()

function(cpp_playground_add_child_directories)
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
