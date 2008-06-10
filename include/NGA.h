#ifndef NGA_H_
#define NGA_H_

#include "RawOperation.h"
#include "NegateOperation.h"

class NGA : public NegateOperation
{
public:
    NGA(RawOperation*);

    void run(Configuration*);
};

#endif /*NGA_H_*/
