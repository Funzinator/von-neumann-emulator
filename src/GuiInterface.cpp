#include "GuiInterface.h"

GuiInterface::GuiInterface(QMainWindow *MainWindow, QListWidget *listWidgetInput, QListWidget *listWidgetOutput) : CommunicationInterface()
{
    this->MainWindow = MainWindow;
    this->listWidgetInput = listWidgetInput;
    this->listWidgetOutput = listWidgetOutput; 

    connect(this, SIGNAL(stop(QString)), this->MainWindow, SLOT(stop(QString)));
    connect(this, SIGNAL(halt(QString)), this->MainWindow, SLOT(halt(QString)));
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
    this->listWidgetOutput->addItem(message);
}

int GuiInterface::receiveInteger()
{
    int res;

    if (this->listWidgetInput->count())
    {
        QListWidgetItem *item = this->listWidgetInput->takeItem(0); 
        res = item->text().toInt();
        delete item;
    }
    else
    {
        bool ok = false;

        res = QInputDialog::getInteger(this->MainWindow,
                                       "Eingabe",
                                       "Integerwert:",
                                       0,           /* Voreinstellung */
                                       -2147483647, /* Minimum */
                                       2147483647,  /* Maximum */
                                       1,           /* Schrittweite */
                                       &ok);

        if(!ok)
        {
            throw "input error";
        }
    }

    return res;
}

double GuiInterface::receiveFloat()
{
    double res;

    if (this->listWidgetInput->count())
    {
        QListWidgetItem *item = this->listWidgetInput->takeItem(0); 
        res = item->text().toDouble();
        delete item;
    }
    else
    {
        bool ok = false;
        
        res = QInputDialog::getDouble(this->MainWindow,
                                      "Eingabe",
                                      "Doublewert:",
                                      0,            /* Voreinstellung */
                                      -2147483647,  /* Minimum */
                                      2147483647,   /* Maximum */
                                      10,           /* Maximale Anzahl Nachkommastellen */
                                      &ok);

        if(!ok)
        {
            throw "input error";
        }
    }

    return res;
}

QString GuiInterface::receiveBinary()
{
    DialogInputBinary dialog("Eingabe", QString::fromUtf8("Binärwert:"), this->MainWindow);

    if (dialog.exec())
    {
        return dialog.lineEditInput->text();
    }
    else
    {
        throw "input error";
    }
}
