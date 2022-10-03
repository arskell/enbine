#include "enbine/graphics/math_unit/vec3.h"



Vec3 operator*(const Vec3& v, const ComponentT& a){
    Vec3 ret;
    ret.x1 = v.x1 * a;
    ret.x2 = v.x2 * a;
    ret.x3 = v.x3 * a;
    return ret;
}

Vec3 operator/(const Vec3& v, const ComponentT& a){
    Vec3 ret;
    ret.x1 = v.x1 / a;
    ret.x2 = v.x2 / a;
    ret.x3 = v.x3 / a;
    return ret;
}


Vec3 operator+(const Vec3& v, const ComponentT& a){
    Vec3 ret;
    ret.x1 = v.x1 + a;
    ret.x2 = v.x2 + a;
    ret.x3 = v.x3 + a;
    return ret;
}

Vec3 operator-(const Vec3& v, const ComponentT& a){
    Vec3 ret;
    ret.x1 = v.x1 - a;
    ret.x2 = v.x2 - a;
    ret.x3 = v.x3 - a;
    return ret;
}

Vec3 operator*(const Vec3& v1, const Vec3& v2){
    Vec3 ret;
    ret.x1 = v1.x1 * v2.x1;
    ret.x2 = v1.x2 * v2.x2;
    ret.x3 = v1.x3 * v2.x3;
    return ret;
}



Vec3 operator/(const Vec3& v1, const Vec3& v2){
    Vec3 ret;
    ret.x1 = v1.x1 / v2.x1;
    ret.x2 = v1.x2 / v2.x2;
    ret.x3 = v1.x3 / v2.x3;
    return ret;
}


Vec3 operator+(const Vec3& v1, const Vec3& v2){
    Vec3 ret;
    ret.x1 = v1.x1 + v2.x1;
    ret.x2 = v1.x2 + v2.x2;
    ret.x3 = v1.x3 + v2.x3;
    return ret;
}


Vec3 operator-(const Vec3& v1, const Vec3& v2){
    Vec3 ret;
    ret.x1 = v1.x1 - v2.x1;
    ret.x2 = v1.x2 - v2.x2;
    ret.x3 = v1.x3 - v2.x3;
    return ret;
}
