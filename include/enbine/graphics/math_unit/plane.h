#ifndef PLANE_H
#define PLANE_H

#include "vec3.h"

struct Plane{
    Vec3 q;
    Vec3 n;
};


/// @brief find t in intersection of plane [p  * n = 0] and ray [p + t*d]
/// @param plane 
/// @param p 
/// @param d 
/// @return 
ComponentT get_intersection(const Plane& plane, const Vec3& p, const Vec3& d);

#endif