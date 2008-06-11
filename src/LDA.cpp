#include "LDA.h"

LDA::LDA(RawOperation *rawOp) : IndirectOperation(rawOp)
{
    /*nichts zu tun*/
}

void LDA::run(Configuration *c)
{
    StorageCell* p1=IndirectToDirect(c); // in p1 steht nun der "echte" Wert.
    switch(c->getData(p1->getInt())->getType()){
        case StorageCell::Binary:
            c->getAC()->setBinary(c->getData(p1->getInt())->getBinary());
            break;
        case StorageCell::Integer:
            c->getAC()->setInt(c->getData(p1->getInt())->getInt());
            break;
        case StorageCell::Float:
            c->getAC()->setFloat(c->getData(p1->getInt())->getFloat());
            break;
    }
    c->setPC(c->getPC() + 1);
    delete p1;
}
