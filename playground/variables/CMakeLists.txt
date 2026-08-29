file(GLOB experiment_sources "*.cpp")

add_executable(var_declaration_vs_definition var_declaration_vs_definition.cpp external_definition.cpp)
target_include_directories(var_declaration_vs_definition PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(var_declaration_vs_definition PRIVATE pch)

foreach(source_file ${experiment_sources})
    get_filename_component(executable_name ${source_file} NAME_WE)
    if(NOT executable_name STREQUAL "var_declaration_vs_definition" AND 
       NOT executable_name STREQUAL "external_definition" AND
       NOT executable_name STREQUAL "var_define_near_use" AND
       NOT executable_name STREQUAL "var_init_vs_assign")
        add_executable(${executable_name} ${source_file})
        target_include_directories(${executable_name} PRIVATE ${CMAKE_SOURCE_DIR}/include)
        target_link_libraries(${executable_name} PRIVATE pch)
    endif()
endforeach()
