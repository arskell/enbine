#ifndef VIEW_PORT_H
#define VIEW_PORT_H

#include "../../angle/simple_angle.h"
#include "../primitives/primitive_object.h"
#include "../../math_unit/vec3.h"
#include "../../ray/ray.h"
#include "../../math_unit/plane.h"

typedef unsigned int ScreenDimensionsT;

class ViewPort{
    
    //'point of view'(absolute)
    Vec3 _p;

    Vec3 _look_at;

    //absolute
    Vec3 _s;
    //relative to s
    Vec3 _s_y;
    Vec3 _s_x;

    ScreenDimensionsT _x_size;
    ScreenDimensionsT _y_size;    
    
    public:

    ViewPort(){
        _x_size = _y_size = 600;

        _p = { 0, 0, 0};
        _look_at = normalize({0,0,1});

        //_look_at, _s_y, _s_x must be ortho
        _s_y = normalize({0,1,0});
        _s_x = normalize({1,0,0});

        const auto screen_range = 10.0f;

        _s = _p +  _look_at * screen_range - (_s_y * _y_size/2) - (_s_x * _x_size/2);

    }

    ScreenDimensionsT get_view_port_width() const{
        return _x_size;
    }

    ScreenDimensionsT get_view_port_height() const{
        return _y_size;
    }

    Ray get_ray(ScreenDimensionsT x_i, ScreenDimensionsT y_i){

        auto cell = _s + _s_x * x_i + _s_y * y_i;
        auto direction = cell - _p;
        
        Ray ray;
        ray.p = _p;
        ray.d = direction;
        ray.t = 0;

        return ray;
    }

};

#endif