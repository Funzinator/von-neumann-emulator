#ifndef AZJLE_H_
#define AZJLE_H_

#include "RawOperation.h"
#include "CompareOperation.h"

class AZJLE : public CompareOperation
{
public:
    AZJLE(RawOperation*);

    void run(Configuration*);
};

#endif /*AZJLE_H_*/
