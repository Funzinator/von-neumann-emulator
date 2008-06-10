#ifndef IRE_H_
#define IRE_H_

#include "RawOperation.h"
#include "ConvertOperation.h"

class IRE : public ConvertOperation
{
public:
    IRE(RawOperation*);

    void run(Configuration*);
};

#endif /*IRE_H_*/
