#ifndef RAY_H
#define RAY_H

#include "../math_unit/vec3.h"

/// @brief Simple ray with P + tD formula
struct Ray {
    Vec3 p;
    Vec3 d;
    
   // ComponentT t;
};

Vec3 to_vec3(const Ray& ray, ComponentT t);

#endif