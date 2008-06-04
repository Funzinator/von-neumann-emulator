#include "ENAI.h"

ENAI::ENAI(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
    /*nichts zu tun*/
}

void ENAI::run(Configuration *c)
{   // ENAI X: Lade AC mit Inhalt von Indexregister X	
    switch (c->getIndexRegister(this->Param1->getInt())->getType())
    {
        case StorageCell::Binary:
            c->getAC()->setBinary(
                c->getIndexRegister(this->Param1->getInt())->getBinary());
            break;
        case StorageCell::Integer:
            c->getAC()->setInt(
                c->getIndexRegister(this->Param1->getInt())->getInt());
            break;
        case StorageCell::Float:
            c->getAC()->setFloat(
                c->getIndexRegister(this->Param1->getInt())->getFloat());
            break;
    }
}
