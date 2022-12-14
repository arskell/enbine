#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H
#include "light.h"
#include "../../math_unit/vec3.h"
#include <math.h>

class PointLight: public Light{
    public:
    LightComponentT get_illumination(const Vec3& n, const Vec3& p) const override{

        auto len_mul = length(n) * length(_n);

        auto intensity = get_flux()/(M_PI * 4);

        auto r2 = distance2(p, this->get_position());
        
        auto illumination = intensity / r2;

        return illumination;
    }
};

#endif