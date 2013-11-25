#include "ADA.h"

ADA::ADA(RawOperation *rawOp) : IntegerOperation(rawOp)
{
    /* nichts zu tun */
}

void ADA::run(Configuration *c)
{
    StorageCell *p1 = this->setP1(c);

    if (p1)
    {
        c->getAC()->setInt(c->getData(p1->getInt())->getInt() + c->getAC()->getInt());
        c->setPC(c->getPC() + 1);
    }

    delete p1;
}
