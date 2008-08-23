#include "OR.h"

OR::OR(RawOperation *rawOp) : LogicOperation(rawOp)
{
    /* nichts zu tun */
}

void OR::run(Configuration *c)
{
    StorageCell *p1 = this->setP1(c);

    c->getAC()->setInt(c->getAC()->getInt() | p1->getInt());
    c->setPC(c->getPC() + 1);
}
