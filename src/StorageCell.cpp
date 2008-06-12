#include "StorageCell.h"

StorageCell::StorageCell()
{
    this->values.i = this->values.f = 0;
    this->type = StorageCell::Integer;
}

void StorageCell::setBinary(int i)
{
    this->values.i = i;
    this->type = StorageCell::Binary;
}

void StorageCell::setInt(int i)
{
    this->values.i = i;
    this->type = StorageCell::Integer;
}

void StorageCell::setFloat(double f)
{
    this->values.f = f;
    this->type = StorageCell::Float;
}

int StorageCell::getBinary()
{
    return this->values.i;
}

int StorageCell::getInt()
{
    return this->values.i;
}

double StorageCell::getFloat()
{
    return this->values.f;
}

unsigned char StorageCell::getType()
{
	return this->type;
}

void StorageCell::show()
{
    switch (this->type)
    {
        case StorageCell::Binary:
            std::cout << this->values.i << " (B)";
            break;
            
        case StorageCell::Integer:
            std::cout << this->values.i << " (I)";
            break;
            
        case StorageCell::Float:
            std::cout << this->values.f << " (F)";
            break;
            
        default: /* FIXME (im Konstruktor) */
            std::cout << "null";
    }
    std::cout << std::endl; 
}
