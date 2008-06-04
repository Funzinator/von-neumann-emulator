#ifndef ENIA_H_
#define ENIA_H_

#include "RawOperation.h"
#include "IndexregisterOperation.h"

class ENIA : public IndexregisterOperation
{
public:
    ENIA(RawOperation*);

    void run(Configuration*);
};

#endif /*ENIA_H_*/
