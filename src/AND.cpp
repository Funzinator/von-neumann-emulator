#include "AND.h"

AND::AND(RawOperation *rawOp) : LogicOperation(rawOp)
{
    /*nichts zu tun*/
}

void AND::run(Configuration *c)
{
    StorageCell *p1=setP1(c);  // in p1 steht nun der "echte" Wert.
    c->getAC()->setBinary(c->getAC()->getBinary() & p1->getBinary());
    c->setPC(c->getPC() + 1);
}
