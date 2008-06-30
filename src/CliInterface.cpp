#include "CliInterface.h"

CliInterface::CliInterface() : CommunicationInterface()
{
}

void CliInterface::sendSignal(unsigned char signal)
{
    this->sendSignal(signal, "");
}

void CliInterface::sendSignal(unsigned char signal, QString message)
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

void CliInterface::sendString(QString message)
{
    std::cout << message.toStdString();
}

int CliInterface::receiveInteger()
{
    std::cout << "Integer-Wert eingeben: ";
    int res; std::cin >> res;
    return res;
}

double CliInterface::receiveFloat()
{
    std::cout << "Float-Wert eingeben: ";
    float res; std::cin >> res;
    return res;
}

int CliInterface::receiveBinary()
{
    return this->receiveInteger(); /* vielleicht mal ändern */
}
