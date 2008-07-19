#include "IndexregisterOperation.h"

IndexregisterOperation::IndexregisterOperation(RawOperation *rawOp) : UnaryOperation(rawOp)
{
    if (!this->Param1)
    {
        this->Param1 = new StorageCell;
    }

	this->Param1->setInt(rawOp->Param1.toInt());

    if (!rawOp->Param2.isEmpty())
    {
        if (!this->Param2)
        {
            this->Param2 = new StorageCell;
        }

        this->Param2->setInt(rawOp->Param2.toInt());
    }
}

StorageCell* IndexregisterOperation::IndirectToDirect(Configuration *c)
{
    StorageCell *p1 = new StorageCell;

    p1->setInt(this->indirect ? c->getData(this->Param1->getInt())->getInt() : this->Param1->getInt());

    return p1;
}
