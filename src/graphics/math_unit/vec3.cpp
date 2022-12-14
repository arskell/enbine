#include "enbine/graphics/math_unit/vec3.h"
#include "math.h"



std::ostream& operator<<(std::ostream&s, const Vec3& v){
    s << "x1: "<<v.x1 <<" | x2: "<<v.x2<<" | x3: "<<v.x3;
    return s;
}

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

ComponentT distance2(const Vec3& v1, const Vec3& v2){
    return pow(v2.x1 - v1.x1, 2) + pow(v2.x2 - v1.x2, 2) + pow(v2.x3 - v1.x3, 2);
}

ComponentT distance(const Vec3& v1,const Vec3& v2){
    return sqrt(distance2(v1, v2));
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


ComponentT area(const Vec3& a, const Vec3& b, const Vec3& c){
    auto ab = b - a;
    auto ac = c - a;
    auto tmp = cross(ab, ac);
    
    return 0.5f * length(tmp);
}


Vec3 euler_rotate(const Vec3& vec, AngleType alpha, AngleType beta, AngleType gamma){
    return {
        vec.x1 * (cos(alpha)* cos(gamma) - cos(beta) * sin(alpha) * sin(gamma)) + vec.x2 * ( -cos(gamma) * sin(alpha) - cos(alpha) * cos(beta) * sin(gamma))  + vec.x3 * sin(beta) * sin(gamma),
        vec.x1 * (cos(beta) * cos(gamma) * sin(alpha) + cos(alpha) * sin(gamma)) + vec.x2 * (cos(alpha) * cos(beta) * cos(gamma) - sin(alpha) * sin(gamma)) - vec.x3 * cos(gamma) * sin(beta),
        vec.x1 * sin(alpha) * sin(beta) + vec.x2 * cos(alpha) * sin(beta) + vec.x3 * cos(beta)
    };
}