cmake_minimum_required(VERSION 3.10)

#project(embine)
project(embine_test)

#Testing library
add_subdirectory(Catch2)
include_directories(Catch2/src)

add_executable(embine_test test/main_test.cpp)

#Link testing library
target_link_libraries(embine_test Catch2WithMain)

