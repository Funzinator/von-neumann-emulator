#ifndef ENAR_H_
#define ENAR_H_

#include "RawOperation.h"
#include "BinaryOperation.h"

class ENAR : public BinaryOperation
{
public:
    ENAR(RawOperation*);

    void run(Configuration*);
};

#endif /*ENAR_H_*/
