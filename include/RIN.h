#ifndef RIN_H_
#define RIN_H_

#include "RawOperation.h"
#include "ConvertOperation.h"

class RIN : public ConvertOperation
{
public:
    RIN(RawOperation*);

    void run(Configuration*);
};

#endif /*RIN_H_*/