#ifndef NOT_H_
#define NOT_H_

#include "RawOperation.h"
#include "NegateOperation.h"

class NOT : public NegateOperation
{
public:
    NOT(RawOperation*);

    void run(Configuration*);
};

#endif /*NOT_H_*/