#ifndef SPHEREUPDATECALLBACK_H
#define SPHEREUPDATECALLBACK_H

#include "OSGWidget.h"
#include "PhysicsLibrary.hpp"

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
public slots:
    void setCOR(int value)
    {
        coefficientOfRestitution = value;
    }

public:
    SphereUpdateCallback(){}


    virtual void operator()(osg::Node* node, osg::NodeVisitor* nv)
    {
        if(resetBall)
        {
            totalTime = 0.0;
            initialVelocity = initialVelocity*coefficientOfRestitution;
        }

        else
        {
            totalTime = totalTime + (1.0/30.0);
        }

        location = position_using_gravity_as_only_body_force(gravity,totalTime,initialVelocity,initialPosition);
        osg::Vec3 position(0.f, 0.f, location);
        osg::PositionAttitudeTransform *pat = dynamic_cast<osg::PositionAttitudeTransform *> (node);
        pat->setPosition(position);

//        traverse(node, nv);

        if(location<-10.0)
            resetBall = true;
        else
            resetBall = false;
    }
protected:
    bool resetBall{false};
    unsigned int mCount{0};
    double totalTime{0.0};
    double gravity{-9.8};
    double initialVelocity{18.0};
    double initialPosition{-10.0};
    double location{0.0};
    double coefficientOfRestitution{0.8};
};

#endif // SPHEREUPDATECALLBACK_H
