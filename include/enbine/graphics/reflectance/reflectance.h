#ifndef REFLECTANCE_H
#define REFLECTANCE_H

#include "../scene/light/bright_element.h"

class Reflectance{
    public:
    //calculate BRDF
    virtual LightComponentT get_light_coefficients(const Vec3& p, const Vec3& wi, const Vec3& w0) = 0;
};

#endif