#include "SRR.h"

SRR::SRR(RawOperation *rawOp) : NullaryOperation(rawOp)
{
    /* nichts zu tun */
}

void SRR::run(Configuration *c)
{
    if (c->isEmptySR())
    {
        c->getInterface()->sendSignal(CommunicationInterface::HLT, "subroutine stack empty");
    }
    else
    {
        c->setPC(c->popSR());
    }
}
