#include "StorageCell.h"

StorageCell::StorageCell()
{
    this->values.i = this->values.f = 0;
    this->type = StorageCell::Unused;
}

void StorageCell::setBinary(QString s)
{
    // Eingabe ist s="101010", gespeichert wird values.i = 42
    int i=0;
    int w=1;
    for (int bit=s.size()-1; bit>=0 ; bit--){
        i+= QString(1,s[bit]).toInt() *w;
        w*=2;
    }
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

QString StorageCell::getBinary()
{
    QString bin;
    bin.setNum(this->values.i,2);
    return bin;
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
