#include "enbine/graphics/angle/euler_angles.h"


EulerAngles operator+(const EulerAngles& lhs, const EulerAngles& rhs){
    EulerAngles result;

    result.alpha = lhs.alpha + rhs.alpha;
    result.beta = lhs.beta + rhs.beta;
    result.gamma = lhs.gamma + rhs.gamma;

    return result;
}