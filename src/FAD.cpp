#include "FAD.h"

FAD::FAD(RawOperation *rawOp) : FloatOperation(rawOp)
{
    /*nichts zu tun*/
}

void FAD::run(Configuration *c)
{
    IndirectToDirect(); // in Param1 steht nun der "echte" Wert.
    c->getAC()->setFloat(
        c->Data[this->Param1->getInt()]->getFloat()
        + c->getAC()->getFloat());
}
