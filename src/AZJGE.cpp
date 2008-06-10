#include "AZJGE.h"

AZJGE::AZJGE(RawOperation *rawOp) : CompareOperation(rawOp)
{
    /*nichts zu tun*/
}

void AZJGE::run(Configuration *c)
{
    IndirectToDirect(c); // in Param1 steht nun der "echte" Wert.
    (c->getAC()->getInt() >= 0 ? c->setPC(this->Param1->getInt()) : c->setPC(c->getPC() +1));
}
