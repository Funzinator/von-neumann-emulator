#ifndef GUIINTERFACE_H_
#define GUIINTERFACE_H_

#include "CommunicationInterface.h"

class GuiInterface : public CommunicationInterface
{
public:
    GuiInterface();
    
    void sendSignal(unsigned char);
    void sendSignal(unsigned char, QString);
    void sendString(QString);
    QString receiveString();
};

#endif /*GUIINTERFACE_H_*/
