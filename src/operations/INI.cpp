#include "INI.h"

INI::INI(RawOperation *rawOp) : InputOperation(rawOp)
{
    /* nichts zu tun */
}

void INI::run(Configuration *c)
{
    IntResult val = c->getInterface()->receiveInteger();
    bool ok = std::get<1>(val);

    if (ok)
    {
        c->getAC()->setInt(std::get<0>(val));
        c->setPC(c->getPC() + 1);
    }
}
