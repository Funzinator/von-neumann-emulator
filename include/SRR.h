#ifndef SRR_H_
#define SRR_H_

#include "RawOperation.h"
#include "NullaryOperation.h"

class SRR : public NullaryOperation
{
public:
    SRR(RawOperation*);

    void run(Configuration*);
};

#endif /*SRR_H_*/
