#include "AND.h"

AND::AND(RawOperation *rawOp) : LogicOperation(rawOp)
{
    /* nichts zu tun */
}

void AND::run(Configuration *c)
{
    StorageCell *p1 = this->setP1(c);

    c->getAC()->setInt(c->getAC()->getInt() & p1->getInt());
    c->setPC(c->getPC() + 1);

    delete p1;
}
