#include "IndirectOperation.h"

IndirectOperation::IndirectOperation(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
}

void IndirectOperation::IndirectToDirect(Configuration *c)
{
    if (this->indirect){
    //Überführe "OP,I x" in "OP Inh(x)"
        this->Param1->setInt(c->getData(this->Param1->getInt())->getInt());
        /*this->indirect=false;
        DARF MAN NICHT! Sonst macht das mit Sprungbefehlen keinen Sinn*/
    }
}
