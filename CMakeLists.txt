cmake_minimum_required(VERSION 3.16)
project(oop_lab_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(oop_lab_1
    main.cpp
    matrix_ops.cpp
)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

add_executable(tests
    test_variant.cpp
    matrix_ops.cpp
)

target_link_libraries(tests GTest::gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(tests)