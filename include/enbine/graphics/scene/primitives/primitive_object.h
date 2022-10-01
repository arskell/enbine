#ifndef PRIMITIVE_OBJECT_H
#define PRIMITIVE_OBJECT_H
#include "../../angle/euler_angles.h"
#include "../../position/position.h"

/*
    Object that has only position and orientation
*/
class PrimitiveObject{
    protected:
    Position3D _position;
    EulerAngles _orientation;
    public:
    void set_position(Position3D position);
    void move_position(Position3D delta_position);

    void set_orientation(EulerAngles orientation);
    void move_orientation(EulerAngles delta_orientation);
};


#endif