#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QTimer>
#include <QMainWindow>
#include "ui_MainWindow.h"

#include "Interpreter.h"

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

private:
    Interpreter *i;
    void showConfiguration(Configuration *);
    void resetConfiguration();
    QTimer *timerRun;

public:
    MainWindow();
    
public slots:
    void on_toolBtnNext_clicked();
    void on_toolBtnPause_clicked();
    void on_toolBtnPlay_clicked();
    void on_toolBtnStop_clicked();
    
    void timerNextStep();
};

#endif /*MAINWINDOW_H_*/
