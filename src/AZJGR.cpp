#include "AZJGR.h"

AZJGR::AZJGR(RawOperation *rawOp) : CompareOperation(rawOp)
{
    /*nichts zu tun*/
}

void AZJGR::run(Configuration *c)
{
    StorageCell *p1=setP1(c);  // in p1 steht nun der "echte" Wert.
    c->setPC(c->getAC()->getInt() > 0 ? p1->getInt() : c->getPC() +1);
    delete p1;
}
