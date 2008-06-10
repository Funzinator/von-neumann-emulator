#include "MUA.h"

MUA::MUA(RawOperation *rawOp) : IntegerOperation(rawOp)
{
    /*nichts zu tun*/
}

void MUA::run(Configuration *c)
{
    IndirectToDirect(c); // in Param1 steht nun der "echte" Wert.
    c->getAC()->setInt(
        c->getAC()->getInt()
        * c->getData(this->Param1->getInt())->getInt());
    c->setPC(c->getPC() + 1);
}
