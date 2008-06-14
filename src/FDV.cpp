#include "FDV.h"

FDV::FDV(RawOperation *rawOp) : FloatOperation(rawOp)
{
    /*nichts zu tun*/
}

void FDV::run(Configuration *c)
{
    StorageCell *p1=setP1(c);  // in p1 steht nun der "echte" Wert.
    if (c->getData(p1->getInt())->getFloat() != 0 )
    {
        c->getAC()->setFloat(
            c->getAC()->getFloat()
            / c->getData(p1->getInt())->getFloat());
    } else
    {
        c->getInterface()->sendSignal(CommunicationInterface::HLT, "Division durch Null");
    }
    c->setPC(c->getPC() + 1);
    delete p1;
}
