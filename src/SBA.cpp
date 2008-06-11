#include "SBA.h"

SBA::SBA(RawOperation *rawOp) : IntegerOperation(rawOp)
{
    /*nichts zu tun*/
}

void SBA::run(Configuration *c)
{
    StorageCell* p1=IndirectToDirect(c); // in p1 steht nun der "echte" Wert.
    c->getAC()->setInt(
        c->getAC()->getInt()
        - c->getData(p1->getInt())->getInt());
    c->setPC(c->getPC() + 1);
    delete p1;
}
