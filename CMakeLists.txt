cmake_minimum_required(VERSION 3.10)

project(enbine)
project(enbine_test)

include_directories(include/)

set(SRC 

    src/graphics/angle/euler_angles.cpp
    src/graphics/math_unit/vec3.cpp
    src/graphics/math_unit/component.cpp
    src/graphics/math_unit/plane.cpp
    src/graphics/scene/primitives/triangle.cpp
    src/graphics/ray/ray.cpp
    )

#Testing library
add_subdirectory(Catch2)
include_directories(Catch2/single_include)

add_executable(enbine_test ${SRC} test/main_test.cpp)

#Link testing library
target_link_libraries(enbine_test Catch2)


#The library itself
add_library(enbine STATIC ${SRC})



