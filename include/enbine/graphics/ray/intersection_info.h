#ifndef INTERSECTION_INFO_H
#define INTERSECTION_INFO_H

#include <memory>

#include "../math_unit/component.h"
#include "../material/material.h"


struct IntersectionInfo{
    bool is_intersected;
    //distance
    ComponentT t;
    
    Vec3 direct_reflect;
    Vec3 n;

    std::shared_ptr<Material> material;

};


#endif