cmake_minimum_required(VERSION 3.10)

project(BallFountain)

FIND_PACKAGE(Qt5Widgets)
FIND_PACKAGE(Qt5Gui)
FIND_PACKAGE(OpenSceneGraph REQUIRED COMPONENTS osgDB osgGA osgUtil osgViewer osgText)

INCLUDE_DIRECTORIES( ${OPENSCENEGRAPH_INCLUDE_DIRS} )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED 1)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTORCC ON)

FIND_PACKAGE(GTEST REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#Physics Library
add_library(${PROJECT_NAME}_LIBRARIES STATIC
    PhysicsLibrary.hpp
    PhysicsLibrary.cpp
    )

#Physics Library unit test executable
add_executable(${PROJECT_NAME}_unit_tests
    PhysicsLibraryTests.cpp
    )

target_link_libraries(${PROJECT_NAME}_unit_tests
    ${GTEST_LIBRARIES}
    ${GTEST_MAIN_LIBRARIES}
    ${PROJECT_NAME}_LIBRARIES
)

#Qt and OSG Application
add_executable(${PROJECT_NAME}
     main.cpp
     mainwindow.cpp
     mainwindow.h
     mainwindowform.ui
     osgwidget.h
     osgwidget.cpp
    )

target_link_libraries(${PROJECT_NAME}
    ${OPENSCENEGRAPH_LIBRARIES}
    Qt5::Widgets
    Qt5::Gui
    ${PROJECT_NAME}_LIBRARIES
)
