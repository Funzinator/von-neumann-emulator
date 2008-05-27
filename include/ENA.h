#ifndef ENA_H_
#define ENA_H_

#include "RawOperation.h"
#include "BinaryOperation.h"

class ENA : public BinaryOperation
{
public:
    ENA(RawOperation*);

    void run(Configuration*);
};

#endif /*ENA_H_*/
