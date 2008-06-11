#include "STA.h"

STA::STA(RawOperation *rawOp) : IndirectOperation(rawOp)
{
    /*nichts zu tun*/
}

void STA::run(Configuration *c)
{
    StorageCell *p1=setP1(c);  // in p1 steht nun der "echte" Wert. 

    switch(c->getAC()->getType()){
        case StorageCell::Binary:
            c->getData(p1->getInt())->setBinary(c->getAC()->getBinary());
            break;
        case StorageCell::Integer:
            c->getData(p1->getInt())->setInt(c->getAC()->getInt());
            break;
        case StorageCell::Float:
            c->getData(p1->getInt())->setFloat(c->getAC()->getFloat());
            break;
    }
    c->setPC(c->getPC() + 1);
    delete p1;
}
