#include "ENAI.h"

ENAI::ENAI(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
    /*nichts zu tun*/
}

void ENAI::run(Configuration *c)
{
    StorageCell *p1 = IndirectToDirect(c); //in p1 ist jetzt der "echte" Wert
    // ENAI X: Lade AC mit Inhalt von Indexregister X	
    c->getAC()->setInt(c->getIndexRegister(p1->getInt())->getInt());
    c->setPC(c->getPC() + 1);
    delete p1;
}
