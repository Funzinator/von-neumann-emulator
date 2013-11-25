#include "ENI.h"

ENI::ENI(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
    this->Param2 = new StorageCell;
    this->Param2->setInt(rawOp->Param2.toInt());
}

void ENI::run(Configuration *c)
{
    /* um einheitlich zu bleiben, hier auch p1 statt Param1 verwenden */
    StorageCell *p1 = new StorageCell;

    p1->setInt(this->Param1->getInt());	

    if (c->getIndexRegister(p1->getInt()))
    {
        c->getIndexRegister(p1->getInt())->setInt(this->Param2->getInt());
        c->setPC(c->getPC() + 1);
    }

    delete p1;
}
