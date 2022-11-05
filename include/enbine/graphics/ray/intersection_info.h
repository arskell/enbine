#ifndef INTERSECTION_INFO_H
#define INTERSECTION_INFO_H

#include "../math_unit/component.h"

struct IntersectionInfo{
    bool is_intersected;
    //distance
    ComponentT t;
    
    Vec3 direct_reflect;
    Vec3 n;
};


#endif