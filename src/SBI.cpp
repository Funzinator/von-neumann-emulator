#include "SBI.h"

SBI::SBI(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
    /*nichts zu tun*/
}

void SBI::run(Configuration *c)
{	
    StorageCell *p1 = IndirectToDirect(c); //in p1 ist jetzt der "echte" Wert
    // speichere IR_Inhalt-AC als Binary im IR
    c->getIndexRegister(p1->getInt())->setInt(
        c->getIndexRegister(p1->getInt())->getInt() - c->getAC()->getInt()); 
    c->setPC(c->getPC() + 1);
    delete p1;
}
