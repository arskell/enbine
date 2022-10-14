#include <math.h>

#include "enbine/graphics/math_unit/component.h"

bool equal(const ComponentT& comp1, const ComponentT& comp2, const ComponentT& eps){
    return abs(comp2 - comp1) <= eps;
}
