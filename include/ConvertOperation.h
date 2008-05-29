#ifndef CONVERTOPERATION_H_
#define CONVERTOPERATION_H_

#include "UnaryOperation.h"

class ConvertOperation : public UnaryOperation
{
public:
    ConvertOperation(RawOperation*);
};

#endif /*CONVERTOPERATION_H_*/
