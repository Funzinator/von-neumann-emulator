#include "SRJ.h"

SRJ::SRJ(RawOperation *rawOp) : IndirectOperation(rawOp)
{
    /*nichts zu tun*/
}

void SRJ::run(Configuration *c)
{
    IndirectToDirect(c); // in Param1 steht nun der "echte" Wert.
    c->setSR(c->getPC() + 1);
    c->setPC(this->Param1->getInt());
}
