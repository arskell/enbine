#include "enbine/graphics/scene/scene.h"
#include <vector>

LightComponentT Scene::get_light(const Ray& ray){
    const Vec3 background = {100,100,100};

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

    //todo calc actual light

    return (shortest.is_intersected == true)?Vec3{0,0,0}:background;
}