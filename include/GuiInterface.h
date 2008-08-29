#ifndef GUIINTERFACE_H_
#define GUIINTERFACE_H_

#include <QMainWindow>
#include <QListWidget>

#include "CommunicationInterface.h"
#include "DialogInputBinary.h"
#include "DialogInputFloat.h"
#include "DialogInputInteger.h"

//! Kommunikationsschnittstelle zwischen Interpreter und grafischer Oberfläche
/*!
 * diese Klasse implementiert CommunicationInterface für die grafische
 * Oberfläche.
 */
class GuiInterface : public CommunicationInterface
{
    Q_OBJECT

private:
    QMainWindow *MainWindow;
    QListWidget *listWidgetInput;
    QListWidget *listWidgetOutput;

    QRegExp *regExpBinary;
    QRegExp *regExpFloat;
    QRegExp *regExpInteger;

public:
    /*!
     * \param Hauptfenster
     * \param Eingabeband
     * \param Ausgabeband
     */
    GuiInterface(QMainWindow*, QListWidget*, QListWidget*);

    /*!
     * \sa CommunicationInterface::sendSignal()
     */
    void sendSignal(unsigned char);

    /*!
     * \sa CommunicationInterface::sendSignal()
     */
    void sendSignal(unsigned char, QString);

    /*!
     * \sa CommunicationInterface::sendString()
     */
    void sendString(QString);

    /*!
     * \sa CommunicationInterface::receiveInteger()
     */
    int receiveInteger();

    /*!
     * \sa CommunicationInterface::receiveFloat()
     */
    double receiveFloat();

    /*!
     * \sa CommunicationInterface::receiveBinary()
     */
    QString receiveBinary();
    
signals:
    void halt(QString);
    void stop(QString);
};

#endif /*GUIINTERFACE_H_*/
