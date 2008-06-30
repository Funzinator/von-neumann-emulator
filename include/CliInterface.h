#ifndef CLIINTERFACE_H_
#define CLIINTERFACE_H_

#include <iostream>
#include <QString>

#include "CommunicationInterface.h"

class CliInterface : public CommunicationInterface
{
    Q_OBJECT

public:
    CliInterface();
    
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
