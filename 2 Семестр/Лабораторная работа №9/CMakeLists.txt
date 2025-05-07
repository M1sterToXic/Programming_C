cmake_minimum_required(VERSION 3.10)
project(project_8)

enable_testing()
find_package(cmocka REQUIRED)

add_executable(TEST_MAIN Tester.c test_main.c)
target_link_libraries(TEST_MAIN cmocka)
add_test(NAME T_MAIN COMMAND main)
set(CTEST_OUTPUT_ON_FAILURE ON)