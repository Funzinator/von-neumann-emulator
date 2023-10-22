#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QTextStream>
#include <QFileDialog>
#include <QTimer>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDate>

#include <ctime>

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
#ifndef Q_OS_WASM
    int saveChanges();
#endif
    void showConfiguration(Configuration *);
    void resetConfiguration();
    QTimer *timerRun;
    unsigned char waitForInputState;

    Interpreter *i;
    Parser *parser;
    QFile *file;

    QRegularExpression *inputRegExp;

    Highlighter *highlighter;

    AboutDialog *aboutDialog;

#if QT_VERSION >= 0x060500
    Qt::ColorScheme colorScheme;
#endif

    static const unsigned short int MaxVisibleStack = 4;

protected:
#ifndef Q_OS_WASM
    void closeEvent(QCloseEvent *);
#endif

public:
#if QT_VERSION >= 0x060500
    MainWindow(Qt::ColorScheme);
#else
    MainWindow();
#endif
    ~MainWindow();

public slots:
    void on_toolBtnNext_clicked();
    void on_toolBtnPause_clicked();
    void on_toolBtnPlay_clicked();
    void on_toolBtnStop_clicked();
#ifndef Q_OS_WASM
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
#endif
    void on_actionAbout_triggered();
    void on_txtEditSourcecode_textChanged();
    void on_lineEditInput_returnPressed();
    void on_toolBtnNumber_clicked();
    void on_toolBtnClearInput_clicked();
    void on_toolBtnOpenInput_clicked();

    void timerNextStep();

    void stop(QString);
    void halt(QString);
    void requestInput(QString);
};

#endif /*MAINWINDOW_H_*/
