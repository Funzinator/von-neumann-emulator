#include "MUA.h"

MUA::MUA(RawOperation *rawOp) : IntegerOperation(rawOp)
{
    /*nichts zu tun*/
}

void MUA::run(Configuration *c)
{
    IndirectToDirect(); // in Param1 steht nun der "echte" Wert.
    c->getAC()->setInt(
        c->getAC()->getInt()
        * c->Data[this->Param1->getInt()]->getInt());
}
