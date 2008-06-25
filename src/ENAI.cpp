#include "ENAI.h"

ENAI::ENAI(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
    /*nichts zu tun*/
}

void ENAI::run(Configuration *c)
{
    StorageCell *p1 = IndirectToDirect(c); //in p1 ist jetzt der "echte" Wert

    // ENAI X: Lade AC mit Inhalt von Indexregister X	
    switch (c->getIndexRegister(p1->getInt())->getType())
    {
        case StorageCell::Binary:
            c->getAC()->setBinary(
                c->getIndexRegister(p1->getInt())->getBinary());
            break;
        case StorageCell::Integer:
            c->getAC()->setInt(
                c->getIndexRegister(p1->getInt())->getInt());
            break;
        case StorageCell::Float:
            c->getAC()->setFloat(
                c->getIndexRegister(p1->getInt())->getFloat());
            break;
    }
    c->setPC(c->getPC() + 1);
    delete p1;
}
