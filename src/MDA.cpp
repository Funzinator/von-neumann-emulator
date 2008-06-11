#include "MDA.h"

MDA::MDA(RawOperation *rawOp) : IntegerOperation(rawOp)
{
    /*nichts zu tun*/
}

void MDA::run(Configuration *c)
{
    StorageCell *p1=setP1(c);  // in p1 steht nun der "echte" Wert.
    c->getAC()->setInt(
        c->getAC()->getInt()
        % c->getData(p1->getInt())->getInt());
    c->setPC(c->getPC() + 1);
    delete p1;
}
