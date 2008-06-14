#include "RIN.h"

RIN::RIN(RawOperation *rawOp) : ConvertOperation(rawOp)
{
    /*nichts zu tun*/
}

void RIN::run(Configuration *c)
{
    if ((int) c->getAC()->getFloat() - c->getAC()->getFloat() == 0)
        c->getAC()->setInt( (int) c->getAC()->getFloat() );
    else
    {
        c->getInterface()->sendSignal(CommunicationInterface::HLT, "Umwandlung fehlgeschlagen");
    }
    c->setPC(c->getPC() +1);
}
