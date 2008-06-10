#include "ENIA.h"

ENIA::ENIA(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
    /*nichts zu tun*/
}

void ENIA::run(Configuration *c)
{   // ENIA X: Lade Indexregister X mit Inhalt von AC	
    switch (c->getAC()->getType())
    {
        case StorageCell::Binary:
            c->getIndexRegister(this->Param1->getInt())->setBinary(
                c->getAC()->getBinary());
            break;
        case StorageCell::Integer:
            c->getIndexRegister(this->Param1->getInt())->setInt(
                c->getAC()->getInt());
            break;
        case StorageCell::Float:
            c->getIndexRegister(this->Param1->getInt())->setFloat(
                c->getAC()->getFloat());
            break;
    }
    c->setPC(c->getPC() + 1);
}
