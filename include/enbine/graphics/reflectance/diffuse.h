#ifndef DIFFUSE_H
#define DIFFUSE_H

#include "reflectance.h"
#include "math.h"

class Diffuse: public Reflectance{
    public:
    LightComponentT get_light_coefficients(const Vec3& p, const Vec3& wi, const Vec3& w0){
        return {M_PI_2,M_PI_2,M_PI_2};
    }
};

#endif