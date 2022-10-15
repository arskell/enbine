#ifndef VIEW_PORT_INFO_H
#define VIEW_PORT_INFO_H

#include "../../math_unit/vec3.h"
#include "../../angle/euler_angles.h"
#include "view_port_screen.h"

struct ViewPortInfo{
    Vec3 pos;
    EulerAngles rotation_pos;
    
    AngleType horizontal_fow;
    AngleType vertical_fow;
    ScreenDimensionsT screen_horizontal_size;
    ScreenDimensionsT screen_vertical_size;
};


#endif