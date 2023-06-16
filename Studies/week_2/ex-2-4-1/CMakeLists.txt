include(CMakePrintHelpers)

cmake_minimum_required(VERSION 3.20)
project(lorem)


# ignore directory list
set(IGNORE_DIRECTORY "TEST" ; "")


# finds libraries automatically
file (GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "source/*.cpp")
set (CPP_FOLDERS "")

foreach (_file ${SOURCES})
    get_filename_component(_dir ${_file} PATH)

    # no need to add full paths to ignore list
    cmake_path(GET _file PARENT_PATH PARENT_F)
    cmake_path(GET PARENT_F FILENAME PARENT_F)
    
    list(FIND IGNORE_DIRECTORY ${PARENT_F} IGNORE_FLAG)
    if (${IGNORE_FLAG} LESS "0")
        list (APPEND CPP_FOLDERS ${_dir})
    endif()
endforeach()


list (REMOVE_DUPLICATES CPP_FOLDERS)
#cmake_print_variables(CPP_FOLDERS)
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CPP_FOLDERS})