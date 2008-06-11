#include "UJP.h"

UJP::UJP(RawOperation *rawOp) : ControlOperation(rawOp)
{
    /*nichts zu tun*/
}

void UJP::run(Configuration *c)
{
    StorageCell *p1=setP1(c);  // in p1 steht nun der "echte" Wert.
    c->setPC(p1->getInt());
    delete p1;
}
