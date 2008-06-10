#include "FNG.h"

FNG::FNG(RawOperation *rawOp) : NegateOperation(rawOp)
{
    /*nichts zu tun*/
}

void FNG::run(Configuration *c)
{
    c->getAC()->setFloat(c->getAC()->getFloat() * (-1) );
    c->setPC(c->getPC() +1 );
}
