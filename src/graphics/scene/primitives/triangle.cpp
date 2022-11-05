#include "enbine/graphics/scene/primitives/triangle.h"
#include "math.h"


//calculate intersection with triangle (if present)
IntersectionInfo calc_intersection(const Triangle& triange, const Ray& ray){
    IntersectionInfo result;
    result.is_intersected = false;

    result.t = get_intersection(triange._plane, ray.p, ray.d);
    
    if(result.t > 0){
        auto inters = to_vec3(ray, result.t);

        auto sum_area = area(triange._a, triange._b, inters) + 
                        area(triange._a, triange._plane.q, inters) + 
                        area(triange._b, triange._plane.q, inters);

        result.is_intersected = equal(triange._area, sum_area, 1e-2);
    }
    return result;
}


void Triangle::set(const Vec3& a, const Vec3& b, const Vec3& c){
    _a = a;
    _b = b;
    _plane.q = c;

    auto ab = b - a;
    auto ac = c - a;

    auto crs = cross(ab, ac);

    _area = 0.5 * length(crs);
    _plane.n = normalize(crs);
}
void Triangle::set_position(Vec3 position) {
    auto pos = get_position();
    auto delta_pos = position - pos;
    move_position(delta_pos);
}

void Triangle::move_position(Vec3 delta_position){
    _a = _a + delta_position;
    _b = _b + delta_position;
    _plane.q = _plane.q + delta_position;
}

Vec3 Triangle::get_position() const{
    return (_a + _b + _plane.q)/3;
}

void Triangle::set_n(Vec3 n){
    _plane.n = n;
}
