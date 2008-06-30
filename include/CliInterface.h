#ifndef CLIINTERFACE_H_
#define CLIINTERFACE_H_

#include <iostream>
#include <QString>

#include "CommunicationInterface.h"
#include "CLI.h"

class CliInterface : public CommunicationInterface
{
    Q_OBJECT

private:
    QThread *Cli;
    
public:
    CliInterface(QThread *);
    
    void sendSignal(unsigned char);
    void sendSignal(unsigned char, QString);
    void sendString(QString);
    int receiveInteger();
    double receiveFloat();
    int receiveBinary();
    
signals:
    void halt(QString);
    void stop(QString);
};

#endif /*CLIINTERFACE_H_*/
