#include "NOP.h"

NOP::NOP(RawOperation *rawOp) : NullaryOperation(rawOp)
{
    /*nichts zu tun*/
}

void NOP::run(Configuration *c)
{
    c->setPC(c->getPC() + 1);
}
