include(CMakePrintHelpers)

cmake_minimum_required(VERSION 3.20)
project(modbus)
add_executable(${PROJECT_NAME} main.cpp)


add_subdirectory(device)
add_subdirectory(utils)
add_subdirectory(csv)
add_subdirectory(logger)

target_link_libraries(${PROJECT_NAME} Device Utils Csv Logger)