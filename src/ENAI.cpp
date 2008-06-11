#include "ENAI.h"

ENAI::ENAI(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
    /*nichts zu tun*/
}

void ENAI::run(Configuration *c)
{
    //Um einheitlich zu bleiben, hier auch p1 statt Param1 verwenden
    StorageCell *p1 = new StorageCell;
    p1->setInt(this->Param1->getInt());	

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
