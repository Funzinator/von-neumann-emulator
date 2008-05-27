#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <map>

#include "StorageCell.h"

class Configuration
{
private:
    StorageCell *AC; /* Akkumulator       */
    unsigned int PC; /* Befehlszähler     */
    unsigned int SR; /* Subroutine-Zeiger */
    std::map<unsigned int,StorageCell *> Data;
    std::map<unsigned int,StorageCell *> IndexRegister;
    
public:
    Configuration();

    StorageCell* getAC();
    unsigned int getPC();
    unsigned int getSR();

    StorageCell* getData(unsigned int);
    StorageCell* getIndexRegister(unsigned int);

    void setPC(unsigned int);
    void setSR(unsigned int);  
};

#endif /*CONFIGURATION_H_*/
