#ifndef AZJGR_H_
#define AZJGR_H_

#include "RawOperation.h"
#include "CompareOperation.h"

class AZJGR : public CompareOperation
{
public:
    AZJGR(RawOperation*);

    void run(Configuration*);
};

#endif /*AZJGR_H_*/