#ifndef INTERSECTABLE_OBJECT
#define INTERSECTABLE_OBJECT
#include "primitive_object.h"
#include "../../ray/intersection_info.h"
#include "../../ray/ray.h"

class IntersectableObject: public PrimitiveObject{
    public:
    virtual IntersectionInfo get_intersection(const Ray& ray) const = 0;
};

#endif