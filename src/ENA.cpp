#include "ENA.h"

ENA::ENA(RawOperation *rawOp) : UnaryOperation(rawOp)
{
    /* Dank ENAR kann ich erst hier die Parameter setzen */
    this->Param1 = new StorageCell;
    this->Param1->setInt(rawOp->Param1.toInt());
}

void ENA::run(Configuration *c)
{
    //Um einheitlich zu bleiben, hier auch p1 statt Param1 verwenden
    StorageCell *p1 = new StorageCell;
    p1->setInt(this->Param1->getInt());	

    c->getAC()->setInt(p1->getInt());
    c->setPC(c->getPC() + 1);
    delete p1;
}
