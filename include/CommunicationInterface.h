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

    //! sendet ein Signal an die Oberfläche
    /*!
     * \param signal Stop- oder Halt-Signal
     */
    virtual void sendSignal(unsigned char signal) = 0;

    //! sendet ein Signal an die Oberfläche
    /*!
     * \param signal Stop- oder Halt-Signal
     * \param message Fehlermeldung
     */
    virtual void sendSignal(unsigned char signal, QString message ) = 0;

    //! sendet eine Ausgabe an die Oberfläche
    /*!
     * \param message Ausgabe
     */  
    virtual void sendString(QString message) = 0;

    //! fordert eine Festpunktzahl von der Oberfläche an
    /*!
     * \return Festpunktzahl
     */
    virtual qint32 receiveInteger() = 0;

    //! fordert eine Gleitpunktzahl von der Oberfläche an
    /*!
     * \return Gleitpunktzahl
     */
    virtual float receiveFloat() = 0;

    //! fordert einen Binärwert von der Oberfläche an
    /*!
     * \return Binärwert
     */
    virtual QString receiveBinary() = 0;
};

#endif /*COMMUNICATIONINTERFACE_H_*/
