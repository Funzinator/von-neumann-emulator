#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTimer>
#include <QString>
#include "ui_MainWindow.h"

#include "Interpreter.h"
#include "Parser.h"
#include "Configuration.h"
#include "GuiInterface.h"

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

private:
    void showConfiguration(Configuration *);
    void resetConfiguration();
    QTimer *timerRun;

    Interpreter *i;
    Parser *parser;
    QFile *file;

public:
    MainWindow();
    
public slots:
    void on_toolBtnNext_clicked();
    void on_toolBtnPause_clicked();
    void on_toolBtnPlay_clicked();
    void on_toolBtnStop_clicked();
    void on_actionOpen_activated();
    
    void timerNextStep();
    
    void stop(QString);
    void halt(QString);
};

#endif /*MAINWINDOW_H_*/
