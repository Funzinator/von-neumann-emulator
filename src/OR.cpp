#include "OR.h"

OR::OR(RawOperation *rawOp) : LogicOperation(rawOp)
{
    /*nichts zu tun*/
}

void OR::run(Configuration *c)
{
    StorageCell *p1=setP1(c);  // in p1 steht nun der "echte" Wert.
    c->getAC()->setInt(c->getAC()->getInt() | p1->getInt());
    c->setPC(c->getPC() + 1);
}
