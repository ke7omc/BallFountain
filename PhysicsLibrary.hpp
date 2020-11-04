#ifndef PHYSICS_LIBRARY_HPP
#define PHYSICS_LIBRARY_HPP

double position_using_gravity_as_only_body_force(double accelerationDueToGravity, double totalTime, double initialVelocity, double initialPosition);
double position_using_gravity_and_drag(double mass, double accelerationDueToGravity, double previousVelocityStep, double totalTime, double initialVelocity, double initialPosition, double fluidDensity);
double calculate_ball_velocity(double mass, double accelerationDueToGravity, double previousVelocityStep, double totalTime, double fluidDensity, double initialVelocity);

#endif // PHYSICS_LIBRARY_HPP
