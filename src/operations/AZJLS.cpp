#include "AZJLS.h"

AZJLS::AZJLS(RawOperation *rawOp) : CompareOperation(rawOp)
{
    /* nichts zu tun */
}

void AZJLS::run(Configuration *c)
{
    StorageCell *p1 = this->setP1(c);

    if (p1)
    {
        c->setPC(c->getAC()->getInt() < 0 ? p1->getInt() : c->getPC() + 1);
    }

    delete p1;
}
