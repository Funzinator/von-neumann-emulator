#include "FSB.h"

FSB::FSB(RawOperation *rawOp) : FloatOperation(rawOp)
{
    /* nichts zu tun */
}

void FSB::run(Configuration *c)
{
    StorageCell *p1 = this->setP1(c);

    if (p1)
    {
        c->getAC()->setFloat(c->getAC()->getFloat() - c->getData(p1->getInt())->getFloat());
        c->setPC(c->getPC() + 1);
    }

    delete p1;
}
