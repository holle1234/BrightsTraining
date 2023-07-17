cmake_minimum_required(3.20)
project(ex-1)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(status)

target_link_libraries(${PROJECT_NAME} Status)