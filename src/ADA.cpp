#include "ADA.h"

ADA::ADA(RawOperation *rawOp) : IntegerOperation(rawOp)
{
    /*nichts zu tun*/
}

void ADA::run(Configuration *c)
{
    IndirectToDirect(c); // in Param1 steht nun der "echte" Wert.
    c->getAC()->setInt(
        c->getData(this->Param1->getInt())->getInt()
        + c->getAC()->getInt());
}
