#include "FDV.h"

FDV::FDV(RawOperation *rawOp) : FloatOperation(rawOp)
{
    /*nichts zu tun*/
}

void FDV::run(Configuration *c)
{
    IndirectToDirect(c); // in Param1 steht nun der "echte" Wert.
    if (c->getData(this->Param1->getInt())->getFloat() != 0 )
    {
        c->getAC()->setFloat(
            c->getAC()->getFloat()
            / c->getData(this->Param1->getInt())->getFloat());
    } else
    {
        //irgendeine Exception 
    }
}
