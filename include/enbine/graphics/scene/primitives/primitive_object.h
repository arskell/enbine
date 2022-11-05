#ifndef PRIMITIVE_OBJECT_H
#define PRIMITIVE_OBJECT_H
#include "../../math_unit/vec3.h"

/*
    Object that has only position and orientation
*/
class PrimitiveObject{
    protected:
    Vec3 _position;
    Vec3 _n;
    public:
    virtual void set_position(Vec3 position){_position = position;}
    virtual void move_position(Vec3 delta_position) {_position = _position + delta_position;}
    virtual Vec3 get_position() const{return _position;}

    virtual void set_n(Vec3 n){_n = normalize(n);}
    virtual Vec3 get_n() const{return _n;}
};


#endif