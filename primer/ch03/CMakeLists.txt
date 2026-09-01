file(GLOB experiment_sources "*.cpp")

foreach(source_file ${experiment_sources})
    get_filename_component(executable_name ${source_file} NAME_WE)
    add_executable(${executable_name} ${source_file})
    target_link_libraries(${executable_name} PRIVATE pch)
endforeach()

add_child_directories()
