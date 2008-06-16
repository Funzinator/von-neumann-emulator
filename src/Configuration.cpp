#include "Configuration.h"

Configuration::Configuration(CommunicationInterface *Interface)
{
	this->IndexRegister.resize(16);

    this->AC = new StorageCell;
    this->PC = 0;
    this->SR = 0;

    this->Interface = Interface;
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
	if (x < (unsigned int) this->IndexRegister.size())
	{
		if (this->IndexRegister[x] == 0)
		{
			this->IndexRegister[x] = new StorageCell;
		}
		
		return this->IndexRegister[x];
	}
	else
	{
		return 0;
	}
}

void Configuration::setPC(unsigned int i)
{
    this->PC = i;
}

void Configuration::setSR(unsigned int i)
{
    this->SR = i;
}

QVector<unsigned int> Configuration::getUsedData()
{
    QVector<unsigned int> res;
    
    QMapIterator<unsigned int, StorageCell *> j(this->Data);
    while (j.hasNext())
    {
        j.next();
        //std::cout << j.key() << ": ";
        //j.value()->show();
        res.append(j.key());
    }
    //std::cout << res.size() << std::endl;
    return res;
}

CommunicationInterface* Configuration::getInterface()
{
    return this->Interface;
}
