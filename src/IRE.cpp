#include "IRE.h"

IRE::IRE(RawOperation *rawOp) : ConvertOperation(rawOp)
{
    /* nichts zu tun */
}

void IRE::run(Configuration *c)
{
    c->getAC()->setFloat(c->getAC()->getInt());
    c->setPC(c->getPC() + 1);
}
