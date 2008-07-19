#include "ENAR.h"

ENAR::ENAR(RawOperation *rawOp) : UnaryOperation(rawOp)
{
    this->Param1 = new StorageCell;
    this->Param1->setFloat(rawOp->Param1.toFloat());
}

void ENAR::run(Configuration *c)
{
    /* um einheitlich zu bleiben, hier auch p1 statt Param1 verwenden */
    StorageCell *p1 = new StorageCell;

    p1->setFloat(this->Param1->getFloat());	

    c->getAC()->setFloat(p1->getFloat());
    c->setPC(c->getPC() + 1);

    delete p1;
}
