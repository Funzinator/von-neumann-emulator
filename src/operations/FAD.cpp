#include "FAD.h"

FAD::FAD(RawOperation *rawOp) : FloatOperation(rawOp)
{
    /* nichts zu tun */
}

void FAD::run(Configuration *c)
{
    StorageCell *p1 = this->setP1(c);

    if (p1)
    {
        c->getAC()->setFloat(c->getData(p1->getInt())->getFloat() + c->getAC()->getFloat());
        c->setPC(c->getPC() + 1);
    }

    delete p1;
}
