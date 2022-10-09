#include "enbine/graphics/math_unit/plane.h"


ComponentT get_intersection(const Plane& plane, const Vec3& p, const Vec3& d){
    
    ComponentT result;

    auto tmp1 = (plane.q - p) * plane.n;
    auto tmp2 = d * plane.n;

    result = tmp1/tmp2;

    return result;
}

