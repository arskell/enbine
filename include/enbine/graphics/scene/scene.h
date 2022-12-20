#ifndef SCENE_H
#define SCENE_H

#include <map>
#include <memory>
#include <string.h>
#include "light/light.h"
#include "primitives/intersectable_object.h"

class Scene{
    private:

    const LightComponentT _background = {0, 0, 0};

    std::map<std::string, std::shared_ptr<Light>> _light;
    std::map<std::string, std::shared_ptr<IntersectableObject>> _objects;

    IntersectionInfo _get_shortest_intersection(const Ray& ray) const;

    public:
    void add(const std::string& name, std::shared_ptr<Light> light){_light.insert({name, light});}
    void add(const std::string& name, std::shared_ptr<IntersectableObject> obj){ _objects.insert({name, obj});};
    LightComponentT get_light(const Ray& ray);
};

#endif