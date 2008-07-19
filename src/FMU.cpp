#include "FMU.h"

FMU::FMU(RawOperation *rawOp) : FloatOperation(rawOp)
{
    /* nichts zu tun */
}

void FMU::run(Configuration *c)
{
    StorageCell *p1 = this->setP1(c);

    c->getAC()->setFloat(c->getAC()->getFloat() * c->getData(p1->getInt())->getFloat());
    c->setPC(c->getPC() + 1);

    delete p1;
}
