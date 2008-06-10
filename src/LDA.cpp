#include "LDA.h"

LDA::LDA(RawOperation *rawOp) : IndirectOperation(rawOp)
{
    /*nichts zu tun*/
}

void LDA::run(Configuration *c)
{
    IndirectToDirect(c); // in Param1 steht nun der "echte" Wert.
    switch(c->getData(this->Param1->getInt())->getType()){
        case StorageCell::Binary:
            c->getAC()->setBinary(c->getData(this->Param1->getInt())->getBinary());
            break;
        case StorageCell::Integer:
            c->getAC()->setInt(c->getData(this->Param1->getInt())->getInt());
            break;
        case StorageCell::Float:
            c->getAC()->setFloat(c->getData(this->Param1->getInt())->getFloat());
            break;
    }
    c->setPC(c->getPC() + 1);
}
