#include "MDA.h"

MDA::MDA(RawOperation *rawOp) : IntegerOperation(rawOp)
{
    /* nichts zu tun */
}

void MDA::run(Configuration *c)
{
    StorageCell *p1 = this->setP1(c);

    if (p1)
    {
        if (c->getData(p1->getInt())->getInt())
        {
            c->getAC()->setInt(c->getAC()->getInt() % c->getData(p1->getInt())->getInt());
            c->setPC(c->getPC() + 1);
        }
        else
        {
            c->getInterface()->sendSignal(CommunicationInterface::HLT, "division by zero");
        }
    }

    delete p1;
}
