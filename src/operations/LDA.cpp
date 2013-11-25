#include "LDA.h"

LDA::LDA(RawOperation *rawOp) : IndirectOperation(rawOp)
{
    /* nichts zu tun */
}

void LDA::run(Configuration *c)
{
    StorageCell *p1 = this->setP1(c);

    if (p1)
    {
        c->getAC()->setRaw(c->getData(p1->getInt())->getRaw(), c->getData(p1->getInt())->getType());
        c->setPC(c->getPC() + 1);
    }

    delete p1;
}
