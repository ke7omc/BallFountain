#include "PhysicsLibrary.hpp"
#include "math.h"

double accelerationDueToGravity{9.8};
double position_using_gravity_as_only_body_force(double accelerationDueToGravity, double totalTime, double initialVelocity, double initialPosition)
{
    double position = (accelerationDueToGravity*pow(totalTime,2)/2)+initialVelocity*totalTime+initialPosition;
    return position;
};


double position_using_gravity_and_drag(double mass, double accelerationDueToGravity, double previousVelocityStep, double totalTime, double initialVelocity, double initialPosition, double fluidDensity)
{
    double coefficientOfDrag{0.5};
    double area{3.1415*pow(0.5,2)};
    double position{0.0};

    if(previousVelocityStep >= 0)
    {
        position = (accelerationDueToGravity-0.5*fluidDensity*coefficientOfDrag*pow(previousVelocityStep,2)*area/mass)*(pow(totalTime,2)/2)+initialVelocity*totalTime+initialPosition;
    }

    else
    {
        position = (accelerationDueToGravity+0.5*fluidDensity*coefficientOfDrag*pow(previousVelocityStep,2)*area/mass)*(pow(totalTime,2)/2)+initialVelocity*totalTime+initialPosition;
    }

    return position;
}

double calculate_ball_velocity(double mass, double accelerationDueToGravity, double previousVelocityStep, double totalTime, double fluidDensity, double initialVelocity)
{
    double ballVelocity = (mass*accelerationDueToGravity-0.5*0.5*fluidDensity*3.1415*pow(0.5,2)*pow(previousVelocityStep,2))*totalTime+(initialVelocity*totalTime);
    return ballVelocity;
}
