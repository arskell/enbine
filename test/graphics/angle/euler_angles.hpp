#include <catch2/catch_all.hpp>
#include <graphics/angle/euler_angles.h>


TEST_CASE("Euler angles operations", "EulerOps"){

    SECTION("Adds"){
        EulerAngles el1;
        el1.alpha = 1;
        el1.beta = 0.5;
        el1.gamma = 0.1;

        auto res = el1 + EulerAngles{1.1, 0.2, 0.3};

        REQUIRE(res.alpha == Catch::Approx(2.1));
        REQUIRE(res.beta == Catch::Approx(0.7));
        REQUIRE(res.gamma == Catch::Approx(0.4));

    }
}

