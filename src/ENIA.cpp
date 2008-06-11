#include "ENIA.h"

ENIA::ENIA(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
    /*nichts zu tun*/
}

void ENIA::run(Configuration *c)
{
    //Um einheitlich zu bleiben, hier auch p1 statt Param1 verwenden
    StorageCell *p1 = new StorageCell;
    p1->setInt(this->Param1->getInt());	

    // ENIA X: Lade Indexregister X mit Inhalt von AC	
    switch (c->getAC()->getType())
    {
        case StorageCell::Binary:
            c->getIndexRegister(p1->getInt())->setBinary(
                c->getAC()->getBinary());
            break;
        case StorageCell::Integer:
            c->getIndexRegister(p1->getInt())->setInt(
                c->getAC()->getInt());
            break;
        case StorageCell::Float:
            c->getIndexRegister(p1->getInt())->setFloat(
                c->getAC()->getFloat());
            break;
    }
    c->setPC(c->getPC() + 1);
    delete p1;
}
