#include "OUI.h"

OUI::OUI(RawOperation *rawOp) : OutputOperation(rawOp)
{
    /* nichts zu tun */
}

void OUI::run(Configuration *c)
{
    QString tmp = "%1";

    c->getInterface()->sendString(tmp.arg(c->getAC()->getInt()));
    c->setPC(c->getPC() + 1);
}
