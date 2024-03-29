#include "StorageCell.h"

StorageCell::StorageCell()
{
    this->values.i = this->values.f = 0;
    this->type = StorageCell::Unused;
}

void StorageCell::setBinary(QString s)
{
    // Eingabe ist s="101010", gespeichert wird values.i = 42
    int i = 0;
    int w = 1;

    for (int bit=s.size()-1; bit>=0 ; bit--)
    {
        i += w * QString(1,s[bit]).toInt();
        w *= 2;
    }

    this->values.i = i;
    this->type = StorageCell::Binary;
}

void StorageCell::setInt(qint32 i)
{
    this->values.i = i;
    this->type = StorageCell::Integer;
}

void StorageCell::setFloat(float f)
{
    this->values.f = f;
    this->type = StorageCell::Float;
}

void StorageCell::setRaw(Storage values, const unsigned char type)
{
    this->values = values;

    switch (type)
    {
        case StorageCell::Integer:
        case StorageCell::Float:
        case StorageCell::Binary:
            this->type = type;
            break;

        default:
            this->type = StorageCell::Unused;
            break;
    }
}

QString StorageCell::getBinary()
{
    QString bin;

    bin.setNum(this->values.i, 2);

    return bin;
}

qint32 StorageCell::getInt()
{
    return this->values.i;
}

float StorageCell::getFloat()
{
    return this->values.f;
}

Storage StorageCell::getRaw()
{
    return this->values;
}

unsigned char StorageCell::getType()
{
	return this->type;
}
