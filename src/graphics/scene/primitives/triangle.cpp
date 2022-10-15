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