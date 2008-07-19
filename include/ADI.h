#ifndef ADI_H_
#define ADI_H_

#include "IndexregisterOperation.h"

class ADI : public IndexregisterOperation
{
public:
    ADI(RawOperation*);

    void run(Configuration*);
};

#endif /*ADI_H_*/
