#include "gtest/gtest.h"
#include "PhysicsLibrary.hpp"

TEST(kinematicEquationsWithGravityOnly,WhenTestingPositionAtTimeZeroWithZeroInitialCondition_ExpectCorrectResults)
{
    double accelerationDueToGravity{-9.8};
    double totalTime{0.0};
    double initialVelocity{0.0};
    double initialPosition{0.0};
    double locationOfBall = position_using_gravity_as_only_body_force(accelerationDueToGravity, totalTime, initialVelocity, initialPosition);
    double expectedLocationOfBall{0.0};

    EXPECT_EQ(locationOfBall,expectedLocationOfBall);
}

TEST(kinematicEquationsWithGravityOnly,WhenTestingPositionAtTimeZeroWithZeroVelocityAndSomeInitialPosition_ExpectCorrectResults)
{
    double accelerationDueToGravity{-9.8};
    double totalTime{0.0};
    double initialVelocity{0.0};
    double initialPosition{5.0};
    double locationOfBall = position_using_gravity_as_only_body_force(accelerationDueToGravity, totalTime, initialVelocity, initialPosition);
    double expectedLocationOfBall{initialPosition};

    EXPECT_EQ(locationOfBall,expectedLocationOfBall);
}

TEST(kinematicEquationsWithGravityOnly,WhenTestingPositionAtTimeZeroWithZeroInitialPositionAndSomeInitialVelocity_ExpectCorrectResults)
{
    double accelerationDueToGravity{-9.8};
    double totalTime{0.0};
    double initialVelocity{10.0};
    double initialPosition{0.0};
    double locationOfBall = position_using_gravity_as_only_body_force(accelerationDueToGravity, totalTime, initialVelocity, initialPosition);
    double expectedLocationOfBall{initialPosition};

    EXPECT_EQ(locationOfBall,expectedLocationOfBall);
}

TEST(kinematicEquationsWithGravityOnly,WhenTestingPositionAtTimeZeroWithSomeInitialPositionAndVelocity_ExpectCorrectResults)
{
    double accelerationDueToGravity{-9.8};
    double totalTime{0.0};
    double initialVelocity{10.0};
    double initialPosition{5.0};
    double locationOfBall = position_using_gravity_as_only_body_force(accelerationDueToGravity, totalTime, initialVelocity, initialPosition);
    double expectedLocationOfBall{initialPosition};

    EXPECT_EQ(locationOfBall,expectedLocationOfBall);
}

TEST(kinematicEquationsWithGravityOnly,WhenTestingPositionAtSomeTimeWithZeroInitialPositionAndVelocity_ExpectCorrectResults)
{
    double accelerationDueToGravity{-9.8};
    double totalTime{3.0};
    double initialVelocity{0.0};
    double initialPosition{0.0};
    double locationOfBall = position_using_gravity_as_only_body_force(accelerationDueToGravity, totalTime, initialVelocity, initialPosition);
    double expectedLocationOfBall{-44.1};

    EXPECT_EQ(locationOfBall,expectedLocationOfBall);
}

TEST(kinematicEquationsWithGravityOnly,WhenTestingPositionAtSomeTimeWithInitialVelocityAndZeroInitialPosition_ExpectCorrectResults)
{
    double accelerationDueToGravity{-9.8};
    double totalTime{3.0};
    double initialVelocity{10.0};
    double initialPosition{0.0};
    double locationOfBall = position_using_gravity_as_only_body_force(accelerationDueToGravity, totalTime, initialVelocity, initialPosition);
    double expectedLocationOfBall{-14.1};

    EXPECT_NEAR(locationOfBall,expectedLocationOfBall,0.01);
}

TEST(kinematicEquationsWithGravityOnly,WhenTestingPositionAtSomeTimeInitialVelocityAndInitialPosition_ExpectCorrectResults)
{
    double accelerationDueToGravity{-9.8};
    double totalTime{3.0};
    double initialVelocity{10.0};
    double initialPosition{5.0};
    double locationOfBall = position_using_gravity_as_only_body_force(accelerationDueToGravity, totalTime, initialVelocity, initialPosition);
    double expectedLocationOfBall{-9.1};

    EXPECT_NEAR(locationOfBall,expectedLocationOfBall,0.01);
}