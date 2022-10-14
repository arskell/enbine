#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../../math_unit/plane.h"
#include "../../math_unit/vec3.h"
#include "../../ray/ray.h"

class Triangle{
private:
    Vec3 _a;
    Vec3 _b;
    Plane _plane;
public:
    Triangle(){
        set({}, {}, {});
    }

    Triangle(const Vec3& a, const Vec3& b, const Vec3& c){
        set(a, b, c);
    }

    void set(const Vec3& a, const Vec3& b, const Vec3& c){
        _a = a;
        _b = b;
        _plane.q = c;

        auto ab = b - a;
        auto ac = c - a;

        _plane.n = cross(ab, ac);
    }

    friend bool is_intersecting(const Ray& ray);

};


#endif