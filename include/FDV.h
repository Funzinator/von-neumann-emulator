#ifndef FDV_H_
#define FDV_H_

#include "RawOperation.h"
#include "FloatOperation.h"

class FDV : public FloatOperation
{
public:
    FDV(RawOperation*);

    void run(Configuration*);
};

#endif /*FDV_H_*/
