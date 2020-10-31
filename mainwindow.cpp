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
    connect(mMainWindowUI->horizontalScrollBar,SIGNAL(valueChanged(int)),this,SLOT(setCOR(int)));
}

MainWindow::~MainWindow()
{
    delete mMainWindowUI;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();

}


