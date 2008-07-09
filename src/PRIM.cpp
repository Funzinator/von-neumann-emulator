#include "PRIM.h"

PRIM::PRIM(RawOperation *rawOp) : NullaryOperation(rawOp)
{
    /*nichts zu tun*/
}

bool PRIM::prim(int x){
//die ersten Fälle abfangen
    switch (x){
    case 0:
    case 1: return false;
    case 2:
    case 3:
    case 5:
    case 7:
    case 11:
    case 13:
    case 17:
    case 19:
    case 23:
    case 29: return true;
    }
    if (!(x%2)) return false;
    if (!(x%3)) return false;
    if (!(x%5)) return false;
    if (!(x%7)) return false;
    if (!(x%11)) return false;
    if (!(x%13)) return false;
    if (!(x%17)) return false;
    if (!(x%19)) return false;
    if (!(x%23)) return false;
    if (!(x%29)) return false;
//die ersten Fälle abgefangen

    for (int t=31; t*t <= x; t=t+2){
        if (!(x%t)) return false;
    }

    return true;

}

void PRIM::run(Configuration *c)
{
    if (prim(c->getAC()->getInt())) c->getAC()->setInt(1);
    else c->getAC()->setInt(0);
    c->setPC(c->getPC() + 1);
}
