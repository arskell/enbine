#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../../math_unit/plane.h"
#include "../../math_unit/vec3.h"
#include "../../ray/ray.h"
#include "../../ray/intersection_info.h"

class Triangle{
private:
    Vec3 _a;
    Vec3 _b;
    Plane _plane;
    ComponentT _area;

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

        auto crs = cross(ab, ac);

        _area = 0.5 * length(crs);
        _plane.n = normalize(crs);
    }

    friend IntersectionInfo calc_intersection(const Triangle& triange, const Ray& ray);
};


#endif