cmake_minimum_required(VERSION 3.20)
project(restaurant)

file (GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

set (CPP_FILES "")
foreach (_file ${SOURCES})
    get_filename_component(_dir ${_file} PATH)
    list (APPEND CPP_FILES ${_dir})
endforeach()

list (REMOVE_DUPLICATES CPP_FILES)
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})