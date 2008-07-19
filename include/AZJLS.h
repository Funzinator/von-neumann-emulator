#ifndef AZJLS_H_
#define AZJLS_H_

#include "CompareOperation.h"

class AZJLS : public CompareOperation
{
public:
    AZJLS(RawOperation*);

    void run(Configuration*);
};

#endif /*AZJLS_H_*/
