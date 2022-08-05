cmake_minimum_required(VERSION 3.20)
project(6)

add_subdirectory(lib/googletest-main)
include_directories(lib/googletest-main/googletest/include)
include_directories(lib/googletest-main/googlemock/include)

set(CMAKE_CXX_STANDARD 20)


add_executable(6 main.cpp Polynomial.cpp Polynomial.h test.cpp)
target_link_libraries(6 gtest gtest_main)
