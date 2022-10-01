cmake_minimum_required(VERSION 3.10)

project(enbine)
project(enbine_test)

include_directories(include/)

set(SRC 

    src/graphics/angle/euler_angles.cpp

    )

#Testing library
add_subdirectory(Catch2)
include_directories(Catch2/src)
add_executable(enbine_test ${SRC} test/main_test.cpp)

#The library itself
add_library(enbine STATIC ${SRC})

#Link testing library
target_link_libraries(enbine_test Catch2WithMain)

