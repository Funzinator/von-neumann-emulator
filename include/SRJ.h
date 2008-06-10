#ifndef SRJ_H_
#define SRJ_H_

#include "RawOperation.h"
#include "IndirectOperation.h"

class SRJ : public IndirectOperation
{
public:
    SRJ(RawOperation*);

    void run(Configuration*);
};

#endif /*SRJ_H_*/
