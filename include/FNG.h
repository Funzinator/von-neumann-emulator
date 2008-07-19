#ifndef FNG_H_
#define FNG_H_

#include "NegateOperation.h"

class FNG : public NegateOperation
{
public:
    FNG(RawOperation*);

    void run(Configuration*);
};

#endif /*FNG_H_*/
