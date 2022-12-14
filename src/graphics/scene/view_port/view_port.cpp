#include "enbine/graphics/scene/view_port/view_port.h"

 void ViewPort::set(ViewPortInfo info){
        
        _info = info;

        _p = info.pos;


        _look_at = {cos(info.beta) * sin(info.alpha),
                    cos(info.beta) * cos(info.alpha),
                    sin(info.beta)};


        _s_y = {cos(info.beta - static_cast<AngleType>(M_PI_2)) * sin(info.alpha),
                cos(info.beta - static_cast<AngleType>(M_PI_2)) * cos(info.alpha),
                sin(info.beta - static_cast<AngleType>(M_PI_2))};

        _s_x = cross(_s_y, _look_at);

        //!!
        //_s_y = normalize({0,1,0});
        //_s_x = normalize({1,0,0});

        const auto screen_range = 10.0f;


        _x_size = info.screen_horizontal_size;

        auto x_half = _x_size / 2;
        auto x_half_fow = static_cast<ComponentT>(tan(info.horizontal_fow / 2) * screen_range);
        auto x_ratio = x_half_fow/ x_half;
        

        _s_x = _s_x * x_ratio;

        _y_size = info.screen_vertical_size;

        auto y_half = _y_size / 2;
        auto y_half_fow = static_cast<ComponentT>(tan(info.vertical_fow / 2) * screen_range);
        auto y_ratio = y_half_fow / y_half;

        _s_y = _s_y * y_ratio;

        _s = _p +  _look_at * screen_range - (_s_y * _y_size / 2) - (_s_x * _x_size / 2);
    }


    Ray ViewPort::get_ray(ScreenDimensionsT x_i, ScreenDimensionsT y_i){

        auto cell = _s + _s_x * x_i + _s_y * y_i;
        auto direction = cell - _p;
        
        Ray ray;
        ray.p = _p;
        ray.d = direction;

        return ray;
    }