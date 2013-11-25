#include "STA.h"

STA::STA(RawOperation *rawOp) : IndirectOperation(rawOp)
{
    /* nichts zu tun */
}

void STA::run(Configuration *c)
{
    StorageCell *p1 = this->setP1(c);

    if (p1)
    {
        c->getData(p1->getInt())->setRaw(c->getAC()->getRaw(), c->getAC()->getType());
        c->setPC(c->getPC() + 1);
    }

    delete p1;
}
