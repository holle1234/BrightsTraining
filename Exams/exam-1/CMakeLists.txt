cmake_minimum_required(VERSION 3.20)
project(finance_tracker)
add_executable(${PROJECT_NAME} main.cpp)


add_subdirectory(transactions)


target_link_libraries(${PROJECT_NAME} Finance_tracker)