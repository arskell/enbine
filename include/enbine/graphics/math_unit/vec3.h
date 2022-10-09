#ifndef VEC3_H
#define VEC3_H

#include "component.h"

struct Vec3
{
    ComponentT x1;
    ComponentT x2;
    ComponentT x3;
};


Vec3 operator*(const Vec3& v, const ComponentT& a);
Vec3 operator/(const Vec3& v, const ComponentT& a);
Vec3 operator+(const Vec3& v, const ComponentT& a);
Vec3 operator-(const Vec3& v, const ComponentT& a);


/// @brief Dot product
/// @param v1 
/// @param v2 
/// @return 
ComponentT operator*(const Vec3& v1, const Vec3& v2);

Vec3 operator+(const Vec3& v1, const Vec3& v2);
Vec3 operator-(const Vec3& v1, const Vec3& v2);


#endif