#ifndef PLANE_TEST_HPP
#define PLANE_TEST_HPP

#include "enbine/graphics/math_unit/plane.h"
#include "enbine/graphics/ray/ray.h"

TEST_CASE("Plane operations", "Plane"){
    
    Plane plane;
    plane.n = {1, 0, 1};
    plane.q = {1, 0, 0};

    Ray ray;
    ray.d = {1, 0, 0};
    ray.p = {0.1f, 0.1f, 0.1f};

    ray.t = get_intersection(plane, ray.p, ray.d);

    REQUIRE( abs((ray.p + ray.d * ray.t - plane.q)*plane.n) == Approx(0.0f) );

}

#endif