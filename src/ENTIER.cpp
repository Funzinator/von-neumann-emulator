#include "ENTIER.h"

ENTIER::ENTIER(RawOperation *rawOp) : ConvertOperation(rawOp)
{
    /*nichts zu tun*/
}

void ENTIER::run(Configuration *c)
{
    c->getAC()->setInt(
        //( x > 0 ? abrunden(x) : abrunden(x) -1 )
        (c->getAC()->getFloat() > 0 ? 
            (int) c->getAC()->getFloat() :
            (int) c->getAC()->getFloat() -1 )
        );
    c->setPC(c->getPC() +1);
}
