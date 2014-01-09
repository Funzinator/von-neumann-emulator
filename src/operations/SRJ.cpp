#include "SRJ.h"

SRJ::SRJ(RawOperation *rawOp) : IndirectOperation(rawOp)
{
    /* nichts zu tun */
}

void SRJ::run(Configuration *c)
{
    StorageCell *p1 = this->setP1(c);

    if (p1)
    {
        c->pushSR(c->getPC() + 1);
        c->setPC(p1->getInt());
    }

    delete p1;
}
