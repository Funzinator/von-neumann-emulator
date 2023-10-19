#include "ENTIRE.h"

ENTIRE::ENTIRE(RawOperation *rawOp) : ConvertOperation(rawOp)
{
    /* nichts zu tun */
}

void ENTIRE::run(Configuration *c)
{
    c->getAC()->setInt(c->getAC()->getFloat() < 0 ? ceil(c->getAC()->getFloat()) : c->getAC()->getFloat());
    c->setPC(c->getPC() + 1);
}
