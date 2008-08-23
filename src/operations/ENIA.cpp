#include "ENIA.h"

ENIA::ENIA(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
    /* nichts zu tun */
}

void ENIA::run(Configuration *c)
{
    StorageCell *p1 = this->IndirectToDirect(c);

    c->getIndexRegister(p1->getInt())->setInt(c->getAC()->getInt());
    c->setPC(c->getPC() + 1);

    delete p1;
}
