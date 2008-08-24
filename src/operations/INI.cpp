#include "INI.h"

INI::INI(RawOperation *rawOp) : InputOperation(rawOp)
{
    /* nichts zu tun */
}

void INI::run(Configuration *c)
{
    try
    {
        c->getAC()->setInt(c->getInterface()->receiveInteger());
        c->setPC(c->getPC() + 1);
    }
    catch (char *e)
    {
        c->getInterface()->sendSignal(CommunicationInterface::HLT, e);
    }
}
