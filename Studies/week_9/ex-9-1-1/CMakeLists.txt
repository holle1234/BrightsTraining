cmake_minimum_required(VERSION 3.20)
project(calculator)


add_executable(${PROJECT_NAME} main.cpp)
add_subdirectory(source)

target_link_libraries(${PROJECT_NAME} Source)