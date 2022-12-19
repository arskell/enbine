#ifndef TRIANGLE_TEST_HPP
#define TRIANGLE_TEST_HPP


#include <catch2/catch.hpp>
#include "enbine/graphics/scene/primitives/triangle.h"
#include "enbine/graphics/material/metal.h"

TEST_CASE("Triangle", "Triangle"){
    Triangle triangle(
        {10, -10, 0}, 
        {10, 10, 0}, 
        {10, 10 ,10}, std::make_shared<MetalMaterial>());

    Ray ray;

    ray.p = {0,0,0};
    ray.d = {1, 0, 0};

    auto intersection = calc_intersection(triangle, ray);
    REQUIRE(intersection.is_intersected == true);
    REQUIRE(intersection.t == Approx(10.f));

    ray.p = {0,0,0};
    ray.d = normalize({1, 0.5, 0});
    intersection = calc_intersection(triangle, ray);
    REQUIRE(intersection.is_intersected == true);


    ray.p = {0,0,0};
    ray.d = normalize({1, -0.95, -5});
    intersection = calc_intersection(triangle, ray);
    REQUIRE(intersection.is_intersected == false);

    ray.p = {0,0,0};
    ray.d = {-1, 0, 0};

    intersection = calc_intersection(triangle, ray);
    REQUIRE(intersection.is_intersected == false);
}

#endif