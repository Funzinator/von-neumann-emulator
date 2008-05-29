#ifndef CONTROLOPERATION_H_
#define CONTROLOPERATION_H_

#include "IndirectOperation.h"

class ControlOperation : public IndirectOperation
{
public:
    ControlOperation(RawOperation*);
};

#endif /*CONTROLOPERATION_H_*/
