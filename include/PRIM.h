#ifndef PRIM_H_
#define PRIM_H_

#include "NullaryOperation.h"

class PRIM : public NullaryOperation
{
private:
    bool prim(unsigned int);

public:
    PRIM(RawOperation*);

    void run(Configuration*);
};

#endif /*PRIM_H_*/
