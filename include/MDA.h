#ifndef MDA_H_
#define MDA_H_

#include "RawOperation.h"
#include "IntegerOperation.h"

class MDA : public IntegerOperation
{
public:
    MDA(RawOperation*);

    void run(Configuration*);
};

#endif /*MDA_H_*/
