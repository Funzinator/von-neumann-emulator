#ifndef UJP_H_
#define UJP_H_

#include "ControlOperation.h"

class UJP : public ControlOperation
{
public:
    UJP(RawOperation*);

    void run(Configuration*);
};

#endif /*UJP_H_*/
