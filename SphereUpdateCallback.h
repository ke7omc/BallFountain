#ifndef SPHEREUPDATECALLBACK_H
#define SPHEREUPDATECALLBACK_H

#include "OSGWidget.h"
#include "PhysicsLibrary.hpp"
#include "math.h"
#include "PhysicsRepresentationOfBall.h"
#include "mainwindow.h"

#include <osg/Camera>
#include <osg/DisplaySettings>
#include <osg/Geode>
#include <osg/Material>
#include <osg/Shape>
#include <osg/ShapeDrawable>
#include <osg/StateSet>
#include <osgDB/WriteFile>
#include <osgGA/EventQueue>
#include <osgViewer/View>
#include <osgViewer/ViewerEventHandlers>
#include <osg/MatrixTransform>
#include <osg/NodeVisitor>
#include <osg/LineWidth>
#include <osgUtil/SmoothingVisitor>
#include <osg/PositionAttitudeTransform>

#include <cassert>
#include <vector>

#include <QKeyEvent>
#include <QPainter>
#include <QWheelEvent>


class SphereUpdateCallback: public osg::NodeCallback
{
public:
    SphereUpdateCallback(){}
    double gravity{-9.8};
    double ballSize{1.0};
    double initialVelocity{18.0};
    double velocity = initialVelocity;
    double angleOfBallShoot{85};
    double initialYPosition{-8.0};
    double initialXPosition{-7.0};
    double locationInTheYDirection{0.0};
    double locationInTheXDirection{0.0};
    double coefficientOfRestitution{0.7};
    bool resetProgram{true};
    double initialVelocityInYDirection{initialVelocity*sin(angleOfBallShoot*3.1415/180)};
    double initialVelocityInXDirection{initialVelocity*cos(angleOfBallShoot*3.1415/180)};
    double fluidDensity{1.16};
    double previousVelocityInXDirection = initialVelocityInXDirection;
    double previousVelocityInYDirection = initialVelocityInYDirection;
    double mass{1};

    virtual void operator()(osg::Node* node, osg::NodeVisitor* nv)
    {
        if(resetProgram==false)
        {
            initialXPosition = -7.0;
            initialYPosition = -8.0;
            totalTime = 0.0;
            resetProgram = true;
            velocity = initialVelocity;
            initialVelocityInYDirection = initialVelocity*sin(angleOfBallShoot*3.1415/180);
            initialVelocityInXDirection = initialVelocity*cos(angleOfBallShoot*3.1415/180);
        }

        else if(resetBallInY)
        {
            initialXPosition = position_using_gravity_as_only_body_force(0,totalTime,initialVelocityInXDirection,initialXPosition);
            initialYPosition = -8.0;
            velocity = velocity*coefficientOfRestitution;
            initialVelocityInYDirection = velocity*sin(angleOfBallShoot*3.1415/180);
            initialVelocityInXDirection = velocity*cos(angleOfBallShoot*3.1415/180);
            totalTime = 0.0;
            if (velocity < 0.01)
                velocity = 0;
        }

        else
        {
            totalTime = totalTime + (1.0/30.0);
        }

        previousVelocityInXDirection = calculate_ball_velocity(mass,0,previousVelocityInXDirection,totalTime,fluidDensity,initialVelocityInXDirection);
        previousVelocityInYDirection = calculate_ball_velocity(mass,gravity,previousVelocityInYDirection,totalTime,fluidDensity,initialVelocityInYDirection);

        locationInTheYDirection = position_using_gravity_as_only_body_force(gravity,totalTime,initialVelocityInYDirection,initialYPosition);
        locationInTheXDirection = position_using_gravity_as_only_body_force(0,totalTime,initialVelocityInXDirection,initialXPosition);
        osg::Vec3 position(locationInTheXDirection, 0.f, locationInTheYDirection);
        osg::PositionAttitudeTransform *pat = dynamic_cast<osg::PositionAttitudeTransform *> (node);
        pat->setPosition(position);

//        traverse(node, nv);

        if(locationInTheYDirection<-8.0)
            resetBallInY = true;
        else
            resetBallInY = false;
    }
protected:
    bool resetBallInY{false};
    bool resetBallInX{false};
    unsigned int mCount{0};
    double totalTime{0.0};


};

#endif // SPHEREUPDATECALLBACK_H
