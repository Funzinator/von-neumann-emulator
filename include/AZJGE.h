#ifndef AZJGE_H_
#define AZJGE_H_

#include "RawOperation.h"
#include "CompareOperation.h"

class AZJGE : public CompareOperation
{
public:
    AZJGE(RawOperation*);

    void run(Configuration*);
};

#endif /*AZJGE_H_*/
