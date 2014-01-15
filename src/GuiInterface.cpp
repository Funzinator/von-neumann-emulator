#include "GuiInterface.h"

GuiInterface::GuiInterface(QMainWindow *MainWindow, QListWidget *listWidgetInput, QListWidget *listWidgetOutput) : CommunicationInterface()
{
    this->MainWindow = MainWindow;
    this->listWidgetInput = listWidgetInput;
    this->listWidgetOutput = listWidgetOutput;

    this->regExpBinary = 0;
    this->regExpInteger = 0;
    this->regExpFloat = 0;

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
    int res = 0;

    if (this->listWidgetInput->count())
    {
        if (!this->regExpInteger)
        {
            this->regExpInteger = new QRegExp("[-+]?[0-9]+");
        }

        QListWidgetItem *item = this->listWidgetInput->takeItem(0);
        if (this->regExpInteger->exactMatch(item->text()))
        {
            res = item->text().toInt();
            delete item;
        }
        else
        {
            delete item;
            this->sendSignal(CommunicationInterface::HLT, "input error: invalid integer value");
        }
    }
    else
    {
        DialogInputInteger dialog("Eingabe", QString::fromUtf8("Integerwert:"), this->MainWindow);

        this->MainWindow->setEnabled(false);

        if (dialog.exec())
        {
            res = dialog.lineEditInput->text().toInt();
        }
        else
        {
            this->sendSignal(CommunicationInterface::HLT, "input error: no input");
        }

        this->MainWindow->setEnabled(true);
    }

    return res;
}

double GuiInterface::receiveFloat()
{
    double res = 0;

    if (this->listWidgetInput->count())
    {
        if (!this->regExpFloat)
        {
            this->regExpFloat = new QRegExp("[-+]?([0-9]*\\.?[0-9]*)");
        }

        QListWidgetItem *item = this->listWidgetInput->takeItem(0);
        if (this->regExpFloat->exactMatch(item->text()))
        {
            res = item->text().toDouble();
            delete item;
        }
        else
        {
            delete item;
            this->sendSignal(CommunicationInterface::HLT, "input error: invalid double value");
        }
    }
    else
    {
        DialogInputFloat dialog("Eingabe", QString::fromUtf8("Doublewert:"), this->MainWindow);

        this->MainWindow->setEnabled(false);

        if (dialog.exec())
        {
            res = dialog.lineEditInput->text().toDouble();
        }
        else
        {
            this->sendSignal(CommunicationInterface::HLT, "input error: no input");
        }

        this->MainWindow->setEnabled(true);
    }

    return res;
}

QString GuiInterface::receiveBinary()
{
    QString res;

    if (this->listWidgetInput->count())
    {
        if (!this->regExpBinary)
        {
            this->regExpBinary = new QRegExp("[01]+");
        }

        QListWidgetItem *item = this->listWidgetInput->takeItem(0);
        if (this->regExpBinary->exactMatch(item->text()))
        {
            res = item->text();
            delete item;
        }
        else
        {
            delete item;
            this->sendSignal(CommunicationInterface::HLT, "input error: invalid binary value");
        }
    }
    else
    {
        DialogInputBinary dialog("Eingabe", QString::fromUtf8("Binärwert:"), this->MainWindow);

        this->MainWindow->setEnabled(false);

        if (dialog.exec())
        {
            res = dialog.lineEditInput->text();
        }
        else
        {
            this->sendSignal(CommunicationInterface::HLT, "input error: no input");
        }

        this->MainWindow->setEnabled(true);
    }

    return res;
}
