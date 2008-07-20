#include "RIN.h"

RIN::RIN(RawOperation *rawOp) : ConvertOperation(rawOp)
{
    /* nichts zu tun */
}

void RIN::run(Configuration *c)
{
    if (floor(c->getAC()->getFloat()) == c->getAC()->getFloat())
    {
        c->getAC()->setInt(c->getAC()->getFloat());
    }
    else
    {
        c->getInterface()->sendSignal(CommunicationInterface::HLT, "conversion failed");
    }
    c->setPC(c->getPC() + 1);
}
