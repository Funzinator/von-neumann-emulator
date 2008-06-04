#ifndef SBI_H_
#define SBI_H_

#include "RawOperation.h"
#include "IndexregisterOperation.h"

class SBI : public IndexregisterOperation
{
public:
    SBI(RawOperation*);

    void run(Configuration*);
};

#endif /*SBI_H_*/