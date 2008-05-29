#ifndef STORAGECELL_H_
#define STORAGECELL_H_

#include "Storage.h"

class StorageCell
{
private:
    static const unsigned char Integer = 1;
    static const unsigned char Float   = 2;
    static const unsigned char Binary  = 3;
    
    Storage values;
    unsigned char last_used;
public:
    StorageCell();

    void setBinary(int);
    void setInt(int);
    void setFloat(double);

    int getBinary();
    int getInt();
    double getFloat();
};

#endif /*STORAGECELL_H_*/
