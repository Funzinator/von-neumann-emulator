#include "ENAI.h"

ENAI::ENAI(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
    /* nichts zu tun */
}

void ENAI::run(Configuration *c)
{
    StorageCell *p1 = this->IndirectToDirect(c);
	
    c->getAC()->setInt(c->getIndexRegister(p1->getInt())->getInt());
    c->setPC(c->getPC() + 1);

    delete p1;
}
