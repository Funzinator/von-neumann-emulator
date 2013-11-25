#include "ADI.h"

ADI::ADI(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
    /* nichts zu tun */
}

void ADI::run(Configuration *c)
{
    StorageCell *p1 = this->IndirectToDirect(c);

    if (c->getIndexRegister(p1->getInt()))
    {
        c->getIndexRegister(p1->getInt())->setInt(c->getAC()->getInt() + c->getIndexRegister(p1->getInt())->getInt());
        c->setPC(c->getPC() + 1);
    }

    delete p1;	
}
