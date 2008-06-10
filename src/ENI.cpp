#include "ENI.h"

ENI::ENI(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
    this->Param2->setInt(rawOp->Param2.toInt());
}

void ENI::run(Configuration *c)
{   //ENI A,B belegt das Indexregister A mit dem Int-Wert B
    c->getIndexRegister(this->Param1->getInt())->setInt(this->Param2->getInt());
    c->setPC(c->getPC() + 1);
}
