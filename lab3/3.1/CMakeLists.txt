cmake_minimum_required(VERSION 3.20)
project(3)

set(CMAKE_CXX_STANDARD 17)

add_executable(3 main.cpp CircularBuffer.h CircularBuffer.cpp Iterator.cpp Iterator.h)
