#include "FSB.h"

FSB::FSB(RawOperation *rawOp) : FloatOperation(rawOp)
{
    /*nichts zu tun*/
}

void FSB::run(Configuration *c)
{
    IndirectToDirect(); // in Param1 steht nun der "echte" Wert.
    c->getAC()->setFloat(
        c->getAC()->getFloat()
        - c->Data[this->Param1->getInt()]->getFloat());
}
