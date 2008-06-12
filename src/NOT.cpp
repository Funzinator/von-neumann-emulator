#include "NOT.h"

NOT::NOT(RawOperation *rawOp) : NegateOperation(rawOp)
{
    /*nichts zu tun*/
}

void NOT::run(Configuration *c)
{
    c->getAC()->setInt( ~ c->getAC()->getInt());
    c->setPC(c->getPC() +1 );
}
