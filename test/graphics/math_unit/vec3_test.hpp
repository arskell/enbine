#ifndef VEC3_HPP
#define VEC3_HPP

#include "enbine/graphics/math_unit/vec3.h"
#include <catch2/catch.hpp>


TEST_CASE("Vec3 ops", "Vec3"){
    Vec3 v = {1,10,-1};

    auto v_norm = normalize(v);

    REQUIRE(length(v_norm) == Approx(1.0f));
}


#endif