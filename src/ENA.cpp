#include "ENA.h"

ENA::ENA(RawOperation *rawOp) : BinaryOperation(rawOp)
{
    /* Dank ENAR kann ich erst hier die Parameter setzen */
    this->Param1 = new StorageCell;
    this->Param1->setInt(rawOp->Param1.toInt());
}

void ENA::run(Configuration *c)
{
    c->getAC()->setInt(this->Param1->getInt());
    c->setPC(c->getPC() + 1);
}
