#ifndef NEGATEOPERATION_H_
#define NEGATEOPERATION_H_

#include "NullaryOperation.h"

class NegateOperation : public NullaryOperation
{
public:
    NegateOperation(RawOperation*);
};

#endif /*NEGATEOPERATION_H_*/
