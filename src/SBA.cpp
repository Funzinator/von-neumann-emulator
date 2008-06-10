#include "SBA.h"

SBA::SBA(RawOperation *rawOp) : IntegerOperation(rawOp)
{
    /*nichts zu tun*/
}

void SBA::run(Configuration *c)
{
    IndirectToDirect(); // in Param1 steht nun der "echte" Wert.
    c->getAC()->setInt(
        c->getAC()->getInt()
        - c->Data[this->Param1->getInt()]->getInt());
}
