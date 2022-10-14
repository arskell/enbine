#ifndef VEC3_HPP
#define VEC3_HPP

#include "enbine/graphics/math_unit/vec3.h"
#include <catch2/catch.hpp>


TEST_CASE("Vec3 ops", "Vec3"){
    Vec3 v = {1,10,-1};

    auto v_norm = normalize(v);

    REQUIRE(length(v_norm) == Approx(1.0f));
}

TEST_CASE("Vec3 cross product", "Vec3_cross"){
    Vec3 v1 = {10, 12, -2};
    Vec3 v2 = {34, 3, 376/2};

    REQUIRE(v1 * v2 == Approx(0.0f));

    auto v3 = cross(v1, v2);


    REQUIRE(v2 * v3 == Approx(0.0f));
    REQUIRE(v1 * v3 == Approx(0.0f));

}

#endif