#include "enbine/graphics/scene/scene.h"
#include <vector>
#include <iostream>


 IntersectionInfo Scene::_get_shortest_intersection(const Ray& ray) const{
    if(_objects.empty()){return {};}

    IntersectionInfo shortest = _objects.begin()->second->get_intersection(ray);
    
    for(auto it = std::next(_objects.begin()); it != _objects.end(); ++it){
        auto intersection =  it->second->get_intersection(ray);
    
        if(intersection.is_intersected){
            if(!shortest.is_intersected || shortest.t > intersection.t){
                shortest = intersection;
            }
        }
    }

    return shortest;
 }

LightComponentT Scene::get_light(const Ray& ray){
    
    auto shortest = _get_shortest_intersection(ray);
    if(!shortest.is_intersected){
        return _background;
    }

    LightComponentT l_global{};
    auto p = to_vec3(ray, shortest.t);
    auto material_coeff = shortest.material->get_material_light_coefficients(p, ray.d, {/*todo calculate reflection vector*/});

    for(const auto& l: _light){
        //test shadow here
        //calulate distance to light
        auto min_dist = distance(l.second->get_position(), p);
        //contruct ray 
        Ray ray_to_light;
        ray_to_light.d = normalize(l.second->get_position() - p);
        ray_to_light.p = p + ray_to_light.d * 10; /*< some step out (to avoid false positive intersecting with itself object)*/
        auto ray_to_light_intersection = _get_shortest_intersection(ray_to_light);
        //test
        if(ray_to_light_intersection.is_intersected && ray_to_light_intersection.t < min_dist){
            //failed
            break;
        }
        auto curr_illum = l.second->get_illumination(shortest.n, p);
        auto l_current =  LightComponentT{curr_illum.x1 * material_coeff.x1, curr_illum.x2 * material_coeff.x2, curr_illum.x3 * material_coeff.x3};
        l_global = l_global + l_current;
    }

    return l_global;
}