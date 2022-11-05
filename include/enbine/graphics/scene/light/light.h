#ifndef LIGHT_H
#define LIGHT_H
#include "bright_element.h"
#include "../primitives/primitive_object.h"

class Light: public BrightElement, public PrimitiveObject{
public:
    virtual LightComponentT get_illumination(const Vec3& n, const Vec3& p) const = 0;
};

#endif