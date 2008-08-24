#include "INR.h"

INR::INR(RawOperation *rawOp) : InputOperation(rawOp)
{
    /* nichts zu tun */
}

void INR::run(Configuration *c)
{
    try
    {
        c->getAC()->setFloat(c->getInterface()->receiveFloat());
        c->setPC(c->getPC() + 1);
    }
    catch (char *e)
    {
        c->getInterface()->sendSignal(CommunicationInterface::HLT, e);
    }
}
