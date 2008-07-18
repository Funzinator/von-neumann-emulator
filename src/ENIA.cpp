#include "ENIA.h"

ENIA::ENIA(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
    /*nichts zu tun*/
}

void ENIA::run(Configuration *c)
{
    StorageCell *p1 = IndirectToDirect(c); //in p1 ist jetzt der "echte" Wert
    // ENIA X: Lade Indexregister X mit Inhalt von AC	
    c->getIndexRegister(p1->getInt())->setInt(c->getAC()->getInt());
    c->setPC(c->getPC() + 1);
    delete p1;
}
