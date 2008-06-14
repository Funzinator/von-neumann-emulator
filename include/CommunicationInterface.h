#ifndef COMMUNICATIONINTERFACE_H_
#define COMMUNICATIONINTERFACE_H_

#include <QString>

class CommunicationInterface
{
public:
    CommunicationInterface();
    
    static const unsigned char STP = 1;
    static const unsigned char HLT = 1;
    
    virtual void sendSignal(unsigned char) = 0;
    virtual void sendSignal(unsigned char, QString) = 0;
    virtual void sendString(QString) = 0;
    virtual QString receiveString() = 0;
};

#endif /*COMMUNICATIONINTERFACE_H_*/
