#ifndef EULER_ANGLES_H
#define EULER_ANGLES_H

#include "simple_angle.h"

struct EulerAngles{
    AngleType alpha;
    AngleType beta;
    AngleType gamma;
};

EulerAngles operator+(const EulerAngles& lhs, const EulerAngles& rhs);

#endif