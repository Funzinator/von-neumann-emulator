#ifndef ENA_H_
#define ENA_H_

#include "RawOperation.h"
#include "UnaryOperation.h"

class ENA : public UnaryOperation
{
public:
    ENA(RawOperation*);

    void run(Configuration*);
};

#endif /*ENA_H_*/
