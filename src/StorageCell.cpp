#include "StorageCell.h"

StorageCell::StorageCell()
{
    this->values.i = this->values.f = 0;
}

void StorageCell::setBinary(int i)
{
    this->values.i = i;
    this->last_used = StorageCell::Binary;
}

void StorageCell::setInt(int i)
{
    this->values.i = i;
    this->last_used = StorageCell::Integer;
}

void StorageCell::setFloat(double f)
{
    this->values.f = f;
    this->last_used = StorageCell::Float;
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
