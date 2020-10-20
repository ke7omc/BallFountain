cmake_minimum_required(VERSION 3.4)
project(BallFountain)

FIND_PACKAGE(Qt5Widgets)
FIND_PACKAGE(Qt5Gui)
FIND_PACKAGE(OpenSceneGraph REQUIRED COMPONENTS osgDB osgGA osgUtil osgViewer osgText)
FIND_PACKAGE(GTest REQUIRED)


INCLUDE_DIRECTORIES( ${OPENSCENEGRAPH_INCLUDE_DIRS} ${GTEST_INCLUDE_DIRS})
INCLUDE(GoogleTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED 1)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTORCC ON)


set(MYSOURCE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindowform.ui
    osgwidget.h
    osgwidget.cpp
    )

add_executable(${PROJECT_NAME}
    ${MYSOURCE}
    )

add_library(${PROJECT_NAME}_LIBRARIES STATIC
    PhysicsLibrary.hpp
    PhysicsLibrary.cpp
    )


#SET(TEST_NAME ${PROJECT_NAME}_UnitTest)

#add_executable(${TEST_Name}
#    PhysicsLibraryTests.cpp
#    )

target_link_libraries(${PROJECT_NAME}
    ${OPENSCENEGRAPH_LIBRARIES}
    ${GTEST_LIBRARIES}
    ${GTEST_MAIN_LIBRARIES}
    Qt5::Widgets
    Qt5::Gui
)
