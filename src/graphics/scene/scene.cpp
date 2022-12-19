#include "enbine/graphics/scene/scene.h"
#include <vector>

LightComponentT Scene::get_light(const Ray& ray){
    const LightComponentT background = {0, 0, 0};

    if(_objects.empty()){return background;}
    IntersectionInfo shortest = _objects.begin()->second->get_intersection(ray);
    
    for(auto it = std::next(_objects.begin()); it != _objects.end(); ++it){
        auto intersection =  it->second->get_intersection(ray);
    
        if(intersection.is_intersected){
            if(shortest.t > intersection.t){
                shortest = intersection;
            }
        }
    }

    if(!shortest.is_intersected){
        return background;
    }

    

    LightComponentT l_global{};
    auto p = to_vec3(ray, shortest.t);
    auto material_coeff = shortest.material->get_material_light_coefficients(p, ray.d, {/*todo calculate reflection vector*/});

    for(const auto& l: _light){

        //todo get shadow here
        auto curr_illum = l.second->get_illumination(shortest.n, p);
        auto l_current =  LightComponentT{curr_illum.x1 * material_coeff.x1, curr_illum.x2 * material_coeff.x2, curr_illum.x3 * material_coeff.x3};
        l_global = l_global + l_current;
    }

    return l_global;
}