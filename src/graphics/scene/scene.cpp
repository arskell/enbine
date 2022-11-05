#include "enbine/graphics/scene/scene.h"
#include <vector>

LightComponentT Scene::get_light(const Ray& ray){
    const LightComponentT background = {30,30,30};

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

    LightComponentT e{};

    for(const auto& l: _light){
        e = e + l.second->get_illumination(shortest.n, to_vec3(ray, shortest.t));
    }

    return e;
}