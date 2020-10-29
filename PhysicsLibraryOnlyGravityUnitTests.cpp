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

TEST(kinematicEquationsWithGravityOnly,WhenTestingPositionOverAVaryingTimeAndZeroInitialVelocityAndPosition_ExpectCorrectResults)
{
    double accelerationDueToGravity{-9.8};
    double totalTime{0.0};
    double initialVelocity{0.0};
    double initialPosition{0.0};
    double locationOfBall [5] = {0.0, 0.0, 0.0, 0.0, 0.0};

    for (int i=0; i<=4; i++)
    {
        locationOfBall [i] = position_using_gravity_as_only_body_force(accelerationDueToGravity, totalTime, initialVelocity, initialPosition);
        totalTime = totalTime+(1.0/30);
    }

    double expectedLocationOfBall [5] = {0, -0.0054, -0.0217, -0.049, -0.0871};

    EXPECT_NEAR(locationOfBall [0],expectedLocationOfBall [0], 0.0001);
    EXPECT_NEAR(locationOfBall [1],expectedLocationOfBall [1], 0.0001);
    EXPECT_NEAR(locationOfBall [2],expectedLocationOfBall [2], 0.0001);
    EXPECT_NEAR(locationOfBall [3],expectedLocationOfBall [3], 0.0001);
    EXPECT_NEAR(locationOfBall [4],expectedLocationOfBall [4], 0.0001);
}

TEST(kinematicEquationsWithGravityOnly,WhenTestingPositionOverAVaryingTimeSomePositionAndZeroInitialVelocity_ExpectCorrectResults)
{
    double accelerationDueToGravity{-9.8};
    double totalTime{0.0};
    double timeStep{1.0/30.0};
    double initialVelocity{0.0};
    double initialPosition{10.0};
    double locationOfBall [5] = {0.0, 0.0, 0.0, 0.0, 0.0};

    for (int i=0; i<=4; i++)
    {
        locationOfBall [i] = position_using_gravity_as_only_body_force(accelerationDueToGravity, totalTime, initialVelocity, initialPosition);
        totalTime = totalTime+timeStep;
    }

    double expectedLocationOfBall [5] = {10.0, 9.9945, 9.9782, 9.951, 9.9128};

    EXPECT_NEAR(locationOfBall [0],expectedLocationOfBall [0], 0.0001);
    EXPECT_NEAR(locationOfBall [1],expectedLocationOfBall [1], 0.0001);
    EXPECT_NEAR(locationOfBall [2],expectedLocationOfBall [2], 0.0001);
    EXPECT_NEAR(locationOfBall [3],expectedLocationOfBall [3], 0.0001);
    EXPECT_NEAR(locationOfBall [4],expectedLocationOfBall [4], 0.0001);
}

TEST(kinematicEquationsWithGravityOnly,WhenTestingPositionOverAVaryingTimeWithSomeInitialVelocityAndPosition_ExpectCorrectResults)
{
    double accelerationDueToGravity{-9.8};
    double totalTime{0.0};
    double timeStep{1.0/5.0};
    double initialVelocity{5.0};
    double initialPosition{10.0};
    double locationOfBall [5] = {0.0, 0.0, 0.0, 0.0, 0.0};

    for (int i=0; i<=4; i++)
    {
        locationOfBall [i] = position_using_gravity_as_only_body_force(accelerationDueToGravity, totalTime, initialVelocity, initialPosition);
        totalTime = totalTime+timeStep;
    }

    double expectedLocationOfBall [5] = {10.0, 10.804, 11.216, 11.236, 10.864};

    EXPECT_NEAR(locationOfBall [0],expectedLocationOfBall [0], 0.0001);
    EXPECT_NEAR(locationOfBall [1],expectedLocationOfBall [1], 0.0001);
    EXPECT_NEAR(locationOfBall [2],expectedLocationOfBall [2], 0.0001);
    EXPECT_NEAR(locationOfBall [3],expectedLocationOfBall [3], 0.0001);
    EXPECT_NEAR(locationOfBall [4],expectedLocationOfBall [4], 0.0001);
}
