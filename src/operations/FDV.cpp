#include "FDV.h"

FDV::FDV(RawOperation *rawOp) : FloatOperation(rawOp)
{
    /* nichts zu tun */
}

void FDV::run(Configuration *c)
{
    StorageCell *p1 = this->setP1(c);

    if (p1)
    {
        if (c->getData(p1->getInt())->getFloat())
        {
            c->getAC()->setFloat(c->getAC()->getFloat() / c->getData(p1->getInt())->getFloat());
            c->setPC(c->getPC() + 1);
        }
        else
        {
            c->getInterface()->sendSignal(CommunicationInterface::HLT, "division by zero");
        }
    }

    delete p1;
}
