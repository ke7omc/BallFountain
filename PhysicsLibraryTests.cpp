#include "gtest/gtest.h"
#include "PhysicsLibrary.hpp"

TEST(kinematicEquations,WhenTestingPosition_ExpectCorrectResults)
{
    double accelerationDueToGravity{9.8};
    double totalTime{0.0};
    double initialVelocity{0.0};
    double initialPosition{0.0};

    double location = position(accelerationDueToGravity, totalTime, initialVelocity, initialPosition);
    EXPECT_EQ(location,0.0);
}
