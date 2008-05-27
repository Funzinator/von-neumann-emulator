#ifndef STORAGECELL_H_
#define STORAGECELL_H_

#include "Storage.h"

class StorageCell
{
private:
    Storage values;
public:
    StorageCell();

    void setInt(int);
    void setFloat(double);

    int getInt();
    double getFloat();
};

#endif /*STORAGECELL_H_*/
