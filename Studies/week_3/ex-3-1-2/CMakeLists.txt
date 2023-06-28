cmake_minimum_required(VERSION 3.20)
project(weather)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(utils csv)

target_link_libraries(${PROJECT_NAME} Utils Csv)