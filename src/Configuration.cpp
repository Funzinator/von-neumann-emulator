#include "Configuration.h"

Configuration::Configuration(CommunicationInterface *Interface)
{
    this->IndexRegister.resize(Configuration::IndexRegisterCount);

    this->AC = new StorageCell;

    this->PC = 0;

    this->Interface = Interface;
}

Configuration::~Configuration()
{
    QVector<unsigned int> res;
    QMapIterator<unsigned int, StorageCell *> i(this->Data);

    while (i.hasNext())
    {
        i.next();
        delete i.value();
    }

    delete this->AC;
}

StorageCell* Configuration::getAC()
{
    return this->AC;
}

unsigned int Configuration::getPC()
{
    return this->PC;
}

unsigned int Configuration::popSR()
{
    if (this->SRStack.isEmpty())
    {
        this->Interface->sendSignal(CommunicationInterface::HLT, "subroutine stack empty");
        return 0;
    }
    else
    {
        return this->SRStack.pop();
    }
}

bool Configuration::isEmptySR()
{
    return this->SRStack.isEmpty();
}

StorageCell* Configuration::getData(unsigned int x)
{
    if (this->Data[x] == 0)
    {
        this->Data[x] = new StorageCell;
    }

    return this->Data[x];
}

StorageCell* Configuration::getIndexRegister(unsigned int x)
{
    if (x < Configuration::IndexRegisterCount)
    {
        if (this->IndexRegister[x] == 0)
        {
            this->IndexRegister[x] = new StorageCell;
        }
        return this->IndexRegister[x];
    }
    else
    {
        this->Interface->sendSignal(CommunicationInterface::HLT, QString("only %1 index registers available").arg(Configuration::IndexRegisterCount));
        return 0;
    }
}

void Configuration::setPC(unsigned int i)
{
    this->PC = i;
}

void Configuration::pushSR(unsigned int i)
{
    this->SRStack.push(i);
}

QVector<unsigned int> Configuration::getUsedData()
{
    QVector<unsigned int> res;
    QMapIterator<unsigned int, StorageCell *> j(this->Data);

    while (j.hasNext())
    {
        j.next();
        res.append(j.key());
    }

    return res;
}

QVector<unsigned int> Configuration::getSRStackContent()
{
    return QVector<unsigned int>(this->SRStack);
}

CommunicationInterface* Configuration::getInterface()
{
    return this->Interface;
}
