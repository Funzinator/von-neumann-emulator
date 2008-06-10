#include "DVA.h"

DVA::DVA(RawOperation *rawOp) : IntegerOperation(rawOp)
{
    /*nichts zu tun*/
}

void DVA::run(Configuration *c)
{
    IndirectToDirect(c); // in Param1 steht nun der "echte" Wert.
    if (c->getData(this->Param1->getInt())->getInt() != 0)
    {
        c->getAC()->setInt(
            c->getAC()->getInt()
            / c->getData(this->Param1->getInt())->getInt());
    } else
    {
        //irgendeine Exception
    }
    c->setPC(c->getPC() + 1);
}
