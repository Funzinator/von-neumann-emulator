#include "OUB.h"

OUB::OUB(RawOperation *rawOp) : OutputOperation(rawOp)
{
    /* nichts zu tun */
}

void OUB::run(Configuration *c)
{
    QString tmp;
    tmp.setNum(c->getAC()->getInt(), 2);
    
    c->getInterface()->sendString(tmp);
    
    c->setPC(c->getPC() + 1);
}
