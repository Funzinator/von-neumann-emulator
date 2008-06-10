#include "STA.h"

STA::STA(RawOperation *rawOp) : IndirectOperation(rawOp)
{
    /*nichts zu tun*/
}

void STA::run(Configuration *c)
{
    IndirectToDirect(c); // in Param1 steht nun der "echte" Wert.
    switch(c->getAC()->getType()){
        case StorageCell::Binary:
            c->getData(this->Param1->getInt())->setBinary(c->getAC()->getBinary());
            break;
        case StorageCell::Integer:
            c->getData(this->Param1->getInt())->setInt(c->getAC()->getInt());
            break;
        case StorageCell::Float:
            c->getData(this->Param1->getInt())->setFloat(c->getAC()->getFloat());
            break;
    }
    c->setPC(c->getPC() + 1);
}
