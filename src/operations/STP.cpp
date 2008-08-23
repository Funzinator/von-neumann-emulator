#include "STP.h"

STP::STP(RawOperation *rawOp) : NullaryOperation(rawOp)
{
    /* nichts zu tun */
}

void STP::run(Configuration *c)
{
    c->getInterface()->sendSignal(CommunicationInterface::STP);
}
