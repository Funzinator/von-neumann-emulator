#include "UJP.h"

UJP::UJP(RawOperation *rawOp) : ControlOperation(rawOp)
{
    /* nichts zu tun */
}

void UJP::run(Configuration *c)
{
    StorageCell *p1 = this->setP1(c);

    c->setPC(p1->getInt());

    delete p1;
}
