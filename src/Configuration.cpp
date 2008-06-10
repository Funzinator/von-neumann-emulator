#include "Configuration.h"

Configuration::Configuration()
{
	this->IndexRegister.resize(15);
	
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

/*! deprecated! 
 * nur zum kurzen Testen!
 */
void Configuration::show()
{
    std::cout << "AC: ";
    this->AC->show();
    
    std::cout << "PC: " << this->PC << std::endl;
    std::cout << "SR: " << this->SR << std::endl;
    
    std::cout << "Indexregister" << std::endl;
    for (int i = 0; i < this->IndexRegister.size(); i++)
    {
        if (this->IndexRegister[i])
        {
            this->IndexRegister[i]->show();
        }
    }
    
    std::cout << "Daten" << std::endl;
    QMapIterator<unsigned int, StorageCell *> j(this->Data);
    while (j.hasNext())
    {
        j.next();
        j.value()->show();
    }
}
