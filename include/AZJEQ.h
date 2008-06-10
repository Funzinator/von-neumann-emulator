#ifndef AZJEQ_H_
#define AZJEQ_H_

#include "RawOperation.h"
#include "CompareOperation.h"

class AZJEQ : public CompareOperation
{
public:
    AZJEQ(RawOperation*);

    void run(Configuration*);
};

#endif /*AZJEQ_H_*/
