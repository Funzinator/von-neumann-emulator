#ifndef NEGATEOPERATION_H_
#define NEGATEOPERATION_H_

#include "UnaryOperation.h"

class NegateOperation : public UnaryOperation
{
public:
    NegateOperation(RawOperation*);
};

#endif /*NEGATEOPERATION_H_*/
