#ifndef OUTPUTOPERATION_H_
#define OUTPUTOPERATION_H_

#include "UnaryOperation.h"

class OutputOperation : public UnaryOperation
{
public:
    InputOperation(RawOperation*);
};

#endif /*OUTPUTOPERATION_H_*/
