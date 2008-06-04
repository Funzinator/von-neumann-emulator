#ifndef CONVERTOPERATION_H_
#define CONVERTOPERATION_H_

#include "NullaryOperation.h"

class ConvertOperation : public NullaryOperation
{
public:
    ConvertOperation(RawOperation*);
};

#endif /*CONVERTOPERATION_H_*/
