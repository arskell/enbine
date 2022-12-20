#ifndef POINT_DIRECTIONAL_LIGHT_H
#define POINT_DIRECTIONAL_LIGHT_H
#include "light.h"
#include "../../math_unit/vec3.h"
#include <math.h>

class PointDirectinalLight: public Light{
    public:
    LightComponentT get_illumination(const Vec3& n, const Vec3& p) const override{

        auto len_mul = length(n) * length(_n);

        auto cos_alpha = abs((n * _n)/(len_mul));
        
        auto intensity = get_flux()/(M_PI * 4);

        auto r2 = distance2(p, this->get_position());
        
        auto illumination = (intensity * cos_alpha) / r2;

        return illumination;
    }
};

#endif