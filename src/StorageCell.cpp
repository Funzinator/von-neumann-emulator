#include "StorageCell.h"

StorageCell::StorageCell()
{
    this->values.i = this->values.f = 0;
}

void StorageCell::setInt(int i)
{
    this->values.i = i;
}

void StorageCell::setFloat(double f)
{
    this->values.f = f;
}

int StorageCell::getInt()
{
    return this->values.i;
}

double StorageCell::getFloat()
{
    return this->values.f;
}
