#include "SRR.h"

SRR::SRR(RawOperation *rawOp) : NullaryOperation(rawOp)
{
    /* nichts zu tun */
}

void SRR::run(Configuration *c)
{
    c->setPC(c->getSR());
}
