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
//    QObject::connect(mMainWindowUI->horizontalScrollBar,SIGNAL(valueChanged(int)),physrep.coefficientOfRestitution,SLOT(setCOR(int)));
}

MainWindow::~MainWindow()
{
    delete mMainWindowUI;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}



void MainWindow::on_horizontalScrollBar_valueChanged(int value)
{
    OSGWidget *osgWidget = qobject_cast<OSGWidget *>(findChild<QObject *>("widget"));
    osgWidget->newBall.coefficientOfRestitution = value/100.0;

}
