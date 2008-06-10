#ifndef MUA_H_
#define MUA_H_

#include "RawOperation.h"
#include "IntegerOperation.h"

class MUA : public IntegerOperation
{
public:
    MUA(RawOperation*);

    void run(Configuration*);
};

#endif /*MUA_H_*/
