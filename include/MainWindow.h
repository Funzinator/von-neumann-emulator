#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QTextStream>
#include <QFileDialog>
#include <QTimer>
#include <QMessageBox>

#include "ui_MainWindow.h"

#include "Interpreter.h"
#include "Parser.h"
#include "GuiInterface.h"
#include "Highlighter.h"
#include "AboutDialog.h"

#define INPUT_REGEXP "[-+]?([0-9]+|[0-9]*\\.[0-9]*)"

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

    QRegExp *inputRegExp;

    Highlighter *highlighter;

    AboutDialog *aboutDialog;

public:
    MainWindow();
    ~MainWindow();

public slots:
    void on_toolBtnNext_clicked();
    void on_toolBtnPause_clicked();
    void on_toolBtnPlay_clicked();
    void on_toolBtnStop_clicked();
    void on_actionNew_activated();
    void on_actionOpen_activated();
    void on_actionSave_activated();
    void on_actionSaveAs_activated();
    void on_actionAbout_activated();
    void on_txtEditSourcecode_textChanged();
    void on_lineEditInput_returnPressed();
    void on_toolBtnNumber_clicked();
    void on_toolBtnClearInput_clicked();
    void on_toolBtnOpenInput_clicked();

    void timerNextStep();

    void stop(QString);
    void halt(QString);
};

#endif /*MAINWINDOW_H_*/
