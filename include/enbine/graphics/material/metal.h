#ifndef METAL_MATERIAL_H
#define METAL_MATERIAL_H

#include "material.h"
#include "../reflectance/diffuse.h"
#include "../color/rgb.h"
#include "../math_unit/vec3.h"

class MetalMaterial: public Material{
    Diffuse _reflectness;
    const RGB _primary_color{0.5f, 0.5f, 0.5f};    
    public:
    MetalMaterial(){}
    MetalMaterial(RGB primary_color):_primary_color(primary_color){}
    LightComponentT get_material_light_coefficients(const Vec3& p, const Vec3& wi, const Vec3& w0) override{
        auto ref = _reflectness.get_light_coefficients(p, wi, w0);
        return  {_primary_color.r * ref.x1, _primary_color.g * ref.x2, _primary_color.b * ref.x3};
    }
};

#endif