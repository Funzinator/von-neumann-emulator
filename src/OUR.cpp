#include "OUR.h"

OUR::OUR(RawOperation *rawOp) : OutputOperation(rawOp)
{
    /* nichts zu tun */
}

void OUR::run(Configuration *c)
{
    QString tmp = "%1";

    c->getInterface()->sendString(tmp.arg(c->getAC()->getFloat()));
    c->setPC(c->getPC() + 1);
}
