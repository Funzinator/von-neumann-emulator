#ifndef ENA_H_
#define ENA_H_

#include "UnaryOperation.h"

class ENA : public UnaryOperation
{
public:
    ENA(RawOperation*);

    void run(Configuration*);
};

#endif /*ENA_H_*/
