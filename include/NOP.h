#ifndef NOP_H_
#define NOP_H_

#include "NullaryOperation.h"

class NOP : public NullaryOperation
{
public:
    NOP(RawOperation*);

    void run(Configuration*);
};

#endif /*NOP_H_*/
