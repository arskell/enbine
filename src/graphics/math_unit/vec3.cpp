#include "enbine/graphics/math_unit/vec3.h"
#include "math.h"


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

ComponentT operator*(const Vec3& v1, const Vec3& v2){
    ComponentT ret;
    ret = v1.x1 * v2.x1 + v1.x2 * v2.x2 + v1.x3 * v2.x3;
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


ComponentT length(const Vec3& v){
    return sqrt(v.x1*v.x1 + v.x2*v.x2 + v.x3*v.x3);
}


Vec3 normalize(const Vec3& v){
    auto len = length(v);
    return v/len;
}

Vec3 avg(const Vec3 v1, const Vec3 v2){
    return (v1 + v2)/2;
}

Vec3 cross(const Vec3& v1, const Vec3& v2){
    return {
        v1.x2*v2.x3 -  v1.x3*v2.x2,
        -(v1.x1*v2.x3 -  v1.x3*v2.x1),
        v1.x1*v2.x2 -  v1.x2*v2.x1
        };
}