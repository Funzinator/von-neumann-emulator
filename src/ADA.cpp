#include "ADA.h"

ADA::ADA(RawOperation *rawOp) : IntegerOperation(rawOp)
{
    /*nichts zu tun*/
}

void ADA::run(Configuration *c)
{
    StorageCell *p1=setP1(c);  // in p1 steht nun der "echte" Wert.
    c->getAC()->setInt(
        c->getData(p1->getInt())->getInt()
        + c->getAC()->getInt());
    c->setPC(c->getPC() + 1);
    delete p1;
}
