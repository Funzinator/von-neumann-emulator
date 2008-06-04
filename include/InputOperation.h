#ifndef INPUTOPERATION_H_
#define INPUTOPERATION_H_

#include "NullaryOperation.h"

class InputOperation : public NullaryOperation
{
public:
    InputOperation(RawOperation*);
};

#endif /*INPUTOPERATION_H_*/
