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
