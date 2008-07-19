#ifndef HLT_H_
#define HLT_H_

#include "NullaryOperation.h"

class HLT : public NullaryOperation
{
public:
    HLT(RawOperation*);

    void run(Configuration*);
};

#endif /*HLT_H_*/
