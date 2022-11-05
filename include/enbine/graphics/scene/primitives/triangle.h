#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../../math_unit/plane.h"
#include "../../math_unit/vec3.h"
#include "../../ray/ray.h"
#include "../../ray/intersection_info.h"
#include "primitive_object.h"

class Triangle: public PrimitiveObject{
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

    void set(const Vec3& a, const Vec3& b, const Vec3& c);
    void set_position(Vec3 position) override;
    void move_position(Vec3 delta_position) override;
    Vec3 get_position() const override;
    void set_n(Vec3 n) override;
    Vec3 get_n() const override{return _plane.n;}

    friend IntersectionInfo calc_intersection(const Triangle& triange, const Ray& ray);
};


#endif