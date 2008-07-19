#include "HLT.h"

HLT::HLT(RawOperation *rawOp) : NullaryOperation(rawOp)
{
    /* nichts zu tun */
}

void HLT::run(Configuration *c)
{
    c->getInterface()->sendSignal(CommunicationInterface::HLT);
}
