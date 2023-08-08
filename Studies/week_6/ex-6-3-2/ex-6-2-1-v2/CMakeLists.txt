cmake_minimum_required(VERSION 3.20)
project(my_app)


add_executable(${PROJECT_NAME} main.cpp)
add_subdirectory(unit_testing)
add_subdirectory(source)

target_link_libraries(${PROJECT_NAME} Source)