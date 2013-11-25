#include "MUA.h"

MUA::MUA(RawOperation *rawOp) : IntegerOperation(rawOp)
{
    /* nichts zu tun */
}

void MUA::run(Configuration *c)
{
    StorageCell *p1 = this->setP1(c);

    if (p1)
    {
        c->getAC()->setInt(c->getAC()->getInt() * c->getData(p1->getInt())->getInt());
        c->setPC(c->getPC() + 1);
    }

    delete p1;
}
