#ifndef AZJNE_H_
#define AZJNE_H_

#include "RawOperation.h"
#include "CompareOperation.h"

class AZJNE : public CompareOperation
{
public:
    AZJNE(RawOperation*);

    void run(Configuration*);
};

#endif /*AZJNE_H_*/
