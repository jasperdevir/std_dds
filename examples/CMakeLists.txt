cmake_minimum_required(VERSION 3.10)

project("stddds_examples")

file(GLOB SOURCES "*.c")

include_directories("../")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

foreach(source_file IN LISTS SOURCES)
    get_filename_component(exe_name ${source_file} NAME_WE)

    add_executable(${exe_name} ${source_file})
endforeach()
