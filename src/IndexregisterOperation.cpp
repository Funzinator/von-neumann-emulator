#include "IndexregisterOperation.h"

IndexregisterOperation::IndexregisterOperation(RawOperation *rawOp) : UnaryOperation(rawOp)
{
        if (!(this->Param1))
            this->Param1 = new StorageCell;
	this->Param1->setInt(rawOp->Param1.toInt());
	/* Param1 ist die Nummer eines IR oder einer Speicherzelle,
	   deshalb Integer */
        if (!(rawOp->Param2.isEmpty()))
        {
            if (!(this->Param2))
                this->Param2 = new StorageCell;
            this->Param2->setInt(rawOp->Param2.toInt());
            /* Param2 ist ebenfalls immer Nummer eines IR, also Int */
        }
}

StorageCell* IndexregisterOperation::IndirectToDirect(Configuration *c)
{
    StorageCell *p1 = new StorageCell;
    if (this->indirect)
    {
    //Überführe "OP,I x" in "OP Inh(x)"
        p1->setInt(c->getData(this->Param1->getInt())->getInt());
    } else 
    {
        p1->setInt(this->Param1->getInt());
    }
    return p1;
}
