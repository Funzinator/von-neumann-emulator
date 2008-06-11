#include "SRJ.h"

SRJ::SRJ(RawOperation *rawOp) : IndirectOperation(rawOp)
{
    /*nichts zu tun*/
}

void SRJ::run(Configuration *c)
{
    StorageCell *p1=setP1(c);  // in p1 steht nun der "echte" Wert.
    c->setSR(c->getPC() + 1);
    c->setPC(p1->getInt());
    delete p1;
}
