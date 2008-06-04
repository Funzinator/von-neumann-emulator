#include "StorageCell.h"

StorageCell::StorageCell()
{
    this->values.i = this->values.f = 0;
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