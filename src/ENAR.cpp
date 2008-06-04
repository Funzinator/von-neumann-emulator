#include "ENAR.h"

ENAR::ENAR(RawOperation *rawOp) : UnaryOperation(rawOp)
{
    /* Dank ENAR kann ich erst hier die Parameter setzen */
    this->Param1 = new StorageCell;
    this->Param1->setFloat(rawOp->Param1.toFloat());
}

void ENAR::run(Configuration *c)
{
    c->getAC()->setFloat(this->Param1->getFloat());
    c->setPC(c->getPC() + 1);
}
