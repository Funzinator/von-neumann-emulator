#include "Configuration.h"

Configuration::Configuration()
{
    this->AC = new StorageCell;
    this->PC = 0;
    this->SR = 0;
}

StorageCell* Configuration::getAC()
{
    return this->AC;
}

unsigned int Configuration::getPC()
{
    return this->PC;
}

unsigned int Configuration::getSR()
{
    return this->SR;
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
    if (this->IndexRegister[x] == 0)
    {
        this->IndexRegister[x] = new StorageCell;
    }

    return this->IndexRegister[x];
}

void Configuration::setPC(unsigned int i)
{
    this->PC = i;
}

void Configuration::setSR(unsigned int i)
{
    this->SR = i;
}
