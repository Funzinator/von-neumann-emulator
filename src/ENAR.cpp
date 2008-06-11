#include "ENAR.h"

ENAR::ENAR(RawOperation *rawOp) : UnaryOperation(rawOp)
{
    /* Dank ENAR kann ich erst hier die Parameter setzen */
    this->Param1 = new StorageCell;
    this->Param1->setFloat(rawOp->Param1.toFloat());
}

void ENAR::run(Configuration *c)
{
    //Um einheitlich zu bleiben, hier auch p1 statt Param1 verwenden
    StorageCell *p1 = new StorageCell;
    p1->setFloat(this->Param1->getFloat()); //ENAR hat Float!	

    c->getAC()->setFloat(p1->getFloat());
    c->setPC(c->getPC() + 1);
    delete p1;
}
