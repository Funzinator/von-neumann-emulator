#include "IndirectOperation.h"

IndirectOperation::IndirectOperation(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
}

StorageCell* IndirectOperation::IndirectToDirect(Configuration *c)
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
