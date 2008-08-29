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
    DialogInputInteger dialog("Eingabe", QString::fromUtf8("Integerwert:"), this->MainWindow);

    if (dialog.exec())
    {
        return dialog.lineEditInput->text().toInt();
    }
    else
    {
        throw "input error";
    }
}

double GuiInterface::receiveFloat()
{
    DialogInputFloat dialog("Eingabe", QString::fromUtf8("Doublewert:"), this->MainWindow);

    if (dialog.exec())
    {
        return dialog.lineEditInput->text().toDouble();
    }
    else
    {
        throw "input error";
    }
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
