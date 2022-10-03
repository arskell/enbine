#ifndef VIEW_PORT_H
#define VIEW_PORT_H

#include "../../angle/simple_angle.h"
#include "../primitives/primitive_object.h"

typedef unsigned int ScreenDimensionsT;

class ViewPort: public PrimitiveObject{
    AngleType _fow;    
    ScreenDimensionsT _height;
    ScreenDimensionsT _width;
    public:
    void set_field_of_view(AngleType fow);
    void set_screen_dimensions(ScreenDimensionsT height, ScreenDimensionsT width);
};

#endif