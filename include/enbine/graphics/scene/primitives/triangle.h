#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "enbine/graphics/math_unit/plane.h"

struct Triangle{
    Vec3 a;
    Vec3 b;
    Plane plane;
};


#endif