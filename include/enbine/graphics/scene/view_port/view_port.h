#ifndef VIEW_PORT_H
#define VIEW_PORT_H

#include <math.h>

#include "../../angle/simple_angle.h"
#include "../primitives/primitive_object.h"
#include "../../math_unit/vec3.h"
#include "../../ray/ray.h"
#include "../../math_unit/plane.h"
#include "view_port_screen.h"
#include "vew_port_info.h"


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
    
    ViewPortInfo _info;

    public:

    ViewPort(ViewPortInfo info = {}){set(info);}

    ViewPortInfo get_info() const{return _info;}

    void set(ViewPortInfo info);

    Vec3 get_look_at() const {return _look_at;}


    ScreenDimensionsT get_view_port_width() const{
        return _x_size;
    }

    ScreenDimensionsT get_view_port_height() const{
        return _y_size;
    }

    Ray get_ray(ScreenDimensionsT x_i, ScreenDimensionsT y_i);

};

#endif