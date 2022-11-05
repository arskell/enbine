#ifndef BRIGHT_ELEMENT_H
#define BRIGHT_ELEMENT_H

#include "../../math_unit/vec3.h"

typedef Vec3 LightComponentT;

class BrightElement{
protected:
    LightComponentT _flux;
public:
    virtual LightComponentT get_flux() const {return _flux;}
    virtual void set_flux(LightComponentT flux){ _flux = flux;}
};

#endif