#include "INR.h"

INR::INR(RawOperation *rawOp) : InputOperation(rawOp)
{
    /* nichts zu tun */
}

void INR::run(Configuration *c)
{
    FloatResult val = c->getInterface()->receiveFloat();
    bool ok = std::get<1>(val);

    if (ok)
    {
        c->getAC()->setFloat(std::get<0>(val));
        c->setPC(c->getPC() + 1);
    }
}
