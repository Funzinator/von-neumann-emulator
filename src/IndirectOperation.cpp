#include "IndirectOperation.h"

IndirectOperation::IndirectOperation(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
}

void IndirectOperation::IndirectToDirect()
{
    if (this->indirect){
    //überführe "OP,I x" in "OP Inh(x)"
        this->Param1->setInt(c->Data[this->Param1->getInt()]->getInt());
        this->indirect=false; //just to be clean
    }
}