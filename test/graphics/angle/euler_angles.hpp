#include <catch2/catch.hpp>
#include <graphics/angle/euler_angles.h>


TEST_CASE("Euler angles operations", "EulerOps"){

    SECTION("Adds"){
        EulerAngles el1;
        el1.alpha = 1;
        el1.beta = 0.5;
        el1.gamma = 0.1;

        auto res = el1 + EulerAngles{1.1, 0.2, 0.3};

        REQUIRE(res.alpha == Approx(2.1));
        REQUIRE(res.beta ==  Approx(0.7));
        REQUIRE(res.gamma == Approx(0.4));

    }
}

