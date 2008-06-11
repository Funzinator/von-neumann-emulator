#include "FSB.h"

FSB::FSB(RawOperation *rawOp) : FloatOperation(rawOp)
{
    /*nichts zu tun*/
}

void FSB::run(Configuration *c)
{
    StorageCell *p1=setP1(c);  // in p1 steht nun der "echte" Wert.
    c->getAC()->setFloat(
        c->getAC()->getFloat()
        - c->getData(p1->getInt())->getFloat());
    c->setPC(c->getPC() + 1);
    delete p1;
}
