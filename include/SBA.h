#ifndef SBA_H_
#define SBA_H_

#include "RawOperation.h"
#include "IntegerOperation.h"

class SBA : public IntegerOperation
{
public:
    SBA(RawOperation*);

    void run(Configuration*);
};

#endif /*SBA_H_*/
