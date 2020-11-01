#include "mainwindow.h"
#include "ui_mainwindowform.h"
#include "osgwidget.h"
#include "SphereUpdateCallback.h"

#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent},
    mMainWindowUI{new Ui::MainWindowForm}
{
    mMainWindowUI->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete mMainWindowUI;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_horizontalScrollBarChangeCoefficientOfRestitution_valueChanged(int value)
{
    OSGWidget *osgWidget = qobject_cast<OSGWidget *>(findChild<QObject *>("widget"));
    osgWidget->newBall.coefficientOfRestitution = value/100.0;
}

void MainWindow::on_horizontalScrollBarChangeInitialVelocity_valueChanged(int value)
{
    OSGWidget *osgWidget = qobject_cast<OSGWidget *>(findChild<QObject *>("widget"));
    osgWidget->newBall.initialVelocity = value/1.0;
}


void MainWindow::on_horizontalScrollBarChangeBallSize_valueChanged(int value)
{
    OSGWidget *osgWidget = qobject_cast<OSGWidget *>(findChild<QObject *>("widget"));
    osgWidget->newBall.ballSize = value/10.0;
}
