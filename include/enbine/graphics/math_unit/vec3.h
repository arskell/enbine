#ifndef VEC3_H
#define VEC3_H

#include "component.h"
#include "../angle/simple_angle.h"

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

ComponentT length(const Vec3& v);
ComponentT distance2(const Vec3& v1, const Vec3& v2);
ComponentT distance(const Vec3& v1,const Vec3& v2);

Vec3 normalize(const Vec3& v);

Vec3 avg(const Vec3 v1, const Vec3 v2);

/// @brief cross product
/// @param v1 
/// @param v2 
/// @return 
Vec3 cross(const Vec3& v1, const Vec3& v2);

ComponentT area(const Vec3& a, const Vec3& b, const Vec3& c);


/// @brief Apply euler rotation 
/// @param vec 
/// @param alpha 
/// @param beta 
/// @return 
Vec3 euler_rotate(const Vec3& vec, AngleType alpha, AngleType beta, AngleType gamma);

#endif