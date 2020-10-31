#include "PhysicsLibrary.hpp"
#include "math.h"

double accelerationDueToGravity{9.8};
double position_using_gravity_as_only_body_force(double accelerationDueToGravity, double totalTime, double initialVelocity, double initialPosition)
{
    double position = (accelerationDueToGravity*pow(totalTime,2)/2)+initialVelocity*totalTime+initialPosition;
    return position;
};
