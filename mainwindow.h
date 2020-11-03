#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>

class OutputWindow;


namespace Ui {
class MainWindowForm;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_actionExit_triggered();

private slots:
    void on_horizontalScrollBarChangeCoefficientOfRestitution_valueChanged(int value);

    void on_horizontalScrollBarChangeInitialVelocity_valueChanged(int value);
    void on_horizontalScrollBarChangeBallSize_valueChanged(int value);

    void on_pushButtonResetProgram_clicked(bool checked);

    void on_horizontalScrollBarInitialShootingAngle_valueChanged(int value);

private:
    Ui::MainWindowForm *mMainWindowUI;

};

#endif // MAINWINDOW_H
