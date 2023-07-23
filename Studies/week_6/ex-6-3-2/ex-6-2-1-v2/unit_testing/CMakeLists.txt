add_executable(test test.cpp)
target_include_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/source)
target_link_libraries(test PUBLIC Source)

add_custom_command(
  COMMAND test
  OUTPUT test_results.txt
)

add_custom_target(
  UnitTestResults ALL
  DEPENDS test_results.txt
)