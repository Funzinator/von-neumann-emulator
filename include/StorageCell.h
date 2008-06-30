#ifndef STORAGECELL_H_
#define STORAGECELL_H_

#include "Storage.h"

class StorageCell
{
private:
    Storage values;
    unsigned char type;
public:
    static const unsigned char Unused  = 0;
    static const unsigned char Integer = 1;
    static const unsigned char Float   = 2;
    static const unsigned char Binary  = 3;

    StorageCell();

    void setBinary(int);
    void setInt(int);
    void setFloat(double);

    int getBinary();
    int getInt();
    double getFloat();
    unsigned char getType();
};

#endif /*STORAGECELL_H_*/
