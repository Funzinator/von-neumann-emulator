#ifndef COMMUNICATIONINTERFACE_H_
#define COMMUNICATIONINTERFACE_H_

#include <QObject>
#include <QString>

//! Kommunikationsschnittstelle zwischen Interpreter und Oberfläche
/*!
 * Abstrakte Schnittstelle, die erlaubt Signale und Ausgaben an die Oberfläche
 * zu senden und Eingaben von der Oberfläche anzufordern.
 */
class CommunicationInterface : public QObject
{
public:
    CommunicationInterface();
    
    static const unsigned char STP = 1;
    static const unsigned char HLT = 2;
    
    virtual void sendSignal(unsigned char) = 0;
    virtual void sendSignal(unsigned char, QString) = 0;
    virtual void sendString(QString) = 0;
    virtual int receiveInteger() = 0;
    virtual double receiveFloat() = 0;
    virtual QString receiveBinary() = 0;
};

#endif /*COMMUNICATIONINTERFACE_H_*/
