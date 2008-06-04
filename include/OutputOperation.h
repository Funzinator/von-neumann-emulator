#ifndef OUTPUTOPERATION_H_
#define OUTPUTOPERATION_H_

#include "NullaryOperation.h"

class OutputOperation : public NullaryOperation
{
public:
    OutputOperation(RawOperation*);
};

#endif /*OUTPUTOPERATION_H_*/
