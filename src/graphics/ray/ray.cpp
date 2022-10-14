#include "enbine/graphics/ray/ray.h"


Vec3 to_vec3(const Ray& ray, ComponentT t){
    return ray.p + ray.d * t;
}