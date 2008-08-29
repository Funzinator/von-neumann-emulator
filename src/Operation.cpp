#include "Operation.h"

Operation::Operation(RawOperation *rawOp)
{
    this->indirect = rawOp->indirect;
    this->Operatorname = rawOp->Operator;
    this->Comment = rawOp->Comment;

    /* just to be safe */
    this->Param1 = 0;
    this->Param2 = 0;
}

Operation::~Operation()
{
    if (this->Param1)
    {
        delete this->Param1;
    }

    if (this->Param2)
    {
        delete this->Param2;
    }
}

QString Operation::getOperationName(bool full = false)
{
    if (full)
    {
        QString res, p1, p2;
        res = "%1%2%3%4";

        if (this->Param1)
        {
            p1 = " %1";
            p1 = p1.arg(this->Param1->getType() == StorageCell::Integer ? this->Param1->getInt() : this->Param1->getFloat());
        }
        else
        {
            p1 = "";
        }

        if (this->Param2)
        {
            p2 = ",%1";
            p2 = p2.arg(this->Param2->getInt());
        }
        else
        {
            p2 = "";
        }

        return res.arg(this->Operatorname).arg(this->indirect ? ",I" : "").arg(p1).arg(p2);
    }
    else
    {
        return this->Operatorname;
    }
}
