#include "INB.h"

INB::INB(RawOperation *rawOp) : InputOperation(rawOp)
{
    /* nichts zu tun */
}

void INB::run(Configuration *c)
{
    c->getAC()->setBinary(c->getInterface()->receiveBinary());
    c->setPC(c->getPC() + 1);
}
