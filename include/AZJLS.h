#ifndef AZJLS_H_
#define AZJLS_H_

#include "RawOperation.h"
#include "CompareOperation.h"

class AZJLS : public CompareOperation
{
public:
    AZJLS(RawOperation*);

    void run(Configuration*);
};

#endif /*AZJLS_H_*/
