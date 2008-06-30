#include "CliInterface.h"

CliInterface::CliInterface(QThread *Cli) : CommunicationInterface()
{
    this->Cli = Cli;

    QObject::connect(this, SIGNAL(stop(QString)), this->Cli, SLOT(stop(QString)));
    QObject::connect(this, SIGNAL(halt(QString)), this->Cli, SLOT(halt(QString)));
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
    std::cout << "Binaer-Wert eingeben: ";
    int i; std::cin >>i;
    // Eingabe ist int i = 101010, gebraucht wird res = 42
    int res=0;
    int w=1;
    while (i!=0) {
        if ( i%10 !=0 && i%10!=1)
            this->sendSignal(CommunicationInterface::HLT, "Ungueltige Eingabe. Nur 0 und 1 verwenden!");
        res+=(i%10)*w;
        i/=10;
        w*=2;
    }
    return res;
}
