#ifndef ADA_H_
#define ADA_H_

#include "RawOperation.h"
#include "IntegerOperation.h"

class ADA : public IntegerOperation
{
public:
    ADA(RawOperation*);

    void run(Configuration*);
};

#endif /*ADA_H_*/
