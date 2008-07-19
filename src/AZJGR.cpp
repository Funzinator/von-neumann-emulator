#include "AZJGR.h"

AZJGR::AZJGR(RawOperation *rawOp) : CompareOperation(rawOp)
{
    /* nichts zu tun */
}

void AZJGR::run(Configuration *c)
{
    StorageCell *p1 = this->setP1(c);

    c->setPC(c->getAC()->getInt() > 0 ? p1->getInt() : c->getPC() + 1);

    delete p1;
}
