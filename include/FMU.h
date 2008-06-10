#ifndef FMU_H_
#define FMU_H_

#include "RawOperation.h"
#include "FloatOperation.h"

class FMU : public FloatOperation
{
public:
    FMU(RawOperation*);

    void run(Configuration*);
};

#endif /*FMU_H_*/
