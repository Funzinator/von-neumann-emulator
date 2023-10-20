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
    connect(this, SIGNAL(requestInput(QString)), this->MainWindow, SLOT(requestInput(QString)));
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

        case CommunicationInterface::REQUEST_INPUT:
            emit requestInput(message);
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

IntResult GuiInterface::receiveInteger()
{
    qint32 res = 0;
    bool ok = false;

    if (this->listWidgetInput->count())
    {
        if (!this->regExpInteger)
        {
            this->regExpInteger = new QRegularExpression("^[-+]?[0-9]+$");
        }

        QListWidgetItem *item = this->listWidgetInput->takeItem(0);
        if (this->regExpInteger->match(item->text()).hasMatch())
        {
            res = (qint32) item->text().toInt();
            ok = true;
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
#ifdef Q_OS_WASM
        this->sendSignal(CommunicationInterface::REQUEST_INPUT, "integer");
#else
        DialogInputInteger dialog("Eingabe", QString::fromUtf8("Integerwert:"), this->MainWindow);

        this->MainWindow->setEnabled(false);

        if (dialog.exec())
        {
            res = (qint32) dialog.lineEditInput->text().toInt();
            ok = true;
        }
        else
        {
            this->sendSignal(CommunicationInterface::HLT, "input error: no input");
        }

        this->MainWindow->setEnabled(true);
#endif
    }

    return std::make_tuple(res, ok);
}

FloatResult GuiInterface::receiveFloat()
{
    float res = 0;
    bool ok = false;

    if (this->listWidgetInput->count())
    {
        if (!this->regExpFloat)
        {
            this->regExpFloat = new QRegularExpression("^[-+]?([0-9]*\\.?[0-9]*)$");
        }

        QListWidgetItem *item = this->listWidgetInput->takeItem(0);
        if (this->regExpFloat->match(item->text()).hasMatch())
        {
            res = item->text().toFloat();
            ok = true;
            delete item;
        }
        else
        {
            delete item;
            this->sendSignal(CommunicationInterface::HLT, "input error: invalid float value");
        }
    }
    else
    {
#ifdef Q_OS_WASM
        this->sendSignal(CommunicationInterface::REQUEST_INPUT, "float");
#else
        DialogInputFloat dialog("Eingabe", QString::fromUtf8("Floatwert:"), this->MainWindow);

        this->MainWindow->setEnabled(false);

        if (dialog.exec())
        {
            res = dialog.lineEditInput->text().toFloat();
            ok = true;
        }
        else
        {
            this->sendSignal(CommunicationInterface::HLT, "input error: no input");
        }

        this->MainWindow->setEnabled(true);
#endif
    }

    return std::make_tuple(res, ok);
}

BinaryResult GuiInterface::receiveBinary()
{
    QString res;
    bool ok = false;

    if (this->listWidgetInput->count())
    {
        if (!this->regExpBinary)
        {
            this->regExpBinary = new QRegularExpression("^[01]+$");
        }

        QListWidgetItem *item = this->listWidgetInput->takeItem(0);
        if (this->regExpBinary->match(item->text()).hasMatch())
        {
            res = item->text();
            ok = true;
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
#ifdef Q_OS_WASM
        this->sendSignal(CommunicationInterface::REQUEST_INPUT, "binary");
#else
        DialogInputBinary dialog("Eingabe", QString::fromUtf8("Binärwert:"), this->MainWindow);

        this->MainWindow->setEnabled(false);

        if (dialog.exec())
        {
            res = dialog.lineEditInput->text();
            ok = true;
        }
        else
        {
            this->sendSignal(CommunicationInterface::HLT, "input error: no input");
        }

        this->MainWindow->setEnabled(true);
#endif
    }

    return std::make_tuple(res, ok);
}
