#ifndef MATERIAL_H
#define MATERIAL_H
#include "../scene/light/bright_element.h"

class Material{
    public:
    virtual LightComponentT get_material_light_coefficients(const Vec3& p, const Vec3& wi, const Vec3& w0) = 0;
};


#endif