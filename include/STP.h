#ifndef STP_H_
#define STP_H_

#include "RawOperation.h"
#include "NullaryOperation.h"

class STP : public NullaryOperation
{
public:
    STP(RawOperation*);

    void run(Configuration*);
};

#endif /*STP_H_*/
