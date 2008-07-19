#ifndef DVA_H_
#define DVA_H_

#include "IntegerOperation.h"

class DVA : public IntegerOperation
{
public:
    DVA(RawOperation*);

    void run(Configuration*);
};

#endif /*DVA_H_*/
