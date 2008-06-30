#ifndef CLI_H_
#define CLI_H_

#include <QFile>
#include <QTimer>
#include <QString>
#include <QThread>
#include <string>

#include "Interpreter.h"
#include "Parser.h"
#include "Configuration.h"
#include "CliInterface.h"

class CLI : public QThread
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
    void run();
    CLI(QString);
    
public slots:
    
    void timerNextStep();
    
    void stop(QString);
    void halt(QString);
};

#endif /*CLI_H_*/
