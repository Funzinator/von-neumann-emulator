#ifndef COMMUNICATIONINTERFACE_H_
#define COMMUNICATIONINTERFACE_H_

#include <QObject>
#include <QString>
#include <tuple>

typedef std::tuple<qint32, bool> IntResult;
typedef std::tuple<float, bool> FloatResult;
typedef std::tuple<QString, bool> BinaryResult;

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
    static const unsigned char REQUEST_INPUT = 3;

    static const unsigned char STATE_NO_WAIT = 0;
    static const unsigned char STATE_WAIT_STEP = 1;
    static const unsigned char STATE_WAIT_RUN = 2;

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
    virtual IntResult receiveInteger() = 0;

    //! fordert eine Gleitpunktzahl von der Oberfläche an
    /*!
     * \return Gleitpunktzahl
     */
    virtual FloatResult receiveFloat() = 0;

    //! fordert einen Binärwert von der Oberfläche an
    /*!
     * \return Binärwert
     */
    virtual BinaryResult receiveBinary() = 0;
};

#endif /*COMMUNICATIONINTERFACE_H_*/
