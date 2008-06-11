#include "DVA.h"

DVA::DVA(RawOperation *rawOp) : IntegerOperation(rawOp)
{
    /*nichts zu tun*/
}

void DVA::run(Configuration *c)
{
    StorageCell *p1=setP1(c);  // in p1 steht nun der "echte" Wert.
    if (c->getData(p1->getInt())->getInt() != 0)
    {
        c->getAC()->setInt(
            c->getAC()->getInt()
            / c->getData(p1->getInt())->getInt());
    } else
    {
        //irgendeine Exception
    }
    c->setPC(c->getPC() + 1);
    delete p1;
}
