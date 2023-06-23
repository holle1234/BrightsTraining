cmake_minimum_required(VERSION 3.20)
project(mylibrary.exe)


add_executable(${PROJECT_NAME} main.cpp)
add_subdirectory(library)
add_subdirectory(utils)

target_link_libraries(${PROJECT_NAME} BookLibrary Utils)
