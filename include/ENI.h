#ifndef ENI_H_
#define ENI_H_

#include "RawOperation.h"
#include "IndexregisterOperation.h"

class ENI : public IndexregisterOperation
{
public:
    ENI(RawOperation*);

    void run(Configuration*);
};

#endif /*ENI_H_*/
