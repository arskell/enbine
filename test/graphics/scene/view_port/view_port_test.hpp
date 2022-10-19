#ifndef VIEW_PORT_TEST_H
#define VIEW_PORT_TEST_H

#include "enbine/graphics/scene/view_port/view_port.h"
#include <catch2/catch.hpp>


TEST_CASE("View_port ops", "ViewPort"){
    
    ViewPortInfo info{};
    
    info.screen_horizontal_size = info.screen_vertical_size = 600;
    info.horizontal_fow = info.vertical_fow = M_PI_2;
    
    ViewPort view_port(info);

    SECTION("Diagonal sizes"){

        auto r1 = view_port.get_ray(0,0);

        auto r2 = view_port.get_ray(view_port.get_view_port_width(), view_port.get_view_port_height());

        auto r3 = view_port.get_ray(view_port.get_view_port_width(),0);;

        auto r4 = view_port.get_ray(0, view_port.get_view_port_height());

        auto r12 = to_vec3(r2, 100) - to_vec3(r1, 100);
        auto r34 = to_vec3(r4, 100) - to_vec3(r3, 100);

        REQUIRE(length(r12) == Approx(length(r34)));
    }

    SECTION("Corner to observer distance"){

        auto r1 = view_port.get_ray(0,0);

        auto r2 = view_port.get_ray(view_port.get_view_port_width(), view_port.get_view_port_height());

        auto r3 = view_port.get_ray(view_port.get_view_port_width(),0);

        auto r4 = view_port.get_ray(0, view_port.get_view_port_height());

        auto r_cent = view_port.get_ray(view_port.get_view_port_width()/2, view_port.get_view_port_height()/2);

        auto v1 = to_vec3(r1, 100);
        auto v2 = to_vec3(r2, 100);
        auto v3 = to_vec3(r3, 100);
        auto v4 = to_vec3(r4, 100);
        
        auto v_cent = to_vec3(r_cent, 100);

        auto v13 = avg(v1, v3);
        auto v24 = avg(v2, v4);
        auto v_avg = avg(v13, v24);

        REQUIRE(v_cent.x1 == Approx(v_avg.x1));
        REQUIRE(v_cent.x2 == Approx(v_avg.x2));
        REQUIRE(v_cent.x3 == Approx(v_avg.x3));
    }

}

#endif