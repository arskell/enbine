#ifndef VIEW_PORT_TEST_H
#define VIEW_PORT_TEST_H

#include "enbine/graphics/scene/view_port/view_port.h"
#include <catch2/catch.hpp>


TEST_CASE("View_port ops", "ViewPort"){

    ViewPort view_port;

    SECTION("Diagonal sizes"){

        auto r1 = view_port.get_ray(0,0);
        r1.t = 100;

        auto r2 = view_port.get_ray(view_port.get_view_port_width(), view_port.get_view_port_height());
        r2.t = 100;

        auto r3 = view_port.get_ray(view_port.get_view_port_width(),0);
        r3.t = 100;

        auto r4 = view_port.get_ray(0, view_port.get_view_port_height());
        r4.t = 100;

        auto r12 = to_vec3(r2) - to_vec3(r1);
        auto r34 = to_vec3(r4) - to_vec3(r3);

        REQUIRE(length(r12) == Approx(length(r34)));
    }

    SECTION("Corner to observer distance"){

        auto r1 = view_port.get_ray(0,0);
        r1.t = 100;

        auto r2 = view_port.get_ray(view_port.get_view_port_width(), view_port.get_view_port_height());
        r2.t = 100;

        auto r3 = view_port.get_ray(view_port.get_view_port_width(),0);
        r3.t = 100;

        auto r4 = view_port.get_ray(0, view_port.get_view_port_height());
        r4.t = 100;

        auto r_cent = view_port.get_ray(view_port.get_view_port_width()/2, view_port.get_view_port_height()/2);
        r_cent.t = 100;

        auto v1 = to_vec3(r1);
        auto v2 = to_vec3(r2);
        auto v3 = to_vec3(r3);
        auto v4 = to_vec3(r4);
        
        auto v_cent = to_vec3(r_cent);

        auto v13 = avg(v1, v3);
        auto v24 = avg(v2, v4);
        auto v_avg = avg(v13, v24);

        REQUIRE(v_cent.x1 == Approx(v_avg.x1));
        REQUIRE(v_cent.x2 == Approx(v_avg.x2));
        REQUIRE(v_cent.x3 == Approx(v_avg.x3));
    }

}

#endif