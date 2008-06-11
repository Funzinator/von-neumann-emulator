#include "AZJLS.h"

AZJLS::AZJLS(RawOperation *rawOp) : CompareOperation(rawOp)
{
    /*nichts zu tun*/
}

void AZJLS::run(Configuration *c)
{
    StorageCell* p1=IndirectToDirect(c); // in p1 steht nun der "echte" Wert.
    (c->getAC()->getInt() < 0 ? c->setPC(p1->getInt()) : c->setPC(c->getPC() +1));
    delete p1;
}
