#include "GuiInterface.h"

GuiInterface::GuiInterface(QMainWindow *MainWindow) : CommunicationInterface()
{
    this->MainWindow = MainWindow;
    
    QObject::connect(this, SIGNAL(stop(QString)), this->MainWindow, SLOT(stop(QString)));
    QObject::connect(this, SIGNAL(halt(QString)), this->MainWindow, SLOT(halt(QString)));
}

void GuiInterface::sendSignal(unsigned char signal)
{
    this->sendSignal(signal, "");
}

void GuiInterface::sendSignal(unsigned char signal, QString message)
{
    switch (signal)
    {
        case CommunicationInterface::STP:
            emit stop(message);
            break;

        default:
        case CommunicationInterface::HLT:
            emit halt(message);
            break;    
    }
}

void GuiInterface::sendString(QString message)
{
    /* wird später durch Ausgabeband ersetzt */
    QMessageBox::information(this->MainWindow,
                             "Ausgabe",
                             message,
                             QMessageBox::Ok);
}

int GuiInterface::receiveInteger()
{
    bool ok = false;
    int res;
    
    do
    {
        res = QInputDialog::getInteger(this->MainWindow,
                                       "Eingabe",
                                       "Integerwert:",
                                       0,           /* Voreinstellung */
                                       -2147483647, /* Minimum */
                                       2147483647,  /* Maximum */
                                       1,           /* Schrittweite */
                                       &ok);
    } while (ok == false);
    
    return res;
}

double GuiInterface::receiveFloat()
{
    bool ok = false;
    double res;
    
    do
    {
        res = QInputDialog::getDouble(this->MainWindow,
                                     "Eingabe",
                                     "Integerwert:",
                                     0,           /* Voreinstellung */
                                     -2147483647, /* Minimum */
                                     2147483647,  /* Maximum */
                                     10,           /* Maximale Anzahl Nachkommastellen */
                                     &ok);
    } while (ok == false);
    
    return res;
}

int GuiInterface::receiveBinary()
{
    return this->receiveInteger(); /* vielleicht mal ändern */
}
