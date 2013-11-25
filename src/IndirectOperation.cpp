#include "IndirectOperation.h"

IndirectOperation::IndirectOperation(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
    /* nichts zu tun */
}

StorageCell* IndirectOperation::BinaryToUnary(Configuration *c)
{
    if (c->getIndexRegister(this->Param2->getInt()))
    {
        StorageCell *p1 = new StorageCell;
        p1->setInt(this->Param1->getInt() + (this->Param2 ? c->getIndexRegister(this->Param2->getInt())->getInt() : 0));
        return p1;
    }
    else
    {
        return 0;
    }
}

StorageCell* IndirectOperation::setP1(Configuration *c)
{
    StorageCell *p1;

    p1 = (this->Param2 ? this->BinaryToUnary(c) : this->IndirectToDirect(c));

    return p1;
}
