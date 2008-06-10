#include "UJP.h"

UJP::UJP(RawOperation *rawOp) : ControlOperation(rawOp)
{
    /*nichts zu tun*/
}

void UJP::run(Configuration *c)
{
    IndirectToDirect(c); // in Param1 steht nun der "echte" Wert.
    c->setPC(this->Param1->getInt());
}
