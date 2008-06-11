#include "FDV.h"

FDV::FDV(RawOperation *rawOp) : FloatOperation(rawOp)
{
    /*nichts zu tun*/
}

void FDV::run(Configuration *c)
{
    StorageCell* p1=IndirectToDirect(c); // in Param1 steht nun der "echte" Wert.
    if (c->getData(p1->getInt())->getFloat() != 0 )
    {
        c->getAC()->setFloat(
            c->getAC()->getFloat()
            / c->getData(p1->getInt())->getFloat());
    } else
    {
        //irgendeine Exception 
    }
    c->setPC(c->getPC() + 1);
    delete p1;
}
