#ifndef OUB_H_
#define OUB_H_

#include "OutputOperation.h"

class OUB : public OutputOperation
{
public:
    OUB(RawOperation*);

    void run(Configuration*);
};

#endif /*OUB_H_*/
