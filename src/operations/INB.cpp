#include "INB.h"

INB::INB(RawOperation *rawOp) : InputOperation(rawOp)
{
    /* nichts zu tun */
}

void INB::run(Configuration *c)
{
    BinaryResult val = c->getInterface()->receiveBinary();
    bool ok = std::get<1>(val);

    if (ok)
    {
        c->getAC()->setBinary(std::get<0>(val));
        c->setPC(c->getPC() + 1);
    }
}
