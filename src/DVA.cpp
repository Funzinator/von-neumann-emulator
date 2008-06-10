#include "DVA.h"

DVA::DVA(RawOperation *rawOp) : IntegerOperation(rawOp)
{
    /*nichts zu tun*/
}

void DVA::run(Configuration *c)
{
    IndirectToDirect(); // in Param1 steht nun der "echte" Wert.
    if (c->Data[this->Param1->getInt()]->getInt() != 0)
    {
        c->getAC()->setInt(
            c->getAC()->getInt()
            / c->Data[this->Param1->getInt()]->getInt());
    } else
    {
        //irgendeine Exception
    }
}
