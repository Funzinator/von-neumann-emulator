#include "AZJNE.h"

AZJNE::AZJNE(RawOperation *rawOp) : CompareOperation(rawOp)
{
    /*nichts zu tun*/
}

void AZJNE::run(Configuration *c)
{
    StorageCell *p1=setP1(c);  // in p1 steht nun der "echte" Wert.
    (c->getAC()->getInt() != 0 ? c->setPC(p1->getInt()) : c->setPC(c->getPC() +1));
    delete p1;
}
